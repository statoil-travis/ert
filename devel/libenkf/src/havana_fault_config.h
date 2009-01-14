#ifndef __HAVANA_FAULT_CONFIGH__
#define __HAVANA_FAULT_CONFIGH__

#include <gen_kw_config.h>
#include <enkf_util.h>
#include <enkf_macros.h>


typedef struct havana_fault_config_struct  havana_fault_config_type;
typedef struct fault_group_struct          fault_group_type;



void                         havana_fault_config_run_havana(const havana_fault_config_type *  , scalar_type *  , const char * );
const char                 * havana_fault_config_get_template_ref(const havana_fault_config_type * );
havana_fault_config_type   * havana_fault_config_fscanf_alloc(const char *);
void                         havana_fault_config_free(havana_fault_config_type *);
void               	     havana_fault_config_transform(const havana_fault_config_type * , const double * , double *);
void               	     havana_fault_config_truncate(const havana_fault_config_type * , scalar_type * );
int                	     havana_fault_config_get_data_size(const havana_fault_config_type * );
const char         	   * havana_fault_config_get_name(const havana_fault_config_type * , int );
char               	  ** havana_fault_config_get_name_list(const havana_fault_config_type *);
const char         	   * havana_fault_config_get_executable_ref(const havana_fault_config_type * );
gen_kw_config_type         * havana_fault_config_get_gen_kw_config(const havana_fault_config_type * );

VOID_FREE_HEADER(havana_fault_config);
SAFE_CAST_HEADER(havana_fault_config);

#endif
