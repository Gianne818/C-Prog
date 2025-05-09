#include <stdio.h>

void create(int* arr, int s){
    printf("Enter the elements of the array:\n");
    for (int i = 0; i<s; i++){
        scanf("%d", arr+i);
    }
}

void disElem(int* arr, int s){
    for (int i = 0; i<s; i++){
        printf("%d ", *(arr+i));
    }
}

void bubbleTwo (int* arr, int s){
    for (int i = 0; i<s-1; i++){
        for (int j = 0; j<s-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        printf("Pass %d: ",i+1);
        disElem(arr, s);
        printf("\n");
    }
}

void bubble (int* arr, int s){
    for (int i = 0; i<s; i++){
        for (int j = i+1; j<s; j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        printf("Pass %d: ",i+1);
        disElem(arr, s);
        printf("\n");
    }
}

void selection(int* arr, int s) {
    for (int i = 0; i < s - 1; i++) { // Loop until the second last element
        int smallest = i;
        for (int j = i + 1; j < s; j++) {
            if (arr[j] < arr[smallest]) {
                smallest = j;
            }
        }
        // Swap only if found a new smallest
        if (smallest != i) {
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
        }
        
        printf("Pass %d: ", i + 1);
        disElem(arr, s);
        printf("\n");
    }
}

void insertion(int* arr, int s){
    for (int i = 1; i<s; i++){
        int temp = arr[i];
        int j;
        for (j = i-1; j>=0 && arr[j]>temp;){
            arr[j+1] = arr[j];
            j--; 
        }
        arr[j+1] = temp;   
        printf("Pass %d: ", i);
        disElem(arr, s);
        printf("\n"); 
    }
    
}


int main (){
    int s;
    printf("Enter the size of the array: ");
    scanf("%d", &s);

    int arr[s];
    create(arr, s);
    bubbleTwo(arr, s);
}

