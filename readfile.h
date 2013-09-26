#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//�������
void OutPutAnEmptyLine()
{
    cout<<"\n";
}

//��ȡ��ʽ: ��ʶ�ȡ, ��֮���ÿո�����
//read data from the file, Word By Word
//when used in this manner, we'll get space-delimited bits of text from the file
//but all of the whitespace that separated words (including newlines) was lost. 
void ReadDataFromFileWBW()
{
    ifstream fin("data.txt");  
    string s;  
    while( fin >> s ) 
    {    
        cout << "Read from file: " << s << endl;  
    }
}

//��ȡ��ʽ: ���ж�ȡ, ���ж����ַ�����, ��֮���ûس���������
//If we were interested in preserving whitespace, 
//we could read the file in Line-By-Line using the I/O getline() function.
void ReadDataFromFileLBLIntoCharArray()
{
    ifstream fin("data.txt"); 
    const int LINE_LENGTH = 100; 
    char str[LINE_LENGTH];  
    while( fin.getline(str,LINE_LENGTH) )
    {    
        cout << "Read from file: " << str << endl;
    }
}

//��ȡ��ʽ: ���ж�ȡ, ���ж����ַ���, ��֮���ûس���������
//If you want to avoid reading into character arrays, 
//you can use the C++ string getline() function to read lines into strings
void ReadDataFromFileLBLIntoString()
{
    ifstream fin("data.txt");  
    string s;  
    while( getline(fin,s) )
    {    
        cout << "Read from file: " << s << endl; 
    }
}

//��������Ķ�ȡ��ʽ
//Simply evaluating an I/O object in a boolean context will return false 
//if any errors have occurred
void ReadDataWithErrChecking()
{
    string filename = "dataFUNNY.txt";  
    ifstream fin( filename.c_str());  
    if( !fin ) 
    {   
        cout << "Error opening " << filename << " for input" << endl;   
        exit(-1);  
    }
}

//�ַ����ָ��
std::vector<std::string> split(std::string str,std::string pattern)
{
    std::string::size_type pos;
    std::vector<std::string> result;
    str += pattern;//��չ�ַ����Է������
    size_t size = str.size();

    for(size_t i = 0; i < size; i++)
    {
        pos=str.find(pattern,i);
        if(pos < size)
        {
            std::string s = str.substr(i, pos - i);
            result.push_back(s);
            i = pos+pattern.size() - 1;
        }
    }
    return result;
}

struct ReadData
{
	ReadData(void)
	{
		memset(config, 0, sizeof(config) / sizeof(unsigned int));
	}
	unsigned int config[3];

};

ReadData splitToInt(std::string str,std::string pattern)
{
    std::string::size_type pos;
    ReadData result;
    str += pattern;//��չ�ַ����Է������
    size_t size = str.size();

	int tmp(0);
    for(size_t i = 0; i < size; i++)
    {
        pos=str.find(pattern,i);
        if(pos < size && tmp < 3)
        {		
            std::string s = str.substr(i, pos - i);
            result.config[tmp++] = atoi(s.c_str());
            i = pos+pattern.size() - 1;
        }
    }
    return result;
}


//parse
std::vector<ReadData> parseInputFile(void)
{
	string filename = "data.txt";  
    ifstream fin( filename.c_str());  
    if(!fin) 
    {   
        cout << "Error opening " << filename << " for input" << endl;   
        exit(-1);  
    }
	 
	std::vector<ReadData> result;
	string s;  
    while(getline(fin,s))
    {    
        cout << "Read from file: " << s << endl; 
		result.push_back(splitToInt(s, "-"));
    }

	return result;
}

