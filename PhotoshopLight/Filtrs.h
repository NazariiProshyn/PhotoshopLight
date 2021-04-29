#pragma once

#include "Photos.h"
#include <SFML/Graphics.hpp>
#include <string>


class Filtr final
{
public:
	Filtr(const std::string& pathImage);
	~Filtr() = default;

    void dark();
    void light();

    void saturationUp();
    void saturationDown();

    const sf::Sprite getSprite()const {return photo.sprite;}
private:
    Photo photo;
};

