#include "foundation.h"

void    f_putnbr_fd(long long n, int fd) {
	long long tmp;

	tmp = n;
	if (tmp < 0) {
		tmp = -tmp;
		f_putchar_fd('-', fd);
	}
	if (tmp >= 10) {
		f_putnbr_fd(tmp / 10, fd);
		f_putnbr_fd(tmp % 10, fd);
	}
	else {
		f_putchar_fd(tmp + '0', fd);
	}
}
