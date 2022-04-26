/*
## 使用说明
1. 只导出了三个方法 getUniquePingyinForName(),getUniquePingyinForCommon(),getAllComPingyinForStr()
2. 使用示例看 test.js
*/

/*
## 更新记录
    1. 2022-03-09 hanziTables 中 'he' 添加 '𬌗' 

## 下次计划(现在还没有做)
    1. hanziTables: 个别行中会有重复的汉字，需要去重下
    2. hanziTables: "shi" 的那一行有特殊字符，'虱'的后面
    3. hanziTables: "zhou" 的那一行有特殊字符，倒数第三个
    4. hanziTables: "he" 最后添加'黑'，对应的 multiToneWordTable 添加'黑'=》'hei'
    5. hanziTables: 加了 '𬌗' 但是正则表达式无法识别（淦）以后再说喽
*/


let g_length_lastNameTable = 554
let g_length_multiToneWordTable = 708
let g_length_hanziTables = 411
let g_hanziRegExp = /^[\u4E00-\u9FA5]+$/

/* 
    0. 姓氏特殊读音(包括：特殊、非特殊、复姓读音)
    1. 可以自己添加
    3. 来源于各种网络数据的整合
    4. lastNameTableS lastNameTable[g_length_lastNameTable]
*/
let lastNameTable =[
	{ hanzi:"赵" , pinyi:"zhao" },
	{ hanzi:"钱" , pinyi:"qian" },
	{ hanzi:"孙" , pinyi:"sun" },
	{ hanzi:"李" , pinyi:"li" },
	{ hanzi:"周" , pinyi:"zhou" },
	{ hanzi:"吴" , pinyi:"wu" },
	{ hanzi:"郑" , pinyi:"zheng" },
	{ hanzi:"王" , pinyi:"wang" },
	{ hanzi:"冯" , pinyi:"feng" },
	{ hanzi:"陈" , pinyi:"chen" },
	{ hanzi:"褚" , pinyi:"chu" },
	{ hanzi:"卫" , pinyi:"wei" },
	{ hanzi:"蒋" , pinyi:"jiang" },
	{ hanzi:"沈" , pinyi:"shen" },
	{ hanzi:"韩" , pinyi:"han" },
	{ hanzi:"杨" , pinyi:"yang" },
	{ hanzi:"朱" , pinyi:"zhu" },
	{ hanzi:"秦" , pinyi:"qin" },
	{ hanzi:"尤" , pinyi:"you" },
	{ hanzi:"许" , pinyi:"xu" },
	{ hanzi:"何" , pinyi:"he" },
	{ hanzi:"吕" , pinyi:"lv" },
	{ hanzi:"施" , pinyi:"shi" },
	{ hanzi:"张" , pinyi:"zhang" },
	{ hanzi:"孔" , pinyi:"kong" },
	{ hanzi:"曹" , pinyi:"cao" },
	{ hanzi:"严" , pinyi:"yan" },
	{ hanzi:"华" , pinyi:"hua" },
	{ hanzi:"金" , pinyi:"jin" },
	{ hanzi:"魏" , pinyi:"wei" },
	{ hanzi:"陶" , pinyi:"tao" },
	{ hanzi:"姜" , pinyi:"jiang" },
	{ hanzi:"戚" , pinyi:"qi" },
	{ hanzi:"谢" , pinyi:"xie" },
	{ hanzi:"邹" , pinyi:"zou" },
	{ hanzi:"喻" , pinyi:"yu" },
	{ hanzi:"柏" , pinyi:"bai" },
	{ hanzi:"水" , pinyi:"shui" },
	{ hanzi:"窦" , pinyi:"dou" },
	{ hanzi:"章" , pinyi:"zhang" },
	{ hanzi:"云" , pinyi:"yun" },
	{ hanzi:"苏" , pinyi:"su" },
	{ hanzi:"潘" , pinyi:"pan" },
	{ hanzi:"葛" , pinyi:"ge" },
	{ hanzi:"奚" , pinyi:"xi" },
	{ hanzi:"范" , pinyi:"fan" },
	{ hanzi:"彭" , pinyi:"peng" },
	{ hanzi:"郎" , pinyi:"lang" },
	{ hanzi:"鲁" , pinyi:"lu" },
	{ hanzi:"韦" , pinyi:"wei" },
	{ hanzi:"昌" , pinyi:"chang" },
	{ hanzi:"马" , pinyi:"ma" },
	{ hanzi:"苗" , pinyi:"miao" },
	{ hanzi:"凤" , pinyi:"feng" },
	{ hanzi:"花" , pinyi:"hua" },
	{ hanzi:"方" , pinyi:"fang" },
	{ hanzi:"俞" , pinyi:"yu" },
	{ hanzi:"任" , pinyi:"ren" },
	{ hanzi:"袁" , pinyi:"yuan" },
	{ hanzi:"柳" , pinyi:"liu" },
	{ hanzi:"酆" , pinyi:"feng" },
	{ hanzi:"鲍" , pinyi:"bao" },
	{ hanzi:"史" , pinyi:"shi" },
	{ hanzi:"唐" , pinyi:"tang" },
	{ hanzi:"费" , pinyi:"fei" },
	{ hanzi:"廉" , pinyi:"lian" },
	{ hanzi:"岑" , pinyi:"cen" },
	{ hanzi:"薛" , pinyi:"xue" },
	{ hanzi:"雷" , pinyi:"lei" },
	{ hanzi:"贺" , pinyi:"he" },
	{ hanzi:"倪" , pinyi:"ni" },
	{ hanzi:"汤" , pinyi:"tang" },
	{ hanzi:"滕" , pinyi:"teng" },
	{ hanzi:"殷" , pinyi:"yin" },
	{ hanzi:"罗" , pinyi:"luo" },
	{ hanzi:"毕" , pinyi:"bi" },
	{ hanzi:"郝" , pinyi:"hao" },
	{ hanzi:"邬" , pinyi:"wu" },
	{ hanzi:"安" , pinyi:"an" },
	{ hanzi:"常" , pinyi:"chang" },
	{ hanzi:"乐" , pinyi:"yue" },
	{ hanzi:"于" , pinyi:"yu" },
	{ hanzi:"时" , pinyi:"shi" },
	{ hanzi:"傅" , pinyi:"fu" },
	{ hanzi:"皮" , pinyi:"pi" },
	{ hanzi:"卞" , pinyi:"bian" },
	{ hanzi:"齐" , pinyi:"qi" },
	{ hanzi:"康" , pinyi:"kang" },
	{ hanzi:"伍" , pinyi:"wu" },
	{ hanzi:"余" , pinyi:"yu" },
	{ hanzi:"元" , pinyi:"yuan" },
	{ hanzi:"卜" , pinyi:"bu" },
	{ hanzi:"顾" , pinyi:"gu" },
	{ hanzi:"孟" , pinyi:"meng" },
	{ hanzi:"平" , pinyi:"ping" },
	{ hanzi:"黄" , pinyi:"huang" },
	{ hanzi:"和" , pinyi:"he" },
	{ hanzi:"穆" , pinyi:"mu" },
	{ hanzi:"萧" , pinyi:"xiao" },
	{ hanzi:"尹" , pinyi:"yin" },
	{ hanzi:"姚" , pinyi:"yao" },
	{ hanzi:"邵" , pinyi:"shao" },
	{ hanzi:"湛" , pinyi:"zhan" },
	{ hanzi:"汪" , pinyi:"wang" },
	{ hanzi:"祁" , pinyi:"qi" },
	{ hanzi:"毛" , pinyi:"mao" },
	{ hanzi:"禹" , pinyi:"yu" },
	{ hanzi:"狄" , pinyi:"di" },
	{ hanzi:"米" , pinyi:"mi" },
	{ hanzi:"贝" , pinyi:"bei" },
	{ hanzi:"明" , pinyi:"ming" },
	{ hanzi:"臧" , pinyi:"zang" },
	{ hanzi:"计" , pinyi:"ji" },
	{ hanzi:"伏" , pinyi:"fu" },
	{ hanzi:"成" , pinyi:"cheng" },
	{ hanzi:"戴" , pinyi:"dai" },
	{ hanzi:"谈" , pinyi:"tan" },
	{ hanzi:"宋" , pinyi:"song" },
	{ hanzi:"茅" , pinyi:"mao" },
	{ hanzi:"庞" , pinyi:"pang" },
	{ hanzi:"熊" , pinyi:"xiong" },
	{ hanzi:"纪" , pinyi:"ji" },
	{ hanzi:"舒" , pinyi:"shu" },
	{ hanzi:"屈" , pinyi:"qu" },
	{ hanzi:"项" , pinyi:"xiang" },
	{ hanzi:"祝" , pinyi:"zhu" },
	{ hanzi:"董" , pinyi:"dong" },
	{ hanzi:"梁" , pinyi:"liang" },
	{ hanzi:"杜" , pinyi:"du" },
	{ hanzi:"阮" , pinyi:"ruan" },
	{ hanzi:"蓝" , pinyi:"lan" },
	{ hanzi:"闵" , pinyi:"min" },
	{ hanzi:"席" , pinyi:"xi" },
	{ hanzi:"季" , pinyi:"ji" },
	{ hanzi:"麻" , pinyi:"ma" },
	{ hanzi:"强" , pinyi:"qiang" },
	{ hanzi:"贾" , pinyi:"jia" },
	{ hanzi:"路" , pinyi:"lu" },
	{ hanzi:"娄" , pinyi:"lou" },
	{ hanzi:"危" , pinyi:"wei" },
	{ hanzi:"江" , pinyi:"jiang" },
	{ hanzi:"童" , pinyi:"tong" },
	{ hanzi:"颜" , pinyi:"yan" },
	{ hanzi:"郭" , pinyi:"guo" },
	{ hanzi:"梅" , pinyi:"mei" },
	{ hanzi:"盛" , pinyi:"sheng" },
	{ hanzi:"林" , pinyi:"lin" },
	{ hanzi:"刁" , pinyi:"diao" },
	{ hanzi:"钟" , pinyi:"zhong" },
	{ hanzi:"徐" , pinyi:"xu" },
	{ hanzi:"邱" , pinyi:"qiu" },
	{ hanzi:"骆" , pinyi:"luo" },
	{ hanzi:"高" , pinyi:"gao" },
	{ hanzi:"夏" , pinyi:"xia" },
	{ hanzi:"蔡" , pinyi:"cai" },
	{ hanzi:"田" , pinyi:"tian" },
	{ hanzi:"樊" , pinyi:"fan" },
	{ hanzi:"胡" , pinyi:"hu" },
	{ hanzi:"凌" , pinyi:"ling" },
	{ hanzi:"霍" , pinyi:"huo" },
	{ hanzi:"虞" , pinyi:"yu" },
	{ hanzi:"万" , pinyi:"wan" },
	{ hanzi:"支" , pinyi:"zhi" },
	{ hanzi:"柯" , pinyi:"ke" },
	{ hanzi:"昝" , pinyi:"zan" },
	{ hanzi:"管" , pinyi:"guan" },
	{ hanzi:"卢" , pinyi:"lu" },
	{ hanzi:"莫" , pinyi:"mo" },
	{ hanzi:"经" , pinyi:"jing" },
	{ hanzi:"房" , pinyi:"fang" },
	{ hanzi:"裘" , pinyi:"qiu" },
	{ hanzi:"缪" , pinyi:"miao" },
	{ hanzi:"干" , pinyi:"gan" },
	{ hanzi:"解" , pinyi:"xie" },
	{ hanzi:"应" , pinyi:"ying" },
	{ hanzi:"宗" , pinyi:"zong" },
	{ hanzi:"丁" , pinyi:"ding" },
	{ hanzi:"宣" , pinyi:"xuan" },
	{ hanzi:"贲" , pinyi:"ben" },
	{ hanzi:"邓" , pinyi:"deng" },
	{ hanzi:"郁" , pinyi:"yu" },
	{ hanzi:"单" , pinyi:"shan" },
	{ hanzi:"杭" , pinyi:"hang" },
	{ hanzi:"洪" , pinyi:"hong" },
	{ hanzi:"包" , pinyi:"bao" },
	{ hanzi:"诸" , pinyi:"zhu" },
	{ hanzi:"左" , pinyi:"zuo" },
	{ hanzi:"石" , pinyi:"shi" },
	{ hanzi:"崔" , pinyi:"cui" },
	{ hanzi:"吉" , pinyi:"ji" },
	{ hanzi:"钮" , pinyi:"niu" },
	{ hanzi:"龚" , pinyi:"gong" },
	{ hanzi:"程" , pinyi:"cheng" },
	{ hanzi:"嵇" , pinyi:"ji" },
	{ hanzi:"邢" , pinyi:"xing" },
	{ hanzi:"滑" , pinyi:"hua" },
	{ hanzi:"裴" , pinyi:"pei" },
	{ hanzi:"陆" , pinyi:"lu" },
	{ hanzi:"荣" , pinyi:"rong" },
	{ hanzi:"翁" , pinyi:"weng" },
	{ hanzi:"荀" , pinyi:"xun" },
	{ hanzi:"羊" , pinyi:"yang" },
	{ hanzi:"於" , pinyi:"yu" },
	{ hanzi:"惠" , pinyi:"hui" },
	{ hanzi:"甄" , pinyi:"zhen" },
	{ hanzi:"曲" , pinyi:"qu" },
	{ hanzi:"家" , pinyi:"jia" },
	{ hanzi:"封" , pinyi:"feng" },
	{ hanzi:"芮" , pinyi:"rui" },
	{ hanzi:"羿" , pinyi:"yi" },
	{ hanzi:"储" , pinyi:"chu" },
	{ hanzi:"靳" , pinyi:"jin" },
	{ hanzi:"汲" , pinyi:"ji" },
	{ hanzi:"邴" , pinyi:"bing" },
	{ hanzi:"糜" , pinyi:"mi" },
	{ hanzi:"松" , pinyi:"song" },
	{ hanzi:"井" , pinyi:"jing" },
	{ hanzi:"段" , pinyi:"duan" },
	{ hanzi:"富" , pinyi:"fu" },
	{ hanzi:"巫" , pinyi:"wu" },
	{ hanzi:"乌" , pinyi:"wu" },
	{ hanzi:"焦" , pinyi:"jiao" },
	{ hanzi:"巴" , pinyi:"ba" },
	{ hanzi:"弓" , pinyi:"gong" },
	{ hanzi:"牧" , pinyi:"mu" },
	{ hanzi:"隗" , pinyi:"kui" },
	{ hanzi:"山" , pinyi:"shan" },
	{ hanzi:"谷" , pinyi:"gu" },
	{ hanzi:"车" , pinyi:"che" },
	{ hanzi:"侯" , pinyi:"hou" },
	{ hanzi:"宓" , pinyi:"mi" },
	{ hanzi:"蓬" , pinyi:"peng" },
	{ hanzi:"全" , pinyi:"quan" },
	{ hanzi:"郗" , pinyi:"xi" },
	{ hanzi:"班" , pinyi:"ban" },
	{ hanzi:"仰" , pinyi:"yang" },
	{ hanzi:"秋" , pinyi:"qiu" },
	{ hanzi:"仲" , pinyi:"zhong" },
	{ hanzi:"伊" , pinyi:"yi" },
	{ hanzi:"宫" , pinyi:"gong" },
	{ hanzi:"宁" , pinyi:"ning" },
	{ hanzi:"仇" , pinyi:"qiu" },
	{ hanzi:"栾" , pinyi:"luan" },
	{ hanzi:"暴" , pinyi:"bao" },
	{ hanzi:"甘" , pinyi:"gan" },
	{ hanzi:"钭" , pinyi:"tou" },
	{ hanzi:"厉" , pinyi:"li" },
	{ hanzi:"戎" , pinyi:"rong" },
	{ hanzi:"祖" , pinyi:"zu" },
	{ hanzi:"武" , pinyi:"wu" },
	{ hanzi:"符" , pinyi:"fu" },
	{ hanzi:"刘" , pinyi:"liu" },
	{ hanzi:"景" , pinyi:"jing" },
	{ hanzi:"詹" , pinyi:"zhan" },
	{ hanzi:"束" , pinyi:"shu" },
	{ hanzi:"龙" , pinyi:"long" },
	{ hanzi:"叶" , pinyi:"ye" },
	{ hanzi:"幸" , pinyi:"xing" },
	{ hanzi:"司" , pinyi:"si" },
	{ hanzi:"韶" , pinyi:"shao" },
	{ hanzi:"郜" , pinyi:"gao" },
	{ hanzi:"黎" , pinyi:"li" },
	{ hanzi:"蓟" , pinyi:"ji" },
	{ hanzi:"薄" , pinyi:"bo" },
	{ hanzi:"印" , pinyi:"yin" },
	{ hanzi:"宿" , pinyi:"su" },
	{ hanzi:"白" , pinyi:"bai" },
	{ hanzi:"怀" , pinyi:"huai" },
	{ hanzi:"蒲" , pinyi:"pu" },
	{ hanzi:"邰" , pinyi:"tai" },
	{ hanzi:"从" , pinyi:"cong" },
	{ hanzi:"鄂" , pinyi:"e" },
	{ hanzi:"索" , pinyi:"suo" },
	{ hanzi:"咸" , pinyi:"xian" },
	{ hanzi:"籍" , pinyi:"ji" },
	{ hanzi:"赖" , pinyi:"lai" },
	{ hanzi:"卓" , pinyi:"zhuo" },
	{ hanzi:"蔺" , pinyi:"lin" },
	{ hanzi:"屠" , pinyi:"tu" },
	{ hanzi:"蒙" , pinyi:"meng" },
	{ hanzi:"池" , pinyi:"chi" },
	{ hanzi:"乔" , pinyi:"qiao" },
	{ hanzi:"阴" , pinyi:"yin" },
	{ hanzi:"郁" , pinyi:"yu" },
	{ hanzi:"胥" , pinyi:"xu" },
	{ hanzi:"能" , pinyi:"nai" },
	{ hanzi:"苍" , pinyi:"cang" },
	{ hanzi:"双" , pinyi:"shuang" },
	{ hanzi:"闻" , pinyi:"wen" },
	{ hanzi:"莘" , pinyi:"shen" },
	{ hanzi:"党" , pinyi:"dang" },
	{ hanzi:"翟" , pinyi:"zhai" },
	{ hanzi:"谭" , pinyi:"tan" },
	{ hanzi:"贡" , pinyi:"gong" },
	{ hanzi:"劳" , pinyi:"lao" },
	{ hanzi:"逄" , pinyi:"pang" },
	{ hanzi:"姬" , pinyi:"ji" },
	{ hanzi:"申" , pinyi:"shen" },
	{ hanzi:"扶" , pinyi:"fu" },
	{ hanzi:"堵" , pinyi:"du" },
	{ hanzi:"冉" , pinyi:"ran" },
	{ hanzi:"宰" , pinyi:"zai" },
	{ hanzi:"郦" , pinyi:"li" },
	{ hanzi:"雍" , pinyi:"yong" },
	{ hanzi:"郤" , pinyi:"xi" },
	{ hanzi:"璩" , pinyi:"qu" },
	{ hanzi:"桑" , pinyi:"sang" },
	{ hanzi:"桂" , pinyi:"gui" },
	{ hanzi:"濮" , pinyi:"pu" },
	{ hanzi:"牛" , pinyi:"niu" },
	{ hanzi:"寿" , pinyi:"shou" },
	{ hanzi:"通" , pinyi:"tong" },
	{ hanzi:"边" , pinyi:"bian" },
	{ hanzi:"扈" , pinyi:"hu" },
	{ hanzi:"燕" , pinyi:"yan" },
	{ hanzi:"冀" , pinyi:"ji" },
	{ hanzi:"郏" , pinyi:"jia" },
	{ hanzi:"浦" , pinyi:"pu" },
	{ hanzi:"尚" , pinyi:"shang" },
	{ hanzi:"农" , pinyi:"nong" },
	{ hanzi:"温" , pinyi:"wen" },
	{ hanzi:"别" , pinyi:"bie" },
	{ hanzi:"庄" , pinyi:"zhuang" },
	{ hanzi:"晏" , pinyi:"yan" },
	{ hanzi:"柴" , pinyi:"chai" },
	{ hanzi:"瞿" , pinyi:"qu" },
	{ hanzi:"阎" , pinyi:"yan" },
	{ hanzi:"充" , pinyi:"chong" },
	{ hanzi:"慕" , pinyi:"mu" },
	{ hanzi:"连" , pinyi:"lian" },
	{ hanzi:"茹" , pinyi:"ru" },
	{ hanzi:"习" , pinyi:"xi" },
	{ hanzi:"宦" , pinyi:"huan" },
	{ hanzi:"艾" , pinyi:"ai" },
	{ hanzi:"鱼" , pinyi:"yu" },
	{ hanzi:"容" , pinyi:"rong" },
	{ hanzi:"向" , pinyi:"xiang" },
	{ hanzi:"古" , pinyi:"gu" },
	{ hanzi:"易" , pinyi:"yi" },
	{ hanzi:"慎" , pinyi:"shen" },
	{ hanzi:"戈" , pinyi:"ge" },
	{ hanzi:"廖" , pinyi:"liao" },
	{ hanzi:"庾" , pinyi:"yu" },
	{ hanzi:"终" , pinyi:"zhong" },
	{ hanzi:"暨" , pinyi:"ji" },
	{ hanzi:"居" , pinyi:"ju" },
	{ hanzi:"衡" , pinyi:"heng" },
	{ hanzi:"步" , pinyi:"bu" },
	{ hanzi:"都" , pinyi:"du" },
	{ hanzi:"耿" , pinyi:"geng" },
	{ hanzi:"满" , pinyi:"man" },
	{ hanzi:"弘" , pinyi:"hong" },
	{ hanzi:"匡" , pinyi:"kuang" },
	{ hanzi:"国" , pinyi:"guo" },
	{ hanzi:"文" , pinyi:"wen" },
	{ hanzi:"寇" , pinyi:"kou" },
	{ hanzi:"广" , pinyi:"guang" },
	{ hanzi:"禄" , pinyi:"lu" },
	{ hanzi:"阙" , pinyi:"que" },
	{ hanzi:"东" , pinyi:"dong" },
	{ hanzi:"欧" , pinyi:"ou" },
	{ hanzi:"殳" , pinyi:"shu" },
	{ hanzi:"沃" , pinyi:"wo" },
	{ hanzi:"利" , pinyi:"li" },
	{ hanzi:"蔚" , pinyi:"wei" },
	{ hanzi:"越" , pinyi:"yue" },
	{ hanzi:"夔" , pinyi:"kui" },
	{ hanzi:"隆" , pinyi:"long" },
	{ hanzi:"师" , pinyi:"shi" },
	{ hanzi:"巩" , pinyi:"gong" },
	{ hanzi:"厍" , pinyi:"she" },
	{ hanzi:"聂" , pinyi:"nie" },
	{ hanzi:"晁" , pinyi:"chao" },
	{ hanzi:"勾" , pinyi:"gou" },
	{ hanzi:"句" , pinyi:"gou" },
	{ hanzi:"敖" , pinyi:"ao" },
	{ hanzi:"融" , pinyi:"rong" },
	{ hanzi:"冷" , pinyi:"leng" },
	{ hanzi:"訾" , pinyi:"zi" },
	{ hanzi:"辛" , pinyi:"xin" },
	{ hanzi:"阚" , pinyi:"kan" },
	{ hanzi:"那" , pinyi:"na" },
	{ hanzi:"简" , pinyi:"jian" },
	{ hanzi:"饶" , pinyi:"rao" },
	{ hanzi:"空" , pinyi:"kong" },
	{ hanzi:"曾" , pinyi:"zeng" },
	{ hanzi:"母" , pinyi:"mu" },
	{ hanzi:"沙" , pinyi:"sha" },
	{ hanzi:"乜" , pinyi:"nie" },
	{ hanzi:"养" , pinyi:"yang" },
	{ hanzi:"鞠" , pinyi:"ju" },
	{ hanzi:"须" , pinyi:"xu" },
	{ hanzi:"丰" , pinyi:"feng" },
	{ hanzi:"巢" , pinyi:"chao" },
	{ hanzi:"关" , pinyi:"guan" },
	{ hanzi:"蒯" , pinyi:"kuai" },
	{ hanzi:"相" , pinyi:"xiang" },
	{ hanzi:"查" , pinyi:"zha" },
	{ hanzi:"后" , pinyi:"hou" },
	{ hanzi:"荆" , pinyi:"jing" },
	{ hanzi:"红" , pinyi:"hong" },
	{ hanzi:"游" , pinyi:"you" },
	{ hanzi:"竺" , pinyi:"zhu" },
	{ hanzi:"权" , pinyi:"quan" },
	{ hanzi:"逯" , pinyi:"lu" },
	{ hanzi:"盖" , pinyi:"gai" },
	{ hanzi:"益" , pinyi:"yi" },
	{ hanzi:"桓" , pinyi:"huan" },
	{ hanzi:"公" , pinyi:"gong" },
	{ hanzi:"晋" , pinyi:"jin" },
	{ hanzi:"楚" , pinyi:"chu" },
	{ hanzi:"闫" , pinyi:"yan" },
	{ hanzi:"法" , pinyi:"fa" },
	{ hanzi:"汝" , pinyi:"ru" },
	{ hanzi:"鄢" , pinyi:"yan" },
	{ hanzi:"涂" , pinyi:"tu" },
	{ hanzi:"钦" , pinyi:"qin" },
	{ hanzi:"归" , pinyi:"gui" },
	{ hanzi:"海" , pinyi:"hai" },
	{ hanzi:"微" , pinyi:"wei" },
	{ hanzi:"生" , pinyi:"sheng" },
	{ hanzi:"岳" , pinyi:"yue" },
	{ hanzi:"帅" , pinyi:"shuai" },
	{ hanzi:"缑" , pinyi:"gou" },
	{ hanzi:"亢" , pinyi:"kang" },
	{ hanzi:"况" , pinyi:"kuang" },
	{ hanzi:"后" , pinyi:"hou" },
	{ hanzi:"有" , pinyi:"you" },
	{ hanzi:"琴" , pinyi:"qin" },
	{ hanzi:"商" , pinyi:"shang" },
	{ hanzi:"牟" , pinyi:"mou" },
	{ hanzi:"佘" , pinyi:"she" },
	{ hanzi:"佴" , pinyi:"nai" },
	{ hanzi:"伯" , pinyi:"bo" },
	{ hanzi:"赏" , pinyi:"shang" },
	{ hanzi:"墨" , pinyi:"mo" },
	{ hanzi:"哈" , pinyi:"ha" },
	{ hanzi:"谯" , pinyi:"qiao" },
	{ hanzi:"笪" , pinyi:"da" },
	{ hanzi:"年" , pinyi:"nian" },
	{ hanzi:"爱" , pinyi:"ai" },
	{ hanzi:"阳" , pinyi:"yang" },
	{ hanzi:"佟" , pinyi:"tong" },
	{ hanzi:"言" , pinyi:"yan" },
	{ hanzi:"福" , pinyi:"fu" },
	{ hanzi:"黑" , pinyi:"he" },
	{ hanzi:"区" , pinyi:"ou" },
	{ hanzi:"朴" , pinyi:"piao" },
	{ hanzi:"繁" , pinyi:"po" },
	{ hanzi:"员" , pinyi:"yun" },
	{ hanzi:"蕃" , pinyi:"pi" },
	{ hanzi:"种" , pinyi:"chong" },
	{ hanzi:"秘" , pinyi:"bi" },
	{ hanzi:"谌" , pinyi:"chen" },
	{ hanzi:"啜" , pinyi:"chuai" },
	{ hanzi:"邸" , pinyi:"di" },
	{ hanzi:"苻" , pinyi:"fu" },
	{ hanzi:"甫" , pinyi:"fu" },
	{ hanzi:"杲" , pinyi:"gao" },
	{ hanzi:"艮" , pinyi:"gen" },
	{ hanzi:"冠" , pinyi:"guan" },
	{ hanzi:"妫" , pinyi:"gui" },
	{ hanzi:"过" , pinyi:"guo" },
	{ hanzi:"晟" , pinyi:"cheng" },
	{ hanzi:"隽" , pinyi:"juan" },
	{ hanzi:"逢" , pinyi:"pang" },
	{ hanzi:"邳" , pinyi:"pi" },
	{ hanzi:"莆" , pinyi:"pu" },
	{ hanzi:"溥" , pinyi:"pu" },
	{ hanzi:"亓" , pinyi:"qi" },
	{ hanzi:"少" , pinyi:"shao" },
	{ hanzi:"召" , pinyi:"shao" },
	{ hanzi:"折" , pinyi:"she" },
	{ hanzi:"彤" , pinyi:"tong" },
	{ hanzi:"庹" , pinyi:"tuo" },
	{ hanzi:"宛" , pinyi:"wan" },
	{ hanzi:"尉" , pinyi:"wei" },
	{ hanzi:"冼" , pinyi:"xian" },
	{ hanzi:"洗" , pinyi:"xian" },
	{ hanzi:"郇" , pinyi:"xun" },
	{ hanzi:"幺" , pinyi:"yao" },
	{ hanzi:"郧" , pinyi:"yun" },
	{ hanzi:"恽" , pinyi:"yun" },
	{ hanzi:"郓" , pinyi:"yun" },
	{ hanzi:"妘" , pinyi:"yun" },
	{ hanzi:"祭" , pinyi:"zhai" },
	{ hanzi:"砦" , pinyi:"zhai" },
	{ hanzi:"占" , pinyi:"zhan" },
	{ hanzi:"仉" , pinyi:"zhang" },
	{ hanzi:"禚" , pinyi:"zhuo" },
	{ hanzi:"迮" , pinyi:"ze" },
    { hanzi:"覃" , pinyi:"qin" },

    { hanzi:"万俟" ,pinyi: "MoQi" },
    { hanzi:"羊舌" ,pinyi: "YangShe" },
    { hanzi:"段干" ,pinyi: "DuanGan" },
	{ hanzi:"百里" ,pinyi: "BaiLi" },
	{ hanzi:"东郭" ,pinyi: "DongGuo" },
	{ hanzi:"南门" ,pinyi: "NanMen" },
	{ hanzi:"呼延" ,pinyi: "HuYan" },
    { hanzi:"南宫" ,pinyi: "NanGong" },
    { hanzi:"梁丘" ,pinyi: "LiangQiu" },
	{ hanzi:"左丘" ,pinyi: "ZuoQiu" },
	{ hanzi:"东门" ,pinyi: "DongMen" },
	{ hanzi:"西门" ,pinyi: "XiMen" },
    { hanzi:"第五" ,pinyi: "DiWu" },
    { hanzi:"羊角" ,pinyi: "YangJue" },
    { hanzi:"中行" ,pinyi: "ZhongHang" },
    { hanzi:"司马" ,pinyi: "SiMa" },
	{ hanzi:"上官" ,pinyi: "ShangGuan" },
	{ hanzi:"欧阳" ,pinyi: "OuYang" },
	{ hanzi:"夏侯" ,pinyi: "XiaHou" },
	{ hanzi:"诸葛" ,pinyi: "ZhuGe" },
	{ hanzi:"闻人" ,pinyi: "WenRen" },
	{ hanzi:"东方" ,pinyi: "DongFang" },
	{ hanzi:"赫连" ,pinyi: "HeLian" },
	{ hanzi:"皇甫" ,pinyi: "HuangPu" },
	{ hanzi:"尉迟" ,pinyi: "YuChi" },
	{ hanzi:"公羊" ,pinyi: "GongYang" },
	{ hanzi:"澹台" ,pinyi: "TanTai" },
	{ hanzi:"公冶" ,pinyi: "GongYe" },
	{ hanzi:"宗政" ,pinyi: "ZongZheng" },
	{ hanzi:"濮阳" ,pinyi: "PuYang" },
	{ hanzi:"淳于" ,pinyi: "ChunYu" },
	{ hanzi:"单于" ,pinyi: "ChanYu" },
	{ hanzi:"太叔" ,pinyi: "TaiShu" },
	{ hanzi:"申屠" ,pinyi: "ShenTu" },
	{ hanzi:"公孙" ,pinyi: "GongSun" },
	{ hanzi:"仲孙" ,pinyi: "ZhongSun" },
	{ hanzi:"轩辕" ,pinyi: "XuanYuan" },
	{ hanzi:"令狐" ,pinyi: "LingHu" },
	{ hanzi:"钟离" ,pinyi: "ZhongLi" },
	{ hanzi:"宇文" ,pinyi: "YuWen" },
	{ hanzi:"长孙" ,pinyi: "ZhangSun" },
	{ hanzi:"慕容" ,pinyi: "MuRong" },
	{ hanzi:"鲜于" ,pinyi: "XianYu" },
	{ hanzi:"闾丘" ,pinyi: "LuQiu" },
	{ hanzi:"司徒" ,pinyi: "SiTu" },
	{ hanzi:"司空" ,pinyi: "SiKong" },
	{ hanzi:"亓官" ,pinyi: "QiGuan" },
	{ hanzi:"司寇" ,pinyi: "SiKou" },
	{ hanzi:"仉督" ,pinyi: "ZhangDu" },
	{ hanzi:"子车" ,pinyi: "ZiJu" },
	{ hanzi:"颛孙" ,pinyi: "ZhuanSun" },
	{ hanzi:"端木" ,pinyi: "DuanMu" },
	{ hanzi:"巫马" ,pinyi: "WuMa" },
	{ hanzi:"公西" ,pinyi: "GongXi" },
	{ hanzi:"漆雕" ,pinyi: "QiDiao" },
	{ hanzi:"乐正" ,pinyi: "YueZheng" },
	{ hanzi:"壤驷" ,pinyi: "RangSi" },
	{ hanzi:"公良" ,pinyi: "GongLiang" },
	{ hanzi:"拓跋" ,pinyi: "TuoBa" },
	{ hanzi:"夹谷" ,pinyi: "JiaGu" },
	{ hanzi:"宰父" ,pinyi: "ZaiFu" },
	{ hanzi:"榖梁" ,pinyi: "GuLiang" },
];

