#pragma once

namespace MeleeHits {

	// float& damage is the actual crit damage from the weapon record. 
	// This function changes damage to the weapon damage + tempering bonus and only runs on critical hits. basically when the game calculates crit damage
	static inline void ApplyCritDMGEntry(RE::BGSPerkEntry::EntryPoint ep, RE::Actor* attacker, RE::TESObjectWEAP* weapon, RE::Actor* target, float& damage);

	static inline REL::Hook _Hook1{ REL::ID(44016), 0x40b, ApplyCritDMGEntry };

	//credits to KernalsEgg in the RE discord server for the function address for SE, so i was able to find it for AE
	static inline float GetDamageFromTemper(float a_itemHealth) {
		using func_t = decltype(GetDamageFromTemper);
		REL::Relocation<func_t> func{ REL::ID(26498) };
		return func(a_itemHealth);
	}


}
