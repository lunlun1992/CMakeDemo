#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "TutorialConfig.h"

#ifdef USE_MYMATH
#include "MathFunction.h"
#endif

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        fprintf(stdout, "dasd");
        return 1;
    }

    double input = atof(argv[1]);
#ifdef USE_MYMATH
    double output = mysqrt(input);
#else
    double output = sqrt(input);
#endif
    fprintf(stdout, "The root of %g is %g\n", input, output);
    return 0;
}
