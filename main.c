#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "errormsg.h"
#include "symbol.h"
#include "absyn.h"
#include "parse.h"
#include "temp.h"
#include "tree.h"
#include "frame.h"
#include "types.h"
#include "translate.h"
#include "semant.h"
#include "printtree.h"

int main(int argc, char **argv) {
    if (argc!=3) {fprintf(stderr,"usage: a.out infile outfile\n"); exit(1);}
    A_exp tree = parse(argv[1]);
    if(!tree){fprintf(stderr, "parsing failed\n"); exit(1); }
    F_fragList ir = SEM_transProg(tree);
    fflush(stdout);
    FILE *out = fopen(argv[2], "w");
    printFragList(out, ir) ;
    fclose(out);
    return 0;
}
