#pragma once

class Binary : public String {

  protected:
    void check();
    char match(const Binary&);

  public:
    Binary();
    Binary(const char*);
    Binary(const String&);
    Binary(const Binary&);
    ~Binary();

    Binary& operator =(const String&);
    Binary& operator =(const Binary&);
    bool operator ==(const String&);
    bool operator <(const String&);

    void optimization();
};
