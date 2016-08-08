//
// Created by developer on 17.07.2016.
//

#ifndef DEMO_SCENE_BASELOG_H
#define DEMO_SCENE_BASELOG_H

#include <map>
#include <string>

#define LOG_SIZE 3
#define LOG_LINE_SIZE 65536

typedef int logGroup;
typedef char logChar;

const logGroup LOG_DEFAULT = 0;
const logGroup LOG_FPS = 1;
const logGroup LOG_TIMER = 2;

typedef logChar* logLine;

class BaseLog {
protected:
    logLine* _lines;
public:
    BaseLog();
    ~BaseLog();
    void add(logGroup group, char* message);
    void add(logGroup group, double value);
    void add(logGroup group, char* format, ...);
    virtual void render();
};


#endif //DEMO_SCENE_BASELOG_H
