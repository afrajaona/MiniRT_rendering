#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "parse.h"

double	ft_atod(char *s)
{
	int		i;
	double	decimal;
	int		count;
	double	res;
	int		j;

	i = 0;
	count = 0;
	res = 0.0;
	decimal = 0.0;
	while (s && s[i] && s[i] == ' ')
		i++;
	j = i;
	if (!s || (s[i] == '-' && !ft_isdigit(s[i + 1])))
		return (0);
	if (s[i] == '-')
	{
		j = i;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	if (s[i] == '.')
	{
		while (s[++i] && ft_isdigit(s[i]))
		{
			decimal = decimal * 10 + s[i] - '0';
			count++;
		}
	}
	if (s[j] == '-')
		return (-(res + decimal / pow(10, count)));
	return (res + decimal / pow(10, count));
}
