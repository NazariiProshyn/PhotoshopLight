#include "Photo.h"

namespace NSCoordinates
{
    const unsigned int coordinateX = 200;
    const unsigned int coordinateY = 125;
};



// TODO: exc img load from file
Photo::Photo(const std::string& infoPath)
{
    mainImage.loadFromFile(infoPath);
    savedImage.loadFromFile(infoPath);
    activeImage.loadFromFile(infoPath);

    texture.loadFromImage(mainImage);

    sprite.setTexture(texture);
    sprite.setPosition(NSCoordinates::coordinateX,NSCoordinates::coordinateY);
}


void Photo::setImage(bool chooseImage)
{
    if (chooseImage)
    {
        texture.loadFromImage(activeImage);
        sprite.setTexture(texture);
        sprite.setPosition(NSCoordinates::coordinateX,NSCoordinates::coordinateY);
        savedImage = activeImage;
    }
    else
    {
        texture.loadFromImage(activeImage);
        sprite.setTexture(texture);
        sprite.setPosition(NSCoordinates::coordinateX,NSCoordinates::coordinateY);
    }
}

 void Photo::setImage()
 {
    texture.loadFromImage(activeImage);
    sprite.setTexture(texture);
    sprite.setPosition(NSCoordinates::coordinateX,NSCoordinates::coordinateY);
 }

