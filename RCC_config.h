/***************************************************************/
/* Author  : Sayed Elrouby                                     */
/* Date    : 14 Aug 2020                                       */
/* Version : V1                                                */    
/***************************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* Options : RCC_HSE_CRYSTAL
             RCC_HSE_RC
             RCC_HSI
			 RCC_PLL        */
#define RCC_CLOCK_TYPE     RCC_HSE_CRYSTAL



  /*Pll Config*/
#if     RCC_CLOCK_TYPE == RCC_PLL
/* Options : RCC_HSE_IN_PLL
			 RCC_HSE_DIV2_IN_PLL
			 RCC_HSI_DIV2_IN_PLL   */	
/* NOTE : sellect value only if pll as input clock   */			 
#define  RCC_PLL_INPUT   RCC_HSE_IN_PLL
#endif  



#if   RCC_CLOCK_TYPE  == RCC_PLL
/*Options : 2-->16*/
/* NOTE : sellect value only if pll as input clock   */		
#define RCC_CLOCK_MUL  2
#endif


#endif