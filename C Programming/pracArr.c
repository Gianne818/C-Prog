#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void create(int *arr, int s);
void disElem(int* arr, int s);
/*1*/ void subArrayySum(int* arr, int s);
/*2*/ void reverseInGroups(int* arr, int s);
/*3*/ void sumOfPairsZero(int *arr, int s);
/*4*/ void smallestPositiveMissing(int* arr, int s);
/*5*/ void minimumJumps(int *arr, int s);
/*6*/ void minimizeHeights(int* arr, int s);
/* Input: k = 2, arr[] = {1, 5, 8, 10}
Output: 5
Explanation: The array can be modified as {1+k, 5-k, 8-k, 10-k} = {3, 3, 6, 8}.
The difference between the largest and the smallest is 8-3 = 5.*/

/*7*/ void countInversions(int* arr, int s);
/*8*/ void maxProduct(int* arr, int s);
/*9*/ void searchRotated(int* arr, int s);
/*10*/ void maxSumSubArray(int* arr, int s);
/*11*/ void sumNonAdjacentArray(int* arr, int s);
/*12*/ void bestTimeToBuyStock (int* arr, int s);
/*13*/ void minimumPlatforms(int* arr, int s);
/*14*/ void absoluteDifferenceSorting (int* arr, int s);

int main (){
    int s;
    printf("Enter the size of the array: ");
    scanf("%d", &s);

    int arr[s];
    create(arr, s);
    absoluteDifferenceSorting(arr, s);
}

/*14*/ void absoluteDifferenceSorting (int* arr, int s){
    int k;
    printf("Enter value of k:");
    scanf("%d", &k);

    int dif[s];
    for (int i = 0; i<s; i++){
        *(dif+i) = abs(k-*(arr+i));
    }
    // printf("Dif Pass %d: ", 0);
    // disElem(dif, s);
    // printf("\n");
    // printf("\n");
    
    // for (int i = 0; i<s; i++){
    //     for (int j = i+1; j<s; j++){
    //         if(*(dif+i)>*(dif+j)){
                
    //             int tempDif = (*(dif+i));
    //             *(dif+i) = *(dif+j);
    //             *(dif+j) = tempDif;

    //             int tempArr = *(arr+i);
    //             *(arr+i) = *(arr+j);
    //             *(arr+j) = tempArr;
    //         }
    //     }
    //     printf("Arr Pass %d: ", i + 1);
    //     disElem(arr, s);
    //     printf("\tDif Pass %d: ", i + 1);
    //     disElem(dif, s);
    //     printf("\n");
    // }

   
    disElem(arr, s);
    
}

/*13*/ void minimumPlatforms(int* arr, int s){
    int* dep = (int*) malloc(s*sizeof(int));
    create(dep, s);

    int count = 0;
    int maxCount = 0;
    for (int i = 0; i<s; i++){
        count = 1;
        for(int j = 0; j<s; j++){
            if(*(arr+j)>*(arr+i) && *(arr+j)<*(dep+i) && i!=j){
                count++;
            }
        }
        maxCount = (count > maxCount) ? count : maxCount;
    }
    printf("%d", maxCount);
}

/*12*/ void bestTimeToBuyStock (int* arr, int s){
    int min = *(arr+0), max = 0, maxProfit = 0, profit;
    for (int i = 1; i<s; i++){
        if(*(arr+i)<min) min = *(arr+i);
        
        else {
            profit = *(arr+i) - min;
            if (maxProfit<profit){
                maxProfit = profit;
            }
        } 
    }
    printf("%d", maxProfit);
}

/*11*/ void sumNonAdjacentArray(int* arr, int s){
    int sum = 0;
    for (int i = 0; i<s; i+=2){
        sum+=*(arr+i);
    }

    printf("%d", sum);
}

/*10*/ void maxSumSubArray(int* arr, int s) {
    int maxSum = 0, sum = 0;
    for (int i = 0; i<s; i++){
        sum+=*(arr+i);
        if(sum>maxSum){
            maxSum=sum;
        }
        if (sum<0){
            sum = 0;
        }
    }
    printf("%d", maxSum);
}

/*9*/void searchRotated(int* arr, int s){
    int target;
    printf("Enter target value: ");
    scanf("%d", &target);
    for (int i = 0; i<s; i++){
        if(target==*(arr+i)){
            printf("%d", i);
            return;
        }
    }
    printf("%d", -1);
}

