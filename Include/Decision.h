//
// Created by sebastien on 23-1-16.
//

#ifndef CENTAURENGINE_ACTION_H
#define CENTAURENGINE_ACTION_H

#include <vector>
#include <string>

#include "../Include/Context.h"
#include "../Include/Consideration.h"


class Decision {

public:
    Decision();

    Decision( std::string name,
              std::string description,
              std::vector<Consideration> considerations );

    float calculateScore( Context context, float minScore );

    std::vector<Consideration> &getOrderedConsiderations() {
        return orderedConsiderations;
    }

    std::vector<Consideration> &getConsiderations() {
        return considerations;
    }

    std::string getName() {
        return name;
    }

    std::string getDesciption() {
        return description;
    }

private:
    std::vector<Consideration> considerations;
    std::vector<Consideration> orderedConsiderations;
    std::string name;
    std::string description;

};


#endif //CENTAURENGINE_ACTION_H
