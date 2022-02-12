class Identifier : public String {

  protected:
    void check() {
        bool ok = true;
        for (int i = 0; i < length; i++) {
            if ('0' <= pointer[i] && pointer[i] <= '9' && i ||
                'A' <= pointer[i] && pointer[i] <= 'Z' ||
                'a' <= pointer[i] && pointer[i] <= 'z' ||
                '_' == pointer[i]) continue;
            ok = false;
            break;
        }
        if (!ok) empty();
    }

  public:
    Identifier() : String() { }
    Identifier(const char chr) : String(chr) { check(); }
    Identifier(const char *str) : String(str) { check(); }
    Identifier(const String &Str) : String(Str) { check(); }
    Identifier(const Identifier &Str) : String(Str) { }
    ~Identifier() { }

    Identifier& operator =(const String &Str) {
        copy(Str.pointer);
        check();
        return *this;
    }
    Identifier& operator =(const Identifier &Str) {
        copy(Str.pointer);
        return *this;
    }
    bool operator ==(const String &Str) {
        if (length == Str.length) {
            bool ok = true;
            for (int i = 0; i < length; i++) {
                if (pointer[i] != Str.pointer[i]) {
                    ok = false;
                    break;
                }
            }
            return ok;
        }
        return false;
    }

    void lower() {
        for (int i = 0; i < length; i++) {
            pointer[i] |= (1 << 5);
        }
    }
};
