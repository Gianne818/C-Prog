#ifndef FINALS_REVIEW_H
#define FINALS_REVIEW_H

typedef struct {
    int r;
    int c;
    int arr[100][100];
} Matrix;

void create(int r, int c, int arr[][100]);
void disElem(int r, int c, int arr[][100]);
void thirdLargestElement(int r, int c, int arr[][100]);
void multiplyMatrices(int r1, int c1, int arr1[][100]);
Matrix multiplyMatricesStruct();
void rowWithMaxSum(int r, int c, int arr[][100]);
void largestSubMatrixwEqualELem(int r, int c, int arr[][100]);
void transposeMatrix(int r, int c, int arr[][100]);
void rotateMatrixClockwise(int r, int c, int arr[][100]);
void rotateMatrixCounterClockwise(int r, int c, int arr[][100]);
void flatten2dArray(int r, int c, int arr[][100]);
void countOccurencesOfElem(int r, int c, int arr[][100]);
void longestConsecutiveSequence(int r, int c, int arr[][100]);

#endif