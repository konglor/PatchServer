#ifndef __APP_H__
#define __APP_H__

#include "PatchServer.h"
#include "GateServer.h"

class PatchApp
{
private:
	PatchServer* p_PatchServer;
	GateServer* p_GateServer;

	Thread t_PatchServer;
	Thread t_GateServer;

	PatchApp();
};

extern PatchApp App;

#endif