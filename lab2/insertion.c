#include <stdio.h>

void insertionSort(int A[], int n) {
    int comparisons = 0;
    int iterations = 0;

    for(int i = 1; i < n ; i ++){
        int key = A[i];
        int j = i -1;

        while (key <= A[j])
        {
            comparisons++; // comparison inside while
            A[j+1] = A[j];
            j = j - 1;
            iterations++; // each shift is an iteration
            if (j < 0) {
                break;
            }   
        }

        if (j >= 0) comparisons++; // one final comparison when while fails

        A[j+1] = key;   

        // Print array after each pass
        printf("Pass %d: ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", A[k]);
        }
        printf("\n");
    }

    // Final stats
    printf("\nTotal comparisons: %d\n", comparisons);
    printf("Total iterations (shifts): %d\n", iterations);
}

int main(){
    int n;
    printf("Enter the number of elements u want:");
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i < n; i++){
        printf("Enter the %dth element: ", i+1);
        scanf("%d", &A[i]);
    };

    insertionSort(A, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}