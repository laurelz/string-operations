#include<iostream>
using namespace std;

// 找出字符串中第一个只出现一次的字符
// 考虑使用哈希表来存储每个字符出现的次数
// 再按字符串中字符出现的顺序遍历该哈希表
// 第一个次数为1的元素即为所求字符
char firstNotRepeatingChar(char* pstring) {
	if (pstring == NULL)
		return '\0';
	// 字符（char）是一个长度为8的类型
	// 因此有256种可能，哈希表的大小为256
	// 以字符的ASCII码值作为Key，次数为Value
    const int tableSize = 256;
	unsigned int hashTable[tableSize];
	// 首先初始化所有哈希表的元素值为0
	for(unsigned int i = 0;i < tableSize; ++i) {
	    hashTable[i] = 0;
	}

	// 将字符串中的字符次数存入哈希表
	char* phashkey = pstring;
	while(*phashkey != '\0') {
	    hashTable[*(phashkey)++] ++;
	}

	// 按照字符串中的字符出现书需遍历哈希表
	// 返回第一个value为1的字符
	phashkey = pstring;
	while(*phashkey != '\0') {
	    if (hashTable[*phashkey] == 1)
		    return *phashkey;
		phashkey++;
	}
	return '\0';
}
int main(){
    char str[] = {"abaccdeff"};
	cout<<firstNotRepeatingChar(str)<<endl;
}
