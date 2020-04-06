#include "Cloud.h"
#include "Game.h"

Cloud::Cloud()
{
	TheTextureManager::Instance()->load("../Assets/textures/cloud.png",
		"cloud", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	const auto size = TheTextureManager::Instance()->getTextureSize("cloud");
	setWidth(size.x);
	setHeight(size.y);

	m_reset();
	setIsColliding(false);
	setType(GameObjectType::CLOUD);
	

	TheSoundManager::Instance()->load("../Assets/audio/thunder.ogg", "thunder", SOUND_SFX);
}

Cloud::~Cloud()
= default;

void Cloud::draw()
{
	const int xComponent = getPosition().x;
	const int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("cloud", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 128, true);
}

void Cloud::update()
{
	m_move();
	m_checkBounds();
}

void Cloud::clean()
{
}

void Cloud::m_reset()
{
	// speed changes
	const auto randomVelocityX = Util::RandomRange(-2, 2);
	const auto randomVelocityY = Util::RandomRange(5, 10);
	setVelocity(glm::vec2(randomVelocityX, randomVelocityY));

	// positional changes
	const auto randomX = Util::RandomRange(getWidth() * 0.5, Config::SCREEN_WIDTH - getWidth());
	setPosition(glm::vec2(randomX, -getHeight()));
}

void Cloud::m_move()
{
	const int xPos = getPosition().x + getVelocity().x;
	const int yPos = getPosition().y + getVelocity().y;
	setPosition(glm::vec2(xPos, yPos));
}

void Cloud::m_checkBounds()
{
	if (getPosition().y > Config::SCREEN_HEIGHT + getHeight())
	{
		m_reset();
	}
}
