 /*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) do this for each class in this project: 
    initialize some of your member variables either in-class or in the Constructor member initializer list.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable
    float b { 2.f }; // in-class initialization
    UDT() : a(0) { } // 'constructor-initializer-list' member variable initialization
    void printThing()  //the member function
    {
        std::cout << "UDT::printThing() a:" << a << " b: " << b << std::endl;  //4) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printThing(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()




struct Guitar
{
    Guitar();
    int numberOfPickups = 2;
    int numberOfStrings = 6;
    std::string logoName;
    std::string color;
    bool tuningSystem;
    
    struct String
    {
        String();
        std::string winding = "flatwound";
        std::string manufactor = "Earnie ball";
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

Guitar::Guitar() : logoName("Gibson"), color("Black"), tuningSystem(true) {} 

Guitar::String::String() : length (100.0f), age (12) {}

void Guitar::String::breakDown(float pressure, float thickness)
{
    if(pressure > 100 && thickness < 0.9f)
    {
        std::cout << "High pressure on string, it is breaking one of the " << age << " year old strings" << std::endl;
    }
}

void Guitar::String::oxide(int ageMonths)
{
    if(ageMonths > 10)
    {
        std::cout << winding << " string is starting to oxidize" << std::endl;
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
        std::cout << "guitar is vibrating when strumming the "<< numberOfStrings << " strings." << std::endl;
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
        std::cout << logoName << "Guitar is not plugged in, mute amp" << std::endl;
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
    int amountOfCandy = 50;
    int amountOfDrinks = 50;
    int InsertedCoins;
    bool coolingSystem;
    std::string itemTag;

 
    float chargeCustomer(bool creditcard, float itemPrice);
    void feedCustomer(int amountOfCandy);
    void coolDownMashine(int temperature, int duration);
};

VendingMashine::VendingMashine() : InsertedCoins(100), coolingSystem(true), itemTag("Orego") {}

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
    int numberOfSpeaker = 2;
    int serialNumber = 13431413;
    double storage = 34.3434332;
    std::string model;
    int cameraResolution;
  
    void receiveCall(bool isPhoneMuted);
    std::string receiveText(bool receiveTextEnabled, std::string textMessage);
    void makeNoise(int numberOfSpeaker, int volume);
};

Phone::Phone() : model("genX"), cameraResolution(12) {}

void Phone::receiveCall(bool isPhoneMuted)
{
    if(!isPhoneMuted)
    {
        std::cout << "Receiving a call on model: " << model << std::endl;
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
    std::cout << "Noise coming from phone with serial number: " << serialNumber << std::endl;
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
    int channelChains = 24;
    int numberOfEmployees = 202;
    int numberOfCameras = 12;
    std::string tvStationName;
    float sateliteRange;

    struct Studio
    {
        Studio();
        bool isNewsStudio = false;
        int lightbulbs = 1000;
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

TVStation::TVStation() : tvStationName("Nickelodeon"), sateliteRange(180.0f) {}

TVStation::Studio::Studio() : isOnAir(false), cameras(5), size(100) {}


void TVStation::Studio::transmitVideo(bool cameraIsOn)
{
    if(cameraIsOn)
    {
        std::cout << "transmitting video, we are on air: " << isOnAir << std::endl;
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
         std::cout << numberOfEmployees << " employees are producing video" << std::endl;
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
    float fuelIntake = 10000.0f;
    int cylinders = 12;
    int compressors = 5;
    bool oilIndicator;
    int pistonSpeed;

    void createMotion(float speed);
    void convertEnergy(float time, float duration);
    void produceHeat(bool oilIndicator);

};

Engine::Engine() : oilIndicator(true), pistonSpeed(45) {}

void Engine::createMotion(float speed)
{
    if(speed > 0)
    {
        std::cout << "Create motion, piston speed is " << pistonSpeed << std::endl;
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
        std::cout << "Fuel intake: " << fuelIntake << "- heating up" << std::endl;
    }

}
struct Wings
{   
    Wings();
    int panels = 10;
    int flaps = 20;
    std::string lampColor = "green";
    std::string tagText;
    int ribs;

    void foldPanels(int numbPanels);
    void holdPlaneUp(int planeWeight);
    void foldPanels2(int numbPanels2);
    void holdTheEngines(int engineWeight);
};

Wings::Wings() : tagText("SAS"), ribs(40) {}

void Wings::foldPanels(int numbOfPanels)
{
    if (numbOfPanels > 0)
    {
        std::cout << "Folding the " << panels << " panels." << std::endl;
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
        std::cout << "holding the plane in the air, light is " << lampColor << std::endl;
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
    int plugs = 10;
    std::string manufactor = "Goodyear";
    double amountOfAir = 1000000.000;
    int rims;
    int wheelWeight;

    void startRolling(bool forward, float speed);
    void balancePlane(float planeWeight);
    void turnTheWheel(std::string direction);
};

Wheels::Wheels() : rims(10), wheelWeight(100){}

void Wheels::startRolling(bool forward, float speed)
{
    if(forward && speed > 0)
    {
        std::cout << "start rolling forward, speed: " << speed << ", amount of air: " << amountOfAir << std::endl;
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
    int seatHeight = 100;
    int seatWidth = 50;
    bool lifeWest = false;
    int numberOfSeats; 
    std::string seatColor;

    void carryPassangers(int numberOfseats, float passengersWeight);
    void foldBack(int seatHeight);
    void store(int numberOfmagazines);
};

Seats::Seats() : numberOfSeats(500), seatColor("grey") {}

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
        std::cout << "fold back one of the  " << numberOfSeats << "seats" << std::endl;
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
    float brakeRadius = 20.5f;
    int brakeWeight = 20;
    int brakePads = 10; 
    std::string wearIndicator;
    float chassisHardness;

    std::string showWear(std::string wearIndicator);
    void stop(float time);
    void decelerate(float duration);
};

Brakes::Brakes() : wearIndicator("bad"), chassisHardness (24.5f) {}

std::string Brakes::showWear(std::string wearDisplay)
{
    std::cout << "Indicator status: " << wearIndicator << std::endl;
    if(wearDisplay == "need replacement") 
    {
        return "replace the brakes";
    }
    return "brakes are fine";  
}

void Brakes::stop(float time)
{
    std::cout << "weight of the brakes: " << brakeWeight << std::endl;
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
    std::cout << "We are flying with " << wings.tagText << "\n";
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
