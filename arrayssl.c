#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void insertbegin();
void insertend();
void insertpos();
void deletebegin();
void deleteend();
void deletepos();
void display();

int main() {
    int ch;
    do {
        printf("\nMenu\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insertbegin(); break;
            case 2: insertend(); break;
            case 3: insertpos(); break;
            case 4: deletebegin(); break;
            case 5: deleteend(); break;
            case 6: deletepos(); break;
            case 7: display(); break;
        }
    } while (ch <= 7);

    return 0;
}

void insertbegin() {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    int val;
    printf("Enter the value to be inserted: ");
    scanf("%d", &val);
    new_node->data = val;
    new_node->next = head;
    head = new_node;
}

void insertend() {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    int val;
    printf("Enter the value to be inserted: ");
    scanf("%d", &val);
    new_node->data = val;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void insertpos() {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    int val, pos;
    printf("Enter the value to be inserted: ");
    scanf("%d", &val);
    printf("Enter the position: ");
    scanf("%d", &pos);
    new_node->data = val;

    if (pos == 1) {
        new_node->next = head;
        head = new_node;
    } else {
        struct node* temp = head;
        int count = 1;
        while (temp != NULL && count < pos - 1) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL) {
            printf("Position not found.\n");
        } else {
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
}

void deletebegin() {
    if (head == NULL) {
        printf("SLL is empty!\n");
    } else {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteend() {
    if (head == NULL) {
        printf("SLL is empty!\n");
    } else {
        struct node* temp = head;
        struct node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL) {
            head = NULL;
        } else {
            prev->next = NULL;
        }
        free(temp);
    }
}

void deletepos() {
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (head == NULL) {
        printf("SLL is empty!\n");
    } else if (pos == 1) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    } else {
        struct node* temp = head;
        struct node* prev = NULL;
        int count = 1;
        while (temp != NULL && count < pos) {
            prev = temp;
            temp = temp->next;
            count++;
        }
        if (temp == NULL) {
            printf("Position not found.\n");
        } else {
            prev->next = temp->next;
            free(temp);
        }
    }
}

void display() {
    if (head == NULL) {
        printf("The SLL is empty.\n");
    } else {
        struct node* temp = head;
        printf("The elements in SLL are: ");
        while (temp != NULL) {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
