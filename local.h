int w = GetSystemMetrics(SM_CXSCREEN);
int h = GetSystemMetrics(SM_CYSCREEN);

// ---------------------------------------------------------
// Dau sach va danh muc sach

EditText *Edit = NULL;
// hoanh do x cua Dau Sach de ve cot
int XDSDS[8] = {200, 380, 900, 1050, 1400, 1500, w-200, 600}; //phan tu cuoi cung la vi tri cac edit box
// X Danh Muc Sach
int XDMS[4] = {(w/2)-450, (w/2)-250, (w/2)+100, (w/2)+450};

char mess[50] = "ISBN khong duoc bo trong";

//char *TrangThaiSach[3] means "declare TrangThaiSach as and array of 3 pointers to char"
char *TrangThaiSach[3] = {"CHO MUON DUOC", "DA CHO MUON", "DA THANH LY"};
char thongBao[50];

bool check_dau_noi = false;
int count_numbers = 0;

char AppTitle[] = "Phan Mem Quan Ly Thu Vien";
char DauSachTitle[] = "DANH SACH DAU SACH";
char ThemDauSach[] = "THEM DAU SACH";
char ThongBao[] = "THONG BAO:";
char HieuChinhDauSach[] = "HIEU CHINH DAU SACH";
char DanhMucSach[80] = "DANH MUC SACH: ";
char NhapSach[] = "NHAP SACH";
char HieuChinhSach[] = "HIEU CHINH SACH";
char ThemSach[] = "THEM SACH: ";

char *recentEditISBN = "";
char *recentEditMASACH = "";

// 4 nut menu
Button btnQLDauSach(100, w/2-325, 200 + 80, 300, 200, "QUAN LY DAU SACH");
Button btnQLDocGia(101, w/2+25, 200 + 80, 300, 200, "QUAN LY DOC GIA");
Button btnQLSach(102, w/2-325, 200 + 4*80, 300, 200, "MUON TRA SACH");
Button btnThoat(104, w/2+25, 200 + 4*80, 300, 200, "THOAT");


// Danh Muc Sach va Danh Sach DOC GIA
Button btnPrevDMS(207, XDMS[0], 520, 150, 50, "Trang truoc");
Button btnNextDMS(208, XDMS[3]-150, 520, 150, 50, "Trang sau");


// Nhap Sach
EditText edNhapSoLuongSach(1016, XDMS[0]+50, 715, 770, 40, "So luong sach :", "", "Toi da 99");
Button btnNhapSoLuongSach(217, w/2-50, 780, 100, 50, "NHAP");


// Them Sach
EditText edThemMaSach(1014, XDMS[0]+10, 720, 850, 40, "Ma sach :", "", "Tu dong");
EditText edThemTrangThaiSach(1015, XDMS[0]+10, 770, 850, 40, "Trang thai [0,1,2] ", "", "0:Cho muon duoc- 1:Da cho muon- 2:Da thanh ly", TrangThaiSach);
EditText edThemViTriSach(1017, XDMS[0]+10, 820, 850, 40, "Vi tri :", "", "Toi da 18 ki tu");
Button btnThemSach(209, w/2-50, 870, 100, 50, "THEM");


// Hieu Chinh Sach
EditText edHieuChinhMaSach(1014, XDMS[0]+30, 720, 850, 40, "Ma sach:", "", "Auto");
EditText edHieuChinhTrangThaiSach(1015, XDMS[0]+30, 770, 850, 40, "Trang thai [0,1,2]", "", "0:Cho muon duoc- 1:Da cho muon- 2:Da thanh ly", TrangThaiSach);
EditText edHieuChinhViTriSach(1015, XDMS[0]+30, 820, 850, 40, "Vi tri :", "", "Toi da 18 ki tu");
Button btnHieuChinhSach(217, w/2-50, 870, 100, 50, "EDIT");
Button btnBackToNhapSach(210, XDMS[0], 610, 200, 35, "< BACK TO ADD");

// Button Dau Sach
EditText edTimDauSach(1000, XDSDS[1]+50, 70, 650, 50, "Tim dau sach:", "", "Nhap ten sach vao day");
Button btnQuayVe(201, 20, 20, 100, 50, "< MENU");
Button btnPrev(203, XDSDS[0], 770, 150, 50, "Trang truoc");
Button btnNext(204, XDSDS[6]-150, 770, 150, 50, "Trang sau");
Button btnClearTimDauSach(202, XDSDS[3]+50, 70, 100, 50, "Reset");
Button btnAddDauSach(205, XDSDS[4]-180, 70, 170, 50, "Them Dau Sach");

// Them Dau Sach
EditText edThemISBN(1002, XDSDS[7], 310, 700, 40, "ISBN :","","Chu va so, toi da 10 ki tu (bat dau bang chu)");
EditText edThemTenSach(1003, XDSDS[7], 360, 700, 40, "Ten sach :","","Chu va so, toi da 30 ki tu (bat dau bang chu)");
EditText edThemSoTrang(1004, XDSDS[7], 410, 700, 40, "So trang :","","So, toi da 5 ki tu");
EditText edThemTacGia(1005, XDSDS[7], 460, 700, 40, "Tac gia :","","Chu, toi da 30 ki tu");
EditText edThemNXB(1006, XDSDS[7], 510, 700, 40, "Nam xuat ban :","","So (dinh dang: 2023)");
EditText edThemTheLoai(1007, XDSDS[7], 560, 700, 40, "The loai :","","Chu, toi da 15 ki tu");
Button btnThemDauSach(205, w/2 - 150, 610, 150, 30, "THEM");
Button btnClearThemDauSach(250, w/2 + 50, 610, 150, 30, "RESET");
Button btnBack(206, 20, 20, 100, 50, "< BACK");

