# ChineseToPinyin
汉字转拼音 自适应多音字处理 姓名自动切分 c++开源代码

// === V2.0 === //
更新提要：
	V2.0 2020年04月10日：
	1. 更新纯c++版本，主要使用wstring实现
	2. 删除字库中的: ','
	3. 更改汉字判断规则，详情看isHanziChar();
    4. 具体使用说明看示例代码即可（main.cpp）
    5. 对文字的编码方式要求降低，并且可自行配置,详情看：isHanziChar() 这个方法内部有说明
    5. 文件夹说明：
        wstring版本 => V2.0, 纯c++版本 ， 平台移植方便
        qstring版本 => V1.0, qt平台版本，
        

// === V1.0版本 === //
一.概要

1. 如标题所示，本项目的功能很明显
2. 对外输出的函数有三个

   getComPingyinForStr(inFull,outFristPy,outFullPy);              // 获取输入姓名对应拼音的所有排列
   
   myNameSplit(inFull,outFristPy,outFullPy);                      // 自动切分：姓、名
   
   QString getNamePingyin(const QString& inStr, bool isLastName); // 获取唯一的拼音（自动识别多音字）
 
   
二.详情

   适用场景、运行效果、代码原理、思路、注意事项 请看博文
   
   https://blog.csdn.net/weixin_38887369/article/details/91047524   // 本开源项目介绍
   
   https://blog.csdn.net/weixin_38887369                            // 我的主页
   
三.使用的简单实例

0. 本代码使用了Qt ,但只使用了 qstring、 qstringlist、 qvector，如果你不想使用qt,直接使用标准的c++也可，
   只需要做很少的改动，代码内部会说明改的思路，其实直接使用c++的标准库效率更高，我之所以使用Qt是因为项目的关系。
   如果下载量多，我会修改成标准的c++版本（不使用任何其他的库），这样移植起来更方便些。

1. 获取输入姓名对应拼音的所有排列（列表搜索时使用），就一个函数，后面的注释就是运行结果，使用很简单。
   速度粗糙大概估计（win10系统 + i5-8265U + 单线程下 + 每人3个字 => 50人/毫秒）。
   因为并不确定用户输入的拼音是那个，所以要输出所有的拼音组合。
   
   getComPingyinForStr("解红",fristPy,fullPy); 
   // fristPy =  "jg xg jh xh"  , fullPy =  "jiegong xiegong jiehong xiehong"
   
   getComPingyinForStr("查查",fristPy,fullPy);    
   // fristPy =  "cc zc cz zz"  , fullPy =  "chacha zhacha chazha zhazha"
   
   getComPingyinForStr("尉迟萌",fristPy,fullPy);  
   // fristPy =  "wcm ycm"  , fullPy =  "weichimeng yuchimeng"
   
   getComPingyinForStr("李石",fristPy,fullPy);    
   // fristPy =  "ld ls"  , fullPy =  "lidan lishi"
   
   getComPingyinForStr("小明",fristPy,fullPy);    
   // fristPy =  "xm"  , fullPy =  "xiaoming"
   
2. 获取输入姓名的拼音（唯一的），和上面的区别就相当于，在所有的拼音组合中选择本算法认为最正确的一个。（100人/毫秒）
   
   因为一个多音字在做 {姓、名}  时可能会有不同的读音。
   
   一共有两个函数 myNameSplit(...）getNamePingyin(...)  ,使用方法很明显。
   
QString names = { "东皇太一 尉迟小白 解波 卜艾 颜碧玉 句帅 杨红给 吕布 亚里士多缺德 覃黄埔 菊花拉姆 上官万" };

QStringList nameList = names.split(" ");   

for (size_t i = 0; i < nameList.size(); i++)

{

  QString full, fist, last;
  
  full = nameList[i];

  myNameSplit(full, last, fist);     // 自动切分 [姓、名]
  
  last = getNamePingyin(last, true); // 获取 [姓] 的拼音
  
  fist = getNamePingyin(fist, false);// 获取 [名] 的拼音

  qout << full + " : " + last + "  " + fist << endl;
  
}

// 运行结果

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

*注意：qout => #define qout qDebug()
	
三.总结

1. 如果你有更好的想法或改进的建议，请告诉我。
2. 如果使用的人多，反馈的优化想法多，我会持久的更新，并且推出跨平台版本（纯c++版本，方便移植）。
3. 原创不易，转载注明。 
4. 版本：V1.0   日期：2019年06月06日  
5. 版权所有 qq:2271590144,新月
4. 使用语言:c++,使用库：qt

