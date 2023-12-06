#include "Company.h"

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    Company company;

    string input;

    int money = 0;

    int numDays = 0;
    int numInfected = 0;
    int totalInfected = 0;

    cout << "--------------------------------------" << endl;
    cout << "Employee Zombie Simulator" << endl;
    cout << "--------------------------------------" << endl;
    cout << endl;
    cout << "Press a key to start : ";
    cin >> input;

    int infectedSup = 0;

    system("cls");


    while (numDays < 28 && totalInfected < 100) {
        
        numInfected = 0;
        for (int i = 0; i < company.employees.size(); i++) {
            if (!company.employees[i].CheckIsZombified()) {
                if (rand() % 101 <= totalInfected) { //INCUBATION CHANCE
                    company.employees[i].SetNewZombieficationState(INCUBATING);
                }
                company.employees[i].HandleInfection(); //IS NOT INFECTED
                money += 26000 / 228;
            }
            else
            { 
                numInfected++; //IS A ZOMBIE
                money += 45000 / 228;
            }
        }

        cout << "Day : " << numDays + 1 << endl;
        cout << endl;

        if (numInfected == 0) {
            switch (infectedSup) {
            case 0:
                cout << "You arrive at work and discover all your employees in great shape, what a great day at work..." << endl;
                break;
            case 1:
                cout << "Employee number " << company.employees[rand() % company.employees.size()].id << " seems weird today but hey it must be the job..." << endl;
                break;
            case 2:
                cout << "Employees number " << company.employees[rand() % company.employees.size()].id <<" and " << company.employees[rand() % 101].id <<" seems weird today but hey it must be the job..." << endl;
                break;
            }
        }
        else if (numInfected > 0 && numInfected < 10) {
            cout << "I arrive at work, a new day begins and... ZOMBIES, I'm going to have to raise their salaries if I don't want to die" << endl;
        }
        else {
            int randomDialogue = rand() % 101;
            switch (randomDialogue) {
            case 1:
                cout << "HE JUST PUFFED MY PENCIL !" << endl;
            case 10:
                cout << "Today day " << numDays << ", I find myself playing cards with the zombies (I was forced)" << endl;
                break;
            case 20:
                cout << "The coffee machine doesn't work anymore..." << endl;
                break;
            case 30:
                cout << "HELP MEEEEE !!!" << endl;
                break;
            case 40:
                cout << "I knew I shouldn't have joined Ubisoft..." << endl;
                break;
            case 50:
                cout << "Small card game with survivors in toilet" << endl;
                break;
            case 60:
                cout << "Today we have zombie octagons" << endl;
                break;
            case 70:
                cout << "I forgot to lock my PC, zombies or put bizzare pictures on it..." << endl;
                break;
            case 80:
                cout << "Maybe I should call the police?" << endl;
                break;
            case 90:
                cout << "I was locked up all night because they ate the guard" << endl;
                break;
            case 99:
                cout << "I need to play agario to feel good better" << endl;
                break;
            default:
                cout << "More zombies..." << endl;
                break;
            }
        }
        cout << endl;
        cout << "Press a key to roll your dice : ";
        cin >> input;

        system("cls");

        int roll1 = rand() % 6 + 1;
        int roll2 = rand() % 6 + 1;

        infectedSup = 0;

        if (roll1 + roll2 >= 3 && roll1 + roll2 <= 6) {
            for (int i = 0; i < company.employees.size() && infectedSup < 1; i++) {
                if (!company.employees[i].CheckIsZombified()) {
                    company.employees[i].SetNewZombieficationState(INCUBATING);
                    infectedSup++;
                }
            }
            cout << "You do, " << roll1 << " and " << roll2 << " ! , An employee has been infected" << endl;
        }
        else if (roll1 + roll2 >= 7 && roll1 + roll2 <= 11) {
            for (int i = 0; i < company.employees.size() && infectedSup < 2; i++) {
                if (!company.employees[i].CheckIsZombified()) {
                    company.employees[i].SetNewZombieficationState(INCUBATING);
                    infectedSup++;
                }
            }
            cout << "You do, "<<roll1 <<" and "<<roll2 << " ! , Two employees have been infected" << endl;
        }
        else if (roll1 + roll2 == 12) {
            for (int i = 0; i < company.employees.size() && infectedSup < 2; i++) {
                if (!company.employees[i].CheckIsZombified()) {
                    company.employees[i].SetNewZombieficationState(ZOMBIFIED);
                    numInfected += 2;
                    infectedSup++;
                }
            }
            cout << "You do, " << roll1 << " and " << roll2 << " ! , Oh no, four employees turned into zombies right in front of your eyes !" << endl;
        }
        else {
            cout << "You do, " << roll1 << " and " << roll2 << " ! , Nothing happens, well done !" << endl;
        }

        totalInfected = numInfected;

        cout << endl <<"Day " << numDays + 1 << " : Infected : " << numInfected << "/100" << " : Infection rate : " << totalInfected << "%" << endl<<endl; //DAILY SCREEN
        cout << "--------------------------------------------" << endl<<endl;

        numDays++;
    }

    if (numDays >= 28) {
        cout << "You survived 28 days,but you loose : "<< money <<"$" << endl; //WIN SCREEN
    }
    else {
        cout << "Game Over, you survived " << numDays << " days, " << "but you loose : " << money << "$" << endl; //DEAD SCREEN
        cout << "The month isn't over and all your employees are zombies, paying them will cost you dearly... I knew I should never have been in charge of a game design team...";
    }
}