// Hieu Chinh Dau Sach
EditText edHieuChinhISBN(1008, XDSDS[7], 310, 700, 40, "ISBN :","","Chu va so, toi da 10 ki tu (bat dau bang chu)");
EditText edHieuChinhTenSach(1009, XDSDS[7], 360, 700, 40, "Ten sach :","","Chu va so, toi da 30 ki tu (bat dau bang chu)");
EditText edHieuChinhSoTrang(1010, XDSDS[7], 410, 700, 40, "So trang :","","So, toi da 5 ki tu");
EditText edHieuChinhTacGia(1011, XDSDS[7], 460, 700, 40, "Tac gia :","","Chu, toi da 30 ki tu");
EditText edHieuChinhNXB(1012, XDSDS[7], 510, 700, 40,"Nam xuat ban :","","So (dinh dang: 2023)");
EditText edHieuChinhTheLoai(1013, XDSDS[7], 560, 700, 40, "The loai :","","Chu, toi da 15 ki tu");
Button btnHieuChinhDauSach(251, w/2 - 200, 610, 100, 30, "SAVE");
Button btnClearHieuChinhDauSach(252, w/2-50, 610, 100, 30, "RESET");
Button btnDeleteDauSach(253, w/2 + 100, 610, 100, 30, "DELETE");

// button for PopUp
Button btnYes(254, w/2 -150, 490, 100, 30, "Yes");
Button btnNo(255, w/2 + 50, 490, 100, 30, "No");

// ---------------------------------------------------------

// ----------------------- DOCGIA VA MUONTRA -----------------------

char DocGiaTitle[] = "DANH SACH DOC GIA";
char *PhaiDocGia[2] = {"NAM", "NU"};
char *TTTDocGia[2] = {"KHOA", "HOAT DONG"};
char TTMuonTra[][10] = {"DANG MUON", "DA TRA", "LAM MAT"};
char ThemDocGia[] = "THEM DOC GIA";
char HieuChinhDocGia[] = "HIEU CHINH DOC GIA";
char XoaDocGia[] = "XOA DOC GIA";
char MuonSach[] = "MUON SACH";
char TraSach[] = "TRA SACH";
char TopTen[] = "TOP 10 CUON SACH MUON NHIEU NHAT";
char DSDM[] = "CAC SACH DANG MUON";

// X DANH SACH DOC GIA

int XXXDG[8] = {200, 380, 1100, 1350, 1450, w-200, w-200, 600};
int XXXQH[9] = {200, 350, 750, 900, 1050, 1150, 1300, w-200};


int MUONTRA[] = {150, 200, 300, 750, 850, 1250, 1350, w-300, w-150}; 
// X Muon Tra sach
int XMT[5] = {50, 170, 570, 720, 920};


// Danh sach Doc Gia
Button btnTatCaDocGia(211, w/2 - 100, 80, 100, 50, "TAT CA");
Button btnDocGiaQuaHan(212, w/2 , 80, 100, 50, "QUA HAN");
Button btnSapXepTen(213, XXXDG[1], 80, 100, 50, "TEN");
Button btnSapXepMaThe(214, XXXDG[1]+100, 80, 100, 50, "MA THE");
Button btnThemMaThe(303, XXXDG[5]-150, 80, 150, 50, "THEM DOC GIA");
Button btnQuayVeMenu(305, 20, 20, 100, 50, "< MENU");
Button btnPrevDocGiaQH(215, XDSDS[0], 770, 150, 50, "Trang truoc");
Button btnNextDocGiaQH(216, XDSDS[6]-150, 770, 150, 50, "Trang sau");


// Them Doc Gia
EditText edThemMaTheDocGia(1002, XDSDS[7], 310, 700, 40, "Ma the:","","auto");
EditText edThemHoDocGia(1003, XDSDS[7], 360, 700, 40, "Ho va ten dem:","","Toi da 18 ki tu");
EditText edThemTenDocGia(1004, XDSDS[7], 410, 700, 40, "Ten:","","Toi da 10 ki tu");
EditText edThemPhaiDocGia(1005, XDSDS[7], 460, 700, 40, "Phai [0,1]:","","0: Nam   -   1: Nu", PhaiDocGia);
EditText edThemTrangThaiTheDocGia(1006, XDSDS[7], 510, 700, 40, "Trang thai [0,1]:","1","0: Khoa  -  1: Hoat dong", TTTDocGia);
Button btnClearFormDocGia(304, w/2 + 50, 610, 150, 30, "RESET");
Button btnThemDocGia(205, w/2 - 150, 610, 150, 30, "THEM");

