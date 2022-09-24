#include "../inc/header.h"

int *mx_find_longest_way(int **adjacency_matrix, int x1y1, int size) {
    int *min_path = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        min_path[i] = 999999999;

    int *node_check = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        node_check[i] = 0;

    int o = 0;
    int start = x1y1;
    min_path[start] = 0;
    int z = 0;
    for (int j = 0; j < size; j++) { 
        for (int i = 0; i < size; i++)
            if (adjacency_matrix[start][i] != 0 && min_path[i] > (min_path[start] + adjacency_matrix[start][i]) ) { 
                min_path[i] = min_path[start] + adjacency_matrix[start][i];
                int y;
                for (y = 0; y < size; y++)
                    if (i == node_check[y]) { 
                        y = 6; 
                        break; 
                    }
                if (y != 6) { 
                    o++; 
                    node_check[o] = i; 
                }
            }
        start = node_check[z];
        z++;
    }
    free(node_check);
    
    int *paths_arr = min_path;
    return paths_arr;
}

