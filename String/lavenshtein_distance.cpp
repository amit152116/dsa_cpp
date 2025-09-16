#include <bits/stdc++.h>
#include <fmt/format.h>
#include <fmt/ranges.h>

std::vector<std::vector<int>> dp;
/*
 * Summary
 *  - Use `Hamming` for equal-length strings when only substitutions matter.
 *
 *  - Use `Levenshtein` for general fuzzy matching where insertions and
 * deletions also count.
 */

/*
The minimum Hamming distance  is used to define some essential notions in coding
theory, such as error detecting and error correcting codes. In particular, a
code C is said to be k error detecting if, and only if, the minimum Hamming
distance between any two of its codewords is at least k+1.[2]

For example, consider a code consisting of two codewords "000" and "111". The
Hamming distance between these two words is 3, and therefore it is k=2 error
detecting. This means that if one bit is flipped or two bits are flipped, the
error can be detected. If three bits are flipped, then "000" becomes "111" and
the error cannot be detected.
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

int levenshtein(const std::string& a, const std::string& b, size_t i = 0,
                size_t j = 0) {
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == a.size())
        return dp[i][j] = b.size() - j;
    if (j == b.size())
        return dp[i][j] = a.size() - i;
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
    int m, n;
    m = a.size();
    n = b.size();

    // Initialize base cases
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + std::min({dp[i - 1][j - 1], dp[i][j - 1],
                                         dp[i - 1][j]});
        }
    }
    return dp[m][n];
}
int damerau_levenshtein(const std::string& a, const std::string& b,
                        size_t i = 0, size_t j = 0) {
    if (dp[i][j] != -1)
        return dp[i][j];
    // Base cases
    if (i == a.size())
        return b.size() - j;  // insert remaining b
    if (j == b.size())
        return a.size() - i;  // delete remaining a

    int cost = (a[i] == b[j]) ? 0 : 1;

    // Standard operations: substitution, insertion, deletion
    int res = std::min({
        damerau_levenshtein(a, b, i + 1, j + 1) + cost,  // substitution
        damerau_levenshtein(a, b, i, j + 1) + 1,         // insertion
        damerau_levenshtein(a, b, i + 1, j) + 1          // deletion
    });

    // Transposition check
    if (i + 1 < a.size() && j + 1 < b.size() && a[i] == b[j + 1] &&
        a[i + 1] == b[j]) {
        res = std::min(res, 1 + damerau_levenshtein(a, b, i + 2, j + 2));
    }

    return dp[i][j] = res;
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

    // Damerau-Levenshtein
    dp = std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, -1));
    print_dp(a, b, damerau_levenshtein(a, b));

    return 0;
}
