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

void populateCsv(){

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

    cout << A[0] << "\n" << A[1] << "\n" << A[2] << "\n";

    int SizeOfArray = A.size();
    int K = SizeOfArray/2;

    if(SizeOfArray%2 == 1){
        K++;
    }

    cout << A.size() << " " << K;


    for(int i = 0; i < (SizeOfArray-1); i++)
    {
        numsmaller = 0;
        numequal = 0;
        for(int j = 0; j < (SizeOfArray-1); j++)
        {
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
            return A[i];
        }
        else
        {
            cout << "median not found \n";
        }



    }
}



int main()
{

    MedianBruteforce();

}


