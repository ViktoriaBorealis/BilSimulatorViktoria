#include "threepp/threepp.hpp"


#include "listenerForKeys.h"
#include "carClass.h"
#include <iostream>
#include <numbers>
using namespace threepp;



int main() {
    Canvas canvas;
    Scene scene;
    GLRenderer renderer(canvas.size());
    PerspectiveCamera camera(60,canvas.aspect(),0.1,1000); //test changing variables, to understand what they do. they might also make a good speedboost visual..

    canvas.onWindowResize([&](WindowSize size) {
                camera.aspect = size.aspect();
                camera.updateProjectionMatrix();
                renderer.setSize(size);
            });

    auto grid = GridHelper::create(20, 10, Color::yellowgreen);
    grid->position.y-=0.5;
    scene.add(grid);

    auto basicGeometry = BoxGeometry::create(1,1,2); //Top down game? nope, skal være 3d
    auto basicMaterial = MeshBasicMaterial::create();
    basicMaterial->color = Color::white;
    auto carMesh = Mesh::create(basicGeometry,basicMaterial);
    scene.add(carMesh);
    camera.position.z=5;
    camera.position.y=1.5;

    CarClass ourCar;
    auto keyController = std::make_unique<MyListener>(ourCar);
    canvas.addKeyListener(*keyController);
    Clock clock;

    canvas.animate([&] {
        const auto dt = clock.getDelta(); //Kode fra youbot
        renderer.render(scene, camera);

        ourCar.dt=dt;
        ourCar.act();

        carMesh->rotation.set(ourCar.carRotation.x,ourCar.carRotation.y,ourCar.carRotation.z);
        carMesh->position.set(ourCar.carPos.x,ourCar.carPos.y,ourCar.carPos.z);

        camera.position.set(ourCar.carPos.x,ourCar.carPos.y,ourCar.carPos.z); //Todo make it so that it follows car
        camera.rotation.set(ourCar.carRotation.x,ourCar.carRotation.y,ourCar.carRotation.z); //Todo make it so that it's not the wrong way...d
    });

    return 0;
}