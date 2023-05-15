struct SachMT {
	char MASACH[15];
	char tenSach[30];
	char ngayMuon[10];
	int trangThai;
};

struct DSMuonTra{
	int n;
	SachMT *mtr = new SachMT[3];
	
	DSMuonTra() {
		n = 0;
	}
	
	~DSMuonTra() {
		delete[] mtr;
	}
};

DSMuonTra DSMTS;

void DrawTopTen(DS_DauSach &DSDS) {
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	setcolor(TEXT_COLOR);
	outtextxy((w/2) - textwidth(TopTen) / 2- 85, 15, TopTen);
	
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar(150, 180, w, h);
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	char cot[][20] = {"STT", "ISBN", "Ten sach", "So trang", "Tac gia", "NXB", "The loai", "So luot muon"};	
	
	settextstyle(3, HORIZ_DIR, 3);
	setfillstyle(USER_FILL, PANEL);
	setbkcolor(PANEL);
	setcolor(BG_COLOR);
	bar(MUONTRA[0], 250, MUONTRA[8], 320);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(BG_COLOR);
	for(int i=0; i<8; i++) {
		outtextxy((MUONTRA[i+1] + MUONTRA[i]) / 2 - textwidth(cot[i]) / 2, 285 - textheight(cot[i]) / 2, cot[i]);
	}
		
	
	setbkcolor(BG_COLOR);	
	// COT MUON TRA
	setcolor(BORDER_COLOR);
	rectangle(MUONTRA[0], 250, MUONTRA[8], 850);	
	for(int i=0; i < 7; i++){
		setlinestyle(SOLID_LINE, 0, 1);
		line(MUONTRA[i+1], 250, MUONTRA[i+1], 850);
	}	
	TopSach topSach(DSDS);
	char ch[20];
	for(int i=0; i < min(topSach.n, 10); i++){
		//cout<<topSach.list[i].indexDS<<endl;
		itoa(i+1, ch, 10);//STT																
		outtextxy((MUONTRA[0] + MUONTRA[1]) / 2 - textwidth(ch) / 2, 350 + i*50, ch);
		outtextxy(MUONTRA[1] + 10, 350 + i*50, DSDS.nodes[topSach.list[i].indexDS]->ISBN);		
		outtextxy(MUONTRA[2] + 10, 350 + i*50, DSDS.nodes[topSach.list[i].indexDS]->tenSach);
				
		itoa(DSDS.nodes[topSach.list[i].indexDS]->soTrang, ch, 10);		
		outtextxy(MUONTRA[3] + 30, 350 + i*50, ch);		
		outtextxy(MUONTRA[4] + 10, 350 + i*50, DSDS.nodes[topSach.list[i].indexDS]->tacGia);
				
		itoa(DSDS.nodes[topSach.list[i].indexDS]->nxb, ch, 10);			
		outtextxy((MUONTRA[5] + MUONTRA[6]) / 2 - textwidth(ch)/2, 350 + i*50, ch);	
		outtextxy(MUONTRA[6] + 10, 350 + i*50, DSDS.nodes[topSach.list[i].indexDS]->theLoai);
						
		itoa(topSach.list[i].count, ch, 10);							
		outtextxy((MUONTRA[7] + MUONTRA[8]) / 2 - textwidth(ch) / 2, 350 + i*50, ch);
	} 
}

void DrawTraSach() {
	btnTraSach.isHover = true;
	btnTraSach.isChoose = true;
	btnTraSach.draw();
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	setcolor(TEXT_COLOR);
	outtextxy((w/2) - textwidth(DauSachTitle) / 2, 15, TraSach);
	
	memset(edNhapMaDGMuonSach.content, 0, sizeof(edNhapMaDGMuonSach.content));
	edNhapMaDGMuonSach.draw();
	btnTimMaDG.draw();
}

