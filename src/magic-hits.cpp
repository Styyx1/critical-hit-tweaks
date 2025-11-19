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
            RE::BGSEntryPoint::HandleEntryPoint(RE::BGSEntryPoint::ENTRY_POINT::kCalculateMyCriticalHitDamage, caster, spell,
                target, std::addressof(damage_modifier));

            damage *= damage_modifier;

            const RE::CriticalHit::Event event{caster, nullptr, false};
            RE::CriticalHit::GetEventSource()->SendEvent(&event);
            const std::string crit_msg = std::format("{} {}", MiscUtil::GetGameSetting("sCriticalStrike")->GetString(), target->GetName());
            RE::DebugNotification(crit_msg.c_str(), "UISneakAttack");
        }
    }
}

er OnCriticalHit::ProcessEvent(const RE::CriticalHit::Event* event, RE::BSTEventSource<RE::CriticalHit::Event>* src)
{
    if (!event)
        return er::kContinue;
    if (!event->aggressor) 
        return er::kContinue;    

    REX::INFO("crit event happened for: {}", event->aggressor->GetName());

    return er::kContinue;
}
void OnCriticalHit::Register()
{
    auto src = RE::CriticalHit::GetEventSource();
    src->AddEventSink(this);
    REX::INFO("Registered for Critical Hit Event");
}
} // namespace MagicHits
