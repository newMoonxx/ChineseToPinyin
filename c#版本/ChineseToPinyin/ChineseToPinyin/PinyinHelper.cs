using System;
using System.Collections.Generic;

namespace ChineseToPinyin
{
    public class PinyinHelper
    {
        private const int g_length_lastNameTable = 554;
        private const int g_length_multiToneWordTable = 708;
        private const int g_length_hanziTables = 411;
        private const int doubleLastNameLength = 90;

        /* 
		0. 姓氏特殊读音(包括：特殊、非特殊、复姓读音)
		1. 可以自己添加
		3. 来源于各种网络数据的整合
		*/
        private static string[,] lastNameTable = new string[g_length_lastNameTable, 2]
        {
            { "赵" , "zhao" },
            { "钱" , "qian" },
            { "孙" , "sun" },
            { "李" , "li" },
            { "周" , "zhou" },
            { "吴" , "wu" },
            { "郑" , "zheng" },
            { "王" , "wang" },
            { "冯" , "feng" },
            { "陈" , "chen" },
            { "褚" , "chu" },
            { "卫" , "wei" },
            { "蒋" , "jiang" },
            { "沈" , "shen" },
            { "韩" , "han" },
            { "杨" , "yang" },
            { "朱" , "zhu" },
            { "秦" , "qin" },
            { "尤" , "you" },
            { "许" , "xu" },
            { "何" , "he" },
            { "吕" , "lv" },
            { "施" , "shi" },
            { "张" , "zhang" },
            { "孔" , "kong" },
            { "曹" , "cao" },
            { "严" , "yan" },
            { "华" , "hua" },
            { "金" , "jin" },
            { "魏" , "wei" },
            { "陶" , "tao" },
            { "姜" , "jiang" },
            { "戚" , "qi" },
            { "谢" , "xie" },
            { "邹" , "zou" },
            { "喻" , "yu" },
            { "柏" , "bai" },
            { "水" , "shui" },
            { "窦" , "dou" },
            { "章" , "zhang" },
            { "云" , "yun" },
            { "苏" , "su" },
            { "潘" , "pan" },
            { "葛" , "ge" },
            { "奚" , "xi" },
            { "范" , "fan" },
            { "彭" , "peng" },
            { "郎" , "lang" },
            { "鲁" , "lu" },
            { "韦" , "wei" },
            { "昌" , "chang" },
            { "马" , "ma" },
            { "苗" , "miao" },
            { "凤" , "feng" },
            { "花" , "hua" },
            { "方" , "fang" },
            { "俞" , "yu" },
            { "任" , "ren" },
            { "袁" , "yuan" },
            { "柳" , "liu" },
            { "酆" , "feng" },
            { "鲍" , "bao" },
            { "史" , "shi" },
            { "唐" , "tang" },
            { "费" , "fei" },
            { "廉" , "lian" },
            { "岑" , "cen" },
            { "薛" , "xue" },
            { "雷" , "lei" },
            { "贺" , "he" },
            { "倪" , "ni" },
            { "汤" , "tang" },
            { "滕" , "teng" },
            { "殷" , "yin" },
            { "罗" , "luo" },
            { "毕" , "bi" },
            { "郝" , "hao" },
            { "邬" , "wu" },
            { "安" , "an" },
            { "常" , "chang" },
            { "乐" , "yue" },
            { "于" , "yu" },
            { "时" , "shi" },
            { "傅" , "fu" },
            { "皮" , "pi" },
            { "卞" , "bian" },
            { "齐" , "qi" },
            { "康" , "kang" },
            { "伍" , "wu" },
            { "余" , "yu" },
            { "元" , "yuan" },
            { "卜" , "bu" },
            { "顾" , "gu" },
            { "孟" , "meng" },
            { "平" , "ping" },
            { "黄" , "huang" },
            { "和" , "he" },
            { "穆" , "mu" },
            { "萧" , "xiao" },
            { "尹" , "yin" },
            { "姚" , "yao" },
            { "邵" , "shao" },
            { "湛" , "zhan" },
            { "汪" , "wang" },
            { "祁" , "qi" },
            { "毛" , "mao" },
            { "禹" , "yu" },
            { "狄" , "di" },
            { "米" , "mi" },
            { "贝" , "bei" },
            { "明" , "ming" },
            { "臧" , "zang" },
            { "计" , "ji" },
            { "伏" , "fu" },
            { "成" , "cheng" },
            { "戴" , "dai" },
            { "谈" , "tan" },
            { "宋" , "song" },
            { "茅" , "mao" },
            { "庞" , "pang" },
            { "熊" , "xiong" },
            { "纪" , "ji" },
            { "舒" , "shu" },
            { "屈" , "qu" },
            { "项" , "xiang" },
            { "祝" , "zhu" },
            { "董" , "dong" },
            { "梁" , "liang" },
            { "杜" , "du" },
            { "阮" , "ruan" },
            { "蓝" , "lan" },
            { "闵" , "min" },
            { "席" , "xi" },
            { "季" , "ji" },
            { "麻" , "ma" },
            { "强" , "qiang" },
            { "贾" , "jia" },
            { "路" , "lu" },
            { "娄" , "lou" },
            { "危" , "wei" },
            { "江" , "jiang" },
            { "童" , "tong" },
            { "颜" , "yan" },
            { "郭" , "guo" },
            { "梅" , "mei" },
            { "盛" , "sheng" },
            { "林" , "lin" },
            { "刁" , "diao" },
            { "钟" , "zhong" },
            { "徐" , "xu" },
            { "邱" , "qiu" },
            { "骆" , "luo" },
            { "高" , "gao" },
            { "夏" , "xia" },
            { "蔡" , "cai" },
            { "田" , "tian" },
            { "樊" , "fan" },
            { "胡" , "hu" },
            { "凌" , "ling" },
            { "霍" , "huo" },
            { "虞" , "yu" },
            { "万" , "wan" },
            { "支" , "zhi" },
            { "柯" , "ke" },
            { "昝" , "zan" },
            { "管" , "guan" },
            { "卢" , "lu" },
            { "莫" , "mo" },
            { "经" , "jing" },
            { "房" , "fang" },
            { "裘" , "qiu" },
            { "缪" , "miao" },
            { "干" , "gan" },
            { "解" , "xie" },
            { "应" , "ying" },
            { "宗" , "zong" },
            { "丁" , "ding" },
            { "宣" , "xuan" },
            { "贲" , "ben" },
            { "邓" , "deng" },
            { "郁" , "yu" },
            { "单" , "shan" },
            { "杭" , "hang" },
            { "洪" , "hong" },
            { "包" , "bao" },
            { "诸" , "zhu" },
            { "左" , "zuo" },
            { "石" , "shi" },
            { "崔" , "cui" },
            { "吉" , "ji" },
            { "钮" , "niu" },
            { "龚" , "gong" },
            { "程" , "cheng" },
            { "嵇" , "ji" },
            { "邢" , "xing" },
            { "滑" , "hua" },
            { "裴" , "pei" },
            { "陆" , "lu" },
            { "荣" , "rong" },
            { "翁" , "weng" },
            { "荀" , "xun" },
            { "羊" , "yang" },
            { "於" , "yu" },
            { "惠" , "hui" },
            { "甄" , "zhen" },
            { "曲" , "qu" },
            { "家" , "jia" },
            { "封" , "feng" },
            { "芮" , "rui" },
            { "羿" , "yi" },
            { "储" , "chu" },
            { "靳" , "jin" },
            { "汲" , "ji" },
            { "邴" , "bing" },
            { "糜" , "mi" },
            { "松" , "song" },
            { "井" , "jing" },
            { "段" , "duan" },
            { "富" , "fu" },
            { "巫" , "wu" },
            { "乌" , "wu" },
            { "焦" , "jiao" },
            { "巴" , "ba" },
            { "弓" , "gong" },
            { "牧" , "mu" },
            { "隗" , "kui" },
            { "山" , "shan" },
            { "谷" , "gu" },
            { "车" , "che" },
            { "侯" , "hou" },
            { "宓" , "mi" },
            { "蓬" , "peng" },
            { "全" , "quan" },
            { "郗" , "xi" },
            { "班" , "ban" },
            { "仰" , "yang" },
            { "秋" , "qiu" },
            { "仲" , "zhong" },
            { "伊" , "yi" },
            { "宫" , "gong" },
            { "宁" , "ning" },
            { "仇" , "qiu" },
            { "栾" , "luan" },
            { "暴" , "bao" },
            { "甘" , "gan" },
            { "钭" , "tou" },
            { "厉" , "li" },
            { "戎" , "rong" },
            { "祖" , "zu" },
            { "武" , "wu" },
            { "符" , "fu" },
            { "刘" , "liu" },
            { "景" , "jing" },
            { "詹" , "zhan" },
            { "束" , "shu" },
            { "龙" , "long" },
            { "叶" , "ye" },
            { "幸" , "xing" },
            { "司" , "si" },
            { "韶" , "shao" },
            { "郜" , "gao" },
            { "黎" , "li" },
            { "蓟" , "ji" },
            { "薄" , "bo" },
            { "印" , "yin" },
            { "宿" , "su" },
            { "白" , "bai" },
            { "怀" , "huai" },
            { "蒲" , "pu" },
            { "邰" , "tai" },
            { "从" , "cong" },
            { "鄂" , "e" },
            { "索" , "suo" },
            { "咸" , "xian" },
            { "籍" , "ji" },
            { "赖" , "lai" },
            { "卓" , "zhuo" },
            { "蔺" , "lin" },
            { "屠" , "tu" },
            { "蒙" , "meng" },
            { "池" , "chi" },
            { "乔" , "qiao" },
            { "阴" , "yin" },
            { "郁" , "yu" },
            { "胥" , "xu" },
            { "能" , "nai" },
            { "苍" , "cang" },
            { "双" , "shuang" },
            { "闻" , "wen" },
            { "莘" , "shen" },
            { "党" , "dang" },
            { "翟" , "zhai" },
            { "谭" , "tan" },
            { "贡" , "gong" },
            { "劳" , "lao" },
            { "逄" , "pang" },
            { "姬" , "ji" },
            { "申" , "shen" },
            { "扶" , "fu" },
            { "堵" , "du" },
            { "冉" , "ran" },
            { "宰" , "zai" },
            { "郦" , "li" },
            { "雍" , "yong" },
            { "郤" , "xi" },
            { "璩" , "qu" },
            { "桑" , "sang" },
            { "桂" , "gui" },
            { "濮" , "pu" },
            { "牛" , "niu" },
            { "寿" , "shou" },
            { "通" , "tong" },
            { "边" , "bian" },
            { "扈" , "hu" },
            { "燕" , "yan" },
            { "冀" , "ji" },
            { "郏" , "jia" },
            { "浦" , "pu" },
            { "尚" , "shang" },
            { "农" , "nong" },
            { "温" , "wen" },
            { "别" , "bie" },
            { "庄" , "zhuang" },
            { "晏" , "yan" },
            { "柴" , "chai" },
            { "瞿" , "qu" },
            { "阎" , "yan" },
            { "充" , "chong" },
            { "慕" , "mu" },
            { "连" , "lian" },
            { "茹" , "ru" },
            { "习" , "xi" },
            { "宦" , "huan" },
            { "艾" , "ai" },
            { "鱼" , "yu" },
            { "容" , "rong" },
            { "向" , "xiang" },
            { "古" , "gu" },
            { "易" , "yi" },
            { "慎" , "shen" },
            { "戈" , "ge" },
            { "廖" , "liao" },
            { "庾" , "yu" },
            { "终" , "zhong" },
            { "暨" , "ji" },
            { "居" , "ju" },
            { "衡" , "heng" },
            { "步" , "bu" },
            { "都" , "du" },
            { "耿" , "geng" },
            { "满" , "man" },
            { "弘" , "hong" },
            { "匡" , "kuang" },
            { "国" , "guo" },
            { "文" , "wen" },
            { "寇" , "kou" },
            { "广" , "guang" },
            { "禄" , "lu" },
            { "阙" , "que" },
            { "东" , "dong" },
            { "欧" , "ou" },
            { "殳" , "shu" },
            { "沃" , "wo" },
            { "利" , "li" },
            { "蔚" , "wei" },
            { "越" , "yue" },
            { "夔" , "kui" },
            { "隆" , "long" },
            { "师" , "shi" },
            { "巩" , "gong" },
            { "厍" , "she" },
            { "聂" , "nie" },
            { "晁" , "chao" },
            { "勾" , "gou" },
            { "句" , "gou" },
            { "敖" , "ao" },
            { "融" , "rong" },
            { "冷" , "leng" },
            { "訾" , "zi" },
            { "辛" , "xin" },
            { "阚" , "kan" },
            { "那" , "na" },
            { "简" , "jian" },
            { "饶" , "rao" },
            { "空" , "kong" },
            { "曾" , "zeng" },
            { "母" , "mu" },
            { "沙" , "sha" },
            { "乜" , "nie" },
            { "养" , "yang" },
            { "鞠" , "ju" },
            { "须" , "xu" },
            { "丰" , "feng" },
            { "巢" , "chao" },
            { "关" , "guan" },
            { "蒯" , "kuai" },
            { "相" , "xiang" },
            { "查" , "zha" },
            { "后" , "hou" },
            { "荆" , "jing" },
            { "红" , "hong" },
            { "游" , "you" },
            { "竺" , "zhu" },
            { "权" , "quan" },
            { "逯" , "lu" },
            { "盖" , "gai" },
            { "益" , "yi" },
            { "桓" , "huan" },
            { "公" , "gong" },
            { "万俟" , "moqi" },
            { "司马" , "sima" },
            { "上官" , "shangguan" },
            { "欧阳" , "ouyang" },
            { "夏侯" , "xiahou" },
            { "诸葛" , "zhuge" },
            { "闻人" , "wenren" },
            { "东方" , "dongfang" },
            { "赫连" , "helian" },
            { "皇甫" , "huangpu" },
            { "尉迟" , "yuchi" },
            { "公羊" , "gongyang" },
            { "澹台" , "tantai" },
            { "公冶" , "gongye" },
            { "宗政" , "zongzheng" },
            { "濮阳" , "puyang" },
            { "淳于" , "chunyu" },
            { "单于" , "chanyu" },
            { "太叔" , "taishu" },
            { "申屠" , "shentu" },
            { "公孙" , "gongsun" },
            { "仲孙" , "zhongsun" },
            { "轩辕" , "xuanyuan" },
            { "令狐" , "linghu" },
            { "钟离" , "zhongli" },
            { "宇文" , "yuwen" },
            { "长孙" , "zhangsun" },
            { "慕容" , "murong" },
            { "鲜于" , "xianyu" },
            { "闾丘" , "luqiu" },
            { "司徒" , "situ" },
            { "司空" , "sikong" },
            { "亓官" , "qiguan" },
            { "司寇" , "sikou" },
            { "仉督" , "zhangdu" },
            { "子车" , "ziju" },
            { "颛孙" , "zhuansun" },
            { "端木" , "duanmu" },
            { "巫马" , "wuma" },
            { "公西" , "gongxi" },
            { "漆雕" , "qidiao" },
            { "乐正" , "yuezheng" },
            { "壤驷" , "rangsi" },
            { "公良" , "gongliang" },
            { "拓跋" , "tuoba" },
            { "夹谷" , "jiagu" },
            { "宰父" , "zaifu" },
            { "榖梁" , "guliang" },
            { "晋" , "jin" },
            { "楚" , "chu" },
            { "闫" , "yan" },
            { "法" , "fa" },
            { "汝" , "ru" },
            { "鄢" , "yan" },
            { "涂" , "tu" },
            { "钦" , "qin" },
            { "段干" , "duangan" },
            { "百里" , "baili" },
            { "东郭" , "dongguo" },
            { "南门" , "nanmen" },
            { "呼延" , "huyan" },
            { "归" , "gui" },
            { "海" , "hai" },
            { "羊舌" , "yangshe" },
            { "微" , "wei" },
            { "生" , "sheng" },
            { "岳" , "yue" },
            { "帅" , "shuai" },
            { "缑" , "gou" },
            { "亢" , "kang" },
            { "况" , "kuang" },
            { "后" , "hou" },
            { "有" , "you" },
            { "琴" , "qin" },
            { "梁丘" , "liangqiu" },
            { "左丘" , "zuoqiu" },
            { "东门" , "dongmen" },
            { "西门" , "ximen" },
            { "商" , "shang" },
            { "牟" , "mou" },
            { "佘" , "she" },
            { "佴" , "nai" },
            { "伯" , "bo" },
            { "赏" , "shang" },
            { "南宫" , "nangong" },
            { "墨" , "mo" },
            { "哈" , "ha" },
            { "谯" , "qiao" },
            { "笪" , "da" },
            { "年" , "nian" },
            { "爱" , "ai" },
            { "阳" , "yang" },
            { "佟" , "tong" },
            { "第五" , "diwu" },
            { "言" , "yan" },
            { "福" , "fu" },
            { "黑" , "he" },
            { "区" , "ou" },
            { "朴" , "piao" },
            { "繁" , "po" },
            { "员" , "yun" },
            { "蕃" , "pi" },
            { "种" , "chong" },
            { "秘" , "bi" },
            { "谌" , "chen" },
            { "啜" , "chuai" },
            { "邸" , "di" },
            { "苻" , "fu" },
            { "甫" , "fu" },
            { "杲" , "gao" },
            { "艮" , "gen" },
            { "冠" , "guan" },
            { "妫" , "gui" },
            { "过" , "guo" },
            { "晟" , "cheng" },
            { "隽" , "juan" },
            { "逢" , "pang" },
            { "邳" , "pi" },
            { "莆" , "pu" },
            { "溥" , "pu" },
            { "亓" , "qi" },
            { "少" , "shao" },
            { "召" , "shao" },
            { "折" , "she" },
            { "彤" , "tong" },
            { "庹" , "tuo" },
            { "宛" , "wan" },
            { "尉" , "wei" },
            { "冼" , "xian" },
            { "洗" , "xian" },
            { "郇" , "xun" },
            { "幺" , "yao" },
            { "郧" , "yun" },
            { "恽" , "yun" },
            { "郓" , "yun" },
            { "羊角" , "yangjue" },
            { "妘" , "yun" },
            { "祭" , "zhai" },
            { "砦" , "zhai" },
            { "占" , "zhan" },
            { "仉" , "zhang" },
            { "中行" , "zhonghang" },
            { "禚" , "zhuo" },
            { "迮" , "ze" },
            { "覃" , "qin" },
        };

        private static string[] doubleLastName = new string[doubleLastNameLength]
        {
            "欧阳" , "太史" , "端木" , "上官" , "司马" , "东方" , "独孤" , "南宫" , "万俟" , "闻人" ,
            "夏侯" , "诸葛" , "尉迟" , "公羊" , "赫连" , "澹台" , "皇甫" , "宗政" , "濮阳" , "公冶" ,
            "太叔" , "申屠" , "公孙" , "慕容" , "仲孙" , "钟离" , "长孙" , "宇文" , "司徒" , "鲜于" ,
            "司空" , "闾丘" , "子车" , "亓官" , "司寇" , "巫马" , "公西" , "颛孙" , "壤驷" , "公良" ,
            "漆雕" , "乐正" , "宰父" , "谷梁" , "拓跋" , "夹谷" , "轩辕" , "令狐" , "段干" , "百里" ,
            "呼延" , "东郭" , "南门" , "羊舌" , "微生" , "公户" , "公玉" , "公仪" , "梁丘" , "公仲" ,
            "公上" , "公门" , "公山" , "公坚" , "左丘" , "公伯" , "西门" , "公祖" , "第五" , "公乘" ,
            "贯丘" , "公皙" , "南荣" , "东里" , "东宫" , "仲长" , "子书" , "子桑" , "即墨" , "达奚" ,
            "褚师" , "吴铭" , "纳兰" , "归海" , "东皇" , "泽翁" , "阿扎" , "泽朗" , "索朗" , "邓真"
        };

