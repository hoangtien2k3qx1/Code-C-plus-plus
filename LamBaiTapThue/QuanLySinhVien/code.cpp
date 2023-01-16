

#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
 
/*              XAY DUNG CLASS NGAY SINH                */
 
class ngaysinh
{
protected:
    int ngay;
    int thang;
    int nam;
public:
    ngaysinh(int ngay, int thang, int nam);
    ~ngaysinh();
    void nhapns();
    void hienns();
};
 
ngaysinh::ngaysinh(int ngay, int thang, int nam)
{
    ngay=ngay;
    thang=thang;
    nam=nam;
}
ngaysinh::~ngaysinh()
{
    ngay=thang=nam=0;
}
 
void ngaysinh::nhapns()
{
    char ch;
    cout<<"\nnhap ngay, thang, nam sinh(dd/mm/yyyy)  ";
    cin>>ngay>>ch>>thang>>ch>>nam;
};
 
void ngaysinh::hienns()
{
    cout<<endl;
    cout<<ngay<<"/"<<thang<<"/"<<nam<<endl;
};
 
/*                       XAY DUNG CLASS NGUOI                           */
 
class nguoi:public ngaysinh
{
    protected:
        int masv;
        char ten[30];
        ngaysinh ns;
        int gt;
    public:
        void nhapn();
        void inn();
};
 
void nguoi::nhapn()
{
    cout<<"\n Nhap ma so sinh vien:";cin>>masv;
    cout<<"\n Nhap ho va ten sinh vien:";
    cin.get(ten,30);
    cin.ignore(1);
    ns.nhapns();
    cout<<"\n Nhap gioi tinh ( Nam 1 / Nu 0 ) :";cin>>gt;
}
 
void nguoi::inn()
{
    cout<<"\n --------------------------------------------------";
    cout<<"\n Ma so sinh vien:"<<masv;
    cout<<"\n Ho va ten:"<<ten;
    cout<<"\n Ngay sinh:";ns.hienns();
    cout<<"\n Gioi tinh:";
    if (gt==1)
        cout<<"Nam";
    else
        cout<<"Nu";
}
 
/*                   XAY DUNG CLASS DIEM                               */
 
class diem : public nguoi
{
    private:
        float dtb;
        float drl;
        float dcong;
    public:
        diem(){}
        void nhapd();
        void ind();
        void sapxep();
        void timkiemdiem_dtb(float diemtb);
        void timkiemdiem_masv(int msv);
        void timkiemdiem_ten(char tensv[]);
        void ghi_file();
        void doc_file(int sod);
        int diem::dem();
        float laydtb();
};
 
//HAM NHAP
 
void diem::nhapd()
{
    nhapn();
    cout<<"\n Nhap diem trung binh:";cin>>dtb;
    cout<<"\n Nhap diem ren luyen:";cin>>drl;
    cout<<"\n Nhap diem cong:";cin>>dcong;
}
 
//HAM IN
 
void diem::ind()
{
    inn();
    cout<<"\n Diem TB:"<<dtb;
    cout<<"\n Diem ren luyen:"<<drl;
    cout<<"\n Diem cong:"<<dcong;
}
 
//HAM GHI FILE
 
void diem::ghi_file()
{
    fstream f;
    f.open("DIEM.TXT", ios::binary|ios::app|ios::out);
    f.write((char*)this, sizeof(*this));
    f.close();
}
 
//HAM DOC FILE
 
void diem::doc_file(int sod)
{
    fstream f;
    f.open("DIEM.TXT",ios::binary|ios::in);
    f.seekg( sod * sizeof(diem) );
    f.read((char*)this,sizeof(*this));
    f.close();
}
 
//HAM DEM
 
int diem::dem()
{
    ifstream f;
    f.open("DIEM.TXT", ios::binary);
    f.seekg(0, ios::end);
    if(!f)
        return 0;
    else
        return (int)f.tellg() / sizeof(diem);
}
 
