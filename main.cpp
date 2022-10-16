#include "common.hpp"
short ptr;

int addition(int a, int b){
	Log1<< "Inside " << __func__ ;
	//printf("%s\n", __func__);
	Log2<< a << "+" << b << "=" << a+b;
	return (a+b);
}

int main(int argc, char* argv[])
{
    if (argc >= 2)
		ptr = stoi(argv[1]);
	else
		ptr = 5; //if no argument..default set to 5 as we want least log info

	LogDebug("This is for testing purpose");

	for (int i = 0; i < 10; i++)
	{
		Log1 << "value of i: " << i ;
	}

	int a = addition(3,5);
	Log2<<"Sum is "<<a;

	/**UNDERSTANDING OF LOGs
	 * 0 is the highest priority and 5 is the least
	 * if 0, all logs will be printed
	 * if 1, debug logs will be skipped
	 * if 2, debug and trace logs will be skipped
	 * if 3, debug, trace and info skipped
	 * if 4, warn, error and fatal will be shown
	 * if 5, just fatal will be shown
	 * 
	 * for logging in other projects
	 * 1) copy commmon.hpp file in your project in src
	 * 2) define get_time_stamp function in func source file
	 * 3) include common.hpp in both main and func source files
	**/
    Log0 << "Done Debug";
    Log1 << "Done Trace";
    Log2 << "Done Info";
    Log3 << "Done Warn";
    Log4 << "Done Error";
    Log5 << "Done Fatal";
	return 0;
}

/**
 * mingw32-make.exe
 * 
 * ./.exe
 * 
 **/