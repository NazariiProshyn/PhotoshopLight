#include "Filtr.h"

namespace NSColors
{
    const size_t step = 5;
    const size_t minColorValue = 0;
    const size_t maxColorValue = 255;
};



void Filter::dark()
{
    for (size_t i = 0; i < photo.getSizeX(); ++i)
    {
        for (size_t j = 0; j < photo.getSizeY(); ++j)
        {

            color = photo.activeImage.getPixel(i,j);
                if (color.r > NSColors::step &&
                    color.g > NSColors::step &&
                    color.b > NSColors::step)
                {
                    color.r -= NSColors::step;
                    color.g -= NSColors::step;
                    color.b -= NSColors::step;

                    photo.activeImage.setPixel(i,j,color);
                }
                else
                {
                    checkBounds = false;
                    if (color.r > NSColors::step)
                    {
                        color.r -= NSColors::step;
                    }
                    if (color.g > NSColors::step)
                    {
                        color.g -= NSColors::step;
                    }
                    if (color.b > NSColors::step)
                    {
                        color.b -= NSColors::step;
                    }

                    photo.activeImage.setPixel(i,j,color);
                }
        }
    }

    photo.setImage(checkBounds);

}

void Filter::light()
{

}

void Filter::transparencyDown()
{

    if (alpha > NSColors::minColorValue)
    {
        alpha -= NSColors::step;
    }

    photo.sprite.setColor(sf::Color(red, green, blue, alpha));
}

void Filter::transparencyUp()
{
    //maxcolorv
    if (alpha < NSColors::maxColorValue)
    {
        alpha += NSColors::step;
    }

    photo.sprite.setColor(sf::Color(red, green, blue, alpha));
}


void Filter::contrastUp()
{
    size_t lightBound = NSColors::maxColorValue - NSColors::step;

    for (size_t i = 0; i < photo.getSizeX(); ++i)
    {
        for (size_t j = 0; j < photo.getSizeY(); ++j)
        {
            color = photo.activeImage.getPixel(i,j);
            if (color.r < NSColors::maxColorValue &&
                color.b < NSColors::maxColorValue &&
                color.g < NSColors::maxColorValue)
            {
                if (color.r < lightBound &&
                    color.g < lightBound &&
                    color.b < lightBound)
                {
                    color.r += NSColors::step;
                    color.g += NSColors::step;
                    color.b += NSColors::step;

                    photo.activeImage.setPixel(i,j,color);
                }

            }

        }
    }

    photo.setImage();
}

void Filter::contrastDown()
{
        // TODO: check bouds(межі виразу)

    for (size_t i = 0; i < photo.getSizeX(); ++i)
    {
        for (size_t j = 0; j < photo.getSizeY(); ++j)
        {
            color = photo.activeImage.getPixel(i,j);
            if (color.r > NSColors::minColorValue &&
                color.b > NSColors::minColorValue &&
                color.g > NSColors::minColorValue)
            {
                if (color.r > NSColors::step &&
                    color.g > NSColors::step &&
                    color.b > NSColors::step)
                {
                    color.r -= NSColors::step;
                    color.g -= NSColors::step;
                    color.b -= NSColors::step;

                    photo.activeImage.setPixel(i,j,color);
                }

            }

        }
    }

    photo.setImage();
}
