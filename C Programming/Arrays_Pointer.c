#include <stdio.h>
#include <stdlib.h>

int* create(int s);
int countDupes(int* arr, int s);
void printUniqueElem(int* arr, int s);
void frequencyArrayElem(int* arr, int s);
void oddAndEven(int* arr, int s);
void insertInArrayAscending(int* arr, int* s);
void deleteElem(int* arr, int* s);
void indexOfSubarraySum(int* arr, int s);
void arrayLeaders(int* arr, int s); //elem is leader if >= to all elem to its right. elem[s-1] is leader
void subArrayLargestSum(int* arr, int s);
void missingInPermutationArray(int* arr, int s);
void elemWithMostFrequency(int* arr, int s);

int main (){
    int s;
    printf("Enter the size of the array: ");
    scanf("%d", &s);

    int* arr = create(s);
    if(arr==NULL){
        printf("Memory not successful.");
        return 0;
    }

    elemWithMostFrequency(arr, s);
}

void elemWithMostFrequency(int* arr, int s){
    int mostFreq = *(arr+0);
    int highestFreq = 1;

    for (int i = 0; i<s; i++){
        int count = 1;
        for (int j = i+1; j<s; j++){
            if(*(arr+i)==*(arr+j)){
                count++;
            }
        }
        if(count>highestFreq){
            highestFreq = count;
            mostFreq = *(arr+i);
        }
    }

    printf("The highest frequency is: %d", highestFreq);
}

void missingInPermutationArray(int* arr, int s){
    int expSum = 0, actSum = 0;
    for (int i = 1; i<=s+1; i++){
        expSum+=i;
    }

    for (int i = 0; i<s; i++){
        actSum+=*(arr+i);
    }

    printf("Missing number: %d", expSum-actSum);
}

void subArrayLargestSum(int* arr, int s){
    int prevMax = -9999;
    int curMax = 0;

    for (int i = 0; i < s; i++) {
        curMax += arr[i];

        if (curMax > prevMax) {
            prevMax = curMax;
        }

        if (curMax < 0) {
            curMax = 0;
        }
    }

    printf("Sum: %d", curMax);
}

void arrayLeaders(int* arr, int s){
    int leaders[s];
    int s2 = 0;
    for (int i = 0; i<s; i++){
        int isLeader = 1;
        for (int j = i+1; j<s; j++){
            if(arr[i]<arr[j]){
                isLeader = 0;
            }
        }
        if(isLeader){
            leaders[s2] = arr[i];
            s2++;
        }
    }

    printf("Leaders: ");
    for (int i = 0; i<s2; i++){
        printf("%d ", leaders[i]);
    }
}

void indexOfSubarraySum(int* arr, int s){
    int n;
    printf("Enter your target sum: ");
    scanf("%d", &n);
   
    int temp;
    for (int i = 0; i<s; i++){
        temp=*(arr+i);
        int j = i+1;
        if(temp==n){
            printf("%d, %d", i, i);
            return;
        } 
        while (temp!=n && j<s){
            temp+=*(arr+j);
            if(temp==n){
                printf("%d, %d", i, j);
                return;
            } j++;
        }
        
    }
    printf("-1");
}

void deleteElem(int* arr, int* s){
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    pos--;

    for (int i = pos; i<*s-1; i++){
        *(arr+i) = *(arr + (i+1));
    }
    (*s)--;
    printf("The new array: ");
    for (int i = 0; i<*s; i++){
        printf("%d ", *(arr+i));
    }

}

void insertInArrayAscending(int* arr, int* s){
    int n;
    printf("Enter the value to be inserted: ");
    scanf("%d", &n);

    *s+=1;
    *(arr+(*s-1)) = n;

    //bubble sort
    // for (int i = 0; i<*s; i ++){
    //    for (int j = 0; j<*s; j++){
    //         if(*(arr+i)<*(arr+j)){
    //             int temp = *(arr+i);
    //             *(arr+i) = *(arr+j);
    //             *(arr+j) = temp;
    //         }
    //    }
    // }

    //Selection sort
    for (int i = 0; i<*s; i++){
        int smallest = i;
        for (int j = i+1; j<*s; j++){
            if(arr[j]<arr[smallest]){
                smallest = j;
            }
        }
        if(smallest!=i){
            int temp = *(arr+i);
            *(arr+i) = *(arr+smallest);
            *(arr+smallest) = temp;
        }    
    }

    printf("The new sorted array: ");
    for (int i = 0; i<*s; i++){
        printf("%d ", *(arr+i));
    }
}

void oddAndEven(int* arr, int s){
    int nArr[s];
    int ns = 0;
    for (int i = 0; i<s; i++){
        if(*(arr+i)%2==0){
            *(nArr+ns) = *(arr+i);
            ns++;
        }
    }
    for (int i = 0; i<s; i++){
        if(*(arr+i)%2!=0){
            *(nArr+ns) = *(arr+i);
            ns++;
        }
    }

    for (int i = 0; i<s; i++){
        printf("%d ", *(nArr+i));
    }
}

void frequencyArrayElem(int* arr, int s){
    int freq[s];
    int uniqueArr[s];
    int s2 = 0;
    for (int i = 0; i<s; i++){
        int isUnique = 1;
        for (int j = 0; j<s2; j++){
            if(*(arr+i)==*(uniqueArr+i)){
                isUnique = 0;
                *(freq+j)=1;
            }
        }
        if(isUnique){
            *(uniqueArr+s2) = *(arr+i);
            *(freq+s2) = 1;
            s2++;
        }
    }

    for (int i = 0; i<s2; i++){
        printf("%d occurs %d times.\n", *(uniqueArr+i), *(freq+i));
    }
}

void printUniqueElem(int* arr, int s){
    printf("Unique elements in the array: ");
    for (int i = 0; i<s; i++){
        int isUnique = 1;
        for (int j = 0; j<s; j++){
            if(*(arr+i)==*(arr+j) && i!=j){
                isUnique = 0;
                break;
            }
        }
        if(isUnique){
            printf("%d ", *(arr+i));
        }
    }
}

int countDupes(int* arr, int s){
    int numDupes = 0;
    for (int i = 0; i<s; i++){
        for (int j = 0; j<s; j++){
            if(*(arr+i)==*(arr+j)){
                numDupes++;
                break;
            }
        }
    }
    return numDupes;
}

int* create(int s){
    int* cArr = (int*) malloc(s*sizeof(int));
    if(cArr==NULL){
        return NULL;
    }

    printf("Enter array elements: ");
    for (int i = 0; i<s; i++){
        scanf("%d", (cArr+i));
    }

    return cArr;
}  