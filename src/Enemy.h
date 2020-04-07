#pragma once
#ifndef __ENEMY__
#define __ENEMY__
#include "DisplayObject.h"
class Enemy : public DisplayObject
{
public:
	Enemy();
	~Enemy();

	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
private:
	void m_reset();
	void m_move();
	void m_checkBounds();
};
#endif /* defined (__ENEMY__) */
