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
        Name = n;
        Age = age;
        Weight = weight;
        Height = height;
    }
    Human(){
        Name = DefaultName;
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
    Student(string name,int age, int weight, int height) : Human(name,  age,  weight,  height){}
    Student() : Human(){}
    double DefinePrimaryRating(){
        double sum = 0;
        if(Name == DefaultName){
            return 0;
        }

        sort(Marks.begin(),Marks.end());
        
        return (Marks[1]+Marks[2]+Marks[3])/3;
    }

    double DefineSecondaryRating(){
        return DefinePrimaryRating() + Age + Weight + Height;
    }


};


int main(){
    Student students[5] = {Student("Alex",16,60,170),
        Student("Egor",17,86,190),
        Student("Ann",16,40,150),
        Student("Zlata",16,50,178),
        Student("Charles",15,80,175)};
    for(int i = 0; i < 5; i++){
        vector<int> marks_for_one;
        for(int j = 0; j < 5; j++){
            int g;
            cin >> g;
            marks_for_one.push_back(g);
        }
        students[i].Marks = marks_for_one;
    }

    Student best("None",0,0,0);
    best.Marks = {0,0,0,0,0};
    for(int i = 0; i < 5; i++){
        if(students[i].DefinePrimaryRating() > best.DefinePrimaryRating()){
            best = students[i];
        }
        else if(students[i].DefinePrimaryRating() == best.DefinePrimaryRating() && students[i].DefineSecondaryRating() > best.DefineSecondaryRating()){
            best = students[i];
        }
        
    }
    cout << "The best student is "<< best.Name;
    return 0;
}
