#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main()
{
    float n1,n2,result;
    int ch;
    char c;
    do
    {
        cout<<"\nEnter first number: ";
        cin>>n1;
        cout<<"\nEnter second number: ";
        cin>>n2;
        cout<<"\n1. Addition \n2. Subtraction \n3. Multiplication \n4. Division";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: result=n1+n2;
                    cout<<"\nThe result of the addition operation is: "<<result;
                    break;
            case 2: result=n1-n2;
                    cout<<"\nThe result of the subtraction operation is: "<<result;
                    break;
            case 3: result=n1*n2;
                    cout<<"\nThe result of the multiplication operation is: "<<result;
                    break;
            case 4: result=n1/n2;
                    cout<<"\nThe result of the division operation is: "<<result;
                    break;
           default: cout<<"\nInvalid Choice!";
        }
        cout<<"\nDo you want to continue? [Y/N] ";
        c=getche();
        cout<<endl;
    }while(c=='Y'||c=='y');
    return 0;
}
