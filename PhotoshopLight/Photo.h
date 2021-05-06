#pragma once

#include <SFML/Graphics.hpp>


class Photo final
{
public:

	Photo(const std::string& infoPath);
	~Photo() = default;

    void setpath(const std::string& infoPath);
    sf::Sprite getSprite() const {return sprite;};

    void setImage(bool chooseImage);
    void setImage();

    size_t getSizeX()const {return mainImage.getSize().x; };
    size_t getSizeY()const {return mainImage.getSize().y; };
    //Todo: private
    sf::Sprite sprite;

    sf::Image mainImage;
    sf::Image savedImage;
    sf::Image activeImage;
private:

    sf::Texture texture;

};

