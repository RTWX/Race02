#include "../inc/header.h"

char *mx_strnew(const int size) {
    if (size < 1)
        return NULL;

    char *temp = (char *)malloc(size + 1);

    for (int i = 0; i <= size; i++)
        temp[i] = '\0';
    return temp;
}

// int main(void) {
//     printf("%s", mx_strnew(4));
// }
