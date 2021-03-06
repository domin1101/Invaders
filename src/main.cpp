#include "LightBulb/NeuralNetwork/NeuralNetwork.hpp"
#include "LightBulb/NetworkTopology/FeedForwardNetworkTopology.hpp"
#include "LightBulb/NeuronDescription/SameNeuronDescriptionFactory.hpp"
#include "LightBulb/NeuronDescription/NeuronDescription.hpp"
#include "LightBulb/Function/InputFunction/WeightedSumFunction.hpp"
#include "LightBulb/Function/ActivationFunction/FermiFunction.hpp"
#include "LightBulb/ActivationOrder/TopologicalOrder.hpp"
#include "LightBulb/Random/StandardRandomGenerator.hpp"

#include <SFML/Graphics.hpp>
#include "Game.hpp"

int main2()
{
	LightBulb::StandardRandomGenerator<> randomGenerator;

	LightBulb::FeedForwardNetworkTopologyOptions options;
	options.neuronsPerLayerCount.push_back(3);
	options.neuronsPerLayerCount.push_back(2);
	options.neuronsPerLayerCount.push_back(1);
	options.descriptionFactory = new LightBulb::SameNeuronDescriptionFactory(new LightBulb::NeuronDescription(new LightBulb::WeightedSumFunction(), new LightBulb::FermiFunction()));

	LightBulb::FeedForwardNetworkTopology* networkTopology = new LightBulb::FeedForwardNetworkTopology(options);
	LightBulb::NeuralNetwork network(networkTopology);

	network.getNetworkTopology().randomizeDependingOnLayerSize(randomGenerator);

	std::vector<double> input(3);
	input[0] = -1;
	input[1] = 3;
	input[2] = 1;
	std::vector<double> output = network.calculate(input, LightBulb::TopologicalOrder());
	std::cout << std::to_string(output[0]);

	getchar();
	return 0;
}


int main3()
{
	sf::RenderWindow window(sf::VideoMode(1000, 450), "SFML works!");
	Game game;
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed)
				game.click(event.mouseButton);
		}

		if (clock.getElapsedTime().asMilliseconds() > 1000 / 30)
		{
			game.step();
			clock.restart();
		}

		window.clear();
		game.draw(window);
		window.display();
	}

	return 0;
}

#include "LightBulbApp/App.hpp"

int main(int argc, char** argv)
{
	std::cout << viennacl::ocl::current_device().name() << std::endl;

	LightBulb::App* app = new LightBulb::App();
	app->addTrainingPlan(new Game());

	wxApp::SetInstance(app);
	wxEntry(argc, argv);

	return 0;
}
