#include <iostream>
#include "Companion.h"

Companion::Companion(int x, int y, int reward)
	: PlacableActor(x, y)
	, m_reward(reward)
	, m_given(false)
{

}

int Companion::GiveReward()
{
	if (m_given && (m_reward > 0))
	{
		m_reward = 0;
	}
	else
	{
		m_given = true;
	}
	return m_reward;
}

void Companion::Draw()
{
	std::cout << "*";
}