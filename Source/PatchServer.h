#ifndef __PATCHSERVER_H__
#define __PATCHSERVER_H__

#include "@@headers.h"
#include "Client.h"

class PatchServer : public ConnectionServer
{
private:
	// ConnectionServer.clients : Map<SockAddr, Client>
	::Client& getClient(Int i);

	void ClientConnect(::Client &client);
	void ClientDisconnect(::Client &client);

public:
	PatchServer();
	void update();

public:
	Memc< ::Client*> conclient;

private:
	UInt flush;
};

extern PatchServer g_PatchServer;

#endif