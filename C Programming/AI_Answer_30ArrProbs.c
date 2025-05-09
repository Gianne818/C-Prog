#include <stdio.h>
#include <stdlib.h>

// Function Declarations
void rotateElemLeft(int arr[], int s);
void intersectionOfArrays(int arr1[], int size1, int arr2[], int size2);
void maxDifference(int arr[], int size);
void moveNegativesToFront(int arr[], int size);
void countDistinct(int arr[], int size);
void reverseSubarray(int arr[], int size);
void sumOfUniqueElements(int arr[], int size);
void sort012(int arr[], int size);
void pairsWithGivenSum(int arr[], int size);
void subarrayWithZeroSum(int arr[], int size);
void swapAlternate(int arr[], int size);
void firstRepeatingElement(int arr[], int size);
void findTriplets(int arr[], int size);
void maxProduct(int arr[], int size);
void replaceWithGreatest(int arr[], int size);
void kthSmallestElement(int arr[], int size);
void shuffleArray(int arr[], int size);
void countPairsWithDifference(int arr[], int size);
void largestRectangleArea(int heights[], int size);
void longestIncreasingSubsequence(int arr[], int size);
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2);
void productExceptSelf(int arr[], int size);
void rearrangeArray(int arr[], int size);
void minimumPlatforms(int arrival[], int departure[], int n);
void findPeakElement(int arr[], int size);
void searchRotatedSortedArray(int arr[], int size);
void findDuplicates(int arr[], int size);
void subarrayWithSum(int arr[], int size);
void longestConsecutiveSequence(int arr[], int size);
void countSubsetsWithSum(int arr[], int size);

int main() {
    int arr[100], arr1[100], arr2[100], size;
    int arrival[100], departure[100];
    
    // Call any function for testing here as needed
    // Example for Rotate Array
    printf("Enter number of elements in the array: ");
    scanf("%d", &size);
    printf("Enter array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    rotateElemLeft(arr, size);
    
    // You can uncomment and call other functions similarly
    // intersectionOfArrays(arr1, size1, arr2, size2);
    // maxDifference(arr, size);
    
    return 0;
}

// Function Implementations
void rotateElemLeft(int arr[], int s) {
    int k;
    printf("Enter number of positions to rotate left: ");
    scanf("%d", &k);
    k = k % s;  // Handle cases where k >= size
    int temp[100];
    
    for (int i = 0; i < k; i++) {
        int first = arr[0];  // Store the first element
        for (int j = 0; j < s - 1; j++) {
            arr[j] = arr[j + 1];  // Shift elements to the left
        }
        arr[s - 1] = first;  // Move the first element to the end
    }
    printf("Rotated array: ");
    for (int i = 0; i < s; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void intersectionOfArrays(int arr1[], int size1, int arr2[], int size2) {
    int intersection[100], idx = 0;
    
    printf("Enter elements for first array: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }
    
    printf("Enter elements for second array: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                int alreadyExists = 0;
                for (int x = 0; x < idx; x++) {
                    if (intersection[x] == arr1[i]) {
                        alreadyExists = 1;
                        break;
                    }
                }
                if (!alreadyExists) {
                    intersection[idx++] = arr1[i];
                }
            }
        }
    }

    printf("Intersection: ");
    for (int i = 0; i < idx; i++) {
        printf("%d ", intersection[i]);
    }
    printf("\n");
}

void maxDifference(int arr[], int size) {
    int maxDiff = arr[1] - arr[0];
    int minElement = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] - minElement > maxDiff) {
            maxDiff = arr[i] - minElement;
        }
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }
    printf("Maximum difference: %d\n", maxDiff);
}

