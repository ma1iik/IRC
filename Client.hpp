#pragma once

#include <string.h>

class Client {
	private:
		std::string		username;
		std::string		nickname;
		std::string		hostname;
		std::string		realname;
		int				fd;
		int				verified;

	public:
		Client(char *port, char *password);
		~Client();

		Client(Client &cpy);
		Client &operator=(Client &cpy);

		void	sendMessage();
		void	recieveMessage();
		void	disconnect();
};