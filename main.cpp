/* 
 * Lee Tran
 * 10/24/2015
 * ID:2468951
 * Created on October 20, 2015, 12:10 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

string value ();

string dealCard();

string swap(string& card1);

void clear();


/*
 * 
 */
int main(int argc, char** argv) {
    string card1; 
    string card2; 
    string card3;
    string card4; 
    string card5;
    string answer;
    
    cout << "Welcome to a Casino game!\n";
    int chips = 100;
    do
    {
        cout << "Your current currency is " << chips <<endl;
        cout << "Please enter the number of the game that";
                cout << " you would like to play\n";
        cout << "1)Five Card Poker\n2)Craps\n";
        int response;
        cin >> response;

        switch(response)
        {
            case 1:
    srand(time(0));
    clear();
    cout << "Welcome to 5 card Poker\n";
    //Explaining the rule of the game
    cout << "You win if you get a pair three of a kind, 4 of a kind, " << endl;
    cout << "two pair, or full house within the current hand."
    cout << "Enter start to begin the game\n";
    cin >> answer;
    clear();
    // loop to allow the user the option to continue playing or stop
    while(tolower(answer[0]) == 's')
    {
    cout << "Your current chips are " << chips << endl;
    cout << "Please enter your bet\n";
    int bet;
    cin >> bet;
    //Checks to see if the user is entering a bet that is larger than what they
    //have.
    while(bet > chips)
    {
        cout << "Not enough chips. Enter another bet\n";
        cin >> bet;
    }
    clear();
    card1 = dealCard();
    card2 = dealCard();
    card3 = dealCard();
    card4 = dealCard();
    card5 = dealCard();
    
    clear();
    cout << "Your starting hand is\n" << "Card 1 is " << card1 << endl;
    cout << "Card 2 is " << card2 << endl; 
    cout << "Card 3 is " << card3 << endl;
    cout << "Card 4 is " << card4 << endl; 
    cout << "Card 5 is " << card5 << endl;
    
    cout << "Would you like to switch out any card? yes or no\n";
    cin >> answer;
    //loop to allow the user to switch out cards
    if(tolower(answer[0]) == 'y')
    {
        cout << "How many cards do you want to exchange?\n";
        int amount;
        cin >> amount;
        // Loop checks if the user is entering an invalid number.
        while(amount > 5)
        {
            cout << "invalid amount, Please enter a number between 1-5\n";
            cin >> amount;
        }
        //Loop allowing the user to enter what card they want to exchange
        for (int i = 0; i < amount; i++)
        {
            cout << "Enter the card number that you wish to exchange ";
            int cardNum;
            cin >> cardNum;
    
            switch(cardNum)
            {
                case 1:
                    card1 = swap(card1);
                    break;
                case 2:
                    card2 = swap(card2);
                    break;
                case 3:
                    card3 = swap(card3);
                    break;
                case 4:
                    card4 = swap(card4);
                    break;
                case 5:
                    card5 = swap(card5);
                    break;
            }
        }
    }

    clear();
    cout << "Your final hand is\n" << "Card 1 is " << card1 << endl;
    cout << "Card 2 is " << card2 << endl; 
    cout << "Card 3 is " << card3 << endl;
    cout << "Card 4 is " << card4 << endl; 
    cout << "Card 5 is " << card5 << endl;
    //Nested loops to check for lose and win conditions.
    if(card1 != card2 && card1 != card3 & card1 != card4 && card1 != card5)
    {
    if(card2 != card1 && card2!= card3 && card2 != card4 && card2 != card5)
    {
    if(card3 != card4 && card3!= card5 && card3 != card1 && card3 != card2)
    {
    if(card4 != card5 && card4!= card1 && card4 != card2 && card4 != card3)
    {
        cout << "You lose\n";
        cout << "You lost " << bet << endl;
        chips = chips - bet;
    }
    else
    {
        cout << "You win!\n";
        cout << "You got " << bet << endl;
        chips = chips + bet;
    }
    }
    else
    {
        cout << "You win!\n";
        cout << "You got " << bet << endl;
        chips = chips + bet;
    }
    }
    else
    {
        cout << "You win!\n";
        cout << "You got " << bet << endl;
        chips = chips + bet;
    }
    }
    else
    {
        cout << "You win!\n";
        cout << "You got " << bet << endl;
        chips = chips + bet;
    }
    clear();
    cout << "Enter start to play again. N to exit\n";
    cin >> answer;
    }
                break;
            case 2:
    srand(time(0));
    clear();
    cout << "Welcome to Craps!\n";
    // Explaining the rule of the game.
    cout << "You win if you get a sum of 7 or 11\n";
    cout << "You lose if you get a sum of 2, 3 or 12\n";
    cout << "If you get any other number, then you go into round 2\n";
    cout << "In round 2, rolling a sum the same as round one is a win\n";
    cout << "Rolling a 7 is a lost, any other number is a reroll\n";
    cout << "Enter start to start the game\n";
    cin >> answer;
    //Loop that allows the user to continue or stop playing.
    while (tolower(answer[0]) == 's')
    {
    cout << "Your current chips are " << chips << endl;
    cout << "Please enter your bet\n";
    int bet;
    cin >> bet;
    //Loop to check if user is entering a bet larger than what they have.
    while(bet > chips)
    {
        cout << "Not enough chips. Enter another bet\n";
        cin >> bet;
    }
    
    
        clear();
        int dice1 = rand()%6 + 1;
        int dice2 = rand()%6 + 1;
        int sum1 = (dice1 + dice2);
        //Checks to see if the sum is a winning condition
        if(sum1 == 7 || sum1 == 11)
        {
            cout << "The sum of the two dices are " << sum1 << endl;
            cout << "You win!\n";
            cout << "You got " << bet << endl;
            
            chips = chips + bet;
        }
        //Checks to see if the sum is a losing condition
        else if(sum1 == 2 || sum1 == 3 || sum1 == 12)
        {
            cout << "The sum of the two dices are " << sum1 << endl;
            cout << "You Lose!\n";
            cout << "You lost " << bet << endl;
            chips = chips - bet;
        }
        //If it is neither a win or lose condition then round two begins
        else
        {
            clear();
            cout << "The sum of your roll is " << sum1 << endl;
            cout << "You have entered round 2!\n";
            int sum2 = 0;
            //Loop to determine if the new sum is equal to round one or not
            while(sum2 == 0)
            {
                dice1 = rand()%6+1;
                dice2 = rand()%6+1;
                sum2 = (dice1 +dice2);
                //Checks winning condition
                if(sum2 == sum1)
                {
                    cout << "The sum of the dice roll is " << sum2 << endl;
                    cout << "You win!\n";
                    cout << "You got " << bet << endl;
                    chips = chips + bet;
                }
                //Checks losing condition
                else if(sum2 == 7)
                {
                    cout << "The sum of the dice roll is " << sum2 << endl;
                    cout << "You lose!\n";
                    cout << "You lost " << bet << endl;
                    chips = chips - bet;
                }
                //Makes the program loop again if it is any other number.
                else
                {
                    cout << "The sum of the dice roll is " << sum2 << endl;
                    sum2 = 0;
                }
            }
            
        }
        cout << "Enter start to play again. N to exit.\n";
        cin >> answer;
        clear();
    }
                break;
            default:
                cout << "Wrong input\n"; 
        }
        //Condition checks to see if the user has any chips left to play with.
    } while (chips > 0);
            
    
    return 0;
}