// Hieu Chinh Doc Gia
EditText edHieuChinhMaTheDocGia(1002, XDSDS[7], 310, 700, 40, "Ma the:","","khong cho phep");
EditText edHieuChinhHoDocGia(1003, XDSDS[7], 360, 700, 40, "Ho va ten dem:","","Toi da 18 ki tu");
EditText edHieuChinhTenDocGia(1004, XDSDS[7], 410, 700, 40, "Ten:","","Toi da 10 ki tu");
EditText edHieuChinhPhaiDocGia(1005, XDSDS[7], 460, 700, 40, "Phai [0,1]:","","0: Nam   -   1: Nu", PhaiDocGia);
EditText edHieuChinhTrangThaiTheDocGia(1006, XDSDS[7], 510, 700, 40, "Trang thai [0,1]:","1","0: Khoa  -  1: Hoat dong", TTTDocGia);
Button btnHieuChinhDocGia(205, w/2 - 150, 610, 150, 30, "HIEU CHINH");

// Xoa doc gia
Button btnXacNhanXoaDocGia(220, w/2 - 50, 600, 100, 40, "XOA");

// Muon Tra Sach
Button btnBackToMenu(230, 20, 20, 100, 50, "< MENU");
Button btnMuonSach(231, w/2 - 350 , 70, 150, 50, " MUON SACH");
Button btnTraSach(232, w/2 -160, 70, 150, 50, "TRA SACH");
Button btnTopTen(233, w/2 +30, 70, 150, 50, "TOP 10");
Button btnTraNgay(314, (XMT[0]+XMT[4])/2-150, 800, 300, 50, "=>> Tra Sach Ngay <<=");
Button btnMuonNgay(315, (XMT[0]+XMT[4])/2-150, 800, 300, 50, "=>> Muon Sach Ngay <<=");

// Muon sach
EditText edNhapMaDGMuonSach(1111, 460, 150, 620, 50, "Nhap ma the :", "", "Nhap ma the doc gia vao day");
EditText edNhapMaSachMuonSach(1112, w/2+150, 240, 600, 50, "Nhap ma sach :", "", "Nhap ma sach can muon (VD: TDK-1)");
EditText edNhapNgayMuonSach(1113, w/2+200, 700, 600, 50, "Ngay muon :", "", "01/01/2020");
Button btnTimMaDG(241, 1110, 150, 100, 50, "TIM");
Button btnTimMaSach(242, w-200, 240, 100, 50, "TIM");
Button btnXacNhanMuonSach(243, 1425, 775, 150, 50, "MUON SACH");

// Tra sach
EditText edNhapNgayTraSach(1114, w/2+200, 500, 600, 50, "Ngay tra :", "", "01/01/2020");
Button btnXacNhanTraSach(244, w/2+400, 560, 140, 50, "TRA SACH");
Button btnLamMatSach(300, w/2+550, 560, 140, 50, "MAT SACH?");
Button btnXacNhanLamMatSach(301, w/2+300, 875, 200, 50, "XAC NHAN");
Button btnHuyLamMatSach(302, w-400, 875, 200, 50, "HUY");

bool isExit = false;
bool openFileSuccess = true;
int recentEditDG = 0;

// ---------------------------------------------------------

Window Window;
SubWindow subWindow;
errorOpenfile error;
int currentMenu = 0, currentMenuMuonTra;
int currentItemDauSach = -1, currentItemSach = -1, currentDauSach = -1, currentSach = -1;
int totalNhapSach = 0, currentNhapSach = 0;

// currentItemDauSach tuong ung voi CurrentItem

//VI TRI CHUOT
int mx = -1, my = -1;
bool canEditTrangThai = true;
int totalPageDauSach = 1, currentPageDauSach = 1;
int totalPageSach = 1, currentPageSach = 1;


void PopUp(char* confirm);
void ReadDauSachFromFile(DS_DauSach &DSDS);
void WriteDauSachToFile(DS_DauSach &DSDS);
void ClearScreen(int choice);
void DrawMenu();
void ButtonEffect(Button &btn);
void DauSachEvent(DS_DauSach &DSDS, TreeDocGia &DSDG);
void DrawDanhSachDauSach();
void SetMenuSelect(DS_DauSach &DSDS, TreeDocGia &DSDG,int menuID);
void DrawListDSDS(DS_DauSach &DSDS);
void PopUp(string s);
void Scan(DS_DauSach &DSDS, EditText* &txt, int maxN, ScanType type, int startLimit = 0, int endLimit = 0);

// ----------- CAC BIEN DOCGIA VA MUONTRA ------------------

DocGiaPTR root = NULL;
DocGia* currentDGMT = NULL;
Sach* currentSachMT = NULL;
DauSach* currentDSMT = NULL;
bool sortDocGiaByName = false;
bool canBorrow = false; // DOC GIA CO DANG BI KHOA HAY KHONG DE HIEN THI THANH TIM KIEM MA SACH
bool canMuonTra = false; // DOC GIA CO THE MUON MA SACH X HAY KHONG ?

int sizeofArrayMaTheDocGia;

int totalPageDG = 1, currentPageDG = 1;
int totalPageDGQuaHan = 1, currentPageDGQuaHan = 1;
int currentItemDG = -1, currentDG = -1;
int currentItemMT = -1, currentMT = -1;
int startIndexSach = -1;

bool CheckDocGia(TreeDocGia &DSDG, EditText &MaThe, EditText &Ho, EditText &Ten, EditText &Phai, EditText &TrangThai, bool them);

