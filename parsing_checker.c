


/**
 * @brief check the parameter contais onlyn numbers.
 * 
 * @param s parameter to check.
 * @return int 1 yes | 0 no.
 */
int	ft_isnbr(char	*s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == '+' || s[i] == '-'))
		i++;
	while (s[i++])
	{
		if (!ft_isdigit(s[i]))
			return (0);
	}
	return (1);
}

/**
 * @brief compare values
 * 
 * @param s1 1st value.
 * @param s2 2nd value.
 * @return int 0 means same value.
 */
int ft_nbrcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && (s1[i] == '+' && s1[i] == '-'))
		i++;
	i = 0;
	while (s2[i] && (s2[i] == '+' && s2[i] == '-'))
		i++;
	return(ft_strcmp(s1, s2));
}

/**
 * @brief check for duplicate values.
 * 
 * @param argv list of values.
 * @return int 1 same value.
 */
int	ft_isdup(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while(argv[i++])
	{
		while(argv[j])
		{
			if (ft_nbrcmp(argv[i], argv[j] == 0))
				return (1);
			j++;
		}
	}
	return (0);
}