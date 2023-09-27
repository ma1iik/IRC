#pragma once

#include "serv.hpp"

class Client {
	private:
		std::string		_username;
		std::string		_nickname;
		std::string		_hostname;
		std::string		_realname;
		int				_fd;
		int				_verified;

	public:
		Client(char *port, char *password);
		~Client();

		Client(Client &cpy);
		Client &operator=(Client &cpy);

		void	sendMessage();
		void	recieveMessage();
		void	disconnect();
};