void DrawMuonSach(){
	CurrentMenuMuonTra = -1;
	btnMuonSach.isHover = true;
	btnMuonSach.isChoose = true;
	btnBackToMenu.draw();
	btnMuonSach.draw();
	btnTraSach.draw();
	btnTopTen.draw();
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	setcolor(TEXT_COLOR);
	outtextxy((w/2) - textwidth(DauSachTitle) / 2, 15, MuonSach);
	
	memset(edNhapMaDGMuonSach.content, 0, sizeof(edNhapMaDGMuonSach.content));
	edNhapMaDGMuonSach.draw();
	btnTimMaDG.draw();
}

void DrawTrangConDSMT(DS_DauSach &DSDS){
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar(15, 130, w, h); //clear phan duoi cua trang tu thanh tim kiem
	bar((w/2) - 400, 15, (w/2) + 400, 65); //clear tieu de
	btnMuonSach.isChoose = false;
	btnTraSach.isChoose = false;
	btnTopTen.isChoose = false;	
	if(Window == MUON_SACH){
		btnMuonSach.isChoose = true;
		DrawMuonSach();
	} else if(Window == TRA_SACH){
		btnTraSach.isChoose = true;
		DrawTraSach();
	} else if(Window == TOP_TEN){
		btnTopTen.isChoose = true;
		DrawTopTen(DSDS);
	}
}

// TUONG DUONG VOI HAM GetItemMTPosition
int GetPositionOfMuonTraItem(int y){
	int pos = (y - 625 + 8)/40;
	if(pos >= DSMTS.n) return -1;
	return pos;
}

void DrawBorderDSMT(){
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setcolor(BORDER_COLOR);
	setbkcolor(BG_COLOR);
	char t[4][15] = {"Ma sach", "Ten sach", "Ngay muon", "Trang thai"};
	setfillstyle(SOLID_FILL, BORDER_COLOR);
	rectangle(150, 275, 800, 500); // khung thong tin doc gia
	rectangle(XMT[0], 550, XMT[4], 775);//khung DSMT
	if (Window == MUON_SACH) { //chi ve khung thong bao cho window MUON_SACH
		rectangle(170, 875, 845, 975);
	}
	
	int yline = 600;
	line(XMT[0], yline, XMT[4], yline);
	for(int i=0; i<4; i++){
		line(XMT[i], 550, XMT[i], 775);
		outtextxy((XMT[i] + XMT[i+1]) / 2 - textwidth(t[i]) / 2, (550 + yline) / 2 - textheight(t[i]) / 2, t[i]);
	}
}

void DrawItemMT(int i){
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	setcolor((DSMTS.mt[i].trangThai == 2) ? PANEL: TEXT_COLOR_SELECTED);	
	outtextxy(XMT[0] + 10, 625 + i*40, DSMTS.mtr[i].MASACH);
	outtextxy(XMT[1] + 10, 625 + i*40, DSMTS.mtr[i].tenSach);
	outtextxy(XMT[2] + 10, 625 + i*40, DSMTS.mtr[i].ngayMuon);
	outtextxy(XMT[3] + 10, 625 + i*40, TTMuonTra[DSMTS.mtr[i].trangThai]);
}

// VE CAC SACH DANG HOVERED
void DrawLineSachMuon(bool current){
	setfillstyle(SOLID_FILL, current ? LINE: BG_COLOR);
	bar(XMT[0], 625 + currentItemMT * 40 - 8, XMT[4], 625 + (currentItemMT + 1) * 40 - 8);			
	setbkcolor(current ? LINE : BG_COLOR);
	DrawItemMT(currentItemMT);			
	DrawBorderDSMT();
}

void ItemSachMuonEvent(){
	if (mx > XMT[0] && mx < XMT[4] && my > 625 - 8 && my < 745 - 8) {
		int pos = GetPositionOfMuonTraItem(my);
		if (currentItemMT != -1) {
			DrawLineSachMuon(false);
		}
		
		currentItemMT = pos;
		
		if (currentItemMT != -1) {
			DrawLineSachMuon(true);
		}
	} else {
		if (currentItemMT != -1) {
			DrawLineSachMuon(false);
			currentItemMT = -1;
		}
	}
}

