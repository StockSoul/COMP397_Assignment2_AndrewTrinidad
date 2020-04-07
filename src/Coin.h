#pragma once
#ifndef __COIN__
#define __COIN__
#include "DisplayObject.h"

class Coin : public DisplayObject
{
public:
	Coin();
	~Coin();

	void draw() override;
	void update() override;
	void clean() override;

private:
	void m_reset();
	void m_move();
	void m_checkBounds();
};

#endif /* defined (__COIN__) */
