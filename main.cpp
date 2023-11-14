#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono;


int main(){
	sf::RenderWindow window(sf::VideoMode(444, 444), "Hello SFML");
	sf::Clock clock;
	bool isRed = true;
	bool isYellow = false;


	sf::Color red(255, 0, 0);
	sf::Color orange(255, 128, 0);
	sf::Color yellow(255, 255, 0);
	sf::Color lgreen(128, 255, 0);
	sf::Color mgreen(0, 255, 0);
	sf::Color dgreen(0, 255, 80);
	sf::Color cyan(0, 255, 255);
	sf::Color lblue(0, 128, 255);
	sf::Color dblue(0, 0, 255);
	sf::Color purple(128, 0, 255);
	sf::Color pink(255, 0, 255);
	sf::Color dpink(255, 0, 128);

	sf::Color colors[12] = {red, orange, yellow, lgreen, mgreen,dgreen, cyan,lblue, dblue, purple, pink, dpink};


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		float elapsedTime = clock.getElapsedTime().asSeconds();
		int colorIndex = int(std::fmod(elapsedTime, 12.0f));
		sf::Color currentColor = colors[colorIndex];
		sf::Color nextColor = colors[(colorIndex + 1) % 12];

		float t = std::fmod(elapsedTime, 1.0f);

		sf::Color bgColor = sf::Color(

			sf::Uint8((1.0f - t) * currentColor.r + t * nextColor.r),
			sf::Uint8((1.0f - t) * currentColor.g + t * nextColor.g),
			sf::Uint8((1.0f - t) * currentColor.b + t * nextColor.b)
		);

		window.clear(bgColor);
		window.display();
	}

	return 0;
}
