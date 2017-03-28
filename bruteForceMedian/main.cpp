#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main()
{

    //Declare variables//
    int numsmaller;
    int numequal;
    vector<int> A;
    int numberRead = 0;
    string inputDataString;


    //Open a file with filestream//
    std::ifstream inputData;
    inputData.open("inputData.csv");
    inputData >> inputDataString;

    inputData.close();
    //



    cout << "Hello world!" << endl;



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
            cout << A[i] << endl;
        }



    }

}
