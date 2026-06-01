#include <stdio.h>

#define PI 3.147

int main() {
int radius;
float area;
printf("Enter the radius of the circle: ");
scanf("%d", &radius);

area = PI * radius * radius;

printf("The area of the circle is %.2f\n", area);

return 0;

}
