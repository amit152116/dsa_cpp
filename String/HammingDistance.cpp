#include <bits/stdc++.h>

/*
 * Hamming Distance
 * ----------------
 * Definition:
 *   Counts the number of positions where two equal-length strings differ.
 *
 * Allowed Operations:
 *   - Substitution only (no insertion or deletion).
 *   - Strings must be of equal length.
 *
 * Formula:
 *   hamming(a, b) = count(i where a[i] != b[i])
 *
 * Complexity:
 *   Time: O(n)
 *   Space: O(1)
 *
 * Example:
 *   hamming("karolin", "kathrin") = 3
 *   (positions 3, 4, 6 differ)
 *
 * Use Cases:
 *   1. **Error detection in coding theory**
 *      - Used to detect the number of bit errors in transmitted messages.
 *      - Example: In digital communication, comparing sent vs received binary
 *      strings.
 *
 *   2. **DNA and bioinformatics**
 *      - Used to measure similarity between two DNA sequences of equal length.
 *
 *   3. **Cryptography / Security**
 *      - Used to measure difference between hash outputs (e.g., Avalanche
 *      effect).
 *
 *   4. **Information retrieval / Machine learning**
 *      - Used as a distance metric for binary feature vectors.
 *
 * Comparison:
 *   - Much faster but less flexible than Levenshtein.
 *   - Not usable when strings are of different lengths.
 */
int hamming(const std::string& a, const std::string& b) {
    if (a.size() != b.size())
        throw std::invalid_argument("Strings must be equal length");

    int dist = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i])
            ++dist;
    }
    return dist;
}

int main(int argc, char* argv[]) {
    return 0;
}
