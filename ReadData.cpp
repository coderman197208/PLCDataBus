#include "Init.h"
#include "ThreadPool.h"

extern bool bExit;

int main() {

	//PLCConnection plc = PLCConnection("140.32.1.141",0,1);
	//bool i = plc.ConnectPLC();
	//std::cout << i << std::endl;
	//return 0;
	int ThreadNum = 3;
	ThreadPool pool(ThreadNum);
	Init* init = new Init(); // һ��profile�ļ���Ӧһ��Init����

	//init->Run("testprofile.txt");

	pool.enqueue(&Init::Run, init, std::ref("testprofile.txt"));
	//pool.enqueue(&Tools::CheckForEscExit);
	//pool.enqueue(&Init::InquireData, init);

	while (1) {

		if (_kbhit()) { // ����Ƿ��а�������
			char key = _getch(); // ��ȡ���µļ�
			if (key == 27) { // 27 �� Esc ���� ASCII ��
				//std::cout << "��⵽ Esc �����˳�����" << std::endl;
				//exit(0); // �˳�����
				bExit = true;
				Sleep(2000);
				break;
			}
		}
	}

	delete init;

	return 0;
}