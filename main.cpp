//camera zoom mode
#include<iostream>
#include<SFML\graphics.hpp>
#include<fstream>
#include "game.cpp"

using namespace std;
using namespace sf;

const int CheckPeriodms=15;
const int RefreshTimeMaxms=1;
const int Time_BufsPerInput=10;
const float ProcessTimeMaxms=CheckPeriodms-RefreshTimeMaxms;//+Time_BufsPerInput;
const int max_toBdrawn=20;

const int winLen=1920;
const int winWid=1080;
const float fieldScale=winWid/3*.7;
const int deltaTime=17;

sf::Vector2i FieldCenter(winLen/2,winWid/2);

//Drawable toBdrawn[];
enum formation {attack,defense,hold};

//int gameEventHandle(Event event);

class TeamSelect
{
private:
public:
    static int teamselect()
    {
        sf::RenderWindow window1(sf::VideoMode(1920, 1080), "Foo2y TeamSelection", sf::Style::Default);
        sf::Texture background1;
        sf::Sprite backgroundImage1;
        if (!background1.loadFromFile("TeamSelect.jpg"))
            std::cout << "teamselect photo not found";
        backgroundImage1.setTexture(background1);
        sf::RectangleShape rectArr1(sf::Vector2f(50, 57.735));
        rectArr1.setPosition(sf::Vector2f(400, 988.132));
        rectArr1.setFillColor(sf::Color::Transparent);
        sf::RectangleShape rectArr2(sf::Vector2f(50, 57.735));
        rectArr2.setPosition(sf::Vector2f(550,988.132));
        rectArr2.setFillColor(sf::Color::Transparent);
        sf::RectangleShape rectArr3(sf::Vector2f(50, 57.735));
        rectArr3.setPosition(sf::Vector2f(1320,988.132));
        rectArr3.setFillColor(sf::Color::Transparent);
        sf::RectangleShape rectArr4(sf::Vector2f(50, 57.735));
        rectArr4.setPosition(sf::Vector2f(1470, 988.132));
        rectArr4.setFillColor(sf::Color::Transparent);
        int count1 = 0;
        int count2 = 0;
        while (window1.isOpen())
        {
            sf::Event event;
            while (window1.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window1.close();
                }
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        if (rectArr1.getGlobalBounds().contains(window1.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                        {
                            if (count1 == 0)
                                count1 = 2;
                            else
                                count1-=1;
                        }
                        if (rectArr2.getGlobalBounds().contains(window1.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                        {
                            if (count1 == 2)
                                count1 = 0;
                            else
                                count1+=1;
                        }
                        if (rectArr3.getGlobalBounds().contains(window1.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                        {
                            if (count2 == 0)
                                count2 = 2;
                            else
                                count2 -= 1;
                        }
                        if (rectArr4.getGlobalBounds().contains(window1.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                        {
                            if (count2 == 2)
                                count2 = 0;
                            else
                                count2 += 1;
                        }
                    }

                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    return 0;
                }
                ;

            }
            window1.clear();
            window1.draw(backgroundImage1);
            window1.draw(rectArr1);
            window1.draw(rectArr2);
            window1.draw(rectArr3);
            window1.draw(rectArr4);
            if (count1 == 0)
            {
                sf::Texture team0;
                sf::Sprite lolpool;
                if (!team0.loadFromFile("team0.jpg"))
                    std::cout << "Error" << std::endl;
                lolpool.setPosition(sf::Vector2f(200, 220));
                lolpool.setTexture(team0);
                window1.draw(lolpool);
                sf::Texture formation0;
                sf::Sprite form0;
                if (!formation0.loadFromFile("formation0.jpg"))
                    std::cout << "Error" << std::endl;
                form0.setPosition(sf::Vector2f(200, 348));
                form0.setTexture(formation0);
                window1.draw(form0);
            }
            if (count1 == 1)
            {
                sf::Texture team1;
                sf::Sprite banterlona;
                if (!team1.loadFromFile("team1.jpg"))
                    std::cout << "Error" << std::endl;
                banterlona.setPosition(sf::Vector2f(200, 220));
                banterlona.setTexture(team1);
                window1.draw(banterlona);
                sf::Texture formation1;
                sf::Sprite form1;
                if (!formation1.loadFromFile("formation1.jpg"))
                    std::cout << "Error" << std::endl;
                form1.setPosition(sf::Vector2f(200, 348));
                form1.setTexture(formation1);
                window1.draw(form1);
            }
            if (count1 == 2)
            {
                sf::Texture team2;
                sf::Sprite chewmentos;
                if (!team2.loadFromFile("team2.jpg"))
                    std::cout << "Error" << std::endl;
                chewmentos.setPosition(sf::Vector2f(200, 220));
                chewmentos.setTexture(team2);
                window1.draw(chewmentos);
                sf::Texture formation2;
                sf::Sprite form2;
                if (!formation2.loadFromFile("formation2.jpg"))
                    std::cout << "Error" << std::endl;
                form2.setPosition(sf::Vector2f(200, 348));
                form2.setTexture(formation2);
                window1.draw(form2);
            }
            if (count2 == 0)
            {
                sf::Texture team0;
                sf::Sprite lolpool;
                if (!team0.loadFromFile("team0.jpg"))
                    std::cout << "Error" << std::endl;
                lolpool.setPosition(sf::Vector2f(1121, 220));
                lolpool.setTexture(team0);
                window1.draw(lolpool);
                sf::Texture formation0;
                sf::Sprite form0;
                if (!formation0.loadFromFile("formation0.jpg"))
                    std::cout << "Error" << std::endl;
                form0.setPosition(sf::Vector2f(1120, 348));
                form0.setTexture(formation0);
                window1.draw(form0);
            }
            if (count2 == 1)
            {
                sf::Texture team1;
                sf::Sprite banterlona;
                if (!team1.loadFromFile("team1.jpg"))
                    std::cout << "Error" << std::endl;
                std::cout << "no error" << std::endl;
                banterlona.setPosition(sf::Vector2f(1121, 220));
                banterlona.setTexture(team1);
                window1.draw(banterlona);
                sf::Texture formation1;
                sf::Sprite form1;
                if (!formation1.loadFromFile("formation1.jpg"))
                    std::cout << "Error" << std::endl;
                std::cout << "no error" << std::endl;
                form1.setPosition(sf::Vector2f(1120, 348));
                form1.setTexture(formation1);
                window1.draw(form1);
            }
            if (count2 == 2)
            {
                sf::Texture team2;
                sf::Sprite chewmentos;
                if (!team2.loadFromFile("team2.jpg"))
                    std::cout << "Error" << std::endl;
                std::cout << "no error" << std::endl;
                chewmentos.setPosition(sf::Vector2f(1121, 220));
                chewmentos.setTexture(team2);
                window1.draw(chewmentos);
                sf::Texture formation2;
                sf::Sprite form2;
                if (!formation2.loadFromFile("formation2.jpg"))
                    std::cout << "Error" << std::endl;
                std::cout << "no error" << std::endl;
                form2.setPosition(sf::Vector2f(1120, 348));
                form2.setTexture(formation2);
                window1.draw(form2);
            }
            window1.display();
        }

    }
    //return 0;
};
class Mainmenu
{
public:
    static int mainmenu()
    {
        sf::RenderWindow window(sf::VideoMode(1920,1080), "Foo2y", sf::Style::Default);
        sf::Texture background;
        sf::Sprite backgroundImage;
        if (!background.loadFromFile("menu.jpg"))
            std::cout << "Error" << std::endl;
        backgroundImage.setTexture(background);
        sf::Texture play;
        sf::Sprite playbutton;
        if (!play.loadFromFile("play.png"))
            std::cout << "Can't find the image" << std::endl;
        playbutton.setTexture(play);
        sf::RectangleShape rect(sf::Vector2f(450, 100));
        rect.setPosition(sf::Vector2f(1319, 803));
        rect.setFillColor(sf::Color::White);
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        if (rect.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                        {
                            return 0;
                        }
                    }

                }
                window.clear();
                window.draw(backgroundImage);

                window.draw(rect);
                window.draw(playbutton);
                window.display();
            }
        }
        return 0;
    }
};






int main()
{
    Mainmenu m;
    TeamSelect t;
    m.mainmenu();
    t.teamselect();
    sf::RenderWindow w(sf::VideoMode(winLen,winWid),"Foo2Y",Style::Default);
    //w.setFramerateLimit(20);
    Clock frameClock;
    w.clear();
    sf::Event event;//,event1;
    game g;
    Clock clk;
    int jhanda;
    while(w.isOpen()){
        while(frameClock.getElapsedTime().asMilliseconds()<deltaTime){
            if(w.pollEvent(event)){
                if(event.type==Event::Closed)
                    w.close();
            }
        }
        g.playerskeyUpdate(.001*deltaTime);
        jhanda=g.ballUpdate(.001*deltaTime);
        if(jhanda==7||jhanda==-7){
                break;
        }
        g.refresh(&w);
        while(clk.getElapsedTime().asMilliseconds()<=CheckPeriodms);
        clk.restart();
        frameClock.restart();
        //cout << "\n"<<deltaTime.asSeconds();
    }
    Texture text;
    if(jhanda==7){
        if(!text.loadFromFile("TeamA.png"))
            cout<<"teamA image failed";
        }
    else if(jhanda==-7){
            if(!text.loadFromFile("TeamB.png"))
                cout<<"teamB image failed";
    }
    Sprite s;
    s.setTexture(text);
    while(w.isOpen()){
            w.clear();
            w.draw(s);
            w.display();
            if(w.pollEvent(event)){
                if(event.type==Event::Closed)
                    w.close();
            }
    }
return 0;
}
