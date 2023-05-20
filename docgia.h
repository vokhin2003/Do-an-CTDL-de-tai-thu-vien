int GetPositionOfItemDocGia(TreeDocGia &DSDG, int y) {
	int pos = (y - 220 + 8) / 40;
	int i;
	if (btnTatCaDocGia.isChoose) {
		i = 13 * (currentPageDG - 1) + pos;
	} else {
		i = 13 * (currentPageDGQuaHan - 1) + pos;
	}
	
	if (i >= DSDG.n) {
		return -1;
	} else {
		return pos;
	}
}

void DrawHieuChinhDocGia() {
	ClearScreen(1);
	
	setfillstyle(USER_FILL, PANEL);
	setbkcolor(PANEL);
	bar((w/2) - 400, 210, (w/2) + 400, 280);
	
	// DINH DANG TIEU DE KHUNG: THEM THE DOC GIA
	setcolor(BORDER_COLOR);
	setlinestyle(SOLID_FILL, 0, 3);
	rectangle((w/2) - 400, 210, (w/2) + 400, 700);
	line((w/2) - 400, 280, (w/2) + 400, 280);
	line((w/2) - 400, 650, (w/2) + 400, 650);
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	setcolor(BG_COLOR);
	outtextxy((w/2) - textwidth(HieuChinhDocGia) / 2, 245 - textheight(HieuChinhDocGia) / 2, HieuChinhDocGia);
	
	setbkcolor(BG_COLOR);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setcolor(TEXT_COLOR);
	outtextxy(XDSDS[7]-30, 675-textheight(ThongBao) / 2, ThongBao);
	
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar((w/2) - 390 + textwidth(ThongBao), 675 - textheight(ThongBao) / 2, (w/2) + 390, 675 + textheight(ThongBao) / 2);
	
	setcolor(TIPS);
	outtextxy(XDSDS[7] - 10 + textwidth(ThongBao), 675 - textheight(ThongBao) / 2, mess);
	
	edHieuChinhMaTheDocGia.draw();
	edHieuChinhHoDocGia.draw();
	edHieuChinhTenDocGia.draw();
	edHieuChinhPhaiDocGia.draw();
	edHieuChinhTrangThaiTheDocGia.draw();
	
	btnHieuChinhDocGia.draw();
	btnClearFormDocGia.draw();
	btnBack.draw();
}

void GetHieuChinhDocGia(TreeDocGia &DSDG, int i) {
	currentDG = i;
	ClearScreen(7); // CLear content HieuChinhDocGia
	
	char s[10];
	itoa(DSDG.nodes[i]->MATHE, s, 10);
	strcpy(edHieuChinhMaTheDocGia.content, s);
	strcpy(edHieuChinhHoDocGia.content, DSDG.nodes[i]->ho);
	strcpy(edHieuChinhTenDocGia.content, DSDG.nodes[i]->ten);
	itoa(DSDG.nodes[i]->phai, s, 10);
	strcpy(edHieuChinhPhaiDocGia.content, s);
	itoa(DSDG.nodes[i]->trangThai, s, 10);
	strcpy(edHieuChinhTrangThaiTheDocGia.content, s);
	// Clear
	DrawHieuChinhDocGia();
}

void DrawBorderDSDocGia(){		
	char ch[6][20] = {"MA THE", "HO", "TEN", "PHAI", "TRANG THAI THE"};
	
	settextstyle(3, HORIZ_DIR, 3);
	setfillstyle(USER_FILL, PANEL);
	setbkcolor(PANEL);
	setcolor(BG_COLOR);
	
	bar(XDSDS[0], 150, w - 200, 215);	
	
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	for(int i=0; i < 5; i++) {
		outtextxy(XXXDG[i] + (XXXDG[i+1] - XXXDG[i]) / 2 - textwidth(ch[i]) / 2, 170, ch[i]);
	}
	
	setbkcolor(BG_COLOR);
	setlinestyle(SOLID_LINE, 0, 2);
	setcolor(BORDER_COLOR);
	rectangle(XXXDG[0], 150, XXXDG[5], 750);
	line(XXXDG[0], 150 + 25 + 2 * 20, XXXDG[5], 150 + 25 + 2 * 20);
	for(int i=0; i < 5; i++) {
		line(XXXDG[i], 150, XXXDG[i], 750);
	}
}

