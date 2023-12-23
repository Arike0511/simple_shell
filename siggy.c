#include "secondmain.h"

/**
 * gt_signdint - Handle the crtl + c call prompt
 * @sigma: Signal handler
 */
void gt_signdint(int sigma)
{
	(void)sigma;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
