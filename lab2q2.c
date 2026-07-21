#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive function to calculate GCD of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    char srcFileName[256];
    char dstFileName[256];

    if (argc >= 3) {
        strncpy(srcFileName, argv[1], sizeof(srcFileName) - 1);
        srcFileName[sizeof(srcFileName) - 1] = '\0';
        strncpy(dstFileName, argv[2], sizeof(dstFileName) - 1);
        dstFileName[sizeof(dstFileName) - 1] = '\0';
    } else {
        printf("Usage via CLI: %s <source-file> <destination-file>\n", argv[0]);
        printf("Entering interactive mode...\n");
        printf("Enter source file name (e.g. inGcd.dat): ");
        if (scanf("%255s", srcFileName) != 1) {
            fprintf(stderr, "Invalid input for source file name.\n");
            return EXIT_FAILURE;
        }
        printf("Enter destination file name (e.g. outGcd.dat): ");
        if (scanf("%255s", dstFileName) != 1) {
            fprintf(stderr, "Invalid input for destination file name.\n");
            return EXIT_FAILURE;
        }
    }

    FILE *src = fopen(srcFileName, "r");
    if (!src) {
        perror("Error opening source file");
        return EXIT_FAILURE;
    }

    FILE *dst = fopen(dstFileName, "w");
    if (!dst) {
        perror("Error opening destination file");
        fclose(src);
        return EXIT_FAILURE;
    }

    int a, b;
    int pairCount = 0;

    while (fscanf(src, "%d %d", &a, &b) == 2) {
        int result = gcd(a, b);
        fprintf(dst, "The GCD of %d and %d is %d\n", a, b, result);
        pairCount++;
    }

    fclose(src);
    fclose(dst);

    if (pairCount == 0) {
        fprintf(stderr, "No pairs of numbers were read from %s.\n", srcFileName);
        return EXIT_FAILURE;
    }

    // Read and display the content of output file
    dst = fopen(dstFileName, "r");
    if (!dst) {
        perror("Error opening output file for reading");
        return EXIT_FAILURE;
    }

    char line[256];
    while (fgets(line, sizeof(line), dst)) {
        printf("%s", line);
    }

    fclose(dst);
    return EXIT_SUCCESS;
}
