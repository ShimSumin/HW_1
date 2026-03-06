#include <iostream>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion);
int StatSystem(int n, int* status[], int* p_HP, int* p_MP,int* Level);
void UpPotion(int count, int* p_HPPotion, int* p_MPPotion);

int main() 
{
	int HP = 0;
	int MP = 0;
	int attack = 0;
	int defense = 0;
	int* status[4] = { &HP, &MP,&attack,&defense };
	int number = 0;
	int HPPotion = 0;
	int MPPotion = 0;
	int Level = 0;
	
	while (true)
	{	cout << " HP와 MP를 입력해주세요 : " ;
		cin >> HP >> MP;
	
		if (HP > 50 && MP > 50) {
			cout << endl;
			while (true) {
				cout << "공격력과 방어력을 입력해 주세요 : ";
				cin >> attack >> defense;
				if (attack > 0 && defense > 0) {
					break;
				}
				else
				{
					cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력 하십시오.\n\n";
				}
			}
			break;
		}
		else
			cout << " HP나 MP의 값이 너무 작습니다. 다시 입력 하십시오.\n\n";

	}

	setPotion(5, &HPPotion, &MPPotion);
	cout << endl << "* 포션이 지급되었습니다 ( HP, MP 포션 각 5개 )\n";

	while (true)
	{
		cout <<"============================" << endl
			<< "<스탯 관리 시스템>" << endl
			<< "1. HP UP" << endl
			<< "2. MP UP" << endl
			<< "3. 공격력 UP" << endl
			<< "4. 방어력 UP" << endl
			<< "5. 현재 능력치" << endl
			<< "6. Level Up" << endl
			<< "0. 나가기" << endl
			<< "번호를 선택해주세요 : ";
		cin >> number;
		cout << "============================" << endl<<endl;

		StatSystem(number, status, &HPPotion, &MPPotion,&Level);

		if (number == 0)
			break;

	}
}

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	* p_HPPotion = count;
	* p_MPPotion = count;
}
void UpPotion(int count, int* p_HPPotion, int* p_MPPotion) {
	*p_HPPotion += count;
	*p_MPPotion += count;
}

int StatSystem(int n, int* status[], int* p_HP, int* p_MP,int*Level) {
	
	switch (n) {

	case 1:
		if (*p_HP <= 0)
		{
			cout << "포션이 부족합니다." << endl;
			cout << "현재 HP : " << *status[0]
				<< endl << "남은 HP 포션 수 : " << *p_HP << endl<<endl;
			break;
		}
		else {
			cout << "* HP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
			*status[0] += 20;
			(*p_HP)--;
			cout << "현재 HP : " << *status[0]
				<< endl << "남은 HP 포션 수 : " << *p_HP << endl<<endl;
			break;
		}
		
	case 2:
		if (*p_MP <= 0)
		{
			cout << "포션이 부족합니다." << endl;
			cout << "현재 MP : " << *status[1]
				<< endl << "남은 MP 포션 수 : " << *p_MP << endl<<endl;
			break;
		}
		else {
			cout << "* MP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
			*status[1] += 20;
			--*p_MP;
			cout << "현재 MP : " << *status[1]
				<< endl << "남은 MP 포션 수 : " << *p_MP << endl<<endl;
			break;
		}

	case 3:
		cout << "* 공격력이 2배로 증가되었습니다. " << endl;
		*status[2] *= 2;
		cout << "현재 공격력: " << *status[2] << endl<<endl;
		break;

	case 4:
		cout << "* 방어력이 2배로 증가되었습니다. " << endl;
		*status[3] *= 2;
		cout << "현재 방어력: " << *status[3] << endl<<endl;
		break;

	case 5:
		cout << "* HP : " << *status[0]
			<< ", MP : " << *status[1]
			<< ", 공격력 : " << *status[2]
			<< ", 방어력 : " << *status[3]
			<< ", Level :" << *Level << endl
			<< "남은 HP 포션 수 : " << *p_HP << " 남은 MP 포션 수 : " << *p_MP
			<< endl<<endl;
		break;

	case 6:
		cout << "* 레벨 업 !! HP/MP 포션이 지급됩니다." << endl;
		UpPotion(1, p_HP, p_MP);
		(*Level)++;
		cout << "남은 HP/MP 포션 수 : " << *p_HP << "/" << *p_MP << endl
			<<"Level UP!\n현재 Level : "<<*Level<<endl<<endl;
		break;

	case 0:
		cout << "프로그램을 종료합니다.";
		break;
	}
	return 0;
}
