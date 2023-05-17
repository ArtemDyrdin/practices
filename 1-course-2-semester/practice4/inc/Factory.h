#ifndef PRACTICE4_FACTORY_H
#define PRACTICE4_FACTORY_H
#include "Devices.h"

// функция определения нужного объекта
Device* Factory(std::string& word) {
    Device* model = nullptr;
    const int cols = 3; // макс кол-во приборов одного типа
    std::string models[3][cols] = {{"Меркурий 230", "Нева МТ314", "Энергомера CE308"},
                                   {"Reallab NL-16HV", "Приборэлектро PRE-16", "Энергосервис ЭНМВ-1-24"},
                                   {"Ouman S203", "Овен ТРМ232"}};

    // определение соответствующего объекта
    if (word == models[0][0])
        model = new el_energy_meter::Mercury230();
    else if (word == models[0][1])
        model = new el_energy_meter::NevaMT314();
    else if (word == models[0][2])
        model = new el_energy_meter::EnergomeraCE308();
    else if (word == models[1][0])
        model = new disc_input_blck::ReallabNL16HV();
    else if (word == models[1][1])
        model = new disc_input_blck::PriborelectroPRE16();
    else if (word == models[1][2])
        model = new disc_input_blck::EnergoservisENMV124();
    else if (word == models[2][0])
        model = new heat_ctrl_blck::OumanS203();
    else if (word == models[2][1])
        model = new heat_ctrl_blck::OvenTPM232();

    return model;
}

#endif //PRACTICE4_FACTORY_H
