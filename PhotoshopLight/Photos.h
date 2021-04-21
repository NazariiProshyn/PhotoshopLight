#pragma once

#include <SFML/Graphics.hpp>


class Photos
{
public:
	Photos();
	~Photos();

	 sf::Sprite sprite;
private:
    std::string path = "D:\\Projects\\PhotoshopL\\PhotoshopLight\\PhotoshopLight\\1.png";

     sf::Image image;
     sf::Texture texture;

    //size of window
};

