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

    void contrastUp();
    void contrastDown();

    void transparencyUp();
    void transparencyDown();

    const sf::Sprite& getSprite()const {return photo.getSprite();}
private:

    Photo photo;
    sf::Color color{0,0,0,0};
    bool   checkBoundsLight = true;
    bool   checkBoundsDark  = true;
    size_t alpha            = 255;
};

