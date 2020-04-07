#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "Plane.h"
#include "Island.h"
#include "Ocean.h"
#include "Cloud.h"
#include "Config.h"
#include "Enemy.h"
#include "Coin.h"
#include "Background.h"

class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

	// getters
	glm::vec2 getMousePosition();

private:
	// game objects
	Plane* m_pPlane;
	//Island* m_pIsland;
	Coin* m_pCoin;
	//Ocean* m_pOcean;
	Background* m_pBackground;

	int m_enemyNum = Config::ENEMY_NUM;
	std::vector<Enemy*> m_pEnemy;
	void m_buildEnemies();

	// private data member
	glm::vec2 m_mousePosition;
	
	
};

#endif /* defined (__LEVEL_1_SCENE__) */
