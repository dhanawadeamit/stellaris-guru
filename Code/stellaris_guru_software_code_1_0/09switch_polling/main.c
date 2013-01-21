 /* Centre for Electronic Design and Technology, NSIT, New Delhi
 * 
 * Dhananjay V Gadre, dhananjay.gadre@gmail.com
 * Shanjit Singh Jajmann, shanjitsingh@gmail.com
 * Rohit Dureja, rohit.dureja@gmail.com
 * 
 */

/* Defines the base address of the memories and peripherals */
#include "inc/hw_memmap.h"

/* Defines the common types and macros */
#include "inc/hw_types.h"

/* Defines and Macros for GPIO API */
#include "driverlib/gpio.h"

/* Prototypes for the system control driver */
#include "driverlib/sysctl.h"

int main(void)
{
	/* Set the clocking to directly run from the crystal at 8MHz */
	SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | SYSCTL_XTAL_8MHZ);

	/* Set the clock for the GPIO Port C */
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);

	/* Set the type of the GPIO Pin */
	GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7);
	GPIOPinTypeGPIOInput(GPIO_PORTE_BASE,GPIO_PIN_0);
	GPIOPinTypeGPIOInput(GPIO_PORTE_BASE,GPIO_PIN_1);
	
	/*Configure GPIO pad with internal pull-up enabled, check with GPIO_PIN_0 | GPIO_PIN_1 */
	GPIOPadConfigSet(GPIO_PORTE_BASE, GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
	GPIOPadConfigSet(GPIO_PORTE_BASE, GPIO_PIN_1, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

	/* GPIO Pins 5, 6, 7 on PORT C initialized to 1
	 * All LEDs are Off.
	 * */
	GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7, GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7);
	
	
	while(1)
    {

		if(GPIOPinRead(GPIO_PORTE_BASE, GPIO_PIN_0)==GPIO_PIN_0)
		{
		//Make High
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, GPIO_PIN_6);
		}
		
		if(GPIOPinRead(GPIO_PORTE_BASE, GPIO_PIN_1)==GPIO_PIN_1)
		{
		//Make High
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, GPIO_PIN_5);
		}

		if(GPIOPinRead(GPIO_PORTE_BASE, GPIO_PIN_0)==0)
		{
		//Make Low
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 0);
		}

		if(GPIOPinRead(GPIO_PORTE_BASE, GPIO_PIN_1)==0)
		{
		//Make Low
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 0);
		}

    }
}

