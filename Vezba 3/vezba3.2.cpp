/* clock example: frequency of primes */
#include <stdio.h>      /* printf */
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <math.h>       /* sqrt */

// Elena Desanoska INKI 767 

// funkcija za presmetuvanje na frekfencijata na prosti vroevi pomala ili ednakva na n
int frequency_of_primes(int n) {
  int i, j;
  int freq = n - 1;     // zapocnuvanje so pretpostavka deka site broevi pomegju 2 i n se prosti, osven 1
  for (i = 2; i <= n; ++i) {
    for (j = sqrt(i); j > 1; --j) {     // proverka dali "i" e deliv so koj bilo broj pomegju 2 i kvadratniot koren od "i"
      if (i % j == 0) {         // ako "i" e deliv so "j" togas "i" ne e prost broj
        --freq;               // namaluvanje na brojot na prosti broevi
        break;                // izlegvanje od vnatresnata jamka i preminuvanje na sledniot broj
      }
    }
  }
  return freq;                // go vrakja broenjeto na prosti broevi
}

int main() {
  clock_t t;                 // deklariranje promenliva za zadrzuvanje na otcukuvanjata na casovnikot
  int f;                     // deklariranje promenliva za zadrzuvanja na frekfencijata na prostite broevi
  t = clock();               // snimanje na tekovnite otcukuvanja na casovnikot
  printf("Calculating...\n");
  f = frequency_of_primes(99999);     // povikuvanje na funkcijata frequency_of_primes za da se presmeta frekfencijata na prosti broevi pomala od 100 000
  printf("The number of primes lower than 100,000 is: %d\n", f);
  t = clock() - t;           // presmetuvanje na izminatite otcukuvanja na casovnikot
  printf("It took me %d clicks (%f seconds).\n", t, ((float)t) / CLOCKS_PER_SEC);     // pecatenje na otcukuvanjata i vremeto na casovnikot vo sekundi
  return 0;
}
