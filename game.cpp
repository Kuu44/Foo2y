#include"game.h"

    game::game() : A("A",1),B("B",-1)
    {
        football.setIcolor(Color::Magenta);
        football.setPosition(Vector2f(0,0));
    }

    int game::ballUpdate(float deltaTime) {
        int jhanda = -1;
        football.updatePosition(deltaTime);
        jhanda = A.check(&football);
        if (jhanda == 7) {
            return 7;
        }
        else if (jhanda == 1) {
            football.setCurrentSide(TeamA);
        }
        jhanda = B.check(&football);
        if (jhanda == 7) {
            return -7;
        }
        else if (jhanda == 1) {
            football.setCurrentSide(TeamB);
        }
        return 0;
    }
    void game::pause() {};
    void game::playerskeyUpdate(float deltaTime)
    {
        B.giveInput(Keyboard::Num4, Keyboard::Num6, Keyboard::Up, Keyboard::Down, Keyboard::M, Keyboard::P, &A, &football, deltaTime, &A);
        A.giveInput(Keyboard::A, Keyboard::D, Keyboard::W, Keyboard::S, Keyboard::Q, Keyboard::E, &B, &football, deltaTime, &B);
    }
    void game::refresh(RenderWindow* w)
    {
        w->clear();
        field.draw(w);
        A.draw(w);
        B.draw(w);
        football.draw(w);
        w->display();
    }
    int game::wh_gm_set()
    {
    }
    


