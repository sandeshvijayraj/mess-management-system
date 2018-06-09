#include<iostream.h>
#include<conio.h>
#include<time.h>
#include<string.h>
char* timer()
{
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,sizeof(buffer),"%d-%m-%Y",timeinfo);
  return buffer;
}