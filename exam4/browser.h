#include <gmodule.h>


typedef struct {

  // struct vtbl *vptr;
    int size;
    int counter;
    GList * list;
    
   
} Browser;


//struct vtbl 
//{
 //   void (*visit) ( Browser *, GString *);
 //   void (*back)(Browser *);
 //  void (*history) (Browser *);

//};

extern struct vtbl Browser_vtable;




//void visit_website(Browser *, GString *);
//void back_website (Browser *);
//void history_print (Browser *);
