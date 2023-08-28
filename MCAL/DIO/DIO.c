/*
 * DIO.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Rowan Madeeh
 */

#include "../../LIB/std_types.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO.h"

#define DIO_PORTA_REG *((volatile u8*)0x03B)
#define DIO_DDRA_REG *((volatile u8*)0x03A)
#define DIO_PINA_REG *((volatile u8*)0x039)

#define DIO_PORTB_REG *((volatile u8*)0x038)
#define DIO_DDRB_REG *((volatile u8*)0x037)
#define DIO_PINB_REG *((volatile u8*)0x036)

#define DIO_PORTC_REG *((volatile u8*)0x035)
#define DIO_DDRC_REG *((volatile u8*)0x034)
#define DIO_PINC_REG *((volatile u8*)0x033)

#define DIO_PORTD_REG *((volatile u8*)0x032)
#define DIO_DDRD_REG *((volatile u8*)0x031)
#define DIO_PIND_REG *((volatile u8*)0x030)


void MDIO_voidSetPinDirection(u8 A_u8PortNo,u8 A_u8PinNo, u8 A_u8PinDirection)
{
	if((A_u8PortNo <= PortD) && (A_u8PinNo <= PIN7) && (A_u8PinDirection <= output)){

		switch(A_u8PortNo)
		{
			case PortA:

				switch(A_u8PinDirection)
				{
					case output: Set_Bit(DIO_DDRA_REG,A_u8PinNo);break;
					case input: Clr_Bit(DIO_DDRA_REG,A_u8PinNo);break;
				}
				break;

			case PortB:

				switch(A_u8PinDirection)
				{
					case output: Set_Bit(DIO_DDRB_REG,A_u8PinNo);break;
					case input: Clr_Bit(DIO_DDRB_REG,A_u8PinNo);break;
				}
				break;

			case PortC:

				switch(A_u8PinDirection)
				{
					case output: Set_Bit(DIO_DDRC_REG,A_u8PinNo);break;
					case input: Clr_Bit(DIO_DDRC_REG,A_u8PinNo);break;
				}
				break;

			case PortD:

				switch(A_u8PinDirection)
				{
					case output: Set_Bit(DIO_DDRD_REG,A_u8PinNo);break;
					case input: Clr_Bit(DIO_DDRD_REG,A_u8PinNo);break;
				}
				break;

		}
	}
	else{
		#if A_u8PortNo!=PortA && A_u8PortNo!=PortB && A_u8PortNo!=PortC && A_u8PortNo!=PortD
		#error Undefined PORT
		#endif

        #if A_u8PinNo<0 || A_u8PinNo>7
		#error Undefined PIN number
		#endif

		#if A_u8PinDirection<0 || A_u8PinDirection>1
		#error Undefined Direction
		#endif
	}
}

void MDIO_voidSetPinValue(u8 A_u8PortNo,u8 A_u8PinNo, u8 A_u8PinValue)
{
	if((A_u8PortNo <= PortD) && (A_u8PinNo <= PIN7) && (A_u8PinValue <= High)){

		switch(A_u8PortNo)
			{
				case PortA:

					switch(A_u8PinValue)
					{
						case output: Set_Bit(DIO_PORTA_REG,A_u8PinNo);break;
						case input: Clr_Bit(DIO_PORTA_REG,A_u8PinNo);break;
					}
					break;

				case PortB:

					switch(A_u8PinValue)
					{
						case output: Set_Bit(DIO_PORTB_REG,A_u8PinNo);break;
						case input: Clr_Bit(DIO_PORTB_REG,A_u8PinNo);break;
					}
					break;

				case PortC:

					switch(A_u8PinValue)
					{
						case output: Set_Bit(DIO_PORTC_REG,A_u8PinNo);break;
						case input: Clr_Bit(DIO_PORTC_REG,A_u8PinNo);break;
					}
					break;

				case PortD:

					switch(A_u8PinValue)
					{
						case output: Set_Bit(DIO_PORTD_REG,A_u8PinNo);break;
						case input: Clr_Bit(DIO_PORTD_REG,A_u8PinNo);break;
					}
					break;

			}
	}
	else
	{
		#if A_u8PortNo!=PortA && A_u8PortNo!=PortB && A_u8PortNo!=PortC && A_u8PortNo!=PortD
		#error Undefined PORT
		#endif

        #if A_u8PinNo<0 || A_u8PinNo>7
		#error Undefined PIN number
		#endif

		#if A_u8PinValue<0 || A_u8PinValue>1
		#error Undefined Value
		#endif
	}
}

u8 MDIO_u8GetPinValue(u8 A_u8PortNo, u8 A_u8PinNo)
{
	u8 local_u8Pin_Direction=5;

	if((A_u8PortNo <= PortD) && (A_u8PinNo <= PIN7)){

		switch(A_u8PortNo)
				{
					case PortA:

						local_u8Pin_Direction=Get_Bit(DIO_PINA_REG,A_u8PinNo);
						break;

					case PortB:

						local_u8Pin_Direction=Get_Bit(DIO_PINB_REG,A_u8PinNo);
						break;

					case PortC:

						local_u8Pin_Direction=Get_Bit(DIO_PINC_REG,A_u8PinNo);
						break;

					case PortD:

						local_u8Pin_Direction=Get_Bit(DIO_PIND_REG,A_u8PinNo);
						break;

				}
	}
	else
	{
		#if A_u8PortNo!=PortA && A_u8PortNo!=PortB && A_u8PortNo!=PortC && A_u8PortNo!=PortD
		#error Undefined PORT
		#endif

        #if A_u8PinNo<0 || A_u8PinNo>7
		#error Undefined PIN number
		#endif

	}
	return local_u8Pin_Direction;
}

void MDIO_voidSetPortDirection(u8 A_u8PortNo,u8 A_u8PortDirection)
{
	if((A_u8PortNo <= PortD)){

		switch(A_u8PortNo)
			{
				case PortA:

					DIO_DDRA_REG=A_u8PortDirection;
					break;

				case PortB:

					DIO_DDRB_REG=A_u8PortDirection;
					break;

				case PortC:

					DIO_DDRC_REG=A_u8PortDirection;
					break;

				case PortD:

					DIO_DDRD_REG=A_u8PortDirection;
					break;

			}
	}
	else
	{
		#if A_u8PortNo!=PortA && A_u8PortNo!=PortB && A_u8PortNo!=PortC && A_u8PortNo!=PortD
		#error Undefined PORT
		#endif

	}
}

void MDIO_voidSetPortValue(u8 A_u8PortNo,u8 A_u8PortValue)
{
	if((A_u8PortNo <= PortD)){

		switch(A_u8PortNo)
			{
				case PortA:

					DIO_PORTA_REG=A_u8PortValue;
					break;

				case PortB:

					DIO_PORTB_REG=A_u8PortValue;
					break;

				case PortC:

					DIO_PORTC_REG=A_u8PortValue;
					break;

				case PortD:

					DIO_PORTD_REG=A_u8PortValue;
					break;

			}
	}
	else
	{
		#if A_u8PortNo!=PortA && A_u8PortNo!=PortB && A_u8PortNo!=PortC && A_u8PortNo!=PortD
		#error Undefined PORT
		#endif
	}
}