bool isDGQH(DS_DauSach &DSDS, TreeDocgia &DSDG){
    if (currentDGMT->mt.chuaTra > 0) {
    	for (mtPTR p = currentDGMT->mt.First; p != NULL; p = p->next) {
    		if (p->muonTra.trangThai == 0) { // DANG MUON SACH (CHUA TRA)
    			if (DiffTime(GetSystemDate(), p->muonTra.ngayMuon) > 6*24*60*60) { // NHIEU HON 6 NGAY
    				return true;
				}
			}
		}
	}
	return false;
}

void DrawThongTinDocGia(DS_DauSach &DSDS, TreeDocGia &DSDG) {
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar(15, 210, w, h); // clear phan duoi cua trang tu thanh tim kiem
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	if (currentDGMT == NULL) {
		setcolor(TIPS);
		outtextxy((w/2) - 240, 210, "KHONG TIM THAY DOC GIA");
	} else {
		char ch[30];
		setcolor(TEXT_COLOR);
		outtextxy(225, 300, "Doc gia :");
		outtextxy(225, 350, "Ma the :");
		outtextxy(225, 400, "Phai :");
		outtextxy(225, 450, "Trang thai the :");
		
		settextstyle(BOLD_FONT, HORIZ_DIR, 3);
		outtextxy(350, 250, "THONG TIN DOC GIA");
		setcolor(TEXT_COLOR_SELECTED);	
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
		
		sprintf(ch, "%s %s", currentDGMT->ho, currentDGMT->ten);		
		outtextxy(500, 300, ch);
		
		sprintf(ch, "%d", currentDGMT->MATHE);						
		outtextxy(500, 350, ch);	
					
		outtextxy(500, 400, PhaiDocGia[currentDGMT->phai]);
		
		setcolor((CurrentDGMT->trangThai == 0) ? PANEL: TEXT_COLOR_SELECTED);	
		outtextxy(500, 450, TTTDocGia[currentDGMT->trangThai]);	
		
		settextstyle(BOLD_FONT, HORIZ_DIR, 3);		
		setcolor(TEXT_COLOR);		
			
		outtextxy((XMT[0] + XMT[4]) / 2 - textwidth(DSDM) / 2, 522, DSDM);
		setlinestyle(SOLID_LINE,0, 3);		
		DrawBorderDSMT();
		
		(Window == MUON_SACH) ? btnTraNgay.draw() : btnMuonNgay.draw();
		DSMTS.n = 0;
		DauSach *ds;
		
		if (currentDGMT->mt.chuaTra > 0) {
			DSMTS.n = currentDGMT->mt.chuaTra;
			int i = DSMTS.n - 1;
			for (mtPTR p = currentDGMT->mt.First; p != NULL; p = p->next) {
				if (p->muonTra.trangThai != 1) {
					ds = GetDauSachByMaSach(DSDS, p->muonTra.MASACH);
					strcpy(DSMTS.mtr[i].MASACH, p->muonTra.MASACH);
					strcpy(DSMTS.mtr[i].tenSach, ds->tenSach);
					strcpy(DSMTS.mtr[i].ngayMuon, p->muonTra.ngayMuon);
					DSMTS.mtr[i].trangThai = p->muonTra.trangThai;
					DrawItemMT(i--);
				}
			}
		}
		
		if (Window == MUON_SACH) {
			setfillstyle(SOLID_FILL, BG_COLOR);
			bar(205, 880, 845, 970); // khung thong bao
			settextstyle(BOLD_FONT, HORIZ_DIR, 3);
			// the bi khoa
			
			if (isDGQH(DSDS, DSDG)) {
				setcolor(TIPS);
				outtextxy(200, 900, "       DOC GIA DA MUON SACH QUA 7 NGAY ");
				outtextxy(200, 925, "  VUI LONG TRA SACH TRUOC KHI MUON SACH MOI");
				currentDGMT->trangThai = 0;
				return;
			} else if (currentDGMT->trangThai == 0) {
				setcolor(TIPS);
				outtextxy(200, 910, "THE DOC GIA DANG BI KHOA, KHONG THE MUON SACH");
				return;
			} else if (DSMTS.n >= 3) {
				setcolor(TIPS);
				outtextxy(200, 900, "SO LUONG SACH MUON DA DAT GIOI HAN !");
				outtextxy(200, 925, "VUI LONG TRA SACH TRUOC KHI MUON SACH MOI");
				return;
			} else {
				btnTimMaSach.draw();
				edNhapMaSachMuonSach.draw();
				canBorrow = true;
				setcolor(TEXT_COLOR_SELECTED);
				outtextxy(275, 912, "THE DOC GIA CUA BAN CO THE MUON SACH");
			}
			
		} else {
			settextstyle(BOLD_FONT, HORIZ_DIR, 3);
			setcolor(TEXT_COLOR);
			outtextxy(240, 900, "LUU Y: CLICK CHUOT TRAI DE CHON SACH");
		}
	}
	
}