//TIM KIEM DIEM THEO MA SV
 
void diem::timkiemdiem_masv(int msv)
{
    diem d;
    int so=diem::dem();
    for(int i=0;i<so;i++)
    {
        d.doc_file(i);
        if(masv==msv)
            d.ind();
    }
}
 
//TIM KIEM DIEM THEO TEN
 
void diem::timkiemdiem_ten(char tensv[])
{
    diem d;
    int so=diem::dem();
    for(int i=0;i<so;i++)
    {
        d.doc_file(i);
        if(ten==tensv)
            d.ind();
    }
}
 
//TIM KIEM THEO DTB
 
void diem::timkiemdiem_dtb(float diemtb)
{
    diem d;
    int so=diem::dem();
    for(int i=0;i<so;i++)
    {
        d.doc_file(i);
        if(dtb==diemtb)
            d.ind();
    }
}
 
/*                   XAY DUNG CLASS SINH VIEN                         */
 
class sinhvien : public nguoi
{
    private:
        char qq[50];
        char cs[20];
    public:
        sinhvien(){}
        void nhapsv();
        void insv();
        void dssv();
        void ghi_file();
        void doc_file(int sosv);
        int sinhvien::dem();
        void timkiem_masv(int msv);
        void timkiem_ten(char ten[]);
};
 
//HAM NHAP
 
void sinhvien::nhapsv()
{
 
    nhapn();
    cout<<"\n Nhap que quan:";
    cin.get(qq,50);
    cin.ignore(1);
    cout<<"\n Nhap dien chinh sach:";
    cin.get(cs,20);
    cin.ignore(1);
}
 
//HAM IN
 
void sinhvien::insv()
{
    inn();
    cout<<"\n Que quan:"<<qq;
    cout<<"\n Dien chinh sach:"<<cs;
}
 
//GHI FILE
 
void sinhvien::ghi_file()
{
    fstream f;
    f.open("SINHVIEN.TXT", ios::binary|ios::app|ios::out);
    f.write((char*)this, sizeof(*this));
    f.close();
}
 
//DOC FILE
 
void sinhvien::doc_file(int sosv)
{
    fstream f;
    f.open("SINHVIEN.TXT",ios::binary|ios::in);
    f.seekg(sosv* sizeof(sinhvien) );
    f.read((char*)this,sizeof(*this));
    f.close();
}
 
//DEM SO SINH VIEN
 
int sinhvien::dem()
{
     ifstream f;
     f.open("SINHVIEN.TXT", ios::binary);
     f.seekg(0, ios::end);
     if(!f)
        return 0;
     else
        return (int)f.tellg() / sizeof(sinhvien);
}
 
//HIEN THI DANH SACH SINH VIEN
 
void sinhvien::dssv()
{
    sinhvien sv;
    cout<<"\n Co tat ca "<<sinhvien::dem()<<" sinhvien";
    for (int i=0 ; i<sv.dem();i++)
    {
        sv.doc_file(i);
        sv.insv();
    }
}
 
//TIM KIEM THEO MA SO SV
 
void sinhvien::timkiem_masv(int msv)
{
    sinhvien sv;
    cout<<"\n Sinh vien co ma so sinh vien "<<msv<<"  la: \n";
    int sosv=sinhvien::dem();
    for(int i=0;i<sosv;i++)
    {
        sv.doc_file(i);
        if(masv==msv)
            sv.insv();
    }
 
}
 
//TIM KIEM THEO TEN
 
void sinhvien::timkiem_ten(char tensv[])
{
    sinhvien sv;
    cout<<"\n Nhung sinh vien ten "<<tensv<<" la:\n";
    int sosv=sinhvien::dem();
    for(int i=0;i<sosv;i++)
    {
        sv.doc_file(i);
        if(ten==tensv)
            sv.insv();
    }
}
 
//MAIN MENU
 
