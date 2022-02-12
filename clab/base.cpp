class String {

  protected:
    void empty() {
        length = 0;
        if (pointer) {
            delete [] pointer;
            pointer = nullptr;
        }
    }
    void copy(const char *str) {
        empty();
        while (str[length++]); length--;
        if (length) {
            pointer = new char [length+1];
            for (int i = 0; i <= length; i++) pointer[i] = str[i];
        }
    }

  public:
    char *pointer = nullptr;
    int length = 0;

    String() { }
    String(const char chr) {
        char str[] = {chr, '\0'};
        copy(str);
    }
    String(const char *str) {
        copy(str);
    }
    String(const String &Str) {
        copy(Str.pointer);
    }
    ~String() {
        empty();
    }

    char read(int pos) {
        return pointer[pos];
    }
};
