#include "../inc/header.h"

int main(int argc, char *argv[])
{
    if (argc != 6) {
        mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
        exit(-1);
    }
    int *rows_ptr = (int *)malloc(sizeof(int *));
    int *cols_ptr = (int *)malloc(sizeof(int *));
    int *size = (int *)malloc(sizeof(int *));

    char *filename = argv[1];
    int **arr =  mx_csv_to_arr(filename, rows_ptr, cols_ptr, size);

    int **matrix = mx_adjacency_matrix(arr, size, *rows_ptr, *cols_ptr);

    int x1 = mx_atoi(argv[2]);
    int y1 = mx_atoi(argv[3]);
    int x2 = mx_atoi(argv[4]);
    int y2 = mx_atoi(argv[5]);

    if ( (x1 >= *cols_ptr || x1 < 0)
            || (y1 >= *rows_ptr || y1 < 0)
            || (x2 >= *cols_ptr || x2 < 0)
            || (y2 >= *rows_ptr || y2 < 0) ) {

        mx_printerr("points are out of map range\n");
        exit(-1);
    }
    if (arr[y1][x1] == 999999999) {
        mx_printerr("entry point cannot be an obstacle\n");
        exit(-1);
    }
    if (arr[y2][x2] == 999999999) {
        mx_printerr("exit point cannot be an obstacle\n");
        exit(-1);
    }

    int *len_arr = mx_find_longest_way(matrix, arr[y1][x1], *size);

    int maxPath = 0;
    for (int i = 0; i < *size; i++)
        if (len_arr[i] > maxPath && len_arr[i] != 999999999)
            maxPath = len_arr[i];
    
    if (len_arr[arr[y2][x2]] == 999999999) {
        mx_printerr("route not found\n");
        exit(-1);
    }
    mx_write_output( len_arr[arr[y2][x2]], maxPath);

    free(rows_ptr);
    free(cols_ptr);
    free(size);
    free(arr);
    free(matrix);
    free(len_arr);
    /*int *path_arr;
    path_arr = (int *)malloc( sizeof(int) * *size);
    for (int i = 0; i < *size; i++)
        path_arr[i] = -1;
    path_arr[0] = arr[x1][y1];
    //mx_printstr("\n");mx_printstr("\n");

    //path_arr = mx_find_home_way(matrix, path_arr, arr[y2][x2], *size);
    //mx_printstr("yyyyyy");mx_printstr("\n");
    //mx_create_final_arr(arr, len_arr, path_arr, *size);
    
    for (int j = 0; j < *size; j++) {
            mx_printint(path_arr[j]);
             mx_printchar(' ');
    }
        mx_printchar('\n');
        mx_printchar('\n');
    // read & save svg into array
    // swap . on * and D || X
    // write array in path.txt
    //int max_len = maxPath;

    for (int i = 0; i < *size; i++) {
        if (len_arr[i] == max_len) {
            int x = 0;
            for (int j = 0; j < *size; j++) {
                if (path_arr[j] == i) {
                    x = 1;
                    for (int ix = 0; ix < *rows_ptr; ix++) {
                        for (int j = 0; j < *cols_ptr; j++) {
                            if (arr[ix][j] == i) {
                                arr[ix][j] = 888888888;
                            }
                        }
                    }
                }
            }
            if (x == 0)
                for (int ix = 0; ix < *rows_ptr; ix++) {
                    for (int j = 0; j < *cols_ptr; j++) {
                        if (arr[ix][j] == i) {
                            arr[ix][j] = 777777777;
                        }
                    }
                }
        }
    }
    //mx_printstr("iiiiiiii");mx_printstr("\n");
    for (int i = 0; i < *rows_ptr; i++) {
        for (int j = 0; j < *cols_ptr; j++) {

            for (int n = 0; n < *size; n++) {
                if (path_arr[n] == arr[i][j]) {
                    arr[i][j] = 666666666;
                    break;
                    // in arr swap on * code
                }
            }

        }
    }
    //mx_printstr("ppppppp");mx_printstr("\n");
    //mx_write_file(arr, *rows_ptr, *cols_ptr);
    //mx_printstr("xxxx");mx_printstr("\n");*/
}

