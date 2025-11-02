#include <stdio.h>

int isbns[100];
char titles[100][50];
float prices[100];
int quantities[100];
int count = 0;

void addBook() {
    if (count >= 100) {
        printf("Inventory full.\n");
        return;
    }
    printf("Enter ISBN: ");
    int isbn;
    scanf("%d", &isbn);
    for (int i = 0; i < count; i++) {
        if (isbns[i] == isbn) {
            printf("ISBN already exists.\n");
            return;
        }
    }
    isbns[count] = isbn;
    printf("Enter title: ");
    scanf("%s", titles[count]);
    printf("Enter price: ");
    scanf("%f", &prices[count]);
    printf("Enter quantity: ");
    scanf("%d", &quantities[count]);
    count++;
    printf("Book added.\n");
}

void processSale() {
    int isbn, sold;
    printf("Enter ISBN: ");
    scanf("%d", &isbn);
    printf("Enter quantity sold: ");
    scanf("%d", &sold);
    for (int i = 0; i < count; i++) {
        if (isbns[i] == isbn) {
            if (quantities[i] < sold) {
                printf("Not enough stock.\n");
                return;
            }
            quantities[i] -= sold;
            printf("Sale processed.\n");
            return;
        }
    }
    printf("ISBN not found.\n");
}

void lowStockReport() {
    printf("Low stock books:\n");
    for (int i = 0; i < count; i++) {
        if (quantities[i] < 5) {
            printf("ISBN: %d, Title: %s, Price: %.2f, Quantity: %d\n", isbns[i], titles[i], prices[i], quantities[i]);
        }
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Add Book\n2. Process Sale\n3. Low Stock Report\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(); break;
            case 2: processSale(); break;
            case 3: lowStockReport(); break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}