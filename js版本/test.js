import { getUniquePingyinForName, getUniquePingyinForCommon, getAllComPingyinForStr } from './pinyin';
/**
 * 
 * @param {String} inStr 输入字符
 * @param {String} mode 模式 ['name','common']
 * @returns
 */
function getPingyinOptions(inStr,mode){
    // 获取拼音
    let unqPinyin = '';
    if (mode === 'name') {
        unqPinyin = getUniquePingyinForName(inStr);
    } else {
        unqPinyin = getUniquePingyinForCommon(inStr);
    }
    let comPinyins = getAllComPingyinForStr(inStr);
    if (!unqPinyin || !comPinyins) {
        return false;
    }

    // 让第一个为预测的最佳拼音
    comPinyins = comPinyins.filter((element) => {
        return unqPinyin.fullPy !== element.fullPy;
    });
    comPinyins.unshift(unqPinyin);

    //
    return comPinyins
}
