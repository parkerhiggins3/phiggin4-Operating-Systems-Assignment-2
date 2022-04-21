# Operating-Systems-Assignment-2-Parker-Higgins
Assignment 2 for Parker Higgins in the operating systems class of spring 2022

Hello, This is my operating systems programming assignment 2 github repository.

///////////////////////////////////////////////////////////////////////////////////////////

Documentation:
  
  In this repository, you should find two files: 'banker.cpp' and 'banker_input.txt'.
  


  Inside of the banker_input.txt there contains three matrices with the corresponding values from the example in the assignment description. It is important to note that banker.cpp will read in the allocation (5X3) matrix first, the maximum (5X3) matrix second and the available (1X3) matrix last. When altering the banker_input.txt file with your own data, it is critical that you follow this given order. Also, do not add any additional integers or strings to the .txt to ensure that it does not crash the file I/O. If you would like to use your own data, please replace the given matrix integers that already exist.

For banker.cpp, the code works as follows:

  Three 2-D arrays are created for the allocation[], maximum[] and need[] matrices. An additional array is created for the available resources. 'banker_input.txt' is then opened and the inputted matrices (allocated, maximum and available) are filled with their respective input values. Next, an array 'f[]' has its values initialized to 0; this array indicates whether each process has had its resource request granted (0 = no, 1 = yes). The need matrix then stores the values of how many resources each process is requesting. The program then goes from process to process comparing its need matrix values to the available matrix that keeps a running counter of how many resources are available for each resource type (A,B,C). If a process is requesting more resources than are available at the tim, it skips that process and comes back to it when the system has enough available resources or if it is determined the sequence is unsafe. If the sequence is safe, the process order is stored in its own array: 'ans[]' and this sequence is printed to the terminal.
  
  Compilation:

  To compile and run this program, download the two files given above into a terminal directory and run these specific commands:

  g++ -o bankerAlg bankerAlg.cpp 
  ./bankerAlg
  
Thank you for downloading this program.
