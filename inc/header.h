#ifndef  HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int *mx_find_home_way(int **adjacency_matrix, int *min_path, int x2y2, int size);
//void mx_create_final_arr(int **arr, int *len_arr, int *path_arr, int size);
void mx_write_file(int **arr, int rows, int cols);

int **mx_csv_to_arr(char *filename, int *rows_ptr, int *cols_ptr, int *size);
int *mx_find_longest_way(int **adjacency_matrix, int x1y1, int size);
int **mx_adjacency_matrix(int **arr, int *size, int rows, int cols);
bool mx_isdigit(int c);
bool mx_isspace (int c);
int mx_atoi(const char *str);
char *mx_strnew(const int size);
char *mx_strtok(char *string, char delim);
void mx_printerr(const char *s);
int mx_strlen(char *s);
int **mx_create_int_arr(char * filename, int *rows_ptr, int* col_ptr);
void mx_printchar(char c);
void mx_printstr (char *str);
void mx_printint(int n);
void mx_write_output(int x2y2Path, int maxPath);

#endif
