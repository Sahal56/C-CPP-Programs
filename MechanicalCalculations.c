#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14
#define CHOICE "\n   Your choice: "

char *a[]=
    {
        (char[]){"Engine is a device which converts one form of Energy into another form."},
        (char[]){"Heat engine is a device which transforms the chemical energy of a fuel into thermal energy \nand utilizes this thermal energy to perform useful work.\nThus, thermal energy is converted to mechanical energy in a heat engine."}
    };
double input(char *query)
{
    double temp;
    if(query)
        printf("%s",query);
    scanf("%lf",&temp);
    return temp;
}

void toIC_Engine(void);
    void calculatorInIC(void);
      double strokeVolume(void);
      double compressionRatio(void);
      double pistonSpeed(void);
      double indicatedPower(void);
      double brakePower(void);
      double frictionPower(void);
      double mechanicalEfficiency(void);
      double indicatedThermalEfficiency(void);
      double brakeThermalEfficiency(void);
      double relativeEfficiency(void);
      double airStandardEfficiency(void);
      double volumetricEfficiency(void);
      double specificOutput(void);
      double specificFuelConsumption(void);

    void definitionInIC(void);
      int *infoListOfDefinitions(int key);
      
// Driver Program
int main(void)
{
    toIC_Engine();
    return 0;
}

