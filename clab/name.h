#pragma once
#include "base.h"

class Identifier : public String {

  protected:
    void check();

  public:
    Identifier();
    Identifier(const char);
    Identifier(const char*);
    Identifier(const Identifier&);
    ~Identifier();

    Identifier& operator=(const Identifier&);
    friend bool operator==(const Identifier&, const Identifier&);

    void lower();
};
