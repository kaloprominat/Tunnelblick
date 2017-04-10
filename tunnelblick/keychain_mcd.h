//
//  keychain_mcd.h
//  Tunnelblick
//
//  Created by Pavel Kondratiev on 07/04/2017.
//
//

#ifndef keychain_mcd_h
#define keychain_mcd_h

#include <stdio.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <err.h>
#include <netdb.h>

#include <Security/Security.h>
#include <CoreServices/CoreServices.h>

#include "cert_data.h"
#include "crypto_osx.h"
#include "base64.h"

typedef enum
{
    templateSearchResultSuccess,
    templateSearchResultNotFound,
    templateSearchResultBadTemplate
} keychainMcdTemplateSearchResult;

typedef enum {
    getCertificateResultSuccess,
    getCertificateResultNull,
    getCertificateResultError
} keychainMcdGetCertificateResult;

typedef enum {
    rsasignResultSuccess,
    rsasignResultError,
    rsasignResultB64Error
} keychainMcdRsasignResult;


SecIdentityRef template_to_identity(const char *template, keychainMcdTemplateSearchResult *result);
char * get_certificate(SecIdentityRef identity, keychainMcdGetCertificateResult *result);
char * rsasign(SecIdentityRef identity, const char *input, keychainMcdRsasignResult *result);

#endif /* keychain_mcd_h */
