#include "Island.h"
#include "Game.h"

Island::Island()
{
	TheTextureManager::Instance()->load("../Assets/textures/island.png",
		"island", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("island");
	setWidth(size.x);
	setHeight(size.y);

	m_reset();
	setIsColliding(false);
	setType(GameObjectType::ISLAND);
	setVelocity(glm::vec2(0.0f, 5.0f));

	TheSoundManager::Instance()->load("../Assets/audio/yay.ogg", "yay", SOUND_SFX);

	
}

Island::~Island()
{
}

void Island::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("island", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Island::update()
{
	m_move();
	m_checkBounds();
}

void Island::clean()
{
}

void Island::m_reset()
{
	const auto randomX = Util::RandomRange(getWidth() * 0.5, Config::SCREEN_WIDTH - getWidth());
	setPosition(glm::vec2(randomX, -getHeight()));
}

void Island::m_move()
{
	const int xPos = getPosition().x + getVelocity().x;
	const int yPos = getPosition().y + getVelocity().y;
	setPosition(glm::vec2(xPos, yPos));
}

void Island::m_checkBounds()
{
	if(getPosition().y > Config::SCREEN_HEIGHT + getHeight())
	{
		m_reset();
	}
}
