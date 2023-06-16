struct Sach{
	char MASACH[15];
	int trangThai; // 0: cho muon duoc, 1: da co nguoi muon, 2: sach da thanh ly
	char viTri[20];
	
//	bool borrowed;
	
	Sach(){
		
	}
	
	Sach(char ms[20], int tt, char vt[30]) {
		strcpy(MASACH, ms);
		trangThai = tt;
		strcpy(viTri, vt);
//		borrowed = false;
	}

};

struct NodeSach{
	Sach sach;
	NodeSach *next;
};

typedef NodeSach *SachPTR;

int GetSTTOfMaSach(char *s) {
	int res = 0;
	int i = 0;
	for (i=0;i<strlen(s);i++) {
		if (s[i] == '-') break;
	}
	++i;
	for (int pos = i; pos < strlen(s);pos++) {
		res = res * 10 + s[pos] - '0';
	}
	return res;
}

SachPTR makeNodeSach(Sach x) {
	SachPTR newNode = new NodeSach();
	newNode->sach = x;
	newNode->next = NULL;
	return newNode;
}

void InsertFirstNodeSach(SachPTR &First, Sach x) {
	SachPTR newNode = makeNodeSach(x);
	newNode->next = First;
	First = newNode;
}

void DeleteAllNodeSach(SachPTR &First) {
	SachPTR tmp;
	while (First != NULL) {
		tmp = First;
		First = First->next;
		delete tmp;
	}
}

// Them sau node x
bool InsertAfterNodeSach(SachPTR &x, Sach sach) {
	if (x == NULL) {
		return false;
	} else {
		SachPTR newNode = makeNodeSach(sach);
		newNode->next = x->next;
		x->next = newNode;
		return true;
	}
}

void InsertOrderNodeSach(SachPTR &First, Sach x) {
	SachPTR newNode = makeNodeSach(x);
	if (First == NULL) {
		First = newNode;
	} else {
		SachPTR prev = NULL;
		SachPTR curr = First;
		
		int newSTT = GetSTTOfMaSach(x.MASACH);
		
		while (curr != NULL && GetSTTOfMaSach(curr->sach.MASACH) < newSTT) {
			prev = curr;
			curr = curr->next;
		}
		
		if (prev == NULL) {
			newNode->next = First;
			First = newNode;
		} else {
			newNode->next = prev->next;
			prev->next = newNode;
		}
	}
}

// Them sach x vao cuoi NodeSach
void InsertLastNodeSach(SachPTR &First, Sach x) {
	if (First == NULL) {
		InsertFirstNodeSach(First, x);
	} else {
		SachPTR last;
		for (last = First; last->next != NULL; last = last->next);
		InsertAfterNodeSach(last, x);
	}
}

bool UpdateNodeSach(SachPTR &node, Sach &sach) {
	if (node == NULL) return false;
	node->sach = sach;
	return true;
}

// Tim trong 1 cuon sach trong First co MASACH tuong ung, tra ve NodeSach tim duoc
SachPTR GetNodeSachByMaSach(SachPTR First, char *MASACH) {
	SachPTR p ;
	for (p = First; p != NULL; p = p->next) {
		if (strcmp(p->sach.MASACH, MASACH) == 0) return p;
	}
	return NULL;
}

// Ham tra ve Sach thu pos trong NodeSach
SachPTR GetNodeSachByPosition(SachPTR First, int pos) {
	SachPTR p = First;
	for (int i = 0; p != NULL && i < pos; p = p->next, i++);
	return p;
}

void DeleteNodeSachByMaSach(SachPTR &First, char *maSach) {
	if (First == NULL) return;
	SachPTR p = First;
	SachPTR prev = NULL;
	
	while (p != NULL) {
		if (strcmp(p->sach.MASACH, maSach) == 0) {
			
			if (prev == NULL) { // TRUONG HOP PHAN TU DAU TIEN
				First = p->next;
			} else {
				prev->next = p->next;
			}
			
			delete p;
			p = NULL;
			break;
		}
		
		prev = p;
		p = p->next;
	}
	

}



