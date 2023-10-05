#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <stdlib.h>
#include <poll.h>
#include <arpa/inet.h>
#include <string.h>
#include "Client.hpp"
#include "Channel.hpp"
#include <vector>

#define MAX_CLIENT 20



class server
{
	public:
		server(char *port, char *password);
		~server();
		void 					run();
		void					pars(char *buffer, int	num);

		server(server &cpy);
		server &operator=(server &cpy);
		
	private:
		int						_sockfd;
		int						_port;
		std::string				_password;
		struct sockaddr_in		_serv_addr;
		struct pollfd			_thepoll[MAX_CLIENT + 1];
		std::vector<Client>		_clients_list;
		std::vector<Channel>	_channel_list;


};