void DrawLamMatSach(){
	setcolor(TEXT_COLOR);
	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	rectangle(1150, 275, 1800, 450); //khung thong tin sach tra		
	outtextxy(1400, 600, "LAM MAT SACH ?");
	rectangle(1150, 625, w-100, 850);
	setcolor(TIPS);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	outtextxy(1175, 650, "Thu vien se khoa the doc gia cua ban");
	outtextxy(1175, 700, "Sach se chuyen qua trang thai: DA THANH LY");
	outtextxy(1175, 750, "Doc gia can den sach moi co the tiep tuc muon sach");
	outtextxy(1175, 800, "Ban co chac chan xac nhan mat sach ?");
	
	btnXacNhanLamMatSach.draw();
	btnHuyLamMatSach.draw();
}

bool CheckDuplicateISBNByMaSach(DS_DauSach &DSDS) {
	DauSach *ds;
	if (currentDGMT->mt.chuaTra > 0) {
		for (mtPTR p = currentDGMT->mt.First; p != NULL; p = p->next) {
			if (p->muonTra.trangThai == 0) { // DANG MUON SACH (CHUA TRA)
				ds = GetDauSachByMaSach(DSDS, p->muonTra.MASACH);
				if (strcmp(ds->ISBN, p->muonTra.MASACH) == 0) {
					return true;
				}
			}
		}
	}
	return false;
}

void DrawThongTinSach(DS_DauSach &DSDS) {
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar(1095, 300, w, h);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	setcolor(TEXT_COLOR);
	
	if (currentSachMT != NULL) {
		setfillstyle(SOLID_FILL, BORDER_COLOR);		
		rectangle(1100, 375, w - 100, 625);
		outtextxy(1375, 350, "THONG TIN SACH");
		outtextxy(1150, 400, "Ma sach :");			
		outtextxy(1150, 450, "Ten sach : ");		
		outtextxy(1150, 500, "Trang thai :");	
		outtextxy(1150, 550, "Vi tri :");
		
		setcolor(TEXT_COLOR_SELECTED);
		outtextxy(1450, 400, currentSachMT->MASACH);
		outtextxy(1450, 450, currentDSMT->tenSach);	
		outtextxy(1450, 500, TrangThaiSach[CurrentSachMT->trangThai]);
		outtextxy(1450, 550, currentSachMT->viTri);
		
		if (CheckDuplicateISBNByMaSach(DSDS)) {
			setcolor(TIPS);
			outtextxy(1130, 600, "THONG BAO: DOC GIA DA MUON SACH THUOC DAU SACH NAY ROI!");
		}
		
		if (currentSachMT->trangThai == 0) {
			setcolor(TEXT_COLOR_SELECTED);
			outtextxy(1250, 600, "=> DOC GIA CO THE MUON CUON SACH NAY!");
			canMuonTra = true;
		} else if (currentSachMT->trangThai == 1) {
			setcolor(TIPS);
			outtextxy(1250, 600, "=> DA CO NGUOI MUON CUON SACH NAY!");
			return;
		} else {
			setcolor(TIPS);
			outtextxy(1250, 600, "=> SACH DA THANH LY, KHONG THE MUON!");
			return;
		}
		edNhapNgayMuonSach.draw();
		btnXacNhanMuonSach.draw();
	} else {
		setcolor(TIPS);
		outtextxy((w/2) + 350, 300, "KHONG TIM THAY SACH!");
	}
	
	settextxy(BOLD_FONT, HORIZ_DIR, 2);
	setcolor(TIPS);
	outtextxy(1175, 840, mess);
}

