#pragma once

namespace MagicHits
{
    using er = RE::BSEventNotifyControl;
struct Critical
{
    //original function is part of a few PerkEntry calls. I took the magnitude one to apply critical hits
    static void ApplyPerkEntrySpellMag(RE::BGSPerkEntry::EntryPoint a_entry, RE::Actor *caster, RE::SpellItem *spell,
                                       RE::Actor *target, float &damage);

    static inline REL::Hook _Hook0{REL::ID(34053), 0x60, ApplyPerkEntrySpellMag};

};
} // namespace MagicHits
