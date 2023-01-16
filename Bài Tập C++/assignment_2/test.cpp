
/*
    Bài 7: : Viết chương trình thực hiện các yêu cầu sau:
        1.	Khai báo lớp ma trận vuông với các thuộc tính: cấp ma trận, các phần tử của ma trận.
        2.	Xây dựng các phương thức: nhập, xuất một đối tượng ma trận.
        3.	Nhập và 1 ma trận. In ra màn hình ma trận vừa nhập. Tính tổng các phần tử nằm trên 
        đường chéo chính, tổng các phần tử nằm trên đường chéo phụ của ma trận.


*/

#include <iomanip>
#include <complex>
#include <iostream>
using namespace std;

#define MAX 10

class MaTran
{

    private:
		int soHang,soCot;
		float det;
		float mt[MAX][MAX];

	public:
		MaTran(int soHang, int soCot);
		~MaTran();
		void inMaTran(float a[][MAX],int soHang,int soCot);
		void nhapMaTran();
		void chuyenVi(int in);
		bool dinhThuc(int in);
		float phuHop(float a[][MAX],int hangXoa, int cotXoa);
		void nghichDao();
		int hang();
		void xoaHang();
		void xoaCot();
		void congMaTran();
		void truMaTran();
		void nhanMT_So();
		void nhanMT_MT();
};
 
MaTran::MaTran(int soHang, int soCot){
	this->soHang=soHang;
	this->soCot=soCot;
}

MaTran::~MaTran(){
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
			mt[i][j]=0;
	soHang=soCot=det=0;
}

void MaTran::inMaTran(float a[][MAX],int soHang,int soCot){
	cout<<fixed<<setprecision(2);
	for(int i=0;i<soHang;i++){
		cout<<"\n\t";
		for(int j=0;j<soCot;j++) 
            cout<<setw(5)<<a[i][j]<<" ";
	}
	cout<<endl;
}

void MaTran::nhapMaTran(){
	for(int i=0;i<soHang;i++) {
		for(int j=0;j<soCot;j++){
			cout<<"\tPhan tu ["<<i+1<<","<<j+1<<"] = ";
			cin>>mt[i][j];
		}
    }
	cout<<"Ma tran ban vua nhap la:";
	inMaTran(mt,soHang,soCot);
}

void MaTran::chuyenVi(int in=0){
	float cv[MAX][MAX];
	for(int i=0;i<soCot;i++){
		for(int j=0;j<soHang;j++)
			cv[i][j]=mt[j][i];
	}
	cout<<"Ma tran chuyen vi cua ma tran A la:";
	inMaTran(cv,soCot,soHang);
}

bool MaTran::dinhThuc(int in = 0){
	if(soHang==soCot){
		//Dua ma tran ve ma tran tam giac tren
		int d=0; //Bien d: dem so lan doi 2 hang cua ma tran
		//B1: tim gia tri khac 0 dau tien cua moi cot cho vao duong cheo chinh
		for(int i=0;i<soHang;i++){
			if(mt[i][i]==0)
				//Neu phan tu mt[i][i]=0 thi tim phan tu khac 0 dau tien trong cot i roi doi cho 2 hang
				for(int k=i+1;k<soHang;k++){
					if(mt[k][i]!=0){
						for(int j=0;j<soCot;j++){
							float t=mt[i][j];
							mt[i][j]=mt[k][j];
							mt[k][j]=t;
						}
						d++;
						break; //Khi doi cho xong thi thoat ra, khong tim nua
					}
				}
			if(mt[i][i]!=0)
				//Neu phan tu mt[i][i]!=0 thi dua cac phan tu cot i phia duoi mt[i][i] ve 0
				for(int k=i+1;k<soHang;k++){
					double tl=mt[k][i]/mt[i][i]; //bien tl de tim ti le 2 hang
					for(int j=0;j<soCot;j++)
						mt[k][j]-=mt[i][j]*tl;
				}
			else{
				//Neu sau cac buoc tren ma phan tu mt[i][i]=0 thi dinh thuc cua ma tran = 0, ta dua ra ket luan va thoat ra.
				det=0;
				if(in==1) cout<<"\tDinh thuc cua ma tran A la: det(A)="<<det<<endl;
				return 1;
			}
		}
		//Tinh dinh thuc bang tich cac phan tu tren duong cheo chinh
		det=1.0;
		for(int i=0;i<soCot;i++) det*=mt[i][i];
		det*=pow(-1,d); //ham pow(x,n)=x^n
		if(in==1) cout<<"\tDinh thuc cua ma tran A la: det(A)="<<det<<endl;
		return 1;
	} else{
		return 0;
	}
}