// DAUSACH ------------------

int sizeListIndexDauSachSearch = 0;
int listIndexDauSachSearch[MAXLIST_DAUSACH];

struct DauSach{
	char ISBN[11];
	char tenSach[31];
	int soTrang;
	char tacGia[31];
	int nxb;
	char theLoai[16];
	SachPTR First = NULL;
	
	// cac thuoc tinh them
	int soLuotMuon, soLuong; 
//	int last; // STT CUOI CUNG CUA MA SACH TRONG DAU SACH
	bool deleted;
	
	DauSach(){
	}
	
	DauSach(char *isbn, char *ten, int st, char *tg, int xb, char *tl) {
		strcpy(ISBN, isbn);//kich thuoc chuoi duoc sao chep phai lon hon ky tu co trong chuoi sao chep, neu khong se bi tran bo nho, du van nhap xuat duoc
		strcpy(tenSach, ten);
		soTrang = st;
		strcpy(tacGia, tg);
		nxb = xb;
		strcpy(theLoai, tl);
		First = NULL;		
		soLuong = 0; //so luong sach moi dau sach
		soLuotMuon = 0;
//		last = -1;
		deleted = false;
	}
};

struct DS_DauSach{
	int n;
	DauSach *nodes[MAXLIST_DAUSACH];
	
	DS_DauSach(){
		n = 0;
	}
};

bool InsertLastDauSach(DS_DauSach &DSDS, DauSach *x) {
	if (DSDS.n < MAXLIST_DAUSACH) {
		DSDS.nodes[DSDS.n++] = x;
		return true;
	}
	return false;
}

// Ham tra ve chi so cua 1 dau sach trong DSDS theo ISBN
int IndexOfDauSach(DS_DauSach &DSDS, char *ISBN) {
	for (int i=0;i<DSDS.n;i++) {
		if (strcmp(ISBN, DSDS.nodes[i]->ISBN) == 0) return i;
	}
	return -1;
}

bool IsInclude(const char* input, const char* tenSach) {
	string target = tenSach, s = input;
	int idx = target.find(s);
	if (idx == string::npos) return false;
	string input_space = s + " ";
	string space_input_space = " " + s + " ";
	string target_space = target + " ";
	if ((idx == 0 && target.find(input_space) != string::npos) || (idx != 0 && target_space.find(space_input_space) != string::npos)) {
		return true;
	}
	return false;
}


// Loc danh sach cac Dau Sach co chua string "strFind", Luu vi tri cua cac Dau Sach vao 1 mang: listIndexDauSachSearch
void GetNodesList(DS_DauSach &DSDS, const char *strFind, int &arraySize) {
	arraySize = 0;
	for (int i=0;i<DSDS.n;i++) {
		if (IsInclude(strFind, DSDS.nodes[i]->tenSach)) {
			listIndexDauSachSearch[arraySize++] = i;
		}
	}
}

// Them DauSach vao vi tri pos trong DSDS
void InsertDauSach(DS_DauSach &DSDS, DauSach* dauSach, int pos) {
	if (pos < 0 || pos > DSDS.n) return;
	for (int i = DSDS.n; i > pos; i--) {
		DSDS.nodes[i] = DSDS.nodes[i - 1];
	}
	DSDS.nodes[pos] = dauSach;
	DSDS.n++;
}

