#pragma once

#include "serv.hpp"

class Channel {
	private:
		std::string		_channel_name;
		std::string		_topic;
		int				_fd;
		int				_verified;
		std::vector<Client>		_Users;

	public:
		Channel(char *port, char *password);
		~Channel();

		Channel(Channel &cpy);
		Channel &operator=(Channel &cpy);

		void	sendMessage();
		void	recieveMessage();
		void	disconnect();
};