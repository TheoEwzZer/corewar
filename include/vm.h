/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** Back in the good old days
*/

#ifndef VM
    #define VM

    #include "my.h"
    #include "op.h"
    #include <fcntl.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/types.h>
    #include <unistd.h>

    #define ADDRESS(nb_champ) vm->champions[nb_champ]->load_address
    #define REG processus->reg
    #define ST(x, y) vm->arena[((x) + ((y) % IDX_MOD)) % MEM_SIZE]
    #define STC(x, y) vm->color_arena[((x) + ((y) % IDX_MOD)) % MEM_SIZE]
    #define STI(x, y) vm->arena[(x + (y) % IDX_MOD) % MEM_SIZE]
    #define STIC(x, y) vm->color_arena[(x + (y) % IDX_MOD) % MEM_SIZE]

    #define NORMAL   "\x1B[1;0m"
    #define RED      "\x1B[1;31m"
    #define GREEN    "\x1B[1;32m"
    #define YELLOW   "\x1B[1;33m"
    #define BLUE     "\x1B[1;34m"
    #define MAGENTA  "\x1B[1;35m"
    #define CYAN     "\x1B[1;36m"
    #define WHITE    "\x1B[1;37m"

typedef struct processus_s {
    bool carry;
    int cycle;
    int pc;
    int reg[REG_NUMBER];
    bool is_alive;
} processus_t;

typedef struct instruction_s {
    int actual_pc;
    int first_arg;
    int second_arg;
    int third_arg;
} instruction_t;

typedef struct champion_s {
    bool alive;
    header_t *header;
    int cycle;
    int cycle_to_die;
    int load_address;
    size_t nbr_exec_lives;
} champion_t;

typedef struct vm_s {
    champion_t **champions;
    char *arena;
    char *color_arena;
    const char *write_color[4];
    processus_t **processus;
    size_t a;
    size_t n;
    size_t nbr_cycle;
    size_t number_of_champion;
} vm_t;

bool is_cor_file(char *str);
const char *get_player_name(champion_t **champs, long result);
int get_arg(vm_t *vm, processus_t *processus, int arg_type, int opcode);
int get_arg2(vm_t *vm, processus_t *processus);
int get_st_arg(vm_t *vm, processus_t *processus);
int get_value(vm_t *vm, processus_t *processus, int arg_type, int arg);
int main(int argc, char **argv);
size_t read_number_of_champion(char **argv);
void change_pc(int *pc, int nb);
void check_cli(vm_t *vm, char **argv, size_t *i);
void check_winner(vm_t *vm);
void choose_function(vm_t *vm, processus_t *processus);
void create_arena(vm_t *vm, char **argv);
void create_champion(vm_t *vm, char **argv);
void create_champion2(vm_t *vm, char **argv, size_t i, size_t *nb_champ);
void create_processus(vm_t *vm);
void define_address(vm_t *vm, char **argv, size_t i, size_t nb_champ);
void define_prog_number(vm_t *vm, char **argv, size_t i, size_t nb_champ);
void dump_memory(vm_t *vm);
void execute_processus(vm_t *vm) __attribute__((noreturn));
void execute_processus2(vm_t *vm);
void function_add(vm_t *vm, processus_t *processus);
void function_aff(vm_t *vm, processus_t *processus);
void function_and(vm_t *vm, processus_t *processus);
void function_and2(vm_t *vm, processus_t *processus, int actual_pc, int *first);
void function_fork(vm_t *vm, processus_t *processus);
void function_ld(vm_t *vm, processus_t *processus);
void function_ldi(vm_t *vm, processus_t *processus);
void function_lfork(vm_t *vm, processus_t *processus);
void function_live(vm_t *vm, processus_t *processus);
void function_lld(vm_t *vm, processus_t *processus);
void function_lldi(vm_t *vm, processus_t *processus);
void function_or(vm_t *vm, processus_t *processus);
void function_or2(vm_t *vm, processus_t *processus, int actual_pc, int *first);
void function_st(vm_t *vm, processus_t *processus);
void function_st2(vm_t *vm, processus_t *processus, instruction_t *i);
void function_sti(vm_t *vm, processus_t *processus);
void function_sti2(vm_t *vm, processus_t *processus, instruction_t *i, int sum);
void function_sub(vm_t *vm, processus_t *processus);
void function_xor(vm_t *vm, processus_t *processus);
void function_xor2(vm_t *vm, processus_t *processus, int actual_pc, int *first);
void function_zjmp(vm_t *vm, processus_t *processus);
void help(vm_t *vm) __attribute__((noreturn));
void init_vm(vm_t *vm);
void load_core(vm_t *vm, char *path, int nb_champ);
void my_exit(vm_t *vm, int status) __attribute__((noreturn));
void print_dump(vm_t *vm, char *str, char color, size_t i, size_t k);
void set_address(vm_t *vm);

#endif /* !VM */