/*
    0. 多音字表 
    1. 后面的注释表示的是：这个字剩余的其他读音 （日、韩分别表示汉字是日语或韩语）
    2. 来源于 hanziTables[]，（遍历的所有，没有遗漏）
    3. 多音字选中读音规则：
    a. 选择常用读音 ：
            { "度" , "du" },        // duo 2020-10-28
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
    4. multiToneWordTableS multiToneWordTable[g_length_multiToneWordTable]
*/
let multiToneWordTable = [
	{ hanzi:"厑" , pinyin:"e" },         // si a
	{ hanzi:"吖" , pinyin:"ya" },        // a
	{ hanzi:"阿" , pinyin:"a" },         // e
	{ hanzi:"呵" , pinyin:"he" },        // ha ke a
	{ hanzi:"腌" , pinyin:"yan" },       // a
	{ hanzi:"嗄" , pinyin:"sha" },       // a
	{ hanzi:"閊" , pinyin:"ci" },        // ka lu ai
	{ hanzi:"魞" , pinyin:"li" },        // ai
	{ hanzi:"鱛" , pinyin:"ai" },        // suo 
	{ hanzi:"娭" , pinyin:"xi" },        // ai
	{ hanzi:"佁" , pinyin:"yi" },        // ai
	{ hanzi:"欸" , pinyin:"ei" },        // ai
	{ hanzi:"艾" , pinyin:"ai" },        // yi 
	{ hanzi:"嗌" , pinyin:"yi" },        // ai
	{ hanzi:"噫" , pinyin:"yi" },        // ai
	{ hanzi:"餲" , pinyin:"ai" },        // he 
	{ hanzi:"厂" , pinyin:"chang" },     // an
	{ hanzi:"广" , pinyin:"guang" },     // an
	{ hanzi:"晻" , pinyin:"yan" },       // an
	{ hanzi:"犴" , pinyin:"han" },       // an
	{ hanzi:"胺" , pinyin:"an" },        // e 
	{ hanzi:"肮" , pinyin:"ang" },       // hang 
	{ hanzi:"卬" , pinyin:"yang" },      // ang
	{ hanzi:"仰" , pinyin:"yang" },      // ang
	{ hanzi:"凹" , pinyin:"ao" },        // wa 
	{ hanzi:"嚣" , pinyin:"xiao" },      // ao
	{ hanzi:"夭" , pinyin:"ao" },        // yao 
	{ hanzi:"拗" , pinyin:"ao" },        // niu 
	{ hanzi:"鎺" , pinyin:"ha" },        // ba
	{ hanzi:"鯐" , pinyin:"li" },        // si xi ba
	{ hanzi:"叭" , pinyin:"ba" },        // pa 
	{ hanzi:"鎺" , pinyin:"ba" },        // pa
	{ hanzi:"伯" , pinyin:"bo" },        // bai  ba
	{ hanzi:"杷" , pinyin:"pa" },        // ba
	{ hanzi:"叭" , pinyin:"ba" },        // pa
	{ hanzi:"耙" , pinyin:"pa" },        // ba
	{ hanzi:"瓸" , pinyin:"bai" },       // wa 
	{ hanzi:"兡" , pinyin:"bai" },       // ke 
	{ hanzi:"陌" , pinyin:"mo" },        // bai
	{ hanzi:"柏" , pinyin:"bai" },       // bo 
	{ hanzi:"伴" , pinyin:"ban" },       // pan 
	{ hanzi:"拌" , pinyin:"ban" },       // pan 
	{ hanzi:"坢" , pinyin:"pan" },       // ban
	{ hanzi:"柈" , pinyin:"pan" },       // ban
	{ hanzi:"膀" , pinyin:"bang" },      // pang 
	{ hanzi:"旁" , pinyin:"pang" },      // bang
	{ hanzi:"蚌" , pinyin:"bang" },      // beng 
	{ hanzi:"棓" , pinyin:"bang" },      // bei 
	{ hanzi:"搒" , pinyin:"bang" },      // peng 
	{ hanzi:"磅" , pinyin:"bang" },      // pang 
	{ hanzi:"炮" , pinyin:"pao" },       // bao
	{ hanzi:"枹" , pinyin:"bao" },       // fu 
	{ hanzi:"薄" , pinyin:"bo" },        // bao
	{ hanzi:"堡" , pinyin:"bao" },       // bu pu 
	{ hanzi:"刨" , pinyin:"pao" },       // bao
	{ hanzi:"袌" , pinyin:"pao" },       // bao
	{ hanzi:"暴" , pinyin:"bao" },       // pu 
	{ hanzi:"瀑" , pinyin:"pu" },        // bao
	{ hanzi:"曝" , pinyin:"bao" },       // pu 
	{ hanzi:"陂" , pinyin:"bei" },       // pi po 
	{ hanzi:"椑" , pinyin:"bei" },       // pi 
	{ hanzi:"孛" , pinyin:"bei" },       // bo 
	{ hanzi:"被" , pinyin:"bei" },       // pi 
	{ hanzi:"贲" , pinyin:"ben" },       // bi 
	{ hanzi:"夯" , pinyin:"hang" },      // ben
	{ hanzi:"萙" , pinyin:"ta" },        // ku lai bi
	{ hanzi:"蛯" , pinyin:"bi" },        // e 
	{ hanzi:"鎞" , pinyin:"bi" },        // pi 
	{ hanzi:"吡" , pinyin:"pi" },        // bi
	{ hanzi:"箄" , pinyin:"pai" },       // bi
	{ hanzi:"芘" , pinyin:"bi" },        // pi 
	{ hanzi:"泌" , pinyin:"mi" },        // bi
	{ hanzi:"秘" , pinyin:"mi" },        // bi
	{ hanzi:"裨" , pinyin:"bi" },        // pi 
	{ hanzi:"辟" , pinyin:"pi" },        // bi
	{ hanzi:"睥" , pinyin:"pi" },        // bi
	{ hanzi:"扁" , pinyin:"bian" },      // pian 
	{ hanzi:"褊" , pinyin:"bian" },      // pian 
	{ hanzi:"便" , pinyin:"bian" },      // pian 
	{ hanzi:"缏" , pinyin:"bian" },      // pian 
	{ hanzi:"杓" , pinyin:"shao" },      // biao
	{ hanzi:"骠" , pinyin:"biao" },      // piao 
	{ hanzi:"麃" , pinyin:"pao" },       // biao
	{ hanzi:"玢" , pinyin:"fen" },       // bin
	{ hanzi:"槟" , pinyin:"bing" },      // bin
	{ hanzi:"屏" , pinyin:"ping" },      // bing
	{ hanzi:"绠" , pinyin:"geng" },      // bing
	{ hanzi:"卜" , pinyin:"bu" },        // bo
	{ hanzi:"畓" , pinyin:"da" },        // bo
	{ hanzi:"泊" , pinyin:"po" },        // bo
	{ hanzi:"魄" , pinyin:"po" },        // tuo bo
	{ hanzi:"埔" , pinyin:"pu" },        // bu
	{ hanzi:"拆" , pinyin:"chai" },      // ca
	{ hanzi:"嚓" , pinyin:"ca" },        // cha 
	{ hanzi:"偲" , pinyin:"si" },        // cai
	{ hanzi:"参" , pinyin:"can" },       // cen san shen 
	{ hanzi:"篸" , pinyin:"can" },       // zan 
	{ hanzi:"掺" , pinyin:"chan" },      // shan can
	{ hanzi:"孱" , pinyin:"chan" },      // can
	{ hanzi:"臧" , pinyin:"zang" },      // cang
	{ hanzi:"藏" , pinyin:"cang" },      // zang 
	{ hanzi:"猠" , pinyin:"o" },         // ce
	{ hanzi:"硛" , pinyin:"ce" },        // ke o 
	{ hanzi:"侧" , pinyin:"ce" },        // ze zhai 
	{ hanzi:"筴" , pinyin:"ce" },        // jia 
	{ hanzi:"噌" , pinyin:"cheng" },     // ceng
	{ hanzi:"曾" , pinyin:"ceng" },      // zeng 
	{ hanzi:"差" , pinyin:"cha" },       // chai ci 
	{ hanzi:"喳" , pinyin:"zha" },       // cha
	{ hanzi:"查" , pinyin:"cha" },       // zha 
	{ hanzi:"猹" , pinyin:"cha" },       // zha 
	{ hanzi:"楂" , pinyin:"zha" },       // cha
	{ hanzi:"槎" , pinyin:"cha" },       // zha 
	{ hanzi:"刹" , pinyin:"sha" },       // cha
	{ hanzi:"咤" , pinyin:"zha" },       // cha
	{ hanzi:"柴" , pinyin:"chai" },      // zhai 
	{ hanzi:"茝" , pinyin:"chai" },      // zhi 
	{ hanzi:"瘥" , pinyin:"cuo" },       // chai
	{ hanzi:"单" , pinyin:"dan" },       // shan chan
	{ hanzi:"禅" , pinyin:"chan" },      // shan 
	{ hanzi:"长" , pinyin:"chang" },     // zhang 
	{ hanzi:"倘" , pinyin:"tang" },      // chang
	{ hanzi:"惝" , pinyin:"chang" },     // tang 
	{ hanzi:"绰" , pinyin:"chuo" },      // chao
	{ hanzi:"焯" , pinyin:"chao" },      // zhuo 
	{ hanzi:"剿" , pinyin:"chao" },      // jiao 
	{ hanzi:"朝" , pinyin:"chao" },      // zhao 
	{ hanzi:"鼌" , pinyin:"zhao" },      // chao
	{ hanzi:"嘲" , pinyin:"chao" },      // zhao 
	{ hanzi:"车" , pinyin:"che" },       // ju 
	{ hanzi:"尺" , pinyin:"chi" },       // che
	{ hanzi:"嗔" , pinyin:"chen" },      // tian 
	{ hanzi:"称" , pinyin:"cheng" },     // chen
	{ hanzi:"铛" , pinyin:"dang" },      // cheng
	{ hanzi:"樘" , pinyin:"tang" },      // cheng
	{ hanzi:"乘" , pinyin:"cheng" },     // sheng 
	{ hanzi:"盛" , pinyin:"sheng" },     // cheng
	{ hanzi:"澄" , pinyin:"cheng" },     // deng 
	{ hanzi:"坻" , pinyin:"di" },        // chi
	{ hanzi:"瘈" , pinyin:"zhi" },       // chi
	{ hanzi:"涌" , pinyin:"yong" },      // chong
	{ hanzi:"虫" , pinyin:"chong" },     // hui 
	{ hanzi:"种" , pinyin:"zhong" },     // chong
	{ hanzi:"重" , pinyin:"zhong" },     // chong
	{ hanzi:"仇" , pinyin:"chou" },      // qiu 
	{ hanzi:"帱" , pinyin:"chou" },      // dao 
	{ hanzi:"杻" , pinyin:"niu" },       // chou
	{ hanzi:"臭" , pinyin:"chou" },      // xiu 
	{ hanzi:"助" , pinyin:"zhu" },       // chu
	{ hanzi:"褚" , pinyin:"zhu" },       // chuzhe 
	{ hanzi:"畜" , pinyin:"chu" },       // xu 
	{ hanzi:"俶" , pinyin:"chu" },       // ti 
	{ hanzi:"滀" , pinyin:"chu" },       // xu 
	{ hanzi:"欻" , pinyin:"xu" },        // chua
	{ hanzi:"啜" , pinyin:"chuo" },      // chuai
	{ hanzi:"传" , pinyin:"chuan" },     // zhuan 
	{ hanzi:"串" , pinyin:"chuan" },     // guan 
	{ hanzi:"幢" , pinyin:"zhuang" },    // chuang
	{ hanzi:"椎" , pinyin:"zhui" },      // chui
	{ hanzi:"錞" , pinyin:"dchun" },     // ui 
	{ hanzi:"婼" , pinyin:"ruo" },       // chuo
	{ hanzi:"茈" , pinyin:"zi" },        // ci
	{ hanzi:"兹" , pinyin:"zi" },        // ci
	{ hanzi:"伺" , pinyin:"si" },        // ci
	{ hanzi:"枞" , pinyin:"cong" },      // zong 
	{ hanzi:"楤" , pinyin:"song" },      // cong
	{ hanzi:"卒" , pinyin:"zu" },        // cu
	{ hanzi:"趣" , pinyin:"qu" },        // cu
	{ hanzi:"菆" , pinyin:"zou" },       // cuan
	{ hanzi:"攒" , pinyin:"zan" },       // cuan
	{ hanzi:"粹" , pinyin:"cui" },       // sui 
	{ hanzi:"蹲" , pinyin:"dun" },       // cun
	{ hanzi:"酂" , pinyin:"zan" },       // cuo
	{ hanzi:"鶎" , pinyin:"ku" },        // ta yi da
	{ hanzi:"嗒" , pinyin:"da" },        // ta 
	{ hanzi:"沓" , pinyin:"ta" },        // da
	{ hanzi:"惮" , pinyin:"dan" },       // da
	{ hanzi:"大" , pinyin:"da" },        // dai 
	{ hanzi:"汏" , pinyin:"tai" },       // da
	{ hanzi:"呔" , pinyin:"dai" },       // tai 
	{ hanzi:"骀" , pinyin:"dai" },       // tai 
	{ hanzi:"掸" , pinyin:"dan" },       // shan 
	{ hanzi:"黵" , pinyin:"dan" },       // zhan 
	{ hanzi:"石" , pinyin:"shi" },       // dan
	{ hanzi:"弹" , pinyin:"tan" },       // dan
	{ hanzi:"澹" , pinyin:"dan" },       // tan 
	{ hanzi:"乭" , pinyin:"dao" },       // ri 
	{ hanzi:"叨" , pinyin:"dao" },       // tao 
	{ hanzi:"焘" , pinyin:"dao" },       // tao 
	{ hanzi:"的" , pinyin:"de" },        // di 
	{ hanzi:"地" , pinyin:"di" },        // de
	{ hanzi:"底" , pinyin:"di" },        // de
	{ hanzi:"得" , pinyin:"de" },        // dei 
	{ hanzi:"嘚" , pinyin:"de" },        // dei 
	{ hanzi:"嚸" , pinyin:"di" },        // mi 
	{ hanzi:"提" , pinyin:"ti" },        // di
	{ hanzi:"翟" , pinyin:"di" },        // zhai 
	{ hanzi:"蹢" , pinyin:"di" },        // zhi 
	{ hanzi:"杕" , pinyin:"di" },        // duo 
	{ hanzi:"揥" , pinyin:"ti" },        // di
	{ hanzi:"阽" , pinyin:"dian" },      // yan 
	{ hanzi:"佃" , pinyin:"dian" },      // tian 
	{ hanzi:"钿" , pinyin:"dian" },      // tian 
	{ hanzi:"鸟" , pinyin:"niao" },      // diao
	{ hanzi:"调" , pinyin:"tiao" },      // zhou diao
	{ hanzi:"铫" , pinyin:"diao" },      // yao 
	{ hanzi:"咥" , pinyin:"die" },       // xi 
	{ hanzi:"昳" , pinyin:"die" },       // yi 
	{ hanzi:"喋" , pinyin:"die" },       // zha 
	{ hanzi:"揲" , pinyin:"die" },       // she 
	{ hanzi:"螲" , pinyin:"zhi" },       // die
	{ hanzi:"丁" , pinyin:"ding" },      // zheng 
	{ hanzi:"町" , pinyin:"ding" },      // ting 
	{ hanzi:"铤" , pinyin:"ting" },      // ding
	{ hanzi:"侗" , pinyin:"tong" },      // dong
	{ hanzi:"垌" , pinyin:"dong" },      // tong 
	{ hanzi:"恫" , pinyin:"dong" },      // tong 
	{ hanzi:"峒" , pinyin:"tong" },      // dong
	{ hanzi:"都" , pinyin:"dou" },       // du 
	{ hanzi:"读" , pinyin:"du" },        // dou
	{ hanzi:"渎" , pinyin:"du" },        // dou
	{ hanzi:"叾" , pinyin:"du" },        // ge 
	{ hanzi:"阇" , pinyin:"du" },        // she 
	{ hanzi:"度" , pinyin:"du" },        // duo
	{ hanzi:"斁" , pinyin:"yi" },        // du
	{ hanzi:"敦" , pinyin:"dun" },       // dui
	{ hanzi:"镦" , pinyin:"dui" },       // dun 
	{ hanzi:"沌" , pinyin:"dun" },       // zhuan 
	{ hanzi:"囤" , pinyin:"tun" },       // dun
	{ hanzi:"楯" , pinyin:"dun" },       // shun 
	{ hanzi:"鯲" , pinyin:"wu" },        // ya duo ji 
	{ hanzi:"驮" , pinyin:"tuo" },       // duo
	{ hanzi:"堕" , pinyin:"duo" },       // hui 
	{ hanzi:"仒" , pinyin:"o" },         // e
	{ hanzi:"旕" , pinyin:"o" },         // si e
	{ hanzi:"襨" , pinyin:"e" },         // ta
	{ hanzi:"欕" , pinyin:"mi" },        // e
	{ hanzi:"恶" , pinyin:"e" },         // wu 
	{ hanzi:"哦" , pinyin:"o" },         // e
	{ hanzi:"蛾" , pinyin:"e" },         // yi 
	{ hanzi:"阏" , pinyin:"e" },         // yan 
	{ hanzi:"椧" , pinyin:"mi" },        // eng
	{ hanzi:"臑" , pinyin:"nao" },       // er
	{ hanzi:"佴" , pinyin:"er" },        // nai 
	{ hanzi:"发" , pinyin:"fa" },        // fei 
	{ hanzi:"酦" , pinyin:"fa" },        // po 
	{ hanzi:"番" , pinyin:"fan" },       // pan 
	{ hanzi:"袢" , pinyin:"pan" },       // fan
	{ hanzi:"繁" , pinyin:"fan" },       // po 
	{ hanzi:"仿" , pinyin:"fang" },      // pang 
	{ hanzi:"彷" , pinyin:"pang" },      // fang
	{ hanzi:"芾" , pinyin:"fu" },        // fei
	{ hanzi:"怫" , pinyin:"fu" },        // fei
	{ hanzi:"濆" , pinyin:"fen" },       // pen 
	{ hanzi:"冯" , pinyin:"feng" },      // ping 
	{ hanzi:"佛" , pinyin:"fo" },        // fu 
	{ hanzi:"否" , pinyin:"fou" },       // pi 
	{ hanzi:"莩" , pinyin:"fu" },        // piao 
	{ hanzi:"俛" , pinyin:"mian" },      // fu
	{ hanzi:"脯" , pinyin:"pu" },        // fu
	{ hanzi:"乫" , pinyin:"ga" },        // ri 
	{ hanzi:"凩" , pinyin:"xi" },        // la  ga
	{ hanzi:"軈" , pinyin:"ya" },        // ga
	{ hanzi:"夹" , pinyin:"jia" },       // ga
	{ hanzi:"伽" , pinyin:"ga" },        // jia qie 
	{ hanzi:"呷" , pinyin:"xia" },       // ga
	{ hanzi:"咖" , pinyin:"ka" },        // ga
	{ hanzi:"轧" , pinyin:"zha" },       // ya  ga
	{ hanzi:"芥" , pinyin:"jie" },       // gai
	{ hanzi:"盖" , pinyin:"gai" },       // ge 
	{ hanzi:"奸" , pinyin:"jian" },      // gan
	{ hanzi:"感" , pinyin:"gan" },       // han 
	{ hanzi:"赣" , pinyin:"gan" },       // gong 
	{ hanzi:"扛" , pinyin:"kang" },      // gang
	{ hanzi:"戆" , pinyin:"gang" },      // zhuang 
	{ hanzi:"皋" , pinyin:"gao" },       // hao 
	{ hanzi:"羙" , pinyin:"mei" },       // gao
	{ hanzi:"镐" , pinyin:"gao" },       // hao 
	{ hanzi:"乬" , pinyin:"ge" },        // ri 
	{ hanzi:"巪" , pinyin:"xi" },        // ge
	{ hanzi:"唟" , pinyin:"ge" },        // xi 
	{ hanzi:"仡" , pinyin:"yi" },        // ge
	{ hanzi:"纥" , pinyin:"ge" },        // he 
	{ hanzi:"咯" , pinyin:"ge" },        // ka luo 
	{ hanzi:"革" , pinyin:"ge" },        // ji 
	{ hanzi:"鬲" , pinyin:"ge" },        // li 
	{ hanzi:"蛤" , pinyin:"ge" },        // ha 
	{ hanzi:"合" , pinyin:"he" },        // ge
	{ hanzi:"硌" , pinyin:"luo" },       // ge
	{ hanzi:"给" , pinyin:"gei" },       // ji 
	{ hanzi:"哏" , pinyin:"gen" },       // hen 
	{ hanzi:"红" , pinyin:"hong" },      // gong
	{ hanzi:"唝" , pinyin:"gong" },      // hong 
	{ hanzi:"句" , pinyin:"ju" },        // gou
	{ hanzi:"枸" , pinyin:"gou" },       // ju 
	{ hanzi:"呱" , pinyin:"gua" },       // gu
	{ hanzi:"家" , pinyin:"jia" },       // gu
	{ hanzi:"鹘" , pinyin:"gu" },        // hu 
	{ hanzi:"汩" , pinyin:"gu" },        // yu 
	{ hanzi:"谷" , pinyin:"gu" },        // yu 
	{ hanzi:"苦" , pinyin:"ku" },        // gu
	{ hanzi:"贾" , pinyin:"jia" },       // gu
	{ hanzi:"鹄" , pinyin:"gu" },        // he hu 
	{ hanzi:"嘏" , pinyin:"gu" },        // jia 
	{ hanzi:"雇" , pinyin:"gu" },        // hu 
	{ hanzi:"栝" , pinyin:"gua" },       // kuo 
	{ hanzi:"纶" , pinyin:"lun" },       // guan
	{ hanzi:"矜" , pinyin:"jin" },       // qin guan
	{ hanzi:"莞" , pinyin:"guan" },      // wan 
	{ hanzi:"归" , pinyin:"gui" },       // kui 
	{ hanzi:"龟" , pinyin:"gui" },       // jun qiu 
	{ hanzi:"廆" , pinyin:"gui" },       // hui wei 
	{ hanzi:"鲑" , pinyin:"gui" },       // hua xie 
	{ hanzi:"氿" , pinyin:"jiu" },       // gui
	{ hanzi:"炅" , pinyin:"jiong" },     // gui
	{ hanzi:"炔" , pinyin:"que" },       // gui
	{ hanzi:"柜" , pinyin:"gui" },       // ju 
	{ hanzi:"桧" , pinyin:"hui" },       // gui 
	{ hanzi:"鳜" , pinyin:"gui" },       // jue 
	{ hanzi:"涡" , pinyin:"wo" },        // guo
	{ hanzi:"乤" , pinyin:"ha" },        // ri 
	{ hanzi:"扖" , pinyin:"ru" },        // me  ha
	{ hanzi:"溌" , pinyin:"tu" },        // ha
	{ hanzi:"噺" , pinyin:"xi" },        // ha na 
	{ hanzi:"鱩" , pinyin:"ta" },        // ha
	{ hanzi:"虾" , pinyin:"xia" },       // ha
	{ hanzi:"咳" , pinyin:"ke" },        // hai
	{ hanzi:"嗨" , pinyin:"hai" },       // hei 
	{ hanzi:"还" , pinyin:"huan" },      // hai
	{ hanzi:"害" , pinyin:"hai" },       // he 
	{ hanzi:"炕" , pinyin:"kang" },      // hang
	{ hanzi:"行" , pinyin:"xing" },      // hang heng
	{ hanzi:"吭" , pinyin:"keng" },      // hang
	{ hanzi:"巷" , pinyin:"xiang" },     // hang
	{ hanzi:"貉" , pinyin:"he" },        // hao
	{ hanzi:"遤" , pinyin:"he" },        // wo 
	{ hanzi:"和" , pinyin:"he" },        // hu huo 
	{ hanzi:"核" , pinyin:"he" },        // hu 
	{ hanzi:"吓" , pinyin:"xia" },       // he
	{ hanzi:"猲" , pinyin:"xie" },       // he
	{ hanzi:"熇" , pinyin:"he" },        // kao 
	{ hanzi:"嘿" , pinyin:"hei" },       // mo 
	{ hanzi:"戏" , pinyin:"xi" },        // hu hui 
	{ hanzi:"芴" , pinyin:"wu" },        // hu
	{ hanzi:"浒" , pinyin:"hu" },        // xu 
	{ hanzi:"唬" , pinyin:"hu" },        // xia 
	{ hanzi:"楛" , pinyin:"ku" },        // hu
	{ hanzi:"砉" , pinyin:"xu" },        // hua
	{ hanzi:"郇" , pinyin:"xun" },       // huan
	{ hanzi:"圜" , pinyin:"yuan" },      // huan
	{ hanzi:"嬛" , pinyin:"huan" },      // qiong xuan 
	{ hanzi:"眩" , pinyin:"xuan" },      // huan
	{ hanzi:"炜" , pinyin:"wei" },       // hui
	{ hanzi:"珲" , pinyin:"hun" },       // hui
	{ hanzi:"睢" , pinyin:"hui" },       // sui 
	{ hanzi:"会" , pinyin:"hui" },       // kuai 
	{ hanzi:"浍" , pinyin:"hui" },       // kuai 
	{ hanzi:"哕" , pinyin:"yue" },       // hui
	{ hanzi:"荤" , pinyin:"hun" },       // xun 
	{ hanzi:"奇" , pinyin:"qi" },        // ji
	{ hanzi:"其" , pinyin:"qi" },        // ji
	{ hanzi:"缉" , pinyin:"ji" },        // qi 
	{ hanzi:"稽" , pinyin:"ji" },        // qi 
	{ hanzi:"亟" , pinyin:"ji" },        // qi 
	{ hanzi:"藉" , pinyin:"ji" },        // jie 
	{ hanzi:"齐" , pinyin:"qi" },        // ji
	{ hanzi:"系" , pinyin:"xi" },        // ji
	{ hanzi:"荠" , pinyin:"ji" },        // qi 
	{ hanzi:"祭" , pinyin:"ji" },        // zhai 
	{ hanzi:"偈" , pinyin:"jie" },       // ji
	{ hanzi:"嗧" , pinyin:"jia" },       // lun 
	{ hanzi:"茄" , pinyin:"qie" },       // jia
	{ hanzi:"葭" , pinyin:"jia" },       // xia 
	{ hanzi:"假" , pinyin:"jia" },       // xia 
	{ hanzi:"价" , pinyin:"jia" },       // jie 
	{ hanzi:"浅" , pinyin:"qian" },      // jian
	{ hanzi:"犍" , pinyin:"jian" },      // qian 
	{ hanzi:"囝" , pinyin:"jian" },      // nan 
	{ hanzi:"见" , pinyin:"jian" },      // xian 
	{ hanzi:"槛" , pinyin:"kan" },       // jian
	{ hanzi:"将" , pinyin:"jiang" },     // qiang 
	{ hanzi:"降" , pinyin:"jiang" },     // xiang 
	{ hanzi:"强" , pinyin:"qiang" },     // jiang
	{ hanzi:"蕉" , pinyin:"jiao" },      // qiao 
	{ hanzi:"徼" , pinyin:"jiao" },      // yao 
	{ hanzi:"嚼" , pinyin:"jiao" },      // jue 
	{ hanzi:"角" , pinyin:"jiao" },      // jue 
	{ hanzi:"侥" , pinyin:"jiao" },      // yao 
	{ hanzi:"脚" , pinyin:"jiao" },      // jue 
	{ hanzi:"湫" , pinyin:"jiu" },       // qiu jiao
	{ hanzi:"缴" , pinyin:"jiao" },      // zhuo 
	{ hanzi:"峤" , pinyin:"qiao" },      // jiao
	{ hanzi:"觉" , pinyin:"jiao" },      // jue 
	{ hanzi:"校" , pinyin:"xiao" },      // jiao
	{ hanzi:"楷" , pinyin:"kai" },       // jie
	{ hanzi:"桔" , pinyin:"jie" },       // ju 
	{ hanzi:"絜" , pinyin:"xie" },       // jie
	{ hanzi:"解" , pinyin:"jie" },       // xie 
	{ hanzi:"廑" , pinyin:"jin" },       // qin 
	{ hanzi:"劲" , pinyin:"jing" },      // jin
	{ hanzi:"倞" , pinyin:"liang" },     // jing
	{ hanzi:"靓" , pinyin:"liang" },     // jing
	{ hanzi:"且" , pinyin:"qie" },       // ju
	{ hanzi:"苴" , pinyin:"ju" },        // zu 
	{ hanzi:"蛆" , pinyin:"qu" },        // ju
	{ hanzi:"趄" , pinyin:"qie" },       // ju
	{ hanzi:"咀" , pinyin:"ju" },        // zui 
	{ hanzi:"籧" , pinyin:"qu" },        // ju
	{ hanzi:"苣" , pinyin:"ju" },        // qu 
	{ hanzi:"圈" , pinyin:"quan" },      // juan
	{ hanzi:"卷" , pinyin:"juan" },      // quan 
	{ hanzi:"踡" , pinyin:"quan" },      // juan
	{ hanzi:"隽" , pinyin:"jun" },       // juan
	{ hanzi:"阙" , pinyin:"que" },       // jue
	{ hanzi:"噱" , pinyin:"xue" },       // jue
	{ hanzi:"筠" , pinyin:"jun" },       // yun 
	{ hanzi:"麇" , pinyin:"qun" },       // jun
	{ hanzi:"浚" , pinyin:"jun" },       // xun 
	{ hanzi:"焌" , pinyin:"jun" },       // qu 
	{ hanzi:"凧" , pinyin:"ka" },        // yi 
	{ hanzi:"裃" , pinyin:"ka" },        // mi mo xi 日
	{ hanzi:"聢" , pinyin:"li" },        // xi ka
	{ hanzi:"鯑" , pinyin:"ke" },        // nou zi ka
	{ hanzi:"鶍" , pinyin:"si" },        // yi ka
	{ hanzi:"卡" , pinyin:"ka" },        // qia 
	{ hanzi:"厼" , pinyin:"mu" },        // wu ke
	{ hanzi:"迲" , pinyin:"o" },         // pi ke
	{ hanzi:"穒" , pinyin:"o" },         // ke
	{ hanzi:"壳" , pinyin:"ke" },        // qiao 
	{ hanzi:"隗" , pinyin:"wei" },       // kui
	{ hanzi:"鮱" , pinyin:"luo" },       // la
	{ hanzi:"落" , pinyin:"luo" },       // lao  la
	{ hanzi:"腊" , pinyin:"la" },        // xi 
	{ hanzi:"蜡" , pinyin:"la" },        // zha 
	{ hanzi:"癞" , pinyin:"lai" },       // la
	{ hanzi:"莨" , pinyin:"liang" },     // lang
	{ hanzi:"潦" , pinyin:"liao" },      // lao
	{ hanzi:"姥" , pinyin:"lao" },       // mu 
	{ hanzi:"獠" , pinyin:"liao" },      // lao
	{ hanzi:"络" , pinyin:"luo" },       // lao
	{ hanzi:"烙" , pinyin:"lao" },       // luo 
	{ hanzi:"朰" , pinyin:"te" },        // wu le
	{ hanzi:"榁" , pinyin:"mu" },        // le
	{ hanzi:"肋" , pinyin:"lei" },       // le
	{ hanzi:"乐" , pinyin:"yue" },       // le
	{ hanzi:"勒" , pinyin:"lei" },       // le
	{ hanzi:"漯" , pinyin:"luo" },       // ta lei
	{ hanzi:"棱" , pinyin:"leng" },      // ling 
	{ hanzi:"甅" , pinyin:"li" },        // wa 
	{ hanzi:"蠡" , pinyin:"li" },        // luo 
	{ hanzi:"栎" , pinyin:"li" },        // yue 
	{ hanzi:"跞" , pinyin:"li" },        // luo 
	{ hanzi:"俩" , pinyin:"liang" },     // lia
	{ hanzi:"飂" , pinyin:"liu" },       // liao
	{ hanzi:"蓼" , pinyin:"liao" },      // lu 
	{ hanzi:"挘" , pinyin:"lie" },       // ri 
	{ hanzi:"六" , pinyin:"liu" },       // lu 
	{ hanzi:"陆" , pinyin:"lu" },        // liu
	{ hanzi:"碌" , pinyin:"lu" },        // liu
	{ hanzi:"泷" , pinyin:"long" },      // shuang 
	{ hanzi:"弄" , pinyin:"nong" },      // long
	{ hanzi:"偻" , pinyin:"lou" },       // lv 
	{ hanzi:"露" , pinyin:"lu" },        // lou
	{ hanzi:"绿" , pinyin:"lv" },        // lu 
	{ hanzi:"捋" , pinyin:"luo" },       // lv
	{ hanzi:"率" , pinyin:"shuai" },     // lv
	{ hanzi:"呣" , pinyin:"m" },         // mou 
	{ hanzi:"姆" , pinyin:"mu" },        // m
	{ hanzi:"唜" , pinyin:"si" },        // ma
	{ hanzi:"魸" , pinyin:"na" },        // zi ma 日
	{ hanzi:"孖" , pinyin:"zi" },        // ma
	{ hanzi:"抹" , pinyin:"mo" },        // ma
	{ hanzi:"摩" , pinyin:"mo" },        // ma
	{ hanzi:"埋" , pinyin:"mai" },       // man 
	{ hanzi:"脉" , pinyin:"mai" },       // mo 
	{ hanzi:"蔓" , pinyin:"man" },       // wan
	{ hanzi:"尨" , pinyin:"meng" },      // mang
	{ hanzi:"氓" , pinyin:"mang" },      // meng 
	{ hanzi:"冒" , pinyin:"mao" },       // mo 
	{ hanzi:"乄" , pinyin:"shi" },       // me 日
	{ hanzi:"匁" , pinyin:"mo" },        // ne me 日
	{ hanzi:"没" , pinyin:"mei" },       // mo 
	{ hanzi:"糜" , pinyin:"mi" },        // mei
	{ hanzi:"谜" , pinyin:"mi" },        // mei
	{ hanzi:"汶" , pinyin:"wen" },       // men
	{ hanzi:"亹" , pinyin:"wei" },       // men
	{ hanzi:"黾" , pinyin:"min" },       // meng
	{ hanzi:"鼡" , pinyin:"ne" },        // zu mi 日
	{ hanzi:"蓂" , pinyin:"ming" },      // mi
	{ hanzi:"免" , pinyin:"mian" },      // wen 
	{ hanzi:"渑" , pinyin:"mian" },      // sheng 
	{ hanzi:"缪" , pinyin:"miu" },       // mou miao
	{ hanzi:"乜" , pinyin:"mie" },       // nie 
	{ hanzi:"丆" , pinyin:"ne" },        // o ye mo
	{ hanzi:"乮" , pinyin:"ri" },        // mo 韩
	{ hanzi:"无" , pinyin:"wu" },        // mo
	{ hanzi:"模" , pinyin:"mo" },        // mu 
	{ hanzi:"万" , pinyin:"wan" },       // mo
	{ hanzi:"莫" , pinyin:"mo" },        // mu 
	{ hanzi:"袜" , pinyin:"wa" },        // mo
	{ hanzi:"牟" , pinyin:"mou" },       // mu 
	{ hanzi:"那" , pinyin:"na" },        // ne nei nuo 
	{ hanzi:"南" , pinyin:"nan" },       // na
	{ hanzi:"哪" , pinyin:"na" },        // nai ne nei 
	{ hanzi:"内" , pinyin:"nei" },       // na
	{ hanzi:"呐" , pinyin:"na" },        // ne 
	{ hanzi:"娜" , pinyin:"na" },        // nuo 
	{ hanzi:"艿" , pinyin:"nai" },       // reng 
	{ hanzi:"呶" , pinyin:"nao" },       // nu 
	{ hanzi:"縇" , pinyin:"o" },         // se ne
	{ hanzi:"唔" , pinyin:"wu" },        // ng
	{ hanzi:"哛" , pinyin:"po" },        // pu ni
	{ hanzi:"鳰" , pinyin:"o" },         // ni 日
	{ hanzi:"溺" , pinyin:"ni" },        // niao 
	{ hanzi:"嶷" , pinyin:"yi" },        // ni 
	{ hanzi:"粘" , pinyin:"zhan" },      // nian
	{ hanzi:"捻" , pinyin:"nian" },      // nie 
	{ hanzi:"辗" , pinyin:"zhan" },      // nian
	{ hanzi:"尿" , pinyin:"niao" },      // sui 
	{ hanzi:"宁" , pinyin:"ning" },      // zhu 
	{ hanzi:"莻" , pinyin:"xi" },        // nu 韩
	{ hanzi:"喏" , pinyin:"nuo" },       // re 
	{ hanzi:"疟" , pinyin:"nve" },       // yao 
	{ hanzi:"区" , pinyin:"qu" },        // ou 
	{ hanzi:"巼" , pinyin:"xi" },        // pa 韩
	{ hanzi:"派" , pinyin:"pai" },       // pa
	{ hanzi:"闏" , pinyin:"ying" },      // pai 韩
	{ hanzi:"迫" , pinyin:"po" },        // pai
	{ hanzi:"胖" , pinyin:"pang" },      // pan
	{ hanzi:"拚" , pinyin:"pin" },       // pan
	{ hanzi:"喸" , pinyin:"xi" },        // pao 韩
	{ hanzi:"朴" , pinyin:"pu" },        // po  piao
	{ hanzi:"娉" , pinyin:"pin" },       // ping 
	{ hanzi:"乶" , pinyin:"po" },        // ri 韩 
	{ hanzi:"栖" , pinyin:"qi" },        // xi 
	{ hanzi:"踦" , pinyin:"qi" },        // yi 
	{ hanzi:"蹊" , pinyin:"qi" },        // xi 
	{ hanzi:"圻" , pinyin:"qi" },        // yin 
	{ hanzi:"俟" , pinyin:"si" },        // qi
	{ hanzi:"綮" , pinyin:"qing" },      // qi
	{ hanzi:"契" , pinyin:"qi" },        // xie 
	{ hanzi:"砌" , pinyin:"qie" },       // qi
	{ hanzi:"铅" , pinyin:"qian" },      // yan 
	{ hanzi:"嗛" , pinyin:"xian" },      // qian
	{ hanzi:"荨" , pinyin:"qian" },      // xun 
	{ hanzi:"羬" , pinyin:"xian" },      // qian
	{ hanzi:"纤" , pinyin:"xian" },      // qian
	{ hanzi:"茜" , pinyin:"xi" },        // qian
	{ hanzi:"倩" , pinyin:"qian" },      // qing 
	{ hanzi:"慊" , pinyin:"qie" },       // qian
	{ hanzi:"雀" , pinyin:"que" },       // qiao
	{ hanzi:"鞘" , pinyin:"qiao" },      // shao 
	{ hanzi:"亲" , pinyin:"qin" },       // qing 
	{ hanzi:"覃" , pinyin:"tan" },       // qin
	{ hanzi:"溱" , pinyin:"qin" },       // zhen 
	{ hanzi:"鲭" , pinyin:"qing" },      // zheng 
	{ hanzi:"蝤" , pinyin:"qiu" },       // you 
	{ hanzi:"券" , pinyin:"quan" },      // xuan 
	{ hanzi:"芍" , pinyin:"shao" },      // que
	{ hanzi:"荛" , pinyin:"yao" },       // rao
	{ hanzi:"若" , pinyin:"ruo" },       // re
	{ hanzi:"葚" , pinyin:"shen" },      // ren
	{ hanzi:"乽" , pinyin:"za" },        // ri 韩
	{ hanzi:"乼" , pinyin:"zu" },        // ri 韩
	{ hanzi:"乺" , pinyin:"sao" },       // ri 韩
	{ hanzi:"鑓" , pinyin:"ya" },        // ri 日
	{ hanzi:"虄" , pinyin:"sa" },        // ri 韩
	{ hanzi:"扨" , pinyin:"te" },        // sa 日
	{ hanzi:"苆" , pinyin:"su" },        // sa 日
	{ hanzi:"栍" , pinyin:"ying" },      // sa 韩
	{ hanzi:"摋" , pinyin:"sa" },        // sha 
	{ hanzi:"思" , pinyin:"si" },        // sai
	{ hanzi:"塞" , pinyin:"sai" },       // se 
	{ hanzi:"糁" , pinyin:"shen" },      // san
	{ hanzi:"燥" , pinyin:"zao" },       // sao
	{ hanzi:"色" , pinyin:"se" },        // shai 
	{ hanzi:"杉" , pinyin:"shan" },      // sha
	{ hanzi:"莎" , pinyin:"sha" },       // suo 
	{ hanzi:"挲" , pinyin:"sha" },       // suo 
	{ hanzi:"噎" , pinyin:"ye" },        // sha
	{ hanzi:"奢" , pinyin:"she" },       // sha
	{ hanzi:"啑" , pinyin:"ti" },        // sha
	{ hanzi:"厦" , pinyin:"xia" },       // sha
	{ hanzi:"酾" , pinyin:"shi" },       // shai
	{ hanzi:"栅" , pinyin:"shan" },      // zha 
	{ hanzi:"剡" , pinyin:"yan" },       // shan
	{ hanzi:"汤" , pinyin:"tang" },      // shang
	{ hanzi:"蛸" , pinyin:"xiao" },      // shao
	{ hanzi:"苕" , pinyin:"shao" },      // tiao 
	{ hanzi:"畬" , pinyin:"she" },       // yu 
	{ hanzi:"折" , pinyin:"zhe" },       // she
	{ hanzi:"蛇" , pinyin:"she" },       // yi 
	{ hanzi:"叶" , pinyin:"ye" },        // xie she
	{ hanzi:"拾" , pinyin:"shi" },       // she
	{ hanzi:"歙" , pinyin:"she" },       // xi 
	{ hanzi:"谁" , pinyin:"shui" },      // shei
	{ hanzi:"籡" , pinyin:"shi" },       // shen 日
	{ hanzi:"莘" , pinyin:"shen" },      // xin 
	{ hanzi:"什" , pinyin:"shen" },      // shi 
	{ hanzi:"椹" , pinyin:"shen" },      // zhen 
	{ hanzi:"狌" , pinyin:"sheng" },     // xing 
	{ hanzi:"省" , pinyin:"sheng" },     // xing 
	{ hanzi:"嘘" , pinyin:"xu" },        // shi
	{ hanzi:"识" , pinyin:"shi" },       // zhi 
	{ hanzi:"食" , pinyin:"shi" },       // si yi 
	{ hanzi:"氏" , pinyin:"shi" },       // zhi 
	{ hanzi:"似" , pinyin:"si" },        // shi
	{ hanzi:"峙" , pinyin:"zhi" },       // shi
	{ hanzi:"螫" , pinyin:"shi" },       // zhe 
	{ hanzi:"熟" , pinyin:"shu" },       // shou
	{ hanzi:"荼" , pinyin:"tu" },        // shu
	{ hanzi:"属" , pinyin:"shu" },       // zhu 
	{ hanzi:"术" , pinyin:"shu" },       // zhu 
	{ hanzi:"庶" , pinyin:"shu" },       // zhu 
	{ hanzi:"说" , pinyin:"shuo" },      // tuo yue shui
	{ hanzi:"忪" , pinyin:"song" },      // zhong 
	{ hanzi:"宿" , pinyin:"su" },        // xiu 
	{ hanzi:"缩" , pinyin:"suo" },       // su
	{ hanzi:"燵" , pinyin:"tui" },       // ta 日
	{ hanzi:"拓" , pinyin:"tuo" },       // ta
	{ hanzi:"潭" , pinyin:"tan" },       // xun 
	{ hanzi:"陶" , pinyin:"tao" },       // yao 
	{ hanzi:"罀" , pinyin:"yo" },        // zhao te 日
	{ hanzi:"忒" , pinyin:"tui" },       // te
	{ hanzi:"擿" , pinyin:"ti" },        // zhi 
	{ hanzi:"荑" , pinyin:"yi" },        // ti
	{ hanzi:"裼" , pinyin:"xi" },        // ti
	{ hanzi:"僮" , pinyin:"tong" },      // zhuang 
	{ hanzi:"侻" , pinyin:"tuo" },       // tui
	{ hanzi:"褪" , pinyin:"tui" },       // tun 
	{ hanzi:"屯" , pinyin:"tun" },       // zhun 
	{ hanzi:"崴" , pinyin:"wei" },       // wai
	{ hanzi:"菀" , pinyin:"wan" },       // yu 
	{ hanzi:"尢" , pinyin:"you" },       // wang
	{ hanzi:"亡" , pinyin:"wang" },      // wu 
	{ hanzi:"圩" , pinyin:"wei" },       // xu 
	{ hanzi:"尾" , pinyin:"wei" },       // yi 
	{ hanzi:"尉" , pinyin:"wei" },       // yu 
	{ hanzi:"遗" , pinyin:"yi" },        // wei
	{ hanzi:"蔚" , pinyin:"wei" },       // yu 
	{ hanzi:"挝" , pinyin:"wo" },        // zhua 
	{ hanzi:"涴" , pinyin:"wan" },       // yuan wo 
	{ hanzi:"於" , pinyin:"yu" },        // wu
	{ hanzi:"铻" , pinyin:"wu" },        // yu 
	{ hanzi:"夞" , pinyin:"yi" },        // xi 韩
	{ hanzi:"硳" , pinyin:"ze" },        // xi 韩
	{ hanzi:"褶" , pinyin:"zhe" },       // xi
	{ hanzi:"洗" , pinyin:"xi" },        // xian 
	{ hanzi:"铣" , pinyin:"xi" },        // xian 
	{ hanzi:"县" , pinyin:"xian" },      // xuan 
	{ hanzi:"削" , pinyin:"xiao" },      // xue 
	{ hanzi:"邪" , pinyin:"xie" },       // ye 
	{ hanzi:"荥" , pinyin:"ying" },      // xing
	{ hanzi:"褎" , pinyin:"you" },       // xiu
	{ hanzi:"吁" , pinyin:"yu" },        // xu 
	{ hanzi:"芧" , pinyin:"zhu" },       // xu
	{ hanzi:"窨" , pinyin:"yin" },       // xun
	{ hanzi:"厌" , pinyin:"yan" },       // ya
	{ hanzi:"咽" , pinyin:"yan" },       // ye 
	{ hanzi:"殷" , pinyin:"yin" },       // yan
	{ hanzi:"芫" , pinyin:"yuan" },      // yan
	{ hanzi:"约" , pinyin:"yue" },       // yao
	{ hanzi:"繇" , pinyin:"yao" },       // you zhou 
	{ hanzi:"钥" , pinyin:"yao" },       // yue 
	{ hanzi:"拽" , pinyin:"zhuai" },     // ye
	{ hanzi:"育" , pinyin:"yu" },        // yo
	{ hanzi:"喁" , pinyin:"yong" },      // yu 
	{ hanzi:"柚" , pinyin:"you" },       // zhu 
	{ hanzi:"粥" , pinyin:"zhou" },      // yu
	{ hanzi:"熨" , pinyin:"yun" },       // yu
	{ hanzi:"员" , pinyin:"yuan" },      // yun 
	{ hanzi:"扎" , pinyin:"zha" },       // za
	{ hanzi:"拶" , pinyin:"zan" },       // za
	{ hanzi:"囋" , pinyin:"za" },        // zan 
	{ hanzi:"咋" , pinyin:"za" },        // ze zha 
	{ hanzi:"甾" , pinyin:"zai" },       // zi 
	{ hanzi:"仔" , pinyin:"zi" },        // zai
	{ hanzi:"奘" , pinyin:"zang" },      // zhuang 
	{ hanzi:"责" , pinyin:"ze" },        // zhai 
	{ hanzi:"择" , pinyin:"ze" },        // zhai 
	{ hanzi:"综" , pinyin:"zong" },      // zeng
	{ hanzi:"着" , pinyin:"zhuo" },      // zhao
	{ hanzi:"啁" , pinyin:"zhou" },      // zhao
	{ hanzi:"爪" , pinyin:"zhua" },      // zhao
	{ hanzi:"这" , pinyin:"zhe" },       // zhei 
	{ hanzi:"吱" , pinyin:"zhi" },       // zi 
	{ hanzi:"祝" , pinyin:"zhu" },       // zhou
	{ hanzi:"躅" , pinyin:"zhuo" },      // zhu
	{ hanzi:"转" , pinyin:"zhuan" },     // zhuai
	{ hanzi:"赚" , pinyin:"zhuan" },     // zuan 
	{ hanzi:"篹" , pinyin:"zuan" },      // zhuan
	{ hanzi:"觜" , pinyin:"zui" },       // zi
	{ hanzi:"鲅" , pinyin:"ba" },        // bo 
	{ hanzi:"" , pinyin:"pa" },        // ba
	{ hanzi:"扳" , pinyin:"ban" },       // pan 
	{ hanzi:"般" , pinyin:"ban" },       // bo pan 
	{ hanzi:"剥" , pinyin:"bao" },       // bo 
	{ hanzi:"趵" , pinyin:"bao" },       // bo 
	{ hanzi:"蕃" , pinyin:"fan" },       // bo
	{ hanzi:"嗀" , pinyin:"gu" },        // hu 
	{ hanzi:"桁" , pinyin:"heng" },      // hang
	{ hanzi:"珩" , pinyin:"heng" },      // hang
	{ hanzi:"牙" , pinyin:"ya" },        // he
	{ hanzi:"" , pinyin:"song" },      // yu 
	{ hanzi:"嘬" , pinyin:"zuo" },       // chuai
	{ hanzi:"撮" , pinyin:"cuo" },       // zuo 
	{ hanzi:"笮" , pinyin:"zuo" },       // ze
	{ hanzi:"琢" , pinyin:"zhuo" },      // zuo 
];


