#include "../inc/header.h"

void mx_write_output(int x2y2Path, int maxPath) {

    mx_printstr("dist=");
    mx_printint(maxPath);
    mx_printstr("\n");

    mx_printstr("exit=");
    mx_printint(x2y2Path);
    mx_printstr("\n");
}

