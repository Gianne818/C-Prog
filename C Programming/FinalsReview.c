#include <stdio.h>
#include <math.h>
// #include "FinalsReview.h"

typedef struct {
    int r;
    int c;
    int arr[100][100];
} Matrix;

typedef struct {
    char name[50];
    int grades[5];
    char name1[50];
} Student;

void create(int r, int c, int arr[r][c]);
void disElem(int r, int c, int arr[r][c]);
void thirdLargestElement(int r, int c, int arr[r][c]);
void multiplyMatrices(int r1, int c1, int arr1[r1][c1]);
Matrix multiplyMatricesStruct();
void rowWithMaxSum(int r, int c, int arr[r][c]);
void largestSubMatrixwEqualELem(int r, int c, int arr[r][c]);
void transposeMatrix(int r, int c, int arr[r][c]);
void rotateMatrixClockwise(int r, int c, int arr[r][c]);
void rotateMatrixCounterClockwise(int r, int c, int arr[r][c]);
void flatten2dArray(int r, int c, int arr[r][c]);
void countOccurencesOfElem(int r, int c, int arr[r][c]);
void longestConsecutiveSequence(int r, int c, int arr[r][c]);
void studentGrades();
void ticTacToe();

int main (){
    int r, c;
    printf("Enter size of row: ");
    scanf("%d", &r);
    printf("Enter size of column: ");
    scanf("%d", &c);

    int arr[r][c];
    printf("Enter the elements:\n");
    create(r, c, arr);
    ticTacToe();
    
}

void ticTacToe(){
    char tic[3][3];
    printf("Enter 'X' or 'O':\n");
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            scanf(" %c", &tic[i][j]);
        }
    }

    int isX = 0;
    int isO = 0;
    // //check row-wise
    // for (int i = 0; i<3; i++){
    //     isX = 0;
    //     isO = 0;
    //     for (int j = 0; j<2; j++){
    //         if(tic[i][0]=='X'){
    //             if(tic[i][j+1]==tic[i][j+2]){
    //                 isX = 1;
    //                 break;
    //             }
    //         }
    //         if(tic[i][0]=='O'){
    //             if(tic[i][j+1]==tic[i][j+2]){
    //                 isO = 1;
    //                 break;
    //             } 
    //         }
    //     }
    //     if(isX || isO) break;
    // }


    // //check column-wise
    // for (int i = 0; i<3; i++){
    //     isX = 0;
    //     isO = 0;
    //     for (int j = 0; j<2; j++){
    //         if(tic[j][0]=='X'){
    //             if(tic[j][i+1]==tic[j][i+2]){
    //                 isX = 1;
    //                 break;
    //             }
    //         }
    //         if(tic[j][0]=='O'){
    //             if(tic[j][i+1]==tic[j][i+2]){
    //                 isO = 1;
    //                 break;
    //             } 
    //         }
    //     }
    //     if(isX || isO) break;
    // }
    while(isX==isO){
        //row-wise
        for (int i = 0; i<3; i++){
            isX = 0;
            isO = 0;
            if(tic[i][0]=='X'){
                if(tic[i][0]==tic[i][1] && tic[i][1]==tic[i][2]){
                    isX = 1;
                }
            }
            if(tic[0][i]=='O'){
                if(tic[i][0]==tic[i][1] && tic[i][1]==tic[i][2]){
                    isO = 1;
                }
            }
        }

        //column-wise
        for (int i = 0; i<3; i++){
            isX = 0;
            isO = 0;
            if(tic[0][i]=='X'){
                if(tic[0][i]==tic[1][i] && tic[1][i]==tic[2][i]){
                    isX = 1;
                    break;
                }
            }
            if(tic[0][i]=='O'){
                if(tic[0][i]==tic[1][i] && tic[1][i]==tic[2][i]){
                    isO = 1;
                    break;
                }
            }
        }
    
        //check diagonal'\'
            int i = 0;
            if(tic[0][0]=='X'){
                if(tic[0][0]==tic[1][1] && tic[1][1] == tic[2][2])
                    isX = 1;
                    break;
            }
            if(tic[i][i]=='O'){
                if(tic[0][0]==tic[1][1] && tic[1][1] == tic[2][2]){
                    isO = 1;
                    break;
                }  
            }
        
        //check diagonal '/'
        if(tic[0][2]=='X'){
            if(tic[0][2]==tic[1][1] && tic[1][1]==tic[2][0])
                isX = 1;
                break;
        }
        if(tic[0][2]=='O'){
            if(tic[0][2]==tic[1][1] && tic[1][1]==tic[2][0]){
                isO = 1;
                break;
            }  
        }
    }
    

    if(isX && !isO){
        printf("X");
        return;
    } else if (isO && !isX){
        printf("O");
        return;
    }

}

