#include <stdio.h>
#include <string.h>
#include <stdint.h>

struct bit_op
{
	int id_num;
	char name[5] ;
	int amount ;
};

int main()
{
	
	bit_op bit[] = 
	{
		{1,"set",1},
		{2,"shl",1},
		{3,"sh1",1},
		{4,"or",1},
		{5,"or",2},
		{6,"shl",2},
		{7,"xor",10},
		{8,"xor",10},
		{9,"and",4},
		{10,"set", 0x1c},
		{11,"and",3},
		{12,"set", 0x1c},
		{13,"shr",1}	
	};
	
	char  dbg_input[10];
	int stepper = 0;
	uint8_t total_val = 0;
	printf("What would you like to do? Your options are list, step, print, run,quit \n");
	//if(scanf("%[^\n]%*c\n", dbg_input) != "quit")
	//{
	//gets(dbg_input);
	//
		while(scanf("%s", dbg_input) == 1)
		{
			//printf("\n");
			//printf("before the list if question");
			//scanf("%s\n",dbg_input);
			if(strcmp(dbg_input,"list") == 0)
			{
				if(stepper <= 0)
				{
					printf("%d %s %x \n",bit[0].id_num, bit[0].name,bit[0].amount);
					printf("%d %s %x\n", bit[1].id_num, bit[1].name,bit[1].amount);
				}
				else if(stepper >= 12)
				{
					printf("%d %s %x\n", bit[11].id_num, bit[11].name,bit[11].amount);
					printf("%d %s %x\n", bit[12].id_num, bit[12].name,bit[12].amount);
				}
				else 
				{
					//if(bit[stepper++].id_num  >= 0 && bit[stepper++].amount >=0)
					//{
						printf("%d %s %x\n", bit[stepper-1].id_num, bit[stepper-1].name,bit[stepper-1].amount);
						printf("%d %s %x\n", bit[stepper].id_num, bit[stepper].name,bit[stepper].amount);
						printf("%d %s %x\n", bit[stepper+1].id_num, bit[stepper+1].name,bit[stepper+1].amount);
					//}
			
				}
			}
			
			else if(strcmp(dbg_input,"step") == 0)
			{
			//	printf("before the step if question");
				if(strcmp(bit[stepper].name,"set") == 0)
					{
					//	set(&total_val, &input);
						total_val = bit[stepper].amount;
					//	printf("set %x => %x",bit[i].amount, total_val);
				
					}
					else if(strcmp(bit[stepper].name,"shl") == 0)
					{
						//total_val = sh1(&total_val,&input);
						total_val =  total_val << bit[stepper].amount;
					//	printf("shl %x => %x" ,bit[i].amount,total_val );
					}
					else if(strcmp(bit[stepper].name,"shr") == 0)
					{
						//total_val = shr(&total_val,&input)
						total_val = total_val >> bit[stepper].amount;
					//	printf("shr %x => %x",bit[i].amount,total_val);
					}
					else if(strcmp(bit[stepper].name,"or") == 0)
					{
						//total_val = or_com(&total_val,input);
						total_val|= bit[stepper].amount; // total_val = total_val|input 
					//	printf("or %x => %x",bit[i].amount,total_val);
					}
					else if(strcmp(bit[stepper].name,"and") == 0)
					{
						//total_val = and_com(&total_val,&input);
						total_val &=bit[stepper].amount;
					//	printf("and %x => %x",bit[i].amount,total_val);
					}
					else if(strcmp(bit[stepper].name,"xor") == 0)
					{
						//total_val = xor_com(&total_val,&input);input
						total_val ^= bit[stepper].amount;
					//	printf("xor %x => %x",(uint8_t)bit[i].amount,total_val);
					}
			//		printf("\n");
					stepper++;
			}
			else if(strcmp(dbg_input,"print") == 0)
			{
				//printf("before the [rint if question");
				printf("%x",total_val );
		
			}
			else if(strcmp(dbg_input,"run") == 0)
			{
				for(stepper = stepper; stepper  < 13; stepper++)
				{
					if(strcmp(bit[stepper].name,"set") == 0)
					{
					//	set(&total_val, &input);
						total_val = bit[stepper].amount;
					//	printf("set %x => %x",bit[i].amount, total_val);
				
					}
					else if(strcmp(bit[stepper].name,"shl") == 0)
					{
						//total_val = sh1(&total_val,&input);
						total_val =  total_val << bit[stepper].amount;
					//	printf("shl %x => %x" ,bit[i].amount,total_val );
					}
					else if(strcmp(bit[stepper].name,"shr") == 0)
					{
						//total_val = shr(&total_val,&input)
						total_val = total_val >> bit[stepper].amount;
					//	printf("shr %x => %x",bit[i].amount,total_val);
					}
					else if(strcmp(bit[stepper].name,"or") == 0)
					{
						//total_val = or_com(&total_val,input);
						total_val|= bit[stepper].amount; // total_val = total_val|input 
					//	printf("or %x => %x",bit[i].amount,total_val);
					}
					else if(strcmp(bit[stepper].name,"and") == 0)
					{
						//total_val = and_com(&total_val,&input);
						total_val &=bit[stepper].amount;
					//	printf("and %x => %x",bit[i].amount,total_val);
					}
					else if(strcmp(bit[stepper].name,"xor") == 0)
					{
						//total_val = xor_com(&total_val,&input);input
						total_val ^= bit[stepper].amount;
					//	printf("xor %x => %x",(uint8_t)bit[i].amount,total_val);
					}
				//	printf("\n");
					
				}
			}
			else if(strcmp(dbg_input,"quit") == 0)
			{
				break;
			}
			else
			{
				printf("invalid value\n");
			}
		//	scanf("%s\n", dbg_input);
		}
	//}
}
