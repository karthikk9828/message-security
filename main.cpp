
#include <iostream>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <ctime>
#include <cstdio>
#include <sstream>

using namespace std;

#define max 300

int main()
{
    int size;
    static int new_i, new_j;
    char message[1000];
    int temp[max][max];
    int rows = 3, k=0, row, col, sum =0, c =0;

    float multiply[200][200];
    float dec_multiply[200][200];
    float determinant = 0;

    int key_matrix[3][3];
    float inverse_matrix[3][3];

    get_choice:
    int ch;
    cout << "\t\tMessage Security Using Matrices\n";
    cout << "\n1.Encrypt a message\n2.Decrypt a message\n";
    cin >> ch;

    if (ch==1)
    {
    get_key_matrix:

    srand((unsigned)time(0));
    int x;

    for(int i =0; i<3; i++)
    {
        for(int j =0; j<3; j++)
        {
            x = rand() / rand() + 1;
            key_matrix[i][j] = x;
        }
    }

    for(int i=0; i<3; i++)
    {
        determinant = determinant + (key_matrix[0][i] * (key_matrix[1][(i+1)%3] * key_matrix[2][(i+2)%3] - key_matrix[1][(i+2)%3] * key_matrix[2][(i+1)%3]));
    }

    if(determinant == 0)
    {
        goto get_key_matrix;
    }

    cout << "\nThe encryption key matrix is\n";
    for(int i =0; i<3; i++)
    {
        for(int j =0; j<3; j++)
        {
            cout << key_matrix[i][j] << " ";
        }
    }

    cout << "\n\nEnter your message\n";
    cin.get();
    gets(message);

    int i=0;
    while(message[i] != '\0')
    {
        ++c;
        i++;
    }

    size = c;
    int arr[size];

    for(int k =0; message[k] != '\0'; k++)
    {
        //arr[k] = int(message[k]);
        arr[k] = static_cast<int>(message[k]);
    }

    /*if(size%rows == 1)
        size = size+2;
    else if(size%rows == 2)
        size = size+1;
    else
        size = size;*/

    new_i = size/rows;
    new_j = size/new_i;

    char enc_message[new_i][3];

    int index = 0;
    for(int row =0; row<new_i; row++)
    {
        for(int col =0; col<new_j; col++)
        {
            temp[row][col] = arr[index];
            index++;
        }
    }

    for(int row =0; row<new_i; row++)
        {
            for(int col =0; col<3; col++)
            {
                for(int k =0; k<3; k++)
                {

                    multiply[row][col] = multiply[row][col] + temp[row][k] * key_matrix[k][col];
                    enc_message[row][col] = multiply[row][col];
                }
            }
        }
    cout << "\nMessage Encrypted successfully\n";
    cout << "Encrypted message is\n\n";

    for(int col =0; col<new_i; col++)
        {
            for(int k =0; k<3; k++)
            {
                cout << enc_message[col][k] << " ";
                //cout << int(enc_message[col][k]) << "  ";
                //cout << char(multiply[col][k]) << " ";
            }//cout << endl;
        }
        cout << "\n";

        /*for(int col =0; col<new_i; col++)
        {
            for(int k =0; k<3; k++)
            {
                //cout << enc_message[col][k] << " ";
                //cout << int(enc_message[col][k]) << "  ";
                cout << char(multiply[col][k]) << "  ";
            }//cout << endl;
        }*/
    cout << "\n\n\n\n";
    }

    else if(ch == 2)
    {
        int flag = 0, m, size1, length =0, i1, j1;
        int encryption_key[3][3];

        //get_enc_message:
        int c =0;
        /*int message[200][3];

        cout << "\nEnter your encrypted message here (append a '0')\n";

        for(int i =0; i<200; i++)
        {
            for(int j =0; j<3; j++)
            {
                cin >> message[i][j];
                c++;
                if(message[i][j] == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;

        }

        c = c - 1;

        int new_c = c / 3;
        int message1[new_c][3];

        for(int col =0; col<new_c; col++)
        {
            for(int k =0; k<3; k++)
            {
                message1[col][k] = message[col][k];
            }
        }*/

        char message[2000], msg[200][3];
        //int c =0;

        //cin.get();
        //gets(message);

        cout << "\nEnter your encrypted message here (append a '0')\n";

        for(int row =0; row<200; row++)
    {
        for(int col =0; col<3; col++)
        {
            cin >> msg[row][col];
            c++;
                if(msg[row][col] == '0')
                {
                    flag = 1;
                    break;
                }
        }
            if(flag == 1)
                break;

    }

    c = c - 1;

    /*if(c%rows == 1)
        c = c+2;
    else if(c%rows == 2)
        c = c+1;
    else
        c = c;*/

        //cout << "\nc: " << c << endl;

        int new_c = c / 3;
        int message1[new_c][3];

        for(int col =0; col<new_c; col++)
        {
            for(int k =0; k<3; k++)
            {
                message1[col][k] = int(msg[col][k]);
                //message1[col][k] = static_cast<int>(msg[col][k]);
                cout << message1[col][k] << "\t";
            }cout << endl;
        }

        /*int i=0;
    while(message[i] != '\0')
    {
        ++c;
        i++;
    }

    size = c;
    int arr[size];
    cout << endl << size << endl;

    for(int k =0; message[k] != '\0'; k++)
    {
        arr[k] = int(message[k]);
        //cout << arr[k] << "  ";
    }

    if(size%rows == 1)
        size = size+2;
    else if(size%rows == 2)
        size = size+1;
    else
        size = size;

    new_i = size/3;
    new_j = size/new_i;

    char new_msg[new_i][3];
    //cout << endl << size << endl << new_i << endl << new_j << endl;

    int index = 0;
    for(int row =0; row<new_i; row++)
    {
        for(int col =0; col<new_j; col++)
        {
            new_msg[row][col] = arr[index];
            index++;
        }
    }*/

    /*for(int row =0; row<new_c; row++)
    {
        for(int col =0; col<3; col++)
        {
            cout << message1[row][col] << "  ";
        }cout << endl;
    }*/

        get_encryption_key:
        cout << "\nEnter encryption key matrix\n";

        for(int i =0; i<3; i++)
        {
            for(int j =0; j<3; j++)
            {
                cin >> encryption_key[i][j];
            }
        }

        float determinant=0;
        for(int i=0; i<3; i++)
        {
        determinant = determinant + (encryption_key[0][i] * (encryption_key[1][(i+1)%3] * encryption_key[2][(i+2)%3] - encryption_key[1][(i+2)%3] * encryption_key[2][(i+1)%3]));
        }

        if(determinant == 0)
        {
            cout << "\nInvalid encryption key matrix\n";
            goto get_encryption_key;
        }

        for(int i =0; i<3; i++)
        {
            for(int j =0; j<3; j++)
            {
                inverse_matrix[i][j] = ((encryption_key[(j+1)%3][(i+1)%3] * encryption_key[(j+2)%3][(i+2)%3]) - (encryption_key[(j+1)%3][(i+2)%3] * encryption_key[(j+2)%3][(i+1)%3])) / determinant;
            }
        }

        float mid;

        for(int row =0; row<new_c; row++)
        {
            for(int col =0; col<3; col++)
            {
                dec_multiply[row][col] =0;
                for(int k =0; k<3; k++)
                {
                    mid = dec_multiply[row][col] + message1[row][k] * inverse_matrix[k][col];
                    dec_multiply[row][col] = ceilf(mid*100)/100;
                }
            }
        }

        cout << "\nDecrypted message is\n\n";
        for(int col =0; col<new_c; col++)
        {
            for(int k =0; k<3; k++)
            {
                cout << char(dec_multiply[col][k]);
            }
        }
        cout << "\n\n\n\n";
    }

    else
    {
        cout << "Invalid choice\n";
        goto get_choice;
    }

    return 0;
}
