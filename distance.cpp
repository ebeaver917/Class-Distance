// Elliot Beaver
// Section 10

#include <iostream> 
#include "distance.h"
using namespace std;

//Stream IO overloads
ostream& operator<<(ostream& s, const Distance& d1)
{
   s << "("; 
  
   if(d1.miles != 0)
      s << d1.miles << "m ";
   
   if(d1.yards != 0)
      s << d1.yards << "y ";

   if(d1.feet != 0)
      s << d1.feet << "' ";

   s << d1.inches << "\"";
   
   s << ")";

   return s;
}
istream& operator>>(istream& i, Distance& d1)
{
   //char defined for input of parentheses and commas
   char s;

   i >> s >> d1.miles >> s >> d1.yards >> s >> d1.feet 
     >> s >> d1.inches >> s;

   d1.Set(d1.miles, d1.yards, d1.feet, d1.inches); 
}

//Arithmetic overloads
//Return new Distance objects with a single inches parameter
Distance operator+(Distance d1, Distance d2)
{
   return Distance(d1.totalInches + d2.totalInches);   
}
Distance operator-(Distance d1, Distance d2)
{
   return Distance(d1.totalInches - d2.totalInches);
}
Distance operator*(Distance d1, int m)
{
   return Distance(d1.totalInches * m);
}

//Comparison overloads
//Returns comparison of two total inch distances
bool operator<(const Distance& d1, const Distance& d2)
{
   return(d1.totalInches < d2.totalInches);
}
bool operator>(const Distance& d1, const Distance& d2)
{
   return(d1.totalInches > d2.totalInches);
}
bool operator<=(const Distance& d1, const Distance& d2)
{
   return(d1.totalInches <= d2.totalInches);
}
bool operator>=(const Distance& d1, const Distance& d2)
{
   return(d1.totalInches >= d2.totalInches);
}
bool operator==(const Distance& d1, const Distance& d2)
{
   return(d1.totalInches == d2.totalInches);
}
bool operator!=(const Distance& d1, const Distance& d2)
{
   return(d1.totalInches != d2.totalInches);
}

//Increment overloads
Distance& Distance::operator++()
{
   totalInches += 1;
   return *this;
}
Distance Distance::operator++(int)
{
   Distance temp;
   totalInches += 1;
   return Distance(totalInches);
}
Distance& Distance::operator--()
{
   totalInches -= 1;
   return *this;
}
Distance Distance::operator--(int)
{
   Distance temp;
   totalInches -= 1;
   return Distance(totalInches);
}

/* Constructors */

//Default Constructor
Distance::Distance()
{
   Set(0, 0, 0, 0);
}

//Single parameter (inches)/conversion constructor
Distance::Distance(int i)
{   
   if(Set(0, 0, 0, i) == false)
   {
      Set(0, 0, 0, 0);
   }
}

//Final constructor with all four distance qualitites
Distance::Distance(int m, int y, int f, int i)
{
   if(Set(m, y, f, i) == false)
   {
      Set(0, 0, 0, 0);
   }
}

/* Setter */
//Sets private data and checks for overflows/validity of 
//constructor parameters
bool Distance::Set(int m, int y, int f, int i)
{
   if(m < 0 || y < 0 || f < 0 || i < 0)
   {
      Set(0, 0, 0, 0);
     
      return false;
   }
   
   //loop through overflow on inches, feet, and yards until
   //max is reached
   else
   {      
      while(i >= 12)
      {
         f++;
         i -= 12;
      }
      while(f >= 3)
      {
         y++;
         f -= 3;
      }
      while(y >= 1760)
      {
         m++;
         y -= 1760;
      }
  
      //Set private data and calculate totalInches
      miles = m;
      yards = y;
      feet = f;
      inches = i;

      totalInches = (miles * 63360) + (yards * 36) +
                    (feet * 12) + (inches);

      return true;
   }         
}
