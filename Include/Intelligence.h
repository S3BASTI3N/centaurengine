//
// Created by sebastien on 23-1-16.
//

#pragma once


#include <vector>
#include <iostream>

#include "Decision.h"


const int MAX_SCORE = 5;


class Intelligence {

public:
    Intelligence();

    Intelligence(std::vector<Decision> decisions, DemoInputModule loadedModules);

    Decision getNextBestDecision(Context context);

private:
    std::vector<Decision> staticDecisions;
    std::vector<Decision> tempDecisions;
    std::vector<Decision> orderedDecisions;
    std::vector<float> orderedWeights;

    DemoInputModule modules;
};
