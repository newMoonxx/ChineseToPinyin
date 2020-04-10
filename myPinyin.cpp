#include "myPinyin.h"

#define g_length_lastNameTable 554
#define g_length_multiToneWordTable 708
#define g_length_hanziTables 411

// ºº×Ö-Æ´Òô
struct hanziTableS
{
	// Æ´Òô
	wstring first_py;  // Ê××ÖÄ¸
	wstring full_py;   // È«Æ´

	// ºº×Ö
	wstring hanzis;
};

// ÌØÊâÐÕÊÏ·¢Òô
struct lastNameTableS
{
	wstring hanzi;
	wstring pinyi;
};

// ³£ÓÃ¶àÒô×Ö
struct multiToneWordTableS
{
	wstring hanzi;
	wstring pinyi;
};


/* 
0. ÐÕÊÏÌØÊâ¶ÁÒô(°üÀ¨£ºÌØÊâ¡¢·ÇÌØÊâ¡¢¸´ÐÕ¶ÁÒô)
1. ¿ÉÒÔ×Ô¼ºÌí¼Ó
3. À´Ô´ÓÚ¸÷ÖÖÍøÂçÊý¾ÝµÄÕûºÏ
*/
lastNameTableS lastNameTable[g_length_lastNameTable] =
{
{ L"ÕÔ" , L"zhao" },
{ L"Ç®" , L"qian" },
{ L"Ëï" , L"sun" },
{ L"Àî" , L"li" },
{ L"ÖÜ" , L"zhou" },
{ L"Îâ" , L"wu" },
{ L"Ö£" , L"zheng" },
{ L"Íõ" , L"wang" },
{ L"·ë" , L"feng" },
{ L"³Â" , L"chen" },
{ L"ñÒ" , L"chu" },
{ L"ÎÀ" , L"wei" },
{ L"½¯" , L"jiang" },
{ L"Éò" , L"shen" },
{ L"º«" , L"han" },
{ L"Ñî" , L"yang" },
{ L"Öì" , L"zhu" },
{ L"ÇØ" , L"qin" },
{ L"ÓÈ" , L"you" },
{ L"Ðí" , L"xu" },
{ L"ºÎ" , L"he" },
{ L"ÂÀ" , L"lv" },
{ L"Ê©" , L"shi" },
{ L"ÕÅ" , L"zhang" },
{ L"¿×" , L"kong" },
{ L"²Ü" , L"cao" },
{ L"ÑÏ" , L"yan" },
{ L"»ª" , L"hua" },
{ L"½ð" , L"jin" },
{ L"Îº" , L"wei" },
{ L"ÌÕ" , L"tao" },
{ L"½ª" , L"jiang" },
{ L"ÆÝ" , L"qi" },
{ L"Ð»" , L"xie" },
{ L"×Þ" , L"zou" },
{ L"Ó÷" , L"yu" },
{ L"°Ø" , L"bai" },
{ L"Ë®" , L"shui" },
{ L"ñ¼" , L"dou" },
{ L"ÕÂ" , L"zhang" },
{ L"ÔÆ" , L"yun" },
{ L"ËÕ" , L"su" },
{ L"ÅË" , L"pan" },
{ L"¸ð" , L"ge" },
{ L"ÞÉ" , L"xi" },
{ L"·¶" , L"fan" },
{ L"Åí" , L"peng" },
{ L"ÀÉ" , L"lang" },
{ L"Â³" , L"lu" },
{ L"Î¤" , L"wei" },
{ L"²ý" , L"chang" },
{ L"Âí" , L"ma" },
{ L"Ãç" , L"miao" },
{ L"·ï" , L"feng" },
{ L"»¨" , L"hua" },
{ L"·½" , L"fang" },
{ L"Óá" , L"yu" },
{ L"ÈÎ" , L"ren" },
{ L"Ô¬" , L"yuan" },
{ L"Áø" , L"liu" },
{ L"Ûº" , L"feng" },
{ L"±«" , L"bao" },
{ L"Ê·" , L"shi" },
{ L"ÌÆ" , L"tang" },
{ L"·Ñ" , L"fei" },
{ L"Á®" , L"lian" },
{ L"á¯" , L"cen" },
{ L"Ñ¦" , L"xue" },
{ L"À×" , L"lei" },
{ L"ºØ" , L"he" },
{ L"Äß" , L"ni" },
{ L"ÌÀ" , L"tang" },
{ L"ëø" , L"teng" },
{ L"Òó" , L"yin" },
{ L"ÂÞ" , L"luo" },
{ L"±Ï" , L"bi" },
{ L"ºÂ" , L"hao" },
{ L"Úù" , L"wu" },
{ L"°²" , L"an" },
{ L"³£" , L"chang" },
{ L"ÀÖ" , L"yue" },
{ L"ÓÚ" , L"yu" },
{ L"Ê±" , L"shi" },
{ L"¸µ" , L"fu" },
{ L"Æ¤" , L"pi" },
{ L"±å" , L"bian" },
{ L"Æë" , L"qi" },
{ L"¿µ" , L"kang" },
{ L"Îé" , L"wu" },
{ L"Óà" , L"yu" },
{ L"Ôª" , L"yuan" },
{ L"²·" , L"bu" },
{ L"¹Ë" , L"gu" },
{ L"ÃÏ" , L"meng" },
{ L"Æ½" , L"ping" },
{ L"»Æ" , L"huang" },
{ L"ºÍ" , L"he" },
{ L"ÄÂ" , L"mu" },
{ L"Ïô" , L"xiao" },
{ L"Òü" , L"yin" },
{ L"Ò¦" , L"yao" },
{ L"ÉÛ" , L"shao" },
{ L"Õ¿" , L"zhan" },
{ L"Íô" , L"wang" },
{ L"Æî" , L"qi" },
{ L"Ã«" , L"mao" },
{ L"Óí" , L"yu" },
{ L"µÒ" , L"di" },
{ L"Ã×" , L"mi" },
{ L"±´" , L"bei" },
{ L"Ã÷" , L"ming" },
{ L"ê°" , L"zang" },
{ L"¼Æ" , L"ji" },
{ L"·ü" , L"fu" },
{ L"³É" , L"cheng" },
{ L"´÷" , L"dai" },
{ L"Ì¸" , L"tan" },
{ L"ËÎ" , L"song" },
{ L"Ã©" , L"mao" },
{ L"ÅÓ" , L"pang" },
{ L"ÐÜ" , L"xiong" },
{ L"¼Í" , L"ji" },
{ L"Êæ" , L"shu" },
{ L"Çü" , L"qu" },
{ L"Ïî" , L"xiang" },
{ L"×£" , L"zhu" },
{ L"¶­" , L"dong" },
{ L"Áº" , L"liang" },
{ L"¶Å" , L"du" },
{ L"Èî" , L"ruan" },
{ L"À¶" , L"lan" },
{ L"ãÉ" , L"min" },
{ L"Ï¯" , L"xi" },
{ L"¼¾" , L"ji" },
{ L"Âé" , L"ma" },
{ L"Ç¿" , L"qiang" },
{ L"¼Ö" , L"jia" },
{ L"Â·" , L"lu" },
{ L"Â¦" , L"lou" },
{ L"Î£" , L"wei" },
{ L"½­" , L"jiang" },
{ L"Í¯" , L"tong" },
{ L"ÑÕ" , L"yan" },
{ L"¹ù" , L"guo" },
{ L"Ã·" , L"mei" },
{ L"Ê¢" , L"sheng" },
{ L"ÁÖ" , L"lin" },
{ L"µó" , L"diao" },
{ L"ÖÓ" , L"zhong" },
{ L"Ðì" , L"xu" },
{ L"Çñ" , L"qiu" },
{ L"Âæ" , L"luo" },
{ L"¸ß" , L"gao" },
{ L"ÏÄ" , L"xia" },
{ L"²Ì" , L"cai" },
{ L"Ìï" , L"tian" },
{ L"·®" , L"fan" },
{ L"ºú" , L"hu" },
{ L"Áè" , L"ling" },
{ L"»ô" , L"huo" },
{ L"ÓÝ" , L"yu" },
{ L"Íò" , L"wan" },
{ L"Ö§" , L"zhi" },
{ L"¿Â" , L"ke" },
{ L"êÃ" , L"zan" },
{ L"¹Ü" , L"guan" },
{ L"Â¬" , L"lu" },
{ L"Äª" , L"mo" },
{ L"¾­" , L"jing" },
{ L"·¿" , L"fang" },
{ L"ôÃ" , L"qiu" },
{ L"çÑ" , L"miao" },
{ L"¸É" , L"gan" },
{ L"½â" , L"xie" },
{ L"Ó¦" , L"ying" },
{ L"×Ú" , L"zong" },
{ L"¶¡" , L"ding" },
{ L"Ðû" , L"xuan" },
{ L"êÚ" , L"ben" },
{ L"µË" , L"deng" },
{ L"Óô" , L"yu" },
{ L"µ¥" , L"shan" },
{ L"º¼" , L"hang" },
{ L"ºé" , L"hong" },
{ L"°ü" , L"bao" },
{ L"Öî" , L"zhu" },
{ L"×ó" , L"zuo" },
{ L"Ê¯" , L"shi" },
{ L"´Þ" , L"cui" },
{ L"¼ª" , L"ji" },
{ L"Å¥" , L"niu" },
{ L"¹¨" , L"gong" },
{ L"³Ì" , L"cheng" },
{ L"ïú" , L"ji" },
{ L"ÐÏ" , L"xing" },
{ L"»¬" , L"hua" },
{ L"Åá" , L"pei" },
{ L"Â½" , L"lu" },
{ L"ÈÙ" , L"rong" },
{ L"ÎÌ" , L"weng" },
{ L"Ü÷" , L"xun" },
{ L"Ñò" , L"yang" },
{ L"ì¶" , L"yu" },
{ L"»Ý" , L"hui" },
{ L"Õç" , L"zhen" },
{ L"Çú" , L"qu" },
{ L"¼Ò" , L"jia" },
{ L"·â" , L"feng" },
{ L"ÜÇ" , L"rui" },
{ L"ôà" , L"yi" },
{ L"´¢" , L"chu" },
{ L"½ù" , L"jin" },
{ L"¼³" , L"ji" },
{ L"Úû" , L"bing" },
{ L"ÃÓ" , L"mi" },
{ L"ËÉ" , L"song" },
{ L"¾®" , L"jing" },
{ L"¶Î" , L"duan" },
{ L"¸»" , L"fu" },
{ L"Î×" , L"wu" },
{ L"ÎÚ" , L"wu" },
{ L"½¹" , L"jiao" },
{ L"°Í" , L"ba" },
{ L"¹­" , L"gong" },
{ L"ÄÁ" , L"mu" },
{ L"Úó" , L"kui" },
{ L"É½" , L"shan" },
{ L"¹È" , L"gu" },
{ L"³µ" , L"che" },
{ L"ºî" , L"hou" },
{ L"åµ" , L"mi" },
{ L"Åî" , L"peng" },
{ L"È«" , L"quan" },
{ L"Û­" , L"xi" },
{ L"°à" , L"ban" },
{ L"Ñö" , L"yang" },
{ L"Çï" , L"qiu" },
{ L"ÖÙ" , L"zhong" },
{ L"ÒÁ" , L"yi" },
{ L"¹¬" , L"gong" },
{ L"Äþ" , L"ning" },
{ L"³ð" , L"qiu" },
{ L"èï" , L"luan" },
{ L"±©" , L"bao" },
{ L"¸Ê" , L"gan" },
{ L"î×" , L"tou" },
{ L"À÷" , L"li" },
{ L"ÈÖ" , L"rong" },
{ L"×æ" , L"zu" },
{ L"Îä" , L"wu" },
{ L"·û" , L"fu" },
{ L"Áõ" , L"liu" },
{ L"¾°" , L"jing" },
{ L"Õ²" , L"zhan" },
{ L"Êø" , L"shu" },
{ L"Áú" , L"long" },
{ L"Ò¶" , L"ye" },
{ L"ÐÒ" , L"xing" },
{ L"Ë¾" , L"si" },
{ L"ÉØ" , L"shao" },
{ L"Û¬" , L"gao" },
{ L"Àè" , L"li" },
{ L"¼»" , L"ji" },
{ L"±¡" , L"bo" },
{ L"Ó¡" , L"yin" },
{ L"ËÞ" , L"su" },
{ L"°×" , L"bai" },
{ L"»³" , L"huai" },
{ L"ÆÑ" , L"pu" },
{ L"Û¢" , L"tai" },
{ L"´Ó" , L"cong" },
{ L"¶õ" , L"e" },
{ L"Ë÷" , L"suo" },
{ L"ÏÌ" , L"xian" },
{ L"¼®" , L"ji" },
{ L"Àµ" , L"lai" },
{ L"×¿" , L"zhuo" },
{ L"Ýþ" , L"lin" },
{ L"ÍÀ" , L"tu" },
{ L"ÃÉ" , L"meng" },
{ L"³Ø" , L"chi" },
{ L"ÇÇ" , L"qiao" },
{ L"Òõ" , L"yin" },
{ L"Óô" , L"yu" },
{ L"ñã" , L"xu" },
{ L"ÄÜ" , L"nai" },
{ L"²Ô" , L"cang" },
{ L"Ë«" , L"shuang" },
{ L"ÎÅ" , L"wen" },
{ L"Ý·" , L"shen" },
{ L"µ³" , L"dang" },
{ L"µÔ" , L"zhai" },
{ L"Ì·" , L"tan" },
{ L"¹±" , L"gong" },
{ L"ÀÍ" , L"lao" },
{ L"åÌ" , L"pang" },
{ L"¼§" , L"ji" },
{ L"Éê" , L"shen" },
{ L"·ö" , L"fu" },
{ L"¶Â" , L"du" },
{ L"È½" , L"ran" },
{ L"Ô×" , L"zai" },
{ L"Ûª" , L"li" },
{ L"Óº" , L"yong" },
{ L"àS" , L"xi" },
{ L"è³" , L"qu" },
{ L"É£" , L"sang" },
{ L"¹ð" , L"gui" },
{ L"å§" , L"pu" },
{ L"Å£" , L"niu" },
{ L"ÊÙ" , L"shou" },
{ L"Í¨" , L"tong" },
{ L"±ß" , L"bian" },
{ L"ìè" , L"hu" },
{ L"Ñà" , L"yan" },
{ L"¼½" , L"ji" },
{ L"Û£" , L"jia" },
{ L"ÆÖ" , L"pu" },
{ L"ÉÐ" , L"shang" },
{ L"Å©" , L"nong" },
{ L"ÎÂ" , L"wen" },
{ L"±ð" , L"bie" },
{ L"×¯" , L"zhuang" },
{ L"êÌ" , L"yan" },
{ L"²ñ" , L"chai" },
{ L"öÄ" , L"qu" },
{ L"ÑÖ" , L"yan" },
{ L"³ä" , L"chong" },
{ L"Ä½" , L"mu" },
{ L"Á¬" , L"lian" },
{ L"Èã" , L"ru" },
{ L"Ï°" , L"xi" },
{ L"»Â" , L"huan" },
{ L"°¬" , L"ai" },
{ L"Óã" , L"yu" },
{ L"ÈÝ" , L"rong" },
{ L"Ïò" , L"xiang" },
{ L"¹Å" , L"gu" },
{ L"Ò×" , L"yi" },
{ L"É÷" , L"shen" },
{ L"¸ê" , L"ge" },
{ L"ÁÎ" , L"liao" },
{ L"â×" , L"yu" },
{ L"ÖÕ" , L"zhong" },
{ L"ôß" , L"ji" },
{ L"¾Ó" , L"ju" },
{ L"ºâ" , L"heng" },
{ L"²½" , L"bu" },
{ L"¶¼" , L"du" },
{ L"¹¢" , L"geng" },
{ L"Âú" , L"man" },
{ L"ºë" , L"hong" },
{ L"¿ï" , L"kuang" },
{ L"¹ú" , L"guo" },
{ L"ÎÄ" , L"wen" },
{ L"¿Ü" , L"kou" },
{ L"¹ã" , L"guang" },
{ L"Â»" , L"lu" },
{ L"ãÚ" , L"que" },
{ L"¶«" , L"dong" },
{ L"Å·" , L"ou" },
{ L"ì¯" , L"shu" },
{ L"ÎÖ" , L"wo" },
{ L"Àû" , L"li" },
{ L"Îµ" , L"wei" },
{ L"Ô½" , L"yue" },
{ L"Ùç" , L"kui" },
{ L"Â¡" , L"long" },
{ L"Ê¦" , L"shi" },
{ L"¹®" , L"gong" },
{ L"ØÇ" , L"she" },
{ L"Äô" , L"nie" },
{ L"êË" , L"chao" },
{ L"¹´" , L"gou" },
{ L"¾ä" , L"gou" },
{ L"°½" , L"ao" },
{ L"ÈÚ" , L"rong" },
{ L"Àä" , L"leng" },
{ L"ö¤" , L"zi" },
{ L"ÐÁ" , L"xin" },
{ L"ãÛ" , L"kan" },
{ L"ÄÇ" , L"na" },
{ L"¼ò" , L"jian" },
{ L"ÈÄ" , L"rao" },
{ L"¿Õ" , L"kong" },
{ L"Ôø" , L"zeng" },
{ L"Ä¸" , L"mu" },
{ L"É³" , L"sha" },
{ L"Ø¿" , L"nie" },
{ L"Ñø" , L"yang" },
{ L"¾Ï" , L"ju" },
{ L"Ðë" , L"xu" },
{ L"·á" , L"feng" },
{ L"³²" , L"chao" },
{ L"¹Ø" , L"guan" },
{ L"Øá" , L"kuai" },
{ L"Ïà" , L"xiang" },
{ L"²é" , L"zha" },
{ L"ºó" , L"hou" },
{ L"¾£" , L"jing" },
{ L"ºì" , L"hong" },
{ L"ÓÎ" , L"you" },
{ L"óÃ" , L"zhu" },
{ L"È¨" , L"quan" },
{ L"åÖ" , L"lu" },
{ L"¸Ç" , L"gai" },
{ L"Òæ" , L"yi" },
{ L"»¸" , L"huan" },
{ L"¹«" , L"gong" },
{ L"ÍòÙ¹" , L"moqi" },
{ L"Ë¾Âí" , L"sima" },
{ L"ÉÏ¹Ù" , L"shangguan" },
{ L"Å·Ñô" , L"ouyang" },
{ L"ÏÄºî" , L"xiahou" },
{ L"Öî¸ð" , L"zhuge" },
{ L"ÎÅÈË" , L"wenren" },
{ L"¶«·½" , L"dongfang" },
{ L"ºÕÁ¬" , L"helian" },
{ L"»Ê¸¦" , L"huangpu" },
{ L"Î¾³Ù" , L"yuchi" },
{ L"¹«Ñò" , L"gongyang" },
{ L"å£Ì¨" , L"tantai" },
{ L"¹«Ò±" , L"gongye" },
{ L"×ÚÕþ" , L"zongzheng" },
{ L"å§Ñô" , L"puyang" },
{ L"´¾ÓÚ" , L"chunyu" },
{ L"µ¥ÓÚ" , L"chanyu" },
{ L"Ì«Êå" , L"taishu" },
{ L"ÉêÍÀ" , L"shentu" },
{ L"¹«Ëï" , L"gongsun" },
{ L"ÖÙËï" , L"zhongsun" },
{ L"ÐùÔ¯" , L"xuanyuan" },
{ L"Áîºü" , L"linghu" },
{ L"ÖÓÀë" , L"zhongli" },
{ L"ÓîÎÄ" , L"yuwen" },
{ L"³¤Ëï" , L"zhangsun" },
{ L"Ä½ÈÝ" , L"murong" },
{ L"ÏÊÓÚ" , L"xianyu" },
{ L"ãÌÇð" , L"luqiu" },
{ L"Ë¾Í½" , L"situ" },
{ L"Ë¾¿Õ" , L"sikong" },
{ L"ØÁ¹Ù" , L"qiguan" },
{ L"Ë¾¿Ü" , L"sikou" },
{ L"Øë¶½" , L"zhangdu" },
{ L"×Ó³µ" , L"ziju" },
{ L"ò§Ëï" , L"zhuansun" },
{ L"¶ËÄ¾" , L"duanmu" },
{ L"Î×Âí" , L"wuma" },
{ L"¹«Î÷" , L"gongxi" },
{ L"Æáµñ" , L"qidiao" },
{ L"ÀÖÕý" , L"yuezheng" },
{ L"ÈÀæá" , L"rangsi" },
{ L"¹«Á¼" , L"gongliang" },
{ L"ÍØ°Ï" , L"tuoba" },
{ L"¼Ð¹È" , L"jiagu" },
{ L"Ô×¸¸" , L"zaifu" },
{ L"˜bÁº" , L"guliang" },
{ L"½ú" , L"jin" },
{ L"³þ" , L"chu" },
{ L"ãÆ" , L"yan" },
{ L"·¨" , L"fa" },
{ L"Èê" , L"ru" },
{ L"Û³" , L"yan" },
{ L"Í¿" , L"tu" },
{ L"ÇÕ" , L"qin" },
{ L"¶Î¸É" , L"duangan" },
{ L"°ÙÀï" , L"baili" },
{ L"¶«¹ù" , L"dongguo" },
{ L"ÄÏÃÅ" , L"nanmen" },
{ L"ºôÑÓ" , L"huyan" },
{ L"¹é" , L"gui" },
{ L"º£" , L"hai" },
{ L"ÑòÉà" , L"yangshe" },
{ L"Î¢" , L"wei" },
{ L"Éú" , L"sheng" },
{ L"ÔÀ" , L"yue" },
{ L"Ë§" , L"shuai" },
{ L"çÃ" , L"gou" },
{ L"¿º" , L"kang" },
{ L"¿ö" , L"kuang" },
{ L"ºó" , L"hou" },
{ L"ÓÐ" , L"you" },
{ L"ÇÙ" , L"qin" },
{ L"ÁºÇð" , L"liangqiu" },
{ L"×óÇð" , L"zuoqiu" },
{ L"¶«ÃÅ" , L"dongmen" },
{ L"Î÷ÃÅ" , L"ximen" },
{ L"ÉÌ" , L"shang" },
{ L"Ä²" , L"mou" },
{ L"ÙÜ" , L"she" },
{ L"Ù¦" , L"nai" },
{ L"²®" , L"bo" },
{ L"ÉÍ" , L"shang" },
{ L"ÄÏ¹¬" , L"nangong" },
{ L"Ä«" , L"mo" },
{ L"¹þ" , L"ha" },
{ L"ÚÛ" , L"qiao" },
{ L"óÎ" , L"da" },
{ L"Äê" , L"nian" },
{ L"°®" , L"ai" },
{ L"Ñô" , L"yang" },
{ L"Ù¡" , L"tong" },
{ L"µÚÎå" , L"diwu" },
{ L"ÑÔ" , L"yan" },
{ L"¸£" , L"fu" },
{ L"ºÚ" , L"he" },
{ L"Çø" , L"ou" },
{ L"ÆÓ" , L"piao" },
{ L"·±" , L"po" },
{ L"Ô±" , L"yun" },
{ L"Þ¬" , L"pi" },
{ L"ÖÖ" , L"chong" },
{ L"ÃØ" , L"bi" },
{ L"ÚÈ" , L"chen" },
{ L"à¨" , L"chuai" },
{ L"Û¡" , L"di" },
{ L"ÜÞ" , L"fu" },
{ L"¸¦" , L"fu" },
{ L"ê½" , L"gao" },
{ L"ôÞ" , L"gen" },
{ L"¹Ú" , L"guan" },
{ L"æ£" , L"gui" },
{ L"¹ý" , L"guo" },
{ L"êÉ" , L"cheng" },
{ L"öÁ" , L"juan" },
{ L"·ê" , L"pang" },
{ L"Úü" , L"pi" },
{ L"ÆÎ" , L"pu" },
{ L"äß" , L"pu" },
{ L"ØÁ" , L"qi" },
{ L"ÉÙ" , L"shao" },
{ L"ÕÙ" , L"shao" },
{ L"ÕÛ" , L"she" },
{ L"Í®" , L"tong" },
{ L"âÕ" , L"tuo" },
{ L"Íð" , L"wan" },
{ L"Î¾" , L"wei" },
{ L"Ùþ" , L"xian" },
{ L"Ï´" , L"xian" },
{ L"Û¨" , L"xun" },
{ L"çÛ" , L"yao" },
{ L"ÔÇ" , L"yun" },
{ L"ã¢" , L"yun" },
{ L"Û©" , L"yun" },
{ L"Ñò½Ç" , L"yangjue" },
{ L"Šu" , L"yun" },
{ L"¼À" , L"zhai" },
{ L"íÎ" , L"zhai" },
{ L"Õ¼" , L"zhan" },
{ L"Øë" , L"zhang" },
{ L"ÖÐÐÐ" , L"zhonghang" },
{ L"ìú" , L"zhuo" },
{ L"åÅ" , L"ze" },
{ L"ñû" , L"qin" },
};