/**
 * This function gets the relevant value and turns it into an actual card
 * @param num represents the random number that is assigned to a card
 * @return returns 1 of the 13 cards in a deck.
 */
string value (int num)
{
    if(num == 1)
    {
        return "Ace";
    }
    else if(num == 2)
    {
        return "2";
    }
    else if(num == 3)
    {
        return "3";
    }
    else if(num == 4)
    {
        return "4";
    }
    else if(num == 5)
    {
        return "5";
    }
    else if(num == 6)
    {
        return "6";
    }
    else if(num == 7)
    {
        return "7";
    }
    else if(num == 8)
    {
        return "8";
    }
    else if(num == 9)
    {
        return "9";
    }
    else if(num == 10)
    {
        return "10";
    }
    else if(num == 11)
    {
        return "Jack";
    }
    else if(num == 12)
    {
        return "Queen";
    }
    else if(num == 13)
    {
        return "King";
    }
}

/**
 * This function is used to determine what value a card will have when dealt to
 * the player
 * @return this function returns what card a user will end up getting
 */
string dealCard()
{
    string card;
    int cardvalue = rand()%13+1;
    card += value(cardvalue);
    return card;
}

/**
 * This function is used to swap the value of a card with another one
 * @param card1 represents the card that is being switched
 * @return Returns the value of the new card
 */
string swap(string& card1)
{
string card;
int cardvalue = rand()%13+1;
card += value(cardvalue);
return card;
}

/**
 * This function is used to add lines to the console to mimic a console clear
 */

void clear()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
    << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
