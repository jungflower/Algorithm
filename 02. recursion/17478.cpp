#include <iostream>
using namespace std;


void recursion(int n, string str){

    cout << str << "\"����Լ��� ������?\"\n";
    if(n==0){
        cout << str << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        cout << str << "��� �亯�Ͽ���.\n";
        return;
    }
    cout << str << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
    cout << str << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
    cout << str << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    recursion(n-1, str + "____");
    cout << str << "��� �亯�Ͽ���.\n";
    return ;
}

int main()
{
    int n;
    cin >> n;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    recursion(n, "");
    return 0;
}