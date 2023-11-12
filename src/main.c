#include "foundation.h"
#include <stdio.h>

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

/*
** process calc
1. declare v_space char*
2. declare r_space char**
3. generate p_space (v_space, r_space) => p_space
4. generate simple example:
      |   | .
    . | . | 
      |   | .
    . | . | 
      |   | .
    . | . | 
      |   | .
    . | . | 

5. paramaterize/generalize for following examples:
    0 | 0 | 1
    1 | 1 | 0 
    0 | 0 | 1
    1 | 1 | 0 
    
    0 0 | 0 0 | 1 0
    1 0 | 1 0 | 0 1
    0 1 | 0 1 | 1 1
    1 1 | 1 1 | 0 0


- single liminal expression
    | 1 | 1 | 0 | 0 
  0 | 0 | 0 | 1 |
    | 1 | 1 | 0 | 
    | 0 | 0 | 1 | 1
  1 | 1 | 1 | 0 |
    | 0 | 0 | 0 |
    | 1 | 1 | 0 | 0
  0 | 0 | 0 | 1 |
    | 1 | 1 | 0 | 
    | 0 | 0 | 1 | 1
          p	  p	  F
          p	  F
          F
*/

/*
**  new process, determinate selector where (~ (= (f f)))
*/

/*
HL plan: 
    0. gen p_space
    1. succession (prev_evaluation, p_space, pidx, sidx) => **char
        declare variable for observation
        declare variable for evaluation

        observation = previous_evaluation
        if (= (F F) F)
            evaluation = observation
        else (~ (= (F F)))
            evaluation = select(observation, p_space, 'determinate' | 'model')
*/


int raise (int b, int p) {
    if (!p){
        return 1;
    }
    return (b * raise(b, p - 1));
}

/*
** populate p_space
*/

char **td_array_cpy(char **arr) {
    size_t     i;
    char    **new;
    size_t  len;
    
    len = f_array_len(arr);
    new = (char**)f_memalloc(sizeof(char*) * len);
    
    i = 0; 
    while (i < len) {
        new[i] = f_strdup(arr[i]);
        i ++;
    }
    return (new);
}

char ***f (char ***res, char **cur, char **v_space, char **r_space, size_t i, size_t j, size_t r_len, size_t *p_idx) {
    if (j == f_array_len(v_space)) {
        res[*p_idx] = td_array_cpy(cur);
        p_idx++;
        return res;
    }

    while (i < r_len) {
        cur[i] = f_strdup(v_space[j]);
        f(res, cur, v_space, r_space, i, j + 1, r_len, p_idx);
        i++;
    }
    return (res);
}

void display_p_space(char ***p_space, int rlen) {
    int i;
    int j;

    i = 0;
    while (*(p_space + i) != NULL) {
        j = 0;
        while (j < rlen) {
            f_putstr(p_space[i][j++]);
        }
    }
}

char ***gen_p_space(char **v_space, char **r_space, int rlen, int vlen) {
    int         plen;
    size_t      *p_idx;
    char        ***p_space;
    char        **tmp_row;
    
    plen = raise(rlen, vlen);
    p_idx = (size_t*)f_memalloc(sizeof(size_t*));
    *p_idx = 0;

    //allocate matrix for pspace
    p_space = (char***)f_memalloc( sizeof(char**) * plen + 1);
    p_space[plen] = NULL;
    tmp_row = (char**)f_memalloc(sizeof(char*) * rlen + 1);
    f(p_space, tmp_row, v_space, r_space, 0, 0, f_array_len(r_space), p_idx);
    display_p_space(p_space, rlen);
    return (p_space);
}

char **new_process(char **v_space, char **r_space) {
    char    ***p_space;
    int     vlen;
    int     rlen;

    vlen = f_array_len(v_space);
    rlen = f_array_len(r_space);
    p_space = gen_p_space(v_space, r_space, rlen, vlen);

    display_p_space(p_space, rlen);
    return (*p_space);
}

int     main (int argc, char **argv) {
    //char    *meta;
    char    *prima;
    char    *sucessions;
    char    *notation;
    char    **v_space;
    char    **r_space;

    if (argc < 2){
        return 0;
    }
    
    prima = argv[2];
    sucessions = argv[1];
    notation = argv[3];

    v_space = (char**)f_memalloc(sizeof(char*) * 3);
    r_space = (char**)f_memalloc(sizeof(char*) * 3);

    v_space[2] = NULL;
    v_space[0] = f_strdup("0");
    v_space[1] = f_strdup("1");

    r_space[2] = NULL;
    r_space[0] = "r";
    r_space[1] = "q";

    new_process(v_space, r_space);
    //meta = generation(prima, parse_num(sucessions), notation);
    //f_putendl(meta);

    return (0);
}