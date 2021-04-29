#pragma once

#include "Photos.h"
#include <SFML/Graphics.hpp>
#include <string>

// TODO: rename class
// TODO: rename files
class Filter final
{
public:
	Filter(const std::string& pathImage);
	~Filter() = default;

    void dark();
    void light();

    void saturationUp();
    void saturationDown();

    sf::Sprite getSprite()const {return photo.sprite;}
private:
    Photo photo;
};

