/**
  ***********************************************************************************************************
  * @file    osThreadPWM.c
  * @author  EDESIGN TEAM
  * @version V1.3.0         modificado por JMLG para MDK-ARM V5.0
  * @date    12-Febrero-2015
  * @brief   Archivo de control de efectos de sirena
  *                
  *************************************************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2015 EDESIGN</center></h2>
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
	
/* Include------------------------------------------------------------------*/
#include "osThreadEFECTS.h"	

/* Estructura de control del Centro de Carga */
extern TAB_CC_STRUCT TAB_CC1;

	/**
  * @{
  */

/** @brief  EFECTO1
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_Directional_EFECTO_1(){ 
	
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_Directional_Sequence_change(FASE1,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 50:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 100:
			osThreadEFECTS_Directional_Sequence_change(FASE1,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 150:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 200:
			osThreadEFECTS_Directional_Sequence_change(FASE1,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		/* Cambio de señal *************************************/
		
		case 350:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,ACTIVE);
			break;
		
		case 400:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 450:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,ACTIVE);
			break;
		
		case 500:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 550:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,ACTIVE);
			break;
		
		/* Fin de señal *****************************************/
		
		case 700:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 750:
			TAB_CC1.EFECTO_COUNTER = 0;
			break;
		
		default:
			break;
	}
}

/** @brief  EFECTO2
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_Directional_EFECTO_2(){

	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_Directional_Sequence_change(FASE3,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 50:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 100:
			osThreadEFECTS_Directional_Sequence_change(FASE3,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 150:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 200:
			osThreadEFECTS_Directional_Sequence_change(FASE3,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		/* Cambio de señal *************************************/
		
		case 350:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,ACTIVE);
			break;
		
		case 400:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 450:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,ACTIVE);
			break;
		
		case 500:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 550:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,ACTIVE);
			break;
		
		/* Fin de señal *****************************************/
		
		case 700:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 750:
			TAB_CC1.EFECTO_COUNTER = 0;
			break;
		
		default:
			break;
	}
}

