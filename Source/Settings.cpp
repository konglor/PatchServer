#include "stdafx.h"
#include "Settings.h"

C Str& Settings::getVal(C Str &k)
{
	Str* r = cfg.find(k);
}

void Settings::Load(TextData &data)
{
	Str key;
	key = "Service";
	if (TextNode *n = data.findNode("Service"))
		(*cfg.get("Service")) = Str(n->asText());

	// Client Port
}

void Settings::Load(C Str &name)
{
	TextData settings;
	if (settings.load(name))
		Load(settings);
}