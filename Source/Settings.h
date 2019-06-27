#ifndef __SETTINGS_H__
#define __SETTINGS_H__

#include "@@headers.h"
#include "StrMap.h"

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