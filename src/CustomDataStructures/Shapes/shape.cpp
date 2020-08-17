#include "../vector.cpp"
#include <SFML/Graphics.hpp>

class Shape2D {
public:
  Shape2D() {}
  
  // virtuals
  virtual void draw(sf::RenderWindow * window) {}
};
