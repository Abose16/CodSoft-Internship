#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#define MAX 10

using namespace std;

class StudentGrades
{
    string name;
    char grades[4];
    int numerics[4];
    void putData();

    public:
    void getData();
    char maxGrade();
    char minGrade();
    char avgGrade();
    void displayFields();
};

void StudentGrades::putData()
{
    for(int i=0;i<4;i++)
    {
        if(grades[i]=='O')
            numerics[i]=90;
        else if(grades[i]=='E')
            numerics[i]=80;
        else if(grades[i]>=65&&grades[i]<=68)
            numerics[i]=(72-grades[i])*10;
        else
            numerics[i]=30;
    }
}

void StudentGrades::getData()
{
    fflush(stdin);
    cout<<"\nEnter student name: ";
    getline(cin,name);
    fflush(stdin);
    cout<<"Math: ";
    cin>>grades[0];
    fflush(stdin);
    cout<<"Chemistry: ";
    cin>>grades[1];
    fflush(stdin);
    cout<<"Physics: ";
    cin>>grades[2];
    fflush(stdin);
    cout<<"English: ";
    cin>>grades[3];
    putData();
}

char StudentGrades::maxGrade()
{
    int grade,index;
    grade=numerics[0];
    index=0;
    for(int i=1;i<4;i++)
    {
        if(numerics[i]>grade)
        {
            grade=numerics[i];
            index=i;
        }
    }
    return grades[index];
}

char StudentGrades::minGrade()
{
    int grade,index;
    grade=numerics[0];
    index=0;
    for(int i=1;i<4;i++)
    {
        if(numerics[i]<grade)
        {
            grade=numerics[i];
            index=i;
        }
    }
    return grades[index];
}

char StudentGrades::avgGrade()
{
    int sum,avg,r;
    sum=0;
    for(int i=0;i<4;i++)
    {
        sum=sum+numerics[i];
    }
    avg=sum/4;
    r=avg/10;
    if(r==3)
        return 'F';
    if(r==9)
        return 'O';
    if(r==8)
        return 'E';
    else
        return (72-r);
}

void StudentGrades::displayFields()
{
    cout<<endl<<setw(20)<<name;
    for(int i=0;i<4;i++)
    {
        cout<<setw(12)<<grades[i];
    }
    cout<<setw(12)<<maxGrade();
    cout<<setw(12)<<minGrade();
    cout<<setw(12)<<avgGrade()<<endl;
}

int main()
{
    int n,i;
    StudentGrades student[MAX];
    cout<<"O = 90% and above"<<endl;
    cout<<"E = 80% and above"<<endl;
    cout<<"A = 70% and above"<<endl;
    cout<<"B = 60% and above"<<endl;
    cout<<"C = 50% and above"<<endl;
    cout<<"D = 40% and above"<<endl;
    cout<<"F = Below 40%"<<endl;
    cout<<"\nEnter the number of entries you would like to make: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        student[i].getData();
    }
    cout<<endl;
    cout<<setw(20)<<"Name";
    cout<<setw(12)<<"Maths";
    cout<<setw(12)<<"Chemistry";
    cout<<setw(12)<<"Physics";
    cout<<setw(12)<<"English";
    cout<<setw(12)<<"Max Grade";
    cout<<setw(12)<<"Min Grade";
    cout<<setw(12)<<"Avg Grade"<<endl;
    for(i=0;i<n;i++)
    {
        student[i].displayFields();
    }
    cout<<endl;
    return 0;
}
