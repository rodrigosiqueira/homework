#define GPBCON      (*(volatile unsigned long *)0x56000010) //Port B Control
#define GPBDAT      (*(volatile unsigned long *)0x56000014) //Port B Data

#define GPFCON      (*(volatile unsigned long *)0x56000050) //Port F Control
#define GPFDAT      (*(volatile unsigned long *)0x56000054) //Port F Data

#define GPGCON      (*(volatile unsigned long *)0x56000060) //Port G Control
#define GPGDAT      (*(volatile unsigned long *)0x56000064) //Port G Data

#define GPB5_out        (1<<(5*2))
#define GPB6_out        (1<<(6*2))
#define GPB7_out        (1<<(7*2))
#define GPB8_out        (1<<(8*2))

#define GPG0_in     ~(3<<(0*2))
#define GPG3_in     ~(3<<(3*2))
#define GPG5_in     ~(3<<(5*2))
#define GPG6_in     ~(3<<(6*2))

int main()
{
        unsigned long dwDat;
        // LED1-LED4
        GPBCON = GPB5_out | GPB6_out | GPB7_out | GPB8_out ;

        // K1-K2
        GPGCON = GPG0_in & GPG3_in & GPG5_in & GPG6_in;

        while(1)
        {
            //LEDn
            dwDat = GPGDAT;             //GPG
            /* De acordo com a configuracao de GPGCON o GPGDAT
             * lidara com o dado
             */
        
            if (dwDat & (1<<0))         // K1
                GPBDAT |= (1<<5);       // LED1
            else    
                GPBDAT &= ~(1<<5);      // LED1
                
            if (dwDat & (1<<3))         // K2
                GPBDAT |= (1<<6);       // LED2
            else    
                GPBDAT &= ~(1<<6);      // LED2
    
            //dwDat = GPFDAT;             // GPF
            
            if (dwDat & (1<<5))         // K3
                GPBDAT |= (1<<7);       // LED3
            else    
                GPBDAT &= ~(1<<7);      // LED3
    
            if (dwDat & (1<<6))         // K4
                GPBDAT |= (1<<8);       // LED4
            else    
                GPBDAT &= ~(1<<8);      // LED4
    }

    return 0;
   }
