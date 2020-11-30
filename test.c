#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "defines.h"
#include "RJM.h"

int main(void)
{
	int seq[MAX_LAG + 1];
	RJMP p;
	double v[NO_STIMS];
	int i;

	/* Low-Spread Condition stimulus values */
	p.S[0] = 73.0;
	p.S[1] = 82.0;
	p.S[2] = 85.0;

	/* Optimal values */
	p.zeroPoint[0] = -1.130796;
	p.zeroPoint[1] = 0.530144;
	p.zeroPoint[2] = 1.100768;
	p.crit[0] = 0.0; /* Two criteria fixed at 0 and 1 on internal response scale without loss of generality */
	p.crit[1] = 1.0;

	/* Fixed parameters */
	p.alpha[0] = 1.0;
	p.thresh = 100.0; /* Large, so judgment is always relative to Sn-1 */
	p.chi = 1.0;

	/* Free parameters */
	p.alpha[1] = 0.197230;
	p.sigma = 0.136588;
	p.lambda = 4.223944;

	/* Set sequence of stimuli. Stimuli numbered from 0 */
	seq[0] = 2;					/* Sn   */
	seq[1] = 0;					/* Sn-1 */
	seq[2] = 2;					/* Sn-2 */

	/* Print out the probabilities of each response for a given sequence */
	printf("Probabilities of each response\n");
	evidence(seq, &p, v);
	for (i = 0; i < NO_STIMS; i++)
		printf("evidence[%d] = %f\n", i, v[i]);

	return 0;
}
