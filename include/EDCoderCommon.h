#ifndef EDCODERCOMMON
#define EDCODERCOMMON

enum class WORKMODE
{
    kEnCode = 0,
    kDeCode
};

enum class PasswordMode
{
    kNumLetterSimbol,
    kLetterSimbol,
    kNumLetter,
    kNumSimbol,
    kLetter,
    kNum
};

enum class PasswordCount
{
    kAutoNum = -1,
    k6Num = 6,
    k8Num = 8,
    k10Num = 10,
    k12Num = 12,
    k16Num = 16,
    k18Num = 18
};

enum class EDCodeLevel
{
    kDLevel,    //Base64
    kCLevel,    //MD5
    kBLevel,
    kALevel,
    kSLevel,
    kSSLevel,
    kSSSLevel,
};

enum class SingedFlag
{
    kUnSigned,
    kSigned
};

#endif // EDCODERCOMMON

