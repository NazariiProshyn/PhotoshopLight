#include "Photos.h"


Photos::Photos()
{


    //add image to prpgramm

    image.loadFromFile(path);

    //add texture

    texture.loadFromImage(image);

    sprite.setTexture(texture);
    sprite.setPosition( 0,0);
}

Photos::~Photos()
{
}
