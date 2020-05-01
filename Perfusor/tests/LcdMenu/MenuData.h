#ifndef _sampleMenu_
#define _sampleMenu_
#include "MenuManager.h"
#include <avr/pgmspace.h>

/*

Generated using LCD Menu Builder at https://lcd-menu-bulder.cohesivecomputing.co.uk/
For more information, visit https://www.cohesivecomputing.co.uk/hackatronics/arduino-lcd-menu-library/

All our hackatronics projects are free for personal use. If you find them helpful or useful, please consider
making a small donation to our hackatronics fund using the donate buttons on our web pages. Thank you.
    
*/

enum sampleMenuCommandId
{
  mnuCmdBack = 0,
  mnuCmdTopItem1,
  mnuCmdSubItem1,
  mnuCmdSubItem50,
  mnuCmdSubItem20,
  mnuCmdSubItem10,
  mnuCmdSubItem05,
  mnuCmdSubItem2,
  mnuCmdSubItem2A,
  mnuCmdSubItem2B,
  mnuCmdSubItem2C,
  mnuCmdSubItem2D,
  mnuCmdSubItem2E,
  mnuCmdSubItem2F,
  mnuCmdSubItem3,
  mnuCmdFlujo,
  mnuCmdSubItem4,
  mnuCmdComenzar,
  mnuCmdParar,
  mnuCmdCancelar,
  mnuCmdSubItem5,
  mnuCmdBolus,
  mnuCmdCambiarFlujo,
  mnuCmdTopItem2,
  mnuCmdSpanish,
  mnuCmdEnglish,
  mnuCmdResetToDefaults
};

PROGMEM const char sampleMenu_back[] = "Back";
PROGMEM const char sampleMenu_exit[] = "Exit";

PROGMEM const char sampleMenu_2_1[] = "1 50 ml        ";
PROGMEM const char sampleMenu_2_2[] = "2 20 ml        ";
PROGMEM const char sampleMenu_2_3[] = "3 10 ml        ";
PROGMEM const char sampleMenu_2_4[] = "4 05 ml        ";
PROGMEM const MenuItem sampleMenu_List_2[] = {{mnuCmdSubItem50, sampleMenu_2_1}, {mnuCmdSubItem20, sampleMenu_2_2}, {mnuCmdSubItem10, sampleMenu_2_3}, {mnuCmdSubItem05, sampleMenu_2_4}, {mnuCmdBack, sampleMenu_back}};

PROGMEM const char sampleMenu_3_1[] = "1 BD Plastipak ";
PROGMEM const char sampleMenu_3_2[] = "2 Fresenius Inj";
PROGMEM const char sampleMenu_3_3[] = "3 Braun Omnifix";
PROGMEM const char sampleMenu_3_4[] = "4 Braun Perfuso";
PROGMEM const char sampleMenu_3_5[] = "5 PIC Indolor  ";
PROGMEM const char sampleMenu_3_6[] = "6 Terumo       ";
PROGMEM const MenuItem sampleMenu_List_3[] = {{mnuCmdSubItem2A, sampleMenu_3_1}, {mnuCmdSubItem2B, sampleMenu_3_2}, {mnuCmdSubItem2C, sampleMenu_3_3}, {mnuCmdSubItem2D, sampleMenu_3_4}, {mnuCmdSubItem2E, sampleMenu_3_5}, {mnuCmdSubItem2F, sampleMenu_3_6}, {mnuCmdBack, sampleMenu_back}};

PROGMEM const char sampleMenu_4_1[] = "1 Flujo ml/hr  ";
PROGMEM const MenuItem sampleMenu_List_4[] = {{mnuCmdFlujo, sampleMenu_4_1}, {mnuCmdBack, sampleMenu_back}};

PROGMEM const char sampleMenu_5_1[] = "1 Comenzar     ";
PROGMEM const char sampleMenu_5_2[] = "2 Parar        ";
PROGMEM const char sampleMenu_5_3[] = "3 Cancelar     ";
PROGMEM const MenuItem sampleMenu_List_5[] = {{mnuCmdComenzar, sampleMenu_5_1}, {mnuCmdParar, sampleMenu_5_2}, {mnuCmdCancelar, sampleMenu_5_3}, {mnuCmdBack, sampleMenu_back}};

PROGMEM const char sampleMenu_6_1[] = "1 Bolus de x (m";
PROGMEM const char sampleMenu_6_2[] = "2 Cambio bolus ";
PROGMEM const MenuItem sampleMenu_List_6[] = {{mnuCmdBolus, sampleMenu_6_1}, {mnuCmdCambiarFlujo, sampleMenu_6_2}, {mnuCmdBack, sampleMenu_back}};

PROGMEM const char sampleMenu_7_1[] = "1 Español      ";
PROGMEM const char sampleMenu_7_2[] = "2 Inglés       ";
PROGMEM const MenuItem sampleMenu_List_7[] = {{mnuCmdSpanish, sampleMenu_7_1}, {mnuCmdEnglish, sampleMenu_7_2}, {mnuCmdBack, sampleMenu_back}};

