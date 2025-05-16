#include "OPT.h"
#include <stdio.h>



int main(int argc, char **argv){

    OPT *opt = init_opt(argc, argv);
    if(opt == NULL)
    {   perror("Failed to init OPT");
        return 1;
    }
    add_argument(opt, "-a");
    parse_args(opt);
    param *args = get_args(opt, "-a");

    if(args != NULL)
    {
        printf("Args for: %s\n", args->name);
        for(size_t i=0; i<args->num_args; i++)
        {
            printf("%s\n", args->args[i]);
        }
    }


    return 0;
}