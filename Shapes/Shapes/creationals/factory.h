/*
    S : ...
    O : ...
    L : Lines 34/36 setBuiler() expects a reference to the TriangleBuilder but gets a reference to a child.
    I : ~
    D : ...

    Creational design patterns: factory - instantiates a shape based on the order details and employs a director,
    through whom it is capable of ordering triangles from the builders.
*/


#include <vector>
#include <iostream>
#include <string>

#include "builder.h"

#pragma once

class Factory {
    private:
        Director* triangle_master;
    
    public:
        Factory() {
            triangle_master = new Director();
        }

        Shape* createShape(const std::string& type, const std::vector<double>& values) {
            if (type == "SQUARE") {
                return new Square(values[0]);
            } else if (type == "TRIANGLE") {
                if (values.size() == 3) {
                    triangle_master->setBuilder(new ArbitraryBuilder());
                } else {
                    triangle_master->setBuilder(new EquilateralBuilder());
                }

                triangle_master->buildTriangle(values);
            } else {
                return nullptr;
            }
            return nullptr;
        }
};
