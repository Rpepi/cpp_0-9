/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:06:41 by pepi              #+#    #+#             */
/*   Updated: 2024/10/31 15:08:54 by pepi             ###   ########.fr       */
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
		// Si aucun argument n'est fourni
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		// Parcourir les arguments fournis (en commençant à argv[1] pour ignorer le nom du programme)
		while (i < argc)
		{
			// Parcourir chaque caractère de l'argument et le convertir en majuscule
			while (argv[i][j] != '\0')
			{
				std::cout << (char)std::toupper(argv[i][j]);
                j++;
			}
            j = 0;
            i++;
		}
		std::cout << std::endl; // Nouvelle ligne après la sortie
	}
	return (0);
}
