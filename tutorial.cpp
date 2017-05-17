#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "TutorialConfig.h"

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        fprintf(stdout, "dasd");
        return 1;
    }

    double input = atof(argv[1]);
    double output = sqrt(input);
    fprintf(stdout, "The root of %g is %g\n", input, output);
    return 0;
}
