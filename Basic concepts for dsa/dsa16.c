#include <stdio.h>

int add(int, int);
float sub(float, float);

void main()
{
    int a, b, (*ptr1)(int, int), (*ptr2)(int, int);
    float c, d, (*ptr3)(float, float), (*ptr4)(float, float);

    ptr1 = &add;
    ptr2 = add;
    ptr3 = &sub;
    ptr4 = sub;

    printf("Enter 2 integers for addition: \n");
    scanf("%d%d", &a, &b);
    printf("Enter 2 real numbers for substraction\n");
    scanf("%f%f", &c, &d);

    printf("Addition : \n%d(ptr1)\n%d(ptr2)\n", (*ptr1)(a, b), ptr2(a, b));
    printf("Substraction : \n%f(ptr3)\n%f(ptr4)\n", (*ptr3)(c, d), ptr4(c, d));

    return;
}

int add(int x, int y)
{
    return (x + y);
}

float sub(float x, float y)
{
    return (x - y);
}
