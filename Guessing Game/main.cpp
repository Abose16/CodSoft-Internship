#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

using namespace std;

int main()
{
    int num,random;
    char ch='Y';
    cout<<"\n\n\n*****NUMBER GUESSING GAME*****\n"<<endl;
    while(1)
    {
        cout <<"\n\nGuess the number (Between 0 and 500): ";
        cin >> num;
        if(ch=='Y'||ch=='y')
        {
            srand(time(0));
            random=rand()%501;
            ch=0;
        }
        if(random==num)
        {
            cout<<"\nCongratulations! You have found the secret number."<<endl;
            cout<<"\nDo you want to play again? [Y/N] ";
            cin>>ch;
            if(ch=='Y'||ch=='y')
                continue;
            else
                break;
        }
        if(random<10)
        {
            if(abs(random-num)<5)
            {
                if(num<random)
                    printf("\nLow");
                else
                    printf("\nHigh");
            }
            else
            {
                if(num<random)
                    printf("\nToo Low");
                else
                    printf("\nToo High");
            }
        }
        else if(random<100)
        {
            if(abs(random-num)<10)
            {
                if(num<random)
                    printf("\nLow");
                else
                    printf("\nHigh");
            }
            else
            {
                if(num<random)
                    printf("\nToo Low");
                else
                    printf("\nToo High");
            }
        }
        else
        {
            if(abs(random-num)<15)
            {
                if(num<random)
                    printf("\nLow");
                else
                    printf("\nHigh");
            }
            else
            {
                if(num<random)
                    printf("\nToo Low");
                else
                    printf("\nToo High");
            }
        }
    }
    return 0;
}
