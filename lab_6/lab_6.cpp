#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RULES 20
#define MAX_PROD 10
#define MAX_SYMBOLS 10
#define MAX_TOKEN_LEN 16
#define MAX_SET_ITEMS 20

// Structure to represent a grammar production rule.
typedef struct
{
    char head[MAX_TOKEN_LEN];
    char body[MAX_PROD][MAX_SYMBOLS][MAX_TOKEN_LEN];
    int body_len[MAX_PROD];
    int prod_count;
} GrammarRule;

GrammarRule grammar[MAX_RULES];
int rule_count = 0;

// Arrays to store FIRST and FOLLOW sets as token lists.
char first_sets[26][MAX_SET_ITEMS][MAX_TOKEN_LEN];
int first_counts[26];
char follow_sets[26][MAX_SET_ITEMS][MAX_TOKEN_LEN];
int follow_counts[26];

char non_terminals[26][MAX_TOKEN_LEN];
int non_terminal_count = 0;

bool is_non_terminal(const char *symbol);

void init_sets()
{
    for (int i = 0; i < 26; i++)
    {
        first_counts[i] = 0;
        follow_counts[i] = 0;
    }
}

void register_non_terminal(const char *symbol)
{
    for (int i = 0; i < non_terminal_count; i++)
    {
        if (strcmp(non_terminals[i], symbol) == 0)
        {
            return;
        }
    }

    if (non_terminal_count < 26)
    {
        strcpy(non_terminals[non_terminal_count++], symbol);
    }
}

int find_symbol_index(const char *symbol)
{
    for (int i = 0; i < non_terminal_count; i++)
    {
        if (strcmp(non_terminals[i], symbol) == 0)
        {
            return i;
        }
    }

    return -1;
}

bool is_non_terminal(const char *symbol)
{
    return find_symbol_index(symbol) != -1;
}

bool add_to_set(char set[][MAX_TOKEN_LEN], int *count, const char *val)
{
    for (int i = 0; i < *count; i++)
    {
        if (strcmp(set[i], val) == 0)
        {
            return false;
        }
    }

    if (*count >= MAX_SET_ITEMS)
    {
        return false;
    }

    strcpy(set[*count], val);
    (*count)++;
    return true;
}

bool has_epsilon(char set[][MAX_TOKEN_LEN], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(set[i], "e") == 0)
        {
            return true;
        }
    }

    return false;
}

bool merge_sets(char set1[][MAX_TOKEN_LEN],
                int *count1,
                char set2[][MAX_TOKEN_LEN],
                int count2,
                bool ignore_epsilon)
{
    bool changed = false;

    for (int i = 0; i < count2; i++)
    {
        if (ignore_epsilon && strcmp(set2[i], "e") == 0)
        {
            continue;
        }

        if (add_to_set(set1, count1, set2[i]))
        {
            changed = true;
        }
    }

    return changed;
}

void add_rule(const char *head)
{
    strcpy(grammar[rule_count].head, head);
    grammar[rule_count].prod_count = 0;
    register_non_terminal(head);
}

void add_production(GrammarRule *rule, const char *symbols[], int symbol_count)
{
    int prod_index = rule->prod_count;

    for (int i = 0; i < symbol_count; i++)
    {
        strcpy(rule->body[prod_index][i], symbols[i]);
    }

    rule->body_len[prod_index] = symbol_count;
    rule->prod_count++;
}

// Compute FIRST sets.
void compute_first()
{
    bool changed = true;

    while (changed)
    {
        changed = false;

        for (int i = 0; i < rule_count; i++)
        {
            int head_idx = find_symbol_index(grammar[i].head);

            if (head_idx == -1)
            {
                continue;
            }

            for (int j = 0; j < grammar[i].prod_count; j++)
            {
                char (*prod)[MAX_TOKEN_LEN] = grammar[i].body[j];
                int prod_len = grammar[i].body_len[j];

                if (prod_len == 1 && strcmp(prod[0], "e") == 0)
                {
                    if (add_to_set(first_sets[head_idx], &first_counts[head_idx], "e"))
                    {
                        changed = true;
                    }
                    continue;
                }

                bool nullable_prefix = true;

                for (int k = 0; k < prod_len && nullable_prefix; k++)
                {
                    const char *sym = prod[k];

                    if (!is_non_terminal(sym))
                    {
                        if (add_to_set(first_sets[head_idx], &first_counts[head_idx], sym))
                        {
                            changed = true;
                        }
                        nullable_prefix = false;
                    }
                    else
                    {
                        int sym_idx = find_symbol_index(sym);

                        if (sym_idx == -1)
                        {
                            nullable_prefix = false;
                            continue;
                        }

                        if (merge_sets(first_sets[head_idx],
                                       &first_counts[head_idx],
                                       first_sets[sym_idx],
                                       first_counts[sym_idx],
                                       true))
                        {
                            changed = true;
                        }

                        if (!has_epsilon(first_sets[sym_idx], first_counts[sym_idx]))
                        {
                            nullable_prefix = false;
                        }
                    }
                }

                if (nullable_prefix)
                {
                    if (add_to_set(first_sets[head_idx], &first_counts[head_idx], "e"))
                    {
                        changed = true;
                    }
                }
            }
        }
    }
}

