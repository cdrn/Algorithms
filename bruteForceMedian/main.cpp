//INCLUDES//
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
//system clock includes//
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std;
using namespace std::chrono;


//simple method to populate a dummy csv
void populateCsv(int numberOfValues)
{
    ofstream outputData;
    outputData.open("inputData.csv");
    //seed srand using time in ms by getting it from sys clock//
    milliseconds ms = duration_cast< milliseconds >(
    system_clock::now().time_since_epoch()
    );
    //count ms and seed//
    srand(ms.count());

    for(int i=0; i<numberOfValues; i++)
    {
        //seed rand with time
        outputData << rand()%100 << "\r\n";

    }
    outputData.close();

}


//The method which reads in a CSV and executes the median bruteforce//
int MedianBruteforce()
{
    //Declare variables//
    int numsmaller;
    int numequal;
    int iterationCounter;
    vector<int> A;
    string inputDataString;
    duration<double> time_span;

    //Open a file with filestream//
    ifstream inputData;
    inputData.open("inputData.csv");
    //Check if stream opens, if not return error//
    if(inputData.is_open())
    {
        cout << "stream opened" << endl;
    }

    cout <<"streamcount is: " <<  inputData.gcount() << "\n";


    for (string line; getline(inputData, line);)
    {

        //stream ifstreamchar to int//
        int numberAsInteger;
        //stringstream the line to an integer/
        istringstream(line) >> numberAsInteger;
        //put in the vector//
        A.push_back(numberAsInteger);

    }

    //cout << A[0] << "\n" << A[1] << "\n" << A[2] << "\n";

    //Save time before algorithm run//
    steady_clock::time_point t1 = steady_clock::now();



    int SizeOfArray = A.size();
    int K = SizeOfArray/2;
    int operationsCounter = 0;

    if(SizeOfArray%2 == 1)
    {
        K++;
    }

    cout << A.size() << " " << K << "\n";


    for(int i = 0; i < (SizeOfArray-1); i++)
    {
        numsmaller = 0;
        numequal = 0;
        for(int j = 0; j < (SizeOfArray-1); j++)
        {

            //operation counter//
            operationsCounter++;
            if(A[j] < A[i])
            {
                numsmaller = numsmaller + 1;

            }
            else
            {
                if (A[j] == A[i])
                {
                    numequal = numequal + 1;

                }
            }
        }
        if(numsmaller < K and K <= (numsmaller + numequal))
        {

            cout << "the median is " << A[i] << "\n";
            cout << "the number of operations is " << operationsCounter << " with array size " << SizeOfArray << "\n";

            //operation counter//

            //save time after algorithm completion//
            steady_clock::time_point t2 = steady_clock::now();
            //cout t2-t1
            time_span = duration_cast<duration<double>>(t2 - t1);
            cout << "It took me " << time_span.count() << " seconds." << "\n";
            //Export the results to Excel
            ofstream runtimes;
            runtimes.open("runtimes.csv", fstream::app);
            runtimes << "\r\n" << SizeOfArray << "," << operationsCounter << "," << time_span.count();
            runtimes.close();

            //return the median and TERMINATE//
            return A[i];

            ;
        }
        else
        {
            cout << "median not found \n";
        }



    }


}



int main()
{
    int numberOfValues = 0;

    for(int i=0; i<100; i++)
    {
        numberOfValues = numberOfValues + 100;

        for (int j=0; j<5; j++)
        {
            populateCsv(numberOfValues);
            MedianBruteforce();

        }

    }

}


