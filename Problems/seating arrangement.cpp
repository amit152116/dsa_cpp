#include<iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        int q,div;
        div=n/12;
        q=n%12;
        if(q==1){
            cout<< (12*div+12) <<" WS"<<endl;
        }
        else if(q==2){
            cout<< 12*div+11 <<" MS"<<endl;
        }   
        else if(q==3){
            cout<< 12*div+10 <<" AS"<<endl;
        } 
        else if(q==4){
            cout<< 12*div+9 <<" AS"<<endl;
        } 
        else if(q==5){
            cout<<12*div+8<<" MS"<<endl;
        } 
        else if(q==6){
            cout<<12*div+7<<" WS"<<endl;
        } 
        else if(q==7){
            cout<<12*div+6<<" WS"<<endl;
        } 
        else if(q==8){
            cout<<12*div+5<<" MS"<<endl;
        } 
        else if(q==9){
            cout<<12*div+4<<" AS"<<endl;
        } 
        else if(q==10){
            cout<<12*div+3<<" AS"<<endl;
        } 
        else if(q==11){
            cout<<12*div+2<<" MS"<<endl;
        } 
        else if(q==0){
            cout<<12*div-11<<" WS"<<endl;
        }     
         
        
    }
}
