#include <iostream>
#include <Windows.h>
using namespace std;

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;  
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };  
    SetConsoleCursorPosition(h,c);
}

void DrawFrame(int x, int xend, int y, int yend) {
	gotoxy(x, y);
	for (int i = x; i <= xend; i++) {
		if (i == x) {
			cout << char(218);
		}
		else if (i == xend) {
			cout << char(191);
		}
		else {
			cout << char(196);
		}
	} 
	gotoxy(x, yend);
	for (int i = x; i <= xend; i++) {
		if (i == x) {
			cout << char(192);
		}
		else if (i == xend) {
			cout << char(217);
		}
		else {
			cout << char(196);
		}
	}
	gotoxy(x, y+1);
	for (int i = y+1; i < yend; i++) {
		gotoxy(x, i);
		cout << char(179);
	}
	gotoxy(xend, y+1);
	for (int i = y+1; i < yend; i++) {
		gotoxy(xend, i);
		cout << char(179);
	}
}

void ChangeColor(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 3);
        cout << "color" << endl;
}
int main(){
    //(x start rộng, x end rộng, y start cao, y end cao);
    DrawFrame(20, 80, 3, 15); 
    cout << endl;
    ChangeColor();
    return 0;
}