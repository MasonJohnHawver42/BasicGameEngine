#include "entity.cpp"

class Entity2D : Entity {
protected:
  World2D * world;
  Transform2D * trans;

public:
  Entity2D() : Entity() {
    world = nullptr;
    std::cout << "World NOT Defined! why?" << '\n';

    trans = new Transform2D(0, 0, 0);
  }

  Entity2D(World2D * wrld) : Entity() {
    world = wrld;

    trans = new Transform2D(0, 0, 0);
  }

  // getters

  World2D * getWorld() { return world; }

  //setters

  virtual void setWorld(World2D * w) { world = w; }
};
