// #include <stdlib.h>

// int     ft_str_len(char *s)
// {
//     int i = 0;

//     while (s[i])
//         i++;
//     return i;
// }

// static void	ft_bzero(void *s, size_t n)
// {
// 	unsigned char *str;

// 	str = (unsigned char*)s;
// 	while (n--)
// 	{
// 		*str = '\0';
// 		str++;
// 	}
// }

// static char	*ft_strnew(size_t size)
// {
// 	char	*str;

// 	if (!(str = (char*)malloc(sizeof(*str) * (size + 1))))
// 		return (NULL);
// 	ft_bzero(str, size + 1);
// 	return (str);
// }

// static int	count_size(int n)
// {
// 	int i;

// 	i = 0;
// 	if (n < 0)
// 		n *= -1;
// 	while (n != 0)
// 	{
// 		n /= 10;
// 		i++;
// 	}
// 	return (i);
// }

// char		*ft_itoa(int num)
// {
// 	char		*dst;
// 	int			count;
// 	int			i;
// 	long int	n;

// 	n = num;
// 	count = count_size(n);
// 	i = 0;
// 	if (n < 0 || count == 0)
// 		count++;
// 	if (!(dst = ft_strnew(count)))
// 		return (NULL);
// 	if (n < 0)
// 	{
// 		n *= -1;
// 		dst[0] = '-';
// 		i++;
// 	}
// 	while (count > i)
// 	{
// 		count--;
// 		dst[count] = (n % 10) + '0';
// 		n /= 10;
// 	}
// 	return (dst);
// }

// //atoi

// static int	ft_isdigit(int c)
// {
// 	return (c >= '0' && c <= '9');
// }

// int	ft_atoi(const char *str)
// {
// 	int	sign;
// 	int	res;

// 	sign = 1;
// 	while ((*str >= 9 && *str <= 13) || *str == 32)
// 		str++;
// 	if (*str == '-' || *str == '+')
// 	{
// 		if (*str == '-')
// 			sign = -1;
// 		str++;
// 	}
// 	res = 0;
// 	while (ft_isdigit((int)*str))
// 	{
// 		res = (res * 10) + *str - 48;
// 		str++;
// 	}
// 	return (res * sign);
// }