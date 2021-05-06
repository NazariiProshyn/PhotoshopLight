#include "ViewController.h"
namespace NSConstanst
{
    const std::vector<std::string> menuItems =
    {
        "Use \"UP\" and \"DOWN\".",
        "1.CONTRAST",
        "2.BRIGHTNESS",
        "3.TRANSPARENCY"
    };

    const std::vector<std::string> paths =
    {
        "1.png",
        "1.jpg"
    };

    const sf::Color    nonActiveColor   = sf::Color::Red;
    const unsigned int nonActiveSize    = 24;
    const float        nonActiveBorder  = 1.9f;

    const float        positionX        = 5.2f;
    const float        positionY        = 5.2f;

    const sf::Color    activeColor      = sf::Color::Blue;
    const unsigned int activeSize       = 29;
    const float        activeBorder     = 2.2f;

    const float        stepBetweenItems = 30.0f;

};

enum class EFiltrSelection
{
    CONTRAST = 1,
    BRIGHTNESS = 2,
    TRANSPARENCY   = 3
};


ViewController::ViewController():filter{path}
{
    infoText.resize(sizeOfInfoText);
}

void ViewController::refreshTextView()
{
    for (size_t i = 0; i < sizeOfInfoText; ++i )
    {
        if (i == controllerLogic.getcurrentFiltr())
        {

            infoText[i].setCharacterSize(NSConstanst::activeSize);
            infoText[i].setOutlineColor(NSConstanst::activeColor);
            infoText[i].setOutlineThickness(NSConstanst::activeBorder);
        }
        else
        {
            infoText[i].setCharacterSize(NSConstanst::nonActiveSize);
            infoText[i].setOutlineColor(NSConstanst::nonActiveColor);
            infoText[i].setOutlineThickness(NSConstanst::nonActiveBorder);
        }
        infoText[i].setFont(font);
        infoText[i].setPosition(NSConstanst::positionX,
                                NSConstanst::positionY + NSConstanst::stepBetweenItems * i);
        infoText[i].setString(NSConstanst::menuItems.at(i));
    }
}


 void ViewController::editImage(const sf::Event& event)
 {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        controllerLogic.increaseFiltr();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        controllerLogic.reduceFiltr();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
    {
        controllerLogic.increasePicture();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        switch (controllerLogic.getcurrentFiltr())
        {
            case static_cast<int>(EFiltrSelection::CONTRAST):
                 filter.contrastDown();
                 break;
            case static_cast<int>(EFiltrSelection::BRIGHTNESS):
                 filter.dark();
                 break;
            case static_cast<int>(EFiltrSelection::TRANSPARENCY):
                 filter.transparencyDown();
                 break;

            default:
                 break;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        switch (controllerLogic.getcurrentFiltr())
        {
            case static_cast<int>(EFiltrSelection::CONTRAST):
                 filter.contrastUp();
                 break;
            case static_cast<int>(EFiltrSelection::TRANSPARENCY):
                 filter.transparencyUp();
                 break;
            default:
                 break;
        }
    }
 }
