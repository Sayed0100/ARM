/***************************************************************/
/* Author  : Sayed Elrouby                                     */
/* Date    : 14 Aug 2020                                       */
/* Version : V1                                                */    
/***************************************************************/

#ifndef  RCC_PROGRAM_C
#define RCC_PROGRAM_C

#include "STD_TYPES.h"
#include "BIT_Math.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

             
            
 void RCC_VoidInitSysClock(void)
 {
   #if CLOCK_SYSTEM_EN   ==  RCC_HSE_CRYSTAL
	 RCC_CR     = 0x00010080;    /*HSE_Crystal (clock) Without Bypass*/
	 RCC_CFGR   = 0x00000001;    /*Enable HSE As Input On System   */
   #elif CLOCK_SYSTEM_EN ==  RCC_HSE_RC
	 RCC_CR     = 0x00050080;    /*Enable HSE_RC(clock) With Bypass */
	 RCC_CFGR   = 0x00000001;    /*Enable HSI As Input On System */
   #elif CLOCK_SYSTEM_EN ==  RCC_HSI
	 RCC_CR     = 0x00000081;    /*Enable HSI(clock) With Bypass */
	 RCC_CFGR   = 0x00000000;    /*Enable HSI As Input On System */
	 
	 
   #elif CLOCK_SYSTEM_EN ==  RCC_PLL
   
	  #if   RCC_PLL_INPUT == RCC_HSE_IN_PLL
            RCC_CFGR = 0x00010002;	                /* HSE As Input On Pll   */
			RCC_CFGR|=((RCC_CLOCK_MUL -2)<<18)
			SET_BIT(RCC_CR,24);                   /*Enable Pll             */
			
	  #elif RCC_PLL_INPUT == RCC_HSE_DIV2_IN_PLL
	        RCC_CFGR = 0x00030002;	                /* HSE/2 As Input On Pll */
			RCC_CFGR|=((RCC_CLOCK_MUL -2)<<18)      /*Mul Factor*/
			SET_BIT(RCC_CR,24);                   /*Enable Pll           	 */
			
	  #elif RCC_PLL_INPUT == RCC_HSI_DIV2_IN_PLL 
	        RCC_CFGR = 0x00030002;	                /* HSI/2 As Input On Pll */
			RCC_CFGR|=((RCC_CLOCK_MUL -2)<<18)
			SET_BIT(RCC_CR,24);                   /* Enable Pll            */
			
			
	  #endif
	 
	 
	 
	 #else
		 #error("There Are Error")
	  #endif
 }

/* Enter RCC_AHB,RCC_APB1,RCC_APB2*/
void RCC_VoidEnableClock(u8 Copy_BusId,u8 Copy_PerId)
{
	if(Copy_PerId<=31)
	{
		switch(Copy_BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR ,Copy_PerId);break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR,Copy_PerId);break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR,Copy_PerId);break;
			default    : break;
			

		}
	}
	else
	{
		/*Return Erorr*/
	}
	
}
void RCC_VoidDisableClock(u8 Copy_BusId,u8 Copy_PerId)
{
	if(Copy_PerId<=31)
	{
		switch(Copy_BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR ,Copy_PerId);break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR,Copy_PerId);break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR,Copy_PerId);break;
			default    : break;
			
		}
	}
	else
	{
		/*Return Erorr*/
	}
	
}



#endif
