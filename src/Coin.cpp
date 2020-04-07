#include "Coin.h"
#include "Game.h"

Coin::Coin()
{
	TheTextureManager::Instance()->load("../Assets/textures/coin1.png",
		"coin", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("coin");
	setWidth(size.x);
	setHeight(size.y);

	m_reset();
	setIsColliding(false);
	setType(GameObjectType::COIN);
	setVelocity(glm::vec2(0.0f, 5.0f));

	TheSoundManager::Instance()->load("../Assets/audio/collect.wav", "collect", SOUND_SFX);
}

Coin::~Coin()
{
}

void Coin::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("coin", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Coin::update()
{
	m_move();
	m_checkBounds();
}

void Coin::clean()
{
}

void Coin::m_reset()
{
	const auto randomX = Util::RandomRange(getWidth() * 0.5, Config::SCREEN_WIDTH - getWidth());
	setPosition(glm::vec2(randomX, -getHeight()));
}

void Coin::m_move()
{
	const int xPos = getPosition().x + getVelocity().x;
	const int yPos = getPosition().y + getVelocity().y;
	setPosition(glm::vec2(xPos, yPos));
}

void Coin::m_checkBounds()
{
	if (getPosition().y > Config::SCREEN_HEIGHT + getHeight())
	{
		m_reset();
	}
}
