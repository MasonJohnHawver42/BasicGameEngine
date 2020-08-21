#include "../transform.cpp"
#include <SFML/Graphics.hpp>

class Shape2D {
protected:
  Transform2D * trans;

public:
  Shape2D(double x, double y, double r) {
    trans = new Transform2D(x, y, r);
  }

  //getters

  Transform2D * getTransform() { return trans; }

  Vector<double> * getPos() { return trans->getPos(); }
  double getDir() { return trans->getDir(); }

  // setters

  void setTransform(Transform2D * t) { trans = t; }

  void setPos(Vector<double> * p) { trans->setPos(p); }
  void setPos(double x, double y) { trans->setPos(x, y); }

  void setDir(double d) { trans->setDir(d); }

  // virtuals
  virtual void draw(sf::RenderWindow * window) {}

};
