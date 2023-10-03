/*
    S : ...
    O : ...
    L : ~
    I : The application may implement only the functionality it needs, either scanning from the terminal or scanning from a file.
    D : ...
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../model/shapes.h"
#include "../creationals/factory.h"

#pragma once

class Utility {
    public:
        static std::vector<std::string> separate_tokens(const std::string& line, const char& separator) {
            std::istringstream iss(line);
            std::vector<std::string> tokens;

            std::string token;
            while (std::getline(iss, token, separator)) {
                tokens.push_back(token);
            }

            return tokens;
        }
};

class Scanner {
    public:
        virtual std::vector<Shape*> scan_shapes() = 0;
};

class ConsoleScanner : public Scanner {
    public:
        std::vector<Shape*> scan_shapes() override {
            std::vector<Shape*> shapes;
            Factory* factory = new Factory();

            int n;

            std::cout << "How many shapes would you like to create? - ";
            std::cin >> n;

            std::cout << "Insert " << n << " lines in the following format - TYPE|a|b|c ..." << '\n';
            std::cout << "* Leave a only for square or equilateral triangle * :" << '\n';
            
            for (int i = 0; i < n; i++) {
                std::string line;
                std::cin >> line;

                std::vector<std::string> tokens = Utility::separate_tokens(line, '|');
                std::vector<double> values;

                for (int j = 1; j < tokens.size(); j++) {
                    values.push_back(std::stod(tokens[j]));
                }

                Shape* new_shape = factory->createShape(tokens[0], values);

                if (new_shape == nullptr) {
                    shapes.push_back(factory->createShape(tokens[0], values));
                } else {
                    std::cout << "ERROR: Some error with the shape - " << line << '\n';
                }
            }

            return shapes;
        }
};

class FileScanner : public Scanner {
    public:
        std::vector<Shape*> scan_shapes() override {
            std::vector<Shape*> shapes;
            Factory* factory = new Factory();

            std::string filename;

            std::cout << "What is the name of the file from the input folder to read? - ";
            std::cin >> filename;

            std::ifstream file("./" + filename);

            if (file.is_open()) {
                std::string line;
                std::getline(file, line);

                int n = std::stoi(line);
            
                for (int i = 0; i < n; i++) {
                    std::getline(file, line);

                    std::vector<std::string> tokens = Utility::separate_tokens(line, '|');
                    std::vector<double> values;

                    for (int j = 1; j < tokens.size(); j++) {
                        values.push_back(std::stod(tokens[j]));
                    }

                    Shape* new_shape = factory->createShape(tokens[0], values);

                    if (new_shape != nullptr) {
                        shapes.push_back(factory->createShape(tokens[0], values));
                    } else {
                        std::cout << "ERROR: Some error with the shape - " << line << '\n';
                    }
                }

                file.close();
            } else {
                std::cout << "ERROR: File not found!" << '\n';
            }

            return shapes;
        }
};
