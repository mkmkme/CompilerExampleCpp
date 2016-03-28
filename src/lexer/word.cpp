#include "word.hpp"
#include "tag.hpp"

CWord CWord::And    = CWord("&&",       Tag::AND);
CWord CWord::Or     = CWord("||",       Tag::OR);
CWord CWord::Eq     = CWord("==",       Tag::EQ);
CWord CWord::Ne     = CWord("!=",       Tag::NE);
CWord CWord::Le     = CWord("<=",       Tag::LE);
CWord CWord::Ge     = CWord(">=",       Tag::GE);
CWord CWord::Minus  = CWord("minus",    Tag::MINUS);
CWord CWord::True   = CWord("true",     Tag::TRUE);
CWord CWord::False  = CWord("false",    Tag::FALSE);
CWord CWord::Temp   = CWord("t",        Tag::TEMP);

std::ostream& operator<<(std::ostream& os, const CWord& w)
{
    os << "Word: " << w;
    return os;
}
