#include "TextBuffer.hpp"
struct Position{
    int line;
    int column;
};

enum class Direction {
    Up,
    Down,
    Left,
    Right
};

class TextEditor{
    public:
        TextEditor();
        void HandleInput();
        void Update();
        void Render();
        void setPosition(Direction& dir);
    private:
        TextBuffer textBuffer;
        Position position;

};