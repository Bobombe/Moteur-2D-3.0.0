#include <cmath>
#include <SFML/Graphics.hpp>

static float Norm(const sf::Vector2f & vec)
{
    return (sqrt(vec.x*vec.x + vec.y*vec.y));
}
static void Normalize(sf::Vector2f & vec)
{
    vec = vec/Norm(vec);
}
static float scal(const sf::Vector2f & v1, const sf::Vector2f & v2)
{
    return v1.x*v2.x + v1.y*v2.y;
}
static sf::Vector2f getRot90(const sf::Vector2f & vec)
{
    sf::Vector2f aux(vec.x, vec.y);
    float nVec = Norm(vec);
    Normalize(aux);
    float angle = atan2(aux.y, aux.x);
    angle+=3.14/2.;
    aux.x=cos(angle);
    aux.y = sin(angle);
    aux = aux*nVec;

    return aux;

}
