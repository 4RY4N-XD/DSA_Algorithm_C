#include <stdio.h>

int binarySearch(int A[],int n, int target ){
    int left = 0; 
    int right  = n-1;
    int result = -1;
    while (left <= right)
    {
        int mid = (left+right)/2; 
        
        printf("Current search range: ");
        for (int i = left; i <= right; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
        
        printf("mid element is %d at index %d\n",A[mid], mid);

    
        if ( A[mid] == target)
        {
            right = mid -1;
            result =  mid;
        }
        else if (A[mid] < target)
        {
            left = mid + 1;
        }
        else{
            right = mid -1;
        }
        
    }
    return result; 
}

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
    int target;
    printf("Enter your Target Element: ");
    scanf("%d", &target);
    printf("\n");

    bubbleSort(A, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    printf("\n\n");
    int index = binarySearch(A, n, target);
    if (index != -1)
        printf("\nElement found at index %d\n", index);
    else
        printf("\nElement not found\n");

    return 0;
}