#include <stdio.h>
#include <string.h>
#include <xlocale.h>


int main() {
  
  char big[] = "mashed potatoes with thick gravy";
  char little[] = "potatoes";
  
  printf("%s\n", strnstr(big, little, 18));

  return 0;
}