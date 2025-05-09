#include <stdio.h>

void create(int r, int c, int arr[r][c]);
void disElem(int r, int c, int arr[r][c]);
/*1*/ void transpose(int r, int c, int arr[r][c]);

int main (){
    int r, c;
    printf("Enter size of row and column: ");
    scanf("%d %d", &r, &c);

    int arr[r][c];
    create (r, c, arr);
    transpose(r, c, arr);
}

/*1*/ void transpose(int r, int c, int arr[r][c]){
    int temp[c][r];
    for (int i = 0; i<r; i++){
        for (int j = 0; j<c; j++){
            temp[i][j] = arr[j][i];
        }
    }
    disElem(c, r, temp);
    
}

void disElem(int r, int c, int arr[r][c]){
    for (int i = 0; i<r; i++){
        for (int j = 0; j<c; j++){
            printf("%d ", *(*(arr+i)+j));
        }
        printf("\n");
    }
}

void create(int r, int c, int arr[r][c]){
    printf("Enter the elements:\n");
    for (int i = 0; i<r; i++){
        for (int j = 0; j<c; j++){
            scanf("%d", *(arr+i)+j);
        }
    }
}