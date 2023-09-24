#include <stdio.h>


int strlength(char *a)
{
  int i = 0;
  while(a[i] != '\0')
    i++;
  return i;
}


void toUpper(char *a)
{
  int i = 0;
  while(a[i] != '\0'){
    if (a[i] >= 'a' && a[i] <= 'z') a[i++] -= 32;
    else i++;
  }
}

void toLower(char *a)
{
  int i = 0;
  while(a[i] != '\0'){
    if (a[i] >= 'A' && a[i] <= 'Z') a[i++] += 32;
    else i++;
  }
}


void changeCase(char *a)
{
  int i = 0;
  while(a[i] != '\0')
  {
    if (a[i] >= 'a' && a[i] <= 'z') a[i++] -= 32;
    else if (a[i] >= 'A' && a[i] <= 'z') a[i++] += 32;
    else i++;
  }
}


int countWords(char *a)
{
  int c = 0, i = 0;
  while(a[i] != '\0')
  {
    if (a[i] == ' ' && a[i-1] != ' ') c++;
    i++;
  }
  return c;
}

void swapc(char *x, char *y)
{
  char temp = *x;
  *x = *y;
  *y = temp;
}

void perm(char s[],int l,int h)
{
    if(l==h)
    {
        printf("%s\n",s);
    }
    else
    {
        for(int i=l;i<=h;i++)
        {
            swapc(&s[i],&s[l]);
            perm(s,l+1,h);
            swapc(&s[i],&s[l]);
        }
    }
}
int main()
{
  char arr[10];
//  scanf();
  printf("%i\n",strlength(arr));
  changeCase(arr);
  printf("%s\n",arr);
  toLower(arr);
  printf("%s\n",arr);
  toUpper(arr);
  printf("%s\n",arr);
   char s[]="ABC";
    perm(s,0,2);
  return 0;
}
