#include <stdio.h>
#include <stdlib.h>

int* create(int s);
void disArr(int* arr, int s);
int* createSecondArr(int s, int* s2);
int* mergeTwoSortedArraysDescending(int* arr, int* arr2, int s, int s2);

int main (){
    int s;
    printf("Enter the size of the array: ");
    scanf("%d", &s);

    int* arr = create(s);
    if(arr==NULL){
        printf("Memory not successful.");
        return 0;
    }

    int s2;
    int* arr2 = createSecondArr(s, &s2);
    int* mergedDescending = mergeTwoSortedArraysDescending(arr, arr2, s, s2);
    disArr(mergedDescending, s2);

    free(arr);
    
}

int* mergeTwoSortedArraysDescending(int* arr, int* arr2, int s, int s2){
    int* nArr = (int*) malloc((s2)*sizeof(int));
    for (int i = 0; i<s; i++){
        *(nArr+i) = *(arr+i);
    }
    for (int i = 0; i<s2; i++){
        *(nArr+(s+i)) = *(arr2+i);
    }

    for (int i = 0; i<s2; i++){
        int smallest = i;
        for (int j = i+1; j<=s2; j++){
            if(nArr[j]>nArr[i]){
                smallest = j;
                int temp = nArr[i];
                nArr[i] = nArr[j];
                nArr[j] = temp;
            }
        }
    }

    return nArr;
}

int* createSecondArr(int s, int* s2){
    int ns;
    printf("Enter the size for the second array: ");
    scanf("%d", &ns);
    
    int* arr2 = create(ns);
    *s2 = s+ns;

    return arr2;
}

void disArr(int* arr, int s){
    for (int i = 0; i<s; i++){
        printf("%d ", *(arr+i));
    }
}

int* create(int s){
    int* arr = (int*) malloc(s*sizeof(int));
    printf("Enter array elements:\n");
    for (int i = 0; i<s; i++){
        scanf("%d", arr+i);
    }

    return arr;
}