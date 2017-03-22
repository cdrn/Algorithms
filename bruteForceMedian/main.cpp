#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{

    //Declare variables//
    int numsmaller;
    int numequal;
    vector<int> A;
    int numberRead;


    //Open a file with filestream//
    ofstream inputData;
    inputData.open("inputData.csv");
    while (inputData > numberRead)
    {
        A.push_back(numberRead);
    }
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
        }



    }

}
