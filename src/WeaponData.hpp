#pragma once
#include "AnimationStates.hpp"

struct WeaponData {
	AnimInfo weaponAnim;
	float baseDamage;
	float baseSpeed;
	float baseRange;
	float baseRadius;
	float baseCritChance;
	float baseCritDamage;
	float baseCD;
	float baseDuration;

	//positioning
	sf::Vector2f origin;
	sf::Vector2f offset;
	float rotation;
};



enum class WeaponType {
	LASER,
	EXPLOSIONS,
	CONE_CLEAVE,
};