float MaTran::phuHop(float a[][MAX],int hangXoa, int cotXoa){
	//Ma tran phu hop xoa di 1 hang va 1 cot
	MaTran ph(soHang-1,soCot-1);
	for(int i=0;i<hangXoa;i++){
		for(int j=0;j<cotXoa;j++)
			ph.mt[i][j]=a[i][j];
		for(int j=cotXoa;j<ph.soCot;j++)
			ph.mt[i][j]=a[i][j+1];
	}
	for(int i=hangXoa;i<ph.soHang;i++){
		for(int j=0;j<cotXoa;j++)
			ph.mt[i][j]=a[i+1][j];
		for(int j=cotXoa;j<ph.soCot;j++)
			ph.mt[i][j]=a[i+1][j+1];
	}
	ph.dinhThuc(); //tinh dinh thuc
	if(ph.det==0) return 0; //neu dinh thuc bang 0 thi phan tu phu hop se bang 0
	float pTu=(float) ph.det/det; //neu khong thi tinh phan tu phu hop bang thuong cua dinh thuc ma tran phu hop
	pTu*=pow(-1,hangXoa+cotXoa); //va dinh thuc ma tran can tim nghich dao nhan voi -1^(hangxoa+cotxoa).
	//if(abs(pTu)<0.01 && abs(pTu)>0) cout<<pTu*10000000000<<endl; //Kiem tra xem phan tu -0.00 co phai la do lam tron khong.
	return pTu;
}

void MaTran::nghichDao(){
	if(!dinhThuc() || det==0) cout<<"\tMa Tran A khong kha nghich\n";
	else{
		dinhThuc();
		//Tao ma tran lay gia tri cua ma tran chuyen vi
		float cv[MAX][MAX];
		for(int i=0;i<soHang;i++)
			for(int j=0;j<soCot;j++)
				cv[i][j]=mt[j][i];
		//Ma tran co cac phan tu la ti le dinh thuc cua ma tran phu hop va dinh thuc ma tran A
		for(int i=0;i<soHang;i++)
			for(int j=0;j<soCot;j++)
				mt[i][j]=phuHop(cv,i,j);
		cout<<"Ma tran nghich dao cua ma tran A la:";
		inMaTran(mt,soHang,soCot);
	}
}

int MaTran::hang(){
	//Dua ma tran ve ma tran tam giac tren
	for(int i=0;i<soHang-1;i++){
		for(int j=i;j<soCot;j++){
			if(mt[i][j]==0)
				for(int k=i+1;k<soHang;k++)
					if(mt[k][j]!=0){
						for(int u=0;u<soCot;u++){
							float t=mt[i][u];
							mt[i][u]=mt[k][u];
							mt[k][u]=t;
						}
						break;
					}
			if(mt[i][j]!=0){
				for(int k=i+1;k<soHang;k++){
					double tl=(double) mt[k][j]/mt[i][j];
					for(int u=0;u<soCot;u++){
						mt[k][u]-=mt[i][u]*tl;
					}
				}
				break;
			}
		}
	}
	//Tim hang (dem hang chua phan tu != 0 co chi so lon nhat, chi so do chinh la hang cua ma tran
	int r=0;
	for(int i=soHang-1;i>=0;i--){
		for(int j=0;j<soCot;j++)
			if(abs(mt[i][j])!=0){
				r=i+1;
				break;
			}
		if(r>0) break;
	}
	return r;
}

void MaTran::xoaHang(){
	int x=0;
	do{
		cout<<"Nhap vao hang thu x (0<x<"<<soHang+1<<") ban muon xoa: ";
		cin>>x;
	} while(x<1 || x>soHang);
	x--;
	soHang--;
	for(int j=0;j<soCot;j++)
		for(int i=x;i<soHang;i++)
			mt[i][j]=mt[i+1][j];
	cout<<"Ma tran A sau khi xoa hang thu "<<x+1<<" la:";
	inMaTran(mt,soHang,soCot);
}

void MaTran::xoaCot(){
	int x=0;
	do{
		cout<<"Nhap vao cot thu x (0<x<"<<soCot+1<<") ban muon xoa: ";
		cin>>x;
	} while(x<1 || x>soCot);
	x--;
	soCot--;
	for(int i=0;i<soHang;i++){
		for(int j=x;j<soCot;j++)
			mt[i][j]=mt[i][j+1];
	}
	cout<<"Ma tran A sau khi xoa cot thu "<<x+1<<" la:";
	inMaTran(mt,soHang,soCot);
}

