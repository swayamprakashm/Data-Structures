#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}



void displayBackground() {
    printf("\n================ Supermarket Management System ================\n");
    printf("              ___    ____    _____  \n");
    printf("             / _ \\  / ___\\  /  ___\\\n");
    printf("            | |_| | | |     | |_  \n");
    printf("            |  _  | | |     |  _| \n");
    printf("            | | | | | |___  | |___  \n");
    printf("            |_| |_| \\____/  \\_____/  \n");
    printf("==============================================================\n\n");
}

// Structure for storing item details
struct Item {
    char name[50];
    float price;
    int quantity;
};

// Function prototypes
void addItem(struct Item items[], int *count);
void viewItems(struct Item items[], int count);
void deleteItem(struct Item items[], int *count);

int main() {
    struct Item items[100];
    int itemCount = 0;
    int choice;

    while (1) {b
        clearScreen();

        displayBackground();

        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Delete Item\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume newline character

        switch (choice) {
            case 1:
                addItem(items, &itemCount);
                break;
            case 2:
                viewItems(items, itemCount);
                break;
            case 3:
                deleteItem(items, &itemCount);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\nPress Enter to continue...");
        getchar();
    }
    return 0;
}

void addItem(struct Item items[], int *count) {
    printf("Enter item name: ");
    fgets(items[*count].name, 50, stdin);
    strtok(items[*count].name, "\n");  // Remove trailing newline

    printf("Enter item price: ");
    scanf("%f", &items[*count].price);

    printf("Enter item quantity: ");
    scanf("%d", &items[*count].quantity);

    (*count)++;
    printf("Item added successfully!\n");
}

void viewItems(struct Item items[], int count) {
    if (count == 0) {
        printf("No items available.\n");
        return;
    }
    printf("Item List:\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Item %d: %s\n", i + 1, items[i].name);
        printf("Price: $%.2f | Quantity: %d\n", items[i].price, items[i].quantity);
        printf("------------------------------------------------\n");
    }
}

void deleteItem(struct Item items[], int *count) {
    int index;
    if (*count == 0) {
        printf("No items available to delete.\n");
        return;
    }

    printf("Enter item number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > *count) {
        printf("Invalid item number.\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        items[i] = items[i + 1];
    }
    (*count)--;
    printf("Item deleted successfully!\n");
}
