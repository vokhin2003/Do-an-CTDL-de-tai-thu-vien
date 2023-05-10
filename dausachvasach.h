void DrawDanhSachDauSach() {
	ClearScreen(1);
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	setcolor(TEXT_COLOR);
	setbkcolor(BG_COLOR);
	outtextxy(w/2 - textwidth(DauSachTitle)/2, 15, DauSachTitle);
	
	btnQuayVe.draw();
	btnClearTimDauSach.draw();
	btnAddDauSach.draw();
	btnPrev.draw();
	btnNext.draw();
	
	edTimDauSach.draw();
	
	char ch[6][20] = {"ISBN", "TEN SACH", "SO TRANG", "TAC GIA", "NXB", "THE LOAI"};
	
	settextstyle(3, HORIZ_DIR, 3);
	setfillstyle(USER_FILL, PANEL);
	setbkcolor(PANEL);
	setcolor(BG_COLOR);
	
	bar(XDSDS[0], 152, w - 200, 215);
	
	for (int i = 0; i < 6; i++) {
		outtextxy(XDSDS[i] + (XDSDS[i+1] - XDSDS[i]) / 2 - textwidth(ch[i])/2, 170, ch[i]);
	}
	
	setbkcolor(BG_COLOR);
	setcolor(BG_COLOR);
	
	// tips
	setcolor(TEXT_COLOR);
	rectangle((w/2) - 350, 850, (w/2) + 350, 950);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	outtextxy((w/2) - 290, 875, "Click chuot trai: Hieu chinh va xoa dau sach");
	outtextxy((w/2) - 290, 900, "Click chuot phai: Xem thong tin, danh muc sach");
}

void DrawThemDauSach() {
	ClearScreen(1);
	setfillstyle(USER_FILL, PANEL);
	setbkcolor(PANEL);
	bar((w/2) - 400, 210, (w/2) + 400, 280);
	
	// dinh dang tieu de khung THEM DAU SACH
	setcolor(BORDER_COLOR);
	setlinestyle(SOLID_FILL, 0, 3);
	rectangle((w/2) - 400, 210, (w/2) + 400, 700);
	line((w/2) - 400, 280, (w/2) + 400, 280);
	line((w/2) - 400, 650, (w/2) + 400, 650);
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	setcolor(BG_COLOR);
	outtextxy((w / 2) - textwidth(ThemDauSach) / 2, 245 - textheight(ThemDauSach) / 2, ThemDauSach);
	
	setbkcolor(BG_COLOR);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setcolor(TEXT_COLOR);
	outtextxy(XDSDS[7]-30, 675-textheight(ThongBao)/2, ThongBao);
	
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar((w / 2) - 390 + textwidth(ThongBao), 675 - textheight(ThongBao) / 2, (w / 2) + 390, 675 + textheight(ThongBao) / 2);
	
	setcolor(TIPS);
	outtextxy(XDSDS[7] - 10 + textwidth(ThongBao), 675 - textheight(ThongBao) / 2, mess);
	
	edThemISBN.draw();
	edThemTenSach.draw();
	edThemSoTrang.draw();
	edThemTacGia.draw();
	edThemNXB.draw();
	edThemTheLoai.draw();
	
	btnThemDauSach.draw();
	btnClearThemDauSach.draw();
	btnBack.draw();
}

void DrawHieuChinhDauSach() {
	ClearScreen(1);
	setfillstyle(USER_FILL, PANEL);
	setbkcolor(PANEL);
	bar((w/2) - 400, 210, (w/2) + 400, 280);
	
	// dinh dang tieu de khung HIEU CHINH DAU SACH
	setcolor(BORDER_COLOR);
	setlinestyle(SOLID_FILL, 0, 3);
	rectangle((w/2) - 400, 210, (w/2) + 400, 700);
	line((w/2) - 400, 280, (w/2) + 400, 280);
	line((w/2) - 400, 650, (w/2) + 400, 650);
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	setcolor(BG_COLOR);
	outtextxy((w / 2) - textwidth(HieuChinhDauSach) / 2, 245 - textheight(HieuChinhDauSach) / 2, HieuChinhDauSach);
	
	setbkcolor(BG_COLOR);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setcolor(TEXT_COLOR);
	outtextxy(XDSDS[7]-30, 675-textheight(ThongBao)/2, ThongBao);
	
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar((w / 2) - 390 + textwidth(ThongBao), 675 - textheight(ThongBao) / 2, (w / 2) + 390, 675 + textheight(ThongBao) / 2);
	
	setcolor(TIPS);
	outtextxy(XDSDS[7] - 10 + textwidth(ThongBao), 675 - textheight(ThongBao) / 2, mess);
	
	edHieuChinhISBN.draw();
	edHieuChinhTenSach.draw();
	edHieuChinhSoTrang.draw();
	edHieuChinhTacGia.draw();
	edHieuChinhNXB.draw();
	edHieuChinhTheLoai.draw();
	
	btnBack.draw();
	btnHieuChinhDauSach.draw();
	btnDeleteDauSach.draw();
	btnClearHieuChinhDauSach.draw();	
}