// Insert DauSach vao DSDS theo theLoai tang dan, neu theLoai trung thi theo tenSach tang dan
bool InsertOrderDauSach(DS_DauSach &DSDS, DauSach* dauSach) {
	if (DSDS.n >= MAXLIST_DAUSACH) return false;
	int i;
	for (i=0;i<DSDS.n;i++) {
		if (strcmp(dauSach->theLoai, DSDS.nodes[i]->theLoai) < 0) {
			break;
		} else if (strcmp(dauSach->theLoai, DSDS.nodes[i]->theLoai) == 0) {
			if (strcmp(dauSach->tenSach, DSDS.nodes[i]->tenSach) <= 0) {
				break;
			}
		}
	}
	InsertDauSach(DSDS, dauSach, i);
	return true;
}


// Cap nhat DauSach tai vi tri i, noi dung la dauSach
bool UpdateDauSach(DS_DauSach &DSDS, DauSach* dauSach, int i) {
	if (i < 0 || i >= DSDS.n) return false;
	
	dauSach->First = DSDS.nodes[i]->First;
	dauSach->soLuong = DSDS.nodes[i]->soLuong;
	dauSach->soLuotMuon = DSDS.nodes[i]->soLuotMuon;
	
	delete DSDS.nodes[i];
	
	for (int j=i;j<DSDS.n-1;j++) {
		DSDS.nodes[j] = DSDS.nodes[j + 1];
	}
	DSDS.n--;
	InsertOrderDauSach(DSDS, dauSach);
	return true;
}

// Xoa DauSach theo ISBN
int DeleteDauSach(DS_DauSach &DSDS, char *ISBN) {
	int i = IndexOfDauSach(DSDS, ISBN);
	if (i == -1) return -1;
	else {
		delete DSDS.nodes[i];
		
		for (int j=i;j<DSDS.n-1;j++) {
			DSDS.nodes[j] = DSDS.nodes[j+1];
		}
		
		DSDS.n--;
		return 1;
	}
}

DauSach* GetDauSachByMaSach(DS_DauSach &DSDS, char *MASACH) {
	SachPTR p;
	int pos;
	int n = strlen(MASACH);
	for (int i=0;i<n;i++) {
		if (MASACH[i] == '-') {
			pos = i;
			break;
		}
	}
	
	char isbn[pos + 1];
	int stt = 0;
	
	for (int i=0;i<pos;i++) {
		isbn[i] = MASACH[i];
	}
	isbn[pos] = '\0';
	
	for (int i=pos+1;i<n;i++) {
		stt = stt * 10 + (MASACH[i] - '0');
	}
	
	for (int i=0;i<DSDS.n;i++) {
		if (strcmp(DSDS.nodes[i]->ISBN, isbn) == 0) {
//			if (stt < DSDS.nodes[i]->soLuong) return DSDS.nodes[i];
			return DSDS.nodes[i];
		}
	}
	return NULL;
}

// -----------------------------------
// MUON TRA
// -----------------------------------

struct MuonTra{
	char MASACH[15];
	char ngayMuon[11];
	char ngayTra[11];
	int trangThai; // 0: Dang muon, 1: Da tra, 2: Lam mat
	
	MuonTra(){
	}
	
	MuonTra(char *ms, char *nm, char* nt, int tt) {
		strcpy(MASACH, ms);
		strcpy(ngayMuon, nm);
		strcpy(ngayTra, nt);
		trangThai = tt;
	}
	
};

struct NodeMuonTra{
	MuonTra muonTra;
	NodeMuonTra *prev;
	NodeMuonTra *next;
};

typedef NodeMuonTra* mtPTR;

struct DS_MuonTra{
	mtPTR First = NULL; 
	mtPTR Last;
	
	// thuoc tinh them
	int total;		// tong so luong sach da muon
	int chuaTra;	// so luong sach dang muon || lam mat
	
	DS_MuonTra() {
		First = NULL;
		Last = NULL;
		total = 0;
		chuaTra = 0;
	}
	
	
};