void DrawBorderDSDocGiaQuaHan(){
	char ch[7][20] = {"Ma the", "Ho", "Ten", "Trang thai", "Ngay QH", "Ma sach", "Ten Dau sach"};
	
	settextstyle(3, HORIZ_DIR, 3);
	setfillstyle(USER_FILL, PANEL);
	setbkcolor(PANEL);
	setcolor(BG_COLOR);
	
	bar(XDSDS[0], 150, w-200, 215);		
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	for(int i=0; i < 7; i++) {
		outtextxy(XXXQH[i] + (XXXQH[i+1]-XXXQH[i]) / 2 - textwidth(ch[i]) / 2, 170, ch[i]);
	}

	setbkcolor(BG_COLOR);
	setlinestyle(SOLID_LINE, 0, 2);
	setcolor(BORDER_COLOR);
	rectangle(XXXQH[0], 150, XXXQH[7], 750);
	line(XXXQH[0], 150 + 25 + 2*20, XXXQH[7], 150 + 25 + 2*20);
	for(int i=0; i < 8; i++) {
		line(XXXQH[i], 150, XXXQH[i], 750);
	}
}

void DrawItemDocGia(DocGia &docGia, int i, bool QUAHAN){
	setcolor((recentEditDG == docGia.MATHE) ? TEXT_COLOR_SELECTED : TEXT_COLOR);
	i %= 13;
	char ch[6];
	itoa(docGia.MATHE, ch, 10);
	if (QUAHAN) {
		outtextxy((XXXQH[0] + XXXQH[1]) / 2 - textwidth(ch) / 2, 220 + i*40, ch);
		outtextxy(XXXQH[1] + 10, 220 + i*40, docGia.ho);
		outtextxy(XXXQH[2] + 10, 220 + i*40, docGia.ten);
		outtextxy(XXXQH[3] + 10, 220 + i*40, TTTDocGia[docGia.trangThai]);
	}
	else {
		outtextxy((XXXDG[0] + XXXDG[1]) / 2 - textwidth(ch) / 2, 220 + i*40, ch);
		outtextxy(XXXDG[1] + 10, 220 + i*40, docGia.ho);
		outtextxy(XXXDG[2] + 80, 220 + i*40, docGia.ten);
		outtextxy(XXXDG[3] + 30, 220 + i*40, PhaiDocGia[docGia.phai]);
		outtextxy((XXXDG[4] + XXXDG[5]) / 2 - textwidth(TTTDocGia[docGia.trangThai]) / 2, 220 + i*40, TTTDocGia[docGia.trangThai]);	
	}
}

void DrawItemDocGiaQuaHan(DocGia &docGia, int soNgayQH, int i, DS_DauSach &DSDS){
	DrawItemDocGia(docGia, i, true);
	i %= 13;
	char ch[4];
	sprintf(ch, "%d", soNgayQH);
	outtextxy(XXXQH[4] + 30, 220 + i * 40, ch);
	outtextxy(XXXQH[5] + 20, 220 + i * 40, docGia.mt.First->muonTra.MASACH);
	
	DauSach *searchDSMT = NULL;
	searchDSMT = GetDauSachByMaSach(DSDS, docGia.mt.First->muonTra.MASACH);
	outtextxy(XXXQH[6] + 20, 220 + i * 40, searchDSMT->tenSach);
}


