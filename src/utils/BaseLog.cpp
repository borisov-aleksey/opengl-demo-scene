//
// Created by developer on 17.07.2016.
//

#include "BaseLog.h"
#include <cstdio>
#include <cstring>
#include <stdarg.h>

BaseLog::BaseLog() {
    _lines = new logLine[LOG_SIZE];
    for(int i = 0; i < LOG_SIZE; i++) {
        _lines[i] = new logChar[LOG_LINE_SIZE];
        snprintf(_lines[i], 0, "%s", " ");
    }
}


BaseLog::~BaseLog() {
    for(int i = 0; i < LOG_SIZE; i++) {
        delete[] _lines[i];
    }
    delete[] _lines;
}

void BaseLog::add(logGroup group, char* message) {
    strncpy(_lines[group], message, LOG_LINE_SIZE - 1);
}

void BaseLog::add(logGroup group, double value) {
    snprintf(_lines[group], 9, "%4.4f", value);
}

void BaseLog::add(logGroup group, char* format, ...) {
    va_list args;
    va_start(args,format);
    vsnprintf(_lines[group], LOG_LINE_SIZE - 1, format, args);
    va_end(args);
}

void BaseLog::render() {}

