#pragma once

#include "Information.h"
#include "Photo.h"
#include "Filter.h"
#include "ControllerLogic.h"
#include <sstream>
#include <string>
#include <vector>
#include <thread>



class ViewController final
{
public:
	ViewController();
	~ViewController() = default;

    void refreshTextView();
    bool loadFont(){ return font.loadFromFile(fontPath);};

    void editImage(const sf::Event& event);

    const sf::Sprite& getSprite() const{return filter.getSprite();};
    sf::Text getText(size_t num) const {return infoText[num];};

    size_t getSizeOfInfoText() const {return sizeOfInfoText;}

    const std::string& getFontPath(){return fontPath;};
    const std::string& getImagePath(){return filter.getImagePath();}
    bool loadImage(){return filter.loadImage();};
    void saveImage(){filter.saveImage();};
private:

    static const size_t sizeOfInfoText = 4;
    const std::string fontPath = "font.ttf";

    std::vector<sf::Text> infoText;

    sf::Font font;

    std::string path = "1.jpg";
    Filter filter;
    ControllerLogic controllerLogic;
};
