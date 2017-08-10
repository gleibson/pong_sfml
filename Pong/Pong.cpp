#include "ball.h"
#include "bat.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main()
{
	//window
	int windowWidth = 1024;
	int windowHeight = 768;
    
	//title
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Pong");

	int score = 0;
	int lives = 3;

	//bat
	Bat bat(windowHeight / 2, windowHeight - 20);

	//ball
	Ball ball(windowHeight / 2, 1);

	//text on Screen
	sf::Text hud;
    sf::Font font;
	font.loadFromFile("ka1.ttf");
	hud.setFont(font);
	hud.setCharacterSize(75);
	hud.setFillColor(sf::Color::White);

//Players Input
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			bat.MoveLeft();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			bat.MoveRight();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		//Update frame

			//hitting the bottom
		if (ball.getPosition().top > windowHeight)
		{
			//reverse the direction of the ball
			ball.hitBottom();

			//remove one life
			lives--;


			//Check for zero lives
			if (lives < 1)
			{
				//reset score
				score = 0;
				//reset lives
				lives = 3;
			}
		}
		//Handle ball hitting top
		if (ball.getPosition().top < 0)
		{
			ball.ReboundBatorTop();

			//Add a point to score player
			score++;
		}
		// ritting sides
		if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth)
		{
			ball.ReboundSides();
		}
		// ritting bat
		if (ball.getPosition().intersects(bat.getPosition()))
		{

			ball.ReboundBatorTop();
		}

		ball.Update();
		bat.Update();

		std::stringstream ss;
		ss << "Score: " << score << "      Lives: " << lives;
		hud.setString(ss.str());

		//Draw the frame

		//Clear eveything from the last frame
		window.clear(sf::Color(26, 128, 182, 255));

		window.draw(bat.getShape());

		window.draw(ball.getShape());
		//draw our score
		window.draw(hud);

		//Show 
		window.display();

	}// End the while
	return 0;
}

