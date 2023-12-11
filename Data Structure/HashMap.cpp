#include<iostream>
#include<vector>

using namespace std;
/*
    There are two methods for handling collision for hashing.
        1. Separate Chaining
        2. Open Addressing

    In Open Addressing, the size of the table must be greater than or equal to the total number of keys.
        https://www.geeksforgeeks.org/open-addressing-collision-handling-technique-in-hashing/
*/

// Time Complexity of Insertion/Deletion/Get = O(1+α)
// Where 	α = Avg. no of element in each slot = no of elements/capacity
template <typename T,typename V>
struct Node{
    T key;
    V val;
    Node* next;
    Node(T key, V val){
        this->key = key;
        this->val = val;
        next = nullptr;
    }
};


template<typename T,typename V>
class HashMap{
private:
    vector<Node<T,V>*> arr;
    int capacity;
public:
    
    HashMap(int capacity){
        this->capacity = capacity;
        arr.resize(capacity);
        for(auto &node:arr){
            node = new Node(T(),V());
        }
        return;
    }
    V get(T key){
        auto node = arr[hashCode(key)];
        while(node && node->key!=key){
            node = node->next;
        }
        if(!node)return V();
        return node->val;
    }
    void put(T key,V val){
        auto node = arr[hashCode(key)];
        while(node->next){
            if(node->key==key){
                node->val = val;
                return;
            }
            node = node->next;
        }
        node->next = new Node(key,val);
    }
    void remove(T key){
        auto node = arr[hashCode(key)];
        while(node->next){
            if(node->next->key==key){
                auto delElement = node->next;
                node->next = node->next->next;
                delete delElement;
                return;
            }
            node = node->next;
        }
        return;
    }

     int hashCode(int val){
        return val%capacity;
    }

    int hashCode(string val){
        const int prime = 53;
        long long hash_val = 0;
        long long p_pow = 1;
        for(auto it:val){
            hash_val = (hash_val + (it-'a'+1)*p_pow)%capacity;
            p_pow = (p_pow*prime)%capacity;
        }
        cout<<hash_val<<endl;
        return hash_val;
    }
};
int main(){
    HashMap<int,string> mp(1000);
    mp.put(1,"1");
    mp.put(1001,"1001");
    cout<<mp.get(1)<<endl;
    mp.put(1,"amit");
    cout<<mp.get(1)<<endl;
    cout<<mp.get(1001)<<endl;
    mp.remove(1);
    mp.remove(1001);
    cout<<mp.get(1);
    
    mp.put(2,"akhil");
    cout<<mp.get(1)<<mp.get(2);
    return 0;
}