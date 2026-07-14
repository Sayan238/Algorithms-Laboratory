#include <stdio.h>

int main() {
    int n, i, j;
    int arr[100];
    int duplicate = 0;
    int maxCount = 0, mostRepeat;

    FILE *fp = fopen("C:\\Users\\Sayan Barman\\OneDrive\\Desktop\\DAA_LAB\\input.txt", "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);

    printf("The content of the array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Count duplicate values
    for (i = 0; i < n; i++) {
        int count = 1;

        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j])
                break;
        }

        if (j != i)
            continue;

        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j])
                count++;
        }

        if (count > 1)
            duplicate++;

        if (count > maxCount) {
            maxCount = count;
            mostRepeat = arr[i];
        }
    }

    printf("Total number of duplicate values = %d\n", duplicate);
    printf("The most repeating element in the array = %d\n", mostRepeat);

    return 0;
}