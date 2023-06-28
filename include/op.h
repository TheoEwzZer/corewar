/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#ifndef _OP_H_
    #define _OP_H_

    #include <stdint.h>

    #define MEM_SIZE            (6 * 1024)
    #define IDX_MOD             512    /* modulo of the index < */
    #define MAX_ARGS_NUMBER     4      /* this may not be changed 2^*IND_SIZE */

    #define COMMENT_CHAR        '#'
    #define LABEL_CHAR          ':'
    #define DIRECT_CHAR         '%'
    #define SEPARATOR_CHAR      ','
    #define REGISTER_CHAR       'r'

    #define LABEL_CHARS         "abcdefghijklmnopqrstuvwxyz_0123456789"

    #define NAME_CMD_STRING     ".name"
    #define COMMENT_CMD_STRING  ".comment"

    /*
    ** regs
    */

    #define REG_NUMBER          16     /* r1 <--> rx */

    /*
    **
    */

typedef char args_type_t;

    #define T_REG               1      /* register */
    #define T_DIR               2      /* direct  (ld  #1,r1  put 1 into r1) */
    #define T_IND               4      /* indirect always relative */
    #define T_LAB               8      /* LABEL */

typedef struct op_s {
    const char  *mnemonique;
    char        nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char        code;
    int         nbr_cycles;
    const char  *comment;
} op_t;

    /*
    ** size (in bytes)
    */
    #define IND_SIZE            2
    #define DIR_SIZE            4
    #define REG_SIZE            DIR_SIZE

/*
** op_tab
*/

extern op_t op_tab[];

    /*
    ** header
    */
    #define PROG_NAME_LENGTH    128
    #define COMMENT_LENGTH      2048
    #define HEADER_LENGTH       (PROG_NAME_LENGTH + COMMENT_LENGTH)

typedef struct header_s {
    #define COREWAR_EXEC_MAGIC  0xea83f3 /* why not */
    char    comment[COMMENT_LENGTH + 1];
    char    prog_name[PROG_NAME_LENGTH + 1];
    int     magic;
    int     prog_size;
    int     prog_number;
} header_t;

    /*
    ** live
    */
    #define CYCLE_TO_DIE        1536 /* number of cycle before die */
    #define CYCLE_DELTA         5
    #define NBR_LIVE            40

#endif
