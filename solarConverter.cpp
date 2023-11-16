/* This programm is to help the user decide what kind of panels batteries inverters
he needs to go solar for every functionality our app needs we will define separate
functions and use prototyping */
#include<iostream>
/* First we need to ask the user about the load of his house accros the year 
then sum it to calculate the average load that his house has. */
/* This function will calculate the average annual load of the house for a single year 
and then return it's value */
int averageLoad();
/* The value of production ratio depends upon how much sunlight is available to your panel */
/* function returns a floating point as the value of production ratios ranges between 1.6-1.2 */
float productionRatio();
/* This function will take the average load and production ratio as parameters and 
use them to help calculate the number of solar panels required for our system */
int numberOfPanels(float,int);
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
        int systemLoad{averageLoad()};
        std::cout<<"We also need to calculate a constant called Production Ratio which decides the input to output"
        <<std::endl<<"power ratio of your solar panel for this we need to know :"<<std::endl;
        /* Again declaring and defining a floating point having value returned by the function 
        productionRatio() */
        float pr{productionRatio()};
        std::cout<<"Now to calculate the number of panels you need we need to know :"<<std::endl;
        int noOfPanels{numberOfPanels(pr,systemLoad)};
        std::cout<<"You need "<<noOfPanels<<"according to the data provided"<<std::endl;
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
    std::cout<<"Amount of sunlight that tocuhes your building in winter :"<<std::endl
    <<"1. Ample"<<std::endl<<"2. Fair"<<std::endl<<"3. Faint"<<std::endl;
    std::cin>>choiceWinter;
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
int averageLoad()
{   
    /* We are using two unsigned integers as the Electrical Energy consumed by a house can 
    never be negative and the sum of that energy can never be negatvie either  */
    unsigned int load;
    double sum =0;
    /* Where are using a for loop because we will never need more than 12 itterations */
    /* the use of usnigned int "i" is becuase we never want it to be negative */
    for (unsigned int  i = 1; i <= 12; i++)
    {
        std::cout<<"What was the Electrical load requirement of your house for month "<<i<<std::endl;
        std::cin>>load;
        /* Adds new values to the previous sum */
        sum=sum+load;
    }
    /* Averaging the sum to a year */
     return (sum = sum/12);
    

}
int numberOfPanels(float pr,int systemLoad)
{
    /* The formula for calcualting number of panels is 
    numberOfPanels = systemload/productionRation/panelWattage */
    /* this integer will store the panel wattage amount given to us by the user */
    int panelWattage;
    std::cout<<"How many wattage of power can the panel you plan on using output ?"<<std::endl
    <<"Most panles have wattage ratings between 250 - 400, averaging about 300 watts"<<std::endl;
    /* Taking the wattage input */
    std::cin>>panelWattage;
    float panels= systemLoad/(pr/panelWattage);
    return(static_cast<int>(panels));
}