/*
    S : Instantiation of the triangles of various complexity;
    O : Add more builders to increase the variety;
    L : ~
    I : ~
    D : The TriangleBuilder abstraction is a universal interface through which any type of worker can be acessed.

    Creational design patterns: builder - create objects (triangles) of various complexity (equilateral and arbitrary) using same abstraction;
    the EquilateralBuilder assigns the same length to all sides during EquilateralBuilder::setSides(), while the ArbitraryBuilder is capable of assigning
    three different and is capable of checking if the request triangle is valid - ArbitraryBuilder::checkSides(); the services of these builders
    are accessed through a single abstraction - the Director, through which the order for the product is placed.
*/


#include <vector>
#include <iostream>

#include "../model/shapes.h"

#pragma once

class TriangleBuilder {
    public:
        virtual void reset() = 0;
        virtual Triangle* getProduct() = 0;

        virtual bool checkSides(const std::vector<double>&) = 0;
        virtual void setSides(const std::vector<double>&) = 0;
};

class EquilateralBuilder : public TriangleBuilder {
    private:
        Triangle* product;

    public:
        void reset() override { product = new Triangle(); }
        Triangle* getProduct() override { return product; }

        bool checkSides(const std::vector<double>& values) override {
            return true;
        }

        void setSides(const std::vector<double>& values) override {
            product->setParameter("a", values[0]);
            product->setParameter("b", values[0]);
            product->setParameter("c", values[0]);
        }
};

class ArbitraryBuilder : public TriangleBuilder {
    private:
        Triangle* product;

    public:
        void reset() override { product = new Triangle(); }
        Triangle* getProduct() override { return product; }

        bool checkSides(const std::vector<double>& values) override {
            if (
                values[0] + values[1] > values[2] &&
                values[1] + values[2] > values[0] &&
                values[0] + values[2] > values[1]
            ) {
                return true;
            } else {
                return false;
            }
        }

        void setSides(const std::vector<double>& values) override {
            product->setParameter("a", values[0]);
            product->setParameter("b", values[1]);
            product->setParameter("c", values[2]);
        }
};

class Director {
    private:
        TriangleBuilder* builder;

        public:
            void setBuilder(TriangleBuilder* new_builder) { builder = new_builder; }

            Triangle* buildTriangle(const std::vector<double>& values) {
                if (builder->checkSides(values)) {
                    builder->reset();
                    builder->setSides(values);
                    return builder->getProduct();
                } else {
                    // std::cout << "ERROR: There is some issue with the lenghts of the sides!" << '\n';
                    return nullptr;
                }
            }
};
