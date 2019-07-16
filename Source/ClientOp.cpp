#include "stdafx.h"
#include "Client.h"
#include "Netcommand.h"
#include "Settings.h"

void Client::cmd_SendVersionResult()
{
	C Str8 ip = connection.address().ip4Text();
	File f;

	f.writeMem();
	f.putUInt(CMD_PSC_VERSION);
	f.putBool(versionOk);
	if (!versionOk)
	{
		f.pos(0);
		connection.send(f, -1, false);
		Log(S + "[" + ip + "] version mismatch... disconnected!");
		disconnect();
	}
	else
	{
		Str8 loginIp = Settings::Instance().getVal("LoginIP");
		UInt loginPort = TextUInt(Settings::Instance().getVal("LoginPort"));
		f.putStr(loginIp);
		f.putUInt(loginPort);
		f.pos(0);
		connection.send(f, -1, false);

		Log(S + "[" + ip + "] version matched... proceed!");
	}
};