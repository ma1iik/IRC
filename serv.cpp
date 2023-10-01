/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ma1iik <ma1iik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:43:46 by ma1iik            #+#    #+#             */
/*   Updated: 2023/10/01 15:30:36 by ma1iik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serv.hpp"

server::server(char *port, char *pwd) : _port(std::atoi(port)), _password(pwd) {}

server::~server() {}

server::server(server &cpy) {
	*this = cpy;
}

server& server::operator=(server &rhs) {
	this->_password = rhs._password;
	this->_port = rhs._port;
	this->_serv_addr = rhs._serv_addr;
	this->_sockfd = rhs._sockfd;
	//this->_thepoll = rhs._thepoll; //SHALLOW COPY FIX LATER //
	return *this;
}

void	server::run(void) {
	char	BUFFER[4098];
	this->_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	int newClient;
	this->_clients_list.reserve(MAX_CLIENT);
	if (this->_sockfd < 0) {
		// throw an exception (u have to code one, retard)
	}
	int yes = 1; // 1 means "yes, enable the option"
	if (setsockopt(this->_sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0) {
    	//  throw an exception (u have to code one, retard)
	}
	this->_serv_addr.sin_addr.s_addr = INADDR_ANY; //check this
	this->_serv_addr.sin_family = AF_INET;
	this->_serv_addr.sin_port = htons(this->_port);

	if (bind(this->_sockfd, (struct sockaddr*)&this->_serv_addr, sizeof(this->_serv_addr)) < 0) {
		//  throw an exception (u have to code one, retard)
	}

	if (listen(this->_sockfd, MAX_CLIENT) < 0) {
		// throw exception
	}

	memset(this->_thepoll, 0, sizeof(this->_thepoll));
	this->_thepoll[0].fd = this->_sockfd;       // NOTE: read about the poll for better understanding
	this->_thepoll[0].events = POLLIN;
	while (true) {
		if (poll(this->_thepoll, MAX_CLIENT + 1, -1) < 0) {
			//throw exception
		}
		if (this->_thepoll[0].revents & POLLIN) {
			newClient = accept(this->_sockfd, 0,0);
			if (newClient <= 0) {
				//throw exception
			}
			for (int i = 0; i < MAX_CLIENT + 1; i++) {
				if (this->_thepoll[i].fd == 0) {
					this->_thepoll[i].fd = newClient;
					this->_thepoll[i].events = POLLIN;
					this->_clients_list[i-1]._fd = newClient;
					break;
				}
			}
		}
		else {
			for (int i = 1; i < MAX_CLIENT + 1; i++)  {
				if (this->_thepoll[i].revents & POLLIN) {
					int	byte_read = recv(this->_thepoll[i].fd, BUFFER, 4098, 0);
					if (byte_read < 0) {
						// exception
					}
					else if (byte_read == 0){
						// this->cleanClient()  
					}
					else {
						BUFFER[byte_read] = 0;
						std::cout << BUFFER << std::endl;
						
					}
					break;
				}
			}
		}
	}
}