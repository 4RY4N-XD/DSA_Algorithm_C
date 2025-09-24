#include <stdio.h>

int smallest(int A[], int start, int n){
    int smallest = start;
    int smallest_value = A[start];
    for(int i = start; i < n; i++){
        if(A[i]< smallest_value){
            smallest_value = A[i];
            smallest = i;
        }
    }
    return smallest;
}

void selectionSort(int A[], int n) {
    for (int i = 0; i < n; i++)
    {
        int smallest_pos = smallest(A, i , n);
        printf("Smallest value is: %d \n", A[smallest_pos]);
        if(smallest_pos != i){
            int temp = A[i];
            A[i] = A[smallest_pos];
            A[smallest_pos] = temp;
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

    selectionSort(A, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}