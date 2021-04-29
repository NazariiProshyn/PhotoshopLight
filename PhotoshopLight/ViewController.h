#pragma once

#include "Information.h"
#include "Photos.h"
#include "Filtrs.h"
#include "ControllerLogic.h"
#include <sstream>
#include <string>
#include <vector>


class ViewController final
{
public:
	ViewController();
	~ViewController() = default;

    void customizeTextView();
    // TODO: accept fontpath as a param
    bool loadFont(){ return font.loadFromFile("sansation.ttf");};

    void editImage(const sf::Event& event);
    // TODO: return const reference
    sf::Sprite getSprite() const;
    sf::Text getText(size_t num) const {return infoText[num];};
    // TODO: rename function
    size_t getsizeOfInfoText() const {return sizeOfInfoText;}
private:

    static const size_t sizeOfInfoText = 4;


    std::vector<sf::Text> infoText;

    sf::Font font;

    std::string path1 = "1.png";
    //TODO: get rid of filtr1. Use filtrs
    Filter filtr1;
    ControllerLogic controllerLogic;
    //TODO: rename filtrs
    std::vector<Filter> filtrs;
};
