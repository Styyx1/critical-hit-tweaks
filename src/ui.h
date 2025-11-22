#pragma once

#include <st-ui.h>

namespace Menu {

	using ux = StyyxUtil::UIUtil;

	namespace Titles {
		inline std::string MOD_TITLE = "Critical Hit Tweaks";
		inline std::string SETTINGS_SEC = "Settings";
	}
	namespace Label {
		inline std::string system = FontAwesome::UnicodeToUtf8(0xf390) + " System";
		inline std::string save_settings = FontAwesome::UnicodeToUtf8(0xf0c7) + " Save Settings";
		inline std::string restore_defaults = FontAwesome::UnicodeToUtf8(0xf0e2) + " Reset Settings";
	}
	void RegisterCritMenu();
	void RestoreFromSettings();
	void RenderSystem();
	void ResetDefaults();

	namespace Settings {
		namespace Titles {
			inline std::string MAGIC_SETTING = "Magic Critical Hits";
			inline std::string MELEE_SETTING = "Melee Critical Hits";
		}
		namespace Label {
			inline std::string default_crit_chance_magic = "Default Critical Hit Chance";
			inline std::string default_crit_damage_magic = "Default Crit Damage Modifier Magic";
			inline std::string default_crit_damage_melee = "Default Crit Damage Modifier Weapons";
		}
		namespace Tool {
			inline std::string default_crit_chance_magic = "Default Chance to land a critical hit with any playable spell.";
			inline std::string default_crit_damage_magic = "Default modifier for magic critical hits";
			inline std::string default_crit_damage_melee = "Default modifier for critical hits with weapons";
		}
		namespace Var {
			inline float default_crit_chance_magic;
			inline float default_crit_damage_magic;
			inline float default_crit_damage_melee;
		}
		void __stdcall RenderSettings();
	}


}
