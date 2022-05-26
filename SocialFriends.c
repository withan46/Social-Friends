#include <stdio.h>
#include <stdbool.h>


//find when Stathis friends and hate between them
void makeNeighborArray(int members[13][13]);

//find if Stathis friends doesn't hate anyonse so he can come to the party
int findDearOnes(int members[13][13], char names[13][22], bool S[13], int people);

//find  people that have to come to the party
int findInvitations(int members[13][13], char names[13][22], bool S[13], int people);

/*
 * names[13][22] have the names of Stathis friends
 * members[13][13] have the hate between friends (1 if someone hate someone, else 0)
 * initialization S array with true (that means he is not in invitation list(visitorsArray))
 * so when someone is in the invitation list it turns to false
 * call method makeNeighborArray and find the hate between friends and save these in members array
 * call method findDearOnes and findInvitations and find the number of people should come
 */
int main() {
    char names[13][22] = {"Giannis", "Eva", "Nikos", "Akis", "Manos", "Dimitris", "Maria", "Eleni",
                          "Petros",
                          "Alexandros", "Zwh", "Anna",
                          "Lidia"};//I used greeklish because UTF8 didn't work 
    int members[13][13];
    bool S[13];
    for (int i = 0; i < 13; ++i) {
        S[i] = true;
    }

    int people = 0;//save the number of people in invitation list
    makeNeighborArray(members);
    printf("-----------------------------------------------\n");
    printf("the guests who can enter are: ");
    printf("\n-----------------------------------------------\n");
    people = findDearOnes(members, names, S, people);//find when someone does not hate anyone in Stathis friends list
    people = findInvitations(members, names, S, people);//find the friends that should come in party than other
    printf("***********************************************\n\n\n");


    printf("-----------------------------------------------\n");
    printf("The number of people who can enter is: %d\n", people);
    printf("-----------------------------------------------");
    return (0);
}

/*
 * Find when someone does not hate anyone so he add him in invitation list (visitorsArray)
 */
int findDearOnes(int members[13][13], char names[13][22], bool S[13], int people) {
    char visitorsArray[13][22] = {"", ""};
    int c = 0;
    for (int i = 0; i < 13; ++i) {
        int count = 0;
        if (S[i]) {//if friend isn't in visitorsArray
            for (int j = 0; j < 13; ++j) {
                if (members[i][j] == 1 && S[j]) {//if friend is leaf
                    count++;//count hates
                }
            }
            if (count == 0) {//He/She don't hate someone
                S[i] = false;
                c++;
                for (int j = 0; j < 22; ++j) {
                    visitorsArray[c][j] = names[i][j];
                }

            }
        }
    }


    //print the results without printing blank lines
    for (int i = 0; i < 13; ++i) {
        bool flag = false;
        for (int j = 0; j < 22; ++j) {
            if (visitorsArray[i][j] != NULL) {
                printf("%c", visitorsArray[i][j]);
                flag = true;
            }
        }
        if (flag) {
            printf("\n");
            people++;
        }
    }

    return people;
}

/*
 * Find  the most important friends and add them in the visitorsArray
 */
int findInvitations(int members[13][13], char names[13][22], bool S[13], int people) {
    char visitorsArray[13][22] = {"", ""};
    int position, c = 0;
    int count;
    for (int i = 0; i < 13; ++i) {
        count = 0;
        if (S[i]) {//if friend isn't in visitorsArray
            for (int j = 0; j < 13; ++j) {
                if (members[i][j] == 1 && S[j]) {//if friend is leaf
                    count++;//count the hates
                    position = j;
                }
            }
            if (count == 1) {
                S[i] = false;//goes off the leaf friend from visitorsArray
                S[position] = false;//goes off the leaf parent friend from visitorsArray
                c++;
                for (int j = 0; j < 22; ++j) {
                    visitorsArray[c][j] = names[i][j];
                }

            }
        }
    }

    //print the results without printing blank lines
    for (int i = 0; i < 13; ++i) {
        bool flag = false;
        for (int j = 0; j < 22; ++j) {
            if (visitorsArray[i][j] != NULL) {
                printf("%c", visitorsArray[i][j]);
                flag = true;
            }
        }
        if (flag) {
            people++;
            printf("\n");
        }
    }

    //call itself with new graph until we don't have leaves so we find all guests
    for (int i = 0; i < 13; ++i) {
        if (S[i]) {
            people = findInvitations(members, names, S, people);
        }
    }

    return people;
}

/*
 * make new array neighborArray[13][13] is initialized with 0 and if someone from Stathis friends list hate anyone
 * so he change this position with 1
 */
void makeNeighborArray(int members[13][13]) {
    int neighborArray[13][13] = {
            {0, 0},
            {0, 0}
    };

    //hate between friends
    neighborArray[0][3] = 1;
    neighborArray[1][4] = 1;
    neighborArray[2][3] = 1;
    neighborArray[2][12] = 1;
    neighborArray[3][4] = 1;
    neighborArray[4][7] = 1;
    neighborArray[5][6] = 1;
    neighborArray[5][7] = 1;
    neighborArray[6][7] = 1;
    neighborArray[6][9] = 1;
    neighborArray[7][8] = 1;
    neighborArray[9][11] = 1;


    //add to members array neighborArray array variables so it change in main function
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 13; ++j) {
            if (neighborArray[i][j] == 1)
                neighborArray[j][i] = 1;
            members[i][j] = neighborArray[i][j];
        }
    }
}