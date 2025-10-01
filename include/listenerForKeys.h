#ifndef PEKERENENE_LISTENERFORKEYS_H
#define PEKERENENE_LISTENERFORKEYS_H
#include "carClass.h"

struct MyListener : threepp::KeyListener {

    MyListener(carClass& ourCar): ourCar(ourCar)
         {}

    void onKeyPressed(threepp::KeyEvent evt) override {
        if (evt.key == threepp::Key::SPACE) {
            ourCar.hop();
        }
    }
    void onKeyRepeat(threepp::KeyEvent evt) override { //Instead of this we can use a toggle.
        //because this is slow
        if (evt.key == threepp::Key::W) {
            ourCar.hop();
        }
    }
private:
    carClass& ourCar;

};


#endif //PEKERENENE_LISTENERFORKEYS_H