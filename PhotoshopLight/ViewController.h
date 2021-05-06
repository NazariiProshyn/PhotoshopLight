#pragma once

#include "Information.h"
#include "Photo.h"
#include "Filtr.h"
#include "ControllerLogic.h"
#include <sstream>
#include <string>
#include <vector>


class ViewController final
{
public:
	ViewController();
	~ViewController() = default;

    void refreshTextView();
    bool loadFont(){ return font.loadFromFile(fontpath);};

    void editImage(const sf::Event& event);
    // TODO: return const reference
    sf::Sprite getSprite() const{return filter.getSprite();};
    sf::Text getText(size_t num) const {return infoText[num];};

    size_t getSizeOfInfoText() const {return sizeOfInfoText;}
private:

    static const size_t sizeOfInfoText = 4;
    const std::string fontpath = "font.ttf";

    std::vector<sf::Text> infoText;

    sf::Font font;

    std::string path = "1.jpg";
    Filter filter;
    ControllerLogic controllerLogic;

};
