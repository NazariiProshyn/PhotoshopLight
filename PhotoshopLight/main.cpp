#include "Photos.h"
#include "Filtrs.h"
#include "ViewController.h"


int main()
{
    const unsigned int wWidth = 800;
    const unsigned int wHeight = 600;

    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Photoshop Light",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    ViewController view;

    if (!view.checkFont())
        {
            window.close();
            return 0;
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


            view.imageEvents(event);

        }

		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {}
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {filtr.light();}

        view.textView();
        window.clear();
        for(size_t i = 0; i < view.getsizeOfInfoText(); i++)
            {
                window.draw(view.getText(i));
            }
        window.draw(view.getSprite());
        window.display();
    }

    return 0;
}
