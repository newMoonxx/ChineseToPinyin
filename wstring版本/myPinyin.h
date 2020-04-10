/*
0. ¹¦ÄÜ°üÀ¨£º×Ô¶¯·ÖÀëĞÕÃûÖĞµÄ[ĞÕ,Ãû]£»ĞÕÃû×ªÆ´Òô£¨Ò»¶ÔÒ»£¬Ê××ÖÄ¸+È«Æ´Òô£©£»ĞÕÃû×ªÆ´Òô£¨Ò»¶Ô¶à£¬Ê××ÖÄ¸+È«Æ´Òô£©
1. °æ±¾£ºV1.0   ÈÕÆÚ£º2019Äê06ÔÂ06ÈÕ
2. ÏêÇé£º
	https://blog.csdn.net/weixin_38887369/article/details/91047524   // ±¾¿ªÔ´ÏîÄ¿½éÉÜ
	https://blog.csdn.net/weixin_38887369                            // 
3. °æÈ¨ËùÓĞ qq:2271590144,ĞÂÔÂ
4. Ê¹ÓÃÓïÑÔ:c++,Ê¹ÓÃ¿â£ºqt
5. qt¿âÖ»Ê¹ÓÃÁË qstring qstringlist qvector£¬Èç¹ûÄã²»ÏëÊ¹ÓÃqt,Ö±½ÓÊ¹ÓÃ±ê×¼µÄc++Ò²¿É£¬Ö»ĞèÒª×öºÜÉÙµÄ¸Ä¶¯
   Èç¹ûÊ¹ÓÃ±ê×¼µÄc++¿â,¸Ä¶¯ÈçÏÂ£º
   qstring     -> string
   qstringlist -> vector<string>
   qvector     -> vector
   a. cppÎÄ¼şÖĞµÄ´úÂë¾Í300ĞĞ×óÓÒ,ËùÒÔ¸Ä¶¯²»¶à
   b. [vector,qvector],[string,qstring] µÄÏàËÆ¶È¼«¸ß£¬ºÜ¶àº¯Êı¶¼ÊÇÒ»ÑùµÄ£¬ËùÒÔ¸ÄÆğÀ´Ò²ÈİÒ×
   c. Ê¹ÓÃ±ê×¼µÄstringĞ§ÂÊ»á¸ü¸ß
6. Êµ¼ÊÔËÓÃ²âÊÔ£º
	a. ÒÑ¾­ÉÌÓÃ£¬Ã»Ê²Ã´ÎÊÌâ
	b. ËÙ¶È²âÊÔ£¬»·¾³£ºwin10ÏµÍ³ + i5-8265U + µ¥Ïß³ÌÏÂ + Ã¿ÈË3¸ö×Ö £¬ºÜ´Ö²ÚµÄËÙ¶È²âÊÔ½á¹ûÈçÏÂ
	   getComPingyinForStr() => 50 ÈË/ms
	   getNamePingyin()      => 100ÈË/ms
7. Ê¹ÓÃ·½·¨£º¿ÉÒÔÖ±½Ó¿´±¾ÎÄ¼ş£¨.hÎÄ¼ş£©µÄ×¢ÊÍ »ò ½øÈëÏêÇéÒ³Ãæ¿ª£¬¼ûµÚ¶şÌõµÄÍøÖ· 

¸üĞÂ£º
	V2.0 2020Äê04ÔÂ10ÈÕ£º
	1. ¸üĞÂc++°æ±¾£¬Ö÷ÒªÊ¹ÓÃwstring
	2. É¾³ı×Ö¿âÖĞµÄ: ','
	3. ¸ü¸Äºº×ÖÅĞ¶Ï¹æÔò£¬ÏêÇé¿´isHanziChar(wchar_t wch);
*/
#pragma once

#include <string>
#include <vector>
using namespace std;


