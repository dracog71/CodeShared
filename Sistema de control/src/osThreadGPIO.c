/**
  ******************************************************************************
  * @file    OSTHREADGPIO.c
  * @author  EDESIGN TEAM
  * @version V1.3.0        
  * @date    24-Febrero-2015
  * @brief   ________________________________________________________________
  *          ________________________________________________________________ 
  ****************************************************************************** 
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */
	
		/* Incluside------------------------------------------------------------------*/
#include "osThreadGPIO.h"
	
	/** @addtogroup Definiciones Internas de OsThreadGPIO
  * @{
  */
     GPIO_InitTypeDef GPIO_InitStruct; 
/**
  * @}
  */

/**
  * @brief  Inicializacion de pines Basado en el tipo de funcion a levantar
  * @retval Ninguno
  */
void osThreadGPIOInitFunc(
	 uint32_t Funcion,   /* Tipo de funcion que se desea implementar */
   uint32_t PinsPack   /* Pines que se desean configurar () */
   ){
	
	 /* Compara la funcion de entrada y envía los datos a la funcion de inicializacion pertinente */
	 switch (Funcion){
		 
		 case os_USART1:
			 osThreadGPIOInitUSART(Funcion, PinsPack);
		   break;
		 
		 case os_USART2:
			 osThreadGPIOInitUSART(Funcion, PinsPack);
		   break;
		 
		 case os_USART3:
			 osThreadGPIOInitUSART(Funcion, PinsPack);
		   break;
		 
		 case os_USART4:
			 osThreadGPIOInitUSART(Funcion, PinsPack);
		   break;
		 
		 case os_USART5:
			 osThreadGPIOInitUSART(Funcion, PinsPack);
		   break;
		 
		 case os_USART6:
			 osThreadGPIOInitUSART(Funcion, PinsPack);
		   break;
		 
	 case os_CANBUS1:
			 osThreadGPIOInitCANBUS(Funcion, PinsPack);
		   break;
				 
		case os_CANBUS2:
			 osThreadGPIOInitCANBUS(Funcion, PinsPack);
		   break;
		
		 default:
			 break;
	 }
 }

 /**
  * @brief  Inicializacion de pines del USART
  * @retval Ninguno
  */
