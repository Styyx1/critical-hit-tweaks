#pragma once

namespace MeleeHits {

	static inline void ApplyCritDMGEntry(RE::BGSPerkEntry::EntryPoint ep, RE::Actor* attacker, RE::TESObjectWEAP* weapon, RE::Actor* target, float& damage);
	//AE ID: 44016 AE Offset: 0x40b
	static inline REL::Hook _Hook1{ REL::ID(44016), 0x40b, ApplyCritDMGEntry };

}
