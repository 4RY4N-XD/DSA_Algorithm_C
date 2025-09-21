#include <stdio.h>

void partition(int A[], int beg, int end, int *loc){
    int left = beg;
    int right = end;
    int flag = 0;
    *loc = beg;

    while (flag != 1){
        while ((A[*loc] <= A[right]) && (*loc != right)){
            right--;
        }
        if (*loc == right){
            flag = 1;
        } else if (A[*loc] > A[right]){
            int temp = A[*loc];
            A[*loc] = A[right];
            A[right] = temp;
            *loc = right;
        }

        if (flag != 1){
            while ((A[*loc] >= A[left]) && (*loc != left)){
                left++;
            }
            if (*loc == left){
                flag = 1;
            } else if (A[*loc] < A[left]){
                int temp = A[*loc];
                A[*loc] = A[left];
                A[left] = temp;
                *loc = left;
            }
        }
    }
}

void quickSort(int A[], int beg, int end){
    if (beg < end){
        int loc;
        partition(A, beg, end, &loc);
        quickSort(A, beg, loc - 1);
        quickSort(A, loc + 1, end);
    }
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i < n; i++){
        printf("Enter the %dth element: ", i + 1);
        scanf("%d", &A[i]);
    }

    quickSort(A, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}