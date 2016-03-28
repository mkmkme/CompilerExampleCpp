#pragma once

#include <ostream>

class CToken
{
public:
    const int mTag;

    CToken(int t) : mTag(t) {}
    virtual ~CToken() {}

    friend std::ostream& operator<<(std::ostream& os, const CToken& t)
    {
        os << "Token: " << t.mTag;
        return os;
    }
};
