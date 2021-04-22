#pragma once

#include <SFML/Graphics.hpp>


class Photos
{
public:
	Photos();
	~Photos();
void setpath(std::string pathImage);
	 sf::Sprite sprite;
private:
    std::string path = "1.png";

     sf::Image image;
     sf::Texture texture;

    //size of window
};

