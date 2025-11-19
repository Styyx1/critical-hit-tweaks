#include "settings.h"

void Config::Settings::UpdateSettings(bool save)
{
	const auto toml = REX::TOML::SettingStore::GetSingleton();
	toml->Init(CONFIG_PATH_DEFAULT.data(), CONFIG_PATH_CUSTOM.data());
	if (!save)
		toml->Load();
	else
		toml->Save();
}