void GetHieuChinhDauSach(DS_DauSach &DSDS,int i){
	currentDauSach = i;
	ClearScreen(3);
	
	char ch[10];
	strcpy(edHieuChinhISBN.content, DSDS.nodes[i]->ISBN);
	strcpy(edHieuChinhTenSach.content, DSDS.nodes[i]->tenSach);
	itoa(DSDS.nodes[i]->soTrang, ch, 10);
	strcpy(edHieuChinhSoTrang.content, ch);
	strcpy(edHieuChinhTacGia.content, DSDS.nodes[i]->tacGia);
	itoa(DSDS.nodes[i]->nxb, ch, 10);
	strcpy(edHieuChinhNXB.content, ch);
	strcpy(edHieuChinhTheLoai.content, DSDS.nodes[i]->theLoai);
	
	ClearScreen(1);
	DrawHieuChinhDauSach();
}

void DrawThemSach(DS_DauSach &DSDS) {
	// auto create ma sach sau moi lan load trang them sach
	
	if (currentNhapSach == 1) {
		startIndexSach = DSDS.nodes[currentDauSach]->soLuong;
	} else {
		startIndexSach++;
	}
	
	char id[15];
	sprintf(id, "%s-%d", DSDS.nodes[currentDauSach]->ISBN, startIndexSach);
	strcpy(edThemMaSach.content, id);
	
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar((w/2) - 450, 650, (w/2) + 450, 980);
	
	setfillstyle(USER_FILL, PANEL);
	setbkcolor(PANEL);
	bar((w/2) - 450, 650, (w/2) + 450, 700);
	rectangle((w/2) - 450, 650, (w/2) + 450, 980);
	line((w/2) - 450, 700, (w/2) + 450, 700);
	line((w/2) - 450, 930, (w/2) + 450, 930);
	
	strcpy(edThemTrangThaiSach.content, "0");
	memset(edThemViTriSach.content, 0, sizeof(edThemViTriSach.content));
	char ch[30], c[3];
	sprintf(ch, "%s %d / %d", ThemSach, currentNhapSach, totalNhapSach);
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	setcolor(BG_COLOR);
	outtextxy((w/2) - textwidth(HieuChinhSach) / 2 - 25, 675 - textheight(ch) / 2, ch);
	setbkcolor(BG_COLOR);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setcolor(TEXT_COLOR);
	outtextxy((w/2) - 440 , 955 - textheight(ThongBao) / 2, ThongBao);
	
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar((w/2) - 430 + textwidth(ThongBao), 955 - textheight(ThongBao) / 2, (w/2) + 430, 955 + textheight(ThongBao) / 2);
	
	btnThemSach.draw();
	edThemMaSach.draw();
	edThemTrangThaiSach.draw();
	edThemViTriSach.draw();
	btnBackToNhapSach.draw();	
}

void DrawHieuChinhSach() {
	// Clear subWindow
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar(XDMS[0], 580, XDMS[3], 985);
	
	setfillstyle(USER_FILL, PANEL);
	setbkcolor(PANEL);
	bar(XDMS[0], 650, XDMS[3], 700);
	rectangle(XDMS[0], 650, XDMS[3], 980);
	line(XDMS[0], 700, XDMS[3], 700);
	line(XDMS[0], 930, XDMS[3], 930);
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	setcolor(BG_COLOR);
	outtextxy((w / 2) - textwidth(HieuChinhSach) / 2, 675 - textheight(HieuChinhSach) / 2, HieuChinhSach);
	
	setbkcolor(BG_COLOR);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setcolor(TEXT_COLOR);
	outtextxy(XDMS[0] + 10, 955 - textheight(ThongBao) / 2, ThongBao);
	
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar(XDMS[0] + 20 + textwidth(ThongBao), 955 - textheight(ThongBao) / 2, XDMS[3] - 20, 955 + textheight(ThongBao) / 2);
	
	setcolor(TIPS);
	outtextxy(XDMS[0] + 40 + textwidth(ThongBao), 955-  textheight(ThongBao) / 2, mess);
	
	
	btnHieuChinhSach.draw();
	edHieuChinhMaSach.draw();
	edHieuChinhTrangThaiSach.draw();
	edHieuChinhViTriSach.draw();
	btnBackToNhapSach.draw();
}



// Ve ItemDauSach: Neu j = -1 thi ve theo i. Neu j != -1 thi ve theo j
void DrawItemDauSach(DS_DauSach DSDS, int i, int j) {
	char tmp[10];
	outtextxy(XDSDS[0] + 10, 230 + (j != -1 ? j : (i % 13)) * 40, DSDS.nodes[i]->ISBN);
	outtextxy(XDSDS[1] + 10, 230 + (j != -1 ? j : (i % 13)) * 40, DSDS.nodes[i]->tenSach);
	itoa(DSDS.nodes[i]->soTrang, tmp, 10);
	outtextxy(XDSDS[2] + (XDSDS[3] - XDSDS[2]) / 2 - textwidth(tmp) / 2, 230 + (j != -1 ? j : (i % 13)) * 40, tmp);
	outtextxy(XDSDS[3] + 10, 230 + (j != -1 ? j : (i % 13)) * 40, DSDS.nodes[i]->tacGia);
	itoa(DSDS.nodes[i]->nxb, tmp, 10);
	outtextxy(XDSDS[4] + (XDSDS[5] - XDSDS[4]) / 2 - textwidth(tmp) / 2, 230 + (j != -1 ? j : (i % 13)) * 40, tmp);
	outtextxy(XDSDS[5] + (XDSDS[6] - XDSDS[5]) / 2 - textwidth(DSDS.nodes[i]->theLoai) / 2, 230 + (j != -1 ? j : (i % 13)) * 40, DSDS.nodes[i]->theLoai);
}

