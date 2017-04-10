//
//  crypto_osx.c
//  openvpn-mcd
//
//  Created by Pavel Kondratiev on 07/04/2017.
//  Copyright © 2017 Pavel Kondratiev. All rights reserved.
//

#include <CommonCrypto/CommonDigest.h>
#include <Security/SecKey.h>
#include <Security/Security.h>

#include "crypto_osx.h"
#include <err.h>

void printErrorMsg(const char *func, CFErrorRef error) {
    CFStringRef desc = CFErrorCopyDescription(error);
    warnx("%s failed: %s", func, CFStringGetCStringPtr(desc, kCFStringEncodingUTF8));
    CFRelease(desc);
}

void printErrorStatusMsg(const char *func, OSStatus status) {
    CFStringRef error;
    error = SecCopyErrorMessageString(status, NULL);
    if (error)
    {
        warnx("%s failed: %s", func, CFStringGetCStringPtr(error, kCFStringEncodingUTF8));
        CFRelease(error);
    }
    else
    {
        warnx("%s failed: %X", func, (int)status);
    }
}

void signData(SecIdentityRef identity, const uint8_t *from, int flen, uint8_t *to, size_t *tlen) {
    SecKeyRef privateKey = NULL;
    OSStatus status;
    
    status = SecIdentityCopyPrivateKey(identity,  &privateKey);
    if (status != noErr)
    {
        printErrorStatusMsg("signData: SecIdentityCopyPrivateKey", status);
        *tlen = 0;
        return;
    }
    
    status = SecKeyRawSign(privateKey, kSecPaddingPKCS1, from, flen, to, tlen);
    CFRelease(privateKey);
    if (status != noErr)
    {
        printErrorStatusMsg("signData: SecKeyRawSign", status);
        *tlen = 0;
        return;
    }
}

