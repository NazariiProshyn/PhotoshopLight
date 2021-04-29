#pragma once

#include <SFML/Graphics.hpp>

// TODO: rename files
class Photo final
{
public:
    // TODO: sens def constr
	Photo();
	~Photo() = default;
    // TODO: no def param
    void setpath(const std::string& infoPath);
    // TODO: private
    sf::Sprite sprite;
private:
    std::string path;

    sf::Image image;
    sf::Texture texture;
    // TODO: default values
    size_t sizeX;
    size_t sizeY;
};

