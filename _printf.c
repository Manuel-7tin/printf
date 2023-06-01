#include "printf.h"

/**
 * _printf - The main custom printf function
 *
 * @l: major string
 *
 * Return: int
 */

int _printf(char *l, ...)
{
	char *s;
  char *w;
  char *c;
  int i, b, j, a = 0;
  unsigned int n;
  va_list ptr;
  void *addr;
  addr = (void *)0x7ffe637541f0;

  va_start(ptr, l);
  s = malloc(10000);

  if (s == NULL || l == NULL){
    free(s);
    return (1);
  }
  for (i = 0; i <= strlen(l)+1; i++){
    if (l[i] != '%'){
      s[a] = l[i];
    }
    else{

      if (l[i+1] == '%'){
        s[a] = l[i++];
      }
      else if (l[i+1] == 'c'){
        s[a] = va_arg(ptr, int);
        i++;
      }
      else if (l[i+1] == 's'){
        c = malloc(sizeof va_arg(ptr, char*));
        if (c == NULL){
          free(c);
          return (1);
        }
        c = va_arg(ptr, char*);
        b = 0;
        a--;
        while (b < strlen(c))
          s[++a] = c[b++];
        i++;
      }
      else if (l[i+1] == 'd' || l[i+1] == 'i'){
        j = va_arg(ptr, int);
        w = int_to_str(j);
        if (w == NULL){
          free(w);
          return (1);
        }
        a--;
        for (n = 0; n < strlen(w); n++)
          s[++a] = w[n];
        i++;
      }
      else if (l[i+1] == 'u'){
        j = va_arg(ptr, unsigned int);
        w = unsigned_int_to_str(j);
        if (w == NULL){
          free(w);
          return (1);
        }
        a--;
        for (n = 0; n < strlen(w); n++)
          s[++a] = w[n];
        i++;
      }
      else if (l[i+1] == 'o'){
        j = va_arg(ptr, unsigned int);
        w = int_to_oct(j);
        if (w == NULL){
          free(w);
          return (1);
        }
        a--;
        for (n = 0; n < strlen(w); n++)
          s[++a] = w[n];
        i++;
      }
      else if (l[i+1] == 'x' || l[i+1] == 'X'){
        j = va_arg(ptr, int);
        w = int_to_hex(j, l[i+1]);
        if (w == NULL){
          free(w);
          return (1);
        }
        a--;
        for (n = 0; n < strlen(w); n++)
          s[++a] = w[n];
        i++;
      }
      else if (l[i+1] == 'p'){
        void *ptor;
        ptor = va_arg(ptr, void*);
        w = ptr_to_hex(ptor);
        if (w == NULL){
          free(w);
          return (1);
        }
        a--;
        s[++a] = '0';
        s[++a] = 'x';
        for (n = 4; n < strlen(w); n++)
          s[++a] = w[n];
        i++;
      }
      else{
       s[a] = l[i];
      }
    }

    a++;
  }

  va_end(ptr);
  return (print_str(s));
}
