#ifndef PRACTICE4_DEVICETYPE_H
#define PRACTICE4_DEVICETYPE_H

#include "Device.h"

// тип прибора - счетчик эл. энергии
class ElEnergyMeter : public Device {
protected:
    void device_type() override {
        std::cout << "Счетчик электро-энергии: ";
    }
};

// тип прибора - блок ввода дискретных сигналов
class DiscInputBlck : public Device {
protected:
    void device_type() override {
        std::cout << "Блок ввода дискретных сигналов: ";
    }
};

// тип прибора - блок управления отоплением
class HeatCtrlBlck : public Device {
protected:
    void device_type() override {
        std::cout << "Блок управления отоплением: ";
    }
};

#endif //PRACTICE4_DEVICETYPE_H
