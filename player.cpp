#include<iostream>
#include<SFML\graphics.hpp>
#include<cmath>
/*#ifndef ballCPP
    #define ballCPP
    #include"ball.cpp"
#endif // ballCPP*/

using namespace std;
using namespace sf;

enum Flags{pass,shoot};
enum Direction{und,dayan,bayan,mathi,muni};
const float playerFieldWidR=.02;
const float playerSize=playerFieldWidR*3;
const float playerOtlnSzR=.2;//outline size ratio
const float posIncUnit=playerSize*.05;
//const float drag=.05;
const float vibrtn=.00084;
const int speedScale=100;//acceleration=speedScale pixels/sec^2 and speed=velocity pixels/sec
extern const float fieldScale;
extern sf::Vector2i FieldCenter;

class player{
public:
    //Sprite jerseyS;
    player():v_posInField(sf::Vector2f(7,7)),v_posInWin(sf::Vector2f(7,7)),pass_flag(false),passSpeed(25.0f)
    {
        MaxSpeed=70.0f;
        velocity=sf::Vector2f(0,0);
        Cir.setPointCount(20);
        Cir.setRadius(playerSize);
        Cir.setOrigin(playerSize*(1-playerOtlnSzR),playerSize*(1-playerOtlnSzR));
        Cir.setFillColor(Color(255,0,0,100));
        Cir.setOutlineThickness(playerSize*playerOtlnSzR);
        Cir.setOutlineColor(Color(0,255,0,100));
        Cir.scale(fieldScale,fieldScale);
        Scale=sf::Vector2f((2-playerSize)*fieldScale,(1.5-playerSize)*fieldScale);
        set_bounceFac(1);
        input_speed_store=Vector2f(0,0);
        directions[0]=und; directions[1]=und;
        //(fieldScale*2-playerSize-playerOutline,fieldScale*1.5-playerSize-playerOutline);
    }
    void setName(string naam){
        name=naam;
    }
    void setNum(short int anka){
        num=anka;
    }
    void setPosition(){
        setPosition(v_posInField);
    }
    void setPosition(sf::Vector2f v){
        v_posInField=v;
        setPositionI();
    }
    void incPosition(float x=1,float y=1,int virt=0){
        if(x==0&&y==0)
            v_posInWin=posInWin;
        else
        {
            incPositionLow(virt,x,y);
        }

    }
    /*void incSpeed(float x,float y){
        velocity.x+=x;
        velocity.y+=y;
        setSpeed();
    }*/
    void incSpeed(Vector2f inputSpeed){
        inputSpeed.x*=speedScale;inputSpeed.y*=speedScale;
        int tmp=1;
        if(inputSpeed.x<0)
            tmp=-1;
        if(input_speed_store.x<tmp*inputSpeed.x)
            input_speed_store.x=tmp*inputSpeed.x;
        tmp=1;
        if(inputSpeed.y<0)
            tmp=-1;
        if(input_speed_store.y<tmp*inputSpeed.y)
            input_speed_store.y=tmp*inputSpeed.y;
        //tmp=pow(velocity.x*velocity.x+velocity.y*velocity.y,.5);
        velocity += inputSpeed;
        velocity-=Vector2f(velocity.x*input_speed_store.x/MaxSpeed,velocity.y*input_speed_store.y/MaxSpeed);
        if(velocity.x>-1*vibrtn&&velocity.x<vibrtn){
            velocity.x=0;
        }
        if(velocity.y>-1*vibrtn&&velocity.y<vibrtn){
            velocity.y=0;
        }
        setSpeed();
    }
    void setSpeed(float x,float y){
        velocity.x=x;
        velocity.y=y;
        setSpeed();
    }
    void setSpeed(Vector2f inputSpeed){
        velocity=inputSpeed;
        setSpeed();
    }
    void setOcolor(Color Oc){
        Cir.setOutlineColor(Oc);
    }
    void setIcolor(Color Ic){
        Cir.setFillColor(Ic);
    }
    void draw(RenderWindow* tar) const{
        tar->draw(Cir);
    }
    sf::Vector2f operator-(player p){
        return (sf::Vector2f(v_posInWin.x-p.v_posInWin.x,v_posInWin.y-p.v_posInWin.y));
    }
    sf::Vector2f get_posInWin(){
        return posInWin;
    }
    sf::Vector2f getSpeed() { return velocity; }
    void set_bounceFac(float f){
        if(f>=0&&f<=1){
                bounceFac=f;
        }
    }
    float get_bounceFac(){
        return bounceFac;
    }
    bool getFlag(int i=pass){
        switch(i){
            case pass:
                return pass_flag;
            default:
                return pass_flag;
        };
    }
    void setFlag(bool flag,int i=pass){
        switch(i){
            case pass:
                pass_flag=flag;
            default:
                ;
        };
    }
    int get_passSpeed(){
        return passSpeed;
    };
    void set_directions(Direction d){
        if(d==dayan||d==bayan){
            directions[0]=d;
        }
        else if(d==mathi||d==muni){
            directions[1]=d;
        }
        else{
            directions[0]=und;
            directions[1]=und;
        }
    }
    bool is_direction(Direction d){
        bool flag=false;
        if(d==dayan||d==bayan){
            if(d==directions[0])
                flag=true;
        }
        else if(d==mathi||d==muni){
            if(d==directions[1])
                flag=true;
        }
        else{
            if(d==und)
                flag=true;
        }
        return flag;
    }
    void setHasPossesion(bool t)
    {
        hasPossesion = t;
    }
private:
    void incPositionLow(int virt, float x=0,float y=0){                      //(int x=1,int y=1){
        v_posInField=posInField;
        v_posInField.x+=x*posIncUnit*velocity.x;
        v_posInField.y+=y*posIncUnit*velocity.y;
        setPositionI(virt);
        //cout << " Move: (" << x << " , " << y << ")\n";
    }
    inline void update_posInWin(){
        posInWin=sf::Vector2f(FieldCenter.x+posInField.x*Scale.x,FieldCenter.y+posInField.y*Scale.y);
    }
    inline void update_vposInWin(){
        v_posInWin=sf::Vector2f(FieldCenter.x+v_posInField.x*Scale.x,FieldCenter.y+v_posInField.y*Scale.y);
    }
    void setPositionI(int virt=0){
        int change=1;
        if(v_posInField.x<-1||v_posInField.x>1){
            change=0;//posInField.x=(posInField.x>1)?1:-1;
        }
        if(v_posInField.y<-1||v_posInField.y>1){
            change=0;//posInField.y=(posInField.y>1)?1:-1;
        }
        if(change){
            if(!virt){
                posInField=v_posInField;
                update_posInWin();

                Cir.setPosition(posInWin);
            }
            else
                update_vposInWin();
        }
    }
    void setSpeed(){
        velocity.x=(velocity.x<-1*MaxSpeed)?-1*MaxSpeed:velocity.x;
        velocity.x=(velocity.x>MaxSpeed)?MaxSpeed:velocity.x;
        velocity.y=(velocity.y<-1*MaxSpeed)?-1*MaxSpeed:velocity.y;
        velocity.y=(velocity.y>MaxSpeed)?MaxSpeed:velocity.y;
        if(posInField.x<=-.996)
            velocity.x=(velocity.x<0)?0:velocity.x;
        else if(posInField.x>=.996)
            velocity.x=(velocity.x>0)?0:velocity.x;
        if(posInField.y<=-.998)
            velocity.y=(velocity.y<0)?0:velocity.y;
        else if(posInField.y>=.998)
            velocity.y=(velocity.y>0)?0:velocity.y;
    }
    

    string name;
    short int num;
    //Texture jerseyT;
    sf::Vector2f posInField;
    sf::Vector2f posInWin;
    sf::Vector2f v_posInField;
    sf::Vector2f v_posInWin;
    CircleShape Cir;
    float MaxSpeed;
    sf::Vector2f velocity;
    sf::Vector2f input_speed_store;
    sf::Vector2f Scale;
    float bounceFac;//0 means perfect control

    int passSpeed;
    bool hasPossesion;

    bool pass_flag;
    Direction directions[2];
};

