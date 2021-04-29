#pragma once

#include <SFML/Graphics.hpp>


class Photo final
{
public:
	Photo();
	~Photo() = default;

    void setpath(const std::string& infoPath);
    sf::Sprite sprite;
private:
    std::string path;

    sf::Image image;
    sf::Texture texture;
};

