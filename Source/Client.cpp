#include "stdafx.h"
#include "Client.h"
#include "NetCommand.h"
#include "Settings.h"
#include "@@headers.h"

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
			UInt cVersion = connection.data.getUInt();
			versionOk = cVersion == TextUInt(Settings::Instance().getVal("Version"));
			cmd_SendVersionResult();
		} break;
	}
}