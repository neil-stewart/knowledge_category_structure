#ifndef RJM
#define RJM

#include <gsl/gsl_cdf.h>		/* GNU Scientific library */
#include <gsl/gsl_randist.h>
#include <gsl/gsl_integration.h>

#include "defines.h"

typedef struct RJMParams RJMP;

struct RJMParams {
	double S[NO_STIMS]; /* Actual stimulus magnitudes used to calulate stimulus differences */
	double zeroPoint[NO_STIMS]; /* Free to maximize accuracy not fit to data */
	double crit[NO_STIMS - 1]; /* Two fixed without loss of generality, rest free to maximize accuracy not fit to data */
	double alpha[MAX_LAG]; /* Free */
	double sigma; /* Free */
	double lambda; /* Free */
	double chi; /* Fixed, but could vary */
	double thresh; /* Fixed, but could vary */
};

double DnC(int *seq, int base, RJMP * p);
double rho(double d, int base, RJMP * p);
void evidence(int *seq, RJMP * p, double *v);

#endif
