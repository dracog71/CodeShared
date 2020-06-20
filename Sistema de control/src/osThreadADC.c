/**
  ******************************************************************************
  * @file    canBUS.c
  * @author  EDESIGN Team
  * @version V1.0
  * @date    18-Agosto-2015
  * @brief   Configuracion de perifericos     
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
  **/
/* Include------------------------------------------------------------------*/
#include "osThreadADC.h"

/** @addtogroup Espacios de memoria especificos del ADC
  * @{
  */ 
     #define ADC3_DR_ADDRESS     ((uint32_t)0x4001224C)
     #define ADC2_DR_ADDRESS     ((uint32_t)0x4001214C)
     #define ADC1_DR_ADDRESS     ((uint32_t)0x4001204C)
/** 
  * @}
  */ 
	
/* Datos en STM32F4 Reference manual DOC ID 018909 REV1
   Pag 51 2.3 Memory map  ADCx_DR_ADDRESS 
   Registro especifico 10.13.18 pag 247 ADC Register Map  ADCx_DR_ADDRESS */

/** @addtogroup Unidad de Conversion
  * @{
  */ 
    uint32_t ADC1ConvertedValue = 0;
		
    uint32_t ADC2ConvertedValue = 0;
		
    uint32_t ADC3ConvertedValue = 0;
		
		uint32_t ADCxConvertedVoltage;
/** 
  * @}
  */ 


/**
  * @brief  Inicializacion del ADC
  * @param  Ninguno
  * @retval Ninguno
  */
		
void osThreadADCInit(
	GPIO_TypeDef * GPIOx,               /* Definicion del puerto que se desea configurar */
  uint16_t Pin,                       /* Pin sobre el cual se aplican las configuraciones */
  uint8_t ADC_Channel_x,              /* Canal del ADC que se desea configurar */
	ADC_TypeDef* ADCx,                  /* ADC al que se desea apuntar */                                
  DMA_Stream_TypeDef* DMAy_Streamx,   /* DMA Y Stream donde se guardará la conversion */
	uint32_t DMA_Channel_x 	            /* Canal del DMA donde se ubica el ADC a configurar */ 
  ){
	
	ADC_InitTypeDef       ADC_InitStructure;
  ADC_CommonInitTypeDef ADC_CommonInitStructure;
  DMA_InitTypeDef       DMA_InitStructure;
 
  /* Habilitar relojes de ADC2, DMA2   ****************************************/
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2 , ENABLE);


  /* Configuracion del DMA_x Stream_x canal_x **************************************/
  /* Datos en STM32F4 Reference manual DOC ID 018909 REV1*/
  /* DMA1 / DMA2 request mapping DMAx Stream_x canal_x pag164.*/
		
	if     (ADCx == ADC1){
	                       DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)ADC1_DR_ADDRESS;  
	                       DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)&ADC1ConvertedValue;
	                       RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);}	
  else if(ADCx == ADC2){ 
	                       DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)ADC2_DR_ADDRESS;  
	                       DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)&ADC2ConvertedValue;
	                       RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC2, ENABLE);}
	else if(ADCx == ADC3){
	                       DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)ADC3_DR_ADDRESS; 
                         DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)&ADC3ConvertedValue;
	                       RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE);}
	
  /* Inicializacion de la estructura para el DMA ******************************************/
  DMA_InitStructure.DMA_Channel = DMA_Channel_x;  
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
  DMA_InitStructure.DMA_BufferSize = 4;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;         
  DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;
  DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
  DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
  DMA_Init(DMAy_Streamx, &DMA_InitStructure);
  DMA_Cmd(DMAy_Streamx, ENABLE);

  /* Configura el pin ADC_x Channel_x como entrada analogica ******************************/
	osThreadGPIOInit(GPIOx,Pin,os_AN);

  /* Inicializacion comun del ADC **********************************************************/
  ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
  ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;
  ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
  ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
  ADC_CommonInit(&ADC_CommonInitStructure);

  /* Inicializacion del ADCx ****************************************************************/
  ADC_InitStructure.ADC_Resolution = ADC_Resolution_10b;
  ADC_InitStructure.ADC_ScanConvMode = DISABLE;
  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
  ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfConversion = 1;
  ADC_Init(ADCx, &ADC_InitStructure);

  /* configuracion regular del ADC3 canal 12 *************************************/
  ADC_RegularChannelConfig(ADCx, ADC_Channel_x, 1, ADC_SampleTime_3Cycles);

 /* Habilitar el DMA request despues de la ultima transferencia (Single-ADC mode) */
  ADC_DMARequestAfterLastTransferCmd(ADCx, ENABLE);

  /* Habilitar ADCx DMA */
  ADC_DMACmd(ADCx, ENABLE);

  /* Habilitar ADCx */
  ADC_Cmd(ADCx, ENABLE);
	
	/* Se inicializa la conversion automática del ADC */
  if     (ADCx == ADC1){
	                       ADC_SoftwareStartConv(ADC1);}	
  else if(ADCx == ADC2){ 
	                       ADC_SoftwareStartConv(ADC2);}
	else if(ADCx == ADC3){
	                       ADC_SoftwareStartConv(ADC3);}
}

