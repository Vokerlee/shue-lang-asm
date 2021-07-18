#ifndef BACKEND_H_INCLUDED
#define BACKEND_H_INCLUDED

#include "tree.h"
#include "backend_config.h"

#include "text.h"

#define MULTIPLY(left, right)                                                                   \
    create_tree_element(OPER, MUL, left, right)

#define DIVIDE(left, right)                                                                     \
    create_tree_element(OPER, DIV, left, right)

#define ADDITION(left, right)                                                                   \
    create_tree_element(OPER, ADD, left, right)

#define SUBTRACT(left, right)                                                                   \
    create_tree_element(OPER, SUB, left, right)

#define CR_NUM(value)                                                                           \
    create_tree_element(NUM, value, nullptr, nullptr)

#define CR_VAR(value)                                                                           \
    create_tree_element(VAR, value, nullptr, nullptr)

struct variables
{
    int curr_size = 0;

    char var[MAX_VAR_NUM][MAX_VAR_NAME_LENGTH] = {0};
};

struct elements
{
    bin_tree_elem **elements_ = nullptr;

    int curr_size_ = 0;
};

void backend (FILE *tree_lang, FILE *asm_code);

bin_tree_elem *fill_tree (text_t *text, variables *var);

int var_search (variables* var, char* temp_var_name);

void asm_compile (bin_tree *tree, FILE *assmbl, variables *var);

void find_glob_vars (bin_tree_elem *element, int n_glob_vars);

void main_var_optimize (bin_tree_elem *element, int n_glob_vars);

void body_asm (bin_tree_elem *vertex, FILE *assmbl, variables *var);

void command_asm_tree (bin_tree_elem *element, FILE *assmbl, variables *var);

void analyse_expr (bin_tree_elem *element, FILE *assmbl, variables *var);

void find_func_var (bin_tree_elem *element, int *param, int *n_param, int first_loc_var);

void param_pass_func (bin_tree_elem *element, FILE *assmbl);

void func_asm (bin_tree_elem *vertex, FILE *assmbl, variables *var);

void user_func_optimize (bin_tree_elem *element, int *param, int n_param);


#endif // BACKEND_H_INCLUDED