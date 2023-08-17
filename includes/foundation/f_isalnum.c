#include "foundation.h"

int     f_isalnum(char c) {
    int    is_num;
    int    is_alpha;

    is_num = f_isdigit(c);
    is_alpha = f_isalpha(c);
    return ((is_num || is_alpha) ? 1 : 0);
}