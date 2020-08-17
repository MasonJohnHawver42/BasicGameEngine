#include "../Entity/MetaEntities/worldEntity.cpp"

void play() {

  ParticleWorld * world = new TestWorld();

  double fps = 240.0;

  sf::Clock * clock = new sf::Clock();

  world->updateFrame();

  while (world->continueGame()){

    if(clock->getElapsedTime().asSeconds() > 1. / fps) {
      world->updateFrame();
      clock->restart();
    }

    world->update();

  }

  return;
}
