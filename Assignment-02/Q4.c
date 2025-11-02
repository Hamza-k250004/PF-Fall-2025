#include <stdio.h>

int stack[100];
int top = -1;
int maxSize = 100;

void push() {
    if (top >= maxSize - 1) {
        printf("Stack overflow.\n");
        return;
    }
    int value;
    printf("Enter value: ");
    scanf("%d", &value);
    top++;
    stack[top] = value;
}

void pop() {
    if (top < 0) {
        printf("Stack underflow.\n");
        return;
    }
    top--;
}

void peek() {
    if (top < 0) {
        printf("Stack empty.\n");
        return;
    }
    printf("Top: %d\n", stack[top]);
}

void display() {
    if (top < 0) {
        printf("Stack empty.\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);
    return 0;
}