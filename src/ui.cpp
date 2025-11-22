#include "ui.h"
#include "settings.h"

namespace Menu
{

void RegisterCritMenu()
{
    if (!SKSEMenuFramework::IsInstalled())
    {
        return;
    }
    SKSEMenuFramework::SetSection(Titles::MOD_TITLE);
    SKSEMenuFramework::AddSectionItem(Titles::SETTINGS_SEC, Settings::RenderSettings);
    RestoreFromSettings();
}

void RestoreFromSettings()
{
    using set = Config::Settings;
    using namespace Settings::Var;

    default_crit_chance_magic = set::default_crit_chance_magic.GetValue();
    default_crit_damage_magic = set::default_crit_damage_magic.GetValue();
    default_crit_damage_melee = set::default_crit_damage_melee.GetValue();
}

void ResetDefaults()
{
    using set = Config::Settings;
    using namespace Settings::Var;
    default_crit_chance_magic = 0.0f;
    default_crit_damage_magic = 1.0f;
    default_crit_damage_melee = 1.0f;

    set::default_crit_chance_magic.SetValue(default_crit_chance_magic);
    set::default_crit_damage_magic.SetValue(default_crit_damage_magic);
    set::default_crit_damage_melee.SetValue(default_crit_damage_melee);
}

void RenderSystem()
{
    ImGui::NewLine();
    ImGui::SeparatorText(Label::system.c_str());

    if (ImGui::Button(Label::save_settings.c_str()))
    {
        Config::Settings::GetSingleton()->UpdateSettings(true);
    }

    ImGui::SameLine();
    if (ImGui::Button(Label::restore_defaults.c_str()))
    {
        ResetDefaults();
    }
}



namespace Settings
{
void __stdcall RenderSettings()
{
    using set = Config::Settings;
    FontAwesome::PushSolid();

    ImGui::Text(Titles::MAGIC_SETTING.c_str());
    ImGui::NewLine();

    ImGui::SetNextItemWidth(200.f);
    if (ImGui::SliderFloat(Label::default_crit_chance_magic.c_str(), &Var::default_crit_chance_magic, 0.0, 100.0, "%.2f"))
        set::default_crit_chance_magic.SetValue(Var::default_crit_chance_magic);
    ImGui::SameLine();
    ux::HelpMarker(Tool::default_crit_chance_magic.c_str());

    ImGui::SetNextItemWidth(200.f);
    if (ImGui::SliderFloat(Label::default_crit_damage_magic.c_str(), &Var::default_crit_damage_magic, 1.0f, 4.f, "%.2f"))
        set::default_crit_damage_magic.SetValue(Var::default_crit_damage_magic);
    ImGui::SameLine();
    ux::HelpMarker(Tool::default_crit_damage_magic.c_str());

    ImGui::Text(Titles::MELEE_SETTING.c_str());
    ImGui::NewLine();

    ImGui::SetNextItemWidth(200.f);
    if (ImGui::SliderFloat(Label::default_crit_damage_melee.c_str(), &Var::default_crit_damage_melee, 1.0f, 4.0f, "%.2f"))
        set::default_crit_damage_melee.SetValue(Var::default_crit_damage_melee);
    ImGui::SameLine();
    ux::HelpMarker(Tool::default_crit_damage_melee.c_str());

    // Settings
    RenderSystem();

    FontAwesome::Pop();
}
} // namespace Settings
} // namespace Menu
