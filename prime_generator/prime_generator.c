
// find the first 100 primes
int prime_generator(int primes[], int primes_size) {

    int pushed_numbers = 0;
    for (int i = 2; i <= 100; i++) {
        if (i % 2 != 0 && i % 3 != 0 && i % 5 != 0 && i % 7 != 0) {
            if(pushed_numbers > primes_size) {
                return 1;
            }
            primes[pushed_numbers++] = i;
        }
        else if (i == 2 || i == 3 || i == 5 || i == 7) {
            if(pushed_numbers > primes_size) {
                return 1;
            }
            primes[pushed_numbers++] = i;
        }
    } 
    return 0;
}
