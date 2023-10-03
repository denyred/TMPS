#include "./controller/controller.h"
#include "./io/scanner.h"
#include "./model/shapes.h"

#include <iostream>
#include <vector>

int main() {
    std::vector<Shape*> shape_repo;
    Scanner* scanner = new ConsoleScanner();

    Controller::get().create_shapes(scanner, shape_repo);
    
    // Shape* clone = shape_repo[0]->clone();

    for(int i = 0; i < shape_repo.size(); i++) {
        std::cout << "Shape " << i + 1 << " - " << shape_repo[i]->className() << " : P = " << shape_repo[i]->calculatePerimeter() << ", A = " << shape_repo[i]->calculateArea() << '\n';
    }

    // std::cout << "Clone - " << clone->className() << " (of shape #1) " << " : P = " << clone->calculatePerimeter() << ", A = " << clone->calculateArea() << '\n';
}
