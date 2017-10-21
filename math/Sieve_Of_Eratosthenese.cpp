vi Sieve(int n){
	bitset<100000901> prime;
	prime.set(1);
	vi primes;
	for(int p = 2; p<=n;p++) {
		if(!prime.test(p)) { // check if bit is set
			primes.push_back(p);
			// set all bits that are a multiple of the prime number
			for(int i = p*2; i<=n;i+=p) prime.set(i); 
		} 
	}
	return primes;
}
