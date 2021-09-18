 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
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
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */
struct Step
{
    void stepForward();
    int stepSize();

};

void Step::stepForward()
{
    std::cout << "stepped forward" << std::endl;
}
int Step::stepSize()
{  
    int stepSize = 2;
    return stepSize;
}
struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;
    Step leftfoot;
    Step rightfoot;

};



 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */




struct Guitar
{
    
    int numberOfPickups = 2;
    int numberOfStrings = 6;
    std::string logoName = "Gibson";
    std::string color = "Black";
    bool tuningSystem = true;

    struct String
    {
        std::string winding = "flatwound";
        std::string manufactor = "Earnie ball";
        float length = 100;
        std::string material;
        int age;

        void breakDown(float pressure, float thickness );
        void oxide (int age);
        void kill (int sharpness, float length);
    };

    void vibrate(String string);
    void amplify(bool guitarPluggedIn, int howLoud);
    float electricity(float time);
    
};

void Guitar::String::breakDown(float pressure, float thickness)
{
    if(pressure > 100 & thickness < 0.9f)
    {
        std::cout << "High pressure on string: " << pressure << " is breaking the string" << std::endl;
    }
}

void Guitar::String::oxide(int ageMonths)
{
    if(ageMonths > 10)
    {
        std::cout << "string is starting to oxidize" << std::endl;
    }
}

void Guitar::String::kill(int sharpness, float lengthCm)
{
    if(sharpness > 10 & lengthCm > 100)
    {
        std::cout << "string could be dangerous" << std::endl;
    }
}

void Guitar::vibrate(String string)
{
    if(string.length > 0.1f)
    {
        std::cout << "guitar is vibrating" << std::endl;
    }
}

void Guitar::amplify(bool guitarPluggedIn, int howLoud)
{
    if(guitarPluggedIn)
    {
        if(howLoud > 10)
        {
            std::cout << howLoud << std::endl;
        }
    }
    else
    {
        std::cout << "Mute amp" << std::endl;
    }
}

float Guitar::electricity(float time)
{
    if (time > 0)
    {
        return time; 
    }
    return 0;
}

struct VendingMashine
{
    
    int amountOfCandy = 50;
    int amountOfDrinks = 50;
    int InsertedCoins = 100;
    bool coolingSystem = true;
    std::string itemTag = "Orego";

 
    float chargeCustomer(bool creditcard, float itemPrice);
    void feedCustomer(int amountOfCandy);
    void coolDownMashine(int temperature, int duration);
};

float VendingMashine::chargeCustomer(bool creditcard, float itemPrice)
{
    if(!creditcard)
    {
        return itemPrice-InsertedCoins;           
    }
    return 0;
}

void VendingMashine::feedCustomer(int amountOfCandyOrdered)
{
    if(amountOfCandyOrdered > 0)
    {
        std::cout << itemTag << std::endl;
    }
   
}

void VendingMashine::coolDownMashine(int temperature, int duration)
{
    if(temperature > 30)
    {
        for(int i = 0; i < duration; i++)
        {
            std::cout << "cooling down the mashine" << std::endl; 
        }
    }

}

struct Phone
{

    int numberOfSpeaker = 2;
    int serialNumber = 13431413;
    double storage = 34.3434332;
    std::string model = "genX";
    int cameraResolution = 12;
  
    void receiveCall(bool isPhoneMuted);
    std::string receiveText(bool receiveTextEnabled, std::string textMessage);
    void makeNoise(int numberOfSpeaker, int volume);

};

void Phone::receiveCall(bool isPhoneMuted)
{
    if(!isPhoneMuted)
    {
        std::cout << "Receiving a call" << std::endl;
    }

}

std::string Phone::receiveText(bool receiveTextEnabled, std::string textMessage)
{
    if(receiveTextEnabled)
    {
        return textMessage;
    }
    return "text message disabled";   
}

void Phone::makeNoise(int numberOfSpeakers, int volume)
{
    
    for (int i = 0; i < numberOfSpeakers; i++)
    {
        if(volume > 0)
        {
            volume = 10;
        }
    }

}

