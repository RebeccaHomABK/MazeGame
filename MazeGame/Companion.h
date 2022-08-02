#pragma once
#include "PlacableActor.h"
#include "Player.h"

class Companion : public PlacableActor
{
	int m_reward;
	bool m_given;
public:
	Companion(int x, int y, int reward);

	bool HasGiven() const { return m_given; }

	int GiveReward();

	virtual ActorType GetType() override { return ActorType::Companion; }
	void HandleCollision(Player& CollidingActor);
	virtual void Draw() override;
};