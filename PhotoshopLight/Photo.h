#pragma once

#include <SFML/Graphics.hpp>


class Photo final
{
public:

	Photo(const std::string& infoPath);
	~Photo() = default;

    void setpath(const std::string& infoPath);
    const sf::Sprite& getSprite() const {return sprite;};
    sf::Color  getPixel(size_t i, size_t j) const {return activeImage.getPixel(i,j);};
    void  setPixel(size_t i, size_t j,const sf::Color color){activeImage.setPixel(i,j,color);};

    void setImage(bool chooseImage);
    void setImage();
    void setSavedImage(){activeImage = savedImage;};

    size_t getSizeX()const {return mainImage.getSize().x; };
    size_t getSizeY()const {return mainImage.getSize().y; };

    void setColorForSprite(size_t r,size_t g,size_t b,size_t a);

    void setOriginalImage();

    bool loadImage(){return checkImage;};
    const std::string& getImagePath(){return imagePath;}
    void saveImage();
private:
    sf::Texture texture;
    sf::Sprite sprite;

    sf::Image savedImage;
    sf::Image mainImage;
    sf::Image activeImage;

    bool checkImage;
    std::string imagePath;

};