void toIC_Engine(void)
{
    printf("\n-----Start-----\n");
    short choice, getout=0;
    do
    {
        printf("\n [1]Calculator");
        printf("\n [2]Definitions");
        printf("\n [0]Exit");
        choice = input(CHOICE);
        switch(choice)
        {
            case 0 : break;
            case 1 :
                calculatorInIC();
                break;
            case 2 :
                definitionInIC();
                break;
            default : printf("\n Invalid Choice");
        }
    }while(choice != getout);
    printf("\n-----End-----\n");
}
void calculatorInIC(void)
{
    printf("\n-----Calculator-----\n");
    double result;
    short choice, getout=0;
    do
    {
        printf("\n\n [1]Stroke Volume");
        printf("\n [2]Compression Ratio");
        printf("\n [3]Piston Speed");
        printf("\n [4]Indicated Power");
        printf("\n [5]Brake Power");
        printf("\n [6]Friction Power");
        printf("\n [7]Mechanical Efficiency");
        printf("\n [8]Indicated Thermal Efficiency");
        printf("\n [9]Brake Thermal Efficiency");
        printf("\n [10]Relative Efficiency");
        printf("\n [11]Air Standard Efficiency");
        printf("\n [12]Volumetric Efficiency");
        printf("\n [13]Specific Output");
        printf("\n [14]Specific Fuel Consumption");
        printf("\n [0]Exit Calculator");
        choice = input(CHOICE);
        switch(choice)
        {
            case 0 : break;
                
            case 1 :
                result = strokeVolume();
                printf("\n Stroke Volume(Swept Volume) = %.4lf m^3", result);
                break;
            case 2 :
                result = compressionRatio();
                printf("\n Compression Ratio(r) = %.4lf", result);
                break;
            case 3 :
                result = pistonSpeed();
                printf("\n Piston Speed Vp = %.4lf m/s", result);
                break;
            case 4 :
                result = indicatedPower();
                printf("\n Indicated Power = %.4lf kW", result);
                break;
            case 5 :
                result = brakePower();
                printf("\n Brake Power = %.4lf kW", result);
                break;
            case 6 :
                result = frictionPower();
                printf("\n Friction Power = %.4lf kW", result);
                break;
            case 7 :
                result = mechanicalEfficiency();
                printf("\n Mechanical Efficiency = %.4lf", result);
                break;
            case 8 :
                result = indicatedThermalEfficiency();
                printf("\n Indicated Thermal Efficiency = %.4lf", result);
                break;
            case 9 :
                result = brakeThermalEfficiency();
                printf("\n Brake Thermal Efficiency = %.4lf", result);
                break;
            case 10 :
                result = relativeEfficiency();
                printf("\n Relative Efficiency = %.4lf", result);
                break;
            case 11 :
                result = airStandardEfficiency();
                printf("\n Air Standard Efficiency = %.4lf", result);
                break;
            case 12 :
                result = volumetricEfficiency();
                printf("\n Volumetric Efficiency = %.4lf", result);
                break;
            case 13 :
                result = specificOutput();
                printf("\n Specific Output = %.4lf kW/m^2", result);
                break;
            case 14 :
                result = specificFuelConsumption();
                printf("\n Specific Fuel Consumption = %.4lf kg/kWh", result);
                break;
            default : printf("\n Invalid Choice");
        }
    }while(choice != getout);
     printf("\n-----Exiting-Calculator-----\n");
}
double strokeVolume(void)
{
    double Vs, L, d;
    L = input("\n Stroke Length: ");
    d = input("\n Bore(Diameter): ");
    Vs = (PI*d*d*L)/4;
    printf("\n");
    return Vs;
}
double compressionRatio(void)
{
    double  Vs, Vc, r;
    Vs = input("\n Stroke Volume(Swept Volume): ");
    Vc = input("\n Clearance Volume: ");
    // or r = (Vs+Vc) / Vc;
    r = 1.0 + (Vs / Vc);
    printf("\n");
    return r;
}
double pistonSpeed(void)
{
    double Vp, L, N;
    L = input("\n Stroke Length(m): ");
    N = input("\n Speed of Crankshaft(RPM): ");
    Vp = (2*L*N) / 60.0;
    printf("\n");
    return Vp;
}
double indicatedPower(void)
{
    double Pm, L, A, N, n, _IP;
    short check = input("\n Do you have Mean Effective Pressure? Yes[1] No[otherwise]: ");
    if(check == 1)
        Pm = input("\n  Pm (N/m^2): ");
    else
    {
        double area, springValue, baseWidth;
        area = input("\n Area of actual indicator  diagram(cm^2): ");
        baseWidth= input("\n Base width of indicator  diagram(cm): ");
        springValue = input("\n Spring Value of spring used in indicator diagram(cm^2): ");
        Pm = ( springValue * area) / springValue;
    }
    L = input("\n Stroke Length(m): ");
    N = input("\n Speed of Engine Crankshaft(RPM): ");
    A = input("\n Area of cross-section of cylinder(m^2): ");
    
    check = input("\n Stroke _> Two[1] Four[otherwise]: ");
    if(check == 1)
        n = N;
    else
        n = N / 2;
    
    _IP = (Pm*L*A*n) / 60000.0;
    printf("\n");
    return _IP;
}
double brakePower(void)
{
    double N, T, _BP;
    T = input("\n Resisting Torque(Nm): ");
    N = input("\n Speed of Crankshaft(RPM): ");
    _BP = (2.0*PI*N*T) / 60000.0;
    printf("\n");
    return _BP;
}
double frictionPower(void)
{
    double _IP, _BP, _FP;
    short check;
    check = input("\n Do you have Indicated Power? Yes[1] No[otherwise]: ");
    if(check == 1)
        _IP = input("\n Indicated Power(kW): ");
    else
        _IP = indicatedPower();
    
    check = input("\n Do you have Brake Power? Yes[1] No[otherwise]: ");
    if(check == 1)
         _BP = input("\n Brake Power(kW): ");
    else
        _BP = brakePower();
    
    _FP = _IP - _BP;
    printf("\n");
    return _FP;
}
double mechanicalEfficiency(void)
{
    double m_efficiency, _IP, _BP;
    short check;
    check = input("\n Do you have Indicated Power? Yes[1] No[otherwise]: ");
    if(check == 1)
        _IP = input("\n Indicated Power(kW): ");
    else
        _IP = indicatedPower();
    check = input("\n Do you have Brake Power? Yes[1] No[otherwise]: ");
    if(check == 1)
        _BP = input("\n Brake Power(kW): ");
    else
        _BP = brakePower();
    m_efficiency = _IP / _BP;
    printf("\n");
    return m_efficiency;
 }
