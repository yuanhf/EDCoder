#ifndef CEDCODER_H
#define CEDCODER_H
#include "EDCoderCommon.h"
#include <QString>

class CEDCoder
{
public:
    CEDCoder();
    ~CEDCoder();

public:
    void DEnCodeAPI(WORKMODE mode, EDCodeLevel Level,QString& strSInfo, QString& strDInfo);

private:
    void DeCodeAPI(EDCodeLevel, QString&, QString&);
    void EnCodeAPI(EDCodeLevel, QString&, QString&);

    void AlgorithmsBase64(QString&, QString&, WORKMODE);
    void AlgorithmsSM4(QString&, QString&, WORKMODE);
    void AlgorithmsSM2(QString&, QString&, WORKMODE);
    void AlgorithmsSM3(QString&, QString&, WORKMODE);
private:

};

#endif // CEDCODER_H
