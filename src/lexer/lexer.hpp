#pragma once

#include <unordered_map>

class CLexer
{
    char mPeek;
    std::unordered_map<std::string, CWord> mWords;

public:
    static int Line = 1;

    CLexer();
    virtual ~CLexer() {}

private:
    void reserve(CWord w);
    void readChar();
    bool readChar(char c);

public:
    CToken scan();
};