struct TVStation
{
   
    int channelChains = 24;
    int numberOfEmployees = 202;
    int numberOfCameras = 12;
    std::string tvStationName = "Nickelodeon";
    float sateliteRange = 180.0f;

    struct Studio
    {
        bool isNewsStudio = false;
        int lightbulbs = 1000;
        bool isOnAir = false;
        int cameras = 5;
        float size = 100;

        void transmitVideo(bool cameraIsOn);
        void transmitAudio(bool microphone);
        bool getOnAirStatus(bool isCameraOn);

    };

    void broadcastChannel(std::string channel);
    void produceVideo(Studio studio);
    std::string getFeedback(int date, std::string feedBack);

};

void TVStation::Studio::transmitVideo(bool cameraIsOn)
{
    if(cameraIsOn)
    {
        std::cout << "transmitting video" << std::endl;
    }
    else
    {
        std::cout << "stop transmitting video" << std::endl;
    }

}

void TVStation::Studio::transmitAudio(bool microphone)
{
    if(microphone)
    {
        std::cout << "transmitting audio" << std::endl;
    }
    else
    {
        std::cout << "stop transmitting audio" << std::endl;
    }

}
 bool TVStation::Studio::getOnAirStatus(bool isCameraOn)
 {
    isOnAir = isCameraOn;
    return isOnAir;
 }

void TVStation::broadcastChannel(std::string channel)
{
    if(channel == "CNN")
    {
        std::cout << channel << std::endl;
    }
    else
    {
        std::cout << tvStationName << std::endl;
    }

}

 void TVStation::produceVideo(Studio studio)
 {
     if(studio.cameras > 0)
     {
         std::cout << "produce video" << std::endl;
     }
     else
     {
         std::cout << "get cameras" << std::endl;
     }
 }
 
std::string TVStation::getFeedback(int date, std::string feedBack)
{  
    if(date > 0)
    {
        return feedBack;
    }
    return "";
}

struct Engine 
{
  
    float fuelIntake = 10000.0f;
    int cylinders = 12;
    int compressors = 5;
    bool oilIndicator = true;
    int pistonSpeed = 45;

    void createMotion(float speed);
    void convertEnergy(float time, float duration);
    void produceHeat(bool oilIndicator);

};

void Engine::createMotion(float speed)
{
    if(speed > 0)
    {
        std::cout << "Create motion" << std::endl;
    }
    else
    {
        std::cout << "Do not move" << std::endl;
    }
}

void Engine::convertEnergy(float time, float duration)
{
    while(time < duration)
    {
        std::cout << "Converting energy" << std::endl;
    }
}

void Engine::produceHeat(bool hasOilIndicator)
{
    if(hasOilIndicator && pistonSpeed>10)
    {
        std::cout << "Heating up" << std::endl;
    }

}
struct Wings
{
    int panels = 10;
    int flaps = 20;
    std::string lampColor = "green";
    std::string tagText= "SAS";
    int ribs = 40;

    void foldPanels(int panels);
    void holdPlaneUp(float planeWeight);
    void holdTheEngines(float engineWeight);
};

void Wings::foldPanels (int numbOfPanels)
{
    if (numbOfPanels > 0)
    {
        std::cout << "Folding the panels" << std::endl;
    }
    else
    {
        std::cout << "No panels to fold" << std::endl;
    }
}

void holdPlaneUp(float planeWeight)
{
    if(planeWeight < 100000)
    {
        std::cout << "holding the plane in the air" << std::endl;
    }
    else
    {
        std::cout << "plane is too heavy" << std::endl;
    }
}

void holdTheEngines(float engineWeight)
{
    if(engineWeight < 1000)
    {
        std::cout << "holding the engines" << std::endl;
    }
    else
    {
        std::cout << "engine is too heavy" << std::endl;
    }

}
struct Wheels
{
    int plugs = 10;
    std::string manufactor = "Goodyear";
    double amountOfAir = 1000000.000;
    int rims = 10;
    int wheelWeight = 100;


