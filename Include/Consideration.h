//
// Created by sebastien on 23-1-16.
//

#ifndef CENTAURENGINE_CONSIDERATION_H
#define CENTAURENGINE_CONSIDERATION_H

#include <iostream>
#include <string>
#include <vector>

#include "../Include/Context.h"
#include "../Modules/DemoInputModule.h"

/*
 * curve type, curve params, input, input limits
 */


class Consideration {

public:
    Consideration( std::string curveType,
                   std::vector<std::string> curveParams,
                   DemoInputModule functionModule,
                   std::string functionName,
                   std::string inputMin,
                   std::string inputMax );
    float calculateScore(Context context);

private:

    DemoInputModule functionModule;
    std::string functionName;


};


#endif //CENTAURENGINE_CONSIDERATION_H
