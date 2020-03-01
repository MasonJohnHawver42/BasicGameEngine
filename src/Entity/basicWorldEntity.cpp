#include"cbEntity.cpp"

class BasicWorldEntity : public CoordinateBasedEntity {
protected:
  BasicWorld * world;

public:

  BasicWorldEntity(BasicWorld * wrld) : CoordinateBasedEntity() {
    world = wrld;
    world->getEntityGroup()->addEntity(this);
  }

  BasicWorldEntity() : CoordinateBasedEntity() {
    world = nullptr;
  }

  //getters

  BasicWorld * getWorld() { return world; }

  //setters

  void setWorld(BasicWorld * w) {
    world = w;
    if(world) {w->getEntityGroup()->addEntity(this);}
  }

  //virtuals

  virtual void update() {

    double time = world->getElapsedTime();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { pos->setY(pos->getY() + ( 10 * world->getElapsedTime())); }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { pos->setY(pos->getY() - ( 10 * world->getElapsedTime())); }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { pos->setX(pos->getX() + ( 10 * world->getElapsedTime())); }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { pos->setX(pos->getX() - ( 10 * world->getElapsedTime())); }

    std::cout << world->getElapsedTime() - time << '\n';
  }

  virtual void draw(sf::RenderWindow * window) {

    CoordinateBasedViewer * cam = world->getViewer();

    Vector<double> * shiftedPos = new Vector<double>(pos->getX(), pos->getY());
    shiftedPos->sub(*cam->getPos());

    Vector<double> * transform = new Vector<double>(window->getSize().x / cam->getWidth(), window->getSize().y / cam->getHeight());

    shiftedPos->mult(*transform);

    Vector<double> * shift = new Vector<double>(window->getSize().x, window->getSize().y);
    shift->div(2);
    shiftedPos->add(*shift);

    shiftedPos->setY(window->getSize().y - shiftedPos->getY());

    sf::RectangleShape * rectangle = new sf::RectangleShape();
    rectangle->setSize(sf::Vector2f(world->getWidth() * transform->getX(), world->getHeight() * transform->getY()));
    rectangle->setPosition(shiftedPos->getX(), shiftedPos->getY());
    //rectangle->setFillColor(sf::Color( rand() % 256, rand() % 256, rand() % 256));

    window->draw(*rectangle);

    delete rectangle, shift, shiftedPos, transform;

  };

};
