#include "Init.h"
#include "ThreadPool.h"

int main() {

	int ThreadNum = 3;
	ThreadPool pool(ThreadNum);
	Init* init = new Init(); // һ��profile�ļ���Ӧһ��Init����

	pool.enqueue(&Init::Run, init, std::ref("testprofile.txt"));
	pool.enqueue(&Tools::CheckForEscExit);
	//pool.enqueue(&Init::InquireData, init);

	return 0;
}