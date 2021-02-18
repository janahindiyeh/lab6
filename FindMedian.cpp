
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

void FindMedian(string filename, ifstream& ifs);


void FindMedian(string filename, ifstream& ifs){

    ifs.open(filename);


    ofstream ofs;


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
       ofs << a << endl;


   }

   else if(size == 1){
       ofs << arr[m] << endl;
       
   }

   else{     
       ofs << arr[m] << endl; 
       
   }   
    
    ifs.close();
    ofs.close();
}

