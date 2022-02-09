class String {

  private:
    char *pointer;
    int length;

  public:
    String() {
        cout << "none\n";
        length = 0;
        pointer = 0;
    }
    String(string str) {
        cout << "string\n";
        length = str.length();
        pointer = new char [length];
        for (int i = 0; i < length; i++) pointer[i] = str[i];
    }
    String(char chr) : String(string(1, chr)) {
        cout << "char\n";
    }
    String(const String &Str) {
        cout << "copy\n";
        length = Str.length;
        pointer = new char [length];
        for (int i = 0; i < length; i++) pointer[i] = Str.pointer[i];
    }
    ~String() {
        cout << "end\n";
        if (pointer) delete [] pointer;
    }

    char read(int pos) {
        return pointer[pos];
    }
    void show() {
        for (int i = 0; i < length; i++) cout << pointer[i];
        cout << endl;
    }
};

int main() {
    String tmp = String("abc");
    String str(tmp);
    str.show();
    return 0;
}
