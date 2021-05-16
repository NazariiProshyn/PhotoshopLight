#include "ViewController.h"
#include <iostream>
#include "Exception.h"


void checkFontAndImage(bool fontStatus, bool imageStatus, std::string fontPath, std::string imagePath);

static int run()
{
    const unsigned int wWidth = 1300;
    const unsigned int wHeight = 900;

    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Photoship Light",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    ViewController view;

    try
    {
        checkFontAndImage(view.loadFont(),view.loadImage(),view.getFontPath(),view.getImagePath());
    }
    catch(PhotoshipException &ex)
    {
       std::cout << ex.getErrorMsg();
        window.close();
        return 1;
    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed ||sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                 view.saveImage();
            }

            view.editImage(event);

        }

        view.refreshTextView();
        window.clear();
        for (size_t i = 0; i < view.getSizeOfInfoText(); i++)
        {
            window.draw(view.getText(i));
        }
        window.draw(view.getSprite());
        window.display();
    }

    return 0;
}

int main()
{
    return run();
}

void checkFontAndImage(bool fontStatus, bool imageStatus, std::string fontPath,  std::string imagePath)
{
    if (!fontStatus)
    {
        throw PhotoshipException(fontPath);
    }

    if (!imageStatus)
    {
        throw PhotoshipException(imagePath);
    }
}
