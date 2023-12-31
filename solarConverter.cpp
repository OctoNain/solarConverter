/* This programm is to help the user decide what kind of panels batteries inverters
he needs to go solar for every functionality our app needs we will define separate
functions and use prototyping */
#include<iostream>
/* Including the library which allows us to use the floor/ceil function */
#include<cmath>
/* First we need to ask the user about the load of his house accros the year 
then sum it to calculate the average load that his house has. */
/* This function will calculate the average annual load of the house for a single year 
and then return it's value */
float averageLoad();
/* The value of production ratio depends upon how much sunlight is available to your panel */
/* function returns a floating point as the value of production ratios ranges between 1.6-1.2 */
float productionRatio();
/* This function will take the average load and production ratio as parameters and 
use them to help calculate the number of solar panels required for our system */
float numberOfPanels(float,double);
/* A function that helps us calculate the number of battiers required for the solar system */
float numberOfBattiers(float,float);
/* A function that helps decide the rating for your UPS/Inverter Rating */
int inverterRating(float );
/* A function that calculates the charging current required by the battery system */
int chargingCurrent(int numberOfBatteries);
int main()
{
    bool exit = true;
    while (exit)
    {
        std::cout<<"Welcome to the solarConverter app which will help you decide, on going solar-energy"<<std::endl
        <<"for any of your buildings for this we first need to calculate the average anual load for your house"
        <<std::endl;
        /* Declaring and defining the variable systemload having a value returned by the function
        averageLoad() */
        float systemLoad{averageLoad()};
        std::cout<<systemLoad<<std::endl;
        std::cout<<"We also need to calculate a constant called Production Ratio which decides the input to output"
        <<std::endl<<"power ratio of your solar panel for this we need to know :"<<std::endl;
        /* Again declaring and defining a floating point having value returned by the function 
        productionRatio() */
        float pr{productionRatio()};
        std::cout<<"Now to calculate the number of panels you need we need to know :"<<std::endl;
        float noOfPanels{numberOfPanels(pr,11000)};
        /* ceil function rounds up the decimal numbers in c++  */
        std::cout<<"You need "<<ceil(noOfPanels)<<" panels according to the data provided"<<std::endl;
        /* Now to calculate the number of batteries required for the system ? we need to ask the user 
        the back-up time required by the batteries to run */
        std::cout<<"In case of shortage of powers for how long would you need to run your electrical system "
        <<"On Batteries (Please specify your answer in hours)"<<std::endl;
        /* Backup time can be half an hour hence using floating point */
        float hours;
        std::cin>>hours;
        /* defining and initializing a floating point according to the return value 
        from the function numberOfBatteries */
        float Batteries{numberOfBattiers(hours,systemLoad)};
        std::cout<<"You need "<<Batteries<<" battieres"<<std::endl;
        int ups{inverterRating(systemLoad)};
        int current{chargingCurrent(Batteries)};
        std::cout<<"Your inverter rating should be "<<ups<<" watts"<<std::endl;
        std::cout<<"Do you wish to make another calculation (y/n) ?"<<std::endl;
        char ans;
        std::cin>>ans;
        if (ans == 'n')
            exit=false;
    }


}
float productionRatio()
{
    /* floating points that sum together to determine the production ratio */
    float summerRatio,winterRatio;
    /* Integer Values that upon user input will help decide production ratio */
    int choiceWinter,choiceSummer;
    std::cout<<"Amount of sunlight that tocuhes your building in summer :"<<std::endl
    <<"1. Ample"<<std::endl<<"2. Fair"<<std::endl<<"3. Faint"<<std::endl;
    std::cin>>choiceSummer;
    system("cls");
    std::cout<<"Amount of sunlight that tocuhes your building in winter :"<<std::endl
    <<"1. Ample"<<std::endl<<"2. Fair"<<std::endl<<"3. Faint"<<std::endl;
    std::cin>>choiceWinter;
    system("cls");
    /* If ample sunlight touches throught the year production ratio will always be 1.6 */
    if (choiceSummer==1 && choiceWinter == 1)
    {
        return 1.6f;
    }
    /* When faint sunlight touches throughout the year production ratio will be 1.2 */
    else if(choiceSummer==3 && choiceWinter == 3)
    {
        return 1.2f;
    }
    /* Apart from the above to conditions we calculate the production ratio */
    else{
        /* Using switch case to determine the float point value with great speed
        as dealing with constant expression switch case is the fastest and simplest
        approach */
        switch (choiceSummer)
        {
        case 1:
            summerRatio = 0.2f;
            break;
        case 2:
            summerRatio = 0.1f;
            break;
        case 3:
        summerRatio = 0.05f;
            break;
        /* Default statement will only run in case of wrong input */
        default:
        std::cout<<"Error Wrong input"<<std::endl;
            return 0;
        }
        switch (choiceWinter)
        {
        case 1:
            winterRatio = 0.2f;
            break;
        case 2:
            winterRatio = 0.1f;
            break;
        case 3:
        winterRatio = 0.05f;
            break;
        /* Default case only runs in case of wrong input */
        default:
            std::cout<<"Error Wrong input"<<std::endl;
            return 0;
        }
        /* Formula to get the correct production ratio value and return it  */
        return 1.2+(summerRatio+winterRatio);
    }


}
float averageLoad()
{   
    float load;
    float sum =0.0f;
    /* Where are using a for loop because we will never need more than 12 itterations */
    /* the use of usnigned int "i" is becuase we never want it to be negative */
    for (unsigned int  i = 1; i <= 12; i++)
    {
        system("cls");
        std::cout<<"What was the Electrical load requirement of your house for month "<<i<<std::endl
        <<"please provide the input in killo-watts/hour only !!!!!!!!!!"<<std::endl;
        std::cin>>load;
        /* Adds new values to the previous sum */
        sum=sum+load;
    }
    /* Averaging the sum to a year */
     return (sum = sum/12);
    

}
float numberOfPanels(float pr,double systemLoad)
{
    /* The formula for calcualting number of panels is 
    numberOfPanels = systemload/(productionRation*panelWattage) */
    /* this integer will store the panel wattage amount given to us by the user */
    int panelWattage;
    std::cout<<"How many wattage of power can the panel you plan on using output ?"<<std::endl
    <<"Most panles have wattage ratings between 250 - 400, averaging about 300 watts"<<std::endl;
    /* Taking the wattage input */
    std::cin>>panelWattage;
    return(systemLoad/(pr*panelWattage));
    
}
float numberOfBattiers(float time,float load)
{
    int calculatedLoad,ampsPerHour,volts;
    float batteryload;
    char temp;
    /* Converting the load from kilo-watts to watts  */
    load *=1000;
    std::cout<<"Please Input specifications of your battery in the format ampsPerHour"<<
    " : volts"<<std::endl;
    std::cin>>ampsPerHour>>temp>>volts;
    /* Calculating the load battery can provide */
    calculatedLoad = ampsPerHour * volts;
    /* Calculating for how long a single battery will run the average provided load */
    batteryload = calculatedLoad / load;
    return floor(time/batteryload);
}
int inverterRating(float load)
{
    /* Your inverter rating should always be 25% more than your desired load */
    int Load;
    Load =load + (load*(25/100));
    return load;
}
int chargingCurrent( int numberOfBatteries)
{
    /* The charging current required by the batteries is 1/10th the amperage 
    of the batteries */
    return numberOfBatteries/10;
}