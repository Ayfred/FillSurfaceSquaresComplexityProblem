#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


int main () {
    freopen("resource/s1.txt", "rb", stdin);
    string file_contents[3];
    string line;
    int i = 0;

    while(getline(cin, line))
    {   
        file_contents[i] = line;
        cout << line << endl;
        i += 1;
    }
    cout << "\n"<< endl;

    int k = 0;
    int nbt = 0;

    for(int i = 1; i <= stoi(file_contents[0]); i++)
    {
        for(int j = 1; j <= stoi(file_contents[1]); j++)
        {   
            if(file_contents[2][k] == '1'){
                cout << ". ";
                nbt++;
            }
            else{
                cout << "* ";
            }
            
            if(j == stoi(file_contents[1])){
                cout << "\n";
            }
            k++;
        }
    }

    cout << "\n"<< endl;
    cout << "hauteur " << file_contents[0] << endl;
    cout << "largeur " << file_contents[1] << endl;
    cout << "nbt " << nbt << endl;    
    
    int H = stoi(file_contents[1]);
    int L = stoi(file_contents[0]);
    string table[H][L];
    int k1 = 0;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < L; j++){
            table[i][j] = file_contents[2][k1];
            k1++;

            cout << table[i][j] << " ";
            if(j == L-1){
                cout << "\n";
            }
        }
    }
    //table initiale
    int table_copy[H][L];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < L; j++){
            table_copy[i][j] = stoi(table[i][j]);
        }
    }

    //table 90
    int table_copy_90[L][H];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < L; j++){
            table_copy_90[L-j-1][i] = stoi(table[i][j]);
        }
    }

    //table 180
    int table_copy_180[H][L];
    for(int i = 0; i < L; i++){
        for(int j = 0; j < H; j++){
            table_copy[H-j-1][i] = table_copy_90[i][j];
        }
    }

    //table 270
    int table_copy_270[L][H];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < L; j++){
            table_copy_270[L-j-1][i] = table_copy_180[i][j];
        }
    }
    
     

    //for(int i = 0; i < L; i++){
    //    for(int j = 0; j < H; j++){
    //        printf("%i ", table_copy[i][j]);
    //    }
    //    printf("\n");
    //}

    int counter_H = 0;
    int counter_L = 0;
    int squareIndex[H][L];
    int count = 0;
    int tempH = H;
    //H = L;
    //L = tempH;
    //printf("H = %d", H); printf("L = %d", L);

    for(int i=0; i< H; i++){
        for(int j=0; j<L; j++){
            //printf("(i = %i, ", i);
            //printf("j = %i)\n", j);
            if(table_copy[i][j] == 0){
                int side = 0;
                bool error = false;
                while(i+side < H && j+side < L && !error){
                    side++;
                    if(table_copy[i+side][j+side] == 0){
                        for(int iP = i; iP <i+side; iP++){
                            if(table_copy[iP][j+side] >= 1){
                                //printf("(iP  = %i, ", iP);
                                //printf("j+side  = %i)\n", j+side);
                                error = true;
                            }
                        }
                    
                        for(int jP = j; jP <j+side; jP++){
                            if(table_copy[i+side][jP] >= 1){
                                //printf("(jP  = %i, ", jP);
                                //printf("i+side  = %i)\n", i+side);
                                error = true;
                            }
                        }
                    }
                    else{
                        count++;
                        break;
                    }
                    if(error){count++;}
                }

                for(int k = 0; k < side; k++){
                    for(int m = 0; m < side; m++){
                        //printf("side print = %i\n", side);
                        table_copy[i+k][j+m] = side;
                    }
                }
            }
        }
    }
    printf("\n");


    for(int i = 0; i < H; i++){
        for(int j = 0; j < L; j++){
            printf("%i ", table_copy[i][j]);
        }
        printf("\n");
    }
    printf("carres = %i\n", count);

    return 0;
}
