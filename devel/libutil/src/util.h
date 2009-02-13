#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <hash.h>

#define UTIL_PATH_SEP_STRING "/"   /* A \0 terminated separator used when we want a (char *) instance.                   */
#define UTIL_PATH_SEP_CHAR   '/'   /* A simple character used when we want an actual char instance (i.e. not a pointer). */

#define UTIL_NEWLINE_STRING "\n"


#ifdef __cplusplus
extern"C" {
#endif


typedef enum {left_pad  = 0,
	      right_pad = 1,
	      center    = 2} string_alignement_type;

void         util_bitmask_on(int *  , int );
time_t       util_make_datetime(int , int , int , int , int , int );
void         util_fprintf_datetime(time_t  , FILE * );
void         util_fprintf_date(time_t  , FILE * );
time_t       util_make_date(int , int , int);
void         util_inplace_forward_days(time_t *  , double);
double       util_difftime(time_t  , time_t  , int *  , int *  , int *  , int *);

bool         util_char_in(char c, int , const char *);
char       * util_alloc_sprintf(const char *  , ...);
char       * util_realloc_sprintf(char * , const char *  , ...);
void         util_fprintf_int(int , int , FILE * );
void         util_fprintf_string(const char *  , int , string_alignement_type ,  FILE * );
void         util_fprintf_double(double , int , int , char , FILE *);
bool         util_fscanf_date(FILE * , time_t *);
bool         util_sscanf_date(const char * , time_t *);
char       * util_blocking_alloc_stdin_line(unsigned long );
char       * util_alloc_stdin_line();
char       * util_realloc_stdin_line(char * );
char       * util_alloc_PATH_executable(const char * );
bool         util_is_executable(const char * );
bool 	     util_file_exists(const char *);
int          util_get_path_length(const char * );
bool 	     util_path_exists(const char *);
bool         util_is_abs_path(const char * );
bool 	     util_fmt_bit8   (const char *);
bool         util_fmt_bit8_stream(FILE * );
void 	     util_make_path  (const char *);
char       * util_newest_file(const char *, const char *);
double       util_file_difftime(const char * , const char *);
bool         util_file_update_required(const char *, const char *);
int          util_file_size(const char *);
void         util_unlink_path(const char *);
void         util_unlink_path_TESTING(const char *);
void         util_unlink_existing(const char *filename);
void         util_strupr(char *);
char       * util_alloc_strupr_copy(const char * );
void         util_string_tr(char * , char , char);
void 	     util_copy_stream(FILE *, FILE *, int , void * );
void 	     util_copy_file(const char * , const char * );
char       * util_alloc_cwd(void);
char       * util_alloc_realpath(const char * );

int    	     util_forward_line(FILE * , bool * );
void   	     util_rewind_line(FILE *);
int    	     util_count_content_file_lines(FILE * );
int    	     util_count_file_lines(FILE * );
FILE       * util_fopen_lockf(const char * , const char * );
FILE   	   * util_fopen(const char *  , const char *);
void   	     util_alloc_file_components(const char * , char ** , char **, char **);
  //char   	   * util_realloc_full_path(char * , const char *, const char *);
char   	   * util_alloc_tmp_file(const char * , const char * , bool );
char   	   * util_fscanf_alloc_line(FILE *, bool *);
char   	   * util_fscanf_realloc_line(FILE *, bool * , char *);
char   	   * util_fscanf_alloc_token(FILE * );
void   	     util_fskip_token(FILE * );
void         util_fskip_space(FILE *  ,  bool *);
void   	     util_fskip_chars(FILE * , const char * , bool *);
void   	     util_fskip_cchars(FILE * , const char * , bool *);
bool   	     util_fscanf_int(FILE * , int * );
bool   	     util_sscanf_bool(const char * , bool *);
bool   	     util_sscanf_int(const char * , int * );
const char * util_parse_int(const char * , int * , bool *);
const char * util_skip_sep(const char * , const char * , bool *);
int      util_scanf_int_with_limits(const char * , int  , int  , int );
void     util_printf_prompt(const char * , int , char , const char *);
int      util_scanf_int(const char * , int);
char   * util_scanf_alloc_string(const char * );
bool     util_sscanf_double(const char * , double * );
  //char   * util_alloc_full_path(const char *, const char *);
char   * util_alloc_filename(const char * , const char *  , const char * );
char   * util_realloc_filename(char *  , const char *  , const char *  , const char * );
char   * util_alloc_strip_copy(const char *);
char   * util_realloc_strip_copy(char *);
void     util_set_strip_copy(char * , const char *);
char   * util_alloc_string_sum(const char **  , int);
char   * util_strcat_realloc(char *, const char * );
char   * util_alloc_string_copy(const char *);
char  ** util_stringlist_append_copy(char **  , int , const char * );
char  ** util_stringlist_append_ref(char **  , int , const char * );
char  ** util_alloc_stringlist_copy(const char **, int );
void     util_split_string(const char *, const char *, int *, char ***);
char   * util_alloc_joined_string(const char **  , int , const char * );
char   * util_alloc_multiline_string(const char ** , int );
char   * util_string_replace_alloc(const char *, const char *, const char *);
char   * util_string_replacen_alloc(const char *, int , const char ** , const char **);
int      util_string_replace_inplace(char ** , int * , const char *  , const char * );
char   * util_string_strip_chars_alloc(const char *, const char * );
char   * util_realloc_string_copy(char * , const char *);
char   * util_realloc_substring_copy(char * , const char *, int );
char   * util_alloc_string_sum2(const char *, const char *);
char   * util_realloc_dequoted_string(char *);
void   * util_safe_free(void *);
void     util_free_stringlist(char **, int );
char  ** util_alloc_stringlist(int , int );
char   * util_alloc_substring_copy(const char *, int );
bool     util_is_directory(const char * );
bool     util_is_file(const char * );
bool     util_is_link(const char * );
void     util_make_slink(const char *, const char * );
void 	 util_set_datetime_values(time_t , int * , int * , int * , int * , int *  , int *);
void 	 util_set_date_values(time_t , int * , int * , int * );


void     util_fread_dev_random(int , char * );
void     util_fread_dev_urandom(int , char * );
bool     util_intptr_2bool(const int *);
int      util_C2f90_bool(bool );
void     util_memcpy_string_C2f90(const char *  , char *  , int );
void     util_pad_f90string(char * , int , int );
char *   util_alloc_cstring(const char *, const int *);
char *   util_alloc_string_copy(const char *);
void     util_enkf_unlink_ensfiles(const char *, const char *, int , bool );

void    util_exit(const char * fmt , ...);
void    util_abort(const char * fmt , ...);
void    util_abort_signal(int );
void    util_abort_append_version_info(const char * );
void *  util_realloc(void *  , size_t  , const char * );
void *  util_malloc(size_t , const char * );
void *  util_alloc_copy(const void * , size_t , const char * );
void 	util_double_to_float(float  * , const double * , int );
void 	util_float_to_double(double * , const float  * , int );

int 	util_get_month_nr(const char * );
int 	util_check_month(const char * );

char *  util_fread_alloc_file_content(const char * , const char * , int *);
void    util_fwrite_string(const char * , FILE *);
char *  util_fread_realloc_string(char *  , FILE *);
char *  util_fread_alloc_string(FILE *);
void    util_fskip_string(FILE *stream);
void    util_endian_flip_vector(void *, int , int );
bool    util_proc_alive(pid_t pid);
int     util_proc_mem_free(void);


void     util_apply_int_limits(int * , int , int );
void     util_apply_float_limits(float * , float , float );
void     util_apply_double_limits(double * , double , double );
double   util_double_vector_mean(int , const double * );
double   util_double_vector_stddev(int , const double * );
void     util_double_vector_max_min(int  , const double *, double * , double *);
void     util_update_double_max_min(double , double * , double * );
void     util_update_float_max_min(float , float * , float * );
void     util_update_int_max_min(int , int * , int * );
float  	 util_float_max (float   , float );
int    	 util_int_max   (int     , int);
double 	 util_double_max(double  , double );
float  	 util_float_min (float   , float );
int    	 util_int_min   (int     , int);
double 	 util_double_min(double  , double );
void     util_fskip_lines(FILE * , int);
bool     util_same_file(const char *  , const char * );
void     util_read_path(const char * , int , bool , char *  );
void     util_read_filename(const char * , int , bool , char * );
void     util_read_string(const char *  , int  , char * );
void     util_fread (void *, size_t , size_t , FILE * , const char * );
void     util_fwrite(const void *, size_t , size_t , FILE * , const char * );
int      util_fread_int(FILE * );
long     util_fread_long(FILE * );
bool     util_fread_bool(FILE * );
void 	 util_fwrite_int   (int    , FILE * );
void 	 util_fwrite_long  (long    , FILE * );
void 	 util_fwrite_bool  (bool    , FILE * );
void 	 util_fwrite_double(double , FILE * );
void 	 util_fwrite_int_vector   (const int     * , int , FILE * , const char * );
void 	 util_fwrite_double_vector(const double  * , int , FILE * , const char * );
void     util_fread_char_vector(char * , int , FILE * , const char * );

void 	 util_compress_buffer(const void * , int , void * , unsigned long * );
void 	 util_fread_compressed(void * , FILE * );
void   * util_fread_alloc_compressed(FILE * );
void 	 util_fwrite_compressed(const void * , int , FILE * );
void     util_block_growing_file(const char * );
void     util_block_growing_directory(const char * );
pid_t    util_vfork_exec(const char *  , int , const char ** , bool , const char * , const char *  , const char * , const char *  , const char * );
char   * util_alloc_realpath(const char * );
bool     util_try_lockf(const char *  , mode_t  , int * );
bool     util_sscanf_bytesize(const char * , size_t *);
void     util_sscanf_active_range(const char *  , int , bool * );
int    * util_sscanf_alloc_active_list(const char *  , int * );
int      util_get_current_linenr(FILE * stream);
void     util_update_path_var(const char * , const char * , bool );

#define UTIL_FWRITE_SCALAR(s,stream) { if (fwrite(&s , sizeof s , 1 , stream) != 1) util_abort("%s: write failed: %s\n",__func__ , strerror(errno)); }
#define UTIL_FREAD_SCALAR(s,stream)  { if (fread(&s , sizeof s , 1 , stream) != 1) util_abort("%s: read failed: %s\n",__func__ , strerror(errno)); }

#define UTIL_FWRITE_VECTOR(s,n,stream) { if (fwrite(s , sizeof s , (n) , stream) != (n)) util_abort("%s: write failed: %s \n",__func__ , strerror(errno)); }
#define UTIL_FREAD_VECTOR(s,n,stream)  { if (fread(s , sizeof s , (n) , stream) != (n)) util_abort("%s: read failed: %s \n",__func__ , strerror(errno)); }

#ifdef __cplusplus
}
#endif
#endif
