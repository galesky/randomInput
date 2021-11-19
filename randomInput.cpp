#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
using namespace std;

vector<int> geraVetorShuffle(int size){
    
    //Random Seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
   
    //Create a vector with size (2*size)
    vector<int> vetor;
    for (int i=1; i<size*2; ++i) {
        vetor.push_back(i);
    }
    //Shuffle elements of vector
    shuffle(vetor.begin(),vetor.end(),default_random_engine(seed));

    //Get first (size) elements of the vector to return
    vetor.resize(size);
    return vetor;
}


void createDatFile(int size)
{
    //Define the file name of tipe DATE
	char fileName[21];
	sprintf(fileName, "Entrada_%d.dat", size);

    //Call the generation of elements
    vector<int> vetor = geraVetorShuffle(size);

    //Open File
	FILE *saveFile = fopen(fileName, "wb");

    //Write to file in Binary
    for (int i = 0; i < size; i++){
        fwrite(&vetor[i], sizeof(int), 1, saveFile);
    }

    //Close File
	fclose(saveFile);
}

void createTxtFile(int size)
{
    //Define the file name of tipe TXT
	char fileName[21];
	sprintf(fileName, "Entrada_%d.txt", size);

    //Call the generation of elements
    vector<int> vetor = geraVetorShuffle(size);

    //Open File
	FILE *saveFile = fopen(fileName, "wb");

    //Write to file
    for (int i = 0; i < size; i++){
        fprintf(saveFile, "%d ", vetor[i]);
    }

    //Close File
	fclose(saveFile);
}


int main(int argc, char** argv)
{
    int fileType = -1;

    //Verify params
    if (argc < 3) 
    {
        //No params
        if(argc < 2){
            printf("Missing arguments (number of elements and file type (0-TXT or 1-DAT)) \n");
            return 0;
        }
        //Only number of elements informed will use TXT
        else {
            printf("Missing argument (file type) using TXT\n");
            fileType = 0;
        }
    }
    //Converting params
    int numOfElements = atoi(argv[1]);
    if(fileType < 0){
        fileType = atoi(argv[2]);
    }

    //Creating file with param choice
    if( fileType == 1){
        printf("Will create a .dat file with %d elements\n", numOfElements);
        createDatFile(numOfElements);
    }else{
        printf("Will create a .txt file with %d elements\n", numOfElements);
        createTxtFile(numOfElements);
    }
}   

