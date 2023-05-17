#ifndef PRACTICE4_DEVICES_H
#define PRACTICE4_DEVICES_H

#include "DeviceType.h"

// Счетчики электрической энергии
namespace el_energy_meter {
    // Меркурий 230
    class Mercury230 : public ElEnergyMeter {
    public:
        void poll() override {
            ElEnergyMeter::device_type(); // вывод типа прибора
            std::cout << "Меркурий 230" << std::endl;
            // некоторая реализация полученных данных
        }
    };

    // Нева MT314
    class NevaMT314 : public ElEnergyMeter {
    public:
        void poll() override {
            ElEnergyMeter::device_type(); // вывод типа прибора
            std::cout << "Нева MT314" << std::endl;
            // некоторая реализация полученных данных
        }
    };

    // Энергомера CE308
    class EnergomeraCE308 : public ElEnergyMeter {
    public:
        void poll() override {
            ElEnergyMeter::device_type(); // вывод типа прибора
            std::cout << "Энергомера CE308" << std::endl;
            // некоторая реализация полученных данных
        }
    };
}

// Блоки ввода дискретных сигналов
namespace disc_input_blck {
    // Reallab NL-16HV
    class ReallabNL16HV : public DiscInputBlck {
    public:
        void poll() override {
            DiscInputBlck::device_type(); // вывод типа прибора
            std::cout << "Reallab NL-16HV" << std::endl;
            // некоторая реализация полученных данных
        }
    };

    // Приборэлектро PRE-16
    class PriborelectroPRE16 : public DiscInputBlck {
    public:
        void poll() override {
            DiscInputBlck::device_type(); // вывод типа прибора
            std::cout << "Приборэлектро PRE-16" << std::endl;
            // некоторая реализация полученных данных
        }
    };

    // Энергосервис ЭНМВ-1-24
    class EnergoservisENMV124 : public DiscInputBlck {
    public:
        void poll() override {
            DiscInputBlck::device_type(); // вывод типа прибора
            std::cout << "Энергосервис ЭНМВ-1-24" << std::endl;
            // некоторая реализация полученных данных
        }
    };
}

// Блоки управления отоплением
namespace heat_ctrl_blck {
    // Ouman S203
    class OumanS203 : public HeatCtrlBlck {
    public:
        void poll() override {
            HeatCtrlBlck::device_type(); // вывод типа прибора
            std::cout << "Ouman S203" << std::endl;
            // некоторая реализация полученных данных
        }
    };

    // Овен ТРМ232
    class OvenTPM232 : public HeatCtrlBlck {
    public:
        void poll() override {
            HeatCtrlBlck::device_type(); // вывод типа прибора
            std::cout << "Овен ТРМ232" << std::endl;
            // некоторая реализация полученных данных
        }
    };
}

#endif //PRACTICE4_DEVICES_H
