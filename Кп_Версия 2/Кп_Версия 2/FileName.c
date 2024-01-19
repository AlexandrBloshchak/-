#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX_SIZE 90

struct Materials {
    char name[52];
    int price;
    double square;
    double density;
    int endurance;
    double thermal_conductivity;
};
void Find_Name(struct Materials materials[], int size, char Find_of_Name[]);
void Find_Price(struct Materials materials[], int size, int Find_of_Price);
void Find_Square(struct Materials materials[], int size, double Find_of_Square);
void Sort_Thermal_conductivity(struct Materials materials[], int size);
void Write_to_File(struct Materials materials[], int size);

int main() {
    struct Materials materials[MAX_SIZE];
    int size = 0;

    int choice;
    setlocale(LC_ALL, "RUS");
    system("chcp 1251");

    do {
        printf("Меню:\n");
        printf("1) Добавить запись\n");
        printf("2) Поиск по названию\n");
        printf("3) Поиск по стоимости блока\n");
        printf("4) Поиск по площади строительного материала\n");
        printf("5) Сортировка по теплопроводимости\n");
        printf("6) Записать в файл\n");
        printf("7) Выход из программы\n");
        printf("Выберите пункт меню: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (size < MAX_SIZE) {
                printf("Введите данные для новой записи в программе:\n");
                printf("Название: ");
                scanf("%s", materials[size].name);
                printf("Цена материала: ");
                scanf("%d", &materials[size].price);
                printf("Площадь одного блока: ");
                scanf("%lf", &materials[size].square);
                printf("Плотность кг/м3: ");
                scanf("%lf", &materials[size].density);
                printf("Прочность от 1 до 200 кг/см: ");
                scanf("%d", &materials[size].endurance);
                printf("Теплопроводность от 0 до 0,9 ВТ/м: ");
                scanf("%lf", &materials[size].thermal_conductivity);
                size++;
            }
            else {
                printf("База данных переполненна! Добавление запрещено! Ошибка!\n");
            }
            break;
        case 2:
            if (size > 0) {
                char Find_of_Name[40];
                printf("Введите наименование строительного материала для поиска: ");
                scanf("%s", &Find_of_Name);
                Find_Name(materials, size, Find_of_Name);
            }
            else {
                printf("База данных = пустое место!\n");
            }
            break;
        case 3:
            if (size > 0) {
                int Find_of_Price1, Find_of_Price2;
                printf("Введите начальную цену строительного материала для поиска: ");
                scanf("%d", &Find_of_Price1);
                printf("Введите конечную цену строительного материала для поиска: ");
                scanf("%d", &Find_of_Price2);
                Find_Price(materials, size, Find_of_Price1, Find_of_Price2);
            }
            else {
                printf("База данных = пустое место!\n");
            }
            break;
        case 4:
            if (size > 0) {
                double Find_of_Square;
                printf("Введите площадь строительного материала для поиска: ");
                scanf("%lf", &Find_of_Square);
                Find_Square(materials, size, Find_of_Square);
            }
            else {
                printf("База данных = пустое место!\n");
            }
            break;
        case 5:
            if (size > 0) {
                double Sort_of_Thermal_conductivity;
                printf("Введите предел теплопроводимости: ");
                scanf("%lf", &Sort_of_Thermal_conductivity);
                Sort_Thermal_conductivity(materials, size, Sort_of_Thermal_conductivity);
            }
            else {
                printf("База данных = пустое место!\n");
            }
            break;
        case 6:
            if (size > 0) {
                Write_to_File(materials, size);
            }
            else {
                printf("База данных = пустое место!\n");
            }
            break;
        case 7:
            printf("Программа прекратила работу и была успешно завершена!\n");
            break;
        default:
            printf("Неправильный ввод. Пожалуйста, выберите существующий пункт меню.\n");
        }

    } while (choice != 7);
}

