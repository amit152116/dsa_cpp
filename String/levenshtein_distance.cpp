#include <bits/stdc++.h>
#include <fmt/format.h>
#include <fmt/ranges.h>

std::vector<std::vector<int>> dp;

/*
 * Levenshtein Distance (Recursive + Memoization)
 * ----------------------------------------------
 * Definition:
 *   - Minimum number of operations to convert string a → b.
 *   - Allowed operations:
 *        1. Substitution
 *        2. Insertion
 *        3. Deletion
 *
 * Recurrence:
 *   - If characters match → skip (no cost).
 *   - Otherwise → 1 + min(substitute, insert, delete).
 *
 * Complexity:
 *   Time: O(n * m)
 *   Space: O(n * m) (can optimize to O(min(n,m)))
 *
 * Example:
 *   levenshtein("kitten", "sitting") = 3
 *   ("kitten" → "sitten" → "sittin" → "sitting")
 *
 * Common Use Cases:
 *   1. **Spell checking / Auto-correct**
 *      - Find closest dictionary word to a misspelled input.
 *
 *   2. **Search engines & fuzzy matching**
 *      - Rank results by similarity to query (e.g., "kitten" vs "sitten").
 *
 *   3. **Natural Language Processing (NLP)**
 *      - Measure similarity between words/sentences.
 *
 *   4. **DNA/Bioinformatics**
 *      - Compare gene sequences where insertions/deletions/substitutions occur.
 *
 *   5. **Plagiarism detection / Version control**
 *      - Quantify how much two strings/documents differ.
 *
 * Comparison:
 *   - More general than Hamming (handles insertions/deletions).
 *   - Less powerful than Damerau–Levenshtein (no transpositions).
 */
int levenshtein(const std::string& a, const std::string& b, size_t i = 0,
                size_t j = 0) {
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == a.size())
        return dp[i][j] = b.size() - j;  // insert remaining b
    if (j == b.size())
        return dp[i][j] = a.size() - i;  // delete remaining a

    if (a[i] == b[j]) {
        return dp[i][j] = levenshtein(a, b, i + 1, j + 1);
    }

    return dp[i][j] = 1 + std::min({
                              levenshtein(a, b, i + 1, j + 1),  // substitution
                              levenshtein(a, b, i, j + 1),      // insertion
                              levenshtein(a, b, i + 1, j)       // deletion
                          });
}

int levenshtein_iter(const std::string& a, const std::string& b) {
    int m = a.size(), n = b.size();

    // Initialize base cases
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + std::min({dp[i - 1][j - 1],  // substitution
                                         dp[i][j - 1],      // insertion
                                         dp[i - 1][j]});    // deletion
        }
    }
    return dp[m][n];
}

void print_dp(const std::string& a, const std::string& b, int distance) {
    int m, n;
    m = a.size();
    n = b.size();

    // Print top header
    fmt::print("\n    {:>3}", " ");  // top-left empty space
    for (char c : b) fmt::print("{:>3}", c);
    fmt::print("\n");

    // Print rows
    for (int i = 0; i <= m; i++) {
        if (i == 0)
            fmt::print("{:>3} ", " ");  // top-left empty corner
        else
            fmt::print("{:>3} ", a[i - 1]);  // left header

        for (int j = 0; j <= n; j++) {
            fmt::print("{:>3}", dp[i][j]);
        }
        fmt::print("\n");
    }
    fmt::print("\nLevenshtein distance: {}\n\n", distance);
}

int main() {
    std::string a = "Amit Kumar";
    std::string b = "Akhil Kumar";

    int m, n;
    m = a.size();
    n = b.size();

    // Recursive
    dp = std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, -1));
    print_dp(a, b, levenshtein(a, b));

    // Iterative
    dp = std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, -1));
    print_dp(a, b, levenshtein_iter(a, b));

    return 0;
}
