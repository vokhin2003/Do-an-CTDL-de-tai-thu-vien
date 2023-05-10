struct Button{
	int id, x, y, width, height;
	char title[50];
	bool isHover, isChoose;
	
	Button(int i, int xx, int yy, int wid, int hei, char s[50]) {
		id = i;
		x = xx; y = yy;
		width = wid; height = hei;
		strcpy(title, s);
	}
	
	void draw() {
		setfillstyle(SOLID_FILL, isHover ? BG_BUTTON_SELECT : BG_BUTTON_DEFAULT);
		bar(x, y, x + width, y + height);
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
		setbkcolor(isHover ? BG_BUTTON_SELECT : BG_BUTTON_DEFAULT);
		setcolor(isHover ? TEXT_BUTTON_SELECT : TEXT_BUTTON_DEFAULT);
		outtextxy(x + width/2 - textwidth(title)/2, y + height/2 - textheight(title)/2, title);
		setbkcolor(BG_COLOR);
	}
	
	bool isMouseHover(int mx, int my) {
		return mx >= x && mx <= x+width && my >= y  && my <= y+height;
	}
};


struct EditText{
	int id, x, y , width, height;
	char title[50], content[50], hint[50];
	bool isHover, isChoose;
	char** dataFill;
	
	EditText(int i, int xx, int yy, int wid, int hei, char s[50], char c[50], char hi[50], char **datafill = NULL) {
		id = i;
		x = xx; y = yy;
		width = wid; height = hei;
		strcpy(title, s);
		strcpy(content, c);
		strcpy(hint, hi);
		isHover = false;
		dataFill = datafill;
	}
	
	void draw() {
		setbkcolor(BG_COLOR);
		// Ve tieu de
		settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
		setcolor(TEXT_BUTTON_DEFAULT);
		outtextxy(x, y + height/2 - textheight("T")/2, title);
		
		// Ve background
		setfillstyle(SOLID_FILL, BG_BUTTON_DEFAULT);
		bar(x + 150, y, x + width, y + height);
		
		if (strlen(content) == 0) {
			// Ve hint
			setcolor(TEXT_BUTTON_DEFAULT);
			setbkcolor(BG_BUTTON_DEFAULT);
			outtextxy(x + 160, y + height/2 - textheight("H")/2, hint);
		} else {
			// Ve noi dung nguoi dung nhap vao
			setcolor(TEXT_COLOR_SELECTED);
			setbkcolor(BG_BUTTON_DEFAULT);
			outtextxy(x + 160, y + height/2 - textheight("C")/2, content);
			
			if (dataFill != NULL) {
				int pos = toInt();
				if (pos != -1) {
					outtextxy(x + width - textwidth(dataFill[pos]) - 20, y + height/2 - textheight("C")/2, dataFill[pos]);
				}
			}	
		}
		setbkcolor(BG_COLOR);
	}
	
	int toInt() {
		int x = 0;
		for (int i = 0; i < strlen(content); i++) {
			if (i > 0 && content[i] == '_') break;
			if (content[i] >= '0' && content[i] <= '9') {
				x = x * 10 + (content[i] - '0');
			} else return -1;
		}
		return x;
	}
	
	char* trim() {
		int n = strlen(content);
		if (content[n-1] == ' ') content[n-1] = '\0';
		return content;
	}
	
	bool isMouseHover(int mx, int my) {
		return (mx >= x + 160 && mx <= x + width && my >= y && my <= y + height);
	}
};
