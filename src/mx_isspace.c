#include "../inc/header.h"

bool mx_isspace (int c) {
    if (c >= 9 && c <= 13) {
        return 1;
    } else if (c == 32){
	return 1;
    } else {
        return 0;
    }
}

