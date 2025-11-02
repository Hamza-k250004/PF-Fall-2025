#include <stdio.h>

int grid[3][3];

void updateSector() {
    int row, col, flag, value;
    printf("Enter row and column: ");
    scanf("%d %d", &row, &col);
    printf("Enter flag (0-2) and value (0/1): ");
    scanf("%d %d", &flag, &value);
    if (value) {
        grid[row][col] |= (1 << flag);
    } else {
        grid[row][col] &= ~(1 << flag);
    }
}

void querySector() {
    int row, col;
    printf("Enter row and column: ");
    scanf("%d %d", &row, &col);
    int status = grid[row][col];
    printf("Power: %s\n", (status & 1) ? "ON" : "OFF");
    printf("Overload: %s\n", (status & 2) ? "YES" : "NO");
    printf("Maintenance: %s\n", (status & 4) ? "YES" : "NO");
}

void diagnostic() {
    int overload = 0, maintenance = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] & 2) overload++;
            if (grid[i][j] & 4) maintenance++;
        }
    }
    printf("Overloaded: %d\nMaintenance: %d\n", overload, maintenance);
}

int main() {
    int choice;
    do {
        printf("\n1. Update Sector\n2. Query Sector\n3. Diagnostic\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: updateSector(); break;
            case 2: querySector(); break;
            case 3: diagnostic(); break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}