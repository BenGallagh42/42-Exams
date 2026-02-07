#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

static void	ft_putstr(const char *s, int *count)
{
	if (!s)
		s = "(null)";
	while (*s)
	{
		write(1, s++, 1);
		(*count)++;
	}
}

static void	ft_putnbr(int n, int *count)
{
	char c;

	if (n == INT_MIN)
	{
		ft_putstr("-2147483648", count);
		return;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		(*count)++;
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10, count);
	c = (n % 10) + '0';
	write(1, &c, 1);
	(*count)++;
}

static void	ft_puthex(unsigned int n, int *count)
{
	char *hex = "0123456789abcdef";

	if (n >= 16)
		ft_puthex(n / 16, count);
	write(1, &hex[n % 16], 1);
	(*count)++;
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		count = 0;

	va_start(args, string);
	while (*string)
	{
		if (*string == '%' && *(string + 1))
		{
			string++;
			if (*string == 's')
				ft_putstr(va_arg(args, char *), &count);
			else if (*string == 'd')
				ft_putnbr(va_arg(args, int), &count);
			else if (*string == 'x')
				ft_puthex(va_arg(args, unsigned int), &count);
			else
			{
				write(1, string, 1);
				count++;
			}
		}
		else
		{
			write(1, string, 1);
			count++;
		}
		string++;
	}
	va_end(args);
	return (count);
}

int main(void)
{
	int count = 0;
	ft_putstr("Test\n", &count);
	ft_putnbr(-123, &count);
	write(1, "\n", 1);
	ft_puthex(255, &count);
	write(1, "\n", 1);
	return (0);
}