//
// Created by developer on 17.07.2016.
//

#include "COutLog.h"
#include <iostream>

void COutLog::render() {
    LogIterator it;

    for (it = _data->begin(); it != _data->end(); ++it) {
        std::cout << it->second << std::endl;
    }
}


