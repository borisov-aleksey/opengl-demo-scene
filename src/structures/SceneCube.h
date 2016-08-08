//
// Created by ebolgov on 08.08.16.
//

#ifndef DEMO_SCENE_SCENECUBE_H
#define DEMO_SCENE_SCENECUBE_H

#include "BaseScene.h"

class SceneCube: public BaseScene {
private:
    float xrf, yrf, zrf;
public:
    SceneCube();
    ~SceneCube();
    void render();
    void tick(double dt);
};


#endif //DEMO_SCENE_SCENECUBE_H
