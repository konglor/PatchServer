#include "stdafx.h"
#include "Client.h"

Client::Client() :
	versionOk(false)
{
}

Client::~Client()
{
	connection.del();
}

void Client::create(ConnectionServer &server)
{
	C Str8 ip = connection.address().ip4Text();
	Log(ip);
	connection.tcpNoDelay(true);
}

bool Client::update()
{
	if (!super::update())
		return false;

	//Log(connection.state());
	switch (connection.state())
	{
		case CONNECT_GREETED:
		{
		} break;
	}
	return true;
}

bool Client::disconnect()
{
	connection.flush();
	connection.del();
	return false;
}