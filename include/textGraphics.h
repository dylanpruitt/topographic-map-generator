#ifndef TEXTGRAPHICS_H
#define TEXTGRAPHICS_H


namespace textGraphics
{
    extern void changeTextColor (int foreground, int background);

    enum height_colors : int {
        BLACK = 0,
        GRAY = 8,
        WHITE = 7,
        BRIGHT_WHITE = 15
    };
};

#endif // TEXTGRAPHICS_H
