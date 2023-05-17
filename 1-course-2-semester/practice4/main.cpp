#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "inc/Factory.h"

int main() {
    std::vector<Device*> models; // динамический массив объектов приборов
    // заполнение массива соответствующими объектами
    std::ifstream in("Models.txt", std::ios::in);
    while (!in.eof()) {
        std::string model;
        std::getline(in, model);
        models.push_back(Factory(model));
    }

    // вывод данных приборов
    for (auto & model : models)
        model->poll();

    return 0;
}
