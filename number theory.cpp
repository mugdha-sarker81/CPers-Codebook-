#include<bits/stdc++.h>
using namespace std;
using ll= long long;

int main() { }

// lcm = least common multiple
// gcd = greatest common divisor 
int lcm(int a,int b){  return (a/__gcd(a,b))*b; }  

vector<ll> finddivisors(ll n){  //all divisiors
    vector<ll> divisors;
    for(ll i=1; i*i<=n; i++){
        if(n%i==0){
            if(n/i==i) divisors.push_back(i);
            else {
                divisors.push_back(i);
                divisors.push_back(n/i);
            }
        }
    }
    sort(divisors.begin(),divisors.end());
    return divisors;
}

ll powm(ll a,ll b){             //binary exponentiation
    ll m= 1e9+7;  a=a%m; ll res=1;
    while(b){
        if(b&1) res= ((res%m)*(a%m))%m;
        a= (a*a)%m;  b>>=1;
    }
    return res;
}

// bool isPrime(ll n) {          // is a number prime
//     if (n < 2) return false;
//     for (ll i = 2; i * i <= n; i++) {
//         if (n % i == 0) return false;
//     }
//     return true;
// }

bool isprime(ll n) {          // is a number prime ?
	  if(n<=1) return false; 
	  if(n<=3) return true; 
	  
	  if(n%2==0 || n%3==0) return false; 
	  
	  for(ll i=5; i*i<=n; i+=6) 
		if(n%i ==0 || n%(i+2)==0) 
		    return false; 
	  
	  return true; 
} 


bool prime[15000105];               // sieve algorithm for prime array

void sieve(int n) { 
    for (ll i = 0; i <= n; i++) prime[i] = 1;

    for (ll p = 2; p * p <= n; p++) { 
        if (prime[p] == true) { 
            for (ll i = p * p; i <= n; i += p) 
            prime[i] = false; 
        } 
    } 
    prime[1] = prime[0] = 0;
} 

vector<ll> primelist;                   //only prime in a list 
bool __primes_generated__ = 0;
    
void genprimes(int n){
    __primes_generated__ = 1;
    sieve(n + 1);
    for(ll i = 2; i <= n; i++) 
        if(prime[i]) primelist.push_back(i);
}

vector<int> factor(int n) {    //prime factorization( basic )
	vector<int> res;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			res.push_back(i);
			n /= i;
		}
	}
	if (n > 1) { res.push_back(n); }
	return res;
}

vector<ll> factors(ll n) {              // prime factors (optimized)
    if (!__primes_generated__) {
        cerr << "Call genprimes you dope" << endl;
        exit(1);
    }
    vector<ll> facs;
    
    for(ll i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++) {
        if(n % primelist[i] == 0){
            while (n % primelist[i] == 0){
                n /= primelist[i];
                facs.push_back(primelist[i]);
            }
        }
    }
    if(n > 1) {  facs.push_back(n); }

    sort(facs.begin(), facs.end());
    return facs;
}