/*8*/ void maxProduct(int* arr, int s){
    int maxProduct = *(arr+0);
    for (int i = 0; i<s; i++){
        int prod = *(arr+i);
        for (int j = i+1; j<s; j++){
            prod = prod * (*(arr+j));
            if(prod>maxProduct){
                maxProduct = prod;
            }
        }
    }
    printf("%d", maxProduct);
}

/*7*/ void countInversions(int* arr, int s){
    int count = 0;
    for (int i = 0; i<s; i++){
        for (int j = i+1; j<s; j++){
            if(*(arr+i)>*(arr+j)){
                count++;
                int temp = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = temp;
            }
        }
    }

    printf("%d", count);
}

/*6*/ void minimizeHeights(int* arr, int s){
    int k;
    printf("Enter k value: ");
    scanf("%d", &k);
    int temp[s];
    for (int i = 0; i<s; i++){
        if(*(arr+i)<=k){
            *(temp+i)=*(arr+i)+k;
        } else {
            *(temp+i) = *(arr+i)-k;
        }
    }

    int max = *(temp+0);
    int min = *(temp+0);
    for (int i = 0; i<s; i++){
        if(*(temp+i)>max){
            max = *(temp+i);
        }
        if(*(temp+i)<min){
            min = *(temp+i);
        }
    }

    printf("%d", max-min);
}

/*5*/ void minimumJumps(int *arr, int s){
    int jump = 0;
    int ctr = 0;
    int i = 0;
    while (ctr<s-1){
        if(*(arr+i)==0){
            printf("-1");
            return;
        }
        ctr+=*(arr+i);
        jump++;
        i+=*(arr+i);
        
    }

    printf("%d ", jump);
}

/*4*/ void smallestPositiveMissing(int* arr, int s){

    for (int i = 0; i<s; i++){
        for (int j = i+1; j<s; j++){
            if(*(arr+i)>*(arr+j)){
                int temp = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = temp;
            }
        }
    }
    
    if(*(arr+(s-1)) == 0){
        printf("Smallest missing positive: 1");
        return;
    }

    for (int i = *(arr+0); i<*(arr+(s-1)); i++){
        int isLoc = 0;
        for (int j = 0; j<s; j++){
            if(i==*(arr+j)){
                isLoc = 1;
                break;
            }
        }
        if(!isLoc){
            if(i>0){
                printf("Smallest missing positive: %d", i);
                break;
            }
        }
    }

}

/*3*/ void sumOfPairsZero(int *arr, int s){
    //sorting
    for (int i  = 1; i<s; i++){
        int temp = *(arr+i);
        int j = i-1;
        while (j>=0 && temp<*(arr+j)){
            *(arr+(j+1)) = *(arr+j) ;
            j--; 
        }
        *(arr+(j+1)) = temp;
    }
    disElem(arr, s);
    printf("\n");
    for (int i = 0; i<s; i++){
        for (int j = i+1; j<s; j++){
            if(*(arr+i)+*(arr+j)==0){
                (*(arr+i)>*(arr+j)) ? printf("[%d, %d] ", *(arr+j), *(arr+i)) : printf("[%d, %d] ", *(arr+i), *(arr+j));
                break;
            }
        }
    }
}

/*2*/ void reverseInGroups(int* arr, int s){
    int n;
    printf("Reverse array in groups of: ");
    scanf("%d", &n);
    
    if(n>s){
        n=s;
    }

    int end, start;
    for (int i = 0; i<s; i+=n){
        start = i;
        end = start+n-1;

        if(end >= s) {
            end = s - 1;
        }

        while(start<end){
            int temp = *(arr+start);
            *(arr+start) = *(arr+end);
            *(arr+end) = temp;
            start++;
            end--;
        }
    }
    disElem(arr, s);
}

/*1*/void subArrayySum(int* arr, int s){
    int n;
    printf("Enter target: ");
    scanf("%d", &n);

    
    for (int i = 0; i<s; i++){
        int temp = *(arr+i);
        int j = i+1;
        if(temp==n){
            printf("[%d, %d]", i+1, i+1);
            return;
        }
        while(temp!=n && j<s){
            temp+=*(arr+j);
            if(temp==n){
                printf("[%d, %d]", i+1, j+1);
                return; 
            } 
            j++;
        }
    }
}

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