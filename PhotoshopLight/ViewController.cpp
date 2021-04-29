#include "ViewController.h"

namespace NSConstanst
{
    const std::vector<std::string> menuItems =
    {
        "Use UP and DOWN ",
        "1.",
        "2.",
        "3."
    };

    const std::vector<std::string> paths =
    {
        "1.png",
        "1.jpg"
    };

    const sf::Color    nonActiveColor   = sf::Color::Red ;
    const unsigned int nonActiveSize    = 24;
    const float        nonActiveBorder  = 1.9f;

    const float        positionX        = 5.2f;
    const float        positionY        = 5.2f;

    const sf::Color    ActiveColor      = sf::Color::Blue ;
    const unsigned int ActiveSize       = 29;
    const float        ActiveBorder     = 2.2f;

    const float        stepBetweenItems = 30.0f;

    size_t numOfFiltr = 1;
    size_t numFiltrToUse = 1;
    size_t currentPicture = 1;

};


ViewController::ViewController():filtr1{path1}
{
    infoText.resize(sizeOfInfoText);

    for(size_t i = 0; i < NSConstanst::paths.size(); ++i)
    {
        filtrs.push_back(Filtr {NSConstanst::paths[i]});
    }
}

void ViewController::customizeTextView()
{
    for(size_t i = 0; i < sizeOfInfoText; ++i )
    {
        if(i == NSConstanst::numOfFiltr)
        {

            infoText[i].setCharacterSize(NSConstanst::ActiveSize);
            infoText[i].setOutlineColor(NSConstanst::ActiveColor);
            infoText[i].setOutlineThickness(NSConstanst::ActiveBorder);
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
    {//class for filtrs (next/previous)
        if(NSConstanst::numOfFiltr == 3)
        {
                NSConstanst::numOfFiltr = 1;
        }
        else
        {
            ++NSConstanst::numOfFiltr;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if(NSConstanst::numOfFiltr == 1)
            {
                NSConstanst::numOfFiltr = 3;
            }
            else
            {
                --NSConstanst::numOfFiltr;
            }
        }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
        {
            if (NSConstanst::currentPicture == numofPictures){NSConstanst::currentPicture = 1;}
            else {++NSConstanst::currentPicture;}
        }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            switch(NSConstanst::numOfFiltr + NSConstanst::numFiltrToUse)
            {//enum
               // case 2: filtr1.dark();           break;
               // case 3: filtr1.saturationDown(); break;
                default:                         break;
            }
        }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            switch(NSConstanst::numOfFiltr + NSConstanst::numFiltrToUse)
            {
             //   case 2: filtr1.light();          break;
             //   case 3: filtr1.saturationUp();   break;
                default:                         break;
            }
        }
 }

sf::Sprite ViewController::getSprite() const
{
   // if(currentPicture == 2){return filtr2.getSprite();}
   return filtr1.getSprite();
}
