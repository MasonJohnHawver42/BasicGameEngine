#include"../Entity/EntityGroup/BasicEntityGroup.cpp"
#include "cbWorld.cpp"

class BasicWorld : public CoordinateBasedWorld {
protected:
  EntityGroup * group;

  sf::Clock * masterClock;

public:
  BasicWorld(EntityGroup * g) : CoordinateBasedWorld() {
      group = g;

      masterClock = new sf::Clock();
  }

  BasicWorld() : CoordinateBasedWorld() {
    group = new BasicEntityGroup();
    Entity * test = new Entity();

    masterClock = new sf::Clock();
  }

  // getters

  EntityGroup * getEntityGroup() { return group; }

  double getElapsedTime() { return masterClock->getElapsedTime().asSeconds(); }

  // setters

  void setEntityGroup(EntityGroup * eg) { group = eg; }

  //other

  virtual void start() { group->start(); }
  virtual void update() { group->update(); masterClock->restart();}

};
