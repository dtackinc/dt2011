/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
  ! Copyright (C) 1998 Dtack Inc. All Rights Reserved
  ! To use this file, you must have signed a license agreement with Dtack Inc.
  ! Under no circumstances may you redistribute this file.
  ! This software is provided AS IS with no warranty expressed or implied.
  ! Dtack Inc. accepts no liability for use or misuse of this file.
  ! http://www.dtack.com  dtack@dtack.com  telephone +360.417.6700
  ! Dtack Inc, P.O. Box 3061, Port Angeles, WA USA 98362
  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */




/*..........................................................................
| NAME
| Introduction - intro
| 
| ERRORS
| As yet undocumented.
| 
| END
 *..........................................................................*/

#include <tabdrone.h>
DT_RCSID("app/tabdrone $RCSfile: start.c,v $ $Revision: 1.8 $");
#include <dtack/list.h>
#include <dtack/dg.h>

/*..........................................................................
 *..........................................................................*/

dt_rc_e
DTCONFIG_API1
tabdrone_start(							/* hit the start url					*/
  tabdrone_t *tabdrone)					/* application state 				*/
{
  DT_F("tabdrone_start");
  dt_ctl_t *ctl = tabdrone->ctl;
  dtparam_t *param = tabdrone->param;
  char *request = NULL;
  int request_length;
  char *url = NULL;
  char *filepart;
  char *startstring = "/start?";		/* default url file part 			*/
  dtdg_client_t _dgclient;
  dtdg_client_t *dgclient = &_dgclient;
  int client_initialized = 0;
  int is_available;
  long mask = DT_DBG_MASK_REPLY;
  int i;
  dt_rc_e rc = DT_RC_GOOD;

  if (param->precision == NULL ||		/* no start url specified? 			*/
	  strlen(param->precision) == 0)
	goto cleanup;

  request_length = 256 +				/* extra space for HTTP stuff 		*/
    strlen(param->precision);

  DT_C(dtos_malloc2,(ctl,				/* space for request string 		*/
    (void **)&request, 
    request_length, 
    F, "request"));

  DT_C(dtos_strdup,(ctl,				/* a place to edit 					*/
    param->precision, &url));
  filepart = strchr(url, '/');			/* search for slash					*/
  if (filepart == NULL)					/* no slash? 						*/
	filepart = startstring;				/* default CGI string 				*/

  DT_C(dtstr_printf,(ctl,				/* prepend http GET 				*/
    request, request_length,
    "GET %ssessid=%s HTTP/1.0", 
    filepart,
    param->ident));

  if (filepart != startstring)			/* need to split url? 				*/
    *filepart = '\0';

  DT_C(dtdg_client_init,(ctl, dgclient,	/* send request to server 			*/
    url, request, 10000)); 
  
  DT_C(dtdg_client_wait_header,(ctl,	/* wait for header to appear		*/
    dgclient, 10000, &is_available));
  client_initialized = 1;
  if (!is_available)
  {
	rc = dt_err(ctl, F,
      "server %s not responding", url);
	goto cleanup;
  }
  
  DT_C(dtdg_header_get,(ctl,			/* pick off the header 				*/
    dgclient, -1));
  
  DT_C(dtdg_client_get_response,(ctl,	/* pick off the response			*/
    dgclient, param->dt,
    100, NULL));

  dt_dbg(ctl, F, DT_DBG_MASK_USR1,
    "%s starting",
    param->ident);

cleanup:
  if (url != NULL)
    DT_I(dtos_free2,(ctl, url,
      F, "url"));
  if (request != NULL)
    DT_I(dtos_free2,(ctl, request,
      F, "request"));
  if (client_initialized)
    DT_I(dtdg_client_uninit ,(ctl,
      dgclient));
  return rc;
}





/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
  ! Copyright (C) 1998 Dtack Inc. All Rights Reserved
  ! To use this file, you must have signed a license agreement with Dtack Inc.
  ! Under no circumstances may you redistribute this file.
  ! This software is provided AS IS with no warranty expressed or implied.
  ! Dtack Inc. accepts no liability for use or misuse of this file.
  ! http://www.dtack.com  dtack@dtack.com  telephone +360.417.6700
  ! Dtack Inc, P.O. Box 3061, Port Angeles, WA USA 98362
  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
