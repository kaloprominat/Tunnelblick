//
//  crypto_osx.h
//  openvpn-mcd
//
//  Created by Pavel Kondratiev on 07/04/2017.
//  Copyright © 2017 Pavel Kondratiev. All rights reserved.
//

#ifndef crypto_osx_h
#define crypto_osx_h

#include <stdio.h>


#include <CoreFoundation/CoreFoundation.h>
#include <Security/Security.h>

extern OSStatus SecKeyRawSign(
                              SecKeyRef key,
                              SecPadding padding,
                              const uint8_t *dataToSign,
                              size_t dataToSignLen,
                              uint8_t *sig,
                              size_t *sigLen
                              );

void signData(SecIdentityRef identity, const uint8_t *from, int flen, uint8_t *to, size_t *tlen);

void printErrorMsg(const char *func, CFErrorRef error);

#endif /* crypto_osx_h */
