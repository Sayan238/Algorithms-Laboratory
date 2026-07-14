#include <stdio.h>

void EXCHANGE(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void ROTATE_RIGHT(int a[], int n)
{
    int i;
    for (i = n - 1; i > 0; i--)
    {
        EXCHANGE(&a[i], &a[i - 1]);
    }
}

int main()
{
    int A[100], N, i, p2;

    printf("Enter size of array: ");
    scanf("%d", &N);

    printf("Enter array elements: ");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Enter number of elements to rotate: ");
    scanf("%d", &p2);

    printf("Before ROTATE: ");
    for (i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }

    ROTATE_RIGHT(A, p2);

    printf("\nAfter ROTATE: ");
    for (i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}