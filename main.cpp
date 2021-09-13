/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar(Car car); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior(Car car);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  
};



/*
Thing 1) Guitar
5 properties:
    1) Number of pickups (int)
    2) Number of strings (int)
    3) Logo name (std::string)
    4) Color (std::string)
    5) Tuning system (bool)
3 things it can do:
    1) Vibrate
    2) Amplify sound
    3) Consume electricity
 */

/*
Thing 2) Vending mashine
5 properties:
    1) Amount of candy (int)
    2) Amount of drinks (int)
    3) Inserted coins  (int)
    4) Cooling system (bool)
    5) Tags (std::string)
3 things it can do:
    1) Charge customer
    2) Feed customer
    3) Cool down 
 */

/*
Thing 3) Phone
5 properties:
    1) Number of speakers (int)
    2) Serial number (int)
    3) Amount of storage (double)
    4) Phone model (std::string)
    5) Camera resolution (int)
3 things it can do:
    1) Receive calls
    2) Receive text messages
    3) Make noise
 */

/*
Thing 4) TV station
5 properties:
    1) Number TV channel chains (int)
    2) Number of employees (int)
    3) Number of cameras (int)
    4) Name of the TV station (std::string)
    5) Satelite range (float)
3 things it can do:
    1) Broadcast TV channels
    2) Produce video material
    3) Receive feedback from viewers
 */
/*
Thing 5) Engine
5 properties:
    1) Amount of Fuel intake (float)
    2) Cylinders (int)
    3) Compressors (int)
    4) Oil indicator (bool)
    5) Piston speed (int)
3 things it can do:
    1) Creating motion 
    2) Convert energy
    3) Produce heat
 */

/*
Thing 6) Wings
5 properties:
    1) Panels (int)
    2) Flaps (int)
    3) Lamp color (std::string)
    4) Warning tag text (std::string)
    5) Ribs (int)
3 things it can do:
    1) Fold the panels
    2) Holds the plane in the air
    3) Holds the engines
 */

/*
Thing 7) Wheels
5 properties:
    1) Plugs (int)
    2) Manufactor text (std::string)
    3) Amount of air (double)
    4) Rims (int)
    5) Weight (int)
3 things it can do:
    1) Roll
    2) Balance the plane on the ground
    3) Steer the plane on the ground
 */

/*
Thing 8) Seats
5 properties:
    1) Height in cm (int)
    2) Width in cm  (int)
    3) Lifewest (bool)
    4) Number of seats (int)
    5) color (std::string)
3 things it can do:
    1) Carry passengers 
    2) Fold back
    3) Store magazines
 */

/*
Thing 9) Brakes
5 properties:
    1) Radius in cm (float)
    2) Weight (int)
    3) Brake pads (int) 
    4) Wear indicator (std::string)
    5) Chassis hardness (float)
3 things it can do:
    1) Show how much wear it is on the brakes
    2) Stop the wheels from moving
    3) Slow down the airplane gradually
 */

/*
Thing 10) Airplane
5 properties:
    1) Engine
    2) Wings
    3) Wheels
    4) Seats
    5) Brakes
3 things it can do:
    1) Fly in the air
    2) Drive on the ground
    3) Brake
 */



/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
