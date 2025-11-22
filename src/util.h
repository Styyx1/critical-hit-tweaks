#pragma once
namespace Util {
	class perk_visitor : public RE::PerkEntryVisitor {
	public:
		using pe = RE::BGSEntryPointPerkEntry::EntryData::Function;

		perk_visitor() :
			actor_(nullptr),
			result_(nullptr),
			isSetValue(false),
			entry(nullptr)
		{
		}



		RE::BSContainer::ForEachResult Visit(RE::BGSPerkEntry* perk_entry) override {
			const auto* entry_point = static_cast<RE::BGSEntryPointPerkEntry*>(perk_entry);
			auto* perk = entry_point->perk;

			auto set_val_check = entry_point->entryData.function.any(pe::kSetValue);

			if (set_val_check) {
				isSetValue = true;
				result_ = perk;
				entry = perk_entry;
				REX::DEBUG("searching entry points");
			}
			return RE::BSContainer::ForEachResult::kContinue;
		};
		void SetActor(RE::Actor* actor) {
			actor_ = actor;
		}
		[[nodiscard]] RE::BGSPerk* get_result() const { return result_; };
		[[nodiscard]] bool get_set_value() const { return isSetValue; };
		[[nodiscard]] RE::BGSPerkEntry* get_entry() const { return entry; };

	protected:
		

		RE::Actor* actor_;
		RE::BGSPerk* result_;
		bool isSetValue;
		RE::BGSPerkEntry* entry;
	};
}