void MaTran::congMaTran(){
	float b[MAX][MAX];
	cout<<"Nhap ma tran B:\n";
	for(int i=0;i<soHang;i++)
		for(int j=0;j<soCot;j++){
			cout<<"\tPhan tu ["<<i+1<<","<<j+1<<"] = ";
			cin>>b[i][j];
		}
	cout<<"Ma tran ban vua nhap la:";
	inMaTran(b,soHang,soCot);
	for(int i=0;i<soHang;i++)
		for(int j=0;j<soCot;j++){
			mt[i][j]+=b[i][j];
		}
	cout<<"Tong cua 2 ma tran A va B la:";
	inMaTran(mt,soHang,soCot);
}

void MaTran::truMaTran(){
	float b[MAX][MAX];
	cout<<"Nhap ma tran B:\n";
	for(int i=0;i<soHang;i++)
		for(int j=0;j<soCot;j++){
			cout<<"\tPhan tu ["<<i+1<<","<<j+1<<"] = ";
			cin>>b[i][j];
		}
	cout<<"Ma tran ban vua nhap la:";
	inMaTran(b,soHang,soCot);
	for(int i=0;i<soHang;i++)
		for(int j=0;j<soCot;j++){
			mt[i][j]-=b[i][j];
		}
	cout<<"Hieu cua 2 ma tran A va B la:";
	inMaTran(mt,soHang,soCot);
}

void MaTran::nhanMT_So(){
	float x=1;
	cout<<"Nhap vao so x: ";
	cin>>x;
	for(int i=0;i<soHang;i++)
		for(int j=0;j<soCot;j++)
			mt[i][j]*=x;
	cout<<"Tich cua "<<x<<" voi ma tran A la:";
	inMaTran(mt,soHang,soCot);
}

void MaTran::nhanMT_MT(){
	float b[MAX][MAX];
	int cotB=10;
	cout<<"Nhap so cot cua ma tran B: ";
	cin>>cotB;
	int hangB=soCot;
	cout<<"\nNhap ma tran B:\n";
	for(int i=0;i<hangB;i++)
		for(int j=0;j<cotB;j++){
			cout<<"\tPhan tu ["<<i+1<<","<<j+1<<"] = ";
			cin>>b[i][j];
		}
	cout<<"Ma tran ban vua nhap la:";
	inMaTran(b,hangB,cotB);
	float tong[MAX][MAX]={};
	for(int i=0;i<soHang;i++)
		for(int j=0;j<cotB;j++){
			for(int k=0;k<soCot;k++)
				tong[i][j]+=mt[i][k]*b[k][j];
		}
	cout<<"Tich cua ma tran A va ma tran B la:";
	inMaTran(tong,soHang,cotB);
}

int main(){
	int soHang,soCot;
	cout<<"Nhap so hang cua ma tran A: ";
	cin>>soHang;
	cout<<"Nhap so cot cua ma tran A: ";
	cin>>soCot;
	MaTran a(soHang,soCot);
	cout<<"\nNhap ma tran A:\n";
	a.nhapMaTran();
	cout<<"\n+ Danh sach thao tac:\n";
	cout<<"\tChuyen vi:\t1| Dinh thuc:\t\t2| Nghich dao:\t3|";
	cout<<"\n\tHang:\t\t4| Xoa hang:\t\t5| Xoa cot:\t6|";
	cout<<"\n\tCong ma tran:\t7| Tru ma tran:\t\t8|";
	cout<<"\n\tMa tran x So:\t9| Ma tran x Ma tran:\t10|";
	cout<<"\n\tKet thuc phien lam viec:\t0\n";
	while(true){
		int tt=0;
		cout<<"\n+ Chon thao tac ma ban muon thuc hien (0->10): ";
		cin>>tt;
		cout<<endl;
		MaTran b(soHang,soCot);
		b=a;
		switch(tt){
			case 1: b.chuyenVi(1); break;
			case 2: if(!b.dinhThuc(1)) cout<<"\tMa tran khong hop le!\n"; break;
			case 3: b.nghichDao(); break;
			case 4: cout<<"\tHang cua ma tran A la: "<<b.hang()<<endl; break;
			case 5: b.xoaHang(); break;
			case 6: b.xoaCot(); break;
			case 7: b.congMaTran(); break;
			case 8: b.truMaTran(); break;
			case 9: b.nhanMT_So(); break;
			case 10: b.nhanMT_MT(); break;
			default: tt=0; break;
		}
		if(tt==0) break;
	}
	return 0;
}