/** @brief  EFECTO3
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_Directional_EFECTO_3(){

	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_Directional_Sequence_change(FASE1,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 10:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 20:
			osThreadEFECTS_Directional_Sequence_change(FASE1,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 90:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,ACTIVE);
			break;
		
		case 100:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 110:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,ACTIVE);
			break;
		
		case 180:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 250:
			TAB_CC1.EFECTO_COUNTER = 0;
			break;
		
		default:
			break;
	}
}


/** @brief  EFECTO4
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_Directional_EFECTO_4(){

	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_Directional_Sequence_change(FASE3,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 90:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,ACTIVE);
			break;
		
		case 180:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 270:
			TAB_CC1.EFECTO_COUNTER = 0;
			break;
		
		default:
			break;
	}
}

/** @brief  EFECTO5
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_Directional_EFECTO_5(){

	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_Directional_Sequence_change(FASE1,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 100:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 200:
			osThreadEFECTS_Directional_Sequence_change(FASE1,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 300:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 450:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,ACTIVE);
			break;
		
		case 550:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 650:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,ACTIVE);
			break;
		
		case 750:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 900:
			TAB_CC1.EFECTO_COUNTER = 0;
			break;
		
		default:
			break;
	}
}

/** @brief  EFECTO6
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_Directional_EFECTO_6(){

	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_Directional_Sequence_change(FASE3,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 100:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 200:
			osThreadEFECTS_Directional_Sequence_change(FASE3,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 300:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 450:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,ACTIVE);
			break;
		
		case 550:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 650:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,ACTIVE);
			break;
		
		case 750:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 900:
			TAB_CC1.EFECTO_COUNTER = 0;
			break;
		
		default:
			break;
	}
}

/** @brief  EFECTO7
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_Directional_EFECTO_7(){

	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_Directional_Sequence_change(FASE1,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 50:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 100:
			osThreadEFECTS_Directional_Sequence_change(FASE1,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 450:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 500:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,ACTIVE);
			break;
		
		case 550:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 600:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,ACTIVE);
			break;
		
		case 950:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 1000:
			TAB_CC1.EFECTO_COUNTER = 0;
			break;
		
		default:
			break;
	}
}


/** @brief  EFECTO7
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_Directional_EFECTO_8(){

	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_Directional_Sequence_change(FASE3,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 50:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 100:
			osThreadEFECTS_Directional_Sequence_change(FASE3,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 450:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 500:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,ACTIVE);
			break;
		
		case 550:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 600:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,ACTIVE);
			break;
		
		case 950:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 1000:
			TAB_CC1.EFECTO_COUNTER = 0;
			break;
		
		default:
			break;
	}
}


/** @brief  EFECTO7
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_Directional_EFECTO_9(){

	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_Directional_Sequence_change(FASE1,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,ACTIVE);
			break;
		
		case 100:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 200:
			TAB_CC1.EFECTO_COUNTER = 0;
			break;
		
		default:
			break;
	}
}


/** @brief  EFECTO7
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_Directional_EFECTO_10(){

	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_Directional_Sequence_change(FASE1,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 70:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,ACTIVE);
			break;
		
		case 140:
			osThreadEFECTS_Directional_Sequence_change(FASE1,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 210:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,ACTIVE);
			break;
		
		case 280:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 600:
			TAB_CC1.EFECTO_COUNTER = 0;
			break;
		
		default:
			break;
	}
}


/** @brief  EFECTO7
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_Directional_EFECTO_11(){

	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_Directional_Sequence_change(FASE3,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 70:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,ACTIVE);
			break;
		
		case 140:
			osThreadEFECTS_Directional_Sequence_change(FASE3,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 210:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,ACTIVE);
			break;
		
		case 280:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 600:
			TAB_CC1.EFECTO_COUNTER = 0;
			break;
		
		default:
			break;
	}
}


/** @brief  EFECTO7
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_Directional_EFECTO_12(){

	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_Directional_Sequence_change(FASE3,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,ACTIVE);
			break;
		
		case 50:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 60:
			osThreadEFECTS_Directional_Sequence_change(FASE3,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,ACTIVE);
			break;
		
		case 80:
			osThreadEFECTS_Directional_Sequence_change(FASE3,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE4,NO_ACTIVE);
			break;
		
		case 600:
			TAB_CC1.EFECTO_COUNTER = 0;
			break;
		
		default:
			break;
	}
}

/** @brief  EFECTO7
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_Directional_EFECTO_13(){

	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_Directional_Sequence_change(FASE1,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 10:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 20:
			osThreadEFECTS_Directional_Sequence_change(FASE1,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 30:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 40:
			osThreadEFECTS_Directional_Sequence_change(FASE1,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 50:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 150:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,ACTIVE);
			break;
		
		case 160:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 170:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,ACTIVE);
			break;
		
		case 180:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 190:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,ACTIVE);
			break;
		
		case 200:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 300:
			TAB_CC1.EFECTO_COUNTER = 0;
			break;
		
		default:
			break;
	}
}


/** @brief  EFECTO7
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_Directional_EFECTO_14(){

	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_Directional_Sequence_change(FASE1,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,ACTIVE);
			break;
		
		case 27:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 58:
			osThreadEFECTS_Directional_Sequence_change(FASE1,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,ACTIVE);
			break;
		
		case 80:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 110:
			osThreadEFECTS_Directional_Sequence_change(FASE1,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,ACTIVE);
			break;
		
		case 147:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 163:
			osThreadEFECTS_Directional_Sequence_change(FASE1,ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,ACTIVE);
			break;
		
		case 189:
			osThreadEFECTS_Directional_Sequence_change(FASE1,NO_ACTIVE);
			osThreadEFECTS_Directional_Sequence_change(FASE2,NO_ACTIVE);
			break;
		
		case 220:
			TAB_CC1.EFECTO_COUNTER = 0;
			break;
		
		default:
			break;
	}
}

/********************************************************************************************************/
/*****************************************  EFECTOS 1 ***************************************************/
/********************************************************************************************************/

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_LEFT_1(){
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 35:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 70:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 105:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 140:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 175:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 210:
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 245:
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			break;
		
		case 280:
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			break;
		
		case 315:
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			break;
		
		case 350:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			break;
		
		case 385:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			break;
		
		case 420:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			break;
		
		case 455:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			break;
		
		case 490:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			break;
		
		case 525:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			break;
		
		case 630:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			break;
		
		case 735:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			break;
		
		case 840:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			break;
		
		case 945:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			break;
		
		case 1050:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			break;
		
		case 1155:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			break;
		
		case 1260:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			break;
		
		case 1365:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			break;
		
		case 1470:
			if(TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] == ACTIVE){
		    /* Control obre los efectos del direccionador */
	      TAB_CC1.EFECTO_SELECTED = EFECTO_FINAL;
			}
		  else{
				TAB_CC1.EFECTO_COUNTER = 0;
			}
		  break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_RIGHT_1(){
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			break;
		
		case 35:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			break;
		
		case 70:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			break;
		
		case 105:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			break;
		
		case 140:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			break;
		
		case 175:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			break;
		
		case 210:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			break;
		
		case 245:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			break;
		
		case 280:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 315:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			break;
		
		case 350:
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 385:
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 420:
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 455:
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 490:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 525:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 630:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 735:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 840:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 945:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1050:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1155:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1260:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1365:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1470:
			if(TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] == ACTIVE){
		    /* Control obre los efectos del direccionador */
	      TAB_CC1.EFECTO_SELECTED = EFECTO_FINAL;
			}
		  else{
				TAB_CC1.EFECTO_COUNTER = 0;
			}
		  break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_INTERMITENTES_1(){
	
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 50:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
		  break;
		
		case 100:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 150:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
		  break;
		
		case 200:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 250:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			
	    /* Control de direccionales */
		  GPIO_ResetBits(LED_DIR_IZQ);
		  GPIO_ResetBits(LED_DIR_DER);
		  break;
		
		case 350:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
		  break;
		
		case 400:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
		  break;
		
		case 450:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
		  break;
		
		case 500:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
		  break;
		
		case 550:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
		  break;
		
		case 600:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
		  break;
		
		case 700:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 750:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
		  break;
		
		case 800:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 850:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
		  break;
		
		case 900:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 950:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  50*/
		
		case 1000:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1050:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1100:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 1150:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 1250:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1300:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 1350:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 1400:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1450:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  45*/
		
		case 1495:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1540:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1585:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 1630:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 1675:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1720:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 1765:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 1810:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1855:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  40*/
		
		case 1895:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1935:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1975:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2015:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2055:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2095:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2135:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2175:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2215:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  35*/
		
		case 2250:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2285:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2320:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2355:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2390:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2425:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2460:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2495:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2530:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
      break;
		
		/* Efectos de segunda parte  30*/
		
		case 2560:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2590:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2620:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2650:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2680:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2710:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2740:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2770:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2800:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
				
		/* Efectos de segunda parte  25*/
		
		case 2825:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2850:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2875:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2900:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2925:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2950:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2975:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3000:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3025:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  20*/
		
		case 3045:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3065:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3085:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3105:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3125:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3145:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 3165:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3185:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3205:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  15*/
		
		case 3220:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3235:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3250:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3265:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3280:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3295:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 3310:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3325:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3340:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  10*/
		
		case 3350:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3360:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3370:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3380:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3390:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3400:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 3410:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3420:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3430:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  10*/
		
		case 3440:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3450:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3460:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3470:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3480:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3490:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 3500:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3510:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3520:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Parte final */
		
		case 3570:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 3620:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 3670:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 3720:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 3770:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 3820:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 4000:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 4050:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 4100:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 4150:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 4200:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 4250:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 4500:
		  /* Control obre los efectos del direccionador */
	    TAB_CC1.EFECTO_SELECTED = EFECTO_FINAL;
		break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_STOP_1(){
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 35:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			break;
		
		case 70:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 105:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 140:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 175:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 210:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 245:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 280:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 385:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 490:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 595:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 700:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 805:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 910:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1015:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1120:
			TAB_CC1.EFECTO_COUNTER = 0;
		  break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_STOP_1B(){
	
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 50:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
		  break;
		
		case 100:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 150:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
		  break;
		
		case 200:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 250:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			
	    /* Control de direccionales */
		  GPIO_ResetBits(LED_DIR_IZQ);
		  GPIO_ResetBits(LED_DIR_DER);
		  break;
		
		case 350:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
		  break;
		
		case 400:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
		  break;
		
		case 450:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
		  break;
		
		case 500:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
		  break;
		
		case 550:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
		  break;
		
		case 600:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
		  break;
		
		case 700:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 750:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
		  break;
		
		case 800:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 850:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
		  break;
		
		case 900:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 950:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  50*/
		
		case 1000:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1050:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1100:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 1150:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 1250:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1300:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 1350:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 1400:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1450:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  45*/
		
		case 1495:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1540:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1585:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 1630:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 1675:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1720:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 1765:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 1810:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1855:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  40*/
		
		case 1895:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1935:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1975:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2015:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2055:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2095:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2135:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2175:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2215:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  35*/
		
		case 2250:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2285:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2320:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2355:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2390:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2425:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2460:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2495:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2530:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
      break;
		
		/* Efectos de segunda parte  30*/
		
		case 2560:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2590:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2620:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2650:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2680:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2710:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2740:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2770:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2800:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
				
		/* Efectos de segunda parte  25*/
		
		case 2825:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2850:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2875:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2900:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2925:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2950:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2975:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3000:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3025:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  20*/
		
		case 3045:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3065:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3085:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3105:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3125:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3145:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 3165:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3185:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3205:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  15*/
		
		case 3220:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3235:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3250:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3265:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3280:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3295:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 3310:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3325:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3340:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  10*/
		
		case 3350:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3360:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3370:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3380:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3390:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3400:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 3410:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3420:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3430:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  10*/
		
		case 3440:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3450:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3460:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3470:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3480:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3490:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 3500:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3510:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3520:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Parte final */
		
		case 3570:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 3620:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 3670:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 3720:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 3770:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 3820:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 4000:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 4050:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 4100:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 4150:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 4200:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 4250:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 4500:
		  /* Control obre los efectos del direccionador */
	    TAB_CC1.EFECTO_COUNTER = 0;
		break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_STOP_FLASHER_ON_1(){
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			/* Control obre los efectos del direccionador */
	    TAB_CC1.STOP_CARRIER = TOGGLE;
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 35:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			break;
		
		case 70:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 105:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 140:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 175:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 210:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 245:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 280:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 385:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 490:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 595:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 700:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 805:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 910:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 1120:
			if(TAB_CC1.SAVED_BUFFER[STOP_FLASHER_SEL] == NO_ACTIVE){
				TAB_CC1.EFECTO_COUNTER = 0;
				TAB_CC1.EFECTO_SELECTED = EFECTO_STOP_FLASHER_OFF;
			
	      /* Se detiene el timer */
        TIM_Cmd(TIM4, ENABLE);
	      TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
			  TIM4->CNT = 0; 
			}
			else{
	      /* Se detiene el timer */
        TIM_Cmd(TIM4, DISABLE);
	      TIM_ITConfig(TIM4, TIM_IT_Update, DISABLE);
			  TIM4->CNT = 0; 
	
			  /* Control obre los efectos del direccionador */
	      TAB_CC1.STOP_CARRIER = ACTIVE;
			}
		  break;
		
		default:
			break;
	}	
}


/********************************************************************************************************/
/*****************************************  EFECTOS 2 ***************************************************/
/********************************************************************************************************/

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_LEFT_2(){
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 75:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 150:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 225:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 300:
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			break;
		
		case 375:
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			break;
		
		case 450:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			break;
		
		case 525:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			break;
		
		case 600:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			break;
		
		case 675:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 750:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 825:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 900:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 975:
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			break;
		
		case 1050:
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			break;
		
		case 1125:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			break;
		
		case 1200:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			break;
		
		case 1275:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			break;
		
		case 1350:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			break;
		
		case 1500:
			if(TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] == ACTIVE){
		    /* Control obre los efectos del direccionador */
	      TAB_CC1.EFECTO_SELECTED = EFECTO_FINAL;
			}
		  else{
				TAB_CC1.EFECTO_COUNTER = 0;
			}
		  break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_RIGHT_2(){
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			break;
		
		case 75:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			break;
		
		case 150:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			break;
		
		case 225:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			break;
		
		case 300:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 375:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 450:
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 525:
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 600:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 675:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			break;
		
		case 750:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			break;
		
		case 825:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			break;
		
		case 900:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			break;
		
		case 975:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1050:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 1125:
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 1200:
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1275:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 1350:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1500:
			if(TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] == ACTIVE){
		    /* Control obre los efectos del direccionador */
	      TAB_CC1.EFECTO_SELECTED = EFECTO_FINAL;
			}
		  else{
				TAB_CC1.EFECTO_COUNTER = 0;
			}
		  break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_INTERMITENTES_2(){
	
	switch(TAB_CC1.EFECTO_COUNTER){
		
		/* Efectos de segunda parte  50*/
		
		case 1:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 50:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 100:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 150:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 200:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 250:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 300:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 350:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 400:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  45*/
		
		case 445:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 490:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 535:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 580:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 625:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 670:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 715:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 760:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 805:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  40*/
		
		case 845:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 885:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 925:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 956:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 1005:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1045:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 1085:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 1125:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1165:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  35*/
		
		case 1200:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1235:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1270:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 1305:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 1340:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1375:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 1410:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 1445:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1480:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
      break;
		
		/* Efectos de segunda parte  30*/
		
		case 1510:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1540:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1570:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 1600:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 1630:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1660:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 1690:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 1720:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1750:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
				
		/* Efectos de segunda parte  25*/
		
		case 1775:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1800:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1825:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 1850:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 1875:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1900:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 1925:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 1950:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1975:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  20*/
		
		case 1995:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2015:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2035:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2055:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2075:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2095:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2115:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2135:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2155:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  15*/
		
		case 2170:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2185:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2200:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2215:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2230:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2245:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2260:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2275:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2290:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  10*/
		
		case 2300:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2310:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2320:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2330:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2340:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2350:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2360:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2370:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2380:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  10*/
		
		case 2390:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2400:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2410:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2420:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2430:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2440:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2450:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2460:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2470:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Parte final */
		
		/* Efectos de segunda parte  10*/
		
		case 2480:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2490:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2500:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2510:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2520:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2530:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2540:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2550:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2560:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  10*/
		
		case 2570:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2580:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2590:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2600:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2610:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2620:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2630:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2640:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2650:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  15*/
		
		case 2665:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2680:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2695:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2710:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2725:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2740:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2755:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2770:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2785:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  20*/
		
		case 2805:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2825:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2545:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2865:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2885:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2905:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2925:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2945:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2965:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
      break;
		
		/* Efectos de segunda parte  25*/
		
		case 2990:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3015:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3040:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3065:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3090:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3115:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 3140:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3165:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3190:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
				
		/* Efectos de segunda parte  30*/
		
		case 3220:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3250:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3280:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3310:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3340:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3370:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 3400:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3430:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3460:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  35*/
		
		case 3495:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3530:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3565:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3600:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3635:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3670:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 3705:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3740:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3775:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  40*/
		
		case 3815:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3855:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3895:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3935:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3975:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 4015:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 4055:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 4095:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 4135:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  45*/
		
		case 4180:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 4225:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 4270:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 4315:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 4360:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 4405:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 4450:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 4495:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 4540:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  50*/
		
		case 4590:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 4640:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 4690:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 4740:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 4790:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 4840:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 4890:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 4940:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 4990:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Parte final */
		
		case 5040:
		  /* Control obre los efectos del direccionador */
	    TAB_CC1.EFECTO_SELECTED = EFECTO_FINAL;
		break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_STOP_2(){
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
		  break;
		
		case 150:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
		  break;
		
		case 300:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 450:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
		  break;
		
		case 600:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
		  break;
		
		case 750:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 900:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
		  break;
		
		case 1200:
		  /* Control obre los efectos del direccionador */
		  TAB_CC1.EFECTO_COUNTER = 0;
		break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_STOP_2B(){
	
	switch(TAB_CC1.EFECTO_COUNTER){
		
		/* Efectos de segunda parte  50*/
		
		case 1:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 50:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 100:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 150:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 200:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 250:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 300:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 350:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 400:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  45*/
		
		case 445:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 490:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 535:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 580:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 625:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 670:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 715:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 760:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 805:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  40*/
		
		case 845:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 885:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 925:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 956:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 1005:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1045:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 1085:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 1125:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1165:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  35*/
		
		case 1200:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1235:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1270:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 1305:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 1340:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1375:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 1410:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 1445:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1480:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
      break;
		
		/* Efectos de segunda parte  30*/
		
		case 1510:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1540:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1570:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 1600:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 1630:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1660:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 1690:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 1720:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1750:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
				
		/* Efectos de segunda parte  25*/
		
		case 1775:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1800:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1825:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 1850:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 1875:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1900:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 1925:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 1950:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1975:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  20*/
		
		case 1995:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2015:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2035:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2055:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2075:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2095:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2115:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2135:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2155:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  15*/
		
		case 2170:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2185:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2200:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2215:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2230:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2245:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2260:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2275:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2290:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  10*/
		
		case 2300:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2310:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2320:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2330:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2340:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2350:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2360:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2370:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2380:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  10*/
		
		case 2390:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2400:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2410:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2420:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2430:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2440:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2450:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2460:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2470:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Parte final */
		
		/* Efectos de segunda parte  10*/
		
		case 2480:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2490:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2500:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2510:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2520:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2530:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2540:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2550:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2560:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  10*/
		
		case 2570:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2580:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2590:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2600:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2610:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2620:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2630:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2640:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2650:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  15*/
		
		case 2665:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2680:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2695:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2710:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2725:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2740:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2755:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2770:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2785:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  20*/
		
		case 2805:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2825:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2545:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2865:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2885:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2905:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2925:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2945:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2965:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
      break;
		
		/* Efectos de segunda parte  25*/
		
		case 2990:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3015:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3040:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3065:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3090:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3115:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 3140:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3165:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3190:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
				
		/* Efectos de segunda parte  30*/
		
		case 3220:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3250:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3280:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3310:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3340:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3370:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 3400:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3430:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3460:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  35*/
		
		case 3495:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3530:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3565:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3600:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3635:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3670:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 3705:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3740:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3775:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  40*/
		
		case 3815:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3855:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3895:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3935:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3975:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 4015:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 4055:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 4095:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 4135:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  45*/
		
		case 4180:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 4225:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 4270:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 4315:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 4360:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 4405:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 4450:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 4495:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 4540:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  50*/
		
		case 4590:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 4640:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 4690:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 4740:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 4790:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 4840:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 4890:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 4940:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 4990:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Parte final */
		
		case 5040:
		  /* Control obre los efectos del direccionador */
		  TAB_CC1.EFECTO_COUNTER = 0;
		break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_STOP_FLASHER_ON_2(){
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			
			/* Control obre los efectos del direccionador */
	    TAB_CC1.STOP_CARRIER = TOGGLE;
		
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
		  break;
		
		case 150:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
		  break;
		
		case 300:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 400:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 500:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 600:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 700:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 800:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 1000:			
			if(TAB_CC1.SAVED_BUFFER[STOP_FLASHER_SEL] == NO_ACTIVE){
				TAB_CC1.EFECTO_COUNTER = 0;
				TAB_CC1.EFECTO_SELECTED = EFECTO_STOP_FLASHER_OFF;
			
	      /* Se detiene el timer */
        TIM_Cmd(TIM4, ENABLE);
	      TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
			  TIM4->CNT = 0; 
			}
			else{
	      /* Se detiene el timer */
        TIM_Cmd(TIM4, DISABLE);
	      TIM_ITConfig(TIM4, TIM_IT_Update, DISABLE);
			  TIM4->CNT = 0; 
	
			  /* Control obre los efectos del direccionador */
	      TAB_CC1.STOP_CARRIER = ACTIVE;
			}
		  break;
			
		default:
			break;
	}	
}

/********************************************************************************************************/
/*****************************************  EFECTOS 3 ***************************************************/
/********************************************************************************************************/

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_LEFT_3(){
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 50:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 100:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 150:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 200:
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 250:
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 300:
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 350:
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 400:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 450:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 500:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 550:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 600:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 650:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 700:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 750:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 800:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 850:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 900:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 950:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 1000:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1050:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			break;
		
		case 1100:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			break;
		
		case 1150:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			break;
		
		case 1200:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			break;
		
		case 1250:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			break;
		
		case 1300:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			break;
		
		case 1350:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			break;
		
		case 1400:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			break;
		
		case 1450:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			break;
		
		case 1700:
			if(TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] == ACTIVE){
		    /* Control obre los efectos del direccionador */
	      TAB_CC1.EFECTO_SELECTED = EFECTO_FINAL;
			}
		  else{
				TAB_CC1.EFECTO_COUNTER = 0;
			}
		  break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_RIGHT_3(){
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			break;
		
		case 50:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			break;
		
		case 100:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			break;
		
		case 150:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			break;
		
		case 200:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			break;
		
		case 250:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			break;
		
		case 300:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			break;
		
		case 350:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			break;
		
		case 400:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 450:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			break;
		
		case 500:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 550:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 600:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 650:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 700:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 750:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 800:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 850:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 900:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 950:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1000:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1050:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1100:
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1150:
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1200:
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1250:
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1300:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1350:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1400:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1450:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1700:
			if(TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] == ACTIVE){
		    /* Control obre los efectos del direccionador */
	      TAB_CC1.EFECTO_SELECTED = EFECTO_FINAL;
			}
		  else{
				TAB_CC1.EFECTO_COUNTER = 0;
			}
		  break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_INTERMITENTES_3(){
	
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 50:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
		  break;
		
		case 100:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 150:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
		  break;
		
		case 200:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 250:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			
	    /* Control de direccionales */
		  GPIO_ResetBits(LED_DIR_IZQ);
		  GPIO_ResetBits(LED_DIR_DER);
		  break;
		
		case 350:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
		  break;
		
		case 400:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
		  break;
		
		case 450:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
		  break;
		
		case 500:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
		  break;
		
		case 550:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
		  break;
		
		case 600:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
		  break;
		
		case 700:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 750:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
		  break;
		
		case 800:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 850:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
		  break;
		
		case 900:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 950:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  50*/
		
		case 1000:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1050:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1100:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 1150:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 1250:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1300:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 1350:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 1400:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1450:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  45*/
		
		case 1495:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1540:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1585:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 1630:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 1675:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1720:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 1765:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 1810:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1855:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  40*/
		
		case 1895:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1935:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1975:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2015:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2055:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2095:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2135:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2175:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2215:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  35*/
		
		case 2250:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2285:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2320:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2355:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2390:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2425:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2460:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2495:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2530:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
      break;
		
		/* Efectos de segunda parte  30*/
		
		case 2560:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2590:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2620:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2650:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2680:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2710:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2740:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2770:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2800:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
				
		/* Efectos de segunda parte  25*/
		
		case 2825:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2850:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2875:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2900:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2925:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2950:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2975:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3000:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3025:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  20*/
		
		case 3045:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3065:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3085:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3105:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3125:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3145:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 3165:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3185:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3205:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  15*/
		
		case 3220:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3235:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3250:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3265:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3280:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3295:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 3310:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3325:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3340:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  10*/
		
		case 3350:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3360:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3370:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3380:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3390:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3400:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 3410:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3420:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3430:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  10*/
		
		case 3440:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3450:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3460:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3470:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3480:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3490:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 3500:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3510:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3520:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Parte final */
		
		case 3570:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 3620:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 3670:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 3720:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 3770:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 3820:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 4000:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 4050:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 4100:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 4150:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 4200:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 4250:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 4500:
		  /* Control obre los efectos del direccionador */
	    TAB_CC1.EFECTO_SELECTED = EFECTO_FINAL;
		break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_STOP_3(){
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 100:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			break;
		
		case 200:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 300:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			break;
		
		case 400:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 500:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 600:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 700:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 800:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 900:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1000:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1100:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1200:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1300:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1400:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1500:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1800:
		  /* Control obre los efectos del direccionador */
		  TAB_CC1.EFECTO_COUNTER = 0;
		break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_STOP_3B(){
	
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 50:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
		  break;
		
		case 100:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 150:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
		  break;
		
		case 200:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 250:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			
	    /* Control de direccionales */
		  GPIO_ResetBits(LED_DIR_IZQ);
		  GPIO_ResetBits(LED_DIR_DER);
		  break;
		
		case 350:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
		  break;
		
		case 400:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
		  break;
		
		case 450:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
		  break;
		
		case 500:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
		  break;
		
		case 550:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
		  break;
		
		case 600:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
		  break;
		
		case 700:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 750:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
		  break;
		
		case 800:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 850:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
		  break;
		
		case 900:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
		  break;
		
		case 950:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  50*/
		
		case 1000:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1050:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1100:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 1150:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 1250:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1300:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 1350:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 1400:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1450:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  45*/
		
		case 1495:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1540:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1585:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 1630:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 1675:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1720:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 1765:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 1810:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 1855:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  40*/
		
		case 1895:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 1935:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1975:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2015:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2055:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2095:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2135:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2175:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2215:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  35*/
		
		case 2250:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2285:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2320:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2355:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2390:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2425:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2460:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2495:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2530:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
      break;
		
		/* Efectos de segunda parte  30*/
		
		case 2560:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2590:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2620:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2650:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2680:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2710:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2740:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 2770:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2800:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
				
		/* Efectos de segunda parte  25*/
		
		case 2825:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 2850:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 2875:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 2900:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 2925:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 2950:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 2975:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3000:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3025:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Efectos de segunda parte  20*/
		
		case 3045:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3065:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3085:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3105:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3125:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3145:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 3165:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3185:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3205:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  15*/
		
		case 3220:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3235:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3250:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3265:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3280:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3295:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 3310:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3325:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3340:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  10*/
		
		case 3350:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3360:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3370:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3380:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3390:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3400:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 3410:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3420:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3430:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		
		/* Efectos de segunda parte  10*/
		
		case 3440:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 3450:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 3460:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 3470:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 3480:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3490:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 3500:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 3510:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 3520:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
		  break;
		
		/* Parte final */
		
		case 3570:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 3620:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 3670:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 3720:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 3770:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 3820:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 4000:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 4050:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 4100:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 4150:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 4200:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 4250:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 4500:
		  /* Control obre los efectos del direccionador */
		  TAB_CC1.EFECTO_COUNTER = 0;
		break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_STOP_FLASHER_ON_3(){
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			/* Control obre los efectos del direccionador */
	    TAB_CC1.STOP_CARRIER = TOGGLE;
		
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 100:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			break;
		
		case 200:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 300:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			break;
		
		case 400:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 500:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 600:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 700:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 800:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 900:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 1000:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 1100:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 1300:			
			if(TAB_CC1.SAVED_BUFFER[STOP_FLASHER_SEL] == NO_ACTIVE){
				TAB_CC1.EFECTO_COUNTER = 0;
				TAB_CC1.EFECTO_SELECTED = EFECTO_STOP_FLASHER_OFF;
			
	      /* Se detiene el timer */
        TIM_Cmd(TIM4, ENABLE);
	      TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
			  TIM4->CNT = 0; 
			}
			else{
	      /* Se detiene el timer */
        TIM_Cmd(TIM4, DISABLE);
	      TIM_ITConfig(TIM4, TIM_IT_Update, DISABLE);
			  TIM4->CNT = 0; 
	
			  /* Control obre los efectos del direccionador */
	      TAB_CC1.STOP_CARRIER = ACTIVE;
			}
		  break;
			
		default:
			break;
	}	
}

/********************************************************************************************************/
/*****************************************  EFECTOS 4 ***************************************************/
/********************************************************************************************************/

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_LEFT_4(){
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 25:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 50:
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 75:
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 100:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			break;
		
		case 125:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			break;
		
		case 150:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			break;
		
		case 175:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			break;
		
		case 200:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 225:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 250:
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 275:
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			break;
		
		case 300:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			break;
		
		case 325:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			break;
		
		case 350:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			break;
		
		case 375:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			break;
		
		case 475:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 500:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 525:
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 550:
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 575:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			break;
		
		case 600:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			break;
		
		case 625:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			break;
		
		case 650:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			break;
		
		case 675:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 700:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 725:
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 750:
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			break;
		
		case 775:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			break;
		
		case 800:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			break;
		
		case 825:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			break;
		
		case 850:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			break;
		
		case 1200:
			if(TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] == ACTIVE){
		    /* Control obre los efectos del direccionador */
	      TAB_CC1.EFECTO_SELECTED = EFECTO_FINAL;
			}
		  else{
				TAB_CC1.EFECTO_COUNTER = 0;
			}
		  break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_RIGHT_4(){
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			break;
		
		case 25:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			break;
		
		case 50:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			break;
		
		case 75:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			break;
		
		case 100:
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 125:
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 150:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 175:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 200:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			break;
		
		case 225:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			break;
		
		case 250:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			break;
		
		case 275:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			break;
		
		case 300:
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			break;
		
		case 325:
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 350:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 375:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 475:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			break;
		
		case 500:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			break;
		
		case 525:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			break;
		
		case 550:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			break;
		
		case 575:
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 600:
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			break;
		
		case 625:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 650:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 675:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			break;
		
		case 700:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			break;
		
		case 725:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			break;
		
		case 750:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			break;
		
		case 775:
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			break;
		
		case 800:
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 825:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 850:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1200:
			if(TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] == ACTIVE){
		    /* Control obre los efectos del direccionador */
	      TAB_CC1.EFECTO_SELECTED = EFECTO_FINAL;
			}
		  else{
				TAB_CC1.EFECTO_COUNTER = 0;
			}
		  break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_INTERMITENTES_4(){
	
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			break;
		
		case 10:
		  /* Control obre los efectos del direccionador */
	    TAB_CC1.EFECTO_SELECTED = EFECTO_FINAL;
		break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_STOP_4(){
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 75:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 150:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 225:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 300:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 450:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 525:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
	
		case 600:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 675:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 750:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 1100:
		  /* Control obre los efectos del direccionador */
		  TAB_CC1.EFECTO_COUNTER = 0;
		break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_STOP_4B(){
	
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
		break;
		
		case 10:
		  /* Control obre los efectos del direccionador */
		  TAB_CC1.EFECTO_COUNTER = 0;
		break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_STOP_FLASHER_ON_4(){
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			/* Control obre los efectos del direccionador */
	    TAB_CC1.STOP_CARRIER = TOGGLE;
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,ACTIVE);
			break;
		
		case 75:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,ACTIVE);
			break;
		
		case 150:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,ACTIVE);
			break;
		
		case 225:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 300:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 400:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 500:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 600:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 700:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			break;
		
		case 800:
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,ACTIVE);
			break;
		
		case 900:			
			if(TAB_CC1.SAVED_BUFFER[STOP_FLASHER_SEL] == NO_ACTIVE){
				TAB_CC1.EFECTO_COUNTER = 0;
				TAB_CC1.EFECTO_SELECTED = EFECTO_STOP_FLASHER_OFF;
			
	      /* Se detiene el timer */
        TIM_Cmd(TIM4, ENABLE);
	      TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
			  TIM4->CNT = 0; 
			}
			else{
	      /* Se detiene el timer */
        TIM_Cmd(TIM4, DISABLE);
	      TIM_ITConfig(TIM4, TIM_IT_Update, DISABLE);
			  TIM4->CNT = 0; 
	
			  /* Control obre los efectos del direccionador */
	      TAB_CC1.STOP_CARRIER = ACTIVE;
			}
		  break;
			
		default:
			break;
	}	
}

/********************************************************************************************************/
/*****************************************  EFECTOS 5 ***************************************************/
/********************************************************************************************************/

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_LEFT_5(){
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			break;
		
		case 10:
			if(TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] == ACTIVE){
		    /* Control obre los efectos del direccionador */
	      TAB_CC1.EFECTO_SELECTED = EFECTO_FINAL;
			}
		  else{
				TAB_CC1.EFECTO_COUNTER = 0;
			}
		  break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_RIGHT_5(){
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			break;
		
		case 1365:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 10:
			if(TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] == ACTIVE){
		    /* Control obre los efectos del direccionador */
	      TAB_CC1.EFECTO_SELECTED = EFECTO_FINAL;
			}
		  else{
				TAB_CC1.EFECTO_COUNTER = 0;
			}
		  break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_INTERMITENTES_5(){
	
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			break;
		
		case 10:
		  /* Control obre los efectos del direccionador */
	    TAB_CC1.EFECTO_SELECTED = EFECTO_FINAL;
		break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_STOP_5(){
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
		  break;
		
		case 10:
		  /* Control obre los efectos del direccionador */
		  TAB_CC1.EFECTO_COUNTER = 0;
		break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_STOP_5B(){
	
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
		break;
		
		case 10:
		  /* Control obre los efectos del direccionador */
		  TAB_CC1.EFECTO_COUNTER = 0;
		break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_STOP_FLASHER_ON_5(){
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
		  break;
		
		case 10:			
			if(TAB_CC1.SAVED_BUFFER[STOP_FLASHER_SEL] == NO_ACTIVE){
				TAB_CC1.EFECTO_COUNTER = 0;
				TAB_CC1.EFECTO_SELECTED = EFECTO_STOP_FLASHER_OFF;
			
	      /* Se detiene el timer */
        TIM_Cmd(TIM4, ENABLE);
	      TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
			  TIM4->CNT = 0; 
			}
			else{
	      /* Se detiene el timer */
        TIM_Cmd(TIM4, DISABLE);
	      TIM_ITConfig(TIM4, TIM_IT_Update, DISABLE);
			  TIM4->CNT = 0; 
	
			  /* Control obre los efectos del direccionador */
	      TAB_CC1.STOP_CARRIER = ACTIVE;
			}
		  break;
			
		default:
			break;
	}	
}

/**********************************************************************************************************************/
/**********************************    FINAL DE EFECTOS    ************************************************************/
/**********************************************************************************************************************/

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_EFECTO_STOP_FLASHER_OFF(){
	switch(TAB_CC1.EFECTO_COUNTER){
		
		case 1:
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,NO_ACTIVE);
			break;
		
		case 35:
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,NO_ACTIVE);
			break;
		
		case 70:
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,NO_ACTIVE);
			break;
		
		case 105:
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,NO_ACTIVE);
			break;
		
		case 140:
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,NO_ACTIVE);
			break;
		
		case 175:
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,NO_ACTIVE);
			break;
		
		case 210:
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,NO_ACTIVE);
			break;
		
		case 245:
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,NO_ACTIVE);
			break;
		
		case 280:
			/*Control obre los efectos del direccionador */
	    TAB_CC1.EFECTO_SELECTED = EFECTO_FINAL;
	
	    TAB_CC1.STOP_CARRIER = NO_ACTIVE;
	    TAB_CC1.FLASHER_CARRIER = NO_ACTIVE;
			break;
	
		default:
			break;
	}
}

