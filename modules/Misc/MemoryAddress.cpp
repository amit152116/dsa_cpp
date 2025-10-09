

#include "utils/logger.hpp"

#include <map>
#include <string>
#include <vector>

namespace {
    void mapMemory() {
        // Create a local variable on the stack
        std::map<int, std::string> myMap;

        // Insert an element (allocated internally)
        myMap[1] = "Hello, heap!";

        // Show the address of the container itself
        print("Address of myMap (container object): ",
              static_cast<void*>(&myMap));
        print("Size of myMap (container object): ", sizeof(myMap));
        print("End Address of myMap (container object): ",
              static_cast<void*>(&myMap + 1));

        // Get an iterator to the first element
        auto it = myMap.begin();

        // Show address of key and value stored in the heap
        print("Address of key inside node:   ",
              static_cast<const void*>(&it->first));
        print("End Address of key inside node:   ",
              static_cast<const void*>(&it->first + 1));
        print("Address of value inside node: ",
              static_cast<const void*>(&it->second));
        print("End Address of value inside node:   ",
              static_cast<const void*>(&it->second + 1));
        print("=====================================");
    }

    void vectorMemory() {
        std::vector<int> arr(2);
        print("Address of arr (container object): ", static_cast<void*>(&arr));
        print("sizeof(arr): ", sizeof(arr));
        print("container size: ", arr.size());
        print("capacity: ", arr.capacity());

        print("Address of first element: ", static_cast<void*>(arr.data()));

        for (int i = 0; i < arr.size(); i++) {
            print("Address of [", i,
                  "] element in arr: ", static_cast<void*>(&arr[i]));
        }
        arr.push_back(3);
        arr.push_back(4);
        print("container size: ", arr.size());
        print("capacity: ", arr.capacity());
        for (int i = 0; i < arr.size(); i++) {
            print("Address of [", i,
                  "] element in arr: ", static_cast<void*>(&arr[i]));
        }
        arr.push_back(5);
        print("container size: ", arr.size());
        print("capacity: ", arr.capacity());
        for (int i = 0; i < arr.size(); i++) {
            print("Address of [", i,
                  "] element in arr: ", static_cast<void*>(&arr[i]));
        }
        arr.resize(8);
        print("container size: ", arr.size());
        print("capacity: ", arr.capacity());
        for (int i = 0; i < arr.size(); i++) {
            print("Address of [", i,
                  "] element in arr: ", static_cast<void*>(&arr[i]));
        }

        print("=====================================");
    }

    void moveMemory() {
        std::string a = "This is a very long string that exceeds SSO limit...";
        print(a);
        print("Address of a (container object): ", static_cast<void*>(&a));
        print("Address of first element in a: ", static_cast<void*>(&a[0]));

        std::string b = std::move(a);
        print(a, b);
        print("Address of b (container object): ", static_cast<void*>(&b));
        print("Address of a (container object): ", static_cast<void*>(&a));
        print("Address of first element in a: ", static_cast<void*>(&a[0]));
        print("Address of first element in b: ", static_cast<void*>(&b[0]));
    }
}  // namespace

auto main(int /*argc*/, char* /*argv*/[]) -> int {
    print("sizeof(std::map<int64_t,std::string>): ",
          sizeof(std::map<int64_t, std::string>));

    print("sizeof(std::string): ", sizeof(std::string));

    print("sizeof(double): ", sizeof(double));
    print("sizeof(std::vector<int>): ", sizeof(std::vector<int>));
    print("sizeof(std::vector<std::string>): ",
          sizeof(std::vector<std::string>));

    double* p = nullptr;
    print("sizeof(ptr): ", sizeof(p));
    print("=====================================");

    mapMemory();
    vectorMemory();
    moveMemory();

    return 0;
}
