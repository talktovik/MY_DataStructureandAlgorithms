#include<bits/stdC++.h>
#inlcude<time.h>

using namespace std;

int selectRandom(int x)
{
  static int result;
  static int count = 0;
  count++;
  if(count == 1)result = x;
  else
  {
    //rand() is predefined function in the header <bits/stdC++>, actually its in the header stdlib.h
    int i = rand()%count;
    if(i == count -1) result = x;
  }
  return result;
}

int main()
{
  int stream[] = {1,2,3,4}; //you can you the file I/O here as well
  int n = sizeof(stream)/sizeof(stream[0]); //count the Number of elements in the container[Array here! ]
  
  srand(time(NULL));
  for(int i = 0 i< n ;i++)
    std::cout<<"here we get the value  "<< selectRandom(stream[i])<<std::endl;
  return 1;
}
//Producing some unexpected results! 

//Discarded ! 
