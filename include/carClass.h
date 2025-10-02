#ifndef PEKERENENE_CARCLASS_H
#define PEKERENENE_CARCLASS_H

class carClass {
    public:
    carClass(const std::shared_ptr<threepp::Mesh>& carMesh): carMesh(carMesh) {}


    void hop() {
        carMesh->position.y+=1;
    }




    private:
    const std::shared_ptr<threepp::Mesh>& carMesh;
    float rightTurn;
    float leftTurn;

};

#endif //PEKERENENE_CARCLASS_H