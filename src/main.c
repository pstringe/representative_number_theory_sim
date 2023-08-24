#include "foundation.h"
#include <stdio.h>

typedef struct   s_global {
    char    *meta;
    char    *prima;
    char    *sucessions;
    char    *notation;
}                t_global;

int     calc_weight(char *num) {
    int base;
    int i;

    i = f_strlen(num);
    base  = 1;
    while (--i) {
        base *= 10;
    } 
    return (base);
}

/*
char    *prepend(char *src, char *dst, size_t len) {
    int     i;

    dst[0] = 'm';
    dst[1] = '(';
    dst[len - 1] = ')';

    i = 2;
    while (i < len) {
        dst[i] = src;
    }
    return (dst);
}
*/

int     parse_num(char *num) {
    int     n;
    int     i;
    int     base;
    int     digit;

    base = calc_weight(num);
    i = 0;
    n = 0;
    while (base && *(num + i)) {
        digit = (int)(num[i] - 48);
        n += base * digit;
        base /= 10;
        i++;
    }
    return (n);
}

char    *succeed(char *src, char *notation) {
    int     i;
    int     len;
    char    *dst;

    len = f_strlen(src);
    dst = f_strnew(len + 3);
    
    dst[0] = f_strcmp(notation, "infix") == 0 ? 'm' : '(';
    dst[1] = f_strcmp(notation, "infix") == 0 ? '(' : 'm';
    dst[len + 2] = ')';

    i = 1;
    while (++i < len + 2) {
        dst[i] = *(src + i - 2);
    }
    return (dst);
}

char    *f_strdup(char *s){
    int    len;
    int     i;
    char    *dup;

    len = f_strlen(s);
    dup = f_strnew(len);
    i = 0;
    while (i < len) {
        dup[i] = s[i];
        i++;
    }
    return (dup);
}

char    *generation(char *prima, int sucessions, char *notation) {
    int     i;
    char    *tmp;
    char    *meta;
    
    meta = f_strdup(prima);
    i = 0;
    while (i++ < sucessions) {
        tmp = f_strdup(meta);
        f_bzero(meta, f_strlen(meta));
        meta = succeed(tmp, notation);
    }
    return(meta);
}

t_global        *display_menu(t_global *data) {
    f_putstr("Please select and option for displaying the delusion of the prima representation");
    f_putendl("1. determinate sucessions");
    f_putendl("2. hallucinatory sucessions");
    return (data);
}

struct s_global *init(struct s_global *global, char *prima, char *sucessions, char *notation) {
    global = f_memalloc(sizeof(struct s_global));
    global->prima = prima;
    global->sucessions = sucessions;
    global->notation = notation;
    global->meta = generation(
        global->prima, 
        parse_num(global->sucessions), 
        global->notation
    );
    return (global);
}

/*
** For now, we will use arrays ot represent pluralitiess,,,,,,,,,,,,,,,dd
*/

int          main (int argc, char **argv) {
    t_global    *global;
    
    if (argc < 2){
        return 0;
    }
    global = NULL;
    global = init(global, argv[2], argv[1], argv[3]);
    display_menu(global);
    
    f_putendl(global->meta);
    return (0);
}