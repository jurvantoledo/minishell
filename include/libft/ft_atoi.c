/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 15:40:27 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/14 15:40:29 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	x;

	i = 0;
	num = 0;
	x = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			x = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * x);
}

// 23
// 0 * 10 + str[2] - 48   
// ascii value begins at 48 + increased by 2 values is 50 - 48 = 2
// 2 * 10 + str[3] - 48
// ascii value begins at 48 + increased by 3 values is 51 - 48 = 3
