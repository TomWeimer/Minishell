#include <readline/history.h>

int main()
{
	typedef void * histdata_t;

	HIST_ENTRY ** the_history_list; 

	typedef void * histdata_t;

       typedef struct _hist_entry {
         char *line;
         char *timestamp;
         histdata_t data;
       } HIST_ENTRY;

	   
	   typedef struct _hist_state {
 		 HIST_ENTRY **entries; /* Pointer to the entries themselves. */
  		int offset;           /* The location pointer within this array. */
  		int length;           /* Number of elements within this array. */
  		int size;             /* Number of slots allocated to this array. */
  		int flags;
		} HISTORY_STATE;


	using_history();

}
