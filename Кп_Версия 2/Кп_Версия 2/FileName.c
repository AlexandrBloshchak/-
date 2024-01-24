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
struct Materials* Find_Name(struct Materials* materials[], int size, char Find_of_Name[]);
struct Materials* Find_Price(struct Materials* materials[], int size, int Find_of_Price);
struct Materials* Find_Square(struct Materials* materials[], int size, double Find_of_Square);
struct Materials* Sort_Thermal_conductivity(struct Materials* materials[], int size);
struct Materials* Write_to_File(struct Materials* materials[], int size);

int main() {
    struct Materials materials[MAX_SIZE];
    int size = 0;

    int choice;
    do {
        printf("Menu:\n");
        printf("1) Add entry\n");
        printf("2) Search by name\n");
        printf("3) Search by block cost\n");
        printf("4) Search by area of building material\n");
        printf("5) Sorting by thermal conductivity\n");
        printf("6) Write to file\n");
        printf("7) Exit the program\n");
        printf("Select menu item: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (size < MAX_SIZE) {
                printf("Enter data for a new entry in the program:\n");
                printf("Name: ");
                scanf("%s", materials[size].name);
                printf("Material price: ");
                scanf("%d", &materials[size].price);
                printf("Area of one block: ");
                scanf("%lf", &materials[size].square);
                printf("Density kg/m3: ");
                scanf("%lf", &materials[size].density);
                printf("Strength from 1 to 200 kg/cm: ");
                scanf("%d", &materials[size].endurance);
                printf("Thermal conductivity from 0 to 0.9 W/m: ");
                scanf("%lf", &materials[size].thermal_conductivity);
                size++;
            }
            else {
                printf("Database is full! Adding prohibited! Error!\n");
            }
            break;
        case 2:
            if (size > 0) {
                char Find_of_Name[40];
                printf("Enter the name of the building material to search for: ");
                scanf("%s", &Find_of_Name);
                Find_Name(materials, size, Find_of_Name);
            }
            else {
                printf("Database = empty space!\n");
            }
            break;
        case 3:
            if (size > 0) {
                int Find_of_Price1, Find_of_Price2;
                printf("Enter the starting price of the building material to search for: ");
                scanf("%d", &Find_of_Price1);
                printf("Enter the final price of the building material to search for: ");
                scanf("%d", &Find_of_Price2);
                Find_Price(materials, size, Find_of_Price1, Find_of_Price2);
            }
            else {
                printf("Database = empty space!\n");
            }
            break;
        case 4:
            if (size > 0) {
                double Find_of_Square;
                printf("Enter the area of the building material to search for: ");
                scanf("%lf", &Find_of_Square);
                Find_Square(materials, size, Find_of_Square);
            }
            else {
                printf("Database = empty space!\n");
            }
            break;
        case 5:
            if (size > 0) {
                double Sort_of_Thermal_conductivity;
                printf("Enter the thermal conductivity limit: ");
                scanf("%lf", &Sort_of_Thermal_conductivity);
                Sort_Thermal_conductivity(materials, size, Sort_of_Thermal_conductivity);
            }
            else {
                printf("Database = empty space!\n");
            }
            break;
        case 6:
            if (size > 0) {
                Write_to_File(materials, size);
            }
            else {
                printf("Database = empty space!\n");
            }
            break;
        case 7:
            printf("The program stopped running and was completed successfully!\n");
            break;
        default:
            printf("Invalid input. Please select an existing menu item.\n");
            break;
        }

    } while (choice != 7);
}

struct Materials* Find_Name(struct Materials* materials[], int size, char Find_of_Name[]) {
    printf("\nSearch results for the name of the building material \"%s\":\n", Find_of_Name);
    printf("------------------------------------------------ -\n");
    for (int i = 0; i < size; ++i) {
        if (strstr(materials[i]->name, Find_of_Name) != NULL) {
            printf("|%25s | %10s |\n", "Name", materials[i]->name);
            printf("|%25s | %10d |\n", "Price", materials[i]->price);
            printf("|%25s | %10.2lf |\n", "Area", materials[i]->square);
            printf("|%25s | %10.2lf |\n", "Density", materials[i]->density);
            printf("|%25s | %10d |\n", "Strength", materials[i]->endurance);
            printf("|%25s | %10.2lf |\n", "Thermal conductivity", materials[i]->thermal_conductivity);
            printf("------------------------------------------------ -\n");
        }
    }
    return materials;
}