void DrawDanhSachDocGia(TreeDocGia &DSDG, DS_DauSach &DSDS);
void DrawThemDocGia(TDGTS_PTR tdg, bool genNewID = true);
void DrawMuonSach();
void ItemDocGiaEvent(TreeDocGia &DSDG, DS_DauSach &DSDS);
void DocGiaEvent(DS_DauSach &DSDS, TreeDocGia &DSDG, TDGTS_PTR tdg);
//void MuonTraEvent(DS_DauSach &DSDS, TreeDocGia &DSDG);
void WriteDauSachToFile(DS_DauSach &DSDS);
void WriteDocGiaToFile(DocGiaPTR &root);
void WriteMaTheDocGia(TDGTS_PTR tdg);

void LoadFoundDS(DS_DauSach &DSDS, EditText* &txt, int &n) {
	GetNodesList(DSDS, txt->content, sizeListIndexDauSachSearch);
	currentPageDauSach = 1;
	ClearScreen(5);
	DrawListDSDS(DSDS);
}

void ScanTimDauSach(DS_DauSach &DSDS, EditText* &txt, int &n, int maxN, char c) {
	if (c == BACKSPACE) {
		if (n > 0) {
			txt->content[n--] = ' ';
		} else if (n == 0) { // tu dong load lai danh sach neu da xoa het content trong o tim kiem
			LoadFoundDS(DSDS, txt, n);
		}
	}
	
	if (n < maxN) {
		if (c == SPACE) {
			if (n > 0 && txt->content[n-1] != ' ') { // khi go xong 1 tu thi se load danh sach tim kiem
				LoadFoundDS(DSDS, txt, n);
				txt->content[n++] = ' ';
			}
		} else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			txt->content[n++] = toupper(c);
		}
	}
}

// n la vi tri cua ky tu c trong chuoi ma ta xet (bat dau tu 0 -> strlen(chuoi) - 1)
bool NumberOnly(int n, char c) {
	if (c >= '0' && c <= '9') {
		return ((n == 0 && c != '0') || (n > 0));
	} else return false;
}

// Chi nhan c la chu cai hoac dau cach hoac dau phay neu ok = true;
bool TextOnly(char c, bool ok) {
	char s = (ok ? 44 : 32);
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == ' ') || (c == s));
}

int KiemTraNhapLieu(EditText* &txt, int n, char c) {
	if ((n == 0 && c == ' ') || (n != 0 && c == ' ' && txt->content[n-1] == ' ')) { // truong hop khoang cach o dau hoac co 2 khoang cach ke tiep
		return 0;
	} else if ((n != 0 && txt->content[n-1] == ' ' && c != ' ') || (n == 0 && c != ' ')) { // truong hop phai viet hoa chu cai dau
		return 1;
	} else if (n != 0 && c == ' ' && txt->content[n-1] != ' ') { // truong hop ky tu vua nhap vao la khoang cach
		return -1;
	} else return 3; // chuoi hop le khong can xu ly
}

bool ScanLimit(char c, int start, int end) {
	return (c >= start && c <= end);
}

void Scan(DS_DauSach &DSDS, EditText* &txt, int maxN, ScanType type, int startLimit, int endLimit) {
	if (txt == NULL) return;
	int mx = -1, my = -1, mrx = -1, mry = -1;
	int n = strlen(txt->content);
	
	getmouseclick(WM_LBUTTONDOWN, mx, my);
	clearmouseclick(WM_LBUTTONDOWN);
	getmouseclick(WM_RBUTTONDOWN, mrx, mry);
	clearmouseclick(WM_RBUTTONDOWN);
	
	if ((mx != -1 && my != -1) || (mrx != -1 && mry != -1) && !txt->isMouseHover(mx, my)) {
		txt->content[n] = '\0';
		txt->draw();
		txt = NULL;
		return;
	}
	
	if (kbhit()) {
		char c = getch();
		if (c == BACKSPACE && type != TIM_DAU_SACH) {
			if (n > 0) {
				if (type == TIM_MA_SACH) {
					if (txt->content[n-1] == '-') {
						check_dau_noi = false;
					} else if (txt->content[n-1] >= '0' && txt->content[n-1] <= '9') {
						count_numbers--;
					}
				}
				txt->content[n--] = ' ';
				txt->content[n] = '\0';
			}
		} else if (n < maxN) {
			switch (type) {
				case ONLY_NUMBER:
					if (NumberOnly(n, c)) {
						txt->content[n++] = c;
					}
					break;
					
				case ONLY_TEXT:
					if (TextOnly(c, false) && KiemTraNhapLieu(txt, n, c) == 3) {
						txt->content[n++] = c;
					}
					break;
					
				case TEXT_NUM_ADD_COMMA_UPPERCASE:
					if (TextOnly(c, true) || NumberOnly(n, c)) {
						if (KiemTraNhapLieu(txt, n, c) == 0) {
							txt->content[n++] = '\0';
						} else {
							txt->content[n++] = toupper(c);
						}
					}
					break;
					
				case TEXT_NUMBER:
					if (TextOnly(c, false) || NumberOnly(n, c)) {
						if (KiemTraNhapLieu(txt, n, c) == 0) {
							txt->content[n++] = '\0';
						} else {
							txt->content[n++] = c;
						}
					}
					break;
					
				case SPACE_TEXT:
					if (TextOnly(c, false)) {
						if (KiemTraNhapLieu(txt, n, c) == 0) {
							txt->content[n++] = '\0';
						} else if (KiemTraNhapLieu(txt, n, c) == 1) {
							txt->content[n++] = toupper(c);
						} else {
							txt->content[n++] = tolower(c);
						}
					}
					break;
					
				case SPACE_TEXT_UPPERCASE:
					if (TextOnly(c, false)) {
						if (KiemTraNhapLieu(txt, n, c) == 0) {
							txt->content[n++] = '\0';
						} else {
							txt->content[n++] = toupper(c);
						}
					}
					break;
					
				case SPACE_TEXT_NUM_UPPERCASE:
					if (TextOnly(c, false) || NumberOnly(n, c)) {
						if (KiemTraNhapLieu(txt, n, c) == 0) {
							txt->content[n++] = '\0';
						} else {
							txt->content[n++] = toupper(c);
						}
					}
					break;
					
				case DELETE_SPACE_UPPERCASE:
					if (TextOnly(c, false) || NumberOnly(n, c)) {
						if (KiemTraNhapLieu(txt, n, c) == 0 || KiemTraNhapLieu(txt, n, c) == -1) {
							txt->content[n++] = '\0';
						} else {
							txt->content[n++] = toupper(c);
						}
					}
					break;
					
				case LIMIT_CHARACTER:
					if (ScanLimit(c, startLimit, endLimit)) {
						txt->content[n++] = c;
					}
					break;
					
				case TIM_MA_SACH:
					if (n == 0) {
						if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
							txt->content[n++] = toupper(c);
						}
					} else {
						if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '-') && txt->content[n-1] != '-' && !check_dau_noi) {
							txt->content[n++] = toupper(c);
							if (c == '-') {
								check_dau_noi = true;
							}
						} else if (c >= '0' && c <= '9' && check_dau_noi && count_numbers < 3) {
							count_numbers++;
							txt->content[n++] = c;
						}
					}
					break;
					
				case DATE_ONLY:
					int cnt = 0;
					for (int i=0;i<n;i++) {
						if (txt->content[i] == '/') ++cnt;
					}
					if (c >= '0' && c <= '9') {
						txt->content[n++] = c;
					} else if (c == '/' && cnt < 2 && n > 0 && txt->content[n-1] != '/') {
						txt->content[n++] = c;
					}
					break; 
					
			}
			
			if (type == TIM_DAU_SACH) {
				ScanTimDauSach(DSDS, txt, n, maxN, c);
			}
			
			txt->content[n] = '_';
			txt->draw();
			txt->content[n] = '\0';
		}
	}
}

