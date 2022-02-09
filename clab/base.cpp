class String {

  public:
    char *pointer = nullptr;
    int length;

    void empty() {
        if (!pointer) return;
        delete [] pointer;
        pointer = nullptr;
        length = 0;
    }

    String() {
        empty();
    }
    String(string str) {
        length = str.length();
        if (length) {
            pointer = new char [length+1];
            for (int i = 0; i < length; i++) pointer[i] = str[i];
            pointer[length] = '\0';
        }
    }
    String(char chr) : String(string(1, chr)) { }
    String(String &Str) {
        length = Str.length;
        if (length) {
            pointer = new char [length+1];
            for (int i = 0; i < length; i++) pointer[i] = Str.pointer[i];
            pointer[length] = '\0';
        }
    }
    ~String() {
        empty();
    }

    char read(int pos) {
        return pointer[pos];
    }
    void show() {
        cout << "length: " << length << endl;
        if (pointer) {
            cout << "pointer: " << &pointer << endl;
            cout << "value: " << pointer << endl;
        }
    }
};
