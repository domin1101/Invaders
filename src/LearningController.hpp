#pragma once

#ifndef _LEARNINGCONTROLLER_HPP_
#define _LEARNINGCONTROLLER_HPP_

#include "Map.hpp"
#include "Invader.hpp"
#include <LightBulb/Learning/Reinforcement/DQNLearningRule.hpp>
#include "Inspector.hpp"
#include "World.hpp"

class LearningController
{
private:
	std::vector<std::unique_ptr<Invader>> invaders;
	LightBulb::DQNLearningRule* learningRule;
	std::shared_ptr<LightBulb::TransitionStorage> transitionStorage;
	World* world;
public:

	LearningController(World* world_);
	void step();
	bool hasRoundEnded();
	void draw(sf::RenderWindow& window, int offsetY);
	void reset();
	void newGame();
	void storeTransitions(bool force = false);
	void doLearning();
	std::vector<std::unique_ptr<Invader>>& getInvaders();
	LightBulb::DQNLearningRule* createLearningRule();
};

#endif