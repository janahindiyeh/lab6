
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

void FindMedian(string filename, ifstream& ifs);


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
   
   if(size % 2 == 0){    
       ofs << (arr[m-1] + arr[m])/2 << endl;
   }

   else{     
       ofs << arr[m] << endl; 
   }   
    
}

