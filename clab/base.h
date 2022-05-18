#pragma once

class String {

  protected:
    void empty();
    void copy(const char*);

  public:
    char *pointer = nullptr;
    int length = 0;

    String();
    String(const char);
    String(const char*);
    String(const String&);
    ~String();

    const char& read(const int);
};