/**
  * @brief  Inicializacion del ADC
  * @param  Ninguno
  * @retval Ninguno
  */
uint32_t osThreadADCReadADC(uint32_t ADCx){
	uint32_t ADCxConvertedVoltage2,i = 0;
	ADCxConvertedVoltage = 0;
	mainDelay(5000);
	
  for(i=1;i<=1000000;i++){
	  switch(ADCx){
		  case 1: ADCxConvertedVoltage = ADC1ConvertedValue ; 
		  		break;
		  case 2: ADCxConvertedVoltage = ADC2ConvertedValue ;
		  	break;
	  	case 3: ADCxConvertedVoltage = ADC3ConvertedValue;
		  	break;
	  }
		ADCxConvertedVoltage2 = ADCxConvertedVoltage2 + ADCxConvertedVoltage;
  }
	
	 ADCxConvertedVoltage  = ADCxConvertedVoltage2 / 1000000;

	 ADCxConvertedVoltage2 = ADCxConvertedVoltage * 1000;
	
   if((ADCxConvertedVoltage >=1  ) && (ADCxConvertedVoltage <=280)) ADCxConvertedVoltage = (ADCxConvertedVoltage2 /4288);	//1-6 -
	 if((ADCxConvertedVoltage >=281) && (ADCxConvertedVoltage <=330)) ADCxConvertedVoltage = (ADCxConvertedVoltage2 /4190);	//7   
	 if((ADCxConvertedVoltage >=331) && (ADCxConvertedVoltage <=367)) ADCxConvertedVoltage = (ADCxConvertedVoltage2 /4120); //8   -

	 /* Valores para 09V */
	 if((ADCxConvertedVoltage >=367) && (ADCxConvertedVoltage <=368)) ADCxConvertedVoltage =   90; //9.2
	 if((ADCxConvertedVoltage >=369) && (ADCxConvertedVoltage <=370)) ADCxConvertedVoltage =   91; //9.2
	 if((ADCxConvertedVoltage >=371) && (ADCxConvertedVoltage <=377)) ADCxConvertedVoltage =   92; //9.2
	 if((ADCxConvertedVoltage >=376) && (ADCxConvertedVoltage <=377)) ADCxConvertedVoltage =   93; //9.3
	 if((ADCxConvertedVoltage >=378) && (ADCxConvertedVoltage <=381)) ADCxConvertedVoltage =   94; //9.4
	 if((ADCxConvertedVoltage >=382) && (ADCxConvertedVoltage <=383)) ADCxConvertedVoltage =   95; //9.5
	 if((ADCxConvertedVoltage >=384) && (ADCxConvertedVoltage <=386)) ADCxConvertedVoltage =   96; //9.6
	 if((ADCxConvertedVoltage >=387) && (ADCxConvertedVoltage <=390)) ADCxConvertedVoltage =   97; //9.7
	 if((ADCxConvertedVoltage >=390) && (ADCxConvertedVoltage <=392)) ADCxConvertedVoltage =   98; //9.8
	 if((ADCxConvertedVoltage >=393) && (ADCxConvertedVoltage <=396)) ADCxConvertedVoltage =   99; //9.9
	 
	 /* Valores para 10V */
	 if((ADCxConvertedVoltage >=397) && (ADCxConvertedVoltage <=398)) ADCxConvertedVoltage =  100; //10.0
	 if((ADCxConvertedVoltage >=399) && (ADCxConvertedVoltage <=400)) ADCxConvertedVoltage =  101; //10.1
	 if((ADCxConvertedVoltage >=401) && (ADCxConvertedVoltage <=404)) ADCxConvertedVoltage =  102; //10.2
	 if((ADCxConvertedVoltage >=405) && (ADCxConvertedVoltage <=406)) ADCxConvertedVoltage =  103; //10.3
	 if((ADCxConvertedVoltage >=407) && (ADCxConvertedVoltage <=409)) ADCxConvertedVoltage =  104; //10.4
	 if((ADCxConvertedVoltage >=410) && (ADCxConvertedVoltage <=412)) ADCxConvertedVoltage =  105; //10.5
	 if((ADCxConvertedVoltage >=413) && (ADCxConvertedVoltage <=414)) ADCxConvertedVoltage =  106; //10.6
	 if((ADCxConvertedVoltage >=415) && (ADCxConvertedVoltage <=416)) ADCxConvertedVoltage =  107; //10.7
	 if((ADCxConvertedVoltage >=417) && (ADCxConvertedVoltage <=418)) ADCxConvertedVoltage =  108; //10.8
	 if((ADCxConvertedVoltage >=419) && (ADCxConvertedVoltage <=422)) ADCxConvertedVoltage =  109; //10.9
	 
	 /* Valores para 11V */	
	 if((ADCxConvertedVoltage >=423) && (ADCxConvertedVoltage <=424)) ADCxConvertedVoltage =  110; //11.0
	 if((ADCxConvertedVoltage >=425) && (ADCxConvertedVoltage <=426)) ADCxConvertedVoltage =  111; //11.1
	 if((ADCxConvertedVoltage >=427) && (ADCxConvertedVoltage <=428)) ADCxConvertedVoltage =  112; //11.2
	 if((ADCxConvertedVoltage >=429) && (ADCxConvertedVoltage <=430)) ADCxConvertedVoltage =  113; //11.3
	 if((ADCxConvertedVoltage >=431) && (ADCxConvertedVoltage <=432)) ADCxConvertedVoltage =  114; //11.4
	 if((ADCxConvertedVoltage >=433) && (ADCxConvertedVoltage <=436)) ADCxConvertedVoltage =  115; //11.5
	 if((ADCxConvertedVoltage >=437) && (ADCxConvertedVoltage <=438)) ADCxConvertedVoltage =  116; //11.6
	 if((ADCxConvertedVoltage >=439) && (ADCxConvertedVoltage <=440)) ADCxConvertedVoltage =  117; //11.7
	 if((ADCxConvertedVoltage >=441) && (ADCxConvertedVoltage <=442)) ADCxConvertedVoltage =  118; //11.8
	 if((ADCxConvertedVoltage >=443) && (ADCxConvertedVoltage <=444)) ADCxConvertedVoltage =  119; //11.9
	 
	 /* Valores para 12V */
   if((ADCxConvertedVoltage >=445) && (ADCxConvertedVoltage <=446)) ADCxConvertedVoltage =  120; //12.0
   if((ADCxConvertedVoltage >=447) && (ADCxConvertedVoltage <=448)) ADCxConvertedVoltage =  121; //12.1
   if((ADCxConvertedVoltage >=449) && (ADCxConvertedVoltage <=450)) ADCxConvertedVoltage =  122; //12.2
   if((ADCxConvertedVoltage >=451) && (ADCxConvertedVoltage <=452)) ADCxConvertedVoltage =  123; //12.3
	 if((ADCxConvertedVoltage >=453) && (ADCxConvertedVoltage <=454)) ADCxConvertedVoltage =  124; //12.4  
	 if((ADCxConvertedVoltage >=455) && (ADCxConvertedVoltage <=456)) ADCxConvertedVoltage =  125; //12.5 12.5
	 if((ADCxConvertedVoltage >=457) && (ADCxConvertedVoltage <=458)) ADCxConvertedVoltage =  126; //12.6 12.6
	 if((ADCxConvertedVoltage >=459) && (ADCxConvertedVoltage <=460)) ADCxConvertedVoltage =  127; //12.7 12.6
	 if((ADCxConvertedVoltage >=461) && (ADCxConvertedVoltage <=462)) ADCxConvertedVoltage =  128; //12.8
	 if((ADCxConvertedVoltage >=463) && (ADCxConvertedVoltage <=464)) ADCxConvertedVoltage =  129; //12.9
	 
	 /* Valores para 13V */
	 if((ADCxConvertedVoltage >=465) && (ADCxConvertedVoltage <=466)) ADCxConvertedVoltage =  130; //13.0
   if (ADCxConvertedVoltage ==467)                                  ADCxConvertedVoltage =  131; //13.1	 
	 if (ADCxConvertedVoltage ==468)                                  ADCxConvertedVoltage =  132; //13.2	 
	 if((ADCxConvertedVoltage >=469) && (ADCxConvertedVoltage <=470)) ADCxConvertedVoltage =  133; //13.3
	 if((ADCxConvertedVoltage >=471) && (ADCxConvertedVoltage <=472)) ADCxConvertedVoltage =  134; //13.4
	 if((ADCxConvertedVoltage >=473) && (ADCxConvertedVoltage <=474)) ADCxConvertedVoltage =  135; //13.5	 
	 if (ADCxConvertedVoltage ==475)                                  ADCxConvertedVoltage =  136; //13.6
	 if (ADCxConvertedVoltage ==476)                                  ADCxConvertedVoltage =  137; //13.7
	 if((ADCxConvertedVoltage >=477) && (ADCxConvertedVoltage <=478)) ADCxConvertedVoltage =  138; //13.8
	 if((ADCxConvertedVoltage >=479) && (ADCxConvertedVoltage <=480)) ADCxConvertedVoltage =  139; //13.9
	 //if (ADCxConvertedVoltage >=500)                                  ADCxConvertedVoltage =  140; //14.0

return ADCxConvertedVoltage ;	
}	
/******************* (C) COPYRIGHT 2015 EDESIGN *****FIN DE ARCHIVO****/