/*
    0. 汉字拼音表，来源于 http://xh.5156edu.com/pinyi.html （需要自己获取数据）
    1. 在'bo'添加'卜' ; 'de'添加'的' ; 'wan'添加'涴' ; 'ta'添加'他'
    （获取到的数据有缺失，是网站的问题，这里直接补全）
    2. ü 用 v 代替
    3. hanziTableS hanziTables[g_length_hanziTables]
*/
let hanziTables = [
    { first_py:"a",full_py:"a", hanzis:"吖阿呵啊腌锕錒嗄厑" },
    { first_py:"a",full_py:"ao", hanzis:"凹柪梎軪熬爊敖厫隞蔜遨廒嗷嗸獓嶅滶獒摮璈磝螯聱翱翶謷謸鳌翺嚣鏖鷔鰲鼇艹夭芺抝拗袄镺媪媼襖岙岰垇坳傲奡奥奧骜嫯慠懊墺澳嶴擙鏊驁澚鱜" },
    { first_py:"a",full_py:"ang", hanzis:"肮骯卬仰岇昂昻枊盎醠" },
    { first_py:"a",full_py:"ai", hanzis:"哎哀诶唉娭挨埃溾嗳锿鎄捱皑啀凒溰敱敳嘊皚癌騃佁毐昹欸娾矮蔼躷噯濭藹譪霭靄艾阨伌爱砹硋隘嗌嫒塧碍愛叆暧瑷僾噫壒懓嬡薆鴱餲璦曖懝皧瞹馤礙譺鑀靉閊魞﨟鱛鱫" },
    { first_py:"a",full_py:"an", hanzis:"厂广安侒峖桉氨庵偣谙菴萻葊媕腤痷鹌誝蓭鞍鞌諳盦馣鮟盫鵪鶕韽玵啽雸儑垵俺唵埯铵晻揞罯銨屵犴岸按洝荌胺豻案婩隌堓暗貋錌闇黯" },
    { first_py:"b",full_py:"bai", hanzis:"挀掰白犤百伯佰陌柏栢捭絔摆擺襬庍呗拝败拜敗猈稗粺薭贁韛瓸竡粨兡" },
    { first_py:"b",full_py:"ba", hanzis:"丷八仈巴叭朳玐吧岜扷芭夿疤柭釟蚆粑笆捌哵羓豝鲃叐茇妭拔炦胈癹菝軷詙跋颰魃鼥把钯鈀靶伯弝坝爸杷垻罢耙跁鲅罷鮁覇矲霸壩灞欛抜鎺鯐" },
    { first_py:"b",full_py:"ban", hanzis:"扳肦攽班般颁斑斒搬頒鳻瘢螌褩癍辬阪岅坂板版昄瓪钣粄舨鈑蝂魬闆办半伴扮拌姅绊坢怑柈秚絆湴鉡靽辦瓣螁" },
    { first_py:"b",full_py:"bang", hanzis:"邦帮垹梆捠浜邫幇幚縍幫鞤绑綁榜牓膀玤挷旁蚌棒棓傍谤蒡搒塝稖蜯镑磅艕謗鎊" },
    { first_py:"b",full_py:"bao", hanzis:"勹包苞孢炮枹胞剥剝笣龅煲裦褒蕔襃闁齙窇雹薄宝饱怉鸨保宲珤葆堡堢媬寚飽飹褓駂鳵鴇緥賲寳寶靌勽刨报抱铇豹趵蚫菢袌報鉋鲍骲髱暴虣鮑曓儤瀑爆犦曝忁鑤佨藵" },
    { first_py:"b",full_py:"ben", hanzis:"奔泍贲犇锛錛本苯奙畚翉楍夯坌倴逩桳笨捹渀撪" },
    { first_py:"b",full_py:"bei", hanzis:"陂卑杯柸背盃桮椑揹悲鹎碑藣鵯北鉳贝狈孛邶貝牬昁苝备郥钡被倍俻狽悖梖偝偹鄁珼琲惫軰備僃棓辈焙蓓蛽碚愂禙犕褙誖鞁骳鋇輩糒憊鞴鐾唄" },
    { first_py:"b",full_py:"beng", hanzis:"伻祊奟崩绷閍絣痭嵭嘣綳繃甭甮埄埲菶琫琣鞛迸泵蚌逬揼塴甏镚蹦鏰" },
    { first_py:"b",full_py:"bi", hanzis:"皀屄偪逼毴楅榌豍鵖螕鲾鎞鰏荸鼻匕比朼夶吡妣沘佊疕彼毞柀秕笔粃舭俾啚筆鄙箄聛貏币必毕闭庇佖诐芘邲迊坒怭怶苾妼咇泌畀畁哔荜陛贲毖柲珌疪秘铋毙狴畢袐粊笓閉閇婢庳萆萞梐敝赑堛愊愎皕禆弼弻湢詖筚賁貱蜌裨辟跸閟飶鉍滗滭嗶彃蓖蓽腷睥睤痹痺煏熚碧蔽弊鄪獙幣綼箅箆馝髲駜襅幤潷罼獘壁廦嬖避薜篦篳縪觱鮅蹕髀濞斃臂奰鏎饆鄨璧繴襣襞鞸魓韠躄躃驆鷝鐴贔朇鷩鼊萙蛯嬶" },
    { first_py:"b",full_py:"bian", hanzis:"边炞砭笾萹编猵煸牑甂箯蝙糄編鞕鍽鳊獱邉邊鞭鯿鯾籩贬扁窆匾貶惼褊稨碥鴘藊卞弁抃汳汴苄釆忭玣变変昪便覍徧遍缏揙閞辡諚緶艑辨辩辧辫辮辯變峅" },
    { first_py:"b",full_py:"biao", hanzis:"杓标飑骉髟彪淲猋脿颮滮摽骠蔈幖墂麃標熛膘镖瘭磦飙飚儦颷謤藨瀌爂鏢贆臕穮镳飆飇飈飊鑣驫嫑表婊裱諘錶褾檦俵鳔鋲" },
    { first_py:"b",full_py:"bie", hanzis:"憋瘪蟞鳖癟鱉鼈虌龞别別莂蛂徶襒蹩彆" },
    { first_py:"b",full_py:"bin", hanzis:"邠玢宾彬梹椕傧斌滨缤賓賔豩槟瑸镔儐濒頻豳濱濵虨璸檳瀕霦繽蠙鑌顮摈殡膑髩鬂擯殯臏髌鬓髕鬢" },
    { first_py:"b",full_py:"bing", hanzis:"冫仌氷并冰兵屏栟掤槟丙邴陃苪怲抦秉昞昺炳柄饼绠眪蛃偋寎棅鈵禀稟鉼餅餠鞞幷並併庰倂栤竝病窉傡摒誁鮩靐垪鞆" },
    { first_py:"b",full_py:"bo", hanzis:"卜癶癷波拨玻饽钵盋砵哱剥般趵缽紴袰菠啵溊碆鉢鲅僠蕃嶓播撥餑礡蹳驋鱍仢伯驳孛肑瓝泊狛帛郣勃侼胉柏袯瓟秡钹铂浡挬亳萡淿脖袹舶鹁渤葧博猼馎愽搏鈸鉑鲌魄馛駁艊箔牔煿膊僰镈踣鋍馞駮鮊薄謈襏簙餺鵓鎛嚗懪髆髉糪襮欂礴鑮跛簸孹檗擘譒蘗畓蔔" },
    { first_py:"b",full_py:"bu", hanzis:"逋庯峬钸晡鈽誧餔錻鳪轐醭卜卟补哺捕堡補鵏鸔不布吥佈步歨歩怖咘钚柨悑部勏捗埔埗荹埠瓿鈈蔀廍踄郶餢篰簿巭" },
    { first_py:"c",full_py:"ca", hanzis:"拆擦攃嚓礤礸遪乲" },
    { first_py:"c",full_py:"cai", hanzis:"偲猜才财材財裁纔毝采倸啋寀婇彩採埰棌睬跴綵踩宷菜蔡縩" },
    { first_py:"c",full_py:"can", hanzis:"参參叄骖飡湌叅喰傪嬠餐驂残蚕惭殘慚蝅慙蠺蠶惨朁慘憯穇篸黪黲灿掺孱粲薒澯燦璨謲儏爘" },
    { first_py:"c",full_py:"cang", hanzis:"仓仺伧苍沧鸧舱倉傖凔滄蒼獊嵢螥艙鶬臧藏鑶賶濸" },
    { first_py:"c",full_py:"cao", hanzis:"撡操糙曺曹蓸嘈嶆漕慒槽褿螬艚鏪艸草愺懆騲肏鄵襙鼜" },
    { first_py:"c",full_py:"ce", hanzis:"夨册冊侧厕荝拺测恻敇粣笧萗厠側萴策測廁惻筴筞蓛箣憡簎猠硛" },
    { first_py:"c",full_py:"cen", hanzis:"参嵾岑涔埁笒梣" },
    { first_py:"c",full_py:"ceng", hanzis:"噌层曾層嶒竲驓蹭" },
    { first_py:"c",full_py:"cha", hanzis:"叉扱扠杈臿差挿偛馇插揷嗏喳锸碴銟艖疀嚓鍤餷茬茶垞查査秅猹嵖搽靫詧楂槎察檫衩蹅镲鑔奼汊岔刹侘诧剎姹咤紁詫" },
    { first_py:"c",full_py:"chai", hanzis:"芆肞钗拆差釵犲侪柴豺祡喍儕茝虿訍袃瘥蠆囆" },
    { first_py:"c",full_py:"chan", hanzis:"辿觇梴掺搀覘裧摻鋓幨襜攙苂单谗婵馋湹孱棎禅煘缠蝉獑僝誗鋋儃廛嬋潺潹緾澶磛鄽螹毚蟬瀍酁儳蟾劖壥嚵瀺巉欃纏纒躔镵艬讒鑱饞产刬旵丳斺浐剗谄阐铲產産蒇剷摌滻蕆幝諂閳骣燀簅冁醦繟鏟譂闡囅灛讇忏硟摲懴颤懺羼韂顫" },
    { first_py:"c",full_py:"chang", hanzis:"伥昌倡倀菖阊娼猖淐琩锠裮錩閶鲳鯧鼚长仧仩场兏肠苌镸長尝倘偿萇徜常瓺場腸甞裳塲嫦嘗膓瑺嚐償鲿鱨厂昶惝敞厰僘廠氅鋹怅玚畅鬯唱悵焻暢畼誯韔椙蟐" },
    { first_py:"c",full_py:"che", hanzis:"车伡車俥砗莗唓硨蛼尺扯偖撦屮彻迠坼烢聅硩掣頙撤澈徹瞮勶爡" },
    { first_py:"c",full_py:"chao", hanzis:"吵抄弨怊欩钞绰訬超鈔焯剿窼牊晁巢巣朝鼌鄛漅潮樔嘲窲罺鼂轈謿炒眧焣煼麨巐仦仯耖觘" },
    { first_py:"c",full_py:"chen", hanzis:"抻郴捵棽琛嗔綝賝諃瞋謓尘臣辰忱沉陈迧茞莀莐宸陳栕桭谌訦軙敐晨鈂愖煁蔯樄塵敶瘎霃諶螴薼麎曟鷐趻硶碜墋夦踸磣鍖贂衬疢称龀趁趂榇齓齔儭谶嚫櫬襯讖烥" },
    { first_py:"c",full_py:"cheng", hanzis:"阷泟爯柽棦称秤浾琤偁铛碀蛏晿牚赪靗憆稱摚撑撐噌樘緽頳赬瞠橕檉竀罉蟶穪鏿鐣饓丞成朾呈郕诚枨承荿宬娍峸洆城乗乘埕挰珹珵窚掁脭铖盛程揨堘裎絾筬惩椉棖誠塍塖溗酲鋮畻澄澂憕橙檙瀓懲騬侱徎逞骋悜庱睈騁鯎" },
    { first_py:"c",full_py:"chi", hanzis:"吃妛彨哧胵鸱蚩粚笞眵瓻喫訵絺嗤媸摛痴瞝殦噄誺螭鴟鵄魑癡齝攡彲黐弛驰池迟迡茌坻竾荎持匙蚳赿貾遅筂遟馳箎墀漦遲踟篪鍉謘尺叺伬呎肔齿侈卶垑胣蚇耻恥豉袳歯欼袲裭鉹齒褫彳叱斥杘赤饬灻抶侙勅恜炽勑翅翄敕烾湁啻飭雴傺腟痸鉓銐翤瘈遫憏瘛慗翨熾趩懘鶒鷘麶" },
    { first_py:"c",full_py:"chong", hanzis:"冲充沖忡茺涌浺珫翀舂嘃摏憧衝憃罿艟蹖虫种重隀崇崈漴褈蝩緟蟲爞宠埫寵铳揰銃" },
    { first_py:"c",full_py:"chou", hanzis:"抽紬搊篘瘳犨犫仇俦帱栦菗绸惆絒椆畴愁皗稠筹詶酬酧裯踌綢雔儔薵懤幬嬦檮燽雠疇籌醻躊讎讐雦丑丒吜杻杽偢瞅醜矁魗臭臰遚殠鮘" },
    { first_py:"c",full_py:"chua", hanzis:"欻" },
    { first_py:"c",full_py:"chu", hanzis:"出岀初摴樗貙齣刍处助除芻厨蒢豠滁锄雏鉏趎蒭媰蜍耡犓鋤篨廚橱櫉幮躇雛蹰櫥鶵躕杵础處椘楮储禇楚褚濋儲檚礎齭齼亍処竌豖绌怵泏竐欪畜俶敊埱絀珿傗鄐滀搐触閦諔儊嘼憷斶黜臅歜觸矗榋璴蟵" },
    { first_py:"c",full_py:"chuan", hanzis:"巛川氚穿瑏传舡舩船剶遄椽傳暷篅輲舛荈喘歂僢踳汌玔串钏釧猭賗鶨" },
    { first_py:"c",full_py:"chuang", hanzis:"刅创疮窓窗牎摐牕瘡窻床牀幢噇闯傸磢闖怆刱剏剙創愴" },
    { first_py:"c",full_py:"chuai", hanzis:"揣搋膗啜嘬膪踹" },
    { first_py:"c",full_py:"chui", hanzis:"吹炊龡垂埀陲倕桘菙捶搥棰椎圌腄锤槌箠錘鎚顀" },
    { first_py:"c",full_py:"chun", hanzis:"旾杶春萅媋堾椿槆暙瑃蝽箺輴橁櫄鶞鰆纯陙莼唇浱純脣淳湻犉鹑滣蒓蓴漘醇醕錞鶉鯙偆萶惷睶賰蠢" },
    { first_py:"c",full_py:"cong", hanzis:"匆苁囱囪忩茐枞怱悤棇葱楤蔥蓯骢漗聡聪聦熜潨樅樬暰瑽璁瞛蟌聰篵鍯繱鏦鏓騘驄从丛徔従從徖婃淙悰孮琮潀漎賨賩誴錝樷藂叢灇欉爜愡憁謥" },
    { first_py:"c",full_py:"ci", hanzis:"刺差呲玼疵趀偨跐骴縒髊蠀齹词珁茈茨垐柌祠兹瓷辝詞辞慈甆鹚磁雌餈飺糍辤薋嬨濨鴜礠辭鷀鶿此佌泚皉鮆朿次伺佽刾庛茦栨莿赐蛓絘賜螆閊" },
    { first_py:"c",full_py:"chuo", hanzis:"逴趠踔戳繛辶辵哾娖娕婼婥啜涰绰惙辍酫踀綽輟龊擉餟磭歠嚽齪鑡" },
    { first_py:"c",full_py:"cu", hanzis:"怚粗觕麁麄橻麤徂殂卒促脨猝酢媨瘄蔟趗誎醋憱趣踧噈瘯踿縬簇鼀蹙蹴蹵顣" },
    { first_py:"c",full_py:"cou", hanzis:"凑湊辏楱腠輳" },
    { first_py:"c",full_py:"cun", hanzis:"邨村皴踆澊墫竴膥存侟拵蹲刌忖寸籿" },
    { first_py:"c",full_py:"cuan", hanzis:"汆撺镩蹿攛躥鑹菆攒櫕巑欑穳窜殩熶篡簒竄爨" },
    { first_py:"c",full_py:"cui", hanzis:"崔脺嵟凗催缞墔慛榱獕摧槯磪縗鏙漼璀趡皠伜忰疩脆脃倅粋紣翆萃啐啛淬悴焠毳琗瘁翠綷粹膵膬竁襊濢顇臎" },
    { first_py:"c",full_py:"cuo", hanzis:"搓遳瑳磋撮醝蹉鎈虘嵯嵳睉痤蒫矬蔖瘥鹾酂鹺脞剉剒莝莡厝挫夎措逪锉错蓌銼錯" },
    { first_py:"d",full_py:"da", hanzis:"咑哒耷笚答嗒搭褡撘墶噠鎝鎉打达迏迖迚怛呾妲沓荙荅炟羍畗畣惮匒剳逹笪詚達跶靼瘩薘鞑蟽鐽韃龖龘大亣汏垯眔畓繨躂鶎" },
    { first_py:"d",full_py:"dang", hanzis:"当珰裆铛筜當儅噹澢璫襠蟷艡簹鐺闣挡党谠擋譡黨攩灙欓讜氹凼圵宕砀荡垱档菪婸逿愓瓽雼嵣潒碭瞊趤蕩壋檔璗盪礑簜蘯" },
    { first_py:"d",full_py:"dan", hanzis:"丹妉担单単眈砃耽耼郸聃躭酖單殚媅瘅匰鄲頕褝箪勯儋殫擔甔襌簞聸刐伔抌瓭玬胆衴紞疸掸赕亶馾撣撢賧黕膽黮黵旦石帎但诞狚泹沊柦唌疍蛋弹惮啖啗淡萏啿弾氮蜑腅觛誕窞蓞僤噉髧嘾彈憚憺禫澹駳鴠餤癉癚繵贉嚪饏霮" },
    { first_py:"d",full_py:"dai", hanzis:"呆呔待獃懛歹歺逮傣大代轪甙侢迨帒骀岱绐垈贷带玳殆柋怠軑貣帯帶埭蚮紿軚袋軩貸瑇跢廗叇曃蝳緿鴏黛艜戴簤瀻霴黱襶靆" },
    { first_py:"d",full_py:"de", hanzis:"的嘚恴得淂棏惪悳锝徳德鍀地底" },
    { first_py:"d",full_py:"dao", hanzis:"刀刂叨忉朷氘舠釖鱽魛螩捯导岛陦島捣倒祷禂搗隝嶋嶌導隯嶹擣壔蹈禱辺到帱悼焘菿盗盜道翢稲稻噵艔衜衟檤燾翿軇瓙纛乭﨩椡槝" },
    { first_py:"d",full_py:"dei", hanzis:"嘚得" },
    { first_py:"d",full_py:"deng", hanzis:"灯登豋僜噔嬁燈璒竳簦蹬等戥邓鄧隥凳嶝澄墱镫瞪磴櫈覴鐙艠" },
    { first_py:"d",full_py:"den", hanzis:"扥扽" },
    { first_py:"d",full_py:"dia", hanzis:"嗲" },
    { first_py:"d",full_py:"di", hanzis:"氐仾低彽奃岻秪袛隄羝埞啲堤提趆滴嘀镝磾鞮廸狄苖迪的籴唙荻涤敌梑啇笛靮觌滌髢馰頔翟嫡蔋蔐樀敵藡嚁豴蹢鏑覿糴鸐厎邸阺诋坘坻弤底呧抵拞柢牴砥掋菧軧觝詆骶聜鯳地坔杕旳弟玓苐枤怟埅帝俤娣递逓埊焍谛梊祶菂偙眱珶第釱睇揥媂蒂棣缔楴禘遞僀腣鉪碲蝃摕遰蔕墬墑甋蝭締慸諦踶嶳螮嚸" },
    { first_py:"d",full_py:"die", hanzis:"爹跌褺苵迭咥峌挕绖垤恎昳胅瓞眣耊谍眰戜絰臷镻詄趃跕畳喋耋惵堞揲殜叠楪牃牒跮碟褋蜨嵽蝶艓諜蹀鴩疂螲鲽蹛曡疉鰈疊氎哋幉" },
    { first_py:"d",full_py:"diao", hanzis:"刁叼汈刟虭凋彫奝弴蛁貂琱鳭碉鮉瞗錭鲷雕簓鼦鯛鵰鸟扚屌弔吊伄钓盄窎訋调铞铫掉釣鈟竨蓧銱銚雿魡調窵瘹鋽藋鑃" },
    { first_py:"d",full_py:"dian", hanzis:"敁掂厧傎嵮滇槇槙瘨颠蹎顛顚巅癫巓攧巔癲齻典奌点婰敟碘蒧蕇踮點电甸阽佃店坫垫扂玷钿惦婝淀琔奠殿鈿蜔電墊壂澱橂靛磹癜簟驔椣" },
    { first_py:"d",full_py:"diu", hanzis:"丢丟铥颩銩" },
    { first_py:"d",full_py:"ding", hanzis:"丁仃帄叮玎钉盯疔町虰耵酊釘靪艼奵顶頂鼎鼑嵿濎薡鐤订饤忊矴定訂飣铤萣啶椗腚锭碇碠錠顁磸" },
    { first_py:"d",full_py:"du", hanzis:"厾剢都阇督嘟醏闍独毒读渎牍椟犊裻読錖獨凟匵嬻瀆殰犢櫝牘瓄皾騳黩髑韣讀贕豄鑟韇韥黷讟肚笃堵赌琽睹賭覩篤芏杜妒妬度荰秺靯渡镀螙鍍殬斁蠧蠹叾獤" },
    { first_py:"d",full_py:"dou", hanzis:"吺剅都唗兜兠蔸橷篼唞斗阧抖枓钭陡蚪鈄吋豆郖读荳逗饾浢鬥渎酘毭梪脰痘閗窦鬦餖斣闘竇鬪鬬鬭乧" },
    { first_py:"d",full_py:"dong", hanzis:"东冬東咚苳岽昸氡鸫倲菄崬崠涷埬娻笗氭蝀鮗鼕鯟鶇董蕫嬞懂箽諌动冻侗垌恫栋胨迵姛峒挏洞凍胴戙動硐湩腖棟働駧霘鶫" },
    { first_py:"d",full_py:"dui", hanzis:"垖堆塠痽磓鴭鐜鐓頧队对兊兌対兑祋怼陮隊敦碓綐對憞憝錞镦薱濧懟瀩譈譵轛" },
    { first_py:"d",full_py:"duan", hanzis:"耑偳媏端褍鍴短段断葮缎塅煅瑖腶椴锻碫緞毈簖鍛斷躖籪" },
    { first_py:"d",full_py:"duo", hanzis:"多夛咄哆剟掇毲敠敪裰嚉夺度铎敚敓剫喥痥奪凙澤踱鐸驮朵朶杕饳剁沲哚挆柮柂垛垜埵缍舵崜惰媠椯躲躱趓跺綞亸鬌軃嚲奲刴陊陏挅尮桗堕跥飿墮憜墯鵽﨣鈬鯲" },
    { first_py:"d",full_py:"dun", hanzis:"吨惇敦蜳撴墩墪噸撉犜镦礅蹲蹾驐盹趸躉伅庉沌囤炖逇钝盾砘顿鈍遁頓楯遯潡燉踲碷壿" },
    { first_py:"e",full_py:"e", hanzis:"阿妸妿娿婀屙讹迗吪囮俄峉峨峩涐恶娥莪哦珴訛鈋皒锇睋鹅蛾誐磀噁鋨頟魤额額鵝鵞譌厄阸苊呃扼轭枙垩砨饿胺阏鄂谔萼遌遏崿愕頋腭锷鹗頞餩噩鳄騀戹岋呝砐砈咹咢姶匎蚅軛硆悪卾偔堊堨堮湂惡軶豟鈪琧廅搤搹僫蝁蕚遻餓颚閼擜諤覨鍔顎歞礘櫮鶚鰐鰪齃讍齶鑩鱷仒厑蛯旕鵈襨欕" },
    { first_py:"e",full_py:"en", hanzis:"奀恩蒽煾峎摁" },
    { first_py:"e",full_py:"ei", hanzis:"欸誒" },
    { first_py:"e",full_py:"eng", hanzis:"鞥椧" },
    { first_py:"e",full_py:"er", hanzis:"乻儿而児陑侕荋耏峏洏栭胹唲鸸袻聏輀鲕髵隭鴯鮞臑轜尔尒尓耳迩饵洱毦栮珥铒鉺餌爾駬薾邇二弍弐佴刵咡贰貮貳衈誀髶樲粫趰" },
    { first_py:"f",full_py:"fa", hanzis:"发冹沷発發酦彂乏伐姂坺垡茷阀疺罚栰笩筏傠瞂罰閥罸墢橃藅佱法峜砝灋珐琺髪髮蕟浌鍅" },
    { first_py:"f",full_py:"fang", hanzis:"匚方邡芳汸坊枋牥钫蚄淓趽鈁錺鴋防妨房肪鲂魴访仿彷纺昉昘瓬眆紡舫旊倣訪髣鶭放堏" },
    { first_py:"f",full_py:"fan", hanzis:"帆忛畨番勫蕃幡噃嬏憣旙旛繙翻藩轓颿飜籓鱕凡凣凢匥杋柉钒矾籵舤舧袢烦笲釩棥煩緐墦樊璠膰薠燔襎繁羳蹯鐇礬蘩瀿蠜鷭反払仮返橎犯氾汎奿饭泛贩范畈軓訉販笵盕梵軬飯飰滼嬎範輽瀪" },
    { first_py:"f",full_py:"feng", hanzis:"丰风凨仹凬妦沣凮枫盽疯砜封風峰峯偑桻烽堼葑崶渢猦锋犎楓蜂碸瘋篈僼鄷鋒檒豐鎽鏠酆蘴寷灃蠭靊飌麷冯夆沨浲逢溄堸馮艂漨缝摓綘縫讽覂唪諷凤奉俸湗焨煈赗鳯鳳鴌賵琒" },
    { first_py:"f",full_py:"fen", hanzis:"分芬帉吩纷氛昐玢衯紛翂躮訜酚棻梤鈖雰馚餴朆饙妢岎汾坟炃朌枌羒蚠蚡焚棼蒶隫魵蕡幩獖墳濆燌燓橨豮鼢羵鼖豶轒鐼馩黂粉黺份弅坋忿奋秎偾粪愤僨憤膹奮糞鲼瀵鱝竕瞓" },
    { first_py:"f",full_py:"fei", hanzis:"飞妃非飛菲啡婓婔渄绯扉猆暃靟裶蜚緋鲱霏馡餥騑騛鯡飝肥淝腓蜰朏胐匪诽奜悱棐斐翡榧蕜誹篚发芾吠狒沸怫杮废肺胇昲费厞剕陫俷疿萉屝廃費痱镄廢曊癈鼣蟦濷櫠鐨靅" },
    { first_py:"f",full_py:"fou", hanzis:"紑缶否妚缻缹雬殕鴀" },
    { first_py:"f",full_py:"fo", hanzis:"仏佛坲梻" },
    { first_py:"f",full_py:"fu", hanzis:"夫伕邞孚呋妋姇玞肤胕砆衭怤柎荂荴尃娐旉麸趺紨跗鈇稃綒筟鄜孵粰膚鳺麩敷麬糐麱懯乀巿弗凫伏甶佛刜芾芙芣扶拂泭岪绂绋咈帗苻茀枎怫服韨氟祓玸枹柫炥畐畉罘茯郛鳬俘垘洑浮哹莩蚨袚栿砩翇桴烰琈袱虙艴紱紼符笰菔匐涪幅葍絥罦棴鳧艀鉘鉜颫辐福蜉綍箙稪榑韍豧髴鴔蝠幞澓輻踾鮄諨黻襆癁鮲襥鵩鶝阝父甫抚拊弣府斧郙俛俌俯釜釡捬脯辅腑盙焤蜅滏腐輔頫嘸撫鬴簠鯱黼讣付妇负附彿咐驸坿竎阜訃負赴复祔峊袝蚥蚹副婦婏冨偩傅復萯媍富赋蛗秿覄詂鲋腹椱缚赙複褔蝮蝜緮蕧賦駙鮒輹嬔縛賻鳆鍑鍢馥覆鰒酜﨓椨禣" },
    { first_py:"g",full_py:"ga", hanzis:"夹旮伽呷咖嘎嘠轧钆釓尜噶錷玍尕尬魀乫凩軈" },
    { first_py:"g",full_py:"gai", hanzis:"侅该陔郂荄姟峐垓赅晐祴畡絯隑賅賌豥該忋改絠丐乢匃匄芥钙盖鈣摡溉葢蓋戤概槩漑槪瓂" },
    { first_py:"g",full_py:"gang", hanzis:"冈冮刚扛纲岗杠肛疘矼牨岡钢缸罡剛堈掆釭犅棡摃堽罁綱鋼鎠崗港焵焹筻槓戆戅戇" },
    { first_py:"g",full_py:"gan", hanzis:"干甘迀奸忓杆攼玕肝姏泔苷坩矸竿柑酐疳粓凲尴尲筸鳱漧尶尷魐仠芉皯衦秆赶笴桿敢稈感澉趕橄澸擀簳鳡鱤汵旰盰绀凎倝淦紺詌骭幹榦檊贑赣贛灨" },
    { first_py:"g",full_py:"gao", hanzis:"羔皋高羙髙皐臯膏睾槔槹橰糕篙餻韟櫜鼛鷎鷱夰杲菒稁搞缟槁槀暠稿稾镐縞藁藳檺鎬告郜勂诰峼祮祰锆筶誥禞鋯吿" },
    { first_py:"g",full_py:"gei", hanzis:"给給" },
    { first_py:"g",full_py:"ge", hanzis:"戈仡犵扢纥圪戓肐牫疙饹咯哥胳格鸽袼搁割滒歌戨鴚鴿謌擱鎶呄匌佮茖阁挌革鬲敋葛隔裓蛤蛒臵愅觡嗝滆塥搿槅膈閤閣鞈骼韐镉獦諽輵鮯鎘韚騔鞷轕个合各哿盖舸嗰虼個铬硌箇鉻乬巪叾唟彁櫊" },
    { first_py:"g",full_py:"geng", hanzis:"更刯庚畊耕浭菮赓焿絚鹒縆緪賡羮鶊羹郠莄哽峺挭绠埂耿颈梗綆鲠骾鯁堩暅椩" },
    { first_py:"g",full_py:"gen",hanzis:"根跟哏艮亘亙茛揯搄" },
    { first_py:"g",full_py:"gu",hanzis:"估杚姑沽泒孤苽咕呱轱柧骨鸪罛唂唃家菰菇蛄笟軱軲觚辜酤蓇鈲毂稒箍箛篐嫴橭鴣鮕鹘夃古诂汩谷股苦牯羖贾钴罟蛊啒淈愲尳詁鹄馉鈷榾嗀鼓鼔榖嘏皷穀縎糓薣濲臌皼餶轂盬瞽瀔鶻蠱固故顾凅牿梏崮崓堌棝雇祻锢痼僱錮鲴鯝顧逧脵傦" },
    { first_py:"g",full_py:"gou",hanzis:"勾句沟佝枸钩痀袧鈎缑鉤溝褠緱篝簼鞲韝芶苟狗岣耇耉玽蚼笱耈豿诟坸购构姤垢冓够夠啂訽詬雊遘彀媾搆煹觏構撀購覯" },
    { first_py:"g",full_py:"gong",hanzis:"工弓公厷功共红杛攻供侊肱糼糿宫宮恭蚣躬龚匑幊愩塨觥躳慐匔碽髸觵龏龔廾巩汞拱栱拲珙輁鞏贡唝貢嗊熕赣" },
    { first_py:"g",full_py:"guai",hanzis:"乖摑叏拐柺枴罫箉夬怪恠" },
    { first_py:"g",full_py:"gua",hanzis:"瓜刮呱胍栝桰鸹歄煱趏劀緺踻颳鴰騧冎叧剐剮寡卦诖坬挂掛啩罣絓詿褂颪" },
    { first_py:"g",full_py:"guan",hanzis:"关观纶官冠矜覌倌莞蒄棺窤関瘝癏観闗鳏關鰥鱞觀馆琯筦痯管輨錧館璭舘鳤卝毌丱串贯泴掼涫惯悺貫悹祼慣潅摜遦樌盥罆雚躀鏆灌瓘爟矔鹳礶罐鑵鸛鱹欟" },
    { first_py:"g",full_py:"gui",hanzis:"归圭妫龟邽规茥闺皈胿珪帰亀硅袿規廆椝媯郌瑰摫閨鲑嫢嬀槻槼龜璝瞡鮭歸雟鬶嶲騩瓌鬹蘬宄氿轨庋匦陒佹诡姽垝恑攱癸軌鬼祪庪匭晷湀蛫觤詭厬簋蟡攰昋刿刽炅炔柜贵桂桧椢猤筀貴跪蓕瞆螝撌劌劊槶樻檜禬瞶癐襘櫃鐀鳜鞼鑎鱖鱥櫷" },
    { first_py:"g",full_py:"guang",hanzis:"光灮炗炚炛茪咣姯洸垙烡桄珖胱輄僙銧黆广広犷廣獷臩俇逛臦" },
    { first_py:"g",full_py:"gun",hanzis:"丨衮袞绲惃辊棍蓘滚滾蔉緄緷輥鲧磙鮌鯀睔謴" },
    { first_py:"g",full_py:"guo",hanzis:"过呙咶涡埚郭堝啯猓崞锅楇聒鈛瘑墎濄蝈彉嘓鍋彍蟈懖囯国囶囻圀國帼掴腘漍聝幗蔮慖虢膕馘簂果菓馃淉惈褁椁槨蜾粿綶裹輠餜過腂鐹" },
    { first_py:"h",full_py:"han",hanzis:"犴佄顸哻蚶酣頇谽嫨憨馠魽鼾邗汗邯含函凾虷唅娢浛圅焓梒晗琀涵崡嵅寒韩甝筨蜬鋡澏韓罕浫喊蔊豃厈汉屽扞闬旱垾悍猂莟捍涆菡焊晘釬閈皔睅蛿傼馯感颔漢撖蜭熯銲鋎暵頷憾螒翰撼顄駻雗譀瀚鶾兯爳" },
    { first_py:"h",full_py:"hai",hanzis:"咍咳嗨还孩骸海胲烸酼醢亥妎骇害氦餀嗐駭駴饚塰" },
    { first_py:"h",full_py:"ha",hanzis:"呵哈紦铪鉿虾蛤奤乤扖溌噺鎺鱩" },
    { first_py:"h",full_py:"hao",hanzis:"茠蒿薅薧嚆乚毜皋蚝毫椃嗥獆貉豪獔噑嘷獋儫濠壕嚎蠔籇譹好郝号昊昦侴秏悎耗哠浩恏晧淏傐皓鄗聕號滈暤暭皞皜澔镐薃皡曍皥颢顥鰝灏灝竓" },
    { first_py:"h",full_py:"hang",hanzis:"夯炕行苀迒吭斻杭肮绗桁珩蚢航笐颃貥裄絎筕頏魧沆巷垳" },
    { first_py:"h",full_py:"hen",hanzis:"拫痕鞎佷很哏狠詪恨" },
    { first_py:"h",full_py:"hei",hanzis:"黒黑嗨嘿潶" },
    { first_py:"h",full_py:"he",hanzis:"诃呵抲欱牙合訶喝嗬蠚禾纥何和咊郃劾姀河盇柇狢峆饸阂曷籺紇釛荷核敆盍盉害涸渮盒菏萂啝龁訸颌惒楁澕毼阖鲄詥貉貈鉌閡餄麧熆鹖頜魺螛翮篕餲鞨齕闔礉覈鶡皬鑉龢吓佫贺垎哬袔寉焃鹄猲賀碋嗃煂熇褐赫鹤翯癋謞壑嚇燺爀鶴鶮鸖靍粭遤靎靏𬌗" },
    { first_py:"h",full_py:"hong",hanzis:"叿吽呍灴轰哄訇烘軣焢硡揈渹谾薨輷鍧嚝轟仜弘妅屸红纮玒汯吰闳宏宖苰泓玜垬沗虹紅洪娂荭羾翃浤紘耾竑鸿硔紭谹鈜閎粠竤渱葓葒綋谼翝鉷鞃魟潂鋐篊黉霐彋蕻霟鴻黌唝晎讧訌閧銾撔澒闂鬨闀" },
    { first_py:"h",full_py:"heng",hanzis:"亨哼涥悙脝行恒恆姮珩胻烆桁鸻撗横橫衡鴴蘅鑅鵆啈" },
    { first_py:"h",full_py:"hu",hanzis:"乎匢戏虍芴苸呼泘垀昒忽曶恗烀轷匫唿惚淴虖軤雽雐滹嘑寣幠糊歑膴謼抇囫狐弧和瓳胡核壶隺壷斛焀鹄絗壺猢搰湖喖葫媩煳楜瑚鹘鹕蔛嘝蝴箶槲魱衚頶醐螜縠鍸餬觳鵠鬍瀫鶘鶦鰗乕汻虎浒俿萀唬虝琥滸錿互弖户戶戸冱芐护沪沍帍戽岵怙枑昈祜怘笏瓠扈婟楛雇綔嗀嗀鄠嫭嫮蔰滬摢槴熩鳸鍙豰簄嚛鹱護鳠頀鸌鱯粐" },
    { first_py:"h",full_py:"hua",hanzis:"化华花哗砉錵蘤划呚骅姡華铧釫釪猾滑嘩搳撶劃磆鲑螖鋘蕐譁鏵驊鷨夻话杹枠画桦崋婳畫畵嬅觟話摦樺槬澅嫿諙諣黊舙繣譮婲埖椛硴蒊糀誮" },
    { first_py:"h",full_py:"huan",hanzis:"欢犿狟歓鴅鵍酄嚾孉獾懽歡讙貛驩还郇环荁峘洹桓萑萈寏堚雈絙綄貆獂羦锾圜澴缳寰嬛還阛鍰環豲镮鹮糫繯轘鐶闤鬟瓛缓睆緩幻肒奂奐宦唤换涣浣眩烉焕梙逭患嵈喛喚渙換愌痪豢瑍煥瘓漶鲩槵澣擐藧鯇攌鯶鰀" },
    { first_py:"h",full_py:"huai",hanzis:"怀徊淮槐褢踝褱懐懷瀤櫰耲蘹坏壊壞蘾" },
    { first_py:"h",full_py:"hou",hanzis:"齁侯矦鄇葔帿喉猴睺瘊銗篌骺糇翭翵鍭餱鯸吼犼后郈厚茩後逅洉垕候堠豞鲎鲘鮜鱟" },
    { first_py:"h",full_py:"hun",hanzis:"昏昬荤阍婚涽惛殙棔葷睧睯蔒閽轋忶浑珲混馄渾魂琿餛鼲诨俒圂溷慁倱婫掍焝睴觨尡諢" },
    { first_py:"h",full_py:"huang",hanzis:"巟肓荒衁宺朚塃慌皇隍凰偟黄黃葟徨遑喤媓崲揘湟堭惶煌楻瑝锽墴潢獚熿蝗璜艎篁諻穔癀磺蟥簧餭鳇鍠韹趪騜鐄鰉鱑鷬怳恍炾晃晄谎奛幌詤熀縨謊兤櫎滉愰榥曂皝鎤皩" },
    { first_py:"h",full_py:"huo",hanzis:"吙秴耠锪劐嚄豁騞攉佸和活秮秳灬火邩伙钬鈥煷漷夥沎货或咟俰获捇眓閄貨掝祸喐剨湱禍惑旤蒦窢鍃霍濩獲奯擭檴雘謋穫镬矆彟瀖嚯藿蠖耯艧嚿曤臛矐癨鑊韄靃彠" },
    { first_py:"h",full_py:"hui",hanzis:"戏灰灳炜诙咴挥拻洃恢袆虺珲烣晖豗堕婎媈揮隓辉翚暉禈睢煇楎詼睳褘幑噅噕撝翬輝麾徽隳瀈蘳鰴囘回囬佪廻廽茴迴恛洄蚘烠逥痐蛔蛕蜖鮰虫悔毁毀毇燬檓譭卉屶屷汇讳会泋浍绘哕诲荟芔贿烩桧恚恵晦彗秽絵翙廆惠喙缋阓湏滙匯會彚彙賄詯誨瘣僡嘒蔧蕙潓寭圚憓槥暳慧橞諱嬒獩濊薈薉徻頮餯藱篲檅燴璯繢穢瞺蟪嚖懳繪翽譓櫘鏸儶闠靧鐬譿顪颒璤" },
    { first_py:"j",full_py:"ji",hanzis:"几讥叽击刉饥圾机刏乩芨玑肌鸡矶奇其枅咭唧剞姬屐积畟笄飢基庴喞嵇嵆幾赍犄筓缉朞稘畸嗘跻鳮銈僟綨緁箕毄稽鹡觭躸諆緝畿嘰槣齑錤機禨墼激隮襀積璣磯羁賷簊擊櫅耭雞韲鶏譏譤鐖饑躋鷄鞿魕癪羇虀鑇鑙齏覉羈鸄覊亼亽及伋彶吉汲岌级忣极即亟郆佶卽姞叝急皍級笈革觙揤疾堲楖焏偮卙谻集殛戢棘極湒塉嵴楫辑愱蒺嫉蝍趌銡耤膌槉嶯潗濈蕺蕀瘠箿踑踖輯螏檝藉磼襋蹐鍓艥籍鏶霵轚鶺齎躤雧己丮妀犱纪泲虮济给挤脊掎鱾戟麂魢撠橶穖擠蟣彑计旡记伎齐系忌坖际芰妓技剂季迹垍既紀荠茤茍洎哜計記剤紒觊继绩悸梞旣祭偈徛寄寂済葪蔇惎臮跡鬾魝裚痵継蓟際兾勣漈漃禝穊稩暨魥鲚霁跽誋諅鲫暩稷穄曁冀劑薊髻覬薺嚌濟檕績罽繋璾檵蹟鵋鯽齌鯚懻癠穧骥蘎蘮瀱繼鱀鰶鰿鷑霽蘻鱭驥﨤樭撃鯲廭" },
    { first_py:"j",full_py:"jiang",hanzis:"江茳将姜浆畕豇將葁畺摪翞僵螀漿薑缰壃殭橿螿鳉礓疅疆繮韁鱂讲奖桨蒋傋塂奨奬蔣槳獎膙耩講顜匞匠弜夅降洚绛弶强絳酱勥滰嵹摾犟糡醤醬糨謽櫤" },
    { first_py:"j",full_py:"jie",hanzis:"节阶疖皆结階接掲秸痎街揭嗟喈喼媘嫅堦椄湝脻楷煯稭鞂蝔擑謯癤鶛卩卪孑尐讦刧劫岊刦杢昅杰疌衱劼刼诘狤洁拮迼桔桀訐莭倢偈偼菨婕崨捷掶袺蛣絜結媫傑颉鉣嵥搩滐節睫詰蜐楬楶榤截鲒碣竭蓵潔镼鞊頡誱踕羯幯嶻擮鮚礍鍻巀蠞蠘蠽毑姐媎解觧飷檞丯介价芥岕庎吤戒届屆玠疥砎界畍衸诫借蚧悈徣唶堺楐琾骱蛶誡犗褯魪鎅藉桝" },
    { first_py:"j",full_py:"jiao",hanzis:"艽交郊茭茮骄娇姣峧浇胶教焦椒蛟跤虠鲛僬蕉澆憍嶕嶣嬌膠膲徼鮫穚鹪礁鵁簥轇蟭鐎驕鷦鷮矫嚼臫角侥佼狡饺挢绞烄晈捁笅皎脚铰搅湫絞筊賋勦剿腳敫煍暞僥摷踋鉸餃撟撹儌徺劋敽缴憿敿矯曒璬蟜皦繳譑孂灚攪鱎龣叫呌挍峤觉訆珓校轿较敎窌窖較滘漖嘄嘂嘦斠酵嶠噍潐嬓獥噭藠轎醮趭譥皭釂" },
    { first_py:"j",full_py:"jian",hanzis:"戋尖幵奸间歼坚浅戔冿玪肩艰姦姧兼监笺豜菅菺猏惤渐堅缄溅湔葌間雃犍牋瑊椷椾睷碊蒹搛缣煎蔪箋鲣緘鹣樫蕑蕳熞鳽熸縑鋻餰馢鞬艱鞯鳒瀐鵑鵳殱礛瀸鰔鰜鶼殲櫼譼韀礷鰹囏虃韉鑯暕囝枧拣俭茧柬笕倹捡挸湕帴减剪检梘趼詃検锏睑硷裥堿減揃揀谫弿瑐絸筧简戬戩碱儉翦篯撿藆襇襉檢謇蹇謭簡繭礆瞼鬋鹸鰎蠒鐧鐗瀽鹻譾籛襺鹼见件見建饯贱洊荐剑牮珔舰剣健俴涧栫剱谏徤袸毽臶腱践跈寋楗旔賎鉴键監槛榗漸僭劎劍澗箭糋諓賤踺踐趝餞諫鍵薦劒劔鍳瞷磵礀繝濺檻擶瀳譛鏩覵覸艦轞鐱鑑鑒鑬鑳豣彅墹麉" },
    { first_py:"j",full_py:"jia",hanzis:"加夹夾伽抸拁泇佳茄迦珈浃毠枷浹家痂耞笳袈梜葭傢跏猳腵筴鉫犌嘉镓豭貑鴐鎵麚甲扴圿忦郏郟荚莢唊恝脥铗戛戞裌蛱颊蛺跲頬鋏頰鴶鵊岬叚玾胛钾贾斚假婽徦斝椵賈鉀槚榎嘏瘕檟价驾架嫁幏榢價駕稼嗧糘" },
    { first_py:"j",full_py:"jiu",hanzis:"丩勼纠朻牞鸠究糺糾赳阄萛啾揪揂湫鳩揫摎樛鬏鬮九久乆乣氿汣奺灸玖舏韭紤镹酒韮匛旧臼疚咎柩柾桕倃匓厩救就廄廐舅廏僦慦殧舊鹫鯦麔匶齨鷲杦欍" },
    { first_py:"j",full_py:"ju",hanzis:"车凥且抅拘泃匊狙岨苴驹居陱毩捄挶眗疽砠罝梮蛆掬据涺崌娵婮毱趄跔跙椐琚腒锔裾雎蜛艍躹諊踘鋦駒鴡鮈鞠檋鞫鶋局泦侷狊桔郹焗菊啹婅淗湨椈輂犑閰跼粷趜橘駶鵙繘鵴蹫鶪鼰巈蘜鼳驧弆咀沮柜枸举莒矩挙椇筥龃榉榘蒟聥舉踽擧櫸齟欅襷籧巨句讵苣邭姖岠拒洰怇炬歫拠具昛秬钜剧俱倨倶袓蚷耟粔詎距埧埾惧犋鉅飓虡豦锯窭寠聚愳駏鮔踞屦劇勮遽據澽懅窶壉鋸颶屨貗簴醵躆鐻懼﨔" },
    { first_py:"j",full_py:"jiong",hanzis:"冂冋坰扃埛駉駫蘏蘔囧冏迥泂炅炯逈侰浻烱絅颎煚窘綗僒煛熲褧澃顈燛" },
    { first_py:"j",full_py:"jing",hanzis:"巠坕坙泾茎京径经亰荆荊秔涇婛猄惊旌旍菁経稉葏晶腈睛經粳精綡聙兢鲸麖鶄鶁鯨鼱驚麠井丼阱刭宑汫坓汬肼穽剄殌景儆頚幜澋憬璄璟璥憼暻頸蟼警劲妌迳弪净浄俓婙胫莖弳逕倞徑凈竞痉竟竫淨桱梷婧脛靓敬竧痙傹靖静獍誩踁境靚靜镜曔瀞鵛鏡競竸橸" },
    { first_py:"j",full_py:"jin",hanzis:"巾今仐斤钅金釒觔矜衿荕津珒紟矝琎惍釿堻筋禁璡黅鹶襟仅尽卺侭巹紧堇菫厪谨僅锦嫤馑漌蓳廑緊槿瑾儘錦謹饉伒劤妗劲进近枃浕勁荩浸赆烬晋晉祲進唫煡缙溍寖搢靳盡墐瑨歏殣凚僸觐縉賮噤濅濜嚍藎嬧燼璶覲贐齽兓砛琻壗" },
    { first_py:"j",full_py:"jun",hanzis:"军君汮均龟袀軍姰钧莙蚐桾菌皲鈞碅筠覠銞皸皹銁鲪頵麇鍕鮶麏麕呁郡陖俊骏峻馂捃浚埈隽焌晙珺葰竣畯棞雋蜠箘箟賐儁寯懏餕燇駿濬鵔鵕鵘攈攟" },
    { first_py:"j",full_py:"juan",hanzis:"姢娟捐涓圈焆朘鹃裐勬镌鋑鎸鐫蠲呟卷帣埍菤捲锩踡錈臇奆劵巻狷勌倦桊绢悁隽眷鄄淃瓹腃睊罥絭絹睠慻蔨餋獧羂讂" },
    { first_py:"j",full_py:"jue",hanzis:"噘撅撧屩屫亅孓孒决刔诀氒角芵弡決抉泬玦玨珏觉疦砄虳绝挗捔倔蚗欮脚桷斍覐觖訣赽掘崛崫趹鈌焳傕厥趉覚絶絕阙劂谲瑴駃鴃鴂瘚爴觮獗噊蕨蕝熦憰嶡嶥噱憠橛橜镢臄爵櫭蟩蟨譎爑蹶蹻蹷鐍鐝矍鳜嚼匷覺觼爝灍戄攫玃彏鷢矡貜躩钁" },
    { first_py:"k",full_py:"ka",hanzis:"咖咔喀卡佧咯胩鉲凧垰桛裃閊綛聢鯑鶍" },
    { first_py:"k",full_py:"kai",hanzis:"开奒開揩锎鐦凯剀闿恺垲铠慨剴蒈凱嘅嵦愷楷塏輆锴暟鍇鎧闓颽忾炌烗欬勓愾鎎" },
    { first_py:"k",full_py:"ken",hanzis:"肎肯肻垦恳啃豤貇錹墾懇掯硍裉褃" },
    { first_py:"k",full_py:"kao",hanzis:"尻嵪髛丂考攷拷洘烤栲铐熇犒銬鲓靠鮳鯌廤" },
    { first_py:"k",full_py:"kan",hanzis:"刊看栞龛勘嵁堪戡龕凵冚坎侃砍莰偘惂欿歁槛輡顑轗竷衎崁墈阚磡瞰闞鬫矙" },
    { first_py:"k",full_py:"ke",hanzis:"匼苛坷呵牱牁珂科轲柯钶疴砢趷蚵痾軻颏棵萪稞犐搕鈳窠颗薖榼樖頦瞌蝌磕顆髁醘礚壳咳殻殼翗揢可岢炣渇渴敤嵑嶱克刻勀勊客峇恪娔课骒氪堁衉愘缂溘愙锞嗑碦緙艐課錁騍礊厼迲硛嵙兡穒鯑" },
    { first_py:"k",full_py:"kang",hanzis:"忼砊粇康閌嫝嵻漮慷槺穅糠躿鏮鱇扛亢匟邟伉闶犺抗囥炕钪鈧" },
    { first_py:"k",full_py:"kua",hanzis:"夸咵姱誇侉垮銙挎胯趶跨骻舿" },
    { first_py:"k",full_py:"ku",hanzis:"刳郀矻枯桍哭堀圐跍窟骷鮬苦狜楛库绔俈秙庫焅袴裤絝喾瘔酷褲嚳萙鶎" },
    { first_py:"k",full_py:"kou",hanzis:"芤抠眍剾摳彄瞘口劶叩扣怐敂宼冦寇釦窛筘蔻蔲滱瞉簆鷇" },
    { first_py:"k",full_py:"kong",hanzis:"空倥崆涳埪悾硿箜躻錓鵼孔恐控鞚" },
    { first_py:"k",full_py:"keng",hanzis:"阬劥吭妔坑挳硁牼铿硜硻誙摼銵鍞鏗" },
    { first_py:"k",full_py:"kuan",hanzis:"宽寛寬臗髋髖梡欵款歀窽窾鑧" },
    { first_py:"k",full_py:"kuai",hanzis:"蒯擓巜凷会块快侩郐浍哙狯脍欳塊筷鲙墤鄶儈廥澮獪噲膾糩旝鱠圦" },
    { first_py:"k",full_py:"kui",hanzis:"亏岿刲悝盔窥聧窺虧顝闚巋奎晆隗鄈逵馗揆葵喹骙暌戣楏楑魁睽蝰頯鍨鍷櫆藈騤夔蘷虁巙犪躨傀煃跬頍磈蹞归尯匮蒉喟媿馈溃愦愧匱蕢嬇嘳憒潰聩聭篑謉殨膭餽簣聵籄饋" },
    { first_py:"k",full_py:"kuang",hanzis:"匡邼劻诓哐洭恇匩硄筐筺軭誆狂狅抂忹诳軖軠誑鵟夼儣懭邝纩圹况旷岲況矿昿贶眖砿框絋眶絖貺軦鉱鋛鄺壙黋爌曠懬穬矌礦纊鑛" },
    { first_py:"k",full_py:"kun",hanzis:"坤昆晜裈堃菎猑崑崐焜琨髠髡锟鹍裩褌蜫髨醌瑻熴錕鲲騉鵾鯤鶤捆悃阃壸梱祵稇硱裍綑稛壼閫閸困涃睏堒潉" },
    { first_py:"k",full_py:"kuo",hanzis:"扩拡括挄栝蛞筈萿葀阔廓頢髺韕鞟闊擴濶霩鞹鬠" },
    { first_py:"l",full_py:"lan",hanzis:"兰岚拦栏惏婪嵐阑葻蓝谰澜褴斓儖篮镧闌藍襕懢燷燣璼襤幱譋繿籃蘭蘫瀾灆攔欄斕襴灡囒籣讕躝欗襽鑭韊览浨揽缆榄漤罱醂覧壈懒擥懶嬾孄覽孏攬爦欖顲纜烂滥燗濫嚂爁爛瓓灠爤糷钄" },
    { first_py:"l",full_py:"la",hanzis:"拉垃柆菈啦喇搚邋旯剌砬揦磖嚹藞翋落腊楋揧蜡蝋辣辢瘌蝲臈癞鬎臘攋爉瓎櫴镴鯻蠟鑞凩溂鞡鮱" },
    { first_py:"l",full_py:"lai",hanzis:"来俫莱徕崃涞梾铼來倈郲徠逨庲唻婡猍崍淶萊赉棶琜睐筙赖箂錸濑癞騋麳鶆鯠籁襰睞賫賚賴頼顂鵣藾瀨瀬癩籟萙" },
    { first_py:"l",full_py:"lang",hanzis:"啷勆郎郞郎欴莨狼桹蓈廊嫏琅斏稂锒硠瑯榔蜋艆筤郒躴螂樃鋃鎯朗朖烺蓢塱誏朤阆崀浪埌蒗閬" },
    { first_py:"l",full_py:"lao",hanzis:"捞撈劳労牢窂涝浶唠哰崂勞铹痨僗嶗潦憥癆磱蟧簩醪鐒顟髝耂老佬荖咾姥狫恅栳珯铑銠獠轑络烙閖落嗠酪耢嫪嘮澇憦躼橯耮軂硓粩朥" },
    { first_py:"l",full_py:"leng",hanzis:"棱唥塄楞稜碐薐冷倰堎愣睖踜" },
    { first_py:"l",full_py:"le",hanzis:"肋嘞仂阞忇艻叻扐氻乐玏泐竻砳勒楽餎韷樂簕鳓鰳鱳朰榁" },
    { first_py:"l",full_py:"li",hanzis:"哩刕丽厘骊剓荲狸离梨梸犁琍悡菞喱犂棃鹂缡蜊艃筣漓蓠剺嫠孷樆璃盠貍鋫鲡黎褵犛蔾縭篱罹錅謧醨蟍釐離藜嚟邌斄瓈鏫鵹鯬蟸黧蠡蠫灕囄蘺孋廲劙鑗籬穲纚驪鱺鸝礼礼里李俚峛峢峲逦娌理锂裡裏裏豊鋰鲤澧禮鯉醴鳢邐鱧鱱欚力历厉屴立朸吏呖励利叓苈坜沥沴岦枥苙例戾疠隶疬砅赲俪俐荔茘郦栎栃轹猁悧珕栗栛涖浰莉莅娳砺砾秝鬲蛎蚸粝粒笠婯唳脷悷棙傈凓厤跞詈蛠痢雳鳨睙鉝厯蒞蒚搮溧塛慄暦歴瑮厲綟蜧蝷篥鴗隷勵歷曆巁濿檪隸鬁磿癘犡爄蠇櫔曞禲擽儮嚦攊藶瓅櫟瀝壢礪麗礫蠣爏糲盭櫪瓑皪酈儷癧礰麜鷅轢觻躒囇攦欐讈轣靂瓥攭靋唎甅睝粴魞聢竰糎鯏鯐" },
    { first_py:"l",full_py:"lei",hanzis:"勒累傫雷蔂缧嫘畾樏擂儡縲攂镭礌櫑瓃羸礧罍纍蘲鐳轠鑘靁虆欙纝鼺厽耒诔洡垒絫塁誄漯蕌磊磥蕾藟壘癗櫐礨蠝灅蘽讄儽壨鑸鸓肋泪类涙淚酹銇頛頪錑檑颣類纇蘱禷矋" },
    { first_py:"l",full_py:"lia",hanzis:"俩" },
    { first_py:"l",full_py:"lian",hanzis:"连奁怜帘涟連莲梿裢联廉慩蓮亷漣溓嗹匲奩槤熑覝鲢聨聫磏褳憐匳劆噒嫾濂濓薕螊聮縺翴聯謰蹥燫櫣臁镰鎌簾蠊瀮鬑鰱鐮籢籨敛琏脸裣摙璉蔹嬚鄻斂歛臉襝羷蘞蘝练炼恋殓堜僆萰媡湅链煉楝瑓潋練澰錬鍊殮鏈鰊瀲戀纞" },
    { first_py:"l",full_py:"liang",hanzis:"良俍莨凉凉梁涼椋辌量粮粱踉墚樑輬駺糧両两兩俩倆唡啢掚脼裲蜽緉魉魎亮谅哴悢倞辆晾喨湸靓輌諒輛鍄" },
    { first_py:"l",full_py:"liao",hanzis:"撩蹽辽疗聊尞憀膋僚寥嵺漻潦缭嘹嶚嶛寮嫽獠遼敹暸璙膫燎橑療鹩竂蟟繚簝賿豂蹘廫藔屪爎爒飂髎飉鷯了钌釕鄝蓼憭瞭镽尥尦炓料廖撂窷镣鐐" },
    { first_py:"l",full_py:"lie",hanzis:"裂列劣劽冽挒茢迾咧姴洌浖埒埓烈哷烮栵捩猎猟蛚聗趔煭巤颲鴷鮤儠獵擸犣躐鬛鬣鱲挘" },
    { first_py:"l",full_py:"lin",hanzis:"拎厸邻阾林临冧啉崊淋晽粦琳碄粼箖鄰隣隣遴潾嶙獜暽辚燐斴璘霖瞵磷疄臨繗翷麐轔鏻鳞瀶壣驎麟鱗菻亃僯凛凜撛澟懔懍廪廩檩檁癛癝吝恡悋赁焛賃蔺橉甐膦閵蹸藺躏躙躪轥" },
    { first_py:"l",full_py:"liu",hanzis:"溜熘澑蹓刘畄浏斿流留琉旈畱裗硫遛旒蒥蓅骝媹嵧馏飗榴瑠镏瘤瑬劉磂駠鹠橊疁镠璢癅蟉駵麍鎏鎦嚠瀏懰藰鏐飀騮鐂飅鶹鰡驑柳栁桞珋桺绺锍綹鋶罶熮橮羀嬼六陆翏廇塯碌鹨磟餾霤雡飂鬸鷚" },
    { first_py:"l",full_py:"ling",hanzis:"令伶刢灵坽囹夌苓彾呤姈狑泠柃朎昤瓴玲皊秢铃竛鸰砱陵羐凌菱淩崚掕婈棂琌蛉聆紷衑翎舲笭绫羚詅軨跉祾棱裬蓤龄鈴閝零綾蔆輘霊駖鹷鴒魿霗鲮錂蕶澪燯霛霝齢鯪酃孁齡櫺醽麢欞爧龗岭岺袊领領嶺另炩蘦靈" },
    { first_py:"l",full_py:"long",hanzis:"龙茏咙泷栊昽珑胧竜眬砻聋笼隆湰滝漋槞嶐窿篭龍癃鏧霳巃巄瀧嚨蘢爖櫳瓏曨襱朧矓礱礲龒龓籠豅躘聾蠪蠬靇鑨驡鸗陇拢垄垅篢隴儱壟壠攏竉弄哢梇徿贚" },
    { first_py:"l",full_py:"lou",hanzis:"搂瞜娄婁偻蒌溇喽楼漊慺蔞遱廔嘍熡樓蝼耧耬艛螻軁謱髅髏鞻鷜嵝嶁摟塿甊篓簍陋屚漏镂瘘瘺瘻鏤露" },
    { first_py:"l",full_py:"lu",hanzis:"噜撸謢擼嚕卢芦庐泸垆炉枦栌胪鸬舮舻玈颅鲈馿魲盧璷壚瀘蘆廬嚧獹攎爐櫨曥瓐臚矑艫籚蠦罏纑鑪髗顱鱸鸕黸卤虏掳鹵鲁硵虜蓾滷塷澛樐魯磠橹擄穞镥瀂氌櫓艣鏀鐪艪鑥六圥甪陆侓录彔坴峍赂辂陸勎娽逯菉渌淕淥硉绿鹿椂禄祿琭勠僇剹稑盝睩碌賂輅路粶箓蓼蔍廘漉摝塶辘戮熝樚膔踛醁趢録錄錴穋潞蕗璐簏螰鴼蹗騄轆簶鹭簬簵鏕鵦鵱麓鯥騼鏴露籙鷺虂轳焒閊鈩氇轤" },
    { first_py:"l",full_py:"lv",hanzis:"驴闾榈閭膢氀櫚藘驢吕呂郘侣侶挔捛捋旅梠祣偻铝稆絽屡缕僂屢膂褛鋁履褸膐縷儢穭律垏虑绿率氯葎嵂滤綠緑慮膟箻繂勴濾爈櫖鑢" },
    { first_py:"l",full_py:"luan",hanzis:"娈峦孪栾挛脟鸾脔滦銮鵉巒孌奱孿圝攣灓欒曫羉臠圞虊灤鑾癴癵鸞卵乱釠亂" },
    { first_py:"l",full_py:"lue",hanzis:"寽畧稤鋝鋢" },
    { first_py:"l",full_py:"lve",hanzis:"掠略锊圙" },
    { first_py:"l",full_py:"lun",hanzis:"抡掄仑伦论芲沦纶囵侖轮倫陯圇淪菕婨崘崙棆腀碖蜦耣綸輪踚錀鯩埨惀稐溣論嗧磮" },
    { first_py:"l",full_py:"luo",hanzis:"捋啰落頱囉罗萝逻猡脶腡椤锣骡箩镙螺羅覶鏍騾覼蠡儸邏蘿玀攞欏驘鸁籮鑼饠囖剆倮蓏裸躶瘰蠃臝曪癳泺洛咯骆峈荦络烙洜珞硌硦絡跞笿詻雒犖摞漯駱鵅鮥濼纙鮱" },
    { first_py:"m",full_py:"m",hanzis:"呒呣姆" },
    { first_py:"m",full_py:"mai",hanzis:"埋薶霾买荬買嘪鷶劢迈麦佅売卖脉脈麥衇勱賣邁霡霢蕒" },
    { first_py:"m",full_py:"ma",hanzis:"亇妈孖抹蚂麻媽嫲摩吗嗎痲痳蔴犘蟆马犸玛码馬獁溤瑪碼螞鎷鷌鰢杩祃骂閁唛傌睰嘜禡榪罵駡鬕唜嘛魸蟇" },
    { first_py:"m",full_py:"man",hanzis:"埋嫚颟顢悗蛮谩蔓馒摱慲樠瞒瞞鞔謾饅鳗鬘鬗鰻蠻娨屘満满滿螨蟎鏋矕曼鄤僈蔄幔獌漫缦墁慢熳槾镘澷縵鏝襔" },
    { first_py:"m",full_py:"mang",hanzis:"邙牤芒吂汒忙尨杧杗氓盲盳笀恾茫厖庬哤娏狵浝牻釯铓硭痝蛖鋩駹蘉莽莾硥茻壾漭蟒蠎" },
    { first_py:"m",full_py:"mao",hanzis:"猫貓毛矛枆茆茅牦旄罞軞酕渵堥楙锚髦鉾蝥氂髳錨蟊鶜冇夘卯戼峁泖昴铆笷鉚蓩冃芼皃茂冐冒贸柕眊耄覒袤貿鄚萺帽媢毷暓瑁愗鄮貌瞀蝐懋毟" },
    { first_py:"m",full_py:"mei",hanzis:"没沒坆苺枚玫栂眉脄莓郿脢梅珻睂堳湄湈葿媒猸嵋腜瑂禖楣楳煤酶槑镅鹛塺鋂霉鎇徾糜攗鶥黴毎每美凂挴浼羙嵄渼媄媺镁嬍燘躾鎂黣妹抺沬袂昧祙眛谜寐媚跊鬽痗煝魅韎睸蝞篃" },
    { first_py:"m",full_py:"me",hanzis:"乄么匁扖庅嚒濹嚜嚰" },
    { first_py:"m",full_py:"men",hanzis:"闷门们扪汶玧钔門閅們菛捫璊穈鍆亹虋焖悶暪燜懑懣椚" },
    { first_py:"m",full_py:"meng",hanzis:"掹蒙擝尨甿氓虻莔萌溕盟鄳甍蝱鄸儚蕄瞢橗幪濛懞檬曚氋朦鹲礞鯍矇艨矒饛霿靀顭鸏黾勐冡猛锰蜢艋錳獴懵蠓鯭鼆孟梦夢夣懜霥" },
    { first_py:"m",full_py:"mi",hanzis:"咪眯瞇弥祢迷猕谜蒾詸謎醚糜縻麋麊麿藌彌擟禰靡麛瀰獼蘪镾蘼戂攠瓕爢醾醿鸍釄米芈羋侎沵洣弭敉脒渳葞蔝銤濔孊灖冖糸汨沕泌怽宓觅祕峚宻秘覔覓密淧幂谧蓂幎覛塓蜜榓鼏蔤滵漞嘧熐冪樒幦濗謐簚櫁羃鼡袮粎裃椧嚸欕" },
    { first_py:"m",full_py:"mian",hanzis:"宀芇杣眠绵婂媔棉綿臱蝒緜嬵檰櫋矈矊矏丏汅沔免勉俛眄娩渑偭勔冕葂喕湎睌缅愐腼緬澠靦鮸靣面麪麫糆麺麵" },
    { first_py:"m",full_py:"miao",hanzis:"喵苗媌描瞄鹋緢嫹鶓劰杪秒眇渺缈淼緲篎藐邈妙庙竗玅庿缪廟" },
    { first_py:"m",full_py:"min",hanzis:"民玟苠姄岷怋旻旼盿砇珉罠崏捪缗琘琝瑉碈痻鈱緍緡錉鴖鍲皿冺刡忟闵黾抿泯忞敃勄闽悯敏笢閔黽惽湣敯暋愍閩僶潣憫慜簢鳘蠠鰵垊笽" },
    { first_py:"m",full_py:"mie",hanzis:"乜吀咩哶孭灭烕搣滅蔑薎鴓幭篾瀎懱櫗礣蠛衊鑖鱴旀" },
    { first_py:"m",full_py:"ming",hanzis:"名明鸣眀洺茗冥眳朙铭鄍蓂溟嫇猽詺銘鳴榠暝瞑螟覭佲姳凕慏酩命掵" },
    { first_py:"m",full_py:"miu",hanzis:"谬缪謬" },
    { first_py:"m",full_py:"mo",hanzis:"摸嚤无尛谟嫫馍模摹膜麽麼摩橅磨糢謨謩嬷嬤擵饃蘑髍魔劘饝万抹懡末圽没沫陌妺茉帓殁歾歿枺昩脉帞冒莫莈皌秣砞眜眿袜絈眽貃蛨貊塻蓦嗼漠寞獏銆靺魩黙嫼嘿墨瞐瞙瘼镆默貘蟔鏌藦爅癦驀纆礳耱丆匁乮裃酛魹囕" },
    { first_py:"m",full_py:"mou",hanzis:"哞牟劺侔呣恈谋眸蛑缪踎謀鍪麰鴾繆某" },
    { first_py:"m",full_py:"mu",hanzis:"毪氁模母牡亩姆畂拇畆畒姥峔牳胟砪畝畞畮鉧踇木目仫牟狇沐坶苜牧炑毣莫莯蚞钼雮募慔幕幙墓鉬睦楘慕暮暯艒霂縸穆鞪厼榁" },
    { first_py:"n",full_py:"na",hanzis:"那南拏拿嗱搻镎鎿乸哪雫内呐吶妠纳肭郍娜钠衲袦納笝軜豽捺貀鈉靹蒳魶凪魸噺" },
    { first_py:"n",full_py:"nai",hanzis:"腉孻乃艿奶氖疓廼迺哪倷釢嬭佴奈柰耐萘渿鼐褦螚錼" },
    { first_py:"n",full_py:"nan",hanzis:"囝囡男抩枏柟侽南莮畘难娚喃楠暔諵難赧萳揇湳煵腩蝻戁婻遖" },
    { first_py:"n",full_py:"nao",hanzis:"孬呶怓挠峱铙硇蛲詉猱碙撓嶩憹蟯獶譊夒鐃獿巎垴恼悩脑脳匘堖惱瑙嫐腦碯闹淖閙鬧臑" },
    { first_py:"n",full_py:"nang",hanzis:"囊囔乪嚢蠰馕欜饢擃曩攮灢儾齉" },
    { first_py:"n",full_py:"ne",hanzis:"哪疒那讷呐抐眲訥丆匁鼡縇" },
    { first_py:"n",full_py:"nei",hanzis:"哪娞馁脮腇餒鮾鯘内內那氝氞錗" },
    { first_py:"n",full_py:"nen",hanzis:"恁嫩嫰" },
    { first_py:"n",full_py:"neng",hanzis:"能" },
    { first_py:"n",full_py:"ng",hanzis:"嗯唔" },
    { first_py:"n",full_py:"ni",hanzis:"妮尼泥兒呢坭怩籾秜铌郳倪屔淣婗猊蚭埿棿跜鈮馜蜺聣輗觬貎鲵霓麑鯢齯臡拟你伲伱苨妳狔抳柅掜旎晲孴隬儗儞薿擬聻屰氼逆胒昵匿眤堄惄腻愵溺嫟睨暱縌誽膩嬺嶷檷哛鳰" },
    { first_py:"n",full_py:"nian",hanzis:"拈蔫年秊秊哖姩秥粘鲇鲶鮎黏鯰涊淰捻辇辗碾輦撵撚簐蹍攆蹨躎卄廿念唸埝惗艌焾" },
    { first_py:"n",full_py:"niang",hanzis:"娘嬢孃酿醸釀" },
    { first_py:"n",full_py:"niao",hanzis:"鸟茑袅鳥嫋裊蔦樢褭嬝嬲尿脲溺" },
    { first_py:"n",full_py:"nie",hanzis:"捏捻揑苶乜帇圼枿陧涅聂痆臬隉菍啮湼敜嵲嗫踂踗踙摰镊镍噛槷嶭篞臲錜颞蹑聶嚙鎳闑孽孼櫱蘖籋囁齧鑈巕蠥糱糵囓躡讘鑷顳钀" },
    { first_py:"n",full_py:"nin",hanzis:"囜您拰脌" },
    { first_py:"n",full_py:"ning",hanzis:"宁苧咛狞拧柠聍甯寍寕寗寜寧凝儜橣擰獰嚀薴嬣檸聹鑏鬡鸋矃佞侫泞倿澝濘" },
    { first_py:"n",full_py:"niu",hanzis:"妞牛牜汼狃扭纽忸炄杻钮紐莥鈕靵拗" },
    { first_py:"n",full_py:"nou",hanzis:"羺槈耨獳鎒檽鐞鯑" },
    { first_py:"n",full_py:"nong",hanzis:"农侬浓哝脓秾農辳儂蕽濃噥膿燶檂禯穠襛譨醲欁鬞繷弄挊挵癑齈" },
    { first_py:"n",full_py:"nu",hanzis:"奴伮驽孥笯駑努弩呶砮胬怒傉搙莻" },
    { first_py:"n",full_py:"nv",hanzis:"女钕籹釹沑衂恧朒衄" },
    { first_py:"n",full_py:"nuan",hanzis:"奻渜煗暖餪" },
    { first_py:"n",full_py:"nun",hanzis:"黁" },
    { first_py:"n",full_py:"nve",hanzis:"疟虐" },
    { first_py:"n",full_py:"nuo",hanzis:"那娜挪梛傩橠儺诺逽喏掿愞搦锘榒稬諾蹃鍩糑懧懦糥穤糯" },
    { first_py:"o",full_py:"ou",hanzis:"区讴沤欧殴瓯鸥塸熰歐鴎甌膒毆謳藲櫙鏂鷗呕吘偶腢嘔蕅耦藕怄慪漚" },
    { first_py:"o",full_py:"o",hanzis:"噢哦丆仒乯迲猠硛旕筽鳰縇穒纐" },
    { first_py:"p",full_py:"pa",hanzis:"叭汃妑苩派皅趴舥啪葩扒杷爬耙掱琶筢潖帊帕怕袙巼" },
    { first_py:"p",full_py:"pai",hanzis:"拍俳徘猅排棑牌箄輫簰簲迫沠派哌渒湃蒎鎃闏" },
    { first_py:"p",full_py:"pan",hanzis:"扳拌眅萠番潘攀丬爿洀柈胖般盘跘蒰幋媻槃搫盤磐縏磻蹒蹣鎜蟠瀊鞶坢冸判伴沜泮拚炍牉盼叛畔袢詊溿頖鋬鵥襻鑻" },
    { first_py:"p",full_py:"pang",hanzis:"乓胮雱滂膀膖霶仿彷厐庞逄旁舽嫎徬磅螃鳑龎龐鰟嗙耪覫髈炐肨胖眫" },
    { first_py:"p",full_py:"pao",hanzis:"抛拋泡脬萢刨庖咆狍垉炰炮爮袍匏袌軳跑鞄麃麅奅疱皰砲靤麭礟礮喸褜" },
    { first_py:"p",full_py:"pei",hanzis:"呸怌肧胚衃醅阫陪培赔毰锫裴裵賠錇俖伂犻沛佩帔姵斾旆珮配浿辔馷霈轡蓜" },
    { first_py:"p",full_py:"pen",hanzis:"喷噴濆歕瓫盆葐湓呠翸喯" },
    { first_py:"p",full_py:"pi",hanzis:"丕伓伾批纰邳坯炋枈披抷狉狓岯砒紕被秛秠铍悂旇耚翍豾鈚釽鉟銔髬駓磇劈噼錃魾錍憵鎞礔礕霹皮阰陂芘肶枇毗毘郫陴疲蚍蚾蚽豼埤啤崥琵焷脾腗椑裨鈹鲏蜱罴膍隦魮鮍壀篺螷鵧貔羆鼙蠯匹庀仳圮苉吡否脴痞銢鴄諀嶏擗噽癖嚭屁淠揊媲嫓睥辟稫潎僻澼甓疈譬闢鸊鷿迲" },
    { first_py:"p",full_py:"peng",hanzis:"匉抨泙怦恲砰硑烹梈軯閛剻漰嘭駍磞芃朋竼莑倗捀堋弸袶彭棚椖搒塜塳傰蓬稝鹏硼樥熢澎憉輣錋篷篣膨韸髼鬅蟛蟚纄蘕韼鵬鬔騯鑝捧淎皏掽椪碰槰踫輧" },
    { first_py:"p",full_py:"pian",hanzis:"片囨扁偏媥犏翩篇鶣便骈胼腁缏楄楩賆跰褊骿駢蹁騈谝覑貵諞骗騙騗" },
    { first_py:"p",full_py:"piao",hanzis:"票剽勡嘌彯漂缥飘旚螵翲犥飄飃魒朴嫖瓢薸闝莩殍瞟縹篻醥顠皫僄徱骠慓驃鰾" },
    { first_py:"p",full_py:"pie",hanzis:"氕覕撇暼撆瞥丿苤鐅嫳" },
    { first_py:"p",full_py:"ping",hanzis:"乒甹俜娉涄砯聠艵頩冯平评苹郱凭呯坪枰玶胓屏洴帡荓瓶蚲萍帲淜幈蓱蛢缾甁塀焩評鲆軿竮凴箳慿憑鮃檘簈屛岼" },
    { first_py:"p",full_py:"pin",hanzis:"拚拼姘砏礗穦馪驞贫玭娦貧琕嫔频嬪薲蘋嚬矉颦顰品榀牝汖娉聘朩" },
    { first_py:"p",full_py:"po",hanzis:"朴钋陂岥泊泼坡釙颇酦頗潑醗醱鏺婆鄱蔢嘙皤繁櫇嚩叵尀钷笸鉕箥駊廹迫岶洦敀昢珀破砶烞粕湐蒪魄乶哛桲" },
    { first_py:"p",full_py:"pou",hanzis:"剖娝抔抙捊垺掊裒箁咅哣婄犃" },
    { first_py:"p",full_py:"pu",hanzis:"仆攵攴扑抪炇陠铺痡鋪噗撲潽鯆圤匍莆菩脯葡菐蒱蒲僕酺墣獛璞穙镤瞨濮贌鏷纀朴浦埔圃烳普圑溥谱暜諩樸擈氆檏镨譜蹼鐠堡舖舗暴瀑曝巬哛" },
    { first_py:"q",full_py:"qi",hanzis:"七迉沏妻柒栖桤凄郪倛娸捿淒悽萋戚桼棲敧欺欹期攲紪缉傶僛嘁墄漆慽緀榿慼踦霋魌蹊鏚鶈丌亓祁齐圻忯芪岐岓奇其亝祈祇斉肵歧疧俟荠剘陭旂耆蚑蚔蚚脐斊竒颀畦軝跂釮埼萁萕帺骐骑猉崎掑淇棋棊祺蛴琪琦锜褀碕碁鬿頎愭﨑齊旗綥粸綦蜞蜝璂禥蕲錡鲯藄鄿濝懠檱櫀鳍騏騎臍鵸鶀鯕蘄麒鬐艩蠐騹鰭玂麡乞邔企芑岂屺杞玘盀启呇唘豈起啓啟啔婍绮棨晵綮綺稽諬闙气讫迄汔気汽芞弃矵呮泣炁亟盵契咠砌訖栔氣欫唭葺湆湇棄夡愒滊摖暣甈碶憇槭噐器憩碛磜磧磩藒蟿罊鐑嵜褄螧簯簱籏" },
    { first_py:"q",full_py:"qia",hanzis:"掐袷葜擖拤卡峠酠跒鞐圶冾帢洽恰胢硈殎髂" },
    { first_py:"q",full_py:"qian",hanzis:"千阡仟芊迁扦奷汘圱圲汧岍杄茾佥欦钎臤牵拪悭蚈铅谸釺婜牽孯掔谦鈆鉛鹐签愆僉嗛骞撁搴慳遷厱諐褰謙顅檶櫏攐攑簽鵮騫攓籖鬜鬝籤韆仱岒扲忴拑乹前荨钤钱钳虔歬軡乾偂掮揵亁媊葥鈐靬犍鉗銭墘榩箝蕁潜潛羬黔橬錢黚騝騚濳灊鰬浅肷淺遣膁蜸槏谴缱繾譴欠刋伣纤芡茜俔倩悓堑椠棈傔嵌皘蒨慊塹蔳綪歉篏儙槧篟輤縴壍嬱竏粁鎆鏲" },
    { first_py:"q",full_py:"qing",hanzis:"靑青轻氢郬卿倾寈清淸埥圊氫軽傾蜻輕錆鲭鯖鑋夝甠剠勍啨情殑棾葝氰晴暒擏樈檠擎黥苘顷请頃庼廎漀請謦檾庆亲凊倩掅殸碃綮箐靘慶磬罄濪儬硘櫦" },
    { first_py:"q",full_py:"qie",hanzis:"切癿伽茄聺且妾怯厒砌窃匧悏挈洯惬淁笡蛪趄愜慊朅锲箧篋踥鍥穕鯜竊" },
    { first_py:"q",full_py:"qin",hanzis:"侵亲钦衾骎媇嵚欽綅嵰誛嶔親顉駸鮼寴芹芩庈肣矜秦蚙菦埐珡耹捦菳禽覃鈙鈫雂琴琹溱勤靲嫀嗪廑慬嶜擒噙鳹斳澿檎懄螓瘽懃蠄鵭坅昑笉赾梫寑锓寝寢鋟螼吣吢抋沁唚菣揿搇撳藽瀙" },
    { first_py:"q",full_py:"qiao",hanzis:"悄郻硗雀跷鄡鄥勪踍敲毃锹劁骹頝墝墽燆橇幧缲磽鍫鍬繑繰趬蹺鐰乔侨荞荍峤桥菬硚喬翘僑谯槗墧憔蕉蕎嘺嫶鞒犞燋樵橋瞧癄礄翹譙趫櫵藮鐈鞽顦巧釥愀髜壳陗俏诮帩峭窍誚髚僺撬撽韒鞘鞩竅躈" },
    { first_py:"q",full_py:"qiang",hanzis:"羌呛抢斨枪戗戕玱羗将猐啌跄腔溬嗴獇椌蜣锖锵羫槍牄瑲戧嶈摤篬謒镪蹌蹡鎗鏘強强蔷嫱墙樯蔃漒薔彊廧墻嬙檣牆艢蘠羟羥搶墏襁繈繦鏹炝唴嗆熗羻" },
    { first_py:"q",full_py:"qiu",hanzis:"丘丠龟邱坵恘秋秌恷蚯媝湫萩楸湬蓲鹙蝵緧篍趥穐鳅鞦鞧蟗鶖鰌鰍蠤龝仇叴芁扏囚犰玌朹肍汓虬求虯泅俅訄訅酋觓釚唒莍逑逎浗紌毬球梂赇殏釻頄渞湭遒巯崷盚皳絿蛷煪裘觩巰賕蝤璆銶醔鼽鮂鯄鰽搝糗蘒蘒" },
    { first_py:"q",full_py:"qu",hanzis:"区曲匤阹佉伹诎驱岖岴屈抾坥浀胠祛袪蛆紶躯區焌煀詘趋筁蛐粬趍駆憈嶇敺駈誳麹魼髷麯趨軀覰麴鶌黢驅鰸鱋佢劬斪朐胊菃鸲絇翑渠淭葋軥蕖璖鴝磲螶蟝璩瞿鼩蘧忂灈戵爠臞氍欋籧癯蠷衢欔躣鑺蠼鸜苣取竘娶詓竬蝺龋齲去厺刞呿耝阒觑趣閴麮鼁闃覷覻衐" },
    { first_py:"q",full_py:"que",hanzis:"炔缺缼蒛阙瘸芍却卻崅埆琷悫雀确硞棤阕塙搉鹊皵碏榷愨慤碻確趞闋燩闕礐鵲礭" },
    { first_py:"q",full_py:"qiong",hanzis:"銎邛卭宆穷穹茕桏筇笻赹惸焪焭琼蛩蛬舼跫睘煢熍瞏窮憌橩璚儝藑藭瓊竆瓗嬛" },
    { first_py:"q",full_py:"quan",hanzis:"奍弮悛圈圏棬椦箞鐉全权卷诠佺姾荃峑洤恮泉牷辁拳铨痊硂惓埢婘啳葲湶絟筌犈瑔輇觠詮搼跧銓蜷権踡駩醛鳈鬈騡鰁巏權齤颧蠸顴犭犬犮畎烇绻綣虇劝券牶勧韏縓勸楾闎" },
    { first_py:"q",full_py:"qun",hanzis:"夋囷逡帬宭峮裙群羣裠麇" },
    { first_py:"r",full_py:"rao",hanzis:"荛娆饶桡嬈蕘橈襓饒扰隢擾绕遶繞" },
    { first_py:"r",full_py:"rang",hanzis:"嚷穣勷儴蘘獽瀼禳瓤穰躟鬤壌壤攘爙让懹譲讓" },
    { first_py:"r",full_py:"ran",hanzis:"呥肰衻袇袡蚦蚺然髥髯嘫燃繎冄冉苒姌染珃媣橪" },
    { first_py:"r",full_py:"re",hanzis:"若喏惹热熱" },
    { first_py:"r",full_py:"reng",hanzis:"扔仍辸礽芿陾艿" },
    { first_py:"r",full_py:"ren",hanzis:"人亻仁壬朲忈任芢忎秂魜銋鵀忍荏荵栠栣秹稔躵刃刄认讱仞仭纫屻饪牣纴轫杒妊韧肕祍姙衽紉紝軔訒袵梕葚腍絍鈓飪靭靱韌餁認" },
    { first_py:"r",full_py:"rong",hanzis:"戎肜栄茸荣茙狨绒毧峵容烿媶嵘搑傛絨羢搈溶嵤嫆蓉榵榕榮熔穁瑢縙镕褣蝾槦融螎駥嬫嶸爃鎔瀜曧蠑冗宂坈傇軵氄穃" },
    { first_py:"r",full_py:"ri",hanzis:"日驲囸衵釰釼鈤馹乤乬乫乮乭乶乽乼乺挘艝鑓虄" },
    { first_py:"r",full_py:"rou",hanzis:"厹禸柔粈脜葇媃揉渘楺瑈腬煣蝚糅輮蹂鍒鞣騥瓇鶔鰇韖肉宍譳" },
    { first_py:"r",full_py:"ru",hanzis:"邚如侞帤茹挐桇铷袽渪筎蒘銣蝡蕠儒鴑鴽嚅薷濡孺嬬曘襦蠕颥醹顬鱬汝肗乳辱鄏擩入洳溽缛蓐嗕媷褥縟扖杁嶿" },
    { first_py:"r",full_py:"rui",hanzis:"甤緌蕤桵蕊蕋橤繠蘂蘃壡芮汭枘蚋锐蜹瑞睿鋭銳叡" },
    { first_py:"r",full_py:"ruan",hanzis:"堧撋壖阮软朊耎軟偄媆瑌腝碝緛輭瓀礝" },
    { first_py:"r",full_py:"run",hanzis:"闰润閏閠潤橍膶" },
    { first_py:"r",full_py:"ruo",hanzis:"挼捼叒若鄀偌弱婼渃焫楉蒻箬篛爇鰙鰯鶸嵶" },
    { first_py:"s",full_py:"sang",hanzis:"丧桒桑喪槡嗓搡磉褬颡鎟顙" },
    { first_py:"s",full_py:"san",hanzis:"三弎参叁毵毶厁毿犙鬖伞傘散糁馓糝糣糤繖鏒鏾饊俕閐壭" },
    { first_py:"s",full_py:"sai",hanzis:"思毢愢揌塞腮毸嘥噻鳃顋鰓赛僿賽簺嗮" },
    { first_py:"s",full_py:"sa",hanzis:"仨撒洒訯靸潵灑躠卅钑飒脎萨鈒馺摋蕯颯薩櫒扨苆乷栍隡虄" },
    { first_py:"s",full_py:"sao",hanzis:"掻搔溞骚慅缫螦繅鳋颾騒騷鰠鱢扫掃嫂埽瘙燥氉臊矂髞乺" },
    { first_py:"s",full_py:"seng",hanzis:"僧鬙" },
    { first_py:"s",full_py:"sen",hanzis:"森椮槮襂" },
    { first_py:"s",full_py:"se",hanzis:"閪色洓涩栜啬渋铯雭歮嗇瑟塞摵歰銫澁濇濏擌懎瘷穑璱澀瀒穡繬轖穯鏼譅飋縇鱪" },
    { first_py:"s",full_py:"sha",hanzis:"杀杉沙纱刹砂殺莎唦猀粆紗挲铩桬痧硰摋煞蔱裟榝樧噎鲨魦閷髿鯊鯋鎩繺奢啥傻儍倽萐帹啑唼喢厦廈嗄歃翜翣箑閯霎" },
    { first_py:"s",full_py:"shai",hanzis:"筛酾篩簁簛籭色晒曬" },
    { first_py:"s",full_py:"shang",hanzis:"汤伤殇商觞禓傷蔏滳漡墒慯殤熵螪觴謪鬺上垧扄晌赏樉賞鋿鏛贘鑜丄尚尙恦绱緔鞝" },
    { first_py:"s",full_py:"shan",hanzis:"山彡邖删刪芟杉钐衫苫姗姍狦挻舢珊栅柵脠痁扇軕掺笘釤傓跚剼搧煽幓嘇潸澘鯅縿膻檆羴羶闪陕陝炶閃晱睒煔熌覢讪汕疝单訕剡赸掸掞善椫禅銏骟鄯僐缮墠墡樿敾歚擅嬗禪膳磰赡謆繕蟮蟺鐥饍鳝騸贍譱灗鱓鱔圸" },
    { first_py:"s",full_py:"she",hanzis:"奢猞赊畬畲畭輋賖賒檨舌佘折虵蛇阇揲蛥舍捨叶厍设社舎厙拾涉射赦設渉涻弽滠慑摄摂蔎慴歙蠂韘騇麝懾灄攝欇" },
    { first_py:"s",full_py:"shao",hanzis:"莦弰捎烧梢稍焼萷旓蛸艄筲輎鞘燒髾鮹勺芍杓苕柖玿韶少邵卲劭绍袑哨娋紹睄綤潲蕱" },
    { first_py:"s",full_py:"shei",hanzis:"谁" },
    { first_py:"s",full_py:"shen",hanzis:"申扟屾伸身籶侁参诜冞罙呻妽绅柛氠穼珅姺籸娠峷莘眒甡砷深紳敒兟訷棯裑葠蓡罧詵糁甧蔘糂鲹駪薓燊曑鵢鯓鯵鰺什神甚鉮鰰邥弞沈矤审哂矧谂谉婶訠渖諗審頣魫曋瞫瀋嬸讅覾肾胂侺昚涁眘脤渗祳葚腎瘆慎愼椹蜃蜄滲鋠瘮堔榊籡" },
    { first_py:"s",full_py:"shou",hanzis:"収收熟扌手守首垨艏寿受狩兽售授涭绶痩膄壽夀瘦綬獣獸鏉" },
    { first_py:"s",full_py:"shi",hanzis:"尸失师呞邿诗鸤虱狮施屍浉師絁釶葹湿湤溼溮蒒蓍鉇詩獅瑡酾鳲嘘鳾箷蝨褷鲺鍦濕鯴鰤鶳襹釃十饣什石时识实実旹飠食祏炻蚀拾姼峕埘莳時遈寔湜溡塒鉐實榯蝕鲥鼫鼭識鰣史矢乨豕使驶始屎宩兘笶鉂駛士氏礻示市世丗仕似卋忕式戺亊事侍势试呩饰视柹柿枾昰是贳恃恀眂峙拭冟室适逝眎眡铈舐轼烒栻秲釈視释貰弑谥徥揓崼嗜蒔勢弒軾筮睗觢試鈰鉃飾鉽誓舓適奭餝餙銴諡諟澨噬嬕遾螫謚簭釋襫乄辻佦竍嵵煶鮖籂鰘籡鱰" },
    { first_py:"s",full_py:"sheng",hanzis:"升生阩呏声斘枡昇泩狌苼陞珄牲殅陹笙湦焺甥鉎鍟聲鼪鵿渑绳憴縄繉繩譝省眚偗渻圣胜晟晠乘剰盛貹剩勝嵊琞聖墭榺蕂賸竔曻﨡橳" },
    { first_py:"s",full_py:"shu",hanzis:"书殳抒纾陎叔枢杸姝荼倏倐殊紓書焂梳鄃菽婌掓軗淑疏疎舒琡綀毹毺摅输跾踈蔬樞輸鮛橾儵攄鵨尗秫孰赎塾熟璹贖属暑暏黍鼠蜀数署潻薯薥曙癙藷襡襩屬术朮戍束沭述侸荗咰树怷竖恕捒庶庻蒁絉術裋尌鉥腧竪墅漱潄澍數豎錰霔濖樹鶐鏣虪瀭糬蠴" },
    { first_py:"s",full_py:"shua",hanzis:"刷唰耍誜" },
    { first_py:"s",full_py:"shuang",hanzis:"双泷爽霜雙骦孀孇騻欆鷞鹴礵艭驦鸘漺慡縔塽灀﨎鏯" },
    { first_py:"s",full_py:"shuan",hanzis:"闩拴閂栓涮腨" },
    { first_py:"s",full_py:"shuai",hanzis:"衰摔甩帅帥率蟀卛" },
    { first_py:"s",full_py:"shui",hanzis:"谁脽誰氵水氺说帨涗涚祱税稅裞睡" },
    { first_py:"s",full_py:"shun",hanzis:"楯吮顺順舜蕣橓瞚瞤瞬鬊" },
    { first_py:"s",full_py:"song",hanzis:"忪松枀枩柗娀凇倯菘庺崧淞梥硹嵩濍憽檧鬆怂悚耸竦愯楤傱嵷慫聳駷讼宋诵送訟颂頌誦鎹餸" },
    { first_py:"s",full_py:"shuo",hanzis:"说説說妁烁朔铄硕欶矟蒴搠獡槊碩箾鎙爍鑠" },
    { first_py:"s",full_py:"si",hanzis:"厶纟丝司糹私泀咝俬思恖鸶虒偲缌媤蛳斯絲鉰楒禗飔凘厮禠蜤锶銯罳鋖緦磃澌嘶噝撕蕬廝燍螄鍶颸蟖蟴騦鐁鷥鼶死巳亖四似寺汜泤姒兕伺佀祀孠杫価驷饲泗洠娰俟枱柶牭食飤肂涘洍耜耛梩笥釲覗竢肆嗣貄鈶鈻飼榹禩駟蕼儩瀃厑唜旕鯐鶍" },
    { first_py:"s",full_py:"sou",hanzis:"叟凁捜鄋搜蒐蓃廀廋嗖獀馊溲飕摉摗锼螋艘醙鎪餿颼騪叜傁嗾瞍擞薮藪櫢籔嗽瘶擻" },
    { first_py:"s",full_py:"su",hanzis:"苏甦酥窣稣穌鯂蘓蘇櫯囌俗玊夙诉泝肃洬涑莤速珟素粛殐梀骕宿谡傃粟訴肅鹔愫塑塐遡嫊嗉溯溸缩遬蔌僳榡愬膆趚觫鋉餗碿樎樕憟潥潚縤簌謖藗橚璛蹜驌鷫鱐苆" },
    { first_py:"s",full_py:"suan",hanzis:"狻痠酸匴祘笇筭蒜算" },
    { first_py:"s",full_py:"sui",hanzis:"夊芕尿虽浽荾哸倠隋眭睢滖熣鞖濉雖绥随遂遀綏隨髄瓍膸瀡髓亗岁砕祟谇埣嵗煫歲歳碎睟粹隧澻穂嬘賥誶燧檖禭璲穗穟邃襚繀繐繸旞譢鐆鐩韢荽" },
    { first_py:"s",full_py:"sun",hanzis:"孙狲荪孫飧飱猻搎蓀槂蕵薞笋损隼筍損榫箰簨鎨鶽潠" },
    { first_py:"s",full_py:"suo",hanzis:"莎莏唆娑挱桫梭挲傞睃嗍蓑羧摍缩趖簑簔縮鮻所唢索琐惢锁嗩溑暛褨瑣璅鎖鎻鎍鏁逤溹蜶琑嗦鱛" },
    { first_py:"t",full_py:"ta",hanzis:"他它她牠祂铊趿鉈溻塌榙禢褟踏溚塔墖獭鮙鳎獺鰨拓沓挞闼狧粏崉涾傝嗒遝阘搨漯毾榻澾撻誻錔橽嚃鞜蹋濌鞳闒蹹闥嚺譶躢侤萙遢燵襨鶎鱩" },
    { first_py:"t",full_py:"tan",hanzis:"坍贪怹痑啴舑貪滩摊嘽瘫潬擹攤灘癱坛昙郯倓谈弹婒埮惔覃锬痰榃谭潭憛墰墵談醈曇錟壇燂橝澹檀顃罈藫壜譚醰貚譠罎忐坦钽袒菼毯僋鉭嗿憳憻醓暺璮叹炭探湠嘆碳舕歎" },
    { first_py:"t",full_py:"tai",hanzis:"台囼孡苔胎邰旲坮骀抬炱炲菭跆鲐颱臺箈駘鮐儓薹擡嬯檯籉呔太夳冭汏汰汱忲肽态钛舦泰酞鈦溙態燤" },
    { first_py:"t",full_py:"tao",hanzis:"夲叨弢涛绦掏焘絛詜慆搯滔幍嫍槄瑫韬飸縚縧轁濤謟鞱韜饕迯匋洮逃咷陶桃梼萄淘绹啕祹裪蜪綯鞀鞉醄鋾駣騊饀鼗讨討套" },
    { first_py:"t",full_py:"tang",hanzis:"汤铴湯嘡羰劏蝪趟薚镗蹚鏜鞺鼞坣唐堂棠啺鄌傏蓎隚搪溏塘煻榶漟禟瑭膅膛磄糃樘橖糖螗篖踼赯醣螳糛鎕餹饄闛鶶伖帑倘偒淌惝傥耥躺镋鎲儻戃爣曭矘钂烫摥燙鐋" },
    { first_py:"t",full_py:"te",hanzis:"忑忒特铽慝鋱蟘朰扨脦罀" },
    { first_py:"t",full_py:"teng",hanzis:"膯鼟疼痋幐腾誊漛滕邆駦螣縢謄儯藤騰鰧籐籘虅驣霯" },
    { first_py:"t",full_py:"tiao",hanzis:"旫佻庣挑恌祧聎芀条苕迢岧岹祒條调萔笤蓚蓨龆樤蜩鋚鲦鞗髫鯈鎥齠鰷宨晀朓脁窕誂窱斢嬥眺粜絩覜趒跳糶" },
    { first_py:"t",full_py:"tian",hanzis:"天兲婖添酟靔黇靝田佃沺屇恬胋畋畑畠钿甜甛菾湉填塡嗔阗搷碵緂窴磌璳闐鷆鷏忝殄倎唺淟悿觍晪琠腆睓痶舔餂瑱賟覥錪掭舚鴫" },
    { first_py:"t",full_py:"ti",hanzis:"体剔梯锑踢銻擿鷉鷈厗荑绨偍媞崹提渧缇惿遆啼稊鹈罤题瑅綈嗁睼褆碮漽蕛徲緹醍趧蹄蹏鍗鳀謕鮷題鵜騠鶗鶙鯷禵鷤挮躰骵軆體戻屉洟剃俶倜逖涕悌惕屜掦逷啑笹悐惖替揥裼褅歒髰殢薙嚏鬀鬄瓋嚔籊趯" },
    { first_py:"t",full_py:"tie",hanzis:"帖怗贴萜聑貼铁蛈鉄銕僣鐡鐵驖呫飻餮" },
    { first_py:"t",full_py:"tou",hanzis:"偷偸媮婾鋀鍮亠头投骰頭妵紏敨黈蘣透" },
    { first_py:"t",full_py:"tu",hanzis:"凸宊秃禿怢突涋捸湥堗葖痜嶀鋵鵚鼵図图凃荼徒途庩峹捈涂悇梌屠菟揬稌瘏筡鈯嵞塗蒤腯廜潳瑹酴跿圖圗馟駼鍎鵌鶟鷋鷵土圡吐钍唋釷兎迌兔莵堍鵵汢溌" },
    { first_py:"t",full_py:"tong",hanzis:"恫炵通痌絧嗵蓪熥樋仝同彤佟侗庝峂峒峝哃狪茼垌烔晍桐浵砼蚒秱铜眮童粡赨詷酮鉖銅鉵餇鲖勭僮潼獞橦犝曈朣膧燑氃穜瞳鮦统捅桶統筒筩綂恸痛衕慟憅" },
    { first_py:"t",full_py:"ting",hanzis:"厅庁汀町听耓烃厛烴桯綎鞓聴聼廰聽廳邒廷莛庭亭停葶婷嵉渟蜓筳楟榳閮霆蝏聤諪鼮圢甼侹娗挺涏烶梃珽脡铤艇颋誔鋌頲" },
    { first_py:"t",full_py:"tuan",hanzis:"猯湍圕煓貒团団抟剸摶漙團慱槫篿檲鏄糰鷒鷻畽墥疃彖湪褖" },
    { first_py:"t",full_py:"tun",hanzis:"吞呑旽涒焞朜噋暾屯坉囤忳芚蛌軘豚豘飩鲀魨黗霕臀臋氽褪饨" },
    { first_py:"t",full_py:"tui",hanzis:"忒推蓷藬弚颓隤尵橔頹頺頽魋蘈穨蹪俀腿僓蹆骽侻退娧煺蜕蛻褪駾燵" },
    { first_py:"t",full_py:"tuo",hanzis:"乇仛讬饦托扡汑杔佗侂咜咃沰拖拕说侻莌捝挩袥託飥涶脱脫馲魠鮵阤驮陁陀驼狏岮沱坨柁鸵砣砤袉紽詑酡跎堶馱碢槖駄駝駞橐鴕鮀鼧鵎騨鼍驒驝鼉彵妥庹椭楕嫷橢鰖拓柝毤萚唾跅毻箨嶞魄蘀籜鵇" },
    { first_py:"w",full_py:"wa",hanzis:"屲凹穵劸洼哇挖娲窊畖窐媧啘嗗瓾蛙搲溛漥窪鼃韈攨娃瓦邷佤咓砙袜聉嗢腽膃襪韤瓸甅" },
    { first_py:"w",full_py:"wai",hanzis:"咼歪喎竵崴外顡" },
    { first_py:"w",full_py:"wei",hanzis:"厃危委威烓隈隇偎逶喴葳葨媙崴嵔揻揋愄溦椳楲詴煨微蜲蝛覣縅薇燰鳂癓鰃鰄巍霺囗为韦圩围囲闱违帏沩洈峗峞為韋桅涠帷唯维惟琟嵬媁圍喡幃違湋溈爲維潍鄬蓶潿潙醀鍏闈鮠濰壝矀覹犩欈伟伪苇芛尾纬炜玮洧浘娓荱诿隗偽偉萎崣梶痏硊骩骫骪愇猥渨蒍葦徫廆椲暐煒艉痿瑋韪腲鲔撱嶉僞寪蔿頠緯諉踓韑薳儰濻鍡鮪颹韙瀢韡亹斖卫未位苿味胃畏軎叞菋谓硙尉遗喂媦猬渭煟蔚碨蜼蝟磑犚慰緭熭衛衞餧鮇懀謂罻螱褽魏餵轊藯鏏鳚霨蘶饖讆躗躛讏捤墛嶶" },
    { first_py:"w",full_py:"wang",hanzis:"尢尣尪汪尫尩亾兦亡王仼莣蚟罓罒网彺往徃罔枉惘菵辋棢暀蛧蝄網輞誷魍瀇妄迋忘旺徍望朢" },
    { first_py:"w",full_py:"wen",hanzis:"昷温溫辒殟榅瑥瘟榲緼蕰豱輼轀鳁鞰鰛鰮文芠彣纹炆闻蚊蚉紋阌珳雯駇馼聞瘒鳼鴍魰螡閿閺闅蟁鼤繧闦刎伆吻呅抆呡肳紊桽脗稳穏穩问妏免汶莬問渂揾搵絻顐璺塭鎾饂" },
    { first_py:"w",full_py:"wan",hanzis:"涴弯剜帵婠湾塆睕蜿豌潫彎壪灣丸刓芄汍纨完岏抏玩紈捖顽貦烷頑翫宛倇莞挽盌唍绾埦惋梚菀萖婉脘晚晥晩晼琬皖椀碗畹綰綩輓踠鋔万卐卍忨妧捥脕腕萬蔓輐澫鋄錽薍瞣蟃贃鎫贎乛杤笂琓" },
    { first_py:"w",full_py:"weng",hanzis:"翁嗡滃鹟螉聬鎓鶲勜奣嵡蓊塕暡瞈攚瓮蕹甕罋齆" },
    { first_py:"w",full_py:"wo",hanzis:"挝涡倭莴萵唩猧渦涹窝喔窩蜗蝸踒我婑婐捰仴沃肟枂卧臥捾涴偓幄媉渥握焥硪楃腛斡瞃龌臒瓁濣齷遤" },
    { first_py:"w",full_py:"wu",hanzis:"兀乌邬弙污汙汚圬呜巫杇於屋洿诬钨恶烏剭窏鄔嗚誈誣歍箼螐鴮鎢鰞亡无毋芜吾吴吳呉郚茣莁唔娪峿浯洖梧祦珸铻鹀無蜈鋙蕪墲橆璑鵐蟱鯃譕鼯鷡五午伍仵迕妩庑怃忤玝武侮倵逜陚捂娒娬牾啎珷鹉碔摀熓瑦舞憮潕廡嫵儛甒瞴鵡躌兀勿阢务戊扤屼岉芴坞杌物忢旿矹卼敄俉误務悟悮悞粅晤焐痦婺隖骛嵍靰雾雺嵨奦溩塢鹜熃寤誤鋈窹霚鼿齀霧騖蘁鶩厼朰鯲" },
    { first_py:"x",full_py:"xi",hanzis:"夕兮邜吸汐忚西扸希卥析昔穸肸肹矽怸饻恓郗茜俙徆莃奚娭唏浠狶悕屖栖牺氥息悉硒琋赥釸欷晞桸惜烯焁焈淅渓唽菥傒鄎焟焬犀晰晳翕翖舾粞稀睎惁腊锡皙裼煕厀徯蒠溪嵠僖熙熈熄榽蜥緆餏覡豨瘜磎膝潝嘻噏嬉嬆凞樨橀暿歙熺熻熹螅螇窸羲錫貕蹊豯蟋谿豀瞦燨犠巂繥糦鵗譆醯觹鏭鐊隵酅巇嚱犧曦爔饎觽鼷鸂蠵觿鑴习郋席觋習袭喺媳蓆蒵椺嶍漝趘槢褶薂隰檄謵鎴鳛霫飁騱騽鰼襲驨洗枲玺铣徙喜葸葈鈢鉨鉩蓰漇屣憘歖禧憙諰謑縰壐蟢蹝璽鱚矖囍躧匸卌戏饩屃系呬细郄怬忥盻恄郤係咥屓绤欯阋細釳趇舄舃塈隙椞禊慀隟綌赩熂墍犔稧潟澙戯蕮覤縘黖戱戲磶虩餼鬩繫闟霼衋屭巪凩巼夞莻唟裃硳喸聢噺橲礂鯐" },
    { first_py:"x",full_py:"xia",hanzis:"呷虾谺閕傄颬煆瞎蝦鰕匣狎侠俠狭陜峡炠柙烚峽埉狹祫珨硖翈舺陿假葭硤遐筪瑕舝敮暇辖碬磍蕸縖赮魻霞鍜轄鎋黠騢鶷閜丅下吓疜夏唬厦睱諕懗罅夓鎼鏬圷梺" },
    { first_py:"x",full_py:"xian",hanzis:"仚仙屳纤先奾忺佡氙杴秈苮祆枮籼莶珗掀铦锨酰跹僊僲銛鲜嘕韯銽暹薟憸嬐鍁韱鮮褼繊蹮馦孅攕廯纎鶱躚襳纖鱻闲伭弦咁妶贤胘涎盷咸挦娴娹婱蚿絃衔舷閑閒蛝鹇痫湺啣嗛嫌甉銜誸賢羬稴澖憪嫻嫺撏諴醎輱癇癎瞯藖礥鹹麙贒鷼鷳鷴冼狝险洗显烍毨蚬崄険猃赻铣筅蜆跣禒搟尠尟銑箲險獫嶮獮藓鍌燹顕幰攇蘚櫶譣玁韅顯灦见县苋岘限现线臽県陥宪姭娊峴陷莧哯涀垷埳現晛馅羡缐睍絤腺粯塪献羨僩僴誢綫線鋧撊憲橺橌錎餡縣豏壏麲臔瀗獻糮霰鼸咞衘鑦" },
    { first_py:"x",full_py:"xiang",hanzis:"乡芗相香郷鄉鄊厢廂湘缃鄕葙萫薌箱緗膷襄麘忀骧欀瓖镶纕鑲驤瓨降佭详庠栙祥絴翔詳跭享亯响饷蚃晑飨想銄餉鲞鮝蠁鯗響饗饟鱶向姠巷项珦象項缿衖勨像嶑橡曏襐蟓嚮鐌鱌" },
    { first_py:"x",full_py:"xiao",hanzis:"灱灲肖枭呺哓削侾骁枵绡庨烋宵宯逍消鸮虓婋猇萧梟焇销痚痟翛硝硣窙蛸綃揱箫嘐潇踃歊銷霄獢撨嘵憢膮蕭彇颵魈鴞鴵簘蟏蟂藃穘嚣瀟蟰簫髇櫹囂嚻髐鷍驍蠨毊虈洨郩崤淆訤殽誵小晓暁筱筿皛篠謏曉皢孝効恔咲哮涍俲笑校效啸傚敩詨誟嘨嘋嘯熽歗斆斅﨧" },
    { first_py:"x",full_py:"xing",hanzis:"兴狌星垶骍猩惺煋瑆腥觪篂箵鮏興觲騂曐皨鯹刑邢饧行陉形侀郉陘荥洐型钘娙铏硎鈃蛵滎銒鉶鋞餳省睲醒擤杏性幸姓荇莕倖婞悻涬葕緈﨨嬹臖哘謃" },
    { first_py:"x",full_py:"xin",hanzis:"忄心邤辛芯妡忻炘杺欣昕盺莘俽惞訢鈊锌歆新廞鋅噷嬜薪馨鑫馫枔镡襑鐔伈阠伩囟孞信軐訫脪衅焮馸顖舋釁" },
    { first_py:"x",full_py:"xie",hanzis:"些娎猲揳楔歇蝎蠍叶邪劦协旪胁協奊垥恊峫挟拹挾脇脋脅衺斜谐偕絜翓綊瑎愶嗋携熁膎鲑鞋蝢緳缬撷擕縀勰諧燲嚡擷鞵襭攜孈讗龤写血冩寫藛伳灺绁泄泻祄缷洩炧炨契卸卨屑烲禼徢偰偞焎紲械絏絬亵谢屟媟渫塮僁解靾榭榍褉暬緤噧屧獬嶰澥懈廨邂薤薢糏韰謝褻燮夑瀉鞢齘繲蟹蠏瀣爕齛齥纈齂躞" },
    { first_py:"x",full_py:"xiong",hanzis:"匂凶兄兇匈讻芎忷汹洶恟哅胸胷訩詾賯雄熊熋焸焽诇詗夐敻楿" },
    { first_py:"x",full_py:"xu",hanzis:"吁圩戌盱疞砉欨胥须顼訏許裇虚虗偦谞媭揟湑欻虛須綇楈需魆墟嘘噓蕦嬃歔縃緰蝑諝歘燸譃魖繻驉鬚鑐俆徐冔禑蒣许诩呴姁浒栩珝喣暊詡稰鄦糈諿醑盨旭旴伵芧序汿侐卹怴沀恤昫叙洫晇殈烅珬垿欰畜酗烼绪续敍敘勖勗溆婿壻聓訹絮朂続賉頊滀蓄慉煦槒漵潊銊聟緒盢瞁稸魣緖獝藇藚續鱮﨏蓿" },
    { first_py:"x",full_py:"xiu",hanzis:"休俢修庥咻脩烌羞脙鸺臹貅馐髤銝樇髹鵂鎀鏅饈鱃飍苬朽宿滫潃糔秀岫峀绣珛袖臭琇锈綉溴嗅璓褏褎銹螑繍嚊繡鏥鏽齅鮴" },
    { first_py:"x",full_py:"xue",hanzis:"削疶蒆靴薛辥辪鞾穴斈乴茓峃学泶鸴袕踅學嶨壆噱燢澩觷鷽彐雪鳕鱈吷狘岤坹桖谑趐謔瞲瀥樰膤轌" },
    { first_py:"x",full_py:"xuan",hanzis:"吅轩昍宣弲晅軒梋谖萱萲喧媗揎塇愃愋煖煊蓒暄瑄睻蝖禤箮翧儇鋗鞙蕿嬛懁諠諼駽鍹翾蠉矎蘐藼譞玄县玹痃悬琁旋蜁嫙漩璇暶檈璿懸咺选烜選癣癬券泫怰炫昡绚眩铉袨琄眴衒渲絢楦楥鉉碹蔙镟颴縼繏鏇贙" },
    { first_py:"x",full_py:"xun",hanzis:"坃勋荤埙焄勛塤熏窨勲勳薫薰壎獯曛臐燻蘍矄纁爋壦醺廵巡寻旬杊郇询畃荨荀浔洵峋恂紃珣栒桪毥偱循尋揗詢鲟鄩噚潭潯駨璕攳燖燅樳蟳鱏鱘灥卂讯训迅伨驯汛侚狥逊迿巺徇殉訊訓訙浚奞殾巽稄馴遜愻蕈噀顨鑂嚑" },
    { first_py:"y",full_py:"ya",hanzis:"ㄚ丫圧吖压厌呀庘押枒鸦哑鸭桠孲铔雅椏鴉鴨錏壓鵶鐚牙伢芽岈厓玡琊蚜笌堐猚崖崕涯釾睚衙漄齖疋厊庌疨唖啞痖瘂蕥劜圠轧覀襾冴亚讶迓亜犽亞軋砑挜娅垭俹氩掗訝埡婭猰聐揠氬稏圔窫齾鯲鑓軈" },
    { first_py:"y",full_py:"yan",hanzis:"咽恹烟殷珚胭焉淹淊阏阉崦湮腌硽煙歅鄢傿嫣漹嶖醃閹燕懨嬮篶懕臙黫讠延闫妍芫严阽言訁郔岩沿炎炏昖狿埏莚姸娫研铅盐娮阎啱琂硏訮閆蜒綖筵嵒嵓喦塩揅楌詽碞蔅颜虤閻厳檐顔顏簷壛巌嚴櫩巖巗壧鹽礹麣夵抁沇奄乵兖兗匽弇俨衍剡眼酓偃掩郾厣萒遃隒嵃揜渰渷扊棪愝晻琰罨裺椼演嵼褗蝘魇戭噞躽縯黡檿厴黤甗鶠鰋龑黭黬儼孍顩鼴鼹魘巘巚曮齴黶厌妟觃牪砚姲彦彥烻唁验宴艳晏覎偐谚隁焔焰焱堰喭雁敥猒硯椻鳫滟溎墕熖厭酽暥鴈谳嬊餍燄赝鬳諺鴳曕嚈酀騐験艶贋嚥嬿爓曣騴醶齞鷃贗灔囐鷰驗醼讌觾饜艷釅驠灎灧讞豓豔灩剦樮軅" },
    { first_py:"y",full_py:"yao",hanzis:"幺夭吆约妖殀祅要訞喓葽楆腰鴁鴢徼邀爻尧尭肴侥荛姚峣轺垚烑陶倄珧窑铫堯揺傜谣軺滧徭遥遙嗂媱猺摇搖愮摿榣暚飖瑶瑤餆窯窰磘嶢嶤餚繇謡謠鎐鳐颻蘨邎顤鰩鱙仸宎岆抭杳枖狕苭咬柼眑窅窈舀偠婹崾溔蓔榚闄騕齩鷕疟穾药钥袎窔葯筄詏靿覞熎鹞獟鼼薬藥燿曜艞矅耀纅鷂讑" },
    { first_py:"y",full_py:"yang",hanzis:"央姎抰泱殃胦秧眏鸯鉠雵鞅鴦鍈阳阦扬羊飏炀杨旸钖疡氜劷佯徉洋垟昜羏珜烊陽眻蛘揚崵崸煬楊敭瑒暘瘍輰諹鍚鴹颺鰑霷鸉卬仰佒咉岟坱炴柍养氧痒紻軮楧傟慃氱飬蝆養駚懩攁瀁癢怏恙样羕詇漾様樣礢" },
    { first_py:"y",full_py:"ye",hanzis:"吔耶倻掖椰暍歋潱噎擨蠮邪爷捓揶铘爺瑘鋣鎁ㄝ也冶野埜嘢漜壄业叶曳页曵邺抴夜枼拽亱咽頁捙枽烨晔液谒葉腋殗業煠馌墷璍僷燁曅曄皣瞱擛鄴靥餣謁嶪嶫澲擫瞸曗鍱鎑饁擪礏爗鵺鐷靨驜鸈丆亪" },
    { first_py:"y",full_py:"yi",hanzis:"一弌衤伊衣医吚壱依祎洢咿郼渏悘铱猗蛜壹揖椅禕漪稦銥嫛嬄撎夁噫瑿鹥繄檥檹醫毉黟譩鷖黳乁义匜仪夷圯宐诒冝杝沂沶侇迤宜狋怡饴拸姨恞贻峓迻荑瓵珆咦訑貤胰栘桋巸眙袘宧扅萓蛇痍移椬蛦貽詒羠遗媐颐飴頉誃跠椸暆疑熪遺儀彛彜嶬螔頤頥顊鴺鮧簃嶷寲彝彞謻鏔籎觺讉乙已以迆钇攺矣苡佁尾苢迱庡舣蚁釔笖酏扆逘倚偯旑崺鈘鉯鳦裿蛾旖踦輢螘敼嬟礒蟻艤顗轙齮乂亿弋刈艺忆艾阣仡议肊伇芅亦异忔屹抑坄呓劮役苅佚译耴杙邑枍炈易衪秇诣佾呹呭驿泆怿怈绎峄浂帟帠俋弈奕疫羿昳玴轶枻食栧欭袣益谊唈浥浳挹悒垼埸埶逸勚萟殹翊翌悥豙豛異訲訳隿釴羛鈠軼骮跇詍晹敡殔棭焲蛡鄓湙幆嗌溢缢兿義亄睪獈竩痬意詣肄裔裛駅榏瘗膉蜴蓺勩廙嫕潩億鹝鹢毅镒瘞槸熠熤熼篒誼黓艗燚曀殪瘱瞖穓螠褹縊劓薏澺嬑嶧墿圛懌憶寱翳翼臆斁歝曎燡燱檍賹貖鮨鎰贀镱癔藝藙繹繶豷霬鯣鶂鶃饐醷醳譯議蘙瀷囈鐿鷊鷁懿襼鷧驛鷾鸃虉齸讛辷匇凧弬夞畩鶍鶎" },
    { first_py:"y",full_py:"yin",hanzis:"囙因阴阥侌茵骃姻洇垔音栶氤殷陰隂陻凐秵铟裀絪筃堙愔喑婣溵蔭蒑禋慇瘖銦鞇磤緸諲霒駰霠闉噾濦齗韾冘乑吟犾圻烎斦泿垠圁狺峾荶珢訚訔訡银淫寅婬崟崯鈝龂滛碒鄞蔩夤銀龈誾璌殥噖嚚蟫檭霪齦鷣廴引尹饮吲蚓隐赺鈏飲淾隠飮靷輑朄趛瘾檃隱嶾濥螾檼蘟櫽癮讔印茚荫洕胤垽堷湚猌廕窨酳癊慭憖憗鮣懚岃粌" },
    { first_py:"y",full_py:"ying",hanzis:"应応英莺珱偀渶绬婴媖瑛煐朠锳碤嫈嘤缨撄甇緓蝧罂賏樱璎鹦噟霙罃褮鴬韺嬰膺應鹰甖鶑鶧罌譍孆嚶攖蘡孾瀴櫻瓔礯譻鶯鑍鷪蠳纓鷹鸎鸚迎盁茔荥荧盈莹萤营萦蛍営萾溁溋滢蓥塋楹僌颖熒蝇潆蝿禜瑩螢營嬴縈覮謍赢濙濚濴藀瀅蠅鎣巆攍瀛瀯瀠贏櫿灐籝灜籯郢矨浧梬颍颕摬影潁穎瘿頴鐛廮巊癭映暎硬媵膡鱦栍桜愥闏" },
    { first_py:"y",full_py:"yo",hanzis:"育哟唷喲罀" },
    { first_py:"y",full_py:"yong",hanzis:"佣拥邕痈庸傭嗈鄘雍嫞滽墉慵牅壅澭擁噰镛郺臃癕雝鳙鏞灉廱饔鷛鱅癰喁颙顒鰫永甬咏泳勇勈俑栐柡悀涌埇恿惥愑湧詠硧蛹塎嵱彮愹慂踊鲬踴鯒用苚蒏醟怺砽" },
    { first_py:"y",full_py:"you",hanzis:"优忧攸怮呦泑幽峳浟逌悠麀羪滺憂鄾優瀀嚘懮櫌耰纋尢尤由甴沋邮犹油怞肬怣疣柚庮郵莜莸秞铀蚰訧偤逰遊猶游鱿鲉鈾楢猷輏駀魷蝤蝣蕕鮋輶繇友有酉丣卣苃羑莠栯梄铕聈湵蜏禉銪槱牖牗黝又右幼佑侑狖峟囿牰祐迶哊宥姷诱唀蚴亴釉貁酭誘褎鼬櫾孧" },
    { first_py:"y",full_py:"yue",hanzis:"曰曱约約箹矱哕噦月乐戉刖妜岄抈礿玥泧岳说恱栎钥钺蚏蚎阅軏悦悅捳跃跀鈅越粤粵鉞閲閱篗樾嬳嶽龠籆蘥瀹黦躍爚禴籥鑰鸑籰鸙" },
    { first_py:"y",full_py:"yuan",hanzis:"囦肙鸢剈冤鸳眢寃涴渊渁渆渕淵葾惌蒬棩鹓裷蜎箢鳶駌蜵鴛鵷嬽灁鼘鼝元円邧贠沅园芫员茒杬垣爰貟笎蚖袁圆原員厡媛猨援圎湲鼋缘鈨源溒園圓塬猿嫄媴蒝辕榞榬緣魭縁褤蝯蝝螈黿羱薗橼圜轅謜鎱櫞邍騵鶢鶰厵远盶逺遠鋺夗苑妴院怨衏垸傆掾禐瑗愿裫褑噮願" },
    { first_py:"y",full_py:"yu",hanzis:"込迂迃吁扝扜纡於穻陓紆盓菸淤唹瘀箊与于亐予邘伃余妤扵杅欤玙玗盂衧臾鱼舁竽虶禺茰俞兪谀娱娛娯馀狳桙酑雩魚渔萸隅隃萮渝湡揄堣堬嵎嵛崳逾喁楰愉腴畬骬虞艅觎愚瑜歈榆楡牏舆窬睮褕漁蕍蝓歶雓餘諛羭踰覦嬩澞璵歟螸輿鍝謣髃鮽騟籅旟轝蘛鰅鷠鸆齵屿宇伛羽妪雨俣俁语挧禹圄祤圉敔匬鄅偊庾萭斞铻瘐楀與瑀傴寙語窳頨龉貐懙噳嶼斔穥麌齬肀驭玉聿芋芌圫饫汩忬谷欥育郁茟狱秗昱浴峪彧俼预钰砡粖袬谕逳菀尉阈淯淢惐悆欲域堉棫棛棜琙焴寓媀喻喅喩庽御遇馭飫粥鹆硲硢矞裕鈺誉罭預蓣蒮煜滪愈稢戫蔚僪隩嶎獄嫗緎蜮蜟毓瘉銉輍豫鋊鳿遹薁蓹熨潏稶慾澦燠燏蕷鴥鴪鴧錥諭閾礇禦鹬魊儥鵒礜癒醧篽饇櫲蘌霱譽鐭雤鬻驈欎鷸鱊籞鸒欝龥鬰鬱籲灪爩礖軉" },
    { first_py:"y",full_py:"yun",hanzis:"晕蒀缊蒕煴氲氳熅奫蝹赟馧贇匀勻云伝芸员妘沄纭囩昀秐眃畇郧涢耺耘紜雲鄖蒷溳愪筠筼熉澐蕓鋆篔縜橒允阭狁抎夽陨荺殒隕喗鈗馻殞磒賱霣齫齳孕运郓枟恽酝鄆傊運愠惲慍暈韫腪韵褞熨蕴薀縕醖醞餫韞韗藴蘊韻抣" },
    { first_py:"z",full_py:"za",hanzis:"帀扎匝沞咂拶桚鉔魳臜臢杂沯砸韴雑襍雜囃囋雥咋乽橴" },
    { first_py:"z",full_py:"zan",hanzis:"兂糌橵篸簪簮鵤鐟鐕咱偺喒拶昝寁揝撍噆儧攅攒儹攢趱趲暂暫賛赞錾鄼酂濽蹔鏨贊瓉瓒酇囋灒讃瓚禶襸讚饡" },
    { first_py:"z",full_py:"zao",hanzis:"傮遭糟醩蹧凿鑿早枣蚤棗澡璪薻藻灶皂皁造唣唕梍慥煰喿艁簉噪燥竃竈譟趮躁栆" },
    { first_py:"z",full_py:"zang",hanzis:"匨赃牂脏羘賍賘臧贓髒贜驵駔奘弉塟葬蔵銺藏臓臟欌" },
    { first_py:"z",full_py:"zai",hanzis:"灾災甾哉烖栽渽溨睵賳仔宰载崽再扗在洅傤載酨儎縡岾" },
    { first_py:"z",full_py:"ze",hanzis:"则沢泽泎责迮咋择則帻啧啫舴笮責矠滜溭箦嘖嫧幘蔶赜樍歵諎擇瞔皟簀賾礋襗謮蠌齚齰鸅仄庂汄昃昗侧捑崱択硳" },
    { first_py:"z",full_py:"zeng",hanzis:"曽曾増鄫缯增憎橧璔磳矰罾繒譄综锃鋥赠熷甑鬵贈囎" },
    { first_py:"z",full_py:"zen",hanzis:"怎谮譖" },
    { first_py:"z",full_py:"zei",hanzis:"贼戝賊鲗蠈鰂鱡" },
    { first_py:"z",full_py:"zha",hanzis:"扎吒咋抯挓查柤奓紥哳偧紮渣溠喳猹揸楂劄摣皶觰樝皻譇齄齇轧札闸炸铡蚻喋牐閘箚耫鍘譗厏苲拃眨砟鲊鲝鮓鮺乍诈灹咤栅柞痄宱蚱詐搾槎榨蜡霅醡蓙" },
    { first_py:"z",full_py:"zhai",hanzis:"侧夈捚斋斎摘榸齋宅择翟檡窄鉙责柴债砦祭債寨粂瘵" },
    { first_py:"z",full_py:"zhan",hanzis:"占沾枬毡旃栴蛅粘飦趈詀惉詹閚谵薝邅噡嶦霑氊氈瞻鹯旜譫饘鳣魙驙鸇鱣讝斩飐盏展崭斬琖盞搌辗嶄嶃榐颭醆嫸橏輾黵佔战栈桟站绽偡菚湛棧戦綻輚嶘戰虥虦襢覱轏譧驏蘸" },
    { first_py:"z",full_py:"zhao",hanzis:"佋钊妱招巶昭釗着啁朝鉊鼌駋嘲鍣皽爫爪找沼瑵召兆诏枛炤狣垗赵笊肁棹旐詔罩照肇肈箌趙曌燳鮡瞾櫂羄罀" },
    { first_py:"z",full_py:"zhang",hanzis:"仉张張章鄣傽蔁遧粻嫜獐彰漳慞樟暲璋餦蟑騿麞鱆长涨掌漲礃丈仗扙帐杖胀账涱帳脹障痮幛嶂墇賬瘴瘬瞕粀幥鏱" },
    { first_py:"z",full_py:"zhe",hanzis:"折蜇遮嗻嫬螫厇歽矺砓虴籷袩埑哲啠辄晢晣悊喆詟蛰谪摺輒輙銸磔辙蟄鮿謫謺嚞轍讁讋者锗褚赭踷鍺褶襵这柘這浙淛蔗樜鹧蟅鷓粍" },
    { first_py:"z",full_py:"zhei",hanzis:"这" },
    { first_py:"z",full_py:"zhong",hanzis:"中伀汷彸刣忪妐炂忠泈终钟柊盅衳舯衷終鈡蜙锺幒蔠銿鴤螤螽鍾鼨蹱鐘籦肿种冢喠尰煄腫歱塚種瘇徸踵众仲妕狆祌衶重茽蚛眾偅堹媑筗衆諥" },
    { first_py:"z",full_py:"zheng",hanzis:"丁正争佂诤征姃怔爭糽埩炡政挣狰峥烝脀钲眐症聇睁铮掙崝崢猙揁媜筝踭鉦睜徰蒸錚箏篜鲭鬇癥鏳氶抍拯掟晸愸撜整证郑証幁塣諍靕鄭鴊證" },
    { first_py:"z",full_py:"zhi",hanzis:"之氏支只卮汁芝汦汥吱巵知肢泜织枝栀祗胝胑秓衼疷隻脂祬栺倁梔椥臸綕禔稙搘馶蜘榰憄鳷鴲織鼅蘵执侄妷直姪值値聀釞职淔埴執殖戠植犆禃跖絷瓡馽摭潪嬂漐慹踯膱樴縶蹢蹠職蟙軄躑夂止阯劧旨帋芷扺沚纸址坁坧抧茋祉秖恉轵枳砋衹咫指洔淽茝紙疻訨趾黹軹酯徴墌徵藢襧芖至豸扻伿识忮志炙质治垁郅迣厔制帜帙挃庢庤陟峙洷栉柣祑挚桎晊歭秩贽轾徏娡狾致袟紩畤窒痔痓铚鸷貭翐觗袠猘徝掷乿剬偫秷梽智滞崻傂骘痣彘蛭置锧跱輊筫雉寘搱廌滍稚滯墆銍製覟誌瘈疐觯踬質鋕熫稺膣摯摨幟擳隲璏旘瀄鴙駤緻螲懥櫛穉儨劕擿擲懫贄觶騭鯯櫍瓆豑礩騺驇鷙躓鑕豒俧潌" },
    { first_py:"z",full_py:"zhou",hanzis:"州舟诌侜周洲诪炿烐珘调郮辀婤淍啁週徟鸼矪粥喌赒輈銂輖賙霌鵃謅盩嚋騆譸妯轴軸肘疛帚菷晭睭箒鯞纣伷咒呪绉宙冑祝昼咮荮紂胄皱酎粙舳晝葤詋甃僽駎皺縐噣骤繇籀籕籒驟碡駲" },
    { first_py:"z",full_py:"zhua",hanzis:"抓挝撾檛膼簻髽爪" },
    { first_py:"z",full_py:"zhu",hanzis:"朱邾侏诛茱洙诸珠株猪秼铢硃袾蛛絑誅跦銖槠蝫潴蕏橥諸豬駯鴸鮢鼄藸瀦鯺櫫櫧蠩术竹竺笁柚茿炢烛逐窋笜逫蓫瘃篴燭蠋躅鱁劚孎灟爥斸欘曯蠾钃丶主劯宔拄柱罜陼帾渚煮煑属詝褚濐嘱燝麈瞩囑鸀矚宁伫住佇芧苎助纻坾贮驻迬杼拀注祝柷炷殶壴莇祩竚眝疰砫蛀紵紸著庶羜铸筑貯軴註跓嵀鉒筯飳馵箸翥樦鋳駐麆築篫簗鑄墸" },
    { first_py:"z",full_py:"zhen",hanzis:"贞针侦帧浈胗珍珎貞針祯桢真眞砧帪偵酙葴幀寊湞遉斟溱嫃獉搸蓁蒖甄椹楨禎鉁禛瑧榛碪殝潧箴臻樼澵薽錱轃鍼籈鱵诊枕抮轸昣弫姫屒眕疹畛袗聄紾裖軫覙診缜駗稹縝縥辴鬒黰阵圳纼甽鸩陣侲挋振栚朕紖眹赈塦揕絼賑誫镇震鴆鎭鎮鋴" },
    { first_py:"z",full_py:"zhuai",hanzis:"拽转跩" },
    { first_py:"z",full_py:"zhui",hanzis:"隹追骓椎锥錐騅鵻沝坠笍娷缀缒甀腏惴畷膇硾墜綴赘縋諈醊錣礈贅鑆" },
    { first_py:"z",full_py:"zhuang",hanzis:"庄妆妝庒荘莊娤桩梉粧装湷裝樁糚奘壮壯状狀壵焋僮幢撞戆" },
    { first_py:"z",full_py:"zhuan",hanzis:"专叀専砖專鄟嫥塼甎瑼膞磗颛磚諯顓蟤鱄转孨竱轉传沌灷啭転堟蒃瑑腞赚僎馔撰篆篹襈縳賺譔饌籑囀" },
    { first_py:"z",full_py:"zhun",hanzis:"屯迍宒肫窀谆啍諄衠准埻凖準綧訰稕" },
    { first_py:"z",full_py:"zhuo",hanzis:"拙炪捉倬桌棁梲涿棳焯槕穛擢鐯穱彴犳汋圴灼妰卓叕茁浊斫烵浞诼丵酌娺啄啅着椓晫斮斱琢琸硺罬窡禚斲撯擆劅諑諁鋜篧缴濁濯斵斀謶镯櫡鵫躅蠗灂鐲鷟籗蠿籱窧" },
    { first_py:"z",full_py:"zou",hanzis:"邹驺陬郰诹菆掫棷棸鄒緅箃諏鲰鄹黀鯫騶齱齺赱走奏揍" },
    { first_py:"z",full_py:"zong",hanzis:"宗枞倧骔综堫惾腙葼猣嵏嵕棕椶朡稯嵸潈綜緃翪踪踨緵熧蝬磫繌鍐鬃騌蹤騣鯮鬉鬷鯼鑁总倊偬捴揔搃惣焧傯蓗摠総縂緫燪總纵昮疭猔碂粽糉瘲縦縱豵糭" },
    { first_py:"z",full_py:"zi",hanzis:"仔孖孜吱甾茊茲兹姿姕咨赀资玆栥紎赼缁秶崰淄谘菑葘鄑滋湽嵫椔粢辎嗞孳孶锱禌趑觜訾資貲緇緕龇鈭稵镃輜鼒鲻髭輺錙諮趦澬鍿鎡頾頿齍鶅鯔鰦纃齜蓻子吇杍姊姉胏秄矷虸耔籽秭呰茈笫釨梓啙紫滓訿榟字芓自荢茡剚倳牸恣眦眥渍胾胔漬嗭魸鯑" },
    { first_py:"z",full_py:"zu",hanzis:"苴租菹葅蒩卆足卒哫崒崪族椊箤踤镞鏃阻诅组祖珇爼俎唨組詛靻鼡乼" },
    { first_py:"z",full_py:"zun",hanzis:"尊嶟遵樽罇繜鐏鳟鷷鱒僔噂撙譐捘銌" },
    { first_py:"z",full_py:"zui",hanzis:"咀厜脧嗺樶蟕纗觜嶊嘴噿璻栬冣絊酔晬祽最稡罪辠酻槜醉蕞嶵鋷錊檇檌" },
    { first_py:"z",full_py:"zuan",hanzis:"钻鉆劗鑚躜躦鑽篹繤缵纂纉纘籫赚攥" },
    { first_py:"z",full_py:"zuo",hanzis:"作嘬穝昨莋秨笮捽琢筰鈼稓左佐撮繓阼坐怍岞岝侳祚胙袏座唑做葃葄飵糳咗" }
];


