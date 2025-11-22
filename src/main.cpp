#include "settings.h"
#include "ui.h"

SKSE_PLUGIN_LOAD(const SKSE::LoadInterface* a_skse)
{
	SKSE::Init(a_skse, { .trampoline = true });
	Config::Settings::GetSingleton()->UpdateSettings(false);
	Menu::RegisterCritMenu();
	return true;
}
