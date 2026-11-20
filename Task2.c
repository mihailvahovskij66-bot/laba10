#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
double asin_n(double x, int N)
{
    double term = x;
    double sum = x;

    for (int i = 1; i < N; i++)
    {
        term = term * x * x * (2 * i - 1) * (2 * i - 1)
            / (2.0 * i * (2 * i + 1));

        sum = sum + term;
    }

    return sum;
}
double asin_eps(double x, double eps)
{
    double term = x;
    double sum = x;
    int i = 1;
    while (fabs(term) > eps * (1 - x * x))
    {
        term = term * x * x * (2 * i - 1) * (2 * i - 1)
            / (2.0 * i * (2 * i + 1));

        sum = sum + term;
        i++;
    }
    return sum;
}
int main(void)
{
    setlocale(LC_ALL, "Russian");
    double x, eps;
    double a, b, c;
    int N;
    printf("Введите x (-1 < x < 1): ");
    scanf("%lf", &x);
    printf("Введите количество членов N: ");
    scanf("%d", &N);
    printf("Введите точность eps: ");
    scanf("%lf", &eps);
    if (fabs(x) >= 1 || N < 1 || eps <= 0)
    {
        printf("Нужно: -1 < x < 1, N >= 1, eps > 0.\n");
        return 0;
    }
    a = asin(x);
    b = asin_n(x, N);
    c = asin_eps(x, eps);
    printf("Стандартная функция: %.10f\n", a);
    printf("По N членам ряда:    %.10f\n", b);
    printf("С точностью eps:     %.10f\n", c);
    printf("Отклонение для N:   %g\n", fabs(a - b));
    printf("Отклонение для eps: %g\n", fabs(a - c));
    return 0;
}