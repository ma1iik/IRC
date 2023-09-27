#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <stdlib.h>
#include <poll.h>
#include <arpa/inet.h>
#include <string.h>
#include "Client.hpp"

#define MAX_CLIENT 20



class server
{
	public:
		server(char *port, char *password);
		~server();
		void run();

		server(server &cpy);
		server &operator=(server &cpy);
		
	private:
		int _sockfd;
		int _port;
		std::string _password;
		struct sockaddr_in _serv_addr;
		struct pollfd	_thepoll[MAX_CLIENT + 1];


};

