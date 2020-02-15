
/*
//Stewart Fred Sheppard
Modified date: 2-15-20
Dev-C++
A Program to output the textual represenation of entered integers.
tests -32 billion to +32 billion
//Writen by Tyson McMillan
// 11-27-11,10-2-2015 updated
//Inspired in part by http://www.dreamincode.net/code/snippet1759.htm
*/
#include <iostream>
#include <string> //using the string library important for the below
#include <sstream>
#include<cstdlib>
using namespace std;

//Function to convert String Number to Doubles
template <class out_type, class in_value> out_type convert(const in_value & t)
{

    std::stringstream ss;
    ss << t;
    out_type result;
    ss >> result;
    
    return result;
}

//Function to check if an entered value is of type double
bool checkForInteger(std::string const& s) 
{ 
  std::istringstream ss(s); 
  int d; 
  return (ss >> d) && (ss >> std::ws).eof(); 
} 

int number = 0; //the entered number
string myNumberAsString = "";

//This takes an integer and returns it in an English representation
string EnglishNumber(int n) 
{
  // set up our core numbers from which other numbers can be constructed
  const int numbers[] = {0,1,2,3,4,5,6,7,8,9,
  10,11,12,13,14,15,16,17,18,19,20,30,40,50,60,70,80,90,
  100,1000,1000000,1000000000};
  
  const string english[] = {"zero", "one", "two", "three", "four", "five", "six",
  "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
  "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
  "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety",
  "hundred", "thousand", "million","billion"};
  
  // count of core numbers (size of above arrays)
  const int count = 32;
  
  // two strings, one holding our number so far, and another temp.
  string returnString = "";
  string temp;
  
  if(n < 0) 
  {
    n = -n;
    returnString = "negative";
  }
  
  // simply return the number if it already exists in the array above
  for(int i = 0; i < count; i++) 
  {
    if(n == numbers[i]) 
    {
      if(returnString.size()) // this is a negative number, so add qualifier
        return returnString + " " + english[i];
        
      return english[i]; // positive number, just return it
    }
  }
  
  // otherwise we have to contruct it
  for(int i = count - 1; i > 0; i--) 
  {
    if(n >= numbers[i]) 
    {
      temp = english[i];

      // e.g. if n = 5000, then we have "thousand" + n/1000 which equals 5 so,
      //      "five" + " " + "thousand"
      if(n >= 100)
        temp = EnglishNumber(n / numbers[i]) + " " + temp;
        
      if(returnString.size() > 0) returnString = returnString + " ";
      returnString = returnString + temp; // add this number to our existing number

      // remove this number from n, to complete construction of the number
      n = n - (int)(n / numbers[i]) * numbers[i];
    }
  }
  
  return returnString;
}

int main()
{
     while (myNumberAsString != "*") 
     {
        
        //Give the user instructions to order, implement these in your program
        cout << "\nEnter an Integer. Press (* to exit): ";
           
        //Accept input of the nubmber as a string
        getline(cin, myNumberAsString );
                         
       // This code converts from string to number (double) safely.
       //General syntax for calling convert String to Double function is...
       number = convert<int, string>(myNumberAsString);
                                          
       if (checkForInteger(myNumberAsString))
       {

          //It is now safe to perform calculations on the number 
          //It has been verified as a valid number
         cout << "\nThe Number you entered is: " <<  number << endl;
         cout << "Converted, your number is: ";
         cout << EnglishNumber(number);//  Added from line 42, and input variable "number".  
         cout << endl;
        
       }
       else
       {
           if(myNumberAsString != "*")
           {
                   cout << "Invalid INTEGER number, please try again." << endl;
           }        
           
       }
       
       if(myNumberAsString == "*")
       {
            cout << "Exiting Calculation Sequence mode..." << endl;
       }
            
       
     }//end while loop
     
    
    
    system("pause");
    return 0;   
}
