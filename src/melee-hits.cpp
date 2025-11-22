#include "melee-hits.h"
#include "settings.h"

namespace MeleeHits
{
void ApplyCritDMGEntry(RE::BGSPerkEntry::EntryPoint ep, RE::Actor *attacker, RE::TESObjectWEAP *weapon,
                       RE::Actor *target, float &damage)
{
    float modifier = Config::Settings::default_crit_damage_melee.GetValue();
    float item_health = 1.0f;
    auto &data_list = attacker->GetInventoryChanges(false)->entryList;
    //loop through inventory and check for extra data on *weapon. attacker->GetAttackingWeapon() does not work with bows, so, this is the workaround for that
    if (data_list && !data_list->empty())
    {
        for (const auto &entry_data : *data_list)
        {
            if (!entry_data)
                continue;

            if (entry_data->object == weapon)
            {
                for (const auto &sList : *entry_data->extraLists)
                {
                    auto extraHealth = sList->GetByType<RE::ExtraHealth>();
                    if (extraHealth) {
                        item_health = extraHealth->health;
                    }                    
                    break;
                }
                break;
            }
        }
    }
    auto weap_dmg = static_cast<float>(weapon->GetAttackDamage());
    float temper_dmg = GetDamageFromTemper(item_health);

    //weap_dmg + temper_dmg is the actual shown damage in the inventory
    weap_dmg += temper_dmg;
    damage = weap_dmg;

    //can't pass addressof(weap_dmg) cause the original damage gets used later on from the game    
    _Hook1(ep, attacker, weapon, target, damage);
    damage *= modifier;


    REX::DEBUG("end damage for {} is: {}", attacker->GetName(), damage);
    REX::DEBUG("entry point is: {}", MiscUtil::EntryPointToString(ep));

}
} // namespace MeleeHits
