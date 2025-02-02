#include <stdio.h>
#define i_extern // cstr + utf8 functions
#include <stc/cregex.h>
#include <stc/csview.h>

int main()
{
    puts("Split with c_fortoken (csview):");

    c_fortoken (i, "Hello World C99!", " ")
        printf("'%.*s'\n", c_SV(i.token));


    puts("\nSplit with c_formatch (regex):");

    c_with (cregex re = cregex_from("[^ ]+"), cregex_drop(&re))
        c_formatch (i, &re, "  Hello   World      C99! ")
            printf("'%.*s'\n", c_SV(i.match[0]));
}
