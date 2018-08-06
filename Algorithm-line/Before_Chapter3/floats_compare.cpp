#include <stdio.h>
#include <math.h>

const double eps = 1e-8;
const double Pi = acos(-1.0); 

#define Equ(a, b) (((fabs((a) - (b))) < (eps))
#define More(a, b) (((a) - (b) > (eps))
#define Less(a, b) (((a) - (b) < (-eps))
#define MoreEqu(a, b) (((a) - (b)) > (-eps))
#define LessEqu(a, b) (((a) - (b)) < (eps))
