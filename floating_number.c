#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int ival = 0;
    float fval = 0.0;

    if (argc != 2) {
        fprintf(stderr, "USAGE: %s [floating-number]\n", argv[0]);
        return -1;
    }

    if (argv[1] == NULL) {
        return -1;
    }

    if (sscanf(argv[1], "%i %f", &ival, &fval) != 2) {
        fprintf(stderr, "%s is not a floating-number\n", argv[1]);
        return -1;
    }

    char buffer[50];
    sprintf(buffer, "%i %.2f", ival, fval);

    printf("%s\n", buffer);

    return 0;
}
