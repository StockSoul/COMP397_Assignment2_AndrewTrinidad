#pragma once
#ifndef __END_SCENE__
#define __END_SCENE__

#include "Scene.h"
#include "Label.h"
#include "RestartButton.h"

class Ocean;

class EndScene : public Scene
{
public:
	EndScene();
	~EndScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	// getters
	glm::vec2 getMousePosition();
	
private:
	// Game Objects
	Label* m_pGameOverLabel{};
	RestartButton* m_pRestartButton{};
	Ocean* m_pOcean{};

	// private data member
	glm::vec2 m_mousePosition;
};

#endif /* defined (__END_SCENE__) */