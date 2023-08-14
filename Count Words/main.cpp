#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

int main()
{
    int counter=0;
	ifstream fin;
	string file;
	char ch;

	cout<<"Provide the file name: ";
    cin>>file;
    fin.open(file+".txt");

    if(!fin)
    {
        cout<<"\nFile not found!\n";
        exit(0);
    }

    cout<<"\nOpening "<<file<<".txt...\n";
	while(fin.get(ch))
	{
        if((ch>=65&&ch<=90)||(ch>=97&&ch<=122))
        {
            while(fin.get(ch))
            {
                if(ch==' '||ch=='\n')
                    break;
            }
            counter++;
        }
	}
	fin.close();

	cout<<"\nNumber of words: "<<counter<<endl;
    return 0;
}
