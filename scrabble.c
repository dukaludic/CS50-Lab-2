#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int abc[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int compute_score(string word);
string to_uppercase(string word);

int main(void)
{
    //Get input from both players
    string word1 = get_string("Player 1: ");
    word1 = to_uppercase(word1);
    printf("%s\n", word1);
    string word2 = get_string("Player 2: ");
    word2 = to_uppercase(word2);
    printf("%s\n", word2);


    //Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    printf("%i\n", score1);
    printf("%i\n", score2);


    //Print the winner

    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 Wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

}

int compute_score(string word)
{
    int sum = 0;
    for(int i = 0, n = strlen(word); i < n; i++ )
    {
        for (int j = 0; j < 25; j++ )
        {
            if (word[i] == abc[j])
            {
                sum += POINTS[j];
                // printf("%i\n", POINTS[j]);
            }
        }
    }
    return sum;
}

string to_uppercase(string word)
{
    for (int i = 0, n = strlen(word); i < n; i++)
    {

        if(isupper(word[i]))
        {
            word[i] = tolower(word[i]);
        }
    }
    return word;
}
