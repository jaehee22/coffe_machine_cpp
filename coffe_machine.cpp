#include<iostream>
using namespace std;

string coffe[1000];			//Ŀ�� �̸�, ����, �޴��� ���� �ʿ��ϴϱ� ���������� ����
int coffe_price[10], coffe_stock[10];
int coffe_s[10];

void coffe_set() {			//Ŀ���� �̸�/����/���/������ �̸� �����Ѵ�.
	coffe[1] = "�Ƹ޸�ī��";
	coffe[2] = "ī���";
	coffe[3] = "�ٴҶ��";
	coffe[4] = "�ݵ���";
	coffe[5] = "����ڸ�Ƽ";

	coffe_price[1] = 3500;
	coffe_price[2] = 3800;
	coffe_price[3] = 4000;
	coffe_price[4] = 3600;
	coffe_price[5] = 4500;

	for (int i = 1; i <= 5; i++) {		//�⺻ ���� 10���� �Ѵ�.
		coffe_stock[i] = 10;
		coffe_s[i] = 0;
	}
}

void manu_list() {			//�ʱ�ȭ��
	cout << "=====================" << endl;
	cout << "        �޴�         " << endl;
	cout << "=====================" << endl;
	cout << "1. Ŀ�� �ֹ��ϱ�" << endl;
	cout << "2. Ŀ�� ���� Ȯ��" << endl;
	cout << "3. Ŀ�� �԰� �ϱ�" << endl;
	cout << "4. �����ϱ�" << endl;
	cout << "=====================" << endl;
}

void coffe_list() {			//Ŀ���� ��Ȳ�� ����Ѵ�.
	int i = 1;
	while (coffe[i] != "") {
		printf("%d.", i);
		cout << coffe[i] << endl;
		printf("  ����:%d    ���:%d\n\n", coffe_price[i], coffe_stock[i]);
		i++;
	}
}

void coffe_order() {
	int choice = 0, coffe_n;			//choice : Ŀ�Ǹ� ����, coffe_n : Ŀ���� ����

	while (choice != 9) {
		coffe_list();
		cout << "�����Ͻ� Ŀ���� ��ȣ�� �������ּ���. (�ڷΰ��÷��� 9���� ��������.)" << endl;
		cin >> choice;
		if (choice == 9) {
			break;
		}
		else if (coffe[choice] == "") {
			cout << "�ش�Ǵ� Ŀ�Ǵ� �����ϴ�." << endl << endl;
			continue;
		}
		cout << "��� �ֹ��Ͻðڽ��ϱ�?" << endl;
		cin >> coffe_n;
		while (coffe_stock[choice] < coffe_n) {
			cout << "�˼��մϴ�. Ŀ���� ������ �����մϴ�. ������ �������ּ���" << endl;
			cin >> coffe_n;
		}
		coffe_stock[choice] -= coffe_n;						//Ŀ���� ��� ����
		coffe_s[choice] += coffe_price[choice] * coffe_n;	//Ŀ���� ���� ���ϱ�
		cout << "�� �ֹ� �Ͻðڽ��ϱ�?" << endl;
	}

	return;
}

void coffe_sales() {
	int total_sale = 0, i = 1;
	while (coffe[i] != "") {
		cout << coffe[i];
		printf("	���� : %d\n", coffe_s[i]);
		i++;
	}
	printf("�� ���� : %d\n", total_sale);
}

void coffe_plus() {
	int choice = 0, coffe_n;

	while (choice != 9) {
		coffe_list();
		cout << "�԰��Ͻ� Ŀ���� ��ȣ�� �������ּ���. (�ڷΰ��÷��� 9���� ��������.)" << endl;
		cin >> choice;
		if (choice == 9)
			break;
		else if (coffe[choice] == "") {
			cout << "�ش�Ǵ� Ŀ�Ǵ� �����ϴ�." << endl << endl;
			continue;
		}
		cout << "��� �԰��Ͻðڽ��ϱ�?" << endl;
		cin >> coffe_n;
		coffe_stock[choice] += coffe_n;
		cout << "�� �԰��Ͻðڽ��ϱ�?" << endl;
	}
	return;
}
int main() {
	coffe_set();		//Ŀ�� ����Ʈ�� �̸� �����Ѵ�.
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