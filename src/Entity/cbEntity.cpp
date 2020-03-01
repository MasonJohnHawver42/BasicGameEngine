#include"../Viewer/worldViewer.cpp"

class CoordinateBasedEntity : public Entity {
protected:
  Vector<double> * pos;

public:

  CoordinateBasedEntity() : Entity() {
    pos = new Vector<double>(0, 0);
  }

  //getters

  Vector<double> * getPos() { return pos; }

  //setters

  void setPos(Vector<double> * p) { pos = p; }
  void setPos(double x, double y) {
    pos->setX(x);
    pos->setY(y);
  }

};
