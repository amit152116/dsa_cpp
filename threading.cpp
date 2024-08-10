#include<iostream>
#include<vector>
#include<thread>
#include<chrono>
using namespace std;


void doWork(int value){
    cout<<"start thread "<<this_thread::get_id()<<endl;
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    for(int i=2;i<value;i++){
        arr.push_back(arr[i-1]+arr[i-2]);
    }
    for(auto it:arr){
        cout<<it<<' ';
    }
    cout<<"end thread"<<this_thread::get_id()<<endl;
    return;
}
int main(){
    auto start = chrono::high_resolution_clock::now();
    thread worker(doWork,10);
    thread worker2(doWork,20);
    thread worker3(doWork,30);
    doWork(25);
    doWork(20);
    doWork(30);
    worker.join();
    worker2.join();
    worker3.join();
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout<<duration.count()<<"ms"<<endl;
    return 0;
}