mtPTR makeNodeMuonTra(MuonTra x) {
	mtPTR newNode = new NodeMuonTra();
	newNode->muonTra = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void InsertFirstMuonTra(DS_MuonTra &DSMT, MuonTra &x) {
	mtPTR newNode = makeNodeMuonTra(x);
	newNode->next = DSMT.First;
	if (DSMT.First != NULL) {
		DSMT.First->prev = newNode;
	}
	DSMT.First = newNode;
	DSMT.total++;
	if (x.trangThai != 1) {
		DSMT.chuaTra++;
	}
	if (DSMT.Last == NULL) {
		DSMT.Last = newNode;
	}
}


void InsertLastMuonTra(DS_MuonTra &DSMT, MuonTra x) {
	mtPTR newNode = makeNodeMuonTra(x);
	if (DSMT.First == NULL) {
		DSMT.First = newNode;
	} else {
		newNode->prev = DSMT.Last;
		DSMT.Last->next = newNode;
	}
	DSMT.Last = newNode;
	DSMT.total++;
	if (x.trangThai != 1) {
		DSMT.chuaTra++;
	}
}

void DeleteAllMuonTra(DS_MuonTra &DSMT) {
	mtPTR tmp;
	while (DSMT.First != NULL) {
		tmp = DSMT.First;
		DSMT.First = DSMT.First->next;
		delete tmp;
	}
	DSMT.Last = NULL;
	DSMT.total = 0;
	DSMT.chuaTra = 0;
}

// Tra sach + lam mat sach
void Update_MuonTra(DS_MuonTra &DSMT, MuonTra &mt){
	for(mtPTR node = DSMT.First; node != NULL; node = node->next){
		if(strcmp(node->muonTra.MASACH, mt.MASACH) == 0 && strlen(node->muonTra.ngayTra) == 0){
			node->muonTra = mt;
			if(mt.trangThai == 1) 
				DSMT.chuaTra--;
			return;
		}
	}	
}

// -----------------------------------
// DOC GIA
// -----------------------------------

struct DocGia{
	int MATHE;
	char ho[20];
	char ten[11];
	int phai; // 0: Nam, 1: Nu
	int trangThai; // 0: Khoa, 1: Hoat dong
	
	DS_MuonTra mt;
	
	DocGia(){
		
	}
	
	DocGia(int mt, char h[20], char t[11], int p, int tt) {
		MATHE = mt;
		strcpy(ho, h);
		strcpy(ten, t);
		phai = p;
		trangThai = tt;
	}
};

struct NodeDocGia{
	DocGia docGia;
	NodeDocGia *left;
	NodeDocGia *right;
	int balanceFactor;
};

typedef NodeDocGia *DocGiaPTR;

struct TreeDocGia{
	int n;
	DocGia *nodes[MAX_DOC_GIA];
	int soNgayQuaHan[MAX_DOC_GIA];
	ModeDocGia mode;
	
	TreeDocGia() {
		
	}


	// Duyet InOrder
	void LNR(DocGiaPTR &node){
		if(node == NULL) return;
		LNR(node->left);
		nodes[n++] = &node->docGia;
		LNR(node->right);
	}
	
	void GetAllDocGia(DocGiaPTR &root){
		Reset();
		LNR(root);
	}
	
	int compareDG(DocGia *a, DocGia *b){
		if(mode == MODE_MA_THE)
			return a->MATHE - b->MATHE;
		else if(mode == MODE_TEN){
			/*
			strcmp: 
				return 0 neu 2 chuoi giong nhau
				return -X , gia tri am neu ki tu khac biet dau tien trong *a nho hon ki tu tuong ung trong *b trong ASCII, 				
				return X, gia tri duong neu ki tu khac biet dau tien trong *a lon hon ki tu tuong ung trong *b trong ASCII				
				neu ki tu dau 2 chuoi bang nhau, tiep tuc so ki tu tiep theo	
			*/
			if(strcmp(a->ten, b->ten) == 0)	return strcmp(a->ho, b->ho); 
			else return strcmp(a->ten, b->ten);
		}
	}
	
	void Partition(int low, int high){
		int i = low, j = high;
		DocGia* pivot = nodes[(low+high)/2];
		int pivotQH = soNgayQuaHan[(low+high)/2];
		DocGia* temp;
		int qhTemp;		
		do{
			if(mode == MODE_QUA_HAN){
				while(soNgayQuaHan[i] > pivotQH) i++;
				while(soNgayQuaHan[j] < pivotQH) j--;
			}else{
				//T?m phan tu dau ti?n c? gia tri nho hon hay bang x
				while(compareDG(nodes[j], pivot) > 0) 	j--; 
				//T?m phan tu dau ti?n c? gia tri lon hon hay bang x
				while(compareDG(nodes[i], pivot) < 0)	i++; 
			}
			
			if(j>=i){//neu vi tri cua node co gia tri lon, nam phia truoc node co gia tri nho hon
				//hoan doi vi tri cho toi khi node co gia tri LON nam sau node co gia tri NHO
				temp = nodes[i];
				nodes[i] = nodes[j];
				nodes[j] = temp;
				if(mode == MODE_QUA_HAN){
					qhTemp = soNgayQuaHan[i];
					soNgayQuaHan[i] = soNgayQuaHan[j];
					soNgayQuaHan[j] = qhTemp;
				}
				i++; j--;
			}
		}while(i <= j);
		
		if(low < j) Partition(low, j);   //phan thu nhat co tu 2 phan tu tro len
		if(i < high) Partition(i, high); //phan thu 3 co tu 2 phan tu tro len
	}
	
	void SapXepDocGia(ModeDocGia type){
		if (n>0){
			switch(type){
				case MODE_MA_THE:{
					mode = MODE_MA_THE;	
					Partition(0, n-1);
					break;
				}
				case MODE_TEN:{
					mode = MODE_TEN;
					Partition(0, n-1);	
					break;
				}
				case MODE_QUA_HAN:{
					mode = MODE_QUA_HAN;
					Partition(0, n-1);
				}
				default:
					break;
			}
		}
	}
	
	void GetDocGiaQuaHan(NodeDocGia* &TreeDG){
		Reset();	
		ResetQH();
		Queue<NodeDocGia*> q;
		if(TreeDG != NULL) //push node root cua tree DocGia vo queue
			q.push(TreeDG);
			
		NodeDocGia* nodeDG;
		bool QUAHAN;
		while(!q.empty()){
			nodeDG = q.front();	
			q.pop();
			soNgayQuaHan[n];
			QUAHAN = false;
			int cmp = 0;
			if(nodeDG->docGia.mt.chuaTra > 0)
				for(NodeMuonTra *nodeMT = nodeDG->docGia.mt.First; nodeMT != NULL; nodeMT = nodeMT->next)
					if(strlen(nodeMT->muonTra.ngayTra) == 0){// chua tra sach
						int soNgayMuon = DiffTime(GetSystemDate(), nodeMT->muonTra.ngayMuon);
						if(soNgayMuon > 6*24*60*60){
//							soNgayQuaHan[n] = (soNgayMuon / (24*60*60))-6; //NGAY QUA HAN SO VOI 7 NGAY CHO PHEP
//							//cout<<"snqh: "<<n<<":"<<soNgayQH[n]<<endl;
//							nodeDG->docGia.trangThai = 0;						
//							QUAHAN = true;

							cmp = (soNgayMuon / (24*60*60)) - 6;
							if (cmp > soNgayQuaHan[n]) soNgayQuaHan[n] = cmp;
							
							nodeDG->docGia.trangThai = 0;
							QUAHAN = true;
						}

					}
			if(QUAHAN) nodes[n++] = &nodeDG->docGia;  //XU LY NODE			
			if(nodeDG->left != NULL) q.push(nodeDG->left);  //push node cuoi cung ben trai cua tree DocGia vo queue
			if(nodeDG->right != NULL) q.push(nodeDG->right); //push node cuoi cung ben phai cua tree DocGia vo queue
		}
		SapXepDocGia(MODE_QUA_HAN);
	}

	void Reset(){
		n = 0;
	}

	void ResetQH(){
		for(int i=0; i<MAX_DOC_GIA; i++) soNgayQuaHan[i] = 0;
	}
	
};

DocGiaPTR makeNodeDocGia(DocGia x) {
	DocGiaPTR newNode = new NodeDocGia();
	newNode->docGia = x;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->balanceFactor = 0;
	return newNode;
}

int height(DocGiaPTR root) {
	if (root == NULL) return 0;
	else return 1 +	max(height(root->left), height(root->right));
}


int balanceFactor(DocGiaPTR root) {
	if (root == NULL) return 0;
	return height(root->left) - height(root->right);
}

void rightRotate(DocGiaPTR &root) {
	DocGiaPTR newRoot = root->left;
	root->left = newRoot->right;
	newRoot->right = root;
	root->balanceFactor = balanceFactor(root);
	newRoot->balanceFactor = balanceFactor(newRoot);
	root = newRoot;
}

void leftRotate(DocGiaPTR &root) {
	DocGiaPTR newRoot = root->right;
	root->right = newRoot->left;
	newRoot->left = root;
	root->balanceFactor = balanceFactor(root);
	newRoot->balanceFactor = balanceFactor(newRoot);
	root = newRoot;
}

void InsertDocGia(DocGiaPTR &root, DocGia x) {
	// Tim vi tri de chen node vao cay
	if (root == NULL) {
		root = makeNodeDocGia(x);
	} else if (x.MATHE < root->docGia.MATHE) {
		InsertDocGia(root->left, x);
	} else if (x.MATHE > root->docGia.MATHE) {
		InsertDocGia(root->right, x);
	}
	
}

// Tim doc gia theo ma, neu co tra ve NodeDocGia, khong thi tra ve NULL
DocGiaPTR TimDocGiaTheoMa(DocGiaPTR &root, int maDocGia) {
	DocGiaPTR p = root;
	while (p != NULL && maDocGia != p->docGia.MATHE) {
		if (maDocGia < p->docGia.MATHE) {
			p = p->left;
		} else {
			p = p->right;
		}
	}
	return p;
}

void RemoveCaseTwoNode(DocGiaPTR &root, DocGiaPTR &y){
	if(y->left!= NULL){
		RemoveCaseTwoNode(root,y->left);
	}
	else{
		root->docGia = y->docGia;
		root = y;
		y = y->right;
	}
}
//// Xoa 1 doc gia theo maDocGia
int RemoveDocGia(DocGiaPTR &root, int maDocGia) {
	if(root == NULL) return 0;
	if(root->docGia.MATHE > maDocGia){
		RemoveDocGia(root->left,maDocGia);
	}
	else if(root->docGia.MATHE < maDocGia){
		RemoveDocGia(root->right,maDocGia);
	}
	else if(root->docGia.MATHE == maDocGia){
		DocGiaPTR temp = root;
		if(root->right == NULL){
			root = root->left;
		}
		else if(root->left == NULL){
			root = root->right;
		}
		else{
			RemoveCaseTwoNode(temp,root->right);
		}
	//	DeleteAllMuonTra(temp->docGia.mt);
		delete temp;
	}
	// can bang lai cay
	if(root!= NULL){
		root->balanceFactor = balanceFactor(root);
		int balance = root->balanceFactor;
		if (balance > 1 && balanceFactor(root->left) >=0){ // Left Left Case
			rightRotate(root);
		} 
		else if (balance < -1 && balanceFactor(root->right) <=0 ){ // Right Right Case
			leftRotate(root);
		} 
		else if (balance > 1 && balanceFactor(root->left) < 0) { // Left Right Case
			leftRotate(root->left);
			rightRotate(root);
		}
		else if (balance < -1 && balanceFactor(root->right)>0) { // Right Left Case
			rightRotate(root->right);
			leftRotate(root);
	    }
	}
		return 1;
}


void UpdateDocGia(DocGiaPTR &root, DocGia &docGia) {
	DocGiaPTR nodeUpdate = TimDocGiaTheoMa(root, docGia.MATHE);
	if(nodeUpdate == NULL){
		printf("K the update doc gia \n");
	}else{
		docGia.mt = nodeUpdate->docGia.mt;
		nodeUpdate->docGia = docGia;
	}	
}

void DeleteMemoryDocGia(DocGiaPTR &node) {
	if(node != NULL){
		DeleteMemoryDocGia(node->left);
		DeleteMemoryDocGia(node->right);		
		DeleteAllMuonTra(node->docGia.mt);		
		delete node;
	}
}

char* getMaSachQuaHan(DocGia &docGia){
	if(docGia.mt.chuaTra > 0){
		for(NodeMuonTra* node = docGia.mt.First; node != NULL; node = node->next){
			if(strlen(node->muonTra.ngayTra) == 0) return node->muonTra.MASACH;
		}
	}
}
char* getNgayMuonQuaHan(DocGia &docGia){
	if(docGia.mt.chuaTra > 0){
		for(NodeMuonTra* node = docGia.mt.First; node != NULL; node = node->next){
			if(strlen(node->muonTra.ngayTra) == 0) return node->muonTra.ngayMuon;
		}
	}
}

// ===================================================== //
struct TheDocGiaBSTC{  
   int MaThe;
   TheDocGiaBSTC *next;
};
typedef TheDocGiaBSTC* TDGTS_PTR;

TDGTS_PTR CreateNewNode(int MaThe) {
    TDGTS_PTR newNode = new TheDocGiaBSTC;
    newNode->MaThe = MaThe;
    return newNode;
}

void InsertLast_TDGTS(TDGTS_PTR &Last, int MaThe){
   TDGTS_PTR newNode  = CreateNewNode(MaThe);
   if (Last==NULL) newNode->next=newNode;
   else{
        newNode->next = Last->next;
	    Last->next = newNode;
   }
   Last = newNode;
}

bool DeleteFirst_TDGTS(TDGTS_PTR &Last) {
    TDGTS_PTR p;
    if (Last == NULL)
        return false;
    else{
    	// nut can xoa la nut dau
        p = Last -> next; 
        // danh sach chi co 1 nut
        if (p == Last)    
			Last = NULL;
        else    
			Last -> next = p -> next;
        delete p;
        return true;
    }
}

void deleteAll_TDGTS(TDGTS_PTR &Last) {
	while (Last != NULL) {
		DeleteFirst_TDGTS(Last);
	}
}

// ------------------------------------------------------
// Top sach
// ------------------------------------------------------


struct LuotMuonSach{
	int indexDS;	// vi tri cua DauSach
	int count;		// so luot muon
};	

struct TopSach{
	int n;
	LuotMuonSach *list;	
	
	TopSach(DS_DauSach &DSDS) {
		n = DSDS.n;
		list = new LuotMuonSach[n];
		for(int i=0; i<n; i++){
			list[i].indexDS = i;
			list[i].count = DSDS.nodes[i]->soLuotMuon;
		}
		// Sap xep theo thu tu count giam dan
		// Su dung QuickSort
		partition(0, n-1);
	}
	~TopSach(){
		delete[] list;
	}	
	// Phan doan
	void partition(int low, int high){
		int i = low, j = high;
		LuotMuonSach tmp;
		int pivot = list[(low+high)/2].count;
		do {
			while(list[i].count > pivot) i++;
			while(list[j].count < pivot) j--;
			if(i <= j){
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
				i++; j--;
			}
		} while(i <= j);
		
		if(low < j) partition(low, j);
		if(i < high) partition(i, high);
	}
};
