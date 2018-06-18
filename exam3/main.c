// argc is the # of arguments
// argv is the actual argument itself
// the plan is to take in each character and change it to be lowercase or uppercase depending on the value
// we will ge using getopt to do that by taking in u l and t 

#include <stdio.h>
#include <string.h>
#include "filter.h"
#include <unistd.h>

int main(int argc, char * argv[])
{
    int low = 0;
    int up = 0;
    int tog = 0;
    int opt;
    FILE *fp;
    char c;
    
    if(argc >= 3)
    {
        while((opt = getopt(argc,argv,"ult"))!= -1)
        {
            switch(opt)
            {
                case 'u':
                    up = 1;
                break;
                case 'l':
                    low = 1;
                break;
                case 't':
                    tog = 1;
                break;
                default:
                break;
                
            }
            
            for(; optind < argc; optind++)
            {
                fp = fopen(argv[optind],"r");
                while(fscanf(fp,"%c",&c) != EOF)
                {
                    if(up == 1)
                    {
                        c =to_upper(c);
                    }
                    else if(low == 1)
                    {
                       c = to_lower(c);
                    }
                    else if(tog == 1)
                    {
                        c = toggle(c);
                    }
                    char n = c;
                    printf("%c",n);
                    
                }
            }
        }
    }
    else
    {
        printf("Specify one of '-u', '-l' or '-t'");
    }
    
    
}
