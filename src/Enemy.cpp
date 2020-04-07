#include "Enemy.h"
#include "Game.h"

Enemy::Enemy()
{
	TheTextureManager::Instance()->load("../Assets/textures/Spaceship.png",
		"enemy", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	const auto size = TheTextureManager::Instance()->getTextureSize("enemy");
	setWidth(size.x);
	setHeight(size.y);

	m_reset();
	setIsColliding(false);
	setType(GameObjectType::ENEMY);


	TheSoundManager::Instance()->load("../Assets/audio/Hurt.wav", "hurt", SOUND_SFX);
}

Enemy::~Enemy()
= default;

void Enemy::draw()
{
	const int xComponent = getPosition().x;
	const int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("enemy", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 128, true);
}

void Enemy::update()
{
	m_move();
	m_checkBounds();
}

void Enemy::clean()
{
}

void Enemy::m_reset()
{
	const auto randomVelocityX = Util::RandomRange(-2, 2);
	const auto randomVelocityY = Util::RandomRange(5, 10);
	setVelocity(glm::vec2(randomVelocityX, randomVelocityY));

	const auto randomX = Util::RandomRange(getWidth() * 0.5, Config::SCREEN_WIDTH - getWidth());
	setPosition(glm::vec2(randomX, -getHeight()));
}

void Enemy::m_move()
{
	const int xPos = getPosition().x + getVelocity().x;
	const int yPos = getPosition().y + getVelocity().y;
	setPosition(glm::vec2(xPos, yPos));
}

void Enemy::m_checkBounds()
{
	if (getPosition().y > Config::SCREEN_HEIGHT + getHeight())
	{
		m_reset();
	}
}