/** ## 获取【姓名】唯一拼音
 * @param {string} inStr 输入姓名
 * @returns 输出：唯一拼音，多音字的处理倾向姓、名读音  
 * @适用场景 获取姓名的唯一拼音  
 */
export function getUniquePingyinForName(inStr) {
    if (!inStr || typeof(inStr)!=='string') {
        return false;
    }
    //
    let nameObj = myNameSplit(inStr);
    let fullPy = getNamePingyin(nameObj.lastName,true) + getNamePingyin(nameObj.firstName,false);
    return {
        fristPy: getFristPyByFullPy(fullPy),
        fullPy: fullPy
    };
}
/** ## 获取【常用】唯一拼音
 * @param {string} inStr 输入：日常汉字、短语、名词、词条、名称
 * @returns 输出：唯一拼音，多音字的处理倾向日常、常用、高频读音
 * @适用场景 获取常用词条、条目名称的唯一拼音  
 */
export function getUniquePingyinForCommon(inStr) {
    if (!inStr || typeof(inStr)!=='string') {
        return false;
    }
    let fullPy = getNamePingyin(inStr, false);
    return {
        fristPy: getFristPyByFullPy(fullPy),
        fullPy: fullPy
    };
}

/** ## 获取【字符】所有拼音
 * @param {string} inStr 随意属于
 * @returns 输出：所有的拼音组合
 * @适用场景 获取输入内容的所有拼音组合，然后自行决定选用那个
 * @适用技巧 配合getUniquePingyinForName(),getUniquePingyinForCommon()可将最佳预测放在第一个
*/
export function getAllComPingyinForStr(inStr){
	// --- 条件返回
	let outFrist_py = [];
	let outFull_py = [];
	if (!inStr){
		return false;
	}
	// --- 获取每个字的所有读音
	let numOfWord = inStr.length;
	let fristPys=[];
	let fullPys=[];
	for (let i_word = 0; i_word < numOfWord; i_word++){
        let tmp = getAllPingyinForWord(inStr.charAt(i_word), true);
        if (tmp) {
            fristPys.push(tmp.fristPys);
		    fullPys.push(tmp.fullPys);
        }
	}
	// --- 开始排列组合
	let nowIndexList=[];
	let maxIndexList=[];
	let sum_maxIndexList = 0;
	for (let i = 0; i < numOfWord; i++){
		nowIndexList.push(0);
		maxIndexList.push(fullPys[i].length - 1);
		sum_maxIndexList += maxIndexList[i];
	}
	// --- 第一次组合（所有采用第一个）
    let mustCombination = sum_maxIndexList > 0 ? true : false;
    let fristPy="";
	let fullPy="";
	for (let i = 0; i < numOfWord; i++){
		fristPy += fristPys[i][0];
		fullPy += fullPys[i][0];
    }
    outFrist_py.push(fristPy);
    outFull_py.push(fullPy);

    
	// --- 循环遍历
	while (mustCombination){
		// --- 组合排列
		let alreadyRunOnce = false;
		for (let i = 0; i < numOfWord; i++){
			if (alreadyRunOnce){
				break;
			}
			if (maxIndexList[i] != 0){
				if (nowIndexList[i] < maxIndexList[i]){
					alreadyRunOnce = true;
					nowIndexList[i]++;
				}else if (nowIndexList[i] === maxIndexList[i]){
					nowIndexList[i] = 0;
				}
			}
		}
		// --- 组合输出字符
		fristPy='';
	    fullPy='';
		for (let i = 0; i < numOfWord; i++){
			fristPy += fristPys[i][nowIndexList[i]];
			fullPy += fullPys[i][nowIndexList[i]];
        }
        outFrist_py.push(fristPy);
        outFull_py.push(fullPy);
		// --- 退出条件
		let canOut = true;
		for (let i = 0; i < numOfWord; i++){
			if (nowIndexList[i] != maxIndexList[i]){
				canOut = false;
				break;
			}
		}
		if (canOut){
			break;
		}
	}
    // --- 返回
    let outList = [];
    for (let i = 0; i < outFrist_py.length; i++) {
        outList.push({
            fristPy:outFrist_py[i],
            fullPy:outFull_py[i]
        })
    }
    return outList;
}

