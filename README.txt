This directory contains source code for the relative judgment model. 

Source code is written in C using functions from the GNU Scientific Library
(http://www.gnu.org/software/gsl/).

See Stewart and Matthews (2009) for details of the model (see also Stewart,
Brown, & Chater, 2005, and Stewart, 2007).

To compile the source code, type 'make'. To run the source code type
'./test'. If all is well, the program will print:

Probabilities of each response
evidence[0] = 0.007430
evidence[1] = 0.281485
evidence[2] = 0.711085

For different stimulus sequences, adjust the contents of the seq[] array in
test.c. Stimuli are numbered from zero.

For different stimulus spacings, adjust the contents of the S[] array in
test.c.

The optimal values listed in test.c are not free parameters, but instead are
ideal observer values. See Stewart and Matthews (2009) for details.

