//
//  common_osx.h
//  openvpn-mcd
//
//  Created by Pavel Kondratiev on 07/04/2017.
//  Copyright © 2017 Pavel Kondratiev. All rights reserved.
//

#ifndef common_osx_h
#define common_osx_h

#include <stdio.h>

#include <CoreFoundation/CoreFoundation.h>

void printCFString(CFStringRef str);

char *cfstringToCstr(CFStringRef str);

CFStringRef createHexString(unsigned char *pData, int length);

void printHex(unsigned char *pData, int length);

#endif /* common_osx_h */
