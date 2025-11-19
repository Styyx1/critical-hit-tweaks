#pragma once

namespace MagicHits
{
    using er = RE::BSEventNotifyControl;
struct Critical
{
    static void ApplyPerkEntrySpellMag(RE::BGSPerkEntry::EntryPoint a_entry, RE::Actor *caster, RE::SpellItem *spell,
                                       RE::Actor *target, float &damage);

    static inline REL::Hook _Hook0{REL::ID(34053), 0x60, ApplyPerkEntrySpellMag};

};

struct OnCriticalHit : REX::Singleton<OnCriticalHit>, public RE::BSTEventSink<RE::CriticalHit::Event> {
    

    er ProcessEvent(const RE::CriticalHit::Event* event, RE::BSTEventSource<RE::CriticalHit::Event>* src) override;
    void Register();

};
} // namespace MagicHits
