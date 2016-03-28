#pragma once

#include "token.hpp"
#include "tag.hpp"

class CNum : public CToken
{
public:
    const int mValue;

    CNum(int v) :
    CToken(Tag::NUM),
    mValue(v)
    {}

    virtual ~CNum() {}

    friend std::ostream& operator<<(std::ostream& os, const CNum& n)
    {
        os << "Num: " << n;
        return os;
    }
};
