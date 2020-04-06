#include "EndScene.h"
#include "Game.h"
#include <ctime>
#include "glm/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>

EndScene::EndScene()
{
	EndScene::start();
}

EndScene::~EndScene()
= default;

void EndScene::draw()
{
	m_pOcean->draw();
	m_pGameOverLabel->draw();
	m_pRestartButton->draw();
}

void EndScene::update()
{
	m_pOcean->update();
	m_pRestartButton->setMousePosition(m_mousePosition);
	m_pRestartButton->ButtonClick();
}

void EndScene::clean()
{
	delete m_pGameOverLabel;
	removeAllChildren();
}

void EndScene::handleEvents()
{
	auto wheel = 0;
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRestartButton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRestartButton->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;






		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::LEVEL1_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			}
			break;

		default:
			break;
		}
	}
}

void EndScene::start()
{
	m_pOcean = new Ocean();
	addChild(m_pOcean);
	
	const SDL_Color yellow = { 255, 255, 0, 255 };
	m_pGameOverLabel = new Label("Game Over", "Dock51", 80, yellow, glm::vec2(320.0f, 100.0f));
	m_pGameOverLabel->setParent(this);
	addChild(m_pGameOverLabel);

	m_pRestartButton = new RestartButton();
	m_pRestartButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f));
	addChild(m_pRestartButton);
}
