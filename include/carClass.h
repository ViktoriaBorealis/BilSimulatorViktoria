#ifndef PEKERENENE_CARCLASS_H
#define PEKERENENE_CARCLASS_H
#include <vector>
#include <math.h>

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
        speed.z += baseAcceleration * dt*std::cos(carRotation.y);
        speed.x += baseAcceleration * dt*std::sin(carRotation.y); //very happy with this!
    }

    void correctSpeedVector() {
        double totalSpeed=speed.z+speed.x+speed.y;
        speed.z=totalSpeed*std::cos(carRotation.y);
        speed.x=totalSpeed*std::sin(carRotation.y);
    }

    void act() {
        if (wPressed) {
            this->accelerate();
        }
        if (rightTurn) {
            carRotation.y-=basicTurnSpeed*dt;
        }
        else if (leftTurn) {
            carRotation.y+=basicTurnSpeed*dt;
        }
        if (not isOnIce) {
            correctSpeedVector();
        }
        carPos.z += speed.z * dt;
        carPos.x += speed.x * dt;
        carPos.y += speed.y * dt;
    }

    bool wPressed = false;
    bool isOnIce = true;
    float dt{0};
    coords carPos{0.0, 0.0, 0.0};
    coords carRotation{0.0, 0.0, 0.0}; //In radians
    bool rightTurn=false;
    bool leftTurn=false;
private:
    float basicTurnSpeed{0.8};
    coords speed{0.0, 0.0, 0.0};
    float baseAcceleration{1.5};

    //std::vector<float> carRotation{0.0,0.0,0.0};

};

#endif //PEKERENENE_CARCLASS_H
