//
// Created by developer on 17.07.2016.
//

#include "COutLog.h"
#include <iostream>
#include <cstdio>

void COutLog::render() {
    for (int i = 0; i < LOG_SIZE; i ++) {
        printf("%s\n", _lines[i]);
    }
}


