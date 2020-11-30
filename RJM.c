/* RJM from Stewart and Matthews (2009) */
/* Back derived from RJM_LBA code */

#include "RJM.h"

double DnC(int *seq, int base, RJMP * p)
/* Stewart, Brown, and Chater (2005) Equation 3 (when judgment is relative
   to Sn-1) and Stewart (2007) Equation 3 (when judgment is relative to Sn-2)
   */
{
	double d = 0.0;
	int i;

	d += p->alpha[0] * (p->S[seq[0]] - p->S[seq[base]]);
	for (i = 1; i < MAX_LAG; i++)
		d += p->alpha[i] * (p->S[seq[i]] - p->S[seq[i + 1]]);

	return d;
}

double rho(double d, int base, RJMP * p)
/* Stewart (2007) Equation 2 */
{
	double rho;

	if (d > p->chi)
		rho = GSL_MAX((double) (NO_STIMS - base - 1), 1.0);
	else if (d < -p->chi)
		rho = GSL_MAX((double) base, 1.0);
	else
		rho = 1.0;
	return rho;
}

void evidence(int *seq, RJMP * p, double *v)
{
	double d, mean, scale;
	int base, i;
	double CDF[NO_STIMS + 1];

	/* Compare to Sn-1 unless Sn-2 is much nearer */
	base =
	  abs(p->S[seq[0]] - p->S[seq[1]]) <=
	  abs(p->S[seq[0]] - p->S[seq[2]]) + p->thresh ? 1 : 2;

	d = DnC(seq, base, p);

	/* Mean and scale parameter for Laplace distribution in Stewart (2007) 
	   Equation 1 */
	mean = (double) p->zeroPoint[seq[base]] + d / p->lambda;
	scale = rho(d, seq[base], p) * p->sigma;

	/* Calculate value of CDF as each criteria */
	CDF[0] = 0.0;
	CDF[NO_STIMS] = 1.0;
	for (i = 1; i < NO_STIMS; i++) {
		CDF[i] = GEN_FUNC(p->crit[i - 1] - mean, scale);
	}
	/* Store evidences for each response in v */
	for (i = 0; i < NO_STIMS; i++) {
		v[i] = CDF[i + 1] - CDF[i];
	}
}

double pCorrect(int *seq, RJMP * p)
{
	double v[NO_STIMS];
	evidence(seq, p, v);
	return v[seq[0]];
}
