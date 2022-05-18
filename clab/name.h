#pragma once

class Identifier : public String {

  protected:
    void check();

  public:
    Identifier();
    Identifier(const char);
    Identifier(const char*);
    Identifier(const String&);
    Identifier(const Identifier&);
    ~Identifier();

    Identifier& operator =(const String&);
    Identifier& operator =(const Identifier&);
    bool operator ==(const String&);

    void lower();
};
