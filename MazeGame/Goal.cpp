#include <iostream>
#include "Goal.h"
#include "Player.h"

Goal::Goal(int x, int y)
	: PlacableActor(x, y)
{
	
}

void Goal::HandleCollision(PlacableActor& CollidingActor)
{
	this->Remove();
	CollidingActor.SetPosition(m_pPosition->x, m_pPosition->y);
}

void Goal::Draw()
{
	std::cout << "X";
}
