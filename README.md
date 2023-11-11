# HT, simple data transfer protocol, written in C++

### Uses socket connection, AES-256 encryption and MD-5 sum calculation.

Usage:
1. Download header file and include it into your project using `#include "ht.h"` directive.
2. Initialize empty struct using `HTSocket sock;`
3. Initialize connection data with `sock.InitializeConnection(ipaddr, port);`
4. Try connection: `bool sock.TryConnect();`
     