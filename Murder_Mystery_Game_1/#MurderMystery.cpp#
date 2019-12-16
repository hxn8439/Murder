#include "MurderMystery.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void Game :: setCase(Case c)
{
    start.push_back(c);
}
Case Game :: getCase(int caseNum)
{
    return start[caseNum];
}

int Menu :: getChoice()
{
    //Print menu
    //Set choice = to the case that user chose
    return choice;
}

void Case :: setClue(string clue)
{
    clues.push_back(clue);
}
void Case :: setSolved(bool solved)
{
    this->solved = solved;
}
string Case :: getClue(int clueNum)
{
    return clues[clueNum];
}

string CaseStory :: getHowToPlay()
{
    return howToPlay;
}
string CaseStory :: getBackStory()
{
    return backStory;
}
Person CaseStory :: getCharacter(int characterNum)
{
    return characters[characterNum];
}


    //Not sure on constructors
Person::Person(string name, string description)
{
    this->name = name;
    alibi = description;
}
void Person :: setMurderer(bool guilty)
{
    murderer = guilty;
}
bool Person :: getMurderer()
{
    return murderer;
}
string Person :: getName()
{
    return name;
}
string Person :: getAlibi()
{
    return alibi;
}
