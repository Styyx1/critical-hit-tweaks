#pragma once
#include "mod-data.h"

namespace Config {
	
	struct Settings : REX::Singleton<Settings>, public MOD {
		static inline REX::TOML::F64 default_crit_chance_magic{ SETTINGS, "fDefaultMagicCritChance", 3.0 };
		static inline REX::TOML::F64 default_crit_damage_magic{ SETTINGS, "fDefaultCritMagicModifier", 1.5 };
		static inline REX::TOML::F64 default_crit_damage_melee{ SETTINGS, "fDefaultCritMeleeModifier", 1.5 };

		void UpdateSettings(bool save);
	};
}