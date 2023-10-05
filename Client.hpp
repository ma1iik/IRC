#pragma once

#include "serv.hpp"

class Client {
	private:
		std::string		_username;
		std::string		_nickname;
		std::string		_hostname;
		std::string		_realname;
		int				_fd;
		int				_number;
		bool			_verified;

	public:
		Client();
		Client(int socketfd, int num);
		~Client();

		Client(Client &cpy);
		Client &operator=(Client &cpy);

		void	sendMessage();
		void	recieveMessage();
		void	disconnect();

		std::string		get_username(void) const{
			return this->_username;
		}

		std::string		get_nickname(void) const{
			return this->_nickname;
		}

		std::string		get_hostname(void) const{
			return this->_hostname;
		}

		std::string		get_realname(void) const{
			return this->_realname;
		}
};