//
// Created by sebastien on 23-1-16.
//

#include "Include/Decision.h"

Decision::Decision() {

}

Decision::Decision(std::string name, std::string description, std::vector<Consideration> considerations) {

    this->considerations = considerations;
    this->name = name;
    this->description = description;

    //TODO order considerations
    this->orderedConsiderations = considerations;
}

/*
 * Loop over all considerations of this action and multiply them to calculate final score
 */
float Decision::calculateScore(Context context, float minScore) {
    float runningScore = 1.0;
    for(auto it = orderedConsiderations.begin(); it != orderedConsiderations.end(); ++it) {
        if(runningScore < minScore) {
            return 0;
        }

        Consideration consideration = *it;
        float score = consideration.calculateScore(context);
        //TODO normalise score
        runningScore = runningScore*score;

    }

    return runningScore;
}


