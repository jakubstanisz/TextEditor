#include <vector>
#include <string>
class TextBuffer{
    public:
        TextBuffer();
        void InsertChar(int line, int pos, char ch);
        void DeleteChar(int line, int pos);
        void SplitLine(int line, int pos);
        void JoinLines(int line);
        bool ValidateLinePos(int line, int pos);
        std::string getLine(int line);
        int getNumberOfLines();
    private:
        std::vector<std::string> text;

};