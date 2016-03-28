#include "lexer.hpp"

#include <cstdio>
#include <cctype>

void CLexer::reserve(CWord w)
{
    mWords.insert(w.lexeme(), w);
}

CLexer::CLexer() :
mPeek(' '),
mWords()
{
    reserve(CWord("if", Tag::IF));
    reserve(CWord("else", Tag::ELSE));
    reserve(CWord("while", Tag::WHILE));
    reserve(CWord("do", Tag::DO));
    reserve(CWord("break", Tag::BREAK));
    reserve(CWord::True);
    reserve(CWord::False);
    reserve(CType::Int);
    reserve(CType::Char);
    reserve(CType::Bool);
    reserve(CType::Float);
}

void CLexer::readChar()
{
    mPeek = getchar();
}

bool CLexer::readChar(char c)
{
    readChar();
    if (mPeek != c)
        return false;
    mPeek = ' ';
    return true;
}

CToken CLexer::scan()
{
    for (;; readChar()) {
        if (mPeek == ' ' || mPeek == '\t')
            continue;
        else if (mPeek == '\n')
            Line += 1;
        else
            break;
    }

    switch (mPeek) {
    case '&':
        if (readChar('&'))
            return CWord::And;
        else
            return CToken('&');
    case '|':
        if (readChar('|'))
            return CWord::Or;
        else
            return CToken('|');
    case '=':
        if (readChar('='))
            return CWord::Eq;
        else
            return CToken('=');
    case '!':
        if (readChar('='))
            return CWord::Ne;
        else
            return CToken('!');
    case '<':
        if (readChar('='))
            return CWord::Le:
        else
            return CToken('<');
    case '>':
        if (readChar('='))
            return CWord::Ge;
        else
            return CToken('>');
    }

    if (isdigit(mPeek)) {
        int v = 0;

        do {
            v = 10 * v + (mPeek - '0');
            readChar();
        } while (isascii(mPeek));   // TODO: find out the replacement of the Character.isDefined

        if (mPeek != '.')
            return CNum(v);

        float x = v;
        float d = 10;

        for (;;) {
            readChar();
            if (!isdigit(mPeek))
                break;

            x += (mPeek - '0') / d;
            d *= 10;
        }
        return CReal(x);
    }

    if (isalpha(mPeek)) {
        std::ostringstream ss;
        do {
            ss << mPeek;
            getChar();
        } while (isalpha(mPeek));

        std::string s = ss.str();
        auto it = mWords.find(s);
        if (it != mWords.end())
            return it->second;
        CWord w(s, Tag::ID);
        mWords.insert(s, w);
        return w;
    }
    CToken tok(mPeek);
    mPeek = ' ';
    return tok;
}
