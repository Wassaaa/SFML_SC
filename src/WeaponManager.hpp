#pragma once
#include <unordered_map>
#include <memory>
#include "WeaponData.hpp"

class WeaponManager {
private:
	std::unordered_map<WeaponType, WeaponData> weaponData;

	WeaponManager() = default;

public:
	static std::shared_ptr<WeaponManager> getInstance();
	void loadWeaponData();
	const WeaponData& getWeaponData(WeaponType type) const;

	WeaponManager(const WeaponManager&) = delete;
	WeaponManager& operator=(const WeaponManager&) = delete;
};