/** @brief  Selector de efectos del direccionador por direccionales
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_DIRECTIONAL_EFFECTS_SELECTOR(){
	
	switch(TAB_CC1.DIRECCIONAL_EFFECT){
		case DIRECCIONAL_EFFECT_1:
			
		  switch(TAB_CC1.EFECTO_SELECTED){
				
		    case EFECTO_MANUAL_LEFT_FLASHER:
			    osThreadEFECTS_EFECTO_LEFT_1();
			    break;
		
		    case EFECTO_MANUAL_RIGHT_FLASHER:
			    osThreadEFECTS_EFECTO_RIGHT_1();
			    break;
		
		    case EFECTO_MANUAL_STOP_FLASHER:
			    osThreadEFECTS_EFECTO_STOP_1();
			    break;
		
		    case EFECTO_LEFT_FLASHER:
			    osThreadEFECTS_EFECTO_LEFT_1();
			    break;
	
		    case EFECTO_STOP_FLASHER_ON:
			    osThreadEFECTS_EFECTO_STOP_FLASHER_ON_1();
			    break; 
		
		    case EFECTO_RIGHT_FLASHER:
		  	  osThreadEFECTS_EFECTO_RIGHT_1();
			    break;
		
		    case EFECTO_INTERMITENTES_FLASHER:
			    osThreadEFECTS_EFECTO_INTERMITENTES_1();
			    break;
				
				default:
					break;
			}
			break;
		
		case DIRECCIONAL_EFFECT_1B:
			
		  switch(TAB_CC1.EFECTO_SELECTED){
				
		    case EFECTO_MANUAL_LEFT_FLASHER:
			    osThreadEFECTS_EFECTO_LEFT_1();
			    break;
		
		    case EFECTO_MANUAL_RIGHT_FLASHER:
			    osThreadEFECTS_EFECTO_RIGHT_1();
			    break;
		
		    case EFECTO_MANUAL_STOP_FLASHER:
			    osThreadEFECTS_EFECTO_STOP_1B();
			    break;
		
		    case EFECTO_LEFT_FLASHER:
			    osThreadEFECTS_EFECTO_LEFT_1();
			    break;
		
		    case EFECTO_RIGHT_FLASHER:
		  	  osThreadEFECTS_EFECTO_RIGHT_1();
			    break;
	
		    case EFECTO_STOP_FLASHER_ON:
			    osThreadEFECTS_EFECTO_STOP_FLASHER_ON_1();
			    break; 
		
		    case EFECTO_INTERMITENTES_FLASHER:
			    osThreadEFECTS_EFECTO_INTERMITENTES_1();
			    break;
				
				default:
					break;
			}
			break;
			
		case DIRECCIONAL_EFFECT_2:
			
		  switch(TAB_CC1.EFECTO_SELECTED){
				
		    case EFECTO_MANUAL_LEFT_FLASHER:
			    osThreadEFECTS_EFECTO_LEFT_2();
			    break;
		
		    case EFECTO_MANUAL_RIGHT_FLASHER:
			    osThreadEFECTS_EFECTO_RIGHT_2();
			    break;
		
		    case EFECTO_MANUAL_STOP_FLASHER:
			    osThreadEFECTS_EFECTO_STOP_2();
			    break;
		
		    case EFECTO_LEFT_FLASHER:
			    osThreadEFECTS_EFECTO_LEFT_2();
			    break;
	
		    case EFECTO_STOP_FLASHER_ON:
			    osThreadEFECTS_EFECTO_STOP_FLASHER_ON_2();
			    break; 
		
		    case EFECTO_RIGHT_FLASHER:
		  	  osThreadEFECTS_EFECTO_RIGHT_2();
			    break;
		
		    case EFECTO_INTERMITENTES_FLASHER:
			    osThreadEFECTS_EFECTO_INTERMITENTES_2();
			    break;
				
				default:
					break;
			}
			break;
		
		case DIRECCIONAL_EFFECT_2B:
			
		  switch(TAB_CC1.EFECTO_SELECTED){
				
		    case EFECTO_MANUAL_LEFT_FLASHER:
			    osThreadEFECTS_EFECTO_LEFT_2();
			    break;
		
		    case EFECTO_MANUAL_RIGHT_FLASHER:
			    osThreadEFECTS_EFECTO_RIGHT_2();
			    break;
		
		    case EFECTO_MANUAL_STOP_FLASHER:
			    osThreadEFECTS_EFECTO_STOP_2B();
			    break;
		
		    case EFECTO_LEFT_FLASHER:
			    osThreadEFECTS_EFECTO_LEFT_2();
			    break;
		
		    case EFECTO_RIGHT_FLASHER:
		  	  osThreadEFECTS_EFECTO_RIGHT_2();
			    break;
	
		    case EFECTO_STOP_FLASHER_ON:
			    osThreadEFECTS_EFECTO_STOP_FLASHER_ON_2();
			    break; 
		
		    case EFECTO_INTERMITENTES_FLASHER:
			    osThreadEFECTS_EFECTO_INTERMITENTES_2();
			    break;
				
				default:
					break;
			}
			break;
			
		case DIRECCIONAL_EFFECT_3:
			
		  switch(TAB_CC1.EFECTO_SELECTED){
				
		    case EFECTO_MANUAL_LEFT_FLASHER:
			    osThreadEFECTS_EFECTO_LEFT_3();
			    break;
		
		    case EFECTO_MANUAL_RIGHT_FLASHER:
			    osThreadEFECTS_EFECTO_RIGHT_3();
			    break;
		
		    case EFECTO_MANUAL_STOP_FLASHER:
			    osThreadEFECTS_EFECTO_STOP_3();
			    break;
		
		    case EFECTO_LEFT_FLASHER:
			    osThreadEFECTS_EFECTO_LEFT_3();
			    break;
	
		    case EFECTO_STOP_FLASHER_ON:
			    osThreadEFECTS_EFECTO_STOP_FLASHER_ON_3();
			    break; 
		
		    case EFECTO_RIGHT_FLASHER:
		  	  osThreadEFECTS_EFECTO_RIGHT_3();
			    break;
		
		    case EFECTO_INTERMITENTES_FLASHER:
			    osThreadEFECTS_EFECTO_INTERMITENTES_3();
			    break;
				
				default:
					break;
			}
			break;
		
		case DIRECCIONAL_EFFECT_3B:
			
		  switch(TAB_CC1.EFECTO_SELECTED){
				
		    case EFECTO_MANUAL_LEFT_FLASHER:
			    osThreadEFECTS_EFECTO_LEFT_3();
			    break;
		
		    case EFECTO_MANUAL_RIGHT_FLASHER:
			    osThreadEFECTS_EFECTO_RIGHT_3();
			    break;
		
		    case EFECTO_MANUAL_STOP_FLASHER:
			    osThreadEFECTS_EFECTO_STOP_3B();
			    break;
		
		    case EFECTO_LEFT_FLASHER:
			    osThreadEFECTS_EFECTO_LEFT_3();
			    break;
		
		    case EFECTO_RIGHT_FLASHER:
		  	  osThreadEFECTS_EFECTO_RIGHT_3();
			    break;
	
		    case EFECTO_STOP_FLASHER_ON:
			    osThreadEFECTS_EFECTO_STOP_FLASHER_ON_3();
			    break; 
		
		    case EFECTO_INTERMITENTES_FLASHER:
			    osThreadEFECTS_EFECTO_INTERMITENTES_3();
			    break;
				
				default:
					break;
			}
			break;
			
		case DIRECCIONAL_EFFECT_4:
			
		  switch(TAB_CC1.EFECTO_SELECTED){
				
		    case EFECTO_MANUAL_LEFT_FLASHER:
			    osThreadEFECTS_EFECTO_LEFT_4();
			    break;
		
		    case EFECTO_MANUAL_RIGHT_FLASHER:
			    osThreadEFECTS_EFECTO_RIGHT_4();
			    break;
		
		    case EFECTO_MANUAL_STOP_FLASHER:
			    osThreadEFECTS_EFECTO_STOP_4();
			    break;
		
		    case EFECTO_LEFT_FLASHER:
			    osThreadEFECTS_EFECTO_LEFT_4();
			    break;
	
		    case EFECTO_STOP_FLASHER_ON:
			    osThreadEFECTS_EFECTO_STOP_FLASHER_ON_4();
			    break; 
		
		    case EFECTO_RIGHT_FLASHER:
		  	  osThreadEFECTS_EFECTO_RIGHT_4();
			    break;
		
		    case EFECTO_INTERMITENTES_FLASHER:
			    osThreadEFECTS_EFECTO_INTERMITENTES_3();
			    break;
				
				default:
					break;
			}
			break;
		
		case DIRECCIONAL_EFFECT_4B:
			
		  switch(TAB_CC1.EFECTO_SELECTED){
				
		    case EFECTO_MANUAL_LEFT_FLASHER:
			    osThreadEFECTS_EFECTO_LEFT_4();
			    break;
		
		    case EFECTO_MANUAL_RIGHT_FLASHER:
			    osThreadEFECTS_EFECTO_RIGHT_4();
			    break;
		
		    case EFECTO_MANUAL_STOP_FLASHER:
			    osThreadEFECTS_EFECTO_STOP_3B();
			    break;
		
		    case EFECTO_LEFT_FLASHER:
			    osThreadEFECTS_EFECTO_LEFT_4();
			    break;
		
		    case EFECTO_RIGHT_FLASHER:
		  	  osThreadEFECTS_EFECTO_RIGHT_4();
			    break;
	
		    case EFECTO_STOP_FLASHER_ON:
			    osThreadEFECTS_EFECTO_STOP_FLASHER_ON_4();
			    break; 
		
		    case EFECTO_INTERMITENTES_FLASHER:
			    osThreadEFECTS_EFECTO_INTERMITENTES_3();
			    break;
				
				default:
					break;
			}
			break;
		
		case DIRECCIONAL_EFFECT_FINAL:
			/* Se regresa al  efecto inicial */
			TAB_CC1.DIRECCIONAL_EFFECT = DIRECCIONAL_EFFECT_1;
			break;
		
		default:
			break;
	}
}

