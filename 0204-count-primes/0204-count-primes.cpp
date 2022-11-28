class Solution {
public:
   int countPrimes(int n) {
	long long count=0;
	vector<bool> isPrime(n+1, 1);

	for(long long i=2; i<n; i++) {
		if(isPrime[i]) {
			count++;
			for(long long j=i*i; j<n; j+=i) isPrime[j]=0;
		}
	}
	return count;
}
};