/* PatchServer
 * verifies that the client is up to date
 * verifies that the client and server have the same version
 * sends the GateServer IP and port to client so client may connect to the game
 * Security Checks: TCP Flood / SPOF (if this service goes down, no one will be able to log in)
 */
#include "stdafx.h"
#include "@@headers.h"
#include "Settings.h"
#include "PatchServer.h"

void InitPre()
{
	EE_INIT();
	D.mode(480, 300).sync(true).shadowMapSize(0).scale(2);

	App.flag = APP_WORK_IN_BACKGROUND |
			   APP_MINIMIZABLE |
			   APP_NO_PAUSE_ON_WINDOW_MOVE_SIZE |
			   APP_ALLOW_NO_GPU;

	Settings::Instance().Load("config.cfg");
}

bool Init()
{
	Skeletons.mode(CACHE_DUMMY_NULL);
	Animations.mode(CACHE_DUMMY_NULL);
	Images.mode(CACHE_DUMMY_NULL);
	Materials.mode(CACHE_DUMMY_NULL);
	Meshes.mode(CACHE_DUMMY_NULL);
	PhysBodies.mode(CACHE_DUMMY_NULL);
	ParticlesCache.mode(CACHE_DUMMY_NULL);

	Int port = TextInt((CChar*)Settings::Instance().getVal("Port"));
	if (!g_PatchServer.create(port))
		Exit("Can't create Server TCP Socket");

	return true;
}

bool Update()
{
	g_PatchServer.update();
	Gui.update();
	Time.wait(1);
	return true;
}

void Shut()
{
	g_PatchServer.del();
}

void Draw()
{
	D.clear(WHITE);

	TextStyleParams ts(true);
	ts.align.set(1, -1);
	flt y = D.h(), h = ts.size.y;

	D.text(ts, -D.w(), y, S + "Service: " + Settings::Instance().getVal("Service"));
	y -= h;
	D.text(ts, -D.w(), y, S + "Version: " + Settings::Instance().getVal("Version"));
	y -= h;
	Int port = TextInt((CChar*)Settings::Instance().getVal("Port"));
	D.text(ts, -D.w(), y, S + "Port: " + Settings::Instance().getVal("Port"));
	y -= h;

	Gui.draw();
}