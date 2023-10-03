/*
    S : The function of these entities is to store all the data related to the shapes;
    O : Extend the functionality of the application by adding new shapes implementing the base abstraction to infinity;
    L : ~
    I : ~
    D : The Shape abstraction is a universal interface through which any method in the application may access the functionality of various shapes.

    Creational design patterns: prototype - freely clone the object without acess to the private field usign the Shape::clone()
*/


#include <string>
#include <cmath>

#pragma once

class Shape {
    public:
        virtual double calculateArea() = 0;
        virtual double calculatePerimeter() = 0;
        
        template <typename T>
        void setParameter(const std::string& field_name, const T& value) {}

        virtual std::string className() { return "Shape"; }

        virtual Shape* clone() = 0;
};

class Square : public Shape {
    private:
        double a;

    public:
        Square(const double& side_len) : a(side_len) {}

        double calculateArea() override { return a * a; }
        double calculatePerimeter() override { return 4 * a; }

        template <typename T>
        void setParameter(const std::string& field_name, const T& value) {
            if (field_name == "a") {
                a = value;
            } else {
                std::cout << "ERROR: Square::" << field_name << " is not defined!" << '\n';
            }
        }

        virtual std::string className() override { return "Square"; }

        Shape* clone() override { return new Square(*this); }
};

class Triangle : public Shape {
    private:
        double a, b, c;

    public:
        double calculateArea() override {
            double s = (a + b + c) / 2.0;
            return sqrt(s * (s - a) * (s - b) * (s - c));
        }

        double calculatePerimeter() override { return a + b + c; }

        template <typename T>
        void setParameter(const std::string& field_name, const T& value) {
            if (field_name == "a") {
                a = value;
            } else if (field_name == "b") {
                b = value;
            } else if (field_name == "c") {
                c = value;
            } else {
                std::cout << "ERROR: Square::" << field_name << " is not defined!" << '\n';
            }
        }

        virtual std::string className() override { return "Triangle"; }

        Shape* clone() override { return new Triangle(*this); }
};
