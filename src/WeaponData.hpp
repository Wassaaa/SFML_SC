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
};



enum class WeaponType {
	LASER,
	EXPLOSIONS,
	CONE_CLEAVE,
};