#include "Q1.cpp"
#include "functionsForMain.h"

void runTimeFunc1()
{
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	int i = ios_base::sync_with_stdio(false);// CHECK! I added the in i= , unless id does not work!
	string multiply();// Here you put the name of the function you wish to measure
	//auto end = chrono::high_resolution_clock::now(); --> I put below since it gave me an error the way they did it :(
	// Calculating total time taken by the program.
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start).count();
	double new_time_taken = (time_taken * 1e-9);
	ofstream myfile("Measure.txt",ios_base::app); // The name of the file
	myfile << "Time taken by function multiply is : " << fixed << new_time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
}

void runTimeFunc2()
{
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	int i = ios_base::sync_with_stdio(false);// CHECK! I added the in i= , unless id does not work!
	string karatsubaRec();// Here you put the name of the function you wish to measure
	//auto end = chrono::high_resolution_clock::now(); --> I put below since it gave me an error the way they did it :(
	// Calculating total time taken by the program.
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start).count();
	double new_time_taken = (time_taken * 1e-9);
	ofstream myfile("Measure.txt",ios_base::app); // The name of the file
	myfile << "Time taken by function karatsubaRec is : " << fixed << new_time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
}

void runTimeFunc3()
{
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	int i = ios_base::sync_with_stdio(false);// CHECK! I added the in i= , unless id does not work!
	string karatsubaStack();// Here you put the name of the function you wish to measure
	//auto end = chrono::high_resolution_clock::now(); --> I put below since it gave me an error the way they did it :(
	// Calculating total time taken by the program.
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start).count();
	double new_time_taken = (time_taken * 1e-9);
	ofstream myfile("Measure.txt",ios_base::app); // The name of the file
	myfile << "Time taken by function karatsubaStack is : " << fixed << new_time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
}
