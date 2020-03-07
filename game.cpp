#include"game.h"

//public
    game::game():A("A",1),B("B",-1)
    {
        football.setIcolor(Color::Magenta);
        football.setPosition(Vector2f(0,0));//float(.03)/(2-.03)*.5,0));
    }

    int game::ballUpdate(float deltaTime)
    {
        int jhanda=-1;
        football.updatePosition(deltaTime);
        jhanda=A.check(&football);
        if(jhanda==7){
            return 7;
        }
        else if(jhanda==1){
            football.setCurrentSide(TeamA);
        }
        jhanda=B.check(&football);
        if(jhanda==7){
            return -7;
        }
        else if(jhanda==1){
            football.setCurrentSide(TeamB);
        }
        return 0;
    }

    void game::playerskeyUpdate(float deltaTime)
    {
        A.giveInput(Keyboard::J,    Keyboard::L,     Keyboard::I,  Keyboard::K,    Keyboard::U, Keyboard::O,     &B, &football, deltaTime,&B);
        B.giveInput(Keyboard::A,    Keyboard::D,     Keyboard::W,  Keyboard::S,    Keyboard::Q, Keyboard::E,     &A, &football, deltaTime,&A);
    }

    void game::refresh(RenderWindow* w){
        w->clear();
        field.draw(w);
        A.draw(w);
        B.draw(w);
        football.draw(w);
    }

