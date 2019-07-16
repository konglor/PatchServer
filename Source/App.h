#ifndef __APP_H__
#define __APP_H__

#include "PatchServer.h"
#include "GateServer.h"

class PatchApp
{
private:
	PatchServer* m_pPatchServer;
	GateServer* m_pGateServer;

	Thread* m_tPatchThread;
	Thread* m_tGateThread;

public:
	PatchApp();
	~PatchApp();

	void init();
	void shut();
};

extern PatchApp g_PatchApp;

#endif