// ----- Íâ²¿Ê¹ÓÃ ----- //
/* 
0. »ñÈ¡×éºÏÆ´Òô(Ò»¿ÉÄÜ¶Ô¶à),ÓÃÓÚËÑË÷
1. eg: 
	getComPingyinForStr("½âºì",fristPy,fullPy);    // fristPy =  "jg xg jh xh"  , fullPy =  "jiegong xiegong jiehong xiehong"
	getComPingyinForStr("²é²é",fristPy,fullPy);    // fristPy =  "cc zc cz zz"  , fullPy =  "chacha zhacha chazha zhazha"
	getComPingyinForStr("Î¾³ÙÃÈ",fristPy,fullPy);  // fristPy =  "wcm ycm"  , fullPy =  "weichimeng yuchimeng"
	getComPingyinForStr("ÀîÊ¯",fristPy,fullPy);    // fristPy =  "ld ls"  , fullPy =  "lidan lishi"
	getComPingyinForStr("Ğ¡Ã÷",fristPy,fullPy);    // fristPy =  "xm"  , fullPy =  "xiaoming"
*/
int getComPingyinForStr(const wstring& inStr, wstring& outFrist_py, wstring& outFull_py);//ok
/*
0. ¡¾ĞÕ¡¢Ãû¡¿·Ö±ğ×ªÆ´Òô£¨ÑÏ¸ñµÄÒ»Ò»¶ÔÓ¦£©£¬ÓÃÓÚºº×ÖÇ¿×ªÆ´Òô
1. Ê¹ÓÃÁË£ºĞÕÊÏÌØÊâ¶ÁÒô×Ö¿â + ¶àÒô×Ö³£ÓÃ¶ÁÒô×Ö¿â + È«×Ö¿â
2. eg:
	str = getNamePingyin("´º",true);   // str => "chun"
	str = getNamePingyin("´º",false);  // str => "chun"
	
	str = getNamePingyin("½â",true);   // str => "xie"
	str = getNamePingyin("½â",false);  // str => "jie"
	
	str = getNamePingyin("µÔ",true);   // str => "zhai"
	str = getNamePingyin("µÔ",false);  // str => "di"

	str = getNamePingyin("²Î",true);   // str => "can"
	str = getNamePingyin("²Î",false);  // str => "can"

	str = getNamePingyin("µ¥ÓÚ",true);   // str => "chanyu"
	str = getNamePingyin("µ¥ÓÚ",false);  // str => "danyu"
*/
wstring getNamePingyin(const wstring& inStr, bool isLastName);//ok
/*
0. ×Ô¶¯ÇĞ·Ö ĞÕ¡¢Ãû
1. »ù±¾Ö»ÄÜÓ¦¶ÔÆÕÍ¨µÄ¸´ĞÕ£¨Á½¸ö×Ö£©£¬Èç¹ûÔÚ¸´ĞÕ±íÖĞÃ»ÓĞÕÒµ½£¬Ôò: ĞÕÊÏ = £¨fullName.size() == 4£© ? fullNameµÄÇ°Á½¸ö¸ö×Ö·û £º fullNameµÄµÚÒ»¸ö×Ö·û
2. ±¸×¢£º°Ù¶ÈµÄĞÕÊÏ»ù±¾¾Í70¶à¸ö£¬ÕâÀïÓĞ90¸ö£¬µ«ÊÇºöÂÔµÄÉÙÊıÃñ×åµÄĞÕÊÏ£¬Ò²²»ÒªÈÏÎª¸´ĞÕ¾ÍÊÇÁ½¸ö×Ö£¬(¡¶ÖĞ¹úÉÙÊıÃñ×åĞÕÊÏ¡·»ã×Ü´ó¸ÅÓĞ1Íò¶à)
   ÀıÈç£ºÎÚÀ­ÎÚÀ­ÊÏ¡¢°®ĞÂ¾õÂŞ¡¢Å¥îÜÂ»¡¢É«ÊÏ¡¢ÄáÂê£¨ÎÒ¼û¹ıºÜ¶àĞÕÕâ¸öµÄ£©
3. eg:
	wcout << L"ĞÕÃû²ğ·Ö²âÊÔ£º" << endl;
	wstring names[13] = { L"¶«»ÊÌ«Ò»", L"Î¾³ÙĞ¡°×", L"½â²¨", L"²·°¬", L"ÑÕ±ÌÓñ", L"¾äË§", L"Ñîºì¸ø", L"ÂÀ²¼", L"ÑÇÀïÊ¿¶àÈ±µÂ", L"ñû»ÆÆÒ", L"¾Õ»¨À­Ä·", L"ÉÏ¹ÙÍò", L"mack" };
	for (size_t i = 0; i < 13; i++)
	{
		wstring full, fist, last;
		full = names[i];
		myNameSplit(full, last, fist);
		wcout << full <<  L" => ĞÕ:" << last  <<L" ,Ãû:" << fist << endl;
	}

	// ½á¹û
	ĞÕÃû²ğ·Ö²âÊÔ£º
	¶«»ÊÌ«Ò»	 => ĞÕ:¶«»Ê ,Ãû:Ì«Ò»
	Î¾³ÙĞ¡°×	 => ĞÕ:Î¾³Ù ,Ãû:Ğ¡°×
	½â²¨		 => ĞÕ:½â   ,Ãû:²¨
	²·°¬		 => ĞÕ:²·   ,Ãû:°¬
	ÑÕ±ÌÓñ		 => ĞÕ:ÑÕ   ,Ãû:±ÌÓñ
	¾äË§		 => ĞÕ:¾ä   ,Ãû:Ë§
	Ñîºì¸ø		 => ĞÕ:Ñî   ,Ãû:ºì¸ø
	ÂÀ²¼         => ĞÕ:ÂÀ   ,Ãû:²¼
	ÑÇÀïÊ¿¶àÈ±µÂ => ĞÕ:ÑÇ   ,Ãû:ÀïÊ¿¶àÈ±µÂ
	ñû»ÆÆÒ		 => ĞÕ:ñû   ,Ãû:»ÆÆÒ
	¾Õ»¨À­Ä·     => ĞÕ:¾Õ»¨ ,Ãû:À­Ä·
	ÉÏ¹ÙÍò       => ĞÕ:ÉÏ¹Ù ,Ãû:Íò
	mack         => ĞÕ:     ,Ãû:mack
*/
void myNameSplit(const wstring& inFullName, wstring& outLastName, wstring& outFirstName);//ok


