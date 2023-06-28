/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** Back in the good old days
*/

#ifndef ASM
    #define ASM

    #include "my.h"
    #include "op.h"
    #include <fcntl.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/types.h>
    #include <unistd.h>

    #define FINALTAB my_asm->finaltab
    #define LABEL_REF my_asm->label_ref
    #define PROG_SIZE my_asm->header->prog_size

typedef struct label_s {
    char *name;
    char opcode;
    off_t label_pos;
    off_t pos;
} label_t;

typedef struct asm_s {
    char ***finaltab;
    char **tab;
    char *file;
    char *name;
    char function_code;
    header_t *header;
    int fd;
    int i;
    int j;
    label_t **label;
    label_t **label_ref;
} asm_t;

bool exist(char *function);
char **my_str_to_tab(char *str);
char **my_str_to_word_delim(char *str, char delimiter);
char **my_strdup_double(char **str);
char *s_to_cor(char *file_name);
int display_help(void);
int main(int argc, char **argv);
int start_asm(asm_t *my_asm, char **argv);
short int swap_uint16(short int x);
size_t nb_delim(char *str, char delim);
unsigned int swap_uint32(unsigned int x);
void coding_args(asm_t *my_asm, size_t i, size_t *k, off_t pos_label);
void coding_byte(asm_t *my_asm, size_t i, size_t *k);
void find_coding_byte(asm_t *my_asm, size_t i,
    size_t k2, unsigned char *coding_byte);
void check_args(asm_t *my_asm, asm_t *pos);
void check_args2(asm_t *my_asm, asm_t *pos);
void check_function(asm_t *my_asm, asm_t *pos);
void check_label_name(const char *label);
void check_label_name2(const char *label, size_t i, bool *char_found);
void check_op_extreme(char *function);
void check_register(int register_int);
void check_type(asm_t *my_asm, size_t i, asm_t *pos, int rank);
void check_type2(asm_t *my_asm, size_t i, asm_t *pos, int rank);
void compare_with_tab(int oct, size_t i, int rank);
void loop(asm_t *my_asm, size_t i, size_t *k);
void parse_header(asm_t *my_asm, char *buffer);
void parse_header2(asm_t *my_asm, char *comment);
void read_header(char *file, char *buffer);
void skip_delimiter(char *str, size_t *i, char delimiter);
void stock_label(asm_t *my_asm, char *str, off_t pos_label);
void stock_label_ref(asm_t *my_asm, char *str, int fd);
void verify_tab(asm_t *pos);
void verify_tab2(asm_t *my_asm, asm_t *pos);
void write_args(asm_t *my_asm, size_t i, size_t k, off_t pos_label);
void write_body(asm_t *my_asm, char **argv);
void write_body2(asm_t *my_asm, size_t i);
void write_direct(asm_t *my_asm, size_t i, size_t k, off_t pos_label);
void write_header(asm_t *my_asm, char **argv);
void write_labels(asm_t *my_asm);
void write_labels2(asm_t *my_asm, size_t i);
void write_prog_size(asm_t *my_asm, int fd);

#endif /* !ASM */
