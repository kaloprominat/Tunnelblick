//
//  base64.h
//  openvpn-mcd
//
//  Created by Pavel Kondratiev on 07/04/2017.
//  Copyright © 2017 Pavel Kondratiev. All rights reserved.
//

#ifndef _BASE64_H_
#define _BASE64_H_

int base64_encode(const void *data, int size, char **str);

int base64_decode(const char *str, void *data, int size);

#endif
