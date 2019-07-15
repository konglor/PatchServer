#include "stdafx.h"
#include "Client.h"
#include "NetCommand.h"
#include "Settings.h"

Client::Client() :
	versionOk(false)
{
}

Client::~Client()
{
	connection.del();
}

void Client::create(ConnectionServer &server) // override
{
	C Str8 ip = connection.address().ip4Text();
	connection.tcpNoDelay(true);
}

bool Client::update()
{
	if (!super::update())
		return false;

	REP(8)
	switch (connection.state())
	{
		case CONNECT_GREETED:
		{
		} break;
	}

	if (!connection.receive(0))
	{
	}
	else // process commands
	{
		process();
	}
	return true;
}

bool Client::disconnect()
{
	connection.flush();
	connection.del();
	return false;
}

void Client::process()
{
	UInt cmd = connection.data.getUInt();
	switch (cmd)
	{
		case CMD_CPS_VERSION:
		{
			UInt cVerion = connection.data.getUInt();
			versionOk = connection.data.getUInt() == TextInt(Settings::Instance().getVal("Version"));

			if (!versionOk)
				disconnect(); // TODO: need to update the client

			// TODO: send client ip to gateserver for staging
			// TODO: send gateserver ip to client for connection
		} break;
	}
}