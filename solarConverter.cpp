/* This programm is to help the user decide what kind of panels batteries inverters
he needs to go solar for every functionality our app needs we will define separate
functions and use prototyping */
#include<iostream>
/* First we need to ask the user about the load of his house accros the year 
then sum it to calculate the average load that his house has. */
/* This function will calculate the average annual load of the house for a single year 
and then return it's value */
int average_load();
int main()
{
    int averageSum=average_load();
    std::cout<<averageSum;

};
int average_load()
{   
    /* We are using two unsigned integers as the Electrical Energy consumed by a house can 
    never be negative and the sum of that energy can never be negatvie either  */
    unsigned int load;
    unsigned int sum =0;
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