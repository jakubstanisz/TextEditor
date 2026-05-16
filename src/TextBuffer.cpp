#include "TextBuffer.hpp"

TextBuffer::TextBuffer(){}

void TextBuffer::InsertChar(int line, int pos, char ch){
    if (ValidateLinePos(line, pos))
        text[line].insert(pos,1,ch);
}
void TextBuffer::DeleteChar(int line, int pos){
    if (ValidateLinePos(line, pos))
        text[line].erase(pos, 1);
}
void TextBuffer::SplitLine(int line, int pos){
    if (ValidateLinePos(line, pos)){
        std::string remainingChars = text[line].substr(pos);
        text[line].erase(pos);
        text.insert(text.begin() + line + 1, remainingChars);
    }
}
void TextBuffer::JoinLines(int line){
    if (line > 0 && line < (int)text.size()){

    }
}
bool TextBuffer::ValidateLinePos(int line, int pos){
    if (line < 0 || line >= (int)text.size()){ 
        return false;
    }
    if (pos < 0 || pos > (int)text[line].length()){
        return false;
    }
    return true;
}
std::string TextBuffer::getLine(int line){
    if (line > 0 && line < (int)text.size()){
        return text[line];
    }
    return "";
}
int TextBuffer::getNumberOfLines(){
    return text.size();
}
