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

	/* Response from server when client sends its version
	 * deny connection if version does not match
	 * sends loginserver ip and port so client can log in if version match
	 */
	void cmd_SendVersionResult();

public:
	Client();
	~Client();
};

#endif