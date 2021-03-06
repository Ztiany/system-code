#include "chars.h"

/**
 * ROT13（回转 13 位，rotateby13places，有时中间加了个减号称作ROT-13）是一种简易的置换暗码。
 * ROT-13 编码是一种每一个字母被另一个字母代替的方法。这个代替字母是由原来的字母向前移动 13 个字母而得到的。数字和非字母字符保持不变。
 * 它是一种在网路论坛用作隐藏八卦、妙句、谜题解答以及某些脏话的工具，目的是逃过版主或管理员的匆匆一瞥。
 * ROT13 激励了广泛的线上书信撰写与字母游戏，且它常于新闻群组对话中被提及。
 */
char rot13_char(char c) {
    if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
        return c + 13;
    else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
        return c - 13;
    else
        return c;
}