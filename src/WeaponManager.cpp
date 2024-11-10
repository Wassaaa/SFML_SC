#include "WeaponManager.hpp"

std::shared_ptr<WeaponManager> WeaponManager::getInstance()
{
	static auto instance = std::make_shared<WeaponManager>();
	return instance;
}

void WeaponManager::loadWeaponData() {
	// LASER - Fast, medium damage, long range, precise
	{
		WeaponData& laser = weaponData[WeaponType::LASER];
		laser.animations.loadTexture("");
		laser.baseDamage = 8.f;
		laser.baseSpeed = 0.15f;		// Attacks very frequently
		laser.baseRange = 400.f;		// Long range
		laser.baseRadius = 5.f;			// Thin beam
		laser.baseCritChance = 0.05f;	// 5% crit chance
		laser.baseCritDamage = 1.5f;	// 50% bonus on crit
		laser.baseCD = 0.f;				// No cooldown between shots
		laser.baseDuration = 0.2f;		// Beam lasts briefly
	}

	// EXPLOSIONS - Slow, high damage, medium range, area damage
	{
		WeaponData& explosion = weaponData[WeaponType::EXPLOSIONS];
		explosion.animations.loadTexture("");
		explosion.baseDamage = 25.f;
		explosion.baseSpeed = 1.2f;			// Slow attacks
		explosion.baseRange = 250.f;		// Medium range
		explosion.baseRadius = 60.f;		// Large area of effect
		explosion.baseCritChance = 0.1f;	// 10% crit chance
		explosion.baseCritDamage = 2.f;		// Double damage on crit
		explosion.baseCD = 0.5f;			// Cooldown between explosions
		explosion.baseDuration = 0.4f;		// Explosion effect duration
	}

	// CONE_CLEAVE - Medium speed, medium damage, short range, wide area
	{
		WeaponData& cone = weaponData[WeaponType::CONE_CLEAVE];
		cone.animations.loadTexture("");
		cone.baseDamage = 15.f;
		cone.baseSpeed = 0.8f;			// Medium attack speed
		cone.baseRange = 150.f;			// Short range
		cone.baseRadius = 45.f;			// 45-degree cone
		cone.baseCritChance = 0.08f;	// 8% crit chance
		cone.baseCritDamage = 1.75f;	// 75% bonus on crit
		cone.baseCD = 0.2f;				// Short cooldown
		cone.baseDuration = 0.3f;		// Attack animation duration
	}
}

const WeaponData &WeaponManager::getWeaponData(WeaponType type) const
{
	return this->weaponData.at(type);
}