/*
0. ¶àÒô×Ö±í 
1. ºóÃæµÄ×¢ÊÍ±íÊ¾µÄÊÇ£ºÕâ¸ö×ÖÊ£ÓàµÄÆäËû¶ÁÒô £¨ÈÕ¡¢º«·Ö±ð±íÊ¾ºº×ÖÊÇÈÕÓï»òº«Óï£©
2. À´Ô´ÓÚ hanziTables[]£¬£¨±éÀúµÄËùÓÐ£¬Ã»ÓÐÒÅÂ©£©
3. ¶àÒô×ÖÑ¡ÖÐ¶ÁÒô¹æÔò£º
   a. Ñ¡Ôñ³£ÓÃ¶ÁÒô £º
		{ "ºì" , "hong" },      // gong  
		{ "±¡" , "bo" },        // bao
		{ "²ð" , "chai" },      // ca
   b. Ñ¡Ôñ¸ù¾ÝÆ´Òô¿ÉÒÔ²Â³öºº×ÖµÄ¶ÁÒô¡£ÕâÖÖ×Ö´ó¼ÒÖªµÀÊÇ¶àÒô×Ö£¬Èç¹ûÎÒÊä³ö'ju'Äã»ù±¾¿ÉÒÔ²Âµ½ºº×Ö'¾ä'£¬µ«ÊÇÎÒÊä³ö'gou'Äã»¹ÄÜ²Âµ½ºº×ÖÊÇ'¾ä'¾Í...
		{ "¾ä" , "ju" },        // gou
		{ "ÅÔ" , "pang" },      // bang
		{ "¸ø" , "gei" },       // ji
		{ "°¬" , "ai" },        // yi
		{ "´ó" , "da" },        // dai
		{ "ÅÚ" , "pao" },       // bao
   c. Ñ¡ÖÐ·ÇÐÕÊÏ¶ÁÒô
		{ "³ð" , "chou" },      // qiu £¬³ð£º×÷ÐÕÊÏÊ±¶Áqi¨²
		{ "½â" , "jie" },       // xie £¬½â£º×÷ÐÕÊÏÊ±¶Áxi¨¨
		{ "Ôø" , "ceng" },      // zeng£¬Ôø£º×÷ÐÕÊÏÊ±¶Áz¨¥ng
   d. Ñ¡ÖÐÐÕÃûÖÐ±È½Ï¿ÉÄÜ³öÏÖµÄ×Ö,ÏÂÃæµÄÀý×Ó¿ÉÄÜÇ¡ºÃ·ûºÏÆäËûµÄ¹æÔò£¬µ«ÊÇÔÚÎÒÊÖ¶¯É¸Ñ¡¶àÒô×ÖÊ±È·Êµ¿¼ÂÇµ½Õâ·½ÃæµÄÇé¿ö£¬ÒòÎªÓÐÐ©¶àÒô×ÖµÄÆäÖÐÒ»Ð©¶ÁÒô´ú±íµÄÒâÒåÃ÷ÏÔ²»¿ÉÄÜ±»µ±Ãû×ÖÀ´Ê¹ÓÃ£¬ÒòÎªÉ¸Ñ¡Ê±Ã»¼ÇÂ¼£¬ÏÂÃæµÄÀý×Ó¿ÉÄÜ²»ÌùÇÐ
		{ "Ê¢" , "sheng" },     // cheng £¬ Ã¯Ê¢£¨maoSheng£©£¬Ê¢·¹(chengFan)
		{ "Ê¯" , "shi" },       // dan    £¬ ÅËÊ¯ÒÙ
		{ "ñæ" , "jin" },       // qin guan
		{ "Ç¿" , "qiang" },     // jiang , ¼áÇ¿£¨qiang£©£¬¾óÇ¿£¨jiang£©
   e. ÐèÒªÉÏÏÂÎÄÁªÏµµÄ£¬ÕâÖÖ×ÖÃ»·¨ÁË£¬Ö»ÄÜ²é±í£¬ÕâÀïµÄÊä³öÔ­Ôò×ñÑ­£¨abcd£©
		{ "ÆÁ" , "ping" },      // bing £¬ ÆÁÄ»¡¢ÆÁÆú
		{ "²·" , "bu" },        // bo £¬   Õ¼²·¡¢ÂÜ²·
*/
multiToneWordTableS multiToneWordTable[g_length_multiToneWordTable] =
{
{ L"…" , L"e" },         // si a
{ L"ß¹" , L"ya" },        // a
{ L"°¢" , L"a" },         // e
{ L"ºÇ" , L"he" },        // ha ke a
{ L"ëç" , L"yan" },       // a
{ L"àÄ" , L"sha" },       // a
{ L"é^" , L"ci" },        // ka lu ai
{ L"ôƒ" , L"li" },        // ai
{ L"÷_" , L"ai" },        // suo 
{ L"ŠÖ" , L"xi" },        // ai
{ L"Ì" , L"yi" },        // ai
{ L"šG" , L"ei" },        // ai
{ L"°¬" , L"ai" },        // yi 
{ L"àÉ" , L"yi" },        // ai
{ L"àæ" , L"yi" },        // ai
{ L"ðg" , L"ai" },        // he 
{ L"³§" , L"chang" },     // an
{ L"¹ã" , L"guang" },     // an
{ L"••" , L"yan" },       // an
{ L"áí" , L"han" },       // an
{ L"°·" , L"an" },        // e 
{ L"°¹" , L"ang" },       // hang 
{ L"…n" , L"yang" },      // ang
{ L"Ñö" , L"yang" },      // ang
{ L"°¼" , L"ao" },        // wa 
{ L"Ïù" , L"xiao" },      // ao
{ L"Ø²" , L"ao" },        // yao 
{ L"ÞÖ" , L"ao" },        // niu 
{ L"æŽ" , L"ha" },        // ba
{ L"õ•" , L"li" },        // si xi ba
{ L"°È" , L"ba" },        // pa 
{ L"æŽ" , L"ba" },        // pa
{ L"²®" , L"bo" },        // bai  ba
{ L"èË" , L"pa" },        // ba
{ L"°È" , L"ba" },        // pa
{ L"°Ò" , L"pa" },        // ba
{ L"®B" , L"bai" },       // wa 
{ L"ƒÄ" , L"bai" },       // ke 
{ L"Ä°" , L"mo" },        // bai
{ L"°Ø" , L"bai" },       // bo 
{ L"°é" , L"ban" },       // pan 
{ L"°è" , L"ban" },       // pan 
{ L"ˆm" , L"pan" },       // ban
{ L"–®" , L"pan" },       // ban
{ L"°ò" , L"bang" },      // pang 
{ L"ÅÔ" , L"pang" },      // bang
{ L"°ö" , L"bang" },      // beng 
{ L"—”" , L"bang" },      // bei 
{ L"“s" , L"bang" },      // peng 
{ L"°õ" , L"bang" },      // pang 
{ L"ÅÚ" , L"pao" },       // bao
{ L"–¢" , L"bao" },       // fu 
{ L"±¡" , L"bo" },        // bao
{ L"±¤" , L"bao" },       // bu pu 
{ L"ÅÙ" , L"pao" },       // bao
{ L"Ðˆ" , L"pao" },       // bao
{ L"±©" , L"bao" },       // pu 
{ L"ÆÙ" , L"pu" },        // bao
{ L"ÆØ" , L"bao" },       // pu 
{ L"Úé" , L"bei" },       // pi po 
{ L"—À" , L"bei" },       // pi 
{ L"ØÃ" , L"bei" },       // bo 
{ L"±»" , L"bei" },       // pi 
{ L"êÚ" , L"ben" },       // bi 
{ L"º»" , L"hang" },      // ben
{ L"ÈZ" , L"ta" },        // ku lai bi
{ L"ÍŒ" , L"bi" },        // e 
{ L"æq" , L"bi" },        // pi 
{ L"ßÁ" , L"pi" },        // bi
{ L"¹u" , L"pai" },       // bi
{ L"ÜÅ" , L"bi" },        // pi 
{ L"ÃÚ" , L"mi" },        // bi
{ L"ÃØ" , L"mi" },        // bi
{ L"ñÔ" , L"bi" },        // pi 
{ L"±Ù" , L"pi" },        // bi
{ L"î¢" , L"pi" },        // bi
{ L"±â" , L"bian" },      // pian 
{ L"ñÛ" , L"bian" },      // pian 
{ L"±ã" , L"bian" },      // pian 
{ L"çÂ" , L"bian" },      // pian 
{ L"è¼" , L"shao" },      // biao
{ L"æô" , L"biao" },      // piao 
{ L"û" , L"pao" },       // biao
{ L"çã" , L"fen" },       // bin
{ L"éÄ" , L"bing" },      // bin
{ L"ÆÁ" , L"ping" },      // bing
{ L"ç®" , L"geng" },      // bing
{ L"²·" , L"bu" },        // bo
{ L"®z" , L"da" },        // bo
{ L"²´" , L"po" },        // bo
{ L"ÆÇ" , L"po" },        // tuo bo
{ L"ÆÒ" , L"pu" },        // bu
{ L"²ð" , L"chai" },      // ca
{ L"àê" , L"ca" },        // cha 
{ L"‚Æ" , L"si" },        // cai
{ L"²Î" , L"can" },       // cen san shen 
{ L"ºd" , L"can" },       // zan 
{ L"²ô" , L"chan" },      // shan can
{ L"åî" , L"chan" },      // can
{ L"ê°" , L"zang" },      // cang
{ L"²Ø" , L"cang" },      // zang 
{ L"ªe" , L"o" },         // ce
{ L"³€" , L"ce" },        // ke o 
{ L"²à" , L"ce" },        // ze zhai 
{ L"¹k" , L"ce" },        // jia 
{ L"àá" , L"cheng" },     // ceng
{ L"Ôø" , L"ceng" },      // zeng 
{ L"²î" , L"cha" },       // chai ci 
{ L"Ôû" , L"zha" },       // cha
{ L"²é" , L"cha" },       // zha 
{ L"âª" , L"cha" },       // zha 
{ L"é«" , L"zha" },       // cha
{ L"é¶" , L"cha" },       // zha 
{ L"É²" , L"sha" },       // cha
{ L"ßå" , L"zha" },       // cha
{ L"²ñ" , L"chai" },      // zhai 
{ L"Æ" , L"chai" },      // zhi 
{ L"ðû" , L"cuo" },       // chai
{ L"µ¥" , L"dan" },       // shan chan
{ L"ìø" , L"chan" },      // shan 
{ L"³¤" , L"chang" },     // zhang 
{ L"ÌÈ" , L"tang" },      // chang
{ L"ã®" , L"chang" },     // tang 
{ L"´Â" , L"chuo" },      // chao
{ L"ìÌ" , L"chao" },      // zhuo 
{ L"½Ë" , L"chao" },      // jiao 
{ L"³¯" , L"chao" },      // zhao 
{ L"ü…" , L"zhao" },      // chao
{ L"³°" , L"chao" },      // zhao 
{ L"³µ" , L"che" },       // ju 
{ L"³ß" , L"chi" },       // che
{ L"àÁ" , L"chen" },      // tian 
{ L"³Æ" , L"cheng" },     // chen
{ L"îõ" , L"dang" },      // cheng
{ L"éÌ" , L"tang" },      // cheng
{ L"³Ë" , L"cheng" },     // sheng 
{ L"Ê¢" , L"sheng" },     // cheng
{ L"³Î" , L"cheng" },     // deng 
{ L"Ûæ" , L"di" },        // chi
{ L"¯€" , L"zhi" },       // chi
{ L"Ó¿" , L"yong" },      // chong
{ L"³æ" , L"chong" },     // hui 
{ L"ÖÖ" , L"zhong" },     // chong
{ L"ÖØ" , L"zhong" },     // chong
{ L"³ð" , L"chou" },      // qiu 
{ L"àü" , L"chou" },      // dao 
{ L"–ƒ" , L"niu" },       // chou
{ L"³ô" , L"chou" },      // xiu 
{ L"Öú" , L"zhu" },       // chu
{ L"ñÒ" , L"zhu" },       // chuzhe 
{ L"Ðó" , L"chu" },       // xu 
{ L"‚m" , L"chu" },       // ti 
{ L"œä" , L"chu" },       // xu 
{ L"šH" , L"xu" },        // chua
{ L"à¨" , L"chuo" },      // chuai
{ L"´«" , L"chuan" },     // zhuan 
{ L"´®" , L"chuan" },     // guan 
{ L"´±" , L"zhuang" },    // chuang
{ L"×µ" , L"zhui" },      // chui
{ L"åT" , L"dchun" },     // ui 
{ L"‹S" , L"ruo" },       // chuo
{ L"Üë" , L"zi" },        // ci
{ L"×È" , L"zi" },        // ci
{ L"ËÅ" , L"si" },        // ci
{ L"èÈ" , L"cong" },      // zong 
{ L"˜B" , L"song" },      // cong
{ L"×ä" , L"zu" },        // cu
{ L"È¤" , L"qu" },        // cu
{ L"Çˆ" , L"zou" },       // cuan
{ L"ÔÜ" , L"zan" },       // cuan
{ L"´â" , L"cui" },       // sui 
{ L"¶×" , L"dun" },       // cun
{ L"àŸ" , L"zan" },       // cuo
{ L"ùŒ" , L"ku" },        // ta yi da
{ L"àª" , L"da" },        // ta 
{ L"í³" , L"ta" },        // da
{ L"µ¬" , L"dan" },       // da
{ L"´ó" , L"da" },        // dai 
{ L"šù" , L"tai" },       // da
{ L"ß¾" , L"dai" },       // tai 
{ L"ææ" , L"dai" },       // tai 
{ L"µ§" , L"dan" },       // shan 
{ L"ür" , L"dan" },       // zhan 
{ L"Ê¯" , L"shi" },       // dan
{ L"µ¯" , L"tan" },       // dan
{ L"å£" , L"dan" },       // tan 
{ L"h" , L"dao" },       // ri 
{ L"ß¶" , L"dao" },       // tao 
{ L"ìâ" , L"dao" },       // tao 
{ L"µÄ" , L"de" },        // di 
{ L"µØ" , L"di" },        // de
{ L"µ×" , L"di" },        // de
{ L"µÃ" , L"de" },        // dei 
{ L"‡N" , L"de" },        // dei 
{ L"‡Ã" , L"di" },        // mi 
{ L"Ìá" , L"ti" },        // di
{ L"µÔ" , L"di" },        // zhai 
{ L"Û—" , L"di" },        // zhi 
{ L"–m" , L"di" },        // duo 
{ L"“W" , L"ti" },        // di
{ L"Úç" , L"dian" },      // yan 
{ L"µè" , L"dian" },      // tian 
{ L"îä" , L"dian" },      // tian 
{ L"Äñ" , L"niao" },      // diao
{ L"µ÷" , L"tiao" },      // zhou diao
{ L"ï¢" , L"diao" },      // yao 
{ L"†A" , L"die" },       // xi 
{ L"•i" , L"die" },       // yi 
{ L"à©" , L"die" },       // zha 
{ L"Þé" , L"die" },       // she 
{ L"ÏH" , L"zhi" },       // die
{ L"¶¡" , L"ding" },      // zheng 
{ L"î®" , L"ding" },      // ting 
{ L"îú" , L"ting" },      // ding
{ L"¶±" , L"tong" },      // dong
{ L"Ûí" , L"dong" },      // tong 
{ L"¶²" , L"dong" },      // tong 
{ L"á¼" , L"tong" },      // dong
{ L"¶¼" , L"dou" },       // du 
{ L"¶Á" , L"du" },        // dou
{ L"äÂ" , L"du" },        // dou
{ L"…¶" , L"du" },        // ge 
{ L"ê^" , L"du" },        // she 
{ L"¶È" , L"duo" },       // du
{ L"”¾" , L"yi" },        // du
{ L"¶Ø" , L"dun" },       // dui
{ L"ïæ" , L"dui" },       // dun 
{ L"ãç" , L"dun" },       // zhuan 
{ L"¶Ú" , L"tun" },       // dun
{ L"˜J" , L"dun" },       // shun 
{ L"öV" , L"wu" },        // ya duo ji 
{ L"ÍÔ" , L"tuo" },       // duo
{ L"¶é" , L"duo" },       // hui 
{ L"˜" , L"o" },         // e
{ L"”ñ" , L"o" },         // si e
{ L"Òk" , L"e" },         // ta
{ L"™ë" , L"mi" },        // e
{ L"¶ñ" , L"e" },         // wu 
{ L"Å¶" , L"o" },         // e
{ L"¶ê" , L"e" },         // yi 
{ L"ãÕ" , L"e" },         // yan 
{ L"—Ò" , L"mi" },        // eng
{ L"Äž" , L"nao" },       // er
{ L"Ù¦" , L"er" },        // nai 
{ L"·¢" , L"fa" },        // fei 
{ L"áN" , L"fa" },        // po 
{ L"·¬" , L"fan" },       // pan 
{ L"ñÈ" , L"pan" },       // fan
{ L"·±" , L"fan" },       // po 
{ L"·Â" , L"fang" },      // pang 
{ L"áÝ" , L"pang" },      // fang
{ L"ÜÀ" , L"fu" },        // fei
{ L"âö" , L"fu" },        // fei
{ L"å" , L"fen" },       // pen 
{ L"·ë" , L"feng" },      // ping 
{ L"·ð" , L"fo" },        // fu 
{ L"·ñ" , L"fou" },       // pi 
{ L"Ý³" , L"fu" },        // piao 
{ L"‚a" , L"mian" },      // fu
{ L"¸¬" , L"pu" },        // fu
{ L"f" , L"ga" },        // ri 
{ L"„L" , L"xi" },        // la  ga
{ L"Ü…" , L"ya" },        // ga
{ L"¼Ð" , L"jia" },       // ga
{ L"Ù¤" , L"ga" },        // jia qie 
{ L"ßÈ" , L"xia" },       // ga
{ L"¿§" , L"ka" },        // ga
{ L"Ôþ" , L"zha" },       // ya  ga
{ L"½æ" , L"jie" },       // gai
{ L"¸Ç" , L"gai" },       // ge 
{ L"¼é" , L"jian" },      // gan
{ L"¸Ð" , L"gan" },       // han 
{ L"¸Ó" , L"gan" },       // gong 
{ L"¿¸" , L"kang" },      // gang
{ L"í°" , L"gang" },      // zhuang 
{ L"¸Þ" , L"gao" },       // hao 
{ L"Áo" , L"mei" },       // gao
{ L"¸ä" , L"gao" },       // hao 
{ L"g" , L"ge" },        // ri 
{ L"Ž|" , L"xi" },        // ge
{ L"†{" , L"ge" },        // xi 
{ L"Øî" , L"yi" },        // ge
{ L"æü" , L"ge" },        // he 
{ L"¿©" , L"ge" },        // ka luo 
{ L"¸ï" , L"ge" },        // ji 
{ L"Øª" , L"ge" },        // li 
{ L"¸ò" , L"ge" },        // ha 
{ L"ºÏ" , L"he" },        // ge
{ L"íÑ" , L"luo" },       // ge
{ L"¸ø" , L"gei" },       // ji 
{ L"ßç" , L"gen" },       // hen 
{ L"ºì" , L"hong" },      // gong
{ L"†y" , L"gong" },      // hong 
{ L"¾ä" , L"ju" },        // gou
{ L"èÛ" , L"gou" },       // ju 
{ L"ßÉ" , L"gua" },       // gu
{ L"¼Ò" , L"jia" },       // gu
{ L"÷½" , L"gu" },        // hu 
{ L"ãé" , L"gu" },        // yu 
{ L"¹È" , L"gu" },        // yu 
{ L"¿à" , L"ku" },        // gu
{ L"¼Ö" , L"jia" },       // gu
{ L"ðÀ" , L"gu" },        // he hu 
{ L"ØÅ" , L"gu" },        // jia 
{ L"¹Í" , L"gu" },        // hu 
{ L"èé" , L"gua" },       // kuo 
{ L"ÂÚ" , L"lun" },       // guan
{ L"ñæ" , L"jin" },       // qin guan
{ L"Ý¸" , L"guan" },      // wan 
{ L"¹é" , L"gui" },       // kui 
{ L"¹ê" , L"gui" },       // jun qiu 
{ L"@" , L"gui" },       // hui wei 
{ L"öÙ" , L"gui" },       // hua xie 
{ L"šð" , L"jiu" },       // gui
{ L"êÁ" , L"jiong" },     // gui
{ L"È²" , L"que" },       // gui
{ L"¹ñ" , L"gui" },       // ju 
{ L"èí" , L"hui" },       // gui 
{ L"÷¬" , L"gui" },       // jue 
{ L"ÎÐ" , L"wo" },        // guo
{ L"a" , L"ha" },        // ri 
{ L"’C" , L"ru" },        // me  ha
{ L"œÂ" , L"tu" },        // ha
{ L"‡" , L"xi" },        // ha na 
{ L"÷m" , L"ta" },        // ha
{ L"Ïº" , L"xia" },       // ha
{ L"¿È" , L"ke" },        // hai
{ L"àË" , L"hai" },       // hei 
{ L"»¹" , L"huan" },      // hai
{ L"º¦" , L"hai" },       // he 
{ L"¿»" , L"kang" },      // hang
{ L"ÐÐ" , L"xing" },      // hang heng
{ L"¿Ô" , L"keng" },      // hang
{ L"Ïï" , L"xiang" },     // hang
{ L"ºÑ" , L"he" },        // hao
{ L"ßj" , L"he" },        // wo 
{ L"ºÍ" , L"he" },        // hu huo 
{ L"ºË" , L"he" },        // hu 
{ L"ÏÅ" , L"xia" },       // he
{ L"ªn" , L"xie" },       // he
{ L"ŸÀ" , L"he" },        // kao 
{ L"ºÙ" , L"hei" },       // mo 
{ L"Ï·" , L"xi" },        // hu hui 
{ L"ÜÌ" , L"wu" },        // hu
{ L"ä°" , L"hu" },        // xu 
{ L"»£" , L"hu" },        // xia 
{ L"—ü" , L"ku" },        // hu
{ L"í¹" , L"xu" },        // hua
{ L"Û¨" , L"xun" },       // huan
{ L"à÷" , L"yuan" },      // huan
{ L"‹Ö" , L"huan" },      // qiong xuan 
{ L"Ñ£" , L"xuan" },      // huan
{ L"ì¿" , L"wei" },       // hui
{ L"çõ" , L"hun" },       // hui
{ L"î¡" , L"hui" },       // sui 
{ L"»á" , L"hui" },       // kuai 
{ L"ä«" , L"hui" },       // kuai 
{ L"ßÜ" , L"yue" },       // hui
{ L"»ç" , L"hun" },       // xun 
{ L"Ææ" , L"qi" },        // ji
{ L"Æä" , L"qi" },        // ji
{ L"¼©" , L"ji" },        // qi 
{ L"»ü" , L"ji" },        // qi 
{ L"Ø½" , L"ji" },        // qi 
{ L"½å" , L"ji" },        // jie 
{ L"Æë" , L"qi" },        // ji
{ L"Ïµ" , L"xi" },        // ji
{ L"Üù" , L"ji" },        // qi 
{ L"¼À" , L"ji" },        // zhai 
{ L"ÙÊ" , L"jie" },       // ji
{ L"†í" , L"jia" },       // lun 
{ L"ÇÑ" , L"qie" },       // jia
{ L"Ýç" , L"jia" },       // xia 
{ L"¼Ù" , L"jia" },       // xia 
{ L"¼Û" , L"jia" },       // jie 
{ L"Ç³" , L"qian" },      // jian
{ L"êù" , L"jian" },      // qian 
{ L"àî" , L"jian" },      // nan 
{ L"¼û" , L"jian" },      // xian 
{ L"¼÷" , L"kan" },       // jian
{ L"½«" , L"jiang" },     // qiang 
{ L"½µ" , L"jiang" },     // xiang 
{ L"Ç¿" , L"qiang" },     // jiang
{ L"½¶" , L"jiao" },      // qiao 
{ L"áè" , L"jiao" },      // yao 
{ L"½À" , L"jiao" },      // jue 
{ L"½Ç" , L"jiao" },      // jue 
{ L"½Ä" , L"jiao" },      // yao 
{ L"½Å" , L"jiao" },      // jue 
{ L"äÐ" , L"jiu" },       // qiu jiao
{ L"½É" , L"jiao" },      // zhuo 
{ L"á½" , L"qiao" },      // jiao
{ L"¾õ" , L"jiao" },      // jue 
{ L"Ð£" , L"xiao" },      // jiao
{ L"¿¬" , L"kai" },       // jie
{ L"½Û" , L"jie" },       // ju 
{ L"½e" , L"xie" },       // jie
{ L"½â" , L"jie" },       // xie 
{ L"âÛ" , L"jin" },       // qin 
{ L"¾¢" , L"jing" },      // jin
{ L"‚Š" , L"liang" },     // jing
{ L"ö¦" , L"liang" },     // jing
{ L"ÇÒ" , L"qie" },       // ju
{ L"ÜÚ" , L"ju" },        // zu 
{ L"Çù" , L"qu" },        // ju
{ L"ôò" , L"qie" },       // ju
{ L"¾×" , L"ju" },        // zui 
{ L"»c" , L"qu" },        // ju
{ L"ÜÄ" , L"ju" },        // qu 
{ L"È¦" , L"quan" },      // juan
{ L"¾í" , L"juan" },      // quan 
{ L"Ûm" , L"quan" },      // juan
{ L"öÁ" , L"jun" },       // juan
{ L"ãÚ" , L"que" },       // jue
{ L"àå" , L"xue" },       // jue
{ L"óÞ" , L"jun" },       // yun 
{ L"÷å" , L"qun" },       // jun
{ L"¿£" , L"jun" },       // xun 
{ L"Ÿa" , L"jun" },       // qu 
{ L"„J" , L"ka" },        // yi 
{ L"ÑQ" , L"ka" },        // mi mo xi ÈÕ
{ L"Âˆ" , L"li" },        // xi ka
{ L"õ–" , L"ke" },        // nou zi ka
{ L"ù‹" , L"si" },        // yi ka
{ L"¿¨" , L"ka" },        // qia 
{ L"…ž" , L"mu" },        // wu ke
{ L"Þ‘" , L"o" },         // pi ke
{ L"·i" , L"o" },         // ke
{ L"¿Ç" , L"ke" },        // qiao 
{ L"Úó" , L"wei" },       // kui
{ L"õu" , L"luo" },       // la
{ L"Âä" , L"luo" },       // lao  la
{ L"À°" , L"la" },        // xi 
{ L"À¯" , L"la" },        // zha 
{ L"ñ®" , L"lai" },       // la
{ L"Ý¹" , L"liang" },     // lang
{ L"ÁÊ" , L"liao" },      // lao
{ L"ÀÑ" , L"lao" },       // mu 
{ L"â²" , L"liao" },      // lao
{ L"Âç" , L"luo" },       // lao
{ L"ÀÓ" , L"lao" },       // luo 
{ L"–Y" , L"te" },        // wu le
{ L"˜V" , L"mu" },        // le
{ L"Àß" , L"lei" },       // le
{ L"ÀÖ" , L"yue" },       // le
{ L"ÀÕ" , L"lei" },       // le
{ L"äð" , L"luo" },       // ta lei
{ L"Àâ" , L"leng" },      // ling 
{ L"®M" , L"li" },        // wa 
{ L"ó»" , L"li" },        // luo 
{ L"èÝ" , L"li" },        // yue 
{ L"õÈ" , L"li" },        // luo 
{ L"Á©" , L"liang" },     // lia
{ L"ïf" , L"liu" },       // liao
{ L"Þ¤" , L"liao" },      // lu 
{ L"’£" , L"lie" },       // ri 
{ L"Áù" , L"liu" },       // lu 
{ L"Â½" , L"lu" },        // liu
{ L"Âµ" , L"lu" },        // liu
{ L"ãñ" , L"long" },      // shuang 
{ L"Åª" , L"nong" },      // long
{ L"ÙÍ" , L"lou" },       // lv 
{ L"Â¶" , L"lu" },        // lou
{ L"ÂÌ" , L"lv" },        // lu 
{ L"ÞÛ" , L"luo" },       // lv
{ L"ÂÊ" , L"shuai" },     // lv
{ L"…Þ" , L"m" },         // mou 
{ L"Ä·" , L"mu" },        // m
{ L"†x" , L"si" },        // ma
{ L"ô" , L"na" },        // zi ma ÈÕ
{ L"ŒI" , L"zi" },        // ma
{ L"Ä¨" , L"mo" },        // ma
{ L"Ä¦" , L"mo" },        // ma
{ L"Âñ" , L"mai" },       // man 
{ L"Âö" , L"mai" },       // mo 
{ L"Âû" , L"wan" },       // man
{ L"Œ´" , L"meng" },      // mang
{ L"Ã¥" , L"mang" },      // meng 
{ L"Ã°" , L"mao" },       // mo 
{ L"W" , L"shi" },       // me ÈÕ
{ L"„õ" , L"mo" },        // ne me ÈÕ
{ L"Ã»" , L"mei" },       // mo 
{ L"ÃÓ" , L"mi" },        // mei
{ L"ÃÕ" , L"mi" },        // mei
{ L"ãë" , L"wen" },       // men
{ L"" , L"wei" },       // men
{ L"ö¼" , L"min" },       // meng
{ L"ü“" , L"ne" },        // zu mi ÈÕ
{ L"Éq" , L"ming" },      // mi
{ L"Ãâ" , L"mian" },      // wen 
{ L"äÅ" , L"mian" },      // sheng 
{ L"çÑ" , L"miu" },       // mou miao
{ L"Ø¿" , L"mie" },       // nie 
{ L"C" , L"ne" },        // o ye mo
{ L"i" , L"ri" },        // mo º«
{ L"ÎÞ" , L"wu" },        // mo
{ L"Ä£" , L"mo" },        // mu 
{ L"Íò" , L"wan" },       // mo
{ L"Äª" , L"mo" },        // mu 
{ L"Íà" , L"wa" },        // mo
{ L"Ä²" , L"mou" },       // mu 
{ L"ÄÇ" , L"na" },        // ne nei nuo 
{ L"ÄÏ" , L"nan" },       // na
{ L"ÄÄ" , L"na" },        // nai ne nei 
{ L"ÄÚ" , L"nei" },       // na
{ L"ÄÅ" , L"na" },        // ne 
{ L"ÄÈ" , L"na" },        // nuo 
{ L"Üµ" , L"nai" },       // reng 
{ L"ßÎ" , L"nao" },       // nu 
{ L"¿L" , L"o" },         // se ne
{ L"ßí" , L"wu" },        // ng
{ L"†R" , L"po" },        // pu ni
{ L"øM" , L"o" },         // ni ÈÕ
{ L"Äç" , L"ni" },        // niao 
{ L"áÚ" , L"yi" },        // ni 
{ L"Õ³" , L"zhan" },      // nian
{ L"Äí" , L"nian" },      // nie 
{ L"Õ·" , L"zhan" },      // nian
{ L"Äò" , L"niao" },      // sui 
{ L"Äþ" , L"ning" },      // zhu 
{ L"Ç‚" , L"xi" },        // nu º«
{ L"ßö" , L"nuo" },       // re 
{ L"Å±" , L"nve" },       // yao 
{ L"Çø" , L"qu" },        // ou 
{ L"Ž‡" , L"xi" },        // pa º«
{ L"ÅÉ" , L"pai" },       // pa
{ L"êC" , L"ying" },      // pai º«
{ L"ÆÈ" , L"po" },        // pai
{ L"ÅÖ" , L"pang" },      // pan
{ L"ÞÕ" , L"pin" },       // pan
{ L"†Ô" , L"xi" },        // pao º«
{ L"ÆÓ" , L"pu" },        // po  piao
{ L"æ³" , L"pin" },       // ping 
{ L"n" , L"po" },        // ri º« 
{ L"ÆÜ" , L"qi" },        // xi 
{ L"Ûp" , L"qi" },        // yi 
{ L"õè" , L"qi" },        // xi 
{ L"Ûß" , L"qi" },        // yin 
{ L"Ù¹" , L"si" },        // qi
{ L"ôì" , L"qing" },      // qi
{ L"Æõ" , L"qi" },        // xie 
{ L"Æö" , L"qie" },       // qi
{ L"Ç¦" , L"qian" },      // yan 
{ L"†é" , L"xian" },      // qian
{ L"Ý¡" , L"qian" },      // xun 
{ L"Á{" , L"xian" },      // qian
{ L"ÏË" , L"xian" },      // qian
{ L"Üç" , L"xi" },        // qian
{ L"Ù»" , L"qian" },      // qing 
{ L"ã»" , L"qie" },       // qian
{ L"È¸" , L"que" },       // qiao
{ L"ÇÊ" , L"qiao" },      // shao 
{ L"Ç×" , L"qin" },       // qing 
{ L"ñû" , L"tan" },       // qin
{ L"äÚ" , L"qin" },       // zhen 
{ L"öë" , L"qing" },      // zheng 
{ L"òø" , L"qiu" },       // you 
{ L"È¯" , L"quan" },      // xuan 
{ L"ÉÖ" , L"shao" },      // que
{ L"Üé" , L"yao" },       // rao
{ L"Èô" , L"ruo" },       // re
{ L"ÝØ" , L"shen" },      // ren
{ L"u" , L"za" },        // ri º«
{ L"t" , L"zu" },        // ri º«
{ L"r" , L"sao" },       // ri º«
{ L"èc" , L"ya" },        // ri ÈÕ
{ L"Ìƒ" , L"sa" },        // ri º«
{ L"’P" , L"te" },        // sa ÈÕ
{ L"Æj" , L"su" },        // sa ÈÕ
{ L"–Ó" , L"ying" },      // sa º«
{ L"“—" , L"sa" },        // sha 
{ L"Ë¼" , L"si" },        // sai
{ L"Èû" , L"sai" },       // se 
{ L"ôÖ" , L"shen" },      // san
{ L"Ôï" , L"zao" },       // sao
{ L"É«" , L"se" },        // shai 
{ L"É¼" , L"shan" },      // sha
{ L"É¯" , L"sha" },       // suo 
{ L"êý" , L"sha" },       // suo 
{ L"Ò­" , L"ye" },        // sha
{ L"ÉÝ" , L"she" },       // sha
{ L"†—" , L"ti" },        // sha
{ L"ÏÃ" , L"xia" },       // sha
{ L"õ§" , L"shi" },       // shai
{ L"Õ¤" , L"shan" },      // zha 
{ L"Øß" , L"yan" },       // shan
{ L"ÌÀ" , L"tang" },      // shang
{ L"òÙ" , L"xiao" },      // shao
{ L"Üæ" , L"shao" },      // tiao 
{ L"®Œ" , L"she" },       // yu 
{ L"ÕÛ" , L"zhe" },       // she
{ L"Éß" , L"she" },       // yi 
{ L"Ò¶" , L"ye" },        // xie she
{ L"Ê°" , L"shi" },       // she
{ L"ì¨" , L"she" },       // xi 
{ L"Ë­" , L"shui" },      // shei
{ L"»]" , L"shi" },       // shen ÈÕ
{ L"Ý·" , L"shen" },      // xin 
{ L"Ê²" , L"shen" },      // shi 
{ L"é©" , L"shen" },      // zhen 
{ L" õ" , L"sheng" },     // xing 
{ L"Ê¡" , L"sheng" },     // xing 
{ L"Ðê" , L"xu" },        // shi
{ L"Ê¶" , L"shi" },       // zhi 
{ L"Ê³" , L"shi" },       // si yi 
{ L"ÊÏ" , L"shi" },       // zhi 
{ L"ËÆ" , L"si" },        // shi
{ L"ÖÅ" , L"zhi" },       // shi
{ L"ó§" , L"shi" },       // zhe 
{ L"Êì" , L"shu" },       // shou
{ L"Ý±" , L"tu" },        // shu
{ L"Êô" , L"shu" },       // zhu 
{ L"Êõ" , L"shu" },       // zhu 
{ L"Êü" , L"shu" },       // zhu 
{ L"Ëµ" , L"shuo" },      // tuo yue shui
{ L"âì" , L"song" },      // zhong 
{ L"ËÞ" , L"su" },        // xiu 
{ L"Ëõ" , L"suo" },       // su
{ L" [" , L"tui" },       // ta ÈÕ
{ L"ÍØ" , L"tuo" },       // ta
{ L"Ì¶" , L"tan" },       // xun 
{ L"ÌÕ" , L"tao" },       // yao 
{ L"À’" , L"yo" },        // zhao te ÈÕ
{ L"ß¯" , L"tui" },       // te
{ L"”`" , L"ti" },        // zhi 
{ L"Üè" , L"yi" },        // ti
{ L"ñÓ" , L"xi" },        // ti
{ L"Ù×" , L"tong" },      // zhuang 
{ L"‚M" , L"tuo" },       // tui
{ L"ÍÊ" , L"tui" },       // tun 
{ L"ÍÍ" , L"tun" },       // zhun 
{ L"áË" , L"wei" },       // wai
{ L"ÝÒ" , L"wan" },       // yu 
{ L"ÞÌ" , L"you" },       // wang
{ L"Íö" , L"wang" },      // wu 
{ L"Û×" , L"wei" },       // xu 
{ L"Î²" , L"wei" },       // yi 
{ L"Î¾" , L"wei" },       // yu 
{ L"ÒÅ" , L"yi" },        // wei
{ L"Îµ" , L"wei" },       // yu 
{ L"ÎÎ" , L"wo" },        // zhua 
{ L"›ð" , L"wan" },       // yuan wo 
{ L"ì¶" , L"yu" },        // wu
{ L"èž" , L"wu" },        // yu 
{ L"‰ñ" , L"yi" },        // xi º«
{ L"³’" , L"ze" },        // xi º«
{ L"ñÞ" , L"zhe" },       // xi
{ L"Ï´" , L"xi" },        // xian 
{ L"Ï³" , L"xi" },        // xian 
{ L"ÏØ" , L"xian" },      // xuan 
{ L"Ï÷" , L"xiao" },      // xue 
{ L"Ð°" , L"xie" },        // ye 
{ L"Üþ" , L"ying" },       // xing
{ L"Ñ„" , L"you" },        // xiu
{ L"Óõ" , L"yu" },         // xu 
{ L"Æ^" , L"zhu" },        // xu
{ L"ñ¿" , L"yin" },        // xun
{ L"Ñá" , L"yan" },        // ya
{ L"ÑÊ" , L"yan" },        // ye 
{ L"Òó" , L"yin" },        // yan
{ L"Ü¾" , L"yuan" },       // yan
{ L"Ô¼" , L"yue" },        // yao
{ L"ôí" , L"yao" },        // you zhou 
{ L"Ô¿" , L"yao" },        // yue 
{ L"×§" , L"zhuai" },      // ye
{ L"Óý" , L"yu" },         // yo
{ L"à¯" , L"yong" },       // yu 
{ L"èÖ" , L"you" },        // zhu 
{ L"Öà" , L"zhou" },       // yu
{ L"ìÙ" , L"yun" },        // yu
{ L"Ô±" , L"yuan" },       // yun 
{ L"Ôú" , L"zha" },        // za
{ L"ÞÙ" , L"zan" },        // za
{ L"‡Ô" , L"za" },         // zan 
{ L"Õ¦" , L"za" },         // ze zha 
{ L"çÞ" , L"zai" },        // zi 
{ L"×Ð" , L"zi" },         // zai
{ L"ÞÊ" , L"zang" },       // zhuang 
{ L"Ôð" , L"ze" },         // zhai 
{ L"Ôñ" , L"ze" },         // zhai 
{ L"×Û" , L"zong" },       // zeng
{ L"×Å" , L"zhuo" },       // zhao
{ L"ßú" , L"zhou" },       // zhao
{ L"×¦" , L"zhua" },       // zhao
{ L"Õâ" , L"zhe" },        // zhei 
{ L"Ö¨" , L"zhi" },        // zi 
{ L"×£" , L"zhu" },        // zhou
{ L"õî" , L"zhuo" },       // zhu
{ L"×ª" , L"zhuan" },      // zhuai
{ L"×¬" , L"zhuan" },      // zuan 
{ L"ºe" , L"zuan" },       // zhuan
{ L"õþ" , L"zui" },        // zi

{ L"öÑ", L"ba" },           // bo 
{ L"þx", L"pa" },           // ba
{ L"°â", L"ban" },          // pan 
{ L"°ã", L"ban" },          // bo pan 
{ L"°þ", L"bao" },          // bo 
{ L"õÀ", L"bao" },          // bo 
{ L"Þ¬", L"fan" },          // bo
{ L"þA", L"gu" },           // hu 
{ L"èì", L"heng" },         // hang
{ L"çñ", L"heng" },         // hang
{ L"ÑÀ", L"ya" },           // he
{ L"þe", L"song" },         // yu 
{ L"àÜ", L"zuo" },          // chuai
{ L"´é", L"cuo" },          // zuo 
{ L"óÐ", L"zuo" },          // ze
{ L"×Á", L"zhuo" },         // zuo 
};

