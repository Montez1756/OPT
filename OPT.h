#ifndef OPT_H
#define OPT_H

#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#define NOARGS 1

typedef struct param
{
    char *name;
    char **args;
    size_t num_args;
} param;

typedef struct OPT
{
    char **args;
    size_t num_args;
    param **params;
    size_t num_params;
    int argc;
    char **argv;
} OPT;


OPT *init_opt(int argc, char **argv);
void add_argument(OPT *opt, char *argument);
int compare_strings(void *a, void *b);
void parse_args(OPT *opt);
param *get_args(const OPT *opt, char *arg);
#endif // OPT_H
