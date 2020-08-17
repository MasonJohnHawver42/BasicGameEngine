#include "shape.cpp"

class Circle : public Shape {
private:
  Vector<double> * pos;
  double radius;

public:
  Circle(double x, double y, double r) : Shape() {
    pos = new Vector<double>(x, y);
    raduis = r;
  }

  //getters

  Vector<double> * getPos() { return pos; }
  double getRadius() { return radius; }

  //setters

  void setPos(Vector<double> * p) { pos = p; }
  void setPos(double x, double y) { pos->setX(x); pos->setY(y); }

  void setRaduis(double r) { radius = r; }

  //virts

  virtual void draw(sf::RenderWindow * window) {
    sf::CircleShape circle;
    circle.setRadius(radius);
    circle.setPosition(pos->getX(), pos->getY());

    window->draw(circle);
  }
};
