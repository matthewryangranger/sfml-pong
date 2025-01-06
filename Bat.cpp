#include "Bat.h"

Bat::Bat(float startX, float startY): m_Position(startX, startY)
{
  m_Shape.setSize(sf::Vector2f(50,5));
  m_Shape.setPosition(m_Position);
}