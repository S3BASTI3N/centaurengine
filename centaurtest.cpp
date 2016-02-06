#include <iostream>

#include "Include/Context.h"
#include "Include/IntelligenceLoader.h"

class CentaurTest {

public:

    CentaurTest(const char** argv) {
        std::string runningDirectory = argv[0];

        std::cout << "init tests" << std::endl;

        // Init context
        std::cout << "Init Context" << std::endl;
        Context context = Context();

        // Init context
        std::cout << "Loading Intelligence" << std::endl;
        IntelligenceLoader intelLoader = IntelligenceLoader();

        Intelligence intelligence = intelLoader.getIntelligence();

        std::cout << "Getting next action" << std::endl;
        Decision bestDecision = intelligence.getNextBestDecision(context);


        std::cout << "Next bestDecision: " << bestDecision.getName() << std::endl;


        std::cout << "Done testing" << std::endl;

    }

};

int main(int argc, const char** argv) {
    std::cout << "Creating test Intelligence object" << std::endl;

    CentaurTest tester = CentaurTest(argv);

    return -1;
}