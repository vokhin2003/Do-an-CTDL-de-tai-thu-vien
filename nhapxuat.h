void Sort(int A[], int q, int r) {
    int temp;
    int i = q;
    int j = r;
    int x = A[(q + r)/2]; 
    do { 
        while (A[i] < x) i++;
        while (A[j] > x) j--; 
        if (i <= j) 
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++; j--;
        }
    } while (i <= j);
    if (q < j) Sort(A, q, j);
    if (i < r) Sort(A, i, r);
}

void CreateFileMaTheDocGia(){
	int a[MAX_DOC_GIA];
	a[0]=0;
	a[1]= MAX_DOC_GIA;
	int j=2;
	int k=2;
	int TheDocGiaBST[MAX_DOC_GIA];
	int count = 0;
	while(a[1]!=1)
	{
		for(int i=0;i<j-1;i++){
			a[k]=(a[i]+a[i+1])/2;
			TheDocGiaBST[count] = a[k];
			count++;
			k++;
		}
		j=k;
		Sort(a, 0, k-1);
	}
	
	fstream fileMaTheDocGia;
	fileMaTheDocGia.open("data_MaTheDocGia.txt", ios::out | ios::trunc);
	fileMaTheDocGia << count << endl;	
	for(int i=0; i<count; i++)
		fileMaTheDocGia << TheDocGiaBST[i]<<"\t";
	fileMaTheDocGia.close();
}


void ReadDauSachFromFile(DS_DauSach &DSDS) {
	fstream fileDauSach, fileDMS;
	fileDauSach.open("data_dsds.txt", ios::in);
	fileDMS.open("data_dms.txt", ios::in);
	
	int n;
	fileDauSach >> n;
	fileDauSach.ignore();
	
	int m, slm;
	DauSach *tmp;
	Sach x;
	for (int i=0;i<n;i++) {
		tmp = new DauSach();
		fileDauSach.getline(tmp->ISBN, sizeof(tmp->ISBN));
		fileDauSach.getline(tmp->tenSach, sizeof(tmp->tenSach));
		fileDauSach >> tmp->soTrang; fileDauSach.ignore();
		fileDauSach.getline(tmp->tacGia, sizeof(tmp->tacGia));
		fileDauSach >> tmp->nxb; fileDauSach.ignore();
		fileDauSach.getline(tmp->theLoai, sizeof(tmp->theLoai));
		
		fileDMS >> tmp->soLuotMuon; fileDMS.ignore();
		fileDMS >> tmp->soLuong; fileDMS.ignore();
		m = tmp->soLuong;
		
		for (int j=0;j<m;j++) {
			fileDMS.getline(x.MASACH, sizeof(x.MASACH));
			fileDMS >> x.trangThai; fileDMS.ignore();
			fileDMS.getline(x.viTri, sizeof(x.viTri));
			InsertLastNodeSach(tmp->First, x);
		}
		
		if (!InsertLastDauSach(DSDS, tmp)) {
			return;
		}
	}
	cout << "Successfully\n";
	fileDauSach.close();
	fileDMS.close();
}

void WriteDauSachToFile(DS_DauSach &DSDS) {
	fstream fileDauSach, fileDMS;
	fileDauSach.open("data_dsds.txt", ios::out | ios::trunc);	
	fileDMS.open("data_dms.txt", ios::out | ios::trunc);
	
	fileDauSach << DSDS.n << endl;
	for (int i=0; i < DSDS.n; i++) {
		fileDauSach << DSDS.nodes[i]->ISBN << endl;
		fileDauSach << DSDS.nodes[i]->tenSach << endl;
		fileDauSach << DSDS.nodes[i]->soTrang << endl;
		fileDauSach << DSDS.nodes[i]->tacGia << endl;
		fileDauSach << DSDS.nodes[i]->nxb << endl;
		fileDauSach << DSDS.nodes[i]->theLoai << endl;		
		fileDMS << DSDS.nodes[i]->soLuotMuon << endl;
		fileDMS << DSDS.nodes[i]->soLuong << endl;
		
		for (SachPTR p = DSDS.nodes[i]->First; p != NULL; p = p->next) {
			fileDMS << p->sach.MASACH << endl;
			fileDMS << p->sach.trangThai << endl;
			fileDMS << p->sach.viTri << endl;
		}
	}
	fileDauSach.close();
	fileDMS.close();
}

