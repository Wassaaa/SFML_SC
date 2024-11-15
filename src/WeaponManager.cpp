#include "WeaponManager.hpp"

WeaponManager& WeaponManager::getInstance() {
	static WeaponManager instance;
	return instance;
}

void WeaponManager::loadWeaponData() {
	// LASER - Fast, medium damage, long range, precise
	{
		WeaponData& laser = weaponData[WeaponType::LASER];
		//anim info
		laser.weaponAnim.texturePath = "../../textures/Legacy/Assets/Misc/fantasy weapons set/PNG/10.png";
		laser.weaponAnim.frameSize = {62, 66};
		laser.weaponAnim.startPos = {0, 0};
		laser.weaponAnim.frameCount = 1;
		laser.weaponAnim.frameDuration = sf::milliseconds(100);
		laser.weaponAnim.loop = true;
		//positioning
		laser.origin = {0.f, 66.f};
		laser.offset = {0.f, 0.f};
		laser.rotation = 0.f;
		//weapon stats
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
		explosion.weaponAnim.texturePath = "needTexture";
		explosion.weaponAnim.frameSize = {20, 20};
		explosion.weaponAnim.startPos = {0, 0};
		explosion.weaponAnim.frameCount = 5;
		explosion.weaponAnim.frameDuration = sf::milliseconds(100);
		explosion.weaponAnim.loop = true;
		//positioning
		explosion.origin = {0.f, 0.f};
		explosion.offset = {0.f, 0.f};
		explosion.rotation = 0.f;
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
		cone.weaponAnim.texturePath = "needTexture";
		cone.weaponAnim.frameSize = {20, 20};
		cone.weaponAnim.startPos = {0, 0};
		cone.weaponAnim.frameCount = 5;
		cone.weaponAnim.frameDuration = sf::milliseconds(100);
		cone.weaponAnim.loop = true;
		//positioning
		cone.origin = {0.f, 0.f};
		cone.offset = {0.f, 0.f};
		cone.rotation = 0.f;
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
