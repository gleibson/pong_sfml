#include "bat.h"

//constructor
Bat::Bat(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	batshape.setSize(sf::Vector2f(50, 5));
	batshape.setPosition(position);
}

sf::FloatRect Bat::getPosition()
{
	return batshape.getGlobalBounds();
}

sf::RectangleShape Bat::getShape()
{
	return batshape;
}
void Bat::MoveLeft()
{
	position.x -= batspeed;
}
void Bat::MoveRight()
{
	position.x += batspeed;
}
void Bat::Update()
{
	batshape.setPosition(position);
}







