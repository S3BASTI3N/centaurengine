//
// Created by sebastien on 23-1-16.
//

#include "Include/Intelligence.h"

Intelligence::Intelligence() {

}

Intelligence::Intelligence(std::vector<Decision> decisions, DemoInputModule loadedModules) {
    this->staticDecisions = decisions;
    //TODO order decisions
    this->orderedDecisions = decisions;
    this->modules = loadedModules;
}


/*
 * Calc score of actions and multiply by weight
 * since actions receive a score between 0 and 1, if the weight of this action is less than the current best,
 * calculating the score is not required because it wil always be lower than the current best action
 */
Decision Intelligence::getNextBestDecision(Context context) {
    float score = 0;
    Decision bestDecision;

    std::cout << "-----------------------------" << std::endl;
    std::cout << "Found " << orderedDecisions.size() << " possible decisions/actions" << std::endl;

    for(auto decisionIt = orderedDecisions.begin(); decisionIt != orderedDecisions.end(); ++decisionIt) {
        Decision decision = *decisionIt;

        std::cout << "  scoring " << decision.getName() << std::endl;
        //TODO get weight from consideration
        float weight = 1.0;


        if(weight > score) {
            std::cout << "    -weight bigger than score" << std::endl;
            float currentScore = decision.calculateScore(context, score / weight ) * weight;
            std::cout << "    -score: " << currentScore << std::endl;
            if( currentScore > score ) {
                std::cout << "    - Set new score!" << std::endl;
                score = currentScore;
                bestDecision = decision;
            }
        }
    }
    std::cout << "-----------------------------" << std::endl;

    return bestDecision;
}

