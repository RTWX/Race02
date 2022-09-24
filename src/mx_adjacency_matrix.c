#include "../inc/header.h"

static void mx_zero_to_matrix(int **matrix, int size) {
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++)
            matrix[i][j] = 0;
    }
}

int **mx_adjacency_matrix(int **arr, int *size, int rows, int cols) {
    int **matrix = (int **)malloc(*size *sizeof(int *));
    for (int i = 0; i < *size; i++) 
        matrix[i] = (int *)malloc(*size *sizeof(int));
        
    mx_zero_to_matrix(matrix, *size);
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] != 999999999) {
                if (i - 1 >= 0 && arr[i - 1][j] != 999999999){
                    matrix[arr[i - 1][j]][arr[i][j]] = 1;
                    matrix[arr[i][j]][arr[i - 1][j]] = 1;
                }
                if (i + 1 < rows && arr[i + 1][j] != 999999999){
                    matrix[arr[i + 1][j]][arr[i][j]] = 1;
                    matrix[arr[i][j]][arr[i + 1][j]] = 1;
                }
                if (j + 1 < cols && arr[i][j + 1] != 999999999){
                    matrix[arr[i][j + 1]][arr[i][j]] = 1;
                    matrix[arr[i][j]][arr[i][j + 1]] = 1;
                }
                if (j - 1 >= 0 && arr[i][j - 1] != 999999999){
                    matrix[arr[i][j - 1]][arr[i][j]] = 1;
                    matrix[arr[i][j]][arr[i ][j- 1]] = 1;
                }
            }
            
        }
    }
    return matrix;
}


