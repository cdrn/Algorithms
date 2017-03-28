#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

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

    cout << inputData.gcount();


    for (string line; getline(inputData, line);)
    {

        //stream ifstreamchar to int//
        int numberAsInteger;
        //stringstream the line to an integer/
        istringstream(line) >> numberAsInteger;
        //put in the vector//
        A.push_back(numberAsInteger);
        //cout << A.size();
        inputData.close();
        }

    cout << A[0];

    int K = A.size()/2;
    int SizeOfArray = A.size();


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
        if(numsmaller<K and K <=(numsmaller + numequal))
        {
            return A[i];
            cout << "the median is " << A[i] << endl;
        }



    }
}



int main()
{

    MedianBruteforce();

}


