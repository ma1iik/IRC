/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ma1iik <ma1iik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:21:28 by ma1iik            #+#    #+#             */
/*   Updated: 2023/09/16 14:38:41 by ma1iik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serv.hpp"

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "Usage: ./ircserv <port> <password>" << std::endl;
		return (1);
	}
	int	checkport = std::atoi(argv[1]);
	if (!(checkport >= 1024 && checkport <= 65535)) {
		std::cout << "Invalid Port, Port must be between 1024 and 65535" << std::endl;
	}
	else {
		server serv(argv[1], argv[2]);
		serv.run();
	}

	return (0);
}