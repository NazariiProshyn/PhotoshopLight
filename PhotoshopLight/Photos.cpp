#include "Photos.h"


Photos::Photos()
{
    image.loadFromFile(path);
    texture.loadFromImage(image);

    sprite.setTexture(texture);
    sprite.setPosition( 0,0);
}

Photos::~Photos()
{
}

void Photos::setpath(std::string pathImage)
{
    path = pathImage;
    image.loadFromFile(path);
    texture.loadFromImage(image);

    sprite.setTexture(texture);
    sprite.setPosition( 0,0);
}
