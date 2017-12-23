<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="8.5.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.5" unitdist="mm" unit="mm" style="lines" multiple="1" display="yes" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="yes" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="yes" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="yes" active="no"/>
<layer number="4" name="Route4" color="1" fill="4" visible="yes" active="no"/>
<layer number="5" name="Route5" color="4" fill="4" visible="yes" active="no"/>
<layer number="6" name="Route6" color="1" fill="8" visible="yes" active="no"/>
<layer number="7" name="Route7" color="4" fill="8" visible="yes" active="no"/>
<layer number="8" name="Route8" color="1" fill="2" visible="yes" active="no"/>
<layer number="9" name="Route9" color="4" fill="2" visible="yes" active="no"/>
<layer number="10" name="Route10" color="1" fill="7" visible="yes" active="no"/>
<layer number="11" name="Route11" color="4" fill="7" visible="yes" active="no"/>
<layer number="12" name="Route12" color="1" fill="5" visible="yes" active="no"/>
<layer number="13" name="Route13" color="4" fill="5" visible="yes" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="yes" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="yes" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="yes" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="yes" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="yes" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="yes" active="no"/>
<layer number="20" name="Dimension" color="24" fill="1" visible="yes" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="yes" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="yes" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="yes" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="yes" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="yes" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="yes" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="yes" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="yes" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="yes" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="yes" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="yes" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="yes" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="yes" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="yes" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="yes" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="yes" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="ic">
<packages>
<package name="QFN44">
<wire x1="-3.5" y1="3.5" x2="3.5" y2="3.5" width="0.127" layer="39"/>
<wire x1="3.5" y1="3.5" x2="3.5" y2="-3.5" width="0.127" layer="39"/>
<wire x1="-3.5" y1="3.5" x2="-3.5" y2="-3.5" width="0.127" layer="39"/>
<wire x1="-3.5" y1="-3.5" x2="3.5" y2="-3.5" width="0.127" layer="39"/>
<smd name="45" x="0" y="0" dx="5.12" dy="5.12" layer="1" roundness="20"/>
<smd name="1" x="-3.4" y="2.5" dx="0.25" dy="0.7" layer="1" rot="R270"/>
<circle x="-3.8" y="3.8" radius="0.1" width="0.127" layer="21"/>
<wire x1="-3.5" y1="3.5" x2="-3.5" y2="3.1" width="0.127" layer="21"/>
<wire x1="-3.5" y1="-3.1" x2="-3.5" y2="-3.5" width="0.127" layer="21"/>
<wire x1="-3.5" y1="-3.5" x2="-3.1" y2="-3.5" width="0.127" layer="21"/>
<wire x1="3.1" y1="-3.5" x2="3.5" y2="-3.5" width="0.127" layer="21"/>
<wire x1="3.5" y1="-3.5" x2="3.5" y2="-3.1" width="0.127" layer="21"/>
<wire x1="3.5" y1="3.1" x2="3.5" y2="3.5" width="0.127" layer="21"/>
<wire x1="-3.5" y1="3.5" x2="-3.1" y2="3.5" width="0.127" layer="21"/>
<wire x1="3.1" y1="3.5" x2="3.5" y2="3.5" width="0.127" layer="21"/>
<text x="0" y="4.5" size="0.8128" layer="25" font="vector" align="bottom-center">&gt;NAME</text>
<smd name="2" x="-3.4" y="2" dx="0.25" dy="0.7" layer="1" rot="R270"/>
<smd name="3" x="-3.4" y="1.5" dx="0.25" dy="0.7" layer="1" rot="R270"/>
<smd name="4" x="-3.4" y="1" dx="0.25" dy="0.7" layer="1" rot="R270"/>
<smd name="5" x="-3.4" y="0.5" dx="0.25" dy="0.7" layer="1" rot="R270"/>
<smd name="6" x="-3.4" y="0" dx="0.25" dy="0.7" layer="1" rot="R270"/>
<smd name="7" x="-3.4" y="-0.5" dx="0.25" dy="0.7" layer="1" rot="R270"/>
<smd name="8" x="-3.4" y="-1" dx="0.25" dy="0.7" layer="1" rot="R270"/>
<smd name="9" x="-3.4" y="-1.5" dx="0.25" dy="0.7" layer="1" rot="R270"/>
<smd name="10" x="-3.4" y="-2" dx="0.25" dy="0.7" layer="1" rot="R270"/>
<smd name="11" x="-3.4" y="-2.5" dx="0.25" dy="0.7" layer="1" rot="R270"/>
<smd name="12" x="-2.5" y="-3.4" dx="0.25" dy="0.7" layer="1"/>
<smd name="13" x="-2" y="-3.4" dx="0.25" dy="0.7" layer="1"/>
<smd name="14" x="-1.5" y="-3.4" dx="0.25" dy="0.7" layer="1"/>
<smd name="15" x="-1" y="-3.4" dx="0.25" dy="0.7" layer="1"/>
<smd name="16" x="-0.5" y="-3.4" dx="0.25" dy="0.7" layer="1"/>
<smd name="17" x="0" y="-3.4" dx="0.25" dy="0.7" layer="1"/>
<smd name="18" x="0.5" y="-3.4" dx="0.25" dy="0.7" layer="1"/>
<smd name="19" x="1" y="-3.4" dx="0.25" dy="0.7" layer="1"/>
<smd name="20" x="1.5" y="-3.4" dx="0.25" dy="0.7" layer="1"/>
<smd name="21" x="2" y="-3.4" dx="0.25" dy="0.7" layer="1"/>
<smd name="22" x="2.5" y="-3.4" dx="0.25" dy="0.7" layer="1"/>
<smd name="23" x="3.4" y="-2.5" dx="0.25" dy="0.7" layer="1" rot="R90"/>
<smd name="24" x="3.4" y="-2" dx="0.25" dy="0.7" layer="1" rot="R90"/>
<smd name="25" x="3.4" y="-1.5" dx="0.25" dy="0.7" layer="1" rot="R90"/>
<smd name="26" x="3.4" y="-1" dx="0.25" dy="0.7" layer="1" rot="R90"/>
<smd name="27" x="3.4" y="-0.5" dx="0.25" dy="0.7" layer="1" rot="R90"/>
<smd name="28" x="3.4" y="0" dx="0.25" dy="0.7" layer="1" rot="R90"/>
<smd name="29" x="3.4" y="0.5" dx="0.25" dy="0.7" layer="1" rot="R90"/>
<smd name="30" x="3.4" y="1" dx="0.25" dy="0.7" layer="1" rot="R90"/>
<smd name="31" x="3.4" y="1.5" dx="0.25" dy="0.7" layer="1" rot="R90"/>
<smd name="32" x="3.4" y="2" dx="0.25" dy="0.7" layer="1" rot="R90"/>
<smd name="33" x="3.4" y="2.5" dx="0.25" dy="0.7" layer="1" rot="R90"/>
<smd name="34" x="2.5" y="3.4" dx="0.25" dy="0.7" layer="1" rot="R180"/>
<smd name="35" x="2" y="3.4" dx="0.25" dy="0.7" layer="1" rot="R180"/>
<smd name="36" x="1.5" y="3.4" dx="0.25" dy="0.7" layer="1" rot="R180"/>
<smd name="37" x="1" y="3.4" dx="0.25" dy="0.7" layer="1" rot="R180"/>
<smd name="38" x="0.5" y="3.4" dx="0.25" dy="0.7" layer="1" rot="R180"/>
<smd name="39" x="0" y="3.4" dx="0.25" dy="0.7" layer="1" rot="R180"/>
<smd name="40" x="-0.5" y="3.4" dx="0.25" dy="0.7" layer="1" rot="R180"/>
<smd name="41" x="-1" y="3.4" dx="0.25" dy="0.7" layer="1" rot="R180"/>
<smd name="42" x="-1.5" y="3.4" dx="0.25" dy="0.7" layer="1" rot="R180"/>
<smd name="43" x="-2" y="3.4" dx="0.25" dy="0.7" layer="1" rot="R180"/>
<smd name="44" x="-2.5" y="3.4" dx="0.25" dy="0.7" layer="1" rot="R180"/>
</package>
</packages>
<symbols>
<symbol name="ATMEGA32U4">
<pin name="PB0(SS/PCINT0)" x="-46" y="12" length="middle"/>
<pin name="PB1(PCINT1/SCL)" x="-46" y="9" length="middle"/>
<pin name="PB2(PDI/PCINT2/MOSI)" x="-46" y="6" length="middle"/>
<pin name="PB3(PDO/PCINT3/MISO)" x="-46" y="3" length="middle"/>
<pin name="PB4(PCINT4/ADC11)" x="-46" y="0" length="middle"/>
<pin name="PB5(PCINT5(OC1A/OC4B/ADC12)" x="-46" y="-3" length="middle"/>
<pin name="PB6(PCINT6/OC1B/OC4B/ADC13)" x="-46" y="-6" length="middle"/>
<pin name="PB7(PCINT7/OC0A/OC1C/RTS)" x="-46" y="-9" length="middle"/>
<pin name="PC6(OC3A/OC4A)" x="-46" y="-12" length="middle"/>
<pin name="PC7(ICP3/CLK0/OC4A)" x="-46" y="-15" length="middle"/>
<pin name="PD0(OC0B/SCL/INT0)" x="-16" y="-45" length="middle" rot="R90"/>
<pin name="PD1(SDA/INT1)" x="-13" y="-45" length="middle" rot="R90"/>
<pin name="PD2(RXD1/INT2)" x="-10" y="-45" length="middle" rot="R90"/>
<pin name="PD3(TXD1/INT3)" x="-7" y="-45" length="middle" rot="R90"/>
<pin name="PD4(ICP1/ADC8)" x="-4" y="-45" length="middle" rot="R90"/>
<pin name="PD5(XCK1/CTS)" x="-1" y="-45" length="middle" rot="R90"/>
<pin name="PD6(T1/OC4D/ADC9)" x="2" y="-45" length="middle" rot="R90"/>
<pin name="PD7(T0/OC4D/ADC10)" x="5" y="-45" length="middle" rot="R90"/>
<pin name="PE2(HWB)" x="8" y="-45" length="middle" rot="R90"/>
<pin name="PE6(INT6/AIN0)" x="11" y="-45" length="middle" rot="R90"/>
<wire x1="-41" y1="-18" x2="-38" y2="-18" width="0.1524" layer="94"/>
<wire x1="-41" y1="-18" x2="-41" y2="15" width="0.1524" layer="94"/>
<wire x1="-41" y1="15" x2="-38" y2="15" width="0.1524" layer="94"/>
<wire x1="-19" y1="-40" x2="-19" y2="-37" width="0.1524" layer="94"/>
<wire x1="-19" y1="-40" x2="14" y2="-40" width="0.1524" layer="94"/>
<wire x1="14" y1="-40" x2="14" y2="-37" width="0.1524" layer="94"/>
<pin name="PF0(ADC0)" x="41" y="-9" length="middle" rot="R180"/>
<pin name="PF1(ADC1)" x="41" y="-6" length="middle" rot="R180"/>
<pin name="PF4(ADC4/TCK)" x="41" y="-3" length="middle" rot="R180"/>
<pin name="PF5(ADC5/TMS)" x="41" y="0" length="middle" rot="R180"/>
<pin name="PF6(ADC6/TDO)" x="41" y="3" length="middle" rot="R180"/>
<pin name="PF7(ADC7/TDI)" x="41" y="6" length="middle" rot="R180"/>
<wire x1="36" y1="9" x2="33" y2="9" width="0.1524" layer="94"/>
<wire x1="36" y1="9" x2="36" y2="-12" width="0.1524" layer="94"/>
<wire x1="36" y1="-12" x2="33" y2="-12" width="0.1524" layer="94"/>
<pin name="UGND" x="-19" y="42" length="middle" rot="R270"/>
<pin name="UCAP" x="-16" y="42" length="middle" rot="R270"/>
<pin name="UVCC" x="-13" y="42" length="middle" rot="R270"/>
<pin name="VBUS" x="-10" y="42" length="middle" rot="R270"/>
<pin name="AVCC" x="-7" y="42" length="middle" rot="R270"/>
<pin name="AREF" x="-4" y="42" length="middle" rot="R270"/>
<pin name="GND" x="-1" y="42" length="middle" rot="R270"/>
<pin name="VCC" x="2" y="42" length="middle" rot="R270"/>
<pin name="XTAL1" x="5" y="42" length="middle" rot="R270"/>
<pin name="XTAL2" x="8" y="42" length="middle" rot="R270"/>
<wire x1="-22" y1="37" x2="-22" y2="34" width="0.1524" layer="94"/>
<wire x1="-22" y1="37" x2="20" y2="37" width="0.1524" layer="94"/>
<wire x1="20" y1="37" x2="20" y2="34" width="0.1524" layer="94"/>
<pin name="D-" x="11" y="42" length="middle" rot="R270"/>
<pin name="D+" x="14" y="42" length="middle" rot="R270"/>
<pin name="_RESET" x="17" y="42" length="middle" rot="R270"/>
<text x="-38.1" y="27.94" size="6.4516" layer="95" align="bottom-center">&gt;NAME</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="ATMEGA32U4" prefix="U">
<gates>
<gate name="G$1" symbol="ATMEGA32U4" x="2" y="1"/>
</gates>
<devices>
<device name="" package="QFN44">
<connects>
<connect gate="G$1" pin="AREF" pad="42"/>
<connect gate="G$1" pin="AVCC" pad="24 44"/>
<connect gate="G$1" pin="D+" pad="4"/>
<connect gate="G$1" pin="D-" pad="3"/>
<connect gate="G$1" pin="GND" pad="15 23 35 43 45"/>
<connect gate="G$1" pin="PB0(SS/PCINT0)" pad="8"/>
<connect gate="G$1" pin="PB1(PCINT1/SCL)" pad="9"/>
<connect gate="G$1" pin="PB2(PDI/PCINT2/MOSI)" pad="10"/>
<connect gate="G$1" pin="PB3(PDO/PCINT3/MISO)" pad="11"/>
<connect gate="G$1" pin="PB4(PCINT4/ADC11)" pad="28"/>
<connect gate="G$1" pin="PB5(PCINT5(OC1A/OC4B/ADC12)" pad="29"/>
<connect gate="G$1" pin="PB6(PCINT6/OC1B/OC4B/ADC13)" pad="30"/>
<connect gate="G$1" pin="PB7(PCINT7/OC0A/OC1C/RTS)" pad="12"/>
<connect gate="G$1" pin="PC6(OC3A/OC4A)" pad="31"/>
<connect gate="G$1" pin="PC7(ICP3/CLK0/OC4A)" pad="32"/>
<connect gate="G$1" pin="PD0(OC0B/SCL/INT0)" pad="18"/>
<connect gate="G$1" pin="PD1(SDA/INT1)" pad="19"/>
<connect gate="G$1" pin="PD2(RXD1/INT2)" pad="20"/>
<connect gate="G$1" pin="PD3(TXD1/INT3)" pad="21"/>
<connect gate="G$1" pin="PD4(ICP1/ADC8)" pad="25"/>
<connect gate="G$1" pin="PD5(XCK1/CTS)" pad="22"/>
<connect gate="G$1" pin="PD6(T1/OC4D/ADC9)" pad="26"/>
<connect gate="G$1" pin="PD7(T0/OC4D/ADC10)" pad="27"/>
<connect gate="G$1" pin="PE2(HWB)" pad="33"/>
<connect gate="G$1" pin="PE6(INT6/AIN0)" pad="1"/>
<connect gate="G$1" pin="PF0(ADC0)" pad="41"/>
<connect gate="G$1" pin="PF1(ADC1)" pad="40"/>
<connect gate="G$1" pin="PF4(ADC4/TCK)" pad="39"/>
<connect gate="G$1" pin="PF5(ADC5/TMS)" pad="38"/>
<connect gate="G$1" pin="PF6(ADC6/TDO)" pad="37"/>
<connect gate="G$1" pin="PF7(ADC7/TDI)" pad="36"/>
<connect gate="G$1" pin="UCAP" pad="6"/>
<connect gate="G$1" pin="UGND" pad="5"/>
<connect gate="G$1" pin="UVCC" pad="2"/>
<connect gate="G$1" pin="VBUS" pad="7"/>
<connect gate="G$1" pin="VCC" pad="14 34"/>
<connect gate="G$1" pin="XTAL1" pad="17"/>
<connect gate="G$1" pin="XTAL2" pad="16"/>
<connect gate="G$1" pin="_RESET" pad="13"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="connectors">
<packages>
<package name="3X1_HEADER">
<pad name="3" x="0" y="0" drill="1" diameter="1.6764" rot="R90"/>
<pad name="1" x="0" y="2.54" drill="1" diameter="1.6764" rot="R90"/>
<pad name="5" x="0" y="-2.54" drill="1" diameter="1.6764" rot="R90"/>
<wire x1="-1.27" y1="3.81" x2="1.27" y2="3.81" width="0.127" layer="21"/>
<wire x1="1.27" y1="3.81" x2="1.27" y2="-3.81" width="0.127" layer="21"/>
<wire x1="1.27" y1="-3.81" x2="-1.27" y2="-3.81" width="0.127" layer="21"/>
<wire x1="-1.27" y1="-3.81" x2="-1.27" y2="3.81" width="0.127" layer="21"/>
</package>
<package name="4PIN_FAN_HEADER_THT">
<pad name="2" x="-1.27" y="0" drill="1.14"/>
<pad name="3" x="1.27" y="0" drill="1.14"/>
<pad name="1" x="-3.81" y="0" drill="1.14"/>
<pad name="4" x="3.81" y="0" drill="1.14"/>
<wire x1="-5.005" y1="3.05" x2="-3.81" y2="3.05" width="0.127" layer="21"/>
<wire x1="3.81" y1="3.05" x2="5.005" y2="3.05" width="0.127" layer="21"/>
<wire x1="5.005" y1="3.05" x2="5.005" y2="-3.05" width="0.127" layer="21"/>
<wire x1="5.005" y1="-3.05" x2="-5.005" y2="-3.05" width="0.127" layer="21"/>
<wire x1="-5.005" y1="-3.05" x2="-5.005" y2="3.05" width="0.127" layer="21"/>
<wire x1="-3.81" y1="2.54" x2="3.81" y2="2.54" width="0.127" layer="21"/>
<wire x1="3.81" y1="2.54" x2="3.81" y2="3.05" width="0.127" layer="21"/>
<wire x1="3.81" y1="3.05" x2="-3.81" y2="3.05" width="0.127" layer="21"/>
<wire x1="-3.81" y1="3.05" x2="-3.81" y2="2.54" width="0.127" layer="21"/>
<text x="0" y="5.08" size="1.27" layer="21" align="bottom-center">footprint needs to be updated for offset</text>
</package>
<package name="MOLEX_POWER">
<pad name="2" x="-1.25" y="0" drill="0.85"/>
<pad name="1" x="-3.75" y="0" drill="0.85"/>
<pad name="4" x="3.75" y="0" drill="0.85"/>
<pad name="3" x="1.25" y="0" drill="0.85"/>
<wire x1="-5" y1="1.25" x2="5" y2="1.25" width="0.127" layer="21"/>
<wire x1="5" y1="1.25" x2="5" y2="-0.75" width="0.127" layer="21"/>
<wire x1="5" y1="-0.75" x2="4.5" y2="-1.25" width="0.127" layer="21"/>
<wire x1="4.5" y1="-1.25" x2="-3.5" y2="-1.25" width="0.127" layer="21"/>
<wire x1="-3.5" y1="-1.25" x2="-3.75" y2="-1.25" width="0.127" layer="21"/>
<wire x1="-5" y1="1.25" x2="-5" y2="-0.75" width="0.127" layer="21"/>
<wire x1="-5" y1="-0.75" x2="-4.5" y2="-1.25" width="0.127" layer="21"/>
<wire x1="-4.5" y1="-1.25" x2="-3.75" y2="-1.25" width="0.127" layer="21"/>
<text x="0" y="1.75" size="1.27" layer="21" align="bottom-center">&gt;NAME</text>
</package>
<package name="5X2_HEADER_SMT">
<wire x1="6.35" y1="2.54" x2="6.35" y2="-2.54" width="0.127" layer="21"/>
<wire x1="-6.35" y1="-2.54" x2="-6.35" y2="2.54" width="0.127" layer="21"/>
<smd name="9" x="-2.54" y="2.5" dx="2" dy="3" layer="1"/>
<smd name="2" x="-2.54" y="-2.58" dx="2" dy="3" layer="1"/>
<smd name="8" x="0" y="2.5" dx="2" dy="3" layer="1"/>
<smd name="10" x="-5.08" y="2.5" dx="2" dy="3" layer="1"/>
<smd name="1" x="-5.08" y="-2.58" dx="2" dy="3" layer="1"/>
<smd name="3" x="0" y="-2.58" dx="2" dy="3" layer="1"/>
<smd name="4" x="2.54" y="-2.58" dx="2" dy="3" layer="1"/>
<smd name="5" x="5.08" y="-2.58" dx="2" dy="3" layer="1"/>
<smd name="7" x="2.54" y="2.5" dx="2" dy="3" layer="1"/>
<smd name="6" x="5.08" y="2.5" dx="2" dy="3" layer="1"/>
</package>
<package name="5X2_HEADER">
<pad name="8" x="0" y="1.27" drill="1"/>
<pad name="3" x="0" y="-1.27" drill="1"/>
<pad name="2" x="-2.54" y="-1.27" drill="1"/>
<pad name="9" x="-2.54" y="1.27" drill="1"/>
<pad name="10" x="-5.08" y="1.27" drill="1"/>
<pad name="1" x="-5.08" y="-1.27" drill="1"/>
<pad name="4" x="2.54" y="-1.27" drill="1"/>
<pad name="7" x="2.54" y="1.27" drill="1"/>
<pad name="6" x="5.08" y="1.27" drill="1"/>
<pad name="5" x="5.08" y="-1.27" drill="1"/>
<wire x1="-6.35" y1="2.52" x2="6.35" y2="2.52" width="0.125" layer="21"/>
<wire x1="6.35" y1="2.52" x2="6.35" y2="-2.52" width="0.125" layer="21"/>
<wire x1="6.35" y1="-2.52" x2="-6.35" y2="-2.52" width="0.125" layer="21"/>
<wire x1="-6.35" y1="-2.52" x2="-6.35" y2="2.52" width="0.125" layer="21"/>
<text x="-7" y="0" size="1.4224" layer="21" rot="R90" align="bottom-center">&gt;NAME</text>
</package>
<package name="2X1_HEADER">
<pad name="3" x="0" y="-1.27" drill="1" diameter="1.6764" rot="R90"/>
<pad name="1" x="0" y="1.27" drill="1" diameter="1.6764" shape="square" rot="R90"/>
<wire x1="-1.27" y1="2.54" x2="1.27" y2="2.54" width="0.127" layer="21"/>
<wire x1="1.27" y1="2.54" x2="1.27" y2="-2.54" width="0.127" layer="21"/>
<wire x1="1.27" y1="-2.54" x2="-1.27" y2="-2.54" width="0.127" layer="21"/>
<wire x1="-1.27" y1="-2.54" x2="-1.27" y2="2.54" width="0.127" layer="21"/>
<text x="-1.75" y="0" size="1.4224" layer="21" rot="R90" align="bottom-center">&gt;NAME</text>
</package>
<package name="3X2_HEADER">
<pad name="3" x="-1.27" y="0" drill="1" diameter="1.6764" rot="R90"/>
<pad name="4" x="1.27" y="0" drill="1" diameter="1.6764" rot="R90"/>
<pad name="1" x="-1.27" y="2.54" drill="1" diameter="1.6764" shape="square" rot="R90"/>
<pad name="2" x="1.27" y="2.54" drill="1" diameter="1.6764" rot="R90"/>
<pad name="6" x="1.27" y="-2.54" drill="1" diameter="1.6764" rot="R90"/>
<pad name="5" x="-1.27" y="-2.54" drill="1" diameter="1.6764" rot="R90"/>
<wire x1="-2.54" y1="3.81" x2="2.54" y2="3.81" width="0.127" layer="21"/>
<wire x1="2.54" y1="3.81" x2="2.54" y2="-3.81" width="0.127" layer="21"/>
<wire x1="2.54" y1="-3.81" x2="-2.54" y2="-3.81" width="0.127" layer="21"/>
<wire x1="-2.54" y1="-3.81" x2="-2.54" y2="3.81" width="0.127" layer="21"/>
<circle x="-4" y="3" radius="0.25" width="0.127" layer="21"/>
</package>
<package name="3X2_HEADER_SMT">
<wire x1="3.81" y1="2.54" x2="3.81" y2="-2.54" width="0.127" layer="21"/>
<wire x1="-3.81" y1="-2.54" x2="-3.81" y2="2.54" width="0.127" layer="21"/>
<smd name="4" x="0" y="2.5" dx="2" dy="3" layer="1"/>
<smd name="3" x="0" y="-2.58" dx="2" dy="3" layer="1"/>
<smd name="6" x="2.54" y="2.5" dx="2" dy="3" layer="1"/>
<smd name="2" x="-2.54" y="2.5" dx="2" dy="3" layer="1"/>
<smd name="1" x="-2.54" y="-2.58" dx="2" dy="3" layer="1"/>
<smd name="5" x="2.54" y="-2.58" dx="2" dy="3" layer="1"/>
<wire x1="-0.5" y1="-4.5" x2="0.5" y2="-4.5" width="0.127" layer="21"/>
<wire x1="0.5" y1="-4.5" x2="0.5" y2="-5.5" width="0.127" layer="21"/>
<wire x1="0.5" y1="-5.5" x2="-0.5" y2="-5.5" width="0.127" layer="21"/>
<wire x1="-0.5" y1="-5.5" x2="-0.5" y2="-4.5" width="0.127" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="WS2812_HEADER_3PIN">
<pin name="DATA" x="-8" y="0" length="middle"/>
<pin name="5V" x="-8" y="3" length="middle"/>
<pin name="GND" x="-8" y="-3" length="middle"/>
<wire x1="-3" y1="5" x2="6" y2="5" width="0.254" layer="94"/>
<wire x1="6" y1="5" x2="6" y2="-5" width="0.254" layer="94"/>
<wire x1="6" y1="-5" x2="-3" y2="-5" width="0.254" layer="94"/>
<wire x1="-3" y1="-5" x2="-3" y2="5" width="0.254" layer="94"/>
<text x="1.5" y="6" size="1.778" layer="95" align="bottom-center">&gt;NAME</text>
</symbol>
<symbol name="4PIN_FAN_HEADER">
<pin name="TACH" x="-10.16" y="1" length="middle"/>
<pin name="12V" x="-10.16" y="-2" length="middle"/>
<pin name="PWM" x="-10.16" y="4" length="middle"/>
<pin name="GND" x="-10.16" y="-5" length="middle"/>
<wire x1="-5.08" y1="6.16" x2="4.08" y2="6.16" width="0.254" layer="94"/>
<wire x1="4.08" y1="6.16" x2="4.08" y2="-7.16" width="0.254" layer="94"/>
<wire x1="4.08" y1="-7.16" x2="-5.08" y2="-7.16" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-7.16" x2="-5.08" y2="6.16" width="0.254" layer="94"/>
<text x="0" y="7" size="1.27" layer="95" align="bottom-center">&gt;NAME</text>
</symbol>
<symbol name="MOLEX_POWER">
<pin name="12V" x="-8" y="3" length="middle"/>
<pin name="GND" x="-8" y="0" length="middle"/>
<pin name="5V" x="-8" y="-3" length="middle"/>
<wire x1="-3" y1="5" x2="-3" y2="-5" width="0.254" layer="94"/>
<wire x1="-3" y1="-5" x2="6" y2="-5" width="0.254" layer="94"/>
<wire x1="6" y1="-5" x2="6" y2="5" width="0.254" layer="94"/>
<wire x1="6" y1="5" x2="-3" y2="5" width="0.254" layer="94"/>
<text x="1" y="6" size="1.27" layer="95" align="bottom-center">&gt;NAME</text>
</symbol>
<symbol name="HEADER_10">
<pin name="3" x="-10" y="0" length="middle"/>
<pin name="8" x="10" y="0" length="middle" rot="R180"/>
<pin name="7" x="10" y="-3" length="middle" rot="R180"/>
<pin name="6" x="10" y="-6" length="middle" rot="R180"/>
<pin name="4" x="-10" y="-3" length="middle"/>
<pin name="5" x="-10" y="-6" length="middle"/>
<pin name="2" x="-10" y="3" length="middle"/>
<pin name="1" x="-10" y="6" length="middle"/>
<pin name="10" x="10" y="6" length="middle" rot="R180"/>
<pin name="9" x="10" y="3" length="middle" rot="R180"/>
<wire x1="-5" y1="9" x2="5" y2="9" width="0.254" layer="94"/>
<wire x1="5" y1="9" x2="5" y2="-9" width="0.254" layer="94"/>
<wire x1="5" y1="-9" x2="-5" y2="-9" width="0.254" layer="94"/>
<wire x1="-5" y1="-9" x2="-5" y2="9" width="0.254" layer="94"/>
<text x="0" y="10" size="1.4224" layer="95" align="bottom-center">&gt;NAME</text>
</symbol>
<symbol name="HEADER_2">
<pin name="2" x="-8" y="-3" length="middle"/>
<pin name="1" x="-8" y="3" length="middle"/>
<wire x1="-3" y1="6" x2="-3" y2="-6" width="0.254" layer="94"/>
<wire x1="-3" y1="-6" x2="3" y2="-6" width="0.254" layer="94"/>
<wire x1="3" y1="-6" x2="3" y2="6" width="0.254" layer="94"/>
<wire x1="3" y1="6" x2="-3" y2="6" width="0.254" layer="94"/>
<text x="0" y="7" size="1.4224" layer="95" align="bottom-center">&gt;NAME</text>
</symbol>
<symbol name="ISP_CONN">
<pin name="MISO" x="-13" y="3" length="middle"/>
<pin name="SCK" x="-13" y="0" length="middle"/>
<pin name="RST" x="-13" y="-3" length="middle"/>
<pin name="VCC" x="13" y="3" length="middle" rot="R180"/>
<pin name="MOSI" x="13" y="0" length="middle" rot="R180"/>
<pin name="GND" x="13" y="-3" length="middle" rot="R180"/>
<wire x1="-8" y1="6" x2="8" y2="6" width="0.127" layer="94"/>
<wire x1="8" y1="6" x2="8" y2="-6" width="0.127" layer="94"/>
<wire x1="8" y1="-6" x2="-8" y2="-6" width="0.127" layer="94"/>
<wire x1="-8" y1="-6" x2="-8" y2="6" width="0.127" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="WS2812B_3" prefix="J">
<gates>
<gate name="G$1" symbol="WS2812_HEADER_3PIN" x="0" y="0"/>
</gates>
<devices>
<device name="" package="3X1_HEADER">
<connects>
<connect gate="G$1" pin="5V" pad="1"/>
<connect gate="G$1" pin="DATA" pad="3"/>
<connect gate="G$1" pin="GND" pad="5"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="4PIN_LED_HEADER">
<gates>
<gate name="G$1" symbol="4PIN_FAN_HEADER" x="0" y="0"/>
</gates>
<devices>
<device name="" package="4PIN_FAN_HEADER_THT">
<connects>
<connect gate="G$1" pin="12V" pad="3"/>
<connect gate="G$1" pin="GND" pad="4"/>
<connect gate="G$1" pin="PWM" pad="1"/>
<connect gate="G$1" pin="TACH" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="MOLEX_POWER" prefix="J">
<gates>
<gate name="G$1" symbol="MOLEX_POWER" x="0" y="0"/>
</gates>
<devices>
<device name="" package="MOLEX_POWER">
<connects>
<connect gate="G$1" pin="12V" pad="1"/>
<connect gate="G$1" pin="5V" pad="4"/>
<connect gate="G$1" pin="GND" pad="2 3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="FEMALE_HEADER_5X2" prefix="J">
<gates>
<gate name="G$1" symbol="HEADER_10" x="0" y="0"/>
</gates>
<devices>
<device name="THT" package="5X2_HEADER">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="10" pad="10"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="9" pad="9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="SMT" package="5X2_HEADER_SMT">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="10" pad="10"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="9" pad="9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="FEMALE_HEADER_2X1" prefix="J">
<gates>
<gate name="G$1" symbol="HEADER_2" x="0" y="0"/>
</gates>
<devices>
<device name="" package="2X1_HEADER">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="ISP_CONN_6PIN" prefix="J">
<gates>
<gate name="G$1" symbol="ISP_CONN" x="0" y="0"/>
</gates>
<devices>
<device name="THT" package="3X2_HEADER">
<connects>
<connect gate="G$1" pin="GND" pad="6"/>
<connect gate="G$1" pin="MISO" pad="1"/>
<connect gate="G$1" pin="MOSI" pad="4"/>
<connect gate="G$1" pin="RST" pad="5"/>
<connect gate="G$1" pin="SCK" pad="3"/>
<connect gate="G$1" pin="VCC" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="" package="3X2_HEADER_SMT">
<connects>
<connect gate="G$1" pin="GND" pad="6"/>
<connect gate="G$1" pin="MISO" pad="1"/>
<connect gate="G$1" pin="MOSI" pad="4"/>
<connect gate="G$1" pin="RST" pad="5"/>
<connect gate="G$1" pin="SCK" pad="3"/>
<connect gate="G$1" pin="VCC" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="passive">
<packages>
<package name="MFR25">
<pad name="P$1" x="-5" y="0" drill="0.8" diameter="1.6764"/>
<pad name="P$2" x="5" y="0" drill="0.8" diameter="1.6764"/>
<wire x1="-3.5" y1="0" x2="-3.5" y2="1.5" width="0.127" layer="21"/>
<wire x1="-3.5" y1="1.5" x2="3.5" y2="1.5" width="0.127" layer="21"/>
<wire x1="3.5" y1="1.5" x2="3.5" y2="-1.5" width="0.127" layer="21"/>
<wire x1="3.5" y1="-1.5" x2="-3.5" y2="-1.5" width="0.127" layer="21"/>
<wire x1="-3.5" y1="-1.5" x2="-3.5" y2="0" width="0.127" layer="21"/>
<text x="0" y="0" size="1.27" layer="25" align="center">&gt;NAME</text>
</package>
<package name="0805">
<smd name="1" x="-0.95" y="0" dx="1.3" dy="0.7" layer="1" rot="R90"/>
<smd name="2" x="0.95" y="0" dx="1.3" dy="0.7" layer="1" rot="R270"/>
<text x="0" y="0.75" size="0.6096" layer="21" font="vector" align="bottom-center">&gt;NAME</text>
<wire x1="-0.425" y1="0.625" x2="0.425" y2="0.625" width="0.127" layer="21"/>
<wire x1="0.425" y1="-0.625" x2="-0.425" y2="-0.625" width="0.127" layer="21"/>
</package>
<package name="CAP_RADIAL_SMALL">
<pad name="1" x="-1" y="0" drill="0.8" diameter="1.4224"/>
<pad name="2" x="1" y="0" drill="0.8" diameter="1.4224"/>
<circle x="0" y="0" radius="2.5" width="0.127" layer="21"/>
<text x="-0.8" y="1.25" size="1.27" layer="21" align="center">+</text>
<text x="0" y="-2" size="0.8128" layer="21" font="vector" align="bottom-center">&gt;NAME</text>
</package>
<package name="DIELECTRIC_MED">
<pad name="1" x="-1.5" y="0" drill="0.8" diameter="1.4224"/>
<pad name="2" x="1.5" y="0" drill="0.8" diameter="1.4224"/>
<circle x="0" y="0" radius="3.2" width="0.127" layer="21"/>
<text x="-2" y="1" size="1.27" layer="21">+</text>
</package>
<package name="0402">
<smd name="1" x="-0.5" y="0" dx="0.5" dy="0.5" layer="1" rot="R90"/>
<smd name="2" x="0.5" y="0" dx="0.5" dy="0.5" layer="1" rot="R270"/>
<text x="0" y="0.75" size="0.6096" layer="21" font="vector" align="bottom-center">&gt;NAME</text>
<wire x1="-0.425" y1="0.625" x2="0.425" y2="0.625" width="0.127" layer="21"/>
<wire x1="0.425" y1="-0.625" x2="-0.425" y2="-0.625" width="0.127" layer="21"/>
</package>
<package name="QCL">
<pad name="P$1" x="-2.44" y="0" drill="0.6"/>
<pad name="P$2" x="2.44" y="0" drill="0.6" rot="R180"/>
<wire x1="-3" y1="2.375" x2="-3" y2="-2.375" width="0.127" layer="21" curve="180"/>
<wire x1="3" y1="-2.375" x2="3" y2="2.375" width="0.127" layer="21" curve="180"/>
<wire x1="-3" y1="2.375" x2="3" y2="2.375" width="0.127" layer="21"/>
<wire x1="-3" y1="-2.375" x2="3" y2="-2.375" width="0.127" layer="21"/>
</package>
<package name="3.2X2.5_OSC">
<smd name="4" x="-1.25" y="0.875" dx="1.4" dy="1.6" layer="1" rot="R90"/>
<smd name="1" x="-1.25" y="-0.875" dx="1.4" dy="1.6" layer="1" rot="R90"/>
<smd name="3" x="1.25" y="0.875" dx="1.4" dy="1.6" layer="1" rot="R90"/>
<smd name="2" x="1.25" y="-0.875" dx="1.4" dy="1.6" layer="1" rot="R90"/>
<text x="0" y="1.81" size="1.27" layer="25" align="bottom-center">&gt;NAME</text>
<wire x1="2.5" y1="1.6" x2="2.5" y2="-1.6" width="0.127" layer="21"/>
<wire x1="-2.5" y1="-1.6" x2="-2.5" y2="1.6" width="0.127" layer="21"/>
<wire x1="-2.5" y1="1.6" x2="-2.3" y2="1.6" width="0.127" layer="21"/>
<wire x1="-0.2" y1="1.6" x2="0.2" y2="1.6" width="0.127" layer="21"/>
<wire x1="2.3" y1="1.6" x2="2.5" y2="1.6" width="0.127" layer="21"/>
<wire x1="-2.5" y1="-1.6" x2="-2.3" y2="-1.6" width="0.127" layer="21"/>
<wire x1="-0.2" y1="-1.6" x2="0.2" y2="-1.6" width="0.127" layer="21"/>
<wire x1="2.3" y1="-1.6" x2="2.5" y2="-1.6" width="0.127" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="RESISTOR">
<pin name="1" x="-4.46" y="0" visible="off" length="short"/>
<pin name="2" x="4.46" y="0" visible="off" length="short" rot="R180"/>
<text x="0" y="2" size="1.778" layer="95" align="bottom-center">&gt;NAME</text>
<text x="0" y="-2" size="1.778" layer="96" align="top-center">&gt;VALUE</text>
<wire x1="-2" y1="0" x2="-1.27" y2="1.016" width="0.254" layer="94"/>
<wire x1="-1.27" y1="1.016" x2="0" y2="-0.762" width="0.254" layer="94"/>
<wire x1="0" y1="-0.762" x2="1.016" y2="1.016" width="0.254" layer="94"/>
<wire x1="1.016" y1="1.016" x2="1.778" y2="0" width="0.254" layer="94"/>
</symbol>
<symbol name="CAPACITOR">
<pin name="P$1" x="-3.46" y="0" visible="off" length="short"/>
<pin name="P$2" x="3.46" y="0" visible="off" length="short" rot="R180"/>
<wire x1="-1" y1="3" x2="-1" y2="-3" width="0.254" layer="94"/>
<wire x1="2" y1="-3" x2="2" y2="3" width="0.254" layer="94" curve="-90"/>
<text x="-1" y="0" size="1.778" layer="94" rot="R90">+</text>
<text x="0" y="4" size="1.778" layer="95" align="bottom-center">&gt;NAME</text>
<text x="0" y="-4" size="1.778" layer="96" align="top-center">&gt;VALUE</text>
</symbol>
<symbol name="QUARTZ">
<pin name="P$1" x="-8" y="0" visible="off" length="middle"/>
<wire x1="-2.5" y1="6" x2="-2.5" y2="0" width="0.254" layer="94"/>
<wire x1="-2.5" y1="0" x2="-2.5" y2="-6" width="0.254" layer="94"/>
<wire x1="-1.5" y1="5" x2="-1.5" y2="-5" width="0.254" layer="94"/>
<wire x1="-1.5" y1="-5" x2="1.5" y2="-5" width="0.254" layer="94"/>
<wire x1="1.5" y1="-5" x2="1.5" y2="5" width="0.254" layer="94"/>
<wire x1="1.5" y1="5" x2="-1.5" y2="5" width="0.254" layer="94"/>
<wire x1="2.5" y1="6" x2="2.5" y2="0" width="0.254" layer="94"/>
<pin name="P$2" x="8" y="0" visible="off" length="middle" rot="R180"/>
<wire x1="2.5" y1="0" x2="2.5" y2="-6" width="0.254" layer="94"/>
<wire x1="-3" y1="0" x2="-2.5" y2="0" width="0.1524" layer="94"/>
<wire x1="2.5" y1="0" x2="3" y2="0" width="0.1524" layer="94"/>
<text x="0" y="7" size="1.27" layer="95" align="bottom-center">&gt;NAME</text>
<text x="0" y="-7" size="1.27" layer="95" rot="R180" align="bottom-center">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="RESISTOR" prefix="R" uservalue="yes">
<gates>
<gate name="G$1" symbol="RESISTOR" x="0" y="0"/>
</gates>
<devices>
<device name="THT" package="MFR25">
<connects>
<connect gate="G$1" pin="1" pad="P$1"/>
<connect gate="G$1" pin="2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="" package="0805">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="CAPACITOR" prefix="C" uservalue="yes">
<gates>
<gate name="G$1" symbol="CAPACITOR" x="0" y="0"/>
</gates>
<devices>
<device name="RADIAL_SMALL" package="CAP_RADIAL_SMALL">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="RADIAL_MED" package="DIELECTRIC_MED">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="0805" package="0805">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="0402" package="0402">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="QUARTZ" prefix="X" uservalue="yes">
<gates>
<gate name="G$1" symbol="QUARTZ" x="0" y="0"/>
</gates>
<devices>
<device name="TH" package="QCL">
<connects>
<connect gate="G$1" pin="P$1" pad="P$1"/>
<connect gate="G$1" pin="P$2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="" package="3.2X2.5_OSC">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$2" pad="3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="opto">
<packages>
<package name="T1">
<pad name="1" x="-1.27" y="0" drill="0.7" diameter="1.4224"/>
<pad name="2" x="1.27" y="0" drill="0.7" diameter="1.4224"/>
<text x="-0.95" y="1.25" size="1.27" layer="21" font="vector" align="center">+</text>
<circle x="0" y="0" radius="2.2" width="0.127" layer="21"/>
<text x="-2.25" y="2.25" size="1.27" layer="21" rot="R180">&gt;NAME</text>
</package>
<package name="0805">
<smd name="1" x="-0.95" y="0" dx="1.3" dy="0.7" layer="1" rot="R90"/>
<smd name="2" x="0.95" y="0" dx="1.3" dy="0.7" layer="1" rot="R270"/>
<wire x1="-0.4" y1="0.4" x2="-0.4" y2="-0.4" width="0.127" layer="21"/>
<wire x1="-0.4" y1="-0.4" x2="0.4" y2="0" width="0.127" layer="21"/>
<wire x1="0.4" y1="0" x2="-0.4" y2="0.4" width="0.127" layer="21"/>
<wire x1="0.4" y1="0.4" x2="0.4" y2="0" width="0.127" layer="21"/>
<wire x1="0.4" y1="0" x2="0.4" y2="-0.4" width="0.127" layer="21"/>
<text x="1.5" y="0" size="0.4064" layer="25" font="vector" rot="R90" align="top-center">&gt;NAME</text>
</package>
</packages>
<symbols>
<symbol name="LED">
<pin name="1" x="-3.46" y="0" visible="off" length="short"/>
<pin name="2" x="3.46" y="0" visible="off" length="short" rot="R180"/>
<wire x1="-1" y1="1" x2="-1" y2="-1" width="0.254" layer="94"/>
<wire x1="-1" y1="-1" x2="1" y2="0" width="0.254" layer="94"/>
<wire x1="1" y1="0" x2="-1" y2="1" width="0.254" layer="94"/>
<wire x1="1" y1="1" x2="1" y2="0" width="0.254" layer="94"/>
<text x="-3" y="2" size="1.778" layer="96">&gt;NAME</text>
<text x="-3" y="-5" size="1.778" layer="96">&gt;VALUE</text>
<wire x1="1" y1="0" x2="1" y2="-1" width="0.254" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="LED" prefix="D" uservalue="yes">
<gates>
<gate name="G$1" symbol="LED" x="1" y="0" addlevel="must"/>
</gates>
<devices>
<device name="T1" package="T1">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="" package="0805">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U1" library="ic" deviceset="ATMEGA32U4" device=""/>
<part name="PUMP" library="connectors" deviceset="4PIN_LED_HEADER" device=""/>
<part name="PWM_IN" library="connectors" deviceset="4PIN_LED_HEADER" device=""/>
<part name="R1" library="passive" deviceset="RESISTOR" device="" value="3.3k"/>
<part name="LED_4" library="connectors" deviceset="WS2812B_3" device=""/>
<part name="R5" library="passive" deviceset="RESISTOR" device="" value="470"/>
<part name="C6" library="passive" deviceset="CAPACITOR" device="0805" value="470u"/>
<part name="LED_1" library="connectors" deviceset="WS2812B_3" device=""/>
<part name="R2" library="passive" deviceset="RESISTOR" device="" value="470"/>
<part name="C1" library="passive" deviceset="CAPACITOR" device="0805" value="470u"/>
<part name="LED_2" library="connectors" deviceset="WS2812B_3" device=""/>
<part name="R3" library="passive" deviceset="RESISTOR" device="" value="470"/>
<part name="C2" library="passive" deviceset="CAPACITOR" device="0805" value="470u"/>
<part name="LED_3" library="connectors" deviceset="WS2812B_3" device=""/>
<part name="R4" library="passive" deviceset="RESISTOR" device="" value="470"/>
<part name="C3" library="passive" deviceset="CAPACITOR" device="0805" value="470u"/>
<part name="LED_5" library="connectors" deviceset="WS2812B_3" device=""/>
<part name="R6" library="passive" deviceset="RESISTOR" device="" value="470"/>
<part name="C4" library="passive" deviceset="CAPACITOR" device="0805" value="470u"/>
<part name="LED_6" library="connectors" deviceset="WS2812B_3" device=""/>
<part name="R7" library="passive" deviceset="RESISTOR" device="" value="470"/>
<part name="C5" library="passive" deviceset="CAPACITOR" device="0805" value="470u"/>
<part name="LED_7" library="connectors" deviceset="WS2812B_3" device=""/>
<part name="R8" library="passive" deviceset="RESISTOR" device="" value="470"/>
<part name="C7" library="passive" deviceset="CAPACITOR" device="0805" value="470u"/>
<part name="LED_8" library="connectors" deviceset="WS2812B_3" device=""/>
<part name="R9" library="passive" deviceset="RESISTOR" device="" value="470"/>
<part name="C8" library="passive" deviceset="CAPACITOR" device="0805" value="470u"/>
<part name="MOLEX" library="connectors" deviceset="MOLEX_POWER" device=""/>
<part name="J1" library="connectors" deviceset="FEMALE_HEADER_5X2" device="SMT"/>
<part name="X1" library="passive" deviceset="QUARTZ" device="" value="16MHz"/>
<part name="C9" library="passive" deviceset="CAPACITOR" device="0805"/>
<part name="C10" library="passive" deviceset="CAPACITOR" device="0805"/>
<part name="USR_LED" library="opto" deviceset="LED" device=""/>
<part name="R10" library="passive" deviceset="RESISTOR" device="" value="330"/>
<part name="TEMP1" library="connectors" deviceset="FEMALE_HEADER_2X1" device=""/>
<part name="R11" library="passive" deviceset="RESISTOR" device=""/>
<part name="TEMP2" library="connectors" deviceset="FEMALE_HEADER_2X1" device=""/>
<part name="R12" library="passive" deviceset="RESISTOR" device=""/>
<part name="R14" library="passive" deviceset="RESISTOR" device=""/>
<part name="J2" library="connectors" deviceset="ISP_CONN_6PIN" device=""/>
</parts>
<sheets>
<sheet>
<plain>
<wire x1="65" y1="43" x2="103" y2="43" width="0.1524" layer="97"/>
<wire x1="103" y1="43" x2="103" y2="1" width="0.1524" layer="97"/>
<wire x1="103" y1="1" x2="65" y2="1" width="0.1524" layer="97"/>
<wire x1="65" y1="1" x2="65" y2="43" width="0.1524" layer="97"/>
<text x="85" y="44" size="1.778" layer="97" align="bottom-center">pump</text>
<wire x1="41" y1="-15" x2="166" y2="-15" width="0.1524" layer="97"/>
<wire x1="166" y1="-15" x2="166" y2="-124" width="0.1524" layer="97"/>
<wire x1="166" y1="-124" x2="41" y2="-124" width="0.1524" layer="97"/>
<wire x1="41" y1="-124" x2="41" y2="-15" width="0.1524" layer="97"/>
<text x="106" y="-14" size="1.778" layer="97" align="bottom-center">LEDS</text>
<wire x1="57" y1="101" x2="57" y2="73" width="0.1524" layer="97"/>
<wire x1="57" y1="73" x2="150" y2="73" width="0.1524" layer="97"/>
<wire x1="150" y1="73" x2="150" y2="101" width="0.1524" layer="97"/>
<wire x1="150" y1="101" x2="57" y2="101" width="0.1524" layer="97"/>
<text x="104" y="102" size="1.778" layer="97" align="bottom-center">connectors</text>
<wire x1="-65.5" y1="-61" x2="-1.5" y2="-61" width="0.1524" layer="97"/>
<wire x1="-1.5" y1="-61" x2="-1.5" y2="-120.5" width="0.1524" layer="97"/>
<wire x1="-1.5" y1="-120.5" x2="-65.5" y2="-120.5" width="0.1524" layer="97"/>
<wire x1="-65.5" y1="-120.5" x2="-65.5" y2="-61" width="0.1524" layer="97"/>
<text x="-30.5" y="-60" size="1.778" layer="97" align="bottom-center">TEMPS</text>
</plain>
<instances>
<instance part="U1" gate="G$1" x="-30" y="13"/>
<instance part="PUMP" gate="G$1" x="96" y="28"/>
<instance part="PWM_IN" gate="G$1" x="96" y="11"/>
<instance part="R1" gate="G$1" x="79" y="38" rot="R180"/>
<instance part="LED_4" gate="G$1" x="91" y="-83"/>
<instance part="R5" gate="G$1" x="63" y="-83" rot="R180"/>
<instance part="C6" gate="G$1" x="78" y="-73"/>
<instance part="LED_1" gate="G$1" x="91" y="-59"/>
<instance part="R2" gate="G$1" x="63" y="-59" rot="R180"/>
<instance part="C1" gate="G$1" x="78" y="-49"/>
<instance part="LED_2" gate="G$1" x="91" y="-37"/>
<instance part="R3" gate="G$1" x="63" y="-37" rot="R180"/>
<instance part="C2" gate="G$1" x="78" y="-27"/>
<instance part="LED_3" gate="G$1" x="91" y="-106"/>
<instance part="R4" gate="G$1" x="63" y="-106" rot="R180"/>
<instance part="C3" gate="G$1" x="78" y="-96"/>
<instance part="LED_5" gate="G$1" x="149" y="-83"/>
<instance part="R6" gate="G$1" x="121" y="-83" rot="R180"/>
<instance part="C4" gate="G$1" x="136" y="-73"/>
<instance part="LED_6" gate="G$1" x="149" y="-59"/>
<instance part="R7" gate="G$1" x="121" y="-59" rot="R180"/>
<instance part="C5" gate="G$1" x="136" y="-49"/>
<instance part="LED_7" gate="G$1" x="149" y="-37"/>
<instance part="R8" gate="G$1" x="121" y="-37" rot="R180"/>
<instance part="C7" gate="G$1" x="136" y="-27"/>
<instance part="LED_8" gate="G$1" x="149" y="-106"/>
<instance part="R9" gate="G$1" x="121" y="-106" rot="R180"/>
<instance part="C8" gate="G$1" x="136" y="-96"/>
<instance part="MOLEX" gate="G$1" x="78" y="83"/>
<instance part="J1" gate="G$1" x="119" y="83"/>
<instance part="X1" gate="G$1" x="-24" y="85"/>
<instance part="C9" gate="G$1" x="-38" y="85" rot="R180"/>
<instance part="C10" gate="G$1" x="-10" y="85"/>
<instance part="USR_LED" gate="G$1" x="136" y="24"/>
<instance part="R10" gate="G$1" x="125" y="24"/>
<instance part="TEMP1" gate="G$1" x="-17.5" y="-79"/>
<instance part="R11" gate="G$1" x="-35" y="-76"/>
<instance part="TEMP2" gate="G$1" x="-17.5" y="-100.5"/>
<instance part="R12" gate="G$1" x="-35" y="-97.5"/>
<instance part="R14" gate="G$1" x="-31.5" y="-115.5"/>
<instance part="J2" gate="G$1" x="27.5" y="55.5"/>
</instances>
<busses>
</busses>
<nets>
<net name="PUMP_PWM" class="0">
<segment>
<pinref part="PUMP" gate="G$1" pin="PWM"/>
<wire x1="85.84" y1="32" x2="85" y2="32" width="0.1524" layer="91"/>
<label x="80" y="32" size="1.778" layer="95" rot="R180"/>
<pinref part="R1" gate="G$1" pin="1"/>
<wire x1="85" y1="32" x2="80" y2="32" width="0.1524" layer="91"/>
<wire x1="83.46" y1="38" x2="85" y2="38" width="0.1524" layer="91"/>
<wire x1="85" y1="38" x2="85" y2="32" width="0.1524" layer="91"/>
<junction x="85" y="32"/>
</segment>
<segment>
<pinref part="PWM_IN" gate="G$1" pin="PWM"/>
<wire x1="85.84" y1="15" x2="80" y2="15" width="0.1524" layer="91"/>
<label x="80" y="15" size="1.778" layer="95" rot="R180"/>
</segment>
</net>
<net name="PUMP_TACH" class="0">
<segment>
<pinref part="PUMP" gate="G$1" pin="TACH"/>
<wire x1="85.84" y1="29" x2="80" y2="29" width="0.1524" layer="91"/>
<label x="80" y="29" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="PWM_IN" gate="G$1" pin="TACH"/>
<wire x1="85.84" y1="12" x2="80" y2="12" width="0.1524" layer="91"/>
<label x="80" y="12" size="1.778" layer="95" rot="R180"/>
</segment>
</net>
<net name="PUMP_12" class="0">
<segment>
<pinref part="PUMP" gate="G$1" pin="12V"/>
<wire x1="85.84" y1="26" x2="80" y2="26" width="0.1524" layer="91"/>
<label x="80" y="26" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="PWM_IN" gate="G$1" pin="12V"/>
<wire x1="80" y1="9" x2="85.84" y2="9" width="0.1524" layer="91"/>
<label x="80" y="9" size="1.778" layer="95" rot="R180"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="PUMP" gate="G$1" pin="GND"/>
<wire x1="85.84" y1="23" x2="80" y2="23" width="0.1524" layer="91"/>
<label x="80" y="23" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="PWM_IN" gate="G$1" pin="GND"/>
<wire x1="85.84" y1="6" x2="80" y2="6" width="0.1524" layer="91"/>
<label x="80" y="6" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="LED_4" gate="G$1" pin="GND"/>
<wire x1="83" y1="-86" x2="71" y2="-86" width="0.1524" layer="91"/>
<label x="71" y="-86" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="C6" gate="G$1" pin="P$2"/>
<wire x1="81.46" y1="-73" x2="84" y2="-73" width="0.1524" layer="91"/>
<label x="84" y="-73" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="LED_1" gate="G$1" pin="GND"/>
<wire x1="83" y1="-62" x2="71" y2="-62" width="0.1524" layer="91"/>
<label x="71" y="-62" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="C1" gate="G$1" pin="P$2"/>
<wire x1="81.46" y1="-49" x2="84" y2="-49" width="0.1524" layer="91"/>
<label x="84" y="-49" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="LED_2" gate="G$1" pin="GND"/>
<wire x1="83" y1="-40" x2="71" y2="-40" width="0.1524" layer="91"/>
<label x="71" y="-40" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="C2" gate="G$1" pin="P$2"/>
<wire x1="81.46" y1="-27" x2="84" y2="-27" width="0.1524" layer="91"/>
<label x="84" y="-27" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="LED_3" gate="G$1" pin="GND"/>
<wire x1="83" y1="-109" x2="71" y2="-109" width="0.1524" layer="91"/>
<label x="71" y="-109" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="C3" gate="G$1" pin="P$2"/>
<wire x1="81.46" y1="-96" x2="84" y2="-96" width="0.1524" layer="91"/>
<label x="84" y="-96" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="LED_5" gate="G$1" pin="GND"/>
<wire x1="141" y1="-86" x2="129" y2="-86" width="0.1524" layer="91"/>
<label x="129" y="-86" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="C4" gate="G$1" pin="P$2"/>
<wire x1="139.46" y1="-73" x2="142" y2="-73" width="0.1524" layer="91"/>
<label x="142" y="-73" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="LED_6" gate="G$1" pin="GND"/>
<wire x1="141" y1="-62" x2="129" y2="-62" width="0.1524" layer="91"/>
<label x="129" y="-62" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="C5" gate="G$1" pin="P$2"/>
<wire x1="139.46" y1="-49" x2="142" y2="-49" width="0.1524" layer="91"/>
<label x="142" y="-49" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="LED_7" gate="G$1" pin="GND"/>
<wire x1="141" y1="-40" x2="129" y2="-40" width="0.1524" layer="91"/>
<label x="129" y="-40" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="C7" gate="G$1" pin="P$2"/>
<wire x1="139.46" y1="-27" x2="142" y2="-27" width="0.1524" layer="91"/>
<label x="142" y="-27" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="LED_8" gate="G$1" pin="GND"/>
<wire x1="141" y1="-109" x2="129" y2="-109" width="0.1524" layer="91"/>
<label x="129" y="-109" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="C8" gate="G$1" pin="P$2"/>
<wire x1="139.46" y1="-96" x2="142" y2="-96" width="0.1524" layer="91"/>
<label x="142" y="-96" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="MOLEX" gate="G$1" pin="GND"/>
<wire x1="70" y1="83" x2="64" y2="83" width="0.1524" layer="91"/>
<label x="64" y="83" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="J1" gate="G$1" pin="7"/>
<wire x1="138" y1="80" x2="129" y2="80" width="0.1524" layer="91"/>
<label x="138" y="80" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="UGND"/>
<wire x1="-49" y1="55" x2="-49" y2="65" width="0.1524" layer="91"/>
<label x="-49" y="65" size="1.778" layer="95" rot="R90"/>
</segment>
<segment>
<pinref part="C9" gate="G$1" pin="P$2"/>
<wire x1="-41.46" y1="85" x2="-44" y2="85" width="0.1524" layer="91"/>
<label x="-44" y="85" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="C10" gate="G$1" pin="P$2"/>
<wire x1="-6.54" y1="85" x2="-3" y2="85" width="0.1524" layer="91"/>
<label x="-3" y="85" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="GND"/>
<wire x1="-31" y1="55" x2="-31" y2="65" width="0.1524" layer="91"/>
<label x="-31" y="65" size="1.778" layer="95" rot="R90"/>
</segment>
<segment>
<pinref part="USR_LED" gate="G$1" pin="2"/>
<wire x1="139.46" y1="24" x2="144" y2="24" width="0.1524" layer="91"/>
<label x="144" y="24" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="R14" gate="G$1" pin="1"/>
<wire x1="-35.96" y1="-115.5" x2="-41" y2="-115.5" width="0.1524" layer="91"/>
<label x="-41" y="-115.5" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="J2" gate="G$1" pin="GND"/>
<wire x1="40.5" y1="52.5" x2="53" y2="52.5" width="0.1524" layer="91"/>
<label x="53" y="52.5" size="1.778" layer="95"/>
</segment>
</net>
<net name="5V" class="0">
<segment>
<pinref part="R1" gate="G$1" pin="2"/>
<wire x1="74.54" y1="38" x2="73" y2="38" width="0.1524" layer="91"/>
<label x="73" y="38" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="LED_4" gate="G$1" pin="5V"/>
<wire x1="83" y1="-80" x2="73" y2="-80" width="0.1524" layer="91"/>
<label x="71" y="-80" size="1.778" layer="95" rot="R180"/>
<pinref part="C6" gate="G$1" pin="P$1"/>
<wire x1="73" y1="-80" x2="71" y2="-80" width="0.1524" layer="91"/>
<wire x1="74.54" y1="-73" x2="73" y2="-73" width="0.1524" layer="91"/>
<wire x1="73" y1="-73" x2="73" y2="-80" width="0.1524" layer="91"/>
<junction x="73" y="-80"/>
</segment>
<segment>
<pinref part="LED_1" gate="G$1" pin="5V"/>
<wire x1="83" y1="-56" x2="73" y2="-56" width="0.1524" layer="91"/>
<label x="71" y="-56" size="1.778" layer="95" rot="R180"/>
<pinref part="C1" gate="G$1" pin="P$1"/>
<wire x1="73" y1="-56" x2="71" y2="-56" width="0.1524" layer="91"/>
<wire x1="74.54" y1="-49" x2="73" y2="-49" width="0.1524" layer="91"/>
<wire x1="73" y1="-49" x2="73" y2="-56" width="0.1524" layer="91"/>
<junction x="73" y="-56"/>
</segment>
<segment>
<pinref part="LED_2" gate="G$1" pin="5V"/>
<wire x1="83" y1="-34" x2="73" y2="-34" width="0.1524" layer="91"/>
<label x="71" y="-34" size="1.778" layer="95" rot="R180"/>
<pinref part="C2" gate="G$1" pin="P$1"/>
<wire x1="73" y1="-34" x2="71" y2="-34" width="0.1524" layer="91"/>
<wire x1="74.54" y1="-27" x2="73" y2="-27" width="0.1524" layer="91"/>
<wire x1="73" y1="-27" x2="73" y2="-34" width="0.1524" layer="91"/>
<junction x="73" y="-34"/>
</segment>
<segment>
<pinref part="LED_3" gate="G$1" pin="5V"/>
<wire x1="83" y1="-103" x2="73" y2="-103" width="0.1524" layer="91"/>
<label x="71" y="-103" size="1.778" layer="95" rot="R180"/>
<pinref part="C3" gate="G$1" pin="P$1"/>
<wire x1="73" y1="-103" x2="71" y2="-103" width="0.1524" layer="91"/>
<wire x1="74.54" y1="-96" x2="73" y2="-96" width="0.1524" layer="91"/>
<wire x1="73" y1="-96" x2="73" y2="-103" width="0.1524" layer="91"/>
<junction x="73" y="-103"/>
</segment>
<segment>
<pinref part="LED_5" gate="G$1" pin="5V"/>
<wire x1="141" y1="-80" x2="131" y2="-80" width="0.1524" layer="91"/>
<label x="129" y="-80" size="1.778" layer="95" rot="R180"/>
<pinref part="C4" gate="G$1" pin="P$1"/>
<wire x1="131" y1="-80" x2="129" y2="-80" width="0.1524" layer="91"/>
<wire x1="132.54" y1="-73" x2="131" y2="-73" width="0.1524" layer="91"/>
<wire x1="131" y1="-73" x2="131" y2="-80" width="0.1524" layer="91"/>
<junction x="131" y="-80"/>
</segment>
<segment>
<pinref part="LED_6" gate="G$1" pin="5V"/>
<wire x1="141" y1="-56" x2="131" y2="-56" width="0.1524" layer="91"/>
<label x="129" y="-56" size="1.778" layer="95" rot="R180"/>
<pinref part="C5" gate="G$1" pin="P$1"/>
<wire x1="131" y1="-56" x2="129" y2="-56" width="0.1524" layer="91"/>
<wire x1="132.54" y1="-49" x2="131" y2="-49" width="0.1524" layer="91"/>
<wire x1="131" y1="-49" x2="131" y2="-56" width="0.1524" layer="91"/>
<junction x="131" y="-56"/>
</segment>
<segment>
<pinref part="LED_7" gate="G$1" pin="5V"/>
<wire x1="141" y1="-34" x2="131" y2="-34" width="0.1524" layer="91"/>
<label x="129" y="-34" size="1.778" layer="95" rot="R180"/>
<pinref part="C7" gate="G$1" pin="P$1"/>
<wire x1="131" y1="-34" x2="129" y2="-34" width="0.1524" layer="91"/>
<wire x1="132.54" y1="-27" x2="131" y2="-27" width="0.1524" layer="91"/>
<wire x1="131" y1="-27" x2="131" y2="-34" width="0.1524" layer="91"/>
<junction x="131" y="-34"/>
</segment>
<segment>
<pinref part="LED_8" gate="G$1" pin="5V"/>
<wire x1="141" y1="-103" x2="131" y2="-103" width="0.1524" layer="91"/>
<label x="129" y="-103" size="1.778" layer="95" rot="R180"/>
<pinref part="C8" gate="G$1" pin="P$1"/>
<wire x1="131" y1="-103" x2="129" y2="-103" width="0.1524" layer="91"/>
<wire x1="132.54" y1="-96" x2="131" y2="-96" width="0.1524" layer="91"/>
<wire x1="131" y1="-96" x2="131" y2="-103" width="0.1524" layer="91"/>
<junction x="131" y="-103"/>
</segment>
<segment>
<pinref part="MOLEX" gate="G$1" pin="5V"/>
<wire x1="70" y1="80" x2="64" y2="80" width="0.1524" layer="91"/>
<label x="64" y="80" size="1.778" layer="95" rot="R180"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="R5" gate="G$1" pin="1"/>
<pinref part="LED_4" gate="G$1" pin="DATA"/>
<wire x1="67.46" y1="-83" x2="83" y2="-83" width="0.1524" layer="91"/>
</segment>
</net>
<net name="LED_4" class="0">
<segment>
<pinref part="R4" gate="G$1" pin="2"/>
<wire x1="58.54" y1="-106" x2="56" y2="-106" width="0.1524" layer="91"/>
<label x="56" y="-106" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="PF6(ADC6/TDO)"/>
<wire x1="11" y1="16" x2="20" y2="16" width="0.1524" layer="91"/>
<label x="20" y="16" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<pinref part="R2" gate="G$1" pin="1"/>
<pinref part="LED_1" gate="G$1" pin="DATA"/>
<wire x1="67.46" y1="-59" x2="83" y2="-59" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="R3" gate="G$1" pin="1"/>
<pinref part="LED_2" gate="G$1" pin="DATA"/>
<wire x1="67.46" y1="-37" x2="83" y2="-37" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="R4" gate="G$1" pin="1"/>
<pinref part="LED_3" gate="G$1" pin="DATA"/>
<wire x1="67.46" y1="-106" x2="83" y2="-106" width="0.1524" layer="91"/>
</segment>
</net>
<net name="LED_1" class="0">
<segment>
<pinref part="R3" gate="G$1" pin="2"/>
<wire x1="58.54" y1="-37" x2="56" y2="-37" width="0.1524" layer="91"/>
<label x="56" y="-37" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="PF1(ADC1)"/>
<wire x1="11" y1="7" x2="20" y2="7" width="0.1524" layer="91"/>
<label x="20" y="7" size="1.778" layer="95"/>
</segment>
</net>
<net name="LED_2" class="0">
<segment>
<pinref part="R2" gate="G$1" pin="2"/>
<wire x1="58.54" y1="-59" x2="56" y2="-59" width="0.1524" layer="91"/>
<label x="56" y="-59" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="PF4(ADC4/TCK)"/>
<wire x1="11" y1="10" x2="20" y2="10" width="0.1524" layer="91"/>
<label x="20" y="10" size="1.778" layer="95"/>
</segment>
</net>
<net name="LED_3" class="0">
<segment>
<pinref part="R5" gate="G$1" pin="2"/>
<wire x1="58.54" y1="-83" x2="56" y2="-83" width="0.1524" layer="91"/>
<label x="56" y="-83" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="PF5(ADC5/TMS)"/>
<wire x1="20" y1="13" x2="11" y2="13" width="0.1524" layer="91"/>
<label x="20" y="13" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="R6" gate="G$1" pin="1"/>
<pinref part="LED_5" gate="G$1" pin="DATA"/>
<wire x1="125.46" y1="-83" x2="141" y2="-83" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="R7" gate="G$1" pin="1"/>
<pinref part="LED_6" gate="G$1" pin="DATA"/>
<wire x1="125.46" y1="-59" x2="141" y2="-59" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="R8" gate="G$1" pin="1"/>
<pinref part="LED_7" gate="G$1" pin="DATA"/>
<wire x1="125.46" y1="-37" x2="141" y2="-37" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="R9" gate="G$1" pin="1"/>
<pinref part="LED_8" gate="G$1" pin="DATA"/>
<wire x1="125.46" y1="-106" x2="141" y2="-106" width="0.1524" layer="91"/>
</segment>
</net>
<net name="LED_5" class="0">
<segment>
<pinref part="R8" gate="G$1" pin="2"/>
<wire x1="116.54" y1="-37" x2="114" y2="-37" width="0.1524" layer="91"/>
<label x="114" y="-37" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="PC6(OC3A/OC4A)"/>
<wire x1="-76" y1="1" x2="-89" y2="1" width="0.1524" layer="91"/>
<label x="-89" y="1" size="1.778" layer="95" rot="R180"/>
</segment>
</net>
<net name="LED_6" class="0">
<segment>
<pinref part="R7" gate="G$1" pin="2"/>
<wire x1="116.54" y1="-59" x2="114" y2="-59" width="0.1524" layer="91"/>
<label x="114" y="-59" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="PB6(PCINT6/OC1B/OC4B/ADC13)"/>
<wire x1="-76" y1="7" x2="-89" y2="7" width="0.1524" layer="91"/>
<label x="-89" y="7" size="1.778" layer="95" rot="R180"/>
</segment>
</net>
<net name="LED_7" class="0">
<segment>
<pinref part="R6" gate="G$1" pin="2"/>
<wire x1="116.54" y1="-83" x2="114" y2="-83" width="0.1524" layer="91"/>
<label x="114" y="-83" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="PB5(PCINT5(OC1A/OC4B/ADC12)"/>
<wire x1="-76" y1="10" x2="-89" y2="10" width="0.1524" layer="91"/>
<label x="-89" y="10" size="1.778" layer="95" rot="R180"/>
</segment>
</net>
<net name="LED_8" class="0">
<segment>
<pinref part="R9" gate="G$1" pin="2"/>
<wire x1="116.54" y1="-106" x2="114" y2="-106" width="0.1524" layer="91"/>
<label x="114" y="-106" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="PB4(PCINT4/ADC11)"/>
<wire x1="-76" y1="13" x2="-89" y2="13" width="0.1524" layer="91"/>
<label x="-89" y="13" size="1.778" layer="95" rot="R180"/>
</segment>
</net>
<net name="12V" class="0">
<segment>
<pinref part="MOLEX" gate="G$1" pin="12V"/>
<wire x1="70" y1="86" x2="64" y2="86" width="0.1524" layer="91"/>
<label x="64" y="86" size="1.778" layer="95" rot="R180"/>
</segment>
</net>
<net name="USB_D-" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="D-"/>
<wire x1="-19" y1="55" x2="-19" y2="65" width="0.1524" layer="91"/>
<label x="-19" y="65" size="1.778" layer="95" rot="R90"/>
</segment>
<segment>
<pinref part="J1" gate="G$1" pin="9"/>
<wire x1="138" y1="86" x2="129" y2="86" width="0.1524" layer="91"/>
<label x="138" y="86" size="1.778" layer="95"/>
</segment>
</net>
<net name="USB_D+" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="D+"/>
<wire x1="-16" y1="65" x2="-16" y2="55" width="0.1524" layer="91"/>
<label x="-16" y="65" size="1.778" layer="95" rot="R90"/>
</segment>
<segment>
<pinref part="J1" gate="G$1" pin="8"/>
<wire x1="129" y1="83" x2="138" y2="83" width="0.1524" layer="91"/>
<label x="138" y="83" size="1.778" layer="95"/>
</segment>
</net>
<net name="NC" class="0">
<segment>
<pinref part="J1" gate="G$1" pin="6"/>
<wire x1="129" y1="77" x2="138" y2="77" width="0.1524" layer="91"/>
<label x="138" y="77" size="1.778" layer="95"/>
</segment>
</net>
<net name="USB_5V" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="UVCC"/>
<wire x1="-43" y1="55" x2="-43" y2="65" width="0.1524" layer="91"/>
<label x="-43" y="65" size="1.778" layer="95" rot="R90"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="VBUS"/>
<wire x1="-40" y1="65" x2="-40" y2="55" width="0.1524" layer="91"/>
<label x="-40" y="65" size="1.778" layer="95" rot="R90"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="AVCC"/>
<wire x1="-37" y1="55" x2="-37" y2="65" width="0.1524" layer="91"/>
<label x="-37" y="65" size="1.778" layer="95" rot="R90"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="VCC"/>
<wire x1="-28" y1="65" x2="-28" y2="55" width="0.1524" layer="91"/>
<label x="-28" y="65" size="1.778" layer="95" rot="R90"/>
</segment>
<segment>
<pinref part="J1" gate="G$1" pin="10"/>
<wire x1="129" y1="89" x2="138" y2="89" width="0.1524" layer="91"/>
<label x="138" y="89" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="R11" gate="G$1" pin="1"/>
<wire x1="-39.46" y1="-76" x2="-46.5" y2="-76" width="0.1524" layer="91"/>
<label x="-46.5" y="-76" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="R12" gate="G$1" pin="1"/>
<wire x1="-39.46" y1="-97.5" x2="-46.5" y2="-97.5" width="0.1524" layer="91"/>
<label x="-46.5" y="-97.5" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="J2" gate="G$1" pin="VCC"/>
<wire x1="40.5" y1="58.5" x2="53" y2="58.5" width="0.1524" layer="91"/>
<label x="53" y="58.5" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$14" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="AREF"/>
<wire x1="-34" y1="65" x2="-34" y2="55" width="0.1524" layer="91"/>
<label x="-34" y="65" size="1.778" layer="95" rot="R90"/>
</segment>
</net>
<net name="N$17" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="XTAL1"/>
<wire x1="-25" y1="55" x2="-25" y2="76" width="0.1524" layer="91"/>
<wire x1="-25" y1="76" x2="-33" y2="76" width="0.1524" layer="91"/>
<pinref part="C9" gate="G$1" pin="P$1"/>
<pinref part="X1" gate="G$1" pin="P$1"/>
<wire x1="-34.54" y1="85" x2="-33" y2="85" width="0.1524" layer="91"/>
<wire x1="-33" y1="85" x2="-32" y2="85" width="0.1524" layer="91"/>
<wire x1="-33" y1="76" x2="-33" y2="85" width="0.1524" layer="91"/>
<junction x="-33" y="85"/>
</segment>
</net>
<net name="_RESET" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="_RESET"/>
<wire x1="-13" y1="55" x2="-13" y2="65" width="0.1524" layer="91"/>
<label x="-13" y="65" size="1.778" layer="95" rot="R90"/>
</segment>
<segment>
<pinref part="J2" gate="G$1" pin="RST"/>
<wire x1="14.5" y1="52.5" x2="4.5" y2="52.5" width="0.1524" layer="91"/>
<label x="4.5" y="52.5" size="1.778" layer="95" rot="R180"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="X1" gate="G$1" pin="P$2"/>
<pinref part="C10" gate="G$1" pin="P$1"/>
<wire x1="-16" y1="85" x2="-15" y2="85" width="0.1524" layer="91"/>
<wire x1="-15" y1="85" x2="-13.46" y2="85" width="0.1524" layer="91"/>
<wire x1="-15" y1="85" x2="-15" y2="76" width="0.1524" layer="91"/>
<wire x1="-15" y1="76" x2="-22" y2="76" width="0.1524" layer="91"/>
<junction x="-15" y="85"/>
<pinref part="U1" gate="G$1" pin="XTAL2"/>
<wire x1="-22" y1="76" x2="-22" y2="55" width="0.1524" layer="91"/>
</segment>
</net>
<net name="BOOTLOADER" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="PE2(HWB)"/>
<wire x1="-22" y1="-32" x2="-22" y2="-38" width="0.1524" layer="91"/>
<label x="-22" y="-38" size="1.778" layer="95" rot="R270"/>
</segment>
</net>
<net name="USR_LED" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="PD5(XCK1/CTS)"/>
<wire x1="-31" y1="-32" x2="-31" y2="-38" width="0.1524" layer="91"/>
<label x="-31" y="-38" size="1.778" layer="95" rot="R270"/>
</segment>
<segment>
<pinref part="R10" gate="G$1" pin="1"/>
<wire x1="120.54" y1="24" x2="116" y2="24" width="0.1524" layer="91"/>
<label x="116" y="24" size="1.778" layer="95" rot="R180"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="R10" gate="G$1" pin="2"/>
<pinref part="USR_LED" gate="G$1" pin="1"/>
<wire x1="129.46" y1="24" x2="132.54" y2="24" width="0.1524" layer="91"/>
</segment>
</net>
<net name="TEMP1" class="0">
<segment>
<pinref part="R11" gate="G$1" pin="2"/>
<pinref part="TEMP1" gate="G$1" pin="1"/>
<wire x1="-30.54" y1="-76" x2="-28" y2="-76" width="0.1524" layer="91"/>
<wire x1="-28" y1="-76" x2="-25.5" y2="-76" width="0.1524" layer="91"/>
<wire x1="-28" y1="-76" x2="-28" y2="-71" width="0.1524" layer="91"/>
<junction x="-28" y="-76"/>
<label x="-28" y="-71" size="1.778" layer="95" rot="R90"/>
</segment>
</net>
<net name="TEMP2" class="0">
<segment>
<pinref part="R12" gate="G$1" pin="2"/>
<pinref part="TEMP2" gate="G$1" pin="1"/>
<wire x1="-30.54" y1="-97.5" x2="-28" y2="-97.5" width="0.1524" layer="91"/>
<wire x1="-28" y1="-97.5" x2="-25.5" y2="-97.5" width="0.1524" layer="91"/>
<wire x1="-28" y1="-97.5" x2="-28" y2="-92.5" width="0.1524" layer="91"/>
<junction x="-28" y="-97.5"/>
<label x="-28" y="-92.5" size="1.778" layer="95" rot="R90"/>
</segment>
</net>
<net name="AGND" class="0">
<segment>
<pinref part="TEMP1" gate="G$1" pin="2"/>
<wire x1="-25.5" y1="-82" x2="-46.5" y2="-82" width="0.1524" layer="91"/>
<label x="-46.5" y="-82" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="TEMP2" gate="G$1" pin="2"/>
<wire x1="-25.5" y1="-103.5" x2="-46.5" y2="-103.5" width="0.1524" layer="91"/>
<label x="-46.5" y="-103.5" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="R14" gate="G$1" pin="2"/>
<wire x1="-27.04" y1="-115.5" x2="-22.5" y2="-115.5" width="0.1524" layer="91"/>
<label x="-22.5" y="-115.5" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="PD6(T1/OC4D/ADC9)"/>
<wire x1="-28" y1="-32" x2="-28" y2="-38" width="0.1524" layer="91"/>
<label x="-28" y="-38" size="1.778" layer="95" rot="R270"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="PD7(T0/OC4D/ADC10)"/>
<wire x1="-25" y1="-32" x2="-25" y2="-38" width="0.1524" layer="91"/>
<label x="-25" y="-38" size="1.778" layer="95" rot="R270"/>
</segment>
</net>
<net name="MISO" class="0">
<segment>
<pinref part="J2" gate="G$1" pin="MISO"/>
<wire x1="14.5" y1="58.5" x2="4.5" y2="58.5" width="0.1524" layer="91"/>
<label x="4.5" y="58.5" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="PB3(PDO/PCINT3/MISO)"/>
<wire x1="-76" y1="16" x2="-89" y2="16" width="0.1524" layer="91"/>
<label x="-89" y="16" size="1.778" layer="95" rot="R180"/>
</segment>
</net>
<net name="SCK" class="0">
<segment>
<pinref part="J2" gate="G$1" pin="SCK"/>
<wire x1="14.5" y1="55.5" x2="4.5" y2="55.5" width="0.1524" layer="91"/>
<label x="4.5" y="55.5" size="1.778" layer="95" rot="R180"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="PB1(PCINT1/SCL)"/>
<wire x1="-76" y1="22" x2="-89" y2="22" width="0.1524" layer="91"/>
<label x="-89" y="22" size="1.778" layer="95" rot="R180"/>
</segment>
</net>
<net name="MOSI" class="0">
<segment>
<pinref part="J2" gate="G$1" pin="MOSI"/>
<wire x1="40.5" y1="55.5" x2="53" y2="55.5" width="0.1524" layer="91"/>
<label x="53" y="55.5" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="PB2(PDI/PCINT2/MOSI)"/>
<wire x1="-76" y1="19" x2="-89" y2="19" width="0.1524" layer="91"/>
<label x="-89" y="19" size="1.778" layer="95" rot="R180"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