void osThreadGPIOInitUSART(
	   uint32_t USART,      /* USART al que se le aplica la configuracion */
     uint32_t PinsPack    /* Pines que se desean configurar */
     ){
			 
	 	 switch (USART){
	            
		     case os_USART1:
		            
	           switch (PinsPack){
     	                   
				         case USART1_PA9PA10:
                             					 
		                 /* Configuracion de funciones alternativas */
								     osThreadGPIOInit(PA9, osThreadGPIO_USART);
				             osThreadGPIOInit(PA10, osThreadGPIO_USART);
	                   GPIO_PinAFConfig(GPIOA, GPIO_PinSource9,  GPIO_AF_USART1); //
	                   GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
										 break;
                       
				         case USART1_PA9PB7:
		                                 
		                 /* Configuracion de funciones alternativas */
								     osThreadGPIOInit(PA9, osThreadGPIO_USART);
				             osThreadGPIOInit(PB7, osThreadGPIO_USART); 
	                   GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1); //
	                   GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_USART1);
				             break;								 
                         
				         case USART1_PB6PA10:
	                                    
		                 /* Configuracion de funciones alternativas */
							    	 osThreadGPIOInit(PB6, osThreadGPIO_USART);
				             osThreadGPIOInit(PA10, osThreadGPIO_USART); 
	                   GPIO_PinAFConfig(GPIOB, GPIO_PinSource6,  GPIO_AF_USART1); //
	                   GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
                     break;								 
                                 
				         case USART1_PB6PB7:
					                        
		                 /* Configuracion de funciones alternativas */
								     osThreadGPIOInit(PB6, osThreadGPIO_USART);
				             osThreadGPIOInit(PB7, osThreadGPIO_USART); 
	                   GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_USART1); //
	                   GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_USART1);
                     break;								 
                                
				         default:
					           break;
				                      
			           }
		         break;       
		     
         case os_USART2:
		            
	           switch (PinsPack){
     	                   
				         case USART2_PA2PA3:
                             					 
		                 /* Configuracion de funciones alternativas */
								     osThreadGPIOInit(PA2, osThreadGPIO_USART);
				             osThreadGPIOInit(PA3, osThreadGPIO_USART);
	                   GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2); //
	                   GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);
                     break;								 
                       
				         case USART2_PA2PD6:
		                                 
		                 /* Configuracion de funciones alternativas */
								     osThreadGPIOInit(PA2, osThreadGPIO_USART);
				             osThreadGPIOInit(PD6, osThreadGPIO_USART);
	                   GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2); //
	                   GPIO_PinAFConfig(GPIOD, GPIO_PinSource6, GPIO_AF_USART2);
                     break;								 
                         
				         case USART2_PD5PA3:
	                                    
		                 /* Configuracion de funciones alternativas */
										 osThreadGPIOInit(PD5, osThreadGPIO_USART);
				             osThreadGPIOInit(PA3, osThreadGPIO_USART); 
	                   GPIO_PinAFConfig(GPIOD, GPIO_PinSource5,  GPIO_AF_USART2); //
	                   GPIO_PinAFConfig(GPIOA, GPIO_PinSource3,  GPIO_AF_USART2);
                     break;								 
                                 
				         case USART2_PD5PD6:
					                        
		                 /* Configuracion de funciones alternativas */
							    	 osThreadGPIOInit(PD5, osThreadGPIO_USART);
				             osThreadGPIOInit(PD6, osThreadGPIO_USART);  
	                   GPIO_PinAFConfig(GPIOD, GPIO_PinSource5,  GPIO_AF_USART2); //
	                   GPIO_PinAFConfig(GPIOD, GPIO_PinSource6, GPIO_AF_USART2);
                     break;								 
                                
				         default:
					           break;
				                      
			           }
		         break;  
								 
         case os_USART3:
		            
	           switch (PinsPack){
     	                   
				         case USART3_PB10PB11:
                             					 
		                 /* Configuracion de funciones alternativas */
								     osThreadGPIOInit(PB10, osThreadGPIO_USART);
				             osThreadGPIOInit(PB11, osThreadGPIO_USART);  
	                   GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_USART3); //
	                   GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_USART3);
								     break;
                       
				         case USART3_PB10PC11:
		                                 
		                 /* Configuracion de funciones alternativas */
								     osThreadGPIOInit(PB10, osThreadGPIO_USART);
				             osThreadGPIOInit(PC11, osThreadGPIO_USART);
	                   GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_USART3); //
	                   GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_USART3);
								     break;
                         
				         case USART3_PB10PD9:
	                                    
		                 /* Configuracion de funciones alternativas */
							    	 osThreadGPIOInit(PB10, osThreadGPIO_USART);
				             osThreadGPIOInit(PD9, osThreadGPIO_USART);
	                   GPIO_PinAFConfig(GPIOB, GPIO_PinSource10,  GPIO_AF_USART3); //
	                   GPIO_PinAFConfig(GPIOD, GPIO_PinSource9,  GPIO_AF_USART3);
                     break;
                                 
				         case USART3_PC10PB11:
					                        
		                 /* Configuracion de funciones alternativas */
								     osThreadGPIOInit(PC10, osThreadGPIO_USART);
				             osThreadGPIOInit(PB11, osThreadGPIO_USART); 
	                   GPIO_PinAFConfig(GPIOC, GPIO_PinSource10,  GPIO_AF_USART3); //
	                   GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_USART3);
                     break;			

				         case USART3_PC10PC11:
					                        
		                 /* Configuracion de funciones alternativas */
								     osThreadGPIOInit(PC10, osThreadGPIO_USART);
				             osThreadGPIOInit(PC11, osThreadGPIO_USART); 
	                   GPIO_PinAFConfig(GPIOC, GPIO_PinSource10,  GPIO_AF_USART3); //
	                   GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_USART3);
                     break;	

				         case USART3_PC10PD9:
					                        
		                 /* Configuracion de funciones alternativas */
								     osThreadGPIOInit(PC10, osThreadGPIO_USART);
				             osThreadGPIOInit(PD9, osThreadGPIO_USART); 
	                   GPIO_PinAFConfig(GPIOC, GPIO_PinSource10,  GPIO_AF_USART3); //
	                   GPIO_PinAFConfig(GPIOD, GPIO_PinSource9, GPIO_AF_USART3);
                     break;	

				         case USART3_PD8PD9:
					                        
		                 /* Configuracion de funciones alternativas */
							    	 osThreadGPIOInit(PD8, osThreadGPIO_USART);
				             osThreadGPIOInit(PD9, osThreadGPIO_USART); 
	                   GPIO_PinAFConfig(GPIOD, GPIO_PinSource8,  GPIO_AF_USART3); //
	                   GPIO_PinAFConfig(GPIOD, GPIO_PinSource9, GPIO_AF_USART3);
                     break;	

				         case USART3_PD8PB11:
					                        
		                 /* Configuracion de funciones alternativas */
								     osThreadGPIOInit(PD8, osThreadGPIO_USART);
				             osThreadGPIOInit(PB11, osThreadGPIO_USART);
	                   GPIO_PinAFConfig(GPIOD, GPIO_PinSource8,  GPIO_AF_USART3); //
	                   GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_USART3);
                     break;	

				         case USART3_PD8PC11:
					                        
		                 /* Configuracion de funciones alternativas */
							    	 osThreadGPIOInit(PD8, osThreadGPIO_USART);
				             osThreadGPIOInit(PC11, osThreadGPIO_USART); 
	                   GPIO_PinAFConfig(GPIOD, GPIO_PinSource8,  GPIO_AF_USART3); //
	                   GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_USART3);
                     break;									 
                                
				         default:
					           break;
				                      
			           }
		         break;  

         case os_USART4:
		            
	           switch (PinsPack){
     	                   
				         case USART4_PA0PA1:
                             					 
		                 /* Configuracion de funciones alternativas */
								     osThreadGPIOInit(PA0, osThreadGPIO_USART);
				             osThreadGPIOInit(PA1, osThreadGPIO_USART);
	                   GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_UART4); //
	                   GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_UART4);
                     break;								 
                       
				         case USART4_PA0PC11:
		                                 
		                 /* Configuracion de funciones alternativas */
								     osThreadGPIOInit(PA0, osThreadGPIO_USART);
				             osThreadGPIOInit(PC11, osThreadGPIO_USART);
	                   GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_UART4); //
	                   GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_UART4);
                     break;								 
                         
				         case USART4_PC10PA1:
	                                    
		                 /* Configuracion de funciones alternativas */
								     osThreadGPIOInit(PC10, osThreadGPIO_USART);
				             osThreadGPIOInit(PA1, osThreadGPIO_USART); 
	                   GPIO_PinAFConfig(GPIOC, GPIO_PinSource10,  GPIO_AF_UART4); //
	                   GPIO_PinAFConfig(GPIOA, GPIO_PinSource1,  GPIO_AF_UART4);
                     break;								 
                                 
				         case USART4_PC10PC11:
					                        
		                 /* Configuracion de funciones alternativas */
								     osThreadGPIOInit(PC10, osThreadGPIO_USART);
				             osThreadGPIOInit(PC11, osThreadGPIO_USART); 
	                   GPIO_PinAFConfig(GPIOC, GPIO_PinSource10,  GPIO_AF_UART4); //
	                   GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_UART4);
                     break;								 
                                
				         default:
					           break;
				                      
			           }
		         break;  
								 
         case os_USART5:
		            
	           switch (PinsPack){
     	                   
				         case USART5_PC12PD2:
                             					 
		                 /* Configuracion de funciones alternativas */
								     osThreadGPIOInit(PC12, osThreadGPIO_USART);
				             osThreadGPIOInit(PD2, osThreadGPIO_USART); 
	                   GPIO_PinAFConfig(GPIOC, GPIO_PinSource12, GPIO_AF_UART5); //
	                   GPIO_PinAFConfig(GPIOD, GPIO_PinSource2, GPIO_AF_UART5);
                     break;								 
                       
				         default:
					           break;
				                      
			           }
		         break;
								 
         case os_USART6:
		            
	           switch (PinsPack){
     	                   
				         case USART6_PC6PC7:
                             					 
		                 /* Configuracion de funciones alternativas */
								     osThreadGPIOInit(PC6, osThreadGPIO_USART);
				             osThreadGPIOInit(PC7, osThreadGPIO_USART); 
	                   GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_USART6); //
	                   GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_USART6);
                     break;								 
                       
				         case USART6_PC6PG14:
		                                 
		                 /* Configuracion de funciones alternativas */
								     osThreadGPIOInit(PC6, osThreadGPIO_USART);
				             osThreadGPIOInit(PG14, osThreadGPIO_USART);
	                   GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_USART6); //
	                   GPIO_PinAFConfig(GPIOG, GPIO_PinSource14, GPIO_AF_USART6);
                     break;								 
                         
				         case USART6_PG9PC7:
	                                    
		                 /* Configuracion de funciones alternativas */
								     osThreadGPIOInit(PG9, osThreadGPIO_USART);
				             osThreadGPIOInit(PC7, osThreadGPIO_USART); 
	                   GPIO_PinAFConfig(GPIOG, GPIO_PinSource9,  GPIO_AF_USART6); //
	                   GPIO_PinAFConfig(GPIOC, GPIO_PinSource7,  GPIO_AF_USART6);
                     break;								 
                                 
				         case USART6_PG9PG14:
					                        
		                 /* Configuracion de funciones alternativas */
								     osThreadGPIOInit(PG9, osThreadGPIO_USART);
				             osThreadGPIOInit(PG14, osThreadGPIO_USART); 
	                   GPIO_PinAFConfig(GPIOG, GPIO_PinSource9,  GPIO_AF_USART6); //
	                   GPIO_PinAFConfig(GPIOG, GPIO_PinSource14, GPIO_AF_USART6);
                     break;								 
                                
				         default:
					           break;
				                      
			           }
		         break;
								 
		     default:             
			       break;
	   }   
}

 /**
  * @brief  Inicializacion de pines del canBUS
  * @retval Ninguno
  */