void DrawThongTinSachTra(int itemMT) {
	if (itemMT != -1) {
		currentMT = itemMT;
		setfillstyle(SOLID_FILL, BG_COLOR);
		bar(250 + (w - 250) / 2 + 5, 240, w, h);
		
		settextstyle(BOLD_FONT, HORIZ_DIR, 3);				
		outtextxy(1375, 250, "THONG TIN SACH");
		
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
		setcolor(TEXT_COLOR);
		rectangle(1150, 275, 1800, 450); //khung thong tin sach tra		
		outtextxy(1250, 300, "Ma sach :");					
		outtextxy(1250, 350, "Ten sach : ");		
		outtextxy(1250, 400, "Ngay muon :");
		
		setcolor(TEXT_COLOR_SELECTED);		
		outtextxy(1500, 300, DSMTS.mtr[currentMT].MASACH);
		outtextxy(1500, 350, DSMTS.mtr[currentMT].tenSach);	
		outtextxy(1500, 400, DSMTS.mtr[currentMT].ngayMuon);
		
		if (subWindow == XAC_NHAN_TRA_SACH) {
			edNhapNgayTraSach.draw();
			btnXacNhanTraSach.draw();
			btnLamMatSach.draw();		
			settextstyle(BOLD_FONT, HORIZ_DIR, 2);
			setcolor(TIPS);
			outtextxy(1200, 650,  mess);
		} else if (subWindow == XAC_NHAN_LAM_MAT_SACH) {
			DrawLamMatSach();
		}
	}
}

