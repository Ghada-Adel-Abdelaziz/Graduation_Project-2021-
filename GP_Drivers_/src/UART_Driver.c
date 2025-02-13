/*
 * UART_Driver.c
 *
 *  Created on: Dec 30, 2020
 *      Author: Ghada & Toaa
 */



#include "UART_Driver.h"



/************************************************************ NEW ************************************/
USART_RegDef_t *UART_Arr[NUM_OF_GPIO] = {USART1,USART2,USART3,USART4,USART5,USART6};
/*****************************************************************************************************/




//void USART_PeripheralControl(USART_RegDef_t *pUSARTx, uint8_t Cmd)
void USART_PeripheralControl(uint8_t UART_num, uint8_t Cmd)
{

	USART_RegDef_t *pUSARTx = UART_Arr[UART_num];       // new

	switch(Cmd) 
	{
	    case ENABLE :
	
		pUSARTx->USART_CR1 |= (1 << USART_CR1_UE);
		break;

		case DISABLE:
	
		pUSARTx->USART_CR1 &= ~(1 << USART_CR1_UE);
		break;

	}

}


//void USART_PeriClockControl(USART_RegDef_t *pUSARTx, uint8_t EnorDi)
static void USART_PeriClockControl(uint8_t UART_num, uint8_t EnorDi)
{
	switch (EnorDi)
	{
		case ENABLE:

		for(char i=0; i<NUM_OF_UART; i++)          //new
		{
			if(i == UART_num)
			{
				USART_PCLK_EN |= (1 << UART_num);
			}
			break;
		}
		break;

		case DISABLE:

		for(char i=0; i<NUM_OF_UART; i++)          //new
		{
			if(i == UART_num)
			{
				USART_PCLK_EN &= ~(1 << UART_num);
			}
			break;
		}
		break;
	}
}

//	if(EnorDi == ENABLE)
//	{
//		if(pUSARTx == USART1)
//		{
//			USART1_PCLK_EN;
//		}
//		else if(pUSARTx == USART2)
//		{
//			USART2_PCLK_EN;
//		}
//		else if(pUSARTx == USART3)
//		{
//			USART3_PCLK_EN;
//		}
//		else if(pUSARTx == USART4)
//		{
//			USART4_PCLK_EN;
//		}
//		else if(pUSARTx == USART5)
//		{
//			USART5_PCLK_EN;
//		}
//		else if(pUSARTx == USART6)
//		{
//			USART6_PCLK_EN;
//		}
//
//
//	}
//	else
//	{
//		if(pUSARTx == USART1)
//		{
//			USART1_PCLK_DI;
//		}
//		else if(pUSARTx == USART2)
//		{
//			USART2_PCLK_DI;
//		}
//		else if(pUSARTx == USART3)
//		{
//			USART3_PCLK_DI;
//		}
//		else if(pUSARTx == USART4)
//		{
//			USART4_PCLK_DI;
//		}
//		else if(pUSARTx == USART5)
//		{
//			USART5_PCLK_DI;
//		}
//		else if(pUSARTx == USART6)
//		{
//			USART6_PCLK_DI;
//		}
//
//
//	}


/*Get flag status function */

//uint8_t USART_GetFlagStatus(USART_RegDef_t *pUSARTx , uint32_t FlagName)
uint8_t USART_GetFlagStatus(uint8_t UART_num , uint32_t FlagName)
{
	USART_RegDef_t *pUSARTx = UART_Arr[UART_num];     // new

	if(pUSARTx->USART_SR & FlagName)
	{
		return FLAG_SET;
	}
	return FLAG_RESET;
}