void DrawListDocGia(TreeDocGia &DSDG, bool reload, DS_DauSach&DSDS) {
	char numPag[20];
	
	if (reload && btnTatCaDocGia.isChoose) {
		DSDG.GetAllDocGia(root);
	}
	
	if (btnTatCaDocGia.isChoose) {
		DrawBorderDSDocGia();
		if (sortDocGiaByName) {
			DSDG.SapXepDocGia(MODE_TEN);
		} else {
			DSDG.SapXepDocGia(MODE_MA_THE);
		}
		
		totalPageDG = (DSDG.n + (13 - 1)) / 13;
		
		for (int i = 13 * (currentPageDG - 1); i < 13 * currentPageDG; i++) {
			if (i >= DSDG.n) break;
			DrawItemDocGia(*DSDG.nodes[i], i, false);
		}
		
		// NUM PAGE
		
		sprintf(numPag, "TRANG %d / %d", currentPageDG, totalPageDG);
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
		outtextxy((w/2) - textwidth(numPag) / 2, 785, numPag);
		
		btnPrev.draw();
		btnNext.draw();
		btnThemMaThe.draw();
	} else if (btnDocGiaQuaHan.isChoose) {
		DrawBorderDSDocGiaQuaHan();
		totalPageDGQuaHan = (DSDG.n + (13 - 1)) / 13;
		
		for (int i = 13 * (currentPageDGQuaHan - 1); i < 13 * currentPageDGQuaHan; i++) {
			if (i >= DSDG.n) break;
			DrawItemDocGia(*DSDG.nodes[i], i, true);
			DrawItemDocGiaQuaHan(*DSDG.nodes[i], DSDG.soNgayQuaHan[i], i, DSDS);
		}
		
		// NUM PAGE
		sprintf(numPag, "TRANG %d / %d", currentPageDGQuaHan, totalPageDGQuaHan);
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
		outtextxy((w/2) - textwidth(numPag) / 2, 785, numPag);
		btnPrevDocGiaQH.draw();
		btnNextDocGiaQH.draw();
	}
	
	setcolor(TEXT_COLOR);
	rectangle((w/2) - 250, 850, (w/2) + 250, 950);
	outtextxy((w/2) - 230, 865, "Click chuot trai: Hieu chinh doc gia");
	outtextxy((w/2) - 230, 915, "Click chuot phai: Xoa doc gia");
}

void DrawDanhSachDocGia(TreeDocGia &DSDG, DS_DauSach &DSDS) {
	ClearScreen(1);
	strcpy(mess, " ");
	
	btnSapXepTen.isChoose = sortDocGiaByName;
	btnSapXepMaThe.isChoose = !sortDocGiaByName;
	
	btnSapXepTen.isHover = sortDocGiaByName;
	btnSapXepMaThe.isHover = !sortDocGiaByName;
	
	btnSapXepTen.draw();
	btnSapXepMaThe.draw();
	
	btnTatCaDocGia.isHover = true;
	btnTatCaDocGia.isChoose = true;
	btnDocGiaQuaHan.isHover = false;
	btnDocGiaQuaHan.isHover = false;
	
	btnTatCaDocGia.draw();
	btnDocGiaQuaHan.draw();
	
	
	DrawListDocGia(DSDG, true, DSDS);
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	setcolor(TEXT_COLOR);
	outtextxy((w/2) - textwidth(DocGiaTitle) / 2, 15, DocGiaTitle);
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setcolor(TIPS);
	outtextxy(XXXDG[0], 100, "Sap xep theo: ");
	
	btnQuayVeMenu.draw();
	btnTatCaDocGia.draw();
	btnDocGiaQuaHan.draw();
	btnPrev.draw();
	btnNext.draw();
	btnSapXepTen.draw();
	btnSapXepMaThe.draw();
}

void ButtonSwitchClick(TreeDocGia &DSDG, DS_DauSach &DSDS) {
	if (btnTatCaDocGia.isMouseHover(mx, my)) {
		if (!btnTatCaDocGia.isChoose) {
			ClearScreen(8);
			btnDocGiaQuaHan.isChoose = false;
			btnTatCaDocGia.isChoose = true;
			currentItemDG = -1;
			
			DrawListDocGia(DSDG, false, DSDS);
			DrawDanhSachDocGia(DSDG, DSDS);
			
			btnSapXepTen.isChoose = sortDocGiaByName;
			btnSapXepMaThe.isChoose = !btnSapXepTen.isChoose;
			
			btnSapXepTen.isHover = sortDocGiaByName;
			btnSapXepMaThe.isHover = !sortDocGiaByName;
			btnSapXepTen.draw();
			btnSapXepMaThe.draw();
		}
	} else if (btnDocGiaQuaHan.isMouseHover(mx, my)) {
		if (!btnDocGiaQuaHan.isChoose) {
			ClearScreen(8);
			btnTatCaDocGia.isChoose = false;
			btnDocGiaQuaHan.isChoose = true;
			currentItemDG = -1;
			
			DSDG.GetDocGiaQuaHan(root);
			DrawListDocGia(DSDG, false, DSDS);
		}
	}
	
	if (btnSapXepTen.isMouseHover(mx, my)) {
		if (!sortDocGiaByName) {
			sortDocGiaByName = true;
			ClearScreen(8);
			DrawListDocGia(DSDG, false, DSDS);
		}
	} else if (btnSapXepMaThe.isMouseHover(mx, my)) {
		if (sortDocGiaByName) {
			sortDocGiaByName = false;
			ClearScreen(8);
			DrawListDocGia(DSDG, false, DSDS);
		}
	}
	
	btnSapXepTen.isChoose = sortDocGiaByName;
	btnSapXepMaThe.isChoose = !sortDocGiaByName;
}

