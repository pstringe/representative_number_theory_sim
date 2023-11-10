#include "foundation.h"
#include <stdio.h>

/*
** Code positional logic
*/

/*
** Data structure for representative number
*/

typedef struct   s_global {
    char    *meta;
    char    *prima;
    char    *successions;
    char    *notation;
    int     option;
}                t_global;

/***********************************************************/

/*
** RTN: 
*/

typedef struct  s_hallucination {

}               t_hallucination;

/*
** dimension
*/

typedef struct s_dimension {
    struct s_abstraction  **positions;
}              t_dimension;

/*
** space 
*/

typedef struct s_space {
    struct s_abstraction   **dimensions; 
}              t_space;
                                                              
/*
** Expressable abstraction of  of information, pointed to by
** *representation.
*/

typedef struct  s_abstraction {
    char                    *symbol;
    void                    *data;
    struct s_abstraction    *expression;
}               t_abstraction;

/*
** Structure represents a proposition as a plurality of 
** abstractions symbolically represented using a character array
*/

typedef struct  s_proposition {
    struct s_abstraction    *representation;
    struct s_abstraction    **abstractions;
}               t_proposition;

/*
**  proccess related meta-representations
*/

typedef struct  s_succession {
    struct s_proccess       *proccess;
    struct s_abstraction    *observation;
    struct s_abstraction    *evaluation;
}               t_succession;

/*
** proccess 
*/

typedef struct  s_proccess {
    struct s_abstraction    **v_space;
    struct s_proposition    **r_space;
    //struct s_space        *possibility_space;
    int                     **possibility_space;
    struct s_succession     **successions; 
    size_t                  no_of_proccesses;                                                                                     
}               t_proccess;

/*
** New abstraction
*/

/*
t_abstraction *new_abstraction(void *symbol, void *data) {
    t_abstraction *new;

    new = (t_abstraction*)f_memalloc(sizeof(t_abstraction));
    new->data = data;
    new->symbol = symbol;
    new->expression = NULL;
    return (new);
}
*/

/*
** New proposition  
*/

/*
t_proposition *new_proposition(t_abstraction *representation, t_abstraction **abstractions) {
    t_proposition *new;

    new = (t_proposition*)f_memalloc(sizeof(t_proposition));
    new->abstractions=abstractions;
    new->representation = representation;
    return( new );
}
*/

/*
** New dimension
*/

/*
t_dimension *new_dimension(t_abstraction **positions) {
    t_dimension *new;
    size_t len;

    len = f_array_len((void**)positions);
    new = (t_dimension*)f_memalloc(sizeof(t_dimension));
    new->positions = positions;

    return (new);
}
*/

/*
** generate an array of positions
*/

/*
t_abstraction **gen_positions(size_t no_of_pos) {
    size_t          i;
    t_abstraction   **positions;

    i = 0; 
    positions = (t_abstraction**)f_memalloc(sizeof(t_abstraction*) * no_of_pos);

    while (i < no_of_pos) {
        positions[i] = (t_abstraction*)f_memalloc(sizeof(t_abstraction));
    }
    return (positions);
}
*/

/*
** simple determinate selector assume binary state-space single proposition
** assume (f f) != f
** over-operate t_succession, pass in proccess struct to gain access to p R and V space
** TODO: modify struct s_abstraction, to include uttility functions for CRUD
*/

/*
t_abstraction *simple_determinate_selector(t_proccess *proccess, int idx) {
    t_succession *succession;
    succession = proccess->successions[idx];
    char *value;
    
    value = (char*)f_memalloc(sizeof(char) * 1 + 1);
    value[1] = '\0';
    value[0] = (((succession->observation == 0) ? 1 : 0) - '0');
    succession->evaluation->symbol=value;
    succession->evaluation->data=value;
    return (new_abstraction(value, value));
}
*/

/*
** new space
*/

/*
t_space     *new_space(t_abstraction **dimensions) {
    t_space         *space;

    space = (t_space*)f_memalloc(sizeof(t_space));
    space->dimensions = dimensions;
    return (space);
}
*/

/*
** allocate and evaluate, observe a succession
** develop a constructor for abstraction type. Save the value returned from constructor.
*/

t_succession *new_succession(t_proccess *proccess, int i, t_abstraction* (*selector)(struct s_proccess*, int), void *last_evaluation) {
    proccess->successions[i] = (struct s_succession*)f_memalloc(sizeof(struct s_succession*));
    proccess->successions[i]->observation = last_evaluation;
    proccess->successions[i]->evaluation = selector(proccess, i);
    return (proccess->successions[i]);
}

/*
int     arr_len(int *arr) {
    arr[0] = 0;
    return 0;
}
*/

/*
int **g(int **res, int *cur, int *V, char **R, int i, int j, int len) {
    int     vlen;

    vlen = arr_len(V);    
    if (j == vlen) {
        res[vlen - 1] = &cur[i];
    }
    cur = (int*)f_memalloc(sizeof(int*) * arr_len(R));
    while (i < f_array_len(R)) {
        cur[vlen - 1] = V[i];
        g(res, cur, V, R, i, j, len);
    }
    return (res);
}
*/

/*
** simple p_space function
*/

/*
int **gen_p_space(int *V, char **R){
    int     res;
    int     cur;
    int     len;
    
    len = raise(arr_len(V), arr_len(R));
    res = (int**)f_memalloc((int*)len + 1);
    res[len] = -1; //assume positive values in state-space
    g(res, cur, V, R, 0, 0, len);
    return (res);
}
*/

/*
** proc calc functions
** TODO : Check spellling of proccess
*/