void moveNegativesToFront(int arr[], int size) {
    int temp[100], j = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            temp[j++] = arr[i];
        }
    }
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 0) {
            temp[j++] = arr[i];
        }
    }
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
    printf("Array after moving negatives to front: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void countDistinct(int arr[], int size) {
    int temp[100], count = 0;

    for (int i = 0; i < size; i++) {
        int found = 0;
        for (int j = 0; j < count; j++) {
            if (arr[i] == temp[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            temp[count++] = arr[i];
        }
    }
    printf("Number of distinct elements: %d\n", count);
}

void reverseSubarray(int arr[], int size) {
    int l, r;
    printf("Enter indices to reverse (l, r): ");
    scanf("%d %d", &l, &r);

    while (l < r) {
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    }

    printf("Array after reversing subarray: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sumOfUniqueElements(int arr[], int size) {
    int temp[100], sum = 0, count = 0;

    for (int i = 0; i < size; i++) {
        int found = 0;  
        for (int j = 0; j < count; j++) {
            if (arr[i] == temp[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            temp[count++] = arr[i];
            sum += arr[i];
        }
    }
    printf("Sum of unique elements: %d\n", sum);
}

void sort012(int arr[], int size) {
    int count0 = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) count0++;
        else if (arr[i] == 1) count1++;
        else count2++;
    }

    for(int i = 0; i < count0; i++) arr[i] = 0;
    for(int i = count0; i < count0 + count1; i++) arr[i] = 1;
    for(int i = count0 + count1; i < size; i++) arr[i] = 2;

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void pairsWithGivenSum(int arr[], int size) {
    int target;
    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("Pairs with sum %d: ", target);
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == target) {
                printf("(%d, %d) ", arr[i], arr[j]);
            }
        }
    }
    printf("\n");
}

void subarrayWithZeroSum(int arr[], int size) {
    int current_sum = 0;
    for (int i = 0; i < size; i++) {
        current_sum += arr[i];
        if (current_sum == 0) {
            printf("Subarray with zero sum found.\n");
            return;
        }
        for (int j = 0; j < i; j++) {
            if (current_sum - arr[j] == 0) {
                printf("Subarray with zero sum found.\n");
                return;
            }
        }
    }
    printf("No subarray with zero sum exists.\n");
}

void swapAlternate(int arr[], int size) {
    for (int i = 0; i < size - 1; i += 2) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }

    printf("Array after swapping: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void firstRepeatingElement(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                printf("First repeating element: %d\n", arr[i]);
                return;
            }
        }
    }
    printf("No repeating element found.\n");
}

void findTriplets(int arr[], int size) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            for (int k = j + 1; k < size; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    printf("Triplet: (%d, %d, %d)\n", arr[i], arr[j], arr[k]);
                    found = 1;
                }
            }
        }
    }
    if (!found) {
        printf("No triplet found.\n");
    }
}

void maxProduct(int arr[], int size) {
    int max1 = 0, max2 = 0;

    for(int i = 0; i < size; i++) {
        if(arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if(arr[i] > max2) {
            max2 = arr[i];
        }
    }
    printf("Maximum product of two elements: %d\n", max1 * max2);
}

void replaceWithGreatest(int arr[], int size) {
    int maxFromRight = -1;
    
    for (int i = size - 1; i >= 0; i--) {
        int current = arr[i];
        arr[i] = maxFromRight;
        if (current > maxFromRight) {
            maxFromRight = current;
        }
    }
    
    printf("Array after replacement: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void kthSmallestElement(int arr[], int size) {
    int k;
    printf("Enter k: ");
    scanf("%d", &k);

    int temp[100];
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }

    // Simple bubble sort to find the kth smallest element
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }
    
    printf("%dth smallest element: %d\n", k, temp[k - 1]);
}

void shuffleArray(int arr[], int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    printf("Shuffled array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void countPairsWithDifference(int arr[], int size) {
    int d;
    printf("Enter difference: ");
    scanf("%d", &d);

    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (abs(arr[i] - arr[j]) == d) {
                count++;
            }
        }
    }
    
    printf("Number of pairs with difference %d: %d\n", d, count);
}

void largestRectangleArea(int heights[], int size) {
    // Placeholder for the example
    int area = 0; // Implementation would require handling
    printf("Largest rectangle area (placeholder): %d\n", area);
}

void longestIncreasingSubsequence(int arr[], int size) {
    int lis[100];
    for (int i = 0; i < size; i++) {
        lis[i] = 1;
    }

    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }
    
    int maxLis = 0;
    for (int i = 0; i < size; i++) {
        if (lis[i] > maxLis) {
            maxLis = lis[i];
        }
    }
    printf("Length of longest increasing subsequence: %d\n", maxLis);
}

