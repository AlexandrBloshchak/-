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
        printf("����:\n");
        printf("1) �������� ������\n");
        printf("2) ����� �� ��������\n");
        printf("3) ����� �� ��������� �����\n");
        printf("4) ����� �� ������� ������������� ���������\n");
        printf("5) ���������� �� �����������������\n");
        printf("6) �������� � ����\n");
        printf("7) ����� �� ���������\n");
        printf("�������� ����� ����: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (size < MAX_SIZE) {
                printf("������� ������ ��� ����� ������ � ���������:\n");
                printf("��������: ");
                scanf("%s", materials[size].name);
                printf("���� ���������: ");
                scanf("%d", &materials[size].price);
                printf("������� ������ �����: ");
                scanf("%lf", &materials[size].square);
                printf("��������� ��/�3: ");
                scanf("%lf", &materials[size].density);
                printf("��������� �� 1 �� 200 ��/��: ");
                scanf("%d", &materials[size].endurance);
                printf("���������������� �� 0 �� 0,9 ��/�: ");
                scanf("%lf", &materials[size].thermal_conductivity);
                size++;
            }
            else {
                printf("���� ������ ������������! ���������� ���������! ������!\n");
            }
            break;
        case 2:
            if (size > 0) {
                char Find_of_Name[40];
                printf("������� ������������ ������������� ��������� ��� ������: ");
                scanf("%s", &Find_of_Name);
                Find_Name(materials, size, Find_of_Name);
            }
            else {
                printf("���� ������ = ������ �����!\n");
            }
            break;
        case 3:
            if (size > 0) {
                int Find_of_Price1, Find_of_Price2;
                printf("������� ��������� ���� ������������� ��������� ��� ������: ");
                scanf("%d", &Find_of_Price1);
                printf("������� �������� ���� ������������� ��������� ��� ������: ");
                scanf("%d", &Find_of_Price2);
                Find_Price(materials, size, Find_of_Price1, Find_of_Price2);
            }
            else {
                printf("���� ������ = ������ �����!\n");
            }
            break;
        case 4:
            if (size > 0) {
                double Find_of_Square;
                printf("������� ������� ������������� ��������� ��� ������: ");
                scanf("%lf", &Find_of_Square);
                Find_Square(materials, size, Find_of_Square);
            }
            else {
                printf("���� ������ = ������ �����!\n");
            }
            break;
        case 5:
            if (size > 0) {
                double Sort_of_Thermal_conductivity;
                printf("������� ������ �����������������: ");
                scanf("%lf", &Sort_of_Thermal_conductivity);
                Sort_Thermal_conductivity(materials, size, Sort_of_Thermal_conductivity);
            }
            else {
                printf("���� ������ = ������ �����!\n");
            }
            break;
        case 6:
            if (size > 0) {
                Write_to_File(materials, size);
            }
            else {
                printf("���� ������ = ������ �����!\n");
            }
            break;
        case 7:
            printf("��������� ���������� ������ � ���� ������� ���������!\n");
            break;
        default:
            printf("������������ ����. ����������, �������� ������������ ����� ����.\n");
        }

    } while (choice != 7);
}

void Find_Name(struct Materials materials[], int size, char Find_of_Name[]) {
    printf("\n���������� ������ �� �������� ������������� ��������� \"%s\":\n", Find_of_Name);
    printf("------------------------------------------------\n");
    for (int i = 0; i < size; ++i) {
        if (strstr(materials[i].name, Find_of_Name) != NULL) {
            printf("|%25s | %10s |\n", "��������", materials[i].name);
            printf("|%25s | %10d |\n", "����", materials[i].price);
            printf("|%25s | %10.2lf |\n", "�������", materials[i].square);
            printf("|%25s | %10.2lf |\n", "���������", materials[i].density);
            printf("|%25s | %10d |\n", "���������", materials[i].endurance);
            printf("|%25s | %10.2lf |\n", "�����������������", materials[i].thermal_conductivity);
            printf("------------------------------------------------\n");
        }
    }
}

void Find_Price(struct Materials materials[], int size, int Find_of_Price1, int Find_of_Price2) {
    printf("\n���������� ������ �� ��������� �� \"%d\ �� \"%d\:\n", Find_of_Price1, Find_of_Price2);
    printf("------------------------------------------------\n");
    for (int i = 0; i < size; ++i) {
        if (Find_of_Price1 <= materials[i].price && materials[i].price <= Find_of_Price2) {
            printf("| %25s | %10s |\n", "��������", materials[i].name);
            printf("| %25s | %10d |\n", "����", materials[i].price);
            printf("| %25s | %10d |\n", "�������", materials[i].square);
            printf("| %25s | %10.2lf |\n", "���������", materials[i].density);
            printf("| %25s | %10d |\n", "���������", materials[i].endurance);
            printf("| %25s | %10.2lf |\n", "�����������������", materials[i].thermal_conductivity);
            printf("------------------------------------------------\n");
        }
    }
}
void Find_Square(struct Materials materials[], int size, double Find_of_Square) {
    printf("\n���������� ������ �� ������� \"%s\":\n", Find_of_Square);
    printf("------------------------------------------------\n");
    for (int i = 0; i < size; ++i) {
        if (materials[i].square == Find_of_Square) {
            printf("| %25s | %10s |\n", "��������", materials[i].name);
            printf("| %25s | %10d |\n", "����", materials[i].price);
            printf("| %25s | %10.lf |\n", "�������", materials[i].square);
            printf("| %25s | %10.2lf |\n", "���������", materials[i].density);
            printf("| %25s | %10d |\n", "���������", materials[i].endurance);
            printf("| %25s | %10.2lf |\n", "�����������������", materials[i].thermal_conductivity);
            printf("------------------------------------------------\n");
        }
    }
}

void Sort_Thermal_conductivity(struct Materials materials[], int size, double Sort_of_Thermal_conductivity) {
    printf("\n���������� ������ �� ����������������� �� %.2lf:\n", Sort_of_Thermal_conductivity);
    printf("------------------------------------------------\n");
    for (int i = 0; i < size; ++i) {
        if (materials[i].thermal_conductivity <= Sort_of_Thermal_conductivity) {
            printf("| %20s | %25s |\n", "��������", materials[i].name);
            printf("| %20s | %25d |\n", "����", materials[i].price);
            printf("| %20s | %25.lf |\n", "�������", materials[i].square);
            printf("| %20s | %25.2lf |\n", "���������", materials[i].density);
            printf("| %20s | %25d |\n", "���������", materials[i].endurance);
            printf("| %20s | %25.2lf |\n", "�����������������", materials[i].thermal_conductivity);
            printf("------------------------------------------------\n");
        }
    }
}

void Write_to_File(struct Materials materials[], int size) {
    FILE* file = fopen("materials.txt", "w");
    if (file == NULL) {
        printf("���� �� ������.\n");
        return;
    }
    printf("------------------------------------------------\n");
    for (int i = 0; i < size; ++i) {
        fprintf(file, "|%20s | %15s |\n", "��������", materials[i].name);
        fprintf(file, "|%20s | %15d |\n", "����", materials[i].price);
        fprintf(file, "|%20s | %15.2lf |\n", "�������", materials[i].square);
        fprintf(file, "|%20s | %15.2lf |\n", "���������", materials[i].density);
        fprintf(file, "|%20s | %15d |\n", "���������", materials[i].endurance);
        fprintf(file, "|%20s | %15.2lf |\n", "�����������������", materials[i].thermal_conductivity);
        fprintf(file, "------------------------------------------------\n");
    }
    fclose(file);
    printf("������ ���� �������� � ����.\n");
}