PROGMEM const char sampleMenu_1[] = "1 Prog. infusió";
PROGMEM const char sampleMenu_2[] = "2 Tamaño jering";
PROGMEM const char sampleMenu_3[] = "3 Marca jeringa";
PROGMEM const char sampleMenu_4[] = "4 Seleccionar V";
PROGMEM const char sampleMenu_5[] = "5 Infusión";
PROGMEM const char sampleMenu_6[] = "6 Función bolus";
PROGMEM const char sampleMenu_7[] = "7 Seleccionar i";
PROGMEM const char sampleMenu_8[] = "8 Reiniciar";
PROGMEM const MenuItem sampleMenu_Root[] = {{mnuCmdTopItem1, sampleMenu_1}, {mnuCmdSubItem1, sampleMenu_2, sampleMenu_List_2, menuCount(sampleMenu_List_2)}, {mnuCmdSubItem2, sampleMenu_3, sampleMenu_List_3, menuCount(sampleMenu_List_3)}, {mnuCmdSubItem3, sampleMenu_4, sampleMenu_List_4, menuCount(sampleMenu_List_4)}, {mnuCmdSubItem4, sampleMenu_5, sampleMenu_List_5, menuCount(sampleMenu_List_5)}, {mnuCmdSubItem5, sampleMenu_6, sampleMenu_List_6, menuCount(sampleMenu_List_6)}, {mnuCmdTopItem2, sampleMenu_7, sampleMenu_List_7, menuCount(sampleMenu_List_7)}, {mnuCmdResetToDefaults, sampleMenu_8}, {mnuCmdBack, sampleMenu_exit}};

/*
case mnuCmdTopItem1 :
  break;
case mnuCmdSubItem50 :
  break;
case mnuCmdSubItem20 :
  break;
case mnuCmdSubItem10 :
  break;
case mnuCmdSubItem05 :
  break;
case mnuCmdSubItem2A :
  break;
case mnuCmdSubItem2B :
  break;
case mnuCmdSubItem2C :
  break;
case mnuCmdSubItem2D :
  break;
case mnuCmdSubItem2E :
  break;
case mnuCmdSubItem2F :
  break;
case mnuCmdFlujo :
  break;
case mnuCmdComenzar :
  break;
case mnuCmdParar :
  break;
case mnuCmdCancelar :
  break;
case mnuCmdBolus :
  break;
case mnuCmdCambiarFlujo :
  break;
case mnuCmdSpanish :
  break;
case mnuCmdEnglish :
  break;
case mnuCmdResetToDefaults :
  break;
*/

/*
<?xml version="1.0"?>
<RootMenu xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
  <Config IdPrefix="mnuCmd" VarPrefix="sampleMenu" UseNumbering="true" IncludeNumberHierarchy="false"
          MaxNameLen="15" MenuBackFirstItem="false" BackText="Back" ExitText="Exit" AvrProgMem="true"/>
  <MenuItems>
    <Item Id="TopItem1" Name="Prog. infusión  "/>
        <Item Id="SubItem1" Name="Tamaño jeringa  ">
          <MenuItems>
            <Item Id="SubItem50" Name="50 ml           "/>
            <Item Id="SubItem20" Name="20 ml           "/>
            <Item Id="SubItem10" Name="10 ml           "/>
            <Item Id="SubItem05" Name="05 ml           "/>
          </MenuItems>
        </Item>
        <Item Id="SubItem2" Name="Marca jeringa   ">
          <MenuItems>
            <Item Id="SubItem2A" Name="BD Plastipak    "/>
            <Item Id="SubItem2B" Name="Fresenius Inject"/>
            <Item Id="SubItem2C" Name="Braun Omnifix   "/>
            <Item Id="SubItem2D" Name="Braun Perfusor  "/>
            <Item Id="SubItem2E" Name="PIC Indolor     "/>
            <Item Id="SubItem2F" Name="Terumo          "/>
          </MenuItems>
        </Item>
        <Item Id="SubItem3" Name="Seleccionar Vol.">
          <MenuItems>
            <Item Id="Flujo" Name="Flujo ml/hr     "/>
          </MenuItems>
        </Item> 
        <Item Id="SubItem4" Name="Infusión">
          <MenuItems>
            <Item Id="Comenzar" Name="Comenzar        "/>
            <Item Id="Parar" Name="Parar           "/>            
            <Item Id="Cancelar" Name="Cancelar        "/>
          </MenuItems>
        </Item>        
        <Item Id="SubItem5" Name="Función bolus   ">
          <MenuItems>
            <Item Id="Bolus" Name="Bolus de x (ml) "/>
            <Item Id="CambiarFlujo" Name="Cambio bolus ml/h"/>
          </MenuItems>
        </Item>     
    <Item Id="TopItem2" Name="Seleccionar idioma  ">
          <MenuItems>
            <Item Id="Spanish" Name="Español         "/>
            <Item Id="English" Name="Inglés          "/>
          </MenuItems>
        </Item>    
    <Item Id="ResetToDefaults" Name="Reiniciar"/>
  </MenuItems>
</RootMenu>
*/
#endif
