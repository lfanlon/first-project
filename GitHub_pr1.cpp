/*
File: Lfanlon_Pr4.cpp 
Programmer: Loic Fanlon
Course: CMSC140 CRN 30325
Semester: Spring 2026
Project: Project 3 - Grade Calculator.
Due Date: 04/19/2026
Description:
This program reads multiple student records from an input file, 
computes tuition and academic standing for each student, 
and generates a formatted report to both the screen and an output file.
Each record includes the student’s name, number of credits, cost per credit,
and final numeric grade. For each valid record, the program must compute
letter grade, academic standing, and total amount due, then update summary 
statistics (count, total of grades, minimum, maximum) and output both per-student
and summary information. The program uses multiple functions, file I/O, and 
simple selection logic

I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
print your name here: Loic Fanlon  
*/

#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;

// print one student report to the screen and the output file
void printStudentReport(string name,int credits, double costPerCredit,
        double grade,char letterGrade,string standing, double totalDue,
        ofstream& outFile);
void printSummaryReport(int validStudents,int invalidRow,double averageGrade,double minGrade,
        double maxGrade,ofstream& outFile);
    
void displayWelcome();
  
double calculateTotalDue(int credits,double costPerCredit);

char getLetterGrade(double grade);

string getStanding(double grade);
        
int main()
{
    char choice;
do
{   
    int invalidRow=0;
    string name, standing,inputFileName,outputFileName;
    int credits;
    double costPerCredit;
    double totalDue;
    char letterGrade;
    double grade;
    double averageGrade=0;
    int validStudents=0;
    double totalGrade=0;
    double minGrade=0;
    double maxGrade=0;
    
    ofstream outFile; 
    ifstream inFile;
    
    displayWelcome();
    cout <<"Enter input file name: ";
    cin >> inputFileName;
    inFile.open(inputFileName);
    
    // keep asking until user enter valid input file
    while(!inFile)
    {
        inFile.clear();
        cout<<"File not found. try again: ";
        cin >> inputFileName;
        inFile.open(inputFileName);
    }
    
    cout << "Enter output file name: ";
    cin >>outputFileName;//create file report with the name choose by the user
    outFile.open(outputFileName);
    
   
    while(inFile >> name>> credits >> costPerCredit>>grade) //get those data for each line
    {
        if(credits<0 || costPerCredit<0 || grade<0 || grade >100)// check if data is valid
        {
            invalidRow++; //count invalid row
            cout<<"Invalid Data for Student: "<<name<<endl;
            outFile<< "Invalid Data for student: "<< name << endl;
            continue;  //the program move to the next line
        }
        
        totalDue= calculateTotalDue(credits, costPerCredit);
        letterGrade=getLetterGrade(grade);
        standing=getStanding(grade);
        
        validStudents++;
        totalGrade+=grade;//will accumulate the grade
        if(validStudents==1)// to find the min and max grade
        {
            minGrade= grade;
            maxGrade= grade;
        }
        else
        {
            if(grade<minGrade)
            {
                minGrade=grade;
            }
            if(grade>maxGrade)
            {
                maxGrade=grade;
            }
        }
    printStudentReport(name,credits,costPerCredit,grade,letterGrade,standing,
        totalDue,outFile);
        
        
    }
    if (validStudents > 0)
    {
        averageGrade= totalGrade/validStudents;
    }
    
    printSummaryReport(validStudents,invalidRow,averageGrade,minGrade,maxGrade,outFile);
    cout <<"report also written to : "<< outputFileName
          <<"\n\nThank you for using the MC File-Based Student Report Generator....."
          <<"\nSummary: Average grade of valid students, max/min grade.\n";
    inFile.close();
    outFile.close();
    
    cout<<"\n\nDo you want to run again? (Y/N): ";
    cin >> choice;
    while(choice != 'y' && choice != 'Y' && choice != 'n' && choice!='N')
    {
      cout<<" Invalid input. Please enter Y or N: ";
      cin >> choice;
    }
    
}

while(choice=='Y' || choice== 'y');
    
    return 0;
    
}


void printStudentReport(string name,int credits, double costPerCredit,
        double grade,char letterGrade,string standing, double totalDue,
        ofstream& outFile)
{
    
   cout << fixed<<setprecision(2);
        outFile << fixed << setprecision(2); // formatting the File.
        
        
        cout <<"Student Name: "<< name <<"\nCredits: " << credits
             <<"\nCost/Credit: $"<< costPerCredit <<"\nGrade: "<< grade 
             <<"("<< letterGrade<<")" <<"\nStanding: "<< standing 
             <<"\nTotal Due: $"<< totalDue <<endl
             << "\n------------------------------------------\n";
        
        
        
        outFile  <<"Student Name: "<< name <<"\nCredits: " << credits
             <<"\nCost/Credit: $"<< costPerCredit <<"\nGrade: "<< grade 
             <<"("<< letterGrade<<")" <<"\nStanding: "<< standing 
             <<"\nTotal Due: $"<< totalDue <<endl
             << "\n------------------------------------------\n"; 
}


void printSummaryReport(int validStudents,int invalidRow,double averageGrade,double minGrade,
        double maxGrade,ofstream& outFile)
{
    
  cout <<"\n\n================== Summary Report ==================\n" <<"Valid Students: "<< validStudents
          <<"\nInvalid Rows: "<< invalidRow <<"\nAverage Grade: "<< averageGrade <<"\nMin Grade: " << minGrade 
          <<"\nMax Grade: " <<maxGrade <<"\n=========================================================\n\n";
      
    
  outFile <<"\n\n================== Summary Report ==================\n" <<"Valid Students: "<< validStudents
          <<"\nInvalid Rows: "<< invalidRow <<"\nAverage Grade: "<< averageGrade <<"\nMin Grade: " << minGrade 
          <<"\nMax Grade: " <<maxGrade <<"\n=========================================================\n\n";
      
}

char getLetterGrade(double grade)
{
    if(grade >=90)
    {
        return 'A';
    }
    
    else if(grade >=80)
    {
        return 'B';
    }
    
    else if(grade >=70)
    {
        return 'C';
    }
    
    else if(grade >=60)
    {
        return 'D';
    }
    
    else
    {
        return 'F';
    }
    
}

string getStanding(double grade)
{
    if (grade >=70)
    {
        return "Good Standing";
    }
    else
    {
        return "See Advisor";
    }
    
}

double calculateTotalDue(int credits, double costPerCredit)
{
    return credits  * costPerCredit;
}

void displayWelcome()
{
    cout <<"=====================================================\n\n" 
         <<" MC File-Based Student Report Generator\n\n"
         <<"=====================================================\n";
}