void DrawListDSDS(DS_DauSach &DSDS) {
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(BORDER_COLOR);
	rectangle(XDSDS[0], 150, XDSDS[6], 750);
	for (int i=0;i<5;i++) {
		setlinestyle(SOLID_LINE, 0, 1);
		line(XDSDS[i+1], 150, XDSDS[i+1], 750);
	}
	
	// TINH TOAN SO TRANG
	settextstyle(3, HORIZ_DIR, 2);
	if (strlen(edTimDauSach.content) == 0) { // Truong hop khong tim kiem dau sach
		totalPageDauSach = (DSDS.n + 13 - 1) / 13;
		for (int i = 13 * (currentPageDauSach - 1); i < 13 * currentPageDauSach; i++) {
			if (i >= DSDS.n) break;
			DrawItemDauSach(DSDS, i, -1);
		}
	} else { // Truong hop tim kiem dau sach
		totalPageDauSach = (sizeListIndexDauSachSearch + 13 - 1) / 13;
		int j = 0;
		for (int i = 13 * (currentPageDauSach - 1); i < 13 * currentPageDauSach; i++) {
			if (i >= sizeListIndexDauSachSearch) break;
			DrawItemDauSach(DSDS, listIndexDauSachSearch[i], j++);
		}
	}
	
	// Ve number page
	
	setcolor(TEXT_BUTTON_DEFAULT);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	char numPag[20];
	sprintf(numPag, "TRANG %d / %d", currentPageDauSach, totalPageDauSach);
	outtextxy((XDSDS[0] + XDSDS[6]) / 2 - textwidth(numPag) / 2, 785, numPag);
}

void DrawItemSach(Sach sach, int i) {
	setcolor(TEXT_COLOR);
	outtextxy((XDMS[0] + XDMS[1]) / 2 - textwidth(sach.MASACH) / 2, 170 + i * 40, sach.MASACH);
	outtextxy((XDMS[1] + XDMS[2]) / 2 - textwidth(TrangThaiSach[sach.trangThai]) / 2, 170 + i * 40, TrangThaiSach[sach.trangThai]);
	outtextxy((XDMS[2] + XDMS[3]) / 2 - textwidth(sach.viTri) / 2, 170 + i * 40, sach.viTri);
}


void DrawListSach(DS_DauSach &DSDS) {
	setfillstyle(USER_FILL, BG_COLOR);
	bar((w/2) - 448, 102, (w/2) + 449, 500);
	
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(BORDER_COLOR);
	rectangle(XDMS[0], 100, XDMS[3], 500);
	line(XDMS[1], 100, XDMS[1], 500);
	line(XDMS[2], 100, XDMS[2], 500);
	
	setcolor(TEXT_BUTTON_DEFAULT);
	setbkcolor(BG_COLOR);
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	outtextxy((XDMS[0] + XDMS[3]) / 2 - textwidth(DanhMucSach) / 2 - textwidth(DSDS.nodes[currentDauSach]->tenSach) / 2, 20, DanhMucSach);
	setcolor(TEXT_COLOR_SELECTED);
	outtextxy((XDMS[0] + XDMS[3]) / 2 - textwidth(DSDS.nodes[currentDauSach]->tenSach) / 2 + 130, 20, DSDS.nodes[currentDauSach]->tenSach);
	
	setfillstyle(USER_FILL, PANEL);
	bar((w/2) - 448, 102, (w/2) + 449, 150);
	
	setcolor(BG_COLOR);
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	char col[3][20] = {"MA SACH", "TRANG THAI", "VI TRI"};
	for (int i=0;i<3;i++) {
		setbkcolor(PANEL);
		outtextxy((XDMS[i] + XDMS[i+1]) / 2 - textwidth(col[i]) / 2, 125 - textheight("ABC") / 2, col[i]);
	}
	
	setcolor(TEXT_COLOR);
	btnBack.draw();
	btnPrevDMS.draw();
	btnNextDMS.draw();
	
	
	setcolor(BG_COLOR);
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	
	int n = DSDS.nodes[currentDauSach]->soLuong;
	totalPageSach = (n + (8 - 1)) / 8;
	
	setbkcolor(BG_COLOR);
	setcolor(TEXT_COLOR);
	
	SachPTR p = GetNodeSachByPosition(DSDS.nodes[currentDauSach]->First, 8 * (currentPageSach-1));
	
	for (int i = 0; p != NULL && i < 8; p = p->next) {
		DrawItemSach(p->sach, i++);
	}
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	char numPag[20];
	sprintf(numPag, "TRANG %d / %d", currentPageSach, totalPageSach);
	outtextxy((w / 2) - textwidth(numPag) / 2, 510, numPag);
}


void DrawNhapSach() {
	// clear subWindows: lam sach khong gian ve bang
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar(XDMS[0] - 5, 580, XDMS[3] + 5, 985);
	
	setfillstyle(USER_FILL, PANEL);
	setbkcolor(PANEL);
	setcolor(TEXT_COLOR);
	setlinestyle(SOLID_LINE, 0, 3);
	bar(XDMS[0], 650, XDMS[3], 700);
	rectangle(XDMS[0], 650, XDMS[3], 900);
	line(XDMS[0], 850, XDMS[3], 850);
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	setcolor(BG_COLOR);
	outtextxy((w/2) - textwidth(NhapSach) / 2, 675 - textheight(NhapSach) / 2, NhapSach);
	
	setbkcolor(BG_COLOR);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setcolor(TEXT_COLOR);
	outtextxy(XDMS[0] + 10, 875 - textheight(ThongBao) / 2, ThongBao);
	
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar(XDMS[0] + 20 + textwidth(ThongBao), 875 - textheight(ThongBao) / 2, (w/2) + 430, 875 + textheight(ThongBao) / 2);
	
	setbkcolor(BG_COLOR);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setcolor(TEXT_COLOR);
	setlinestyle(SOLID_LINE, 0, 3);
	rectangle((w/2) - 250, 930, (w/2) + 250, 980);
	outtextxy((w/2) - textwidth("Click chuot phai: Hieu chinh sach") / 2, 955 - textheight("C") / 2, "Click chuot phai: Hieu chinh sach");
	
	edNhapSoLuongSach.draw();
	btnNhapSoLuongSach.draw();
}

