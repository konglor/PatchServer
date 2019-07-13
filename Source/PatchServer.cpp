#include "stdafx.h"
#include "PatchServer.h"
#include "Client.h"

PatchServer::PatchServer() :
	flush(0)
{
	clients.replaceClass<::Client>();
}

void PatchServer::update()
{
	super::update();
	REPA(clients) getClient(i).connection.flush();
}

::Client& PatchServer::getClient(Int i)
{
	return (::Client&)clients[i];
}

PatchServer g_PatchServer;