int	ft_atoi(const char *str)
{
	int i = 0;
	int sign = 1;
	int nbr = 0;

	if (!str)
		return (0);
	if (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] && (str[i] == 45 || str[i] == 43))
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while(str[i] && (str[i] >= '0' || str[i] <= '9'))
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	return (nbr * sign);
}