// 获取字的所有拼音
function getAllPingyinForWord(inWord){
    // 只能输入一个字符
	if (inWord.length > 1){
		return false;
    }
	// 清空
	let fristPys = [];
    let fullPys = [];
    // 查找       
	if (g_hanziRegExp.test(inWord)){
		for (let index_table = 0; index_table < g_length_hanziTables; index_table++){
            if (hanziTables[index_table].hanzis.includes(inWord)) {
                fristPys.push(toFristUpperCaseMode(hanziTables[index_table].first_py));
                fullPys.push(toFristUpperCaseMode(hanziTables[index_table].full_py));
			}
		}
	}
    // 返回
	if (fristPys.length <= 0){
		fristPys.push(inWord);
	}
	if (fullPys.length <= 0){
		fullPys.push(inWord);
	}
    return {
        fristPys:fristPys,
        fullPys:fullPys
    };
}

// 获取姓名专属拼音
function getNamePingyin(inStr, isLastName){
	let outStr = "";
	// ----- 姓氏
	if (isLastName && g_hanziRegExp.test(inStr)){
		// --- 在百家姓中查找
		for (let i = 0; i < g_length_lastNameTable; i++){
			if (inStr === lastNameTable[i].hanzi){
				outStr = toFristUpperCaseMode(lastNameTable[i].pinyi);
				break;
			}
		}
	}
	// --- 直接汉字库查找
	if (!outStr){
		for (let i = 0; i < inStr.length; i++){
			outStr += getNoRepeatPingyinForWord(inStr[i]);
		}
	}
    // 返回
	return outStr;
}