void MoveToNextDSDS(EditText &ISBN,EditText &TenSach,EditText &SoTrang,EditText &TacGia,EditText &NXB,EditText &TheLoai){
	if(Edit == &ISBN) Edit = &TenSach;
	else if(Edit == &TenSach) Edit = &SoTrang;
	else if(Edit == &SoTrang) Edit = &TacGia;
	else if(Edit == &TacGia) Edit = &NXB;
	else if(Edit == &NXB) Edit = &TheLoai;
	else if(Edit == &TheLoai) Edit = &ISBN;
}

void MoveToPrevDSDS(EditText &ISBN,EditText &TenSach,EditText &SoTrang,EditText &TacGia,EditText &NXB,EditText &TheLoai){
	if(Edit == &ISBN) Edit = &TheLoai;
	else if(Edit == &TenSach) Edit = &ISBN;
	else if(Edit == &SoTrang) Edit = &TenSach;
	else if(Edit == &TacGia) Edit = &SoTrang;
	else if(Edit == &NXB) Edit = &TacGia;
	else if(Edit == &TheLoai) Edit = &NXB;
}

void MoveToNextDSDG(EditText &HoDocGia,EditText &TenDocGia,EditText &PhaiDocGia,EditText &TrangThaiTheDocGia){
	if(Edit == &HoDocGia) Edit = &TenDocGia;
	else if(Edit == &TenDocGia) Edit = &PhaiDocGia;
	else if(Edit == &PhaiDocGia && (!btnDocGiaQuaHan.isChoose)) Edit = &TrangThaiTheDocGia;
	else if(Edit == &PhaiDocGia && (btnDocGiaQuaHan.isChoose)) Edit = &HoDocGia;
	else if(Edit == &TrangThaiTheDocGia) Edit = &HoDocGia;
}

void MoveToPrevDSDG(EditText &HoDocGia,EditText &TenDocGia,EditText &PhaiDocGia,EditText &TrangThaiTheDocGia){
	if(Edit == &HoDocGia && (!btnDocGiaQuaHan.isChoose)) Edit = &TrangThaiTheDocGia;
	else if(Edit == &HoDocGia && (btnDocGiaQuaHan.isChoose)) Edit = &PhaiDocGia;
	else if(Edit == &TenDocGia) Edit = &HoDocGia;
	else if(Edit == &PhaiDocGia) Edit = &TenDocGia;
	else if(Edit == &TrangThaiTheDocGia) Edit = &PhaiDocGia;
}

