#include "Background.h"
#include "Game.h"


Background::Background()
{
	TheTextureManager::Instance()->load("../Assets/textures/Space_Background.png",
		"background", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("background");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(0.0f, -960.0f));
	setIsColliding(false);
	setType(BACKGROUND);
	setVelocity(glm::vec2(0.0f, 5.0f));
}

Background::~Background()
{
}

void Background::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("background", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, false);
}

void Background::update()
{
	m_move();
	m_checkBounds();
}

void Background::clean()
{
}

void Background::m_move()
{
	setPosition(getPosition() + getVelocity());
}

void Background::m_checkBounds()
{
	if (getPosition().y >= 0.0f)
	{
		m_reset();
	}
}

void Background::m_reset()
{
	setPosition(glm::vec2(0.0f, -960.0f));
}
