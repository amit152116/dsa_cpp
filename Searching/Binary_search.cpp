#include<iostream>
#include<vector>
using namespace std;

int Binary_Search(vector<int> nums,int target){
	int start=0, end=nums.size()-1;
	while(start<=end){
		int mid= start+ (end-start)/2;

		 if(nums[mid] == target) {
                return mid;
            }
            else if(target>nums[mid]) {
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
	return -1;
}
int main(){
    vector<int> arr={1,2,3,4,5,6,10,50,64,85,97,234,674};
    int target=234;
    cout<<Binary_Search(arr,target);
}

int Binary_Search(vector<int> nums,int target){

    int start=0, end=nums.size()-1;
    while(start<=end){

        int mid= start+ (end-start)/2;
        if(nums[mid] == target) {
            return mid;
        }
        else if(target>nums[mid]) {
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}
