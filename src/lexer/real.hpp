#pragma once

#include "token.hpp"
#include "tag.hpp"

class CReal : public CToken
{
public:
    const float mValue;

    CReal(float v) :
    CToken(Tag::REAL),
    mValue(v)
    {}

    virtual ~CReal() {}

    friend std::ostream& operator<<(std::ostream& os, const CReal& r)
    {
        os << "Real: " << mValue;
        return os;
    }

};
