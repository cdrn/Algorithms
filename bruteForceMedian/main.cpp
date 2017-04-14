//INCLUDES//
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <tuple>
//system clock includes//
#include <ctime>
#include <ratio>
#include <chrono>


using namespace std;
using namespace std::chrono;


//GLOBAL VARIABLES//

//declare a new type of vector to hold tuples
typedef vector < tuple<int, int, float> > tuple_list;



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
tuple<long, long, float> MedianBruteforce()
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

            //return the median and TERMINATE//
            return make_tuple(SizeOfArray, operationsCounter, time_span.count());


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
    float cumulativeruntimes;
    long cumulativeoperations;
    int arraysize;
    float meanruntimes;
    long meanoperations;

    tuple_list runtime_tuples;


    //PROVE THE ALGORITHM WORKS//
    MedianBruteforce();


    //Very hacky code to run arraysizes a certain number of times and take an average.//
    //could be made orthoganal in a method but who has the time//
    //Just edit the condition to change the number of times to run//

//    for(int i=0; i<1000; i++)
//    {
//        //increment arraysize and erase vector of results//
//        numberOfValues = numberOfValues + 10;
//        runtime_tuples.clear();
//
//        for(int j=0; j<10; j++)
//        {
//
//            populateCsv(numberOfValues);
//            runtime_tuples.emplace_back(MedianBruteforce());
//
//        }
//
//        for(n : runtime_tuples){
//            arraysize = get<0>(n);
//
//            cumulativeoperations += get<1>(n);
//            cumulativeruntimes += get<2>(n);
//
//        }
//
//        meanoperations = cumulativeoperations/10;
//        meanruntimes = cumulativeruntimes/10;
//        //Export the results to Excel (using append)
//        ofstream runtimes;
//        runtimes.open("runtimes.csv", fstream::app);
//        runtimes << "\r\n" << arraysize << "," << meanoperations << "," << meanruntimes;
//        runtimes.close();
//        //reset our calculation counters
//        meanoperations, cumulativeoperations, meanruntimes, cumulativeruntimes = 0;
//
//    }

}


