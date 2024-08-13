#include<iostream>
using namespace std;

int main() {

int n = 0, i = 0, j = 0, k = 0, z, q, v, ranka, rankab, var;

cout << "Enter size of square matrix : "<<endl;
cin >> n;
cout << "Enter number of varibles : "<<endl;
cin >> var;

float a[n][n],a2[n][n], b[n], ab[n][n+1], l[n][n], u[n][n], x[n], y[n], temp, p;

cout<<"\nEnter matrix A values: "<<endl;
for (i = 0; i < n; i++)
for (j = 0; j < n; j++)
cin >> a[i][j];

cout<<"\nEnter B values: "<<endl;
for (i = 0; i < n; i++)
cin >> b[i];


cout << "\nYour matrix is: ​"<<endl;
for (i = 0; i < n; i++) {
  for (j = 0; j < n; j++) {
     cout<<a[i][j]<<" ";
     ab[i][j] = a[i][j];
     a2[i][j] = a[i][j];
  }
  cout << b[i] << endl;
  ab[i][n] = b[i];
}

//ранг матрицы a
int R = n;
int C = n;

if(a[0][0]==0){
  for(j=0;j<C;j++){
    z=-1;
    for(i=1;i<R;i++){
      if(a[i][j]!=0){
        z=i;
        break;
      }
    }
    if(z!=-1){
      for( v=0;v<C;v++){
        float t=a[0][v];
        a[0][v]=a[i][v];
        a[i][v]=t;
      }
      break;
    }
  }
}
for(k=0;k<R-1;k++){
  for(i=k+1;i<R;i++){
    p=a[k][k];
    q=a[i][k];
    for(j=0;j<C;j++){
      a[i][j]=p*a[i][j] - q*a[k][j];
    }
  }
}
z=0;
for(i=0;i<R;i++){
  int c=0;
  for(j=0;j<C;j++){
    if(a[i][j]==0){
      c++;
    }
  }
  if(c==C){
    z++;
  }
}
ranka = R-z;
cout<<"\nRank a = "<< ranka <<endl;
cout<<"\nVaribles = "<< var <<endl;

// //ранг матрицы ab
  R = n;
  C = n+1;

  if(ab[0][0]==0){
    for(j=0;j<C;j++){
      z=-1;
      for(i=1;i<R;i++){
        if(ab[i][j]!=0){
          z=i;
          break;
        }
      }
      if(z!=-1){
        for( v=0;v<C;v++){
          float t=ab[0][v];
          ab[0][v]=ab[i][v];
          ab[i][v]=t;
        }
        break;
      }
    }
  }
  for(k=0;k<R-1;k++){
    for(i=k+1;i<R;i++){
      p=ab[k][k];
      q=ab[i][k];
      for(j=0;j<C;j++){
        ab[i][j]=p*ab[i][j] - q*ab[k][j];
      }
    }
  }
  z=0;
  for(i=0;i<R;i++){
    int c=0;
    for(j=0;j<C;j++){
      if(ab[i][j]==0){
        c++;
      }
    }
    if(c==C){
      z++;
    }
  }
  rankab = R-z;
  cout<<"\nRank ab = "<< rankab <<endl;

//проверка
if (ranka > rankab && ranka != var) {
  cout << "\nСистема - неопределенная" << '\n';
  return 0;
}
if (ranka < rankab){
  cout << "\nСистема - не совместна" << '\n';
  return 0;
}
if (ranka == rankab && ranka != var){
  cout << "\nСистема - не совместна" << '\n';
  return 0;
}

//LU разложение
 for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
       if (j < i)
       l[j][i] = 0;
       else {
          l[j][i] = a2[j][i];
          for (k = 0; k < i; k++) {
             l[j][i] = l[j][i] - l[j][k] * u[k][i];
          }
       }
    }
    for (j = 0; j < n; j++) {
       if (j < i)
       u[i][j] = 0;
       else if (j == i)
       u[i][j] = 1;
       else {
          u[i][j] = a2[i][j] / l[i][i];
          for (k = 0; k < i; k++) {
             u[i][j] = u[i][j] - ((l[i][k] * u[k][j]) / l[i][i]);
          }
       }
    }
 }

 cout << "\nL Decomposition is as follows..."<<endl;
 for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
       cout<<l[i][j]<<" ";
    }
    cout << endl;
 }

 cout << "\nU Decomposition is as follows..."<<endl;
 for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
       cout<<u[i][j]<<" ";
    }
    cout << endl;
 }
//ly=b
y[0] = b[0]/l[0][0];

for (i = 1; i < n; i++) {
  temp = 0;
  for (k = 0; k < i; k++) {
    temp = temp + l[i][k]*y[k];
  }
  y[i]=1/l[i][i]*(b[i]-temp);
}
  cout << '\n';
for (i = 0; i < n; i++) {
  cout << "y["<< i <<"] = " << y[i] << '\n';
}
cout << endl;

//ux=y
x[n-1] = y[n-1];

for (i = n-1; i > -1; i--) {
  temp = 0;
  for (k = i+1; k < n ; k++) {
    temp = temp + u[i][k]*x[k];
  }
  x[i]=y[i]-temp;
}

cout << '\n';
for (i = 0; i < n; i++) {
cout << "x["<< i <<"] = " << x[i] << '\n';
}
 return 0;
}
