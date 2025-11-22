#include "magic-hits.h"
#include "settings.h"
namespace MagicHits
{

void Critical::ApplyPerkEntrySpellMag(RE::BGSPerkEntry::EntryPoint a_entry, RE::Actor *caster, RE::SpellItem *spell,
                                      RE::Actor *target, float &damage)
{
    _Hook0(a_entry, caster, spell, target, damage);
    float chance = Config::Settings::default_crit_chance_magic.GetValue();

    RE::BGSEntryPoint::HandleEntryPoint(RE::BGSEntryPoint::ENTRY_POINT::kCalculateMyCriticalHitChance, caster, spell,
                                        target, std::addressof(chance));

    if (chance > 0)
    {
        auto calc = RandomiserUtil::GetRandomFloat(0.f, 100.f);
        if (calc <= chance && MagicUtil::IsSpellPlayable(spell))
        {
            float damage_modifier = Config::Settings::default_crit_damage_magic.GetValue();
            float base_damage = damage;

            // the game handles it fairly accurate and it results basically in the same as any manual calcs i did before
            RE::BGSEntryPoint::HandleEntryPoint(RE::BGSEntryPoint::ENTRY_POINT::kCalculateMyCriticalHitDamage, caster,
                                                spell, target, &damage);

            // if i want some extra damage modifier, i think about only applying it if the player has no perks that modify crit damage
            damage *= damage_modifier;

            REX::DEBUG("damage is: {}", damage);

            const RE::CriticalHit::Event event{caster, nullptr, false};
            RE::CriticalHit::GetEventSource()->SendEvent(&event);
            const std::string crit_msg =
                std::format("{} {}", MiscUtil::GetGameSetting("sCriticalStrike")->GetString(), target->GetName());
            RE::DebugNotification(crit_msg.c_str(), "UISneakAttack");
        }
    }
}
} // namespace MagicHits
