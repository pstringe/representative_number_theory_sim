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
** RTN: 
*/

typedef struct  s_hallucination {

}               t_hallucination;

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
}               t_proposition;

/*
**  Process related meta-representations
*/

typedef struct  s_sucession {
    struct s_process        *process;
    struct s_abstraction    *observation;
    struct s_abstraction    *evaluation;
}               t_sucession;

/*
** Process 
*/

typedef struct  s_process {
    struct s_abstraction    *v_space;
    struct s_proposition    **r_space;
    struct s_space          **posibility_space;
    struct t_sucession      **sucessions; 
    size_t                  no_of_processes;                                                                                     
}               t_process;

/*
** simple determinate selector assume binary state-space single proposition
** assume (f f) != f
** over-operate t_sucession, pass in proccess struct to gain access to p R and V space
** TODO: modify struct s_abstraction, to include uttility functions for CRUD
*/

char *simple_determinate_selector(t_sucession **process, idx) {
    t_sucession *sucession;
    sucession = process.successions[idx];
    char *value;
    
    value = (char*)f_memalloc(sizeof(char) * 1 + 1);
    value[1] = '\0';
    value[0] = (((sucession->observation == 0) ? 1 : 0) - '0');
    sucession->evaluation->symbol=value;
    sucession->evaluation->representation=value;

    return (value);  
}

/*
** allocate and evaluate, observe a sucession
*/

t_sucession **new_succession(t_sucession **process, int i, (*t_process)(selector), void *last_evaluation) {
    process->sucessions[i] = (*t_sucession)f_memalloc(sizeof(t_sucession));
    process->sucessions[i]->observation = last_evaluation;
    process->sucessions[i]->evaluation = selector(process, )
    return (proccess->sucessions[i]);
}

/*
** proc calc functions
** TODO : Check spellling of process
*/

t_sucession **new_proccess(int no_sucessions, void *init, (*t_process, int)(selector)) {
    t_process   *process;
    t_sucession **succesions;
    void        *last_obs;
    int         i;
    
    process = (*t_process)f_memalloc(sizeof(process) * no_sucessions);
    process->v_space = [0 , 1];
    process->r_space = ["q"];
    process->posibility_space = [
        ["0", "1"];
    ]; //review static declarations in C
    /*generate_possibility_space(process);*/

    succesions = process->sucessions;
    last_obs = init;
    i = 0;
    while (i < no_sucessions){
        succesions[i] = new_succession(process, i, selector(process, i), last_obs);
        last_obs = succesions[i]->evaluation;
        i++;
    }
    return (process);
}

/*
** display succession
**    1. index
**    2. last evaluation
**    3. observation
**    4. evaluation
**
*/

void    display_succession(t_sucession sucession, void* last_evaluation, size_t idx) {
    f_putnbr(idx);
    f_putchar(' ');
    f_putstr((char*)last_evaluation);
    f_putchar(' ');
    f_putstr((char*)sucession.observation);
    f_putchar(' ');
    f_putstr((char*)sucession.evaluation);
    f_putstr('\n');
}

/*
** display sucessions of a process
*/

void    display_process(t_process *process){
    int     i;
    void    *last;
    
    i = 0;
    while (i < process->no_of_processes) {
        last = (i == 0 ? init : process->sucessions[i - 1].evaluation);
        display_sucession(process->sucessions[i], last, i);
        i++;
    }    
}

/*----*/
/*
** After dining process data structure.
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
**
*/

char     **new_row(char **propositions, int n, int m) {
    int     i;
    int     j;
    int     k;
    int     len;
    char    **arr;

    len = f_array_len(propositions);
    arr = (char**)f_memalloc(sizeof(char*) * n);
    i = 0;
    while (i < n) {
        arr[i] = (char*)f_memalloc(sizeof(char) * m);
        j = 0;
        while (j < m) {
            k = 0;
            while(k < len) {
                succeed(propositions[k], "infix");
            }
        }
    }
    return (arr);
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

int     raise(int base, int power){
    if (power == 0){
        return 1;
    }
    return (raise(base, power) * raise(base, power - 1));
}

char    **generate_possibility_space(t_process *process) {  //[p [m p]] [p r]
    int     n;
    int     m;
    int     r;
    int     i;
    int     j;

    int     p_space_len;
    char    *cur_prop_idx;
    char    *cur_prop:
    char    *cur_val;
    char    **possibility_space;
    int     CONST_CHAR_OFFSET;

    n = f_array_len(value_space);
    m = f_array_len(propositions);

    mat_len = (sizeof(char*) * raise(n, m));
    possibility_space = f_memalloc(sizeof(char*) * raise(n, m));
    
    if (n < 2) {
        return NULL;
    }
    
    i = 0;
    while (i < p_space_len) {
        possibility_space[i] = f_memalloc((char*) * m);
        v_idx = 0;
        p_idx = 0;
        j = 0;
        while (j < n) {
            v_idx = (v_idx < n : v_idx++ : 0);
            p_idx = (p_idx < m ? p_idx : 0);
            cur_val = ((char*)(value_space[v_idx] + CONST_CHAR_OFFSET));
            cur_prop = (propositions[p_idx]);
            possibility_space[i][j] = generation(propositions[cur_prop], value_space[cur_val], "prefix");
        }
        i++;
    }

    return possibility_space;
}

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

/*
** 
*/

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
** display menu
*/

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
** instanciate global data-structure
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
** Proc calc functions
*/

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

    new_proccess(8, "0", simple_determinate_selector)
    /*
    global = NULL;
    display_menu(global);
    global = init(global, prima_representation, successions, notation);
    f_putendl(global->meta);
    new_proccess
    return (0);
    */
}