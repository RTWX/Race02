#include "../inc/header.h"

int **mx_csv_to_arr(char *filename, int *rows_ptr, int *cols_ptr, int *size) {
    int **arr = mx_create_int_arr(filename, rows_ptr, cols_ptr);
    int file = open(filename, O_RDONLY);
    if (file < 0) {
        mx_printerr("map does not exist\n");
        exit(-1);
    }
    char buffer[1024];
    size_t nbytes = sizeof(buffer);
    int file_read = read(file, buffer, nbytes);
    if (close(file) < 0) {
        mx_printerr("error\n");
        exit(-1);
    }
    int j = 0;
    int k = 0;
    int count = 0;
    if (file_read > 0) {
        for(int i = 0; i < file_read; i++) {
            if (buffer[i] != ',' && buffer[i] != '\n') {
                if (buffer[i] == '#')
                    arr[j][k] = 999999999;
                else if (buffer[i] == '.'){
                    arr[j][k] = count;
                    count++;
                }
                else {
                    mx_printerr("map error");
                    exit(-1);
                }
            }
            else 
                continue;
            if (k < *cols_ptr)
                k++;
            if (k == *cols_ptr) {
                j++;
                k = 0;
            }
            if(j >= *rows_ptr)
                break;
        }

    }
    else {
        mx_printerr("map does not exist\n");
        exit(-1);
    }
    *size = count;
    return arr;
}

