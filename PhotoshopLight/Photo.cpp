#include "Photo.h"

// TODO: exc img load from file
Photo::Photo(const std::string& infoPath)
{
    path = infoPath;
    image.loadFromFile(path);
    texture.loadFromImage(image);

    sprite.setTexture(texture);
    sprite.setPosition(0,0);

    sizeX = image.getSize().x;
    sizeY = image.getSize().y;
}
