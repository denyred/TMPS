/*
    Creational design patterns: singleton - the application needs only one controller, so we hide the instance
    and its controller and provide a global interface to access its functionality.
*/


#include <vector>

#include "../io/scanner.h"
#include "../model/shapes.h"

#pragma once

class Controller {
    private:
        Controller() {}
        static Controller c_instance;

    public:
        static Controller& get() {
            return c_instance;
        }

        void create_shapes(Scanner* scanner, std::vector<Shape*>& shape_repo) {
            for(Shape* shape : scanner->scan_shapes()) {
                shape_repo.push_back(shape);
            }
        }
};

Controller Controller::c_instance;
