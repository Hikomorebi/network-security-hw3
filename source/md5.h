#ifndef MD5_H
#define MD5_H
#include "common.h"
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z))) // G 函数
#define H(x, y, z) ((x) ^ (y) ^ (z))            // H 函数
#define I(x, y, z) ((y) ^ ((x) | (~z)))         // I 函数
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))    // 32 位双字的循环左移操作
#define FF(a, b, c, d, x, s, ac) {(a) += F((b), (c), (d)) + (x) + ac;(a) = ROTATE_LEFT((a), (s));(a) += (b);}
#define GG(a, b, c, d, x, s, ac) {(a) += G((b), (c), (d)) + (x) + ac;(a) = ROTATE_LEFT((a), (s));(a) += (b);}
#define HH(a, b, c, d, x, s, ac) {(a) += H((b), (c), (d)) + (x) + ac;(a) = ROTATE_LEFT((a), (s));(a) += (b);}
#define II(a, b, c, d, x, s, ac) {(a) += I((b), (c), (d)) + (x) + ac;(a) = ROTATE_LEFT((a), (s));(a) += (b);}

#define T(i) 4294967296 * abs(sin(i))
class MD5 {
public:
    void Update(const string &str);             //对给定长度的字符串进行 MD5 运算
    void Update(ifstream &in);                  //对给定长度的输入流进行 MD5 运算
    string Tostring();                          //将 MD5 摘要以字符串形式输出

private:
    void Init();                               //初始化变量
    void Update(vector<uint8_t> input);
    void Transform(const vector<uint8_t> block);
    vector<uint32_t> Decode(const vector<uint8_t>input);
    string from10To16(uint32_t decimal);
    vector<uint8_t> fromInt64ToInt8Vec(uint64_t num);

private:
    uint32_t state[4]; // 用于表示4个初始向量
};
#endif