
//Parker Higgins
//Operating Systems Assignment 2
//4-21-22

// Banker's Algorithm
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
 

int main()
{
  // P0, P1, P2, P3, P4 are the Process names 
  int n, m, i, j, k;






//Starts the File I/O_____________________________________________________

    ifstream inFile;
    inFile.open("inputMatrices.txt");

    const int Num_Proc = 5; // Number of Processes
    const int Num_Resc = 3; // Number of Resources

    int allocate[Num_Proc][Num_Resc]; //Allocation Matrix
 
    int max[Num_Proc][Num_Resc]; //Max Matrix

    int avail[Num_Resc]; //Available Resources Matrix
 
    //*ensures the explanation line above the matrix in the .txt file is not used as matrix input*
    string line;
    getline(inFile, line);


//fills the allocate[][] from .txt file
    for (i = 0; i < Num_Proc; ++i){
        for(j = 0; j < Num_Resc; ++j){
            inFile >> allocate[i][j];
        }
    }

//fills the max[][] from .txt file
    for (i = 0; i < Num_Proc; ++i){
        for(j = 0; j < Num_Resc; ++j){
            inFile >> max[i][j];
        }
    }

    for(i = 0; i < Num_Resc; ++i){
        inFile >> avail[i];
    }


    inFile.close();

//End of the File I/O _______________________________________________________________________






int f[Num_Proc], ans[Num_Proc], ind = 0;

    for (k = 0; k < Num_Proc; k++) {

        f[k] = 0;

    }

    int need[Num_Proc][Num_Resc];

    for (i = 0; i < Num_Proc; i++) {

        for (j = 0; j < Num_Resc; j++)

        need[i][j] = max[i][j] - allocate[i][j];

    }

    int y = 0;

    for (k = 0; k < 5; k++) {

        for (i = 0; i < Num_Proc; i++) {

            if (f[i] == 0) {

                int flag = 0;

                for (j = 0; j < Num_Resc; j++) {

                    if (need[i][j] > avail[j]){

                        flag = 1;
                        break;
                    }
                }
 

                if (flag == 0) {

                    ans[ind++] = i;

                    for (y = 0; y < Num_Resc; y++)
                        avail[y] += allocate [i][y];
                        f[i] = 1;
                }
            }
        }
    }


  int flag = 1; //if flag is 0 the sequence is not safe, but if it is 1 it is safe.

  // checks if given sequence is safe
  for(int i = 0;i<Num_Proc;i++){

        if(f[i]==0){

            flag = 0;
            cout << "The given sequence is not safe\n";
            break;
        }
  }
 
  //if the given sequence is safe it will output it
  if(flag==1){

    cout << "The Safe Sequence is:" << endl;

      for (i = 0; i < Num_Proc - 1; i++)
        cout << " P" << ans[i] << " ->";

      cout << " P" << ans[Num_Proc - 1] <<endl;
  }

    return (0);
}