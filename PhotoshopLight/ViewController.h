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
    bool loadFont(){ return font.loadFromFile("sansation.ttf");};

    void editImage(const sf::Event& event);

    sf::Sprite getSprite() const;
    sf::Text getText(size_t num) const {return infoText[num];};

    size_t getsizeOfInfoText() const {return sizeOfInfoText;}
private:

    static const size_t sizeOfInfoText = 4;


    std::vector<sf::Text> infoText;
    std::vector<std::ostringstream> containerForInfoText;

    sf::Font font;

    std::string path1 = "1.png";
    Filtr filtr1;
    ControllerLogic controllerLogic;
    std::vector<Filtr> filtrs;
};
