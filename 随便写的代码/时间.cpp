#include <iostream>
#include <time.h>

using namespace std;

int main()
{
 // ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
 time_t now = time(0);

 // �� now ת��Ϊ�ַ�����ʽ
 char* dt = ctime(&now);

 cout << "�������ں�ʱ�䣺" << dt << endl;

 // �� now ת��Ϊ tm �ṹ
 tm* gmtm = gmtime(&now);
 dt = asctime(gmtm);
 cout << "UTC ���ں�ʱ�䣺" << dt << endl;
}
