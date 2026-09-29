#include <stdio.h>
#include <stdlib.h>
struct Node {
    int roll;
    struct Node* next;
};
struct Node* head = NULL;
void display() {
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Roll Numbers: ");
    while(temp != NULL) {
        printf("%d -> ", temp->roll);
        temp = temp->next;
    }
    printf("NULL\n");
}
void insertBeginning(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->roll = val;
    n->next = head;
    head = n;
    display();
}
void insertEnd(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->roll = val;
    n->next = NULL;
    if(head == NULL) {
        head = n;
    } 
    else {
        struct Node* temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = n;
    }
    display();
}
void search(int val) {
    struct Node* temp = head;
    int pos = 1, found = 0;
    while(temp != NULL) {
        if(temp->roll == val) {
            printf("Roll number %d found at position %d\n", val, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }
    if(!found) printf("Roll number %d is not available in the list.\n", val);
}
void deleteNode(int val) {
    if(head == NULL) {
        printf("List is empty, roll number not found.\n");
        return;
    }
    struct Node *temp = head, *prev = NULL;
    if(temp->roll == val) {
        head = temp->next;
        free(temp);
        printf("Deleted %d successfully.\n", val);
        display();
        return;
    }
    while(temp != NULL && temp->roll != val) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Roll number %d is not available in the list.\n", val);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Deleted %d successfully.\n", val);
    display();
}
int main() {
    int choice, val;
    while(1) {
        printf("1.Insert Beg 2.Insert End 3.Search 4.Delete 5.Display 6.Exit: ");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("Enter roll number: ");
            scanf("%d", &val);
            insertBeginning(val);
        } 
        else if(choice == 2) {
            printf("Enter roll number: ");
            scanf("%d", &val);
            insertEnd(val);
        } 
        else if(choice == 3) {
            printf("Enter roll number to search: ");
            scanf("%d", &val);
            search(val);
        } 
        else if(choice == 4) {
            printf("Enter roll number to delete: ");
            scanf("%d", &val);
            deleteNode(val);
        } 
        else if(choice == 5) {
            display();
        } 
        else if(choice == 6) {
            break;
        } 
        else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