//void USART_SetBaudRate(USART_RegDef_t *pUSARTx, uint32_t BaudRate)
void USART_SetBaudRate(uint8_t UART_num, uint32_t BaudRate)
{

	//Variable to hold the APB clock
	uint32_t PCLKx;

	uint32_t usartdiv;

	//variables to hold Mantissa and Fraction values
	uint32_t M_part,F_part;

	uint32_t tempreg=0;


	USART_RegDef_t *pUSARTx = UART_Arr[UART_num];                // new

	//Get the value of APB bus clock in to the variable PCLKx
	if(pUSARTx == USART1 || pUSARTx == USART6)
	{
		//USART1 and USART6 are hanging on APB2 bus
		PCLKx = RCC_GetPCLK2Value();
	}else
	{
		PCLKx = RCC_GetPCLK1Value();
	}

	//Check for OVER8 configuration bit
	if(pUSARTx->USART_CR1 & (1 << USART_CR1_OVER8))
	{
		//OVER8 = 1 , over sampling by 8
		usartdiv = ((25 * PCLKx) / (2 *BaudRate));
	}else
	{
		//over sampling by 16
		usartdiv = ((25 * PCLKx) / (4 *BaudRate));
	}

	//Calculate the Mantissa part
	M_part = usartdiv/100;

	//Place the Mantissa part in appropriate bit position . refer USART_BRR
	tempreg |= M_part << 4;

	//Extract the fraction part
	F_part = (usartdiv - (M_part * 100));

	//Calculate the final fractional
	if(pUSARTx->USART_CR1 & ( 1 << USART_CR1_OVER8))
	{
		//OVER8 = 1 , over sampling by 8
		F_part = ((( F_part * 8)+ 50) / 100)& ((uint8_t)0x07);

	}else
	{
		//over sampling by 16
		F_part = ((( F_part * 16)+ 50) / 100) & ((uint8_t)0x0F);

	}

	//Place the fractional part in appropriate bit position . refer USART_BRR
	tempreg |= F_part;

	//copy the value of tempreg in to BRR register
	pUSARTx->USART_BRR = tempreg;
}


/*********************************************************************
 * @fn      		  - USART_Init
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              - Resolve all the TODOs
 */
//void USART_Init(USART_Handle_t *pUSARTHandle)
void USART_Init(uint8_t UART_num , USART_Config_t config)
{

	//Temporary variable
	uint32_t tempreg=0;

	USART_Handle_t UART_handle;
	USART_Handle_t *pUSARTHandle = &UART_handle;

	pUSARTHandle -> pUSARTx = UART_Arr[UART_num];       // new
	pUSARTHandle -> USART_Config = config;

	/******************************** Configuration of CR1******************************************/

	//Implement the code to enable the Clock for given USART peripheral
	USART_PeriClockControl(UART_num,ENABLE);

	//Enable USART Tx and Rx engines according to the USART_Mode configuration item
	if ( pUSARTHandle->USART_Config.USART_Mode == USART_MODE_ONLY_RX)
	{
		//Implement the code to enable the Receiver bit field
		tempreg|= (1 << USART_CR1_RE);
	}else if (pUSARTHandle->USART_Config.USART_Mode == USART_MODE_ONLY_TX)
	{
		//Implement the code to enable the Transmitter bit field
		tempreg |= ( 1 << USART_CR1_TE);

	}else if (pUSARTHandle->USART_Config.USART_Mode == USART_MODE_TXRX)
	{
		//Implement the code to enable the both Transmitter and Receiver bit fields
		tempreg |= ( ( 1 << USART_CR1_TE) | ( 1 << USART_CR1_RE) );
	}

	//Implement the code to configure the Word length configuration item
	tempreg |= pUSARTHandle->USART_Config.USART_WordLength << USART_CR1_M ;


	//Configuration of parity control bit fields
	if ( pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_EN_EVEN)
	{
		//Implement the code to enable the parity control
		tempreg |= ( 1 << USART_CR1_PCE);

		//Implement the code to enable EVEN parity
		//Not required because by default EVEN parity will be selected once you enable the parity control

	}else if (pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_EN_ODD )
	{
		//Implement the code to enable the parity control
		tempreg |= ( 1 << USART_CR1_PCE);

		//Implement the code to enable ODD parity
		tempreg |= ( 1 << USART_CR1_PS);

	}

	//Program the CR1 register
	pUSARTHandle->pUSARTx->USART_CR1 = tempreg;

	/******************************** Configuration of CR2******************************************/

	tempreg=0;

	//Implement the code to configure the number of stop bits inserted during USART frame transmission
	tempreg |= pUSARTHandle->USART_Config.USART_NoOfStopBits << USART_CR2_STOP;

	//Program the CR2 register
	pUSARTHandle->pUSARTx->USART_CR2 = tempreg;

	/******************************** Configuration of CR3******************************************/

	tempreg=0;

	//Configuration of USART hardware flow control
	if ( pUSARTHandle->USART_Config.USART_HWFlowControl == USART_HW_FLOW_CTRL_CTS)
	{
		//Implement the code to enable CTS flow control
		tempreg |= ( 1 << USART_CR3_CTSE);


	}else if (pUSARTHandle->USART_Config.USART_HWFlowControl == USART_HW_FLOW_CTRL_RTS)
	{
		//Implement the code to enable RTS flow control
		tempreg |= (1 << USART_CR3_RTSE);

	}else if (pUSARTHandle->USART_Config.USART_HWFlowControl == USART_HW_FLOW_CTRL_CTS_RTS)
	{
		//Implement the code to enable both CTS and RTS Flow control
		tempreg |= ( ( 1 << USART_CR3_CTSE) | ( 1 << USART_CR3_RTSE) );
	}


	pUSARTHandle->pUSARTx->USART_CR3 = tempreg;

	/******************************** Configuration of BRR(Baudrate register)******************************************/

	USART_SetBaudRate(UART_num,pUSARTHandle->USART_Config.USART_Baud);    // new

}



