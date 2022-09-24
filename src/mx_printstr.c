#include "../inc/header.h"

void mx_printstr (char *str) {
    int len = mx_strlen(str);
    for (int i = 0; i < len; i++)
        mx_printchar(str[i]);
}

// int main(void) {
//     mx_printstr("game over");
// }
