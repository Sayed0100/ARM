/***************************************************************/
/* Author  : Sayed Elrouby                                     */
/* Date    : 14 Aug 2020                                       */
/* Version : V1                                                */    
/***************************************************************/

#ifndef RCC_INTERFACE_H 
#define RCC_INTERFACE_H 
void RCC_VoidInitSysClock(void);
void RCC_VoidEnableClock(u8 Copy_BusId,u8 Copy_PerId);
void RCC_VoidDisableClock(u8 Copy_BusId,u8 Copy_PerId);

/*Option Of Buses*/
#define      RCC_AHB     0
#define		 RCC_APB1    1
#define		 RCC_APB2	 2

#endif