void DrawTrangConDSDS(DS_DauSach &DSDS) {
	if (Window == THEM_DAU_SACH) {
		DrawThemDauSach();
	} else if (Window == DANH_SACH_DAU_SACH) {
		DrawDanhSachDauSach();
		DrawListDSDS(DSDS);
	} else if (Window == DANH_MUC_SACH) {
		DrawListSach(DSDS);
		if (subWindow == THEM_SACH) {
			DrawThemSach(DSDS);
		} else if (subWindow == NHAP_SACH) {
			DrawNhapSach();
		} else if (subWindow == HIEU_CHINH_SACH) {
			DrawHieuChinhSach();
		}
	}
}

// Tuong ung voi ham Draw_Line_DSDS
void DrawItemDauSachHovered(DS_DauSach DSDS, bool current) {
	setfillstyle(SOLID_FILL, current ? LINE : BG_COLOR);
	bar(XDSDS[0], 230 + currentItemDauSach * 40 - 8, XDSDS[6], 230 + (currentItemDauSach + 1) * 40 - 8);
	
	setbkcolor(current ? LINE : BG_COLOR);
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	setcolor(TEXT_COLOR);
	
	if (strlen(edTimDauSach.content) == 0) {
		DrawItemDauSach(DSDS, (currentPageDauSach - 1) * 13 + currentItemDauSach, -1);
	} else {
		DrawItemDauSach(DSDS, listIndexDauSachSearch[(currentPageDauSach - 1) * 13 + currentItemDauSach], currentItemDauSach);
	}
	
	// Ve cac duong vien
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(BORDER_COLOR);
	rectangle(XDSDS[0], 150, XDSDS[6], 750);
	for (int i=0;i<5;i++) {
		setlinestyle(SOLID_LINE, 0, 1);
		line(XDSDS[i+1], 150, XDSDS[i+1], 750);
	}
}

// Tuong ung voi ham Draw_Line_DMS
void DrawItemDMSHovered(DS_DauSach &DSDS, bool current) {
	setfillstyle(SOLID_FILL, current ? LINE : BG_COLOR);
	bar(XDMS[0], 170 + currentItemSach * 40 - 8, XDMS[3], 170 + (currentItemSach + 1) * 40 - 8);
	
	setbkcolor(current ? LINE : BG_COLOR);
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	setcolor(TEXT_COLOR);
	
	DrawItemSach(GetNodeSachByPosition(DSDS.nodes[currentDauSach]->First, 8*(currentPageSach-1) + currentItemSach)->sach , currentItemSach);	
	
	// Ve Cac Duong Vien
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(BORDER_COLOR);
	rectangle(XDMS[0], 100, XDMS[3], 500);
	line(XDMS[1], 150, XDMS[1], 500);
	line(XDMS[2], 150, XDMS[2], 500);
}

// Tuong ung voi ham GetItemDauSachPosition
int GetPositionOfItemDauSach(DS_DauSach &DSDS, int y) {
	// y la tung do cua con chuot
	
	int pos = (y - 230 + 8) / 40; // pos = x tuc la tung do y dang nam o item thu x cua trang hien tai
	int i = 13 * (currentPageDauSach - 1) + pos; // tu item thu pos va so trang ta se tim duoc i la phan tu thu i trong DSDS
	
	if (strlen(edTimDauSach.content) == 0) {
		if (i >= DSDS.n) return -1;
	} else {
		if (i >= sizeListIndexDauSachSearch) return -1;
	}
	
	return pos;
}

// Tuong ung voi ham GetItemSachPosition
int GetPositionOfItemSach(DS_DauSach &DSDS, int y) {
	int pos = (y - 170 + 8) / 40;
	int i = 8 * (currentPageSach - 1) + pos;
	
	if (i >= DSDS.nodes[currentDauSach]->soLuong) return -1;
	else return pos;
}


void ItemEvent(DS_DauSach &DSDS) {
	if (Window == DANH_SACH_DAU_SACH) {
		if ((mx > XDSDS[0] && mx < XDSDS[6] && my > 230 - 8 && my < 230 + 40 * 13 - 8)) { //vi tri hien tai cua chuot nam trong bang DSDS
			int pos = GetPositionOfItemDauSach(DSDS, my);
			if (currentItemDauSach != pos) {
				if (currentItemDauSach != -1) DrawItemDauSachHovered(DSDS, false);
				currentItemDauSach = pos;
				
				if (currentItemDauSach != -1) DrawItemDauSachHovered(DSDS, true);
			}
		} else { // vi tri hien tai cua chuot khong nam trong bang DSDS
			if (currentItemDauSach != -1) {
				DrawItemDauSachHovered(DSDS, false);
				currentItemDauSach = -1;
			}
		}
	} else if (mx > XDMS[0] && mx < XDMS[3] && my > 170 - 8 && my < 170 + 8 * 40 - 8) { // vi tri hien tai cua chuot trong bang cac sach
		int pos = GetPositionOfItemSach(DSDS, my);
		if (currentItemSach != pos) {
			if (currentItemSach != -1) DrawItemDMSHovered(DSDS, false);
			
			currentItemSach = pos;
			
			if (currentItemSach != -1) DrawItemDMSHovered(DSDS, true);
		}
	} else { // vi tri hien tai cua chuot khong nam trong bang cac sach
		if (currentItemSach != -1) {
			DrawItemDMSHovered(DSDS, false);
			currentItemSach = -1;
		}
	}
}


