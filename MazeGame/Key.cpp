#include <iostream>
#include <windows.h>

#include "Key.h"

void Key::HandleCollision(PlacableActor& CollidingActor)
{
	if (!CollidingActor.HasKey())
	{
		CollidingActor.PickupKey(this);
		this->Remove();
		CollidingActor.SetPosition(m_pPosition->x, m_pPosition->y);
		AudioManager::GetInstance()->PlayKeyPickupSound();
	}
}

void Key::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, (int)m_color);

	std::cout << "+";
	SetConsoleTextAttribute(console, (int)ActorColor::Regular);
}
