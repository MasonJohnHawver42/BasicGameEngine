#include "vector.cpp"

class Transform2D {
private:
  Vector<double> * pos;
  double dir; // radians

public:
  Transform2D(double x, double y, double d) {
    pos = new Vector<double>(x, y);
    dir = d;
  }

  //getters

  Vector<double> * getPos() { return pos; }
  double getDir() { return dir; }

  //setters

  void setPos(Vector<double> * p) { pos = p; }
  void setPos(double x, double y) { pos->setX(x); pos->setY(y); }

  void setRot(double d) { dir = d; }

  //other

  virtual void toString() {
    std::cout << "Transform2D=[pos:(" << pos->x << ", " << pos->y << "), dir:" << dir << "]";
  }

};
