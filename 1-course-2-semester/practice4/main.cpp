#include <iostream>
#include "inc/Devises.h"

int main() {
    setlocale(LC_ALL, "rus"); // вызов функции настройки локали
    Devise* a = new devises::heat_ctrl_blck::OvenТРМ232();
    a->poll();
    delete a;
    return 0;
}
