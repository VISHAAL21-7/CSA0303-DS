#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void matrixMultiplication(int mat1[][MAX_COLS], int mat2[][MAX_COLS], int res[][MAX_COLS], 
                         int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Error: Matrix dimensions incompatible for multiplication!\n");
        printf("Columns of first matrix must equal rows of second matrix.\n");
        return;
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void printMatrix(int mat[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[MAX_ROWS][MAX_COLS], mat2[MAX_ROWS][MAX_COLS], res[MAX_ROWS][MAX_COLS];
    int rows1, cols1, rows2, cols2;

    printf("Enter dimensions of first matrix (rows columns): ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter dimensions of second matrix (rows columns): ");
    scanf("%d %d", &rows2, &cols2);

    printf("Enter elements of second matrix:\n");
    for (int i =  0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Check if multiplication is possible
    if (cols1 != rows2) {
        printf("\nMatrix multiplication not possible!\n");
        printf("Columns of first matrix (%d) must equal rows of second matrix (%d).\n", cols1, rows2);
        return 1;
    }

    matrixMultiplication(mat1, mat2, res, rows1, cols1, rows2, cols2);

    printf("\nFirst Matrix:\n");
    printMatrix(mat1, rows1, cols1);

    printf("\nSecond Matrix:\n");
    printMatrix(mat2, rows2, cols2);

    printf("\nResultant Matrix:\n");
    printMatrix(res, rows1, cols2);

    return 0;
}