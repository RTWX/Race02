#include "../inc/header.h"


void mx_write_file(int **arr, int rows, int cols) {
    //mx_printstr("ttttttttt");mx_printstr("\n");
    int file = open("path.txt", O_CREAT | O_TRUNC, 00777);
    if (file < 0) {
        mx_printerr("error\n");
        exit(-1);
    }
    /*for (int i = 0; i < cols; i++) {

        for (int j = 0; j < rows; j++) {
            if (arr[i][j] > 100000) 
                mx_printint(-1);
            else
                mx_printint(arr[i][j]);
            mx_printstr("\t   ");
        }
        mx_printstr("\n");
    }*/
    char c;
    //mx_printstr("sssss");mx_printstr("\n");
        for (int i = 0; i < rows; i++) {
            
            for (int j = 0; j < cols; j++) {
                if (arr[i][j] == 999999999) {
                    c = '#';
                    write(file, (void *)&c, 1);
                }
                else if (arr[i][j] == 888888888) {
                    c = 'X';
                    write(file, (void *)&c, 1);
                }
                else if (arr[i][j] == 777777777) {
                    c = 'D';
                    write(file, (void *)&c, 1);
                }
                else if (arr[i][j] == 666666666) {
                    c = '*';
                    write(file, (void *)&c, 1);
                }
                else {
                    c = '.';
                    write(file, (void *)&c, 1);
                }
                // if (err <= 0) {
                //     mx_printerr("error\n");
                //     exit(-1);
                // }
            }
            //mx_printstr("bbbbbb");mx_printstr("\n");
            c = '\n';
            write(file, (void *)&c, 1);
        }
    if (close(file) < 0) {
        mx_printerr("error\n");
        exit(-1);
    }
}

