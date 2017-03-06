#include "httpd.h"
#include "http_core.h"
#include "http_protocol.h"
#include "http_request.h"

// Prototypes
static void register_hooks(apr_pool_t * pool);
static int example_handler(request_rec * r);

// Define module as entity
module AP_MODULE_DECLARE_DATA example_module =
{
  STANDARD20_MODULE_STUFF,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  register_hooks
};

static void register_hooks(apr_pool_t * pool)
{
  ap_hook_handler(example_handler, NULL, NULL, APR_HOOK_LAST);
}

static int example_handler(request_rec * r)
{
  if (!r->handler || strcmp(r->handler, "example_module"))
    return (DECLINED);
  ap_set_content_type(r, "text/html");
  ap_rprintf(r, "Hello, world!<br/>");
  return OK;
}
