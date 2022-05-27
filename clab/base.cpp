#include <iostream>
#include "base.h"

void String::empty() {
    length = 0;
    if (pointer) {
        delete [] pointer;
        pointer = nullptr;
    }
}
void String::copy(const char *str) {
    empty();
    if (!str) return;
    while (str[length++]); length--;
    pointer = new char [length+1];
    for (int i = 0; i <= length; i++) pointer[i] = str[i];
}

String::String() {
    copy("");
}
String::String(const char chr) {
    char str[2] = {chr, '\0'};
    copy(str);
}
String::String(const char *str) {
    copy(str);
}
String::String(const String &Str) {
    copy(Str.pointer);
}
String::~String() {
    empty();
}

const char& String::read(const int pos) const {
    return pointer[pos];
}
