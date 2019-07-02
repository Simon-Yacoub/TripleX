#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    //Print welcome message to the terminal
    std::cout << "The nuclear missiles of the world have been activated!";
    std::cout << std::endl;
    std::cout << "Only you can stop them but, you must crack the level " << Difficulty << " clearance codes.";
    std::cout << std::endl;
    std::cout << "You must deactivate them using the correct codes to save the planet!\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    //declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    /*
    This is a multiline comment >:D
     */
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //print sum and product to the terminal
    std::cout << std::endl;
    std::cout << ">There a 3 numbers in the code" << std::endl;
    std::cout << ">The codes add-up to " << CodeSum << std::endl;
    std::cout << ">The codes multiply to give " << CodeProduct << std::endl;

    //Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB  + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if player guess is correct
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nWell done! You are one step closer to deactivating the nukes!\n";
        std::cout << "*************************************************************\n\n";
        return true;
    }
    else
    {
        std::cout << "\nYou entered the wrong code! Be careful, people's lives are in your hands!\n";
        std::cout << "*************************************************************************\n\n";
        return false;
    }

}


int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    while(LevelDifficulty <= MaxDifficulty)//loop game untill all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();//clears any errors
        std::cin.ignore();//discards the buffer

        if (bLevelComplete)
        {
            //increase level difficulty
            ++LevelDifficulty;
        }
        
    }
    std::cout << "Great Job! You saved the planet from nuclear destruction!";
    return 0;
}