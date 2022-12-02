#include <SFML/Graphics.hpp>
#include <iostream>

const int width = 1200, height = 400;
const int l = 300;
int blocks[l] = {};
int blocksCheck[l] = {};
int temp = 0, part = 1, j = 0, lim = l - 1, c = 0, x = 1;
int len = sizeof(blocksCheck) / sizeof(int);

bool isEqual(int a[], int b[]) {
    for(int i = 0; i < len; i++) {
        if(a[i] != b[i])
            return false;
    }
    return true;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "ATTEMPT");
    for(int i = 0; i < l; i++) {
        blocks[i] = rand() % 400 + 1;
        blocksCheck[i] = blocks[i];
    }

    std::sort(blocksCheck, blocksCheck + len);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(part == 2) {
            if(blocks[j + 1] < blocks[j]) {
                temp = blocks[j];
                blocks[j] = blocks[j + 1];
                blocks[j + 1] = temp;
            }
        }
        window.clear(sf::Color::Black);
        if(!isEqual(blocks, blocksCheck)) {
            for(int i = 0; i < l; i++) {
                sf::RectangleShape bar(sf::Vector2f((float) width / (float) l, (float) blocks[i]));
                bar.setPosition((float) i * (float) width / (float) l, (float) (height - blocks[i]));
                bar.setFillColor(sf::Color::White);
                window.draw(bar);
            }
        } else {
            for(int i = 0; i < l; i++) {
                if(i < x) {
                    sf::RectangleShape bar(sf::Vector2f((float) width / (float) l, (float) blocks[i]));
                    bar.setPosition((float) i * (float) width / (float) l, (float) (height - blocks[i]));
                    bar.setFillColor(sf::Color::Green);
                    window.draw(bar);
                } else {
                    sf::RectangleShape bar(sf::Vector2f((float) width / (float) l, (float) blocks[i]));
                    bar.setPosition((float) i * (float) width / (float) l, (float) (height - blocks[i]));
                    bar.setFillColor(sf::Color::White);
                    window.draw(bar);
                }
            }
            if(x <= 800) {
                x++;
            }
        }

        window.display();
        j++;
        part = 2;
        if(j >= lim){
            j = 0;
            c++;
            lim--;
        }
    }

    return 0;
}