        /*
		0. 多音字表 
		1. 后面的注释表示的是：这个字剩余的其他读音 （日、韩分别表示汉字是日语或韩语）
		2. 来源于 hanziTables[]，（遍历的所有，没有遗漏）
		3. 多音字选中读音规则：
		   a. 选择常用读音 ：
				{ "红" , "hong" },      // gong  
				{ "薄" , "bo" },        // bao
				{ "拆" , "chai" },      // ca
		   b. 选择根据拼音可以猜出汉字的读音。这种字大家知道是多音字，如果我输出'ju'你基本可以猜到汉字'句'，但是我输出'gou'你还能猜到汉字是'句'就...
				{ "句" , "ju" },        // gou
				{ "旁" , "pang" },      // bang
				{ "给" , "gei" },       // ji
				{ "艾" , "ai" },        // yi
				{ "大" , "da" },        // dai
				{ "炮" , "pao" },       // bao
		   c. 选中非姓氏读音
				{ "仇" , "chou" },      // qiu ，仇：作姓氏时读qiú
				{ "解" , "jie" },       // xie ，解：作姓氏时读xiè
				{ "曾" , "ceng" },      // zeng，曾：作姓氏时读zēng
		   d. 选中姓名中比较可能出现的字,下面的例子可能恰好符合其他的规则，但是在我手动筛选多音字时确实考虑到这方面的情况，因为有些多音字的其中一些读音代表的意义明显不可能被当名字来使用，因为筛选时没记录，下面的例子可能不贴切
				{ "盛" , "sheng" },     // cheng ， 茂盛（maoSheng），盛饭(chengFan)
				{ "石" , "shi" },       // dan    ， 潘石屹
				{ "矜" , "jin" },       // qin guan
				{ "强" , "qiang" },     // jiang , 坚强（qiang），倔强（jiang）
		   e. 需要上下文联系的，这种字没法了，只能查表，这里的输出原则遵循（abcd）
				{ "屏" , "ping" },      // bing ， 屏幕、屏弃
				{ "卜" , "bu" },        // bo ，   占卜、萝卜
		*/
        private static string[,] multiToneWordTable = new string[g_length_multiToneWordTable, 2]
        {
            { "厑" , "e" },         // si a
            { "吖" , "ya" },        // a
            { "阿" , "a" },         // e
            { "呵" , "he" },        // ha ke a
            { "腌" , "yan" },       // a
            { "嗄" , "sha" },       // a
            { "閊" , "ci" },        // ka lu ai
            { "魞" , "li" },        // ai
            { "鱛" , "ai" },        // suo 
            { "娭" , "xi" },        // ai
            { "佁" , "yi" },        // ai
            { "欸" , "ei" },        // ai
            { "艾" , "ai" },        // yi 
            { "嗌" , "yi" },        // ai
            { "噫" , "yi" },        // ai
            { "餲" , "ai" },        // he 
            { "厂" , "chang" },     // an
            { "广" , "guang" },     // an
            { "晻" , "yan" },       // an
            { "犴" , "han" },       // an
            { "胺" , "an" },        // e 
            { "肮" , "ang" },       // hang 
            { "卬" , "yang" },      // ang
            { "仰" , "yang" },      // ang
            { "凹" , "ao" },        // wa 
            { "嚣" , "xiao" },      // ao
            { "夭" , "ao" },        // yao 
            { "拗" , "ao" },        // niu 
            { "鎺" , "ha" },        // ba
            { "鯐" , "li" },        // si xi ba
            { "叭" , "ba" },        // pa 
            { "鎺" , "ba" },        // pa
            { "伯" , "bo" },        // bai  ba
            { "杷" , "pa" },        // ba
            { "叭" , "ba" },        // pa
            { "耙" , "pa" },        // ba
            { "瓸" , "bai" },       // wa 
            { "兡" , "bai" },       // ke 
            { "陌" , "mo" },        // bai
            { "柏" , "bai" },       // bo 
            { "伴" , "ban" },       // pan 
            { "拌" , "ban" },       // pan 
            { "坢" , "pan" },       // ban
            { "柈" , "pan" },       // ban
            { "膀" , "bang" },      // pang 
            { "旁" , "pang" },      // bang
            { "蚌" , "bang" },      // beng 
            { "棓" , "bang" },      // bei 
            { "搒" , "bang" },      // peng 
            { "磅" , "bang" },      // pang 
            { "炮" , "pao" },       // bao
            { "枹" , "bao" },       // fu 
            { "薄" , "bo" },        // bao
            { "堡" , "bao" },       // bu pu 
            { "刨" , "pao" },       // bao
            { "袌" , "pao" },       // bao
            { "暴" , "bao" },       // pu 
            { "瀑" , "pu" },        // bao
            { "曝" , "bao" },       // pu 
            { "陂" , "bei" },       // pi po 
            { "椑" , "bei" },       // pi 
            { "孛" , "bei" },       // bo 
            { "被" , "bei" },       // pi 
            { "贲" , "ben" },       // bi 
            { "夯" , "hang" },      // ben
            { "萙" , "ta" },        // ku lai bi
            { "蛯" , "bi" },        // e 
            { "鎞" , "bi" },        // pi 
            { "吡" , "pi" },        // bi
            { "箄" , "pai" },       // bi
            { "芘" , "bi" },        // pi 
            { "泌" , "mi" },        // bi
            { "秘" , "mi" },        // bi
            { "裨" , "bi" },        // pi 
            { "辟" , "pi" },        // bi
            { "睥" , "pi" },        // bi
            { "扁" , "bian" },      // pian 
            { "褊" , "bian" },      // pian 
            { "便" , "bian" },      // pian 
            { "缏" , "bian" },      // pian 
            { "杓" , "shao" },      // biao
            { "骠" , "biao" },      // piao 
            { "麃" , "pao" },       // biao
            { "玢" , "fen" },       // bin
            { "槟" , "bing" },      // bin
            { "屏" , "ping" },      // bing
            { "绠" , "geng" },      // bing
            { "卜" , "bu" },        // bo
            { "畓" , "da" },        // bo
            { "泊" , "po" },        // bo
            { "魄" , "po" },        // tuo bo
            { "埔" , "pu" },        // bu
            { "拆" , "chai" },      // ca
            { "嚓" , "ca" },        // cha 
            { "偲" , "si" },        // cai
            { "参" , "can" },       // cen san shen 
            { "篸" , "can" },       // zan 
            { "掺" , "chan" },      // shan can
            { "孱" , "chan" },      // can
            { "臧" , "zang" },      // cang
            { "藏" , "cang" },      // zang 
            { "猠" , "o" },         // ce
            { "硛" , "ce" },        // ke o 
            { "侧" , "ce" },        // ze zhai 
            { "筴" , "ce" },        // jia 
            { "噌" , "cheng" },     // ceng
            { "曾" , "ceng" },      // zeng 
            { "差" , "cha" },       // chai ci 
            { "喳" , "zha" },       // cha
            { "查" , "cha" },       // zha 
            { "猹" , "cha" },       // zha 
            { "楂" , "zha" },       // cha
            { "槎" , "cha" },       // zha 
            { "刹" , "sha" },       // cha
            { "咤" , "zha" },       // cha
            { "柴" , "chai" },      // zhai 
            { "茝" , "chai" },      // zhi 
            { "瘥" , "cuo" },       // chai
            { "单" , "dan" },       // shan chan
            { "禅" , "chan" },      // shan 
            { "长" , "chang" },     // zhang 
            { "倘" , "tang" },      // chang
            { "惝" , "chang" },     // tang 
            { "绰" , "chuo" },      // chao
            { "焯" , "chao" },      // zhuo 
            { "剿" , "chao" },      // jiao 
            { "朝" , "chao" },      // zhao 
            { "鼌" , "zhao" },      // chao
            { "嘲" , "chao" },      // zhao 
            { "车" , "che" },       // ju 
            { "尺" , "chi" },       // che
            { "嗔" , "chen" },      // tian 
            { "称" , "cheng" },     // chen
            { "铛" , "dang" },      // cheng
            { "樘" , "tang" },      // cheng
            { "乘" , "cheng" },     // sheng 
            { "盛" , "sheng" },     // cheng
            { "澄" , "cheng" },     // deng 
            { "坻" , "di" },        // chi
            { "瘈" , "zhi" },       // chi
            { "涌" , "yong" },      // chong
            { "虫" , "chong" },     // hui 
            { "种" , "zhong" },     // chong
            { "重" , "zhong" },     // chong
            { "仇" , "chou" },      // qiu 
            { "帱" , "chou" },      // dao 
            { "杻" , "niu" },       // chou
            { "臭" , "chou" },      // xiu 
            { "助" , "zhu" },       // chu
            { "褚" , "zhu" },       // chuzhe 
            { "畜" , "chu" },       // xu 
            { "俶" , "chu" },       // ti 
            { "滀" , "chu" },       // xu 
            { "欻" , "xu" },        // chua
            { "啜" , "chuo" },      // chuai
            { "传" , "chuan" },     // zhuan 
            { "串" , "chuan" },     // guan 
            { "幢" , "zhuang" },    // chuang
            { "椎" , "zhui" },      // chui
            { "錞" , "dchun" },     // ui 
            { "婼" , "ruo" },       // chuo
            { "茈" , "zi" },        // ci
            { "兹" , "zi" },        // ci
            { "伺" , "si" },        // ci
            { "枞" , "cong" },      // zong 
            { "楤" , "song" },      // cong
            { "卒" , "zu" },        // cu
            { "趣" , "qu" },        // cu
            { "菆" , "zou" },       // cuan
            { "攒" , "zan" },       // cuan
            { "粹" , "cui" },       // sui 
            { "蹲" , "dun" },       // cun
            { "酂" , "zan" },       // cuo
            { "鶎" , "ku" },        // ta yi da
            { "嗒" , "da" },        // ta 
            { "沓" , "ta" },        // da
            { "惮" , "dan" },       // da
            { "大" , "da" },        // dai 
            { "汏" , "tai" },       // da
            { "呔" , "dai" },       // tai 
            { "骀" , "dai" },       // tai 
            { "掸" , "dan" },       // shan 
            { "黵" , "dan" },       // zhan 
            { "石" , "shi" },       // dan
            { "弹" , "tan" },       // dan
            { "澹" , "dan" },       // tan 
            { "乭" , "dao" },       // ri 
            { "叨" , "dao" },       // tao 
            { "焘" , "dao" },       // tao 
            { "的" , "de" },        // di 
            { "地" , "di" },        // de
            { "底" , "di" },        // de
            { "得" , "de" },        // dei 
            { "嘚" , "de" },        // dei 
            { "嚸" , "di" },        // mi 
            { "提" , "ti" },        // di
            { "翟" , "di" },        // zhai 
            { "蹢" , "di" },        // zhi 
            { "杕" , "di" },        // duo 
            { "揥" , "ti" },        // di
            { "阽" , "dian" },      // yan 
            { "佃" , "dian" },      // tian 
            { "钿" , "dian" },      // tian 
            { "鸟" , "niao" },      // diao
            { "调" , "tiao" },      // zhou diao
            { "铫" , "diao" },      // yao 
            { "咥" , "die" },       // xi 
            { "昳" , "die" },       // yi 
            { "喋" , "die" },       // zha 
            { "揲" , "die" },       // she 
            { "螲" , "zhi" },       // die
            { "丁" , "ding" },      // zheng 
            { "町" , "ding" },      // ting 
            { "铤" , "ting" },      // ding
            { "侗" , "tong" },      // dong
            { "垌" , "dong" },      // tong 
            { "恫" , "dong" },      // tong 
            { "峒" , "tong" },      // dong
            { "都" , "dou" },       // du 
            { "读" , "du" },        // dou
            { "渎" , "du" },        // dou
            { "叾" , "du" },        // ge 
            { "阇" , "du" },        // she 
            { "度" , "duo" },       // du
            { "斁" , "yi" },        // du
            { "敦" , "dun" },       // dui
            { "镦" , "dui" },       // dun 
            { "沌" , "dun" },       // zhuan 
            { "囤" , "tun" },       // dun
            { "楯" , "dun" },       // shun 
            { "鯲" , "wu" },        // ya duo ji 
            { "驮" , "tuo" },       // duo
            { "堕" , "duo" },       // hui 
            { "仒" , "o" },         // e
            { "旕" , "o" },         // si e
            { "襨" , "e" },         // ta
            { "欕" , "mi" },        // e
            { "恶" , "e" },         // wu 
            { "哦" , "o" },         // e
            { "蛾" , "e" },         // yi 
            { "阏" , "e" },         // yan 
            { "椧" , "mi" },        // eng
            { "臑" , "nao" },       // er
            { "佴" , "er" },        // nai 
            { "发" , "fa" },        // fei 
            { "酦" , "fa" },        // po 
            { "番" , "fan" },       // pan 
            { "袢" , "pan" },       // fan
            { "繁" , "fan" },       // po 
            { "仿" , "fang" },      // pang 
            { "彷" , "pang" },      // fang
            { "芾" , "fu" },        // fei
            { "怫" , "fu" },        // fei
            { "濆" , "fen" },       // pen 
            { "冯" , "feng" },      // ping 
            { "佛" , "fo" },        // fu 
            { "否" , "fou" },       // pi 
            { "莩" , "fu" },        // piao 
            { "俛" , "mian" },      // fu
            { "脯" , "pu" },        // fu
            { "乫" , "ga" },        // ri 
            { "凩" , "xi" },        // la  ga
            { "軈" , "ya" },        // ga
            { "夹" , "jia" },       // ga
            { "伽" , "ga" },        // jia qie 
            { "呷" , "xia" },       // ga
            { "咖" , "ka" },        // ga
            { "轧" , "zha" },       // ya  ga
            { "芥" , "jie" },       // gai
            { "盖" , "gai" },       // ge 
            { "奸" , "jian" },      // gan
            { "感" , "gan" },       // han 
            { "赣" , "gan" },       // gong 
            { "扛" , "kang" },      // gang
            { "戆" , "gang" },      // zhuang 
            { "皋" , "gao" },       // hao 
            { "羙" , "mei" },       // gao
            { "镐" , "gao" },       // hao 
            { "乬" , "ge" },        // ri 
            { "巪" , "xi" },        // ge
            { "唟" , "ge" },        // xi 
            { "仡" , "yi" },        // ge
            { "纥" , "ge" },        // he 
            { "咯" , "ge" },        // ka luo 
            { "革" , "ge" },        // ji 
            { "鬲" , "ge" },        // li 
            { "蛤" , "ge" },        // ha 
            { "合" , "he" },        // ge
            { "硌" , "luo" },       // ge
            { "给" , "gei" },       // ji 
            { "哏" , "gen" },       // hen 
            { "红" , "hong" },      // gong
            { "唝" , "gong" },      // hong 
            { "句" , "ju" },        // gou
            { "枸" , "gou" },       // ju 
            { "呱" , "gua" },       // gu
            { "家" , "jia" },       // gu
            { "鹘" , "gu" },        // hu 
            { "汩" , "gu" },        // yu 
            { "谷" , "gu" },        // yu 
            { "苦" , "ku" },        // gu
            { "贾" , "jia" },       // gu
            { "鹄" , "gu" },        // he hu 
            { "嘏" , "gu" },        // jia 
            { "雇" , "gu" },        // hu 
            { "栝" , "gua" },       // kuo 
            { "纶" , "lun" },       // guan
            { "矜" , "jin" },       // qin guan
            { "莞" , "guan" },      // wan 
            { "归" , "gui" },       // kui 
            { "龟" , "gui" },       // jun qiu 
            { "廆" , "gui" },       // hui wei 
            { "鲑" , "gui" },       // hua xie 
            { "氿" , "jiu" },       // gui
            { "炅" , "jiong" },     // gui
            { "炔" , "que" },       // gui
            { "柜" , "gui" },       // ju 
            { "桧" , "hui" },       // gui 
            { "鳜" , "gui" },       // jue 
            { "涡" , "wo" },        // guo
            { "乤" , "ha" },        // ri 
            { "扖" , "ru" },        // me  ha
            { "溌" , "tu" },        // ha
            { "噺" , "xi" },        // ha na 
            { "鱩" , "ta" },        // ha
            { "虾" , "xia" },       // ha
            { "咳" , "ke" },        // hai
            { "嗨" , "hai" },       // hei 
            { "还" , "huan" },      // hai
            { "害" , "hai" },       // he 
            { "炕" , "kang" },      // hang
            { "行" , "xing" },      // hang heng
            { "吭" , "keng" },      // hang
            { "巷" , "xiang" },     // hang
            { "貉" , "he" },        // hao
            { "遤" , "he" },        // wo 
            { "和" , "he" },        // hu huo 
            { "核" , "he" },        // hu 
            { "吓" , "xia" },       // he
            { "猲" , "xie" },       // he
            { "熇" , "he" },        // kao 
            { "嘿" , "hei" },       // mo 
            { "戏" , "xi" },        // hu hui 
            { "芴" , "wu" },        // hu
            { "浒" , "hu" },        // xu 
            { "唬" , "hu" },        // xia 
            { "楛" , "ku" },        // hu
            { "砉" , "xu" },        // hua
            { "郇" , "xun" },       // huan
            { "圜" , "yuan" },      // huan
            { "嬛" , "huan" },      // qiong xuan 
            { "眩" , "xuan" },      // huan
            { "炜" , "wei" },       // hui
            { "珲" , "hun" },       // hui
            { "睢" , "hui" },       // sui 
            { "会" , "hui" },       // kuai 
            { "浍" , "hui" },       // kuai 
            { "哕" , "yue" },       // hui
            { "荤" , "hun" },       // xun 
            { "奇" , "qi" },        // ji
            { "其" , "qi" },        // ji
            { "缉" , "ji" },        // qi 
            { "稽" , "ji" },        // qi 
            { "亟" , "ji" },        // qi 
            { "藉" , "ji" },        // jie 
            { "齐" , "qi" },        // ji
            { "系" , "xi" },        // ji
            { "荠" , "ji" },        // qi 
            { "祭" , "ji" },        // zhai 
            { "偈" , "jie" },       // ji
            { "嗧" , "jia" },       // lun 
            { "茄" , "qie" },       // jia
            { "葭" , "jia" },       // xia 
            { "假" , "jia" },       // xia 
            { "价" , "jia" },       // jie 
            { "浅" , "qian" },      // jian
            { "犍" , "jian" },      // qian 
            { "囝" , "jian" },      // nan 
            { "见" , "jian" },      // xian 
            { "槛" , "kan" },       // jian
            { "将" , "jiang" },     // qiang 
            { "降" , "jiang" },     // xiang 
            { "强" , "qiang" },     // jiang
            { "蕉" , "jiao" },      // qiao 
            { "徼" , "jiao" },      // yao 
            { "嚼" , "jiao" },      // jue 
            { "角" , "jiao" },      // jue 
            { "侥" , "jiao" },      // yao 
            { "脚" , "jiao" },      // jue 
            { "湫" , "jiu" },       // qiu jiao
            { "缴" , "jiao" },      // zhuo 
            { "峤" , "qiao" },      // jiao
            { "觉" , "jiao" },      // jue 
            { "校" , "xiao" },      // jiao
            { "楷" , "kai" },       // jie
            { "桔" , "jie" },       // ju 
            { "絜" , "xie" },       // jie
            { "解" , "jie" },       // xie 
            { "廑" , "jin" },       // qin 
            { "劲" , "jing" },      // jin
            { "倞" , "liang" },     // jing
            { "靓" , "liang" },     // jing
            { "且" , "qie" },       // ju
            { "苴" , "ju" },        // zu 
            { "蛆" , "qu" },        // ju
            { "趄" , "qie" },       // ju
            { "咀" , "ju" },        // zui 
            { "籧" , "qu" },        // ju
            { "苣" , "ju" },        // qu 
            { "圈" , "quan" },      // juan
            { "卷" , "juan" },      // quan 
            { "踡" , "quan" },      // juan
            { "隽" , "jun" },       // juan
            { "阙" , "que" },       // jue
            { "噱" , "xue" },       // jue
            { "筠" , "jun" },       // yun 
            { "麇" , "qun" },       // jun
            { "浚" , "jun" },       // xun 
            { "焌" , "jun" },       // qu 
            { "凧" , "ka" },        // yi 
            { "裃" , "ka" },        // mi mo xi 日
            { "聢" , "li" },        // xi ka
            { "鯑" , "ke" },        // nou zi ka
            { "鶍" , "si" },        // yi ka
            { "卡" , "ka" },        // qia 
            { "厼" , "mu" },        // wu ke
            { "迲" , "o" },         // pi ke
            { "穒" , "o" },         // ke
            { "壳" , "ke" },        // qiao 
            { "隗" , "wei" },       // kui
            { "鮱" , "luo" },       // la
            { "落" , "luo" },       // lao  la
            { "腊" , "la" },        // xi 
            { "蜡" , "la" },        // zha 
            { "癞" , "lai" },       // la
            { "莨" , "liang" },     // lang
            { "潦" , "liao" },      // lao
            { "姥" , "lao" },       // mu 
            { "獠" , "liao" },      // lao
            { "络" , "luo" },       // lao
            { "烙" , "lao" },       // luo 
            { "朰" , "te" },        // wu le
            { "榁" , "mu" },        // le
            { "肋" , "lei" },       // le
            { "乐" , "yue" },       // le
            { "勒" , "lei" },       // le
            { "漯" , "luo" },       // ta lei
            { "棱" , "leng" },      // ling 
            { "甅" , "li" },        // wa 
            { "蠡" , "li" },        // luo 
            { "栎" , "li" },        // yue 
            { "跞" , "li" },        // luo 
            { "俩" , "liang" },     // lia
            { "飂" , "liu" },       // liao
            { "蓼" , "liao" },      // lu 
            { "挘" , "lie" },       // ri 
            { "六" , "liu" },       // lu 
            { "陆" , "lu" },        // liu
            { "碌" , "lu" },        // liu
            { "泷" , "long" },      // shuang 
            { "弄" , "nong" },      // long
            { "偻" , "lou" },       // lv 
            { "露" , "lu" },        // lou
            { "绿" , "lv" },        // lu 
            { "捋" , "luo" },       // lv
            { "率" , "shuai" },     // lv
            { "呣" , "m" },         // mou 
            { "姆" , "mu" },        // m
            { "唜" , "si" },        // ma
            { "魸" , "na" },        // zi ma 日
            { "孖" , "zi" },        // ma
            { "抹" , "mo" },        // ma
            { "摩" , "mo" },        // ma
            { "埋" , "mai" },       // man 
            { "脉" , "mai" },       // mo 
            { "蔓" , "wan" },       // man
            { "尨" , "meng" },      // mang
            { "氓" , "mang" },      // meng 
            { "冒" , "mao" },       // mo 
            { "乄" , "shi" },       // me 日
            { "匁" , "mo" },        // ne me 日
            { "没" , "mei" },       // mo 
            { "糜" , "mi" },        // mei
            { "谜" , "mi" },        // mei
            { "汶" , "wen" },       // men
            { "亹" , "wei" },       // men
            { "黾" , "min" },       // meng
            { "鼡" , "ne" },        // zu mi 日
            { "蓂" , "ming" },      // mi
            { "免" , "mian" },      // wen 
            { "渑" , "mian" },      // sheng 
            { "缪" , "miu" },       // mou miao
            { "乜" , "mie" },       // nie 
            { "丆" , "ne" },        // o ye mo
            { "乮" , "ri" },        // mo 韩
            { "无" , "wu" },        // mo
            { "模" , "mo" },        // mu 
            { "万" , "wan" },       // mo
            { "莫" , "mo" },        // mu 
            { "袜" , "wa" },        // mo
            { "牟" , "mou" },       // mu 
            { "那" , "na" },        // ne nei nuo 
            { "南" , "nan" },       // na
            { "哪" , "na" },        // nai ne nei 
            { "内" , "nei" },       // na
            { "呐" , "na" },        // ne 
            { "娜" , "na" },        // nuo 
            { "艿" , "nai" },       // reng 
            { "呶" , "nao" },       // nu 
            { "縇" , "o" },         // se ne
            { "唔" , "wu" },        // ng
            { "哛" , "po" },        // pu ni
            { "鳰" , "o" },         // ni 日
            { "溺" , "ni" },        // niao 
            { "嶷" , "yi" },        // ni 
            { "粘" , "zhan" },      // nian
            { "捻" , "nian" },      // nie 
            { "辗" , "zhan" },      // nian
            { "尿" , "niao" },      // sui 
            { "宁" , "ning" },      // zhu 
            { "莻" , "xi" },        // nu 韩
            { "喏" , "nuo" },       // re 
            { "疟" , "nve" },       // yao 
            { "区" , "qu" },        // ou 
            { "巼" , "xi" },        // pa 韩
            { "派" , "pai" },       // pa
            { "闏" , "ying" },      // pai 韩
            { "迫" , "po" },        // pai
            { "胖" , "pang" },      // pan
            { "拚" , "pin" },       // pan
            { "喸" , "xi" },        // pao 韩
            { "朴" , "pu" },        // po  piao
            { "娉" , "pin" },       // ping 
            { "乶" , "po" },        // ri 韩 
            { "栖" , "qi" },        // xi 
            { "踦" , "qi" },        // yi 
            { "蹊" , "qi" },        // xi 
            { "圻" , "qi" },        // yin 
            { "俟" , "si" },        // qi
            { "綮" , "qing" },      // qi
            { "契" , "qi" },        // xie 
            { "砌" , "qie" },       // qi
            { "铅" , "qian" },      // yan 
            { "嗛" , "xian" },      // qian
            { "荨" , "qian" },      // xun 
            { "羬" , "xian" },      // qian
            { "纤" , "xian" },      // qian
            { "茜" , "xi" },        // qian
            { "倩" , "qian" },      // qing 
            { "慊" , "qie" },       // qian
            { "雀" , "que" },       // qiao
            { "鞘" , "qiao" },      // shao 
            { "亲" , "qin" },       // qing 
            { "覃" , "tan" },       // qin
            { "溱" , "qin" },       // zhen 
            { "鲭" , "qing" },      // zheng 
            { "蝤" , "qiu" },       // you 
            { "券" , "quan" },      // xuan 
            { "芍" , "shao" },      // que
            { "荛" , "yao" },       // rao
            { "若" , "ruo" },       // re
            { "葚" , "shen" },      // ren
            { "乽" , "za" },        // ri 韩
            { "乼" , "zu" },        // ri 韩
            { "乺" , "sao" },       // ri 韩
            { "鑓" , "ya" },        // ri 日
            { "虄" , "sa" },        // ri 韩
            { "扨" , "te" },        // sa 日
            { "苆" , "su" },        // sa 日
            { "栍" , "ying" },      // sa 韩
            { "摋" , "sa" },        // sha 
            { "思" , "si" },        // sai
            { "塞" , "sai" },       // se 
            { "糁" , "shen" },      // san
            { "燥" , "zao" },       // sao
            { "色" , "se" },        // shai 
            { "杉" , "shan" },      // sha
            { "莎" , "sha" },       // suo 
            { "挲" , "sha" },       // suo 
            { "噎" , "ye" },        // sha
            { "奢" , "she" },       // sha
            { "啑" , "ti" },        // sha
            { "厦" , "xia" },       // sha
            { "酾" , "shi" },       // shai
            { "栅" , "shan" },      // zha 
            { "剡" , "yan" },       // shan
            { "汤" , "tang" },      // shang
            { "蛸" , "xiao" },      // shao
            { "苕" , "shao" },      // tiao 
            { "畬" , "she" },       // yu 
            { "折" , "zhe" },       // she
            { "蛇" , "she" },       // yi 
            { "叶" , "ye" },        // xie she
            { "拾" , "shi" },       // she
            { "歙" , "she" },       // xi 
            { "谁" , "shui" },      // shei
            { "籡" , "shi" },       // shen 日
            { "莘" , "shen" },      // xin 
            { "什" , "shen" },      // shi 
            { "椹" , "shen" },      // zhen 
            { "狌" , "sheng" },     // xing 
            { "省" , "sheng" },     // xing 
            { "嘘" , "xu" },        // shi
            { "识" , "shi" },       // zhi 
            { "食" , "shi" },       // si yi 
            { "氏" , "shi" },       // zhi 
            { "似" , "si" },        // shi
            { "峙" , "zhi" },       // shi
            { "螫" , "shi" },       // zhe 
            { "熟" , "shu" },       // shou
            { "荼" , "tu" },        // shu
            { "属" , "shu" },       // zhu 
            { "术" , "shu" },       // zhu 
            { "庶" , "shu" },       // zhu 
            { "说" , "shuo" },      // tuo yue shui
            { "忪" , "song" },      // zhong 
            { "宿" , "su" },        // xiu 
            { "缩" , "suo" },       // su
            { "燵" , "tui" },       // ta 日
            { "拓" , "tuo" },       // ta
            { "潭" , "tan" },       // xun 
            { "陶" , "tao" },       // yao 
            { "罀" , "yo" },        // zhao te 日
            { "忒" , "tui" },       // te
            { "擿" , "ti" },        // zhi 
            { "荑" , "yi" },        // ti
            { "裼" , "xi" },        // ti
            { "僮" , "tong" },      // zhuang 
            { "侻" , "tuo" },       // tui
            { "褪" , "tui" },       // tun 
            { "屯" , "tun" },       // zhun 
            { "崴" , "wei" },       // wai
            { "菀" , "wan" },       // yu 
            { "尢" , "you" },       // wang
            { "亡" , "wang" },      // wu 
            { "圩" , "wei" },       // xu 
            { "尾" , "wei" },       // yi 
            { "尉" , "wei" },       // yu 
            { "遗" , "yi" },        // wei
            { "蔚" , "wei" },       // yu 
            { "挝" , "wo" },        // zhua 
            { "涴" , "wan" },       // yuan wo 
            { "於" , "yu" },        // wu
            { "铻" , "wu" },        // yu 
            { "夞" , "yi" },        // xi 韩
            { "硳" , "ze" },        // xi 韩
            { "褶" , "zhe" },       // xi
            { "洗" , "xi" },        // xian 
            { "铣" , "xi" },        // xian 
            { "县" , "xian" },      // xuan 
            { "削" , "xiao" },      // xue 
            { "邪" , "xie" },        // ye 
            { "荥" , "ying" },       // xing
            { "褎" , "you" },        // xiu
            { "吁" , "yu" },         // xu 
            { "芧" , "zhu" },        // xu
            { "窨" , "yin" },        // xun
            { "厌" , "yan" },        // ya
            { "咽" , "yan" },        // ye 
            { "殷" , "yin" },        // yan
            { "芫" , "yuan" },       // yan
            { "约" , "yue" },        // yao
            { "繇" , "yao" },        // you zhou 
            { "钥" , "yao" },        // yue 
            { "拽" , "zhuai" },      // ye
            { "育" , "yu" },         // yo
            { "喁" , "yong" },       // yu 
            { "柚" , "you" },        // zhu 
            { "粥" , "zhou" },       // yu
            { "熨" , "yun" },        // yu
            { "员" , "yuan" },       // yun 
            { "扎" , "zha" },        // za
            { "拶" , "zan" },        // za
            { "囋" , "za" },         // zan 
            { "咋" , "za" },         // ze zha 
            { "甾" , "zai" },        // zi 
            { "仔" , "zi" },         // zai
            { "奘" , "zang" },       // zhuang 
            { "责" , "ze" },         // zhai 
            { "择" , "ze" },         // zhai 
            { "综" , "zong" },       // zeng
            { "着" , "zhuo" },       // zhao
            { "啁" , "zhou" },       // zhao
            { "爪" , "zhua" },       // zhao
            { "这" , "zhe" },        // zhei 
            { "吱" , "zhi" },        // zi 
            { "祝" , "zhu" },        // zhou
            { "躅" , "zhuo" },       // zhu
            { "转" , "zhuan" },      // zhuai
            { "赚" , "zhuan" },      // zuan 
            { "篹" , "zuan" },       // zhuan
            { "觜" , "zui" },        // zi

            { "鲅", "ba" },           // bo 
            { "䎬", "pa" },           // ba
            { "扳", "ban" },          // pan 
            { "般", "ban" },          // bo pan 
            { "剥", "bao" },          // bo 
            { "趵", "bao" },          // bo 
            { "蕃", "fan" },          // bo
            { "嗀", "gu" },           // hu 
            { "桁", "heng" },         // hang
            { "珩", "heng" },         // hang
            { "牙", "ya" },           // he
            { "㧐", "song" },         // yu 
            { "嘬", "zuo" },          // chuai
            { "撮", "cuo" },          // zuo 
            { "笮", "zuo" },          // ze
            { "琢", "zhuo" },         // zuo 
        };

