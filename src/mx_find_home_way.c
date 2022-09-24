#include "../inc/header.h"

int *mx_find_home_way(int **adjacency_matrix, int *min_path, int x2y2, int size) {

    int min_path_last = min_path[0];
    int mpi = 0;
    
    for (int start = min_path_last; start < size;) { //

        int *min_path_next;
        if (adjacency_matrix[start][x2y2] == 1) {
            min_path_next = (int *)malloc(sizeof(int) * size); // 

            for (int i = 0; i < size; i++)
                min_path_next[i] = min_path[i];

            for (int i = 0; i < size; i++)
                if (min_path_next[i] == -1) {
                    min_path_next[i] = x2y2;
                    break;
                } 
            return min_path_next;
        }
        for (int node = start + 1; node < size; node++) { // obhod odnoi stroki
            for (mpi = 0; mpi < size && min_path[mpi] != -1; mpi++)
                min_path_last = min_path[mpi];

            if (adjacency_matrix[start][node] == 1) {
                min_path_next = (int *)malloc(sizeof(int) * size); // 
                for (int i = 0; i < size; i++)
                    min_path_next[i] = min_path[i];

                for (int i = 0; i < size; i++)
                    if (min_path_next[i] == -1) {
                        min_path_next[i] = node;
                        break;
                    }
                mx_printchar('\n');
                mx_printchar('^');
                for (int j = 0; j < size; j++) {
                    mx_printint(min_path_next[j]);
                    mx_printchar(' ');
                }
                    mx_printchar('\n');
                    mx_printchar('\n');
                
                min_path_next = mx_find_home_way(adjacency_matrix, min_path_next, x2y2, size);
                // for (int i = 0; i < size; i++)
                //     if (min_path_next[i] == -1) {
                //         min_path_next[i] = node;
                //         break;
                //     }
                // start = node;
                // break;
                int last1 = -1;
                int i = 0;
                for ( ; i < size && min_path_next[i] != -1; i++) // last
                    last1 = min_path_next[i];
                //printf(" %i ", last1);

                if (last1 != x2y2 && min_path_last != x2y2 && mpi < i)
                    min_path = min_path_next;

                if (last1 == x2y2 && min_path_last != x2y2)
                    min_path = min_path_next;

                else if (last1 == x2y2 && min_path_last == x2y2)
                    if (i < mpi)
                        min_path = min_path_next;
                    else
                        free(min_path_next);
                else
                    free(min_path_next);
            }
        }
        return min_path;
    }
    return min_path;
}
