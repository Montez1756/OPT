#include "OPT.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

OPT *init_opt(int argc, char **argv)
{
    OPT *opt = (OPT *)malloc(sizeof(OPT));
    opt->args = NULL;
    opt->num_args = 0;
    opt->params = NULL;
    opt->num_params = 0;
    opt->argc = argc;
    // memcpy(opt->argv, argv, sizeof(argv));
    opt->argv = malloc(argc * sizeof(char *));
    if (!opt->argv) return NULL;

    for (int i = 0; i < argc; i++) {
        opt->argv[i] = strdup(argv[i]);  // Allocate and copy string
        if (!opt->argv[i]) {
            // Cleanup on failure
            for (int j = 0; j < i; j++) free(opt->argv[j]);
            free(opt->argv);
            return NULL;
        }
    }

    return opt;
}
void add_argument(OPT *opt, char *argument)
{
    add_to_array((void **)&opt->args, &opt->num_args, sizeof(char *), argument);
}

int compare_strings(void *a, void *b)
{
    return strcmp((char *)a, (char *)b) == 0;
}

void parse_args(OPT *opt)
{   
    int i=0;

    while(i < opt->argc)
    {
        
        if(array_includes((void **)opt->args, &opt->num_args, opt->argv[i], compare_strings))
        {
            
            param *p = (param *)malloc(sizeof(param));
            if(!p)
            {
                perror("malloc");
                continue;
            }
            p->name = opt->argv[i++];
            
            p->args = NULL;
            p->num_args = 0;
            while(i < opt->argc && !array_includes((void **)opt->args, &opt->num_args, opt->argv[i], compare_strings))
            {
                add_to_array((void **)&p->args, &p->num_args, sizeof(char *), opt->argv[i++]);
            }
            
            add_to_array((void **)&opt->params, &opt->num_params, sizeof(param *), p);
        }
        else i++;
    }

}
param *get_args(const OPT *opt, char *arg)
{
    for (int i = 0; i < opt->num_params; i++)
    {
        if (strcmp(opt->params[i]->name, arg) == 0)
        {
            if(opt->params[i]->num_args == 0)
                return NULL;
            return opt->params[i];
        }
    }
    return NULL;
}