## PHP C Extension Demo

A performance approach

<br/>

Primes generation is a clasic mathematical problem which needs to develop increasingly optimal algorithms to solve it, in this case we choose miller-rabin algorithm.

> [**Miller-Rabin**](https://en.wikipedia.org/wiki/Miller–Rabin_primality_test) is a probabilistic approch to determine if a number is prime or not similar to the Fermat Primality test.

<br/>

The following demo, show us this algoritm trying to find first 5000 primes with 12 digits using PHP pure implementation and another using a C extension for the calculation process.

<center>

  ![screen](images/screen_record.gif)

</center>

As we can see, using a c-extension for the primality test we get a 2927x faster execution.