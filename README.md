# -
汉字转拼音 自适应多音字处理 姓名自动切分 c++开源代码

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
