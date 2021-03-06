#pragma once

#ifndef _INVADER_HPP_
#define _INVADER_HPP_

#include "AbstractDrawable.hpp"
#include "AbstractGameObject.hpp"
#include "LightBulb/Learning/Reinforcement/AbstractDefaultReinforcementIndividual.hpp"

namespace sf {
	class RenderWindow;
}

class World;

class Invader : public AbstractDrawable, public AbstractGameObject, public LightBulb::AbstractDefaultReinforcementIndividual
{
	World* world;
	sf::Vector2i lastPos;
	bool marked;
protected:
	void interpretNNOutput(LightBulb::Vector<char>& output) override;
	bool doStep() override;
public:
	Invader(World* world, sf::Vector2i pos_, const LightBulb::FeedForwardNetworkTopologyOptions& networkTopologyOptions);
	virtual void draw(sf::RenderWindow& window, sf::Vector2i offset);
	void getNNInput(LightBulb::Vector<>& input) const override;
	void isTerminalState(LightBulb::Scalar<char>& isTerminalState) const override;
	void getReward(LightBulb::Scalar<>& reward) const override;
	void setMarked(bool marked_);
};

#endif