void KeyBoardEvent(DS_DauSach &DSDS) {
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT)) {
		ClearScreen(4); //
		return;
	}
	
	if (GetAsyncKeyState(VK_DOWN)) {
		delay(200);
		ClearScreen(4);
		if (Edit != NULL) {
			int n = strlen(Edit->content);
			Edit->draw();
			Edit->content[n] = '\0';
			if (Window == THEM_DAU_SACH) {
				MoveToNextDSDS(edThemISBN, edThemTenSach, edThemSoTrang, edThemTacGia, edThemNXB, edThemTheLoai);
			} else if (Window == HIEU_CHINH_DAU_SACH) {
				MoveToNextDSDS(edHieuChinhISBN, edHieuChinhTenSach, edHieuChinhSoTrang, edHieuChinhTacGia, edHieuChinhNXB, edHieuChinhTheLoai);
			} else if (Window == THEM_DOC_GIA) {
				MoveToNextDSDG(edThemHoDocGia, edThemTenDocGia, edThemPhaiDocGia, edThemTrangThaiTheDocGia);
			} else if (Window == HIEU_CHINH_DOC_GIA) {
				MoveToNextDSDG(edHieuChinhHoDocGia, edHieuChinhTenDocGia, edHieuChinhPhaiDocGia, edHieuChinhTrangThaiTheDocGia);
			}
		}
		return;
	} else if (GetAsyncKeyState(VK_UP)) {
		delay(300);
		ClearScreen(4);
		if (Edit != NULL) {
			int n = strlen(Edit->content);
			Edit->draw();
			Edit->content[n] = '\0';
			if (Window == THEM_DAU_SACH) {
				MoveToPrevDSDS(edThemISBN, edThemTenSach, edThemSoTrang, edThemTacGia, edThemNXB, edThemTheLoai);
			} else if (Window == HIEU_CHINH_DAU_SACH) {
				MoveToPrevDSDS(edHieuChinhISBN, edHieuChinhTenSach, edHieuChinhSoTrang, edHieuChinhTacGia, edHieuChinhNXB, edHieuChinhTheLoai);
			} else if (Window == THEM_DOC_GIA) {
				MoveToPrevDSDG(edThemHoDocGia, edThemTenDocGia, edThemPhaiDocGia, edThemTrangThaiTheDocGia);
			} else if (Window == HIEU_CHINH_DOC_GIA) {
				MoveToPrevDSDG(edHieuChinhHoDocGia, edHieuChinhTenDocGia, edHieuChinhPhaiDocGia, edHieuChinhTrangThaiTheDocGia);
			}
		}
		return;
	}
	
	if (Edit != NULL) {
		int n = strlen(Edit->content);
		Edit->content[n] = '_';
		Edit->draw();
		Edit->content[n] = '\0';
		
		if (currentMenu == btnQLDauSach.id) {
			if (Window == DANH_SACH_DAU_SACH && Edit == &edTimDauSach) {
				Scan(DSDS, Edit, 20, TIM_DAU_SACH);
			} else if (Window == THEM_DAU_SACH) {
				if (Edit = &edThemISBN) {
					Scan(DSDS, Edit, 10, DELETE_SPACE_UPPERCASE);
				} else if (Edit == &edThemTenSach) {
					Scan(DSDS, Edit, 30, SPACE_TEXT_NUM_UPPERCASE);
				} else if (Edit == &edThemSoTrang) {
					Scan(DSDS, Edit, 5, ONLY_NUMBER);
				} else if (Edit == &edThemTacGia) {
					Scan(DSDS, Edit, 30, SPACE_TEXT_UPPERCASE);
				} else if (Edit == &edThemNXB) {
					Scan(DSDS, Edit, 4, ONLY_NUMBER);
				} else if (Edit == &edThemTheLoai) {
					Scan(DSDS, Edit, 15, SPACE_TEXT_UPPERCASE);
				}
			} else if (Window == HIEU_CHINH_DAU_SACH) {
				if (Edit == &edHieuChinhISBN) {
					Scan(DSDS, Edit, 10, DELETE_SPACE_UPPERCASE);
				} else if (Edit == &edHieuChinhTenSach) {
					Scan(DSDS, Edit, 30, SPACE_TEXT_NUM_UPPERCASE);
				} else if (Edit == &edHieuChinhSoTrang) {
					Scan(DSDS, Edit, 5, ONLY_NUMBER);
				} else if (Edit == &edHieuChinhTacGia) {
					Scan(DSDS, Edit, 30, SPACE_TEXT_UPPERCASE);
				} else if (Edit == &edHieuChinhNXB) {
					Scan(DSDS, Edit, 4, ONLY_NUMBER);
				} else if (Edit == &edHieuChinhTheLoai) {
					Scan(DSDS, Edit, 15, SPACE_TEXT_UPPERCASE);
				}
			} else if (Window == DANH_MUC_SACH) {
				if (subWindow == NHAP_SACH && Edit == &edNhapSoLuongSach) {
					Scan(DSDS, Edit, 2, ONLY_NUMBER);
				} else if (subWindow == HIEU_CHINH_SACH) {
					if (Edit == &edHieuChinhTrangThaiSach) {
						Scan(DSDS, Edit, 1, LIMIT_CHARACTER, '0', '2');
					} else if (Edit == &edHieuChinhViTriSach) {
						Scan(DSDS, Edit, 20, TEXT_NUM_ADD_COMMA_UPPERCASE);
					}
				} else if (subWindow == THEM_SACH) {
					if (Edit == &edThemTrangThaiSach) {
						Scan(DSDS, Edit, 1, LIMIT_CHARACTER, '0', '2');
					} else if (Edit == &edThemViTriSach) {
						Scan(DSDS, Edit, 20, TEXT_NUM_ADD_COMMA_UPPERCASE);
					}
				}
			}
		} else if (currentMenu == btnQLDocGia.id) {
			if (Window == THEM_DOC_GIA) {
				if (Edit == &edThemHoDocGia) {
					Scan(DSDS, Edit, 18, SPACE_TEXT_UPPERCASE);
				} else if (Edit == &edThemTenDocGia) {
					Scan(DSDS, Edit, 10, DELETE_SPACE_UPPERCASE);
				} else if (Edit == &edThemPhaiDocGia) {
					Scan(DSDS, Edit, 1, LIMIT_CHARACTER, '0', '1');
				} else if (Edit == &edThemTrangThaiTheDocGia) {
					Scan(DSDS, Edit, 1, LIMIT_CHARACTER, '0', '1');
				}
			} else if (Window == HIEU_CHINH_DOC_GIA) {
				if (Edit == &edHieuChinhHoDocGia) {
					Scan(DSDS, Edit, 18, SPACE_TEXT_UPPERCASE);
				} else if (Edit == &edHieuChinhTenDocGia) {
					Scan(DSDS, Edit, 10, DELETE_SPACE_UPPERCASE);
				} else if (Edit == &edHieuChinhPhaiDocGia) {
					Scan(DSDS, Edit, 1, LIMIT_CHARACTER, '0', '1');
				} else if (Edit == &edHieuChinhTrangThaiTheDocGia) {
					Scan(DSDS, Edit, 1, LIMIT_CHARACTER, '0', '1');
				}
			}
		} else if (currentMenu == btnQLSach.id) {
//			if (Edit == &edNhapMaDGMuonSach) {
//				Scan(DSDS, Edit, 5, ONLY_NUMBER);
//			} else if (Edit == &edNhapMaSachMuonSach) {
//				Scan(DSDS, Edit, 15, TIM_MA_SACH);
//			}
		} else {
			ClearScreen(4);
		}
	}
}

