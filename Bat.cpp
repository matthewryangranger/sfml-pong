#include "Bat.h"

Bat::Bat(float startX, float startY): m_Position(startX, startY)
{
  m_Shape.setSize(sf::Vector2f(50,5));
  m_Shape.setPosition(m_Position);
}

sf::FloatRect Bat::getPosition() const
{
  return m_Shape.getGlobalBounds();
}

sf::RectangleShape Bat::getShape() const
{
  return m_Shape;
}

void Bat::moveLeft()
{
  m_Moving_Left = true;
}

void Bat::moveRight()
{
  m_Moving_Right = true;
}

void Bat::stopLeft()
{
  m_Moving_Left = false;
}

void Bat::stopRight()
{
  m_Moving_Right = false;
}

void Bat::update(sf::Time dt)
{
  if (m_Moving_Left)
    m_Position.x -= m_Speed * dt.asSeconds();
  if (m_Moving_Right)
    m_Position.x += m_Speed * dt.asSeconds();
  m_Shape.setPosition(m_Position);
}