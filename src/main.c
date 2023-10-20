#include "foundation.h"
#include <stdio.h>

/*
** Data structure for representative number
*/

typedef struct   s_global {
    char    *meta;
    char    *prima;
    char    *sucessions;
    char    *notation;
    int     *option;
}                t_global;

/*
** Expressable abstraction of  of information, pointed to by
** *representation.
*/

typedef struct  s_abstraction {
    char                    *symbol;
    void                    *representation;
    struct s_abstraction    *expression;
}               t_abstraction;

/*
** Structure represents a proposition as a plurality of 
** abstractions symbolically represented using a character array
*/

typedef struct  s_proposition {
    char                    *val;
    struct s_abstraction    *plurality;
}               t_abstraction;

/*
**  Process related meta-representations
*/

typedef struct  s_sucession {
    struct s_process        *process;
    struct s_observattion   *s_observation;
}               t_sucession;

typedef struct  s_process {
    int                     *v_space;
    struct s_proposition    **r_space;
    struct s_space          **posibility_space;
    struct s_abstraction    **observations;                                                                                         
}               t_sucession;

/*
** After dfining process data structure.
*** code a routine of prioritiaztion by dividing the day into 4 qudrants.
*** Develop meta-logic
*** Develop spatial representation positional calc
*/

int     (char *num) {
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
** This function reads a string and returns an integer
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

/*
** Given a string representation of an RTN number, and string indicating
** whether the notation should be prefix or infix, returns a sucession of 
** the number in RTN as a string
*/

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

/*
**   
*/

char     **new_row(propositions, n, m) {
    int     m;
    int     i;
    int     j;
    char    **arr;

    arr = (char**)f_memalloc([]);
    while (i < n) {
        arr[i] = (char*)f_memalloc(sizeof((char *)));
        while (j < m) {
            //gen val given prop in rtn
            succeed("q", 1, "infix");
            //gen val given prop in rtn
            succeed("r", 1, "infix");
        }
    }
    return (arr)
}

/*
** Given a value space, (p (m p))
** The number of rows in the possibility space is doubled when a prop is added
** 1 - 2
** 2 - 4
** 3 - 8
**   .
**   . 
**   .
** The length of each row will always by the number of propositions

/*
** Given a representaiton in RTN a, hallucinates a meta-representation
** Tests
** Given:
    (:= A
        (:= 
            V # value space
            (
                p 
                (m p)
            )
        )
        (:=
            R # propostions space
            (
                p
                q
            )
        )
    )

    (:= S
        (p-space
            V
            R
        ) # => (
            (p , p),
            (p, (m p)),
            ((m p), p),
            ((m p), (m p)),
        )
    )

    char** V = ["p", "(m p)"]
    char** R = ["p", "q"]
    char*** S = [
            ["p" , "p"],
            ["p", "(m p)"],
            ["(m p)", "p"]],
            ["(m p)", "(m p)"],
        ]
    prop_index = 0
    val_index = 0
    p_space = NULL

    NOTES:
    
    High Level Procedure f
    1. If p_space is NULL, Declare an 2D char* matrix, p_space, 
        dimensions: len(propositions) * (len(value_space) ** 2)
    2. Given the space of propositions,
        Select each
        Call f(V R,)

*/

char    **generate_possibility_space(char **value_space, char **propositions) {  //[p [m p]] [p r]
    int     n;
    int     m;
    int     r;
    int     i;
    int     j;
    char    **possibility_space;

    n = f_array_len(value_space);
    m = f_array_len(propositions);
    possibility_space = [];

    if (n < 2) {
        return NULL;
    }

    i = 1;
    r = 2;

    while (i++ < m) {
        r *= 2;
    }

    possibility_space = f_memalloc((char**)(r + 1));
    possibility_space[r] = NULL;
    
    /*
    [
        ['p', 'p'],
        ['p', '(m p)'],
        ['(m p)', 'p'],
        ['(m p), (m p)]
    ]ss
    */

    i = 0;
    j = 0;

    while (i < r) {
        possibility_space[i] = new_row(m);
        while (j < i){
                    
            j++;
        }
        i++;
    }

    return possibility_space;
}

/*
** Doubting everything you code when you are a hallucination
** Evidence isn't what it seems. 
*/

typedef struct  s_hallucination {

}               t_hallucination;

/*
    Given a representation as a p-space, hallucinate the meta-representation
    TESTS:
        GIVEN:
        (
            (:= 
                V # value space
                (
                    p 
                    (m p)
                )
            )
            (:=
                R # propostions space
                (
                    p
                    q
                )
            )
            (:= S
                (p-space
                    V
                    R
                ) # => (
                    (p , p),
                    (p, (m p)),
                    ((m p), p),
                    ((m p), (m p)),
                )
            )
        TEST 0:
            (hallucinate (q r)) = (m (q r)) = 
            (::= 
                ((m q) (m r)) (
                (p p)
                (p (m p))
                ((m p) p)
                ((m p) (m p))
            )

        TEST 1:
            (hallucinate (
                    (p p)
                    (p (m p))
                    ((m p) p)
                    ((m p) (m p))
                )
            ) = (m (
                    (p p)
                    (p (m p))
                    ((m p) p)
                    ((m p) (m p))
                )
            ) = ( 
                (m (p p))
                (m (p (m p)))
                (m ((m p) p))
                (m ((m p) (m p)))
            ) = (
                (
                    (p (m p))
                    ((m p) p)
                    ((m p) (m p))
                )
                (
                    (p p)
                    ((m p) p)
                    ((m p) (m p)) 
                )
                (
                    (p p)
                    (p (m p))
                    ((m p) (m p))
                )
                (
                    (p p)
                    (p (m p))
                    ((m p ) p)
                )
            )
        )
*/ 

char    *hallucinate(*representation) {
    
    
}

char    *f_strdup(char *s) {
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
    char    *input;
    int     fd;

    input = NULL;
    fd = 1;         //STDIN

    f_putendl("Please select and option for displaying the delusion of the prima representation: ");
    f_putendl("1. determinate sucessions ");
    f_putendl("2. hallucinatory sucessions ");
    
    f_gnl(1, &input);
    data.option = (int)(input[0] - 60);
    return (data);
}

/*
**  
*/

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
** For now, we will use arrays to represent pluralitiess
** tests
** PARAMS : no_of_successions, prima_representation, notation [prefix/infix]
**  ./main 10 p prefix
**  ./main 10 p infix
*/

int          row(int len, no_of_processes ){

}


int          simple_reductive_proc_sys (size_t sucessions, int *v_space, size_t v_len, size_t no_of_procs) {

    int     *base_rep;
    int     j;
    int     init;

    //gen_base_rep
    j = 0;
    for (int i; i < sucessions; i++) {
        base_rep[i] = v_space[j];
        j = (j < v_len ? j + 1 : 0);
    }

    //allocate space for process rep
    

    //observe base rep
    init = v_space[0]
    for (int i; i < sucessions; i++) {
        int sucession = new_sucession();
        select (base_rep[i])
    }
    
}

int          main (int argc, char **argv) {
    t_global    *global;
    char        *successions;
    char        *prima_representation;
    char        *notation;

    successions = argv[2];
    prima_representation = argv[1];
    notation = argv[3];

    if (argc < 2){
        return 0;
    }
    global = NULL;
    display_menu(global);
    global = init(global, prima_representation, successions, notation);
    
    f_putendl(global->meta);
    return (0);
}