void MenuEvent(DS_DauSach &DSDS, TreeDocGia &DSDG, TDGTS_PTR tdg) {
	if (openFileSuccess == false) {
		ButtonEffect(btnYes);
		if (GetAsyncKeyState(VK_LBUTTON)) {
			if (btnYes.isMouseHover(mx, my)) {
				isExit = true;
			}
		}
	} else {
		ButtonEffect(btnQLDauSach);
		ButtonEffect(btnQLDocGia);
		ButtonEffect(btnQLSach);
		ButtonEffect(btnThoat);
		if (GetAsyncKeyState(VK_LBUTTON)) {
			if (btnQLDauSach.isMouseHover(mx, my)) {
				SetMenuSelect(DSDS, DSDG, btnQLDauSach.id);
			} else if (btnQLDocGia.isMouseHover(mx, my)) {
				SetMenuSelect(DSDS, DSDG, btnQLDocGia.id);
			} else if (btnQLSach.isMouseHover(mx, my)) {
				SetMenuSelect(DSDS, DSDG, btnQLSach.id);
			} else if (btnThoat.isMouseHover(mx, my)) {
				WriteDauSachToFile(DSDS);
				WriteDocGiaToFile(root);
				cout << "Saved dau sach + danh muc sach\n";
				WriteMaTheDocGia(tdg);
				cout << "Saved MaTheDocGia\n";
				while (DSDS.n) {
					DeleteAllNodeSach(DSDS.nodes[DSDS.n-1]->First);
					delete DSDS.nodes[--DSDS.n];
				}
				DeleteMemoryDocGia(root);
				cout << "Free memory danh muc sach\n";
				isExit = true;
			}
		}
	}
}


void Event(DS_DauSach &DSDS, TreeDocGia &DSDG, TDGTS_PTR tdg) {
	mx = mousex(); my = mousey();
	KeyBoardEvent(DSDS);
	if (currentMenu == 0) {
		MenuEvent(DSDS, DSDG, tdg);
	} else if (currentMenu == btnQLDauSach.id) {
		DauSachEvent(DSDS, DSDG);
	} else if (currentMenu == btnQLDocGia.id) {
		DocGiaEvent(DSDS, DSDG, tdg);
	} else if (currentMenu == btnQLSach.id) {
		//MuonTraEvent(DSDS, DSDG);
	}
}

void SetMenuSelect(DS_DauSach &DSDS, TreeDocGia &DSDG, int menuID) {
	if (currentMenu != menuID) {
		currentMenu =  menuID;
		ClearScreen(0);
		
		if (menuID == 0) {
			DrawMenu();
		} else if (menuID == btnQLDauSach.id) {
			Window = DANH_SACH_DAU_SACH;
			DrawDanhSachDauSach();
			DrawListDSDS(DSDS);
		} else if (menuID == btnQLDocGia.id) {
			Window = DANH_SACH_DOC_GIA;
			DrawDanhSachDocGia(DSDG, DSDS);
		} else if (menuID == btnQLSach.id) {
			Window = MUON_SACH;
			//DrawMuonSach();
		}
	}
}

void ButtonEffect(Button &btn) {
	if (btn.isChoose) return;
	
	if (btn.isMouseHover(mousex(), mousey())) {
		if (btn.isHover == false) {
			btn.isHover = true;
			btn.draw();
		}
	} else {
		if (btn.isHover == true) {
			btn.isHover = false;
			btn.draw();
		}
	}
}

void PopUp(char *confirm) {
	setfillstyle(USER_FILL, TEXT_COLOR_SELECTED);
	setcolor(BORDER_COLOR);
	bar((w/2) - 300, 380, (w/2) + 300, 550);
	setcolor(BG_COLOR);
	setbkcolor(TEXT_COLOR_SELECTED);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	outtextxy((w/2) - textwidth(confirm) / 2, 415 - textheight(confirm) /2 , confirm);
	btnYes.draw();
	btnNo.draw();
}

