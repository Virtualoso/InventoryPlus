#pragma once

class Color {

public:

    float r, g, b, a;

    unsigned int toARGB() const;
    unsigned int toABGR() const;

    static Color fromHSB(float, float, float);

    static Color WHITE;
    static Color GREY;
    static Color BLACK;
    static Color RED;
    static Color GREEN;
    static Color BLUE;
    static Color YELLOW;
    static Color ORANGE;
    static Color PURPLE;
    static Color CYAN;
    static Color NIL;
    static Color SHADE_DOWN;
    static Color SHADE_UP;
    static Color SHADE_NORTH_SOUTH;
    static Color SHADE_WEST_EAST;

};

