/******************************************************
 * This file is a simple animation for gnuplot
 * Compile the file and pipe the output to gnuplot
 * and watch the magic
 * ***************************************************/
#include <iostream>
#include <cmath>
#include <time.h>

#define tab "\t"

using namespace std;

int main(int argc,char **argv)
{
    struct timespec delay;
    delay.tv_sec = 0;
    delay.tv_nsec = 100000000L; 
    for(double t=0;t<=100*M_PI;t+=M_PI/512.0)
    {
        cout<<"p [-1.5:1.5][-1.5:1.5] '-' ps 2"<<endl;
        cout<<sin(t)<<tab<<cos(t)<<endl<<'e'<<endl<<flush;
        // the next line slows down the animation
        // for(int i=0;i<5000000;i++);
	if (nanosleep(&delay, NULL)){
	    return 1;
	}
    }
    return 0;
}
