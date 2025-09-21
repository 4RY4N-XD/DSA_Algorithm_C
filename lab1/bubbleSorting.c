#include <stdio.h>

void bubbleSort(int A[], int n){
    for (int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++){
            if (A[j] > A[j+1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
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

    bubbleSort(A, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}