#include "ft_printf.h"
#include "libft/libft.h"

void	ft_putspace(int nbr)
{
	while (nbr > 0)
	{
		ft_putchar(' ');
		nbr--;
	}
}

int		ft_putchar_cap(char c, char type, int pad)
{
	int		ttl;

	ttl = 0;
	if (pad > 1)
	{
		ft_putspace(pad - 1);
		ttl += (pad - 1);
	}
	if ((type == 'S' || type == 'C') && c <= 'z' && c >= 'a')
	{
		ft_putchar(c - 32);
		ttl += 1;
	}
	else
	{
		ft_putchar(c);
		ttl += 1;
	}
	if (pad < 0 && (pad * -1) > 1)
	{
		ft_putspace((pad * -1) - 1);
		ttl += ((pad * -1) - 1);
	}
	if (type == 'C' || type == 'c')
		return (ttl);
	return (0);
}

int		ft_putstr_cap(char *str, char type, int pad)
{
	int		i;
	int		ttl;

	i = 0;
	ttl = (int)ft_strlen(str);
	if (pad > (int)ft_strlen(str))
	{
		ft_putspace(pad - (int)ft_strlen(str));
		ttl += (pad - ttl);
	}
	while (str[i])
		ttl += ft_putchar_cap(str[i++], type, 0);
	if (pad < 0 && (pad * -1 > (int)ft_strlen(str)))
	{
		ft_putspace((pad * -1) - (int)ft_strlen(str));
		ttl += ((pad * -1) - (int)ft_strlen(str));
	}
	return (ttl);
}

int		base_16(void *add, int pad)
{
	int		i;
	char		base[17] = "0123456789abcdef";
	char		*res;
	unsigned int	k;
	int				ttl;

	k = (unsigned int)add;
	res = (char *)malloc(sizeof(char) * 9);
	ttl = 14;
	if (pad > 14)
	{
		ft_putspace(pad - 14);
		ttl += (pad - 14);
	}
	ft_putstr("0x7ffe");
	i = 7;
	res[8] = '\0';
	while (i >= 0)
	{
		res[i--] = base[k % 16];
		k /= 16;
	}
	ft_putstr(res);
	if (pad < 0 && (pad * -1 > 14))
	{
		ft_putspace((pad * -1) - 14);
		ttl += ((pad * -1) - 14);
	}
	free(res);
	return (ttl);
}

int		ft_putnbr_new(int nbr, int pad)
{
	int	i;
	int	num;
	int	ttl;

	num = nbr;
	i = 0;
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	ttl = i;
	if (pad > i)
	{
		ft_putspace(pad - i);
		ttl += (pad - i);
	}
	ft_putnbr(nbr);
	if (pad < 0 && (pad * -1 > i))
	{
		ft_putspace((pad * -1) - i);
		ttl += ((pad * -1) - i);
	}
	return (ttl);
}

int		ft_putunbr(unsigned int nbr, int pad)
{
	int		i;
	unsigned int	num;
	char		*str;
	int			ttl;

	num = nbr;
	i = 0;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	ttl = i;
	if (pad > i)
	{
		ft_putspace(pad - i);
		ttl += (pad - i);
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = '0' + nbr % 10;
		nbr /= 10;
		i--;
	}
	ft_putstr(str);
	i = ft_strlen(str);
	if (pad < 0 && (pad * -1 > i))
	{
		ft_putspace((pad * -1) - i);
		ttl += ((pad * -1) - i);
	}
	return (ttl);
}

int		ft_uputnbr(unsigned long nbr, int pad)
{
	int		i;
	unsigned long	num;
	char		*str;
	int			ttl;

	num = nbr;
	i = 0;
	ttl = 0;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	ttl = i;
	if (pad > i)
	{
		ft_putspace(pad - i);
		ttl += (pad - i);
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = '0' + nbr % 10;
		nbr /= 10;
		i--;
	}
	ft_putstr(str);
	i = ft_strlen(str);
	if (pad < 0 && (pad * -1 > - i))
	{
		ft_putspace((pad * -1) - i);
		ttl += ((pad * -1) - i);
	}
	return (ttl);
}

int		ft_hex(unsigned int nbr, char type, int pad)
{
	int		i;
	int		amt;
	char		*res;
	unsigned int	temp;
	char		base[17] = "0123456789abcdef";
	int			ttl;

	temp = nbr;
	i = 0;
	ttl = 0;
	while (temp != 0)
	{
		temp /= 16;
		i++;
	}
	if (nbr == 0)
		i += 1;
	ttl = i;
	res = (char *)malloc(sizeof(char) * (i + 1));
	res[i] = '\0';
	if (pad > i)
	{
		ft_putspace(pad - i);
		ttl += (pad - i);
	}
	amt = i;
	temp = nbr;
	while (temp != 0)
	{
		if (type == 'X' && base[temp % 16] >= 'a' && base[temp % 16] <= 'z')
			res[--i] = base[temp % 16] - 32;
		else
			res[--i] = base[temp % 16];
		temp /= 16;
	}
	if (nbr == 0)
		ft_putnbr(nbr);
	ft_putstr(res);
	if (pad < 0 && (pad * -1 > amt))
	{
		ft_putspace((pad * -1) - amt);
		ttl += ((pad * -1) - amt);
	}
	free(res);
	return (ttl);
}

