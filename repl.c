#include <stdio.h>
#include <stdlib.h>
#include <editline/readline.h>
#include "mpc.h"


int main(int argc, char** argv) {

    /* Create Some Parsers */
    mpc_parser_t* Number   = mpc_new("number");
    mpc_parser_t* Operator = mpc_new("operator");
    mpc_parser_t* Expr     = mpc_new("expr");
    mpc_parser_t* Lispy    = mpc_new("derpy");

    /* Define them with the following Language */
    mpca_lang(MPCA_LANG_DEFAULT,
            "                                                   \
            number   : /-?[0-9]+/ ;                             \
            operator : '+' | '-' | '*' | '/' ;                  \
            expr     : <number> | '(' <operator> <expr>+ ')' ;  \
            derpy    : /^/ <operator> <expr>+ /$/ ;             \
            ",
            Number, Operator, Expr, Lispy);

    puts("derpy Version 0.0.0.0.1");

    while (1) {
        char* input = readline("> ");
        add_history(input);
        printf("No, you're a %s\n", input);
        free(input);
    }

    /* Undefine and Delete our Parsers */
    /* mpc_cleanup(4, Number, Operator, Expr, Lispy); */

    return 0;
}

