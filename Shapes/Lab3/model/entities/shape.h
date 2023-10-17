#include <iostream>
#include <vector>

#include "color.h"
#include "image.h"

#pragma once

class Shape : public Figure {
    virtual std::vector<double> getCoords() = 0;
    virtual void setCoords(std::vector<double>) = 0;

    virtual double getParam() = 0;
    virtual void setParam(double) = 0;

    int count() { return 1; }
};

class ColoredShape {
    private:
        Color* color;

    public:
        ColoredShape() {}
        ColoredShape(Color* color_to_set) : color(color_to_set) {}

        void setColor(Color* new_color) { color = new_color; }
        std::string getColor() { return color->getColor(); }
};

class Square : public Shape {
    private:
        double x, y;
        double width;

    public:
        Square() {}
        Square(std::vector<double> coords, double width) : x(coords[0]), y(coords[1]), width(width) {}

        std::vector<double> getCoords() override { return std::vector<double>{x, y}; }
        void setCoords(std::vector<double> new_coords) override { x, y = new_coords[0], new_coords[1]; }

        double getParam() override { return width; }
        void setParam(double new_val) override { width = new_val; }

        void render(std::vector<double> origin, int shift) override {
            std::cout << "Rendering a plain square of width " << width << " at <" << origin[0] + x << ", " << origin[1] + y << "> ... DONE" << '\n';
        }
};

class ColoredSquare : public Square, public ColoredShape {
    public:
        ColoredSquare() {}
        ColoredSquare(std::vector<double> coords, double width, Color* color_to_set) : Square(coords, width), ColoredShape(color_to_set) {}

        void render(std::vector<double> origin, int shift) override {
            std::cout << "Rendering a " << this->getColor() << " square of width " << this->getParam() << " at <" << origin[0] + this->getCoords()[0] << ", " << origin[1] + this->getCoords()[1] << "> ... DONE" << '\n';
        }
};

class Circle : public Shape {
    private:
        double x, y;
        double radius;

    public:
        Circle() {}
        Circle(std::vector<double> coords, double radius) : x(coords[0]), y(coords[1]), radius(radius) {}

        std::vector<double> getCoords() override { return std::vector<double>{x, y}; }
        void setCoords(std::vector<double> new_coords) override { x, y = new_coords[0], new_coords[1]; }

        double getParam() override { return radius; }
        void setParam(double new_val) override { radius = new_val; }

        void render(std::vector<double> origin, int shift) override {
            std::cout << "Rendering a plain circle of radius " << radius << " at <" << origin[0] + x << ", " << origin[1] + y << "> ... DONE" << '\n';
        }
};

class ColoredCircle : public Circle, public ColoredShape {
    public:
        ColoredCircle() {}
        ColoredCircle(std::vector<double> coords, double radius, Color* color_to_set) : Circle(coords, radius), ColoredShape(color_to_set) {}

        void render(std::vector<double> origin, int shift) override {
            std::cout << "Rendering a " << this->getColor() << " circle of radius " << this->getParam() << " at <" << origin[0] + this->getCoords()[0] << ", " << origin[1] + this->getCoords()[1] << "> ... DONE" << '\n';
        }
};