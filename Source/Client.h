#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "@@headers.h"

class Client : ConnectionServer::Client
{
private:
	bool versionOk;

private:
	virtual void create(ConnectionServer &server);
	virtual bool update();
	bool disconnect();

	void process();

public:
	Client();
	~Client();
};

#endif