#include <iostream>
using namespace std;

// Шаблонний базовий клас
template <typename T1, typename T2>
class Base {
public:
    T1 value1;
    T2 value2;

    Base(T1 v1, T2 v2) : value1(v1), value2(v2) {
        cout << "Base constructor: " << value1 << ", " << value2 << endl;
    }

    virtual ~Base() {
        cout << "Base destructor" << endl;
    }
};

// Шаблонний клас-нащадок 1
template <typename T1, typename T2, typename T3, typename T4>
class Child : public Base<T1, T2> {
public:
    T3 value3;
    T4 value4;

    Child(T1 v1, T2 v2, T3 v3, T4 v4) : Base<T1, T2>(v1, v2), value3(v3), value4(v4) {
        cout << "Child constructor: " << value3 << ", " << value4 << endl;
    }

    virtual ~Child() {
        cout << "Child destructor" << endl;
    }
};

// Шаблонний клас-нащадок 2
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Child2 : public Child<T1, T2, T3, T4> {
public:
    T5 value5;
    T6 value6;

    Child2(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6)
        : Child<T1, T2, T3, T4>(v1, v2, v3, v4), value5(v5), value6(v6) {
        cout << "Child2 constructor: " << value5 << ", " << value6 << endl;
    }

    virtual ~Child2() {
        cout << "Child2 destructor" << endl;
    }
};

int main() {
    // Створення об'єкта класу Child2 з різними типами
    Child2<int, double, char, string, float, bool> obj(10, 20.5, 'A', "Hello", 3.14f, true);

    cout << "Base values: " << obj.value1 << ", " << obj.value2 << endl;
    cout << "Child values: " << obj.value3 << ", " << obj.value4 << endl;
    cout << "Child2 values: " << obj.value5 << ", " << obj.value6 << endl;

    return 0;
}
