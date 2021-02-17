
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;


double MeanAverage (string filename);
double StdDev (string filename);
double Median(double arr[],int size);


int main() 

{
   double next, average(0), top(0), sum(0);
   int count(0);
   string filename("");

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(3);

   cout << "Enter filename: ";
   cin >> filename;
   
   ifstream in_stream;
   in_stream.open(filename);
   
   if(in_stream.fail())
   {
      cerr << "Input file opening failed.\n";
      exit(1);
   }
   else
   {  
      
      average = MeanAverage(filename);}
      in_stream.close();

      in_stream.open(filename);

      cout << "Mean = " << MeanAverage(filename) << endl;
      

    double num;
    int size(0), i(0);
   while(in_stream >> num){
       size++;
   }

   in_stream.close();

   in_stream.open(filename.c_str());
   //Creates a double array with the 'size'
   double array[size];
   //Reads elements from file into the array
   while(in_stream >> num){
       array[i] = num;
       i++;
   }
   //Closes the file
   in_stream.close();

   double median = Median(array,size);
   cout << "Median = " << fixed << median << endl;

   cout << "Stddev = " << StdDev(filename) << endl;


   return 0;
}


double MeanAverage(string filename)
{

    double number, total = 0;
    int count = 0;

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(3);

    ifstream in_stream(filename);

    while (in_stream >> number) {
        total += number;
        count++;
    }

    return total / count;
}

double StdDev (string filename)
{
    double avg(0), stdvTop(0), next;
    int count(0);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    ifstream in_stream(filename);

    avg = MeanAverage(filename);

    while(in_stream >> next)
      {
         stdvTop += pow((next - avg), 2);
         count ++;
      }

   double stdv = sqrt(stdvTop / (count-1));
   return (stdv);
}

double Median(double arr[],int size){
   double temp = 0;
   
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
       return (arr[m-1] + arr[m])/2;
   }

   else{     
       return arr[m]; 
   }     
}




