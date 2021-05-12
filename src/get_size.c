int	get_size_hexa(long long number)
{
	int	j;

	j = 1;
	if (!number)
		return (j);
	while (number > 0 && j++)
		number /= 16;
	return (j - 1);
}

int	get_size_decimal(long long number)
{
	int	i;

	i = 1;
	if (number > 0)
	{
		while (number > 0 && i++)
			number /= 10;
		return (i - 1);
	}
	else if (number < 0)
	{
		while (number < 0 && i++)
			number /= 10;
		return (i);
	}
	return (1);
}

int	get_size_pointer(long long number)
{
	int	i;

	i = 2;
	if (!number)
		return (i + 1);
	while (number)
	{
		number /= 16;
		i++;
	}
	return (i);
}
