#ifndef PRACTICE4_DEVISE_H
#define PRACTICE4_DEVISE_H


class Devise {
private:
    // получить данные о типе прибора
    virtual void devise_type() = 0;

public:
    // получить данные о приборе
    virtual void poll() = 0;
};

#endif //PRACTICE4_DEVISE_H
