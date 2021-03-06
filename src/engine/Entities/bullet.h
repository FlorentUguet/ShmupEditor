#ifndef CLASS_BULLET
#define CLASS_BULLET

#include <iostream>

#include <SFML/Graphics.hpp>

#include "constantes.h"
#include "entity.h"
#include "math.h"

enum Bullet_Type{
    B_PLAYER = 0,
    B_ENNEMY
};

class Bullet : public Entity
{
public:
    Bullet(float orig_x, float orig_y, float dest_x, float dest_y, double speed);
    Bullet(sf::Vector2<float> origin, sf::Vector2<float> dest, double speed);
    ~Bullet();

    void move();
    bool isOutOfBounds();

    void setOrigin(sf::Vector2<float> origin);
    void setDestination(sf::Vector2<float> dest);
    void setSpeed(double speed);

private:
    sf::Vector2<float> origin;
    sf::Vector2<float> dest;

    int distance_ratio;

    int direct_relative_travel;

    double bullet_speed;

    int bullet_type;
};

#endif // CLASS_BULLET

