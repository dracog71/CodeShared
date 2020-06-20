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
  ADC_InitStructure.ADC_Resolution = ADC_Resolution_8b;
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

	uint32_t ADCxConvertedVoltage = 0;

	switch(ADCx){
	 case 1: ADCxConvertedVoltage = ADC1ConvertedValue ; 
	 		break;
		
	 case 2: ADCxConvertedVoltage = ADC2ConvertedValue ;
	 	break;
		
	case 3: ADCxConvertedVoltage = ADC3ConvertedValue;
	 	break;
	}
	
	ADCxConvertedVoltage = (ADCxConvertedVoltage * 135) / 30464;
	
	/*if (ADCxConvertedVoltage >= 130)
		ADCxConvertedVoltage = 130;*/

return ADCxConvertedVoltage ;	
}	
/******************* (C) COPYRIGHT 2015 EDESIGN *****FIN DE ARCHIVO****/