void osThreadGPIOInitCANBUS(
	   uint32_t CANBUS,      /* USART al que se le aplica la configuracion */
     uint32_t PinsPack    /* Pines que se desean configurar */
     ){
		
    switch(CANBUS){
 
			case os_CANBUS1:
				switch(PinsPack){
					case CANBUS1_PD1PD0:
				    osThreadGPIOInit(PD1, osThreadGPIO_CANBUS);
				    osThreadGPIOInit(PD0, osThreadGPIO_CANBUS); 
	          GPIO_PinAFConfig(GPIOD, GPIO_PinSource1,  GPIO_AF_CAN1); 
	          GPIO_PinAFConfig(GPIOD, GPIO_PinSource0,  GPIO_AF_CAN1);
						break;
					
					case CANBUS1_PB8PB9:
				    osThreadGPIOInit(PB8, osThreadGPIO_CANBUS);
				    osThreadGPIOInit(PB9, osThreadGPIO_CANBUS); 
	          GPIO_PinAFConfig(GPIOB, GPIO_PinSource8,  GPIO_AF_CAN1); 
	          GPIO_PinAFConfig(GPIOB, GPIO_PinSource9,  GPIO_AF_CAN1);
						break;
					
					default:
						break;
				}
				 break;
			
			case os_CANBUS2:
				 osThreadGPIOInit(PB6, osThreadGPIO_CANBUS);
				 osThreadGPIOInit(PB5, osThreadGPIO_CANBUS); 
	       GPIO_PinAFConfig(GPIOB, GPIO_PinSource6,  GPIO_AF_CAN2); //
	       GPIO_PinAFConfig(GPIOB, GPIO_PinSource5,  GPIO_AF_CAN2);
				 break;
			
			default:
				break;
			
		}			
			 
}
		 
 /**
  * @brief  Inicializacion de pines del canBUS
  * @retval Ninguno
  */
