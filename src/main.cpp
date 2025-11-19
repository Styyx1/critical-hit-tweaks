#include "settings.h"
#include "magic-hits.h"
#include "ui.h"

void Listener(SKSE::MessagingInterface::Message* a_msg) {
	switch (a_msg->type) {
	case SKSE::MessagingInterface::kDataLoaded:
		Config::Settings::default_crit_chance_magic.SetValue(3.0);
		Config::Settings::GetSingleton()->UpdateSettings(true);
		MagicHits::OnCriticalHit::GetSingleton()->Register();
		break;
	}
}

SKSE_PLUGIN_LOAD(const SKSE::LoadInterface* a_skse)
{
	SKSE::Init(a_skse, { .trampoline = true });
	Config::Settings::GetSingleton()->UpdateSettings(false);
	SKSE::GetMessagingInterface()->RegisterListener(Listener);
	Menu::RegisterCritMenu();
	return true;
}
