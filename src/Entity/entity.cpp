#include <SFML/Graphics.hpp>
#include <math.h>

using namespace std;

class Entity {
private:
  int id;
  static int next_id;

public:
  Entity() {
    id = next_id;
    next_id++;
  }

  // getter --

  int getId() { return id; }

  // virtual

  virtual void start() {}
  virtual void update() {}
  virtual void draw(sf::RenderWindow * window) {
    sf::RectangleShape * rectangle = new sf::RectangleShape();
    rectangle->setSize(sf::Vector2f(rand() % 30, rand() % 30));
    rectangle->setPosition(rand() % window->getSize().x, rand() % window->getSize().y);
    rectangle->setFillColor(sf::Color( rand() % 256, rand() % 256, rand() % 256));

    //window->draw(*rectangle);

    delete rectangle;

  };

  virtual bool equal(Entity * other) {
    return id == other->getId();
  }

};

int Entity::next_id = 0;
