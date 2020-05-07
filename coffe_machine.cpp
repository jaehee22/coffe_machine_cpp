#include<iostream>
using namespace std;

string coffe[1000];			//커피 이름, 가격, 메뉴는 전부 필요하니까 전역변수로 선언
int coffe_price[10], coffe_stock[10];
int coffe_s[10];

void coffe_set() {			//커피의 이름/가격/재고/매출을 미리 설정한다.
	coffe[1] = "아메리카노";
	coffe[2] = "카페라떼";
	coffe[3] = "바닐라라떼";
	coffe[4] = "콜드브루";
	coffe[5] = "허니자몽티";

	coffe_price[1] = 3500;
	coffe_price[2] = 3800;
	coffe_price[3] = 4000;
	coffe_price[4] = 3600;
	coffe_price[5] = 4500;

	for (int i = 1; i <= 5; i++) {		//기본 재고는 10개로 한다.
		coffe_stock[i] = 10;
		coffe_s[i] = 0;
	}
}

void manu_list() {			//초기화면
	cout << "=====================" << endl;
	cout << "        메뉴         " << endl;
	cout << "=====================" << endl;
	cout << "1. 커피 주문하기" << endl;
	cout << "2. 커피 매출 확인" << endl;
	cout << "3. 커피 입고 하기" << endl;
	cout << "4. 종료하기" << endl;
	cout << "=====================" << endl;
}

void coffe_list() {			//커피의 현황을 출력한다.
	int i = 1;
	while (coffe[i] != "") {
		printf("%d.", i);
		cout << coffe[i] << endl;
		printf("  가격:%d    재고:%d\n\n", coffe_price[i], coffe_stock[i]);
		i++;
	}
}

void coffe_order() {
	int choice = 0, coffe_n;			//choice : 커피를 선택, coffe_n : 커피의 개수

	while (choice != 9) {
		coffe_list();
		cout << "구입하실 커피의 번호를 선택해주세요. (뒤로가시려면 9번을 누르세요.)" << endl;
		cin >> choice;
		if (choice == 9) {
			break;
		}
		else if (coffe[choice] == "") {
			cout << "해당되는 커피는 없습니다." << endl << endl;
			continue;
		}
		cout << "몇개를 주문하시겠습니까?" << endl;
		cin >> coffe_n;
		while (coffe_stock[choice] < coffe_n) {
			cout << "죄송합니다. 커피의 수량이 부족합니다. 수량을 조정해주세요" << endl;
			cin >> coffe_n;
		}
		coffe_stock[choice] -= coffe_n;						//커피의 재고 빼기
		coffe_s[choice] += coffe_price[choice] * coffe_n;	//커피의 매출 더하기
		cout << "더 주문 하시겠습니까?" << endl;
	}

	return;
}

void coffe_sales() {
	int total_sale = 0, i = 1;
	while (coffe[i] != "") {
		cout << coffe[i];
		printf("	매출 : %d\n", coffe_s[i]);
		i++;
	}
	printf("총 매출 : %d\n", total_sale);
}

void coffe_plus() {
	int choice = 0, coffe_n;

	while (choice != 9) {
		coffe_list();
		cout << "입고하실 커피의 번호를 선택해주세요. (뒤로가시려면 9번을 누르세요.)" << endl;
		cin >> choice;
		if (choice == 9)
			break;
		else if (coffe[choice] == "") {
			cout << "해당되는 커피는 없습니다." << endl << endl;
			continue;
		}
		cout << "몇개를 입고하시겠습니까?" << endl;
		cin >> coffe_n;
		coffe_stock[choice] += coffe_n;
		cout << "더 입고하시겠습니까?" << endl;
	}
	return;
}
int main() {
	coffe_set();		//커피 리스트를 미리 셋팅한다.
	int n = 0;

	while (n != 4) {
		manu_list();
		cin >> n;
		switch (n) {
		case 1:
			coffe_order();
			break;
		case 2:
			coffe_sales();
			break;
		case 3:
			coffe_plus();
			break;
		default:
			break;
		}
	}
	return 0;
}