// 切分：姓、名
function myNameSplit(inFullName){
	let doubleLastNameLength = 90;
	let doubleLastName = [
		"欧阳" , "太史" , "端木" , "上官" , "司马" , "东方" , "独孤" , "南宫" , "万俟" , "闻人" ,
		"夏侯" , "诸葛" , "尉迟" , "公羊" , "赫连" , "澹台" , "皇甫" , "宗政" , "濮阳" , "公冶" ,
		"太叔" , "申屠" , "公孙" , "慕容" , "仲孙" , "钟离" , "长孙" , "宇文" , "司徒" , "鲜于" ,
		"司空" , "闾丘" , "子车" , "亓官" , "司寇" , "巫马" , "公西" , "颛孙" , "壤驷" , "公良" ,
		"漆雕" , "乐正" , "宰父" , "谷梁" , "拓跋" , "夹谷" , "轩辕" , "令狐" , "段干" , "百里" ,
		"呼延" , "东郭" , "南门" , "羊舌" , "微生" , "公户" , "公玉" , "公仪" , "梁丘" , "公仲" ,
		"公上" , "公门" , "公山" , "公坚" , "左丘" , "公伯" , "西门" , "公祖" , "第五" , "公乘" ,
		"贯丘" , "公皙" , "南荣" , "东里" , "东宫" , "仲长" , "子书" , "子桑" , "即墨" , "达奚" ,
		"褚师" , "吴铭" , "纳兰" , "归海" , "东皇" , "泽翁" , "阿扎" , "泽朗" , "索朗" , "邓真"
    ];
	// --- 如果有非汉字字符，直接返回
	for (let i = 0; i < inFullName.length; i++){
		if (!g_hanziRegExp.test(inFullName.charAt(i))){
            return {
                lastName:"",
                firstName:inFullName
            };
		}
	}
	//
	let outLastName = "";
	let outFirstName = "";
	if (!inFullName){
	}
	else if (inFullName.length === 1){
		outFirstName = inFullName;
	}
	else if (inFullName.length === 2){
		outLastName = inFullName.charAt(0);
		outFirstName = inFullName.charAt(1);
	}else{
		let guessLastName = inFullName.substr(0,2);
		for (let i = 0; i < doubleLastNameLength; i++){
			if (guessLastName === doubleLastName[i]){
				outLastName = doubleLastName[i];
				outFirstName = inFullName.substr(2);
				break;
			}
        }
        if (!outLastName){
			if (inFullName.length === 4){
				outLastName = inFullName.substr(0,2);
				outFirstName = inFullName.substr(2);
			}else{
				outLastName = inFullName.charAt(0);
				outFirstName = inFullName.substr(1);
			}			
		}
    }
    // 返回
    return {
        lastName: outLastName,
        firstName: outFirstName
    };
}

