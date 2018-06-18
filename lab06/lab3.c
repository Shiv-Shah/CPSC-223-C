#include <stdio.h>
//#include <string.h>
#include <stdint.h>
#include "bstrlib.h"

struct bit_op
{
	int id_num;
	bstring name;
	int amount ;
};

int main()
{
	bstring set = bfromcstr("set");
	bstring set2 = bfromcstr("set");
	bstring set3 = bfromcstr("set");
	bstring shl = bfromcstr("shl");
	bstring shl2 = bfromcstr("shl");
	bstring shl3 = bfromcstr("shl");
	bstring or = bfromcstr("or");
	bstring or2 = bfromcstr("or");
	bstring xor = bfromcstr("xor");
	bstring xor2 = bfromcstr("xor");
	bstring and = bfromcstr("and");
	bstring and2 = bfromcstr("and");
	bstring shr = bfromcstr("shr");
	
  struct bit_op bit[] = 
	{
		{1,set,1},
		{2,shl,1},
		{3,shl2,1},
		{4,or,1},
		{5,or2,2},
		{6,shl3,2},
		{7,xor,10},
		{8,xor2,10},
		{9,and,4},
		{10,set2, 0x1c},
		{11,and2,3},
		{12,set3, 0x1c},
		{13,shr,1}	
	};
	
	bstring  dbg_input;
	int stepper = 0;
	uint8_t total_val = 0;
	printf("What would you like to do? Your options are list, step, print, continue,quit \n");
		while((dbg_input = bgets((bNgetc) fgetc,stdin,'\n')) !=NULL)
		{
			if(biseqcstr(dbg_input,"list\n") == 1)
			{
				if(stepper <= 0)
				{
					printf("%d %s %x \n",bit[0].id_num, bit[0].name->data,bit[0].amount);
					printf("%d %s %x\n", bit[1].id_num, bit[1].name->data,bit[1].amount);
				}
				else if(stepper >= 12)
				{
					printf("%d %s %x\n", bit[11].id_num, bit[11].name->data,bit[11].amount);
					printf("%d %s %x\n", bit[12].id_num, bit[12].name->data,bit[12].amount);
				}
				else 
				{
						printf("%d %s %x\n", bit[stepper-1].id_num, bit[stepper-1].name->data,bit[stepper-1].amount);
						printf("%d %s %x\n", bit[stepper].id_num, bit[stepper].name->data,bit[stepper].amount);
						printf("%d %s %x\n", bit[stepper+1].id_num, bit[stepper+1].name->data,bit[stepper+1].amount);
				}
			}
			
			else if(biseqcstr(dbg_input,"step\n") == 1)
			{
			//	printf("before the step if question");
				if(biseqcstr(bit[stepper].name,"set") == 1)
					{
						total_val = bit[stepper].amount;
					}
					else if(biseqcstr(bit[stepper].name,"shl") == 1)
					{
						total_val =  total_val << bit[stepper].amount;
					}
					else if(biseqcstr(bit[stepper].name,"shr") == 1)
					{
						//total_val = shr(&total_val,&input)
						total_val = total_val >> bit[stepper].amount;
					//	printf("shr %x => %x",bit[i].amount,total_val);
					}
					else if(biseqcstr(bit[stepper].name,"or") == 1)
					{
						//total_val = or_com(&total_val,input);
						total_val|= bit[stepper].amount; // total_val = total_val|input 
					//	printf("or %x => %x",bit[i].amount,total_val);
					}
					else if(biseqcstr(bit[stepper].name,"and") == 1)
					{
						//total_val = and_com(&total_val,&input);
						total_val &=bit[stepper].amount;
					//	printf("and %x => %x",bit[i].amount,total_val);
					}
					else if(biseqcstr(bit[stepper].name,"xor") == 1)
					{
						//total_val = xor_com(&total_val,&input);input
						total_val ^= bit[stepper].amount;
					//	printf("xor %x => %x",(uint8_t)bit[i].amount,total_val);
					}
			//		printf("\n");
					stepper++;
			}
			else if(biseqcstr(dbg_input,"print\n") == 1)
			{
				//printf("before the [rint if question");
				printf("%x\n",total_val );
		
			}
			else if(biseqcstr(dbg_input,"continue\n") == 1)
			{
				for(stepper = stepper; stepper  < 13; stepper++)
				{
					if(biseqcstr(bit[stepper].name,"set") == 1)
					{
					//	set(&total_val, &input);
						total_val = bit[stepper].amount;
					//	printf("set %x => %x",bit[i].amount, total_val);
				
					}
					else if(biseqcstr(bit[stepper].name,"shl") == 1)
					{
						//total_val = sh1(&total_val,&input);
						total_val =  total_val << bit[stepper].amount;
					//	printf("shl %x => %x" ,bit[i].amount,total_val );
					}
					else if(biseqcstr(bit[stepper].name,"shr") == 1)
					{
						//total_val = shr(&total_val,&input)
						total_val = total_val >> bit[stepper].amount;
					//	printf("shr %x => %x",bit[i].amount,total_val);
					}
					else if(biseqcstr(bit[stepper].name,"or") == 1)
					{
						//total_val = or_com(&total_val,input);
						total_val|= bit[stepper].amount; // total_val = total_val|input 
					//	printf("or %x => %x",bit[i].amount,total_val);
					}
					else if(biseqcstr(bit[stepper].name,"and") == 1)
					{
						//total_val = and_com(&total_val,&input);
						total_val &=bit[stepper].amount;
					//	printf("and %x => %x",bit[i].amount,total_val);
					}
					else if(biseqcstr(bit[stepper].name,"xor") == 1)
					{
						//total_val = xor_com(&total_val,&input);input
						total_val ^= bit[stepper].amount;
					//	printf("xor %x => %x",(uint8_t)bit[i].amount,total_val);
					}
					//stepper++;
				//	printf("\n");
					
				}
			}
			else if(biseqcstr(dbg_input,"quit\n") == 1)
			{
				brtrimws(dbg_input);
				bdestroy(dbg_input);
			
				break;
			}
			else
			{
				printf("invalid value\n");
			}
			bdestroy(dbg_input);
				
		}
			bdestroy(set);
			bdestroy(set2);
			bdestroy(set3);
			bdestroy(shl);
			bdestroy(shl2);
			bdestroy(shl3);
			bdestroy(or);
			bdestroy(or2);
			bdestroy(xor);
			bdestroy(xor2);
			bdestroy(and);
			bdestroy(and2);
			bdestroy(shr);
			bdestroy(dbg_input);
	//}
}
