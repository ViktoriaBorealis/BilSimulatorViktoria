#ifndef PEKERENENE_LISTENERFORKEYS_H
#define PEKERENENE_LISTENERFORKEYS_H
#include "carClass.h"

struct MyListener : threepp::KeyListener {

    MyListener(CarClass& ourCar): ourCar(ourCar)
         {}




    void onKeyPressed(threepp::KeyEvent evt) override {
        if (evt.key == threepp::Key::SPACE) {
            ourCar.momentumKeeping=0.1;
        }

        if (evt.key == threepp::Key::W) {
            ourCar.wPressed=true;
        }
        else if (evt.key == threepp::Key::S) {
            ourCar.sPressed=true;
        }
        if (evt.key == threepp::Key::D) {
            ourCar.rightTurn=true;
        }
        else if (evt.key == threepp::Key::A) {
            ourCar.leftTurn=true;
        }
    }

    void onKeyReleased(threepp::KeyEvent evt) override {
        if (evt.key == threepp::Key::SPACE) {
            ourCar.momentumKeeping=0.001;
        }
        if (evt.key == threepp::Key::W) {
            ourCar.wPressed=false;
        }
        else if (evt.key == threepp::Key::S) {
            ourCar.sPressed=false;
        }

        if (evt.key == threepp::Key::D) {
            ourCar.rightTurn=false;
        }
        else if (evt.key == threepp::Key::A) {
            ourCar.leftTurn=false;
        }

    }

    void giveCarData() {
//pass
    }
private:
    CarClass& ourCar;
//omg branches be hard...
};


#endif //PEKERENENE_LISTENERFORKEYS_H