/*********************************************************************
 * @fn      		  - USART_SendData
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              - Resolve all the TODOs
 */
//void USART_SendData(USART_Handle_t *pUSARTHandle, uint8_t *pTxBuffer, uint32_t Len)
void USART_SendData(uint8_t UART_num, uint8_t *pTxBuffer, uint32_t Len , USART_Config_t config)
{

	uint16_t *pdata;

	USART_Handle_t UART_handle;
	USART_Handle_t *pUSARTHandle = &UART_handle;

	pUSARTHandle -> pUSARTx = UART_Arr[UART_num];       // new
	pUSARTHandle -> USART_Config = config;

	//Loop over until "Len" number of bytes are transferred
	for(uint32_t i = 0 ; i < Len; i++)
	{
		//Implement the code to wait until TXE flag is set in the SR
		while(! USART_GetFlagStatus(UART_num,USART_FLAG_TXE));

		//Check the USART_WordLength item for 9BIT or 8BIT in a frame
		if(pUSARTHandle->USART_Config.USART_WordLength == USART_WORDLEN_9BITS)
		{
			//if 9BIT, load the DR with 2bytes masking the bits other than first 9 bits
			pdata = (uint16_t*) pTxBuffer;
			pUSARTHandle->pUSARTx->USART_DR = (*pdata & (uint16_t)0x01FF);

			//check for USART_ParityControl
			if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_DISABLE)
			{
				//No parity is used in this transfer. so, 9bits of user data will be sent
				//Implement the code to increment pTxBuffer twice
				pTxBuffer++;
				pTxBuffer++;
			}
			else
			{
				//Parity bit is used in this transfer . so , 8bits of user data will be sent
				//The 9th bit will be replaced by parity bit by the hardware
				pTxBuffer++;
			}
		}
		else
		{
			//This is 8bit data transfer
			pUSARTHandle->pUSARTx->USART_DR = (*pTxBuffer  & (uint8_t)0xFF);

			//Implement the code to increment the buffer address
			pTxBuffer++;
		}
	}

	//Implement the code to wait till TC flag is set in the SR
	while( ! USART_GetFlagStatus(UART_num,USART_FLAG_TC));      // new
}


/*********************************************************************
 * @fn      		  - USART_ReceiveData
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -
 */

