
void setcolor(int ForgC)
{ 
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	
	if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
	{
		wColor=(csbi.wAttributes & 0xB0)+(ForgC & 0x0B);
	//	SetConsoleTextAttributes(hStdOut,wColor);
		SetConsoleTextAttribute(hStdOut,wColor);
	}
}

// Function to set console to full screen
void setFullScreen() {
    system("mode con: cols=150 lines=50"); // Approx. full screen
}

// Function to set color: 1F = Blue background, Bright white text
void setColor() {
    system("color 1F");
}

// Function to move cursor to X, Y position
void gotoxy(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function to center and print a string on given row
void centerText(const char* text, int row) {
    int len = strlen(text);
    int col = (120 - len) / 2;
    gotoxy(col, row);
    printf("%s", text);
}
// Function to center and print a string on given row
void printText(const char* text, int row,int col) {
    gotoxy(col, row);
    printf("%s", text);
}

void pauseScreen() {
    centerText("Press any key to continue...", 22);
    getch();
}
