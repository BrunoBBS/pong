#include <SFML/Graphics.hpp>

using namespace sf;

class GameObject
{
  public:
    Vector2f pos, vel, acc;
    Shape *shape;

  public:
    GameObject(Vector2f pos,
               Shape *shape,
               Vector2f vel = Vector2f(0, 0),
               Vector2f acc = Vector2f(0, 0))
        : pos(pos), vel(vel), acc(acc), shape(shape)
    {
    }

    void update(sf::Time dt)
    {
        if (pos.y > 600 - 5 && vel.y > 0)
        {
            vel.y = -vel.y * .7;
            pos.y = 600 - 5;
        }

        if ((pos.x > 1000 - 5 && vel.x > 0) ||
            (pos.x < 5 && vel.x < 0))
            vel.x = -vel.x * .7;
        vel += acc * dt.asSeconds();
        pos += vel * dt.asSeconds();
    }

    void draw(RenderWindow &window)
    {
        shape->setPosition(pos);
        window.draw(*shape);
    }
};

class Ball : public GameObject
{
  public:
    Ball(double radius,
         Vector2f pos,
         Vector2f vel = Vector2f(0, 0),
         Vector2f acc = Vector2f(0, 0))
        : GameObject(pos, new CircleShape(radius), vel, acc)
    {
        shape->setFillColor(sf::Color::White);
        shape->setOrigin(radius, radius);
    }
};

int main()
{
    sf::ContextSettings context;
    context.antialiasingLevel = 4;

    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!", sf::Style::Close, context);
    Ball ball(5, Vector2f(50, 0), Vector2f(200, 0), Vector2f(0, 980));
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        ball.update(dt);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        ball.draw(window);
        window.display();
    }

    return 0;
}
