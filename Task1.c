#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
double f1(double x)
{
    if (x <= 3)
        return x * x - 3 * x + 9;
    else
        return 1.0 / (x * x * x + 3);
}
double f2(double x)
{
    return x * exp(sin(x * x));
}
int main(void)
{
    setlocale(LC_ALL, "Russian");
    double x, a, b;
    int choice;
    printf("Введите x: ");
    scanf("%lf", &x);
    a = f1(x);
    b = f2(x);
    printf("1 - Значение F1(x)\n");
    printf("2 - Значение F2(x)\n");
    printf("3 - Произведение\n");
    printf("4 - Разность квадратов\n");
    printf("5 - Удвоенная сумма\n");
    printf("Выберите действие: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("F1(x) = %f\n", a);
        break;
    case 2:
        printf("F2(x) = %f\n", b);
        break;
    case 3:
        printf("Произведение = %f\n", a * b);
        break;
    case 4:
        printf("Разность квадратов = %f\n", a * a - b * b);
        break;
    case 5:
        printf("Удвоенная сумма = %f\n", 2 * (a + b));
        break;
    default:
        printf("Неверный выбор!\n");
    }
    return 0;
}