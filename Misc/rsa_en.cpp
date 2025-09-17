#include<bits/stdc++.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
class RSA
{
private:
    unsigned long int public_key=7,private_key=823;
    string P="61",Q="97";
    int lenP,lenQ;
    unsigned long int N;
    unsigned long int phi;
    string multiplication(string a, string b);
public:
    RSA(){
        lenP=P.length();
        lenQ=Q.length();
        N=stol(multiplication(P,Q));
        string a=P,b=Q;
        a[lenP-1]-=1;
        b[lenQ-1]-=1;
        phi=stol(multiplication(a,b));
        // unsigned long int k=5;
        // while(true){
        //     if(__gcd(k,phi)==1 &&__gcd(k,N)==1){
        //         public_key=k;
        //         break;
        //     }
        //     if(__gcd(k+2,phi)==1 &&__gcd(k+2,N)==1){
        //         public_key=k+2;
        //         break;
        //     }
        //     k+=6;
        // }
        // auto d=public_key;
        // while(true){
        //     auto mod=(d*public_key)%phi;
        //     if(mod==1 && d!=public_key){
        //         private_key=d;
        //         break;
        //     }
        //     d+=2;
        // }
        cout<<public_key<<' '<<private_key<<endl;
    }
    string encrypt_message(string a){
        int len=a.length();
        vector<string> arr(len);
        for(int i=0;i<len;i++){
            int obj=a[i];
            arr[i]=to_string(obj);
            cout<<arr[i]<<endl;
        }
        cout<<endl;
        for(int i=0;i<len;i++){
            string x=arr[i],y=arr[i];
            int j=public_key;
            while(--j){
                x=multiplication(x,y);
            }
            long int number=stol(x);
            number%=N;
            cout<<number<<endl;
        }
        return"";

    }
};
string RSA::multiplication(string a,string b){
    int m=a.length();
    int n=b.length();
    int size=m+n;
    vector<int> result(size,0);
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            int x=(a[i]-'0')*(b[j]-'0');
            result[i+j+1]+=x;
            result[i+j]+=result[i+j+1]/10;
            result[i+j+1]%=10;
        }
    }
    int i=0;
    while(i<size && result[i]==0)i++;
    string ans="";
    for(i;i<size;i++){
        ans+=result[i]+'0';
    }
    return ans;
}
int main()
{
    string encryption_text="Amit Kumar";
    RSA rsa;
    rsa.encrypt_message(encryption_text);

    return 0;
}