// Tuong ung voi ham DrawLineDocGia
void DrawDocGiaHovered(TreeDocGia &DSDG, bool current, DS_DauSach &DSDS) {
	setfillstyle(SOLID_FILL, current ? LINE : BG_COLOR);
	bar(XXXDG[0], 220 + currentItemDG * 40 - 8, XXXDG[btnTatCaDocGia.isChoose ? 5 : 6], 220 + (currentItemDG + 1) * 40 - 8);
	
	setbkcolor(current ? LINE : BG_COLOR);
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	setcolor(TEXT_COLOR);
	
	if (btnTatCaDocGia.isChoose) {
		DrawItemDocGia(*DSDG.nodes[(currentPageDG - 1) * 13 + currentItemDG], (currentPageDG - 1) * 13 + currentItemDG, false);
		DrawBorderDSDocGia();
	} else {
		DrawItemDocGia(*DSDG.nodes[(currentPageDGQuaHan - 1) * 13 + currentItemDG], (currentPageDG - 1) * 13 + currentItemDG, true);
		DrawItemDocGiaQuaHan(*DSDG.nodes[(currentPageDGQuaHan - 1) * 13 + currentItemDG], DSDG.soNgayQuaHan[(currentPageDGQuaHan - 1) * 13 + currentItemDG], (currentPageDGQuaHan - 1) * 13 + currentItemDG, DSDS);
		DrawBorderDSDocGiaQuaHan();
	}
}


void ItemDocGiaEvent(TreeDocGia &DSDG, DS_DauSach &DSDS) {
	if (mx > XXXDG[0] && mx < XXXDG[btnTatCaDocGia.isChoose ? 5 : 6] && my > 220 - 8 && my < 220 + 13 * 40 - 8) {
		int pos = GetPositionOfItemDocGia(DSDG, my);
		if (currentItemDG != pos) {
			
			// VE LAI BACKGROUND TRANG CHO ITEM HIEN TAI
			if (currentItemDG != -1) {
				DrawDocGiaHovered(DSDG, false, DSDS);
			}
			
			currentItemDG = pos;
			
			if (currentItemDG != -1) {
				DrawDocGiaHovered(DSDG, true, DSDS);
			}
		}
	} else {
		// VE LAI BACKGROUND TRANG CHO ITEM HIEN TAI
		if (currentItemDG != -1) {
			DrawDocGiaHovered(DSDG, false, DSDS);
			currentItemDG = -1;
		}
	}
}