void WriteMaTheDocGia(TDGTS_PTR tdg) {
	fstream fileMaTheDocGia;
	fileMaTheDocGia.open("data_MaTheDocGia.txt", ios::out | ios::trunc);	
	if(!fileMaTheDocGia.is_open())
		cout<<"Loi doc file data_MaTheDocGia roi!!!";		
	fileMaTheDocGia << sizeofArrayMaTheDocGia << endl;	
	for(int i=0; i<sizeofArrayMaTheDocGia; i++,tdg = tdg->next)
		fileMaTheDocGia << tdg->next->MaThe<<"\t";
	fileMaTheDocGia.close();	
}

void ReadMaTheDocGia(TDGTS_PTR &tdg){
	fstream fileMaTheDocGia;
	fileMaTheDocGia.open("data_MaTheDocGia.txt", ios::in);
	if(!fileMaTheDocGia.is_open())
		cout<<"Loi doc file data_MaTheDocGia roi!!!";		
	fileMaTheDocGia >> sizeofArrayMaTheDocGia;
	fileMaTheDocGia.ignore();		
	int temp;
	for(int i=0; i<sizeofArrayMaTheDocGia; i++){
		fileMaTheDocGia >> temp;
		InsertLast_TDGTS(tdg, temp);
	}	
	fileMaTheDocGia.close();
}

void ReadDocGiaFromFile(DocGiaPTR &root) {
	fstream fileDocGia, fileMuonTra;
	fileDocGia.open("data_docgia.txt", ios::in);
	fileMuonTra.open("data_muontra.txt", ios::in);
	
	int n, m;
	DocGia dg;
	MuonTra mt;
	fileDocGia >> n;
	fileDocGia.ignore();
	for (int i=0;i<n;i++) {
		fileDocGia >> dg.MATHE;				fileDocGia.ignore();
		fileDocGia.getline(dg.ho, sizeof(dg.ho));
		fileDocGia.getline(dg.ten, sizeof(dg.ten));
		fileDocGia >> dg.phai;				fileDocGia.ignore();
		fileDocGia >> dg.trangThai;			fileDocGia.ignore();
		
		fileMuonTra >> m;					fileMuonTra.ignore();
		for (int j=0;j<m;j++) {
			fileMuonTra.getline(mt.MASACH, sizeof(mt.MASACH));
			fileMuonTra.getline(mt.ngayMuon, sizeof(mt.ngayMuon));
			fileMuonTra.getline(mt.ngayTra, sizeof(mt.ngayTra));
			fileMuonTra >> mt.trangThai;	fileMuonTra.ignore();
			InsertLastMuonTra(dg.mt, mt);
		}
		
		InsertDocGia(root, dg);
	}
	cout << "\nSuccessfully 222!\n";
	fileDocGia.close();
	fileMuonTra.close();
}

int TotalDocGia(DocGiaPTR &root) {
	if (root == NULL) return 0;
	Queue<NodeDocGia> q;
	NodeDocGia p;
	
	q.push(*root);
	int cnt = 0;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		cnt++;
		if (p.left != NULL) q.push(*p.left);
		if (p.right != NULL) q.push(*p.right);
	}
	return cnt;
}

void WriteDocGiaToFile(DocGiaPTR &root) {
	if (root == NULL) return;
	fstream fileDocGia, fileMuonTra;
	fileDocGia.open("data_docgia.txt", ios::out | ios::trunc);
	fileMuonTra.open("data_muontra.txt", ios::out | ios::trunc);
	
	Queue<NodeDocGia*> q;
	NodeDocGia *node;
	NodeMuonTra *nodeMT;
	q.push(root);
	
	fileDocGia << TotalDocGia(root) << endl;
	while (!q.empty()) {
		// Lay tung doc gia ra - ghi du lieu
		node = q.front();
		q.pop();
		fileDocGia << node->docGia.MATHE << endl;
		fileDocGia << node->docGia.ho << endl;
		fileDocGia << node->docGia.ten << endl;
		fileDocGia << node->docGia.phai << endl;
		fileDocGia << node->docGia.trangThai << endl;
		// ghi danh sach cac sach da muon
		fileMuonTra << node->docGia.mt.total << endl;
		for (nodeMT = node->docGia.mt.First; nodeMT != NULL; nodeMT = nodeMT->next) {
			fileMuonTra << nodeMT->muonTra.MASACH << endl;
			fileMuonTra << nodeMT->muonTra.ngayMuon << endl;
			fileMuonTra << nodeMT->muonTra.ngayTra << endl;
			fileMuonTra << nodeMT->muonTra.trangThai << endl;
		}
		if (node->left != NULL) q.push(node->left);
		if (node->right != NULL) q.push(node->right);
	}
	fileMuonTra.close();
	fileDocGia.close();
}