// ----- ÄÚ²¿²¿Ê¹ÓÃ ----- //
/*
0. »ñÈ¡Ò»¸öºº×ÖµÄ¡¾ËùÓĞ¡¿Æ´Òô(Ê××ÖÄ¸¡¢È«Æ´)
1. Ê¹ÓÃ×Ö¿â £º hanziTables[]
2. Êä³ö²»»áÎª¿Õ£¬³ı·ÇÊäÈë¾ÍµÈÓÚ¿Õ
3. Èç¹ûÊäÈëÎª·ÇÖĞÎÄ×Ö·û£¬Ôò·µ»ØºÍÊäÈëÒ»Ñù
4. inWord Ö»ÄÜÊäÈëÒ»¸öºº×Ö£¬·ñÔò·µ»Ø-1
5. eg:
   getAllPingyinForWord("¾ä",fristPy,fullPy); // fristPy => {"g","j"} , fullPy => {"gou","ju"}
   getAllPingyinForWord("Áú",fristPy,fullPy); // fristPy => {"l"}     , fullPy => {"long"}
*/
int getAllPingyinForWord(const wstring& inWord, vector<wstring>& outFrist_py, vector<wstring>& outFull_py); 
/*
0. »ñÈ¡Ò»¸ö×ÖµÄÆ´Òô,Èç¹ûÊÇ¶àÒô×Ö·µ»Ø³£ÓÃ¶ÁÒô
1. Æ«ÏòÓÚÃûµÄ·¢ÒôÆ«ºÃ,¶ø²»ÊÇĞÕÊÏµÄ·¢ÒôÆ«ºÃ
2. Êä³ö²»»áÎª¿Õ£¬³ı·ÇÊäÈë¾ÍµÈÓÚ¿Õ
3. Ê¹ÓÃ×Ö¿â£ºmultiToneWordTable[]£¨¶àÒô×Ö¿â£©+ hanziTables[]£¨È«×Ö¿â£©
4. Èç¹ûÊäÈëÎª·ÇÖĞÎÄ×Ö·û£¬Ôò·µ»ØºÍÊäÈëÒ»Ñù
5. ¶àÒô×ÖµÄÈ¡Éá¹æÔò¼û£ºmultiToneWordTable[]
6. inWord Ö»ÄÜÊäÈëÒ»¸öºº×Ö£¬·ñÔòÖ±½Ó·Å»ØÊäÈëÄÚÈİ
7. eg:
   str = getNoRepeatPingyinForWord("´ó"); // str => "da"
   str = getNoRepeatPingyinForWord("½â"); // str => "jie"
   str = getNoRepeatPingyinForWord("Ê¯"); // str => "shi"
*/
wstring getNoRepeatPingyinForWord(const wstring& inWord);
/* 
0. ¼ì²éÊÇ·ñÊÇºº×Ö
1. ²»Í¬µÄ±àÂë·½Ê½¡¢IDE£¬¿ÉÄÜĞèÒª²»Í¬µÄÉèÖÃÖµ
*/
bool isHanziChar(wchar_t wch);
/* 
0. ²âÊÔ±¾×Ö¿âÔÚ±¾»·¾³ÏÂÔËĞĞÊ±µÄºº×ÖµÄ±àÂëÖµ
*/
void testHanziRang();