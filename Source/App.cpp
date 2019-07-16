#include "stdafx.h"
#include "App.h"
#include "Settings.h"

PatchApp g_PatchApp;

PatchApp::PatchApp()
{
	m_pPatchServer = new PatchServer();
	//m_pGateServer;

	m_tPatchThread = new Thread();
	//m_tGateThread;
}

PatchApp::~PatchApp()
{
	m_tPatchThread->del();
}

void PatchApp::init()
{
	// set up threads / pool
	m_tPatchThread->create([](Thread &thread) -> Bool
		{
			g_PatchApp.m_pPatchServer->update();
			Time.wait(100);
			return true;
		});

	// create the server
	Int port = TextInt((CChar*)Settings::Instance().getVal("Port"));
	if (!m_pPatchServer->create(port))
		Exit("Can't create Server TCP Socket");
}

void PatchApp::shut()
{
	m_pPatchServer->del();
}