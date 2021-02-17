
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;


double MeanAverage (string filename);
double StdDev (string filename);
double Median(string filename);


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
      
      cout << "Stddev = " << StdDev(filename) << endl;

   
   in_stream.close();


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


