using namespace std;

#include <graphics.h>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <iostream>
#include <time.h>
#include <string>

#include "define.h"
#include "datetime.h"
#include "queue.h"
#include "cautrucdulieu.h"
#include "view.h"
#include "local.h"
#include "dausachvasach.h"
#include "docgia.h"
#include "muontra.h"

#include "nhapxuat.h"

int main() {
	initwindow(w, h, AppTitle);
	ClearScreen(0);
	DS_DauSach DSDS;
	TreeDocGia DSDG;
	ReadDauSachFromFile(DSDS);
	ReadDocGiaFromFile(root);
	
	int TheDocGiaBSTC[MAX_DOC_GIA];
	TDGTS_PTR tdg = NULL;
	ReadMaTheDocGia(tdg);
//	DrawMenu();
//	DrawDanhSachDauSach();
//	DrawItemDauSach(DSDS, 0, 0);
//	DrawListDSDS(DSDS);
//	DrawThemDauSach();
//	DrawHieuChinhDauSach();

//	DrawListSach(DSDS);
//	DrawNhapSach();
//	DrawItemDMSHovered(DSDS, false);
//	DrawBorderDSDocGia();
//	DrawBorderDSDocGiaQuaHan();

	DrawMenu();
	
	while (true) {
		Event(DSDS, DSDG, tdg);
		if (isExit) break;
		delay(100);
	}

//	Window = DANH_SACH_DOC_GIA;
//	DrawTrangConDSDG(DSDG, tdg, DSDS);
	
//	DrawHieuChinhDauSach();

//	GetHieuChinhDauSach(DSDS, 3);
	
	getch();
	closegraph();
	return 0;
}