// 获取唯一拼音
// 输入任何单字符都会返回
function getNoRepeatPingyinForWord(inWord){
	let outPingyin = "";
	// 只能输入一个字符
	if (inWord.length !== 1){
		return false;
    }
    // --- 汉字
    if (g_hanziRegExp.test(inWord)) {
        // ----- 先在多音字里面查询
        for (let i = 0; i < g_length_multiToneWordTable; i++){
            if (inWord === multiToneWordTable[i].hanzi) {
                outPingyin = toFristUpperCaseMode(multiToneWordTable[i].pinyin);
                break;
            }
        }
        // ----- 在全字库查找
        if (!outPingyin) {
            for (let index_table = 0; index_table < g_length_hanziTables; index_table++){
                if (hanziTables[index_table].hanzis.includes(inWord)){
                    outPingyin = toFristUpperCaseMode(hanziTables[index_table].full_py);
                    break;
                }
            }
        }
        // ----- 未知汉字
        if (!outPingyin) {
            outPingyin = inWord;
        }
    } else {
        outPingyin = inWord;
    }
	
	// ----- 返回结果
	return outPingyin;
}

// 转换为首字母大写
function toFristUpperCaseMode(inStr) {
    return inStr.substr(0, 1).toUpperCase() + inStr.substr(1);
}
// 获取简拼
function getFristPyByFullPy(fullPy) {
    // 删除小写字符(逻辑仍然不严谨)
    return fullPy.replace(/[a-z]/g, '');

    // 之前的逻辑：保留大写字符（逻辑超烂，需要保留特殊字符）
    // let upperCaseStrs = fullPy.match(/[A-Z]/g);
    // if (upperCaseStrs) {
    //     return upperCaseStrs.toString().replace(/,/g, '');
    // } else {
    //     return '';
    // }
}
