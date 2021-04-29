#include "Photos.h"


Photo::Photo()
{

}


void Photo::setpath(const std::string& infoPath = "1.png")
{
    path = infoPath;
    image.loadFromFile(path);
    texture.loadFromImage(image);

    sprite.setTexture(texture);
    sprite.setPosition( 0,0);
}
