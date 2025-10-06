#include <fmt/format.h>

#include <queue>
#include <unordered_map>
#include <vector>

/*----------------------------------------------------------------------*/
/*-------------------  Gale Shapely Algorithm  -------------------------*/
/*----------------------------------------------------------------------*/

static void stable_marriage(std::vector<std::vector<int>> menPreferences,
                            std::vector<std::vector<int>> womenPreferences) {
    std::unordered_map<int, int> mensPairing;
    std::unordered_map<int, int> womensPairing;

    std::queue<int> freeMen;

    for (size_t i = 0; i < menPreferences.size(); i++) {
        freeMen.push(i + 1);
    }

    // Track where each man is in his proposal list
    std::vector<size_t> nextProposal(menPreferences.size(), 0);

    while (!freeMen.empty()) {
        auto currMan = freeMen.front();
        freeMen.pop();

        // Get his next preferred woman
        int woman = menPreferences[currMan - 1][nextProposal[currMan - 1]++];

        auto womanPair = womensPairing.find(woman);
        if (womanPair == womensPairing.end()) {
            // Woman is Free
            mensPairing[currMan] = woman;
            womensPairing[woman] = currMan;
        } else {
            // Woman is already paired
            auto engagedMan = womanPair->second;
            bool isStable   = true;
            for (auto man : womenPreferences[woman - 1]) {
                if (man == currMan) {
                    isStable = false;
                    break;
                }
                if (man == engagedMan) {
                    break;
                }
            }
            if (!isStable) {
                // She prefers new man → break engagement
                womensPairing[woman] = currMan;
                mensPairing[currMan] = woman;

                // Old fiancé becomes free again
                mensPairing.erase(engagedMan);
                freeMen.push(engagedMan);
            } else {
                freeMen.push(currMan);
            }
        }
    }

    fmt::print("\nStable Marriage Pairing: \n");
    for (auto it : mensPairing) {
        fmt::print("M{}: W{}\n", it.first, it.second);
    }

    fmt::print("\nStable Marriage Pairing: \n");
    for (auto it : womensPairing) {
        fmt::print("W{}: M{}\n", it.first, it.second);
    }
}

int main(int argc, char* argv[]) {
    // Men’s preferences: men[man][rank] = woman
    std::vector<std::vector<int>> menPreferences = {
        {2, 1, 3, 4},  // M1
        {1, 3, 4, 2},  // M2
        {3, 2, 1, 4},  // M3
        {1, 2, 4, 3}   // M4
    };

    // Women’s preferences: women[woman][rank] = man
    std::vector<std::vector<int>> womenPreferences = {
        {3, 1, 2, 4},  // W1
        {4, 3, 2, 1},  // W2
        {4, 3, 1, 2},  // W3
        {2, 4, 1, 3}   // W4
    };

    // Just print them to verify
    fmt::print("Men's Preferences\n");
    for (size_t i = 0; i < menPreferences.size(); ++i) {
        fmt::print("M{}: ", i + 1);
        for (int w : menPreferences[i]) {
            fmt::print("W{} ", w);
        }
        fmt::print("\n");
    }

    fmt::print("Women's Preferences\n");
    for (size_t i = 0; i < womenPreferences.size(); ++i) {
        fmt::print("W{}: ", i + 1);
        for (int m : womenPreferences[i]) {
            fmt::print("M{} ", m);
        }
        fmt::print("\n");
    }

    stable_marriage(menPreferences, womenPreferences);
    return 0;
}
