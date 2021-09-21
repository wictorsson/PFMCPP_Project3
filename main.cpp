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
    Guitar();
    int numberOfPickups;
    int numberOfStrings;
    std::string logoName;
    std::string color;
    bool tuningSystem;
    
    struct String
    {
        String();
        std::string winding;
        std::string manufactor;
        float length;
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

Guitar::Guitar()
{
    std::cout << "Const Guitar"<<std::endl;
    numberOfPickups = 2;
    numberOfStrings = 6;
    logoName = "Gibson";
    color = "Black";
    tuningSystem = true;
}

Guitar::String::String()
{
    std::cout << "Const String"<<std::endl;
    winding = "flatwound";
    manufactor = "Earnie ball";
    length = 100;
}

void Guitar::String::breakDown(float pressure, float thickness)
{
    if(pressure > 100 && thickness < 0.9f)
    {
        std::cout << "High pressure on string, it is breaking the string" << std::endl;
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
    
    if(guitarPluggedIn && howLoud > 10)
    {
        std::cout << howLoud << std::endl;
    }
    else
    {
        std::cout << "Guitar is not plugged in, mute amp" << std::endl;
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
    VendingMashine();
    int amountOfCandy;
    int amountOfDrinks;
    int InsertedCoins;
    bool coolingSystem;
    std::string itemTag;

 
    float chargeCustomer(bool creditcard, float itemPrice);
    void feedCustomer(int amountOfCandy);
    void coolDownMashine(int temperature, int duration);
};

VendingMashine::VendingMashine()
{
    std::cout << "Const VendingMashine"<<std::endl;
    amountOfCandy = 50;
    amountOfDrinks = 50;
    InsertedCoins = 100;
    coolingSystem = true;
    itemTag = "Orego";
}

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
        std::cout << "Chosen item: " << itemTag << std::endl;
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
    Phone();
    int numberOfSpeaker;
    int serialNumber;
    double storage;
    std::string model;
    int cameraResolution;
  
    void receiveCall(bool isPhoneMuted);
    std::string receiveText(bool receiveTextEnabled, std::string textMessage);
    void makeNoise(int numberOfSpeaker, int volume);
};

Phone::Phone()
{
    std::cout << "Const Phone" << std::endl;
    numberOfSpeaker = 2;
    serialNumber = 13431413;
    storage = 34.3434332;
    model = "genX";
    cameraResolution = 12; 
}

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
    TVStation();
    int channelChains;
    int numberOfEmployees;
    int numberOfCameras;
    std::string tvStationName;
    float sateliteRange;

    struct Studio
    {
        Studio();
        bool isNewsStudio;
        int lightbulbs;
        bool isOnAir;
        int cameras;
        float size;

        void transmitVideo(bool cameraIsOn);
        void transmitAudio(bool microphone);
        bool getOnAirStatus(bool isCameraOn);

    };

    void broadcastChannel(std::string channel);
    void produceVideo(Studio studio);
    std::string getFeedback(int date, std::string feedBack);
};

TVStation::TVStation()
{
    std::cout << "Const TVStation" << std::endl;
    channelChains = 24;
    numberOfEmployees = 202;
    numberOfCameras = 12;
    tvStationName = "Nickelodeon";
    sateliteRange = 180.0f;
}

TVStation::Studio::Studio()
{
    isNewsStudio = false;
    lightbulbs = 1000;
    isOnAir = false;
    cameras = 5;
    size = 100;
}

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
    Engine();
    float fuelIntake;
    int cylinders;
    int compressors;
    bool oilIndicator;
    int pistonSpeed;

    void createMotion(float speed);
    void convertEnergy(float time, float duration);
    void produceHeat(bool oilIndicator);

};

Engine::Engine()
{
    std::cout << "Const engine" << std::endl;
    fuelIntake = 10000.0f;
    cylinders = 12;
    compressors = 5;
    oilIndicator = true;
    pistonSpeed = 45;

}

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
    Wings();
    int panels;
    int flaps;
    std::string lampColor;
    std::string tagText;
    int ribs;

    void foldPanels(int numbPanels);
    void holdPlaneUp(int planeWeight);
    void foldPanels2(int numbPanels2);
    void holdTheEngines(int engineWeight);
};

Wings::Wings()
{   
    std::cout << "Const wings" << std::endl;
    panels = 10;
    flaps = 20;
    lampColor = "green";
    tagText= "SAS";
    ribs = 40;

}
void Wings::foldPanels(int numbOfPanels)
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
void Wings::holdPlaneUp(int planeWeight)
{
    if (planeWeight > 1000)
    {
        std::cout << "holding the plane in the air" << std::endl;
    }
    else
    {
        std::cout << "plane is too heavy" << std::endl;
    }
}

void Wings::holdTheEngines(int engineWeight)
{
    if (engineWeight > 1000)
    {
        std::cout << "holding the engines" << std::endl;
    }
    else
    {
        std::cout << "engines are too heavy" << std::endl;
    }
}
struct Wheels
{
    Wheels();
    int plugs;
    std::string manufactor;
    double amountOfAir;
    int rims;
    int wheelWeight;

    void startRolling(bool forward, float speed);
    void balancePlane(float planeWeight);
    void turnTheWheel(std::string direction);
};

