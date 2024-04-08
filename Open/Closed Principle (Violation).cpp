#include <iostream>

// Base class representing a shape
class Shape {
public:
    virtual double area() const = 0; // Pure virtual function for calculating area
};

// Derived class representing a circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14 * radius * radius; // Area of circle = π * r^2
    }
};

// Derived class representing a square
class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side; // Area of square = side^2
    }
};

// New requirement: Add a Triangle shape
class Shape { // Violation: Modifying the existing class
public:
    virtual double area() const = 0;
};

// Derived class representing a triangle
class Triangle : public Shape { // Violation: Modifying the existing class
private:
    double base;
    double height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override {
        return 0.5 * base * height; // Area of triangle = (base * height) / 2
    }
};

int main() {
    Circle circle(5.0);
    Square square(4.0);
    Triangle triangle(3.0, 4.0); // New shape added

    std::cout << "Area of circle: " << circle.area() << std::endl;
    std::cout << "Area of square: " << square.area() << std::endl;
    std::cout << "Area of triangle: " << triangle.area() << std::endl; // New shape usage

    return 0;
}

/*
In this code:
Initially, the Shape, Circle, and Square classes are defined as before.
Later, we need to add a new shape, Triangle, so we modify the existing Shape
class to remove its hierarchy and add the Triangle class directly. 
This violates the Open/Closed Principle because it requires modifying the existing class.
*/