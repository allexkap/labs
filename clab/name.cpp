#include "name.h"
#include "kwrd.cpp"

void Identifier::check() {
    bool ok = true;
    for (int i = 0; ok && i < length; i++) {
        if ('0' <= pointer[i] && pointer[i] <= '9' && i ||
            'A' <= pointer[i] && pointer[i] <= 'Z' ||
            'a' <= pointer[i] && pointer[i] <= 'z' ||
            '_' == pointer[i]) continue;
        ok = false;
    }
    for (int i = 0, j = 0; ok && i < 84; i++, j = 0)
        while (ok && pointer[j] && keyword[i][j] && pointer[j] == keyword[i][j] && ++j)
            if (!pointer[j] && !keyword[i][j]) ok = false;
    if (!ok) copy("");
}

Identifier::Identifier() : String() { }
Identifier::Identifier(const char chr) : String(chr) { check(); }
Identifier::Identifier(const char *str) : String(str) { check(); }
Identifier::Identifier(const Identifier &Str) : String(Str) { }
Identifier::~Identifier() { }

Identifier& Identifier::operator=(const Identifier &Str) {
    if (this != &Str) copy(Str.pointer);
    return *this;
}
bool operator==(const Identifier &Str1, const Identifier &Str2) {
    if (Str1.length != Str2.length) return false;
    for (int i = 0; i < Str1.length; i++) if (Str1.pointer[i] != Str2.pointer[i]) return false;
    return true;
}

void Identifier::lower() {
    for (int i = 0; i < length; i++) pointer[i] |= (1 << 5);
}
