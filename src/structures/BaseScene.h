//
// Created by ebolgov on 08.08.16.
//

#ifndef DEMO_SCENE_BASESCENE_H
#define DEMO_SCENE_BASESCENE_H


class BaseScene {
public:
    virtual void render();
    virtual void tick(double dt);
};


#endif //DEMO_SCENE_BASESCENE_H
