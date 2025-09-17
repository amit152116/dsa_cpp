#include <bits/stdc++.h>
#include <fmt/format.h>
#include <fmt/ranges.h>

std::vector<std::vector<int>> dp;

/*
 * Damerau–Levenshtein Distance
 * ----------------------------
 * Definition:
 *   - Extension of Levenshtein distance, adding transposition of adjacent
 *      characters.
 *   - Allowed operations:
 *       1. Substitution
 *       2. Insertion
 *       3. Deletion
 *       4. Transposition of adjacent characters
 *
 * Recurrence:
 *   - Same as Levenshtein, but also check if
 *       a[i] == b[j+1] and a[i+1] == b[j]
 *     → Then allow transposition with cost 1.
 *
 * Complexity:
 *   Time: O(n * m)
 *   Space: O(n * m) (can be optimized to O(min(n,m)))
 *
 * Example:
 *   damerau_levenshtein("ca", "abc") = 2
 *   ("ca" → "ac" [transpose] → "abc" [insert 'b'])
 *
 * Use Cases:
 *   - Spell check & autocorrect ("hte" → "the")
 *   - DNA/protein sequence matching (with swaps)
 *   - OCR error correction
 *   - Plagiarism detection / fuzzy search
 *
 * Comparison:
 *   - Hamming Distance: only substitution (strings must be equal length)
 *   - Levenshtein: insertion, deletion, substitution
 *   - Damerau–Levenshtein: adds transposition (handles human typing errors
 * better)
 */

int damerau_levenshtein(const std::string& a, const std::string& b,
                        size_t i = 0, size_t j = 0) {
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == a.size())
        return b.size() - j;  // insert remaining b
    if (j == b.size())
        return a.size() - i;  // delete remaining a

    int cost = (a[i] == b[j]) ? 0 : 1;

    // Standard Levenshtein ops
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

    // Damerau-Levenshtein
    dp = std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, -1));
    print_dp(a, b, damerau_levenshtein(a, b));

    return 0;
}
