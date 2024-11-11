#ifndef PLAYER_HPP
# define PLAYER_HPP
# include "../pch.hpp"
# include "AnimComponent.hpp"
# include "AnimationStates.hpp"
# include "Weapon.hpp"

class Player
{
public:
	Player();
	~Player();

	//functions
	void update(float &dt);
	void render(sf::RenderTarget& target);
	void updatePhysics();
	void updateMovement();
	void updateAnim(float &dt);
	//movement
	void move(const float dir_x, const float dir_y);
	void updateSpriteFacing();
	PlayerState determineState();
	//weapons
	void addWeapon(WeaponType type);
	//accessors
	const sf::Vector2f getPosition() const;
	const sf::FloatRect getGlobalBounds() const;

	void setPosition(const float x, const float y);

private:
	sf::Sprite sprite;
	sf::Texture textureSheet;
	AnimComponent animations;

	//weapons
	std::vector<Weapon> weapons;

	//variables
	sf::Vector2f playerOrigin;


	//vars
	float scale;

	//Movement
	PlayerState currentState;
	//Animation

	//physics
	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;


	void initVariables();
	void initSprite();
	void initAnim();
	void initPhysics();

};

#endif
