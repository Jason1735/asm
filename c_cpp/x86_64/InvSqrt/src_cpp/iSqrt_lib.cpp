#include <math.h>
extern "C" float iSqrt_lib(float);
float iSqrt_lib(float x)
{
	return (float)(1.0 / sqrt(x));
}

