// Elliot Beaver
// Section 10

class Distance
{

//Stream IO overload prototypes
friend std::ostream& operator<<(std::ostream& s, const Distance& d1);
friend std::istream& operator>>(std::istream& i, Distance& d1);

//Arithmetic overload prototypes
friend Distance operator+(Distance d1, Distance d2);
friend Distance operator-(Distance d1, Distance d2);
friend Distance operator*(Distance d1, int m);

//Comparison overload prototypes
//All params passed by const reference because the actual objects
//arent manipulated
friend bool operator<(const Distance& d1, const Distance& d2);
friend bool operator>(const Distance& d1, const Distance& d2);
friend bool operator<=(const Distance& d1, const Distance& d2);
friend bool operator>=(const Distance& d1, const Distance& d2);
friend bool operator==(const Distance& d1, const Distance& d2);
friend bool operator!=(const Distance& d1, const Distance& d2);

public:

   //Constructor prototypes
   Distance();
   Distance(int i);
   Distance(int m, int y, int f, int i);

   //Set prototype
   bool Set(int m, int y, int f, int i);

   //Increment prototypes
   Distance& operator++();
   Distance operator++(int);
   Distance& operator--();
   Distance operator--(int);

private:

   //Member data used for creating a distance
   //totalInches is used to make overloading more efficient
   int miles,
       yards,
       feet, 
       inches,
       totalInches;

};
