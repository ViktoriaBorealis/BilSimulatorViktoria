#include "threepp/threepp.hpp"
#include <vector>
#include <math.h>

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

    auto basicGeometry = BoxGeometry::create(1,1,2); //Top down game?
    auto basicMaterial = MeshBasicMaterial::create();
    basicMaterial->color = Color::white;
    auto carMesh = Mesh::create(basicGeometry,basicMaterial);
    scene.add(carMesh);
    camera.position.z=5;
    camera.position.y=1.5;



    canvas.animate([&]{
        renderer.render(scene, camera);
    });

    return 0;
}