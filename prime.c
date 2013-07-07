#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>

int eratos(int number) {
  int i = 0;
  if (number == 1) return 0;
  i = 2;
  if (!(number%i)) return 0;
  i = 3;
  if (!(number%i)) return 0;
  i = 5;
  while (i <= sqrt(number)) {
    if (!(number%i)) return 0;
    i = i+2;
    if (!(i%3)) i += 2;
  }
  return 1;
}

int makegcd(int a, int number) {
  int reminder, gcd;
  if (a == 0) gcd = number;
  else if (number % a == 0) gcd = a;
  else {
    reminder = number % a;
    number = a;
    a = reminder;
    gcd = makegcd(a, number);
  }
  return gcd;
}

int fermat(int number) {
  if (makegcd(2, number) == 1) {
    int result = (int)pow(2.0, ((double)number - 1.0)) % number;
    return result;
  } else return 0;
}

int main(int argc, char *argv[]) {
  printf ("Input Prime number. (range of int)");
  int number = 0;
  scanf ("%d", &number);
  assert (number > 0);

  clock_t erat1 = clock();
  if (eratos(number)) printf ("%d is Prime!!!!!!!\n", number);
  else printf ("%d is NOT Prime :( \n", number);
  clock_t erat2 = clock();
  printf ("Erathosthenes: %f sec.\n", (double)(erat2 - erat1) / CLOCKS_PER_SEC);

  clock_t fermat1 = clock();
  if (fermat(number)) printf ("%d is Prime!!!!!!!\n", number);
  else printf ("%d is NOT Prime :( \n", number);
  clock_t fermat2 = clock();
  printf ("Fermat test: %f sec.\n", (double)(fermat2 - fermat1) / CLOCKS_PER_SEC);
  /*
  int i = 0;
  int count = 0;
  clock_t t1 = clock();
  for (i=1;i<=10000;i++) {
    if (fermat(i)!=eratos(i)) count++;
  }
  clock_t t2 = clock();
  printf("Miss count: %d\n", count);
  printf("1-%d: %f sec.\n", i-1, (double)(t2-t1)/CLOCKS_PER_SEC);
  */
  return 0;
  
}
