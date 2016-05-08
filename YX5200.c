#include "stm8s_conf.h"
#include "YX5200.h"
 
 
void YX5200_SendCmd(unsigned char cmd, unsigned char feedback, unsigned char para1, unsigned char para2)
{
    unsigned char checksuml,checksumh;
    int checksum;
    
    checksum = 0;
    checksum = 0xFF + 0x06 + cmd + feedback + para1 + para2;
    checksum = 0 - checksum;
    
    checksuml = checksum & 0xff;
    checksumh = checksum >> 8;
    
    //PutCh(0x7E);
    UART3_SendData8(0x7E);
    while ((UART3->SR & UART3_SR_TXE ) != UART3_SR_TXE );
    //PutCh(0xFF);
    UART3_SendData8(0xFF);
    while ((UART3->SR & UART3_SR_TXE ) != UART3_SR_TXE );
    //PutCh(0x06);
    UART3_SendData8(0x06);
    while ((UART3->SR & UART3_SR_TXE ) != UART3_SR_TXE );
    //PutCh(cmd);
    UART3_SendData8(cmd);
    while ((UART3->SR & UART3_SR_TXE ) != UART3_SR_TXE );
    //PutCh(feedback);
    UART3_SendData8(feedback);
    while ((UART3->SR & UART3_SR_TXE ) != UART3_SR_TXE );
    //PutCh(para1);
    UART3_SendData8(para1);
    while ((UART3->SR & UART3_SR_TXE ) != UART3_SR_TXE );
    //PutCh(para2);
    UART3_SendData8(para2);
    while ((UART3->SR & UART3_SR_TXE ) != UART3_SR_TXE );
    //PutCh(checksumh);
    UART3_SendData8(checksumh);
    while ((UART3->SR & UART3_SR_TXE ) != UART3_SR_TXE );
    //PutCh(checksuml);
    UART3_SendData8(checksuml);
    while ((UART3->SR & UART3_SR_TXE ) != UART3_SR_TXE );
    //PutCh(0xEF);
    UART3_SendData8(0xEF);
    while ((UART3->SR & UART3_SR_TXE ) != UART3_SR_TXE );
}