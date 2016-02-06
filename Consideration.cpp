//
// Created by sebastien on 23-1-16.
//

#include "Include/Consideration.h"

float Consideration::calculateScore(Context context) {
    //TODO implement curve
    //return 1;
    return functionModule.score(functionName, context);

}

Consideration::Consideration(std::string curveType, std::vector<std::string> curveParams,
                             DemoInputModule functionModule, std::string functionName,
                             std::string inputMin, std::string inputMax) {

    this->functionModule = functionModule;
    this->functionName = functionName;

}
