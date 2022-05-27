#pragma once
#include "base.h"

class Binary : public String {

  protected:
    void check();
    char match(const Binary&) const;

  public:
    Binary();
    Binary(const char*);
    Binary(const String&);
    Binary(const Binary&);
    ~Binary();

    Binary& operator=(const Binary&);
    friend bool operator==(const Binary&, const Binary&);
    friend bool operator<(const Binary&, const Binary&);

    void optimization();
};
