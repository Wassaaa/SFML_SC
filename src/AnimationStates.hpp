#ifndef ANIMATION_STATES_HPP
# define ANIMATION_STATES_HPP

enum PlayerState {
	NOTHING,
	IDLE,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	WEAPON_1
};

enum Keybindings {
	MOVE_UP,
	MOVE_RIGHT,
	MOVE_DOWN,
	MOVE_LEFT
};

struct AnimInfo {
	std::string texturePath;
	sf::Vector2i frameSize;
	sf::Vector2i startPos;
	size_t frameCount;
	sf::Time frameDuration;
	bool loop;
};

#endif
