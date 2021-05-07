#include "Filtr.h"

namespace NSColors
{
    const size_t step = 5;
    const size_t minColorValue = 0;
    const size_t maxColorValue = 255;
};



void Filter::dark()
{
    if (!checkBoundsLight)
    {
        checkBoundsLight = true;
        photo.setSavedImage();
    }

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
            }
            else
            {
                checkBoundsDark = false;
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
            }
            photo.activeImage.setPixel(i,j,color);
        }
    }

    photo.setImage(checkBoundsDark);

}

void Filter::light()
{
     if (!checkBoundsDark)
    {
        checkBoundsDark  = true;
        photo.setSavedImage();
    }

    size_t lightBound = NSColors::maxColorValue - NSColors::step;

    for (size_t i = 0; i < photo.getSizeX(); ++i)
    {
        for (size_t j = 0; j < photo.getSizeY(); ++j)
        {
            color = photo.activeImage.getPixel(i,j);

            if (color.r < lightBound &&
                color.g < lightBound &&
                color.b < lightBound)
            {
                color.r += NSColors::step;
                color.g += NSColors::step;
                color.b += NSColors::step;
            }
            else
            {
                checkBoundsLight = false;
                if (color.r < lightBound)
                {
                    color.r += NSColors::step;
                }
                if (color.g < lightBound)
                {
                    color.g += NSColors::step;
                }
                if (color.b < lightBound)
                {
                    color.b += NSColors::step;
                }
            }
            photo.activeImage.setPixel(i,j,color);
        }
    }

    photo.setImage(checkBoundsLight);
}

void Filter::transparencyDown()
{
    if (alpha > NSColors::minColorValue)
    {
        alpha -= NSColors::step;
    }

    photo.setColorForSprite(
                 NSColors::maxColorValue, NSColors::maxColorValue, NSColors::maxColorValue, alpha);
}

void Filter::transparencyUp()
{
    if (alpha < NSColors::maxColorValue)
    {
        alpha += NSColors::step;
    }

    photo.setColorForSprite(
                 NSColors::maxColorValue, NSColors::maxColorValue, NSColors::maxColorValue, alpha);
}


void Filter::contrastUp()
{
    if (!checkBoundsLight || !checkBoundsDark)
    {
        checkBoundsLight = true;
        checkBoundsDark  = true;
        photo.setSavedImage();
    }

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
    if (!checkBoundsLight || !checkBoundsDark)
    {
        checkBoundsLight = true;
        checkBoundsDark  = true;
        photo.setSavedImage();
    }

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
