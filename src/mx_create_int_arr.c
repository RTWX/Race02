#include "../inc/header.h"

int **mx_create_int_arr(char * filename, int *rows_ptr, int* cols_ptr) {
    int file = open(filename, O_RDONLY);
    if (file < 0) {
        mx_printerr("map does not exist\n");
        exit(-1);
    }
    int rows = 0;
    int cols = 0;
    char buffer[1024];
    size_t nbytes = sizeof(buffer);
    int file_read = read(file, buffer, nbytes);
    if (file_read > 0) {
        int count_col = 0;
        for (int i = 0; i < file_read; i++) {
            if ( buffer[i] != '\n' && buffer[i] != '#' 
                    && buffer[i] != ',' && buffer[i] != '.') {
                mx_printerr("map error\n");
                exit(-1);
            }
            if (buffer[i] == '\n'){
                if (cols == 0)
                    cols = count_col;
                if (cols != 0 && cols != count_col) {
                    mx_printerr("map error\n");
                    exit(-1);
                }
                rows++;
                count_col = 0;
            }            
            else if (buffer[i] != ',')
                count_col++;
        }

    }
    else {
        mx_printerr("map does not exist\n");
        exit(-1);
    }
    if (close(file) < 0) {
        mx_printerr("error\n");
        exit(-1);
    }
    int **arr = (int **)malloc(rows *sizeof(int *));
    for (int i = 0; i < rows; i++) 
        arr[i] = (int *)malloc(cols *sizeof(int));
    *rows_ptr = rows;
    *cols_ptr = cols;

    return arr;  
}    

