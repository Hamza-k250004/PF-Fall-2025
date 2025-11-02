#include <stdio.h>
#include <string.h>

void encodeMessage(char message[]) {
    int len = strlen(message);
    for (int i = 0; i < len / 2; i++) {
        char temp = message[i];
        message[i] = message[len - 1 - i];
        message[len - 1 - i] = temp;
    }
    for (int i = 0; i < len; i++) {
        message[i] ^= (1 << 1) | (1 << 4);
    }
}

void decodeMessage(char message[]) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        message[i] ^= (1 << 1) | (1 << 4);
    }
    for (int i = 0; i < len / 2; i++) {
        char temp = message[i];
        message[i] = message[len - 1 - i];
        message[len - 1 - i] = temp;
    }
}

int main() {
    int choice;
    char message[100];
    do {
        printf("\n1. Encode\n2. Decode\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar();
        if (choice == 1 || choice == 2) {
            printf("Enter message: ");
            fgets(message, 100, stdin);
            message[strcspn(message, "\n")] = 0;
            if (choice == 1) {
                encodeMessage(message);
                printf("Encoded: %s\n", message);
            } else {
                decodeMessage(message);
                printf("Decoded: %s\n", message);
            }
        }
    } while (choice != 3);
    return 0;
}