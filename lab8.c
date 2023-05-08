#include <stdio.h>
#include <string.h>

int main() {
    char name[50];
    printf("Введіть своє прізвище, ім'я та по-батькові: ");
    fgets(name, 50, stdin);
    
    // перевірка правильності введення
    if (strlen(name) <= 1) {
        printf("Помилка вводу!\n");
        return 1;
    }
    
    // варіант 1: використовуючи функції стандартної бібліотеки
    char* token = strtok(name, " ");
    int i = 1;
    while (token != NULL && i <= 3) {
        printf("Довжина %d-го слова: %lu\n", i, strlen(token));
        token = strtok(NULL, " ");
        i++;
    }
    
    // варіант 2: розглядаючи введений текст як масив символів
    int word_count = 0;
    int word_length = 0;
    for (int j = 0; j < strlen(name); j++) {
        if (name[j] != ' ' && name[j] != '\n') {
            word_length++;
        }
        else {
            if (word_length > 0) {
                printf("Довжина %d-го слова: %d\n", word_count+1, word_length);
                word_count++;
                word_length = 0;
            }
        }
    }
    if (word_length > 0) {
        printf("Довжина %d-го слова: %d\n", word_count+1, word_length);
    }
    
    return 0;
}
