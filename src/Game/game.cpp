#include "../Entity/basicWorldEntity.cpp"

void play() {

  BasicWorld * world = new BasicWorld();

  sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode(600, 600), "Demo Game");

  sf::Event event;

  BasicWorldViewer * camera = new BasicWorldViewer(world, window);

  world->setViewer(camera);

  BasicWorldEntity * test = new BasicWorldEntity(world);

  while (window->isOpen()){

    while (window->pollEvent(event)){
      if (event.type == sf::Event::EventType::Closed)
        window->close();
    }

    window->clear();

    camera->updateWindow();

    window->display();

    world->update();
  }

  return;
}