void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2) {
    int merged[200], i = 0, j = 0, k = 0;

    printf("Enter elements for first sorted array: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }
    
    printf("Enter elements for second sorted array: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    
    while (i < size1) {
        merged[k++] = arr1[i++];
    }
    
    while (j < size2) {
        merged[k++] = arr2[j++];
    }
    
    printf("Merged sorted array: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");
}

void productExceptSelf(int arr[], int size) {
    int left[100], right[100], product[100];

    left[0] = 1;
    for (int i = 1; i < size; i++) {
        left[i] = left[i - 1] * arr[i - 1];
    }
    
    right[size - 1] = 1;
    for (int i = size - 2; i >= 0; i--) {
        right[i] = right[i + 1] * arr[i + 1];
    }
    
    for (int i = 0; i < size; i++) {
        product[i] = left[i] * right[i];
    }
    
    printf("Product array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", product[i]);
    }
    printf("\n");
}

void rearrangeArray(int arr[], int size) {
    int temp[100];
    int start = 0, end = size - 1;

    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            temp[i] = arr[end--];
        } else {
            temp[i] = arr[start++];
        }
    }
    
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }

    printf("Rearranged array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void minimumPlatforms(int arrival[], int departure[], int n) {
    int platforms_needed = 0, max_platforms = 0;
    int i = 0, j = 0;

    printf("Enter arrival and departure times: \n");
    for (int k = 0; k < n; k++) {
        printf("Arrival time for train %d: ", k + 1);
        scanf("%d", &arrival[k]);
        printf("Departure time for train %d: ", k + 1);
        scanf("%d", &departure[k]);
    }

    while (i < n && j < n) {
        if (arrival[i] < departure[j]) {
            platforms_needed++;
            i++;
            if (platforms_needed > max_platforms) {
                max_platforms = platforms_needed;
            }
        } else {
            platforms_needed--;
            j++;
        }
    }

    printf("Minimum platforms required: %d\n", max_platforms);
}

void findPeakElement(int arr[], int size) {
    if (size == 1) {
        printf("Peak element: %d\n", arr[0]);
        return;
    }

    for (int i = 0; i < size; i++) {
        if ((i == 0 || arr[i] >= arr[i - 1]) && (i == size - 1 || arr[i] >= arr[i + 1])) {
            printf("Peak element: %d\n", arr[i]);
            return;
        }
    }
    printf("No peak element found.\n");
}

void searchRotatedSortedArray(int arr[], int size) {
    int target;
    printf("Enter target: ");
    scanf("%d", &target);

    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            printf("Target found at index: %d\n", mid);
            return;
        }

        // Determine which side is sorted
        if (arr[left] <= arr[mid]) {
            if (arr[left] <= target && target < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (arr[mid] < target && target <= arr[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    printf("Target not found.\n");
}

void findDuplicates(int arr[], int size) {
    int temp[100], count = 0;
    printf("Duplicates: ");
    
    for (int i = 0; i < size; i++) {
        int exists = 0;
        for (int j = 0; j < count; j++) {
            if (arr[i] == temp[j]) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
            for (int j = i + 1; j < size; j++) {
                if (arr[i] == arr[j]) {
                    printf("%d ", arr[i]);
                    temp[count++] = arr[i];
                    break;
                }
            }
        }
    }
    printf("\n");
}

void subarrayWithSum(int arr[], int size) {
    int sum;
    printf("Enter target sum: ");
    scanf("%d", &sum);
    
    for (int i = 0; i < size; i++) {
        int current_sum = arr[i];
        if (current_sum == sum) {
            printf("Subarray found with the given sum.\n");
            return;
        }
        for (int j = i + 1; j < size; j++) {
            current_sum += arr[j];
            if (current_sum == sum) {
                printf("Subarray found with the given sum.\n");
                return;
            }
        }
    }
    printf("No subarray found with the given sum.\n");
}

void longestConsecutiveSequence(int arr[], int size) {
    int temp[100], count = 0;

    for (int i = 0; i < size; i++) {
        int found = 0;
        for (int j = 0; j < count; j++) {
            if (arr[i] == temp[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            temp[count++] = arr[i];
        }
    }

    // Sort array
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    int longest_streak = 1, current_streak = 1;

    for (int i = 1; i < count; i++) {
        if (temp[i] == temp[i - 1] + 1) {
            current_streak++;
        } else if (temp[i] != temp[i - 1]) {
            if (current_streak > longest_streak) {
                longest_streak = current_streak;
            }
            current_streak = 1;
        }
    }
    
    if (current_streak > longest_streak) {
        longest_streak = current_streak;
    }

    printf("Length of longest consecutive sequence: %d\n", longest_streak);
}

void countSubsetsWithSum(int arr[], int size) {
    int target;
    printf("Enter target sum: ");
    scanf("%d", &target);

    int total_subsets = 1 << size; // 2^size
    int count = 0;

    for (int i = 0; i < total_subsets; i++) {
        int subset_sum = 0;
        for (int j = 0; j < size; j++) {
            if (i & (1 << j)) { // Check if jth element is in the subset
                subset_sum += arr[j];
            }
        }
        if (subset_sum == target) {
            count++;
        }
    }
    printf("Number of subsets with sum %d: %d\n", target, count);
}
