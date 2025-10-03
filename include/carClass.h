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

    void accelerate(float amount) {//amout lets us decelarate as well
        speed.z += baseAcceleration*amount * dt*std::cos(carRotation.y);
        speed.x += baseAcceleration*amount * dt*std::sin(carRotation.y); //very happy with this!
    }

    void correctSpeedVector() {//this causes some loss in speed while turning, just keep that in mind.
        double totalSpeed=std::sqrt(speed.x*speed.x + speed.z*speed.z+speed.y*speed.y);
        double movementDirection = (speed.x * std::sin(carRotation.y) + speed.z * std::cos(carRotation.y)) >= 0 ? 1.0 : -1.0; //Kode gitt av Copilot, to fix turning while reversing stopping all momentum
        double newZSpeed=movementDirection*(totalSpeed)*std::cos(carRotation.y);
        double newXSpeed=movementDirection*(totalSpeed)*std::sin(carRotation.y);

        if (momentumKeeping< 0.05) { //Random number; to change for feel in the future
            speed.z=newZSpeed;
            speed.x=newXSpeed;
        }
        else {
            float adjustedMomentum = 1.0 - (1.0 - momentumKeeping) * dt;
            speed.z = speed.z * adjustedMomentum + (1.0 - adjustedMomentum) * newZSpeed;
            speed.x = speed.x * adjustedMomentum + (1.0 - adjustedMomentum) * newXSpeed;

        }

    }

    void act() {
        if (wPressed) {
            this->accelerate(1.0);
        }
        else if (sPressed) {
            this->accelerate(-1.0);
        }
        if (rightTurn) {
            carRotation.y-=basicTurnSpeed*dt;
        }
        else if (leftTurn) {
            carRotation.y+=basicTurnSpeed*dt;
        }

        correctSpeedVector();
        carPos.z += speed.z * dt;
        carPos.x += speed.x * dt;
        carPos.y += speed.y * dt;
    }

    bool wPressed = false;
    bool sPressed = false;
    float momentumKeeping = 0.001;// might allow for drifts burde være under 0.1; mayhaps make it scaling of speed.
    bool isOnIce = false;
    float dt{0};
    coords carPos{0.0, 0.0, 0.0};
    coords carRotation{0.0, std::numbers::pi, 0.0}; //In radians, //so that it starts facing away from us
    bool rightTurn=false;
    bool leftTurn=false;
private:
    float basicTurnSpeed{1.2};
    coords speed{0.0, 0.0, 0.0};
    float baseAcceleration{2};

};

#endif //PEKERENENE_CARCLASS_H