//void USART_ReceiveData(USART_Handle_t *pUSARTHandle, uint8_t *pRxBuffer, uint32_t Len)
void USART_ReceiveData(uint8_t UART_num, uint8_t *pRxBuffer, uint32_t Len , USART_Config_t config)
{

	USART_Handle_t UART_handle;
	USART_Handle_t *pUSARTHandle = &UART_handle;

	pUSARTHandle -> pUSARTx = UART_Arr[UART_num];       // new
	pUSARTHandle -> USART_Config = config;

	//Loop over until "Len" number of bytes are transferred
	for(uint32_t i = 0 ; i < Len; i++)
	{
		//Implement the code to wait until RXNE flag is set in the SR
		while(! USART_GetFlagStatus(UART_num,USART_FLAG_RXNE));        //new

		//Check the USART_WordLength to decide whether we are going to receive 9bit of data in a frame or 8 bit
		if(pUSARTHandle->USART_Config.USART_WordLength == USART_WORDLEN_9BITS)
		{
			//We are going to receive 9bit data in a frame

			//check are we using USART_ParityControl control or not
			if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_DISABLE)
			{
				//No parity is used. so, all 9bits will be of user data

				//read only first 9 bits. so, mask the DR with 0x01FF
				*((uint16_t*) pRxBuffer) = (pUSARTHandle->pUSARTx->USART_DR  & (uint16_t)0x01FF);

				//Now increment the pRxBuffer two times
				pRxBuffer++;
				pRxBuffer++;
			}
			else
			{
				//Parity is used, so, 8bits will be of user data and 1 bit is parity
				*pRxBuffer = (pUSARTHandle->pUSARTx->USART_DR  & (uint8_t)0xFF);

				//Increment the pRxBuffer
				pRxBuffer++;
			}
		}
		else
		{
			//We are going to receive 8bit data in a frame

			//check are we using USART_ParityControl control or not
			if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_DISABLE)
			{
				//No parity is used , so all 8bits will be of user data

				//read 8 bits from DR
				*pRxBuffer = pUSARTHandle->pUSARTx->USART_DR;
			}

			else
			{
				//Parity is used, so , 7 bits will be of user data and 1 bit is parity

				//read only 7 bits , hence mask the DR with 0X7F
				*pRxBuffer = ( pUSARTHandle->pUSARTx->USART_DR & (uint8_t) 0x7F);

			}

			//increment the pRxBuffer
			pRxBuffer++;
		}
	}

}

/*********************************************************************
 * @fn      		  - USART_SendDataWithIT
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -
 */
uint8_t USART_SendDataIT(USART_Handle_t *pUSARTHandle,uint8_t *pTxBuffer, uint32_t Len)
{
	uint8_t txstate = pUSARTHandle->TxBusyState;

	if(txstate != USART_BUSY_IN_TX)
	{
		pUSARTHandle->TxLen = Len;
		pUSARTHandle->pTxBuffer = pTxBuffer;
		pUSARTHandle->TxBusyState = USART_BUSY_IN_TX;

		//Implement the code to enable interrupt for TXE
		pUSARTHandle->pUSARTx->USART_CR1 |= ( 1 << USART_CR1_TXEIE);


		//Implement the code to enable interrupt for TC
		pUSARTHandle->pUSARTx->USART_CR1 |= ( 1 << USART_CR1_TCIE);


	}

	return txstate;
}


/*********************************************************************
 * @fn      		  - USART_ReceiveDataWithIT
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -
 */
uint8_t USART_ReceiveDataIT(USART_Handle_t *pUSARTHandle,uint8_t *pRxBuffer, uint32_t Len)
{
	uint8_t rxstate = pUSARTHandle->RxBusyState;

	if(rxstate != USART_BUSY_IN_RX)
	{
		pUSARTHandle->RxLen = Len;
		pUSARTHandle->pRxBuffer = pRxBuffer;
		pUSARTHandle->RxBusyState = USART_BUSY_IN_RX;

		(void)pUSARTHandle->pUSARTx->USART_DR;

		//Implement the code to enable interrupt for RXNE
		pUSARTHandle->pUSARTx->USART_CR1 |= ( 1 << USART_CR1_RXNEIE);

	}

	return rxstate;
}