Wheels::Wheels()
{
    std::cout << "Const wheels" << std::endl;
    plugs = 10;
    manufactor = "Goodyear";
    amountOfAir = 1000000.000;
    rims = 10;
    wheelWeight = 100;

}

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
    if(direction == "forward")
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
    Seats();
    int seatHeight;
    int seatWidth;
    bool lifeWest;
    int numberOfSeats; 
    std::string seatColor;

    void carryPassangers(int numberOfseats, float passengersWeight);
    void foldBack(int seatHeight);
    void store(int numberOfmagazines);
};

Seats::Seats()
{
    std::cout << "Const seats" << std::endl;
    seatHeight = 100;
    seatWidth = 50;
    lifeWest = false;
    numberOfSeats = 500; 
    seatColor = "grey";
}

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
    Brakes();
    float brakeRadius;
    int brakeWeight; 
    int brakePads; 
    std::string wearIndicator;
    float chassisHardness;

    std::string showWear(std::string wearIndicator);
    void stop(float time);
    void decelerate(float duration);
};

Brakes::Brakes()
{   
    std::cout << "Const brakes" << std::endl;
    brakeRadius = 20.5f;
    brakeWeight = 20; 
    brakePads = 10; 
    wearIndicator = "bad";
    chassisHardness = 24.5f;
}

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
        std::cout << "speeding down the plane "<< i << std::endl; 
    }
    std::cout << "done, standing still" << std::endl;
}

struct Airplane
{
    Airplane();
    Engine engine;
    Wings wings;
    Wheels wheels;
    Seats seats;
    Brakes brakes;

    void fly(std::string destination, float speed);
    void driveOnGround(bool isAttached);
    void brake(bool isFlying);
};

Airplane::Airplane()
{
    std::cout << "Const airplane" << std::endl;
}

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

    std::cout << std::endl;
    Guitar guitar;
    Guitar::String string;
    guitar.vibrate(string);
    guitar.amplify(true, 10);
    guitar.electricity(50);
    std::cout << "Is this a 6 stringed guitar? " << (guitar.numberOfStrings == 6 ? "Yes" : "No") << "\n";
    string.breakDown(200,0.1f);
    string.oxide(6);
    string.kill(5,5.5f);
    std::cout << "Is the string short ? " << (string.length <= 6 ? "Yes" : "No") << "\n";
    std::cout << std::endl;

    VendingMashine vMachine;
    vMachine.chargeCustomer(true, 5.5f);
    vMachine.feedCustomer(2);
    vMachine.coolDownMashine(25, 200);
    std::cout << "Do we need to refill drinks? " << (vMachine.amountOfCandy > vMachine.amountOfDrinks ? "Yes" : "No") << "\n";
    std::cout << std::endl;

    Phone phone;
    phone.receiveCall(false);
    phone.receiveText(true, "this is a text");
    phone.makeNoise(2,10);
    std::cout << "This phone has "<< phone.numberOfSpeaker << " speakers" << "\n";
    std::cout << std::endl;

    TVStation tvStation;
    TVStation::Studio studio;
    tvStation.broadcastChannel("CNN");
    tvStation.produceVideo(studio);
    tvStation.getFeedback(10,"Nice show");
    std::cout << "Station has "<< tvStation.numberOfCameras << " cameras" << "\n";
    studio.transmitVideo(true);
    studio.transmitAudio(true);
    studio.getOnAirStatus(false);
    std::cout << "Enough cameras in the newsroom? " << (studio.cameras > 0 && studio.isNewsStudio ? "Yes" : "No") << "\n";
    std::cout << std::endl;

    Engine engine;
    engine.createMotion(20.0f);
    engine.convertEnergy(30.2f, 20.9f);
    engine.produceHeat(true);
    std::cout << "Engine has "<< engine.cylinders << " cylinders" << "\n";
    std::cout << std::endl;

    Wings wings;
    wings.foldPanels(5);
    wings.holdPlaneUp(7);
    wings.holdTheEngines(100);
    std::cout << "We are flying with "<< wings.tagText << "\n";
    std::cout << std::endl;

    Wheels wheels;
    wheels.startRolling(true, 100.9f);
    wheels.balancePlane(10.0f);
    wheels.turnTheWheel("left");
    std::cout << "We are rolling with "<< wheels.manufactor << "\n";
    std::cout << std::endl;

    Seats seats;
    seats.carryPassangers(300,2000);
    seats.foldBack(150);
    seats.store(10);
    std::cout << "Seat color "<< seats.seatColor << "\n";
    std::cout << std::endl;

    Brakes brakes;
    brakes.showWear("new");
    brakes.stop(10.0f);
    brakes.decelerate(10.0f);
    std::cout << "Wear indicator status: "<< brakes.wearIndicator << "\n";
    std::cout << std::endl;

    Airplane airplane;
    airplane.fly("London", 1000);
    airplane.driveOnGround(true);
    airplane.brake(false);
    std::cout << (airplane.seats.lifeWest && airplane.wings.lampColor == "green" ? "Safe to fly" : "Not safe to fly") << "\n";
    

    std::cout << "good to go!" << std::endl;
}
