//*********************************************
// interface for mythread versions of blocking functions
//
// Author: Phil Howard
//
#pragma once

//*********************************************
// print the specified string
//
// Thread safety: mythread safe
int myprints(char *str);

//********************************************
// replacement for fgets() from stdin
//
// Thread safety: mythread safe
int mygets(char *buffer, int size);

//********************************************
// replacement for sleep.
// Note: the sleep may be less than the specified about by up to a fraction
// of a second
//
// Thread safety; mythread safe
int mysleep(int seconds);

