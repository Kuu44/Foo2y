#pragma once
#include<iostream>
#include<SFML\graphics.hpp>
#ifndef playerCpp
#define playerCPP
#include "player.cpp"
#endif // playerCpp

extern const float playerSize;
extern const float fieldScale;
extern sf::Vector2i FieldCenter;

class ball {
public:
	ball();
    
    void applyDrag(float);
    void draw(RenderWindow*) const;
    int getCurrentSide();
    sf::Vector2f getFieldPosition();
    Vector2f getPosInWin();
    void incPosition(float, float, int);
    void incSpeed(float, float);
    void incSpeed(sf::Vector2f);
    void move(float);
    void passBall(player*, sf::Vector2f);
    void setCurrentSide(CurrentTeam);
    void setName(string);
    void setNum(short int);
    void setPosition();
    void setPosition(sf::Vector2f);
    void setSpeed(float, float);
    void setOcolor(Color);
    void setIcolor(Color);
    void updatePosition(float);
    int withBall(player*, int);
    sf::Vector2f operator-(ball);
    void operator<<(player*);

private:
    string name;
    short int num;
    sf::Vector2f posInField;
    sf::Vector2f posInWin;
    sf::Vector2f v_posInField;
    sf::Vector2f v_posInWin;
    CircleShape Cir;
    int MaxSpeed;
    int SpeedScale;
    sf::Vector2f velocity;
    sf::Vector2f Scale;
    float vibrtn;
    bool ball_self_flag;
    bool smOne_has_flag;
    bool stick_flag;
    float ctrl_det;
    Clock clkTmp;
    //0=TeamA, 1=None, 2=TeamB
    CurrentTeam currentSide;
    //friend sf::Vector2f teamoperator-(ball a,ball b
    const float ballFieldWidR;
    const float ballSize;
    const float ballOtlnSzR;//outline size ratio
    const float b_posIncUnit;
    const float p_and_b;

    void incPositionLow(int, float, float);
    static sf::Vector2f makeUnitVector(Vector2f);
    static float magnitude(sf::Vector2f);
    void prep_playerToBall(sf::Vector2f&, sf::Vector2f, player*);
    void setPositionI(int);
    void setSpeed();
    inline void update_posInWin();
    inline void update_vposInWin();
};