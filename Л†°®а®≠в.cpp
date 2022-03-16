#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

/*
������� ��������� ������ �� ��������� ������������� ����� � ������.
���������, ���� �� ���� �� ����� ��� �� �������� �� ������ ��������
���� � ������ ������. ��������� ����� ������ �� ����������� � ���������.
*/

void print(int** arr, int sizex, int sizey) { //������ �������
    for (int y = 0; y < sizey+2; y++) {
        for (int x = 0; x < sizex+2; x++) {
            cout << arr[x][y];
        } cout << endl;
    }
}

void fill(int** arr, int sizex, int sizey) { //������ �������
    for (int y = 0; y < sizey+2; y++) {
        for (int x = 0; x < sizex+2; x++) {
            arr[x][y] = 5;
        }
    }
}

int main() {
    srand(time(0));
    ifstream myfile("yours.txt");

    int sizex = 10;
    int sizey = 5;

    int** arr = new int* [sizex+2]; //�������� �������
    for (int i = 0; i < sizex+2; i++) {
        arr[i] = new int[sizey+2];
    }

    fill(arr, sizex, sizey);

    char num2;
    for (int y = 1; y <= sizey; y++) { //��������� ������� ���������� �� ����������� �����
        for (int x = 1; x <= sizex; x++) {
            myfile >> num2;
            arr[x][y] = char(num2 - char('0'));
        }
    }
    
    print(arr, sizex, sizey);
  

    int curr[]{ 1,1 }; //������� ������� �������
    int num = arr[1][1]; //����� �� �������� �� �������
    int res = 0; //�����
    cout << arr[10][5];
    if (num == arr[10][5]) { //��������� ����� ���� �� �����
        while (true) {
            if (curr[0] == 10 && curr[1] == 5) { //����� �� ������ �� �����
                res = 1;
                break;
            }

            cout << curr[0] << curr[1] << "! "; //���������� ������� �� ������ ����
            if (arr[curr[0]][curr[1] + 1] == num) { //��������� ����
                curr[1]++;
            } else {
                if (arr[curr[0] + 1][curr[1]] == num) { //���� ���� �������� ����, �� ���� ���� �� �����������
                    curr[0]++;
                } else {
                    while (arr[curr[0]][curr[1] - 1] != num) { //������������ ������� ���� ���� ���
                        arr[curr[0]][curr[1]] = 0;
                        curr[0]--;
                        if (arr[curr[0]][curr[1]] == 5) { //���� ����������� � �������(�� ���� ���� ����) �� ���������� 0
                            cout << "0";
                            return 0;
                        }
                    }
                    while (arr[curr[0] + 1][curr[1]] != num) {
                        arr[curr[0]][curr[1]] = 0;
                        curr[1]--;
                        if (arr[curr[0]][curr[1]] == 5) {  //���� ����������� � �������(�� ���� ���� ����) �� ���������� 0
                            cout << "0";
                            return 0;
                        }
                    }
                }
                
            }
        }
    }

    cout << res; //����� ����������
}
