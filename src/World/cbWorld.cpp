#include "../vector.cpp"
#include "world.cpp"

class CoordinateBasedWorld : public World {
protected:
  Vector<double> * origon;
  double width;
  double height;

public:
  CoordinateBasedWorld() : World() {
    origon = new Vector<double>(0, 0);

    width = 10;
    height = 10;
  }


  //getters

  Vector<double> * getOrigon() { return origon; }

  double getHeight() { return height; }
  double getWidth() { return width; }

  //setters

  void setOrigon(double x, double y) {
    origon->setX(x);
    origon->setY(y);
  }

  void setOrigon(Vector<double> * o) { origon = o; }

  void setWidth(double w) { width = w; }
  void setHeight(double h) { height =h; }

};
