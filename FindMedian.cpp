
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

void FindMedian(string filename, ifstream& ifs);

int main() { 
ifstream ifs; 
string fname = "Num.txt"; 
FindMedian(fname, ifs);
return 0;
}

void FindMedian(string filename, ifstream& ifs){

    ifs.open(filename);
    if (ifs.fail( )){
        cout << "Input file opening failed.\n";
        exit(1);
    }
    int num1(0);
    ifs >> num1;

    ofstream ofs;
    ofs.open("median_output.dat");
    if (ofs.fail( )){
        cout << "Output file opening failed.\n";
        exit(1);
 }

   int temp = 0;
   int size = 0;
   int num;
   int i = 0;

   int arr[size];

   while(ifs >> num){
       arr[i] = num;
       i++;
   }


   for(int i = 0;i<size;i++)
       for(int j = i;j<size;j++){
           if(arr[i] > arr[j]){                          
               temp = arr[i];
               arr[i] = arr[j];
               arr[j] = temp;
           }
       }      
   
   int m = size/2;      
   
   if(size % 2 == 0){    
       ofs << (arr[m-1] + arr[m])/2 << endl;
       cout << (arr[m-1] + arr[m])/2;
   }

   else{     
       ofs << arr[m] << endl; 
       cout << arr[m];
   }   
    
}