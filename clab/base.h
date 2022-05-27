#pragma once

class String {

  protected:
    char *pointer = nullptr;
    int length = 0;

    void empty();
    void copy(const char*);

  public:
    String();
    String(const char);
    String(const char*);
    String(const String&);
    ~String();

    const char& read(const int) const;
};
