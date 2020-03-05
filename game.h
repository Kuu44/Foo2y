#pragma once
#include<iostream>
#include<SFML\graphics.hpp>
#include"team.cpp"
#include"field.cpp"

class game {
public:
    game();

    int ballUpdate(float);
    void pause();
    void playerskeyUpdate(float);
    void refresh(RenderWindow*);
    int wh_gm_set();

private:
    team A;
    team B;
    ball football;
    team* tmp_team;
    Field field;
    float time;
    sf::Vector2i ps;
};