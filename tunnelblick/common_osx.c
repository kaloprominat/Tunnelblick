//
//  common_osx.c
//  openvpn-mcd
//
//  Created by Pavel Kondratiev on 07/04/2017.
//  Copyright © 2017 Pavel Kondratiev. All rights reserved.
//

#include "common_osx.h"
#include <err.h>

void printCFString(CFStringRef str) {
    CFIndex bufferLength = CFStringGetLength(str) + 1;
    char *pBuffer = (char *)malloc(sizeof(char) * bufferLength);
    CFStringGetCString(str, pBuffer, bufferLength, kCFStringEncodingUTF8);
    warnx("%s\n", pBuffer);
    free(pBuffer);
}

char * cfstringToCstr(CFStringRef str) {
    CFIndex bufferLength = CFStringGetLength(str) + 1;
    char *pBuffer = (char *)malloc(sizeof(char) * bufferLength);
    CFStringGetCString(str, pBuffer, bufferLength, kCFStringEncodingUTF8);
    return pBuffer;
}

void appendHexChar(CFMutableStringRef str, unsigned char halfByte) {
    if (halfByte < 10)
    {
        CFStringAppendFormat(str, NULL, CFSTR("%d"), halfByte);
    }
    else
    {
        char tmp[2] = {'A'+halfByte-10, 0};
        CFStringAppendCString(str, tmp, kCFStringEncodingUTF8);
    }
}

CFStringRef createHexString(unsigned char *pData, int length) {
    unsigned char byte, low, high;
    int i;
    CFMutableStringRef str = CFStringCreateMutable(NULL, 0);
    
    for (i = 0; i < length; i++)
    {
        byte = pData[i];
        low = byte & 0x0F;
        high = (byte >> 4);
        
        appendHexChar(str, high);
        appendHexChar(str, low);
        
        if (i != (length - 1))
        {
            CFStringAppendCString(str, " ", kCFStringEncodingUTF8);
        }
    }
    
    return str;
}

void printHex(unsigned char *pData, int length) {
    CFStringRef hexStr = createHexString(pData, length);
    printCFString(hexStr);
    CFRelease(hexStr);
}