/*
0. ºº×ÖÆ´Òô±í£¬À´Ô´ÓÚ http://xh.5156edu.com/pinyi.html £¨ÐèÒª×Ô¼º»ñÈ¡Êý¾Ý£©
1. ÔÚ'bo'Ìí¼Ó'²·' ; 'de'Ìí¼Ó'µÄ' ; 'wan'Ìí¼Ó'›ð' ; 'ta'Ìí¼Ó'Ëû'
  £¨»ñÈ¡µ½µÄÊý¾ÝÓÐÈ±Ê§£¬ÊÇÍøÕ¾µÄÎÊÌâ£¬ÕâÀïÖ±½Ó²¹È«£©
2. ¨¹ ÓÃ v ´úÌæ
3. ¸üÐÂ
	È¥µô '' Ô­À´ÔÚ'Ê­'µÄºóÃæ 20200410
	È¥µô '' Ô­À´ÔÚ'óE'µÄºóÃæ 20200410
*/
hanziTableS hanziTables[g_length_hanziTables] =
{
{ L"a", L"a", L"ß¹°¢ºÇ°¡ëçï¹åHàÄ…" },
{ L"a", L"ao", L"°¼–À—`ÝE°¾ n°½…ëJÊTåÛâÚà»†õª‡åEéá“³­H´xòüñú°¿ÂKÖ’Ö“÷¡ÂOÏù÷éúqö—üÜ³Ø²Æb’jÞÖ°ÀéOæÁ‹‹Ò\á®CˆÛê°ÁŠS°ÂŠWæñ‹®‘R°Ã‰¥°ÄŽS“ýöËòˆÁ÷`" },
{ L"a", L"ang", L"°¹óa…nÑöŒì°º•n–‹°»ál" },
{ L"a", L"ai", L"°¥°§ÚÀ°¦ŠÖ°¤°£œâàÈïÍæXÞß°¨†ƒùœÜ”±”²‡B°}°©òIÌš±•lšGŠâ°«°ªÜt‡†žGÌ@×cö°ì\°¬êi´°®íÁ³v°¯àÉæÈ‰a°­Û…¥êÓè¨ƒvàæ‰¹‘°‹ÜËBøðg­a•á‘¹°Š²}ñLµK×rèPìaé^ôƒþH÷_÷o" },
{ L"a", L"an", L"³§¹ã°²ó^èñ°±âÖ‚¹ÚÏÈCÈsÈ€‹jÄW¯uðÆÕYÉŽ°°ì”ÖO±QñKõc±Vùgù“í«q†±ëˆƒ‡ˆ°³††Ûûï§••ÞîÁOä@Œßáí°¶°´›¡ÇI°·Øt°¸‹Fë@ˆÝ°µØåBéœ÷ö" },

{ L"b", L"bai", L"’“êþ°× Û°Ù²®°ÛÄ°°Ø–àÞã½]°Ú”[ÒoŽßßÂ’…°Ü°Ý”¡ªW°Þ»ŸËbÙ”ív®B¸q»“ƒÄ" },
{ L"b", L"ba", L"R°Ë”°Í°È–[«X°Éá±’U°ÅŠB°Ì–ÂášÍMôÎ°Ê°Æ†^ÁjØ^÷„…©ÜØŠ‚°ÎžßÃ_°jÝÃÝRÔy°ÏïT÷Éü–°ÑîÙâZ°Ð²®y°Ó°ÖèËˆ¢°Õ°ÒÚ•öÑÁTõEþxÒ†³Fþw°Ô‰Îå±™ñ’iæŽõ•" },
{ L"b", L"ban", L"°âÃR”‘°à°ã°ä°ß”Ê°áîCøXñ£ÎŒÑ—ñ­ÞnÚæŒêÛà°å°æ•L­šîÓ»{ô²âkÎZô‘é›°ì°ë°é°ç°èŠ”°íˆmE–®¶t½Oœ°ã[ì‡Þk°êÎ†" },
{ L"b", L"bang", L"°î°ïˆ °ð’Êäºß™Ž°ŽÀ¿RŽÍíD°ó½‰°ñ ¥°ò«g’²ÅÔ°ö°ô—”°ø°ùÝò“s‰Y¶œÎM°÷°õÅÖræ^" },
{ L"b", L"bao", L"Ùè°ü°úæßÅÚ–¢°û°þ„ƒ¸öµìÒÑf°ýÊ}ÒJé–ý_·‘±¢±¡±¦±¥Að±±£Œp«’Ýá±¤ˆç‹~Œ‡ï–ï’ñÙñhøRød¾‹Ù…Œ—Œšìd„ôÅÙ±¨±§è˜±ªõÀÍdÇ˜ÐˆˆóãE±«óbóŽ±©Ì™õU•Þƒ˜ÆÙ±¬ ÝÆØÞètÜË" },
{ L"b", L"ben", L"±¼›yêÚ Äï¼åQ±¾±½ŠMÛÎÁ—ñº»ÛÐ‚–ßG—L±¿’Ùœ`“à" },
{ L"b", L"bei", L"Úé±°±­–È±³° —G—À“d±¯ðÇ±®Ëùl±±ãm±´±·ØÃÚýØ ´•KÆp±¸àT±µ±»±¶‚pªNã£—f‚³‚Ëàf¬D¬i±¹ÝK‚äƒF—”±²±ºÝíÍ“íÕÊ¶F ÍñØÕRì‹ócä^Ý…¼L‘v÷¹öÍ†h" },
{ L"b", L"beng", L"ÈµpŠR±À±Áéa½l¯nÐàÔ¾X¿‡±Â®gˆ©ˆÈÈE¬e¬aìž±Å±Ã°ößJ“g‰lê´éG±Äça" },
{ L"b", L"bi", L"°nŒÂ‚¿±ÆšÈ—é˜[ØPùSÎ“÷”æqösÝ©±ÇØ°±È–a‰ýßÁåþ›aÓ¯H±Ëš·–©ïõ±Ê»zô°ÙÂ†ž¹P±É¹uÂØ„±Ò±Ø±Ï±Õ±ÓØ×ÜÅß›ÞˆfPWÆƒŠŒ…ñÃÚî¯®nßÙÜê±ÝêÚ±Ñ–Ä«¯RÃØîé±Ðáù®…Ð‹»¸“é]é[æ¾âØÝÉÈ]—a±ÖÚPˆãÏã¹°zµ–åöŒœ ÔvóÙÙSÙCÍšñÔ±ÙõÏésïãGääœü†ô’±ÍÉœÄbî¢²D±Ô¯wŸ•ŸÎ±Ì±Î±×àŠªŒŽÅ¾aóë¹vñEóñƒÒKŽÆ§ÁXª‹±ÚYæÔ±ÜÞµó÷º`¿oÓvõIÛ‹÷Âå¨”À±ÛŠ`ç@ð{àˆèµÀVÒgôÅíSôxí{ÜLÜKòúzèEÚF–Cú‡ü„ÈZÍŒ‹ï" },
{ L"b", L"bian", L"±ßž×í¾óÖÈq±àªpìÔ ¤®K¹òù¼D¾Žì™æQöýª ß„ß…±Þöcöb»e±á±âñ¹ØÒÙHÆñÛ·HíÜøuËx±åÛÍ’\›MãêÜÐáŠâí«f±ä‰ä•c±ãÒŒÌ±éçÂ“OérÞgÕ—¾œÅŒ±æ±çÞl±èÞpÞq×ƒO" },
{ L"b", L"biao", L"è¼±êì©óT÷Ô±ëœWªYÃ ïRœý“¿æôÊEŽ¼‰wû˜ËŸÏ±ìïÚñ¦´‚ì­ì®ƒšï[Ö€Ë‘žd gçSÙ™ÅA·…ïðïjïkïlïnèsóQ‹›±íæ»ñÑÕ•ålÒF™~‚l÷§ä‰" },
{ L"b", L"bie", L"±ï±ñÏh±î°T÷Mü‚Ì‹ý–±ð„eÇaÍrÖÒXõ¿•" },
{ L"b", L"bin", L"ß“çã±ö±ò—€—ÃÙÏ±ó±õçÍÙeÙfØhéÄ¬žïÙƒ†±ôîláÙžIžMÌž­p™‰žlìEÀ_Ï™è\î ±÷éëë÷ó‰ó”Pš›Äœ÷Æ÷ÞóxôW" },
{ L"b", L"bing", L"Ùû•šê²¢±ù±øÆÁ–Þ’òéÄ±ûÚûêvÆuT’m±ü•\•m±þ±ú±ýç®±}Ís‚§Œ}—ŠâÙ÷·AãuïžðVí@ŽÕKãŽð‚v–â¸p²¡·’‚ìÞðÕ@õmìhˆ—ì" },
{ L"b", L"bo", L"²·°h°i²¨²¦²£âÄ²§±C³j†\°þ°ãõÀÀ¼žÑC²¤à£œÀ´Bã\öÑƒ`Þ¬ó²¥“ÜðGµRÜ@ò’÷Q²®²µØÃÃJ­“²´ þ²¯àR²ª‚NÃ`°ØÑB­”¶zîà²¬›Â’©ÙñÈ`œ_²±ÑJ²°ð¾²³È•²©ªtñAö²«â“ãK÷ˆÆÇñCñgÅ‡²­ ¦Ÿ¹²²ƒkéDõÛäcñFñ•õN±¡ÖcÒUº~ðoùPæn‡¥‘Åómóp¼\Òq™Øíçè}õËô¤ŒXéÞë¢×LÌY®zÊN" },
{ L"b", L"bu", L"åÍŽïmîßêÎâ˜ÕcðJåqøGÞKõ³²·ß²²¹²¸²¶±¤ÑaùLûQ²»²¼…ÄÑ²½šhši²À…ùîÐ–¿‹²¿„Ï’ÃÆÒˆ¶Ç[²ºê³âbÉžEÛYà^ðXº^²¾Ž~" },

{ L"c", L"ca", L"²ð²Á”càêíåµgßnk" },
{ L"c", L"cai", L"‚Æ²Â²Å²Æ²ÄØ”²ÃÀuš¶²É‚š†’ŒuŠé²Ê’ñˆÆ—²ÇÛP¾Z²ÈŒq²Ë²Ì¿n" },
{ L"c", L"can", L"²Î…¢…£æîï{œ’…¤†Ð‚ð‹Û²Íò‰²Ð²Ï²Ñšˆ‘MÎ]‘LÐTÐQ²Ò•ü‘Kþp‘”·_ºd÷õüo²Ó²ôåîôÓËLÓ Nè²Öƒ… |" },
{ L"c", L"cang", L"þX²Ö¨Ø÷²Ô²×û]²Õ‚}‚áƒûœæÉnªÈÏ@Å“úIê°²Øè†Ù‰žP" },
{ L"c", L"cao", L"“Ù²Ù²Ú•ù²ÜÉ˜àÐæäî‘F²ÛÒGó©ô½ç[ÆH²Ýó‘¨òxÃHà“Ò_ü" },
{ L"c", L"ce", L"‰÷²áƒÔ²à²ÞÇR’‘²ââü”˜»¸žÈY…‹‚ÈÈm²ßœyŽúÅ¹k¹ZÉƒ¹‹‘Šºuªe³€" },
{ L"c", L"cen", L"²Îßá¯ä¹ˆ¨¸’—q" },
{ L"c", L"ceng", L"àá²ãÔøŒÓò¸}òš²ä" },
{ L"c", L"cha", L"²æ’Q’Kè¾Åa²î’·‚²âÇ²å“c†âÔûïÊ²êã˜Å‘®›àêåšðl²ç²èˆ“²é–Ë¶gâª¿²ëìxÔˆé«é¶²ìéßñÃÛ‚ïïèdŠgãâ²íÉ²÷²ï„xæ±ßå¼pÔŒ" },
{ L"c", L"chai", L"ÆOÃPîÎ²ð²îâO åÙ­²ñ²òµ}†¶ƒŠÆò²ÓÐƒðûÏŠ‡Ð" },
{ L"c", L"chan", L"Þ{êè—{²ô²óÒ—Ñg“½äiŽÊÒb”vÆgµ¥²÷æ¿²öœµåî—ìøŸž²ø²õª†ƒ]ÕSäaƒ{âÜ‹Èäý¨¿Cå¤´vàšÏMš´Ïsžeàžƒ§ó¸„­‰Ê‡ÁžŽf™ÙÀpÀsõðéKÆB×‹èð’²ú„i•CP”â›º„}ÚÆ²û²ù®a®bÝÛ„•“˜IÊrŽÂÕ~éˆæöŸíºoÙæápÀAçPÖêU‡Ïž¬×€âã³ƒ“·‘Ï²ü‘Ôåñí]î" },
{ L"c", L"chang", L"Øö²ý³«‚tÝÅãÑæ½²þœC¬dè Ñmå_é‹öðöKü³¤Ÿ ³¡ƒ¸³¦ÜÉéMéL³¢ÌÈ³¥ÈOáä³£®DˆöÄc®^ÉÑ‰jæÏ‡LÄq¬ ‡Ÿƒ”÷•÷l³§êÆã®³¨…”ƒYSë©äâê«`³©ÛË³ªŸ…•³®˜Õkío—ÇÏ^" },
{ L"c", L"che", L"³µ¼Ü‡‚eíºÇp†q³ŒÍ’³ß³¶‚®“Ýåø³¹ÞŠÛåŸEÂs³³¸îJ³·³ºØ²u„ï …" },
{ L"c", L"chao", L"³³³­€â÷™ù³®´ÂÔN³¬ânìÌ½Ë¸S ŸêË³²Žz³¯ü…à}R³±˜È³°¸JÁVü{ÞCÖš³´±|ŸqŸ·ûžŽlž£ñéÓe" },
{ L"c", L"chen", L"ÞÓ³»’×—²è¡àÁ¾DÙoÕ€²_Ön³¾³¼³½³À³Á³ÂÞÆÇ_Çkå·ê–×—FÚÈÔHÜ•”³¿â\×Ÿ‹Êc˜¹‰m”´¯„ëÖRÏIËlû‰•æúmÚ’³•í×‰}‰öÛ{´~åŒÙ•³Ä¯M³Æö³³ÃÚfé´ýYýZƒ¡Úß‡¸™ÂÒr×ŸG" },
{ L"c", L"cheng", L"êp›„ èß—¢³Æ³Ó›Õ¬b‚ îõ³òÉ•˜ ªÚWìl‘r·Q“£³Å“ÎàáéÌ¿BîdÚXîª˜û™f¸VÀ˜Ï|·çpç•ð‰Ø©³É–b³ÊàJ³ÏèÇ³ÐÇ^ŒkŠ¿w›“³Ç\³ËÛô’¬¬A«ž·œ’ÞÃ”îñÊ¢³Ì“ZˆáñÎ½†¹f³Í—¼—–Õ\ëó‰SœËõ¨ä…®—³Î¯‘~³È™ržj‘Íòr‚D»³Ñ³Ò‘Žñ±òGõ“" },
{ L"c", L"chi", L"³ÔŠw«ßêÃqð·ò¿»Œó×í÷®E†ËÔW½‚àÍæÊ“¤³Õ²lš“‡iÕvó¤ø|ùA÷Î°Výc”~¯ü[³Ú³Û³Ø³ÙÞ‹ÜÝÛæ¸‡ÇK³Ö³×ÍhÚdÙPßW¹MßgñY¹}Ü¯kßtõØóøå~Ös³ß…µÀ…ÕÃL³Ý³Þ…qˆ‰ÃnÍN³ÜuôùÑEšnšIÑDÑlãrýXñÝáÜß³³â–o³àâÁžÃ’xø„Èp³ã„Ð³áÁ‹ë·ŸUœ‰à´ï†ë†ÙÑÄS¯vãMã‰Â@¯€ßo‘yñ¡‘JÂBŸëÚ†‘´ùúuüJ" },
{ L"c", L"chong", L"³å³ä›_âçÜûÓ¿›Ò«–Áˆô©†ü“›ã¿Ðn‘oÁZô¾ÛŒ³æÖÖÖØê™³çƒrÑ~Îu¾…Ïx ‚³èˆÃŒ™ï¥“_ã|" },
{ L"c", L"chou", L"³éþr¼—“oºNñ¬ ß â³ðÙ±àü–äÇ“³ñã°½[—¹³ë³î°{³í³ïÔ—³êáOÑn³ì¾Iëlƒ‰Ëg‘ÀŽÎ‹á™„ böÅ® »Iá~ÜP×‡×‰ë|³óE…Á–ƒ–„‚¸³òáh²ƒô{³ôÅWßcšŽõ\" },
{ L"c", L"chua", L"šH" },
{ L"c", L"chu", L"³öŒç³õ“¹éËØŒýiÛ»´¦Öú³ýÆc³øÉZØa³ü³ú³ûãIÚnÉe‹ƒòÜÂa ËäzºXN³÷™ŸŽÐ³ùërõé™»úRÜXèÆ´¡ÌŽ—Æèú´¢µ—³þñÒéƒ¦™sµAýsýƒØ¡„I¸aØXç©âð›{¸e™úÐó‚m”™ˆÇ½I¬G‚âàsœä´¤´¥ézÕ‘ƒ‡bãÀ”ß÷íÄ•šbÓ|´£˜Z­lÏ{" },
{ L"c", L"chuan", L"çÝ´¨ë°´©¬´«ô­Åx´¬„”å×´ª‚÷•Äº@ÝŽâ¶ÇF´­šNƒbÛwšö«[´®îËâAªkÙiúE" },
{ L"c", L"chuang", L"„V´´´¯·™´° ¡“œ §¯¸R´² —´±‡l´³‚ü´}êJâë„k„y„€„“í" },
{ L"c", L"chuai", L"´§ÞõÄuþŽà¨àÜþŒëúõß" },
{ L"c", L"chui", L"´µ´¶ý—´¹ˆ§Úï‚…–ûÇ”´·“€é¢×µ‡ùÄD´¸é³¹ŠåNæmîq" },
{ L"c", L"chun", L"•I–~´ºÈN‹a‰@´»˜‡•«¬tòí¹—Ý˜êþ”™šùœöj´¿êÝ»´½›Ì¼ƒÃ‹´¾œ· ÆðÈœ÷ÉOÉ”_´¼ácåTù‡õž‚¤ÈoÃ²QÙƒ´À" },
{ L"c", L"cong", L"´ÒÜÊ´Ñ‡èòÆ‰èÈS•—Œ´Ð˜BÊ[Éæõ^Â‡´ÏÂŒŸÐœ˜º˜Ú•¾­Bè®²jÏZÂ”ºbæCÀSçWçEò^ò‹´Ó´Ô¿¾ÄÀŠæäÈ›ŒQçý|YÙzÙ{ÕpåS˜âËq…²žš™ß ß‘mÖ" },
{ L"c", L"ci", L"´Ì²îßÚ«u´ÃÚe‚½Úód¿WóqÏ…ý€´Ê«yÜë´Äˆˆ–²ìô×È´ÉÞeÔ~´Ç´È®NðË´Å´Æð@ï“ôÙÞiËF‹ãžBøyµQÞoú]ú\´ËÕ›°rõJ–c´ÎËÅè„pŽãÆ˜–æÇ„´ÍÍy½aÙnÎˆé^" },
{ L"c", L"chuo", L"ßOÚ}õÖ´Á¿žåÁÞu†dŠÆŠÅ‹S‹Cà¨›í´Â·ê¡áQÛU¾bÝzöº“óðU´‡šf‡Çýpèq" },
{ L"c", L"cu", L"I´ÖÓcû€û‚™[û›áÞéã×ä´ÙÃâ§õ¡‹{¯|ÝýÚuÕK´×‘–È¤Ûq‡m¯•Û€¿q´Øüyõ¾õíÜAî•" },
{ L"c", L"cou", L"´Õœê£é¨ëíÝ" },
{ L"c", L"cun", L"ß—´åñåÛZ´‰–¸€Ä~´æü’Ž¶×„Yââ´ç»v" },
{ L"c", L"cuan", L"Ùàß¥ïé´Ú”xÜfè‰ÇˆÔÜ™«Žm™ç·‰´Üš–Ÿä´Ûºx¸Zìà" },
{ L"c", L"cui", L"´ÞÃœÅƒþ´ßÀŠ‰…‘NéÁª‰´Ý˜§´…¿\çJyè­Ú~°„ºõ¯Q´àÃy‚y»‚¼ÁŒÝÍßý†Ÿ´ãã²Ÿnë¥¬X´á´ä¾\´âÄ‹Äƒ¸WÒPûîxÄ›" },
{ L"c", L"cuo", L"´êßu¬›´è´éáiõãæ\Ì‘áÏÕ±‘ðîÉcïóÊPðûõºàŸûzëâ„v„zÇsÇuØÈ´ì‰è´ëßHï±´íÉxäSåe" },

{ L"d", L"da", L"…ößÕÞÇ¸—´ðàª´îñ×“Ò‰¡‡}æpæ]´ò´ïÞ…Þ‡Þ‰âò…ìæ§í³ÇQÇEžØÁe®}®†µ¬…A„‘ßQóÎÔzß_ÛQ÷°´ñËR÷²ÏƒèNí^ý‘ý“´ó‡šùˆ™±o®zÀJÜJùŒ" },
{ L"d", L"dang", L"µ±«šñÉîõ¹Y®”ƒ}‡ŽÇ­cÒdÏ}Å™ºšèKêWµ²µ³ÚÔ“õ×[üh”†žª™é×•šëÛÊˆWå´í¸µ´ˆ›µµÝÐ‹PßTÕ®Gë‹É‹´X²^ÚÊŽ‰³™n­T±UµDº‚Ìo" },
{ L"d", L"dan", L"µ¤Šlµ£µ¥…gíñ³Nµ¢Ânµ¦ñõÜláG†Îéé‹[ð÷…SàîFÑóì„éÙÙš—“ú®XÒRº„Â›„[·’b­«mµ¨Ðy¼ðãµ§êæñd“Û“ÚÙyü^Ä‘ülürµ©Ê¯Žµ«µ® ý››X–½†m¯Dµ°µ¯µ¬à¢†›µ­ÝÌ†²ŽµªÍžÄEÓgÕQ·žÉ…ƒd‡nó‡‡d—‘„‘ž¶Vå£ñšø}ðZ°D°QÀWÙœ‡·ð…ìK" },
{ L"d", L"dai", L"´ôß¾´ýªy‘·´õšx´þ´ö´ó´úÞaß°þåÊŽ‘ææá·çªˆ‚´û´øçé´ù–±µ¡ÜØ–Ž¡Ž§Ü¤Íf½HÜ–´üÝDÙJ¬xÛFK…¦•ÎÎ}¿Døl÷ìÅ•´÷º‰žŽìOünÒyì^" },
{ L"d", L"de", L"µÄ‡NzµÃ›ú—‘¿œï½ÔµÂåuµØµ×" },
{ L"d", L"dao", L"µ¶ØÖß¶âá–]ë®Åsá’÷ô€ÏC’Òµ¼µºê‰uµ·µ¹µ»µ”“vëIëìŒ§ëZŽW”F‰»µ¸¶\Þxµ½àüµ¿ìâÈKµÁ±IµÀÁŸ·Rµ¾‡‹ÅÐmÐp™| cÂRÜ„­ôîhþO—Í˜˜" },
{ L"d", L"dei", L"‡NµÃ" },
{ L"d", L"deng", L"µÆµÇØOƒ\àâ‹¿Ÿô­O¸~ô£µÅµÈê­µËà‡ëQµÊáØ³Î‰œïëµÉíã™žÓRç‹Å˜" },
{ L"d", L"den", L"’O’Y" },
{ L"d", L"dia", L"àÇ" },
{ L"d", L"di", L"ØµªµÍµŠDI¶~Ð”êôÆˆ¹†¬µÌÌáÚhµÎàÖïá´”íLfµÒÆmµÏµÄÙá†vÝ¶µÓµÐ—b†µÑì{êëœìóƒñVîEµÔµÕÊHÊL˜µ”³Ë‹‡”ØpÛ—çCÓ]¼eûM…}Û¡êsÚ®ˆkÛæ~µ×…àµÖ’†èÜ ¹íÆ’ãÇœÝBÓhÔg÷¾Â‚öWµØˆh–m•AµÜ«ZÆl–šKˆªµÛ‚dæ·µÝÞžˆ¯ŸbÚÐ—\µÇ…‚±±ƒ«ŸµÚâKíû“W‹XµÙé¦µÞ˜N¶EßfƒCÄVãdíÚÎ[“ŸßrÊO‰—‰„®SÎy¾†‘dÖBÛyŽRÏE‡Ã" },
{ L"d", L"die", L"µùµøÒBÆ|µü†AU’¡À„Ûìg•iÃ]ð¬±yÂWµý±‚‘ä½xÅ\éPÔeÚgÛ@®’à©ñóÂÜ¦ÞéšŠµþ˜G šëºÛLµúÑÎHÞµûÅŽÕ™õÞø‡®ÏHöøÛ•è¯Aöl¯BšÛ†OŽ²" },
{ L"d", L"diao", L"µóµðšô„aÍ@µò¬ŠP‡Íqõõ¬høJµïõM²fåcöôµñºyü—õ ùmÄñ’FŒÅtµõ®µö±@·–ÓŽµ÷îöï¢µôážây¸uÉ‰äHã“ëô†Õ{¸L¯šä”ËyèS" },
{ L"d", L"dian", L"”“µà…Ž‚ÙÑµá˜ˆ˜•¯’µßÛ†îîŒáÛñ²Žo”„Žp°dý‚µäŠHµã‹L”¥µâÉ_ÊsõÚücµçµéÚçµèµêÛãµæ‘úçèîäµëŠûµí¬UµìµîâšÍŸëŠ‰|‰«Õ˜ëµå´ñ°ô¡ò›—Ï" },
{ L"d", L"diu", L"¶ªGîûïMäA" },
{ L"d", L"ding", L"¶¡ØêŽŠ¶£çà¶¤¶¢ðÛî®ÍBñôôúá”ìwÆJŠc¶¥í”¶¦ü‡àìËYç–¶©ð—â³G¶¨Ó†ï}îúÈbà¤—Åëë¶§íÖ´OåVîr´" },
{ L"d", L"du", L"… „†¶¼ê^¶½à½á`êA¶À¶¾¶ÁäÂë¹èü¶¿ÑtÕiåLªš„E…X‹óž^šœ Ù™³ ©­{°òy÷ò÷Çí~×xÚGØKèoíbíüt×˜¶ÇóÆ¶Â¶Ä¬o¶ÃÙ€ÓGºVÜ¶¶Å¶ÊŠ¶ÈÇT¶Šì|¶É¶ÆÎ–åƒš˜”¾ÐCó¼…¶ª–" },
{ L"d", L"dou", L"…Ê„r¶¼†t¶µƒÃÝú™Xóû†z¶·êh¶¶–’î×¶¸ò½â^…¼¶¹àK¶ÁÇW¶ºð›ÃôYäÂáHšÃ—uÃ–¶»ékñ¼ôZðL”ÔêL¸]ô^ô`ôac" },
{ L"d", L"dong", L"¶«¶¬–|ßËÆ{á´•kë±ð´‚”Ç‡ž–›òˆÄŠà¸•šæÎXõ[üŠöCù…¶­Ê‹Ù¶®¹šÕ‰¶¯¶³¶±Ûí¶²¶°ëËÞ“ŠŸá¼’œ¶´ƒöëØ‘ã„ÓíÏœ§ÄL—ƒPñŽëšúH" },
{ L"d", L"dui", L"ˆŒ¶Ñ‰[¯y´qø‹çŽç…îX¶Ó¶Ôƒµƒ¶Œ¶Òµqí¡êŒê ¶ØíÔ½˜Œ¦‘‡í­åTïæËcžA‘»ž}×B×mÞV" },
{ L"d", L"duan", L"ÂZ‚Ç‹e¶ËÑƒæH¶Ì¶Î¶ÏÈ˜¶Ð‰FìÑ¬‡Äaé²¶Í´V¾„š¬óýå‘”àÜY»f" },
{ L"d", L"duo", L"¶à‰ïßÍ¶ß„„¶ÞšÇ”¦”­ñÖ‡š¶á¶Èîì”£”Ÿ„‹†Æ¯kŠZ„AÉõâèIÍÔ¶ä–\–mð™¶çãõßá’—–Ã–ª¶âˆ‘ˆÊç¶¶æ“¶è‹s—Ù¶ãÜoÚr¶å¾EôDÜ€‡¾Šb„mêwêy’–Œ¹–ú¶éÛGï˜‰™‘†‰šùzþKâ‡öV" },
{ L"d", L"dun", L"¶Öª¶ØÎP“æ¶Õ‰•‡“Ç Ôïæíâ¶×ÜHò—íïõ»ÜO¯ŽÝãç¶ÚìÀÞš¶Û¶Üí»¶Ùâg¶ÝîD˜Jßq—ŸõÛv´]‰Ý" },

{ L"e", L"e", L"°¢ŠŠŠŽŠãæ¹åí¶ïÞˆ…Å‡ê¶íS¶ëk›á¶ñ¶ðÝ­Å¶«Óžâe°xï°±“¶ì¶êÕM´d‡fä~îPô‰¶îî~ùZù[×F¶òêqÜÃßÀ¶óéî–•ÛÑ³b¶ö°·ãÕ¶õÚÌÝàß]¶ô¬ãµíëñïÉðÊîOð_Ø¬öùòF‘öŒï…Ù³X³S†H†@Š´„þÍLÜ—³r™…v‚­ˆ×ˆìˆñœŠºÝQØ`â…¬cŽþ“~“ƒiÎYÊ‚ß{ðIò¦é‘”AÖ@ÓFåŠî€šdµJ™Äù˜ötöýL×†ý|èy÷{˜…ÍŒ”ñùEÒk™ë" },
{ L"e", L"en", L"ŠC¶÷ÝìŸ¸WÞô" },
{ L"e", L"ei", L"šGÕO" },
{ L"e", L"eng", L"íE—Ò" },
{ L"e", L"er", L"s¶ù¶øƒ¹êzõÇHÂYX›˜–éÃs†„ð¹ÑLÂxÝ[öÜó’ëXøõbÄžÞW¶ûŒ©Œª¶úåÇ¶ü¶ýš¾–êçíîïãsðD –ñ“Ënßƒ¶þprÙ¦„n…þ·¡Ù@ÙEÐ^Ô ó“˜Þ»•Ú" },

{ L"f", L"fa", L"·¢ƒì›o°k°láN‘·¦·¥Š‘ˆzÛÒÆž·§¯V·£–ì¸Ÿ·¤‚ë²XÁPéyÁU‰˜ìËtá·¨cíÀžž·©¬móŠóŒÊ†›¹åz" },
{ L"f", L"fang", L"ØÎ·½Úú·¼›P·»èÊ °îÕÍKœEÚ“â[åpøh·À·Á·¿·¾öÐô™·Ã·ÂáÝ·Ä•P•X­œ±f¼ô³”ë‚ÔLó„úJ·ÅˆÚ" },
{ L"f", L"fan", L"·«é®‰·¬„åÞ¬á¦‡h‹Ì‘Œ”ó”õ¿œ·­·ªÞNïcïx»O÷Y·²„G„F…K–i–¯·°·¯»oÅtÅwñÈ·³¹BâC—¡Ÿ©¾u‰“·®­[Ä‡ËXìÜÒT·±Á€õìçxµ\ÞÀž’Ï›ú‹þP·´’B¢·µ˜õ·¸šïšøŠi·¹·º···¶î²ÜÓŒØœ¹D±FèóÝGïˆï‰J‹Ë¹ Ý™ž~" },
{ L"f", L"feng", L"·á·ç„K§„NŠ~ãã„O·ã±`·èí¿·âïL·åo‚ª—Q·éˆýÝ×¥œtªh·æ È—÷·ä´^¯‚ºAƒtà•äh™lØSæ‘çQÛºÌtŒ›ž–ÐIìbïpüK·ë‰â›h›Í·êœ½ˆùñTÅ‚m·ì“ž½ ¿p·íÒƒßôÖS·ï·îÙºœ˜ŸuŸ‘ÚRøLøPøiÙˆ¬S" },
{ L"f", L"fen", L"·Ö·ÒŽŒ·Ô·×·Õ•SçãÐv¼ŠÁ‰ÜmÓŸ·Ó—±—râpëƒñBði–BðŠ}Œð·Ú·ØžÇ–D–ŒÁiÍ_Í`·ÙèûÉkëVôšÊˆŽËªŠ‰žåŸøŸþ™JØk÷÷Á‚ü‹ØrÞMèMñOüR·Ûüv·Ýkˆe·Þ·Ü¶lÙÇ·à·ßƒf‘ÄŠ^¼Sö÷å¯÷a¸j²b" },
{ L"f", L"fei", L"þT·Éåú·Çïw·Æ·ÈŠóŠôœdç³ìéªU•›ìqÑqòã¾pöîö­ñIð[òWòaöEïy·ÊäÇëèÎN–FÃd·Ë·ÌŠOã­—’ì³ôäé¼Ê„Õuóõ·¢ÜÀ·Íáô·Ðâö–{·Ï·ÎÃ^•h·Ñ…Š„|êŠ‚n¯XÈQŒÐŽüÙMðòïÐU•Õ°Cü”ÏnžO™¶çšì]" },
{ L"f", L"fou", L"¼€ó¾·ñŠvÀÀŒë€š†ø]" },
{ L"f", L"fo", L"–·ðˆu—‚" },
{ L"f", L"fu", L"·ò¸ß‘æÚß»ŠmŠ•«c·ôÃi³QÐuN–´ÇCÇXŒ ŠÂ”êôïõÃ¼”õÆâaïû½š¹[à~·õ»™ÄwøWûŸ·óüA¼JüF‘ÊTŽˆ¸¥Ùì·ü®i·ð„_ÜÀÜ½Æ]·ö·÷›Š@ç¦ç¨…òŽ“ÜÞÆ…–Žâö·þí‚·úìð«s–¢–ÁžÞ®w®tî·ÜòÛ®øI·ýˆŽ›š¸¡†bÝ³ò¶Ð“–óíÉÁèõŸJ¬M¸¤Ì’åõ¼›½E·û¹AÝÊÙë¸¢·ùÈƒ½nÁJ—­øDÅ€ãRãVïO·ø¸£òÝ½•¹…·J˜_íhØfó‘øqòðá¥ºÝ—Û~õHÖDíêÒL¯žõvÒiùfù›Úâ¸¸¸¦¸§ÞÔ}¸®¸«àM‚a‚Y¸©¸ªáœ’Ñ¸¬¸¨¸­±GŸrÍ—äæ¸¯Ýoî\‡`“áôfº…öUíë¸¼¸¶¸¾¸º¸½·¸Àæâˆ}¸c¸·Ó‡Ø“¸°¸´µyTÐ•ÍbÍk¸±‹DŠïƒå‚¾¸µÍÈi‹c¸»¸³Í|¶Ò„ÔcöÖ¸¹—Ú¸¿êçÑ}Ñ‡òóÎl¾”ÊÙxñ€õVÝ•‹Ñ¿`ÙŽöûå‡å˜ð¥¸²öváKþE—Ó¶O" },

{ L"g", L"ga", L"¼Ðê¸Ù¤ßÈ¿§¸Â‡QÔþîÅáæÙ¸Áåm«VæØÞÎôpf„LÜ…" },
{ L"g", L"gai", L"ì¸ÃÚëà@ÇDŠ¡YÛòêà•|µ‹®„½wëBÙWÙ^ØdÔ“ã¸Ä½iØ¤_„÷„ø½æ¸Æ¸Çâ}“©¸ÈÈ‘Éwê®¸Å˜¢[˜£­y" },
{ L"g", L"gang", L"¸Ôƒé¸Õ¿¸¸Ù¸Ú¸Ü¸Øþbþh¯I³M ±Œù¸Ö¸×î¸„‚ˆÕ’ââG Â—ž“•ˆþÀ“¾Vä“æs¸ÛŸ€Ÿƒóà˜í°‘Þ‘ß" },
{ L"g", L"gan", L"¸É¸ÊÞ|¼éå¸Ë”«\¸ÎŠ›ãïÜÕÛáí·¸Í¸Ìôûðá»ˆ„QÞÏŒ¼¹møNlŒ¿ŒÀôvœÆQ°‘Ðr¸Ñ¸Ï¹C—U¸Ò¶’¸Ðä÷ÚséÏÚß¦º•÷ ÷h›Nêº±Yç¤ƒ÷‚‰äÆ½CÔló_ŽÖ˜o™gÚC¸ÓÚMž¸" },
{ L"g", L"gao", L"¸á¸Þ¸ßÁoó{°wÅV¸àØºéÀ˜°™R¸â¸Ýðpíz™²üŽúkú‰ùê½Ç¶Ž¸ãçÉéÂ˜‚•±¸å·X¸ä¿cÞ»Ë›™æ€¸æÛ¬„ÆÚ¾zµ†µ‡ï¯¹lÕa¶Jä†…Ì" },
{ L"g", L"gei", L"¸ø½o" },
{ L"g", L"ge", L"¸êØî ç’MæüÛÙ‘áÃI ³¸íð›¿©¸ç¸ì¸ñ¸ëñË¸é¸îœð¸è‘ëøwøÖg”RæŠ…Ï„ýàÆŒ¸ó’š¸ïØª”š¸ð¸ôÑ\¸òÍxÅZÍÓkàÃœèÜªë¡˜†ëõéxéwì‘÷ÀíkïÓª˜ÖYÝ‘õsækíuòZíRÞP¸öºÏ¸÷ÛÁ¸Çô´†ñò´‚€¸õíÑ¹wãtgŽ|…¶†{™ " },
{ L"g", L"geng", L"¸ü„j¸ý®u¸û›ÊÈ@âÙŸ‰½cûf¿K¾ÙsÁ}ùˆ¸þàQÇcßìy’ªç®¹¡¹¢¾±¹£½Žöáóiõ†ˆí•œ—Ô" },
{ L"g", L"gen", L"¸ù¸úßçôÞØ¨ƒÝ¢“^“j" },
{ L"g", L"gu", L"¹À–q¹Ã¹Á›}¹ÂÆ‚¹¾ßÉéï–¾¹Çð³ÁB†f†g¼ÒÝÔ¹½òÁ¸šÝLÝMõý¹¼ôþÉuâì±¶™¹¿¹‡ºH‹²™OøõY÷½‰à¹ÅÚ¬ãé¹È¹É¿àêôÁl¼ÖîÜî¹¹Æ†˜›üëŒ½ÔbðÀð â’˜€þA¹Äü‰˜bØÅ°–·Y¿S¼MË[žJëû°›ðkÝž±Wî­žkúXÐM¹Ì¹Ê¹ËƒóêöèôáÄˆØ—›¹ÍµïÀðóƒlådöñöAî™ßEÃ™‚ï" },
{ L"g", L"gou", L"¹´¾ä¹µØþèÛ¹³¯YÐâhçÃã^œÏÑ¾—óôº÷¸íxÆa¹¶¹·á¸ÂTÂV«vÍmóÑÂUØxÚ¸ˆx¹º¹¹Š¥¹¸ƒÚ¹»‰ò†ŽÔ_ÔëgåÜì°æÅ“kŸµêí˜‹“ÂÙÓM" },
{ L"g", L"gong", L"¹¤¹­¹«…šþ^¹¦¹²ºì–r¹¥¹©ïëÅ¼k¼n¹¬Œm¹§ò¼¹ª¹¨…@Ž³ã‰bö¡Üp‘E…C´bó•ÓyýŠýÞÃ¹®¹¯¹°–í’çîÝ\ì–þg¹±†yØ•†ßŸË¸Ó" },
{ L"g", L"guai", L"¹Ô“…¨¹Õ–Ê–¡ÁL¹y‰ø¹Ös" },
{ L"g", L"gua", L"¹Ï¹ÎßÉëÒèé—Ið»šOŸ°Úo„œ¾ Û|ïWøŽòmƒÖ…³¹Ð„Ž¹ÑØÔÚ´ˆq¹Ò’ì†§ÁG½\ÔŸ¹ÓïN" },
{ L"g", L"guan", L"¹Ø¹ÛÂÚ¹Ù¹ÚñæÒ‹ÙÄÝ¸ÉF¹×¸Aév¯°HÓQêK÷¤êPöŠ÷bÓ^¹Ý¬g¹`¯p¹ÜÝ„å]ð^­eÅoøA…jš¯O´®¹á›ŒÞèäÊ¹ß¡Øž µ‘T‚“¥ßk˜ÀîÂÀ•ëqÜIæš¹à­ ƒ²•ðÙµe¹Þè…ûX÷}™õ" },
{ L"g", L"gui", L"¹é¹çæ£¹êßž¹æÆ—¹ëð§Ãv«•Ž¢w¹èÑOÒŽ@—Ë‹‚àF¹å“±é|öÙ‹¥‹¾˜²˜³ý”­Y²nõqšwëvôhŽQòo­„ôkÌlå³šð¹ìâÑØÐê{æ¹îŠ¹ˆ’i”‹¹ïÜ‰¹íµƒŽë…QêÐœˆÍŠÓmÔŽ…‘óþÏj”Š•QØÛ¹ôêÁÈ²¹ñ¹ó¹ðèí—Îªg¹KÙF¹òÉ}²ZÎš“Ê„¥„£˜­˜æ™u¶W²z°IÒ^™™çq÷¬íWè^÷Z÷i™Í" },
{ L"g", L"guang", L"þ]¹âž»žÓžÕžÖÆšßÛŠ­›²ˆŸDèæ«‡ë×Ý_ƒZã üU¹ãŽÚáîV«EÅS‚U¹äÅQ" },
{ L"g", L"gun", L"Ø­ÙòÐ–çµ¨¹õ¹÷É€¹öLÊF¾i¾ÝöçíÞõPõ…±šÖ" },
{ L"g", L"guo", L"¹ýßÃ†FÎÐÛö¹ùˆå†©â£áÆ¹ø—ëñøâu¯†‰ãòå˜‡HåœÏX‘²‡ë¹ú‡î‡ñ‡ó‡øàþÞâÄNXÂƒŽ½Êb‘Ië½ÄsÙåºl¹ûÇ‘ðŸ›ý«Ñxé¤˜¡òä¼@¾[¹üÝ{ðRß^ÄBèJ" },

{ L"h", L"han", L"áíÎñü†còÀº¨í™ØE‹©º©ñHõA÷ýÚõº¹ºªº¬º¯„TÍH†iŠÎ›¿‡öìÊ—cêÏ¬Hº­—²º®º«®]¹bÎKäw¶ínþsº±›Èº°ÊGþ\ØJþ[…{ººŒå’Iê\ºµˆ¥º·ªRÇtº´›ÛÝÕº¸•~âFé\°y±ŽÍ”‚þñU¸Ðò¥hÞþÎLŸßäIäd•Âîhº¶Î‘º²º³îuòAënÖ›å«ú[ƒË ’" },
{ L"h", L"hai", L"…õ¿ÈàË»¹º¢º¡º£ëÜŸQáVõ°º¥Šoº§º¦º¤ï™†ãñ”ñ›ðŽ‰h" },
{ L"h", L"ha", L"ºÇ¹þ¼“îþãxÏº¸òŠUa’CœÂ‡æŽ÷m" },
{ L"h", L"hao", L"Æ’ÝïÞ¶Ë^àã]šµ¸ÞòººÁ—·àÆª|ºÑºÀªˆ‡s‡_ª‚ƒŸå©º¾º¿Ï–»D×qºÃºÂºÅê»•a‚G¶mˆºÄ†SºÆh•‰œB‚Ûð©àzÂ|Ì–œé•µ•¼°‚°€»¸äËA°…•Ø°ˆò«î—ö‚å°ž®¸h" },
{ L"h", L"hang", L"º»¿»ÐÐÆfÞ†¿Ô”ãº¼°¹ç¬èìçñÍaº½¸‘ñþØ˜ÑR½W¹Vî@ôŒãìÏïˆœ" },
{ L"h", L"hen", L"’‹ºÛì•äºÜßçºÝÔ‹ºÞ" },
{ L"h", L"hei", L"ü\ºÚàËºÙ¦" },
{ L"h", L"he", L"Ú­ºÇ’ušBÑÀºÏÔXºÈàÀÏšºÌæüºÎºÍ…ôàAÛÀŠºÓ±A–­ªCPðšºÒêÂ»t¼vá—ºÉºË”—îÁ±Bº¦ºÔœzºÐºÊÈM† ý†ÔZò¢²—æ¼šÎãØ÷…Ô†ºÑØ€ãFéuïûŸ¿ûiîMôŸÎ˜ôçºKðgíHý[êH´Ò‡ùŸ°èYý˜ÏÅÞºØˆ††YÐŽŒyŸZðÀªnÙR´E†ÛŸŒŸÀºÖºÕº×ÂG°FÖyÛÖ‡˜ _ eúQúKûSìe»—ßjìfìg" },
{ L"h", L"hong", L"…·…Ë…Ôž¿ºäºåÙêºæÜŸŸp³…“Eœ‚ØFÞ°Ý“å‡«ÞZ›ºëŠkŒâºìÀ€«Y›K…ÆãÈºêŒfÆyãü«aˆ˜›`ºç¼tºéŠ¼Ý¦Á‡ÁŠ›Ä¼‡Âo¸fºè³{¼˜ØAâvéb»Ž¸sœ|ÈˆÈ‡½“ØDÁãpìô„~äfºCÙäë”šÞ®ëŸø™üZ†y•{Ú§Óé{äU“Ð¹é—ô\é•" },
{ L"h", L"heng", L"ºàºß›êÃ†ÐÐºãaŠ¬çñÃtžîèìûa“Ñºá™Mºâø’Þ¿èUùC†‘" },
{ L"h", L"hu", L"ºõ…IÏ·ò®ÜÌÆ~ºô›~ˆ~•Uºö•÷mìÃéõ…Oßüã±œXÌÜ ëŒëiäï‡FŒŒŽÄºýšXÄŠÖ—’_àñºü»¡ºÍ®@ºúºËºøëa‰ÖõúŸWðÀ½`‰Øâ©“‡ºþ†¼ºù‹|ìÎ—ýº÷÷½ðÉÊS‡Pºû¹”éÎô–Ðkîgõ­Î™¿eæLðbì²ù]ôEž€ù–úCö{[›R»¢ä°‚sÈL»£Ì•çúGåt»¥u»§‘ô‘õÙüÆS»¤»¦›ZŽìæá²âï–•OìïHóËð­ìèŠý—ü¹Í½œþA†Øà‚‹¬‹­Êdœû“ª˜«ŸÚøUåØmºn‡©ð××o÷Ÿí’ûI÷s»‡" },
{ L"h", L"hua", L"»¯»ª»¨»©í¹åkÌf»®…ØæèŠ£ÈAîüâEâD»«»¬‡W“Š“ç„´höÙÎ”änÊyÖœçfò‘ú†‰þ»°––˜»­èë†‹O®‹®“‹ÃÓiÔ’“®˜å˜¥±‹½Õ–Õ üXÅpÀE×f‹Nˆµ—É³“ÉI¼AÕj" },
{ L"h", L"huan", L"»¶ íªBšZøbùJà ‡ÈŒAâµ‘×šg×’ØŽóO»¹Û¨»·ÇB`ä¡»¸ÝÈÈPŒ~ˆâëf½b½ŒØ}ªxÁvïÌà÷×çÙå¾‹Öß€êaæD­hØoéIûq¼]ÀQÞSèGêX÷ß­’»º±¾»ÃÃKÛ¼ŠJ»Â»½»»»Áä½Ñ£žð»À—håÕ»¼´†¿†¾œo“QÑ»¾»¿¬~Ÿ¨¯ˆäñöé˜¬Èß§ËõŒ”köZöd" },
{ L"h", L"huai", L"»³»²»´»±Ñ‘õ×Ñœ‘¯‘Ñžx™ÆÂjÌx»µ‰²‰ÄÌ|" },
{ L"h", L"hou", L"ýJºî³@àjÈ‰Ž«ºíºï²Tðúãóó÷¿ô×ÂFÂJæAðfö\ºð êºóàCºñÆ™ááåË›•ˆ‹ºòÜ©Ø_ö×÷õ`÷c" },
{ L"h", L"hun", L"»è•e»çãÔ»é›÷¸š‰—•È²E²JÊMé’ÞFù»ëçõ»ìâÆœ†»ê¬qðQý@Ú»‚[‡õäãù‚“‹G’äŸk²OÓoŒ±ÕŸ" },
{ L"h", L"huang", L"ŽxëÁ»ÄÐYŒr–M‰E»Å»ÊÚò»Ë‚µ»ÆüSÈáååØ†Å‹h¢“NäÒˆð»Ì»Í˜R¬‰éB‰ŸäêªŸì»Èè«ÅŠóòÖW·kñ¥»Çó¨»Éðcöüå–í‹Ú‡òbçuöm÷UúŠU»Ðžê»Î•s»ÑŠN»ÏÔ…Ÿº¿mÖeƒÆ™¤œêé˜n•Í°æw°Œ" },
{ L"h", L"huo", L"…¿¶…ñëïÁØå‡—»íòdß«åºÍ»î¶¶„ìá»ðß˜»ïîØâ€Ÿ´tâ·›[»õ»ò…ü‚i»ñ’»±néXØ›’î»ö†¸„Šœ­µœ»ó”üÉ^· åx»ôžC«@Š_”N™ŠëoÖf·‚ïì²ˆ¦žmàëÞ½ó¶ÂhÅŸ‡É•ëÅG²‘°\èZí_ì[§" },
{ L"h", L"hui", L"Ï·»Òž¾ì¿Ú¶ßÔ»Ó’’›‘»ÖÐ„ò³çõŸFêÍØY¶éŠî‹^“]ëD»ÔÁš•Ÿµ˜î¡Ÿ—òÔœ²NÑ‹Ž¹‡j‡v“ÖÂEÝx÷â»ÕãÄž`Ìsö™‡ß»Ø‡éÝhjÜîÞ’oä§ÍYŸCßD¯`»×ÍzÍ õt³æ»Ú»Ùš§š« S™m×e»ÜŒàŒá»ã»ä»á›xä«»æßÜ»åÜöÆU»ß»âèíí£{»Þåç»à½}Á™@»Ýà¹çÀê_œ“œó…R•þ¢¡ÙVÔþiÕd¯ƒa‡GÊ]Þ¥ŒŒ“ˆH‘}˜ž•Á»Û™BÖM‹Ïª›èËCËDÚî_ðdË™º_™b Z­gÀD·x²~ó³‡¤‘ÎÀLÂP×M™®çiƒªêTìuçž×wîœïH­_" },

{ L"j", L"ji", L"¼¸¼¥ß´»÷„W¼¢»ø»ú„ZØÀÜ¸çá¼¡¼¦í¶ÆæÆä–ˆßÒßóØÞ¼§åì»ý®‚óÇï|»ùŽó†Àïú³Ž×êåê÷¹U¼©–O¶»û†æõÒøKã‚ƒ_¾N¾f»þš©»üûnÓsÜuÕƒ¾ƒçÜ‡\˜œì´åZ™C¶SÛÔ¼¤ëYÒH·e­^´‰î¿ÙŠºs“ô™›Âfëuí‡ù×I×^çˆð‡ÜQúaíZôy°^ÁaÌ~èWèiýWÒˆÁbûAÒ‰‘’¼°³²¼ª¼³á§¼¶î¼«¼´Ø½àBÙ¥…uŠ …¯¼±°u¼‰óÅ¸ïÓf“V¼²ˆô—ùŸd‚Â…hØC¼¯éêê«¼¬˜Oœ–‰JáÕé®¼­êÝð¼µÎaÚlãšÂcÄl˜ŠŽNçÞªÊmñ¤¹œÛaÛeÝ‹ÎŽ™v½å´’ÒQÛˆå‰Å¼®çgìPÞUúWýVÜeë}¼ºMŠj ä¼Í›‹ò±¼Ã¸ø¼·¼¹Þá÷‚êª÷äô‡“Ø™W·m”DÏlŸ¼Æ”ú¼Ç¼¿ÆëÏµ¼Éˆj¼ÊÜÁ¼Ë¼¼¼Á¼¾¼£ˆ…¼È¼oÜùÆ–Æˆä©ßâÓ‹Ó›„ˆ¼êé¼Ì¼¨¼Â—m”û¼ÀÙÊÂ¼Ä¼ÅœgÈ—ÊD¯ÅUÛEônô‚Ñ_¯s¾@¼»ëHƒÎ„ÞTP¶I·b·IôßôŠöÝö«õÕÕHÕ‚öê•¸ð¢·]•Ì¼½„©ËE÷ÙÓJËj‡ú™o¿ƒÁY¿Ž­u™‹Û”ùHöaýTõŸ‘Õ°U·}æ÷ÌRÌnž†À^÷Dö›÷CúnìVÌz÷qóKþL˜Û“ÄöV^" },
{ L"j", L"jiang", L"½­Üü½«½ª½¬®{ôøŒ¢Èw®–“°Áž½©Î…{ËKçÖ‰¬š™™^ÏQ÷šíä®Ÿ½®ÀPí\÷F½²½±½°½¯‚×‰DŠXŠ\ÊY˜ªª„ÄvñðÖvîŽ…G½³x‰á½µä®ç­‰Ç¿½{½´„ß@Ú“Àêñ¼TánáuôÝÖ˜™º" },
{ L"j", L"jie", L"½Ú½×ðÜ½Ô½áëA½Ó’÷½Õ¯^½Ö½Òàµà®†Ö‹m‹‘ˆê—¸œœÃ¿¬Ÿ®·MìŒÎf“øÖŠ°Xù™Úà…mæÝŒ¨Ú¦„g½ÙŒî„f–t•M½Ü¯CÐw„Â„oÚµªE½àÞ×Þ—½ÛèîÓ“Ç}‚ŒÙÊ‚ÍÇæ¼›½Ý’ùÑKÍ„½e½Y‹}‚Üò¡ã]Ë“ƒœï¹½ÞÔ‘Í˜H˜P˜m½ØöÚíÙ½ßÉ•éQì“îRÕmÛdôÉŽÑŽY”Oõ^µ@æOŽ^ÏÏ˜ÐVš²½ã‹d½âÓnï™wN½é¼Û½æŒôŽà…Ã½ä½ìŒÃ«d½ê³V½ç®vÐ|½ë½èò»…È†‡ˆû—ô¬p÷ºÍŽÕ] ÏÑ›ôæY½å—A" },
{ L"j", L"jiao", L"Ü´½»½¼ÜúÆ›½¾½¿æ¯j½½½º½Ìþ™½¹½·òÔõÓÌ—öÞÙÕ½¶²‘xõŽB‹ÉÄzÄ‰áèõo·pðÔ½¸øŸºŠÞBÏtç€òœú„úŒ½Ã½ÀÅT½Ç½ÄÙ®½Æ½ÈÞØ½Êžì•w’¹¸‹ð¨½Å½Â½ÁäÐ½g¹RÙ]„à½ËÄ_ë¸Ÿ”•¯ƒe“¼Û]ãqïœ“×“èƒ‚Ù„¤”º½É‘¢”¼³C•Ý­dÏf°‰ÀU×K‹ùž«”‡÷Rý™½Ð…Ó’›á½¾õÓŠ«„Ð£½Î½Ï”œ·•½ÑÝ^œò]†ý†û‡U”Ò½ÍþàÝ‰‹Ðª—‡„ËŠÞIõ´ÚŠ×_°á†" },
{ L"j", L"jian", L"ê§¼âŽÔ¼é¼ä¼ß¼áÇ³‘âƒï«l¼ç¼èŠ¦Š§¼æ¼à¼ãØ]ÝÑÈGª\½½¥ˆÔ¼ê½¦äÕÈ‚égëeêù  ¬{—ß—ä²R´DÝóÞöçÌ¼åÊ`¹{öä¾}ðÏ˜ÙÊzÊ—ŸÒøZŸæ¿Vä’ðeñJíKÆD÷µ÷œžhùNùpšµMžŒöxöúYšž™Ò×tí[µföž‡ØÌ‚ídè~•©àîèÅ¼ð¼ó¼ë¼íóÈ‚›¼ñ’³œ—Ž¥¼õ¼ô¼ì—gõÂÔd—Êïµíú¼ïñÐ‰Aœp“B’þÚÙ¬‚½€¹a¼òê¯‘ì¼îƒ€ôåº]“ìËuÒMÒO™zåÀå¿Öˆº†ÀO´š²€ôCûxörÏ•ç™ç‰žû{×v»WÒ}û|¼û¼þÒŠ½¨½¤¼ú›–¼ö½£êð«…½¢„‡½¡‚k½§–ç„ÚÉÉÑIë¦Å[ëì¼ùÚ™Œ{é¥”ðÙ`¼ø¼ü±O¼÷˜cuÙÔ„§„¦¾¼ý¼GÕÙvõÝÛ`Ú{ðTÖGæIË]„ª„«æG²{´´–¿ žR™‘”Wžˆ×UçZÓSÓVÅžÞYèBèaèbè{èƒØb”‰¤û…" },
{ L"j", L"jia", L"¼Ó¼ÐŠAÙ¤’z’~›v¼ÑÇÑåÈçìä¤š¹¼Ï›Ñ¼ÒðèÂ_óÕôÂ—kÝç‚íõÊªoÄ`¹kãe Ç¼ÎïØØjØ†ømæ‰û“¼×’Sˆ]ðÛ£àP¼ÔÇv†kí¢Ãîòê©‘æÑWòÌ¼ÕÍÛOî]äeîaø”ùGáµ…­«wëÎ¼Ø¼Ö”Ï¼Ù‹TË”Ð—ÝÙZâ›˜–˜\ØÅðý™x¼Û¼Ý¼Ü¼ÞŽ·˜kƒrñ{¼Ú†í¼O" },
{ L"j", L"jiu", L"L„ó¾À–` ¬ð¯¾¿¼j¼môñãÎÈ\à±¾¾“AäÐøF“[“š˜Í÷Ýôb¾Å¾ÃX`šð›CŠe¾Ä¾ÁÅi¾Â¼‘éN¾Æíƒ…E¾É¾Ê¾Î¾ÌèÑ–Íèê‚w…B¾Ç¾È¾ÍŽýH¾ËGÙÖ‘Wš”ÅfðÕöJû…Yýnú–w™ã" },
{ L"j", L"ju", L"³µ„HÇÒ’]¾Ð›t„û¾ÑŒþÜÚ¾Ô¾ÓêšÁ’º’±±r¾Ò³^ÁD—xÇùÞä¾Ý›ô‡ŠÛ‹JšÆôòÚ ÛBé§è¢ÄKï¸ñÕöÂÎAÅ‰ÜvÕ‡Ûgä|ñxø~õL¾Ï™h÷¶ù‰¾Ö›†‚I ó½Ûà`Ÿh¾Õ†¯ŠèœHœ¦—»Ý] Êþœé…ÛR»ÚzéÙñùV¿›ùqÛžúGüŸŽeÌ^ýAóMl¾×¾Ú¹ñèÛ¾ÙÜì¾Ø’¤—º¹_ö´é·é°ÉXÂ‹Åeõá”H™Îýe™ÛÒz»c¾Þ¾äÚªÜÄßšŠŒø¾Ü›®þ¾æšj’‡¾ß•Z¶€îÒ¾ç¾ãÙÆ‚˜ÐÍiÂ`»‰Ôn¾àˆ¿ˆÏ¾åêøâ ì«Ì˜Øe¾âñÀŒŠ¾ÛìñuõX¾áåð„¡„èåá“þÞ‘§¸M‰±äïZŒÕØ‹º–õ¶ÜMèL‘ÖþF" },
{ L"j", L"jiong", L"ØçƒÕˆsìçˆ·ñoñ’ÌSÌW‡åƒ×åÄ›sêÁ¾¼Þ›‚C›ÓŸK½NïGŸ ¾½½ŸƒTŸ¡ŸâÑ•°îy E" },
{ L"j", L"jing", L"Žyˆiˆlãþ¾¥¾©¾¶¾­Š¾£ÇG¶p›ÜŠùªS¾ªìº”ìÝ¼½U¶“È…¾§ëæ¾¦½›¾¬þ›¾«¾HÂ€¾¤¾¨ûù‚ù~öLü ó@û—¾®SÚåØÙŒc›Gˆg›HëÂ·„qš€¾°ÙÓîKŽÁµã½­E­Z­`‘ •ÇîiÏ‚¾¯¾¢ŠnåÉåò¾»›·‚\ŠøëÖÇo†ÞŸ‚Š½ƒô¾º¾·¾¹¸xœQ—J—}æºÃ„ö¦¾´¸t¯d‚ý¾¸¾²â°ÕeÛV¾³ìnìo¾µ•ßžsùXçR¸‚¸„™Y" },
{ L"j", L"jin", L"½í½ñ—½ïîÄ½ðáŽÓbñæñÆÇM½ò«ƒ¼Ž²›¬Q®âYˆü½î½û­\üTûv½ó½ö¾¡Úá‚BŽ„½ôÝÀÇž…½÷ƒH½õ‹¦âËWÉ“âÛ¾oéÈèªƒå\Ö”ð~µ„³æ¡¾¢½ø½ü–‡›»„ÅÝ£½þêá½ý½ú•xµ‰ßM†‚Ÿ¥çÆœÃŒƒ“|½ù±M‰ƒ¬’šVš„Bƒqêî¿NÙàääø‡žË|‹â a­nÓPÚBý„ƒ»³\¬n‰½" },
{ L"j", L"jun", L"¾ü¾ý›J¾ù¹êÐ‚ÜŠŠ®¾ûÇqÍS—T¾úñäâx´AóÞÒŸã—°—°˜ãz÷îf÷åå‹õzûŠûŽ…Í¿¤ê}¿¡¿¥¾þðžÞÜ¿£ˆ­öÁŸa•€¬BÈš¿¢®—œëhÎD¹„¹‰ÙbƒyŒ”‘®ðKŸóòEžFùQùRùU”h”|" },
{ L"j", L"juan", L"Š¤¾ê¾èä¸È¦Ÿ]–K¾éÑZ„æïÔägæŒçîÃ…Û¾íŽ™ˆ±Çš’ÔïÃÛmäŸÄ–ŠF„»Ž†áú„Ì¾ëèð¾î€öÁ¾ìÛ²›û®CÄC±’ÁI½v½²C‘gÊ^ðCª™Á\×z" },
{ L"j", L"jue", L"àÙ¾ï“ÞŒÖŒØ|æÞŒH¾ö„]¾÷šÜ½ÇÆ`{›Q¾ñ›‰«i«kçå¾õ¯N³OÍD¾ø’¢’Á¾óÍX™þ½Åèö”ÇÒõûÔEÚb¾òáÈÚ‘âfŸ}‚àØÊÚkÒ™½~½^ãÚØãÚÜ¬œñiø`ø_¯‹ “Ótâ±‡oÞ§Ê…ŸØ‘•Ž@ŽDàå‘‰éÓ™@ïãÄ”¾ô™ÃÏqÏp×H uõêÜFÜBç~çÛÇ÷¬½À…ZÓXÓìßžŸ‘Ý¾ð«Pžú€þ‹²ŸØÜjè‘" },

{ L"k", L"ka", L"¿§ßÇ¿¦¿¨Øû¿©ëÌãl„Jˆš–þÑQé^¾BÂˆõ–ù‹" },
{ L"k", L"kai", L"¿ªŠKé_¿«ï´ç˜¿­ØÜê]âýÛîîø¿®„’ÝÜ„P†þÌð¿¬‰NÝaïÇ•°å|æzêGïaâéžÍžý™ü„Ñ÷æb" },
{ L"k", L"ken", L"ÃG¿ÏÃ\¿Ñ¿Ò¿ÐØcØ~åo‰¨‘©’õ³wñÌÑy" },
{ L"k", L"kao", L"åêÏó}@¿¼”Ž¿½›Ÿ¿¾èàîíŸÀêûäD÷Š¿¿õwõ‘W" },
{ L"k", L"kan", L"¿¯¿´–Ýíè¿±®¿°ê¬ýÛÉƒÝ¿²Ù©¿³Ý¨‚°§šKšM¼÷Ý|îƒÞR¸ƒþaÐb€‰{ãÛ´|î«êRô_²™" },
{ L"k", L"ke", L"…\¿Á¿ÀºÇ · ˜çæ¿Æéð¿ÂîÝðâ³`ÚòÂ¯zÝVò¤¿ÃÈdïý É“tâŽñ½¿ÅËP˜}˜ÊîWî§òò¿Äîw÷ÁáfµL¿Ç¿Èš£š¤Á˜“U¿Éá³žÜœf¿Ê”¨ºŽP¿Ë¿Ì„Ä„Ë¿ÍQã¡ŠÄ¿Îæìë´ˆÑÐ_Ùç¼äÛÚï¾à¾´R¾~Å‹Õnä˜òS´ž…žÞ‘³€ÁƒÄ·iõ–" },
{ L"k", L"kang", L"ý³T»~¿µé`‹¢Üo¿¶˜±·^¿·Ü{ç_÷K¿¸¿º…Hß’ØøãÊ è¿¹‡ã¿»îÖâ‚" },
{ L"k", L"kua", L"¿ä†EŠ¯ÕFÙ¨¿åã’¿æ¿èÚ¿çógÅ~" },
{ L"k", L"ku", L"ØÚß ³L¿Ý–ö¿ÞÜ¥‡ýÚœ¿ß÷¼õp¿àª@—ü¿âç«‚V¶sŽìŸ\ÑF¿ã½fà·¯‰¿áÑ‡¿ÈZùŒ" },
{ L"k", L"kou", L"ÜÒ¿Ùíî„›“¸“²g¿Ú„¼ßµ¿ÛD””Œtƒã¿Üâ@·óØÞ¢ÊfA²]ºpúd" },
{ L"k", L"kong", L"¿ÕÙÅáÇ›ïˆÂ£³œóíÜwåIùy¿×¿Ö¿Øì" },
{ L"k", L"keng", L"êl„´¿ÔŠs¿Ó’®³n ¾ï¬³³™ÕU“¾äLå”çH" },
{ L"k", L"kuan", L"¿íŒˆŒ’ÅC÷Åóy—pšE¿îšL¸T¸Uèw" },
{ L"k", L"kuai", L"þcØá“ùŽw„S»á¿é¿ì¿ëÛ¦ä«ßàáöëÚšC‰K¿ê÷Ž‰‘à”ƒ~XÒªœ‡ˆÄ’¼[”÷÷dˆQ" },
{ L"k", L"kui", L"¿÷¿ù„lã¦¿ø¿úÂ¸QÌîêNŽh¿ü•uÚóàkåÓØ¸Þñ¿ûà­óYêÒ‘è—ó—õ¿ýî¥òñî`åžæK™œËwòjÙçÌwÌ€Žu áÜi¿þŸõÍíŸ´jÛ“þ|¹éŒºØÑÝÞà°‹À¡À£ã´À¢…TÊ‰‹Å‡]‘|¢ñùÂ‘þ}óñÖdš•Ä„ðrºˆÂ˜»Að" },
{ L"k", L"kuang", L"¿ïß„ÁÚ²ßÑ›¬b…N³q¿ð¹nÝHÕE¿ñ ï’[ûÚ¿Ü’ÜœÕNù\ÞÅƒ—‘ÈÚ÷æþÛÛ¿ö¿õD›r¿ó•pêÜ±q³m¿ò½T¿ô½_ÙLÝAãkäqà—‰¿üY p•ç‘Ç·ƒ²ŽµVÀkèk" },
{ L"k", L"kun", L"À¤À¥•‚ÑTˆÒÇª^‹ŠŸjçûó‚÷Õï¿ûdÑhÑ‚ÎJóˆõ«­@ŸãåKöïòOù{öHúAÀ¦ã§ãÍ‰×—yµŒ¶‘³ÑX½™¶Ÿ‰Úé€éÀ§›Ù±—ˆÜ„" },
{ L"k", L"kuo", L"À©’ˆÀ¨’•èéòÒ¹QÈuÈvÀ«ÀªîSó–ípíAéŸ”UžNìHíTôU" },

{ L"l", L"lan", L"À¼á°À¹À¸°À·¹À»ÈŸÀ¶À¾À½ñÜìµƒ‹Àºïçê@Ë{Ò[‘¾ ] L­sÒhŽÓ×EÀa»@ÌmÌkž‘ž™”r™Ú”ÌÒwž±‡Û»_×ŽÜ_™íÒ€è|íeÀÀ›ÇÀ¿ÀÂé­äíî½áYÓE‰°ÀÁ”G‘Ð‹ö‹ûÓ[ŒG”ˆ Š™ìïCÀ|ÀÃÀÄ AžE‡• f €­Šž° ˆ¼hè”" },
{ L"l", L"la", L"À­À¬–¬Ç‰À²À®“yååê¹ØÝíÇ“X´r‡ÄËˆÁÂäÀ°—ï“YÀ¯Î`À±ÞhðøÎ|Ä—ñ®ôFÅD”j m­†™ÊéJö_Ïžèn„Lœ¼íBõu" },
{ L"l", L"lai", L"À´‚gÀ³áâáÁäµ—…ïªí‚|à[ÆßFŽò†‹‹@ª[ˆœZÈRêã—®¬[íù¹XÀµ¹sånäþñ®òQüHù„öDô¥Òs²AÙ}ÙlÙ‡îmîsù`ÌDž|ž°]»[ÈZ" },
{ L"l", L"lang", L"à¥„ÉÀÉàOýœšDÝ¹ÀÇ—OÉvÀÈ‹™ÀÅ”Éïüï¶³„¬˜ÀÆÍ™Å…¹^àHÜqòë˜¸äZæƒÀÊ–JŸRÉ‡‰iÕL–TãÏ~ÀËˆ°Ýõé" },
{ L"l", L"lao", L"ÀÌ“ÆÀÍ„ºÀÎ·ÀÔ›Ðßë†[áÀ„Úï©ðìƒX÷ÁÊ‘Ž°A´‹ÏoºŒõ²ç„î‘ó€ÂSÀÏÀÐÇN†KÀÑªJ`èá«™îîã™â²ÞLÂçÀÓéjÂä†ëÀÒñì‹ª‡Z³‘Üx™QÂgÜ~³z»”–U" },
{ L"l", L"leng", L"Àâ†}Ü¨Àã¶ ´GËJÀä‚’ˆÙã¶±œÛk" },
{ L"l", L"le", L"ÀßàÏØìêbàÆIß·’AšíÀÖ«Wãî¸…³iÀÕ˜SðEí‰˜·º{÷¦ö˜÷w–Y˜V" },
{ L"l", L"li", L"Á¨„^ÀöÀåæê„{ÇVÀêÀëÀæ—~Àç¬P“Ç—à¬ À—ˆð¿çÊòÛÅƒ¹]ÀìÝñ„˜æËŒV˜»Á§±LØ‚ä‚öâÀèÑŸ ÓÊk¿rÀéî¾äœÖ‚árÏ[áëxÞ¼‡­ß†”Á­€ç\ùvöPÏ~÷óó»ÐGž¦‡ÎÌyŒCc„°èg»h·ˆÀ{óP÷~ûZÀñþGÀïÀîÙµbhqåÎæ²Àíï®ÑeýŸÑYØNä‡Àðå¢¶YõŽõ·÷¯ßŠ÷k÷u™ðÁ¦ÀúÀ÷ŒÞÁ¢–^Àôß¿ÀøÀû…«ÜÂÛÞÁ¤›lŒüèÀÆnÀýìåðÝÁ¥ðß³PÚ\Ù³ÀþÀóÆÛªèÝ–Ðéöáû—«†Àõ–Û›ã›ËÀòÝ°ŠÚíÂÀù¶wØªòÃÍjôÏÁ£óÒ‹Kà¦ÃšŸ—˜Àüƒú…õÈîºÍÁ¡ö¨øE±ŸãW…“ÉWÉT“…äà‰Wü•·šs¬—…–¾FÎGÎ€óöøtë_„îšv•ÑŽ_žW™‚ë`óœ´•°O Ø iÏ‹™ª•å¶]”^ƒ¢‡³”iËž­|™µžr‰ÈµZûµ[Ï  s¼c±X™À­‰°áBƒ«°[µ`û•úbÞ]Ó€ÜV‡Ñ”ƒ™æ×Þ^ìZ­–”‰ìc†o®M²@»šôƒÂˆ¸{¼Hõ”õ•" },
{ L"l", L"lei", L"ÀÕÀÛ‚ñÀ×É çÐæÐ®š˜ÃÀÞÀÜ¿w”bÀØ´ ™§­zÙúµWÀœÀnÌrèDÞ[èhìYÌ…™ïÀ}ýF…ŸñçÚ³›¤ÀÝ½t‰CÕCäðÊuÀÚ´ÀÙË‰‰¾°N™¦µXÏœž˜Ì{×|ƒ±‰ÍèˆûPÀßÀáÀà›æœIõªãîLî[åGéÛïKîÀhÌq¶a²" },
{ L"l", L"lia", L"Á©" },
{ L"l", L"lian", L"Á¬ÞÆÁ¯Á±Á°ßBÁ«—†ñÍÁªÁ®‘XÉŽiœÇ†ö…UŠY˜ŸÈÒœöãÂŽÂ´nÑž‘z…V„ ‡t‹¼å¥ïËOÎ‹Â’¿€ÂIÂ“Ö‹Ûš R™¹ì¡Á­æ`ºŸó¹žƒôHö–ç »^»dÁ²çöÁ³ñÏ“¢­IÝü‹Õà˜”¿šaÄ˜ÒcÁ„Ì`Ì_Á·Á¶ÁµéçˆäƒIÈj‹tœ‹Á´Ÿ’é¬¬…äò¾šÔåbå€ššæœönž‡‘ÙÀ~" },
{ L"l", L"liang", L"Á¼‚ZÝ¹Á¹ýÁº›öé£ÞcÁ¿Á¸Á»õÔÜ®˜ÅÝˆò@¼ZIÁ½ƒÉÁ©‚z†|†¤’ëÃžÑoÎW¾n÷ËôuÁÁÁÂ†]”‚ŠÁ¾ÁÀ†Èœ´ö¦ÝgÕÝvåy" },
{ L"l", L"liao", L"ÁÃÜGÁÉÁÆÁÄŒ®‘lÄkÁÅÁÈÛxÁÊçÔàÚùúå¼‹»â²ß|”¶•Å­VÄ‚ÁÇ˜÷¯ŸðÓ¸XÏi¿ºƒÙ’ØIÛŽ\Ë€Œ× r vïfósïmúÁËîÉá‘à€Þ¤‘’²téRÞÍŒ³žÒÁÏÁÎÁÌ¸NÁÍç‚" },
{ L"l", L"lie", L"ÁÑÁÐÁÓ„ÃÙý’žÆ”Þ˜ßÖŠ²ä£›¼Ûøˆ´ÁÒ†`ŸI–ïÞæþšÁÔªdÍ}Â~ôóŸ­Ž{ïVø•õhƒ•«C”Y ÚõñôQ÷à÷v’£" },
{ L"l", L"lin", L"Áà…›ÁÚêtÁÖÁÙƒäßø…ÁÜ•—»‘ÁÕ´@ôÔ¹ƒàëOý åà«á×ª•Éê¥Ÿû”Ý­UÁØî¬Á×®žÅR¿šÂLû‹ÞOçlÁÛžŠ‰Éò•÷ë÷[ÈHzƒjÁÝ„C“ÔÅãÁ‘¬âÞ[éÝ™_°R°SÁßt‡ÁÞŸiÙUÝþ˜ð®Vì¢éŠÜCÌAõïÜ\ÜkÞ`" },
{ L"l", L"liu", L"ÁïìÖ¸Û‰Áõ®qä¯”åÁ÷ÁôÁð”é®‘Ñ^ÁòåÞì¼É]Ésæò‹ˆÍÁóïvÁñ¬ŠïÖÁö¬–„¢´eñ‡ûm˜ñ®œéH­]°@ÏYñœûˆöÌæy‡®žg‘ËË˜çBïdòtçsïiúVö†ò˜Áø–Î—B«€—Pç¸ï³¾^äÁSŸÞ™PÁ[‹ôÁùÂ½Á’A‰gÂµðÒ´zðsìCëwïfôjúw" },
{ L"l", L"ling", L"ÁîÁæ„cÁéˆ{àò‰çÜß¶ßÊŠ– ÷ãöèÚ–E•`ê²Áá°s¶{Áå¸nû_³gÁêÁgÁèÁâœR’’èŠêèù¬OòÈñö½@ÐeôáÅz¸ ç±ÁçÔfÝCÚšµ’ÀâÑkÉˆÁäâéqÁã¾cÊCÝsë‘ñ|ûwøoõCë™öìä™Ê™Î UëëžýhöNÛ¹‹øýg™Ðáû™™ô ‹ý’ÁëHÐ‡ÁìîIŽXÁížâÌhì`" },
{ L"l", L"long", L"ÁúÜ×ÁüãñèÐ•oççëÊ¸o±€íÃÁûÁýÂ¡œ¬œöV˜™ðÁþº\ýˆñªçXìNŽaŽbž{‡µÌd z™É­‡•îÒt–V²”µaµbýýŽ»\ØLÜ[Ã@ÐFÐHì_èxóGûTÂ¤Â£Â¢ÛâºTë]ƒ¥‰Å‰Æ”n¸_Åª†U—YÜÚL" },
{ L"l", L"lou", L"Â§²kÂ¦ŠäÙÍÝäœ¾à¶Â¥U‘fÊVßsI‡DŸÓ˜Çò÷ñïÂeÅ”ÏNÜ}ÖŒ÷ÃótíVúyáÐâ“§‰v®RÂ¨ºtÂªŒÍÂ©ïÎðü¯›¯œçUÂ¶þo" },
{ L"l", L"lu", L"ààß£Ö}”]‡£Â¬Â«Â®ãòÛäÂ¯–›èÓëÍðµÅyôµ«SÂ­öÔñeô—±R­o‰ÀžoÌJ]‡´«G”m t™¾•ì­ˆÅF²’ÆA»VÐBÀžÀrèzózïB÷|ûRüuÂ±Â²Â°ûuÂ³³”Ì”ÉF‰oÂ˜Äô”´{éÖ“ï·tïåžZšÚ™©Å›æ”çœÆ@èuÁùˆP®fÂ½ôÂ¼ ˆvVÂ¸éûê‘„ÎŠáåÖÇŠäËœGœO³tÂÌÂ¹—¶Â»µ“¬f„ÛƒJ„—¶˜±J²FÂµÙTÝ`Â·»œ¹‚Þ¤ÊILäõ“¦‰nê¤Â¾ŸÑ˜ÌÄrÛjáXÚ€åhä›åj·cÂºÊ€è´óüÏFøšÛòJÞAº˜ðØºŽº—çGùcùnÂ´öIòƒçeÂ¶»Uú˜ÌéñŸfé^â„ëªÞ_" },
{ L"l", L"lv", L"Â¿ãÌéµé‚Ä|šÑ™°ËƒóHÂÀ…ÎàLÂÂ‚H’ ’ÇÞÛÂÃ—oµ~ÙÍÂÁïù½…ÂÅÂÆƒEŒÒëöñÚäXÂÄÒ@Äo¿|ƒ–·„ÂÉˆ‡ÂÇÂÌÂÊÂÈÈ„¯ÂË¾G¾v‘]Äy¹˜¿†„ížV l™¬èr" },
{ L"l", L"luan", L"æ®ÂÍÂÏèïÂÎÃ‡ð½ÙõÂÐöÇùFŽnŒDŠaŒ\ˆJ”ž¤™è•ðÁcÅLˆKÌ‰ž´èŽ°f°gû[ÂÑÂÒá›y" },
{ L"l", L"lue", L"Œœ®ˆ·Däsäx" },
{ L"l", L"lve", L"ÂÓÂÔï²ˆG" },
{ L"l", L"lun", L"ÂÕ’àÂØÂ×ÂÛÆ_ÂÙÂÚàðöÂÖ‚ê‡÷œSÇ’‹E‘—‹Ä@´KÎFÂb¾]Ý†Ûiä—öMˆÀ¥¶—œÓÕ“†í´ˆ" },
{ L"l", L"luo", L"ÞÛ†ªÂäîb‡ÓÂÞÂÜÂßâ¤ëáÄTé¡ÂàÂâÂáïÝÂÝÁ_ÓTæ ò…ÓZó»ƒ¬ß‰Ì}«M”{™åòŸúŸ»jèŒð”‡Þ„sÙÀÉzÂãÜsñ§ÙùÅI•ï°eãøÂå¿©ÂæRÜýÂçÀÓ› çóíÑ³Š½jõÈ¹JÔ›öÃ ÎÞûäðñ˜ùBõižTÀzõu" },

{ L"m", L"m", L"ß¼…ÞÄ·" },
{ L"m", L"mai", L"ÂñËhö²ÂòÝ¤ÙI‡Xú”Û½ÂõÂóÏ‰ÓÂôÂöÃ}ûœÐ]„êÙuß~ì@ìAÊ{" },
{ L"m", L"ma", L"}ÂèŒIÄ¨ÂìÂé‹Œ‹°Ä¦Âð†á¯q¯rÊh Ðó¡ÂíáïÂêÂëñRªwœÔ¬”´aÎ›æ‹úiö‡è¿µlÂîéUßé‚Ø²K‡O¶M˜qÁRñˆôK†xÂïôÏW" },
{ L"m", L"man", L"Âñ‹ ò©î”ŽÂùÃ¡ÂûÂø“¶‘`˜ÑÂ÷²m÷´Ö™ðz÷©ôNôMö ÐUŠÒŒÌœºÂúMòýÏ\æž²–Âüà„ƒKÊAá£ªƒÂþçÏÜ¬Âýì×˜´ïÜÙ¿zçNÒZ" },
{ L"m", L"mang", L"Úø ¯Ã¢…¹šûÃ¦Œ´–x–nÃ¥Ã¤±Z¸ˆ}Ã£……Ží†WŠÁªK›À ½âIèšíË¯gÍ{ä€ñ ÌMÃ§Çƒ³‰ÆŸ‰ÜäÝòþÏ‘" },
{ L"m", L"mao", L"Ã¨ØˆþYÃ«Ã¬–‰ÜâÃ©êóì¸ÁEÜšáFœ~ˆé—ûÃª÷ÖãwòúšÓóå^ó±ùšƒÓ‰îÃ®‘ùá¹ã÷êÄÃ­¹FãTÉ‹ƒÐÆd°pÃ¯ƒØÃ°Ã³–µ±gë£Ò‘ÙóÙQà|ÈrÃ±‹ušÊ•§è£ØàŽÃ²î¦Îcí®š¸" },
{ L"m", L"mei", L"Ã»›]ˆbÆ€Ã¶Ãµ–ÏÃ¼ÃzÝ®àdÃŠÃ·¬C±ŒˆõäØœŽÉBÃ½â­áÒÄP¬s¶Cé¹˜MÃºÃ¸˜ŽïÑðÌ‰räYÃ¹æ[ÛÃÓ”uúBüqš°Ã¿ÃÀƒñ’¯ä¼Áo±œ„‹Z‹‰Ã¾‹Ê BÜzæVüeÃÃ’{›iñÇÃÁµ|±tÃÕÃÂÃÄÚ›ôm¯cŸ¢÷Èíi²SÎn¹Ÿ" },
{ L"m", L"me", L"WÃ´„õ’CŽÛ‡¡žQ‡ª‡¼" },
{ L"m", L"men", L"ÃÆÃÅÃÇÞÑãë«jîÍéTéY‚ƒÇ–’Ð­J·`å{ÌŠìËž•¹ Fí¯‘¿—È" },
{ L"m", L"meng", L"’úÃÉ”BŒ´®mÃ¥òµÇmÃÈœÉÃËà‘ÝùÎ{à–ƒÊpÞ«˜ýŽÌ÷‘ºÃÊ•äšÙëüûsíæõ’²‰ô¿²“ðìWìXîŸûLö¼ÛÂƒáÃÍÃÌòìô»åi«BãÂó·öQü€ÃÏÃÎ‰ô‰õ‘¸ìD" },
{ L"m", L"mi", L"ßäÃÐ²[ÃÖìòÃÔâ¨ÃÕÉoÔ™ÖiÃÑÃÓ÷ã÷çû†üOËz›”C¶[ÃÒû”ž…«JÌjéSÞÂ‘Û”}­Œ †á‚áƒûJáˆÃ×ØÂÁdñ›m›¦åôôÍëßœ}ÈŽÊUãðŒBž§Ú¢ôéãè›^ÃÚ\åµÃÙµzaŒsÃØÒ“Ò’ÃÜœPÃÝÚ×ÉqŽ¶Òš‰QÃÛ˜aü†ÊZDeà×ŸÇƒç˜ÆŽÈóÖkº€™—Á]ü“ÑA»…ÑQ—Ò‡Ã™ë" },
{ L"m", L"mian", L"å²ÆP–uÃßÃàŠå‹iÃÞ¾dÅXÎe¾‚‹î™†™¡²Š²Œ²DšóãæÃâÃã‚aííÃääÅ‚Á„ÒÃáÈx†»äÏ±”ÃåÒëï¾’Æìtõ|ìrÃæû ü@¼EüMüI" },
{ L"m", L"miao", L"ß÷Ãç‹bÃèÃéðÅ¾ˆ‹·ù‘„¹èÂÃëíðÃìç¿íµ¾˜ºFÃêåãÃîÃí¸k«QŽøçÑR" },
{ L"m", L"min", L"ÃñçäÜåŠ“áºB•F•G±a³RçëÁF‰’ÏçÅ¬Y¬\¬z´C¯xâŒ¾r¾‡ä øsæFÃóƒí„bìãÉö¼Ãòãýë”•„ÇÃöÃõÃô¸œéhüwÇœ¡”°•¡íªé}ƒo˜‘‘‘Oº‡÷ªÏŸöšˆ„¹I" },
{ L"m", L"mie", L"Ø¿…¸ßã†_ŒPÃðžû“}œçÃïËIøpŽÏóúžf‘Ì™­µTóºÐ`èf÷x”æ" },
{ L"m", L"ming", L"ÃûÃ÷Ãù±b›³ÜøÚ¤±…–LÃúàpÉqäé‹“ªuÔšã‘øQ˜iêÔî¨ÃøÓKâŠ±ƒü‘Dõ¤Ãü’ø" },
{ L"m", L"miu", L"ÃýçÑÖ‡" },
{ L"m", L"mo", L"Ãþ‡±ÎÞŒ­ÚÓæÆâÉÄ£Ä¡Ä¤÷áüNÄ¦˜íÄ¥¼UÖƒÖ„æÖ‹ß”VðxÄ¢órÄ§„¯ð‘ÍòÄ¨‘½Ä©ˆ\Ã»Ä­Ä°Š‹ÜÔŽ’éâšzš{–£•bÂöŽ”Ã°ÄªÇe°tï÷³]±u±‹Íà½Q±‰Ø{Íˆõö‰sÝë†ùÄ®Ä¯ª…ã€ì…ôŽüa‹ººÙÄ«²a²hñ¢ïÒÄ¬õøÏ_æŸË j°Zò‡ÀgµcñòC„õiÑQáJôž‡Ý" },
{ L"m", L"mou", L"ßèÄ²„ÀÙ°…ÞcÄ±íøòÖçÑÛ_Ö\öÊüEøœ¿ŠÄ³" },
{ L"m", L"mu", L"ë¤šÒÄ£Ä¸ÄµÄ¶Ä·®oÄ´®r®yÀÑ\ ¸Ãk³c®€®®ŽãaÛ[Ä¾Ä¿ØïÄ² ñãåÛéÜÙÄÁžÑš»ÄªÇ€Í]îâë‚Ä¼‘HÄ»Ž¿Ä¹ãfÄÀ—úÄ½Äº•½ÅëŽ¿}ÄÂíJ…ž˜V" },

{ L"n", L"na", L"ÄÇÄÏ’‚ÄÃ†ò“ïÕæ“pÄÄë~ÄÚÄÅ…ÈŠ{ÄÉëÇàGÄÈÄÆñÄÐœ¼{¸™Ü˜ØvÞàØyâcì„Éiô›„Mô‡" },
{ L"n", L"nai", L"ÄGŒYÄËÜµÄÌÄÊ¯GiÞ•ÄÄ‚™á‹èÙ¦ÄÎèÍÄÍÝÁœ‡Ø¾Ñ”Î—år" },
{ L"n", L"nan", L"àîàïÄÐ’o––¹‚OÄÏÇ~®~ÄÑŠÉà«éª•¨ÖQëyôöÈl“Dœ¯Ÿ²ëîòï‘Ú‹Rßa" },
{ L"n", L"nao", L"Ø«ßÎFÄÓpîóíÐòÍÔiâ®´L“ÏŽH‘Ïu«D×D‰ëçt«LŽjÛñÄÕ˜ÄÔÃ—…DˆßÀè§‹šÄX´ZÄÖÄ×émô[Äž" },
{ L"n", L"nang", L"ÄÒàìe‡°ÐLâÎ™òð–“îêÙß­ž²ƒ²ýQ" },
{ L"n", L"ne", L"ÄÄðÚÄÇÚ«ÄÅ’f±„ÔGC„õü“¿L" },
{ L"n", L"nei", L"ÄÄŠÌÄÙÃ•ÄFðHõƒõÄÚƒÈÄÇšßšàåM" },
{ L"n", L"nen", L"í¥ÄÛ‹¯" },
{ L"n", L"neng", L"ÄÜ" },
{ L"n", L"ng", L"àÅßí" },
{ L"n", L"ni", L"ÄÝÄáÄàƒºÄØÛèâõ»u¶vîêà\ÄßŒÉœNŠöâ¥ÍeˆÐ—´ÛCâ‰ñDÎUÂ‰ÝrÓrØƒöòÄÞûŒöFýuÅMÄâÄãÙ£ÃÆsŠ… ù’v–«’íì»•ŒTëWƒŒƒ“Ëo”MÂžŒÛšîÄæÃfêÇÄä±zˆÓ©ÄåîÄç‹¤íþ•¿¿QÕyÄ‹òáÚ™†RøM" },
{ L"n", L"nian", L"ÄéÄèÄêýž¶j†PŠ¨¶|Õ³öÓöóõRð¤öT›ÝœVÄíéýÕ·ÄëÝ‚Äì“ÓºvÛ…”fÛœÜT…`Ø¥Äî†ˆÛþ¶ÅˆŸˆ" },
{ L"n", L"niang", L"Äï‹Ý‹úÄðá|á„" },
{ L"n", L"niao", L"ÄñÜàôÁøB‹–ÑUÊ\˜ÒÑ™‹ØæÕÄòëåÄç" },
{ L"n", L"nie", L"ÄóÄí“IÆ}Ø¿Ž‹ˆ[–¨ÚíÄùÄô¯[ô«êŸÇŒÄöœ¸”¤Ôà¿ÛWÛfÛh“µÄ÷Äø‡y˜®ŽLºQÅYåRò¨õæÂ™‡§æ‡êEÄõŒZ™ÇÞÁ»H‡ËýmèXŽqÐA¼b¼f‡ÜÜb×‘è‡ïDè" },
{ L"n", L"nin", L"‡áÄú’ŒÃ€" },
{ L"n", L"ning", L"ÄþÆrßÌÄüÅ¡Äûñ÷å¸Œ|Œ‚Œ„Œ‰ŒŽÄýƒ‘™F”QªŸ‡“Ëf‹Þ™ŽÂœè_ôVûH²…Øú‚AÅ¢‚žÃô" },
{ L"n", L"niu", L"æ¤Å£ «›SáðÅ¤Å¦âîžÈ–ƒÅ¥¼~ÇyâoìÞÖ" },
{ L"n", L"nou", L"Á…˜‰ññ«Aæe™“çõ–" },
{ L"n", L"nong", L"Å©Ù¯Å¨ßæÅ§¶ŒÞrÞsƒzÊâ‡Ä“ \™`¶Z·vÒa×aáx™×ôTÀYÅª’˜’°°JýP" },
{ L"n", L"nu", L"Å«ÂæåæÛ¹@ñwÅ¬åóßÎ³eæÀÅ­‚Õ“xÇ‚" },
{ L"n", L"nv", L"Å®îÏ»sâS›\ÐZí¤–Hô¬" },
{ L"n", L"nuan", L"ŠfœqŸÅ¯ð`" },
{ L"n", L"nun", L"üQ" },
{ L"n", L"nve", L"Å±Å°" },
{ L"n", L"nuo", L"ÄÇÄÈÅ²—jÙÐ™Dƒ®ÅµßSßö’ýÞÞùï»˜`·LÖZÛåŸ¼K‘ÂÅ³¼X·zÅ´" },

{ L"o", L"ou", L"ÇøÚ©Å½Å·Å¹ê±Å¸‰pŸàšWøk®TÄpšªÖŽËš™¯æ–útÅ»…¾Å¼ÄU‡IÊqñîÅºâæ‘Ya" },
{ L"o", L"o", L"àÞÅ¶C˜jÞ‘ªe³€”ñ¹pøM¿L·iÀq" },

{ L"p", L"pa", L"°ÈšñŠrÆtÅÉ°qÅ¿ÅuÅ¾Ýâ°ÇèËÅÀ°Ò’öÅÃóáþxŽÅÁÅÂÐ’Ž‡" },
{ L"p", L"pai", L"ÅÄÙ½ÅÇªTÅÅ—“ÅÆ¹uÝ‡º’º”ÆÈ›fÅÉßßœkÅÈÝåæWêC" },
{ L"p", L"pan", L"°â°è±eÈ_·¬ÅËÅÊãÜãÝ›–®ÅÖ°ãÅÌÛAÉgŽ´‹Š˜„“„±PÅÍ¿T´‘õçÛ˜æoó´žbíQˆmƒëÅÐ°é›cãúÞÕžÎ žÅÎÅÑÅÏñÈÔjœãîGäƒùbñáè‹" },
{ L"p", L"pang", L"ÅÒÃpë„äè°òÄtìQ·ÂáÝ…€ÅÓåÌÅÔÅ}‹˜Ï°õó¦÷›ý‰ý‹ö„†çÅÕÓIóožÐÃTÅÖ±~" },
{ L"p", L"pao", L"Å×’ÅÝëãÈaÅÙâÒÅØáóˆƒžäÅÚ ÅÛÞËÐˆÝNÅÜìŽûûƒŠEðå°’³hìsüBµPµ^†ÔÑŒ" },
{ L"p", L"pei", L"ÅÞCÃSÅßÐ[õ¬êkÅãÅàÅâšÅïÂÅáÑpÙräž‚_¬ éÅæÅåàúŠ³”äì·«˜Åä›ÖàÎñ]ö¬Þ\É„" },
{ L"p", L"pen", L"Åç‡Šåš\­›ÅèÈ†äÔ…ÜÂM†Ï" },
{ L"p", L"pi", L"Ø§¶ÉÅúç¢ÚüÅ÷žÌ–ŠÅû’y ò øBÅø¼„±»¶u¶yîë”èÂ\Á‘ØwâtâWãYãó‹ñy´iÅüàèäšõBåC‘šæqµFµGÅùÆ¤êoÚéÜÅÃYèÁÅþš³Û¯ÚðÆ£ò·ÍoÍnØuÛýÆ¡šÅýŸÆ¢ÄM—ÀñÔâ”÷‰òçî¼ÄmëRô“õQ‰ªºfÏKùdõùÁ`Ü±ÐKÆ¥âÏØòÛÜÆkßÁ·ñÃ˜Æ¦ã›øaÕ|ïß¨‡ñ±‡ºÆ¨äÄ“FæÇ‹œî¢±Ù·K‡Æ§Ýê¶þž¯@Æ©êVûGúÞ‘" },
{ L"p", L"peng", L"„úÅê›€âñyÅé³yÅë—ZÝJéo„™pàØñs´yÆMÅó¸†Çl‚‡’¸Ü¡‹ÑHÅíÅï—Ä“s‰X‰k‚õÅî·@ÅôÅð˜ÕŸÔÅì‘uÝ~åAÅñºUÅòíŠó—óŸó²ÏeÀeÌXíŽùiôJòuèmÅõœA°v’ü—ÕÅö˜¨ÛsÝƒ" },
{ L"p", L"pian", L"Æ¬‡æ±âÆ«‹xêúôæÆªú@±ãæéëÝÄAçÂ—è˜FÙXÛMñÛójñ‰õäòNÚÒÒÙGÕ›Æ­ò_ò]" },
{ L"p", L"piao", L"Æ±Øâ„ÜàÑ®Æ¯çÎÆ®”ôóªÂH ÜïhïgôwÆÓæÎÆ°ËiêQÝ³éèî©¿~ºgáoî’°ŽƒGÒæô‘GòŠ÷B" },
{ L"p", L"pie", L"ë­Ò”Æ²•È“ÅÆ³Ø¯ÜÖçv‹±" },
{ L"p", L"ping", L"Æ¹®jÙ·æ³›Ú³fÂ†ÆEîZ·ëÆ½ÆÀÆ»àZÆ¾…çÆºèÒ«rÃgÆÁ›¯Ž—ÇLÆ¿ÍgÆ¼Ž£œKŽ±É‘ÍƒÀ®J‰BŸvÔuöÒÝZ¸z„R¹’‘k‘{õG™qºqŒÎJ" },
{ L"p", L"pin", L"ÞÕÆ´æ°³WµI·|ñPóDÆ¶«nŠÐØš¬VæÉÆµ‹åËdÌO‡¹²‹ò­ïAÆ·é¯êòšýæ³Æ¸–W" },
{ L"p", L"po", L"ÆÓîÇÚéŒû²´ÆÃÆÂá•þ‡ÆÄáNîHŠáeáwçkÆÅÛ¶ÊX‡Mð«·±™‡¶ØÏŒžîÞóÍãO¹ñpgÆÈF›¨”’•^çêÆÆ³kŸBÆÉœ”ÉbÆÇn†R—K" },
{ L"p", L"pou", L"ÆÊŠË’g’h’½ˆ¡ÞåÙö¹r…ð†VŠç Á" },
{ L"p", L"pu", L"ÆÍë¶ê·ÆË’pžÊê†ÆÌ¯jäàÛ“äªõ‹ˆOÙéÆÎÆÐ¸¬ÆÏÇŽÉhÆÑƒWáT‰ªŽè±·oïä²rå§ÙŸçhÀbÆÓÆÖÆÒÆÔŸMÆÕ‡þäßÆ×•®ÖE˜ã“òë«™kïè×Võëç’±¤ÅmÅn±©ÆÙÆØŽ}†R" },

{ L"q", L"qi", L"ÆßÞ€ÆãÆÞÆâÆÜèçÆààV‚ˆŠÝ’ÝœD¢ÝÂÆÝ—R—«”ªÆÛì¥ÆÚ”Œ¼–¼©‚úƒ[àÒ‰xÆá‘i¾e˜‘hÛpë’ôtõèçKù†Ø¢ØÁÆîÆëÛßôÜÎáªŒóÆæÆä…Æíµo”ÅÃXÆç¯OÙ¹Üù„~ê‹”çêÈÍTÍVÍ[Æê”Æ¸gñýÆèÜ™Ú–âHˆÎÝ½ÈWŽ©æëÆïªXÆé’åä¿Æå—Žì÷òÓç÷çùèŸÑw´J³žôoí æþDýRÆì¾L»žôëòàÎB­D¶QÞ­åW÷’Ësàœù‘¼™‡™–÷¢òUòTÄšùuù}õšÌI÷èôGÅ Ï“ò€ö’«Oû˜ÆòßŒÆóÜ»Æñá¨è½«^°žÆô…Ñ†uØMÆð†™†¢†šŠíç²—¤•’ôì¾_»üÖHêMÆøÆýÆùãàšÝÆûÆZÆú³H…æÆüžÅØ½±[Æõ…ýÆöÓ™–Öšâ™û†ƒÝÝœŒœ—‰‰óÔœë“ •´®P´\‘séÊ‡rÆ÷í¬íÓ´w´ƒ´„Ë~Ï„À™çƒÃÑzÏBº‘º“»K" },
{ L"q", L"qia", L"ÆþñÊÝÖ“ü’‰¿¨gáMÚžì—ˆXƒîŽ˜Ç¢Ç¡Ãm³sš÷Ä" },
{ L"q", L"qian", L"Ç§ÚäÇªÜ·Ç¨Ç¤ŠdšþˆTˆU›Fá©–eÇ@ÙÝ™÷Ç¥ÅOÇ£’Šã¥ÍOÇ¦Ø@âTŠú ¿ŒR’çÇ«â`ãUûeÇ©í©ƒL†éå¹“Ãåº‘aßw…•Õå½Ötîv™Œ™¥”o”pºžùkòq”q»RôRôS»`ía¤Œò’Rø’ƒqÇ°Ý¡îÔÇ®Ç¯ò¯škÜÇ¬‚¡Þç“bx‹`È“âjìyêùãQäE‰‰˜póéÊnÇ±“Á{Ç­™NåXübòcò`žKžö‘Ç³ëÉœ\Ç²ÄdÎS˜Ç´ç×À`×lÇ·„X½ÏËÜÍÜç‚]Ù»ŒÇµèý—‚ßÇ¶°|É`ã»‰qÊg¾PÇ¸ºGƒŽ˜ ºRÝ€¿y‰µ‹ì¸d»xæZçc" },
{ L"q", L"qing", L"þfìiÇàÇáÇâàWÇäÇãŒxÇåœ[ˆ½àõšäÝXƒAòßÝpäöëõ›è[‰ð®_„…„Í†¦Çéš„—³ÈþƒÇèÇç•¦þ‚“÷˜½éÑÇæ÷ôÜÜÇêÇëí•ŽöFNÕˆö¥™”ÇìÇ×ƒõÙ»’áš ³ ôìóäìm‘cíàóÀžDƒ ³|™¼" },
{ L"q", L"qie", L"ÇÐ°mÙ¤ÇÑÂÇÒæªÇÓ…‚ÆöÇÔ…L‰êü›­ã«›ù¸›Í‰ôòÜã»–AïÆóæºDÛoå›·lö@¸`" },
{ L"q", L"qin", L"ÇÖÇ×ÇÕôÀóV‹]ÂšJ½ÒÕWôÓHîzñŸõŒ˜ÇÛÜËŽÜÃQñæÇØÍZÇ›ˆ²«Âl’ÍÈBÇÝñûâsâ†ëdÇÙ¬läÚÇÚì€‹ŽàºâÛ‘[ûÇÜàßøV”ÜàéÕ‘¦òû¯‘¥Ïˆùjˆa•T¸Úc—vŒ€ï·ÇÞŒ‹äuÏOßÄ…Â’aÇß†wÇ™Þì“l“åÌCžp" },
{ L"q", L"qiao", L"ÇÄàbíÍÈ¸õÎàƒà…„äÛ^ÇÃš¨ÇÂØäófîN‰Œ‰§ŸòÇÁŽÉçØ´“å æ@¿”ÀRÚ‰ÜEèAÇÇÇÈÜñÇJá½ÇÅÇŸ³~†ÌÇÌƒSÚÛ˜“‰”ã¾½¶Êw‡a‹´÷³ ÖŸ÷éÔ˜òÇÆ¯ ´™ÂN×SÚˆ™ËË–çyíXî˜ÇÉá ã¸ó~¿Çê~ÇÎÚ½ŽÇÍÇÏÕVó|ƒsÇË“êímÇÊíI¸[ÜN" },
{ L"q", L"qiang", L"Ç¼ÇºÇÀ”ÖÇ¹ê¨ãÞ«oÁm½«ª]†“õÄÇ»œÙ†óª}—¾òÞïºïÏÁz˜Œ ›¬š‘êè“¬º[ÖmïêÛ„Û–æjçIŠÇ¿Ç¾æÍÇ½éÉÊ@\ËN™Z‰¦‹Ô™{ ÅšÌbôÇÁu“Œ‰‚ñß¿‹ÀHçjìÁ†…†ÜŸÍÁ†" },
{ L"q", L"qiu", L"ÇðH¹êÇñˆwnÇï¶k|òÇ‹päÐÈcé±œ©É’ûjÎ~¾ºEÚ‚·höúíFíGÏbù”öpöqÐ@ý•³ð…´ÆL’@Çôáì«U–_ÃFšüò°ÇóÍAÇöÙ´ÓˆÓ‰ÇõÓaá–†pÇiåÏÞ›½¼zšÂÇò—Wêäš‚âUí–œrœªåÙÛÏ¦±H°“½‡ÍŸªôÃÓpŽ€Ùgòø­GäMáb÷üõFþ•õ‰÷A“zôÜÌUþI" },
{ L"q", L"qu", L"ÇøÇú…JêrÒÇÚ°Çýá«EÇü’|ˆo›µÃlìîÐ Çù¼ Çû…^ŸaŸŠÔxÇ÷¹LòÐ»–Úmñl‘tç”·ñnÕoüLõ@ó”üDÚ…Ü|ÓNôðùŠ÷ñòŒö÷OÚÛ¾”×ëÔÃaÇ†ð¶½PÁ”ÇþœTÈÝ@Þ¡­SøzíáÏJÏgè³öÄüšÞ¾ßž›‘ó „ÅJë¬™á»cñ³ÐRáé™êÜdèŠó½ûYÜÄÈ¡¸lÈ¢Ôs¸yÎƒÈ£ýxÈ¥…„`…íÂ^ãÖêïÈ¤é‰üCüzé˜ÓUÓYÐd" },
{ L"q", L"que", L"È²È±ÀŽÉUãÚÈ³ÉÖÈ´…s‚ˆ«¬jí¨È¸È·³‚— ã×‰U“nÈµ°”´FÈ¶â‘U´`´_Ú|é  PêIµCùoµ]" },
{ L"q", L"qiong", L"öÆÚö…oŒ^Çîñ·Üä–÷þ{óÌ¹HÚ^ÄŸwŸzÇíòËÍ‹Å|õ¼±žŸ¦ŸÅ²`¸F‘w™K­Wƒ’Ë}Ë•­‚¸\­Ž‹Ö" },
{ L"q", L"quan", L"ŠIƒãªÈ¦‡ü—¨—Ñ¹ˆçzÈ«È¨¾íÚ¹çŠºÜõZ›§wÈª »éúÈ­îýÈ¬³o³ˆ»Š÷†­È›œ²½hóÜ Å¬†ÝbÓjÔ“‘ÛIãŒòé˜ØÛmñÈ©÷™÷ÜògöeŽk™àýjÈ§ÐSïEáëÈ® ãî°žïç¹¾JÌ†È°È¯ º„áíj¿X„ñ˜TêB" },
{ L"q", L"qun", L"‰æ‡ïåÒŽ ŒlnÈ¹ÈºÁtÑd÷å" },

{ L"r", L"rao", L"Üéæ¬ÈÄèã‹ÆÊ˜ïÒYðˆÈÅëN”_ÈÆßvÀ@" },
{ L"r", L"rang", L"ÈÂ·y„ðƒ¨ÌZ«KžìüÈ¿ð¦Ü`ôX‰´ÈÀÈÁ }ÈÃ‘Ó×j×Œ" },
{ L"r", L"ran", L"…ßÃVÐ€Ð…Ð™ÍcòÅÈ»ó†÷×‡YÈ¼¿‘ƒÑÈ½ÜÛŠ˜È¾«z‹v™L" },
{ L"r", L"re", L"ÈôßöÈÇÈÈŸá" },
{ L"r", L"reng", L"ÈÓÈÔÞwµiÆeê—Üµ" },
{ L"r", L"ren", L"ÈËØéÈÊÈÉ–ZáÈÎÆ\ä¶eôã…øžÈÌÜóÇY–ß–á¶‰ïþÜrÈÐ„UÈÏ×šØð¡ÈÒŒãâ¿ ®Àéí–kÈÑÈÍÃMµsŠžñÅ¼x¼ŒÜÓ•ÑG—eÝØÄH½Vâmïƒìzì~ígïšÕJ" },
{ L"r", L"rong", L"ÈÖëÀ–ÑÈ×ÈÙÆŽáõÈÞš¿tÈÝŸV‹†áÉ“r‚æ½qÁs“mÈÜÊ‹’ÈØ˜xéÅ˜sÈÛ·Z¬Œ¿^éFÑ’òî˜ŸÈÚÎñŒ‹æŽV hægžq•íÏ”ÈßŒ]ˆc‚ÔÝPšÕ·\" },
{ L"r", L"ri", L"ÈÕóR‡ðÐzâJâVâ~ñ_agfihnutr’£Å–ècÌƒ" },
{ L"r", L"rou", L"…œ¶bÈá»€Ã…È|‹YÈàœn˜Q¬yÄ\Ÿ§ÎjôÛÝŠõååˆ÷·òk­~ù’ökíqÈâŒ`×k" },
{ L"r", L"ru", L"ßÈçûŽšÈã’–ôï¨ÑMœx¹TÉSãœÎpÊ‡Èåønø›àéÞ¸å¦Èæ‹ç•ãñàÈäò¬á}îž÷pÈêÃNÈéÈèàr”JÈëä²äáçÈÝê†ä‹‡Èì¿d’C–dŽ]" },
{ L"r", L"rui", L"®c¾qÞ¨—MÈïÊt™GÀBÌGÌH‰ÇÜÇ›IèÄò¸ÈñÎTÈðî£ä„äJ…±" },
{ L"r", L"ruan", L"ˆë“É‰¼ÈîÈíëÃÂXÜ›‚¢‹\¬}ÄQ´M¾Ý‰­wµO" },
{ L"r", L"run", L"ÈòÈóécét™˜ôÄŒ" },
{ L"r", L"ruo", L"’µ’Ú…ªÈôàeÙ¼Èõ‹SœcŸx—íÉmóèºO kö}ö”úU×" },

{ L"s", L"sang", L"É¥–øÉ£†Ê˜šÉ¤ÞúíßÑ˜òªærî‹" },
{ L"s", L"san", L"Èýq²ÎÈþë§šÉ…xšÐ ÑôLÉ¡‚ãÉ¢ôÖâÌ¼R¼V¼W¿™çDçoð€‚^éd‰Ð" },
{ L"s", L"sai", L"Ë¼šºà“HÈûÈùšË‡TàçÈúî|öwÈüƒwÙº›†ð" },
{ L"s", L"sa", L"ØíÈöÈ÷ÔQìƒ¥ž¢ÜaØ¦è•ìªëÛÈøâlñ`“—Ê”ïSË_™¨’PÆjo–ÓëMÌƒ" },
{ L"s", L"sao", L"’ûÉ¦œÐÉ§ýçÒÏA¿‰öþïbòXò}ö…÷fÉ¨’ßÉ©Ü£ðþÔïš×ëý²„ór" },
{ L"s", L"seng", L"É®ôO" },
{ L"s", L"sen", L"É­—Ø˜¦ÒI" },
{ L"s", L"se", L"é~É«››É¬–ÜØÄœiï¤ëšm†ÝÉªÈû“ºšoäC®æí“ö‘­¯™ð£­i­ži·wÀNÞQ·†çmÖ ïo¿L÷n" },
{ L"s", L"sha", L"É±É¼É³É´É²É°š¢É¯†~ªQ»}¼†êýï¡—Eðð³“—É·ÊeôÄ˜f˜×Ò­öèô‹éŒóšõõæ|À\ÉÝÉ¶Éµƒƒ‚ÈSŽ¨†—ßþ†ÃÏÃBàÄì¦ÁœÁ ¹€é„ö®" },
{ L"s", L"shai", L"É¸õ§ºYºkº»iÉ«É¹•ñ" },
{ L"s", L"shang", L"ÌÀÉËéäÉÌõü¶@‚ûÊKCgÉÊ‘^š‘ìØÏDÓxÖ…ôlÉÏÛð‘ûÉÎÉÍ˜¾Ùpä–çLÚJèlAÉÐŒ¬vç´¾yì " },
{ L"s", L"shan", L"É½áêßÉ¾„hÜÏÉ¼îÌÉÀÉ»æ©Š™ªG’´ô®ÉºÕ¤–ÅÃˆ¯ZÉÈÜ‘²ô¸–áŸ‚ÞõÇ„š“É¿Ž»‡Aäú¿õŠ¿„ëþ™cÁÁƒÉÁÉÂê„žèéW•±˜ŸšŸÄÓ@Ú¨ÉÇðÞµ¥Ó˜ØßÚ]µ§’ïÉÆ—ÖìøãˆæóÛ·ƒRÉÉ‰‰Žþˆþ…˜è”»š`ÉÃæÓ¶UÉÅ´ŠÉÄÖb¿˜óµÏ€ç—ðƒ÷­ò~Ù ×iž¨÷W÷XˆZ" },
{ L"s", L"she", L"ÉÝâ¦ÉÞ®Œî´®ÝfÙhÙd™ÉàÙÜÕÛÍFÉßê^ÞéÍ…Éá’ÎÒ¶ØÇÉèÉçÅh…‡Ê°ÉæÉäÉâÔOœh›õäÜÉåÉã“”ÊJ‘bì¨Ï‡ísòM÷ê‘Øž—”z™Ý" },
{ L"s", L"shao", L"Çz„ÉÓÉÕÉÒÉÔŸ†Èp”ïòÙô¹óâÝiÇÊŸýó™õ}É×ÉÖè¼Üæ–¶«xÉØÉÙÉÛ…pÛ¿ÉÜÐŒÉÚŠ¾½B±¾KäûÊ–" },
{ L"s", L"shei", L"Ë­" },
{ L"s", L"shen", L"Éê’JŒæÉìÉí»pê²ÎÚ·ƒßÁAÉëŠÉð–¸šá·Œ«|Š·»rÉïvÝ·±m®`ÉéÉî¼”žƒÂÔY—ªÑ[ÈÉ†ÁKÔ–ôÖ®eÊQ¼B÷“ñ‘ËMŸö•Üù_õ˜öYöŸÊ²ÉñÉõãhö•ß•zÉò² ÉóßÓïòÚÅ×ŸÉôÔBäÉÕ”ŒîTô•Ö²sžc‹ð×}Ó\ÉöëÏ‚L•Y›Ø±sÃŒÉøµŠÝØÄI¯}É÷õé©ò×Í–Bäv¯”ˆÞ˜Y»]" },
{ L"s", L"shou", L"…§ÊÕÊìÞÐÊÖÊØÊ×ˆ–ô¼ÊÙÊÜá÷ÊÞÊÛÊÚ›ìç·¯lÄf‰Û‰ÞÊÝ¾Rª•«Fæ" },
{ L"s", L"shi", L"Ê¬Ê§Ê¦…ÚßŸÊ«û\Ê­þ˜Ê¨Ê©ŒÆ›¸ŽŸ½JâPÈžÊªœ¢œáœÛÉNÝéãAÔŠª{¬‹õ§øOÐêø[¹•ÎtÑ öõåœñöXö‰úPÒ|á‡Ê®â»Ê²Ê¯Ê±Ê¶ÊµŒg•EïzÊ³µuìÂÊ´Ê°Š¸]ÛõÝª•rßYŒœ›œÒ‰PãJŒ˜tÎgöåüœü×RöˆÊ·Ê¸dõ¹Ê¹Ê»Ê¼ÊºŒjƒ½¹Eâñ‚Ê¿ÊÏìêÊ¾ÊÐÊÀFÊËËÆ…bçÊ½‘÷~ÊÂÊÌÊÆÊÔ…áÊÎÊÓ–ÉÊÁ–§•gÊÇêÛÊÑ^±cÖÅÊÃƒàÊÒÊÊÊÅ±i±xîæóÂéøžø–ò¶ƒá‹Ò•ÊÍÙBß±ÚÖÊ“J«ÊÈÉP„ÝsÝYóß±ÓlÔ‡â‹âžï—ãvÊÄÅkßmŠ]ðSðOäKÕžÕœÌÊÉ‹Òß}ó§ÖuºáŒÒnWÞyÛ¸bÖŸ³õZº ö|»]÷t" },
{ L"s", L"sheng", L"ÉýÉúêj…ÖÉù”Î–™•N›ˆ õÆê…«{Éüš}ê’óÏœ¤Ÿ„ÉûãHå•Â•ü›ù|äÅÉþ‘™¿I¿ŒÀK×WÊ¡íò‚¯œƒÊ¥Ê¤êÉ•…³Ë„Ê¢ÙKÊ£„ÙáÓ¬]Â}‰˜˜|ÊoÙ‹¸i•úþJ™T" },
{ L"s", L"shu", L"Êéì¯Êãç£êxÊåÊà–€æ­Ý±Ù¿‚‚Êâ¼‚•øŸYÊáàgÝÄŠì’æÜ“ÊçÊè¯EÊæ¬`½ˆë¨šÌÞóÊäÛSÛ\Êß˜ÐÝ”õ_™]ƒ©”dùeŒ«ïøÊëÊêÛÓÊì­qÚHÊôÊî•¤ÊòÊóÊñÊýÊð©ÊíË\Êï°PËŸÒeÒlŒÙÊõ–XÊùÊøãðÊö‚JÇO†CÊ÷XÊúË¡’¿ÊüŽõÉD½RÐgÑVŒ¥ã_ëò¸wÊûÊþäø”µØQåfë—ò˜äùŽçTÌ ž‚¼^ÐO" },
{ L"s", L"shua", L"Ë¢à§Ë£ÕX" },
{ L"s", L"shuang", L"Ë«ãñË¬ËªëpóZæ×‹þò‚™Üú{ûtµdÆCóLûUw‘S¿Y‰už“þBç`" },
{ L"s", L"shuan", L"ãÅË©éVË¨äÌÄY" },
{ L"s", L"shuai", L"Ë¥Ë¤Ë¦Ë§Ž›ÂÊó°…i" },
{ L"s", L"shui", L"Ë­ÃŸÕlãßË®šìËµŽœ›ä›çµˆË°¶ÑcË¯" },
{ L"s", L"shun", L"˜JË±Ë³í˜Ë´ÊŠ˜ù²i²pË²ôB" },
{ L"s", L"song", L"âìËÉ–…–œ–·Š»Ú¡‚‘Ý¿ŽôáÂäÁ—s³—áÔë‘¡™€ó þeËËã¤ËÊñµè˜B‚öØ‘ZÂ–ñžþdËÏËÎËÐËÍÔAËÌížÕbæðm" },
{ L"s", L"shuo", L"ËµÕhÕfåùË¸Ë·îåË¶šF²ÝôÞ÷ª“éÃ´T¹›æl qèp" },
{ L"s", L"si", L"þSÛÌæùË¿Ë¾¼iË½›qßÐ‚hË¼lð¸ÌŒ‚ÆçÁ‹wòÏË¹½zãj—ö¶Dït„@ØË¶LÎEïÈäFÁQäl¾Œ´fäùË»‡zËºÊ‘PŸùÎ‡æJï\ÏaÏzòlçrúƒýDËÀËÈËÄËÆËÂãá›…æ¦ÙîËÅËìëŒK–yýæáËÇãô›£ŠÙÙ¹–Ÿ–Æ µÊ³ï~ÃB›å›—ñêÂ]—tóÓâLÒ–¸rËÁËÃØ|â‘â–ï•˜{¶Tñ†Êœƒž[…†x”ñõ•ù‹" },
{ L"s", L"sou", L"ÛÅƒð’ÈànËÑÉLÉrŽùCà²ªvâÈäÑì¬“–“¡ïËòôËÒágæ}ðtï`òp…®‚ÏàÕî¤ËÓÞ´Ë’™¸»PËÔ¯˜”\" },
{ L"s", L"su", L"ËÕ®dËÖ¸@öÕ·dõ‡ÌVÌK™Å‡ÕË×«TÙíËß›ƒËà›«ä³ÇxËÙ«ŽËØ»šƒ—VóXËÞÚÕ‚ÑËÚÔVÃCûhãºËÜ‰Oßi‹•à¼ËÝœßËõßpÝøËÛ˜jåÄhÚxö¢ä_ðM´c˜Â˜É‘ˆš’¿ióùÖqË‚˜þ­XÛ‘ò“ú‰÷TÆj" },
{ L"s", L"suan", L"â¡¯iËá…Wµ{¸Œ¹gËâËã" },
{ L"s", L"sui", L"‰åÆVÄòËä›ÔÇ]†a‚‹Ëåíõî¡œñŸÕìšå¡ëmËçËæËìßU½—ëSól­…ÄŽžvËè‚Ëê³ZËîÚÇˆ¼ÀŸ«šqšrËé²B´âËíÜ·[‹ÓÙwÕrìÝ™p¶X­jËë·uåäÒ`¿…¿“ÀZ”ø×\çwç›í}Ý´" },
{ L"s", L"sun", L"ËïáøÝ¥ŒOâ¸ïŠªs“qÉp˜ƒÊ˜ËVËñËðöÀ¹S“pé¾¹º‹æ{úZ–" },
{ L"s", L"suo", L"É¯ÇjËôæ¶’­èøËóêý‚éíüàÊËòôÈ“™ËõÚtºwºz¿sõ€ËùßïË÷Ëö»Ëø†îœÅ•­Ñ–¬­Fæiææaæ•ßCœàÎR¬RàÂ÷_" },

{ L"t", L"ta", L"ËûËüËý ­µkîèõÁãBäâËú˜d¶NÑÌ¤œÍËþ‰‡Ì¡õ]÷£«HöÍØí³þjÌ¢ãËªH»†„›ø‚èàªßeê`“‚äðšÏé½ß“éÕwåJ™\‡–ìŸÌ£êíOêFÜDêY‡Å×nÜc‚@ÈZåÝ [ÒkùŒ÷m" },
{ L"t", L"tan", L"Ì®Ì°Z¯a†®ÅjØÌ²Ì¯‡cÌ± ”Z”‚ž©°cÌ³ê¼Û°‚„Ì¸µ¯ŠòˆÅ´ñûïÄÌµ˜WÌ·Ì¶‘…‰›‰ Õ„á]•ÒåU‰¯Ÿï™Aå£Ì´îtÀ—Ë“‰Â×TávØ×ZÀìþÌ¹îãÌ»ÈIÌºƒNãg†ú‘˜‘Ÿáa•Æ­fÌ¾Ì¿Ì½œž‡@Ì¼ÅlšU" },
{ L"t", L"tai", L"Ì¨‡òŒLÌ¦Ì¥Û¢•@ˆrææÌ§ìÆžåÇ õÌöØïUÅ_¹xñ~õTƒˆÞ·”E‹ê™…»Fß¾Ì«‰ûƒèšùÌ­›LöëÄÌ¬îÑÅvÌ©ÌªâœÌ‘B M" },
{ L"t", L"tao", L"‰úß¶|ÌÎÌÐÌÍìâ½dÔ|þ“†ÌÏŽµ‹—˜…¬•èºï‘¿_¿lÝýÖzíNíw÷ÒÞ„üä¬ÌÓ†GÌÕÌÒ—ƒÌÑÌÔÀ‡ßûµŽÑiÎI¾TìŠì’á[ä•ñŠòPðuØ»ÌÖÓ‘Ì×" },
{ L"t", L"tang", L"ÌÀï¦œ«‡RôÊ„¨ÎvÌËËTïÛÛçMíUü‘ˆnÌÆÌÃÌÄ†°ào‚ÚÉyëGÌÂäçÌÁŸ¶˜yf¶Kè©ÄgÌÅ´g¼CéÌ˜üÌÇó¥ºLÛ}ÚZõ±ó«¼QæhðnðyêOúS¹àûÌÈ‚«ÌÊã®ÙÎñíÌÉéEæ†ƒ¯‘Ü ‡•ò²˜è’ÌÌ“­ Cç|" },
{ L"t", L"te", L"ìýß¯ÌØï«í«äˆÏc–Y’PÃŽÀ’" },
{ L"t", L"teng", L"Ä†ü’ÌÛ¯\Ž¸ÌÚÌÜbëøß‚ñÎŸ¿gÖ`þ—ƒ£ÌÙòvöŒ»L»TÌ„óIìL" },
{ L"t", L"tiao", L"”þÙ¬ŽçÌôfìöÂwÆKÌõÜæÌöŒýGµx—lµ÷ÈVóÔÉ‚ÉŠö¶˜Ôòèäpöæì›÷ØõæxýföœŒi•q–IÃxñ»ÕA¸I”Ó‹àÌ÷ôÐ½rÒ›ÚqÌø¼g" },
{ L"t", L"tian", L"ÌìƒÌŠõÌíáLìjüVìpÌïµè›pŒÄÌñÃbî±®x®ƒîäÌð®\ÈJœÌî‰\àÁãÙ“´[¾g¸K´k­kêDúcúlãÃéå‚†ŠœL¤Ó`•‹¬_Ìó±™¯tÌòï›¬™ÙqÓCå`ÞÝÅqø‰" },
{ L"t", L"ti", L"ÌåÌÞÌÝÌàÌßäRþ”`úfúe…†Üèç°‚¨‹q¨Ìáœvç¾ÉßXÌä¶”ðÃÁHÌâ¬v½†Ù²VÑ|´YzÊƒÓ¾Ÿõ®Ú„ÌãÛ‡å÷–Öpõ{î}ùYòfù•ù—ö[¶_ú‚’«ÜnóeÜƒów‘øÌë›¢Ìê‚mÙÃåÑÌéã©ÌèŒÏ’óßP†—¹GŠµÌæ“WñÓÑ{šYóšËSÌçó›óž­ƒ‡¢»GÚŒ" },
{ L"t", L"tie", L"ÌûGÌùÝÆÂzÙNÌúÍuâŸãŽƒcç“èFò…ãï”÷Ñ" },
{ L"t", L"tou", L"Íµ‚Ê‹‹UäWæBÙïÍ·Í¶÷»î^Š‡¼}”«üWÌeÍ¸" },
{ L"t", L"tu", L"Í¹Œ_Íº¶dLÍ»›Þ’Øœ£ˆàÈ‹¯fáäŒùWýC‡íÍ¼ƒòÝ±Í½Í¾Žêx’¼Í¿„—^ÍÀÝË“\¶•¯…¹\âŠÄ‰TÉ\Ä]O¤¬Ÿõ©ÛTˆDˆEñGòBå„ùIùúhú“ÍÁˆMÍÂîÊ†lâQƒ·ÞƒÍÃÇÜ¢ùr›BœÂ" },
{ L"t", L"tong", L"¶²žçÍ¨¯]½pàÌÉŒŸ×˜¿ÙÚÍ¬Í®Ù¡¶±ŽäMá¼d†LªIÜíÛížú•zÍ©›ÏíÅÍU¶‚Í­±Í¯»ÚUÔ˜ÍªãPã~ãnï ÷‹„çÙ×äüª‘™H Õ•Ó–SÄ€ŸüšÔ·rÍ«õjÍ³Í±Í°½yÍ²¹c½ŠâúÍ´Ðh‘Q‘q" },
{ L"t", L"ting", L"ÌüŽØÍ¡î®ÌýÂ[Ìþ…ˆŸN—H½–ì˜Â—ÂŸaÂ dß‹Í¢ÜðÍ¥Í¤Í£ÝãæÃµœsòÑ¹j—þ˜wéƒöªÎbÂŠÖFüžˆN®k‚KŠÇÍ¦›àŸPèè¬EÃ‰îúÍ§ïFÕPäbîc" },
{ L"t", L"tuan", L"ªlÍÄˆCŸ™Ø‡ÍÅ‡âÞÒ„–“»`ˆF‘_˜¤ºi™ˆæ˜¼aúoú™®™‰’î¶åèœ¨Ñ‰" },
{ L"t", L"tun", L"ÍÌ…×•H›âŸl–N‡pêÕÍÍˆd¶Ú÷ÆXÍvÜ”ëàØZï‚÷ƒôü`ë˜ÍÎÄ™ÙÛÍÊâ½" },
{ L"t", L"tui", L"ß¯ÍÆÉ—Ë”wÍÇëPŒ¾˜úîjîkînôsÌL·~Û‚QÍÈƒUÛƒóh‚MÍËŠÑìÕÍÉÍ‘ÍÊòD [" },
{ L"t", L"tuo", L"Ø±š×™ð˜ÍÐ’Lšú–lÙ¢ë…ú…ï›kÍÏ’„Ëµ‚MÇh’É’¨Ð›Óšï€›ñÍÑÃ“ñXô…õyêeÍÔêuÍÓÍÕ öAãûÛçèÞÍÒíÈ³aÐ†½FÔqõ¢õÉˆ÷ñW´P˜’ñjñ„ñ…éÒørõDü˜ùKònö¾ò™óCüƒ±Í×âÕÍÖ—ø‹µ™EözÍØèØš¼È[ÍÙÚ—šÍóêüÆÇÌE»XùD" },

{ L"w", L"wa", L"ŒÜ°¼·Š„¾ÍÝÍÛÍÚæ´·“®|·˜‹z†œ†å®HÍÜ“‰œÎj¸Dü|íc”…ÍÞÍßßœØô…÷³[ÍàÂv†ìëðÄeÒmí€®B®M" },
{ L"w", L"wai", L"†JÍáþZ†·¸áËÍâî“" },
{ L"w", L"wei", L"…yÎ£Î¯ÍþžùÚñêžÙËåÔ†ÒÝÚÈ–‹náË½“f“GÌœÕ—Ü˜LÔ•ìÐÎ¢ÎOÎkÓA¿JÞ± V÷˜°LögöhÎ¡ìSàíÎªÎ¤Û×Î§‡ìãÇÎ¥àøãí›”_ežéífÎ¦ä¶á¡Î¨Î¬Î©¬^áÍ‹W‡ú†ÂŽ®ß`œ‘œ¿ ‘¾SÎ«àŒÉ–¬‘áWå…éõdžH‰Ã²‚ÓW à™ÞÎ°Î±Î­ÆYÎ²Î³ì¿çâä¢›¾æ¸ÇUÚÃÚó‚Î‚¥Î®™—|¯_³uó[ó]ó\Îâ«œwÉJÈ”Î@—Û•¥Ÿ˜ôºðô¬|è¸Ä^öÛ“ãéƒ^ŒÊlîQ¾•Õ†ÛcílËeƒ¤žSå—õnï]ítžwí|”ÍÎÀÎ´Î»Æ„Î¶Î¸Î·ê¦…°Ç‹Î½³}Î¾ÒÅÎ¹‹yâ¬Î¼Ÿ£Îµ´SÎVÎo´o ÒÎ¿¾“ŸÝÐlÐoð]õK‘£Ö^ÁWÏGÒEÎºðjÞEË—çA÷ìGÌvðŠ×~ÜZÜ^×ˆ’Ë‰ŠŽU" },
{ L"w", L"wang", L"ÞÌŒ²Œ¶ÍôŒ·Œµ“ƒÇÍöÍõ©ÇwÍ^À ÀŸÍø´Íù¸ØèÍ÷ã¯ÈDéþ—Ÿ•™Í‡Î\¾WÝyÕs÷Íž_ÍýÞ‚ÍüÍúºÍû–R" },
{ L"w", L"wen", L"•jÎÂœØÞdš˜X¬ÎÁ˜v¿AÊ•ØnÝ˜Ýœ÷—íMö€ö“ÎÄÆ[¨ÎÆžÉÎÅÎÃÍP¼yãÓ«œö©ñmñbÂ„¯‡øYøjô•Îé”ééšÏRü•ÀIêZØØ°ÎÇ…Ð’^…ÝÃWÎÉ—SÃ‚ÎÈ·g·€ÎÊŠpÃâãëÇ|†–œb“h“‹½ƒî‚è·‰eæ’ðw" },
{ L"w", L"wan", L"›ðÍäØàŽ¦ŠþÍå‰G±›òêÍãŸ‰Ïž³Íè„\Ü¹š÷æýÍêŒñ’eÍæ¼w’ÂÍçØ™ÍéîBÂDÍð‚{Ý¸Íì±D†nçºˆ¾Íï—iÝÒÈXÍñëäÍí•ˆ•Š•–çþÍî—µÍëîµ¾U¾OÝnÛläjÍò…e…dñŠ€’ÌÃÍóÈfÂûÝkÏä[åsËH²oÏTÙ–æ~Ú@^–v¸Š¬T" },
{ L"w", L"weng", L"ÎÌÎËœåûlÎŠÂæfúO„ØŠTÇÝî‰R•²²\”wÎÍÞ³®YÀšýN" },
{ L"w", L"wo", L"ÎÎÎÐÙÁÝ«Èn†ªiœu›óÎÑà¸¸CÎÏÎÛbÎÒŠñŠð’Ó¥ÎÖë¿–†ÎÔÅP’Ü›ð‚¬á¢‹_ä×ÎÕŸsíÒ—çÄOÎÓ²Yö»ÄŸ­xüý}ßj" },
{ L"w", L"wu", L"Ø£ÎÚÚùvÎÛ›@›AÛØÎØÎ×–gì¶ÎÝ›´ÎÜÎÙ¶ñžõ„·—àw†èÕGÕ_šT¹™ÎøŒæuöƒÍöÎÞÎãÎßÎáÎâ…Ç…ÒàNÆ•Ç`ßíŠÓ}ä´›žÎàµ¬@èžûcŸoòÚäoÊ‰˜î­NùMÏwõˆ×O÷ùú~þRÎåÎçÎéØõåÃåüâÐâäâè«bÎäÎê‚—ßAê‚ÎæŠÃŠÕêõ†•« ðÄ´I““ŸÊ¬Îè‘“ŽT‹³ƒ®W²yù^ÜRþ@ÎðÚãÎñÎì’NŒäŒíÜÌÎëè»Îïí•J³J…t”–‚WÎó„ÕÎòš’»|ÎîìÉðíæÄëFæð¶ì}Îíë‰ÎŠVœ×‰]ðÍŸ½å»Õ`öÈ¸PëœýHýIìFò\ÌFúF…ž–YöV" },

{ L"x", L"xi", L"Ï¦ÙâßÎüÏ«èÎ÷’VÏ£…kÎöÎôñ¶ÃZÃ[ÎùYðœjÛ­Üç‚`¹ÇbÞÉŠÖßñä»ªLŒÊÆÜÎþšãÏ¢Ï¤Îø¬NÚTâRì¤•„—NÏ§Ï©ŸXŸ_äÀœl†ŒÝ¾‚ÝàqŸmŸyÏ¬Îú•‘ôâÁ—ô¸ôÑÏ¡±–¦À°ÎýðªñÓŸ›…wÐÉYÏªÆÙÒÎõŸÁÏ¨˜~òá¾kðFÒ Øg¯Œ´mÏ¥”Îû‡qæÒ‹Ä„DéØ˜é•Êì¨ŸçŸèìäó£Î‰¸OôËåaØ‰õèØló¬ØGØH²q O ×Ž`ÀG¼YùT×@õµÓ}ç^ç{ë^á@Žd‡½ ÞêØ xð„Ó‚÷ûú ÐPÓ„è„Ï°àEÏ¯êêÁ•Ï®†ÕÏ±ÉtÉj—áídÚv˜›ñÞË@ÚôÏ­Öæˆ÷žìIïeòwò„÷@ÒuóNÏ´– çôÏ³áãÏ²ÝßÈ}â|ãbãcÝûSåï‘‚š]ìû‘ƒÖLÖl¿u‰¸ÏkÛ’­t÷^²—‡ÖÜh…[…cÏ·â¾ŒÁÏµ…äÏ¸Û§Oï±__àS‚S†AŒÈÀ…š@ãÒ¼šâMÚiôªÅb‰IÏ¶—ÌìùøëK½”ÚVŸ¼‰€ Ì·G•À‘ïÊ“ÓB¿]ü_‘ñ‘ò´ŽÌŸðqô]ÀMêSìUÐaŒÚŽ|„LŽ‡‰ñÇ‚†{ÑQ³’†ÔÂˆ‡™S´—õ•" },
{ L"x", L"xia", L"ßÈÏºØBéi‚ÒïPŸÏ¹ÎröyÏ»áòÏÀ‚bÏÁêƒÏ¿žÙèÔžþ{ˆ®ªMµ„«”íÌÁŽÅ{ê˜¼ÙÝç³ˆåÚ¹dè¦År”¯Ï¾Ï½´W´lÊ›¿[ÚYô Ï¼å’Ý æ_÷ïòhúTépBÏÂÏÅ¯KÏÄ»£ÏÃ²LÕ’‘³óÁ‰ìæç]ˆY—" },
{ L"x", L"xian", L"™ÏÉŒÝÏËÏÈŠhüÙë¯–}¶iÆxìì–žôÌÝ²«ˆÏÆèÏÇõ£õÑƒMƒmã”ÏÊ‡Jí„äTåßËW‘œ‹Íåví†õrÒD¿ÛŸñM‹ü”s`ÀoúNÜ]ÒvÀw÷€ÏÐÁÏÒ…îŠˆÏÍÃjÏÑ±]ÏÌ’¦æµŠÞ‹MÍp½LÏÎÏÏéeéfÍ€ðÂðïœ¶†¥†éÏÓ®Qã•ÕtÙtÁ{·S½‘‹¹‹¸“ÍÖPá_Ý°B°G²vËµUûyû’ÚDúšú‘ú’ÙþªAÏÕÏ´ÏÔžóšÀò¹ê“áýÚ`Ï³óÚÍ˜õÐµ “{Œ°Œ¯ãŠ¹‘ëUªŽMªžÞºå‚ìÞî‡ŽÒ”gÌ\™Ì×]«Ní`ï@ž¶¼ûÏØÜÈá­ÏÞÏÖÏßÅ`±hêˆÏÜŠ«Š½sÏÝÇ{†Z›×ˆŸˆÉ¬F•ÏÚÏÛÀ‰±•½mÏÙ»˜‰dÏ×ÁwƒgƒnÕ^¾Q¾€ä}“È‘—™Z˜óåDðW¿hØR‰·üGÅ@žn«I¼`ö±ýE…ûÐjèv" },
{ L"x", L"xiang", L"ÏçÜ¼ÏàÏãà_àlàmÏáŽûÏæç½àxÝÙÈeËGÏä¾|ÄÏåû‘Ýæø™Ö­ÏâÀvè‚óJ­˜½µßÏêâÔ–ÙÏé½|ÏèÔ”ÛKÏí‰ÏìâÃÍJ•}÷ÏÏëã}ðAößõaÏ†õœí‘ð‹ð“÷zþWÏòŠ¢ÏïÏî«“Ïóí—À‘Ði„âÏññÏð•ÚÒVó­‡»ç}÷P" },
{ L"x", L"xiao", L"ž¼ž½Ð¤èÉ…ëßØÏ÷‚PæçèÕç¯ŽéžñÏüŒnåÐÏûû^ÌŠëªVÏô—nŸ^Ïú¯e¯hÁ›Ïõ³‡·›òÙ½‹“`óï‡EäìÛXšRäNÏöª”“ß‡^‘‹Ä…Ê’–ïY÷Ìø{ø“º}Ï]ÏSËr·nÏùžtÏvºón™Ï‡Ì‡Æóuújò”ÐDš®Ì‡›©àUáÅÏýÔFš¥ÕqÐ¡Ïþ•šóã¹q°~ºSÖj•Ô°†Ð¢„¿k†DÏø›ß‚jÐ¦Ð£Ð§Ð¥‚å”¬Ô‰Õ[‡V‡C‡[Ÿêš^”Ã”ÂþM" },
{ L"x", L"xing", L"ÐË õÐÇˆžóUÐÉÐÊŸ“¬wÐÈÓq¹ž¹“õSÅdÓwòH•Û°‹ö]ÐÌÐÏâ¼ÐÐÚêÐÎéàDê€Üþ›™ÐÍè—ŠÈè™íÊâ]Íœîã‹ãoätðhÊ¡²MÐÑß©ÐÓÐÔÐÒÐÕÜôÇn‚†Šüã¬›ëÈŠ¾mþN‹ñÅB†QÖ_" },
{ L"x", L"xin", L"âàÐÄß”þ€ÐÁÐ¾Š|ÐÃžÔ–‚ÐÀê¿±^Ý·‚r¹ÔDâdÐ¿ì§ÐÂQä\‡Œ‹×Ð½Ü°öÎñQ–“ïâÒWç†²êc¿Ø¶ŒJÐÅÜŒÔMÃ’ÐÆŸ{ñ^îˆÅgá…" },
{ L"x", L"xie", L"Ð©ŠÀªn“aÐ¨ÐªÐ«ÏÒ¶Ð°„µÐ­”ýÐ²…fŠGˆ•elÐ®’’¶Ã|Ã~Ã{Ð~Ð±Ð³ÙÉ½eÁ–½’¬€ï†àÐ¯Ÿ»ÄnöÙÐ¬Îq¾™çÓß¢“û¿EÛÄÖC X‡¯”XíPÒp”yŒ@×ýšÐ´ÑªƒæŒ‘Ë†ÄžÂç¥Ð¹ÐºµmÀ‹›ªžàžáÆõÐ¶…lÐ¼ŸL¶cÇ‚Ä‚´Ÿc¼œÐµ½X½uÙôÐ»ŒÑ‹räÍ‰fƒD½âìˆé¿éÇÑ€•»¾Š‡ƒŒÔâ³ŽOÊÐ¸âÝåâÞ¯ËZ¼Ií…ÖxÒCÛÆ‰êžaíCý^ÀTÐ·Ï’å¬ yýaýkÀiýKõó" },
{ L"x", L"xiong", L"„öÐ×ÐÖƒ´ÐÙ×›ÜºúÐÚ›°r†MÐØÃrÔKÔžÙ‚ÐÛÐÜŸÃŸ‚Ÿ‡×œÔw‰é”¸˜U" },
{ L"x", L"xu", L"ÓõÛ×Ðçíì¯Lí¹™øñãÐëçïÓ’ÔSÑSÐéÌ‚»× ‹€“Tœ•šHÌ“íš½—ìÐèôqÐæÐê‡uÊŒ‹Áš[¿H¾–ÎdÕšš_ ^ÖžôzÀ]òôPè`‚TÐìƒÛµŸÉ[ÐíÚ¼…éŠä°èò«†Ä• Ô‚·Pà†ôÚÖ[õ¯±SÐñ•BÅÆ^Ðò›Tò…rV›UÐô•dÐðäª•vš~ží«—ˆ¦šAÐóÐïŸTÐ÷Ðø”›”¢ÛÃ„ÔäÓÐö‰ÙÂ{Ô[Ðõ•ý¾AÙ[íœœäÐî‘Aìã˜s…ã„Â…¾w±N²W·Vôˆ¾{ªËvË…Àm÷rþCÞ£" },
{ L"x", L"xiu", L"ÐÝ‚cÐÞâÓßÝÃ‘žòÐßÃƒð¼Å^õ÷âÊó…ã–˜¼÷Ûø æTæ™ð}÷GïqÆvÐàËÞœú€¼NÐãá¶LÐå«‹Ðä³ô¬LÐâ½‘äåÐá­PÑ…Ñ„äPÎ¿‡›ÀCçVçnýMõx" },
{ L"x", L"xue", L"Ï÷¯TÉHÑ¥Ñ¦ÞjÞmíYÑ¨”ÄlÆ‹NÑ§í´û`Ðõ½ŒWŽG‰®àå KÍÓ{ú›åæÑ©÷¨÷L…É üŒúˆy–ùÚÊÚpÖo²xžy˜ÝÄ}ÞG" },
{ L"x", L"xuan", L"…ºÐù•RÐû…•tÜŽ—]ÚÎÝæÈkÐú‹lÞï‰HËÐŸœìÓÉ{êÑ¬u²UÎh¶P¹ŽÂAÙØämìœÊž‹Ö‘¤ÕÖXòCæMÂQÏ²ÌTÌB×XÐþÏØ«tðçÐü¬IÐýÍ•‹Ÿäöè¯•Ã™e­v‘Ò†IÑ¡Ÿ@ßxÑ¢°_È¯ãùRìÅ•]Ñ¤Ñ£îçÐž¬K±†ÐfäÖ½ké¸˜CãCíÛÊRïàïX¿¿’æ›ÚK" },
{ L"x", L"xun", L"ˆ_Ñ«»çÛ÷Ÿ[„×‰_Ñ¬ñ¿„ë„ìË`Þ¹‰¶â´êÖÄ `ÌQ²†Àc o‰Ëõ¸eÑ²Ñ°Ñ®–hÛ¨Ñ¯®pÝ¡Ü÷ä±ä­á¾âþ¼r«‘–Õ—Dš½‚ÅÑ­Œ¤“MÔƒöàà‰‡xÌ¶¡ñ­R” @Ÿñ˜ßÏy÷S÷\žµ…_Ñ¶ÑµÑ¸¾Ñ±Ñ´ùªFÑ·Þ™Ž…áßÑ³ÓÓ–Óœ¿£ŠQš¦Ùã¶ñZßdôÞ¦‡eîšèR‡ " },

{ L"y", L"ya", L"¨ÚÑ¾ˆRß¹Ñ¹ÑáÑ½ŽâÑº–‘Ñ»ÑÆÑ¼èâŒSè›ÑÅ—¿øfø†åE‰ºùsçŒÑÀØóÑ¿á¬…ƒ«eçðÑÁ¸ŽˆÛªcÑÂŽÑÄâXíýÑÃQý\ñâ…|ŽÞ¯P†s†¡ðé¯{Ê‹„²ˆLÔþÒ‚ÒƒêÑÇÑÈåÂ„ ë†Üˆí¼’¥æ«Ûë‚oë²’éÓ ˆº‹IªmÂyÞëšå¶–ˆB¸Eý…öVècÜ…" },
{ L"y", L"yan", L"ÑÊâûÑÌÒó«ŠëÙÑÉÑÍ›þãÕÑËáÃäÎëç³šŸŸšPÛ³ƒBæÌvöáZéŽÑà‘Ã‹éºc‘±ÅEüiÚ¥ÑÓãÆåûÜ¾ÑÏÚçÑÔÓ…àIÑÒÑØÑ×žÏ•VªPÛïÇrŠ¶ŠÔÑÐÇ¦ÑÎŠ×ÑÖ†«¬J³xÔPéZÑÑ½žóÛ»¼†Ç‰c“C—ðÔ´NÊBÑÕÌšé…—éÜî†îº™‰ÁŽi‡À™¿ŽrŽs‰Ìû}µhûš‰ü’Z›WÑÙmÙðƒ¼…]mÙ²ÑÜØßÑÛáDÙÈÑÚÛ±ØÉÈTßVëC°“Rœ{œ‘þ—¦Ý••çüî»Ñs—ãÑÝÝÑŠÎi÷Ê‘î‡{Üy¿tüd™•…˜üf®[ùžöoýŒüküjƒ°ŒEî›ýB÷úô|ŽtŽv•óýzüsÑáŠzÓ_ ²ÑâŠ°Ñå©ŸSÑäÑéÑçÑÞêÌÒ‚©ÑèêšŸgÑæìÍÑß†ÍÑã”©ª_³Ž—âøHäÙœÄ‰†ŸÌ…’õ¦•¶øeÚÝ‹Ç÷ÐŸðØÍôeÖVø‘•à‡™àòVòYþÆFÙž‡²‹÷ w•êòzázýdú`ÚIž¥‡ÙúŽòžá€×…ÓƒðÆGá‰óFž ž·×—ØVØWž¹þŸ„‰˜ÜÜ‚" },
{ L"y", L"yao", L"çÛØ²ßºÔ¼Ñýš|µnÒªÔ@†ºÉ@—êÑüø^ø€áèÑûØ³Ò¢Œ¸ëÈ½ÄÜéÒ¦ié÷ˆž÷ÌÕ‚xçòÒ¤ï¢ˆò“e‚çÒ¥ÝUœøáæÒ£ßb†Ú‹„ªrÒ¡“uç“Á˜l•¬ïuÑþ¬ŽïŸ¸G¸H´tŽAŽCðPôíÖ|Ö{æc÷¥ï_Ìißˆî–öŽ÷]¦ŒaŒë’qèÃ–” úÆwÒ§–Ì±l·ñºÒ¨‚¶‹QáÊœÈÉ|˜eé™ò[ýoúrÅ±·ŽÒ©Ô¿Ð‰·šÈ™¹OÔoì‰ÒŸÆðÎª’ýGËaËŽ dê×Å—²‡Ò«Àfú_×Š" },
{ L"y", L"yang", L"ÑëŠš’tãóÑêÃoÑí±jÑìãZë‡÷±ø„å}ÑôêgÑïÑòþtïrì¾Ñî•Dè–ÑñšÞ„½ÑðáàÑóˆ”•[Áf«ŒìÈê–±ˆòÕ“P¤§Ÿ¬—î”®¬„•ª¯ƒÝŒÖUåø—ï^öuìRûF…nÑöÖ…óŒ÷ˆtžæ–³ÑøÑõÑ÷½DÝI˜D‚êûšçï…Î^ðBñ‘Ä”ažY°Wâóí¦ÑùÁkÔhÑú˜”˜ÓµS" },
{ L"y", L"ye", L"…½Ò®‚œÒ´Ò¬•¢šS£Ò­”IÐJÐ°Ò¯’ÀÞÞîô ”¬ˆäyæU¨ÝÒ²Ò±Ò°ˆ¸‡Sc‰­ÒµÒ¶Ò·Ò³•öÚþ’wÒ¹–¥×§‹ÑÊí“’Å–¦ìÇêÊÒºÚËÈ~Ò¸š‡˜IŸ¤ñ@‰¢­LƒpŸî•Ð•Ï°‡²w”@à’ØÌðYÖ]ŽIŽJÖ”L²|•âæEædðv”KµB {ùwèHìvóBûECˆ" },
{ L"y", L"yi", L"Ò»oñÂÒÁÒÂÒ½…À‰ÒÒÀµt›¥ßÞàcœjÒ¿â¢Í~Ò¼Ò¾ÒÎ¶Bäô·Fãž‹¡‹Â“Ì‰ßàæ­Cûp¿ˆ™}™átš­÷ð×búsüpUÒå…FÒÇÒÄÛÝŒbÚ±ƒÞ–sÒÊ›nîåÆÒË ôâùâÂ’ÒÌqêÝ[Þ–Üè®A«}ß×Ó”Ø—ÒÈ–Ø–õŽƒíôÐ‘Œh‘üÈUÉßðêÒÆ—×Í†ÙOÔrÁrÒÅ‹fÒÃïí›ÕBÛD—à•ÒÉŸÛßzƒx£¤ŽKÎ’îUîVî{ø˜õkºmáÚŒ–ÒÍ¥Ö–çF»JÓ~×‚ÒÒÒÑÒÔÞ~îÆ”ÒÓÜÓÌÎ²ÆqÞŽåô¯ÒÏá¸”ôý‘ýÞ ÒÐ‚Ã”î©ârãiøCÑv¶êì½ÛpÝ}Î•”¹‹ÚµEÏÅœî‰ÞTýtVÒÚß®Ø×ÒÕÒä°¬êdØîÒéÃE±ÆNÒàÒìæÒÙÒÖˆ`ß½„·ÒÛÆiØýÒëÂk–pÒØ–žËÒ×Ðt¶hÒèÙ«…ê…åæä›uâø@Òïá»›¶Ž•Ž–‚XÞÄÞÈÒßôà•i«péó–¤Ê³–å™ýÐšÒæÒê†j›Å›ÎÞÚã¨ˆ£ÛüˆËÒÝ„ÖÈ^š¡ñ´Òî–Ø[Ø\®ÔTÔUëcâNÁpâzÝWó`Ú˜Ôm•””§š…—©Ÿ|Í‚àvœ™Ž¯àÉÒççËƒÏÁx{²Gª~¸v¯mÒâÔ„ÒÞÒáÑ`ñk˜]ðùÄjòæÉš„ãM‹ƒ|ûkûoÒãï×¯Ž˜¯ìÚŸÖŸéºIÕxü]Å’ D•Ëéì¯–²e·jÎœÒA¿OØæÞ²Û‹ÎŽF‰©ˆI‘«‘›Œ•ôèÒíÒÜ”¾šc•Ù J W™jÙŒØŠõlæ„Ù“ïîñ¯Ë‡Ë„À[ÀXØsìJöGù€ùð†á{áy×g×hÌ[ž‹‡ÒèOúgú^Ü²Ò~ú…óAúœû@Ìˆý~×”Þv„ù„J‚‰ñ®Šù‹ùŒ" },
{ L"y", L"yin", L"‡àÒòÒõêfðÒðóSÒöä¦ˆŠÒô–ðë³ÒóêŽê›ê”ƒø¶†î÷ÑP½s¹NÜ§Öà³‹AœÞÊaÉMµš‘@¯ŠãŸì´€¾žÖNë–ñ—ë éž‡‘ž@ý]íƒÜZÒ÷ ìÛßžô”Õ›ŽÛó‡ôáþ|ÇZ«ÓÓ—ÔCÒøÒùÒú‹H•Ÿâwý‡œô´HÛ´Ê_â¹ãyö¸Õz­Kš’‡w‡¨Ïr™ƒö¯ýlúÛÈÒýÒüÒûßÅò¾ÒþÚ_âiï‹œ^ëLï‡ì‚Ýl–@Úyñ«™aë[Ž\þÏP™’Ìa™Ó°a×Ó¡ÜáÒñ›Ø·ˆ¤ˆøœšªZJþ“ñ¿áS°E‘\‘€‘õg‘¶Œè»ƒ" },
{ L"y", L"ying", L"Ó¦êÓ¢Ýº«›‚Ÿœ€À†Ó¤‹kçøŸ––PéA´Q‹”àÓÓ§Þü®O¾xÎsó¿ÙaÓ£è¬ðÐ‡|ë›À”ÑšøŠíŒ‹ëâß‘ªÓ¥®ZùúDÀ›×G‹ý‡Â”tÌcŒ[ž‰™Ñ­‹µ_×súLè]úˆÐNÀtú—ûKûWÓ­°ŸÜãÜþÓ«Ó¯Ó¨Ó©ÓªÝÓÍw†ÓÈtœ»œÁäÞÝö‰LéºƒOÓ±ŸÉÓ¬äëÎ„¶H¬“Îž IÙø¿MÓLÖhÓ®õöžLËpž]Ï‰ævŽc”lå­ž„žuÚA™Õž¡»Yž­»kÛ«³A›Æ—wò£ïI“²Ó°}·fñ¨îeç_Žg°`Ó³•£Ó²ëôÄ{÷j–Ó—@áêC" },
{ L"y", L"yo", L"ÓýÓ´à¡†ÑÀ’" },
{ L"y", L"yong", L"Ó¶ÓµçßÓ¸Ó¹‚ò†Þà{Óº‹£KÜ­ã¼ œÛÕÑ“í‡‡ïÞàaÓ·°Mët÷«çOžœb÷Óúx÷I°bà¯ïJî„öÓÀð®Ó½Ó¾ÓÂ„ÊÙ¸–Ô–º~Ó¿ˆ¬ÓÁ¾Óœ¥Ô³‹Ó¼‰MÓ­òúÓ»÷‘Ûxõ—ÓÃÆoÉKák[³l" },
{ L"y", L"you", L"ÓÅÓÇØüQßÏ›|ÓÄr›ÁÞœÓÆû~ÁyH‘nà›ƒžžX‡¦‘É™¢ÂiÀlÞÌÓÈÓÉ®h›YÓÊÓÌÓÍJÃUMðàèÖŽîà]Ý¯Ýµ¶xÓËòÄÔI‚ºßKß[ªqÓÎöÏ÷†â™˜AéàÝjñfôœòøòöÊ~õOÝ’ôíþQÓÑÓÐÓÏJØÕÆhÁhÝ¬–ë—XîðÂuœ±Íœµ™äB˜©ë» ¨÷îÓÖÓÒÓ×ÓÓÙ§ ûfàó ¶µvÞ”†Nå¶ŠµÓÕ†eòÊŒÓÔØzáRÕTÑ„÷ø™ÔŒM" },
{ L"y", L"yue", L"Ô»•õÔ¼¼s¹–³EßÜ‡‚ÔÂÀÖ‘àë¾ŠxŒé’`µj«h›‡ÔÀËµxèÝÔ¿îáÍRÍQÔÄÜ‹ÔÃ‚’ÕÔ¾Ú”â_Ô½ÔÁ»›ãXé‡é†ºMéÐ‹íŽ[Ùß»CÌgå®ügÜS ~¶^»aè€ûN»lûV" },
{ L"y", L"yuan", L"‡äÃOð°„uÔ©Ô§íóŒw›ðÔ¨œaœeœmœYÉA­Éd—¥ûgÑrÍ›óîøSñrÎQøxùt‹õž”üŒüÔªƒÒß–ÚOãäÔ°Ü¾Ô±ÆŠ–zÔ«ë¼Ø’¸ÍWÔ¬Ô²Ô­†T…ŒæÂªjÔ®‡ûœ®ö½ÔµâƒÔ´œÆˆ@ˆAÜ«Ô³‹‹…ÉVÔ¯˜g˜r¾‰ô’¿FÑ“ÎzÎmó¢üxÁ~ËQéÚà÷Þ@Öwæ…™´ß‡ò{ù úM…™Ô¶±\ßRßhä‘‰íÔ·Š†ÔºÔ¹ÐcÛù‚ÓÞòµžè¥Ô¸ÑjÑ†‡…îŠ" },
{ L"y", L"yu", L"ÞzÓØÞ}Óõ’H’Gæúì¶·‹ê|¼u±EÝÎÓÙ†‰ðö¹zÓëÓÚ€ÓèßŽ­Óàæ¥’T–fì£«_«]ÓÛÐsô§Óãô¨óÄÍGØ®ÆœÓáƒÊÚÄÓéŠÊŠØâÅáü–üáCö§ô~ÓæÝÇÓçêœÈhÓåœŸÞíˆèˆï·áÎ£Óâà¯˜KÓäëé®Œó^ÓÝÅ„êìÓÞè¤šQÓÜ˜@ ¢Óßñ¾²IÑˆOÊvòõšuëkðNÕ˜Á|ÛuÓD‹äÄ­mšeÏLÝ›å“Ö~ókõ‚òe»B”ùÞXÌ]öiþeú}ûCý{ÓìÓîØñÓðåýÓêÙ¶‚RÓï’§Óíàôµ€àö” …Pàh‚¦â×Èg”Ñèžðõ—åÅc¬r‚øŒ†ÕZñÁîYö¹Ø…‘µ‡‰ŽZ”Ë·{û‡ýrí±Ô¦Óñí²ÓóÆRˆSâÀãéó¹È™öÓýÓôÆ‘Óü¶rêÅÔ¡Óøª‚qÔ¤îÚ³_»ŠÑ@ÚÍßNÝÒÎ¾ãÐœUœM±ƒÓûÓòˆÖ—§—™—š¬ZŸ~Ô¢‹VÓ÷†³†ÉŽ÷ÓùÓöñSï„ÖàðÁ³‘³†²œÔ£â•ÓþÁNîAÝ÷ÉfìÏœùÓú·C‘íÎµƒhëTîªz‹ž¾sòâÎCØ¹¯ãƒÝhÔ¥ä`ø\ßyÊ É™ìÙˆ·U‘jËìÛŸúÊšøƒøˆø…å[ÖIé“´›¶RðÖôrƒ™ùOµN°Káqºhð|™ÈÌPìM×uçŸëzå÷ò™äú–÷N»ZûO™óý›ôcôd»nžº Œþ’µHÜ†" },
{ L"y", L"yun", L"ÔÎÉCÀˆÉQŸ±ëµšèŸ¾Š[Î‚ÚSñNÙšÔÈ„òÔÆ»Ü¿Ô±Šu›Vç¡‡çêÀ¶n±d®sÔÇ›éÂmÔÅ¼‹ë…àyÉlœÝäóÞ¹oŸÂ·Ê|ä]ºJ¿a˜øÔÊêmáñ’dŠ@ÔÉÇ\éæëE†½âqñašŒ´pÙ„ìBýqýyÔÐÔËÛ©–—ã¢ÔÍài‚Öß\ã³Á‘C•žè¹ÄZÔÏÑŽìÙÔÌÊŸ¿ZádájðaíyírËœÌNí’l" },

{ L"z", L"za", L"Ž‰ÔúÔÑ›eßÆÞÙ–ýãNô˜ÅHÅNÔÓ›jÔÒíˆëjÒSës‡Í‡Ôë{Õ¦u™U" },
{ L"z", L"zan", L"ƒ³ôØ™Vºdô¢ºùaç‘ç‡ÔÛ‚Ì†¹ÞÙêÃŒv“S“Ë‡kƒ›”eÔÜƒ­”€ôõÚŽÔÝ•ºÙmÔÞöÉà™àŸžUÛŠçYÙ­è¶áA‡Ôž£×{­‘¶`Ò{×“ð•" },
{ L"z", L"zao", L"‚óÔâÔãásÛ›ÔäèÔçÔæÔé——Ôè­bËkÔåÔîÔí°oÔìßð†r—_‘VŸ¯†×ÅºrÔëÔï¸Y¸^×YÚ‹Ôê–Ò" },
{ L"z", L"zang", L"…MÔß ™ÔàÁnÙ_Ùjê°ÚEóvÚNæàñzÞÊn‰ZÔáÊiäQ²ØÄ ÅK™â" },
{ L"z", L"zai", L"ÔÖžÄçÞÔÕžüÔÔœ…œÖ²PÙ†×ÐÔ×ÔØáÌÔÙ’DÔÚ›’‚îÝdáPƒ„¿fK" },
{ L"z", L"ze", L"Ôò›gÔó›zÔðåÅÕ¦Ôñ„tàýßõ†¨ô·óÐØŸ²žœõœÚóå‡K‹¨Ž¾ÊjØÓ˜ÁštÕ‹“ñ²c°ƒºjÙ‘´ŸÒ]Ö‰Ïý`ývûBØÆŽÙšòê¾•W²à’¾¡’k³’" },
{ L"z", L"zeng", L"•ûÔø‰ˆà‹çÕÔöÔ÷™I­Q´Œ³DîÀ¿•ÖŸ×Ûï­ä{ÔùŸåêµôgÙ›‡×" },
{ L"z", L"zen", L"ÔõÚÚ×P" },
{ L"z", L"zei", L"Ôô‘åÙ\÷ŒÏŒöf÷e" },
{ L"z", L"zha", L"Ôúß¸Õ¦’s’Ÿ²é–¼ŠL¼’ßî‚¼¼™ÔüœÑÔûâªÞêé«„ž“«°•Óu˜Ï°š×A÷þýOÔþÔýÕ¢Õ¨Õ¡Ílà© £él¹†ÂdåŽ×Q…~Æz’€Õ£íÄ÷‡÷õWõ~Õ§Õ©žÁßåÕ¤×õðäŒoòÆÔp“’é¶Õ¥À¯ëámÉ" },
{ L"z", L"zhai", L"²à‰ã’ÆÕ«”ÈÕª˜zýSÕ¬ÔñµÔ™yÕ­ãSÔð²ñÕ®íÎ¼À‚ùÕ¯»yñ©" },
{ L"z", L"zhan", L"Õ¼Õ´–Õ±ì¹–îÍtÕ³ïÚjÔa¬Õ²énÚÞËUß‡~ŽEë•šØšÖÕ°ûr”ö×dðŒø@ô}ò ûD÷g×–Õ¶ïsÕµÕ¹Õ¸”Ø¬W±KÞøÕ·äã˜^ïQá\‹¶˜öÝšür×Õ½Õ»—CÕ¾ÕÀ‚·Ç•Õ¿—£‘é¾`Ýuø‘ðÌ›ÌœÒfÓOÞJ×`ò–Õº" },
{ L"z", L"zhao", L"ÔîÈŠ„ÕÐŽ‚ÕÑá“×Åßú³¯ãDü…ñq³°å™°œ ×¦ÕÒÕÓ¬ÕÙÕ×Ú¯––žÝªDˆÕÔóÉÃAèþ”íÔtÕÖÕÕÕØÃD¹|Úw•× Yõe²™˜Á^À’" },
{ L"z", L"zhang", L"ØëÕÅˆÕÂÛµƒ@ÉŸßl» æÑâ¯ÕÃÕÄ‘PÕÁ•Àè°ð\ó¯ò†û–÷J³¤ÕÇÕÆq´˜ÕÉÕÌ’EÕÊÕÈÕÍÕË›îŽ¤Ã›ÕÏ¯oá¤áÖ‰zÙ~ÕÎ¯“²d»wŽÇçb" },
{ L"z", L"zhe", L"ÕÛòØÕÚ†ø‹«ó§…zšy³K³YÍE»qÐŸˆ³ÕÜ†£éü•†•‡††´Ô€ÕÝÚØß¡ÝmÝtäOíÝÕÞÏUõ„Ö†Ö•‡¬ÞH×y×„ÕßÕàñÒô÷ÛzæNñÞÒxÕâèÏß@ÕãœJÕá˜ÎðÑÏVúp»„" },
{ L"z", L"zhei", L"Õâ" },
{ L"z", L"zhong", L"ÖÐ«›O³„dâìŠqžÆÖÒ›wÖÕÖÓ–°ÖÑÐxô±ÖÔ½Kâ{Î@ïñŽºÊWäVø‚Î ó®æRü™Û çŠ»bÖ×ÖÖÚ£†ÁŒ»ŸŽÄ[šp‰V·N¯~×õàÖÚÖÙŠt ðµrÐ{ÖØÆ Í\±Š‚£ˆú‹g¹WÐ\ÖA" },
{ L"z", L"zheng", L"¶¡ÕýÕùÍÚºÕ÷Š’Õú Ž¼lˆÁžÚÕþÕõÕøá¿ŸAÃwîÛ±kÖ¢ÂtÕöï£’ê”˜ªb“@‹oóÝÛtã`± ÑÕôåP¹~ºPöëô@°Yçdšé’cÕü’ð•“ñ“ÕÕûÖ¤Ö£þÔ^Ž­‰^ÕŠìkàþøg×C" },
{ L"z", L"zhi", L"Ö®ÊÏÖ§Ö»Ø´Ö­Ö¥›E›DÖ¨ŽÖªÖ«›‚Ö¯Ö¦èÙìóëÕÃe¶oÐ¯UëbÖ¬µ…–ñ‚u—d—ÐÅ]½¶A¶ž“wñ\Ö©˜u‘pøTø¿—ü~ÌuÖ´Ö¶Š‰Ö±Š©Öµ‚ŽÂpá™Ö°œFÛúˆÌÖ³‘çÖ² Ãµ•õÅôê­•ñcÞýž‹ÀZ‘eõÜÄˆ˜à¿{Û—Û•ÂšÏdÜÜUâºÖ¹ên„¶Ö¼ŽŽÜÆ’W›bÖ½Ö·ˆ^ˆp’nÆ‡ìí¶qdéòè×³UÐ}åëÖ¸›œœ]Æ¼ˆ¯WÔJÖºíéÝTõ¥Õ‰~áçËŒÒjÆWÖÁõô’XÊÊ¶âåÖ¾ÖËÖÊÖÎˆ€Û¤ÞŒ…„ÖÆÖÄàù’”ŽæŽèÚìÖÅ›±èÎ–»µwÖ¿èä•yšlÖÈêÞéù¼ŠÍªOÖÂÐ—¼•®‡ÖÏÖÌ¯bèœðºØ Á“ÓdÐ˜ªaÃÖÀv„Œ‚À¶ˆ—„ÖÇÖÍª‚ÐæïðëåéòÎÖÃé@ÛNÝe¹eïôŒ…“ˆDœíÖÉœþ‰yã‡ÑuÒžÕI¯€¯Fö£õÙÙ|äkŸÜ·Wëù“´“¯ŽÃ”Të\­M”òž\øvñ‹¿@ÏH‘Á™±·aƒœ„¬”`”S‘ÆÙ—ÓzòsöS™£­}ØTµYòòŽúvÜWèeØU‚f†" },
{ L"z", L"zhou", L"ÖÝÖÛÖßúÖÜÖÞ×žžëžö«‰µ÷àXÞb‹Bœ@ßúßLÅûb³BÖà†µÚQÝcã{ÝqÙkë“ù@Öa±T‡œòL×pæ¨ÖáÝSÖâ¯JÖãÈF•Ž²H¹öBæûÆþVÖä…âç§Öæþ`ƒÙ×£Öç†BÝ§¼qëÐÖåôü»‹ô¶•ƒÈ’ÔkþUþ_®Lƒuñt°™¿U‡€Öèôíô¦»Q»NóEíØñ™" },
{ L"z", L"zhua", L"×¥ÎÎ“ë™tÄºœó˜×¦" },
{ L"z", L"zhu", L"ÖìÛ¥ÙªÖïÜïä¨ÖîÖéÖêÖí¶‹îù³pÑNÖë½ZÕDÛHãéÆÎwäóÊxéÍÖTØiñ–ø–õfü}Ë žzö^™Á™½ÐEÊõÖñþqóÃ¸‰èÖÇAžÛÖòÖð·”¸˜ßIÉðñºa TÏŽõî÷E„±ŒFž¯ ‰”á™î•ôÐWè“Ø¼Ö÷„¸ŒeÖôÖùÁCê•Žªä¾ÖóŸ—ÊôÔ}ñÒîÖö G÷æÖõ‡Úúž²šÄþØù×¡ÐÆ^ÜÑÖúÀ‚ˆ|Öü×¤ÞŽèÌ’}×¢×£–ÇìÄšŸ‰ÔÇdµ‚¸m±vðæ³dÖû¼Ÿ½AÖøÊüÁqÖýÖþÙAÝOÔ]ÚŸ­ãL¹hïŒñ[óçôã˜ÖäŠñvû„ºBºZº|èT‰£" },
{ L"z", L"zhen", L"ÕêÕëÕìÖ¡ä¥ëÓÕä«‚Ø‘á˜ìõèåÕæ±wÕèŽž‚ÉáIÈœŽ¬ŒzœßZÕåäÚ‹ª€“ŽÝèÉRÕçé©˜Eµâœ¶G¬‘é»´Uš‹›óðÕé˜çØËmågÝŸæP»E÷yÕïÕí’réô•_ŠªŒÇ±pÕîî³ÐÂr½GÑ]ÝFÒ˜Ô\çÇñ}ð¡¿b¿jÞtôIümÕóÛÚÀƒ®lð²ê‡‚E’™Õñ–ÚëÞ¼…±‡êâ‰`“L½„ÙcÕgÕòÕðøcææ‚ä‹" },
{ L"z", L"zhuai", L"×§×ªÛJ" },
{ L"z", L"zhui", L"ö¿×·æí×µ×¶åFòKùx›d×¹¸ŠÜ×ºçÄ®IÄJã·®•Äi³›‰‹¾Y×¸¿PÕ…á^åY´œÙ˜èV" },
{ L"z", L"zhuang", L"×¯×±ŠyŽáÇPÇfŠÏ×®—[»’×°œ³Ñb˜¶¼PÞÊ×³‰Ñ×´ î‰ÕŸ`Ù×´±×²í°" },
{ L"z", L"zhuan", L"×¨…¡ŒŸ×©þzŒ£à‹§‰t®U­AÄx´sò§´uÖKî…Ïm÷H×ªŒN¸|ÞD´«ãçžÀßùÜžˆæÉE¬ƒÄR×¬ƒQâÍ×«×­ºeÒN¿xÙ×Nð‚»M‡Ê" },
{ L"z", L"zhun", L"ÍÍÞ„ŒdëÆñ¸×»†”ÕÐq×¼ˆÍƒýœÊ¾MÔR¶›" },
{ L"z", L"zhuo", L"×¾žã×½Ù¾×À—‡—zäÃ—¬ìÌ˜‘þ‰·qßªè@·‡° æšõˆV×ÆŠƒ×¿…¬×Â×Çí½ŸOä·ÚÂQ×ÃŠß×Ä†×Å—Á•Œ”Ù”Ú×Á¬k³˜ÁM·Ÿìú”Û“â“ð„ŸÕŽÕ}ärºW½Éáåª”Þ”½Ö‘ïí™·ùhõîÏ—ž•èCú|»SÐX»m¸B" },
{ L"z", L"zou", L"×ÞæãÚîàYÚÁÇˆ’ô—¯—°àu¾j¹tÕŒöíÛ¸üPöOò|ýwýÚ[×ß×à×á" },
{ L"z", L"zong", L"×ÚèÈ‚óW×ÛˆîÈëêÈ ªf¸¾×Ø—Þ–Q·OÙƒ¾C¾hÂC×ÙÛr¾›ŸÙÎx´†¿å†××òRÛ™òiöRôAôiö`èQ×Ü‚~ÙÌ’Ö“K“i¼Ÿt‚ôÉ~“¨¾t¿G¾‘ Q¿‚×Ý•f¯Sª`³ŸôÕ¼F¯—¿k¿vØq¼_" },
{ L"z", L"zi", L"×ÐŒI×ÎÖ¨çÞÆ†Æ×È×ËŠœ×Éêß×Ê«R–ã¼|Úaç»¶‡ ×ÍÚÑÇÈŒàt×Ìœ¹áÑ—ÂôÒê¢†êæÜŒUïÅµ›ôôõþö¤ÙYÙD¾l¾zö·âˆ·TéCÝwüˆöö÷ÚÝ–åOÖJÚƒÐæSætîoîpýUùƒõ™ö‹ÀdýbÉ›×Ó…»–jæ¢Š—Ãc¶f³IÍIñè×Ñïö…èÜëóÊâBè÷†×Ï×ÒÔ`˜h×ÖÆT×ÔÇSÆ“„‚• ¼í§íö±{×ÕÃuÃhn†ïôõ–" },
{ L"z", L"zu", L"ÜÚ×âÝÏÈ{Éa…a×ãþ„×ä†XŒœ×å—½¹ŒÛnïßæ—×è×ç×é×æ«~ •ÙÞ†€½MÔ{ì†ü“t" },
{ L"z", L"zun", L"×ðý×ñé×À–¿Ÿç÷®ú•÷VƒV‡gß¤×J’Äã†" },
{ L"z", L"zui", L"¾×…‰Ã†÷˜áÏ`Àxõþê×ì‡’­r–èƒâ½SáE•µ‘×î·B×ïÞfáU˜—×íÞ©ŽTäŽå@™d™i" },
{ L"z", L"zuan", L"×êã@„®èjõòÜgèºeÀFçÚ×ëÀjÀy»g×¬ß¬" },
{ L"z", L"zuo", L"×÷àÜ·s×òÇg¶}óÐ’Û×Á¹iâ—¶š×ó×ô´é¿–Úè×øâôŒöŒõ‚FìñëÑÐŠ×ùßò×öÈyÈzïŽ¼d…ø" }
};



int getComPingyinForStr(const wstring & inStr, wstring& outFrist_py, wstring& outFull_py)
{
	// --- Ìõ¼þ·µ»Ø
	outFrist_py.clear();
	outFull_py.clear();
	if (inStr.empty())
	{
		return -1;
	}


	// --- »ñÈ¡Ã¿¸ö×ÖµÄËùÓÐ¶ÁÒô
	size_t numOfWord = inStr.size();
	vector<vector<wstring>> fristPys;
	vector<vector<wstring>> fullPys;
	for (size_t i_word = 0; i_word < numOfWord; i_word++)
	{
		vector<wstring> fristPy;
		vector<wstring> fullPy;
		getAllPingyinForWord(inStr.substr(i_word,1), fristPy, fullPy);

		fristPys.push_back(fristPy);
		fullPys.push_back(fullPy);
	}


	// --- ¿ªÊ¼ÅÅÁÐ×éºÏ
	vector<int> nowIndexList;
	vector<int> maxIndexList;
	int sum_maxIndexList = 0;
	for (size_t i = 0; i < numOfWord; i++)
	{
		nowIndexList.push_back(0);
		maxIndexList.push_back(int(fullPys[i].size()) - 1);
		sum_maxIndexList += maxIndexList[i];
	}


	// --- µÚÒ»´Î×éºÏ£¨ËùÓÐ²ÉÓÃµÚÒ»¸ö£©
	bool mustCombination = sum_maxIndexList > 0 ? true : false;
	for (size_t i = 0; i < numOfWord; i++)
	{
		outFrist_py += fristPys[i][0];
		outFull_py += fullPys[i][0];
	}


	// --- Ñ­»·±éÀú
	while (mustCombination)
	{
		// --- ×éºÏÅÅÁÐ
		bool alreadyRunOnce = false;
		for (size_t i = 0; i < numOfWord; i++)
		{
			if (alreadyRunOnce)
			{
				break;
			}

			if (maxIndexList[i] != 0)
			{
				if (nowIndexList[i] < maxIndexList[i])
				{
					alreadyRunOnce = true;
					nowIndexList[i]++;
				}
				else if (nowIndexList[i] == maxIndexList[i])
				{
					nowIndexList[i] = 0;
				}
			}
		}

		// --- ×éºÏÊä³ö×Ö·û
		outFrist_py += L" ";
		outFull_py += L" ";
		for (size_t i = 0; i < numOfWord; i++)
		{
			outFrist_py += fristPys[i][nowIndexList[i]];
			outFull_py += fullPys[i][nowIndexList[i]];
		}

		// --- ÍË³öÌõ¼þ
		bool canOut = true;
		for (size_t i = 0; i < numOfWord; i++)
		{
			if (nowIndexList[i] != maxIndexList[i])
			{
				canOut = false;
				break;
			}
		}
		if (canOut)
		{
			break;
		}
	}


	// --- ·µ»Ø
	return 0;
}

wstring getNamePingyin(const wstring& inStr, bool isLastName)
{
	wstring outStr;

	// ----- ÐÕÊÏ
	if (isLastName)
	{
		// --- ÔÚ°Ù¼ÒÐÕÖÐ²éÕÒ
		for (size_t i = 0; i < g_length_lastNameTable; i++)
		{
			if (inStr == lastNameTable[i].hanzi)
			{
				outStr = lastNameTable[i].pinyi;
				break;
			}
		}
	}

	// --- Ö±½Óºº×Ö¿â²éÕÒ
	if (outStr.empty())
	{
		for (size_t i = 0; i < inStr.size(); i++)
		{
			outStr += getNoRepeatPingyinForWord(inStr.substr(i,1));
		}
	}

	return outStr;
}

void myNameSplit(const wstring & inFullName, wstring& outLastName, wstring& outFirstName)
{
	const int doubleLastNameLength = 90;
	static wstring doubleLastName[doubleLastNameLength] =
	{
		L"Å·Ñô" , L"Ì«Ê·" , L"¶ËÄ¾" , L"ÉÏ¹Ù" , L"Ë¾Âí" , L"¶«·½" , L"¶À¹Â" , L"ÄÏ¹¬" , L"ÍòÙ¹" , L"ÎÅÈË" ,
		L"ÏÄºî" , L"Öî¸ð" , L"Î¾³Ù" , L"¹«Ñò" , L"ºÕÁ¬" , L"å£Ì¨" , L"»Ê¸¦" , L"×ÚÕþ" , L"å§Ñô" , L"¹«Ò±" ,
		L"Ì«Êå" , L"ÉêÍÀ" , L"¹«Ëï" , L"Ä½ÈÝ" , L"ÖÙËï" , L"ÖÓÀë" , L"³¤Ëï" , L"ÓîÎÄ" , L"Ë¾Í½" , L"ÏÊÓÚ" ,
		L"Ë¾¿Õ" , L"ãÌÇð" , L"×Ó³µ" , L"ØÁ¹Ù" , L"Ë¾¿Ü" , L"Î×Âí" , L"¹«Î÷" , L"ò§Ëï" , L"ÈÀæá" , L"¹«Á¼" ,
		L"Æáµñ" , L"ÀÖÕý" , L"Ô×¸¸" , L"¹ÈÁº" , L"ÍØ°Ï" , L"¼Ð¹È" , L"ÐùÔ¯" , L"Áîºü" , L"¶Î¸É" , L"°ÙÀï" ,
		L"ºôÑÓ" , L"¶«¹ù" , L"ÄÏÃÅ" , L"ÑòÉà" , L"Î¢Éú" , L"¹«»§" , L"¹«Óñ" , L"¹«ÒÇ" , L"ÁºÇð" , L"¹«ÖÙ" ,
		L"¹«ÉÏ" , L"¹«ÃÅ" , L"¹«É½" , L"¹«¼á" , L"×óÇð" , L"¹«²®" , L"Î÷ÃÅ" , L"¹«×æ" , L"µÚÎå" , L"¹«³Ë" ,
		L"¹áÇð" , L"¹«ðª" , L"ÄÏÈÙ" , L"¶«Àï" , L"¶«¹¬" , L"ÖÙ³¤" , L"×ÓÊé" , L"×ÓÉ£" , L"¼´Ä«" , L"´ïÞÉ" ,
		L"ñÒÊ¦" , L"ÎâÃú" , L"ÄÉÀ¼" , L"¹éº£" , L"¶«»Ê" , L"ÔóÎÌ" , L"°¢Ôú" , L"ÔóÀÊ" , L"Ë÷ÀÊ" , L"µËÕæ"
	};

	// --- Èç¹ûÓÐ·Çºº×Ö×Ö·û£¬Ö±½Ó·µ»Ø
	for (size_t i = 0; i < inFullName.size(); i++)
	{
		if (!isHanziChar(inFullName[i]))
		{
			outLastName = L"";
			outFirstName = inFullName;
			return;
		}
	}


	//
	outLastName = L"";
	outFirstName = L"";

	if (inFullName.empty())
	{
	}
	else if (inFullName.size() == 1)
	{
		outFirstName = inFullName;
	}
	else if (inFullName.size() == 2)
	{
		outLastName = inFullName[0];
		outFirstName = inFullName[1];
	}
	else
	{
		wstring guessLastName = inFullName.substr(0,2);
		for (int i = 0; i < doubleLastNameLength; i++)
		{
			if (guessLastName == doubleLastName[i])
			{
				outLastName = doubleLastName[i];
				outFirstName = inFullName.substr(2);
				break;
			}
		}

		if (outLastName.empty())
		{
			if (inFullName.size() == 4)
			{
				outLastName = inFullName.substr(0,2);
				outFirstName = inFullName.substr(2);
			}
			else
			{
				outLastName = inFullName[0];
				outFirstName = inFullName.substr(1);
			}			
		}
	}

}

int getAllPingyinForWord(const wstring& inWord, vector<wstring>& outFrist_py, vector<wstring>& outFull_py)
{
	// Ö»ÄÜÊäÈëÒ»¸ö×Ö·û
	if (inWord.size() > 1)
	{
		return -1;
	}

	//
	outFrist_py.clear();
	outFull_py.clear();

	wchar_t wch = inWord[0];
	if (isHanziChar(wch))
	{
		for (int index_table = 0; index_table < g_length_hanziTables; index_table++)
		{
			if (hanziTables[index_table].hanzis.find(wch) != -1)
			{
				outFrist_py.push_back(hanziTables[index_table].first_py);
				outFull_py.push_back(hanziTables[index_table].full_py);
			}
		}
	}

	if (outFrist_py.empty())
	{
		outFrist_py.push_back(inWord);
	}
	if (outFull_py.empty())
	{
		outFull_py.push_back(inWord);
	}

	return 0;
}

wstring getNoRepeatPingyinForWord(const wstring& inWord)
{
	wstring outPingyin;

	// Ö»ÄÜÊäÈëÒ»¸ö×Ö·û
	if (inWord.size() > 1)
	{
		return inWord;
	}

	// ----- ÏÈÔÚ¶àÒô×ÖÀïÃæ²éÑ¯
	for (int i = 0; i < g_length_multiToneWordTable; i++)
	{
		if (inWord == multiToneWordTable[i].hanzi)
		{
			outPingyin = multiToneWordTable[i].pinyi;
			break;
		}
	}

	// ----- ¼ÌÐø²éÑ¯
	if (!outPingyin.empty())
	{
		return outPingyin;
	}

	// ----- ÔÚÈ«×Ö¿â²éÕÒ
	wchar_t wch = inWord[0];
	if (isHanziChar(wch))
	{
		for (int index_table = 0; index_table < g_length_hanziTables; index_table++)
		{
			if (hanziTables[index_table].hanzis.find(wch) != -1)
			{
				outPingyin = hanziTables[index_table].full_py;
				break;
			}
		}
	}

	//
	if (outPingyin.empty())
	{
		outPingyin = inWord;
	}

	// ----- ·µ»Ø½á¹û
	return outPingyin;
}

bool isHanziChar(wchar_t wch) {
	// ÔÚvs2019 ÉÏÊ¹ÓÃ qstring Ê±
	// return (wch >= 0x4E00 && wch <= 0x9FA5) ? true : false; 
	
	// ÔÚvs2019 ÉÏÊ¹ÓÃ wstring Ê±
	//return (wch >= 12570 && wch <= 64041) ? true : false;

	// ÕâÊÇÒ»ÖÖÕÛÖÐ·½°¸ => ºº×Ö²»»áÓÐÈÎºÎÒÅÂ©£¬ÄÜÊÊÓ¦´ó¶àÊý±àÂë·½Ê½£¨¿É¹ýÂËµô¾ø´ó¶àÊý³£ÓÃ·Çºº×Ö×Ö·û£©
	// Èç¹ûÏë»ñÈ¡×¼È·µÄÇø¼ä£¬Ê¹ÓÃtestHanziRang()·½·¨£»
	return wch > 127 ? true : false;
}

void testHanziRang() {
	wstring str;
	for (size_t i = 0; i < g_length_hanziTables; i++)
	{
		str += hanziTables[i].hanzis;
	}

	int maxVal = 0;
	int minVal = 1000000000;
	wchar_t maxStr = L' ';
	wchar_t minStr = L' ';
	for (size_t i = 0; i < str.size(); i++)
	{
		int uncd = str[i];
		if (uncd > maxVal)
		{
			maxVal = uncd;
			maxStr = str[i];
		}
		if (uncd < minVal)
		{
			minVal = uncd;
			minStr = str[i];
		}
	}

	printf("\nºº×Ö±àÂë²âÊÔ£º\n");
	printf("×îÐ¡±àÂëÖµ£º%d , ×î´ó±àÂëÖµ:%d , ×Üºº×ÖÊýÁ¿(Î´È¥ÖØ)£º%zd \n", minVal, maxVal,str.size());
	
	printf("×îÐ¡±àÂëÖµµÄºº×Ö£º%wc , ×î´ó±àÂëÖµµÄºº×Ö: %wc \n", minStr, maxStr);
	
	// ¡¾×¢Òâ¡¿
	// Èç¹ûÏëÊ¹printf¿ÉÒÔ´òÓ¡wchar_t  
	// setlocale(LC_ALL, "");  // ÔÚ³õÊ¼»¯Ê±µ÷ÓÃÕâ¸ö
	// #include <iostream>     // ¶ÔÓ¦µÄÍ·ÎÄ¼þ
}