    void startRolling(bool forward, float speed);
    void balancePlane(float planeWeight);
    void turnTheWheel(std::string direction);
};

void Wheels::startRolling(bool forward, float speed)
{
    if(forward&&speed > 0)
    {
        std::cout << "start rolling forward, speed: " << speed << std::endl;
    }
    else
    {
         std::cout << "Can not start, no direction " << std::endl;
    }
}

void Wheels::balancePlane(float planeWeight)
{
    if(planeWeight < 10000)
    {
        std::cout << "wheels can balance the plane" << std::endl;
    }
    else
    {
        std::cout << "plane is too heavy for the wheels" << std::endl;
    }
}

void Wheels::turnTheWheel(std::string direction)
{
    if(direction == "Forward")
    {
        std::cout << "going forward" << std::endl;
    }
    else if(direction == "left")
    {
        std::cout << "going left" << std::endl;
    }
    else
    {
        std::cout << "going right" << std::endl;
    }


}
struct Seats
{

    int seatHeight = 100;
    int seatWidth = 50;
    bool lifeWest = false;
    int numberOfSeats = 500; 
    std::string seatColor = "grey";

    void carryPassangers(int numberOfseats, float passengersWeight);
    void foldBack(int seatHeight);
    void store(int numberOfmagazines);

};

void Seats::carryPassangers(int numberOfseats, float passengersWeight)
{
    if (numberOfseats > 200 && passengersWeight < 16000)
    {
        std::cout << "passengers weight - ok" << std::endl;
    }
    else
    {
        std::cout << "passengers weight - too heavy" << std::endl;
    }

}

void Seats::foldBack(int seatsHeight)
{
    if(seatsHeight < 100)
    {
        std::cout << "fold back the seat" << std::endl;
    }
    else
    {
        std::cout << "fold up the seat" << std::endl;
    }

}

void Seats::store(int numberOfmagazines)
{
    if(numberOfmagazines < 10)
    {
        std::cout << "store the magazines" << std::endl;
    }
    else
    {
        std::cout << "do not store the magazines" << std::endl;
    }


}
struct Brakes
{

    float brakeRadius = 20.5f;
    int brakeWeight = 20; 
    int brakePads = 10; 
    std::string wearIndicator = "bad";
    float chassisHardness = 24.5f;


    std::string showWear(std::string wearIndicator);
    void stop(float time);
    void decelerate(float duration);

};

std::string Brakes::showWear(std::string wearDisplay)
{
    if(wearDisplay=="need replacement") 
    {
        return "replace the brakes";
    }
    return "brakes are fine";  
}

void Brakes::stop(float time)
{
    if(time < 100000.9f)
    {
        std::cout << "Using the brakes" << std::endl;
    }
}

void Brakes::decelerate(float duration)
{
    for(int i = 0; i < duration; i++)
    {
        std::cout << "decelerate" << std::endl; 
    }
}

struct Airplane
{
 
    Engine engine;
    Wings wings;
    Wheels wheels;
    Seats seats;
    Brakes brakes;

 
    void fly(std::string destination, float speed);
    void driveOnGround(bool isAttached);
    void brake(bool isFlying);

};

void Airplane::fly(std::string destination, float speed)
{
    if(destination == "Stockholm" && speed > 0)
    {
        std::cout << "Flying to Stockholm" << std::endl;
    }
    else
    {
        std::cout << "Standing still" << std::endl;
    }

}

void Airplane::driveOnGround(bool isAttached)
{
    if(wheels.amountOfAir > 100000 && isAttached)
    {
        std::cout << "Drive on the ground" << std::endl;
    }
    else
    {
        std::cout << "Stand still" << std::endl;
    }
}

void Airplane::brake(bool isFlying)
{
    if(!isFlying)
    {
        std::cout << "Using the brakes" << std::endl;
    }
    else
    {
        std::cout << "Releasing the brakes" << std::endl;
    }

}

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
