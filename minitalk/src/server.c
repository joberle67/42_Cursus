/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:00:31 by joberle           #+#    #+#             */
/*   Updated: 2022/05/24 14:02:17 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	signal_handler(int signum)
{
	static unsigned char	buffer = 0;
	static int				counter = 128;
	static int				i = 8;

	if (signum == SIGUSR1)
	{
		buffer += counter;
		counter = counter / 2;
	}
	else if (signum == SIGUSR2)
		counter = counter / 2;
	i--;
	if (i <= 0 || counter < 1)
	{
		ft_printf("%c", buffer);
		i = 8;
		counter = 128;
		buffer = 0;
	}
}

int	main(void)
{
	ft_printf("PID = %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
