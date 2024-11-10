#include "Player.hpp"

Player::Player() : animations(sprite)
{
	this->initVariables();
	this->initSprite();
	this->initAnim();
	this->initPhysics();
}

Player::~Player()
{
}

void Player::update(float &dt)
{
	this->updateMovement();
	this->updatePhysics();
	this->updateAnim(dt);
	for (auto &weapon : this->weapons)
	{
		weapon.update(dt, this->getPosition());
	}
}

void Player::render(sf::RenderTarget &target)
{
	target.draw(this->sprite);
}

void Player::updateMovement()
{
	PlayerState newState = this->determineState();
	this->updateSpriteFacing();
	if (newState != currentState)
	{
		currentState = newState;
		switch (currentState)
		{
		case PlayerState::IDLE:
			animations.playAnimation(PlayerState::IDLE);
			break;
		case PlayerState::UP:
			animations.playAnimation(PlayerState::UP);
			break;
		case PlayerState::RIGHT:
			animations.playAnimation(PlayerState::RIGHT);
			break;
		case PlayerState::DOWN:
			animations.playAnimation(PlayerState::DOWN);
			break;
		case PlayerState::LEFT:
			animations.playAnimation(PlayerState::LEFT);
			break;

		default:
			break;
		}
	}
}

void Player::updateAnim(float &dt)
{
	animations.update(dt);
}

void Player::updatePhysics()
{
	// deceleration
	this->velocity *= this->drag;
	// limit deceleration
	if (std::abs(this->velocity.x) < this->velocityMin)
		this->velocity.x = 0.f;
	if (std::abs(this->velocity.y) < this->velocityMin)
		this->velocity.y = 0.f;
	this->sprite.move(this->velocity);
}

void Player::move(const float dir_x, const float dir_y)
{
	// acceleration
	this->velocity.x += dir_x * this->acceleration;
	this->velocity.y += dir_y * this->acceleration;
	// limit velocity
	if (std::abs(this->velocity.x) > this->velocityMax)
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0) ?
				-1.f : 1.f);
	if (std::abs(this->velocity.y) > this->velocityMax)
		this->velocity.y = this->velocityMax * ((this->velocity.y < 0) ?
				-1.f : 1.f);
}

void Player::updateSpriteFacing()
{
	if (velocity.x > 0.f)
	{
		this->sprite.setOrigin({0, 0});
		this->sprite.setScale(this->scale, this->scale);
	}
	else if (velocity.x < 0.f)
	{
		this->sprite.setOrigin({this->sprite.getGlobalBounds().width / this->scale, 0});
		this->sprite.setScale(-this->scale, this->scale);
	}
}

PlayerState Player::determineState()
{
	if (this->velocity.y < 0.f)
		return PlayerState::UP;
	if (this->velocity.y > 0.f)
		return PlayerState::DOWN;
	if (this->velocity.x > 0.f)
		return PlayerState::RIGHT;
	if (this->velocity.x < 0.f)
		return PlayerState::LEFT;
	return PlayerState::IDLE;
}

void Player::addWeapon(WeaponType type)
{
	this->weapons.emplace_back(type);
}

const sf::Vector2f Player::getPosition() const
{
	return (this->sprite.getPosition());
}

const sf::FloatRect Player::getGlobalBounds() const
{
	return (this->sprite.getGlobalBounds());
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::initVariables()
{
	this->currentState = PlayerState::NOTHING;
	this->scale = 3.f;
}

void Player::initSprite()
{
	this->sprite.setScale(this->scale, this->scale);
}

void Player::initAnim()
{
	if (!animations.loadTexture("../../textures/rpg_char/Characters(100x100)/Soldier/Soldier with shadows/Soldier.png"))
		std::cout << "ERROR::PLAYER::INIT_ANIM::LOAD_TEXTURE\n";
	animations.addAnim(PlayerState::IDLE, {100, 100}, {0, 0}, 6,
		sf::Time(sf::milliseconds(100)), true);
	animations.addAnim(PlayerState::UP, {100, 100}, {0, 1}, 8,
		sf::Time(sf::milliseconds(100)), true);
	animations.addAnim(PlayerState::RIGHT, {100, 100}, {0, 1}, 8,
		sf::Time(sf::milliseconds(100)), true);
	animations.addAnim(PlayerState::DOWN, {100, 100}, {0, 1}, 8,
		sf::Time(sf::milliseconds(100)), true);
	animations.addAnim(PlayerState::LEFT, {100, 100}, {0, 1}, 8,
		sf::Time(sf::milliseconds(100)), true);
}

void Player::initPhysics()
{
	this->velocityMax = 10.f;
	this->velocityMin = .1f;
	this->acceleration = 1.f;
	this->drag = 0.92f;
}