void studentGrades(){
    int s;
    printf("Enter the number of students: ");
    scanf("%d", &s);
    Student a[s];
    float sum[s];
    for (int i = 0; i<s; i++){
        sum[i] = 0;
    }

    float ave[s];
    for (int i = 0; i<s; i++){
        printf("Enter details for student %d:\n", i+1);
        printf("Enter name: ");
        scanf("%s", (a+i)->name);
        for (int j = 0; j<5; j++){

            printf("Grade %d: ",j+1);
            scanf("%d", &(a+i)->grades[j]);
            sum[i]+=(a+i)->grades[j]; 
        }
        ave[i] = sum[i]/5;
    }

    for (int i = 0; i<s; i++){
        printf("Average for %s: %.2f\n", (a+i)->name, ave[i]);
    }

    // int maxAve = ave[0];
    // int ind = 0;
    // for (int i = 0; i<s; i++){
    //     if(ave[i]>maxAve){
    //         maxAve = ave[i];
    //         ind = i;
    //     }
    // }
    // printf("Top Student: %s with average grade %.2f", (a+ind)->name, ave[ind]);
    Student temp1;
    for (int i = 0; i<s-1; i++){
        for (int j = 0; j<s-i-1; j++){
            if(ave[j]>ave[j+1]){
                float temp = ave[j];
                ave[j] = ave[j+1];
                ave[j+1] = temp;

                temp1 = *(a+j);
                *(a+j) = *(a+j+1);
                *(a+j+1) = temp1;

                
            }
            
        }
    }

    for (int i = 0; i<s; i++){
        printf("%s \n", (a+i)->name);
    }
}

void longestConsecutiveSequence(int r, int c, int arr[r][c]){
    int s = r*c;
    int nArr[s];
    int ind = 0;
    for (int i = 0; i<r; i++){
        for (int j = 0; j<c; j++){
            nArr[ind] = arr[i][j];
            ind++;
        }
    }

    for (int i = 0; i<s-1; i++){
        for (int j = 0; j<s-i-1; j++){
            if(nArr[j]>nArr[j+1]){
                int temp = nArr[j];
                nArr[j] = nArr[j+1];
                nArr[j+1] = temp;
            }
        }
    }
    
    printf("Sorted nArr:\n");
    for (int i = 0; i<s; i++){
        printf("%d ", nArr[i]);
    }
    printf("\n");

        int start = -1;
        int count = 0;
        int maxCount = 0;
        for (int i = 0; i<s-1; i++){
            int dif = nArr[i+1]-nArr[i];
            if(dif==1){
                start = i;
                break;
            }
        }
    
    printf("Start: %d\n", start);
    
    int temp;
    for (int j = start; j<s; j++){
        count = 0;
        for (int i = start; i<s; i++){
            count++;
            if(nArr[i+1]-nArr[i]!=1){
                start = i+1;
                temp = count;
                break;
            }
        }
        if(temp>maxCount) maxCount=temp;
    }
    
    printf("Length of longest consecutive sequence: %d", maxCount);
}
   
void countOccurencesOfElem(int r, int c, int arr[r][c]){
    int target;
    int count = 0;
    printf("Enter the target value: ");
    scanf("%d", &target);

    for (int i = 0; i<r; i++){
        for (int j = 0; j<c; j++){
            if(*(*(arr+i)+j)==target){
                count++;
            }
        }
    }
    printf("Count of occurences of %d: %d", target, count);
}

void flatten2dArray(int r, int c, int arr[r][c]){
    int nArr[1][r*c];
    int ind = 0;
    for (int i = 0; i<r; i++){
        for (int j = 0; j<c; j++){
            nArr[0][ind] = arr[i][j];
            ind++;
        }
    }
    printf("The flattened array:\n");
    disElem(1, r*c, nArr);
}

void rotateMatrixCounterClockwise(int r, int c, int arr[r][c]){
    int nArr[c][r];
    for (int i = 0; i<c; i++){
        for (int j = 0; j<r; j++){
            nArr[i][j] = arr[j][c-i-1];
        }
    }
    printf("Counter Clockwise Matrix:\n");
    disElem(c, r, nArr);
}

void rotateMatrixClockwise(int r, int c, int arr[r][c]){
    int nArr[c][r];
    for (int i = 0; i<c; i++){
        for (int j = 0; j<r; j++){
            nArr[i][j] = arr[j][i];
        }
    }

    for (int i = 0; i<c; i++){
        for (int j = 0, k=r-1; j<r/2, k>r/2; j++, k--){
            int temp = nArr[i][j];
            nArr[i][j] = nArr[i][k];
            nArr[i][k] = temp;
        }
    }
    printf("Clockwise Matrix:\n");
    disElem(c, r, nArr);
}

