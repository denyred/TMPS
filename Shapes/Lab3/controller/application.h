#include "../model/entities/image.h"
#include "../model/entities/shape.h"
#include "../model/entities/color.h"

class Application {
    public:
        static void basicTest() {
            Image* main_img = new Image();
            main_img->setCoords(std::vector<double>{0.0, 0.0});

            Image* in_img = new Image();
            in_img->setCoords(std::vector<double>{3.0, 3.0});

            in_img->add(new ColoredSquare(std::vector<double>{1.0, 1.0}, 1.0, new RedColor()));
            in_img->add(new ColoredCircle(std::vector<double>{2.0, 2.0}, 1.0, new BlueColor()));

            main_img->add(in_img);
            main_img->add(new Square(std::vector<double>{0.0, 0.0}, 1.0));

            main_img->render(std::vector<double> {0, 0}, 3);

            RenderProxy* proxy = new RenderProxy(main_img);
            proxy->render(std::vector<double> {0, 0}, 3);
        }
};