#include "shape.cpp"

class Circle : public Shape {
protected:
  double radius;

public:
  Circle(double x, double y, double d, double r) : Shape(x, y, d) {
    pos = new Vector<double>(x, y);
    raduis = r;
  }

  //getters

  double getRadius() { return radius; }

  //setters

  void setRaduis(double r) { radius = r; }

  //virts

  virtual Circle * getCopy() {
    Circle * c = new Circle(getPos()->x, getPos()->y, getDir(), radius);
    return c;
  }

  virtual bool is isInside(Vector<double> * point) {
    dis = point->getDis(*getPos());
    return dis < radius;
  }

  virtual void draw(sf::RenderWindow * window) {
    sf::CircleShape circle;
    circle.setRadius(radius);
    circle.setPosition(getPos()->x, getPos()->y);

    window->draw(circle);
  }
};
