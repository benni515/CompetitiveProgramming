void Sieve(int n){
    bitset<100000020> prime;
    prime.flip();
    prime.flip(1);
    for(int p = 2; p*p<=n;p++) {
        if(prime.test(p)) {
            for(int i = p*p; i<=n;i+=p) prime.set(i,0);
        }
    }
}
