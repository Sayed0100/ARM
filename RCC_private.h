/***************************************************************/
/* Author  : Sayed Elrouby                                     */
/* Date    : 14 Aug 2020                                       */
/* Version : V1                                                */    
/***************************************************************/
#ifndef RCC_PRIVAT_H
#define RCC_PRIVAT_H


  /*Register defination */
#define RCC_CR             *((u32*)(0x40021000+0X00))/*Enable clock on cpu*/
#define RCC_CFGR           *((u32*)(0x40021000+0X04))/*Enable clock on cpu*/
#define RCC_CIR            *((u32*)(0x40021000+0X08))
#define RCC_APB2RSTR       *((u32*)(0x40021000+0X0C))
#define RCC_APB1RSTR       *((u32*)(0x40021000+0X10))
#define RCC_AHBENR         *((u32*)(0x40021000+0X14)) /*Enable clock on peripheral*/
#define RCC_APB2ENR        *((u32*)(0x40021000+0X18)) /*Enable clock on peripheral*/
#define RCC_APB1ENR        *((u32*)(0x40021000+0X1C)) /*Enable clock on peripheral*/
#define RCC_BDCR           *((u32*)(0x40021000+0X20))


/* Option Of Clock*/
#define   RCC_HSE_CRYSTAL  0
#define   RCC_HSE_RC       1
#define   RCC_HSI          2
#define   RCC_PLL          3 
			 

/*Option Of enable*/
#define      RCC_HSE_IN_PLL       0
#define		 RCC_HSE_DIV2_IN_PLL  1
#define		 RCC_HSI_DIV2_IN_PLL  2



#endif
