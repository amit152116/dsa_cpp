#include <deque>
#include <stack>
#include <utility>

/*
 * MinQueue
 * --------
 * A monotonic queue that supports:
 *   - O(1) amortized push
 *   - O(1) amortized pop (if we know which element is leaving)
 *   - O(1) minimum() query
 *
 * Idea:
 * -----
 * Maintain a deque in **increasing order** of values.
 *   - push(val): Pop from the back until all elements >= val are removed,
 *                then push val.
 *   - pop(val): If the front == val, pop it.
 *   - front(): Returns the current minimum.
 *   - min(): Same as front(), since the deque is always monotonic.
 *
 * Typical use:
 *   - Sliding window minimum problems.
 */
class MinQueue {
   private:
    std::deque<int> queue;  // Monotonic increasing deque

   public:
    // Insert an element while maintaining monotonic property
    void push(int val) {
        while (!queue.empty() && queue.back() > val) {
            queue.pop_back();
        }
        queue.emplace_back(val);
    }

    // Remove element 'val' from the queue front (if it matches)
    int pop(int val) {
        int remove = -1;
        if (!queue.empty() && queue.front() == val) {
            remove = val;
            queue.pop_front();
        }
        return remove;
    }

    // Get the current minimum element (front of deque)
    int front() {
        return queue.front();
    }

    // Alias for front() — minimum is always at the front
    int min() {
        return queue.front();
    }
};

/*
 * MinQueue2
 * ---------
 * An alternative monotonic queue that tracks element indices.
 *
 * Idea:
 * -----
 * - Each element stored as {value, index}.
 * - "added" = counter for inserted elements.
 * - "removed" = counter for how many elements have been logically removed.
 *
 * Operations:
 *   - push(val): Maintain monotonic increasing order by removing back elements
 *                greater than val, then push {val, index}.
 *   - pop(): Remove from front if its index == removed (i.e., it's expired).
 *   - minium(): Returns the current minimum (queue.front().first).
 *
 * Advantage:
 *   - Useful for sliding window problems, since we don’t need to explicitly
 *     know the element value to pop — we pop by index.
 */
class MinQueue2 {
   private:
    std::deque<std::pair<int, int>> queue;        // {value, index}
    int                             added   = 0;  // Count of inserted elements
    int                             removed = 0;  // Count of removed elements

   public:
    // Insert an element with its "added" index
    void push(int val) {
        while (!queue.empty() && queue.back().first > val) {
            queue.pop_back();
        }
        queue.emplace_back(val, added++);
    }

    // Remove expired elements (those whose index == removed)
    int pop() {
        int val = -1;
        while (!queue.empty() && queue.front().second == removed) {
            val = queue.front().first;
            queue.pop_front();
        }
        removed++;
        return val;
    }

    // Return current minimum element
    int minium() {
        return queue.front().first;
    }
};

/*
 * MinQueue3
 * ----------
 * A queue implementation that supports:
 *   - O(1) amortized push
 *   - O(1) amortized pop
 *   - O(1) minimum() operation (get min element in the queue)
 *
 * Idea:
 * -----
 * We use two stacks (`push_stack` and `pop_stack`) to simulate a queue.
 * Each stack stores pairs: {value, current_min}.
 *   - push_stack: stores new elements when they are pushed.
 *   - pop_stack: stores elements in reverse order when popping.
 *
 * By storing the running minimum in each stack, we can always query the
 * minimum in O(1) time by comparing the top of both stacks.
 */
class MinQueue3 {
   private:
    // Each stack element = {value, minimum_up_to_this_point}
    std::stack<std::pair<int, int>> push_stack, pop_stack;

   public:
    /*
     * push(val)
     * ----------
     * Adds a new element to the queue.
     * Updates the minimum in push_stack as the minimum between:
     *   - the new element, and
     *   - the current min in push_stack (if it exists).
     */
    void push(int val) {
        int minVal =
            push_stack.empty() ? val : std::min(val, push_stack.top().second);
        push_stack.emplace(val, minVal);
    }

    /*
     * pop()
     * -----
     * Removes the front element of the queue.
     *
     * If pop_stack is empty, we move all elements from push_stack → pop_stack.
     *   - While transferring, we maintain the running minimum in pop_stack.
     *   - This reversal ensures the oldest element (queue front) is on top of
     * pop_stack.
     */
    int pop() {
        if (pop_stack.empty()) {
            while (!push_stack.empty()) {
                int element = push_stack.top().first;
                push_stack.pop();

                int minVal = pop_stack.empty()
                                 ? element
                                 : std::min(element, pop_stack.top().second);

                pop_stack.emplace(element, minVal);
            }
        }

        int popVal = pop_stack.top().first;
        pop_stack.pop();
        return popVal;
    }

    /*
     * minimum()
     * ---------
     * Returns the minimum element currently in the queue.
     *
     * Cases:
     *   - If one stack is empty, the min is in the other stack.
     *   - If both are non-empty, the min is the smaller of:
     *        push_stack.top().second  and  pop_stack.top().second
     */
    int minimum() {
        if (push_stack.empty() || pop_stack.empty()) {
            return push_stack.empty() ? pop_stack.top().second
                                      : push_stack.top().second;
        }
        return std::min(push_stack.top().second, pop_stack.top().second);
    }
};

int main(int argc, char* argv[]) {
    return 0;
}
