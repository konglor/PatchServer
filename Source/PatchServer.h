#ifndef __PATCHSERVER_H__
#define __PATCHSERVER_H__

#include "@@headers.h"

class PatchServer : ConnectionServer
{
	void update();

public:
	PatchServer();
};

extern PatchServer g_PatchServer;

#endif