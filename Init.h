#pragma once
#include<algorithm>
#include"snap7.h"
#include"DataStructure.h"
#include "Tools.h"

struct MessagePLC
{
	std::string address; // PLC��ַ
	int Rack;   // ����
	int Solt;   // �ۺ�
};
struct DataBlock {
	std::string area; // DB��M��I��Q
	int blockNum;  // ���
	int startOffset;  // ��ʼƫ����
	int endOffset;  // ����ƫ����
	// pair<pair<ƫ������λƫ����>��������>
	// std::vector<std::pair<std::pair<int, int>, std::string>> BlockData;
	unsigned char buffer[2][210]; // ������
};

class Init {

public:

	static Init* GetInstance(); // ��ȡ��������ָ��
	void deleteInstance();  // ɾ��ָ�����
	void InitPLCData(MessagePLC* myPLC, std::map<std::string, DataInform>& data);  // ��ʼ��PLC����
	void InitTargetData();  // ��ʼ��Ŀ������
	// ��ַ�������
	static bool compare(const std::pair<std::string, DataInform>& a, const std::pair<std::string, DataInform>& b);
	std::string ReadDataRegion(std::string address, std::string type, int size);  // �������ݶ�ȡ
	// ���ݲ�ͬ�����ȡ����
	void DataRead(std::string area, int dbNumber, int offset, int size, unsigned char* buffer);  
	std::string BinaryConversionOther(unsigned char* buffer, std::string type, int offset);  // ��������
	// �����������ַ������
	std::vector<DataBlock> createBlocks(const std::vector<std::pair<std::string, DataInform>>& sortedData);
	// ��ѯ����
	void ReadDataInform(std::vector<DataBlock> blocks, std::map<std::string, DataInform> dataInform);
	//std::vector<std::vector<DataBlock>> splitBlocks(std::vector<DataBlock> blocks, int maxThreadNum); // �ָ��
	//void ReadBlockData(DataBlock block);  // �����ݶ�ȡ
	//void ReadMoreBlockData(std::vector<DataBlock> blocks);

	MessagePLC* plc;  // plc��Ϣ
	TS7Client* myClient;  // snap7�ͻ���
	std::vector<DataBlock> blocks;  // �ָ���Ŀ�
	std::map<std::string, DataInform> dataInform;    // ������Ϣ
	std::map<std::string, std::string> FinalData;    // ��ǰ����ֵ
	// std::vector<std::vector<DataBlock>> sBlocks;

private:
	Init();
	~Init();
	// ��ֹ�ⲿ��������
	Init(const Init& single) = delete;
	// ��ֹ�ⲿ��ֵ����
	const Init& operator=(const Init& single) = delete;

private:
	static Init* g_pInit;
};