int	is_flag(const char c)
{
	const char	str[14] = "sSdDcCxXpoOuU%";
	int		i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_octal(int nbr, int pad)
{
	int		temp;
	char		*str;
	int		i;
	int		amt;
	int		ttl;

	temp = nbr;
	i = 0;
	ttl = 0;
	while (temp != 0)
	{
		temp /= 8;
		i++;
	}
	ttl = i;
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	temp = nbr;
	amt = i;
	if (pad > i)
	{
		ft_putspace(pad - i);
		ttl += (pad - i);
	}
	while (i >= 0)
	{
		str[--i] = '0' + (temp % 8);
		temp /= 8;
	}
	ft_putstr(str); 
	if (pad < 0 && (pad * -1) > amt)
	{
		ft_putspace((pad * -1) - amt);
		ttl += ((pad * -1) - amt);
	}
	free(str);
	return (ttl);
}

int		ft_uoctal(unsigned int nbr, int pad)
{
	unsigned int	temp;
	char		*str;
	int		i;
	int		amt;
	int		ttl;

	ttl = 0;
	temp = nbr;
	i = 0;
	while (temp != 0)
	{
		temp /= 8;
		i++;
	}
	ttl = i;
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	temp = nbr;
	amt = i;
	if (pad > i)
	{
		ft_putspace(pad - i);
		ttl += (pad - i);
	}
	while (i >= 0)
	{
		str[--i] = '0' + (temp % 8);
		temp /= 8;
	}
	ft_putstr(str);
	if (pad < 0 && (pad * -1) - amt)
	{
		ft_putspace((pad * -1) - amt);
		ttl += ((pad * -1) - amt);
	}
	return (ttl);
}

int		sort_flags(const char *str, int i, va_list *lis, int pad)
{
	int		amt;

	amt = 0;
	if (str[i + 1] == 'c' || str[i + 1] == 'C')
		amt = ft_putchar_cap(va_arg(*lis, int), str[i + 1], pad);
	else if (str[i + 1] == 'S' || str[i + 1] == 's')
		amt = ft_putstr_cap(va_arg(*lis, char *), str[i + 1], pad);
	else if (str[i + 1] == 'd' || str[i + 1] == 'D')
		amt = ft_putnbr_new(va_arg(*lis, int), pad);
	else if (str[i + 1] == 'p')
		amt = base_16(va_arg(*lis, void *), pad);
	else if (str[i + 1] == 'X' || str[i + 1] == 'x')
		amt = ft_hex(va_arg(*lis, unsigned int), str[i + 1], pad);
	else if (str[i + 1] == 'o')
		amt = ft_octal(va_arg(*lis, int), pad);
	else if (str[i + 1] == 'O')
		amt = ft_uoctal(va_arg(*lis, unsigned int), pad);
	else if (str[i + 1] == '%')
		amt = ft_putchar_cap('%', 1, pad);
	else if (str[i + 1] == 'u')
		amt = ft_putunbr(va_arg(*lis, unsigned int), pad);
	else if (str[i + 1] == 'U')
		amt = ft_uputnbr(va_arg(*lis, unsigned long), pad);
	return (amt);
}

int		ft_printf(const char *str, ...)
{
	int		j;
	int		i;
	va_list		lis;
	int		neg;
	int		amt;

	i = 0;
	amt = 0;
	va_start(lis, str);
	while (str[i])
	{
		neg = 0;
		if (str[i] == '%')
		{
			j = i;
			if (ft_isdigit(str[i + 1]) || str[i + 1] == '-')
			{
				if (str[i + 1] == '-')
				{
					neg = 1;
					i++;
				}
				while (ft_isdigit(str[i + 1]))
					i++;
			}
			if (is_flag(str[i + 1]))
			{
				if (ft_isdigit(str[j + 1]) || neg == 1)
					amt += sort_flags(str, i++, &lis, ft_atoi(str + j + 1));
				else
					amt += sort_flags(str, i++, &lis, 0);
			}
			else
			{
				while (j < i)
				{
					ft_putchar(str[j++]);
					amt++;
				}
				ft_putchar(str[i]);
				amt++;
			}
			i++;
		}
		else
		{
			ft_putchar(str[i++]);
			amt++;
		}
	}
	va_end(lis);
	return (amt);
}