void transposeMatrix(int r, int c, int arr[r][c]){
    int nArr[c][r];
    for (int i = 0; i<c; i++){
        for (int j = 0; j<r; j++){
            nArr[i][j] = arr[j][i];
        }
    }
    printf("The resulting array:\n");
    disElem(c, r, nArr);
}

void largestSubMatrixwEqualELem(int r, int c, int arr[r][c]){
    int count = 1;
    for (int i = 0; i<r; i++){
        for (int j = 0; j<c; j++){
            for (int k = 0; k<r; k++){
                for (int l = 0; l<c; l++){
                    int size = (k-i+1)*(l-j+1);
                    int isEqual = 1;
                    for (int m = i; m<=k; m++){
                        for (int n = j; n<=l; n++){
                            if(arr[m][n]!=arr[i][j]){
                                isEqual=0;
                                break;
                            }
                        }
                        if(!isEqual) break;
                    }
                    if(size>count && isEqual){
                        count = size;
                    }

                }
            }
        }
    }
}

void rowWithMaxSum(int r, int c, int arr[r][c]){
    int maxInd = 0;
    int max = 0;
    int sum;
    for (int i = 0; i<r; i++){
        sum = 0;
        for (int j = 0; j<c; j++){
            sum+=*(*(arr+i)+j);
        }
        
        if(max<sum){
            max = sum;
            maxInd = i;
        }
        printf("Sum of row %d: %d\n", i, sum);
    }

    printf("Index of row with maximum sum: %d", maxInd);
}

Matrix multiplyMatricesStruct(){
    Matrix a;
    Matrix b;
    Matrix res;
    printf("Enter the row and column of the first matrix: ");
    scanf("%d %d", &a.r, &a.c);
    printf("Enter the row and column of the second matrix: ");
    scanf("%d %d", &b.r, &b.c);

    res.arr[a.r][b.c];
    a.arr[a.r][a.c];
    b.arr[b.r][b.c];
    printf("Enter the elements for the first matrix:\n");
    for (int i = 0; i<a.r; i++){
        for (int j = 0; j<a.c; j++){
            scanf("%d", &a.arr[i][j]);
        }
    }
    printf("Enter the elements for the second matrix:\n");
    for (int i = 0; i<b.r; i++){
        for (int j = 0; j<b.c; j++){
            scanf("%d", &b.arr[i][j]);
        }
    }

    for (int i = 0; i<a.r; i++){
        for (int j = 0; j<b.c; j++){
            res.arr[i][j] = 0;
        }
    }

    for (int i = 0; i<a.r; i++){
        for (int j = 0; j<b.c; j++){
            for (int k = 0; k<a.c; k++){
                res.arr[i][j] += a.arr[i][k]*b.arr[k][j];
            }
        }
    }
    
    
    printf("The matrix:\n");
    for (int i = 0; i<a.r; i++){
        for (int j = 0; j<b.c; j++){
            printf("%d ", res.arr[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int r1, int c1, int arr1[r1][c1]){
    int r2, c2;
    printf("Enter row and column for the second matrix: ");
    scanf("%d %d", &r2, &c2);

    int arr2[r2][c2];
    printf("Enter elements of the second array:\n");
    create(r2, c2, arr2);

    int arr3[r1][c2];

    for (int i = 0; i<r1; i++){
        for (int j = 0; j<c2; j++){
            arr3[i][j] = 0;
        }
    }

    for (int i = 0; i<r1; i++){
        for (int j = 0; j<c2; j++){
            for (int k = 0; k<r2; k++){
                arr3[i][j] += arr1[i][k]*arr2[k][j];
            }
        }
    }
    printf("The result of the matrix multiplication is: \n");
    disElem(r1, c2, arr3);
}

void thirdLargestElement(int r, int c, int arr[r][c]){
    int max = arr[0][0], secMax = -999, thirdMax = -99;

    for (int i = 0; i<r;i++){
        for (int j = 0; j<c; j++){
            if(*(*(arr+i)+j) > max){
                secMax = max;
                max = *(*(arr+i)+j);
            }
            else if((*(*arr+i)+j) < max && *(*(arr+i)+j) > secMax){
                thirdMax = secMax;
                secMax = *(*(arr+i)+j);
                
            }
            else if((*(*arr+i)+j) < secMax && *(*(arr+i)+j) > thirdMax){
                thirdMax = *(*(arr+i)+j);
              
            }
        }
    }


    printf("The third max is: %d", thirdMax);

}

void create(int r, int c, int arr[r][c]){
    for (int i = 0; i<r; i++){
        for (int j = 0; j<c; j++){
            scanf("%d", *(arr+i)+j);
        }
    }
}

void disElem(int r, int c, int arr[r][c]){
    for (int i = 0; i<r; i++){
        for (int j = 0; j<c; j++){
            printf("%d ", *(*(arr+i)+j));
        }
        printf("\n");
    }
}