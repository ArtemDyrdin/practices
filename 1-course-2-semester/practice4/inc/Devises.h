#ifndef PRACTICE4_DEVISES_H
#define PRACTICE4_DEVISES_H

#include "DeviseType.h"

namespace devises {
    // Счетчики электрической энергии
    namespace el_energy_meter {
        class Mercury230 : public ElEnergyMeter {
        public:
            void poll() override {
                ElEnergyMeter::devise_type(); // вывод типа прибора
                std::cout << "Меркурий 230" << std::endl;
            }
        };

        class NevaМТ314 : public ElEnergyMeter {
        public:
            void poll() override {
                ElEnergyMeter::devise_type(); // вывод типа прибора
                std::cout << "Нева MT314" << std::endl;
            }
        };

        class EnergomeraCE308 : public ElEnergyMeter {
        public:
            void poll() override {
                ElEnergyMeter::devise_type(); // вывод типа прибора
                std::cout << "Энергомера CE308" << std::endl;
            }
        };
    }

    // Блоки ввода дискретных сигналов
    namespace disc_sign_input_blck {
        class ReallabNL16HV : public DiscSignInputBlck {
        public:
            void poll() override {
                DiscSignInputBlck::devise_type(); // вывод типа прибора
                std::cout << "Reallab NL-16HV" << std::endl;
            }
        };

        class PriborelectroPRE16 : public DiscSignInputBlck {
        public:
            void poll() override {
                DiscSignInputBlck::devise_type(); // вывод типа прибора
                std::cout << "Приборэлектро PRE-16" << std::endl;
            }
        };

        class EnergoservisENMV124 : public DiscSignInputBlck {
        public:
            void poll() override {
                DiscSignInputBlck::devise_type(); // вывод типа прибора
                std::cout << "Энергосервис ЭНМВ-1-24" << std::endl;
            }
        };
    }

    // Блоки управления отоплением
    namespace heat_ctrl_blck {
        class OumanS203 : public HeatCtrlBlck {
        public:
            void poll() override {
                HeatCtrlBlck::devise_type(); // вывод типа прибора
                std::cout << "Ouman S203" << std::endl;
            }
        };

        class OvenТРМ232 : public HeatCtrlBlck {
        public:
            void poll() override {
                HeatCtrlBlck::devise_type(); // вывод типа прибора
                std::cout << "Овен ТРМ232" << std::endl;
            }
        };
    }
}

#endif //PRACTICE4_DEVISES_H