double indicatedThermalEfficiency(void)
{
    double i_th_efficiency, _IP, _BP, Mf, _CV;
    short check;
    
    Mf = input("\n Mass of Fuel Supplied(Mf): ");
    _CV = input("\n Calorific Value of Fuel(J/kg): ");
    
    check = input("\n Do you have Indicated Power? Yes[1] No[otherwise]: ");
    if(check == 1)
        _IP = input("\n Indicated Power(kW): ");
    else
        _IP = indicatedPower();
    
    i_th_efficiency = _IP / (Mf * _CV);
    printf("\n");
    return i_th_efficiency;
}
double brakeThermalEfficiency(void)
{
    double b_th_efficiency, _BP, Mf, _CV;
    short check;
    
    Mf = input("\n Mass of Fuel Supplied(Mf): ");
    _CV = input("\n Calorific Value of Fuel(J/kg): ");
    
    check = input("\n Do you have Brake Power? Yes[1] No[otherwise]: ");
    if(check == 1)
        _BP = input("\n Brake Power(kW): ");
    else
        _BP = brakePower();
    
    /*
        b_th_efficiency = ( mechanicalEfficiency() * indicatedThermalEfficiency );
    */
    
    b_th_efficiency = _BP / (Mf * _CV);
    
    printf("\n");
    return b_th_efficiency;
}
double relativeEfficiency(void)
{
    double r_Efficiency, aStd_Efficiency, i_th_efficiency;
    short check;
    
    check = input("\n Do you have Indicated Thermal Efficiency? Yes[1] No[otherwise]: ");
    if(check == 1)
        i_th_efficiency = input("\n Indicated Thermal Efficiency: ");
    else
        i_th_efficiency = indicatedThermalEfficiency();
    
    check = input("\n Do you have Air Standard Efficiency? Yes[1] No[otherwise]: ");
    if(check == 1)
        aStd_Efficiency = input("\n Air Standard Efficiency: ");
    else
        aStd_Efficiency = airStandardEfficiency();
    
    r_Efficiency = i_th_efficiency / aStd_Efficiency;
    
    printf("\n");
    return r_Efficiency;
}
double airStandardEfficiency(void)
{
    double gamma, r, aStd_Efficiency;
    short check;
    
    gamma = input("\n Value of gamma: ");
    check = input("\n Do you have Compression Ratio(r)? Yes[1] No[otherwise]: ");
    if(check == 1)
        r = input("\n Compression Ratio(r): ");
    else
        r = compressionRatio();
    
    check = input("\n Engine? Petrol[1] Diesel[otherwise]: ");
    if(check == 1)
        aStd_Efficiency =  1 - (1 / ( pow(r,gamma-1) ) );
    else
    {
        double roo, X, Y;
        roo = input("\n Value of roo: ");
        X = 1 - (1 / ( pow(r,gamma-1) ) );
        Y = (pow(roo,gamma) - 1) / ( gamma * (roo - 1) );
        aStd_Efficiency =  1 - (X * Y);
    }
    
    printf("\n");
    return aStd_Efficiency;
}
double volumetricEfficiency(void)
{
    double vol_Efficiency, Vs, vol_charge;
    short check;
    
    vol_charge = input("\n Actual Volume of  Charge OR Air sucked at Atm. Condition: ");
    
    check = input("\n Do you have Stroke Volume? Yes[1] No[otherwise]: ");
    if(check == 1)
        Vs = input("\n Stroke Volume(m^3): ");
    else
        Vs = strokeVolume();
    
    vol_Efficiency = vol_charge / Vs;
    
    printf("\n");
    return vol_Efficiency;
}
double specificOutput(void)
{
    double sp_OP, _BP, area;
    short check;
    
    area = input("\n Unit Area of Piston: ");
    
    check = input("\n Do you have Brake Power? Yes[1] No[otherwise]: ");
    if(check == 1)
        _BP = input("\n Brake Power(kW): ");
    else
        _BP = brakePower();
    
    sp_OP = _BP / area;
    
    printf("\n");
    return sp_OP;
}
double specificFuelConsumption(void)
{
    double SFC, _BP, Mf;
    short check;
    
    Mf = input("\n Mass of Fuel Supplied(Mf): ");
    
    check = input("\n Do you have Brake Power? Yes[1] No[otherwise]: ");
    if(check == 1)
        _BP = input("\n Brake Power(kW): ");
    else
        _BP = brakePower();
    
    SFC = Mf / _BP;
    
    printf("\n");
    return SFC;
}

void definitionInIC(void)
{
    printf("\n-----Start-----\n");
    short choice, getout=0;
    int *result;
    do
    {
        printf("\n\n [1]Engine");
        printf("\n [2]Heat Engine");
        printf("\n [0]Exit");
        choice = input(CHOICE);
        result = a[choice-1];
        /*switch(choice)
        {
            case 0 : break;
            case 1 :
            case 2 :
            case 3 :
            case 4 :
            case 5 :
                printf("\n %s", result);
                break;
            default : printf("\n Invalid Choice");
        }*/
        printf("\n %s", result);
    }while(choice != getout);
    printf("\n-----End-----\n");
}
/*int *infoListOfDefinitions(int key)
{
    if(key == 0)
        return NULL;
    
    char *a[]=
    {
        (char[]){"Engine is a device which converts one form of Energy into another form."},
        (char[]){"Heat engine is a device which transforms the chemical energy of a fuel into thermal energy \\nand utilizes this thermal energy to perform useful work. \\nThus, thermal energy is converted to mechanical energy in a heat engine."}
        (char[]){""},
        (char[]){""},
        (char[]){""}
    };
    
    return a[key-1];
}*/