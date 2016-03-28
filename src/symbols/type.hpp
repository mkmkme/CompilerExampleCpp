#pragma once

#include <cstddef>
#include <string>

#include "../lexer/word.hpp"

class CType : public CWord
{
    std::size_t mHash; // for operator==
public:
    int mWidth; // Used to allocate memory

    CType(std::string s, int tag, int w);

    virtual ~CType() {}

    inline bool operator==(const CType& t) const
    {
        return mHash == t.mHash;
    }

    static CType    Int,
                    Float,
                    Char,
                    Bool;

    static CType Null;

    static bool isNumeric(const CType& t);
    static CType max(const CType& t1, const CType& t2);
};
