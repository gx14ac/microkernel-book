#include <libs/common/print.h>
#include <libs/common/string.h>
#include <libs/common/vprintf.h>
#include <libs/user/ipc.h>
#include <libs/user/malloc.h>

static task_t tcpip_server;

#define INDEX_HTML                                                             \
    "<!DOCTYPE html>"                                                          \
    "<head>"                                                                   \
    "<html>"                                                                   \
    "   <meta charset=\"utf-8\">"                                              \
    "</head>"                                                                  \
    "<body>"                                                                   \
    "<h1>Hello from WASM OS!</h1>"                                             \
    "</body>"                                                                  \
    "</html>\n"

static void process(int sock, uint8_t *data, size_t len) {
    static char buf[] =
        "HTTP/1.1 200 OK\r\nConnection: close\rContent-Length: 109\r\n\r\n" INDEX_HTML;

    struct message m;
    m.type = TCPIP_WRITE_MSG;
    m.tcpip_write.sock = sock;
    memcpy(m.tcpip_write.data, buf, sizeof(buf));
    m.tcpip_write.data_len = strlen(buf);
    ASSERT_OK(ipc_call(tcpip_server, &m));
}

void main(void) {
    tcpip_server = ipc_lookup("tcpip");

    struct message m;
}