        /*
		0. 汉字拼音表，来源于 http://xh.5156edu.com/pinyi.html （需要自己获取数据）
		1. 在'bo'添加'卜' ; 'de'添加'的' ; 'wan'添加'涴' ; 'ta'添加'他'
		  （获取到的数据有缺失，是网站的问题，这里直接补全）
		2. ü 用 v 代替
		3. 更新
			去掉 '' 原来在'虱'的后面 20200410
			去掉 '' 原来在'驟'的后面 20200410
		*/
        private static string[,] hanziTables = new string[g_length_hanziTables, 3]
        {
            { "a", "a", "吖阿呵啊腌锕錒嗄厑" },
            { "a", "ao", "凹柪梎軪熬爊敖厫隞蔜遨廒嗷嗸獓嶅滶獒摮璈磝螯聱翱翶謷謸鳌翺嚣鏖鷔鰲鼇艹夭芺抝拗袄镺媪媼襖岙岰垇坳傲奡奥奧骜嫯慠懊墺澳嶴擙鏊驁澚鱜" },
            { "a", "ang", "肮骯卬仰岇昂昻枊盎醠" },
            { "a", "ai", "哎哀诶唉娭挨埃溾嗳锿鎄捱皑啀凒溰敱敳嘊皚癌騃佁毐昹欸娾矮蔼躷噯濭藹譪霭靄艾阨伌爱砹硋隘嗌嫒塧碍愛叆暧瑷僾噫壒懓嬡薆鴱餲璦曖懝皧瞹馤礙譺鑀靉閊魞﨟鱛鱫" },
            { "a", "an", "厂广安侒峖桉氨庵偣谙菴萻葊媕腤痷鹌誝蓭鞍鞌諳盦馣鮟盫鵪鶕韽玵啽雸儑垵俺唵埯铵晻揞罯銨屵犴岸按洝荌胺豻案婩隌堓暗貋錌闇黯" },

            { "b", "bai", "挀掰白犤百伯佰陌柏栢捭絔摆擺襬庍呗拝败拜敗猈稗粺薭贁韛瓸竡粨兡" },
            { "b", "ba", "丷八仈巴叭朳玐吧岜扷芭夿疤柭釟蚆粑笆捌哵羓豝鲃叐茇妭拔炦胈癹菝軷詙跋颰魃鼥把钯鈀靶伯弝坝爸杷垻罢耙跁鲅罷鮁䎬覇矲䎱霸壩灞欛抜鎺鯐" },
            { "b", "ban", "扳肦攽班般颁斑斒搬頒鳻瘢螌褩癍辬阪岅坂板版昄瓪钣粄舨鈑蝂魬闆办半伴扮拌姅绊坢怑柈秚絆湴鉡靽辦瓣螁" },
            { "b", "bang", "邦帮垹梆捠浜邫幇幚縍幫鞤绑綁榜牓膀玤挷旁蚌棒棓傍谤蒡搒塝稖蜯镑磅艕謗鎊" },
            { "b", "bao", "勹包苞孢炮枹胞剥剝笣龅煲裦褒蕔襃闁齙窇雹薄宝饱怉鸨保宲珤葆堡堢媬寚飽飹褓駂鳵鴇緥賲寳寶靌勽刨报抱铇豹趵蚫菢袌報鉋鲍骲髱暴虣鮑曓儤瀑爆犦曝忁鑤佨藵" },
            { "b", "ben", "奔泍贲犇锛錛本苯奙畚翉楍夯坌倴逩桳笨捹渀撪" },
            { "b", "bei", "陂卑杯柸背盃桮椑揹悲鹎碑藣鵯北鉳贝狈孛邶貝牬昁苝备郥钡被倍俻狽悖梖偝偹鄁珼琲惫軰備僃棓辈焙蓓蛽碚愂禙犕褙誖鞁骳鋇輩糒憊鞴鐾唄" },
            { "b", "beng", "伻祊奟崩绷閍絣痭嵭嘣綳繃甭甮埄埲菶琫琣鞛迸泵蚌逬揼塴甏镚蹦鏰" },
            { "b", "bi", "皀屄偪逼毴楅榌豍鵖螕鲾鎞鰏荸鼻匕比朼夶吡妣沘佊疕彼毞柀秕笔粃舭俾啚筆鄙箄聛貏币必毕闭庇佖诐芘邲迊坒怭怶苾妼咇泌畀畁哔荜陛贲毖柲珌疪秘铋毙狴畢袐粊笓閉閇婢庳萆萞梐敝赑堛愊愎皕禆弼弻湢詖筚賁貱蜌裨辟跸閟飶鉍滗滭嗶彃蓖蓽腷睥睤痹痺煏熚碧蔽弊鄪獙幣綼箅箆馝髲駜襅幤潷罼獘壁廦嬖避薜篦篳縪觱鮅蹕髀濞斃臂奰鏎饆鄨璧繴襣襞鞸魓韠躄躃驆鷝鐴贔朇鷩鼊萙蛯嬶" },
            { "b", "bian", "边炞砭笾萹编猵煸牑甂箯蝙糄編鞕鍽鳊獱邉邊鞭鯿鯾籩贬扁窆匾貶惼褊稨碥鴘藊卞弁抃汳汴苄釆忭玣变変昪便覍徧遍缏揙閞辡諚緶艑辨辩辧辫辮辯變峅" },
            { "b", "biao", "杓标飑骉髟彪淲猋脿颮滮摽骠蔈幖墂麃標熛膘镖瘭磦飙飚儦颷謤藨瀌爂鏢贆臕穮镳飆飇飈飊鑣驫嫑表婊裱諘錶褾檦俵鳔鋲" },
            { "b", "bie", "憋瘪蟞鳖癟鱉鼈虌龞别別莂蛂徶襒蹩彆" },
            { "b", "bin", "邠玢宾彬梹椕傧斌滨缤賓賔豩槟瑸镔儐濒頻豳濱濵虨璸檳瀕霦繽蠙鑌顮摈殡膑髩鬂擯殯臏髌鬓髕鬢" },
            { "b", "bing", "冫仌氷并冰兵屏栟掤槟丙邴陃苪怲抦秉昞昺炳柄饼绠眪蛃偋寎棅鈵禀稟鉼餅餠鞞幷並併庰倂栤竝病窉傡摒誁鮩靐垪鞆" },
            { "b", "bo", "卜癶癷波拨玻饽钵盋砵哱剥般趵缽紴袰菠啵溊碆鉢鲅僠蕃嶓播撥餑礡蹳驋鱍仢伯驳孛肑瓝泊狛帛郣勃侼胉柏袯瓟秡钹铂浡挬亳萡淿脖袹舶鹁渤葧博猼馎愽搏鈸鉑鲌魄馛駁艊箔牔煿膊僰镈踣鋍馞駮鮊薄謈襏簙餺鵓鎛嚗懪髆髉糪襮欂礴鑮跛簸孹檗擘譒蘗畓蔔" },
            { "b", "bu", "逋庯峬钸晡鈽誧餔錻鳪轐醭卜卟补哺捕堡補鵏鸔不布吥佈步歨歩怖咘钚柨悑部勏捗埔埗荹埠瓿鈈蔀廍踄郶餢篰簿巭" },

            { "c", "ca", "拆擦攃嚓礤礸遪乲" },
            { "c", "cai", "偲猜才财材財裁纔毝采倸啋寀婇彩採埰棌睬跴綵踩宷菜蔡縩" },
            { "c", "can", "参參叄骖飡湌叅喰傪嬠餐驂残蚕惭殘慚蝅慙蠺蠶惨朁慘䅟憯穇篸黪黲灿掺孱粲薒澯燦璨謲儏爘" },
            { "c", "cang", "⺋仓仺伧苍沧鸧舱倉傖凔滄蒼獊嵢螥艙鶬臧藏鑶賶濸" },
            { "c", "cao", "撡操糙曺曹蓸嘈嶆漕慒槽褿螬艚鏪艸草愺懆騲肏鄵襙鼜" },
            { "c", "ce", "夨册冊侧厕荝拺测恻敇粣笧萗厠側萴策測廁惻筴筞蓛箣憡簎猠硛" },
            { "c", "cen", "参嵾岑涔埁笒梣" },
            { "c", "ceng", "噌层曾層嶒竲驓蹭" },
            { "c", "cha", "叉扱扠杈臿差挿偛馇插揷嗏喳锸碴銟艖疀嚓鍤餷茬茶垞查査秅猹嵖搽靫詧楂槎察檫衩蹅镲鑔奼汊岔刹侘诧剎姹咤紁詫" },
            { "c", "chai", "芆肞钗拆差釵犲侪柴豺祡喍儕茝虿訍袃瘥蠆囆" },
            { "c", "chan", "辿觇梴掺搀覘裧摻鋓幨襜攙苂单谗婵馋湹孱棎禅煘缠蝉獑僝誗鋋儃廛嬋潺潹緾澶磛鄽螹毚蟬瀍酁儳蟾劖壥嚵瀺巉欃纏纒躔镵艬讒鑱饞产刬旵丳斺浐剗谄阐铲產産蒇剷摌滻蕆幝諂閳骣燀簅冁醦繟鏟譂闡囅灛讇忏硟摲懴颤懺羼韂顫" },
            { "c", "chang", "伥昌倡倀菖阊娼猖淐琩锠裮錩閶鲳鯧鼚长仧仩场兏肠苌镸長尝倘偿萇徜常瓺場腸甞裳塲嫦嘗膓瑺嚐償鲿鱨厂昶惝敞厰僘廠氅鋹怅玚畅鬯唱悵焻暢畼誯韔椙蟐" },
            { "c", "che", "车伡車俥砗莗唓硨蛼尺扯偖撦屮彻迠坼烢聅硩掣頙撤澈徹瞮勶爡" },
            { "c", "chao", "吵抄弨怊欩钞绰訬超鈔焯剿窼牊晁巢巣朝鼌鄛漅潮樔嘲窲罺鼂轈謿炒眧焣煼麨巐仦仯耖觘" },
            { "c", "chen", "抻郴捵棽琛嗔綝賝諃瞋謓尘臣辰忱沉陈迧茞莀莐宸陳栕桭谌訦軙敐晨鈂愖煁蔯樄塵敶瘎霃諶螴薼麎曟鷐趻硶碜墋夦踸磣鍖贂衬疢称龀趁趂榇齓齔儭谶嚫櫬襯讖烥" },
            { "c", "cheng", "阷泟爯柽棦称秤浾琤偁铛碀蛏晿牚赪靗憆稱摚撑撐噌樘緽頳赬瞠橕檉竀罉蟶穪鏿鐣饓丞成朾呈郕诚枨承荿宬娍峸洆城乗乘埕挰珹珵窚掁脭铖盛程揨堘裎絾筬惩椉棖誠塍塖溗酲鋮畻澄澂憕橙檙瀓懲騬侱徎逞骋悜庱睈騁鯎" },
            { "c", "chi", "吃妛彨哧胵鸱蚩粚笞眵瓻喫訵絺嗤媸摛痴瞝殦噄誺螭鴟鵄魑癡齝攡彲黐弛驰池迟迡茌坻竾荎持匙蚳赿貾遅筂遟馳箎墀漦遲踟篪鍉謘尺叺伬呎肔齿侈卶垑胣蚇耻恥豉袳歯欼袲裭鉹齒褫彳叱斥杘赤饬灻抶侙勅恜炽勑翅翄敕烾湁啻飭雴傺腟痸鉓銐翤瘈遫憏瘛慗翨熾趩懘鶒鷘麶" },
            { "c", "chong", "冲充沖忡茺涌浺珫翀舂嘃摏憧衝憃罿艟蹖虫种重隀崇崈漴褈蝩緟蟲爞宠埫寵铳揰銃" },
            { "c", "chou", "抽䌷紬搊篘瘳犨犫仇俦帱栦菗绸惆絒椆畴愁皗稠筹詶酬酧裯踌綢雔儔薵懤幬嬦檮燽雠疇籌醻躊讎讐雦丑丒吜杻杽偢瞅醜矁魗臭臰遚殠鮘" },
            { "c", "chua", "欻" },
            { "c", "chu", "出岀初摴樗貙齣刍处助除芻厨蒢豠滁锄雏鉏趎蒭媰蜍耡犓鋤篨廚橱櫉幮躇雛蹰櫥鶵躕杵础處椘楮储禇楚褚濋儲檚礎齭齼亍処竌豖绌怵泏竐欪畜俶敊埱絀珿傗鄐滀搐触閦諔儊嘼憷斶黜臅歜觸矗榋璴蟵" },
            { "c", "chuan", "巛川氚穿瑏传舡舩船剶遄椽傳暷篅輲舛荈喘歂僢踳汌玔串钏釧猭賗鶨" },
            { "c", "chuang", "刅创疮窓窗牎摐牕瘡窻床牀幢噇闯傸磢闖怆刱剏剙創愴" },
            { "c", "chuai", "揣搋膗䦷啜嘬䦟膪踹" },
            { "c", "chui", "吹炊龡垂埀陲倕桘菙捶搥棰椎圌腄锤槌箠錘鎚顀" },
            { "c", "chun", "旾杶春萅媋堾椿槆暙瑃蝽箺輴橁䲠櫄鶞鰆纯陙莼唇浱純脣淳湻犉鹑滣蒓蓴漘醇醕錞鶉鯙偆萶惷睶賰蠢" },
            { "c", "cong", "匆苁囱囪忩茐枞怱悤棇葱楤蔥蓯骢漗聡聪聦熜潨樅樬暰瑽璁瞛蟌聰篵鍯繱鏦鏓騘驄从丛徔従從徖婃淙悰孮琮潀漎賨賩誴錝樷藂叢灇欉爜愡憁謥" },
            { "c", "ci", "刺差呲玼疵趀偨跐骴縒髊蠀齹词珁茈茨垐柌祠兹瓷辝詞辞慈甆鹚磁雌餈飺糍辤薋嬨濨鴜礠辭鷀鶿此佌泚皉鮆朿次伺佽刾庛茦栨莿赐蛓絘賜螆閊" },
            { "c", "chuo", "逴趠踔戳繛辶辵哾娖娕婼婥啜涰绰惙辍酫踀綽輟龊擉餟磭歠嚽齪鑡" },
            { "c", "cu", "怚粗觕麁麄橻麤徂殂卒促脨猝酢媨瘄蔟趗誎醋憱趣踧噈瘯踿縬簇鼀蹙蹴蹵顣" },
            { "c", "cou", "凑湊辏楱腠輳" },
            { "c", "cun", "邨村皴踆澊墫竴膥存侟拵蹲刌忖寸籿" },
            { "c", "cuan", "汆撺镩蹿攛躥鑹菆攒櫕巑欑穳窜殩熶篡簒竄爨" },
            { "c", "cui", "崔脺嵟凗催缞墔慛榱獕摧槯磪縗鏙漼璀趡皠伜忰疩脆脃倅粋紣翆萃啐啛淬悴焠毳琗瘁翠綷粹膵膬竁襊濢顇臎" },
            { "c", "cuo", "搓遳瑳磋撮醝蹉鎈虘嵯嵳睉痤蒫矬蔖瘥鹾酂鹺脞剉剒莝莡厝挫夎措逪锉错蓌銼錯" },

            { "d", "da", "咑哒耷笚答嗒搭褡撘墶噠鎝鎉打达迏迖迚怛呾妲沓荙荅炟羍畗畣惮匒剳逹笪詚達跶靼瘩薘鞑蟽鐽韃龖龘大亣汏垯眔畓繨躂鶎" },
            { "d", "dang", "当珰裆铛筜當儅噹澢璫襠蟷艡簹鐺闣挡党谠擋譡黨攩灙欓讜氹凼圵宕砀荡垱档菪婸逿愓瓽雼嵣潒碭瞊趤蕩壋檔璗盪礑簜蘯" },
            { "d", "dan", "丹妉担单単眈砃耽耼郸聃躭酖單殚媅瘅匰鄲頕褝箪勯儋殫擔甔襌簞聸刐伔抌瓭玬胆衴紞疸掸赕亶馾撣撢賧黕膽黮黵旦石帎但诞狚泹沊柦唌疍蛋弹惮啖啗淡萏啿弾氮蜑腅觛誕窞蓞僤噉髧嘾彈憚憺禫澹駳鴠餤癉癚繵贉嚪饏霮" },
            { "d", "dai", "呆呔待獃懛歹歺逮傣大代轪甙侢迨帒骀岱绐垈贷带玳殆柋怠軑貣帯帶埭蚮紿軚袋軩貸瑇跢廗叇曃蝳緿鴏黛艜戴簤瀻霴黱襶靆" },
            { "d", "de", "的嘚恴得淂棏惪悳锝徳德鍀地底" },
            { "d", "dao", "刀刂叨忉朷氘舠釖鱽魛螩捯导岛陦島捣倒祷禂搗隝嶋嶌導隯嶹擣壔蹈禱辺到帱悼焘菿盗盜道翢稲稻噵艔衜衟檤燾翿軇瓙纛乭﨩椡槝" },
            { "d", "dei", "嘚得" },
            { "d", "deng", "灯登豋僜噔嬁燈璒竳簦蹬等戥邓鄧隥凳嶝澄墱镫瞪磴櫈覴鐙艠" },
            { "d", "den", "扥扽" },
            { "d", "dia", "嗲" },
            { "d", "di", "氐仾低彽奃岻秪袛隄羝埞啲堤提趆滴嘀镝磾鞮廸狄苖迪的籴唙荻涤敌梑啇笛靮觌滌髢馰頔翟嫡蔋蔐樀敵藡嚁豴蹢鏑覿糴鸐厎邸阺诋坘坻弤底呧抵拞柢牴砥掋菧軧觝詆骶聜鯳地坔杕旳弟玓苐枤怟埅帝俤娣递逓埊焍谛梊祶菂偙眱珶第釱睇揥媂蒂棣缔楴禘遞僀腣鉪碲蝃摕遰蔕墬墑甋蝭締慸諦踶嶳螮嚸" },
            { "d", "die", "爹跌褺苵迭咥峌挕绖垤恎昳胅瓞眣耊谍眰戜絰臷镻詄趃跕畳喋耋惵堞揲殜叠楪牃牒跮碟褋蜨嵽蝶艓諜蹀鴩疂螲鲽蹛曡疉鰈疊氎哋幉" },
            { "d", "diao", "刁叼汈刟虭凋彫奝弴蛁貂琱鳭碉鮉瞗錭鲷雕簓鼦鯛鵰鸟扚屌弔吊伄钓盄窎訋调铞铫掉釣鈟竨蓧銱銚雿魡調窵瘹鋽藋鑃" },
            { "d", "dian", "敁掂厧傎嵮滇槇槙瘨颠蹎顛顚巅癫巓攧巔癲齻典奌点婰敟碘蒧蕇踮點电甸阽佃店坫垫扂玷钿惦婝淀琔奠殿鈿蜔電墊壂澱橂靛磹癜簟驔椣" },
            { "d", "diu", "丢丟铥颩銩" },
            { "d", "ding", "丁仃帄叮玎钉盯疔町虰耵酊釘靪艼奵顶頂鼎鼑嵿濎薡鐤订饤忊矴定訂飣铤萣啶椗腚锭碇碠錠顁磸" },
            { "d", "du", "厾剢都阇督嘟醏闍独毒读渎牍椟犊裻読錖獨凟匵嬻瀆殰犢櫝牘瓄皾騳黩髑韣讀贕豄鑟韇韥黷讟肚笃堵赌琽睹賭覩篤芏杜妒妬度荰秺靯渡镀螙鍍殬斁蠧蠹叾獤" },
            { "d", "dou", "吺剅都唗兜兠蔸橷篼唞斗阧抖枓钭陡蚪鈄吋豆郖读荳逗饾浢鬥渎酘毭梪脰痘閗窦鬦餖斣闘竇鬪鬬鬭乧" },
            { "d", "dong", "东冬東咚苳岽昸氡鸫倲菄崬崠涷埬娻笗氭蝀鮗鼕鯟鶇董蕫嬞懂箽諌动冻侗垌恫栋胨迵姛峒挏洞凍胴戙動硐湩腖棟働駧霘鶫" },
            { "d", "dui", "垖堆塠痽磓鴭鐜鐓頧队对兊兌対兑祋怼陮隊敦碓綐對憞憝錞镦薱濧懟瀩譈譵轛" },
            { "d", "duan", "耑偳媏端褍鍴短段断葮缎塅煅瑖腶椴锻碫緞毈簖鍛斷躖籪" },
            { "d", "duo", "多夛咄哆剟掇毲敠敪裰嚉夺度铎敚敓剫喥痥奪凙澤踱鐸驮朵朶杕饳剁沲哚挆柮柂垛垜埵缍舵崜惰媠椯躲躱趓跺綞亸鬌軃嚲奲刴陊陏挅尮桗堕跥飿墮憜墯鵽﨣鈬鯲" },
            { "d", "dun", "吨惇敦蜳撴墩墪噸撉犜镦礅蹲蹾驐盹趸躉伅庉沌囤炖逇钝盾砘顿鈍遁頓楯遯潡燉踲碷壿" },

            { "e", "e", "阿妸妿娿婀屙讹迗吪囮俄峉峨峩涐恶娥莪哦珴訛鈋皒锇睋鹅蛾誐磀噁鋨頟魤额額鵝鵞譌厄阸苊呃扼轭枙垩砨饿胺阏鄂谔萼遌遏崿愕頋腭锷鹗頞餩噩鳄騀戹岋呝砐砈咹咢姶匎蚅軛硆悪卾偔堊堨堮湂惡軶豟鈪琧廅搤搹僫蝁蕚遻餓颚閼擜諤覨鍔顎歞礘櫮鶚鰐鰪齃讍齶鑩鱷仒厑蛯旕鵈襨欕" },
            { "e", "en", "奀恩蒽煾峎摁" },
            { "e", "ei", "欸誒" },
            { "e", "eng", "鞥椧" },
            { "e", "er", "乻儿而児陑侕荋耏峏洏栭胹唲鸸袻聏輀鲕髵隭鴯鮞臑轜尔尒尓耳迩饵洱毦栮珥铒鉺餌爾駬薾邇二弍弐佴刵咡贰貮貳衈誀髶樲粫趰" },

            { "f", "fa", "发冹沷発發酦彂乏伐姂坺垡茷阀疺罚栰笩筏傠瞂罰閥罸墢橃藅佱法峜砝灋珐琺髪髮蕟浌鍅" },
            { "f", "fang", "匚方邡芳汸坊枋牥钫蚄淓趽鈁錺鴋防妨房肪鲂魴访仿彷纺昉昘瓬眆紡舫旊倣訪髣鶭放堏" },
            { "f", "fan", "帆忛畨番勫蕃幡噃嬏憣旙旛繙翻藩轓颿飜籓鱕凡凣凢匥杋柉钒矾籵舤舧袢烦笲釩棥煩緐墦樊璠膰薠燔襎繁羳蹯鐇礬蘩瀿蠜鷭⺁反払仮返橎犯氾汎奿饭泛贩范畈軓訉販笵盕梵軬飯飰滼嬎範輽瀪" },
            { "f", "feng", "丰风凨仹凬妦沣凮枫盽疯砜封風峰峯偑桻烽堼葑崶渢猦锋犎楓蜂碸瘋篈僼鄷鋒檒豐鎽鏠酆蘴寷灃蠭靊飌麷冯夆沨浲逢溄堸馮艂漨缝摓綘縫讽覂唪諷凤奉俸湗焨煈赗鳯鳳鴌賵琒" },
            { "f", "fen", "分芬帉吩纷氛昐玢衯紛翂躮訜酚棻梤鈖雰馚餴朆饙妢岎汾坟炃朌枌羒蚠蚡焚棼蒶隫魵蕡幩獖墳濆燌燓橨豮鼢羵鼖豶轒鐼馩黂粉黺份弅坋忿奋秎偾粪愤僨憤膹奮糞鲼瀵鱝竕瞓" },
            { "f", "fei", "⺄飞妃非飛菲啡婓婔渄绯扉猆暃靟裶蜚緋鲱霏馡餥騑騛鯡飝肥淝腓蜰朏胐匪诽奜悱棐斐翡榧蕜誹篚发芾吠狒沸怫杮废肺胇昲费厞剕陫俷疿萉屝廃費痱镄廢曊癈鼣蟦濷櫠鐨靅" },
            { "f", "fou", "紑缶否妚缻缹雬殕鴀" },
            { "f", "fo", "仏佛坲梻" },
            { "f", "fu", "夫伕邞孚呋妋姇玞肤胕砆衭怤柎荂荴尃娐旉麸趺紨跗鈇稃綒筟鄜孵粰膚鳺麩敷麬糐麱懯乀巿弗凫伏甶佛刜芾芙芣扶拂泭岪绂绋咈帗苻茀枎怫服韨氟祓玸枹柫炥畐畉罘茯郛鳬俘垘洑浮哹莩蚨袚栿砩翇桴烰琈袱虙艴紱紼符笰菔匐涪幅葍絥罦棴鳧艀鉘鉜颫辐福蜉綍箙稪榑韍豧髴鴔蝠幞澓輻踾鮄諨黻襆癁鮲襥鵩鶝阝父甫抚拊弣府斧郙俛俌俯釜釡捬脯辅腑盙焤蜅滏腐輔頫嘸撫鬴簠鯱黼讣付妇负附彿咐驸坿竎阜訃負赴复祔峊袝蚥蚹副婦婏冨偩傅復萯媍富赋蛗秿覄詂鲋腹椱缚赙複褔蝮蝜緮蕧賦駙鮒輹嬔縛賻鳆鍑鍢馥覆鰒酜﨓椨禣" },

            { "g", "ga", "夹旮伽呷咖嘎嘠轧钆釓尜噶錷玍尕尬魀乫凩軈" },
            { "g", "gai", "侅该陔郂荄姟峐垓赅晐祴畡絯隑賅賌豥該忋改絠丐乢匃匄芥钙盖鈣摡溉葢蓋戤概槩漑槪瓂" },
            { "g", "gang", "冈冮刚扛纲岗杠肛㧏㭎疘矼牨岡钢缸罡剛堈掆釭犅棡摃堽罁綱鋼鎠崗港焵焹筻槓戆戅戇" },
            { "g", "gan", "干甘迀奸忓杆攼玕肝姏泔苷坩矸竿柑酐疳粓凲尴尲筸鳱漧尶尷魐仠芉皯衦秆赶笴桿敢稈感澉趕橄澸擀簳鳡鱤汵旰盰绀凎倝淦紺詌骭幹榦檊贑赣贛灨" },
            { "g", "gao", "羔皋高羙髙皐臯膏睾槔槹橰糕篙餻韟櫜鼛鷎鷱夰杲菒稁搞缟槁槀暠稿稾镐縞藁藳檺鎬告郜勂诰峼祮祰锆筶誥禞鋯吿" },
            { "g", "gei", "给給" },
            { "g", "ge", "戈仡犵扢纥圪戓肐牫疙饹咯哥胳格鸽袼搁割滒歌戨鴚鴿謌擱鎶呄匌佮茖阁挌革鬲敋葛隔裓蛤蛒臵愅觡嗝滆塥搿槅膈閤閣鞈骼韐镉獦諽輵鮯鎘韚騔鞷轕个合各哿盖舸嗰虼個铬硌箇鉻乬巪叾唟彁櫊" },
            { "g", "geng", "更刯庚畊耕浭菮赓焿絚鹒縆緪賡羮鶊羹郠莄哽峺挭绠埂耿颈梗綆鲠骾鯁堩暅椩" },
            { "g", "gen", "根跟哏艮亘亙茛揯搄" },
            { "g", "gu", "估杚姑沽泒孤苽咕呱轱柧骨鸪罛唂唃家菰菇蛄笟軱軲觚辜酤蓇鈲毂稒箍箛篐嫴橭鴣鮕鹘夃古诂汩谷股苦牯羖贾钴罟蛊啒淈愲尳詁鹄馉鈷榾嗀鼓鼔榖嘏皷穀縎糓薣濲臌皼餶轂盬瞽瀔鶻蠱固故顾凅牿梏崮崓堌棝雇祻锢痼僱錮鲴鯝顧逧脵傦" },
            { "g", "gou", "勾句沟佝枸钩痀袧鈎缑鉤溝褠緱篝簼鞲韝芶苟狗岣耇耉玽蚼笱耈豿诟坸购构姤垢冓够夠啂訽詬雊遘彀媾搆煹觏構撀購覯" },
            { "g", "gong", "工弓公厷⺗功共红杛攻供侊肱糼糿宫宮恭蚣躬龚匑幊愩塨觥躳慐匔碽髸觵龏龔廾巩汞拱栱拲珙輁鞏贡唝貢嗊熕赣" },
            { "g", "guai", "乖摑叏拐柺枴罫箉夬怪恠" },
            { "g", "gua", "瓜刮呱胍栝桰鸹歄煱趏劀緺踻颳鴰騧冎叧剐剮寡卦诖坬挂掛啩罣絓詿褂颪" },
            { "g", "guan", "关观纶官冠矜覌倌莞蒄棺窤関瘝癏観闗鳏關鰥鱞觀馆琯筦痯管輨錧館璭舘鳤卝毌丱串贯泴掼涫惯悺貫悹祼慣潅摜遦樌盥罆雚躀鏆灌瓘爟矔鹳礶罐鑵鸛鱹欟" },
            { "g", "gui", "归圭妫龟邽规茥闺皈胿珪帰亀硅袿規廆椝媯郌瑰摫閨鲑嫢嬀槻槼龜璝瞡鮭歸雟鬶嶲騩瓌鬹蘬宄氿轨庋匦陒佹诡姽垝恑攱癸軌鬼祪庪匭晷湀蛫觤詭厬簋蟡攰昋刿刽炅炔柜贵桂桧椢猤筀貴跪蓕瞆螝撌劌劊槶樻檜禬瞶癐襘櫃鐀鳜鞼鑎鱖鱥櫷" },
            { "g", "guang", "⺌光灮炗炚炛茪咣姯洸垙烡桄珖胱輄僙銧黆广広犷廣獷臩俇逛臦" },
            { "g", "gun", "丨衮袞绲惃辊棍蓘滚滾蔉緄緷輥鲧磙鮌鯀睔謴" },
            { "g", "guo", "过呙咶涡埚郭堝啯猓崞锅楇聒鈛瘑墎濄蝈彉嘓鍋彍蟈懖囯国囶囻圀國帼掴腘漍聝幗蔮慖虢膕馘簂果菓馃淉惈褁椁槨蜾粿綶裹輠餜過腂鐹" },

            { "h", "han", "犴佄顸哻蚶酣頇谽嫨憨馠魽鼾邗汗邯含函凾虷唅娢浛圅焓梒晗琀涵崡嵅寒韩甝筨蜬鋡澏韓⺳罕浫喊蔊㘎豃㘚厈汉屽扞闬旱垾悍猂莟捍涆菡焊晘釬閈皔睅蛿傼馯感颔漢撖蜭熯銲鋎暵頷憾螒翰撼顄駻雗譀瀚鶾兯爳" },
            { "h", "hai", "咍咳嗨还孩骸海胲烸酼醢亥妎骇害氦餀嗐駭駴饚塰" },
            { "h", "ha", "呵哈紦铪鉿虾蛤奤乤扖溌噺鎺鱩" },
            { "h", "hao", "茠蒿薅薧嚆乚毜皋蚝毫椃嗥獆貉豪獔噑嘷獋儫濠壕嚎蠔籇譹好郝号昊昦侴秏悎耗哠浩恏晧淏傐皓鄗聕號滈暤暭皞皜澔镐薃皡曍皥颢顥鰝灏灝竓" },
            { "h", "hang", "夯炕行苀迒吭斻杭肮绗桁珩蚢航笐颃貥裄絎筕頏魧沆巷垳" },
            { "h", "hen", "拫痕鞎佷很哏狠詪恨" },
            { "h", "hei", "黒黑嗨嘿潶" },
            { "h", "he", "诃呵抲欱牙合訶喝嗬蠚禾纥何和咊郃劾姀河盇柇狢峆饸阂曷籺紇釛荷核敆盍盉害涸渮盒菏萂啝龁訸颌惒楁澕毼阖鲄詥貉貈鉌閡餄麧熆鹖頜魺螛翮篕餲鞨齕闔礉覈鶡皬鑉龢吓佫贺垎哬袔寉焃鹄猲賀碋嗃煂熇褐赫鹤翯癋謞壑嚇燺爀鶴鶮鸖靍粭遤靎靏" },
            { "h", "hong", "叿吽呍灴轰哄訇烘軣焢硡揈渹谾薨輷鍧嚝轟仜弘妅屸红纮玒汯吰闳宏宖苰泓玜垬沗虹紅洪娂荭羾翃浤紘耾竑鸿硔紭谹鈜閎粠竤渱葓葒綋谼翝鉷鞃魟潂鋐篊黉霐彋蕻霟鴻黌唝晎讧訌閧銾撔澒闂鬨闀" },
            { "h", "heng", "亨哼涥悙脝行恒恆姮珩胻烆桁鸻撗横橫衡鴴蘅鑅鵆啈" },
            { "h", "hu", "乎匢戏虍芴苸呼泘垀昒忽曶恗烀轷匫唿惚淴虖軤雽雐滹嘑寣幠糊歑膴謼抇囫狐弧和瓳胡核壶隺壷斛焀鹄絗壺猢搰湖喖葫媩煳楜瑚鹘鹕蔛嘝蝴箶槲魱衚頶醐螜縠鍸餬觳鵠鬍瀫鶘鶦鰗乕汻虎浒俿萀唬虝琥滸錿互弖户戶戸冱芐护沪沍帍戽岵怙枑昈祜怘笏瓠扈婟楛雇綔嗀嗀鄠嫭嫮蔰滬摢槴熩鳸鍙豰簄嚛鹱護鳠頀鸌鱯粐" },
            { "h", "hua", "化华花哗砉錵蘤划呚骅姡華铧釫釪猾滑嘩搳撶劃磆鲑螖鋘蕐譁鏵驊鷨夻话杹枠画桦崋婳畫畵嬅觟話摦樺槬澅嫿諙諣黊舙繣譮婲埖椛硴蒊糀誮" },
            { "h", "huan", "欢犿狟歓鴅鵍酄嚾孉獾懽歡讙貛驩还郇环荁峘洹桓萑萈寏堚雈絙綄貆獂羦锾圜澴缳寰嬛還阛鍰環豲镮鹮糫繯轘鐶闤鬟瓛缓睆緩幻肒奂奐宦唤换涣浣眩烉焕梙逭患嵈喛喚渙換愌痪豢瑍煥瘓漶鲩槵澣擐藧鯇攌鯶鰀" },
            { "h", "huai", "怀徊淮槐褢踝褱懐懷瀤櫰耲蘹坏壊壞蘾" },
            { "h", "hou", "齁侯矦鄇葔帿喉猴睺瘊銗篌骺糇翭翵鍭餱鯸吼犼后郈厚茩後逅洉垕候堠豞鲎鲘鮜鱟" },
            { "h", "hun", "昏昬荤阍婚涽惛殙棔葷睧睯蔒閽轋忶浑珲混馄渾魂琿餛鼲诨俒圂溷慁倱婫掍焝睴觨尡諢" },
            { "h", "huang", "巟肓荒衁宺朚塃慌皇隍凰偟黄黃葟徨遑喤媓崲揘湟堭惶煌楻瑝锽墴潢獚熿蝗璜艎篁諻穔癀磺蟥簧餭鳇鍠韹趪騜鐄鰉鱑鷬怳恍炾晃晄谎奛幌詤熀縨謊兤櫎滉愰榥曂皝鎤皩" },
            { "h", "huo", "吙秴耠锪劐嚄豁騞攉佸和活秮秳灬火邩伙钬鈥煷漷夥沎货或咟俰获捇眓閄貨掝祸喐剨湱禍惑旤蒦窢鍃霍濩獲奯擭檴雘謋穫镬矆彟瀖嚯藿蠖耯艧嚿曤臛矐癨鑊韄靃彠" },
            { "h", "hui", "戏灰灳炜诙咴挥拻洃恢袆虺珲烣晖豗堕婎媈揮隓辉翚暉禈睢煇楎詼睳褘幑噅噕撝翬輝麾徽隳瀈蘳鰴囘回囬佪廻廽茴迴恛洄蚘烠逥痐蛔蛕蜖鮰虫悔毁毀毇燬檓譭卉屶屷汇讳会泋浍绘哕诲荟芔贿烩桧恚恵晦彗秽絵翙廆惠喙缋阓湏滙匯會彚彙賄詯㱮誨瘣僡嘒蔧蕙潓寭圚憓槥暳慧橞諱嬒獩濊薈薉徻頮餯藱篲檅燴璯繢穢瞺蟪嚖懳繪翽譓櫘鏸儶闠靧鐬譿顪颒璤" },

            { "j", "ji", "几讥叽击刉饥圾机刏乩芨玑肌鸡矶奇其枅咭唧剞姬屐积畟笄飢基庴喞嵇嵆幾赍犄筓缉朞稘畸嗘跻鳮銈僟綨緁箕毄稽鹡觭躸諆緝畿嘰槣齑錤機禨墼激隮襀積璣磯羁賷簊擊櫅耭雞韲鶏譏譤鐖饑躋鷄鞿魕癪羇虀鑇鑙齏覉羈鸄覊亼亽及伋彶吉汲岌级忣极即亟郆佶卽姞叝急皍級笈革觙揤疾堲楖焏偮卙谻集殛戢棘極湒塉嵴楫辑愱蒺嫉蝍趌銡耤膌槉嶯潗濈蕺蕀瘠箿踑踖輯螏檝藉磼襋蹐鍓艥籍鏶霵轚鶺齎躤雧己丮妀犱纪泲虮济给挤脊掎鱾戟麂魢撠橶穖擠蟣彑计旡记伎齐系忌坖际芰妓技剂季迹垍既紀荠茤茍洎哜計記剤紒觊继绩悸梞旣祭偈徛寄寂済葪蔇惎臮跡鬾魝裚痵継蓟際兾勣漈漃禝穊稩暨魥鲚霁跽誋諅鲫暩稷穄曁冀劑薊髻覬薺嚌濟檕績罽繋璾檵蹟鵋鯽齌鯚懻癠穧骥蘎蘮瀱繼鱀鰶鰿鷑霽蘻鱭驥﨤樭撃鯲廭" },
            { "j", "jiang", "江茳将姜浆畕豇將葁畺摪翞僵螀漿薑缰壃殭橿螿鳉礓疅疆繮韁鱂讲奖桨蒋傋塂奨奬蔣槳獎膙耩講顜匞匠弜夅降洚绛弶强絳酱勥滰嵹摾犟糡醤醬糨謽櫤" },
            { "j", "jie", "节阶疖皆结階接掲秸痎街揭嗟喈喼媘嫅堦椄湝脻楷煯稭鞂蝔擑謯癤鶛卩卪孑尐讦刧劫岊刦杢昅杰疌衱劼刼诘狤洁拮迼桔桀訐莭倢偈偼菨婕崨捷掶袺蛣絜結媫傑颉鉣嵥搩滐節睫詰蜐楬楶榤截鲒碣竭蓵潔镼鞊頡誱踕羯幯嶻擮鮚礍鍻巀蠞蠘蠽毑姐媎解觧飷檞丯介价芥岕庎吤戒届屆玠疥砎界畍衸诫借蚧悈徣唶堺楐琾骱蛶誡犗褯魪鎅藉桝" },
            { "j", "jiao", "艽交郊茭茮骄娇姣峧浇胶教䴔焦椒蛟跤虠鲛僬蕉澆憍嶕嶣嬌膠膲徼鮫穚鹪礁鵁簥轇蟭鐎驕鷦鷮矫嚼臫角侥佼狡饺挢绞烄晈捁笅皎脚铰搅湫絞筊賋勦剿腳敫煍暞僥摷踋鉸餃撟撹儌徺劋敽缴憿敿矯曒璬蟜皦繳譑孂灚攪鱎龣叫呌挍峤觉訆珓校轿较敎窌窖較滘漖嘄嘂嘦斠酵嶠噍潐嬓獥噭藠轎醮趭譥皭釂" },
            { "j", "jian", "戋尖幵奸间歼坚浅戔冿玪肩艰姦姧兼监笺豜菅菺猏惤渐堅缄溅湔葌間雃犍牋瑊椷椾睷碊蒹搛缣煎蔪箋鲣緘鹣樫蕑蕳熞鳽熸縑鋻餰馢鞬艱鞯鳒瀐鵑鵳殱礛瀸鰔鰜鶼殲櫼譼韀礷鰹囏虃韉鑯暕囝枧拣俭茧柬笕倹捡挸湕帴减剪检梘趼詃検锏睑硷裥堿減揃揀谫弿瑐絸筧简戬戩碱儉翦篯撿藆襇襉檢謇蹇謭簡繭礆瞼鬋鹸鰎蠒鐧鐗瀽鹻譾籛襺鹼见件見建饯贱洊荐剑牮珔舰剣健俴涧栫剱谏徤袸毽臶腱践跈寋楗旔賎鉴键監槛榗漸僭劎劍澗箭糋諓賤踺踐趝餞諫鍵薦劒劔鍳瞷磵礀繝濺檻擶瀳譛鏩覵覸艦轞鐱鑑鑒鑬鑳豣彅墹麉" },
            { "j", "jia", "加夹夾伽抸拁泇佳茄迦珈浃毠枷浹家痂耞笳袈梜葭傢跏猳腵筴鉫犌嘉镓豭貑鴐鎵麚甲扴圿忦郏郟荚莢唊恝脥铗戛戞裌蛱颊蛺跲頬鋏頰鴶鵊岬叚玾胛钾贾斚假婽徦斝椵賈鉀槚榎嘏瘕檟价驾架嫁幏榢價駕稼嗧糘" },
            { "j", "jiu", "丩勼纠朻牞鸠究糺糾赳阄萛啾揪揂湫鳩揫摎樛鬏鬮九久乆乣氿汣奺灸玖舏韭紤镹酒韮匛旧臼疚咎柩柾桕倃匓厩救就廄廐舅廏僦慦殧舊鹫鯦麔匶齨鷲杦欍" },
            { "j", "ju", "车凥且抅拘泃匊狙岨苴驹居陱毩捄挶眗疽砠罝梮蛆掬据涺崌娵婮毱趄跔跙椐琚腒锔裾雎蜛艍躹諊踘鋦駒鴡鮈鞠檋鞫鶋局泦侷狊桔郹焗菊啹婅淗湨椈輂犑䴗閰跼粷趜橘駶鵙繘鵴蹫鶪鼰巈蘜鼳驧弆咀沮柜枸举莒矩挙椇筥龃榉榘蒟聥舉踽擧櫸齟欅襷籧巨句讵苣邭姖岠拒洰怇炬歫拠具昛秬钜剧俱倨倶袓蚷耟粔詎距埧埾惧犋鉅飓虡豦锯窭寠聚愳駏鮔踞屦劇勮遽據澽懅窶壉鋸颶屨貗簴醵躆鐻懼﨔" },
            { "j", "jiong", "冂冋坰扃埛駉駫蘏蘔囧冏迥泂炅炯逈侰浻烱絅颎煚窘綗僒煛熲褧澃顈燛" },
            { "j", "jing", "巠坕坙泾茎京径经亰荆荊秔涇婛猄惊旌旍菁経稉葏晶腈睛經粳䴖精綡聙兢鲸麖鶄鶁鯨鼱驚麠井丼阱刭宑汫坓汬肼穽剄殌景儆頚幜澋憬璄璟璥憼暻頸蟼警劲妌迳弪净浄俓婙胫莖弳逕倞徑凈竞痉竟竫淨桱梷婧脛靓敬竧痙傹靖静獍誩踁境靚靜镜曔瀞鵛鏡競竸橸" },
            { "j", "jin", "巾今仐斤钅金釒觔矜衿荕津珒紟矝琎惍釿堻筋禁璡黅鹶襟仅尽卺侭巹紧堇菫厪谨僅锦嫤馑漌蓳廑緊槿瑾儘錦謹饉伒劤妗劲进近枃浕勁荩浸赆烬晋晉祲進唫煡缙溍寖搢靳盡墐瑨歏殣凚僸觐縉賮噤濅濜嚍藎嬧燼璶覲贐齽兓砛琻壗" },
            { "j", "jun", "军君汮均龟袀軍姰钧莙蚐桾菌皲鈞碅筠覠銞皸皹銁鲪頵麇鍕鮶麏麕呁郡陖俊骏峻馂捃浚埈隽焌晙珺葰竣畯棞雋蜠箘箟賐儁寯懏餕燇駿濬鵔鵕鵘攈攟" },
            { "j", "juan", "姢娟捐涓圈焆朘鹃裐勬镌鋑鎸鐫蠲呟卷帣埍菤捲锩踡錈臇奆劵巻狷勌倦桊绢悁隽眷鄄淃瓹腃睊罥絭絹睠慻蔨餋獧羂讂" },
            { "j", "jue", "噘撅撧屩屫亅孓孒决刔诀氒角芵弡決抉泬玦玨珏觉疦砄虳绝挗捔倔蚗欮脚桷斍覐觖訣赽掘崛崫趹鈌焳傕厥趉覚絶絕阙劂谲瑴駃鴃鴂瘚爴觮獗噊蕨蕝熦憰嶡嶥噱憠橛橜镢臄爵櫭蟩蟨譎爑蹶蹻蹷鐍鐝矍鳜嚼匷覺觼爝灍戄攫玃彏鷢䦆矡貜躩钁" },

            { "k", "ka", "咖咔喀卡佧咯胩鉲凧垰桛裃閊綛聢鯑鶍" },
            { "k", "kai", "开奒開揩锎鐦凯剀闿恺垲铠慨剴蒈凱嘅嵦愷楷塏輆锴暟鍇鎧闓颽忾炌烗欬勓愾鎎" },
            { "k", "ken", "肎肯肻垦恳啃豤貇錹墾懇掯硍裉褃" },
            { "k", "kao", "尻嵪髛丂考攷拷洘烤栲铐熇犒銬鲓靠鮳鯌廤" },
            { "k", "kan", "刊看栞龛勘嵁堪戡龕凵冚坎侃砍莰偘惂欿歁槛輡顑轗竷衎崁墈阚磡瞰闞鬫矙" },
            { "k", "ke", "匼苛坷呵牱牁珂科轲柯钶疴砢趷蚵痾軻颏棵萪稞犐搕鈳窠颗薖榼樖頦瞌蝌磕顆髁醘礚壳咳殻殼翗揢可岢炣渇渴敤嵑嶱克刻勀勊客峇恪娔课骒氪堁衉愘缂溘愙锞嗑碦緙艐課錁騍礊厼迲硛嵙兡穒鯑" },
            { "k", "kang", "忼砊粇康閌嫝嵻漮慷槺穅糠躿鏮鱇扛亢匟邟伉闶犺抗囥炕钪鈧" },
            { "k", "kua", "夸咵姱誇侉垮銙挎胯趶跨骻舿" },
            { "k", "ku", "刳郀矻枯桍哭堀圐跍窟骷鮬苦狜楛库绔俈秙庫焅袴裤絝喾瘔酷褲嚳萙鶎" },
            { "k", "kou", "芤抠眍剾摳彄瞘口劶叩扣怐敂宼冦寇釦窛筘蔻蔲滱瞉簆鷇" },
            { "k", "kong", "空倥崆涳埪悾硿箜躻錓鵼孔恐控鞚" },
            { "k", "keng", "阬劥吭妔坑挳硁牼铿硜硻誙摼銵鍞鏗" },
            { "k", "kuan", "宽寛寬臗髋髖梡欵款歀窽窾鑧" },
            { "k", "kuai", "㧟蒯擓巜凷会块快侩郐浍哙狯脍欳塊筷鲙墤鄶儈廥澮獪噲膾糩旝鱠圦" },
            { "k", "kui", "亏岿刲悝盔窥聧窺虧顝闚巋奎晆隗鄈逵馗揆葵喹骙暌戣楏楑魁睽蝰頯鍨鍷櫆藈騤夔蘷虁巙犪躨傀煃跬頍磈蹞䙡归尯匮蒉喟媿馈溃愦愧匱蕢嬇嘳憒潰聩聭䙌篑謉殨膭餽簣聵籄饋" },
            { "k", "kuang", "匡邼劻诓哐洭恇匩硄筐筺軭誆狂狅抂忹诳軖軠誑鵟夼儣懭邝纩圹况旷岲況矿昿贶眖砿框絋眶絖貺軦鉱鋛鄺壙黋爌曠懬穬矌礦纊鑛" },
            { "k", "kun", "坤昆晜裈堃菎猑崑崐焜琨髠髡锟鹍裩褌蜫髨醌瑻熴錕鲲騉鵾鯤鶤捆悃阃壸梱祵稇硱裍綑稛壼閫閸困涃睏堒潉" },
            { "k", "kuo", "扩拡括挄栝蛞筈萿葀阔廓頢髺韕鞟闊擴濶霩鞹鬠" },

            { "", "lan", "兰岚拦栏惏婪嵐阑葻蓝谰澜褴斓儖篮镧闌藍襕懢燷燣璼襤幱譋繿籃蘭蘫瀾灆攔欄斕襴灡囒籣讕躝欗襽鑭韊览浨揽缆榄漤罱醂覧壈懒擥懶嬾孄覽孏攬爦欖顲纜烂滥燗濫嚂爁爛瓓灠爤糷钄" },
            { "", "la", "拉垃柆菈啦喇搚邋旯剌砬揦磖嚹藞翋落腊楋揧蜡蝋辣辢瘌蝲臈癞鬎臘攋爉瓎櫴镴鯻蠟鑞凩溂鞡鮱" },
            { "", "lai", "来俫莱徕崃涞梾铼來倈郲徠逨庲唻婡猍崍淶萊赉棶琜睐筙赖箂錸濑癞騋麳鶆鯠籁襰睞賫賚賴頼顂鵣藾瀨瀬癩籟萙" },
            { "", "lang", "啷勆郎郞郎欴莨狼桹蓈廊嫏琅斏稂锒硠瑯榔蜋艆筤郒躴螂樃鋃鎯朗朖烺蓢塱誏朤阆崀浪埌蒗閬" },
            { "", "lao", "捞撈劳労牢窂涝浶唠哰崂勞铹痨僗嶗潦憥癆磱蟧簩醪鐒顟髝耂老佬荖咾姥狫恅栳珯铑銠獠轑络烙閖落嗠酪耢嫪嘮澇憦躼橯耮軂硓粩朥" },
            { "", "leng", "棱唥塄楞稜碐薐冷倰堎愣睖踜" },
            { "", "le", "肋嘞仂阞忇艻叻扐氻乐玏泐竻砳勒楽餎韷樂簕鳓鰳鱳朰榁" },
            { "", "li", "哩刕丽厘骊剓荲狸离梨梸犁琍悡菞喱犂棃鹂缡蜊艃筣漓蓠剺嫠孷樆璃盠貍鋫鲡黎褵犛蔾縭篱罹錅謧醨蟍釐離藜嚟邌斄瓈鏫鵹鯬蟸黧蠡蠫灕囄蘺孋廲劙鑗籬穲纚驪鱺鸝礼礼里李俚峛峢峲逦娌理锂裡裏裏豊鋰鲤澧禮鯉醴鳢邐鱧鱱欚力历厉屴立朸吏呖励利叓苈坜沥沴岦枥苙例戾疠隶疬砅赲俪俐荔茘郦栎栃轹猁悧珕栗栛涖浰莉莅娳砺砾秝鬲蛎蚸粝粒笠婯唳脷悷棙傈凓厤跞詈蛠痢雳鳨睙鉝厯蒞蒚搮溧塛慄暦歴瑮厲綟蜧蝷篥鴗隷勵歷曆巁濿檪隸鬁磿癘犡爄蠇櫔曞禲擽儮嚦攊藶瓅櫟瀝壢礪麗礫蠣爏糲盭櫪瓑皪酈儷癧礰麜鷅轢觻躒囇攦欐讈轣靂瓥攭靋唎甅睝粴魞聢竰糎鯏鯐" },
            { "", "lei", "勒累傫雷蔂缧嫘畾樏擂儡縲攂镭礌櫑瓃羸礧罍纍蘲鐳轠鑘靁虆欙纝鼺厽耒诔洡垒絫塁誄漯蕌磊磥蕾藟壘癗櫐礨蠝灅蘽讄儽壨鑸鸓肋泪类涙淚酹銇頛頪錑檑颣類纇蘱禷矋" },
            { "", "lia", "俩" },
            { "", "lian", "连奁怜帘涟連莲梿裢联廉慩蓮亷漣溓嗹匲奩槤熑覝鲢聨聫磏褳憐匳劆噒嫾濂濓薕螊聮縺翴聯謰蹥燫櫣臁镰鎌簾蠊瀮鬑鰱鐮籢籨敛琏脸裣摙璉蔹嬚鄻斂歛臉襝羷蘞蘝练炼恋殓堜僆萰媡湅链煉楝瑓潋練澰錬鍊殮鏈鰊瀲戀纞" },
            { "", "liang", "良俍莨凉凉梁涼椋辌量粮粱踉墚樑輬駺糧両两兩俩倆唡啢掚脼裲蜽緉魉魎亮谅哴悢倞辆晾喨湸靓輌諒輛鍄" },
            { "", "liao", "撩蹽辽疗聊尞憀膋僚寥嵺漻潦缭嘹嶚嶛寮嫽獠遼敹暸璙膫燎橑療鹩竂蟟繚簝賿豂蹘廫藔屪爎爒飂髎飉鷯了钌釕鄝蓼憭瞭镽尥尦炓料廖撂窷镣鐐" },
            { "", "lie", "裂列劣劽冽挒茢迾咧姴洌浖埒埓烈哷烮栵捩䴕猎猟蛚聗趔煭巤颲鴷鮤儠獵擸犣躐鬛鬣鱲挘" },
            { "", "lin", "拎厸邻阾林临冧啉崊淋晽粦琳碄粼箖鄰隣隣遴潾嶙獜暽辚燐斴璘霖瞵磷疄臨繗翷麐轔鏻鳞瀶壣驎麟鱗菻亃僯凛凜撛澟懔懍廪廩檩檁癛癝吝恡悋赁焛賃蔺橉甐膦閵蹸藺躏躙躪轥" },
            { "", "liu", "溜熘澑蹓刘畄浏斿流留琉旈畱裗硫遛旒蒥蓅骝媹嵧馏飗榴瑠镏瘤瑬劉磂駠鹠橊疁镠璢癅蟉駵麍鎏鎦嚠瀏懰藰鏐飀騮鐂飅鶹鰡驑柳栁桞珋桺绺锍綹鋶罶熮橮羀嬼六陆翏廇塯碌鹨磟餾霤雡飂鬸鷚" },
            { "", "ling", "令伶刢灵坽囹夌苓彾呤姈狑泠柃朎昤瓴玲皊秢铃竛鸰砱陵羐凌菱淩崚掕婈棂琌蛉聆紷衑翎舲笭绫羚詅軨跉祾棱裬蓤龄鈴閝零綾蔆輘霊駖鹷鴒魿霗鲮錂蕶澪燯霛霝齢鯪酃孁齡櫺醽麢欞爧龗岭岺袊领領嶺另炩蘦靈" },
            { "", "long", "龙茏咙泷栊昽珑胧竜眬砻聋笼隆湰滝漋槞嶐窿篭龍癃鏧霳巃巄瀧嚨蘢爖櫳瓏曨襱朧矓礱礲龒龓籠豅躘聾蠪蠬靇鑨驡鸗陇拢垄垅篢隴儱壟壠攏竉弄哢梇徿贚" },
            { "", "lou", "搂瞜娄婁偻蒌溇喽楼漊慺蔞遱廔嘍熡樓蝼耧耬艛螻軁謱髅髏鞻鷜嵝嶁摟塿甊篓簍陋屚漏镂瘘瘺瘻鏤露䁖" },
            { "", "lu", "噜撸謢擼嚕卢芦庐泸垆炉枦栌胪鸬舮舻玈颅鲈馿魲盧璷壚瀘蘆廬嚧獹攎爐櫨曥瓐臚矑艫籚蠦罏纑鑪髗顱鱸鸕黸卤虏掳鹵鲁硵虜蓾滷塷澛樐魯磠橹擄穞镥瀂氌櫓艣鏀鐪艪鑥六圥甪陆侓录彔坴峍赂辂陸勎娽逯菉渌淕淥硉绿鹿椂禄祿琭勠僇剹稑盝睩碌賂輅路粶箓蓼蔍廘漉摝塶辘戮熝樚膔踛醁趢録錄錴穋潞蕗璐簏螰鴼蹗騄轆簶鹭簬簵鏕鵦鵱麓鯥騼鏴露籙鷺虂轳焒閊鈩氇轤" },
            { "", "lv", "驴闾榈閭膢氀櫚藘驢吕呂郘侣侶挔捛捋旅梠祣偻铝稆絽屡缕僂屢膂褛鋁履褸膐縷儢穭律垏虑绿率氯葎嵂滤綠緑慮膟箻繂勴濾爈櫖鑢" },
            { "", "luan", "娈峦孪栾挛脟鸾脔滦銮鵉巒孌奱孿圝攣灓欒曫羉臠圞虊灤鑾癴癵鸞卵乱釠亂" },
            { "", "lue", "寽畧稤鋝鋢" },
            { "", "lve", "掠略锊圙" },
            { "", "lun", "抡掄仑伦论芲沦纶囵侖轮倫陯圇淪菕婨崘崙棆腀碖蜦耣綸輪踚錀鯩埨惀稐溣論嗧磮" },
            { "", "luo", "捋啰落頱囉罗萝逻猡脶腡椤锣骡箩镙螺羅覶鏍騾覼蠡儸邏蘿玀攞欏驘鸁籮鑼饠囖剆倮蓏裸躶瘰蠃臝曪癳泺洛咯骆峈荦络烙洜珞硌硦絡跞笿詻雒犖摞漯駱鵅鮥濼纙鮱" },

            { "m", "m", "呒呣姆" },
            { "m", "mai", "埋薶霾买荬買嘪鷶劢迈麦佅売卖脉脈麥衇勱賣邁霡霢蕒" },
            { "m", "ma", "亇妈孖抹蚂麻媽嫲摩吗嗎痲痳蔴犘蟆马犸玛码馬獁溤瑪碼螞鎷鷌鰢杩祃骂閁唛傌睰嘜禡榪罵駡鬕唜嘛魸蟇" },
            { "m", "man", "埋嫚颟顢悗蛮谩蔓馒摱慲樠瞒瞞鞔謾饅鳗鬘鬗鰻蠻娨屘満满滿螨蟎鏋矕曼鄤僈蔄幔獌漫缦墁慢熳槾镘澷縵鏝襔" },
            { "m", "mang", "邙牤芒吂汒忙尨杧杗氓盲盳笀恾茫厖庬哤娏狵浝牻釯铓硭痝蛖鋩駹蘉莽莾硥茻壾漭蟒蠎" },
            { "m", "mao", "猫貓毛矛枆茆茅牦旄罞軞酕渵堥楙锚髦鉾蝥氂髳錨蟊鶜冇夘卯戼峁泖昴铆笷鉚蓩冃芼皃茂冐冒贸柕眊耄覒袤貿鄚萺帽媢毷暓瑁愗鄮貌瞀蝐懋毟" },
            { "m", "mei", "没沒坆苺枚玫栂眉脄莓郿脢梅珻睂堳湄湈葿媒猸嵋腜瑂禖楣楳煤酶槑镅鹛塺鋂霉鎇徾糜攗鶥黴毎每美凂挴浼羙嵄渼媄媺镁嬍燘躾鎂黣妹抺沬袂昧祙眛谜寐媚跊鬽痗煝魅韎睸蝞篃" },
            { "m", "me", "乄么匁扖庅嚒濹嚜嚰" },
            { "m", "men", "闷门们扪汶玧钔門閅們菛捫璊穈鍆亹虋焖悶暪燜懑懣椚" },
            { "m", "meng", "掹蒙擝尨甿氓虻莔萌溕盟鄳甍蝱鄸儚蕄瞢橗幪濛懞檬曚氋朦鹲礞鯍矇艨矒饛霿靀顭鸏黾勐冡猛锰蜢艋錳獴懵蠓鯭鼆孟梦夢夣懜霥" },
            { "m", "mi", "咪眯瞇弥祢迷猕谜蒾詸謎醚糜縻麋麊麿藌彌擟禰靡麛瀰獼蘪镾蘼戂攠瓕爢醾醿鸍釄米芈羋侎沵洣弭敉脒渳葞蔝銤濔孊灖冖糸汨沕泌怽宓觅祕峚宻秘覔覓密淧幂谧蓂幎覛塓蜜榓鼏蔤滵漞嘧熐冪樒幦濗謐簚櫁羃鼡袮粎裃椧嚸欕" },
            { "m", "mian", "宀芇杣眠绵婂媔棉綿臱蝒緜嬵檰櫋矈矊矏丏汅沔免勉俛眄娩渑偭勔冕葂喕湎睌缅愐腼緬澠靦鮸靣面麪麫糆麺麵" },
            { "m", "miao", "喵苗媌描瞄鹋緢嫹鶓劰杪秒眇渺缈淼緲篎藐邈妙庙竗玅庿缪廟" },
            { "m", "min", "民玟苠姄岷怋旻旼盿砇珉罠崏捪缗琘琝瑉碈痻鈱緍緡錉鴖鍲皿冺刡忟闵黾抿泯忞敃勄闽悯敏笢閔黽惽湣敯暋愍閩僶潣憫慜簢鳘蠠鰵垊笽" },
            { "m", "mie", "乜吀咩哶孭灭烕搣滅蔑薎鴓幭篾瀎懱櫗礣蠛衊鑖鱴旀" },
            { "m", "ming", "名明鸣眀洺茗冥眳朙铭鄍蓂溟嫇猽詺銘鳴榠暝瞑螟覭佲姳凕慏酩命掵" },
            { "m", "miu", "谬缪謬" },
            { "m", "mo", "摸嚤无尛谟嫫馍模摹膜麽麼摩橅磨糢謨謩嬷嬤擵饃蘑髍魔劘饝万抹懡末圽没沫陌妺茉帓殁歾歿枺昩脉帞冒莫莈皌秣砞眜眿袜絈眽貃蛨貊塻蓦嗼漠寞獏銆靺魩黙嫼嘿墨瞐瞙瘼镆默貘蟔鏌藦爅癦驀纆礳耱丆匁乮裃酛魹囕" },
            { "m", "mou", "哞牟劺侔呣恈谋眸蛑缪踎謀鍪麰鴾繆某" },
            { "m", "mu", "毪氁模母牡亩姆畂拇畆畒姥峔牳胟砪畝畞畮鉧踇木目仫牟狇沐坶苜牧炑毣莫莯蚞钼雮募慔幕幙墓鉬睦楘慕暮暯艒霂縸穆鞪厼榁" },

            { "n", "na", "那南拏拿嗱搻镎鎿乸哪雫内呐吶妠纳肭郍娜钠衲袦納笝軜豽捺貀鈉靹蒳魶凪魸噺" },
            { "n", "nai", "腉孻乃艿奶氖疓廼迺哪倷釢嬭佴奈柰耐萘渿鼐褦螚錼" },
            { "n", "nan", "囝囡男抩枏柟侽南莮畘难娚喃楠暔諵難赧萳揇湳煵腩蝻戁婻遖" },
            { "n", "nao", "孬呶怓挠峱铙硇蛲詉猱碙撓嶩憹蟯獶譊夒鐃獿巎垴恼悩脑脳匘堖惱瑙嫐腦碯闹淖閙鬧臑" },
            { "n", "nang", "囊囔乪嚢蠰馕欜饢擃曩攮灢儾齉" },
            { "n", "ne", "哪疒那讷呐抐眲訥丆匁鼡縇" },
            { "n", "nei", "哪娞馁脮腇餒鮾鯘内內那氝氞錗" },
            { "n", "nen", "恁嫩嫰" },
            { "n", "neng", "能" },
            { "n", "ng", "嗯唔" },
            { "n", "ni", "妮尼泥兒呢坭怩籾秜铌郳倪屔淣婗猊蚭埿棿跜鈮馜蜺聣輗觬貎鲵霓麑鯢齯臡拟你伲伱苨妳狔抳柅掜旎晲孴隬儗儞薿擬聻屰氼逆胒昵匿眤堄惄腻愵溺嫟睨暱縌誽膩嬺嶷檷哛鳰" },
            { "n", "nian", "拈蔫年秊秊哖姩秥粘鲇鲶鮎黏鯰涊淰捻辇辗碾輦撵撚簐蹍攆蹨躎卄廿念唸埝惗艌焾" },
            { "n", "niang", "娘嬢孃酿醸釀" },
            { "n", "niao", "鸟茑袅鳥嫋裊蔦樢褭嬝嬲尿脲溺" },
            { "n", "nie", "捏捻揑苶乜帇圼枿陧涅聂痆臬隉菍啮湼敜嵲嗫踂踗踙摰镊镍噛槷嶭篞臲錜颞蹑聶嚙鎳闑孽孼櫱蘖籋囁齧鑈巕蠥糱糵囓躡讘鑷顳钀" },
            { "n", "nin", "囜您拰脌" },
            { "n", "ning", "宁苧咛狞拧柠聍甯寍寕寗寜寧凝儜橣擰獰嚀薴嬣檸聹鑏鬡鸋矃佞侫泞倿澝濘" },
            { "n", "niu", "妞牛牜汼狃扭纽忸炄杻钮紐莥鈕靵拗" },
            { "n", "nou", "羺槈耨獳鎒檽鐞鯑" },
            { "n", "nong", "农侬浓哝脓秾農辳儂蕽濃噥膿燶檂禯穠襛譨醲欁鬞繷弄挊挵癑齈" },
            { "n", "nu", "奴伮驽孥笯駑努弩呶砮胬怒傉搙莻" },
            { "n", "nv", "女钕籹釹沑衂恧朒衄" },
            { "n", "nuan", "奻渜煗暖餪" },
            { "n", "nun", "黁" },
            { "n", "nve", "疟虐" },
            { "n", "nuo", "那娜挪梛傩橠儺诺逽喏掿愞搦锘榒稬諾蹃鍩糑懧懦糥穤糯" },

            { "o", "ou", "区讴沤欧殴瓯鸥塸熰歐鴎甌膒毆謳藲櫙鏂鷗呕吘偶腢嘔蕅耦藕怄慪漚" },
            { "o", "o", "噢哦丆仒乯迲猠硛旕筽鳰縇穒纐" },

            { "p", "pa", "叭汃妑苩派皅趴舥啪葩扒杷爬耙掱琶筢潖䎬帊帕怕袙巼" },
            { "p", "pai", "拍俳徘猅排棑牌箄輫簰簲迫沠派哌渒湃蒎鎃闏" },
            { "p", "pan", "扳拌眅萠番潘攀丬爿洀柈胖般盘跘蒰幋媻槃搫盤磐縏磻蹒蹣鎜蟠瀊鞶坢冸判伴沜泮拚炍牉盼叛畔袢詊溿頖鋬鵥襻鑻" },
            { "p", "pang", "乓胮雱滂膀膖霶仿彷厐庞逄旁舽嫎徬磅螃鳑龎龐鰟嗙耪覫髈炐肨胖眫" },
            { "p", "pao", "抛拋泡脬萢刨庖咆狍垉炰炮爮袍匏袌軳跑鞄麃麅奅疱皰砲靤麭礟礮喸褜" },
            { "p", "pei", "呸怌肧胚衃醅阫陪培赔毰锫裴裵賠錇俖伂犻沛佩帔姵斾旆珮配浿辔馷霈轡蓜" },
            { "p", "pen", "喷噴濆歕瓫盆葐湓呠翸喯" },
            { "p", "pi", "丕伓伾批纰邳坯炋枈披抷狉狓岯砒紕被秛秠铍悂旇耚翍豾鈚釽鉟銔髬駓磇劈噼錃魾錍憵鎞礔礕霹皮阰陂芘肶枇毗毘郫陴疲蚍蚾蚽豼埤啤崥琵焷脾腗椑裨鈹鲏蜱罴膍隦魮鮍壀篺螷鵧貔羆鼙蠯匹庀仳圮苉吡否脴痞銢鴄諀嶏擗噽癖嚭屁淠揊媲嫓睥辟稫潎僻澼甓䴙疈譬闢鸊鷿迲" },
            { "p", "peng", "匉抨泙怦恲砰硑烹梈軯閛剻漰嘭駍磞芃朋竼莑倗捀堋弸袶彭棚椖搒塜塳傰蓬稝鹏硼樥熢澎憉輣錋篷篣膨韸髼鬅蟛蟚纄蘕韼鵬鬔騯鑝捧淎皏掽椪碰槰踫輧" },
            { "p", "pian", "片囨扁偏媥犏翩篇鶣便骈胼腁缏楄楩賆跰褊骿駢蹁騈谝覑貵諞骗騙騗" },
            { "p", "piao", "票剽勡嘌彯漂缥飘旚螵翲犥飄飃魒朴嫖瓢薸闝莩殍瞟縹篻醥顠皫僄徱骠慓驃鰾" },
            { "p", "pie", "氕覕撇暼撆瞥丿苤鐅嫳" },
            { "p", "ping", "乒甹俜娉涄砯聠艵頩冯平评苹郱凭呯坪枰玶胓屏洴帡荓瓶蚲萍帲淜幈蓱蛢缾甁塀焩評鲆軿竮凴箳慿憑鮃檘簈屛岼" },
            { "p", "pin", "拚拼姘砏礗穦馪驞贫玭娦貧琕嫔频嬪薲蘋嚬矉颦顰品榀牝汖娉聘朩" },
            { "p", "po", "朴钋陂岥泊泼坡釙䥽颇酦頗潑醗醱鏺婆鄱蔢嘙皤繁櫇嚩叵尀钷笸鉕箥駊廹迫岶洦敀昢珀破砶烞粕湐蒪魄乶哛桲" },
            { "p", "pou", "剖娝抔抙捊垺掊裒箁咅哣婄犃" },
            { "p", "pu", "仆攵攴扑抪炇陠铺痡鋪噗撲潽鯆圤匍莆菩脯葡菐蒱蒲僕酺墣獛璞穙镤瞨濮贌鏷纀朴浦埔圃烳普圑溥谱暜諩樸擈氆檏镨譜蹼鐠堡舖舗暴瀑曝巬哛" },

            { "q", "qi", "七迉沏妻柒栖桤凄郪倛娸捿淒悽萋戚桼棲敧欺欹期攲紪缉傶僛嘁墄漆慽緀榿慼踦霋魌蹊鏚鶈丌亓祁齐圻忯芪岐岓奇其亝祈祇斉肵歧疧俟荠剘陭旂耆蚑蚔蚚脐斊竒颀畦軝跂釮埼萁萕帺骐骑猉崎掑淇棋棊祺蛴琪琦锜褀碕碁鬿頎愭﨑齊旗綥粸綦蜞蜝璂禥蕲錡鲯藄鄿濝懠檱櫀鳍騏騎臍鵸鶀鯕蘄麒鬐艩蠐騹鰭玂麡乞邔企芑岂屺杞玘盀启呇唘豈起啓啟啔婍绮棨晵綮綺稽諬闙气讫迄汔気汽芞弃矵呮泣炁亟盵契咠砌訖栔氣欫唭葺湆湇棄夡愒滊摖暣甈碶憇槭噐器憩碛磜磧磩藒蟿罊鐑嵜褄螧簯簱籏" },
            { "q", "qia", "掐袷葜擖拤卡峠酠跒鞐圶冾帢洽恰胢硈殎髂" },
            { "q", "qian", "千阡仟芊迁扦奷汘圱圲汧岍杄茾佥欦钎臤牵拪悭蚈铅谸釺婜牽孯掔谦鈆鉛鹐签愆僉嗛骞撁搴慳遷厱諐褰謙顅檶櫏攐攑簽鵮騫攓籖鬜鬝籤韆仱岒扲忴拑乹前荨钤钱钳虔歬軡乾偂掮揵亁媊葥鈐靬犍鉗銭墘榩箝蕁潜潛羬黔橬錢黚騝騚濳灊鰬浅肷淺遣膁蜸槏谴缱繾譴欠刋伣纤芡茜俔倩悓堑椠棈傔嵌皘蒨慊塹蔳綪歉篏儙槧篟輤縴壍嬱竏粁鎆鏲" },
            { "q", "qing", "靑青轻氢郬卿倾寈清淸埥圊氫軽傾蜻輕錆鲭鯖鑋夝甠剠勍啨情殑棾葝䞍氰晴暒䝼擏樈檠擎黥苘顷请頃庼廎漀請謦檾庆亲凊倩掅殸碃綮箐靘慶磬罄濪儬硘櫦" },
            { "q", "qie", "切癿伽茄聺且妾怯厒砌窃匧悏挈洯惬淁笡蛪趄愜慊朅锲箧篋踥鍥穕鯜竊" },
            { "q", "qin", "侵亲钦衾骎媇嵚欽綅嵰誛嶔親顉駸鮼寴芹芩庈肣矜秦蚙菦埐珡耹捦菳禽覃鈙鈫雂琴琹溱勤靲嫀嗪廑慬嶜擒噙鳹斳澿檎懄螓瘽懃蠄鵭坅昑笉赾梫寑锓寝寢鋟螼吣吢抋沁唚菣揿搇撳藽瀙" },
            { "q", "qiao", "悄郻硗雀跷鄡鄥勪踍敲毃锹劁骹頝墝墽燆橇幧缲磽鍫鍬繑繰趬蹺鐰乔侨荞荍峤桥菬硚喬翘僑谯槗墧憔蕉蕎嘺嫶鞒犞燋樵橋瞧癄礄翹譙趫櫵藮鐈鞽顦巧釥愀髜壳陗俏诮帩峭窍誚髚僺撬撽韒鞘鞩竅躈" },
            { "q", "qiang", "羌呛抢斨枪戗戕玱羗将猐啌跄腔溬嗴獇椌蜣锖锵羫槍牄瑲戧嶈摤篬謒镪蹌蹡鎗鏘強强蔷嫱墙樯蔃漒薔彊廧墻嬙檣牆艢蘠羟羥搶墏襁繈繦鏹炝唴嗆熗羻" },
            { "q", "qiu", "丘丠龟邱坵恘秋秌恷蚯媝湫萩楸湬蓲鹙蝵緧篍趥穐鳅鞦鞧蟗鶖鰌鰍蠤龝仇叴芁扏囚犰玌朹肍汓虬求虯泅俅訄訅酋觓釚唒莍逑逎浗紌毬球梂赇殏釻頄渞湭遒巯崷盚皳絿蛷煪裘觩巰賕蝤璆銶醔鼽鮂䲡鯄鰽搝糗蘒蘒" },
            { "q", "qu", "区曲匤阹佉伹诎驱岖岴屈抾坥浀胠祛袪蛆紶躯區焌煀詘趋筁蛐粬趍駆憈嶇敺駈誳麹魼髷麯趨軀覰麴鶌黢驅鰸鱋佢劬斪朐胊菃鸲絇翑渠淭葋軥蕖璖鴝磲螶蟝璩瞿鼩蘧忂灈戵爠臞氍欋籧癯蠷衢欔躣鑺蠼鸜苣取竘娶詓竬蝺龋齲去厺刞呿耝阒觑趣閴麮鼁闃覷覻衐" },
            { "q", "que", "炔缺缼蒛阙瘸芍却卻崅埆琷悫雀确硞棤阕塙搉鹊皵碏榷愨慤碻確趞闋燩闕礐鵲礭" },
            { "q", "qiong", "銎邛卭宆穷穹茕桏䓖筇笻赹惸焪焭琼蛩蛬舼跫睘煢熍瞏窮憌橩璚儝藑藭瓊竆瓗嬛" },
            { "q", "quan", "奍弮悛圈圏棬椦箞鐉全权卷诠佺姾荃峑洤恮泉牷辁拳铨痊硂惓埢婘啳葲湶絟筌犈瑔輇觠詮搼跧銓蜷権踡駩醛鳈鬈騡鰁巏權齤颧蠸顴犭犬犮畎烇绻綣虇劝券牶勧韏縓勸楾闎" },
            { "q", "qun", "夋囷逡帬宭峮裙群羣裠麇" },

            { "r", "rao", "荛娆饶桡嬈蕘橈襓饒扰隢擾绕遶繞" },
            { "r", "rang", "嚷穣勷儴蘘獽瀼禳瓤穰躟鬤壌壤攘爙让懹譲讓" },
            { "r", "ran", "呥肰衻袇袡蚦蚺然髥髯嘫燃繎冄冉苒姌染珃媣橪" },
            { "r", "re", "若喏惹热熱" },
            { "r", "reng", "扔仍辸礽芿陾艿" },
            { "r", "ren", "人亻仁壬朲忈任芢忎秂魜銋鵀忍荏荵栠栣秹稔躵刃刄认讱仞仭纫屻饪牣纴轫杒妊韧肕祍姙衽紉紝軔訒袵梕葚腍絍鈓飪靭靱韌餁認" },
            { "r", "rong", "戎肜栄茸荣茙狨绒毧峵容烿媶嵘搑傛絨羢搈溶嵤嫆蓉榵榕榮熔穁瑢縙镕褣蝾槦融螎駥嬫嶸爃鎔瀜曧蠑冗宂坈傇軵氄穃" },
            { "r", "ri", "日驲囸衵釰釼鈤馹乤乬乫乮乭乶乽乼乺挘艝鑓虄" },
            { "r", "rou", "厹禸柔粈脜葇媃揉渘楺瑈腬煣蝚糅輮蹂鍒鞣騥瓇鶔鰇韖肉宍譳" },
            { "r", "ru", "邚如侞帤茹挐桇铷袽渪筎蒘銣蝡蕠儒鴑鴽嚅薷濡孺嬬曘襦蠕颥醹顬鱬汝肗乳辱鄏擩入洳溽缛蓐嗕媷褥縟扖杁嶿" },
            { "r", "rui", "甤緌蕤桵蕊蕋橤繠蘂蘃壡芮汭枘蚋锐蜹瑞睿鋭銳叡" },
            { "r", "ruan", "堧撋壖阮软朊耎軟偄媆瑌腝碝緛輭瓀礝" },
            { "r", "run", "闰润閏閠潤橍膶" },
            { "r", "ruo", "挼捼叒若鄀偌弱婼渃焫楉蒻箬篛爇鰙鰯鶸嵶" },

            { "s", "sang", "丧桒桑喪槡嗓搡磉褬颡鎟顙" },
            { "s", "san", "三弎参叁毵毶厁毿犙鬖伞傘散糁馓糝糣糤繖鏒鏾饊俕閐壭" },
            { "s", "sai", "思毢愢揌塞腮毸嘥噻鳃顋鰓赛僿賽簺嗮" },
            { "s", "sa", "仨撒洒訯靸潵灑躠卅钑飒脎萨鈒馺摋蕯颯薩櫒扨苆乷栍隡虄" },
            { "s", "sao", "掻搔溞骚慅缫螦繅鳋颾騒騷鰠鱢扫掃嫂埽瘙燥氉臊矂髞乺" },
            { "s", "seng", "僧鬙" },
            { "s", "sen", "森椮槮襂" },
            { "s", "se", "閪色洓涩栜啬渋铯雭歮嗇瑟塞摵歰銫澁濇濏擌懎瘷穑璱澀瀒穡繬轖穯鏼譅飋縇鱪" },
            { "s", "sha", "杀杉沙纱刹砂殺莎唦猀粆紗挲铩桬痧硰摋煞蔱裟榝樧噎鲨魦閷髿鯊鯋鎩繺奢啥傻儍倽萐帹啑唼喢厦廈嗄歃翜翣箑閯霎" },
            { "s", "shai", "筛酾篩簁簛籭色晒曬" },
            { "s", "shang", "汤伤殇商觞禓傷蔏滳漡墒慯殤熵螪觴謪鬺上垧扄晌赏樉賞鋿鏛贘鑜丄尚尙恦绱緔鞝" },
            { "s", "shan", "山彡邖删刪芟杉钐衫苫姗姍狦挻舢珊栅柵脠痁扇軕掺笘釤傓跚剼搧煽幓嘇潸澘鯅縿膻檆羴羶闪陕陝炶閃晱睒煔熌覢讪汕疝单訕剡赸掸掞善椫禅銏骟鄯僐缮墠墡䦂䥇樿敾歚擅嬗禪膳磰赡謆繕蟮蟺鐥饍鳝騸贍譱灗鱓鱔圸" },
            { "s", "she", "奢猞赊畬畲畭輋賖賒檨舌佘折虵蛇阇揲蛥舍捨叶厍设社舎厙拾涉射赦設渉涻弽滠慑摄摂蔎慴歙蠂韘騇麝懾灄攝欇" },
            { "s", "shao", "莦弰捎烧梢稍焼萷旓蛸艄筲輎鞘燒髾鮹勺芍杓苕柖玿韶少邵卲劭绍袑哨娋紹睄綤潲蕱" },
            { "s", "shei", "谁" },
            { "s", "shen", "申扟屾伸身籶侁参诜冞罙呻妽绅柛氠穼珅姺籸娠峷莘眒甡砷深紳敒兟訷棯裑葠蓡罧詵糁甧蔘糂鲹駪薓燊曑鵢鯓鯵鰺什神甚鉮鰰邥弞沈矤审哂矧谂谉婶訠渖諗審頣魫曋瞫瀋嬸讅覾肾胂侺昚涁眘脤渗祳葚腎瘆慎愼椹蜃蜄滲鋠瘮堔榊籡" },
            { "s", "shou", "収收熟扌手守首垨艏寿受狩兽售授涭绶痩膄壽夀瘦綬獣獸鏉" },
            { "s", "shi", "尸失师呞邿诗鸤虱䴓狮施屍浉師絁釶葹湿湤溼溮蒒蓍鉇詩獅瑡酾鳲嘘鳾箷蝨褷鲺鍦濕鯴鰤鶳襹釃十饣什石时识实実旹飠食祏炻蚀拾姼峕埘莳時遈寔湜溡塒鉐實榯蝕鲥鼫鼭識鰣史矢乨豕使驶始屎宩兘笶鉂駛士氏礻示市世丗仕似卋忕式戺亊事侍势试呩饰视柹柿枾昰是贳恃恀眂峙拭冟室适逝眎眡铈舐轼烒栻秲釈視释貰弑谥徥揓崼嗜蒔勢弒軾筮睗觢試鈰鉃飾鉽誓舓適奭餝餙銴諡諟澨噬嬕遾螫謚簭釋襫乄辻佦竍嵵煶鮖籂鰘籡鱰" },
            { "s", "sheng", "升生阩呏声斘枡昇泩狌苼陞珄牲殅陹笙湦焺甥鉎鍟聲鼪鵿渑绳憴縄繉繩譝省眚偗渻圣胜晟晠乘剰盛貹剩勝嵊琞聖墭榺蕂賸竔曻﨡橳" },
            { "s", "shu", "书殳抒纾陎叔枢杸姝荼倏倐殊紓書焂梳鄃菽婌掓軗淑疏疎舒琡綀毹毺摅输跾踈蔬樞輸鮛橾儵攄鵨尗秫孰赎塾熟璹贖属暑暏黍鼠蜀数署潻薯薥曙癙藷襡襩屬术朮戍束沭述侸荗咰树怷竖恕捒庶庻蒁絉術裋尌鉥腧竪墅漱潄澍數豎錰霔濖樹鶐鏣虪瀭糬蠴" },
            { "s", "shua", "刷唰耍誜" },
            { "s", "shuang", "双泷爽霜雙骦孀孇騻欆鷞鹴礵艭驦鸘漺慡縔塽灀﨎鏯" },
            { "s", "shuan", "闩拴閂栓涮腨" },
            { "s", "shuai", "衰摔甩帅帥率蟀卛" },
            { "s", "shui", "谁脽誰氵水氺说帨涗涚祱税稅裞睡" },
            { "s", "shun", "楯吮顺順舜蕣橓瞚瞤瞬鬊" },
            { "s", "song", "忪松枀枩柗娀凇倯菘庺崧淞梥硹嵩濍憽檧鬆㧐怂悚耸竦愯楤傱嵷慫聳駷㩳讼宋诵送訟颂頌誦鎹餸" },
            { "s", "shuo", "说説說妁烁朔铄硕欶矟蒴搠獡槊碩箾鎙爍鑠" },
            { "s", "si", "厶纟丝司糹私泀咝俬思恖鸶虒偲缌媤蛳斯絲鉰楒禗飔凘厮禠蜤锶銯罳鋖緦磃澌嘶噝撕蕬廝燍螄鍶颸蟖蟴騦鐁鷥鼶死巳亖四似寺汜泤姒兕伺佀祀孠杫価驷饲泗洠娰俟枱柶牭食飤肂涘洍耜耛梩笥釲覗竢肆嗣貄鈶鈻飼榹禩駟蕼儩瀃厑唜旕鯐鶍" },
            { "s", "sou", "叟凁捜鄋搜蒐蓃廀廋嗖獀馊溲飕摉摗锼螋艘醙鎪餿颼騪叜傁嗾瞍擞薮藪櫢籔嗽瘶擻" },
            { "s", "su", "苏甦酥窣稣穌鯂蘓蘇櫯囌俗玊夙诉泝肃洬涑莤速珟素粛殐梀骕宿谡傃粟訴肅鹔愫塑塐遡嫊嗉溯溸缩遬蔌僳榡愬膆趚觫鋉餗碿樎樕憟潥潚縤簌謖藗橚璛蹜驌鷫鱐苆" },
            { "s", "suan", "狻痠酸匴祘笇筭蒜算" },
            { "s", "sui", "夊芕尿虽浽荾哸倠隋眭睢滖熣鞖濉雖绥随遂遀綏隨髄瓍膸瀡髓亗岁砕祟谇埣嵗煫歲歳碎睟粹隧澻穂嬘賥誶燧檖禭璲穗穟邃襚繀繐繸旞譢鐆鐩韢荽" },
            { "s", "sun", "孙狲荪孫飧飱猻搎蓀槂蕵薞笋损隼筍損榫箰簨鎨鶽潠" },
            { "s", "suo", "莎莏唆娑挱桫梭挲傞睃嗍蓑羧摍缩趖簑簔縮鮻所唢索琐惢锁嗩溑暛褨瑣璅鎖鎻鎍鏁逤溹蜶琑嗦鱛" },

            { "t", "ta", "他它她牠祂铊趿鉈溻塌榙禢褟踏溚塔墖獭鮙鳎獺鰨拓沓㳠挞闼狧粏崉涾傝嗒遝阘搨漯毾榻澾撻誻錔橽嚃鞜蹋濌鞳闒蹹闥嚺譶躢侤萙遢燵襨鶎鱩" },
            { "t", "tan", "坍贪怹痑啴舑貪滩摊嘽瘫潬擹攤灘癱坛昙郯倓谈弹婒埮惔覃锬痰榃谭潭憛墰墵談醈曇錟壇燂橝澹檀顃罈藫壜譚醰貚譠罎忐坦钽袒菼毯僋鉭嗿憳憻醓暺璮叹炭探湠嘆碳舕歎" },
            { "t", "tai", "台囼孡苔胎邰旲坮骀抬炱炲菭跆鲐颱臺箈駘鮐儓薹擡嬯檯籉呔太夳冭汏汰汱忲肽态钛舦泰酞鈦溙態燤" },
            { "t", "tao", "夲叨弢涛绦掏焘絛詜慆搯滔幍嫍槄瑫韬飸縚縧轁濤謟鞱韜饕迯匋洮逃咷陶桃梼萄淘绹啕祹裪蜪綯鞀鞉醄鋾駣騊饀鼗讨討套" },
            { "t", "tang", "汤铴湯嘡羰劏蝪趟薚镗蹚鏜鞺鼞坣唐堂棠啺鄌傏蓎隚搪溏塘煻榶漟禟瑭膅膛磄糃樘橖糖螗篖踼赯醣螳糛鎕餹饄闛鶶伖帑倘偒淌惝傥耥躺镋鎲儻戃爣曭矘钂烫摥燙鐋" },
            { "t", "te", "忑忒特铽慝鋱蟘朰扨脦罀" },
            { "t", "teng", "膯鼟疼痋幐腾誊漛滕邆駦螣縢謄䲢儯藤騰鰧籐籘虅驣霯" },
            { "t", "tiao", "旫佻庣挑恌祧聎芀条苕迢岧岹祒條调萔笤蓚蓨龆樤蜩鋚鲦鞗髫鯈鎥齠鰷宨晀朓脁窕誂窱斢嬥眺粜絩覜趒跳糶" },
            { "t", "tian", "天兲婖添酟靔黇靝田佃沺屇恬胋畋畑畠钿甜甛菾湉填塡嗔阗搷碵緂窴磌璳闐鷆鷏忝殄倎唺淟悿觍晪琠腆睓痶舔餂瑱賟覥錪掭舚鴫" },
            { "t", "ti", "体剔梯锑踢銻䴘擿鷉鷈厗荑绨偍媞崹提渧缇惿遆啼稊鹈罤题瑅綈嗁睼褆碮漽蕛徲緹醍趧蹄蹏鍗鳀謕鮷題鵜騠鶗鶙鯷禵鷤挮躰骵軆體戻屉洟剃俶倜逖涕悌惕屜掦逷啑笹悐惖替揥裼褅歒髰殢薙嚏鬀鬄瓋嚔籊趯" },
            { "t", "tie", "帖怗贴萜聑貼铁蛈鉄銕僣鐡鐵驖呫飻餮" },
            { "t", "tou", "偷偸媮婾鋀鍮亠头投骰頭妵紏敨黈蘣透" },
            { "t", "tu", "凸宊秃禿怢突涋捸湥堗葖痜嶀鋵鵚鼵図图凃荼徒途庩峹捈涂悇梌屠菟揬稌瘏筡鈯嵞塗蒤腯廜潳瑹酴跿圖圗馟駼鍎鵌鶟鷋鷵土圡吐钍唋釷兎迌兔莵堍鵵汢溌" },
            { "t", "tong", "恫炵通痌絧嗵蓪熥樋仝同彤佟侗庝峂峒峝哃狪茼垌烔晍桐浵砼蚒秱铜眮童粡赨詷酮鉖銅鉵餇鲖勭僮潼獞橦犝曈朣膧燑氃穜瞳鮦统捅桶統筒筩綂恸痛衕慟憅" },
            { "t", "ting", "厅庁汀町听耓烃厛烴桯綎鞓聴聼廰聽廳邒廷莛庭亭停葶婷嵉渟蜓筳楟榳閮霆蝏聤諪鼮圢甼侹娗挺涏烶梃珽脡铤艇颋誔鋌頲" },
            { "t", "tuan", "猯湍圕煓貒团団抟剸摶漙團慱槫篿檲鏄糰鷒鷻畽墥疃彖湪褖" },
            { "t", "tun", "吞呑旽涒焞朜噋暾屯坉囤忳芚蛌軘豚豘飩鲀魨黗霕臀臋氽褪饨" },
            { "t", "tui", "忒推蓷藬弚颓隤尵橔頹頺頽魋蘈穨蹪俀腿僓蹆骽侻退娧煺蜕蛻褪駾燵" },
            { "t", "tuo", "乇仛讬饦托扡汑杔佗侂咜咃沰拖拕说侻莌捝挩袥託飥涶脱脫馲魠鮵阤驮陁陀驼狏岮沱坨柁鸵砣砤袉紽詑酡跎堶馱碢槖駄駝駞橐鴕鮀鼧鵎騨鼍驒驝鼉彵妥庹椭楕嫷橢鰖拓柝毤萚唾跅毻箨嶞魄蘀籜鵇" },

            { "w", "wa", "屲凹穵劸洼哇挖娲窊畖窐媧啘嗗瓾蛙搲溛漥窪鼃韈攨娃瓦邷佤咓砙袜聉嗢腽膃襪韤瓸甅" },
            { "w", "wai", "咼歪㖞喎竵崴外顡" },
            { "w", "wei", "厃危委威烓隈隇偎逶喴葳葨媙崴嵔揻揋愄溦椳楲詴煨微蜲蝛覣縅薇燰鳂癓鰃鰄巍霺囗为韦圩围囲闱违帏沩洈峗峞為韋桅涠帷唯维惟琟嵬媁圍喡幃違湋溈爲維潍鄬蓶潿潙醀鍏闈鮠濰壝矀覹犩欈伟伪苇芛尾纬炜玮洧浘娓荱诿隗偽偉萎崣梶痏硊骩骫骪愇猥渨蒍葦徫廆椲暐煒艉痿瑋韪腲鲔撱嶉僞寪蔿頠緯諉踓韑薳儰濻鍡鮪颹韙瀢韡亹斖卫未位苿味胃畏軎叞菋谓硙尉遗喂媦猬渭煟蔚碨蜼蝟磑犚慰緭熭衛衞餧鮇懀謂罻螱褽魏餵轊藯鏏鳚霨蘶饖讆躗躛讏捤墛嶶" },
            { "w", "wang", "尢尣尪汪尫尩亾兦亡王仼莣蚟罓罒网彺往徃罔枉惘菵辋棢暀蛧蝄網輞誷魍瀇妄迋忘旺徍望朢" },
            { "w", "wen", "昷温溫辒殟榅瑥瘟榲緼蕰豱輼轀鳁鞰鰛鰮文芠彣纹炆闻蚊蚉紋阌珳雯駇馼聞瘒鳼鴍魰螡閿閺闅蟁鼤繧闦刎伆吻呅抆呡肳紊桽脗稳穏穩问妏免汶莬問渂揾搵絻顐璺塭鎾饂" },
            { "w", "wan", "涴弯剜帵婠湾塆睕蜿豌潫彎壪灣丸刓芄汍纨完岏抏玩紈捖顽貦烷頑翫宛倇莞挽盌唍绾埦惋梚菀萖婉脘晚晥晩晼琬皖椀碗畹綰綩輓踠鋔万卐卍忨妧捥脕腕萬蔓輐澫鋄錽薍瞣蟃贃鎫贎乛杤笂琓" },
            { "w", "weng", "翁嗡滃鹟螉聬鎓鶲勜奣嵡蓊塕暡瞈攚瓮蕹甕罋齆" },
            { "w", "wo", "挝涡倭莴萵唩猧渦涹窝喔窩蜗蝸踒我婑婐捰仴沃肟枂卧臥捾涴偓幄媉渥握焥硪楃腛斡瞃龌臒瓁濣齷遤" },
            { "w", "wu", "兀乌邬弙污汙汚圬呜巫杇於屋洿诬钨恶烏剭窏鄔嗚誈誣歍箼螐鴮鎢鰞亡无毋芜吾吴吳呉郚茣莁唔娪峿浯洖梧祦珸铻鹀無蜈鋙蕪墲橆璑鵐蟱鯃譕鼯鷡五午伍仵迕妩庑怃忤玝武侮倵逜陚捂娒娬牾啎珷鹉碔摀熓瑦舞憮潕廡嫵儛甒瞴鵡躌兀勿阢务戊扤屼岉芴坞杌物忢旿矹卼敄俉误務悟悮悞粅晤焐痦婺隖骛嵍靰雾雺嵨奦溩塢鹜熃寤誤鋈窹霚鼿齀霧騖蘁鶩厼朰鯲" },

            { "x", "xi", "夕兮邜吸汐忚西扸希卥析昔穸肸肹矽怸饻恓郗茜俙徆莃奚娭唏浠狶悕屖栖牺氥息悉硒琋赥釸欷晞桸惜烯焁焈淅渓唽菥傒鄎焟焬犀晰晳翕翖舾粞稀睎惁腊锡皙裼煕厀徯蒠溪嵠僖熙熈熄榽蜥緆餏覡豨瘜磎膝潝嘻噏嬉嬆凞樨橀暿歙熺熻熹螅螇窸羲錫貕蹊豯蟋谿豀瞦燨犠巂繥糦鵗譆醯觹鏭鐊隵酅巇嚱犧曦爔饎觽鼷鸂蠵觿鑴习郋席觋習袭喺媳蓆蒵椺嶍漝趘槢褶薂隰檄謵鎴鳛霫飁騱騽鰼襲驨洗枲玺铣徙喜葸葈鈢鉨鉩蓰漇屣憘歖禧憙諰謑縰壐蟢蹝璽鱚矖囍躧匸卌戏饩屃系呬细郄怬忥盻恄郤係咥屓绤欯阋細釳趇舄舃塈隙椞禊慀隟綌赩熂墍犔稧潟澙戯蕮覤縘黖戱戲磶虩餼鬩繫闟霼衋屭巪凩巼夞莻唟裃硳喸聢噺橲礂鯐" },
            { "x", "xia", "呷虾谺閕傄颬煆瞎蝦鰕匣狎侠俠狭陜峡炠柙烚峽埉狹祫珨硖翈舺陿假葭硤遐筪瑕舝敮暇辖碬磍蕸縖赮魻霞鍜轄鎋黠騢鶷閜丅下吓疜夏唬厦睱諕懗罅夓鎼鏬圷梺" },
            { "x", "xian", "仚仙屳纤先奾忺佡氙杴秈苮祆枮籼莶珗掀铦锨酰跹僊僲銛鲜嘕韯銽暹薟憸嬐鍁韱鮮褼繊蹮馦孅攕廯纎鶱躚襳纖鱻闲伭弦咁妶贤胘涎盷咸挦娴娹婱蚿絃衔舷閑閒蛝鹇痫湺啣嗛嫌甉銜誸賢羬稴澖憪嫻嫺撏諴醎輱癇癎瞯藖礥鹹麙贒鷼鷳鷴冼狝险洗显烍毨蚬崄険猃赻铣筅蜆跣禒搟尠尟銑箲險獫嶮獮藓鍌燹顕幰攇蘚櫶譣玁韅顯灦见县苋岘限现线臽県陥宪姭娊峴陷莧哯涀垷埳現晛馅羡缐睍絤腺粯塪献羨僩僴誢綫線鋧撊憲橺橌錎餡縣豏壏麲臔瀗獻糮霰鼸咞衘鑦" },
            { "x", "xiang", "乡芗相香郷鄉鄊厢廂湘缃鄕葙萫薌箱緗膷襄麘忀骧欀瓖镶纕鑲驤瓨降佭详庠栙祥絴翔詳跭享亯响饷蚃晑飨想銄餉鲞鮝蠁鯗響饗饟鱶⺈向姠巷项珦象項缿衖勨像嶑橡曏襐蟓嚮鐌鱌" },
            { "x", "xiao", "灱灲肖枭呺哓削侾骁枵绡庨烋宵宯逍消鸮虓婋猇萧梟焇销痚痟翛硝硣窙蛸綃揱箫嘐潇踃歊銷霄獢撨嘵憢膮蕭彇颵魈鴞鴵簘蟏蟂藃穘嚣瀟蟰簫髇櫹囂嚻髐鷍驍蠨毊虈洨郩崤淆訤殽誵小晓暁筱筿皛篠謏曉皢孝効恔咲哮涍俲笑校效啸傚敩詨誟嘨嘋嘯熽歗斆斅﨧" },
            { "x", "xing", "兴狌星垶骍猩惺煋瑆腥觪篂箵鮏興觲騂曐皨鯹刑邢饧行陉形侀郉陘荥洐型钘娙铏硎鈃蛵滎銒鉶鋞餳省睲醒擤杏性幸姓荇莕倖婞悻涬葕緈﨨嬹臖哘謃" },
            { "x", "xin", "忄心邤䜣辛芯妡忻炘杺欣昕盺莘俽惞訢鈊锌歆新廞鋅噷嬜薪馨鑫馫枔镡襑鐔伈阠伩囟孞信軐訫脪衅焮馸顖舋釁" },
            { "x", "xie", "些娎猲揳楔歇蝎蠍叶邪劦协旪胁協奊垥恊峫挟拹挾脇脋脅衺斜谐偕絜翓綊瑎愶嗋携熁膎鲑鞋蝢緳缬撷擕縀勰諧燲嚡擷鞵襭攜孈讗龤写血冩寫藛伳灺绁泄泻祄缷洩炧炨契卸卨屑烲禼徢偰偞焎紲械絏絬亵谢屟媟渫塮僁解靾榭榍褉暬緤噧屧獬嶰澥懈廨邂薤薢糏韰謝褻燮夑瀉鞢齘繲蟹蠏瀣爕齛齥纈齂躞" },
            { "x", "xiong", "匂凶兄兇匈讻芎忷汹洶恟哅胸胷訩詾賯雄熊熋焸焽诇詗夐敻楿" },
            { "x", "xu", "吁圩戌盱疞砉欨胥须顼訏許裇虚虗偦谞媭揟湑欻虛須綇楈需魆墟嘘噓蕦嬃歔縃緰蝑諝歘燸譃魖繻驉鬚鑐俆徐冔禑蒣许诩呴姁浒栩珝喣暊詡稰鄦糈諿醑盨旭旴伵芧序汿侐卹怴沀恤昫叙洫晇殈烅珬垿欰畜酗烼绪续敍敘勖勗溆婿壻聓訹絮朂続賉頊滀蓄慉煦槒漵潊銊聟緒盢瞁稸魣緖獝藇藚續鱮﨏蓿" },
            { "x", "xiu", "休俢修庥咻脩烌羞脙鸺臹貅馐髤銝樇髹鵂鎀鏅饈鱃飍苬朽宿滫潃糔秀岫峀绣珛袖臭琇锈綉溴嗅璓褏褎銹螑繍嚊繡鏥鏽齅鮴" },
            { "x", "xue", "削疶蒆靴薛辥辪鞾穴斈乴茓峃学泶鸴袕踅學嶨壆噱燢澩觷鷽彐雪鳕鱈吷狘岤坹桖谑趐謔瞲瀥樰膤轌" },
            { "x", "xuan", "吅轩昍宣弲晅軒梋谖萱萲喧媗揎塇愃愋煖煊蓒暄瑄睻蝖禤箮翧儇鋗鞙蕿嬛懁諠諼駽鍹翾蠉矎蘐藼譞玄县玹痃悬琁旋蜁嫙漩璇暶檈璿懸咺选烜選癣癬券泫怰炫昡绚眩铉袨琄眴衒渲絢楦楥鉉碹蔙镟颴縼繏鏇贙" },
            { "x", "xun", "坃勋荤埙焄勛塤熏窨勲勳薫薰壎獯曛臐燻蘍矄纁爋壦醺廵巡寻旬杊郇询畃荨荀浔洵峋恂紃珣栒桪毥偱循尋揗詢鲟鄩噚潭潯駨璕攳燖燅樳蟳鱏鱘灥卂讯训迅伨驯汛侚狥逊迿巺徇殉訊訓訙浚奞殾巽稄馴遜愻蕈噀顨鑂嚑" },

            { "y", "ya", "ㄚ丫圧吖压厌呀庘押枒鸦哑鸭桠孲铔雅椏鴉鴨錏壓鵶鐚牙伢芽岈厓玡琊蚜笌堐猚崖崕涯釾睚衙漄齖疋厊庌疨唖啞痖瘂蕥劜圠轧覀襾冴亚讶迓亜犽亞軋砑挜娅垭俹氩掗訝埡婭猰聐揠氬稏圔窫齾鯲鑓軈" },
            { "y", "yan", "咽恹烟殷珚胭焉淹淊阏阉崦湮腌硽煙歅鄢傿嫣漹嶖醃閹燕懨嬮篶懕臙黫讠延闫妍芫严阽言訁郔岩沿炎炏昖狿埏莚姸娫研铅盐娮阎啱琂硏訮閆蜒綖筵嵒嵓喦塩揅楌詽碞蔅颜虤閻厳檐顔顏簷壛巌嚴櫩巖巗壧鹽礹麣夵抁沇奄乵兖兗匽弇俨衍剡眼酓偃掩郾厣萒遃隒嵃揜渰渷扊棪愝晻琰罨裺椼演嵼褗蝘魇戭噞躽縯黡檿厴黤甗鶠鰋龑黭黬儼孍顩鼴鼹魘巘巚曮齴黶厌妟觃牪砚姲彦彥烻唁验宴艳晏覎偐谚隁焔焰焱堰喭雁敥猒硯椻鳫滟溎墕熖厭酽暥鴈谳嬊餍燄赝鬳諺鴳曕嚈酀騐験䜩艶贋嚥嬿爓曣騴醶齞鷃贗灔囐鷰驗醼讌觾饜艷釅驠灎灧讞豓豔灩䶮剦樮軅" },
            { "y", "yao", "幺夭吆约妖殀祅要訞喓葽楆腰鴁鴢徼邀爻尧尭肴侥荛姚峣轺垚烑陶倄珧窑铫堯揺傜谣軺滧徭遥遙嗂媱猺摇搖愮摿榣暚飖瑶瑤餆窯窰磘嶢嶤餚繇謡謠鎐鳐颻蘨邎顤鰩鱙仸宎岆抭杳枖狕苭咬柼眑窅窈舀偠婹崾溔蓔榚闄騕齩鷕疟穾药钥袎窔葯筄詏靿覞熎鹞獟鼼薬藥燿曜艞矅耀纅鷂讑" },
            { "y", "yang", "央姎抰泱殃胦秧眏鸯鉠雵鞅鴦鍈阳阦扬羊⺶飏炀杨旸钖疡氜劷佯徉洋垟昜羏珜烊陽眻蛘揚崵崸煬楊敭瑒暘瘍輰諹鍚鴹颺鰑霷鸉卬仰佒咉岟坱炴柍养氧痒紻軮楧傟慃氱飬蝆養駚懩攁瀁癢怏恙样羕詇漾様樣礢" },
            { "y", "ye", "吔耶倻掖椰暍歋潱噎擨蠮邪爷捓揶铘爺瑘鋣鎁ㄝ也冶野埜嘢漜壄业叶曳页曵邺抴夜枼拽亱咽頁捙枽烨晔液谒葉腋殗業煠馌墷璍僷燁曅曄皣瞱擛鄴靥餣謁嶪嶫澲擫瞸曗鍱鎑饁擪礏爗鵺鐷靨驜鸈丆亪" },
            { "y", "yi", "一弌衤伊衣医吚壱依祎洢咿郼渏悘铱猗蛜壹揖椅禕漪稦銥嫛嬄撎夁噫瑿鹥繄檥檹醫毉黟譩鷖黳乁义匜仪夷圯宐诒冝杝沂沶侇迤宜狋怡饴拸姨恞贻峓迻荑瓵珆咦訑貤胰栘桋巸眙袘宧扅萓蛇痍移椬蛦貽詒羠遗媐颐飴頉誃跠椸暆疑熪遺儀彛彜嶬螔頤頥顊鴺鮧簃嶷寲彝彞謻鏔籎觺讉乙已以迆钇攺矣苡佁尾苢迱庡舣蚁釔笖酏扆逘倚偯旑崺鈘鉯鳦裿蛾旖踦輢螘敼嬟礒蟻艤顗轙齮乂亿弋刈艺忆艾阣仡议肊伇芅亦异忔屹抑坄呓劮役苅佚译耴杙邑枍炈易衪秇诣佾呹呭驿泆怿怈绎峄浂帟帠俋弈奕疫羿昳玴轶枻食栧欭袣益谊唈浥浳挹悒垼埸埶逸勚萟殹翊翌悥豙豛異訲訳隿釴羛鈠軼骮跇詍晹敡殔棭焲蛡鄓湙幆嗌溢缢兿義亄睪獈竩痬意詣肄裔裛駅榏瘗膉蜴蓺勩廙嫕潩億鹝鹢毅镒瘞槸熠熤熼篒誼黓艗燚曀殪瘱瞖穓螠褹縊劓薏澺嬑嶧墿圛懌憶寱翳翼臆斁歝曎燡燱檍賹貖鮨鎰贀镱癔藝藙繹繶豷霬鯣鶂鶃饐醷醳譯議蘙瀷囈鐿鷊鷁懿襼鷧驛鷾鸃虉齸讛辷匇凧弬夞畩鶍鶎" },
            { "y", "yin", "囙因阴阥侌茵骃姻洇垔音栶氤殷陰隂陻凐秵铟裀絪筃堙愔喑婣溵蔭蒑禋慇瘖銦鞇磤緸諲霒駰霠闉噾濦齗韾冘乑吟犾圻烎斦泿垠圁狺峾荶珢訚訔訡银淫寅婬崟崯鈝龂滛碒鄞蔩夤銀龈誾璌殥噖嚚蟫檭霪齦鷣廴引尹饮吲蚓隐赺鈏飲淾隠飮靷輑朄趛瘾檃隱嶾濥螾檼蘟櫽癮讔印茚荫洕胤垽堷湚猌廕䲟窨酳癊慭憖憗鮣懚岃粌" },
            { "y", "ying", "应応英莺珱偀渶绬婴媖瑛煐朠锳碤嫈嘤缨撄甇緓蝧罂賏樱璎鹦噟霙罃褮鴬韺嬰膺應鹰甖鶑鶧罌譍孆嚶攖蘡孾瀴櫻瓔礯譻鶯鑍鷪蠳纓鷹鸎鸚迎盁茔荥荧盈莹萤营萦蛍営萾溁溋滢蓥塋楹僌颖熒蝇潆蝿禜瑩螢營嬴縈覮謍赢濙濚濴藀瀅蠅鎣巆攍瀛瀯瀠贏櫿灐籝灜籯郢矨浧梬颍颕摬影潁穎瘿頴鐛廮巊癭映暎硬媵膡鱦栍桜愥闏" },
            { "y", "yo", "育哟唷喲罀" },
            { "y", "yong", "佣拥邕痈庸傭嗈鄘雍嫞滽墉慵牅壅澭擁噰镛郺臃癕雝鳙鏞灉廱饔鷛鱅癰喁颙顒鰫永甬咏泳勇勈俑栐柡悀涌埇恿惥愑湧詠硧蛹塎嵱彮愹慂踊鲬踴鯒用苚蒏醟怺砽" },
            { "y", "you", "优忧攸怮呦泑幽峳浟逌悠麀羪滺憂鄾優瀀嚘懮櫌耰纋尢尤由甴沋邮犹油怞肬怣疣柚庮郵莜莸秞铀蚰訧偤逰遊猶游鱿鲉鈾楢猷輏駀魷蝤蝣蕕鮋輶繇友有酉丣卣苃羑莠栯梄铕聈湵蜏禉銪槱牖牗黝又右幼佑侑狖峟囿牰祐迶哊宥姷诱唀蚴亴釉貁酭誘褎鼬櫾孧" },
            { "y", "yue", "曰曱约約箹矱哕噦月乐戉刖妜岄抈礿玥泧岳说恱栎钥钺蚏蚎阅軏悦悅捳跃跀鈅越粤粵鉞閲閱篗樾嬳嶽龠籆蘥瀹黦躍爚禴籥鑰鸑籰鸙" },
            { "y", "yuan", "囦肙鸢剈冤鸳眢寃涴渊渁渆渕淵葾惌蒬棩鹓裷蜎箢鳶駌蜵鴛鵷嬽灁鼘鼝元円邧贠沅园芫员茒杬垣爰貟笎蚖袁圆原員厡媛猨援圎湲鼋缘鈨源溒園圓塬猿嫄媴蒝辕榞榬緣魭縁褤蝯蝝螈黿羱薗橼圜轅謜鎱櫞邍騵鶢鶰厵远盶逺遠鋺夗苑妴院怨衏垸傆掾禐瑗愿裫褑噮願" },
            { "y", "yu", "込迂迃吁扝扜纡於穻陓紆盓菸淤唹瘀箊与于亐予邘伃余妤扵杅欤玙玗盂衧臾鱼舁竽虶禺茰俞兪谀娱娛娯馀狳桙酑雩魚渔萸隅隃萮渝湡揄堣堬嵎嵛崳逾喁楰愉腴畬骬虞艅觎愚瑜歈榆楡牏舆窬睮褕漁蕍蝓歶雓餘諛羭踰覦嬩澞璵歟螸輿鍝謣髃鮽騟籅旟轝蘛鰅㧐鷠鸆齵屿宇伛羽妪雨俣俁语挧禹圄祤圉敔匬鄅偊庾萭斞铻瘐楀與瑀傴寙語窳頨龉貐懙噳嶼斔穥麌齬肀驭玉聿芋芌圫饫汩忬谷欥育郁茟狱秗昱浴峪彧俼预钰砡粖袬谕逳菀尉阈淯淢惐悆欲域堉棫棛棜琙焴寓媀喻喅喩庽御遇馭飫粥鹆硲硢矞裕鈺誉罭預蓣蒮煜滪愈稢戫蔚僪隩嶎獄嫗緎蜮蜟毓瘉銉輍豫鋊鳿遹薁蓹熨潏稶慾澦燠燏蕷鴥鴪鴧錥諭閾礇禦鹬魊儥鵒礜癒醧篽饇櫲蘌霱譽鐭雤鬻驈欎鷸鱊籞鸒欝龥鬰鬱籲灪爩䲣礖軉" },
            { "y", "yun", "晕蒀缊蒕煴氲氳熅奫蝹赟馧贇匀勻云伝芸员妘沄纭囩昀秐眃畇郧涢耺耘紜雲鄖蒷溳愪筠筼熉澐蕓鋆篔縜橒允阭狁抎夽陨荺殒隕喗鈗馻殞磒賱霣齫齳孕运郓枟恽酝鄆傊運愠惲慍暈韫腪韵褞熨蕴薀縕醖醞餫韞韗藴蘊韻抣" },

            { "z", "za", "帀扎匝沞咂拶桚鉔魳臜臢杂沯砸韴雑襍雜囃囋雥咋乽橴" },
            { "z", "zan", "兂糌橵篸簪簮鵤鐟鐕咱偺喒拶昝寁揝撍噆儧攅攒儹攢趱趲暂暫賛赞錾鄼酂濽蹔鏨贊瓉瓒酇囋灒讃瓚禶襸讚饡" },
            { "z", "zao", "傮遭糟醩蹧凿鑿早枣蚤棗澡璪薻藻灶皂皁造唣唕梍慥煰喿艁簉噪燥竃竈譟趮躁栆" },
            { "z", "zang", "匨赃牂脏羘賍賘臧贓髒贜驵駔奘弉塟葬蔵銺藏臓臟欌" },
            { "z", "zai", "灾災甾哉烖栽渽溨睵賳仔宰载崽再扗在洅傤載酨儎縡岾" },
            { "z", "ze", "则沢泽泎责迮咋择則帻啧啫舴笮責矠滜溭箦嘖嫧幘蔶赜樍歵諎擇瞔皟簀賾礋襗謮蠌齚齰鸅仄庂汄昃昗侧捑崱択硳" },
            { "z", "zeng", "曽曾増鄫缯增憎橧璔磳矰罾繒譄综锃鋥赠熷甑鬵贈囎" },
            { "z", "zen", "怎谮譖" },
            { "z", "zei", "贼戝賊鲗蠈鰂鱡" },
            { "z", "zha", "扎吒咋抯挓查柤奓紥哳偧紮渣溠喳猹揸楂劄摣皶觰樝皻譇齄齇轧札闸炸铡蚻喋牐閘箚耫鍘譗厏苲拃眨砟鲊鲝鮓鮺乍诈灹咤栅柞痄宱蚱詐搾槎榨蜡霅醡蓙" },
            { "z", "zhai", "侧夈捚斋斎摘榸齋宅择翟檡窄鉙责柴债砦祭債寨粂瘵" },
            { "z", "zhan", "占沾枬毡旃栴蛅粘飦趈詀惉詹閚谵薝邅噡嶦霑氊氈瞻鹯旜譫饘鳣魙驙鸇鱣讝斩飐盏展崭斬琖盞搌辗嶄嶃榐颭醆嫸橏輾黵佔战栈桟站绽偡菚湛棧戦綻輚嶘戰虥虦襢覱轏譧驏蘸" },
            { "z", "zhao", "佋钊妱招巶昭釗着啁朝鉊鼌駋嘲鍣皽爫爪找沼瑵召兆诏枛炤狣垗赵笊肁棹旐詔罩照肇肈箌趙曌燳鮡瞾櫂羄罀" },
            { "z", "zhang", "仉张張章鄣傽蔁遧粻嫜獐彰漳慞樟暲璋餦蟑騿麞鱆长涨掌漲礃丈仗扙帐杖胀账涱帳脹障痮幛嶂墇賬瘴瘬瞕粀幥鏱" },
            { "z", "zhe", "折蜇遮嗻嫬螫厇歽矺砓虴籷袩埑哲啠辄晢晣悊喆詟蛰谪摺輒輙銸磔辙蟄鮿謫謺嚞轍讁讋者锗褚赭踷鍺褶襵这柘這浙淛蔗樜鹧蟅鷓粍" },
            { "z", "zhei", "这" },
            { "z", "zhong", "中伀汷彸刣忪妐炂忠泈终钟柊盅衳舯衷終鈡蜙锺幒蔠銿鴤螤螽鍾鼨蹱鐘籦肿种冢喠尰煄腫歱塚種瘇徸踵众仲妕狆祌衶重茽蚛眾偅堹媑筗衆諥" },
            { "z", "zheng", "丁正争佂诤征姃怔爭糽埩炡政挣狰峥烝脀钲眐症聇睁铮掙崝崢猙揁媜筝踭鉦睜徰蒸錚箏篜鲭鬇癥鏳氶抍拯掟晸愸撜整证郑䦶証幁塣諍靕鄭䦛鴊證" },
            { "z", "zhi", "之氏支只卮汁芝汦汥吱巵知肢泜织枝栀祗胝胑秓衼疷隻脂祬栺倁梔椥臸綕禔稙搘馶蜘榰憄鳷鴲織鼅蘵执侄妷直姪值値聀釞职淔埴執殖戠植犆禃跖絷瓡馽摭潪嬂漐慹踯膱樴縶蹢蹠職蟙軄躑夂止阯劧旨帋芷扺沚纸址坁坧抧茋祉秖恉轵枳砋衹咫指洔淽茝紙疻訨趾黹軹酯徴墌徵藢襧芖至豸扻伿识忮志炙质治垁郅迣厔制帜帙挃庢庤陟峙洷栉柣祑挚桎晊歭秩贽轾徏娡狾致袟紩畤窒痔痓铚鸷貭翐觗袠猘徝掷乿剬偫秷梽智滞崻傂骘痣彘蛭置锧跱輊筫雉寘搱廌滍稚滯墆銍製覟誌瘈疐觯踬質鋕熫稺膣摯摨幟擳隲璏旘瀄鴙駤緻螲懥櫛穉儨劕擿擲懫贄觶騭鯯櫍瓆豑礩騺驇鷙躓鑕豒俧潌" },
            { "z", "zhou", "州舟诌侜周洲诪炿烐珘调郮辀婤淍啁週徟鸼矪粥喌赒輈銂輖賙霌鵃謅盩嚋騆譸妯轴軸肘疛帚菷晭睭箒鯞纣伷㑇咒呪绉宙㤘冑祝昼咮荮紂胄皱酎粙舳晝葤詋㑳㥮甃僽駎皺縐噣骤繇籀籕籒驟碡駲" },
            { "z", "zhua", "抓挝撾檛膼簻髽爪" },
            { "z", "zhu", "朱邾侏诛茱洙诸珠株猪秼铢硃袾蛛絑誅跦銖槠蝫潴蕏橥諸豬駯鴸鮢鼄藸瀦鯺櫫櫧蠩术竹⺮竺笁柚茿炢烛逐窋笜逫蓫瘃篴燭蠋躅鱁劚孎灟爥斸欘曯蠾钃丶主劯宔拄柱罜陼帾渚煮煑属詝褚濐嘱燝麈瞩囑鸀矚宁伫住佇芧苎助纻坾贮驻迬杼拀注祝柷炷殶壴莇祩竚眝疰砫蛀紵紸著庶羜铸筑貯軴註跓嵀鉒筯飳馵箸翥樦鋳駐麆築篫簗鑄墸" },
            { "z", "zhen", "贞针侦帧浈胗珍珎貞針祯桢真眞砧帪偵酙葴幀寊湞遉斟溱嫃獉搸蓁蒖甄椹楨禎鉁禛瑧榛碪殝潧箴臻樼澵薽錱轃鍼籈鱵诊枕抮轸昣弫姫屒眕疹畛袗聄紾裖軫覙診缜駗稹縝縥辴鬒黰阵圳纼甽鸩陣侲挋振栚朕紖眹赈塦揕絼賑誫镇震鴆鎭鎮鋴" },
            { "z", "zhuai", "拽转跩" },
            { "z", "zhui", "隹追骓椎锥錐騅鵻沝坠笍娷缀缒甀腏惴畷膇硾墜綴赘縋諈醊錣礈贅鑆" },
            { "z", "zhuang", "庄妆妝庒荘莊娤桩梉粧装湷裝樁糚奘壮壯状狀壵焋僮幢撞戆" },
            { "z", "zhuan", "专叀専砖䏝專鄟嫥塼甎瑼膞磗颛磚諯顓蟤鱄转孨竱轉传沌灷啭転堟蒃瑑腞赚僎馔撰篆篹襈縳賺譔饌籑囀" },
            { "z", "zhun", "屯迍宒肫窀谆啍諄衠准埻凖準綧訰稕" },
            { "z", "zhuo", "拙炪捉倬桌棁梲涿棳焯槕䦃穛擢鐯穱彴犳汋圴灼妰卓叕茁浊斫烵浞诼丵酌娺啄啅着椓晫斮斱琢琸硺罬窡禚斲撯擆劅諑諁鋜篧缴濁濯斵斀謶镯櫡鵫躅蠗灂鐲鷟籗蠿籱窧" },
            { "z", "zou", "邹驺陬郰诹菆掫棷棸鄒緅箃諏鲰鄹黀鯫騶齱齺赱走奏揍" },
            { "z", "zong", "宗枞倧骔综堫惾腙葼猣嵏嵕棕椶朡稯嵸潈綜緃翪踪踨緵熧蝬磫繌鍐鬃騌蹤騣鯮鬉鬷鯼鑁总倊偬捴揔搃惣焧傯蓗摠総縂緫燪總纵昮疭猔碂粽糉瘲縦縱豵糭" },
            { "z", "zi", "仔孖孜吱甾茊茲兹姿姕咨赀资玆栥紎赼缁秶崰淄谘菑葘鄑滋湽嵫椔粢辎嗞孳孶锱禌趑觜訾資貲緇緕龇鈭稵镃輜鼒鲻髭輺錙諮趦澬鍿鎡頾頿齍鶅鯔鰦纃齜蓻子吇杍姊姉胏秄矷虸耔籽秭呰茈笫釨梓啙紫滓訿榟字芓自荢茡剚倳牸恣眦眥渍胾胔漬嗭魸鯑" },
            { "z", "zu", "苴租菹葅蒩卆足⻊卒哫崒崪族椊箤踤镞鏃阻诅组祖珇爼俎唨組詛靻鼡乼" },
            { "z", "zun", "尊嶟遵樽罇繜鐏鳟鷷鱒僔噂撙譐捘銌" },
            { "z", "zui", "咀厜脧嗺樶蟕纗觜嶊嘴噿璻栬冣絊酔晬祽最稡罪辠酻槜醉蕞嶵鋷錊檇檌" },
            { "z", "zuan", "钻鉆劗鑚躜躦鑽篹繤缵纂纉纘籫赚攥" },
            { "z", "zuo", "作嘬穝昨莋秨笮捽琢筰鈼稓左佐撮繓阼坐怍岞岝侳祚胙袏座唑做葃葄飵糳咗" }
        };


