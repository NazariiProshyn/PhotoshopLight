#include "Filtrs.h"

namespace NSColors
{
    size_t red   = 255;
    size_t green = 255;
    size_t blue  = 255;
    size_t alpha = 255;
    size_t step  = 5;
    const size_t minColorValue = 0;
    const size_t maxColorValue = 255;
};


Filtr::Filtr(const std::string& pathImage)
{
    photo.setpath(pathImage);
}



void Filtr::dark()
{

    if( NSColors::red > NSColors::minColorValue)
    {
        NSColors::red   = NSColors::red   - NSColors::step;
        NSColors::green = NSColors::green - NSColors::step;
        NSColors::blue  = NSColors::blue  - NSColors::step;
    }

    photo.sprite.setColor(sf::Color(NSColors::red, NSColors::green, NSColors::blue, NSColors::alpha));
}

void Filtr::light()
{

    if( NSColors::red < NSColors::maxColorValue)
    {
        NSColors::red   = NSColors::red   + NSColors::step;
        NSColors::green = NSColors::green + NSColors::step;
        NSColors::blue  = NSColors::blue  + NSColors::step;
    }

    photo.sprite.setColor(sf::Color(NSColors::red, NSColors::green, NSColors::blue, NSColors::alpha));
}

void Filtr::saturationDown()
{

    if( NSColors::alpha > NSColors::minColorValue)
    {
        NSColors::alpha = NSColors::alpha - NSColors::step;
    }

    photo.sprite.setColor(sf::Color(NSColors::red, NSColors::green, NSColors::blue, NSColors::alpha));
}

void Filtr::saturationUp()
{

    if( NSColors::alpha < NSColors::maxColorValue)
    {
        NSColors::alpha = NSColors::alpha + NSColors::step;
    }

    photo.sprite.setColor(sf::Color(NSColors::red, NSColors::green, NSColors::blue, NSColors::alpha));
}