void DrawXoaDocGia(TreeDocGia &DSDG, int i) {
	ClearScreen(1);
	setfillstyle(USER_FILL, PANEL);
	setbkcolor(PANEL);
	bar((w/2) - 400, 210, (w/2) + 400, 280);
	
	// DINH DANG TIEU DE KHUNG THEM THE DOC GIA
	setcolor(BORDER_COLOR);
	setlinestyle(SOLID_FILL, 0, 3);
	rectangle((w/2) - 400, 210, (w/2) + 400, 700);
	line((w/2) - 400, 280, (w/2) + 400, 280);
	line((w/2) - 400, 650, (w/2) + 400, 650);
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	setcolor(BG_COLOR);
	outtextxy((w/2) - textwidth(XoaDocGia) / 2, 245 - textheight(XoaDocGia) / 2, XoaDocGia);
	
	setbkcolor(BG_COLOR);
	if (i != -1) {
		settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
		setcolor(TEXT_COLOR);
		currentDG = i;
		char s[50];
		sprintf(s, "%s %s", DSDG.nodes[i]->ho, DSDG.nodes[i]->ten);
		outtextxy(XDSDS[7], 300, "Doc gia :");				outtextxy(XDSDS[7] + 450, 300, s);		
		outtextxy(XDSDS[7], 350, "Ma the :");					itoa(DSDG.nodes[i]->MATHE, s, 10);				outtextxy(XDSDS[7]+450, 350, s);	
		outtextxy(XDSDS[7], 400, "Phai :");					outtextxy(XDSDS[7] + 450, 400, PhaiDocGia[DSDG.nodes[i]->phai]);		
		outtextxy(XDSDS[7], 450, "Trang thai the :");			outtextxy(XDSDS[7] + 450, 450, TTTDocGia[DSDG.nodes[i]->trangThai]);		
		outtextxy(XDSDS[7], 500, "So sach dang muon :");		itoa(DSDG.nodes[i]->mt.chuaTra, s, 10);		outtextxy(XDSDS[7]+450, 500, s);		
		outtextxy(XDSDS[7], 550, "Tong so sach da muon :");	itoa(DSDG.nodes[i]->mt.total, s, 10);			outtextxy(XDSDS[7]+450, 550, s);	
		btnXacNhanXoaDocGia.draw();
	}
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);		setcolor(TEXT_COLOR);		outtextxy(XDSDS[7] - 30, 675 - textheight(ThongBao) / 2, ThongBao);
	setfillstyle(SOLID_FILL, BG_COLOR);			bar((w/2) - 390 + textwidth(ThongBao), 675 - textheight(ThongBao) / 2, (w/2) + 390, 675 + textheight(ThongBao) / 2);
	setcolor(TIPS);								outtextxy(XDSDS[7] - 10 + textwidth(ThongBao), 675 - textheight(ThongBao) / 2, mess);		
	btnBack.draw();
}


void DrawThemDocGia(TDGTS_PTR tdg, bool genNewID) {
	ClearScreen(1);
	setfillstyle(USER_FILL, PANEL);
	setbkcolor(PANEL);
	bar((w/2) - 400, 210, (w/2) + 400, 280);
	
	// dinh dang tieu de khung THEM DOC GIA
	setcolor(BORDER_COLOR);
	setlinestyle(SOLID_FILL, 0, 3);
	rectangle((w/2) - 400, 210, (w/2) + 400, 700);
	line((w/2) - 400, 280, (w/2) + 400, 280);
	line((w/2) - 400, 650, (w/2) + 400, 650);
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	setcolor(BG_COLOR);
	outtextxy((w/2) - textwidth(ThemDocGia) / 2, 245 - textheight(ThemDocGia) / 2, ThemDocGia);
	
	setbkcolor(BG_COLOR);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setcolor(TEXT_COLOR);
	outtextxy(XDSDS[7] - 30, 675 - textheight(ThongBao) / 2, ThongBao);
	
	setfillstyle(SOLID_FILL, BG_COLOR);		
	bar((w/2) - 390 + textwidth(ThongBao), 675 - textheight(ThongBao)/2, (w/2) + 390, 675 + textheight(ThongBao) / 2);
	setcolor(TIPS);							
	outtextxy(XDSDS[7] - 10 + textwidth(ThongBao), 675 - textheight(ThongBao) / 2, mess);
	
	if (genNewID) {
		int id = tdg->next->MaThe;
		itoa(id, edThemMaTheDocGia.content, 10);
	}
	strcpy(edThemTrangThaiTheDocGia.content, "1");
	
	edThemMaTheDocGia.draw();
	edThemHoDocGia.draw();
	edThemTenDocGia.draw();
	edThemPhaiDocGia.draw();
	edThemTrangThaiTheDocGia.draw();
	btnThemDocGia.draw();
	btnClearFormDocGia.draw();
	btnBack.draw();
}


void DrawTrangConDSDG(TreeDocGia &DSDG, TDGTS_PTR tdg, DS_DauSach &DSDS) {
	if (Window == DANH_SACH_DOC_GIA) {
		DrawDanhSachDocGia(DSDG, DSDS);
	} else if (Window == THEM_DOC_GIA) {
		DrawThemDocGia(tdg, true);
	} else if (Window == HIEU_CHINH_DOC_GIA) {
		DrawHieuChinhDocGia();
		if (btnTatCaDocGia.isChoose) {
			GetHieuChinhDocGia(DSDG, 13 * (currentPageDG - 1) + currentItemDG);
		} else {
			GetHieuChinhDocGia(DSDG, 13 * (currentPageDGQuaHan - 1) + currentItemDG);
		}
	} else if (Window == XOA_DOC_GIA) {
		if (btnTatCaDocGia.isChoose) {
			DrawXoaDocGia(DSDG, 13 * (currentPageDG - 1) + currentItemDG);
		} else {
			DrawXoaDocGia(DSDG, 13 * (currentPageDGQuaHan - 1) + currentItemDG);
		}
	}
}

