#include<bits/stdc++.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

class RSA_KEY
{
private:
    int Public_key,Private_key;
    int phi;
    int N;
    void prime_sieve(int n);
public:
    RSA_KEY(int n){
        prime_sieve(n);
        vector<int> e;
        vector<int> d;
        vector<int> gcd(phi,0);
        for(int i=2;i<phi;i++){
            if(gcd[i]==0){
                int divisor1=__gcd(i,N);
                int divisor2=__gcd(i,phi);
                if(divisor2!=1 || divisor1!=1){
                    gcd[i]=1;
                }
                for(int j=i*i;j<phi;j+=i){
                    gcd[j]=1;
                }
            }
        }
        for(int i=2;i<phi;i++){
            if(gcd[i]==0){
                e.push_back(i);
            }
        }
        int size=e.size();
        for(int i=0;i<size;i++){
            int x=e[i];
            while(true){
                int mod=(x*e[i])%phi;
                if(mod==1 && x!=e[i] && x!=N){
                    break;
                }
                x+=2;
            }
            d.push_back(x);
        }
        int sum=INT_MAX;
        for(int i=0;i<size;i++){
            int de=d[i]+e[i];
            if(de<sum){
                sum=de;
                Public_key=e[i];
                Private_key=d[i];
            }
        }
        
       
    }
    ~RSA_KEY(){

    }
    int get_N(){
        return N;
    }
    int get_phi(){
        return phi;
    }
    int get_Public_Key(){
        return Public_key;
    }
    int get_Private_key(){
        return Private_key;
    }
};
void RSA_KEY::prime_sieve(int n){
    vector<int> arr(n,0);
    for(int i=2;i<n;i++){
        if(arr[i]==0){
            for(int j=i*i;j<n;j+=i){
                arr[j]=1;
            }
        }
    }
    vector<int> primes;
    int j=0;
    for(int i=n-1;i>1;i--){ 
        if(arr[i]==0){
            primes.push_back(i);
            j++;
        }
        if(j==2){
            break;
        }
    }
    N=primes[0]*primes[1];
    phi =(primes[0]-1)*(primes[1]-1);
}


int main(){
    fast;
    RSA_KEY key(6);
    cout<<key.get_N()<<endl;
    cout<<key.get_Private_key()<<endl;
    cout<<key.get_Public_Key()<<endl;

    int text=2;
    int cipher=pow(text,key.get_Public_Key());
    cipher=cipher%key.get_N();
    cout<<cipher<<endl;
    
    
    return 0;
}