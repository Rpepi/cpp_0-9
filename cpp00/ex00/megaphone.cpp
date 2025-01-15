/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:06:41 by pepi              #+#    #+#             */
/*   Updated: 2024/12/05 14:30:04 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int	main(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    j = 0;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		while (i < argc)
		{
			while (argv[i][j] != '\0')
			{
				std::cout << (char)std::toupper(argv[i][j]);
                j++;
			}
            j = 0;
            i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