        /// <summary>
        /// 自动切分 姓、名
        /// </summary>
        /// <remarks>
        /// 1. 基本只能应对普通的复姓（两个字），如果在复姓表中没有找到，则: 姓氏 = fullName的第一个字符<br/>
        /// 2. 备注：百度的姓氏基本就70多个，这里有90个，但是忽略的少数民族的姓氏，也不要认为复姓就是两个字，(《中国少数民族姓氏》汇总大概有1万多)<br/>
        /// 例如：乌拉乌拉氏、爱新觉罗、钮钴禄、色氏、尼玛（我见过很多姓这个的）
        /// </remarks>
        /// <param name="inFullName">全名</param>
        /// <param name="outLastName">姓</param>
        /// <param name="outFirstName">名</param>
        public static void FullNameSplit(string inFullName, out string outLastName, out string outFirstName)
        {
            //如果有非汉字字符，直接返回
            for (int i = 0; i < inFullName.Length; i++)
            {
                if (!IsHanziChar(inFullName[i]))
                {
                    throw new ArgumentException("包含非中文字符");
                }
            }

            outLastName = "";
            outFirstName = "";

            if (string.IsNullOrEmpty(inFullName))
            {
            }
            else if (inFullName.Length == 1)
            {
                outFirstName = inFullName;
            }
            else if (inFullName.Length == 2)
            {
                outLastName = inFullName.Substring(0, 1);
                outFirstName = inFullName.Substring(1);
            }
            else
            {
                string guessLastName = inFullName.Substring(0, 2);
                for (int i = 0; i < doubleLastNameLength; i++)
                {
                    if (guessLastName == doubleLastName[i])
                    {
                        outLastName = doubleLastName[i];
                        outFirstName = inFullName.Substring(2);
                        break;
                    }
                }

                if (outLastName == "")
                {
                    //鉴于起名的趋势四字姓名逐渐常见，并不认为是复姓。
                    /*if (inFullName.Length == 4)
                    {
                        outLastName = inFullName.Substring(0, 2);
                        outFirstName = inFullName.Substring(2);
                    }
                    else*/
                    {
                        outLastName = inFullName.Substring(0, 1);
                        outFirstName = inFullName.Substring(1);
                    }
                }
            }

        }


