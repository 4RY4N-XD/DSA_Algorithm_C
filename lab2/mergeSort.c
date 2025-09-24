#include <stdio.h>

int comparisons = 0;  // to count number of comparisons
int iterations = 0;   // to count number of merge calls

void printArray(int A[], int l, int r) {
    for (int i = l; i <= r; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int l, int m, int r){
    int i = l;
    int j = m +1;
    int k = l;

    int temp[r - l + 1];  // temporary array to store sorted elements

    // comparison
    while (i <= m && j <= r)
    {
        comparisons++;  // increment comparison count
        if (A[i] < A[j]){
            temp[k] = A[i];
            i++;
        }else{
            temp[k] = A[j];
            j++;
        }
        k++;
    }
    // if only remaining elements in left subarray
    if (i > m)
    {
        while (j <= r)
        {
            temp[k] = A[j];
            j++;
            k++;
        }

    }
    // if only remaining elements in right subarray
    else{
        while (i <= m)
        {
            temp[k] = A[i];
            i++;
            k++;
        }
    }

    // copying element from temp to original array
    for (int p = l; p <= r; p++)
    {
        A[p] = temp[p];
    }

    iterations++;  // increment iteration count
    printf("After iteration %d (merged from index %d to %d): ", iterations, l, r);
    printArray(A, l, r);
}

void mergeSort(int A[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
}

int main() {
    int n;
    printf("Enter the number of elements you want: ");
    scanf("%d", &n);

    int A[n]; 
    for (int i = 0; i < n; i++) {
        printf("Enter the %dth element: ", i + 1);
        scanf("%d", &A[i]);
    }

    mergeSort(A, 0, n - 1); 

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    printf("\nTotal comparisons: %d", comparisons);
    printf("\nTotal iterations: %d\n", iterations);

    return 0;
}