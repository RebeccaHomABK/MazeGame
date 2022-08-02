#include <iostream>
#include <windows.h>
#include "Door.h"

Door::Door(int x, int y, ActorColor color, ActorColor closedColor)
	: PlacableActor(x, y, color)
	, m_isOpen(false)
	, m_closedColor(closedColor)
{

}

void Door::HandleCollision(PlacableActor& CollidingActor)
{
	if (!this->IsOpen())
	{
		if (CollidingActor.HasKey(this->GetColor()))
		{
			this->Open();
			this->Remove();
			CollidingActor.UseKey();
			CollidingActor.SetPosition(m_pPosition->x, m_pPosition->y);
			AudioManager::GetInstance()->PlayDoorOpenSound();
		}
		else
		{
			AudioManager::GetInstance()->PlayDoorClosedSound();
		}
	}
	else
	{
		CollidingActor.SetPosition(m_pPosition->x, m_pPosition->y);
	}
}

void Door::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (m_isOpen)
	{
		SetConsoleTextAttribute(console, (int)m_color);
	}
	else
	{
		SetConsoleTextAttribute(console, (int)m_closedColor);
	}
	std::cout << "|";
	SetConsoleTextAttribute(console, (int)ActorColor::Regular);
}
