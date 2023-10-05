#include "Client.hpp"

Client::Client(void) : _username("*"), _nickname("*"), _hostname("*"), _realname("*"), _fd(0), _number(0), _verified(false) {}

Client::Client(int	socketfd, int num) : _username("*"), _nickname("*"), _hostname("*"), _realname("*"), _fd(socketfd), _number(num), _verified(false) {}

Client::~Client() {}

Client::Client(Client &cpy) {}

Client &Client::operator=(Client &cpy) {}

void	Client::sendMessage() {}

void	Client::recieveMessage() {}

void	Client::disconnect() {}