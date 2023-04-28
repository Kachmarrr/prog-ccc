#include <stdio.h>
#include <math.h>

void solve_quadratic(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    double root1, root2;

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Корені рівняння: %.2f та %.2f\n", root1, root2);
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        printf("Рівняння має єдиний корінь: %.2f\n", root1);
    } else {
        printf("Рівняння не має розв'язків в множині дійсних чисел.\n");
    }
}

int main() {
    double a, b, c;

    printf("Введіть коефіцієнти a, b та c рівняння ax^2 + bx + c = 0: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    solve_quadratic(a, b, c);

    return 0;
}
