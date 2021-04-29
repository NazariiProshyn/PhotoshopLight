#include "Photos.h"

// TODO: default
Photo::Photo()
{

}

// TODO: exc img load from file
// TODO: rename method
void Photo::setpath(const std::string& infoPath = "1.png")
{
    path = infoPath;
    image.loadFromFile(path);
    texture.loadFromImage(image);

    sprite.setTexture(texture);
    sprite.setPosition(0,0);

    sizeX = image.getSize().x;
    sizeY = image.getSize().y;
}
