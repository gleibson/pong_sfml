#pragma once
#include <SFML\Graphics.hpp>

class Ball
{
private:
	sf::Vector2f position; //Position of the ball

	sf::RectangleShape ballshape; //draw the ball

	float xVelocity = .2f;
	float yVelocity = .2f; //speed of ball

public:

	Ball(float startX, float startY); //for constructor startpostion

	sf::FloatRect getPosition();
	
	sf::RectangleShape getShape();

	float getXVelocity();

	void ReboundSides(); //dealing with a ball on the side of screen

	void ReboundBatorTop(); //dealing with a ball on the top of screen

	void hitBottom(); //dealing with a ball on the bottom of screen

	void Update();

};