#pragma once
#include "PlacableActor.h"
class Goal : public PlacableActor
{
public:
	Goal(int x, int y);

	virtual ActorType GetType() override { return ActorType::Goal; }
	void HandleCollision(PlacableActor &CollidingActor) override;
	virtual void Draw() override;
};

