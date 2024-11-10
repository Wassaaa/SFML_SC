#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "AnimComponent.hpp"
#include "WeaponManager.hpp"
#include "WeaponData.hpp"



class Weapon {
public:
	Weapon(WeaponType type);
	~Weapon();

	void update(float& dt, sf::Vector2f playerPos);
	void render(sf::RenderTarget& target);
	
	// Getters
	float getDamage() const { return this->currentDamage; }
	float getAttackSpeed() const { return this->currentSpeed; }
	float getCritChance() const { return this->currentCritChance; }
	float getCritDamage() const { return this->currentCritDamage; }
	float getCurrentRange() const { return this->currentRange; }

	
	// Initialize weapon stats based on type
	void initShape();
	void initStats();
	void initSprite();
	void initAnim();

private:
	const WeaponType type;
	const WeaponData *data;
	sf::Sprite sprite;
	AnimComponent animations;
	
	// Base stats
	float currentDamage;
	float currentSpeed;
	float currentCritChance;
	float currentCritDamage;
	float currentRange;
};