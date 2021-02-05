#include "include/CEDCoder.h"
#include "include/SM4.h"
#include "include/SM3.h"
//#include "include/SM2.h"

CEDCoder::CEDCoder()
{

}

void CEDCoder::DEnCodeAPI(WORKMODE mode,EDCodeLevel Level,QString& strSInfo, QString& strDInfo)
{
    if (mode == WORKMODE::kDeCode)
    {
        DeCodeAPI(Level, strSInfo, strDInfo);
    }
    else if (mode == WORKMODE::kEnCode)
    {
        EnCodeAPI(Level, strSInfo, strDInfo);
    }
}

void CEDCoder::EnCodeAPI(EDCodeLevel Level, QString& strSInfo, QString& strDInfo)
{
    switch (Level)
    {
    case EDCodeLevel::kSSSLevel:
    case EDCodeLevel::kSSLevel:
    case EDCodeLevel::kSLevel:
    case EDCodeLevel::kALevel:
        AlgorithmsSM4 (strSInfo, strDInfo, WORKMODE::kEnCode);
        break;
    case EDCodeLevel::kBLevel:
        AlgorithmsSM3 (strSInfo, strDInfo, WORKMODE::kEnCode);
        break;
    case EDCodeLevel::kCLevel:
        AlgorithmsSM2 (strSInfo, strDInfo, WORKMODE::kEnCode);
        break;
    case EDCodeLevel::kDLevel:
        AlgorithmsBase64(strSInfo, strDInfo, WORKMODE::kEnCode);
        break;
    default:
        break;
    }
}

void CEDCoder::DeCodeAPI(EDCodeLevel Level, QString& strSInfo, QString& strDInfo)
{
    switch (Level)
    {
    case EDCodeLevel::kSSSLevel:
    case EDCodeLevel::kSSLevel:
    case EDCodeLevel::kSLevel:
    case EDCodeLevel::kALevel:
        AlgorithmsSM4 (strSInfo, strDInfo, WORKMODE::kDeCode);
        break;
    case EDCodeLevel::kBLevel:
        AlgorithmsSM3 (strSInfo, strDInfo, WORKMODE::kDeCode);
        break;
    case EDCodeLevel::kCLevel:
        AlgorithmsSM2 (strSInfo, strDInfo, WORKMODE::kDeCode);
        break;
    case EDCodeLevel::kDLevel:
        AlgorithmsBase64(strSInfo, strDInfo, WORKMODE::kDeCode);
        break;
    default:
        break;
    }
}

void CEDCoder::AlgorithmsBase64(QString& strSInfo, QString& strDInfo, WORKMODE eMode)
{
    if(eMode == WORKMODE::kDeCode)
    {
        QByteArray MessageByte = QByteArray::fromStdString(strSInfo.toStdString());
        strDInfo = MessageByte.toBase64();
    } else if(eMode == WORKMODE::kEnCode)
    {
        QByteArray MessageByte = QByteArray::fromStdString(strSInfo.toStdString());
        strDInfo = QByteArray::fromBase64 (MessageByte);
    }
}

void CEDCoder::AlgorithmsSM2(QString& /*strSInfo*/, QString& /*strDInfo*/, WORKMODE /*eMode*/)
{

}

void CEDCoder::AlgorithmsSM3(QString& strSInfo, QString& strDInfo, WORKMODE eMode)
{
    if(eMode == WORKMODE::kDeCode)
    {
        sm3_context ctx;
        char* pSourceData = const_cast<char*>(strSInfo.toStdString ().c_str ());
        char* pDestData = const_cast<char*>(strDInfo.toStdString ().c_str ());
        sm3((unsigned char*)pSourceData, strSInfo.size (), (unsigned char*)pDestData);

        sm3_starts( &ctx );
        for(int i=0; i < 16; i++)
            sm3_update( &ctx, (unsigned char*)pSourceData, strSInfo.size());
        sm3_finish( &ctx, (unsigned char*)pDestData );
        memset( &ctx, 0, sizeof( sm3_context));
    } else if(eMode == WORKMODE::kEnCode)
    {

    }
}

void CEDCoder::AlgorithmsSM4(QString& strSInfo, QString& strDInfo, WORKMODE eMode)
{
    unsigned char SM4Key[16] = {0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef,0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10};

    sm4_context ctx;

    //encrypt standard testing vector
    sm4_setkey_enc(&ctx,SM4Key);
    char* pSourceData = const_cast<char*>(strSInfo.toStdString ().c_str ());
    char* pDestData = const_cast<char*>(strDInfo.toStdString ().c_str ());
    if(eMode == WORKMODE::kDeCode)
    {
        sm4_crypt_ecb(&ctx,1,strSInfo.toStdString ().size (),(unsigned char*)pSourceData,(unsigned char*)pDestData);
    }
    else if(eMode == WORKMODE::kEnCode)
    {
        sm4_crypt_ecb(&ctx,0,strSInfo.toStdString ().size (),(unsigned char*)pSourceData,(unsigned char*)pDestData);
    }
}

CEDCoder::~CEDCoder()
{

}
