#pragma once
#ifndef __CLOUD__
#define __CLOUD__
#include "DisplayObject.h"
class Cloud : public DisplayObject
{
public:
	Cloud();
	~Cloud();
	
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
private:
	void m_reset();
	void m_move();
	void m_checkBounds();
};
#endif /* defined (__CLOUD__) */

