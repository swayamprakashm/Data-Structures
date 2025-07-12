#include <stdio.h>
#include <stdlib.h>

void insertbegin();
void insertend();
void insertpos();
void deletebegin();
void deleteend();
void deletepos();
void display();

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

int main() {
    printf("\nMenu\n1. insertbegin\n2. insertend\n3. insertpos\n4. deletebegin\n5. deleteend\n6. deletepos\n7. display\n8. exit\n");
    int ch;
    do {
        printf("Enter your choice = ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: insertbegin();
            break;
            case 2: insertend();
            break;
            case 3: insertpos();
            break;
            case 4: deletebegin();
            break;
            case 5: deleteend();
            break;
            case 6: deletepos();
            break;
            case 7: display();
            break;
}
    } while (ch != 7);
    return 0;
}

void insertbegin() {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    int val;
    printf("Enter the value to be inserted = ");
    scanf("%d", &val);
    new_node->data = val;
    new_node->next = head;
    head = new_node;
}

void insertend() {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    int val;
    printf("Enter the value to be inserted = ");
    scanf("%d", &val);
    new_node->data = val;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void insertpos() {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    int val, pos;
    printf("Enter the value to be inserted = ");
    scanf("%d", &val);
    printf("Enter the position = ");
    scanf("%d", &pos);
    new_node->data = val;
    if (pos == 1) {
        new_node->next = head;
        head = new_node;
    } else {
        struct node *temp = head;
        int count = 1;
        while (count < pos - 1 && temp != NULL) {
            temp = temp->next;
            count++;
        }
        if (temp != NULL) {
            new_node->next = temp->next;
            temp->next = new_node;
        } else {
            printf("Position not found.\n");
            free(new_node);
        }
    }
}

void deletebegin() {
    if (head == NULL) {
        printf("Single Linked List is empty\n");
    } else {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteend() {
    if (head == NULL) {
        printf("SLL is empty! Not possible\n");
    } else {
        struct node *temp = head;
        struct node *prev = NULL;
        if (head->next == NULL) {
            head = NULL;
            free(temp);
        } else {
            while (temp->next != NULL) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            free(temp);
        }
    }
}

void deletepos() {
    int pos;
    printf("Enter the position to be deleted = ");
    scanf("%d", &pos);
    if (head == NULL) {
        printf("SLL is empty! Not possible\n");
    } else {
        struct node *temp = head;
        if (pos == 1) {
            head = head->next;
            free(temp);
        } else {
            struct node *prev = NULL;
            int count = 1;
            while (count < pos && temp != NULL) {
                prev = temp;
                temp = temp->next;
                count++;
            }
            if (temp != NULL) {
                prev->next = temp->next;
                free(temp);
            } else {
                printf("Position not found.\n");
            }
        }
    }
}

void display() {
    if (head == NULL) {
        printf("The SLL is empty\n");
    } else {
        printf("The elements of SLL are = ");
        struct node *temp = head;
        while (temp != NULL) {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}
