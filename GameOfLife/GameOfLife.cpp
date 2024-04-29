#include <iostream>
#define MAX 10

using namespace std;


static void checkAliveNeighbours(char arr[MAX][MAX], char arr2[MAX][MAX], int x, int y) {
    int tabX[8] = { 0, 0, 1, 1, -1, -1, 1, -1
    };
    int tabY[8] = { 1, -1, 1, -1, 1, -1, 0, 0
    };
    int counter = 0;

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {

            for (int k = 0; k < 8; ++k) {
                if (arr[i + tabX[k]][j + tabY[k]] == '1')
                    counter++;

            }
            arr2[i][j] = char(counter);
            counter = 0;

        }

    }
}


void printBoard(char arr[MAX][MAX], int x, int y) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            cout << arr[i][j];

        }
        cout << "\n";

    }
}


int main() {
    char arr[MAX][MAX];
    char arr2[MAX][MAX];
    char arr3[MAX][MAX];

    int sizeX, sizeY;
    cin >> sizeX >> sizeY;

    for (int i = 0; i < sizeX; ++i) {
        for (int j = 0; j < sizeY; ++j) {
            cin >> arr[i][j];

        }

    }

    int mode;
    cin >> mode;


    if (mode == 0) {
        checkAliveNeighbours(arr, arr2, sizeX, sizeY);

        for (int i = 0; i < sizeX; ++i) {
            for (int j = 0; j < sizeY; ++j) {
                cout << int(arr2[i][j]);

            }
            cout << "\n";

        }

    }

    if (mode == 1) {
        int n;
        cin >> n;


        checkAliveNeighbours(arr, arr2, sizeX, sizeY);

        for (int p = 0; p < n; ++p) {
            printBoard(arr, sizeX, sizeY);

            for (int i = 0; i < sizeX; ++i) {
                for (int j = 0; j < sizeY; ++j) {
                    if (arr[i][j] == '0' && (int(arr2[i][j]) >= 3)) {
                        arr[i][j] = '1';

                    }
                    if (arr[i][j] == '1' && (int(arr2[i][j]) != 2 && int(arr2[i][j]) != 3)) {
                        arr[i][j] = '0';

                    }

                }

            }

            checkAliveNeighbours(arr, arr2, sizeX, sizeY);

        }
        printBoard(arr, sizeX, sizeY);

    }


    return 0;
}