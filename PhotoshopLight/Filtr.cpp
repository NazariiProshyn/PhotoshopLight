#include "Filtr.h"

namespace NSColors
{
    const size_t step = 5;
    const size_t minColorValue = 0;
    const size_t maxColorValue = 255;
};



void Filter::dark()
{
    // TODO: check bouds(межі виразу)
    if (red > NSColors::minColorValue)
    {
        red   -= NSColors::step;
        green -= NSColors::step;
        blue  -= NSColors::step;
    }

    photo.sprite.setColor(sf::Color(red, green, blue, alpha));
}

void Filter::light()
{

    if (red < NSColors::maxColorValue)
    {
        red   += NSColors::step;
        green += NSColors::step;
        blue  += NSColors::step;
    }

    photo.sprite.setColor(sf::Color(red, green, blue, alpha));
}

void Filter::saturationDown()
{

    if (alpha > NSColors::minColorValue)
    {
        alpha -= NSColors::step;
    }

    photo.sprite.setColor(sf::Color(red, green, blue, alpha));
}

void Filter::saturationUp()
{

    if (alpha < NSColors::maxColorValue)
    {
        alpha += NSColors::step;
    }

    photo.sprite.setColor(sf::Color(red, green, blue, alpha));
}

