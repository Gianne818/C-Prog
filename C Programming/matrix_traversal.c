#include <stdio.h>

// Spiral traversal from outer to inner
void spiralTraversal(int rows, int cols, int matrix[rows][cols]) {
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    
    while (top <= bottom && left <= right) {
        // Traverse from left to right on top row
        for (int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;
        
        // Traverse from top to bottom on right column
        for (int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;
        
        if (top <= bottom) {
            // Traverse from right to left on bottom row
            for (int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }
        
        if (left <= right) {
            // Traverse from bottom to top on left column
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }
    printf("\n");
}

// Spiral traversal from center moving outward
void spiralFromCenter(int rows, int cols, int matrix[rows][cols]) {
    int layers = (rows < cols ? rows : cols) / 2;
    int centerRow = rows / 2;
    int centerCol = cols / 2;
    
    printf("%d ", matrix[centerRow][centerCol]);
    
    for (int layer = 1; layer <= layers; layer++) {
        // Start position for this layer
        int row = centerRow - layer;
        int col = centerCol - layer;
        
        // Move right
        for (int i = 0; i < 2 * layer; i++) {
            if (row >= 0 && row < rows && col >= 0 && col < cols) {
                printf("%d ", matrix[row][col]);
            }
            col++;
        }
        
        // Move down
        for (int i = 0; i < 2 * layer; i++) {
            if (row >= 0 && row < rows && col >= 0 && col < cols) {
                printf("%d ", matrix[row][col]);
            }
            row++;
        }
        
        // Move left
        for (int i = 0; i < 2 * layer; i++) {
            if (row >= 0 && row < rows && col >= 0 && col < cols) {
                printf("%d ", matrix[row][col]);
            }
            col--;
        }
        
        // Move up
        for (int i = 0; i < 2 * layer; i++) {
            if (row >= 0 && row < rows && col >= 0 && col < cols) {
                printf("%d ", matrix[row][col]);
            }
            row--;
        }
    }
    printf("\n");
}

// Border traversal in spiral manner
void borderSpiralTraversal(int rows, int cols, int matrix[rows][cols]) {
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    
    // while (top <= bottom && left <= right) {
        // Traverse top border left to right
        for (int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;
        // Traverse right border top to bottom (excluding first element)
        for (int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;
        if (top < bottom) {
            // Traverse bottom border right to left (excluding first element)
            for (int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }
        
        if (left < right) {
            // Traverse left border bottom to top (excluding first element)
            for (int i = bottom - 1; i > top; i--) {
                printf("%d ", matrix[i][left]);
                left++;
            }
        }
    printf("\n");
}

// Border traversal row by row
void borderRowTraversal(int rows, int cols, int matrix[rows][cols]) {
    // Top border
    for (int i = 0; i < cols; i++) {
        printf("%d ", matrix[0][i]);
    }
    
    // Right border (excluding first and last elements)
    for (int i = 1; i < rows - 1; i++) {
        printf("%d ", matrix[i][cols - 1]);
    }
    
    // Bottom border (if there is one, in reverse)
    if (rows > 1) {
        for (int i = cols - 1; i >= 0; i--) {
            printf("%d ", matrix[rows - 1][i]);
        }
    }
    
    // Left border (excluding first and last elements, in reverse)
    if (cols > 1) {
        for (int i = rows - 2; i > 0; i--) {
            printf("%d ", matrix[i][0]);
        }
    }
    printf("\n");
}

int main() {
    // Example matrix
    int rows = 4, cols = 4;
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    printf("Spiral Traversal: ");
    spiralTraversal(rows, cols, matrix);
    
    printf("Spiral from Center: ");
    spiralFromCenter(rows, cols, matrix);
    
    printf("Border Spiral Traversal: ");
    borderSpiralTraversal(rows, cols, matrix);
    
    printf("Border Row Traversal: ");
    borderRowTraversal(rows, cols, matrix);
    
    return 0;
}