/*
Project 3 - Part 1d / 5
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

    The goal of this step is to get you to think about breaking down an object into smaller and smaller objects, 
    until the smallest object is made of up only C++ primitives and std::string. 

    Continuing the previous example:  Cell Phone

    A Cell Phone is made up of the following 5 properties/sub-objects and 3 actions:
        Display
        Memory
        CPU
        Radio
        Applications
    3 actions:
        make a call
        send a text
        run an application.

    These 5 properties can be broken down into their own sub-objects and properties. 

    If we break down the first property 'Display' into its 5 properties we get:
        brightness
        amount of power consumed.
        pixels
        width in cm
        height in cm

    the Display's brightness can be represented with a Primitive, such as a double. 

    The amount of power consumed can also be represented with a Primitive, such as a float or integer (i.e. 250mWa)
    
    The 'pixels' property must be represented with an array of Pixel instances, as the screen has more than 1 row of pixels.
        Arrays have not been discussed and can't be used in this project.
        Instead, we can use an Integer primitive to store the Number of Pixels:

    Display:
        Number of Pixels
        Amount of Power consumed (milliwatt-hours)
        Brightness
        width in cm
        height in cm
************************

1) Fill in #5 - #9 with plain-english UDTs for the 5 properties you created for UDT #10
    example: 
        If #10's first property was 'Engine', then your `Thing 5)` will be `Engine`
        you will need to provide 5 properties and 3 member functions of that Engine object in plain English
        Remember to pick properties that can be represented with 'int float double bool char std::string'
2) write the name of the primitive type you'll be using after each property
    pick properties that can be represented with 'int float double bool char std::string'
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            width in cm (int)
            height in cm (int)

3) move Thing 5-9 to between your Thing 4 and Thing 10.
*/


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
