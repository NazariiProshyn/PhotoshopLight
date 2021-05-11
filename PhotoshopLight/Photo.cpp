#include "Photo.h"

namespace NSCoordinates
{
    const unsigned int coordinateX = 200;
    const unsigned int coordinateY = 125;
};

namespace NSInformationForSave
{
    const std::string pathForSave = "images/";
    const std::string formatForSave = ".jpg";
    int numOfSavedImages = 0;
};


// TODO: exc img load from file
Photo::Photo(const std::string& infoPath)
{
    imagePath = infoPath;
    checkImage = mainImage.loadFromFile(imagePath);
    savedImage.loadFromFile(imagePath);
    activeImage.loadFromFile(imagePath);

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

 void Photo::setColorForSprite(size_t r,size_t g,size_t b,size_t a)
 {
     sprite.setColor(sf::Color(r,g,b,a));
 }


 void Photo::setOriginalImage()
 {
    texture.loadFromImage(mainImage);
    sprite.setTexture(texture);
    sprite.setPosition(NSCoordinates::coordinateX,NSCoordinates::coordinateY);
    savedImage  = mainImage;
    activeImage = mainImage;
 }

 void Photo::saveImage()
 {
     std::string imagePath = NSInformationForSave::pathForSave +
                                std::to_string(NSInformationForSave::numOfSavedImages) +
                                    NSInformationForSave::formatForSave;
    activeImage.saveToFile(imagePath);
    ++NSInformationForSave::numOfSavedImages;
 }
