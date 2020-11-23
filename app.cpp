#include <iostream>
//QUAN LY MUA HANG
using namespace std;
struct DATE{
	int ngay, thang, nam;
};
struct HangHoa{
	char maHH[50]; //Ma hang hoa
	char tenSP[50]; //Ten san pham
	int soLuong; //So luong
	float donGia; //Don gia
	DATE date; //Ngay nhap
};
struct NODE{
	HangHoa data;
	NODE *link;	
};
struct List{
	NODE *first;
	NODE *last;	
};

void init(List &l){
	l.first = l.last = NULL;
}
NODE *CreateNODE(HangHoa x){
	NODE *p = new NODE;
	if(p == NULL){
		return NULL;
	}
	p->data = x;
	p->link = NULL;
	return p;
}
void AddLast(List &l, NODE *k){
	if(l.first == NULL){
		l.first = l.last = k;
	} else {
		l.last->link = k;
		l.last = k;
	}
}
bool AddHangHoa(HangHoa	&x){
	system("cls");
	printf("\n\tBat dau nhap hang hoa nhap ma hang hoa = 0 de dung.\n");
	do{
		printf("\n\tNhap ma hang: ");
		fflush(stdin);
		gets(x.maHH);
		if(strcmp(x.maHH,"0") == 0){
			return  false;
		}
		break;
	}while(1);
	printf("\n\tNhap ten san pham: ");
	fflush(stdin);
	gets(x.tenSP);
	printf("\n\tNhap so luong: ");
	scanf("%d", &x.soLuong);
	printf("\n\tNhap don gia: ");
	scanf("%f", &x.donGia);
	printf("\n\tNgay nhap");
	printf("\n\tNhap ngay: "); scanf("%d", &x.date.ngay);
	printf("\tNhap thang: "); scanf("%d",  &x.date.thang);
	printf("\tNhap nam: "); scanf("%d", &x.date.nam);
	return true;
}
void AddDSHangHoa(List &l){
	HangHoa x;
	while(AddHangHoa(x)){
		NODE *p = CreateNODE(x);
		AddLast(l, p);
	}
}
void TieuDe(){
	printf("\n\t%-10s %-15s %-10s %-10s %s/%s/%s\n", "Ma hang", "Ten sp", "So luong", "Don gia"
	,"dd", "mm", "yyyy");
}
void XuatHangHoa(HangHoa x){
	printf("\n\t%-10s %-15s %-10d %-10.2f %d/%d/%d\n", x.maHH, x.tenSP, x.soLuong, x.donGia
	,x.date.ngay, x.date.thang, x.date.nam);
}
void XuatDSHangHoa(List &l){
	TieuDe();
	for(NODE *k = l.first; k != NULL; k = k->link){
		XuatHangHoa(k->data);
	}
}
void Menu(List &l){
	int chon;
	do{
		printf("\n\t\t====================== Menu ======================");
		printf("\n\t1. Nhap hang hoa");
		printf("\n\t2. Xuat hang hoa");
		printf("\n\t0. Thoat");
		printf("\n\t\t====================== End =======================");
		printf("\n\tNhap lua chon: "); scanf("%d", &chon);
		switch(chon){
			case 0:
				break;
			case 1:
				system("cls");
				AddDSHangHoa(l);
				break;
			case 2: 
				system("cls");
				XuatDSHangHoa(l);
				break;
			default:
				printf("\n\tDang phat trien");
				break;
		}
	}while(chon != 0);
}
int main(int argc, char *argv[])
{
	List l;
	init(l);
	Menu(l);
	return 0;
}