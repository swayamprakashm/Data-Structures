#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

// Define a structure for a product node in the inventory
typedef struct Product {
    int id;
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
    struct Product* next;
} Product;

// Define a structure for a queue of customers
typedef struct Customer {
    int customerId;
    struct Customer* next;
} Customer;

// Define a stack node for undo operations
typedef struct Transaction {
    int productId;
    int quantityChanged;
    struct Transaction* next;
} Transaction;

// Global pointers for inventory, customer queue, and transaction stack
Product* inventory = NULL;
Customer* customerQueue = NULL;
Transaction* transactionStack = NULL;

// Function to create a new product
Product* createProduct(int id, const char* name, int quantity, float price) {
    Product* newProduct = (Product*)malloc(sizeof(Product));
    newProduct->id = id;
    strcpy(newProduct->name, name);
    newProduct->quantity = quantity;
    newProduct->price = price;
    newProduct->next = NULL;
    return newProduct;
}

// Function to add a product to the inventory
void addProduct(int id, const char* name, int quantity, float price) {
    Product* newProduct = createProduct(id, name, quantity, price);
    newProduct->next = inventory;
    inventory = newProduct;
    printf("Product added: %s (ID: %d, Quantity: %d, Price: %.2f)\n", name, id, quantity, price);
}

// Function to display the inventory
void displayInventory() {
    if (inventory == NULL) {
        printf("Inventory is empty.\n");
        return;
    }
    printf("Current Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    Product* temp = inventory;
    while (temp != NULL) {
        printf("%d\t%-10s\t%d\t\t%.2f\n", temp->id, temp->name, temp->quantity, temp->price);
        temp = temp->next;
    }
}

// Function to sell a product
void sellProduct(int productId, int quantity) {
    Product* temp = inventory;
    while (temp != NULL) {
        if (temp->id == productId) {
            if (temp->quantity >= quantity) {
                temp->quantity -= quantity;

                // Record the transaction in the stack for undo
                Transaction* newTransaction = (Transaction*)malloc(sizeof(Transaction));
                newTransaction->productId = productId;
                newTransaction->quantityChanged = quantity;
                newTransaction->next = transactionStack;
                transactionStack = newTransaction;

                printf("Sold %d of %s. Remaining quantity: %d\n", quantity, temp->name, temp->quantity);
            } else {
                printf("Insufficient stock for product %s. Available: %d\n", temp->name, temp->quantity);
            }
            return;
        }
        temp = temp->next;
    }
    printf("Product with ID %d not found.\n", productId);
}

// Function to undo the last transaction
void undoLastTransaction() {
    if (transactionStack == NULL) {
        printf("No transactions to undo.\n");
        return;
    }
    Transaction* lastTransaction = transactionStack;
    transactionStack = transactionStack->next;

    // Find the product and revert the quantity
    Product* temp = inventory;
    while (temp != NULL) {
        if (temp->id == lastTransaction->productId) {
            temp->quantity += lastTransaction->quantityChanged;
            printf("Undo successful. Reverted %d quantity of product %s.\n", lastTransaction->quantityChanged, temp->name);
            free(lastTransaction);
            return;
        }
        temp = temp->next;
    }
    free(lastTransaction);
}

// Function to add a customer to the queue
void addCustomerToQueue(int customerId) {
    Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    newCustomer->customerId = customerId;
    newCustomer->next = NULL;

    if (customerQueue == NULL) {
        customerQueue = newCustomer;
    } else {
        Customer* temp = customerQueue;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newCustomer;
    }
    printf("Customer %d added to the queue.\n", customerId);
}

// Function to process the next customer in the queue
void processNextCustomer() {
    if (customerQueue == NULL) {
        printf("No customers in the queue.\n");
        return;
    }
    Customer* temp = customerQueue;
    printf("Processing customer %d...\n", temp->customerId);
    customerQueue = customerQueue->next;
    free(temp);
}

// Main function
int main() {
    int choice, id, quantity, customerId;
    float price;
    char name[MAX_NAME_LEN];

    while (1) {
        printf("\nSupermarket Management System\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Sell Product\n");
        printf("4. Undo Last Transaction\n");
        printf("5. Add Customer to Queue\n");
        printf("6. Process Next Customer\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product ID, name, quantity, and price: ");
                scanf("%d %s %d %f", &id, name, &quantity, &price);
                addProduct(id, name, quantity, price);
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                printf("Enter product ID and quantity to sell: ");
                scanf("%d %d", &id, &quantity);
                sellProduct(id, quantity);
                break;
            case 4:
                undoLastTransaction();
                break;
            case 5:
                printf("Enter customer ID: ");
                scanf("%d", &customerId);
                addCustomerToQueue(customerId);
                break;
            case 6:
                processNextCustomer();
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
