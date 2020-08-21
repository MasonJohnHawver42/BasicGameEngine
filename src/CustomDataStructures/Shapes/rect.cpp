#include "circle.cpp"

class Rect : public Shape {
protected:
  double width;
  double height;

public:
  Rect(double x, double y, double d, double w, double h) : Shape(x, y, d) {
    width = w;
    height = h;
  }

  //getters

  double getWidth() { return width; }
  double getHeight() { return height; }

  //setters

  void setWidth(double w) { width = w; }
  void setHeight(double h) { height = h; }

  void setSize(double w, double h) {setWidth(w); setHeight(h);}

  //other

  Rect * getCopy() {
    Rect * rect = new Rect(getPos()->x, getPos()->y, getDir(), width, height);
    return rect;
  }

  bool isInside(Vector<double> * point) {

    //update this for dir

    double x = point->x - getPos()->x;
    double y = point->y - getPos()->y;

    return (0 <= x && x <= width) && (0 <= y && y <= height);
  }

  virtual void draw(sf::RenderWindow * window) {
    sf::RectangleShape rect;
    rectangle.setSize(sf::Vector2f(width, height));
    rect.setPosition(getPos()->x, getPos()->y);

    window->draw(rect);
  }

  virtual void toString() {
    std::cout << "Cirlce=[";
    trans->toString();
    std::cout << ", Width: " << width << ", Height: " << height "]";
  }

};
