
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

    ofstream ofs;
    ofs.open("median_output.dat");
    if (ofs.fail( )){
        cout << "Output file opening failed.\n";
        exit(1);
    }

    int num;
    int size(0), i(0);
   while(ifs >> num){
       size++;
   }

   ifs.close();

   ifs.open(filename.c_str());

   int temp = 0;

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
   double a = 0; 
   
   if(size % 2 == 0){    
       a = (double)(arr[m-1] + arr[m])/2;
       ofs << a;

   }

   else if(size == 1){
       ofs << arr[m] << endl;
       cout << arr[m];
   }

   else{     
       ofs << arr[m] << endl; 
   }   
    
}

