//
//  cert_data.h
//  openvpn-mcd
//
//  Created by Pavel Kondratiev on 07/04/2017.
//  Copyright © 2017 Pavel Kondratiev. All rights reserved.
//

#ifndef cert_data_h
#define cert_data_h

#include <CoreFoundation/CoreFoundation.h>
#include <Security/Security.h>

typedef struct _CertData
{
    CFArrayRef subject;
    CFArrayRef issuer;
    CFStringRef serial;
    CFStringRef md5, sha1;
} CertData, *CertDataRef;

CertDataRef createCertDataFromCertificate(SecCertificateRef certificate);

CertDataRef createCertDataFromString(const char *description);

void destroyCertData(CertDataRef pCertData);

bool certDataMatchesTemplate(CertDataRef pCertData, CertDataRef pTemplate);

void printCertData(CertDataRef pCertData);

SecIdentityRef findIdentity(CertDataRef pCertDataTemplate);



#endif /* cert_data_h */
