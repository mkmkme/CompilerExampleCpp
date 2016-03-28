#include "type.hpp"
#include "../lexer/tag.hpp"

#include <functional>

CType::CType(std::string s, int tag, int w) :
CWord(s, tag),
mHash(std::hash<std::string>()(s)),
mWidth(w)
{}

CType CType::Int    = CType("int",      Tag::BASIC, 4);
CType CType::Float  = CType("float",    Tag::BASIC, 8);
CType CType::Char   = CType("char",     Tag::BASIC, 1);
CType CType::Bool   = CType("bool",     Tag::BASIC, 1);

CType CType::Null   = CType("null", 0, 0);

bool CType::isNumeric(const CType& t)
{
    return (t == CType::Char || t == CType::Int || t == CType::Float);
}

CType max(const CType& t1, const CType& t2)
{
    if (!CType::isNumeric(t1) || !CType::isNumeric(t2))
        return CType::Null;
    else if (t1 == CType::Float || t2 == CType::Float)
        return CType::Float;
    else if (t1 == CType::Int || t2 == CType::Int)
        return CType::Int;
    else
        return CType::Char;
}