struct Materials* Find_Price(struct Materials* materials[], int size, int Find_of_Price1, int Find_of_Price2) {
    printf("\nSearch results from \"%d\ to \"%d\:\n", Find_of_Price1, Find_of_Price2);
    printf("------------------------------------------------ -\n");
    for (int i = 0; i < size; ++i) {
        if (Find_of_Price1 <= materials[i]->price && materials[i]->price <= Find_of_Price2) {
            printf("| %25s | %10s |\n", "Name", materials[i]->name);
            printf("| %25s | %10d |\n", "Price", materials[i]->price);
            printf("| %25s | %10d |\n", "Area", materials[i]->square);
            printf("| %25s | %10.2lf |\n", "Density", materials[i]->density);
            printf("| %25s | %10d |\n", "Strength", materials[i]->endurance);
            printf("| %25s | %10.2lf |\n", "Thermal conductivity", materials[i]->thermal_conductivity);
            printf("------------------------------------------------ -\n");
        }
    }
    return materials;
}
struct Materials* Find_Square(struct Materials* materials[], int size, double Find_of_Square) {
    printf("\nSearch results by area \"%s\":\n", Find_of_Square);
    printf("------------------------------------------------ -\n");
    for (int i = 0; i < size; ++i) {
        if (materials[i]->square == Find_of_Square) {
            printf("| %25s | %10s |\n", "Name", materials[i]->name);
            printf("| %25s | %10d |\n", "Price", materials[i]->price);
            printf("| %25s | %10.lf |\n", "Area", materials[i]->square);
            printf("| %25s | %10.2lf |\n", "Density", materials[i]->density);
            printf("| %25s | %10d |\n", "Strength", materials[i]->endurance);
            printf("| %25s | %10.2lf |\n", "Thermal conductivity", materials[i]->thermal_conductivity);
            printf("------------------------------------------------ -\n");
        }
    }
    return materials;
}

struct Materials* Sort_Thermal_conductivity(struct Materials* materials[], int size, double Sort_of_Thermal_conductivity) {
    printf("\nSearch results for thermal conductivity up to %->2lf:\n", Sort_of_Thermal_conductivity);
    printf("------------------------------------------------ -\n");
    for (int i = 0; i < size; ++i) {
        if (materials[i]->thermal_conductivity <= Sort_of_Thermal_conductivity) {
            printf("| %20s | %25s |\n", "Name", materials[i]->name);
            printf("| %20s | %25d |\n", "Price", materials[i]->price);
            printf("| %20s | %25.lf |\n", "Area", materials[i]->square);
            printf("| %20s | %25.2lf |\n", "Density", materials[i]->density);
            printf("| %20s | %25d |\n", "Strength", materials[i]->endurance);
            printf("| %20s | %25.2lf |\n", "Thermal conductivity", materials[i]->thermal_conductivity);
            printf("------------------------------------------------ -\n");
        }
    }
    return materials;
}

struct Materials* Write_to_File(struct Materials* materials[], int size) {
    FILE* file = fopen("materials->txt", "w");
    if (file == NULL) {
        printf("File not found->\n");
        return;
    }
    printf("------------------------------------------------ -\n");
    for (int i = 0; i < size; ++i) {
        fprintf(file, "|%20s | %15s |\n", "Name", materials[i]->name);
        fprintf(file, "|%20s | %15d |\n", "Price", materials[i]->price);
        fprintf(file, "|%20s | %15.2lf |\n", "Area", materials[i]->square);
        fprintf(file, "|%20s | %15.2lf |\n", "Density", materials[i]->density);
        fprintf(file, "|%20s | %15d |\n", "Strength", materials[i]->endurance);
        fprintf(file, "|%20s | %15.2lf |\n", "Thermal conductivity", materials[i]->thermal_conductivity);
        fprintf(file, "-------------------------------------------- ---\n");
    }
    fclose(file);
    printf("The data was written to the file.\n");
    return materials;
}