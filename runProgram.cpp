#include "threepp/threepp.hpp"
#include <vector>
#include <math.h>
#include "listenerForKeys.h"

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

    auto basicGeometry = BoxGeometry::create(1,1,2); //Top down game? nope, skal være 3d
    auto basicMaterial = MeshBasicMaterial::create();
    basicMaterial->color = Color::white;
    auto carMesh = Mesh::create(basicGeometry,basicMaterial);
    scene.add(carMesh);
    camera.position.z=5;
    camera.position.y=1.5;


    auto keyController = std::make_unique<MyListener>(carMesh);
    canvas.addKeyListener(*keyController);
    canvas.animate([&]{
        renderer.render(scene, camera);
    });

    return 0;
}