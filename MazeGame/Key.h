#pragma once
#include "PlacableActor.h"
class Key : public PlacableActor
{
public:
	Key(int x, int y, ActorColor color)
		: PlacableActor(x, y, color)
	{

	}

	virtual ActorType GetType() override { return ActorType::Key; }
	void HandleCollision(PlacableActor& CollidingActor);
	virtual void Draw() override;
};

