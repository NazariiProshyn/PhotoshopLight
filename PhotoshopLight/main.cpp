#include "Photo.h"
#include "Filtr.h"
#include "ViewController.h"

static int run()
{
    const unsigned int wWidth = 800;
    const unsigned int wHeight = 600;

    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Photoship Light",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    ViewController view;
    // TODO: use exc and throw when font didn't load
    if (!view.loadFont())
    {
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
