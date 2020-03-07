#include<iostream>
#include<SFML\graphics.hpp>
#include"team.h"
#include"field.h"

using namespace sf;

class game{
public:
    game();
    int ballUpdate(float );
    void playerskeyUpdate(float );
    void refresh(RenderWindow* );
private:
    float time;
    sf::Vector2i ps;
    ball football;
    team A;
    team B;
    team* tmp_team;
    field field;
};


