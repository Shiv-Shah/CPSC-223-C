#include <stdio.h>
#include <string.h>
#include <stdint.h>



int main()
{
	//	uint8_t eof = 0;
		char  str_input[5]; // str_input[];
		unsigned int input =0;
		uint8_t total_val = 0;
		while(scanf("%5s%x",str_input,&input) != EOF)
		{					
			if(strcmp(str_input,"set") == 0)
			{
			//	set(&total_val, &input);
				total_val = input;
				printf("set %x => %x",input, total_val);
				
			}
			else if(strcmp(str_input,"shl") == 0)
			{
				//total_val = sh1(&total_val,&input);
				total_val =  total_val << input;
				printf("shl %x => %x" ,input,total_val );
			}
			else if(strcmp(str_input,"shr") == 0)
			{
				//total_val = shr(&total_val,&input)
				total_val = total_val >> input;
				printf("shr %x => %x",input,total_val);
			}
			else if(strcmp(str_input,"or") == 0)
			{
				//total_val = or_com(&total_val,input);
				total_val|= input; // total_val = total_val|input 
				printf("or %x => %x",input,total_val);
			}
			else if(strcmp(str_input,"and") == 0)
			{
				//total_val = and_com(&total_val,&input);
				total_val &=input;
				printf("and %x => %x",input,total_val);
			}
			else if(strcmp(str_input,"xor") == 0)
			{
				//total_val = xor_com(&total_val,&input);input
				total_val ^= input;
				printf("xor %x => %x",(uint8_t)input,total_val);
			}
			else
			{
				printf("Not a valid input choose a different input");
			}
			
			printf("\n");
		}			
}
