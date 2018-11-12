#include "STC15F2K60S2.h"
#include "LCD1602.h"
#include "BPC.h"
#include <intrins.h>
void main()
{
	Initialize_LCD();
	ClearLine(1);
	ClearLine(2);
	Timer0Init();
	while(1)
	{
		if((bpc_update==1&&valid_flag==1)||local_update==1)
		{
			WriteChar(1,2,(year/1000)+48);
			WriteChar(1,3,(year/100)%10+48);
			WriteChar(1,4,(year/10)%10+48);
			WriteChar(1,5,(year%10)+48);
			WriteChar(1,6,'/');
			WriteChar(1,7,(month/10)%10+48);
			WriteChar(1,8,(month%10)+48);
			WriteChar(1,9,'/');
			WriteChar(1,10,(day/10)%10+48);
			WriteChar(1,11,(day%10)+48);
			if(week==1) PutString(1,13,"Mon");
			else if(week==2) PutString(1,14,"Tue");
			else if(week==3) PutString(1,14,"Wed");
			else if(week==4) PutString(1,14,"Thu");
			else if(week==5) PutString(1,14,"Fri");
			else if(week==6) PutString(1,14,"Sat");
			else if(week==7) PutString(1,14,"Sun");
			WriteChar(2,2,(hour/10)%10+48);
			WriteChar(2,3,(hour%10)+48);
			WriteChar(2,4,':');
			WriteChar(2,5,(minute/10)%10+48);
			WriteChar(2,6,(minute%10)+48);
			WriteChar(2,7,':');
			WriteChar(2,8,(second/10)%10+48);
			WriteChar(2,9,(second%10)+48);
			PutString(2,11,"BJTU");
			
			if(bpc_update) valid_flag=0;
			bpc_update=0;
			local_update=0;
		}
	}
}