#pragma once
#include <unordered_map>
#include <memory>
#include "WeaponData.hpp"

class WeaponManager {

private:
	std::unordered_map<WeaponType, WeaponData> weaponData;
	WeaponManager() {this->loadWeaponData();};

public:
	static WeaponManager &getInstance();

	void loadWeaponData();
	const WeaponData& getWeaponData(WeaponType type) const;

	WeaponManager(const WeaponManager&) = delete;
	WeaponManager& operator=(const WeaponManager&) = delete;
};
