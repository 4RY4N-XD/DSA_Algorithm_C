#include <stdio.h>

int linear(int A[], int size, int target){
    int found = 0;
    for(int i = 0; i < size; i ++ ){
        if(A[i] == target){
            printf("Element found at index %d\n", i);
            found ++;
        }
    }
    if (!found) {
        printf("Target element is not available in the array\n");
    }
    return found;
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
    int target;
    printf("Enter your Target Element");
    scanf("%d", &target);

    linear(A, n, target);
    return 0;
}