#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_PRODUCTS 100

// Structure for a product
typedef struct Product {
    int id;
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Product;

// Array to hold the inventory and a count of products
Product inventory[MAX_PRODUCTS];
int productCount = 0;

// Function to add a product to the inventory
void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    int id, quantity;
    float price;
    char name[MAX_NAME_LEN];
    printf("Enter product ID, name, quantity, and price: ");
    scanf("%d %s %d %f", &id, name, &quantity, &price);
    inventory[productCount].id = id;
    strcpy(inventory[productCount].name, name);
    inventory[productCount].quantity = quantity;
    inventory[productCount].price = price;
    productCount++;
    printf("Product added: %s (ID: %d, Quantity: %d, Price: %.2f)\n", name, id, quantity, price);
}

// Function to display the inventory
void displayInventory() {
    if (productCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    printf("Current Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%-10s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Function to sell a product
void sellProduct() {
    int id, quantity;
    printf("Enter product ID and quantity to sell: ");
    scanf("%d %d", &id, &quantity);
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            if (inventory[i].quantity >= quantity) {
                inventory[i].quantity -= quantity;
                printf("Sold %d of %s. Remaining quantity: %d\n", quantity, inventory[i].name, inventory[i].quantity);
            } else {
                printf("Insufficient stock for product %s. Available: %d\n", inventory[i].name, inventory[i].quantity);
            }
            return;
        }
    }
    printf("Product with ID %d not found.\n", id);
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("\nSupermarket Management System\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Sell Product\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                sellProduct();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