void DrawMenu() {
	settextstyle(BOLD_FONT, HORIZ_DIR, 7);
	setcolor(TEXT_COLOR);
	setbkcolor(BG_COLOR);
	outtextxy(w/2 - textwidth(AppTitle)/2, 100, AppTitle);
	setlinestyle(SOLID_LINE, 0, 3);
	rectangle(w/2 - 480, 100, w/2 + 480, 180); // vien quanh tieu de
	rectangle(w/2 - 480, 183, w/2 + 480, 800);
	btnQLDauSach.draw();
	btnQLDocGia.draw();
	btnQLSach.draw();
	btnThoat.draw();
	char confirm[50];
	if (openFileSuccess == false) {
		switch (error) {
			case DAU_SACH:
				{
					strcpy(confirm, "Mo file DAU SACH loi, thoat ung dung?");
					break;
				}
				
			case SACH: 
				{
					strcpy(confirm, "Mo file SACH loi, thoat ung dung?");
					break;	
				}

			case DOC_GIA: 
				{
					strcpy(confirm, "Mo file DOC GIA loi, thoat ung dung?");
					break;				
				}
			case MUON_TRA:
				{
					strcpy(confirm, "Mo file MUON TRA loi, thoat ung dung?");
					break;				
				} 
			case DSDS_FULL:
				{
					strcpy(confirm, "DSDS bi day, co the thieu du lieu, thoat ung dung?");
					break;				
				} 
			default:
				{
					strcpy(confirm, "ok");
				}
		}
		subWindow = CONFIRM_POPUP;
		PopUp(confirm);
	}
}




void ClearScreen(int choice) {
	switch (choice) {
		case 1: // xoa toan man hinh
			setfillstyle(SOLID_FILL, BG_COLOR);
			bar(0, 0, w, h);
			break;
		
		case 2: // Clear Content ThemDauSach
			memset(edThemISBN.content, 0, sizeof(edThemISBN.content));
			memset(edThemTenSach.content, 0, sizeof(edThemTenSach.content));
			memset(edThemSoTrang.content, 0, sizeof(edThemSoTrang.content));
			memset(edThemTacGia.content, 0, sizeof(edThemTacGia.content));
			memset(edThemNXB.content, 0, sizeof(edThemNXB.content));
			memset(edThemTheLoai.content, 0, sizeof(edThemTheLoai.content));
			memset(mess, 0, sizeof(mess));			
			break;
				
		case 3://Clear Content HieuChinhDauSach
			memset(edHieuChinhTenSach.content, 0, sizeof(edHieuChinhTenSach.content));
			memset(edHieuChinhSoTrang.content, 0, sizeof(edHieuChinhSoTrang.content));
			memset(edHieuChinhTacGia.content, 0, sizeof(edHieuChinhTacGia.content));
			memset(edHieuChinhNXB.content, 0, sizeof(edHieuChinhNXB.content));
			memset(edHieuChinhTheLoai.content, 0, sizeof(edHieuChinhTheLoai.content));
			memset(mess, 0, sizeof(mess));			
			break;
		
		case 4: // Khong nhan 2 phim < va >
			while (kbhit()) {
				char c = getch();
			}
			break;
		
		case 5: // Clear Bang List Dau Sach, Doc Gia
			setfillstyle(SOLID_FILL, BG_COLOR);
			bar(XDSDS[0], 230, XDSDS[6], 750);
			break;
		
		case 6: // Clear Content ThemDocGia
//			memset(edThemMaTheDocGia.content, 0, sizeof(edThemMaTheDocGia.content));	
			memset(edThemHoDocGia.content, 0, sizeof(edThemHoDocGia.content));	
			memset(edThemTenDocGia.content, 0, sizeof(edThemTenDocGia.content));	
			memset(edThemPhaiDocGia.content, 0, sizeof(edThemPhaiDocGia.content));	
			memset(edThemTrangThaiTheDocGia.content, 0, sizeof(edThemTrangThaiTheDocGia.content));
			memset(mess, 0, sizeof(mess));
			break;	
		
		case 7: // Clear Content HieuChinhDocGia
			//memset(edHieuChinhMaTheDocGia.content, 0, sizeof(edHieuChinhMaTheDocGia.content));	
			memset(edHieuChinhHoDocGia.content, 0, sizeof(edHieuChinhHoDocGia.content));	
			memset(edHieuChinhTenDocGia.content, 0, sizeof(edHieuChinhTenDocGia.content));	
			memset(edHieuChinhPhaiDocGia.content, 0, sizeof(edHieuChinhPhaiDocGia.content));	
			memset(edHieuChinhTrangThaiTheDocGia.content, 0, sizeof(edHieuChinhTrangThaiTheDocGia.content));
			memset(mess, 0, sizeof(mess));
			break;	
		
		case 8: // Clear Bang List Doc Gia
			setfillstyle(SOLID_FILL, BG_COLOR);
			bar(XXXQH[0] - 5, 150 - 5, w - 20, 820);
			break;
		
		default: // xoa toan man hinh
			setfillstyle(SOLID_FILL, BG_COLOR);
			bar(0, 0, w, h); 
			break;
		}	
}













