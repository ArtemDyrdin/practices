#ifndef PRACTICE4_DEVISETYPE_H
#define PRACTICE4_DEVISETYPE_H

#include "Devise.h"
#include <iostream>

class ElEnergyMeter : public Devise {
protected:
    void devise_type() override {
        std::cout << "Счетчик электрической энергии: ";
    }
};

class DiscSignInputBlck : public Devise {
protected:
    void devise_type() override {
        std::cout << "Блоки ввода дискретных сигналов: ";
    }
};

class HeatCtrlBlck : public Devise {
protected:
    void devise_type() override {
        std::cout << "Блоки управления отоплением: ";
    }
};

#endif //PRACTICE4_DEVISETYPE_H
