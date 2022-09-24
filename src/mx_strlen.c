// #include <stdio.h>

int mx_strlen(char *s) {
    int i = 0;
    while (*s != '\0'){
        i++;
        s++;
    }
    return i;
}

// int main (void) {
//     printf("%d", mx_strlen("game over"));
// }
