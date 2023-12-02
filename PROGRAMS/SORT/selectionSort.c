#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int *A, int n) {
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&A[i], &A[minIndex]);
        }
    }
}

int main() {
    int n, i;
    printf("ENTER THE SIZE OF ARRAY  : ");
    scanf("%d", &n);

    int arr[n];
    printf("ENTER THE ARRAY ELEMENTS : ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);

    printf("THE SORTED ARRAY IS : ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    }
