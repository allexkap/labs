#include "base.h"
#include "name.h"
#include "kwrd.h"

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
    if (!ok) empty();
}

Identifier::Identifier() : String() { }
Identifier::Identifier(const char chr) : String(chr) { check(); }
Identifier::Identifier(const char *str) : String(str) { check(); }
Identifier::Identifier(const String &Str) : String(Str) { check(); }
Identifier::Identifier(const Identifier &Str) : String(Str) { }
Identifier::~Identifier() { }

Identifier& Identifier::operator =(const String &Str) {
    copy(Str.pointer);
    check();
    return *this;
}
Identifier& Identifier::operator =(const Identifier &Str) {
    copy(Str.pointer);
    return *this;
}
bool Identifier::operator ==(const String &Str) {
    if (length != Str.length) return false;
    for (int i = 0; i < length; i++) if (pointer[i] != Str.pointer[i]) return false;
    return true;
}

void Identifier::lower() {
    for (int i = 0; i < length; i++) pointer[i] |= (1 << 5);
}
