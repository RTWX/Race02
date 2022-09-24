#include "../inc/header.h"

bool mx_isdigit(int c);
bool mx_isspace (int c);

int mx_atoi(const char *str) {
    int res = 0;
    int sign = 1;
    for (int i = 0; str[i] != '\0';  i++) {
        if ( mx_isdigit(str[i]) ) {
            res *= 10; 
            res += str[i] - '0';
        }
        else if (mx_isspace(str[i]))
            continue;
        else if (str[i] == '+')
            sign = 1;
        else if (str[i] == '-')
            sign = -1;
        else 
            break;
    }
    if (sign != 0)
        return res * sign;
    else
        return res;
}

