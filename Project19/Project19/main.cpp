#include <iostream>
using namespace std;

// Базовий клас
class Base {
public:
    int baseValue;

    Base(int value) : baseValue(value) {
        cout << "Base constructor: " << baseValue << endl;
    }

    virtual ~Base() {
        cout << "Base destructor" << endl;
    }
};

// Віртуальний клас для віртуального успадкування
class Derived : virtual public Base {
public:
    int derivedValue;

    Derived(int baseVal, int derivedVal) : Base(baseVal), derivedValue(derivedVal) {
        cout << "Derived constructor: " << derivedValue << endl;
    }

    virtual ~Derived() {
        cout << "Derived destructor" << endl;
    }
};

// Клас, що наслідує від Derived
class Final : public Derived {
public:
    int finalValue;

    Final(int baseVal, int derivedVal, int finalVal) : Derived(baseVal, derivedVal), finalValue(finalVal) {
        cout << "Final constructor: " << finalValue << endl;
    }

    ~Final() {
        cout << "Final destructor" << endl;
    }
};

int main() {
    Final obj(10, 20, 30);
    cout << "Base value: " << obj.baseValue << ", Derived value: " << obj.derivedValue << ", Final value: " << obj.finalValue << endl;
    return 0;
}
