/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: landlord.h
 *
 * @breaf: 斗地主牌型
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/05/02 16时15分45秒
 *
 **/



#ifndef  LANDLORD_INC
#define  LANDLORD_INC

#include <vector>
#include <map>

namespace poker {

static int kHandCardsCount = 3;
static int kFarmerCardsCount = 17;
static int LandloadCardsCount = 20;
static int kTotalCardsCount = 54;


enum Category {
    Invalid,               // 无效牌型
    Single,                // 单牌(A)
    Double,                // 对子(AA)
    Triple,                // 三张(AAA)
    SingleChain,           // 顺子(34567)
    DoubleChain,           // 连对(334455)
    TripleChain,           // 三连(333444)
    TriplePlusSingle,      // 三带一(3334)
    TriplePlusDouble,      // 三带二(33344)
    TripleChainPlusSingle, // 飞机带翅膀(33344456)
    TripleChainPlusDouble, // 飞机带翅膀(3334445566)
    QuadruplePlusSingle,   // 四带二(333345)
    QuadruplePlusDouble,   // 四带两对(33334455)
    Bomb,                  // 炸弹(3333)
    Rocket                 // 火箭
};

// 掩码
// 高8位表示花色
// 低8位表示数字
// | ------- | --------- | --------- | --------- |
// 保留4bits + 花色4bits + 8bits值
enum Mask {
    Color = 0x0F00,
    Value = 0x00FF
};

enum Color {
    // 方片
    Diamonds   = 0x0100,
    // 梅花
    Plum       = 0x0200,
    // 红桃
    Heart      = 0x0300,
    // 黑桃
    Spade      = 0x0400,
    // 小王
    BlackJoker = 0x0500,
    // 大王
    RedJoker   = 0x0600
};

const std::vector<short> CardsMask = {
    0x0103, 0x0104, 0x0105, 0x0106, 0x0107, 0x0108, 0x0109, 0x010A, 0x010B, 0x010C, 0x010D, 0x010E, 0x010F,
    0x0203, 0x0204, 0x0205, 0x0206, 0x0207, 0x0208, 0x0209, 0x020A, 0x020B, 0x020C, 0x020D, 0x020E, 0x020F,
    0x0303, 0x0304, 0x0305, 0x0306, 0x0307, 0x0308, 0x0309, 0x030A, 0x030B, 0x030C, 0x030D, 0x030E, 0x030F,
    0x0403, 0x0404, 0x0405, 0x0406, 0x0407, 0x0408, 0x0409, 0x040A, 0x040B, 0x040C, 0x040D, 0x040E, 0x040F,
    0x0510, // 小王
    0x0611  // 大王
};

// 数量可能映射的牌型
extern std::map<short, std::vector<Category>> CategoryMap;

class LandlordUtil {
public:
    // 拷贝原始牌码
    static std::vector<short> clone_cards_mask();
    // 点数
    static short value(short card);
    // 花色
    static short color(short card);
    // 牌描述信息
    static std::wstring description(const std::vector<short> &cards);
    // 洗牌
    static void shuffle_cards(std::vector<short> &cards);
    // 排序
    static void sort_cards(std::vector<short> &cards, bool pred);
    // 牌序列中是否有指定的一张牌
    static bool contains(const std::vector<short> &cards, short card);
    /**
     * @brief 牌序列中是否有指定的一组牌
     *
     * @param cards 序列
     * @param subcards 比较子序列
     *
     */
    static bool contains(const std::vector<short> &cards, const std::vector<short> &subcards); 
    /**
     * @brief 判断单牌
     *
     * @param cards
     *
     * @return  true 是单牌; false 不是单牌
     */
    static bool is_single(const std::vector<short> &cards);
    /**
     * @brief 判断对子
     *
     * @param cards 输入序列
     *
     * @return  true 是对子; false 不是对子
     */
    static bool is_double(const std::vector<short> &cards);
    /**
     * @brief 判断三张
     *
     * @param cards 输入序列
     *
     * @return  true 是三张; false 不是三张
     */
    static bool is_triple(const std::vector<short> &cards);
    /**
     * @brief 判断三带一
     *
     * @param cards 输入序列
     *
     * @return  true 是三带一; false 不是三带一
     */
    static bool is_triple_plus_single(const std::vector<short> &cards);
    /**
     * @brief 判断三带二
     *
     * @param cards 输入序列
     *
     * @return true 是三带二; false 不是三带二
     */
    static bool is_triple_plus_double(const std::vector<short> &cards);
    // 判断顺子
    static bool is_single_chain(const std::vector<short> &cards);
    // 判断连对
    static bool is_double_chain(const std::vector<short> &cards);
    // 判断三顺
    static bool is_triple_chain(const std::vector<short> &cards);
    // 判断飞机带2单
    static bool is_triple_chain_plus_single(const std::vector<short> &cards);
    // 判断飞机2对
    static bool is_triple_chain_plus_double(const std::vector<short> &cards);
    // 判断四带2单
    static bool is_quadruple_plus_single(const std::vector<short> &cards);
    // 判断四带2对
    static bool is_quadruple_plus_double(const std::vector<short> &cards);
    // 判断炸弹
    static bool is_bomb(const std::vector<short> &cards);
    // 判断王炸
    static bool is_rocket(const std::vector<short> &cards);

    // 是否是指定类型的牌
    static bool is_category(const std::vector<short> &cards, Category category);

    // 从input里抽取count张牌
    static std::vector<short> extra_cards(std::vector<short> &input, int count);
    
    static Category trait_category(const std::vector<short> &sequce);

private:
    static bool is_same(const std::vector<short> &cards);
    static bool is_same(const std::vector<short> &cards, int from, int n);

    static bool verify(const std::vector<short> &cards, int from , int n);
};

} // namespace poker

#endif   // ----- #ifndef LANDLORD_INC  -----
