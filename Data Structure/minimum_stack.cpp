#include <bits/stdc++.h>

/*
 * MinStack
 * --------
 * A stack that supports:
 *   - O(1) push
 *   - O(1) pop
 *   - O(1) min() → get the minimum element in the stack
 *
 * Idea:
 * -----
 * Instead of storing just values in the stack, we store pairs:
 *   {value, current_min_up_to_this_point}
 *
 * This way, at any time:
 *   - stack.top().first  = actual value
 *   - stack.top().second = minimum of stack from bottom → top
 *
 * On push(val):
 *   - new_min = min(val, top().second if stack not empty)
 *   - push {val, new_min}
 *
 * On pop():
 *   - just pop and return the stored value
 *
 * On min():
 *   - return stack.top().second
 */
class MinStack {
   private:
    std::stack<std::pair<int, int>> stack;  // {value, min_so_far}

   public:
    // Push a value and maintain running minimum
    void push(int val) {
        int minVal = stack.empty() ? val : std::min(val, stack.top().second);
        stack.emplace(val, minVal);
    }

    // Pop top value and return it
    int pop() {
        int val = stack.top().first;
        stack.pop();
        return val;
    }

    // Get current minimum
    int min() {
        return stack.top().second;
    }
};

int main(int argc, char* argv[]) {
    std::vector<int> arr = {1, 2, 3, 4, 5};

    return 0;
}
