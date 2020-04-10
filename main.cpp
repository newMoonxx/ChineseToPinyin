#include <iostream>
#include <string>
using namespace std;
#include "myPinyin.h"

int main()
{
	// wcout 设置
	wcout.imbue(locale("chs"));
	setlocale(LC_ALL, "");  
	

	// 一对多, 用于搜索自动匹配
	if (true)
	{
		wcout << L"一对多, 用于搜索自动匹配:" << endl;

		wstring fristPy, fullPy;
		getComPingyinForStr(L"解红", fristPy, fullPy);    // fristPy =  "jg xg jh xh"  , fullPy =  "jiegong xiegong jiehong xiehong"
		wcout << L"解红:" << fristPy << L" , " << fullPy << endl;
		getComPingyinForStr(L"查查", fristPy, fullPy);    // fristPy =  "cc zc cz zz"  , fullPy =  "chacha zhacha chazha zhazha"
		wcout << L"查查:" << fristPy << L" , " << fullPy << endl;
		getComPingyinForStr(L"尉迟萌", fristPy, fullPy);  // fristPy =  "wcm ycm"  , fullPy =  "weichimeng yuchimeng"
		wcout << L"尉迟萌:" << fristPy << L" , " << fullPy << endl;
		getComPingyinForStr(L"李石", fristPy, fullPy);    // fristPy =  "ld ls"  , fullPy =  "lidan lishi"
		wcout << L"李石:" << fristPy << L" , " << fullPy << endl;
		getComPingyinForStr(L"小明", fristPy, fullPy);    // fristPy =  "xm"  , fullPy =  "xiaoming"
		wcout << L"小明:" << fristPy << L" , " << fullPy << endl;

		wcout << endl << endl;
	}
	// 一对一, 用于汉字强转拼音(姓、名的发音有不同的偏好)
	if (true)
	{ 
		wstring str;
		str = getNamePingyin(L"春", true);   // str => "chun"
		str = getNamePingyin(L"春", false);  // str => "chun"

		str = getNamePingyin(L"解", true);   // str => "xie"
		str = getNamePingyin(L"解", false);  // str => "jie"

		str = getNamePingyin(L"翟", true);   // str => "zhai"
		str = getNamePingyin(L"翟", false);  // str => "di"

		str = getNamePingyin(L"参", true);   // str => "can"
		str = getNamePingyin(L"参", false);  // str => "can"

		str = getNamePingyin(L"单于", true);   // str => "chanyu"
		str = getNamePingyin(L"单于", false);  // str => "danyu"
	}
	// 姓氏自动拆分
	if (true)
	{
		wcout << L"姓名拆分测试(最佳输出)：" << endl;
		wstring names[13] = { L"东皇太一", L"尉迟小白", L"解波", L"卜艾", L"颜碧玉", L"句帅", L"杨红给", L"吕布", L"亚里士多缺德", L"覃黄埔", L"菊花拉姆", L"上官万", L"mack" };
		for (size_t i = 0; i < 13; i++)
		{
			wstring fullName, fistName, lastName;
			wstring fistNamePy, lastNamePy;
			fullName = names[i];
			
			// 先拆分
			myNameSplit(fullName, lastName, fistName);  
			// 再分别计算
			lastNamePy = getNamePingyin(lastName,true);
			fistNamePy = getNamePingyin(fistName,false);

			wcout << fullName << L" => 姓:" << lastName << L"[" << lastNamePy << L"]" << L" ,名:" << fistName << L"[" << fistNamePy << L"]" << endl;
		}
	}
	
	// 汉字编码测试
	if (true)
	{
		testHanziRang();
	}


}
