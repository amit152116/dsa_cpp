#include<iostream>
#include<vector>

using namespace std;

/*         
*               Worst & Average Case Time Complexity : O(n^2)
*               Best Case Time Complexity : O(n)
*               Auxiliary Space: O(1)          
*/


int main(){
    vector<int> arr={375,274,339,471,239,187,176,15,71,116,296,355,491,81,85,329,195,253,11,3,174,48,84,395,261,224,23,466,345,272,492,489,243,257,60,11,87,44,400,64,156,473,175,343,15,345,412,16,407,85,438,175,306,356,197,422,476,109,482,204,207,434,60,409,131,112,111,63,129,121,137,398,494,383,387,110,177,349,409,208,493,100,424,421,329,103,76,87,291,178,317,221,412,360,259,90,147,447,149,153};
    int n= arr.size();

    for(int i=0;i<n-1;i++){
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }    
    }
     for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"\t";
    }
}