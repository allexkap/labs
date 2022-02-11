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
        if (length) {
            pointer = new char [length+1];
            for (int i = 0; i < length; i++) pointer[i] = str[i];
            pointer[length] = '\0';
        }
    }

  public:
    char *pointer = nullptr;
    int length = 0;

    String() { }
    String(const char chr) {
        length = 1;
        copy(&chr);
    }
    String(const char *str) {
        while (str[length++]); length--;
        copy(str);
    }
    String(const String &Str) {
        length = Str.length;
        copy(Str.pointer);
    }
    ~String() {
        empty();
    }

    char read(int pos) {
        return pointer[pos];
    }
    void show() {
        std::cout << "length: " << length << '\n';
        if (pointer) {
            std::cout << "pointer: " << (long int) pointer << '\n'
                      << "value: " << pointer << '\n';
        }
    }
};
