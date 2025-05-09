#include <stdio.h>
#include <stdlib.h>

void create(int arr[], int s){
    printf("Enter elements:\n");
    for (int i = 0; i<s; i++){
        scanf("%d", arr+i);
    }
}

int* mergeArray(int arr1[], int arr2[], int s1, int s2){
    int *arr3 = (int*) malloc((s1+s2)*sizeof(int));
    for (int i = 0; i<s1; i++){
        arr3[i] = arr1[i];
    }
    for (int i = 0; i<s2; i++){
        arr3[s1+i] = arr2[i];
    }

    return arr3;
}

void bubbleSort(int arr[], int s){
    for (int i = 0; i<s-1; i++){
        for (int j = 0; j<s-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main (){
    int s1, s2;
    printf("Enter the size of first array: ");
    scanf("%d", &s1);
    printf("Enter the size of second array: ");
    scanf("%d", &s2);

    int arr1[s1], arr2[s2];
    create(arr1, s1);
    create(arr2, s2);
    int* arr3 = mergeArray(arr1, arr2, s1, s2);
    bubbleSort(arr3, s1+s2);

    printf("Final Array:\n");
    for (int i = 0; i<s1+s2; i++){
        printf("%d ", arr3[i]);
    }

}