#pragma once

class Color {
public:
    float red, green, blue, alpha;

	Color(){}
	Color(float r, float g, float b, float a) : red(r), green(g), blue(b), alpha(a) {};

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

