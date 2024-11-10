#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "AnimComponent.hpp"
#include "WeaponData.hpp"



class Weapon {
public:
	Weapon(WeaponType type);
	~Weapon();

	void update(float& dt);
	void render(sf::RenderTarget& target);
	
	// Getters
	float getDamage() const { return damage; }
	float getAttackSpeed() const { return Speed; }
	
	// Initialize weapon stats based on type
	void initShape();
	void initStats();
	void initSprite();
	void initAnim();

private:
	const WeaponType type;
	AnimComponent animations;
	sf::Sprite sprite;
	std::unique_ptr<sf::Shape> shape;
	
	// Base stats
	float damage;
	float Speed;
	float critChance;
	float critMultiplier;
	float range;
};