#ifndef PEKERENENE_LISTENERFORKEYS_H
#define PEKERENENE_LISTENERFORKEYS_H
#include "carClass.h"

struct MyListener : threepp::KeyListener {

    MyListener(carClass& ourCar): ourCar(ourCar)
         {}
    //why doesnt this get uploaded to github?

    void onKeyPressed(threepp::KeyEvent evt) override {
        if (evt.key == threepp::Key::SPACE) {
            ourCar.hop();
        }
    }
private:
    carClass& ourCar;

};


#endif //PEKERENENE_LISTENERFORKEYS_H