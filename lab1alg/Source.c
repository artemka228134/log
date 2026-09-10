#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <windows.h> 

struct student {
    char famil[20];
    char name[20];
    char facult[20];
    int Nomzach;
};

int main() {
    SetConsoleCP(1251);       
    SetConsoleOutputCP(1251);


    setlocale(LC_ALL, "Russian");
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    srand(time(NULL));
    printf("========== ЗАДАНИЯ 1, 2 и 3 ==========\n");

    int n, i;

    printf("Введите размер одномерного массива: ");
    scanf_s("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));

    printf("Сгенерированный массив: ");
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");

    int max = arr[0];
    int min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    printf("Максимальный элемент: %d\n", max);
    printf("Минимальный элемент: %d\n", min);
    printf("Разница (max - min): %d\n\n", max - min);

    free(arr);

    printf("========== ЗАДАНИЕ 4 ==========\n");

    int rows = 3, cols = 4;
    int matrix[3][4];
    int j, sum;

    printf("Сгенерированный двумерный массив (3x4):\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nСуммы по строкам:\n");
    for (i = 0; i < rows; i++) {
        sum = 0;
        for (j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
        printf("Строка %d: %d\n", i + 1, sum);
    }

    printf("\nСуммы по столбцам:\n");
    for (j = 0; j < cols; j++) {
        sum = 0;
        for (i = 0; i < rows; i++) {
            sum += matrix[i][j];
        }
        printf("Столбец %d: %d\n", j + 1, sum);
    }
    printf("\n");

    printf("========== ЗАДАНИЕ 5 ==========\n");
    struct student stud[3] = {
       {"Иванов", "Иван", "ВТ", 1001},
       {"Петров", "Петр", "ФВТ", 1002},
       {"Сидоров", "Алексей", "ВТ", 1003}
    };

    char search_famil[20];
    int found = 0;

    printf("База студентов загружена.\n");
    printf("Введите фамилию для поиска (например, Петров): ");

    scanf_s("%19s", search_famil, (unsigned)sizeof(search_famil));

    for (i = 0; i < 3; i++) {
        if (strcmp(stud[i].famil, search_famil) == 0) {
            printf("\n--- Студент найден ---\n");
            printf("Фамилия: %s\nИмя: %s\nФакультет: %s\nНомер зачетки: %d\n",
                stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nСтудент с фамилией '%s' не найден.\n", search_famil);
    }

    printf("\nЛабораторная работа завершена!\n");

    return 0;
}