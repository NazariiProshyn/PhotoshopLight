#include "Photos.h"
#include "Filtrs.h"
#include <sstream>

int main()
{
    const unsigned int wWidth = 800;
    const unsigned int wHeight = 600;

    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML Island",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

Photos photo;
    sf::Font font;
    if (!font.loadFromFile("D:\\Projects\\PhotoshopL\\PhotoshopLight\\PhotoshopLight\\sansation.ttf"))
        {
            window.close();
            return 0;
        }

        sf::Text infoText;

        infoText.setFont(font);
        infoText.setCharacterSize(32);
        infoText.setFillColor(sf::Color::White);
        infoText.setOutlineColor(sf::Color::Red);
        infoText.setOutlineThickness(2.2f);
        infoText.setPosition(5.2f, 5.1f);

        std::ostringstream containerForInfoText;


    Filtr filtr("1.png");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {filtr.dark();}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {filtr.light();}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {filtr.saturationUp();}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {filtr.saturationDown();}

        containerForInfoText.str("");
        containerForInfoText << "It's works!\n\n";

        infoText.setString(containerForInfoText.str());


        window.clear();
        window.draw(infoText);
        window.draw(filtr.getSprite());
        window.display();
    }

    return 0;
}
