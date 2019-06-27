#include "stdafx.h"
#include "Settings.h"

C Str& Settings::getVal(C Str &k)
{
	Str* r = cfg.find(k);
	if (r != null)
		return *r;
	return k;
}

void Settings::Load(TextData &data)
{
	Str key;
	key = "Service";
	if (TextNode *n = data.findNode(key))
		(*cfg.get(key)) = Str(n->asText());

	key = "Version";
	if (TextNode *n = data.findNode(key))
		(*cfg.get(key)) = Str(n->asText());

}

void Settings::Load(C Str &name)
{
	TextData settings;
	if (settings.load(name))
		Load(settings);
}