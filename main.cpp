 /*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of each of your user-defined types in the main() function.

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int a; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    a = 0;
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << a << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'a' equal to 0? " << (foo.a == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.







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
    if(pressure > 100 && thickness < 0.9f)
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
    if(sharpness > 10 && lengthCm > 100)
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
        return itemPrice - InsertedCoins;           
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
    if(forward && speed > 0)
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
    if(wearDisplay == "need replacement") 
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
    Example::main();
    
    std::cout << "good to go!" << std::endl;
}