void Find_Name(struct Materials materials[], int size, char Find_of_Name[]) {
    printf("\nРезультаты поиска по названию строительного материала \"%s\":\n", Find_of_Name);
    printf("------------------------------------------------\n");
    for (int i = 0; i < size; ++i) {
        if (strstr(materials[i].name, Find_of_Name) != NULL) {
            printf("|%25s | %10s |\n", "Название", materials[i].name);
            printf("|%25s | %10d |\n", "Цена", materials[i].price);
            printf("|%25s | %10.2lf |\n", "Площадь", materials[i].square);
            printf("|%25s | %10.2lf |\n", "Плотность", materials[i].density);
            printf("|%25s | %10d |\n", "Прочность", materials[i].endurance);
            printf("|%25s | %10.2lf |\n", "Теплопроводимость", materials[i].thermal_conductivity);
            printf("------------------------------------------------\n");
        }
    }
}

void Find_Price(struct Materials materials[], int size, int Find_of_Price1, int Find_of_Price2) {
    printf("\nРезультаты поиска по диапазону от \"%d\ до \"%d\:\n", Find_of_Price1, Find_of_Price2);
    printf("------------------------------------------------\n");
    for (int i = 0; i < size; ++i) {
        if (Find_of_Price1 <= materials[i].price && materials[i].price <= Find_of_Price2) {
            printf("| %25s | %10s |\n", "Название", materials[i].name);
            printf("| %25s | %10d |\n", "Цена", materials[i].price);
            printf("| %25s | %10d |\n", "Площадь", materials[i].square);
            printf("| %25s | %10.2lf |\n", "Плотность", materials[i].density);
            printf("| %25s | %10d |\n", "Прочность", materials[i].endurance);
            printf("| %25s | %10.2lf |\n", "Теплопроводимость", materials[i].thermal_conductivity);
            printf("------------------------------------------------\n");
        }
    }
}
void Find_Square(struct Materials materials[], int size, double Find_of_Square) {
    printf("\nРезультаты поиска по площади \"%s\":\n", Find_of_Square);
    printf("------------------------------------------------\n");
    for (int i = 0; i < size; ++i) {
        if (materials[i].square == Find_of_Square) {
            printf("| %25s | %10s |\n", "Название", materials[i].name);
            printf("| %25s | %10d |\n", "Цена", materials[i].price);
            printf("| %25s | %10.lf |\n", "Площадь", materials[i].square);
            printf("| %25s | %10.2lf |\n", "Плотность", materials[i].density);
            printf("| %25s | %10d |\n", "Прочность", materials[i].endurance);
            printf("| %25s | %10.2lf |\n", "Теплопроводимость", materials[i].thermal_conductivity);
            printf("------------------------------------------------\n");
        }
    }
}

void Sort_Thermal_conductivity(struct Materials materials[], int size, double Sort_of_Thermal_conductivity) {
    printf("\nРезультаты поиска по теплопроводимости до %.2lf:\n", Sort_of_Thermal_conductivity);
    printf("------------------------------------------------\n");
    for (int i = 0; i < size; ++i) {
        if (materials[i].thermal_conductivity <= Sort_of_Thermal_conductivity) {
            printf("| %20s | %25s |\n", "Название", materials[i].name);
            printf("| %20s | %25d |\n", "Цена", materials[i].price);
            printf("| %20s | %25.lf |\n", "Площадь", materials[i].square);
            printf("| %20s | %25.2lf |\n", "Плотность", materials[i].density);
            printf("| %20s | %25d |\n", "Прочность", materials[i].endurance);
            printf("| %20s | %25.2lf |\n", "Теплопроводимость", materials[i].thermal_conductivity);
            printf("------------------------------------------------\n");
        }
    }
}

void Write_to_File(struct Materials materials[], int size) {
    FILE* file = fopen("materials.txt", "w");
    if (file == NULL) {
        printf("Файл не найден.\n");
        return;
    }
    printf("------------------------------------------------\n");
    for (int i = 0; i < size; ++i) {
        fprintf(file, "|%20s | %15s |\n", "Название", materials[i].name);
        fprintf(file, "|%20s | %15d |\n", "Цена", materials[i].price);
        fprintf(file, "|%20s | %15.2lf |\n", "Площадь", materials[i].square);
        fprintf(file, "|%20s | %15.2lf |\n", "Плотность", materials[i].density);
        fprintf(file, "|%20s | %15d |\n", "Прочность", materials[i].endurance);
        fprintf(file, "|%20s | %15.2lf |\n", "Теплопроводимость", materials[i].thermal_conductivity);
        fprintf(file, "------------------------------------------------\n");
    }
    fclose(file);
    printf("Данные были записаны в файл.\n");
}