        /// <summary>
        /// 【姓/名】单独转拼音，可使用<see cref="FullNameSplit"/>分割姓名
        /// </summary>
        /// <remarks>
        /// 使用了：姓氏特殊读音字库 + 多音字常用读音字库 + 全字库
        /// </remarks>
        /// <param name="inStr">姓或名</param>
        /// <param name="isLastName">姓/名标记</param>
        /// <returns>对应姓或名的拼音</returns>
        /// <example>
        /// <code>
        /// str = getNamePingyin("春",true);   // str => "chun"
        /// str = getNamePingyin("春",false);  // str => "chun"
        /// str = getNamePingyin("解",true);   // str => "xie"
        /// str = getNamePingyin("解",false);  // str => "jie"
        /// str = getNamePingyin("翟",true);   // str => "zhai"
        /// str = getNamePingyin("翟",false);  // str => "di"
        /// str = getNamePingyin("参",true);   // str => "can"
        /// str = getNamePingyin("参",false);  // str => "can"
        /// str = getNamePingyin("单于",true);   // str => "chanyu"
        /// str = getNamePingyin("单于",false);  // str => "danyu"
        /// </code>
        /// </example>
        /// 
        public static string GetNamePingyin(string inStr, bool isLastName)
        {
            string outStr = "";

            //姓氏
            if (isLastName)
            {
                //在百家姓中查找
                for (int i = 0; i < g_length_lastNameTable; i++)
                {
                    if (inStr == lastNameTable[i, 0])
                    {
                        outStr = lastNameTable[i, 1];
                        break;
                    }
                }
            }

            //直接汉字库查找
            if (outStr == "")
            {
                for (int i = 0; i < inStr.Length; i++)
                {
                    outStr += GetNoRepeatPingyinForWord(inStr.Substring(i, 1));
                }
            }

            return outStr;
        }

