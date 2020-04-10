/*
0. 功能包括：自动分离姓名中的[姓,名]；姓名转拼音（一对一，首字母+全拼音）；姓名转拼音（一对多，首字母+全拼音）
1. 版本：V1.0   日期：2019年06月06日
2. 详情：
	https://blog.csdn.net/weixin_38887369/article/details/91047524   // 本开源项目介绍
	https://blog.csdn.net/weixin_38887369                            // 
3. 版权所有 qq:2271590144,新月
4. 使用语言:c++,使用库：qt
5. qt库只使用了 qstring qstringlist qvector，如果你不想使用qt,直接使用标准的c++也可，只需要做很少的改动
   如果使用标准的c++库,改动如下：
   qstring     -> string
   qstringlist -> vector<string>
   qvector     -> vector
   a. cpp文件中的代码就300行左右,所以改动不多
   b. [vector,qvector],[string,qstring] 的相似度极高，很多函数都是一样的，所以改起来也容易
   c. 使用标准的string效率会更高
6. 实际运用测试：
	a. 已经商用，没什么问题
	b. 速度测试，环境：win10系统 + i5-8265U + 单线程下 + 每人3个字 ，很粗糙的速度测试结果如下
	   getComPingyinForStr() => 50 人/ms
	   getNamePingyin()      => 100人/ms
7. 使用方法：可以直接看本文件（.h文件）的注释 或 进入详情页面开，见第二条的网址 
*/
#pragma once

#include <qstring.h>
#include <qstringlist.h>
#include <qvector.h>


/*
0. vs2017的默认编码不是utf-8，如果在qt的IDE编辑不需要这句；如果在vs上开发并且不用qt,也不需要这句
1. 我是在vs2017上使用qt, 如果没有这句，则QString str="哈哈"; str会是乱码的
2. 如果你要使用CString ,则自己脑部...
*/
#pragma execution_character_set("utf-8") // 

// 汉字-拼音
struct hanziTableS
{
	// 拼音
	QString first_py;  // 首字母
	QString full_py;   // 全拼

	// 汉字
	QString hanzis;
};

// 特殊姓氏发音
struct lastNameTableS
{
	QString hanzi;
	QString pinyi;
};

// 常用多音字
struct multiToneWordTableS
{
	QString hanzi;
	QString pinyi;
};


// ----- 外部使用 ----- //

/* 
0. 获取组合拼音(一可能对多),用于搜索
1. eg: 
	getComPingyinForStr("解红",fristPy,fullPy);    // fristPy =  "jg xg jh xh"  , fullPy =  "jiegong xiegong jiehong xiehong"
	getComPingyinForStr("查查",fristPy,fullPy);    // fristPy =  "cc zc cz zz"  , fullPy =  "chacha zhacha chazha zhazha"
	getComPingyinForStr("尉迟萌",fristPy,fullPy);  // fristPy =  "wcm ycm"  , fullPy =  "weichimeng yuchimeng"
	getComPingyinForStr("李石",fristPy,fullPy);    // fristPy =  "ld ls"  , fullPy =  "lidan lishi"
	getComPingyinForStr("小明",fristPy,fullPy);    // fristPy =  "xm"  , fullPy =  "xiaoming"
*/
int getComPingyinForStr(const QString& inStr, QString& outFrist_py, QString& outFull_py);//ok
/*
0. 【姓、名】分别转拼音（严格的一一对应），用于汉字强转拼音
1. 使用了：姓氏特殊读音字库 + 多音字常用读音字库 + 全字库
2. eg:
	str = getNamePingyin("春",true);   // str => "chun"
	str = getNamePingyin("春",false);  // str => "chun"
	
	str = getNamePingyin("解",true);   // str => "xie"
	str = getNamePingyin("解",false);  // str => "jie"
	
	str = getNamePingyin("翟",true);   // str => "zhai"
	str = getNamePingyin("翟",false);  // str => "di"

	str = getNamePingyin("参",true);   // str => "can"
	str = getNamePingyin("参",false);  // str => "can"

	str = getNamePingyin("单于",true);   // str => "chanyu"
	str = getNamePingyin("单于",false);  // str => "danyu"
*/
QString getNamePingyin(const QString& inStr, bool isLastName);//
/*
0. 自动切分 姓、名
1. 基本只能应对普通的复姓（两个字），如果在复姓表中没有找到，则: 姓氏 = （fullName.size() == 4） ? fullName的前两个个字符 ： fullName的第一个字符
2. 备注：百度的姓氏基本就70多个，这里有90个，但是忽略的少数民族的姓氏，也不要认为复姓就是两个字，(《中国少数民族姓氏》汇总大概有1万多)
   例如：乌拉乌拉氏、爱新觉罗、钮钴禄、色氏、尼玛（我见过很多姓这个的）
3. eg:
	QString names = {"东皇太一 尉迟小白 解波 卜艾 颜碧玉 句帅 杨红给 吕布 亚里士多缺德 覃黄埔 菊花拉姆 上官万"};
	QStringList nameList = names.split(" ");
	for (size_t i = 0; i < nameList.size(); i++)
	{
		QString full, fist, last;
		full = nameList[i];

		myNameSplit(full, last, fist);
		last = getNamePingyin(last, true);
		fist = getNamePingyin(fist, false);

		qout << full + " : " + last + "  " + fist << endl;
	}
	// 结果
	"东皇太一 : donghuang  taiyi"
	"尉迟小白 : yuchi  xiaobai"
	"解波 : xie  bo"
	"卜艾 : bu  ai"
	"颜碧玉 : yan  biyu"
	"句帅 : gou  shuai"
	"杨红给 : yang  honggei"
	"吕布 : lv  bu"
	"亚里士多缺德 : ya  lishiduoquede"
	"覃黄埔 : qin  huangpu"
	"菊花拉姆 : juhua  lamu"
	"上官万 : shangguan  wan"
*/
void myNameSplit(const QString& inFullName, QString& outLastName, QString& outFirstName);


// ----- 内部部使用 ----- //

/*
0. 获取一个汉字的【所有】拼音(首字母、全拼)
1. 使用字库 ： hanziTables[]
2. 输出不会为空，除非输入就等于空
3. 如果输入为非中文字符，则返回和输入一样
4. inWord 只能输入一个汉字，否则返回-1
5. eg:
   getAllPingyinForWord("句",fristPy,fullPy); // fristPy => {"g","j"} , fullPy => {"gou","ju"}
   getAllPingyinForWord("龙",fristPy,fullPy); // fristPy => {"l"}     , fullPy => {"long"}
*/
int getAllPingyinForWord(const QString& inWord, QStringList& outFrist_py, QStringList& outFull_py); // ok

/*
0. 获取一个字的拼音,如果是多音字返回常用读音
1. 偏向于名的发音偏好,而不是姓氏的发音偏好
2. 输出不会为空，除非输入就等于空
3. 使用字库：multiToneWordTable[]（多音字库）+ hanziTables[]（全字库）
4. 如果输入为非中文字符，则返回和输入一样
5. 多音字的取舍规则见：multiToneWordTable[]
6. inWord 只能输入一个汉字，否则直接放回输入内容
7. eg:
   str = getNoRepeatPingyinForWord("大"); // str => "da"
   str = getNoRepeatPingyinForWord("解"); // str => "jie"
   str = getNoRepeatPingyinForWord("石"); // str => "shi"
*/
QString getNoRepeatPingyinForWord(const QString& inWord);//ok