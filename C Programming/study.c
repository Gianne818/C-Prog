#include <stdio.h>
#include <stdlib.h>

void mirrorArray(int r, int c, int arr[r][c]) {
    for (int i = 0; i<r; i++)
    for (int j=0, k=c-1; j<=c/2, k>=c/2; j++, k--){
        int temp = *(*(arr+i)+j);
        *(*(arr+i)+j) = *(*(arr+i)+k);
        *(*(arr+i)+k) = temp;
    }
}

void printArray(int r, int c, int arr[r][c]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int r, c;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    // Dynamically allocate 2D array
    int arr[r][c];

    printf("Enter %d values:\n", r * c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nOriginal array:\n");
    printArray(r, c, arr);

    mirrorArray(r, c, arr);

    printf("\nMirrored array:\n");
    printArray(r, c, arr);

    

    return 0;
}