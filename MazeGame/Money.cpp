#include <iostream>
#include "Money.h"

Money::Money(int x, int y, int worth)
	: PlacableActor(x, y)
	, m_worth(worth)
{

}

void Money::HandleCollision(PlacableActor& CollidingActor)
{
	AudioManager::GetInstance()->PlayMoneySound();
	this->Remove();
	CollidingActor.SetPosition(m_pPosition->x, m_pPosition->y);
	CollidingActor.AddMoney(m_worth);
}

void Money::Draw()
{
	std::cout << "$";
}
