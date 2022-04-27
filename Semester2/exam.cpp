//
// Created by deafmist on 26.05.2021.
//

#include <iostream>
#include <windows.h>
using namespace std;

class Number {
protected:
    double value;

public:
    auto get_value();
    virtual Number* add(Number* a) = 0;
    virtual Number* diff(Number* a) = 0;
    virtual Number* mult(Number* a) = 0;
    virtual Number* div(Number* a) = 0;
};

auto Number::get_value() {
    return value;
}

class Integer : public Number {
public:
    Integer(double a);
    Number* add(Number* a) override;
    Number* diff(Number* a) override;
    Number* mult(Number* a) override;
    Number* div(Number* a) override;
};

Number* Integer::add(Number* a) {
    Integer *result = new Integer(value);
    result->value = value + (double)(long) a->get_value();

    return result;
}

Number *Integer::diff(Number *a) {
    Integer *result = new Integer(value);
    result->value = value - (double)(long) a->get_value();

    return result;
}

Number *Integer::mult(Number *a) {
    Integer *result = new Integer(value);
    result->value = value * (double)(long) a->get_value();

    return result;
}

Number *Integer::div(Number *a) {
    Integer *result = new Integer(value);
    result->value = (double)(long) (value / (double)(long) a->get_value());

    return result;
}

Integer::Integer(double a) {
    value = (double)(long) a;
}

class Real : public Number {
public:
    Real(double a);
    Number* add(Number* a) override;
    Number* diff(Number* a) override;
    Number* mult(Number* a) override;
    Number* div(Number* a) override;
};

Number* Real::add(Number* a) {
    Real *result = new Real(value);
    result->value = value + a->get_value();

    return result;
}

Number *Real::diff(Number *a) {
    Real *result = new Real(value);
    result->value = value - a->get_value();

    return result;
}

Number *Real::mult(Number *a) {
    Real *result = new Real(value);
    result->value = value * a->get_value();

    return result;
}

Number *Real::div(Number *a) {
    Real *result = new Real(value);
    result->value = value / a->get_value();

    return result;
}

Real::Real(double a) {
    value = a;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Number* a = new Integer(50.956);
    Number* b = new Real(32.245);

    cout << "��������� �������� � ������ Integer: " << a->add(b)->get_value() << endl
         << "��������� ��������� � ������ Integer: " << a->diff(b)->get_value() << endl
         << "��������� ��������� � ������ Integer: " << a->mult(b)->get_value() << endl
         << "��������� ������� � ������ Integer: " << a->div(b)->get_value() << "\n\n";

    cout << "��������� �������� � ������ Real: " << b->add(a)->get_value() << endl
         << "��������� ��������� � ������ Real: " << b->diff(a)->get_value() << endl
         << "��������� ��������� � ������ Real: " << b->mult(a)->get_value() << endl
         << "��������� ������� � ������ Real: " << b->div(a)->get_value() << "\n";
    return 0;
}
