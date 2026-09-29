#include <stdio.h>
#include <stdlib.h>

struct Node {
    int page;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;

void visitPage(int id) {
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->page = id;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        current = newNode;
    }
    else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
        current = newNode;
    }

    printf("Visited page %d\n", id);
}

void moveForward() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("Moved forward to page %d\n", current->page);
    }
    else {
        printf("Forward not possible.\n");
    }
}

void moveBackward() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("Moved backward to page %d\n", current->page);
    }
    else {
        printf("Backward not possible.\n");
    }
}

void displayForward() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("No browsing history.\n");
        return;
    }

    printf("Pages First-to-Last: ");

    while (temp != NULL) {
        printf("%d ", temp->page);
        temp = temp->next;
    }

    printf("\n");
}

void displayBackward() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("No browsing history.\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Pages Last-to-First: ");

    while (temp != NULL) {
        printf("%d ", temp->page);
        temp = temp->prev;
    }

    printf("\n");
}

void deletePage(int id) {
    struct Node *temp = head;

    while (temp != NULL && temp->page != id) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Page %d not found.\n", id);
        return;
    }

    if (temp == head)
        head = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (current == temp) {
        if (temp->next != NULL)
            current = temp->next;
        else
            current = temp->prev;
    }

    free(temp);

    printf("Page %d deleted from history.\n", id);
}

int main() {
    int choice, id;

    while (1) {
        printf("\n1. Visit Page");
        printf("\n2. Forward");
        printf("\n3. Backward");
        printf("\n4. Display Forward");
        printf("\n5. Display Backward");
        printf("\n6. Delete Page");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter Page ID: ");
            scanf("%d", &id);
            visitPage(id);
        }
        else if (choice == 2) {
            moveForward();
        }
        else if (choice == 3) {
            moveBackward();
        }
        else if (choice == 4) {
            displayForward();
        }
        else if (choice == 5) {
            displayBackward();
        }
        else if (choice == 6) {
            printf("Enter Page ID to delete: ");
            scanf("%d", &id);
            deletePage(id);
        }
        else if (choice == 7) {
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