/** @brief  Control de cambio de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_Directional_Sequence_change(uint32_t FASE, uint32_t STATE){
	
	switch(FASE){
		case FASE1:
			/* Desactivacion de leds */
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,STATE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,STATE);
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,STATE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,STATE);
			break;
		
		case FASE2:
			/* Desactivacion de leds */
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,STATE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,STATE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,STATE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,STATE);
			break;
		
			
		case FASE3:
			/* Desactivacion de leds */
			osThreadEFECTS_LED_CONTROL(LED_2_SEL,STATE);
			osThreadEFECTS_LED_CONTROL(LED_3_SEL,STATE);
			osThreadEFECTS_LED_CONTROL(LED_8_SEL,STATE);
			osThreadEFECTS_LED_CONTROL(LED_9_SEL,STATE);
			break;
		
		case FASE4:
				
		  /* Desactivacion de leds */
			osThreadEFECTS_LED_CONTROL(LED_4_SEL,STATE);
			osThreadEFECTS_LED_CONTROL(LED_5_SEL,STATE);
			osThreadEFECTS_LED_CONTROL(LED_6_SEL,STATE);
			osThreadEFECTS_LED_CONTROL(LED_7_SEL,STATE);
			
		default:
			break;
	}
	
}

/** @brief  Control de los estados de leds de salida al direccionador
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadEFECTS_LED_CONTROL(uint32_t LED, uint32_t STATE){
	
	/* Select del LED a controlar */
	switch(LED){
		
		case LED_2_SEL:
			if (STATE == ACTIVE) {
				//GPIO_SetBits(DIR2);
				TAB_CC1.PWM_BUFFER[2] = ACTIVE;
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,LED_2_SEL,ACTIVE,0,0,0,0,0);
			}
      else{
	      GPIO_ResetBits(DIR2);
				TAB_CC1.PWM_BUFFER[2] = NO_ACTIVE;
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,LED_2_SEL,NO_ACTIVE,0,0,0,0,0);
			}
			break;
		
		case LED_3_SEL:
			if (STATE == ACTIVE) {
				//GPIO_SetBits(DIR3);
				TAB_CC1.PWM_BUFFER[3] = ACTIVE;
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,LED_3_SEL,ACTIVE,0,0,0,0,0);
			}
      else{
	      GPIO_ResetBits(DIR3);
				TAB_CC1.PWM_BUFFER[3] = NO_ACTIVE;
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,LED_3_SEL,NO_ACTIVE,0,0,0,0,0);
			}
			break;
		
		case LED_4_SEL:
			if (STATE == ACTIVE) {
				//GPIO_SetBits(DIR4);
				TAB_CC1.PWM_BUFFER[4] = ACTIVE;
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,LED_4_SEL,ACTIVE,0,0,0,0,0);
			}
      else{
	      GPIO_ResetBits(DIR4);
				TAB_CC1.PWM_BUFFER[4] = NO_ACTIVE;
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,LED_4_SEL,NO_ACTIVE,0,0,0,0,0);
			}
			break;
		
		case LED_5_SEL:
			if (STATE == ACTIVE) {
				//GPIO_SetBits(DIR5);
				TAB_CC1.PWM_BUFFER[5] = ACTIVE;
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,LED_5_SEL,ACTIVE,0,0,0,0,0);
			}
      else{
	      GPIO_ResetBits(DIR5);
				TAB_CC1.PWM_BUFFER[5] = NO_ACTIVE;
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,LED_5_SEL,NO_ACTIVE,0,0,0,0,0);
			}
			break;
		
		case LED_6_SEL:
			if (STATE == ACTIVE) {
				//GPIO_SetBits(DIR6);
				TAB_CC1.PWM_BUFFER[6] = ACTIVE;
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,LED_6_SEL,ACTIVE,0,0,0,0,0);
			}
      else{
	      GPIO_ResetBits(DIR6);
				TAB_CC1.PWM_BUFFER[6] = NO_ACTIVE;
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,LED_6_SEL,NO_ACTIVE,0,0,0,0,0);
			}
			break;
		
		case LED_7_SEL:
			if (STATE == ACTIVE) {
				//GPIO_SetBits(DIR7);
				TAB_CC1.PWM_BUFFER[7] = ACTIVE;
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,LED_7_SEL,ACTIVE,0,0,0,0,0);
			}
      else{
	      GPIO_ResetBits(DIR7);
				TAB_CC1.PWM_BUFFER[7] = NO_ACTIVE;
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,LED_7_SEL,NO_ACTIVE,0,0,0,0,0);
			}
			break;
		
		case LED_8_SEL:
			if (STATE == ACTIVE) {
				//GPIO_SetBits(DIR8);
				TAB_CC1.PWM_BUFFER[8] = ACTIVE;
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,LED_8_SEL,ACTIVE,0,0,0,0,0);
			}
      else{
	      GPIO_ResetBits(DIR8);
				TAB_CC1.PWM_BUFFER[8] = NO_ACTIVE;
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,LED_8_SEL,NO_ACTIVE,0,0,0,0,0);
			}
			break;
		
		case LED_9_SEL:
			if (STATE == ACTIVE) {
				//GPIO_SetBits(DIR9);
				TAB_CC1.PWM_BUFFER[9] = ACTIVE;
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,LED_9_SEL,ACTIVE,0,0,0,0,0);
			}
      else{
	      GPIO_ResetBits(DIR9);
				TAB_CC1.PWM_BUFFER[9] = NO_ACTIVE;
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,LED_9_SEL,NO_ACTIVE,0,0,0,0,0);
			}
			break;
		
		case ALL_LED_SEL:
			if(STATE == ACTIVE){
				
				/* Control del PWM */
				TAB_CC1.PWM_BUFFER[2] = ACTIVE;
				TAB_CC1.PWM_BUFFER[3] = ACTIVE;
				TAB_CC1.PWM_BUFFER[4] = ACTIVE;
				TAB_CC1.PWM_BUFFER[5] = ACTIVE;
				TAB_CC1.PWM_BUFFER[6] = ACTIVE;
				TAB_CC1.PWM_BUFFER[7] = ACTIVE;
				TAB_CC1.PWM_BUFFER[8] = ACTIVE;
				TAB_CC1.PWM_BUFFER[9] = ACTIVE;
				
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ALL_LED_SEL,ACTIVE,0,0,0,0,0);
			}
			if(STATE == NO_ACTIVE){
				GPIO_ResetBits(DIR2);
				GPIO_ResetBits(DIR3);
				GPIO_ResetBits(DIR4);
				GPIO_ResetBits(DIR5);
				GPIO_ResetBits(DIR6);
				GPIO_ResetBits(DIR7);
				GPIO_ResetBits(DIR8);
				GPIO_ResetBits(DIR9);
				
				/* Control del PWM */
				TAB_CC1.PWM_BUFFER[2] = NO_ACTIVE;
				TAB_CC1.PWM_BUFFER[3] = NO_ACTIVE;
				TAB_CC1.PWM_BUFFER[4] = NO_ACTIVE;
				TAB_CC1.PWM_BUFFER[5] = NO_ACTIVE;
				TAB_CC1.PWM_BUFFER[6] = NO_ACTIVE;
				TAB_CC1.PWM_BUFFER[7] = NO_ACTIVE;
				TAB_CC1.PWM_BUFFER[8] = NO_ACTIVE;
				TAB_CC1.PWM_BUFFER[9] = NO_ACTIVE;
				
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ALL_LED_SEL,NO_ACTIVE,0,0,0,0,0);
			}
			break;
		
		default:
			break;
	}
}

/**
  * @}
  */
/******************* (C) COPYRIGHT 2015 EDESIGN *****FIN DE ARCHIVO****/
