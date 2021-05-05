#pragma once

#include "Photo.h"
#include <SFML/Graphics.hpp>
#include <string>


class Filter final
{
public:
	Filter(const std::string& pathImage):
    photo{pathImage}{};
	~Filter() = default;

    void dark();
    void light();

    void saturationUp();
    void saturationDown();

    sf::Sprite getSprite()const {return photo.sprite;}
private:
    Photo photo;
    size_t red   = 255;
    size_t green = 255;
    size_t blue  = 255;
    size_t alpha = 255;
};