bool CheckDeleteDauSach(DS_DauSach &DSDS, int currentDauSach) {
	return DSDS.nodes[currentDauSach]->soLuotMuon == 0;
}

bool CheckDauSach(DS_DauSach &DSDS, EditText &ISBN, EditText &tenSach, EditText &soTrang, EditText &tacGia, EditText &NXB, EditText &theLoai, bool checkISBN, bool them) {
	if (DSDS.n + 1 > MAXLIST_DAUSACH && them) {
		strcpy(mess, "SO LUONG DAU SACH DAT GIOI HAN (200)");
		return false;
	} else if (IndexOfDauSach(DSDS, ISBN.content) != -1 && checkISBN) {
		strcpy(mess, "ISBN da ton tai, vui long nhap ISBN khac!");
		Edit = &ISBN;
		Edit->draw();
		return false;
	} else if (strlen(ISBN.content) == 0) {
		strcpy(mess, "ISBN khong duoc bo trong");
		Edit = &ISBN;
		Edit->draw();
		return false;
	} else if (strlen(tenSach.content) == 0) {
		strcpy(mess, "Ten sach khong duoc bo trong");
		Edit = &tenSach;
		Edit->draw();
		return false;
	} else if (strlen(soTrang.content) == 0) {
		strcpy(mess, "So trang khong duoc bo trong");
		Edit = &soTrang;
		Edit->draw();
		return false;
	} else if (strlen(tacGia.content) == 0) {
		strcpy(mess, "Tac gia khong duoc bo trong");
		Edit = &tacGia;
		Edit->draw();
		return false;
	} else if (strlen(NXB.content) == 0) {
		strcpy(mess, "NXB khong duoc bo trong");
		Edit = &NXB;
		Edit->draw();
		return false;
	} else if (strlen(theLoai.content) == 0) {
		strcpy(mess, "The loai khong duoc bo trong");
		Edit = &theLoai;
		Edit->draw();
		return false;
	}
	
	//
	int *d = SplitDate(GetSystemDate());
	int year = d[2];
	delete[] d;
	int y = NXB.toInt();
	if (y > year || y < 1800) {
		strcpy(mess, "NXB LON HON NAM HIEN TAI HOAC NHO HON 1800");
		Edit = &NXB;
		Edit->draw();
		return false;
	}
	return true;
}

bool CheckSach(EditText &trangThaiSach, EditText &viTriSach, bool createSach) {
	setcolor(TIPS);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	if (strlen(trangThaiSach.content) == 0 || strlen(viTriSach.content) == 0) {
		outtextxy((w/2) - 410 + textwidth(ThongBao), 955 - textheight(ThongBao) / 2, mess);
		strcpy(mess, "Khong duoc bo trong bat ki truong nao");
		return false;
	} else if (trangThaiSach.toInt() == 1) {
		strcpy(mess, "Trang thai sach ban dau khong the la: DA CHO MUON");
		outtextxy((w/2) - 410 + textwidth(ThongBao), 955 - textheight(ThongBao) / 2, mess);
		return false;
	}
	return true;
}

