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
char Binary::match(const Binary &other) const {
    char result = other.pointer[0] - pointer[0];
    for (int i = ((length>other.length)?length:other.length)-1; !result && i > 0; i--)
        result = pointer[(length>i)?length-i:0] - other.pointer[(other.length>i)?other.length-i:0];
    return result + '=';
}

Binary::Binary() : String() { }
Binary::Binary(const char *str) : String(str) { check(); }
Binary::Binary(const Binary &Str) : String(Str) { }
Binary::~Binary() { }

Binary& Binary::operator=(const Binary &Str) {
    if (this != &Str) copy(Str.pointer);
    return *this;
}
bool operator==(const Binary &Str1, const Binary &Str2) {
    return Str1.match(Str2) == '=';
}
bool operator<(const Binary &Str1, const Binary &Str2) {
    return Str1.match(Str2) == '<';
}

void Binary::optimization() {
    int i = 0;
    while (++i < length-1 && pointer[0] == pointer[i]); i--;
    if (i) *this = Binary(pointer + i);
}
