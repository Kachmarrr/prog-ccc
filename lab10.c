#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Country {
    char name[50];
    char capital[50];
    int population;
    float area;
    int num_cities;
};

int main() {
    struct Country countries[10];
    int i, j;
    struct Country temp;

    // Введення даних про країни
    printf("Введіть дані про 10 країн Європи:\n");
    for (i = 0; i < 10; i++) {
        printf("Країна %d:\n", i + 1);
        printf("Назва: ");
        scanf("%s", countries[i].name);
        printf("Столиця: ");
        scanf("%s", countries[i].capital);
        printf("Кількість населення: ");
        scanf("%d", &countries[i].population);
        printf("Площа: ");
        scanf("%f", &countries[i].area);
        printf("Кількість міст: ");
        scanf("%d", &countries[i].num_cities);
    }

    // Сортування за зростанням кількості населення
    for (i = 0; i < 9; i++) {
        for (j = i + 1; j < 10; j++) {
            if (countries[i].population > countries[j].population) {
                temp = countries[i];
                countries[i] = countries[j];
                countries[j] = temp;
            }
        }
    }

    // Виведення відсортованого масиву країн
    printf("\nДані про країни у порядку зростання кількості населення:\n");
    for (i = 0; i < 10; i++) {
        printf("Країна %d:\n", i + 1);
        printf("Назва: %s\n", countries[i].name);
        printf("Столиця: %s\n", countries[i].capital);
        printf("Кількість населення: %d\n", countries[i].population);
        printf("Площа: %f\n", countries[i].area);
        printf("Кількість міст: %d\n", countries[i].num_cities);
    }

    return 0;
}
