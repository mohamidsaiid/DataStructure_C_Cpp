#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}


struct Array{
  int A[20];
  int size;
  int length;
};


void Display(struct Array a)
{
  printf("\nELements of the array \n");
  for (int i = 0; i < a.length; i++)
  {
    printf("%i ", a.A[i]);
  }
  printf("\n");
}


void Add(struct Array *a, int n)
{
  if (a->length == a->size) return;
  a->A[a->length++] = n;
}


void Inseret(struct Array *a, int n, int i)
{
  if (a->length == a->size || i+1 > a->size || i < 0) return ;
  if (i+1 == a->length) Add(a ,n);
  for (int j = a->length; j > i; j--)
  {
    a->A[j] = a->A[j-1];
  }
  a->A[i] = n;
  a->length++;
}


int Delete(struct Array *a, int index)
{
  if (index >= a->length || index < 0) return 0;
  int x = a->A[index];
  for (int i = index; i <a->length-1; i++)
  {
    a->A[i] = a->A[i+1];
  }
  a->length--;
  return x;
}


int BinarySearch(struct Array a, int target)
{
  int l = 0;
  int h = a.length-1;
  while(l <= h)
  {
    int mid = (l+h)/2;
    if (a.A[mid] == target) return mid;
    else if(a.A[mid] < target) l = mid+1;
    else h = mid - 1;
  }
  return l;
}


int RBinarySearch(struct Array a,int target,int l, int h)
{
  if(l<=h)
  {
    int mid = (l+h)/2;
    if (a.A[mid] == target) return mid;
    else if(a.A[mid] < target) return RBinarySearch(a, target, mid+1, h);
    else return RBinarySearch(a, target, l, mid-1);
  }
  return -1;
}


int Get(struct Array a, int index)
{
  return a.A[index];
}


void Set(struct Array *a, int x, int index)
{
  a->A[index] = x;
}


int isSorted(struct Array a)
{
  for (int i = 0; i < a.length-1; i++)
  {
    if (a.A[i] > a.A[i+1]) return 0;
  }
  return 1;
}


int Max(struct Array a)
{
  if (isSorted(a)) return a.A[a.length-1];
  int maxx = a.A[0];
  for (int i = 0 ; i < a.length;i++)
  {
    if (a.A[i] > maxx) maxx = a.A[i];
  }
  return maxx;
}


int Min(struct Array a)
{
  if (isSorted(a)) return a.A[0];
  int minn = a.A[0];
  for (int i = 0; i < a.length; i++)
  {
    if (a.A[i] < minn) minn = a.A[i];
  }
  return minn;
}


int Sum(struct Array a, int l)
{
  if (l < 0) return 0;
  return Sum(a, l-1) + a.A[l];
}


float Avg(struct Array a)
{
  return (float)Sum(a, a.length-1) / a.length;
}


void Reverse(struct Array *a)
{
  for (int i = 0, j = a->length-1; i<j; i++,j--)
  {
    swap(&a->A[i],&a->A[j]);
  }
}


void Reverse2(struct Array *a)
{
  int *b = (int *)malloc(a->length*sizeof(int));
  for (int i = a->length-1, j = 0; i >= 0; i--, j++)
  {
    b[j] = a->A[i];
  }
  for (int i = 0; i < a->length; i++) a->A[i] = b[i];
  free(b);
}

void SheftLeft(struct Array *a)
{
  for (int i = 1; i < a->length; i++)
  {
    a->A[i-1] = a->A[i];
  }
}


struct Array* merge(struct Array* a,struct Array* b)
{
  struct Array *c = (struct Array *)malloc(sizeof(struct Array));
  int i = 0, j = 0, k = 0;
  while (i < a->length && j < b->length)
  {
    if (a->A[i] <= b->A[j]) c->A[k++] = a->A[i++];
    else c->A[k++] = b->A[j++];
  }
  while(i < a->length)
  {
    c->A[k++] = a->A[i++]; 
  }
  while(j < b->length)
  {
    c->A[k++] = b->A[j++];
  }
  c->length = a->size + b->size;
  c->length = a->length + b->length;
  return c;
}

struct Array* Union(struct Array *arr1,struct Array *arr2)
{
  int i,j,k;
  i=j=k=0;

  struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

  while(i<arr1->length && j<arr2->length)
  {
    if(arr1->A[i]<arr2->A[j])
      arr3->A[k++]=arr1->A[i++];
    else if(arr2->A[j]<arr1->A[i])
      arr3->A[k++]=arr2->A[j++];
    else
    {
      arr3->A[k++]=arr1->A[i++];
      j++;
    }
  }
  for(;i<arr1->length;i++)
    arr3->A[k++]=arr1->A[i];
  for(;j<arr2->length;j++)
    arr3->A[k++]=arr2->A[j];

  arr3->length=k;
  arr3->size=10;
  return arr3;
}


struct Array* Intersection(struct Array *arr1,struct Array *arr2)
{
  int i,j,k;
  i=j=k=0;

  struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

  while(i<arr1->length && j<arr2->length)
  {
    if(arr1->A[i]<arr2->A[j])
      i++;
    else if(arr2->A[j]<arr1->A[i])
      j++;
    else if(arr1->A[i]==arr2->A[j])
    {
      arr3->A[k++]=arr1->A[i++];
      j++;
    }
  }

  arr3->length=k;
  arr3->size=10;

  return arr3;
}


struct Array* Difference(struct Array *arr1,struct Array *arr2)
{
 int i,j,k;
 i=j=k=0;

 struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

 while(i<arr1->length && j<arr2->length)
 {
    if(arr1->A[i]<arr2->A[j]) arr3->A[k++]=arr1->A[i++];
    else if(arr2->A[j]<arr1->A[i]) j++;
    else
      {
        i++;
        j++;
      }
  }
 for(;i<arr1->length;i++)
   arr3->A[k++]=arr1->A[i];


  arr3->length=k;
  arr3->size=10;

  return arr3;
}
int main()
{
  struct Array a = {{2,4,6,8,10}, 20, 5};
  struct Array b = {{3,5,7,9}, 20, 4};
  struct Array *c = merge(&a, &b);
  Display(*c);
  return 0;
}
