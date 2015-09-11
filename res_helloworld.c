#include "asterisk.h"
ASTERISK_FILE_VERSION(__FILE__, "$Revision: $")
#include "asterisk/module.h"
#include "asterisk/logger.h"
#include "asterisk/cdr.h"

static int cdr_helloworld(struct ast_cdr *cdr )
{
        ast_log(LOG_NOTICE, "We got a CDR for channel '%s'.  "
        "Source: '%s', Dest: '%s', Duration: %ld\n",
        cdr->channel, cdr->src, cdr->dst, cdr->duration);

    return 0;
}

static int load_module(void)
{
        ast_log(LOG_NOTICE, "Hello World!");
        ast_cdr_register("HelloWorld", "Hello World CDR Handler", cdr_helloworld);
        return AST_MODULE_LOAD_SUCCESS;
}


static int unload_module(void)
{
        ast_log(LOG_NOTICE, "Goodbye World!\n");
        ast_cdr_unregister("HelloWorld");

        return 0;
}

AST_MODULE_INFO_STANDARD(ASTERISK_GPL_KEY, "Hello World Example Program");