void osThreadGPIOInitINT(
     GPIO_TypeDef * GPIOx,     /* Definicion del puerto que se desea configurar */
     uint16_t Pin             /* Pin sobre el cual se aplican las configuraciones */
     ){
			 
		EXTI_InitTypeDef EXTI_InitStruct;
    NVIC_InitTypeDef NVIC_InitStruct;
		
    /* Definiciones de variables privadas  */			 
		uint8_t EXTI_PortSourceGPIOx;
		uint8_t EXTI_PinSourcex;
		uint32_t EXTI_Linex;
		uint32_t EXTIx_IRQn;	 
		
		/*  Comparacion para obtener el puerto de configuracion */
		
	  if (GPIOx == GPIOA)
    {
       EXTI_PortSourceGPIOx = EXTI_PortSourceGPIOA;
    }
    else if (GPIOx == GPIOB)
    {
       EXTI_PortSourceGPIOx = EXTI_PortSourceGPIOB;
    }
    else if (GPIOx == GPIOC)
    {
       EXTI_PortSourceGPIOx = EXTI_PortSourceGPIOC;
    }
    else if (GPIOx == GPIOD)
    {
       EXTI_PortSourceGPIOx = EXTI_PortSourceGPIOD;
    }
    else if (GPIOx == GPIOE)
    {
       EXTI_PortSourceGPIOx = EXTI_PortSourceGPIOE;
    }
    else if (GPIOx == GPIOF)
    {
       EXTI_PortSourceGPIOx = EXTI_PortSourceGPIOF;
    }
    else if (GPIOx == GPIOG)
    {
       EXTI_PortSourceGPIOx = EXTI_PortSourceGPIOG;
    }
    else if (GPIOx == GPIOH)
    {
       EXTI_PortSourceGPIOx = EXTI_PortSourceGPIOH;
    }

    /* Definicion del pin que se desea activar la interrupcion */			 
		switch(Pin){
			case GPIO_Pin_0:
				EXTI_PinSourcex = EXTI_PinSource0;
			  EXTI_Linex = EXTI_Line0;
			  EXTIx_IRQn = EXTI0_IRQn;
				break;
			
			case GPIO_Pin_1:
				EXTI_PinSourcex = EXTI_PinSource1;
			  EXTI_Linex = EXTI_Line1;
			  EXTIx_IRQn = EXTI1_IRQn;
				break;
			
			case GPIO_Pin_2:
				EXTI_PinSourcex = EXTI_PinSource2;
			  EXTI_Linex = EXTI_Line2;
			  EXTIx_IRQn = EXTI2_IRQn;
				break;
			
			case GPIO_Pin_3:
				EXTI_PinSourcex = EXTI_PinSource3;
			  EXTI_Linex = EXTI_Line3;
			  EXTIx_IRQn = EXTI3_IRQn;
				break;
			
			case GPIO_Pin_4:
				EXTI_PinSourcex = EXTI_PinSource4;
			  EXTI_Linex = EXTI_Line4;
			  EXTIx_IRQn = EXTI4_IRQn;
				break;
			
			case GPIO_Pin_5:
				EXTI_PinSourcex = EXTI_PinSource5;
			  EXTI_Linex = EXTI_Line5;
			  EXTIx_IRQn = EXTI9_5_IRQn;
				break;
			
			case GPIO_Pin_6:
				EXTI_PinSourcex = EXTI_PinSource6;
			  EXTI_Linex = EXTI_Line6;
			  EXTIx_IRQn = EXTI9_5_IRQn;
				break;
			
			case GPIO_Pin_7:
				EXTI_PinSourcex = EXTI_PinSource7;
			  EXTI_Linex = EXTI_Line7;
			  EXTIx_IRQn = EXTI9_5_IRQn;
				break;
			
			case GPIO_Pin_8:
				EXTI_PinSourcex = EXTI_PinSource8;
			  EXTI_Linex = EXTI_Line8;
			  EXTIx_IRQn = EXTI9_5_IRQn;
				break;
			
			case GPIO_Pin_9:
				EXTI_PinSourcex = EXTI_PinSource9;
			  EXTI_Linex = EXTI_Line9;
			  EXTIx_IRQn = EXTI9_5_IRQn;
				break;
			
			case GPIO_Pin_10:
				EXTI_PinSourcex = EXTI_PinSource10;
			  EXTI_Linex = EXTI_Line10;
			  EXTIx_IRQn = EXTI15_10_IRQn;
				break;
			
			case GPIO_Pin_11:
				EXTI_PinSourcex = EXTI_PinSource11;
			  EXTI_Linex = EXTI_Line11;
			  EXTIx_IRQn = EXTI15_10_IRQn;
				break;
			
			case GPIO_Pin_12:
				EXTI_PinSourcex = EXTI_PinSource12;
			  EXTI_Linex = EXTI_Line12;
			  EXTIx_IRQn = EXTI15_10_IRQn;
				break;
			
			case GPIO_Pin_13:
				EXTI_PinSourcex = EXTI_PinSource13;
			  EXTI_Linex = EXTI_Line13;
			  EXTIx_IRQn = EXTI15_10_IRQn;
				break;
			
			case GPIO_Pin_14:
				EXTI_PinSourcex = EXTI_PinSource14;
			  EXTI_Linex = EXTI_Line14;
			  EXTIx_IRQn = EXTI15_10_IRQn;
				break;
			
			case GPIO_Pin_15:
				EXTI_PinSourcex = EXTI_PinSource15;
			  EXTI_Linex = EXTI_Line15;
			  EXTIx_IRQn = EXTI15_10_IRQn;
				break;
			
		}			
			 
    /* Habilitar reloj para SYSCFG */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

    /* Se le dice al sistema que use Pxx para EXTI_Linex */
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOx, EXTI_PinSourcex);   //<-----------------------

    /* PXX conectado a EXTI_Linea */
    EXTI_InitStruct.EXTI_Line = EXTI_Linex;                         //<-----------------------
    /* Habilitar interrupcion */
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    /* Modo de interrupcion */
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    /* Triggers en flanco de subida o bajada */
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
    /* Agregar al EXTI */
    EXTI_Init(&EXTI_InitStruct);

    /* Agregar vector IRQ al NVIC Nested Vector Interrupt Controller*/
    NVIC_InitStruct.NVIC_IRQChannel = EXTIx_IRQn;                   //<-------------------------
    /* Configurar prioridad */
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
    /* Configurar Subprioridad */
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x00;
    /* Habilitar Interrupcion */
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    /* Agregar a NVIC */
    NVIC_Init(&NVIC_InitStruct);		 
			  
}
		 
 /**
  * @brief  Inicializacion de pines Basado en el tipo de funcion a levantar
  * @retval Ninguno
  */
 void osThreadGPIOInit( 
     GPIO_TypeDef * GPIOx,     /* Definicion del puerto que se desea configurar */
     uint16_t Pin,             /* Pin sobre el cual se aplican las configuraciones */
     uint32_t Func             /* Tipo de configuracion que se cargará al pin */ 
     ){

	/* Habilita los relojes de todos los puertos a configurar*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE); 
			 
	/* Set del pin sobre el que se aplica la configuracion */
	GPIO_InitStruct.GPIO_Pin = Pin; 
	
	/* Dependiendo del tipo de funcion, es el tipo de carga a la inicializacion  */ 
	switch (Func){
		case osThreadGPIO_USART:                    
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF; 			 // El pin es configurado como funcion alternativa para que el USART pueda tener acceso
	    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;	 // Define la velocidad IO y no tiene nada que ver con el baudrate!
	    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;		   // Define el tipo de salida como modo push-pull (opuesto a open-drain)
	    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;	       // Activa las resistencias de pullup de los pines IO 
			break;
		
		case osThreadGPIO_INPUT:
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN; 			 // EL pin son configurado como modo entrada
	    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;	 // Define la velocidad Ide la entrada al maximo
	    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;			 // Define el tipo de salida como modo push-pull (opuesto a open-drain)
	    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;			   // Activa las resistencias de pullup de los pines IO 
			break;
		
		case osThreadGPIO_OUTPUT:
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT; 			 // EL pin son configurado como modo entrada
	    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;	 // Define la velocidad Ide la entrada al maximo
	    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;			 // Define el tipo de salida como modo push-pull (opuesto a open-drain)
	    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;		   // Activa las resistencias de pulldown de los pines IO 
			break;
		
		case osThreadGPIO_CANBUS:
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF; 			 // EL pin son configurado como modo entrada
	    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;	 // Define la velocidad Ide la entrada al maximo
	    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;			 // Define el tipo de salida como modo push-pull (opuesto a open-drain)
	    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;		     // Activa las resistencias de pulldown de los pines IO 
			break;                                                 
		                                                             
		case osThreadGPIO_INT:                                     
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;        // EL pin son configurado como modo entrada
      GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;      // Define el tipo de salida como modo push-pull (opuesto a open-drain)
      GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;        // Activa las resistencias de pullup de los pines IO 
      GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;  // Define la velocidad Ide la entrada al maximo
		  osThreadGPIOInitINT(GPIOx,Pin);
			break;
		
	  case osThreadGPIO_ANALOG:                                     
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AN;        // EL pin son configurado como modo entrada
      //GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;      // Define el tipo de salida como modo push-pull (opuesto a open-drain)
      GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;        // Activa las resistencias de pullup de los pines IO 
      //GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;  // Define la velocidad Ide la entrada al maximo
			break;
	 }

  /* Carga de la estructura al puerto y pin correspondiente */	 
	GPIO_Init(GPIOx, &GPIO_InitStruct);	

 }
/******************* (C) COPYRIGHT 2015 EDESIGN *****FIN DE ARCHIVO****/
