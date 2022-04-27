#include "iostream"
#include "cmath"
#include "windows.h"

using namespace std;


class Tochka {
protected:
    double x_Coord;
    double y_Coord;
public:
    void Set_Coords(int x1, int y1);
    double get_x();
    double get_y();

    virtual void Move(double dx, double dy) = 0;
};

void Tochka::Set_Coords(int x1, int y1) {
    x_Coord = x1;
    y_Coord = y1;
}

double Tochka::get_x() {
    return x_Coord;
}

double Tochka::get_y() {
    return y_Coord;
}

void Tochka::Move(double dx, double dy) {
    x_Coord = x_Coord + dx;
    y_Coord = y_Coord + dy;
}

class Circle : public Tochka {
protected:
    double Radius;
public:
    void Set_Radius(int r1);
    double get_Radius();
};

void Circle::Set_Radius(int r) {
    Radius = r;
}

double Circle::get_Radius() {
    return Radius;
}

class Hexagon : public Circle {
protected:
    void calculate_radius();
    virtual void calculate_length();
    double circle_CoordX;
    double circle_CoordY;
    double length;
public:
    double get_length();
    double get_circle_CoordX();
    double get_circle_CoordY();
    virtual void set_circle_Coord(double coordX, double coordY);
    virtual double area();
    virtual void print();
    virtual void print_coords();
    virtual void print_length();
    virtual void print_radius();
    void Move(double dx, double dy) override;
};

double Hexagon::get_length() {
    return length;
}

void Hexagon::set_circle_Coord(double coordX, double coordY) {
    circle_CoordX = coordX;
    circle_CoordY = coordY;
    calculate_radius();
    calculate_length();
}

void Hexagon::calculate_radius() {
    Radius = sqrt(pow(x_Coord - circle_CoordX, 2) + pow(y_Coord - circle_CoordY, 2));
}

void Hexagon::calculate_length() {
    length = Radius;
}

double Hexagon::area() {
    return pow(length, 2) * 3 * sqrt(3) / 2;
}

double Hexagon::get_circle_CoordX() {
    return circle_CoordX;
}

double Hexagon::get_circle_CoordY() {
    return circle_CoordY;
}

void Hexagon::print_coords() {
    print();
    cout << "Координаты центра описанной окружности: (" << x_Coord << ", " << y_Coord << ");" << endl;
    cout << "Координаты точки на описанной окружности: (" << circle_CoordX << ", " << circle_CoordY << ");" << endl;
}

void Hexagon::Move(double dx, double dy) {
    Circle::Move(dx, dy);
    circle_CoordX += dx;
    circle_CoordY += dy;
}

void Hexagon::print_length() {
    print();
    cout << "Длина стороны правильного шестиугольника: " << length << endl;
}

void Hexagon::print_radius() {
    print();
    cout << "Радиус описанной вокруг правильного шестиугольника окружности: " << Radius << endl;
}

void Hexagon::print() {
    cout << "-----Правильный шестиугольник-----" << endl;
}

class Dodecagon : public Hexagon {
protected:
    void calculate_length() override;
public:
    void set_circle_Coord(double coordX, double coordY) override;
    double area() override;
    void print() override;
    void print_coords() override;
    void print_length() override;
    void print_radius() override;
};

void Dodecagon::calculate_length() {
    length = Radius * sqrt(2 - sqrt(3));
}

void Dodecagon::set_circle_Coord(double coordX, double coordY) {
    Hexagon::set_circle_Coord(coordX, coordY);
    calculate_length();
}

double Dodecagon::area() {
    return pow(length, 2) * 3 * (2 + sqrt(3));
}

void Dodecagon::print_coords() {
    print();
    cout << "Координаты центра описанной окружности (" << x_Coord << ", " << y_Coord << ");" << endl;
    cout << "Координаты точки на описанной окружности: (" << circle_CoordX << ", " << circle_CoordY << ");" << endl;
}

void Dodecagon::print_length() {
    print();
    cout << "Длина стороны правильного двенадцатиугольника: " << length << endl;
}

void Dodecagon::print_radius() {
    print();
    cout << "Радиус описанной вокруг правильного двенадцатиугольника окружности: " << Radius << endl;
}

void Dodecagon::print() {
    cout << "-----Правильный двенадцатиугольник-----" << endl;
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Hexagon hexagon;
    Dodecagon dodecagon;
    hexagon.Set_Coords(10, 15);
    dodecagon.Set_Coords(10, 15);
    hexagon.set_circle_Coord(15, 20);
    dodecagon.set_circle_Coord(15, 20);

    hexagon.print_coords();
    dodecagon.print_coords();

    hexagon.Move(20, 30);
    dodecagon.Move(20, 30);

    hexagon.print_length();
    dodecagon.print_length();
    hexagon.print_radius();
    dodecagon.print_radius();

    hexagon.print_coords();
    dodecagon.print_coords();

    double area = hexagon.area();
    cout << "Площадь шестиугольника = " << area << endl;
    area = dodecagon.area();
    cout << "Площадь двенадцатиугольника = " << area << endl;
    return 0;
}
