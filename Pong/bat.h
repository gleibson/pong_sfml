#pragma once
#include <SFML/Graphics.hpp>

class Bat
{
private:
	//position players bat
	sf::Vector2f position;
	
	//The bat
	sf::RectangleShape batshape;

	//speed bat moviment
	float batspeed = .3f;

public:
	//position on the screen
	Bat(float startX, float starY);
	
	//Points of retangule shape
	sf::FloatRect getPosition();

	//loop bat shape
	sf::RectangleShape getShape();
	
	void MoveLeft();

	void MoveRight();
	 
	void Update();

};