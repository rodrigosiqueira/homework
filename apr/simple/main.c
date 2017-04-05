#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include <apr_general.h>
#include <apr_pools.h>

#define MEM_MALLOC 1024

int main(int argc, char ** argv)
{
  apr_status_t rv;
  apr_pool_t * memoryPool = 0;

  char * buffer1 = 0;
  char * buffer2 = 0;

  rv = apr_initialize();
  if (rv != APR_SUCCESS)
  {
    assert(0);
    return -1;
  }

  apr_pool_create(&memoryPool, NULL);

  buffer1 = apr_palloc(memoryPool, MEM_MALLOC);
  buffer2 = apr_palloc(memoryPool, MEM_MALLOC);

  apr_pool_destroy(memoryPool);

  apr_terminate();

  return 0;
}
