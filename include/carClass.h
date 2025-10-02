#ifndef PEKERENENE_CARCLASS_H
#define PEKERENENE_CARCLASS_H
#include <vector>


struct coords {
    double x;
    double y;
    double z;
};

class CarClass {
public:
    CarClass() {}


    void hop() {
    }

    void accelerate() {
        speed.z -= baseAcceleration * dt;
    }

    void act() {
        if (wPressed) {
            this->accelerate();
        }
        carPos.z += speed.z * dt;
        carPos.x += speed.x * dt;
        carPos.y += speed.y * dt;
    }

    bool wPressed = false;
    float dt{0};
    coords carPos{0.0, 0.0, 0.0};
    coords carRotation{0.0, 0.0, 0.0}; //In radians
private:
    coords speed{0.0, 0.0, 0.0};
    float baseAcceleration{1.5};

    //std::vector<float> carRotation{0.0,0.0,0.0};
    float rightTurn;
    float leftTurn;
};

#endif //PEKERENENE_CARCLASS_H