void DauSachEvent(DS_DauSach &DSDS, TreeDocGia &DSDG) {
	// WINDOW DANH SACH DAU SACH
	char confirm[50];
	if (Window == DANH_SACH_DAU_SACH) {
		ItemEvent(DSDS);
		ButtonEffect(btnAddDauSach);
		ButtonEffect(btnClearTimDauSach);
		ButtonEffect(btnPrev);
		ButtonEffect(btnNext);
		ButtonEffect(btnQuayVe);
		
		if (GetAsyncKeyState(VK_LBUTTON)) {
			if (currentItemDauSach != -1) {
				Window = HIEU_CHINH_DAU_SACH;
				subWindow = CONFIRM_POPUP_NONE;
				if (strlen(edTimDauSach.content) == 0) {
					GetHieuChinhDauSach(DSDS, 13 * (currentPageDauSach - 1) + currentItemDauSach);
				} else {
					GetHieuChinhDauSach(DSDS, listIndexDauSachSearch[13 * (currentPageDauSach -1) + currentItemDauSach]);
				}
			}
			
			if (edTimDauSach.isMouseHover(mx, my)) {
				Edit = &edTimDauSach;
			} else if (btnAddDauSach.isMouseHover(mx, my)) {
				Window = THEM_DAU_SACH;
				DrawTrangConDSDS(DSDS);
			} else if (btnClearTimDauSach.isMouseHover(mx, my)) {
				memset(edTimDauSach.content, 0, sizeof(edTimDauSach.content));
				edTimDauSach.draw();
				DrawListDSDS(DSDS);
			} else if (btnQuayVe.isMouseHover(mx, my)) {
				SetMenuSelect(DSDS, DSDG, 0);
			} else if (btnPrev.isMouseHover(mx, my)) {
				if (currentPageDauSach > 1) {
					--currentPageDauSach;
					ClearScreen(5);
					DrawListDSDS(DSDS);
				}
			} else if (btnNext.isMouseHover(mx, my)) {
				if (currentPageDauSach < totalPageDauSach) {
					++currentPageDauSach;
					ClearScreen(5);
					DrawListDSDS(DSDS);
				}
			}
		} else if (GetAsyncKeyState(VK_RBUTTON)) {
			if (currentItemDauSach != -1) {
				Window = DANH_MUC_SACH;
				subWindow = NHAP_SACH;
				Edit = NULL;
				if (strlen(edTimDauSach.content) == 0) currentDauSach = 13 * (currentPageDauSach - 1) + currentItemDauSach;
				else currentDauSach = listIndexDauSachSearch[13 * (currentPageDauSach - 1) + currentItemDauSach];
				currentPageSach = 1;
				Edit = NULL;
				memset(mess, 0, sizeof(mess));
				ClearScreen(1);
				DrawTrangConDSDS(DSDS);
			}
		}
	}
	// WINDOW THEM DAU SACH
	else if (Window == THEM_DAU_SACH) {
		ButtonEffect(btnBack);
		ButtonEffect(btnThemDauSach);
		ButtonEffect(btnClearThemDauSach);
		if (GetAsyncKeyState(VK_LBUTTON)) {
			if (btnBack.isMouseHover(mx, my)) {
				Window = DANH_SACH_DAU_SACH;
				ClearScreen(2);
				DrawTrangConDSDS(DSDS);
			} else if (btnClearThemDauSach.isMouseHover(mx, my)) {
				ClearScreen(2);
				DrawThemDauSach();
			} else if (edThemISBN.isMouseHover(mx, my)) {
				Edit = &edThemISBN;
			} else if (edThemTenSach.isMouseHover(mx, my)) {
				Edit = &edThemTenSach;
			} else if (edThemSoTrang.isMouseHover(mx, my)) {
				Edit = &edThemSoTrang;
			} else if (edThemTacGia.isMouseHover(mx, my)) {
				Edit = &edThemTacGia;
			} else if (edThemNXB.isMouseHover(mx, my)) {
				Edit = &edThemNXB;
			} else if (edThemTheLoai.isMouseHover(mx, my)) {
				Edit = &edThemTheLoai;
			} else if (btnThemDauSach.isMouseHover(mx, my)) {
				// Check sach truoc khi add
				
				if (CheckDauSach(DSDS, edThemISBN, edThemTenSach, edThemSoTrang, edThemTacGia, edThemNXB, edThemTheLoai, true, true)) {
					DauSach *dauSach = new DauSach(edThemISBN.trim(), edThemTenSach.trim(), edThemSoTrang.toInt(), edThemTacGia.trim(), edThemNXB.toInt(), edThemTheLoai.trim());
					if (InsertOrderDauSach(DSDS, dauSach)) {
						strcpy(mess, "Them dau sach thanh cong!");
						recentEditISBN = edThemISBN.trim();
					} else {
						strcpy(mess, "Them dau sach that bai do day bo nho!");
					}
				}
				
				DrawThemDauSach();
			}
		}
	}
	// WINDOW HIEU CHINH DAU SACH
	else if (Window == HIEU_CHINH_DAU_SACH) {
		ButtonEffect(btnBack);
		if (subWindow == CONFIRM_POPUP_NONE) {
			if(mx >(w/2) - 400 && mx < (w/2) + 400 && my > 210 && my < 700){			
				ButtonEffect(btnHieuChinhDauSach);
				ButtonEffect(btnClearHieuChinhDauSach);	
				ButtonEffect(btnDeleteDauSach);		
			}
			
			if (GetAsyncKeyState(VK_LBUTTON)) {
				if (btnBack.isMouseHover(mx, my)) {
					Edit = NULL;
					Window = DANH_SACH_DAU_SACH;
				    DrawTrangConDSDS(DSDS);
					DrawListDSDS(DSDS);
				} else if (btnDeleteDauSach.isMouseHover(mx, my)) {
					if (CheckDeleteDauSach(DSDS, currentDauSach)) {
						strcpy(confirm, "XAC NHAN XOA DAU SACH?");
						Edit = NULL;
						subWindow = CONFIRM_POPUP;
						PopUp(confirm);
					} else {
						strcpy(mess, "DAU SACH CO SACH \"DANG CHO MUON\"" " => KHONG THE XOA!");
						setcolor(TIPS);
						outtextxy(XDSDS[7] - 10 + textwidth(ThongBao), 675 - textheight(ThongBao) / 2, mess);
					}
				} else if (btnClearHieuChinhDauSach.isMouseHover(mx, my)) {
					ClearScreen(3);
					DrawHieuChinhDauSach();
				} else if (btnHieuChinhDauSach.isMouseHover(mx, my)) {
					// Check truoc khi hieu chinh
					
					if (CheckDauSach(DSDS,edHieuChinhISBN,edHieuChinhTenSach,edHieuChinhSoTrang,edHieuChinhTacGia,edHieuChinhNXB,edHieuChinhTheLoai, false, false)) {
						DauSach *dauSach = new DauSach(edHieuChinhISBN.trim(), edHieuChinhTenSach.trim(), edHieuChinhSoTrang.toInt(), edHieuChinhTacGia.trim(), edHieuChinhNXB.toInt(), edHieuChinhTheLoai.trim());
						
						if (UpdateDauSach(DSDS, dauSach, currentDauSach)) {
							strcpy(mess, "HIEU CHINH DAU SACH THANH CONG!");
							recentEditISBN = edHieuChinhISBN.trim();
						} else {
							strcpy(mess, "HIEU CHINH DAU SACH THAT BAI!");
						}
					}
					DrawHieuChinhDauSach();
				} else if (currentDauSach != -1) {
					if (edHieuChinhISBN.isMouseHover(mx, my)) {
						strcpy(mess, "ISBN khong the chinh sua!");
						setcolor(TIPS);
						outtextxy(XDSDS[7] - 10 + textwidth(ThongBao), 675 - textheight(ThongBao) / 2, mess);
					} else if(edHieuChinhTenSach.isMouseHover(mx, my)) {
						Edit = &edHieuChinhTenSach;
					} else if(edHieuChinhSoTrang.isMouseHover(mx, my)) {
						Edit = &edHieuChinhSoTrang;
					} else if(edHieuChinhTacGia.isMouseHover(mx, my)) {
						Edit = &edHieuChinhTacGia;
					} else if(edHieuChinhNXB.isMouseHover(mx, my)) {
						Edit = &edHieuChinhNXB;
					} else if(edHieuChinhTheLoai.isMouseHover(mx, my)) {
						Edit = &edHieuChinhTheLoai;	
					}
				}
			}
		} else if (subWindow == CONFIRM_POPUP) {
			ButtonEffect(btnYes);
			ButtonEffect(btnNo);
			if (GetAsyncKeyState(VK_LBUTTON)) {
				if (btnYes.isMouseHover(mx, my)) {
					if (DeleteDauSach(DSDS, DSDS.nodes[currentDauSach]->ISBN) == 1) {
						ClearScreen(3);
						memset(edHieuChinhISBN.content, 0, sizeof(edHieuChinhISBN.content));
						strcpy(mess, "Xoa dau sach thanh cong !!");
						setcolor(TIPS);
						outtextxy(XDSDS[7] - 10 + textwidth(ThongBao), 675 - textheight(ThongBao) / 2, mess);
					} else if (DeleteDauSach(DSDS, DSDS.nodes[currentDauSach]->ISBN) == -1) {
						strcpy(mess, "Dau sach khong ton tai!");
						setcolor(TIPS);
						outtextxy(XDSDS[7] - 10 + textwidth(ThongBao), 675 - textheight(ThongBao) / 2, mess);
					}
					
					subWindow = CONFIRM_POPUP_NONE;
					DrawHieuChinhDauSach();
				} else if (btnNo.isMouseHover(mx, my)) {
					subWindow = CONFIRM_POPUP_NONE;
					DrawHieuChinhDauSach();
				}
			}
		}
	} else if (Window == DANH_MUC_SACH) {
		ButtonEffect(btnBack);
		if (GetAsyncKeyState(VK_LBUTTON)) {
			if (btnBack.isMouseHover(mx, my)) {
				SetMenuSelect(DSDS, DSDG, 100);
				Window = DANH_SACH_DAU_SACH;
				subWindow = CONFIRM_POPUP_NONE;
				memset(edNhapSoLuongSach.content, 0, sizeof(edNhapSoLuongSach.content));
				DrawTrangConDSDS(DSDS);
			}
		} else if (GetAsyncKeyState(VK_RBUTTON)) {
			if (currentItemSach != -1) {
				Window = DANH_MUC_SACH;
				subWindow = HIEU_CHINH_SACH;
				currentSach = currentItemSach;
				
				SachPTR nodeSelect = GetNodeSachByPosition(DSDS.nodes[currentDauSach]->First, 8 * (currentPageSach - 1) + currentSach);
				strcpy(edHieuChinhMaSach.content, nodeSelect->sach.MASACH);
				char ch[2];
				itoa(nodeSelect->sach.trangThai, ch, 10);
				strcpy(edHieuChinhTrangThaiSach.content, ch);
				strcpy(edHieuChinhViTriSach.content, nodeSelect->sach.viTri);
				if (nodeSelect->sach.trangThai == 0) {
					canEditTrangThai = true;
				} else {
					canEditTrangThai = false;
				}
				DrawTrangConDSDS(DSDS);
			}
		}
		
		if (subWindow == NHAP_SACH) {
			ItemEvent(DSDS);
			ButtonEffect(btnNhapSoLuongSach);
			ButtonEffect(btnPrevDMS);
			ButtonEffect(btnNextDMS);
			if (GetAsyncKeyState(VK_LBUTTON)) {
				if (btnPrevDMS.isMouseHover(mx, my)) {
					if (currentPageSach > 1) {
						--currentPageSach;
						DrawListSach(DSDS);
					}
				} else if (btnNextDMS.isMouseHover(mx, my)) {
					if (currentPageSach < totalPageSach) {
						currentPageSach++;
						DrawListSach(DSDS);
					}
				} else if (edNhapSoLuongSach.isMouseHover(mx, my)) {
					memset(mess, 0, sizeof(mess));
					Edit = &edNhapSoLuongSach;
				} else if (btnNhapSoLuongSach.isMouseHover(mx, my)) {
					if (strlen(edNhapSoLuongSach.content) != 0) {
						totalNhapSach = edNhapSoLuongSach.toInt();
						currentNhapSach = 1;
						subWindow = THEM_SACH;
						memset(edThemViTriSach.content, 0, sizeof(edThemViTriSach.content));
						DrawTrangConDSDS(DSDS);
					} else {
						strcpy(mess, "Ban chua nhap so luong sach can them");
						setcolor(TIPS);
						settextstyle(BOLD_FONT, HORIZ_DIR, 2);
						outtextxy((w/2) - 350 + textwidth(ThongBao), 875 - textheight(mess) / 2, mess);
					}
				}
			}
		} else if (subWindow == THEM_SACH) {
			ButtonEffect(btnThemSach);
			ButtonEffect(btnBackToNhapSach);
			if (GetAsyncKeyState(VK_LBUTTON)) {
				if (btnBackToNhapSach.isMouseHover(mx, my)) {
					subWindow = NHAP_SACH;
					DrawTrangConDSDS(DSDS);
				} else if (btnThemSach.isMouseHover(mx, my)) {
					// CHECK THEM SACH
					if (CheckSach(edThemTrangThaiSach,edThemViTriSach,true)) {
						Sach sach(edThemMaSach.content, edThemTrangThaiSach.toInt(), edThemViTriSach.content);
						InsertLastNodeSach(DSDS.nodes[currentDauSach]->First, sach);
						DSDS.nodes[currentDauSach]->soLuong++;
						currentNhapSach++;
						strcpy(mess, "Them sach thanh cong!");
						recentEditMASACH = edThemMaSach.content;
						subWindow = THEM_SACH;
						DrawTrangConDSDS(DSDS);
						DrawListSach(DSDS);
						if (currentNhapSach > totalNhapSach) { // them du so luong sach can them thi quay ve trang nhap so luong sach
							subWindow = NHAP_SACH;
							currentNhapSach = -1;
							totalNhapSach = 0;
							DrawTrangConDSDS(DSDS);
						}
					}
					memset(edNhapSoLuongSach.content, 0, sizeof(edNhapSoLuongSach.content));
				} else if (edThemMaSach.isMouseHover(mx, my)) {
					memset(mess, 0, sizeof(mess));	
					strcpy(mess, "Ma sach tu dong (khong the chinh sua)!");
					setcolor(TIPS);
					outtextxy((w/2) - 410 + textwidth(ThongBao), 955 - textheight(ThongBao) / 2, mess);
				} else if (edThemTrangThaiSach.isMouseHover(mx, my)) {
					Edit = &edThemTrangThaiSach;
				} else if (edThemViTriSach.isMouseHover(mx, my)) {
					Edit = &edThemViTriSach;
				}
			} else if(GetAsyncKeyState(VK_RBUTTON)){

			}
		} else if (subWindow == HIEU_CHINH_SACH) {
			ButtonEffect(btnHieuChinhSach);
			ButtonEffect(btnBackToNhapSach);
			if (GetAsyncKeyState(VK_LBUTTON)) {
				if(btnBackToNhapSach.isMouseHover(mx, my)){	
					subWindow = NHAP_SACH;
					DrawTrangConDSDS(DSDS);	
				} else if (btnHieuChinhSach.isMouseHover(mx, my)) {
					// Check hieu chinh sach
					if (CheckSach(edHieuChinhTrangThaiSach, edHieuChinhViTriSach, false)) {
						SachPTR nodeSelect = GetNodeSachByPosition(DSDS.nodes[currentDauSach]->First, 8 * (currentPageSach - 1) + currentSach);
						Sach sach(edHieuChinhMaSach.content, edHieuChinhTrangThaiSach.toInt(), edHieuChinhViTriSach.content);
						if (UpdateNodeSach(nodeSelect, sach)) {
							setfillstyle(SOLID_FILL, BG_COLOR);
							bar((w/2) - 430 + textwidth(ThongBao), 955 - textheight(ThongBao) / 2, (w/2) + 430, 955 + textheight(ThongBao) / 2);			
							strcpy(mess, "Hieu chinh sach thanh cong!");
							recentEditMASACH = edHieuChinhMaSach.content;
							setcolor(TIPS);
							settextstyle(BOLD_FONT, HORIZ_DIR, 2);
							outtextxy((w/2) - 410 + textwidth(ThongBao), 955 - textheight(ThongBao) / 2, mess);
						}
					}
					DrawListSach(DSDS);
				} else if (edThemMaSach.isMouseHover(mx, my)) {
					setfillstyle(SOLID_FILL, BG_COLOR);
					bar((w/2) - 430 + textwidth(ThongBao), 955 - textheight(ThongBao) / 2, (w/2) + 430, 955 + textheight(ThongBao) / 2);				
					strcpy(mess, "Ma sach tu dong (khong the chinh sua)!");
					setcolor(TIPS);
					outtextxy((w/2) - 410 + textwidth(ThongBao), 955 - textheight(ThongBao) / 2, mess);
				} else if (edHieuChinhViTriSach.isMouseHover(mx, my)) {
					Edit = &edHieuChinhViTriSach;
				} else if (edHieuChinhTrangThaiSach.isMouseHover(mx, my) && canEditTrangThai) {
					Edit = &edHieuChinhTrangThaiSach;
				} else if (edHieuChinhTrangThaiSach.isMouseHover(mx, my) && !canEditTrangThai) {
					settextstyle(BOLD_FONT, HORIZ_DIR, 2);	
					setfillstyle(SOLID_FILL, BG_COLOR);
					bar((w/2) - 430 + textwidth(ThongBao), 955 - textheight(ThongBao) / 2, (w/2) + 430, 955 + textheight(ThongBao) / 2);
					strcpy(mess, "Chi duoc phep sua CO THE MUON -> DA THANH LY!!");
					setcolor(TIPS);
					outtextxy((w/2) - 410 + textwidth(ThongBao), 955 - textheight(ThongBao) / 2, mess);
				}
			} else if(GetAsyncKeyState(VK_RBUTTON)){

			}
		}
	}
}
