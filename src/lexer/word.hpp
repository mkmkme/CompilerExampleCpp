#pragma once

#include <string>
#include <ostream>

#include "token.hpp"

class CWord : public CToken
{
    std::string mLexeme;
public:

    CWord(const std::string& s, int tag) :
    CToken(tag),
    mLexeme(s)
    {}

    inline const std::string& lexeme() const { return mLexeme; }

    virtual ~CWord() {}

    friend std::ostream& operator<<(std::ostream& os, const CWord& w);

    static CWord    And,
                    Or,
                    Eq,
                    Ne,
                    Le,
                    Ge,
                    Minus,
                    True,
                    False,
                    Temp;
};