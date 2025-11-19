#include "melee-hits.h"

namespace MeleeHits {
	void ApplyCritDMGEntry(RE::BGSPerkEntry::EntryPoint ep, RE::Actor* attacker, RE::TESObjectWEAP* weapon, RE::Actor* target, float& damage)
	{
		auto weap = ActorUtil::getWieldingWeapon(attacker);
		auto weap_dmg = (float)weap->GetAttackDamage();
		REX::INFO("argument dump: \n attacker: {}\n weapon: {}\n target: {}\n damage: {}\n damage new is: {}",
			attacker ? attacker->GetName() : "null",
			weapon ? weapon->GetName() : "null",
			target ? target->GetName() : "null",
			damage, weap_dmg);
		_Hook1(ep, attacker, weapon, target, weap_dmg);
		REX::INFO("damage after adjusting is: {}", weap_dmg);
		return;
	}
}