void MM(sinhvien &sv,diem &d)
{
    cout<<"\n*******************************************************";
    cout<<"\n*              HE THONG QUAN LY SINH VIEN             *";
    cout<<"\n*                                                     *";
    cout<<"\n*  QUAN LY SINH VIEN                                  *";
    cout<<"\n*                                                     *";
    cout<<"\n*  1. Nhap vao sinh vien                              *";
    cout<<"\n*  2. Tim kiem theo ma so sinh vien                   *";
    cout<<"\n*  3. Tim kiem theo ten sinh vien                     *";
    cout<<"\n*  4. Danh sach sinh vien                             *";
    cout<<"\n*  5. Xoa                                             *";
    cout<<"\n*                                                     *";
    cout<<"\n*  QUAN LY DIEM                                       *";
    cout<<"\n*                                                     *";
    cout<<"\n*  6. Nhap diem cua sinh vien                         *";
    cout<<"\n*  7. Tim kiem theo ma so sinh vien                   *";
    cout<<"\n*  8. Tim kiem theo ten                               *";
    cout<<"\n*  9. Tim kiem theo diem trung binh                   *";
    cout<<"\n*  10. Danh sach SV theo thu tu giam dan cua DTB      *";
    cout<<"\n*  11.xoa                                             *";
    cout<<"\n*                                                     *";
    cout<<"\n*  QUAN LY HOC BONG                                   *";
    cout<<"\n*                                                     *";
    cout<<"\n*  12. Danh sach hoc bong                             *";
    cout<<"\n*  13. Gioi thieu                                     *";
    cout<<"\n*  14. Thoat chuong trinh                             *";
    cout<<"\n*                                                     *";
    cout<<"\n*******************************************************";
    cout<<"\n\nLua chon cong viec tuong ung ";
    int n;
    cin>>n;
    switch(n)
    {
        case (1) :
            {
                sv.nhapsv();
                MM(sv,d);
                break;
            }
        case (2) :
            {
                int ma;
                cout<<"\n Ma so sinh vien can tim: ";
                cin>>ma;
                sv.timkiem_masv(ma);
                MM(sv,d);
                break;
            }
        case (3) :
            {
                char t[30];
                cout<<"\n Ten sinh vien can tim: ";
                fflush(stdin);
                cin.get(t,30);
                sv.timkiem_ten(t);
                MM(sv,d);
                break;
            }
        case (4) :
            {
                sv.dssv();
                MM(sv,d);
                break;
            }
    /*    case (5) :
            {
                cv.nhap();
                MM(ld,cv);
                break;
            }    */
        case (6) :
            {
                d.nhapd();
                MM(sv,d);
                break;
            }
        case (7) :
            {
                int ma;
                cout<<"\n Ma so sinh vien can tim: ";
                cin>>ma;
                d.timkiemdiem_masv(ma);
                MM(sv,d);
                break;
            }
        case (8) :
            {
                char t[30];
                cout<<"\n Ten sinh vien can tim: ";
                fflush(stdin);
                cin.get(t,30);
                d.timkiemdiem_ten(t);
                MM(sv,d);
                break;
            }
        case (9) :
            {
                float d1;
                cout<<"\n DTB can tim: ";
                cin>>d1;
                d.timkiemdiem_dtb(d1);
                MM(sv,d);
                break;
            }
    /*    case(10) :
            {
               
            }
        case(11) :
            {
           
            }
        case (12):
            {
               
            }          */
        case(13) :
            {
                cout<<"\n---------------------------------"
                    <<"\n--------------------------"
                    <<"----------------------------"
                    <<"\n-----------------";
                MM(sv,d);
                break;
            }
        case(14) :
            {
                exit(1);
                break;
            }
 
        default : cout<<"Gia tri nhap vao khong thich hop";
    }
}
 
//CHUONG TRINH CHINH
 
void main()
{
    clrscr();
    sinhvien sv();
    diem d();
    MM(sv,d);
}