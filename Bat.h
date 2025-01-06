#pragma once
#include <SFML/Graphics.hpp>

class Bat
{
private:
  sf::Vector2f m_Position;
  sf::RectangleShape m_Shape;
  float m_Speed = 1000.0f;
  bool m_Moving_Right = false;
  bool m_Moving_Left = false;
public:
  Bat(float start_X, float start_Y);
  sf::FloatRect getPosition() const;
  sf::RectangleShape getShape() const;
  void moveLeft();
  void moveRight();
  void stopLeft();
  void stopRight();
  void update(sf::Time delta_Time);
};