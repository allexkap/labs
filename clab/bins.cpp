#include "base.h"
#include "bins.h"

void Binary::check() {
    bool ok = true;
    for (int i = 0; i < length; i++) {
        if ('0' == pointer[i] || pointer[i] == '1') continue;
        ok = false;
        break;
    }
    if (!ok) copy("00");
}
char Binary::match(const Binary &other) {
    char result = other.pointer[0] - pointer[0];
    for (int i = ((length>other.length)?length:other.length)-1; !result && i > 0; i--)
        result = pointer[(length>i)?length-i:0] - other.pointer[(other.length>i)?other.length-i:0];
    return result + '=';
}

Binary::Binary() : String() { }
Binary::Binary(const char *str) : String(str) { check(); }
Binary::Binary(const String &Str) : String(Str) { check(); }
Binary::Binary(const Binary &Str) : String(Str) { }
Binary::~Binary() { }

Binary& Binary::operator =(const String &Str) {
    copy(Str.pointer);
    check();
    return *this;
}
Binary& Binary::operator =(const Binary &Str) {
    copy(Str.pointer);
    return *this;
}
bool Binary::operator ==(const String &Str) {
    return match(Str) == '=';
}
bool Binary::operator <(const String &Str) {
    return match(Str) == '<';
}

void Binary::optimization() {
    int i = 0;
    while (++i < length-1 && pointer[0] == pointer[i]); i--;
    if (i) *this = Binary(pointer + i);
}
