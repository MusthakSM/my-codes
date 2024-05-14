
// 1 TEST CASE Fails...

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int main(void)
{

    int r; // number of rounds;
    const int queTypes = 4;
    cin >> r;

    int** quesContainer = new int*[r];
    for (int i=0; i<r; i++)
    {
        quesContainer[i] = new int[queTypes];

        for (int j=0; j<queTypes; j++)
        {
            cin >> quesContainer[i][j];
        }
    }

    
    for (int i=0; i<r; i++)
    {
        int numberOfQuestions = 0;
        int RoundScore_A = 0;
        int RoundScore_B = 0;

        for (int j=0; j<queTypes; j++)
        {   
            if(j == 0)
            {
                numberOfQuestions += quesContainer[i][j];
                RoundScore_A += quesContainer[i][j];
                RoundScore_B += quesContainer[i][j];
                continue;
            }else if (j == queTypes-1 && quesContainer[i][j] != 0){
                
                int possibleMaxMinusScore = quesContainer[i][j];
                if(RoundScore_A < possibleMaxMinusScore && RoundScore_A <= RoundScore_B)
                {
                    numberOfQuestions += RoundScore_A + 1;
                    RoundScore_A = -1;
                    RoundScore_B -= RoundScore_A + 1;
                    break;

                }else if(RoundScore_B < possibleMaxMinusScore && RoundScore_B <= RoundScore_A)
                {
                    numberOfQuestions += RoundScore_B + 1;
                    RoundScore_B = -1;
                    RoundScore_A -= RoundScore_B + 1;
                    break;
                }
                
                if( RoundScore_A >= possibleMaxMinusScore && RoundScore_B >= possibleMaxMinusScore )
                {
                    numberOfQuestions += possibleMaxMinusScore;
                    RoundScore_A -= possibleMaxMinusScore;
                    RoundScore_B -= possibleMaxMinusScore;
                    break;
                }
            }else if(j == 1){
                if(quesContainer[i][j+1] == 0 && quesContainer[i][j] != 0)
                {
                    if(RoundScore_B > quesContainer[i][j])
                    {
                        RoundScore_B -= quesContainer[i][j];
                        RoundScore_A += quesContainer[i][j];
                        numberOfQuestions += quesContainer[i][j];
                    }else{
                        int increment = RoundScore_B;
                        RoundScore_B = -1;
                        RoundScore_A += increment + 1;
                        numberOfQuestions += increment + 1;
                        break;
                    }
                }else if(quesContainer[i][j+1] != 0 && quesContainer[i][j] == 0)
                {
                    if(RoundScore_A > quesContainer[i][j+1])
                    {
                        RoundScore_A -= quesContainer[i][j+1];
                        RoundScore_B += quesContainer[i][j+1];
                        numberOfQuestions += quesContainer[i][j+1];
                    }else{
                        int increment = RoundScore_A;
                        RoundScore_A = -1;
                        RoundScore_B += increment + 1;
                        numberOfQuestions += increment + 1;
                        break;
                    }
                }else if(quesContainer[i][j+1] != 0 && quesContainer[i][j] != 0)
                {
                    int temp_A = RoundScore_A + quesContainer[i][j] - quesContainer[i][j+1];
                    int temp_B = RoundScore_B + quesContainer[i][j+1] - quesContainer[i][j];

                    if(temp_A > -1 && temp_B > -1)
                    {
                        if(quesContainer[i][0] == 0 && temp_A == 0 && temp_B == 0)
                        {
                            RoundScore_A = 1;
                            RoundScore_B = -1;
                            numberOfQuestions += 1;
                            break;
                        }
                        else{
                            RoundScore_A = temp_A;
                            RoundScore_B = temp_B;
                            numberOfQuestions += quesContainer[i][j] + quesContainer[i][j+1];
                            continue;
                        }
                    }else{
                        if(temp_A <= -1 && temp_B > -1)
                        {
                            if(quesContainer[i][0] == 0)
                            {
                                RoundScore_A = -1;
                                RoundScore_B = 1;
                                numberOfQuestions += 1;
                                break;
                            }
                            else{int maxReduction = -1 - temp_A;
                            RoundScore_A = -1;
                            RoundScore_B = temp_B - maxReduction;
                            numberOfQuestions += quesContainer[i][j] + quesContainer[i][j+1] - maxReduction;
                            break;
                            }
                        }else if(temp_A > -1 &&  temp_B <= -1)
                        {
                            if(quesContainer[i][0] == 0)
                            {
                                RoundScore_B = -1;
                                RoundScore_A = 1;
                                numberOfQuestions += 1;
                                break;
                            }
                            else{    
                                int maxReduction = -1 - temp_B;
                                RoundScore_B = -1;
                                RoundScore_A = temp_A - maxReduction;
                                numberOfQuestions += quesContainer[i][j] + quesContainer[i][j+1] - maxReduction;
                                break;
                            }
                        }
                    }
                }

            }
        }
        cout << numberOfQuestions << endl;
    }

    

    for (int i=0; i<r; i++)
    {
        delete[] quesContainer[i];
        quesContainer[i] = NULL;
    }

    delete[] quesContainer;
    quesContainer = NULL;
    return 0;
}
