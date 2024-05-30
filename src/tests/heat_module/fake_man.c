#include <stdio.h>

int main(int argc, char ** argv, char ** envp)
{
    int i = 0;
    printf("%d\n", (i++) + (++i) );
    return 0;
}
