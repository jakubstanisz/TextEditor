#include "TextEditor.hpp"
#include "raylib.h"
TextEditor::TextEditor(){}

void TextEditor::HandleInput(){
    char ch = GetCharPressed();
    switch (ch) {
        case KEY_ENTER:
        {
            textBuffer.SplitLine(position.line, position.column);
        }break;
        
        case KEY_BACKSPACE:
        {
            textBuffer.DeleteChar(position.line, position.column);
        }break;

        default:
        {
            textBuffer.InsertChar(position.line, position.column, ch);
        }
    }
}
void TextEditor::setPosition(Direction& dir){
    switch (dir) {
        case Direction::Left:
        {
            if (position.column > 0){
                position.column--;
            }else if (position.line > 0){
                position.line--;
                position.column = textBuffer.getLine(position.line).size() - 1;
            }
        }
        break;
        case Direction::Right:
        {
            if (position.column < textBuffer.getLine(position.line).size() - 1){
                position.column++;
            }else if (position.line < textBuffer.getNumberOfLines() - 1){
                position.line++;
                position.column = 0;
            }
        }
        break;
    }
}