        private static string GetNoRepeatPingyinForWord(string inWord)
        {
            string outPingyin = null;

            //只能输入一个字符
            if (inWord.Length > 1)
            {
                throw new ArgumentException("输入长度不能大于1");
            }

            //先在多音字里面查询，对应了最可能的正确读音
            for (int i = 0; i < g_length_multiToneWordTable; i++)
            {
                if (inWord == multiToneWordTable[i, 0])
                {
                    return multiToneWordTable[i, 1];
                }
            }

            //在全字库查找
            char wch = inWord[0];
            if (IsHanziChar(wch))
            {
                for (int index_table = 0; index_table < g_length_hanziTables; index_table++)
                {
                    if (hanziTables[index_table, 2].IndexOf(wch) != -1)
                    {
                        return hanziTables[index_table, 1];
                    }
                }
            }

            //返回结果
            return outPingyin;
        }

        public static void GetComPingyinForStr(string inStr, out string outFrist_py, out string outFull_py)
        {
            outFrist_py = "";
            outFull_py = "";

            //条件返回
            if (string.IsNullOrEmpty(inStr))
            {
                return;
            }

            // --- 获取每个字的所有读音
            int numOfWord = inStr.Length;
            List<List<string>> fristPys = new List<List<string>>();
            List<List<string>> fullPys = new List<List<string>>();
            for (int i_word = 0; i_word < numOfWord; i_word++)
            {
                List<string> fristPy;
                List<string> fullPy;
                GetAllPingyinForWord(inStr.Substring(i_word, 1), out fristPy, out fullPy);
                fristPys.Add(fristPy);
                fullPys.Add(fullPy);
            }


            // --- 开始排列组合
            List<int> nowIndexList = new List<int>();
            List<int> maxIndexList = new List<int>();
            int sum_maxIndexList = 0;
            for (int i = 0; i < numOfWord; i++)
            {
                nowIndexList.Add(0);
                maxIndexList.Add(fullPys[i].Count - 1);
                sum_maxIndexList += maxIndexList[i];
            }


            // --- 第一次组合（所有采用第一个）
            bool mustCombination = sum_maxIndexList > 0 ? true : false;
            for (int i = 0; i < numOfWord; i++)
            {
                outFrist_py += fristPys[i][0];
                outFull_py += fullPys[i][0];
            }


            // --- 循环遍历
            while (mustCombination)
            {
                // --- 组合排列
                bool alreadyRunOnce = false;
                for (int i = 0; i < numOfWord; i++)
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

                // --- 组合输出字符
                outFrist_py += " ";
                outFull_py += " ";
                for (int i = 0; i < numOfWord; i++)
                {
                    outFrist_py += fristPys[i][nowIndexList[i]];
                    outFull_py += fullPys[i][nowIndexList[i]];
                }

                // --- 退出条件
                bool canOut = true;
                for (int i = 0; i < numOfWord; i++)
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
        }
        
        private static void GetAllPingyinForWord(string inWord, out List<string> outFrist_py, out List<string> outFull_py)
        {
            outFrist_py = new List<string>();
            outFull_py = new List<string>();
            // 只能输入一个字符
            if (inWord.Length > 1)
            {
                throw new ArgumentException("只能输入一个字符");
            }


            char wch = inWord[0];
            if (IsHanziChar(wch))
            {
                for (int index_table = 0; index_table < g_length_hanziTables; index_table++)
                {
                    if (hanziTables[index_table, 2].IndexOf(wch) != -1)
                    {
                        outFrist_py.Add(hanziTables[index_table, 0]);
                        outFull_py.Add(hanziTables[index_table, 1]);
                    }
                }
            }
        }

        private static bool IsHanziChar(char wch)
        {
            // 在vs2019 上使用 qstring 时
            // return (wch >= 0x4E00 && wch <= 0x9FA5) ? true : false; 

            // 在vs2019 上使用 string 时
            //return (wch >= 12570 && wch <= 64041) ? true : false;

            // 这是一种折中方案 => 汉字不会有任何遗漏，能适应大多数编码方式（可过滤掉绝大多数常用非汉字字符）
            // 如果想获取准确的区间，使用testHanziRang()方法；
            return wch > 127 ? true : false;
        }

        void testHanziRang()
        {
            string str = "";
            for (int i = 0; i < g_length_hanziTables; i++)
            {
                str += hanziTables[i, 2];
            }

            int maxVal = 0;
            int minVal = 1000000000;
            char maxStr = ' ';
            char minStr = ' ';
            for (int i = 0; i < str.Length; i++)
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

            Console.Write("\n汉字编码测试：\n");
            Console.Write("最小编码值：%d , 最大编码值:%d , 总汉字数量(未去重)：%zd \n", minVal, maxVal, str.Length);

            Console.Write("最小编码值的汉字：%wc , 最大编码值的汉字: %wc \n", minStr, maxStr);

            // 【注意】
            // 如果想使printf可以打印wchar_t  
            // setlocale(LC_ALL, "");  // 在初始化时调用这个
            // #include <iostream>     // 对应的头文件
        }
    }
}
