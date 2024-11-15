#include "Weapon.hpp"

Weapon::Weapon(WeaponType type):
	type(type),
	data(&WeaponManager::getInstance().getWeaponData(type)),
	animations(sprite)
{
	this->initSprite();
	this->initAnim();
}

Weapon::~Weapon()
{
}

void Weapon::update(float &dt, sf::Vector2f playerPos)
{
	this->sprite.setPosition(playerPos + this->data->offset);
	this->sprite.rotate(100.f * dt);
	this->animations.update(dt);
}

void Weapon::render(sf::RenderTarget &target)
{
	target.draw(this->sprite);
}

void Weapon::initShape()
{
}

void Weapon::initStats()
{
}

void Weapon::initSprite()
{
	this->sprite.setOrigin(this->data->origin);
	this->sprite.setRotation(this->data->rotation);
	// this->sprite.setColor(sf::Color::Blue);
}

void Weapon::initAnim()
{
	this->animations.loadTexture(this->data->weaponAnim.texturePath);
	this->animations.addAnim(PlayerState::WEAPON_1, this->data->weaponAnim);
}