/*
t_proccess *new_proccess(int no_successions, void *init, t_abstraction* (*selector)(struct s_proccess*, int)) {
    t_proccess      *proccess;
    //t_succession    **succesions;
    //t_abstraction   *q;
    //t_abstraction   **dimenensions;

    void            *last_obs;
    int             i;
    
    proccess = (t_proccess*)f_memalloc(sizeof(proccess) * no_successions);

    //allocate v_space

    proccess->v_space = (t_abstraction**)f_memalloc(sizeof(t_abstraction*) * 3);
    proccess->v_space[2] = NULL;
    proccess->v_space[0] = new_abstraction("0", "0");
    proccess->v_space[1] = new_abstraction("0", "0");

    //allocate r_space
    q = new_abstraction("q", "q");
    proccess->r_space = (t_proposition**)f_memalloc(sizeof(t_proposition*));
    proccess->r_space[1] = NULL;
    proccess->r_space[0] = new_proposition(q, &q);
    
    //allocate abstractions for p-space

    //allocate s_space
    dimenensions = (t_abstraction**)f_memalloc(sizeof(t_abstraction*) * 2);
    dimenensions[0]->symbol = "props";
    dimenensions[1]->symbol = "values";
    proccess->possibility_space = new_space(dimenensions);

    int             *V;
    char            **R;
    t_succession    **succesions;

    V = (int*)f_memalloc(sizeof(int) * 2);
    R = (char**)f_memalloc(sizeof(char*) * 2);
    
    V[0] = 0;
    V[1] = 1;
    R[1] = (void*)0;
    proccess->possibility_space = gen_p_space(V, R);
    
    succesions = proccess->successions;
    last_obs = init;
    i = 0;
    
    while (i < no_successions) {
        succesions[i] = new_succession(proccess, i, selector, last_obs);
        last_obs = succesions[i]->evaluation;
        i++;
    }

    return (proccess);
}
*/

/*
** display succession
**    1. index
**    2. last evaluation
**    3. observation
**    4. evaluation
**
*/

/*
void    display_succession(t_succession *succession, void* last_evaluation, size_t idx) {
    f_putnbr(idx);
    f_putchar(' ');
    f_putstr((char*)last_evaluation);
    f_putchar(' ');
    f_putstr((char*)succession->observation);
    f_putchar(' ');
    f_putstr((char*)succession->evaluation);
    f_putchar('\n');
}
*/

/*
** display successions of a proccess
*/

/*
void    display_proccess(t_proccess *proccess){
    size_t     i;
    void    *last;
    
    i = 0;
    while (i < proccess->no_of_proccesses) {
        last = (i == 0 ? NULL : proccess->successions[i - 1]->evaluation);
        display_succession(proccess->successions[i], last, i);
        i++;
    }    
}
*/

/************************************************************************/

/*
** After dining proccess data structure.
*** code a routine of prioritiaztion by dividing the day into 4 qudrants.
*** Develop meta-logic
*** Develop spatial representation positional calc
*/

int calc_most_significant_weight(char *num) {
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

    base = calc_most_significant_weight(num);
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
** whether the notation should be prefix or infix, returns a succession of 
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
** Given a value space, (p (m p))
** The number of rows in the possibility space is doubled when a prop is added
** 1 - 2
** 2 - 4
** 3 - 8
**   .
**   . 
**   .
** The length of each row will always by the number of propositions
*/



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

/*
** Given prima succession notation
*/

char    *generation(char *prima, int successions, char *notation) {
    int     i;
    char    *tmp;
    char    *meta;
    
    meta = f_strdup(prima);
    i = 0;
    while (i++ < successions) {
        tmp = f_strdup(meta);
        f_bzero(meta, f_strlen(meta));
        meta = succeed(tmp, notation);
    }
    return(meta);
}

/*
** display menu
*/

t_global        *display_menu(t_global *data) {
    char    *input;
    int     fd;

    input = NULL;
    fd = 1;         //STDIN

    f_putendl("Please select and option for displaying the delusion of the prima representation: ");
    f_putendl("1. determinate successions ");
    f_putendl("2. hallucinatory successions ");

    f_gnl(1, &input);
    data->option = (int)(input[0] - 60);
    return (data);
}

/*
** instanciate global data-structure
*/

struct s_global *init(struct s_global *global, char *prima, char *successions, char *notation) {
    global = f_memalloc(sizeof(struct s_global));
    global->prima = prima;
    global->successions = successions;
    global->notation = notation;
    global->meta = generation(
        global->prima, 
        parse_num(global->successions), 
        global->notation
    );
    return (global);
}

/*
** Proc calc functions
*/

int          simple_reductive_proc_sys (size_t successions, int *v_space, size_t v_len, size_t no_of_procs) {

    int     *base_rep;
    int     j;
    int     init;

    //gen_base_rep
    j = 0;
    for (int i; i < successions; i++) {
        base_rep[i] = v_space[j];
        j = (j < v_len ? j + 1 : 0);
    }

    //allocate space for proccess rep
    //observe base rep
    init = v_space[0];
    for (int i; i < successions; i++) {
        int succession = new_succession();
        select (base_rep[i])
    }
}

int          main (int argc, char **argv) {
    char        *successions;
    char        *prima_representation;
    char        *notation;
    
    successions = argv[2];
    prima_representation = argv[1];
    notation = argv[3];

    if (argc < 2){
        return (0);
    }

    /*
    **    Test RTN Generator
    */

    display_menu(global);
    global = init(global, prima_representation, successions, notation);
    f_putendl(global->meta);
    return (0);
}