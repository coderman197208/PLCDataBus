#pragma once
#include "snap7.h"
#include <iostream>
#include "Tools.h"

class PLCConnection {
public:
	PLCConnection();
	PLCConnection(std::string, int rack, int solt);
	~PLCConnection();

	bool ConnectPLC();  // ����PLC����������״̬
	bool Disconnection();  // �Ͽ����ӷ��ز����Ƿ�ɹ�
	TS7Client* GetClient(); // ��ȡ�ͻ���

	// Set ����
	void SetAddress(std::string add);
	void SetRack(int rack);
	void SetSolt(int solt);

	// ��ȡ������
	std::string ReadDataRegion(std::string address, Area area, VARENUM type, int size);
	void DataRead(Area area, int dbNumber, int offset, int size, unsigned char* buffer);

private:
	TS7Client* myClient_;
	std::string address_; // PLC��ַ
	int rack_;   // ����
	int solt_;   // �ۺ�
};
