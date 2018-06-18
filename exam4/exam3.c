#define HISTORY_SIZE 5
#include "browser.h"
#include <string.h>
#include <gmodule.h>
#include <stdio.h>
#include <glib.h>
#include <glib/gprintf.h>

void visit_website(Browser * b, GString * s)
{
    if(b->counter != b->size)
    {
    b->list = g_list_insert(b->list, s,b->counter);
        b->counter++;
    }

}

void back_website(Browser * b)
{
    GList * temp = g_list_last(b->list);
   b->list = g_list_remove(b->list,temp);
}

void history_print (Browser *b)
{
    for(int i = 0; i < HISTORY_SIZE; i++)
    {
        g_printf("%s", ((char *)b->list->data));
    }

}

int main(void )
{
    GList * l = NULL;         
    Browser b = {
    .size = HISTORY_SIZE,
    .counter = 0,
    .list = l,
    //.vptr = &Browser_vtable,
     };
     
    //if(argc == 1)
   // {
   GString datas;
   GString back = g_string_new ("back");
   GString history = g_string_new ("history");
   //GString visit = g_string_new ("visit");
   
   while(scanf("%s",datas->str) != EOF)
   {
        if(g_string_equal(data,back)) 
        {
           // b.vptr.back(b);
           back_website(&b);
        }
        else if(g_string_equal(data,history)) 
        {
           //  b->vptr.history(b)
           history_print(&b);
        }
        else
        {
           // b->vptr.visit(b,argv[1]);
          // GString * foo = g_string_new((gchar *)argv[1]);
           visit_website(&b,datas);
        }
   // }
   
   }

}

