#include <iostream>
#include <vector>

#pragma once

class Figure {
    public:
        virtual void add(Figure* new_fig) { return; }
        virtual void render(std::vector<double>, int) = 0;
        virtual int count() = 0; 
};

class Image : public Figure {
    private:
        double x, y;
        std::vector<Figure*> contents;

    public:
        std::vector<double> getCoords() { return std::vector<double>{x, y}; }
        void setCoords(std::vector<double> new_coords) { 
            x = new_coords[0]; 
            y = new_coords[1]; 
        }

        void add(Figure* new_fig) { contents.push_back(new_fig); }
        std::vector<Figure*> getContents() { return contents; }

        void render(std::vector<double> origin, int shift) {
            std::cout << "Rendering an image <" << origin[0] + this->getCoords()[0] << ", " << origin[1] + this->getCoords()[1] << "> :" << '\n';

            for (Figure* fig : this->getContents()) {
                for (int i = 0; i < shift; i++) { std::cout << ' '; }
                fig->render(std::vector<double>{origin[0] + x, origin[1] + y}, shift + 3);
            }
        }

        int count() {
            int total = 0;

            for (Figure* fig : this->getContents()) {
                total += fig->count();
            }

            return total;
        }
};

class RenderProxy : public Image {
    private:
        Image* real_image;

    public:
        RenderProxy(Image* img) : real_image(img) {}

        void render(std::vector<double> origin, int shift) override {
            std::cout << "Proxy rendering - ";
            std::cout << real_image->count() << " shapes will be rendered ..." << '\n';
            real_image->render(origin, shift);
        }
};
