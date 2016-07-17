//
// Created by developer on 17.07.2016.
//

#include "BaseLog.h"
#include <iostream>
#include <cstdio>

BaseLog::BaseLog() {
    _data = new LogMap;
}

void BaseLog::add(logGroup group, std::string message) {
    LogIterator li = _data->find(group);
    if (li != _data->end()) {
        _data->erase(li);
    }

    (*_data)[group] = message;
}

void BaseLog::add(logGroup group, double value) {
    char buffer[10];
    snprintf(buffer, 9, "%4.4f", value);
    (*_data)[group] = std::string(buffer);
}

void BaseLog::render() {}

