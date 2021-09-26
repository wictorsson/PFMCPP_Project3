 /*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            bar.num += 1;                    //2a)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()







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

        void stringAgeUntilBreakdown(int ageLimit);
        void breakDown(float pressure, float thickness );
        void oxide (int age);
        void kill (int sharpness, float length);
    };

    void reStringGuitar(int startingVal);
    void vibrate(String string);
    void amplify(bool guitarPluggedIn, int howLoud);
    float electricity(float time);  
};

Guitar::Guitar() : logoName("Gibson"), color("Black"), tuningSystem(true) {} 

Guitar::String::String() : length (100.0f), age (12) {}

void Guitar::String::stringAgeUntilBreakdown(int ageLimit)
{   
    int newString = 0;
    while(newString < ageLimit)
    {   
        ++ newString;
        std::cout << "String age is increasing " << newString << std::endl;
    }
    std::cout << "String is too old " << std::endl;
}

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

void Guitar::reStringGuitar(int startingVal)
{
    for(int i = startingVal; i < numberOfStrings; ++ i)
    {
        std::cout << "Restringing the " << i + 1 << "th string" << std::endl;
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
    float insertedCoins;
    bool coolingSystem;
    std::string itemTag;

    float purchaseWithFiftyCents(float coinValue,int itemPrice);
    float chargeCustomer(bool creditcard, float itemPrice);
    void feedCustomer(int amountOfCandy);
    void coolDownMashine(int temperature, int duration);
};

VendingMashine::VendingMashine() : insertedCoins(10), coolingSystem(true), itemTag("Orego") {}

float VendingMashine::purchaseWithFiftyCents(float coinValue, int itemPrice)
{
    while(insertedCoins < itemPrice)
    {           
        insertedCoins += coinValue;
        std::cout << "Inserting cash: " << insertedCoins << std::endl;
    }
    std::cout << "Item price reached" << std::endl;
    return insertedCoins;
}

float VendingMashine::chargeCustomer(bool creditcard, float itemPrice)
{
    if(!creditcard)
    {
        return itemPrice - insertedCoins;           
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
        for(int i = 0; i < duration; ++ i) 
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
    
    void generateNewSerialNumbers(int addNumber, int numbOfSerials);
    void receiveCall(bool isPhoneMuted);
    std::string receiveText(bool receiveTextEnabled, std::string textMessage);
    void makeNoise(int numberOfSpeaker, int volume);
};

Phone::Phone() : model("genX"), cameraResolution(12) {}

void Phone::generateNewSerialNumbers(int addNumber, int numbOfSerials)
{
    for(int i = 0; i < numbOfSerials; ++ i) 
    {
        serialNumber += addNumber;
        std::cout << "New serialnumber: " << serialNumber << std::endl;
    }
}
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
    for (int i = 0; i < numberOfSpeakers; ++ i) 
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
    float satelliteRange;

    struct Studio
    {
        Studio();
        bool isNewsStudio = false;
        int lightbulbs = 1000;
        bool isOnAir;
        int cameras;
        float size;

        void distributeLamps(int lampsPerRoom);
        void transmitVideo(bool cameraIsOn);
        void transmitAudio(bool microphone);
        bool getOnAirStatus(bool isCameraOn);
    };

    void changeSatelliteRange(float steps, bool wider);
    void broadcastChannel(std::string channel);
    void produceVideo(Studio studio);
    std::string getFeedback(int date, std::string feedBack);
};

TVStation::TVStation() : tvStationName("Nickelodeon"), satelliteRange(180.0f) {}

TVStation::Studio::Studio() : isOnAir(false), cameras(5), size(100) {}

//lamps left??
void TVStation::Studio::distributeLamps(int lampsPerRoom)
{
    int totalNumbOfRooms = 10;
    int roomNumber = 1;
    while(roomNumber < totalNumbOfRooms)
    {
       ++ roomNumber; 
       lightbulbs -= lampsPerRoom; 
       std::cout << "Amount of lightbulbs left: " << lightbulbs << std::endl;
    }  
    std::cout << "Amount of lightbulbs left: " << lightbulbs << std::endl;
}

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

void TVStation::changeSatelliteRange(float stepSize, bool wider)
{
    for(int i = 0; i < 10; ++ i) 
    {
        if(wider)
        {
            satelliteRange += stepSize;
        }
        else
        {
            satelliteRange -= stepSize;
        }
        std::cout << satelliteRange << std::endl;
    }

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

    void fillTank(float loadsOfFuel);
    void createMotion(float speed);
    void convertEnergy(float time, float duration);
    void produceHeat(bool oilIndicator);

};

Engine::Engine() : oilIndicator(true), pistonSpeed(45) {}

void Engine::fillTank(float loadsOfFuel)
{   
    fuelIntake = 0;
    while(fuelIntake < 10000.0f)
    {
        fuelIntake += loadsOfFuel;
        std::cout << fuelIntake << std::endl;
    }
    std::cout << "Stop refilling " << std::endl;
}
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

    void demountPanels(int numbOfPanelsTodemount);
    void foldPanels(int numbPanels);
    void holdPlaneUp(int planeWeight);
    void holdTheEngines(int engineWeight);
};

Wings::Wings() : tagText("SAS"), ribs(40) {}

void Wings::demountPanels(int numbOfPanelsToKeep)
{
    while(panels > numbOfPanelsToKeep)
    {
        -- panels;
        std::cout << "Panels left: " << panels << std::endl;
    }
} 

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

    double fillAir(double amountOfAirPerSec, int airLimit);
    void countWheels( );
    void startRolling(bool forward, float speed);
    void balancePlane(float planeWeight);
    void turnTheWheel(std::string direction);
};

Wheels::Wheels() : rims(10), wheelWeight(100){}

double Wheels::fillAir(double amountOfAirPerSec, int airLimit)
{
    amountOfAir = 0;
    while(amountOfAir < airLimit)
    {
        amountOfAir += amountOfAirPerSec;
        std::cout << "Filling up air: " << amountOfAir << std::endl;
    }
    std::cout << amountOfAir << std::endl;
    return amountOfAir;  
}

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

    void addSeats(int maxSeats);
    void carryPassangers(int numberOfseats, float passengersWeight);
    void foldBack(int seatHeight);
    void store(int numberOfmagazines);
};

Seats::Seats() : numberOfSeats(500), seatColor("grey") {}

void Seats::addSeats(int maxSeats)
{
    for(int i = 0; i < maxSeats; ++ i)
    {
        ++ numberOfSeats;
        std::cout << "Added a seat" << std::endl;
    }
    std::cout << "Total no of seats: " << numberOfSeats  << std::endl;
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

    void addPadsToBrake(int padWeight, int amountOfPadsOnBrake);
    std::string showWear(std::string wearIndicator);
    void stop(float time);
    void decelerate(float duration);
};

Brakes::Brakes() : wearIndicator("bad"), chassisHardness (24.5f) {}

void Brakes::addPadsToBrake(int padWeight, int amountOfPadsOnBrake)
{
    for(int i = 0; i < amountOfPadsOnBrake; ++ i)
    {
        brakeWeight += padWeight;
        std::cout << "Added pad to brake " << std::endl;
    }
    std::cout << "New brake weight: " << brakeWeight << std::endl;
}

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
    for(int i = 0; i < duration; ++ i)
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

    void acceleratePiston(int startSpeed, int maxSpeed);
    void fly(std::string destination, float speed);
    void driveOnGround(bool isAttached);
    void brake(bool isFlying);
};

Airplane::Airplane()
{
    std::cout << "Const airplane" << std::endl;
}

void Airplane::acceleratePiston(int startSpeed, int maxSpeed)
{
    engine.pistonSpeed = startSpeed;
    while(engine.pistonSpeed < maxSpeed)
    {
        ++ engine.pistonSpeed;
        std::cout << "Speeding up pistons..." << std::endl;
    }

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
    guitar.reStringGuitar(2);
    guitar.vibrate(string);
    guitar.amplify(true, 10);
    guitar.electricity(50);
    std::cout << "Is this a 6 stringed guitar? " << (guitar.numberOfStrings == 6 ? "Yes" : "No") << "\n";
    string.stringAgeUntilBreakdown(8);
    string.breakDown(200,0.1f);
    string.oxide(6);
    string.kill(5,5.5f);
    std::cout << "Is the string short ? " << (string.length <= 6 ? "Yes" : "No") << "\n";
    std::cout << std::endl;

    VendingMashine vMachine;
    vMachine.purchaseWithFiftyCents(0.5f,15);
    vMachine.chargeCustomer(true, 5.5f);
    vMachine.feedCustomer(2);
    vMachine.coolDownMashine(25, 200);
    std::cout << "Do we need to refill drinks? " << (vMachine.amountOfCandy > vMachine.amountOfDrinks ? "Yes" : "No") << "\n";
    std::cout << std::endl;

    Phone phone;
    phone.generateNewSerialNumbers(10,10);
    phone.receiveCall(false);
    phone.receiveText(true, "this is a text");
    phone.makeNoise(2,10);
    std::cout << "This phone has "<< phone.numberOfSpeaker << " speakers" << "\n";
    std::cout << std::endl;

    TVStation tvStation;
    TVStation::Studio studio;
    std::cout << "Moving the satellite dish "<< "\n";
    tvStation.changeSatelliteRange(10.5f, true);
    tvStation.broadcastChannel("CNN");
    tvStation.produceVideo(studio);
    tvStation.getFeedback(10,"Nice show");
    std::cout << "Station has "<< tvStation.numberOfCameras << " cameras" << "\n";
    std::cout << "Distributing lightbulbs" << std::endl;
    studio.distributeLamps(10);
    studio.transmitVideo(true);
    studio.transmitAudio(true);
    studio.getOnAirStatus(false);
    std::cout << "Enough cameras in the newsroom? " << (studio.cameras > 0 && studio.isNewsStudio ? "Yes" : "No") << "\n";
    std::cout << std::endl;

    Engine engine;
    std::cout << "Filling up the tank" << std::endl;
    engine.fillTank(1000.0f);
    engine.createMotion(20.0f);
    engine.convertEnergy(30.2f, 20.9f);
    engine.produceHeat(true);
    std::cout << "Engine has "<< engine.cylinders << " cylinders" << "\n";
    std::cout << std::endl;

    Wings wings;
    std::cout << "demounting panels" << std::endl;
    wings.demountPanels(3);
    wings.foldPanels(5);
    wings.holdPlaneUp(7);
    wings.holdTheEngines(100);
    std::cout << "We are flying with " << wings.tagText << "\n";
    std::cout << std::endl;

    Wheels wheels;
    std::cout << "Filling up with air" << std::endl;
    wheels.fillAir(1000.000, 10000);
    wheels.startRolling(true, 100.9f);
    wheels.balancePlane(10.0f);
    wheels.turnTheWheel("left");
    std::cout << "We are rolling with "<< wheels.manufactor << "\n";
    std::cout << std::endl;

    Seats seats;
    std::cout << "Adding seats" << std::endl;
    seats.addSeats(5);
    seats.carryPassangers(300,2000);
    seats.foldBack(150);
    seats.store(10);
    std::cout << "Seat color "<< seats.seatColor << "\n";
    std::cout << std::endl;

    Brakes brakes;
    std::cout << "adding pads to the brake" << std::endl;
    brakes.addPadsToBrake(2, 5);
    brakes.showWear("new");
    brakes.stop(10.0f);
    brakes.decelerate(10.0f);
    std::cout << "Wear indicator status: "<< brakes.wearIndicator << "\n";
    std::cout << std::endl;

    Airplane airplane;
    std::cout << "Starting to accelerate pistons" << std::endl;
    airplane.acceleratePiston(90, 100);
    airplane.fly("London", 1000);
    airplane.driveOnGround(true);
    airplane.brake(false);
    std::cout << (airplane.seats.lifeWest && airplane.wings.lampColor == "green" ? "Safe to fly" : "Not safe to fly") << "\n";
    

    std::cout << "good to go!" << std::endl;
}
