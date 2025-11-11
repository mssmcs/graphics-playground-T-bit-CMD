#include "graphics.h"

using namespace std;
using namespace mssm;
/*
class Button {
public:
    Vec2d pos;
    Color color;
    Color highlight;
    int width;
    int height;
    string label;

    void draw(Graphics& g);
    // void update(Graphics& g);

    bool isMouseOver(Graphics& g);
    bool isClicked(Graphics& g);
};

void Button::draw(Graphics& g)
{
    if(isMouseOver(g)){
        g.rect(pos, width, height, highlight, highlight);
    }
    else{
        g.rect(pos, width, height, color, color);
    }
    g.text({pos.x + width/2, pos.y + height/2}, 50, format("{}", label), WHITE, HAlign::center,VAlign::center);
}

bool Button::isMouseOver(Graphics &g)
{
    Vec2d mp = g.mousePos();
    if(mp.x > pos.x && mp.x < pos.x + width){
        if(mp.y > pos.y && mp.y < pos.y + height){
            return true;
        }
        return false;
    }
    return false;
    // see if it's in the rectangle
    // return true if it is
}

bool Button::isClicked(Graphics &g)
{
    if(g.onMousePress(MouseButton::Left)){
        if(isMouseOver(g)){
            return true;
        }
        return false;
    }
    return false;
    // use isMouseOver
    // return true if mouse was clicked and mouse is over
}

int main()
{
    Graphics g("Button", 1024, 768);

    Button BenjaminButton;
    BenjaminButton.color = RED;
    BenjaminButton.highlight = GREEN;
    BenjaminButton.height = 300;
    BenjaminButton.width = 500;
    BenjaminButton.label = "Benjamin Button";
    BenjaminButton.pos = {g.width()/2, g.height()/2};

    while (g.draw()) {
        if(!g.isDrawable()) {
            continue;
        }
        BenjaminButton.draw(g);
        if(BenjaminButton.isClicked(g)){
            break;
        }
    }

    return 0;
}
*/

class Car{
public:
    Vec2d pos;
    Color color;
    int width;
    int height;

    void draw(Graphics &g);
    bool isDriveLeft(Graphics &g);
    bool isDriveRight(Graphics &g);
    bool collision(Graphics &g);
};

void Car::draw(Graphics &g){
    g.rect(pos, width, height, color);
    if(g.isKeyPressed(Key::Left)){
        pos.x -= g.width()/100;
    }
    else if(g.isKeyPressed(Key::Right)){
        pos.x += g.width()/100;
    }
}

bool Car::collision(Graphics &g){
    return false;
}


int main()
{
    Graphics g("Polygon Track", 1024, 768);

    Car Player;
    Player.pos = {g.width(), g.height()-50};
    Player.color = BLUE;
    Player.width = 100;
    Player.height = 20;

    while (g.draw()){
        if(!g.isDrawable()){
            continue;
        }
        Player.draw(g);
        if(Player.collision(g)){
            break;
        }
    }
}