bool CheckDocGia(TreeDocGia &DSDG, EditText &maThe, EditText &ho, EditText &ten, EditText &phai, EditText &trangThai, bool them) {
	if (them && DSDG.n+1 >= MAX_DOC_GIA) {
		strcpy(mess, "SO LUONG DOC GIA DAT GIOI HAN");
		return false;
	}
	
	if (strlen(ho.content) == 0) {
		strcpy(mess, "Ho va ten dem khong duoc bo trong");
		Edit = &edThemHoDocGia;
		Edit->draw();
		return false;
	} else if (strlen(ten.content) == 0) {
		strcpy(mess, "Ten khong duoc bo trong");
		Edit = &edThemTenDocGia;
		Edit->draw();
		return false;
	} else if (strlen(phai.content) == 0) {
		strcpy(mess, "Phai khong duoc bo trong");
		Edit = &edThemPhaiDocGia;
		Edit->draw();
		return false;
	} else if (strlen(trangThai.content) == 0) {
		strcpy(mess, "Trang thai the khong duoc bo trong");
		Edit = &edThemTrangThaiTheDocGia;
		Edit->draw();
		return false;
	}
	return true;
}

void DocGiaEvent(DS_DauSach &DSDS, TreeDocGia &DSDG, TDGTS_PTR tdg) {
	char confirm[50];
	
	
	if (Window == DANH_SACH_DOC_GIA) {
		ButtonEffect(btnQuayVeMenu);
		ButtonEffect(btnTatCaDocGia);
		ButtonEffect(btnDocGiaQuaHan);
		ItemDocGiaEvent(DSDG, DSDS);
		ButtonEffect(btnPrev);
		ButtonEffect(btnNext);
		if (GetAsyncKeyState(VK_LBUTTON)) {
			ButtonSwitchClick(DSDG, DSDS);
			if (btnQuayVeMenu.isMouseHover(mx, my)) {
				SetMenuSelect(DSDS, DSDG, 0);
			}
		}
		if (btnTatCaDocGia.isChoose) {
			ButtonEffect(btnSapXepTen);
			ButtonEffect(btnSapXepMaThe);
			ButtonEffect(btnThemMaThe);
			if (GetAsyncKeyState(VK_LBUTTON)) {
				if (btnThemMaThe.isMouseHover(mx, my)) {
					Window = THEM_DOC_GIA;
					DrawTrangConDSDG(DSDG, tdg, DSDS);
				} else if (currentItemDG != -1) {
					Window = HIEU_CHINH_DOC_GIA;
					DrawTrangConDSDG(DSDG, tdg, DSDS);
				} else if (btnPrev.isMouseHover(mx, my)) {
					if (currentPageDG > 1) {
						ClearScreen(8);
						currentPageDG--;
						DrawListDocGia(DSDG, false, DSDS);
					}
				} else if (btnNext.isMouseHover(mx, my)) {
					if (currentPageDG < totalPageDG) {
						ClearScreen(8);
						currentPageDG++;
						DrawListDocGia(DSDG, false, DSDS);
					}
				}
			} else if (GetAsyncKeyState(VK_RBUTTON)) {
				if (currentItemDG != -1) {
					Window = XOA_DOC_GIA;
					subWindow = CONFIRM_POPUP_NONE;
					DrawTrangConDSDG(DSDG, tdg, DSDS);
				}
			}
		} else if (btnDocGiaQuaHan.isChoose) {
			ButtonEffect(btnPrevDocGiaQH);
			ButtonEffect(btnNextDocGiaQH);
			if (GetAsyncKeyState(VK_LBUTTON)) {
				// Doc Gia Qua Han - MODE
				if (currentItemDG != -1) {
					Window = HIEU_CHINH_DOC_GIA;
					DrawTrangConDSDG(DSDG, tdg, DSDS);
				} else if (btnPrevDocGiaQH.isMouseHover(mx, my)) {
					if (currentPageDGQuaHan > 1) {
						currentPageDGQuaHan--;
						ClearScreen(8);
						DrawListDocGia(DSDG, false, DSDS);
					}
				} else if (btnNextDocGiaQH.isMouseHover(mx, my)) {
					if (currentPageDGQuaHan < totalPageDGQuaHan) {
						currentPageDGQuaHan++;
						ClearScreen(8);
						DrawListDocGia(DSDG, false, DSDS);
					}
				}
			} else if (GetAsyncKeyState(VK_RBUTTON)) {
				if(currentItemDG != -1){
					Window = XOA_DOC_GIA;
					subWindow = CONFIRM_POPUP_NONE;
					DrawTrangConDSDG(DSDG, tdg, DSDS);	
				}
			}
		}
	} else if (Window == THEM_DOC_GIA) {
		ButtonEffect(btnThemDocGia);
		ButtonEffect(btnClearFormDocGia);
		ButtonEffect(btnBack);
		if (GetAsyncKeyState(VK_LBUTTON)) {
			if (btnBack.isMouseHover(mx, my)) {
				ClearScreen(6); // Clear content THEM_DOC_GIA
				Window = DANH_SACH_DOC_GIA;
				DrawTrangConDSDG(DSDG, tdg, DSDS);
			} else if (btnClearFormDocGia.isMouseHover(mx, my)) {
				ClearScreen(6);
				Window = THEM_DOC_GIA;
				DrawTrangConDSDG(DSDG, tdg, DSDS);
			} else if (btnThemDocGia.isMouseHover(mx, my)) {
				if (CheckDocGia(DSDG, edThemMaTheDocGia, edThemHoDocGia, edThemTenDocGia, edThemPhaiDocGia, edThemTrangThaiTheDocGia, true)) {
					DocGia docGia(edThemMaTheDocGia.toInt(), edThemHoDocGia.trim(), edThemTenDocGia.trim(), edThemPhaiDocGia.toInt(), edThemTrangThaiTheDocGia.toInt());
					
					InsertDocGia(root, docGia);
					strcpy(mess, "Them doc gia thanh cong!");
					recentEditDG = edThemMaTheDocGia.toInt();
					if (DeleteFirst_TDGTS(tdg)) {
						cout << "xoa thanh cong khoi dslkv";
						sizeofArrayMaTheDocGia--;
					} else {
						cout << "xoa khong thanh cong khoi dslkv";
					}
					// Xoa Bang Danh Sach Doc Gia 
					ClearScreen(5);
					DrawListDocGia(DSDG, true, DSDS);
					DrawThemDocGia(tdg, false);
				}
			} else if (edThemHoDocGia.isMouseHover(mx, my)) {
				Edit = &edThemHoDocGia;
			} else if (edThemTenDocGia.isMouseHover(mx, my)) {
				Edit = &edThemTenDocGia;
			} else if (edThemPhaiDocGia.isMouseHover(mx, my)) {
				Edit = &edThemPhaiDocGia;
			} else if (edThemTrangThaiTheDocGia.isMouseHover(mx, my)) {
				Edit = &edThemTrangThaiTheDocGia;
			}
		}
	} else if (Window == HIEU_CHINH_DOC_GIA) {
		ButtonEffect(btnHieuChinhDocGia);
		ButtonEffect(btnClearFormDocGia);
		ButtonEffect(btnBack);
		if (GetAsyncKeyState(VK_LBUTTON)) {
			if (btnBack.isMouseHover(mx, my)) {
				ClearScreen(7); // Xoa bang HIEU_CHINH_DOC_GIA
				Window = DANH_SACH_DOC_GIA;
				DrawTrangConDSDG(DSDG, tdg, DSDS);
			} else if (btnClearFormDocGia.isMouseHover(mx, my)) {
				ClearScreen(7);
				Window = HIEU_CHINH_DOC_GIA;
				DrawTrangConDSDG(DSDG, tdg, DSDS);
			} else if (btnHieuChinhDocGia.isMouseHover(mx, my)) {
				if (currentDG != -1 && CheckDocGia(DSDG, edHieuChinhMaTheDocGia, edHieuChinhHoDocGia, edHieuChinhTenDocGia, edHieuChinhPhaiDocGia, edHieuChinhTrangThaiTheDocGia, false)) {
					DocGia docGia(edHieuChinhMaTheDocGia.toInt(), edHieuChinhHoDocGia.trim(), edHieuChinhTenDocGia.trim(), edHieuChinhPhaiDocGia.toInt(), edHieuChinhTrangThaiTheDocGia.toInt());
					UpdateDocGia(root, docGia);
					strcpy(mess, "Hieu chinh doc gia thanh cong!");
					recentEditDG = edHieuChinhMaTheDocGia.toInt();
					ClearScreen(8);
					
					DrawListDocGia(DSDG, true, DSDS);
					currentDG = -1;
				}
				DrawHieuChinhDocGia();
			} else if (currentDG != -1) {
				if (edHieuChinhHoDocGia.isMouseHover(mx, my)) {
					Edit = &edHieuChinhHoDocGia;
				} else if (edHieuChinhTenDocGia.isMouseHover(mx, my)) {
					Edit = &edHieuChinhTenDocGia;
				} else if (edHieuChinhPhaiDocGia.isMouseHover(mx, my)) {
					Edit = &edHieuChinhPhaiDocGia;
				} else if (edHieuChinhTrangThaiTheDocGia.isMouseHover(mx, my) && !btnDocGiaQuaHan.isChoose) {
					Edit = &edHieuChinhTrangThaiTheDocGia;
				} else if (edHieuChinhTrangThaiTheDocGia.isMouseHover(mx, my) && !btnDocGiaQuaHan.isChoose) {
					strcpy(mess, "DOC GIA BI KHOA DO TRA SACH QUA HAN, HAY TRA SACH!");
					bar((w/2) - 390 + textwidth(ThongBao), 675 - textheight(ThongBao) / 2, (w/2) + 390, 675 + textheight(ThongBao) / 2);
					setcolor(TIPS);
					outtextxy(XDSDS[7] - 10 + textwidth(ThongBao), 675 - textheight(ThongBao) / 2, mess);
				}
			}
		}
	} else if (Window == XOA_DOC_GIA) {
		if (subWindow == CONFIRM_POPUP_NONE) {
			ButtonEffect(btnBack);
			if (GetAsyncKeyState(VK_LBUTTON)) {
				if (btnBack.isMouseHover(mx, my)) {
					Window = DANH_SACH_DOC_GIA;
					DrawTrangConDSDG(DSDG, tdg, DSDS);
				} else if (btnXacNhanXoaDocGia.isMouseHover(mx, my) && currentDG != -1) {
					// neu doc gia khong muon sach nao thi co the xoa
					if (DSDG.nodes[currentDG]->mt.total == 0) {
						strcpy(confirm, "XAC NHAN XOA MA THE DOC GIA NAY?");
						Edit = NULL;
						subWindow = CONFIRM_POPUP;
						PopUp(confirm);
					} else {
						// doc gia dang muon sach nen khong the xoa
						strcpy(mess, "DOC GIA DA MUON SACH NEN KHONG THE XOA!");
						DrawXoaDocGia(DSDG, currentDG);
					}
				}
			} else if (currentDG != -1) {
				ButtonEffect(btnXacNhanXoaDocGia);
			}
		} else if (subWindow == CONFIRM_POPUP) {
			ButtonEffect(btnYes);
			ButtonEffect(btnNo);
			if (GetAsyncKeyState(VK_LBUTTON)) {
				if (btnYes.isMouseHover(mx, my)) {
					cout << "\nTruoc khi xoa!" << endl;
					if (RemoveDocGia(root, DSDG.nodes[currentDG]->MATHE)) {
						strcpy(mess, "XOA DOC GIA THANH CONG!");
						cout << "Xoa Hoan Tat !" << endl;
						DrawXoaDocGia(DSDG, currentDG);
						delay(2000);
						currentDG = -1;
						Window = DANH_SACH_DOC_GIA;
						subWindow = CONFIRM_POPUP_NONE;
						DrawTrangConDSDG(DSDG, tdg, DSDS);
					} else {
						strcpy(mess, "XOA DOC GIA KHONG THANH CONG!");
						cout << "Xoa khong duoc !" << endl;
						DrawXoaDocGia(DSDG, currentDG);
					}
					cout << "Thoat khoi if\n";
				} else if (btnNo.isMouseHover(mx, my)) {
					subWindow = CONFIRM_POPUP_NONE;
					DrawXoaDocGia(DSDG, currentDG);
				}
			}
		}
	}
}
