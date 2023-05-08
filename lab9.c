#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols, i, j;
    float sum = 0, count = 0;
    float min, max;

    // введення розмірності масиву
    printf("Введіть кількість рядків: ");
    scanf("%d", &rows);
    printf("Введіть кількість стовпців: ");
    scanf("%d", &cols);

    // виділення пам'яті для масиву
    float **array = (float **)malloc(rows * sizeof(float *));
    for(i = 0; i < rows; i++) {
        array[i] = (float *)malloc(cols * sizeof(float));
    }

    // введення елементів масиву
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("Введіть елемент [%d][%d]: ", i, j);
            scanf("%f", *(array + i) + j);
        }
    }

    // знаходження мінімального та максимального елементів
    min = **array;
    max = **array;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if(*(*(array + i) + j) < min) {
                min = *(*(array + i) + j);
            }
            if(*(*(array + i) + j) > max) {
                max = *(*(array + i) + j);
            }
        }
    }

    // обчислення середнього арифметичного елементів без мінімального та максимального
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if(*(*(array + i) + j) != min && *(*(array + i) + j) != max) {
                sum += *(*(array + i) + j);
                count++;
            }
        }
    }
    float avg = sum / count;

    printf("Середнє арифметичне елементів без мінімального та максимального: %.2f\n", avg);

    // звільнення виділеної пам'яті
    for(i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
