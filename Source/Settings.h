#ifndef __SETTINGS_H__
#define __SETTINGS_H__

#include "@@headers.h"

// TODO: move this to seperate .h file (if Map<Str, Str> is to be used again)
static Int Compare(C Str &a, C Str &b) { return EE::CompareCS(a, b); }
static Bool Create(Str &data, C Str &key, Ptr user) { return true; }

/** 
 * Singleton for Settings
 * settings stored in EE:Map to decrease compile time upon new settings
 */
class Settings
{
public:
	static Settings& Instance()
	{
		static Settings instance;
		return instance;
	}

	void Load(TextData &data);
	void Load(C Str &name);

	C Str& getVal(C Str &k);

private:
	Settings() {};
	Settings(const Settings&);
	Settings& operator=(const Settings&);

	Map<Str, Str> cfg = Map<Str, Str>(Compare, Create);
};

#endif