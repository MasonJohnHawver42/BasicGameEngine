#include "../World/basicWorld.cpp"

class BasicWorldViewer : public CoordinateBasedViewer {
protected:
  BasicWorld * world;

public:
  BasicWorldViewer(BasicWorld * wrld, sf::RenderWindow * win) : CoordinateBasedViewer(win) { world = wrld; }
  BasicWorldViewer(BasicWorld * wrld) : CoordinateBasedViewer() { world = wrld; }

  BasicWorldViewer() : CoordinateBasedViewer() {}

  //getters

  BasicWorld * getWorld() { return world; }

  //setters

  void setWorld(BasicWorld * w) { world = w; }

  //other

  virtual void updateWindow() {
     world->getEntityGroup()->draw(window);
     
   }
};
