#pragma once

#include <SFML/Graphics.hpp>


class Photo final
{
public:

	Photo(const std::string& infoPath);
	~Photo() = default;

    void setpath(const std::string& infoPath);
    // TODO: private
    sf::Sprite sprite;
private:
    std::string path;

    sf::Image image;
    sf::Texture texture;

    size_t sizeX = 0;
    size_t sizeY = 0;
};

