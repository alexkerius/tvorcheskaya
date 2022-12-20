#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Human
{
public:
    string Name;
    
    Human(string n, int age, int weight, int height){
        this->Name = n;
        this->Age = age;
        this->Weight = weight;
        this->Height = height;
    }
    Human(){
        this->Name = DefaultName;
    }

    void change(string name){
        if(Name == DefaultName){
            cout << "Name was changed from " << Name << " to " << name;
            Name = name;
        }
        else{
            cout << "You cannot change the name again";
        }
    }

protected:
    string DefaultName = "Lyceum student";
    int Age;
    int Weight;
    int Height;
};

class Student : public Human
{
public:
    vector<int> Marks;

    Student(string name, int age, int weight, int height): Human (Name, Age, Weight, Height){}
    double DefinePrimaryRating(){
        int sum = 0;
        if(Name == DefaultName){
            return 0;
        }
        sort(Marks.begin(),Marks.end());
        Marks.erase(Marks.begin());
        Marks.erase(Marks.end());
        for(int i = 0; i < Marks.size(); i++){
            sum += Marks[i];
            cout << sum << '\n';
        }
        return sum/Marks.size();
    }

    double DefineSecondaryRating(){
        return DefinePrimaryRating() + Age + Weight + Height;
    }


};




int main(){
    Student alex("Alex",18,60,170);
    alex.Marks = {1,2,3,4,5};
    cout << alex.DefinePrimaryRating();
}