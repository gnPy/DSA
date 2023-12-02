#include <stdio.h>

void insertionSort(int *A, int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = A[i] ; 
        j = i-1 ; 

        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j-- ; 
        }

        A[j+1] = key;
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

    insertionSort(arr, n);

    printf("THE SORTED ARRAY IS : ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}
