#ifndef PRACTICE4_DEVICE_H
#define PRACTICE4_DEVICE_H

#include <iostream>

class Device {
protected:
    // получить название типа прибора
    virtual void device_type() = 0;
public:
    // получить данные о приборе
    virtual void poll() = 0;
    // деструктор
    virtual ~Device() = default;
};

#endif //PRACTICE4_DEVICE_H