void MuonTraEvent(DS_DauSach &DSDS, TreeDocGia &DSDG) {
	char confirm[50];
	ButtonEffect(btnBackToMenu);
	ButtonEffect(btnMuonSach);
	ButtonEffect(btnTraSach);
	ButtonEffect(btnTopTen);
	
	if (GetAsyncKeyState(VK_LBUTTON)) {
		memset(mess, 0, sizeof(mess));
		if (btnBackToMenu.isMouseHover(mx, my)) {
			SetMenuSelect(DSDS, DSDG, 0);
		} else if (btnMuonSach.isMouseHover(mx, my) && Window != MUON_SACH) {
			Window = MUON_SACH;
			DrawTrangConDSMT(DSDS);
			if (currentDGMT != NULL) {
				currentDGMT = &TimDocGiaTheoMa(root, currentDGMT->MATHE)->docGia;
				DrawThongTinDocGia(DSDS, DSDG);
			}
		} else if (btnTraSach.isMouseHover(mx, my) && Window != TRA_SACH) {
			Window = TRA_SACH;
			DrawTrangConDSMT(DSDS);
			if (currentDGMT != NULL) {
				currentDGMT = &TimDocGiaTheoMa(root, currentDGMT->MATHE)->docGia;
				DrawThongTinDocGia(DSDS, DSDG);
			}
		} else if (btnTopTen.isMouseHover(mx, my) && Window != TOP_TEN) {
			Window = TOP_TEN;
			DrawTrangConDSMT(DSDS);
		}  
		
	}
	
	if (Window == MUON_SACH) {
		ButtonEffect(btnTimMaDG);	
		ButtonEffect(btnTraNgay);	
		subWindow = CONFIRM_POPUP_NONE;
		if (GetAsyncKeyState(VK_LBUTTON)) {
			if (edNhapMaDGMuonSach.isMouseHover(mx, my)) {
				Edit = &edNhapMaDGMuonSach;
			} else if (btnTimMaDG.isMouseHover(mx, my)) {
				currentDGMT = &TimDocGiaTheoMa(root, edNhapMaDGMuonSach.toInt())->docGia;
				DrawThongTinDocGia(DSDS, DSDG);
			} else if (btnTraNgay.isMouseHover(mx, my) && currentDGMT != NULL) {
				Window = TRA_SACH;
				DrawTrangConDSMT(DSDS);
				currentDGMT = &TimDocGiaTheoMa(root, currentDGMT->MATHE)->docGia;
				DrawThongTinDocGia(DSDS, DSDG);
			}
		}
		
		if (canBorrow && currentDGMT != NULL) {
			ButtonEffect(btnTimMaSach);
			if (canMuonTra) ButtonEffect(btnXacNhanMuonSach);
			
			if (GetAsyncKeyState(VK_LBUTTON)) {
				if (edNhapMaSachMuonSach.isMouseHover(mx, my)) {
					Edit = &edNhapMaSachMuonSach;
				} else if (btnTimMaSach.isMouseHover(mx, my)) {
					if (strlen(edNhapMaSachMuonSach.content) > 0) {
						// tim dau sach co chua MASACH can tim
						currentDSMT = GetDauSachByMaSach(DSDS, edNhapMaSachMuonSach.content);
						if (currentDSMT == NULL) currentSachMT = NULL;
						else {
							for (SachPTR p = currentDSMT->First; p != NULL; p = p->next) {
								if (strcmp(p->sach.MASACH, edNhapMaSachMuonSach.content) == 0) {
									currentSachMT = &p->sach;
								}
							}
						}
						strcpy(edNhapNgayMuonSach.content, GetSystemDate());
						DrawThongTinSach(DSDS);
					}
				} else if (edNhapMaSachMuonSach.isMouseHover(mx, my)) {
					Edit = &edNhapMaSachMuonSach;
				} else if (currentSachMT != NULL && canMuonTra) {
					if (btnXacNhanMuonSach.isMouseHover(mx, my)) {
						if (!CheckDate(edNhapNgayMuonSach.content)) {
							strcpy(mess, "THONG BAO: DINH DANG KHONG HOP LE (VD: 15/5/2023)");
							DrawThongTinSach(DSDS);
						} else {
							// 0: DANG MUON
							MuonTra muon(currentSachMT->MASACH, edNhapNgayMuonSach.content, "", 0);
							InsertLastMuonTra(currentDGMT->mt, muon);
							SachPTR nodeSach = GetNodeSachByMaSach(currentDSMT->First, currentSachMT->MASACH);
							Sach sach = nodeSach->sach;
							sach.trangThai = 1; // DA CHO MUON
							UpdateNodeSach(nodeSach, sach);
							// Tang so luot muon sach cua DAU SACH
							currentDSMT->soLuotMuon++;
							currentDSMT = NULL;
							currentSachMT = NULL;
							canMuonTra = false;
							DrawThongTinDocGia(DSDS, DSDG);
						}
					}
				}
			}
		}
	} else if (Window == TRA_SACH) {
		ButtonEffect(btnTimMaDG);
		ButtonEffect(btnTraSach);
		ItemSachMuonEvent();
		ButtonEffect(btnMuonNgay);
		if (GetAsyncKeyState(VK_LBUTTON)) {
			if (edNhapMaDGMuonSach.isMouseHover(mx, my)) {
				Edit = &edNhapMaDGMuonSach;
			} else if (btnTimMaDG.isMouseHover(mx, my)) {
				currentDGMT = &TimDocGiaTheoMa(root, edNhapMaDGMuonSach.toInt())->docGia;
				DrawThongTinDocGia(DSDS, DSDG);
			} else if (currentItemMT != -1) {
				subWindow = XAC_NHAN_TRA_SACH;
				strcpy(edNhapNgayTraSach.content, GetSystemDate());
				DrawThongTinSachTra(currentItemMT);
			} else if (btnMuonNgay.isMouseHover(mx, my) && currentDGMT != NULL) {
				Window = MUON_SACH;
				DrawTrangConDSMT(DSDS);
				CurrentDGMT = &TimDocGiaTheoMa(root, currentDGMT->MATHE)->docGia;
				DrawThongTinDocGia(DSDS, DSDG);
			}
		}
		
		if (subWindow == XAC_NHAN_TRA_SACH) {
			ButtonEffect(btnXacNhanTraSach);
			ButtonEffect(btnLamMatSach);
			if (GetAsyncKeyState(VK_LBUTTON)) {
				if (currentMT != -1 && currentDGMT != NULL) {
					if (btnXacNhanTraSach.isMouseHover(mx, my)) {
						if (!CheckDate(edNhapNgayTraSach.content)) {
							strcpy(mess, "THONG BAO: Ngay nhap vao khong hop le");
							DrawThongTinSachTra(currentMT);	
						} else {
							// DA TRA
							MuonTra tra(DSMTS.mtr[currentMT].MASACH, DSMTS.mtr[currentMT].ngayMuon, edNhapNgayTraSach.content, 1);
							Update_MuonTra(currentDGMT->mt, tra);
							currentDSMT = GetDauSachByMaSach(DSDS, DSMTS.mtr[currentMT].MASACH);
							SachPTR nodeSach = GetNodeSachByMaSach(currentDSMT->First, DSMTS.mtr[currentMT].MASACH);
							Sach sach = nodeSach->sach;
							sach.trangThai = 0; // CHO MUON DUOC
							UpdateNodeSach(nodeSach, sach);
							if (!isDGQH(DSDS, DSDG)) {
								currentDGMT->trangThai = 1; // MO KHOA THE DOC GIA
							}
							
							currentDSMT = NULL;
							currentMT = -1;
							memset(edNhapNgayTraSach.content, 0, sizeof(edNhapNgayTraSach.content));
							subWindow = TRANG_NULL;
							DrawThongTinDocGia(DSDS, DSDG);
						}
					} else if (btnLamMatSach.isMouseHover(mx, my)) {
						subWindow = XAC_NHAN_LAM_MAT_SACH;
						DrawThongTinSachTra(currentMT);
					}
				}
			}
		} else if (subWindow == XAC_NHAN_LAM_MAT_SACH) {
			ButtonEffect(btnXacNhanLamMatSach);
			ButtonEffect(btnHuyLamMatSach);
			if (GetAsyncKeyState(VK_LBUTTON)) {
				if (currentMT != -1 && currentDGMT != NULL) {
					if (btnXacNhanLamMatSach.isMouseHover(mx, my)) {
						MuonTra tra(DSMTS.mtr[currentMT].MASACH, DSMTS.mtr[currentMT].ngayMuon, "", 2);
						Update_MuonTra(currentDGMT->mt, tra);
						currentDSMT = GetDauSachByMaSach(DSDs, DSMTS.mtr[currentMT].MASACH);
						SachPTR nodeSach = GetNodeSachByMaSach(currentDSMT->First, DSMTS.mtr[currentMT].MASACH);
						Sach sach = nodeSach->sach;
						sach.trangThai = 2; // DA THANH LY
						UpdateNodeSach(nodeSach, sach);
						currentDSMT = NULL;
						currentMT = -1;
						currentDGMT->trangThai = 0; // KHOA THE DOC GIA
						UpdateDocGia(root, *currentDGMT);
						memset(edNhapNgayTraSach.content, 0, sizeof(edNhapNgayTraSach.content));
						subWindow = TRANG_NULL;
						DrawThongTinDocGia(DSDS, DSDG);
					} else if (btnHuyLamMatSach.isMouseHover(mx, my)) {
						subWindow = XAC_NHAN_TRA_SACH;
						DrawThongTinSachTra(currentMT);
					}
				}
			}
		} else if (subWindow == TRANG_NULL) {
			
		}
		
	}                                 
	
}
