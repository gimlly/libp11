#include "engine.h"
#include <string.h>
#include <stdio.h>
#include <limits.h>

int main() {
  size_t plen = 1ULL+INT_MAX; // => int pl == -2147483648
  char *pin = malloc(plen);
  size_t urlLen = 17ULL+plen+1;
  char *url = malloc(urlLen);
  char prefix[] = "pkcs11:pin-value=";
  memcpy(url, prefix, 17);
  for(size_t i=0;i<1ULL+INT_MAX;i++) {
  	url[i+17] = '1';
  }
  url[urlLen-1] = '\0';
  unsigned char id_len;
  PKCS11_TOKEN *ptok;
  char *label;
  parse_pkcs11_uri(NULL, url, &ptok, &id_len, NULL, pin, &plen, &label);
  free(url);
  free(pin);
  int pl = plen;
  printf("Pin length should be %lu and is %d\n", plen, pl);
}
