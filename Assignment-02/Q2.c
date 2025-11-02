#include <stdio.h>
#include <string.h>

char name[50], cnic[20];
int codes[] = {1, 2, 3, 4};
char names[][20] = {"Product1", "Product2", "Product3", "Product4"};
int quantities[] = {50, 10, 20, 8};
int prices[] = {100, 200, 300, 150};
int cart[4] = {0};

void customerInfo() {
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter CNIC: ");
    scanf("%s", cnic);
}

void displayInventory() {
    printf("Product code\tQuantity\tPrice\n");
    for (int i = 0; i < 4; i++) {
        printf("%d\t\t%d\t\t%d\n", codes[i], quantities[i], prices[i]);
    }
}

void updateInventory(int code, int qty) {
    for (int i = 0; i < 4; i++) {
        if (codes[i] == code) {
            quantities[i] -= qty;
            return;
        }
    }
}

void addToCart() {
    int code, qty;
    printf("Enter product code: ");
    scanf("%d", &code);
    printf("Enter quantity: ");
    scanf("%d", &qty);
    for (int i = 0; i < 4; i++) {
        if (codes[i] == code) {
            if (quantities[i] < qty) {
                printf("Not enough stock.\n");
                return;
            }
            cart[i] += qty;
            updateInventory(code, qty);
            printf("Added to cart.\n");
            return;
        }
    }
    printf("Invalid product code.\n");
}

void displayBill() {
    int total = 0;
    for (int i = 0; i < 4; i++) {
        total += cart[i] * prices[i];
    }
    printf("Total: %d\n", total);
    char promo[20];
    printf("Enter promocode: ");
    scanf("%s", promo);
    if (strcmp(promo, "Eid2025") == 0) {
        printf("Discounted: %.2f\n", total * 0.75);
    } else {
        printf("No discount applied.\n");
    }
}

void showInvoice() {
    printf("Name: %s\nCNIC: %s\n", name, cnic);
    int total = 0;
    for (int i = 0; i < 4; i++) {
        if (cart[i] > 0) {
            printf("%s: %d x %d = %d\n", names[i], cart[i], prices[i], cart[i] * prices[i]);
            total += cart[i] * prices[i];
        }
    }
    printf("Total: %d\n", total);
    printf("After discount: %.2f\n", total * 0.75);
}

int main() {
    int choice;
    do {
        printf("\n1. Customer Info\n2. Display Inventory\n3. Add to Cart\n4. Display Bill\n5. Show Invoice\n6. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: customerInfo(); break;
            case 2: displayInventory(); break;
            case 3: addToCart(); break;
            case 4: displayBill(); break;
            case 5: showInvoice(); break;
            case 6: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);
    return 0;
}