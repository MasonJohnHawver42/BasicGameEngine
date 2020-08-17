#include "circle.cpp"

class Rect : public Shape {
private:
  Vector<double> * pos; // top left
  double width;
  double height;

public:
  Rect(double x, double y, double w, double h) : Shape() {
    pos = new Vector<double>(x, y);
    width = w;
    height = h;
  }

  //getters

  Vector<double> * getPos() { return pos; }
  double getWidth() { return width; }
  double getHeight() { return height; }

  //setters

  void setPos(Vector<double> * p) { pos = p; }
  void setPos(double x, double y) { pos->setX(x); pos->setY(y); }

  void setWidth(double w) { width = w; }
  void setHeight(double h) { height = h; }

  void setSize(double w, double h) {setWidth(w); setHeight(h);}

  //virts

};
