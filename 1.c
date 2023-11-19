#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Функция для проверки корректности даты
int isValidDate(int day, int month, int year) {
    // Проверяем корректность дня
    if (day < 1 || day > 31) {
        return 0;
    }

    // Проверяем корректность месяца
    if (month < 1 || month > 12) {
        return 0;
    }

    // Проверяем корректность года
    if (year < 1900 || year > 2100) {
        return 0;
    }

    return 1;
}

// Функция для формирования следующей по порядку даты
void nextDate(int *day, int *month, int *year) {
    // Прибавляем 1 к текущему дню
    (*day)++;

    // Проверяем, если день превысил максимальное значение для текущего месяца
    if (*day > 31) {
        // Переходим к следующему месяцу
        (*month)++;
        *day = 1;

        // Проверяем, если месяц превысил максимальное значение (12)
        if (*month > 12) {
            // Переходим к следующему году
            (*year)++;
            *month = 1;
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int day, month, year;

    // Ввод даты с клавиатуры
    printf("Введите дату в формате 'дд.мм.гггг': ");
    scanf("%d.%d.%d", &day, &month, &year);

    // Проверка корректности даты
    if (!isValidDate(day, month, year)) {
        printf("Некорректная дата.\n");
        return 1;
    }

    // Формирование следующей по порядку даты
    nextDate(&day, &month, &year);

    // Вывод результата
    printf("Следующая дата: %02d.%02d.%04d\n", day, month, year);

    return 0;
}
