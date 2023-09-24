#include <bits/stdc++.h>
using namespace std;

int main(){
  int arr[] = {1,4,7,2,5,8,3,6,9};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3;j++){
      cout << arr[i +3*j] << " ";
    }
    cout <<endl;
  }


  int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  for (int i = 0; i < 3;i++)
  {
    for (int j = 0; j < 3; j++) cout << &a[i][j] << endl;
  }
  cout << endl;
  int **b = new int*[3];
  for (int i = 0; i < 3; i++) b[i] = new int[3];
  for (int i = 0; i < 3;i++)
  {
    for (int j = 0; j < 3; j++) cout << &b[i][j] << endl;
  }
  cout << endl;
  int ar[2][2][2] = {
    {{1,2},{3,4}},{{5,6},{7,8}}
  };
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j <2; j++)
    {
      for (int k = 0; k <2; k++) cout << ar[i][j][k] << " ";
      cout << endl;
    }
    cout << endl;
  }
  
  return 0;
}
