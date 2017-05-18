#include "MathFunction.h"
double mysqrt(double input)
{
#if defined (HAVE_LOG) && defined (HAVE_EXP)
    return exp(log(x) * 0.5);
#else
    return 1.2313;
#endif
}