// Compute FOLLOW sets.
void compute_follow(const char *start_symbol)
{
    int start_idx = find_symbol_index(start_symbol);

    if (start_idx != -1)
    {
        add_to_set(follow_sets[start_idx], &follow_counts[start_idx], "$");
    }

    bool changed = true;

    while (changed)
    {
        changed = false;

        for (int i = 0; i < rule_count; i++)
        {
            int head_idx = find_symbol_index(grammar[i].head);

            if (head_idx == -1)
            {
                continue;
            }

            for (int j = 0; j < grammar[i].prod_count; j++)
            {
                char (*prod)[MAX_TOKEN_LEN] = grammar[i].body[j];
                int prod_len = grammar[i].body_len[j];

                for (int k = 0; k < prod_len; k++)
                {
                    const char *current_sym = prod[k];

                    if (!is_non_terminal(current_sym))
                    {
                        continue;
                    }

                    int cur_idx = find_symbol_index(current_sym);

                    if (cur_idx == -1)
                    {
                        continue;
                    }

                    bool nullable_suffix = true;

                    for (int n = k + 1; n < prod_len && nullable_suffix; n++)
                    {
                        const char *next_sym = prod[n];

                        if (!is_non_terminal(next_sym))
                        {
                            if (strcmp(next_sym, "e") != 0)
                            {
                                if (add_to_set(follow_sets[cur_idx], &follow_counts[cur_idx], next_sym))
                                {
                                    changed = true;
                                }
                            }

                            nullable_suffix = false;
                        }
                        else
                        {
                            int next_idx = find_symbol_index(next_sym);

                            if (next_idx == -1)
                            {
                                nullable_suffix = false;
                                continue;
                            }

                            if (merge_sets(follow_sets[cur_idx],
                                           &follow_counts[cur_idx],
                                           first_sets[next_idx],
                                           first_counts[next_idx],
                                           true))
                            {
                                changed = true;
                            }

                            if (!has_epsilon(first_sets[next_idx], first_counts[next_idx]))
                            {
                                nullable_suffix = false;
                            }
                        }
                    }

                    if (nullable_suffix)
                    {
                        if (merge_sets(follow_sets[cur_idx],
                                       &follow_counts[cur_idx],
                                       follow_sets[head_idx],
                                       follow_counts[head_idx],
                                       false))
                        {
                            changed = true;
                        }
                    }
                }
            }
        }
    }
}

void print_set(const char *label,
               const char *head,
               char set[][MAX_TOKEN_LEN],
               int count)
{
    printf("%s(%s) = { ", label, head);

    for (int i = 0; i < count; i++)
    {
        printf("%s%s", set[i], (i + 1 < count) ? ", " : "");
    }

    printf(" }\n");
}

int main()
{
    init_sets();

    // Original grammar:
    // E  → T E'
    // E' → + T E' | e
    // T  → F T'
    // T' → * F T' | e
    // F  → ( E ) | id

    add_rule("E");
    {
        const char *production[] = {"T", "E'"};
        add_production(&grammar[rule_count], production, 2);
    }
    rule_count++;

    add_rule("E'");
    {
        const char *production1[] = {"+", "T", "E'"};
        add_production(&grammar[rule_count], production1, 3);
        const char *production2[] = {"e"};
        add_production(&grammar[rule_count], production2, 1);
    }
    rule_count++;

    add_rule("T");
    {
        const char *production[] = {"F", "T'"};
        add_production(&grammar[rule_count], production, 2);
    }
    rule_count++;

    add_rule("T'");
    {
        const char *production1[] = {"*", "F", "T'"};
        add_production(&grammar[rule_count], production1, 3);
        const char *production2[] = {"e"};
        add_production(&grammar[rule_count], production2, 1);
    }
    rule_count++;

    add_rule("F");
    {
        const char *production1[] = {"(", "E", ")"};
        add_production(&grammar[rule_count], production1, 3);
        const char *production2[] = {"id"};
        add_production(&grammar[rule_count], production2, 1);
    }
    rule_count++;

    compute_first();
    compute_follow("E");

    printf("------ FIRST SETS ------\n");

    for (int i = 0; i < rule_count; i++)
    {
        int idx = find_symbol_index(grammar[i].head);

        if (idx != -1)
        {
            print_set("FIRST", grammar[i].head, first_sets[idx], first_counts[idx]);
        }
    }

    printf("\n------ FOLLOW SETS ------\n");

    for (int i = 0; i < rule_count; i++)
    {
        int idx = find_symbol_index(grammar[i].head);

        if (idx != -1)
        {
            print_set("FOLLOW", grammar[i].head, follow_sets[idx], follow_counts[idx]);
        }
    }

    return 0;
}