//
// Created by developer on 17.07.2016.
//

#ifndef DEMO_SCENE_BASELOG_H
#define DEMO_SCENE_BASELOG_H

#include <map>
#include <string>

typedef int logGroup;

const logGroup LOG_DEFAULT = 0;
const logGroup LOG_FPS = 1;
const logGroup LOG_TIMER = 2;

typedef std::map<logGroup, std::string> LogMap;
typedef std::pair<logGroup, std::string> LogValue;
typedef std::map<logGroup, std::string>::iterator LogIterator;

class BaseLog {
protected:
    LogMap* _data;
public:
    BaseLog();
    void add(logGroup group, std::string message);
    void add(logGroup group, double value);
    virtual void render();
};


#endif //DEMO_SCENE_BASELOG_H
