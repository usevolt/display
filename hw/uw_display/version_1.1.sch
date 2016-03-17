<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.2.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="no" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="50" name="dxf" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="53" name="tPadExt" color="7" fill="1" visible="no" active="no"/>
<layer number="54" name="bPadExt" color="1" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="250" name="Descript" color="3" fill="1" visible="no" active="no"/>
<layer number="251" name="SMDround" color="12" fill="11" visible="no" active="no"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="frames">
<description>&lt;b&gt;Frames for Sheet and Layout&lt;/b&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="A5L-LOC">
<wire x1="85.09" y1="3.81" x2="85.09" y2="24.13" width="0.1016" layer="94"/>
<wire x1="85.09" y1="24.13" x2="139.065" y2="24.13" width="0.1016" layer="94"/>
<wire x1="139.065" y1="24.13" x2="180.34" y2="24.13" width="0.1016" layer="94"/>
<wire x1="170.18" y1="3.81" x2="170.18" y2="8.89" width="0.1016" layer="94"/>
<wire x1="170.18" y1="8.89" x2="180.34" y2="8.89" width="0.1016" layer="94"/>
<wire x1="170.18" y1="8.89" x2="139.065" y2="8.89" width="0.1016" layer="94"/>
<wire x1="139.065" y1="8.89" x2="139.065" y2="3.81" width="0.1016" layer="94"/>
<wire x1="139.065" y1="8.89" x2="139.065" y2="13.97" width="0.1016" layer="94"/>
<wire x1="139.065" y1="13.97" x2="180.34" y2="13.97" width="0.1016" layer="94"/>
<wire x1="139.065" y1="13.97" x2="139.065" y2="19.05" width="0.1016" layer="94"/>
<wire x1="139.065" y1="19.05" x2="180.34" y2="19.05" width="0.1016" layer="94"/>
<wire x1="139.065" y1="19.05" x2="139.065" y2="24.13" width="0.1016" layer="94"/>
<text x="140.97" y="15.24" size="2.54" layer="94" font="vector">&gt;DRAWING_NAME</text>
<text x="140.97" y="10.16" size="2.286" layer="94" font="vector">&gt;LAST_DATE_TIME</text>
<text x="154.305" y="5.08" size="2.54" layer="94" font="vector">&gt;SHEET</text>
<text x="140.716" y="4.953" size="2.54" layer="94" font="vector">Sheet:</text>
<frame x1="0" y1="0" x2="184.15" y2="133.35" columns="4" rows="4" layer="94"/>
</symbol>
<symbol name="A4L-LOC">
<wire x1="256.54" y1="3.81" x2="256.54" y2="8.89" width="0.1016" layer="94"/>
<wire x1="256.54" y1="8.89" x2="256.54" y2="13.97" width="0.1016" layer="94"/>
<wire x1="256.54" y1="13.97" x2="256.54" y2="19.05" width="0.1016" layer="94"/>
<wire x1="256.54" y1="19.05" x2="256.54" y2="24.13" width="0.1016" layer="94"/>
<wire x1="161.29" y1="3.81" x2="161.29" y2="24.13" width="0.1016" layer="94"/>
<wire x1="161.29" y1="24.13" x2="215.265" y2="24.13" width="0.1016" layer="94"/>
<wire x1="215.265" y1="24.13" x2="256.54" y2="24.13" width="0.1016" layer="94"/>
<wire x1="246.38" y1="3.81" x2="246.38" y2="8.89" width="0.1016" layer="94"/>
<wire x1="246.38" y1="8.89" x2="256.54" y2="8.89" width="0.1016" layer="94"/>
<wire x1="246.38" y1="8.89" x2="215.265" y2="8.89" width="0.1016" layer="94"/>
<wire x1="215.265" y1="8.89" x2="215.265" y2="3.81" width="0.1016" layer="94"/>
<wire x1="215.265" y1="8.89" x2="215.265" y2="13.97" width="0.1016" layer="94"/>
<wire x1="215.265" y1="13.97" x2="256.54" y2="13.97" width="0.1016" layer="94"/>
<wire x1="215.265" y1="13.97" x2="215.265" y2="19.05" width="0.1016" layer="94"/>
<wire x1="215.265" y1="19.05" x2="256.54" y2="19.05" width="0.1016" layer="94"/>
<wire x1="215.265" y1="19.05" x2="215.265" y2="24.13" width="0.1016" layer="94"/>
<text x="217.17" y="15.24" size="2.54" layer="94" font="vector">&gt;DRAWING_NAME</text>
<text x="217.17" y="10.16" size="2.286" layer="94" font="vector">&gt;LAST_DATE_TIME</text>
<text x="230.505" y="5.08" size="2.54" layer="94" font="vector">&gt;SHEET</text>
<text x="216.916" y="4.953" size="2.54" layer="94" font="vector">Sheet:</text>
<frame x1="0" y1="0" x2="260.35" y2="179.07" columns="6" rows="4" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="A5L-LOC" prefix="FRAME" uservalue="yes">
<description>A5L LOC</description>
<gates>
<gate name="G$1" symbol="A5L-LOC" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="A4L-LOC" prefix="FRAME">
<description>&lt;b&gt;FRAME&lt;/b&gt;&lt;p&gt;
DIN A4, landscape with location and doc. field</description>
<gates>
<gate name="G$1" symbol="A4L-LOC" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="GND">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
<symbol name="+3V3">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<text x="-2.54" y="-5.08" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="+3V3" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
<symbol name="+5V">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<text x="-2.54" y="-5.08" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="+5V" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
<symbol name="VCC">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="VCC" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
<symbol name="V+">
<wire x1="0.889" y1="-1.27" x2="0" y2="0.127" width="0.254" layer="94"/>
<wire x1="0" y1="0.127" x2="-0.889" y2="-1.27" width="0.254" layer="94"/>
<wire x1="-0.889" y1="-1.27" x2="0.889" y2="-1.27" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="V+" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" prefix="GND">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="+3V3" prefix="+3V3">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="+3V3" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="+5V" prefix="P+">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="+5V" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="VCC" prefix="P+">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="VCC" symbol="VCC" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="V+" prefix="P+">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="V+" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="arm">
<packages>
<package name="DO-214AB">
<description>TVS diode package</description>
<smd name="P$1" x="0" y="0" dx="1.62" dy="2.18" layer="1"/>
<smd name="P$2" x="4.6" y="0" dx="1.62" dy="2.18" layer="1"/>
<wire x1="1.3" y1="1" x2="1.3" y2="-1" width="0.2032" layer="21"/>
<wire x1="1.3" y1="-1" x2="2.9" y2="0" width="0.2032" layer="21"/>
<wire x1="2.9" y1="0" x2="1.3" y2="1" width="0.2032" layer="21"/>
<wire x1="2.9" y1="1" x2="3.1" y2="1" width="0.2032" layer="21"/>
<wire x1="3.1" y1="1" x2="3.1" y2="-1" width="0.2032" layer="21"/>
<wire x1="3.1" y1="-1" x2="3.3" y2="-1" width="0.2032" layer="21"/>
<text x="0.2" y="2.2" size="0.8128" layer="21">&gt;NAME</text>
<wire x1="0" y1="-1.9" x2="4.5" y2="-1.9" width="0.2032" layer="21"/>
<wire x1="4.5" y1="-1.9" x2="4.5" y2="-1.5" width="0.2032" layer="21"/>
<wire x1="0" y1="-1.9" x2="0" y2="-1.5" width="0.2032" layer="21"/>
<wire x1="0" y1="1.5" x2="0" y2="1.9" width="0.2032" layer="21"/>
<wire x1="0" y1="1.9" x2="4.5" y2="1.9" width="0.2032" layer="21"/>
<wire x1="4.5" y1="1.9" x2="4.5" y2="1.5" width="0.2032" layer="21"/>
</package>
<package name="SOP5">
<smd name="2" x="0" y="0" dx="1" dy="0.7" layer="1" rot="R90"/>
<smd name="1" x="-1" y="0" dx="1" dy="0.7" layer="1" rot="R90"/>
<smd name="3" x="1" y="0" dx="1" dy="0.7" layer="1" rot="R90"/>
<smd name="5" x="-1" y="2.6" dx="1" dy="0.7" layer="1" rot="R90"/>
<smd name="4" x="1" y="2.6" dx="1" dy="0.7" layer="1" rot="R90"/>
<text x="-1" y="3.5" size="0.8128" layer="21" font="vector">&gt;VALUE</text>
<wire x1="-1.7" y1="2.5" x2="-1.8" y2="2.5" width="0.2032" layer="21"/>
<wire x1="-1.8" y1="2.5" x2="-1.8" y2="0.1" width="0.2032" layer="21"/>
<wire x1="-1.8" y1="0.1" x2="-1.7" y2="0.1" width="0.2032" layer="21"/>
<wire x1="1.7" y1="2.5" x2="1.8" y2="2.5" width="0.2032" layer="21"/>
<wire x1="1.8" y1="2.5" x2="1.8" y2="0.1" width="0.2032" layer="21"/>
<wire x1="1.8" y1="0.1" x2="1.7" y2="0.1" width="0.2032" layer="21"/>
<wire x1="-0.3" y1="2.5" x2="0.3" y2="2.5" width="0.2032" layer="21"/>
<text x="-1" y="4.77" size="0.8128" layer="21" font="vector">&gt;NAME</text>
</package>
<package name="ARM_10_PIN_JTAG/SWD_CONNECTOR">
<smd name="P$1" x="-1.27" y="0" dx="1.905" dy="0.635" layer="1"/>
<smd name="P$2" x="3.81" y="0" dx="1.905" dy="0.635" layer="1"/>
<smd name="P$3" x="-1.27" y="-1.27" dx="1.905" dy="0.635" layer="1"/>
<smd name="P$4" x="3.81" y="-1.27" dx="1.905" dy="0.635" layer="1"/>
<smd name="P$5" x="-1.27" y="-2.54" dx="1.905" dy="0.635" layer="1"/>
<smd name="P$6" x="3.81" y="-2.54" dx="1.905" dy="0.635" layer="1"/>
<smd name="P$7" x="3.81" y="-3.81" dx="1.905" dy="0.635" layer="1"/>
<smd name="P$8" x="-1.27" y="-5.08" dx="1.905" dy="0.635" layer="1"/>
<smd name="P$9" x="3.81" y="-5.08" dx="1.905" dy="0.635" layer="1"/>
<text x="-1.778" y="1.7018" size="0.8128" layer="21" font="vector">&gt;NAME</text>
<wire x1="0.254" y1="0.508" x2="2.286" y2="0.508" width="0.2032" layer="21"/>
<wire x1="0.254" y1="-5.588" x2="2.286" y2="-5.588" width="0.2032" layer="21"/>
<text x="-1.778" y="0.762" size="0.8128" layer="21" font="vector">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="DIODE_TVS">
<wire x1="0" y1="1.016" x2="0" y2="-1.016" width="0.254" layer="94"/>
<wire x1="0" y1="-1.016" x2="2.286" y2="0" width="0.254" layer="94"/>
<wire x1="2.286" y1="0" x2="0" y2="1.016" width="0.254" layer="94"/>
<wire x1="1.778" y1="1.016" x2="2.54" y2="1.016" width="0.254" layer="94"/>
<wire x1="2.54" y1="1.016" x2="2.54" y2="-1.016" width="0.254" layer="94"/>
<wire x1="2.54" y1="-1.016" x2="3.302" y2="-1.016" width="0.254" layer="94"/>
<pin name="P" x="-2.54" y="0" visible="off" length="short"/>
<pin name="N" x="5.08" y="0" visible="off" length="short" rot="R180"/>
<text x="2.794" y="0.254" size="1.27" layer="95">&gt;NAME</text>
<text x="3.556" y="-1.524" size="1.27" layer="95">&gt;VALUE</text>
</symbol>
<symbol name="REGULATOR_LINEAR">
<description>LP2985IM5-3.3
9778284
http://fi.farnell.com/webapp/wcs/stores/servlet/ProductDisplay?catalogId=15001&amp;langId=358&amp;urlRequestType=Base&amp;partNumber=9778284&amp;storeId=10159</description>
<pin name="VIN" x="-5.08" y="2.54" length="short"/>
<pin name="VOUT" x="17.78" y="2.54" length="short" rot="R180"/>
<pin name="GND" x="-5.08" y="-2.54" length="short"/>
<wire x1="-2.54" y1="5.08" x2="15.24" y2="5.08" width="0.254" layer="94"/>
<wire x1="15.24" y1="5.08" x2="15.24" y2="-5.08" width="0.254" layer="94"/>
<wire x1="15.24" y1="-5.08" x2="-2.54" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-5.08" x2="-2.54" y2="5.08" width="0.254" layer="94"/>
<pin name="RESET" x="17.78" y="-2.54" length="short" rot="R180"/>
<text x="-2.54" y="5.588" size="1.778" layer="95">&gt;NAME</text>
<text x="6.35" y="5.588" size="1.778" layer="96">&gt;VALUE</text>
</symbol>
<symbol name="ARM_JTAG/SWD_HEADER_10_PIN">
<pin name="VREF" x="-2.54" y="7.62" length="short"/>
<pin name="TMS/SWDIO" x="-2.54" y="5.08" length="short"/>
<pin name="GND" x="-2.54" y="2.54" length="short"/>
<pin name="TCK/SWDCLK" x="-2.54" y="0" length="short"/>
<pin name="GND@2" x="-2.54" y="-2.54" length="short"/>
<pin name="TDO/SWO" x="-2.54" y="-5.08" length="short"/>
<pin name="TDI" x="-2.54" y="-7.62" length="short"/>
<pin name="NC" x="-2.54" y="-10.16" length="short"/>
<pin name="RESET" x="-2.54" y="-12.7" length="short"/>
<wire x1="0" y1="10.16" x2="17.78" y2="10.16" width="0.254" layer="94"/>
<wire x1="17.78" y1="10.16" x2="17.78" y2="-15.24" width="0.254" layer="94"/>
<wire x1="17.78" y1="-15.24" x2="0" y2="-15.24" width="0.254" layer="94"/>
<wire x1="0" y1="-15.24" x2="0" y2="10.16" width="0.254" layer="94"/>
<text x="0" y="11.176" size="1.27" layer="95">&gt;NAME</text>
<text x="0" y="-17.78" size="1.27" layer="95">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="DIODE_TVS" prefix="D" uservalue="yes">
<description>9886257 	

STMICROELECTRONICS

SMBJ33A-TR

Product Range:Transil SMBJ Series; TVS Polarity:Unidirectional; Reverse Stand-Off Voltage Vrwm:33V; Diode Case Style:DO-214AA; No. of Pins:2; Breakdown Voltage Min:36.7V; Breakdown Voltage Max:38.6

http://fi.farnell.com/webapp/wcs/stores/servlet/ProductDisplay?catalogId=15001&amp;langId=358&amp;urlRequestType=Base&amp;partNumber=9886257&amp;storeId=10159</description>
<gates>
<gate name="G$1" symbol="DIODE_TVS" x="0" y="0"/>
</gates>
<devices>
<device name="DO-214AA" package="DO-214AB">
<connects>
<connect gate="G$1" pin="N" pad="P$2"/>
<connect gate="G$1" pin="P" pad="P$1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="LP2985" prefix="VR" uservalue="yes">
<description>TEXAS INSTRUMENTS  LP2985IM5-3.3  V REG LDO +3.3V, SMD, 2985, SOT235
http://www.farnell.com/datasheets/1882537.pdf</description>
<gates>
<gate name="G$1" symbol="REGULATOR_LINEAR" x="-7.62" y="0"/>
</gates>
<devices>
<device name="SOP5" package="SOP5">
<connects>
<connect gate="G$1" pin="GND" pad="2"/>
<connect gate="G$1" pin="RESET" pad="3"/>
<connect gate="G$1" pin="VIN" pad="1"/>
<connect gate="G$1" pin="VOUT" pad="5"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="ARM_JTAG/SWD_HEADER_10_PIN" prefix="J" uservalue="yes">
<description>ARM Olimex Debugger 10 pin header, 0.05 inch</description>
<gates>
<gate name="G$1" symbol="ARM_JTAG/SWD_HEADER_10_PIN" x="-12.7" y="2.54"/>
</gates>
<devices>
<device name="SMD" package="ARM_10_PIN_JTAG/SWD_CONNECTOR">
<connects>
<connect gate="G$1" pin="GND" pad="P$3"/>
<connect gate="G$1" pin="GND@2" pad="P$5"/>
<connect gate="G$1" pin="NC" pad="P$8"/>
<connect gate="G$1" pin="RESET" pad="P$9"/>
<connect gate="G$1" pin="TCK/SWDCLK" pad="P$4"/>
<connect gate="G$1" pin="TDI" pad="P$7"/>
<connect gate="G$1" pin="TDO/SWO" pad="P$6"/>
<connect gate="G$1" pin="TMS/SWDIO" pad="P$2"/>
<connect gate="G$1" pin="VREF" pad="P$1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="usevolt">
<description>Footprints for own devices</description>
<packages>
<package name="0603_SILKSCREEN">
<smd name="0" x="-0.9779" y="0" dx="0.635" dy="0.889" layer="1"/>
<smd name="1" x="0.5842" y="0" dx="0.635" dy="0.889" layer="1"/>
<text x="-1.6129" y="1.905" size="0.8128" layer="21" font="vector">&gt;NAME</text>
<wire x1="1.143" y1="0.6604" x2="1.143" y2="-0.6604" width="0.2032" layer="21"/>
<wire x1="-1.5494" y1="-0.6604" x2="-1.5494" y2="0.6604" width="0.2032" layer="21"/>
<wire x1="1.3462" y1="0.6604" x2="1.3462" y2="-0.6604" width="0.2032" layer="21"/>
<wire x1="-1.5494" y1="-0.6604" x2="1.143" y2="-0.6604" width="0.2032" layer="21"/>
<wire x1="1.143" y1="-0.6604" x2="1.3462" y2="-0.6604" width="0.2032" layer="21"/>
<wire x1="-1.5494" y1="0.6604" x2="1.143" y2="0.6604" width="0.2032" layer="21"/>
<wire x1="1.143" y1="0.6604" x2="1.3462" y2="0.6604" width="0.2032" layer="21"/>
<text x="-1.6002" y="0.889" size="0.8128" layer="21" font="vector">&gt;VALUE</text>
</package>
<package name="RES_1/4W_TH">
<pad name="0" x="0" y="0" drill="1" diameter="1.778" shape="square"/>
<pad name="1" x="8.255" y="0" drill="1" diameter="1.778"/>
<wire x1="1.27" y1="0" x2="2.54" y2="1.016" width="0.2032" layer="21" curve="-90"/>
<wire x1="1.27" y1="0" x2="2.54" y2="-1.016" width="0.2032" layer="21" curve="90"/>
<wire x1="2.54" y1="-1.016" x2="3.175" y2="-0.508" width="0.2032" layer="21" curve="90"/>
<wire x1="3.175" y1="-0.508" x2="5.08" y2="-0.508" width="0.2032" layer="21"/>
<wire x1="3.175" y1="0.508" x2="2.54" y2="1.016" width="0.2032" layer="21" curve="90"/>
<wire x1="6.985" y1="0" x2="5.715" y2="1.016" width="0.2032" layer="21" curve="90"/>
<wire x1="5.715" y1="1.016" x2="5.08" y2="0.508" width="0.2032" layer="21" curve="90"/>
<wire x1="5.08" y1="0.508" x2="3.175" y2="0.508" width="0.2032" layer="21"/>
<wire x1="5.08" y1="-0.508" x2="5.715" y2="-1.016" width="0.2032" layer="21" curve="90"/>
<wire x1="5.715" y1="-1.016" x2="6.985" y2="0" width="0.2032" layer="21" curve="90"/>
</package>
<package name="QFP50P3000X3000X160-208N">
<smd name="1" x="-14.7066" y="12.7508" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="2" x="-14.7066" y="12.2428" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="3" x="-14.7066" y="11.7602" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="4" x="-14.7066" y="11.2522" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="5" x="-14.7066" y="10.7442" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="6" x="-14.7066" y="10.2616" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="7" x="-14.7066" y="9.7536" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="8" x="-14.7066" y="9.2456" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="9" x="-14.7066" y="8.7376" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="10" x="-14.7066" y="8.255" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="11" x="-14.7066" y="7.747" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="12" x="-14.7066" y="7.239" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="13" x="-14.7066" y="6.7564" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="14" x="-14.7066" y="6.2484" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="15" x="-14.7066" y="5.7404" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="16" x="-14.7066" y="5.2578" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="17" x="-14.7066" y="4.7498" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="18" x="-14.7066" y="4.2418" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="19" x="-14.7066" y="3.7592" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="20" x="-14.7066" y="3.2512" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="21" x="-14.7066" y="2.7432" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="22" x="-14.7066" y="2.2606" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="23" x="-14.7066" y="1.7526" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="24" x="-14.7066" y="1.2446" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="25" x="-14.7066" y="0.762" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="26" x="-14.7066" y="0.254" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="27" x="-14.7066" y="-0.254" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="28" x="-14.7066" y="-0.762" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="29" x="-14.7066" y="-1.2446" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="30" x="-14.7066" y="-1.7526" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="31" x="-14.7066" y="-2.2606" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="32" x="-14.7066" y="-2.7432" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="33" x="-14.7066" y="-3.2512" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="34" x="-14.7066" y="-3.7592" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="35" x="-14.7066" y="-4.2418" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="36" x="-14.7066" y="-4.7498" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="37" x="-14.7066" y="-5.2578" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="38" x="-14.7066" y="-5.7404" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="39" x="-14.7066" y="-6.2484" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="40" x="-14.7066" y="-6.7564" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="41" x="-14.7066" y="-7.239" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="42" x="-14.7066" y="-7.747" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="43" x="-14.7066" y="-8.255" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="44" x="-14.7066" y="-8.7376" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="45" x="-14.7066" y="-9.2456" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="46" x="-14.7066" y="-9.7536" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="47" x="-14.7066" y="-10.2616" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="48" x="-14.7066" y="-10.7442" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="49" x="-14.7066" y="-11.2522" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="50" x="-14.7066" y="-11.7602" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="51" x="-14.7066" y="-12.2428" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="52" x="-14.7066" y="-12.7508" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="53" x="-12.7508" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="54" x="-12.2428" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="55" x="-11.7602" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="56" x="-11.2522" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="57" x="-10.7442" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="58" x="-10.2616" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="59" x="-9.7536" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="60" x="-9.2456" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="61" x="-8.7376" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="62" x="-8.255" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="63" x="-7.747" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="64" x="-7.239" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="65" x="-6.7564" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="66" x="-6.2484" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="67" x="-5.7404" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="68" x="-5.2578" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="69" x="-4.7498" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="70" x="-4.2418" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="71" x="-3.7592" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="72" x="-3.2512" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="73" x="-2.7432" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="74" x="-2.2606" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="75" x="-1.7526" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="76" x="-1.2446" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="77" x="-0.762" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="78" x="-0.254" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="79" x="0.254" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="80" x="0.762" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="81" x="1.2446" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="82" x="1.7526" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="83" x="2.2606" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="84" x="2.7432" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="85" x="3.2512" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="86" x="3.7592" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="87" x="4.2418" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="88" x="4.7498" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="89" x="5.2578" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="90" x="5.7404" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="91" x="6.2484" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="92" x="6.7564" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="93" x="7.239" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="94" x="7.747" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="95" x="8.255" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="96" x="8.7376" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="97" x="9.2456" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="98" x="9.7536" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="99" x="10.2616" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="100" x="10.7442" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="101" x="11.2522" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="102" x="11.7602" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="103" x="12.2428" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="104" x="12.7508" y="-14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="105" x="14.7066" y="-12.7508" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="106" x="14.7066" y="-12.2428" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="107" x="14.7066" y="-11.7602" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="108" x="14.7066" y="-11.2522" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="109" x="14.7066" y="-10.7442" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="110" x="14.7066" y="-10.2616" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="111" x="14.7066" y="-9.7536" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="112" x="14.7066" y="-9.2456" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="113" x="14.7066" y="-8.7376" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="114" x="14.7066" y="-8.255" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="115" x="14.7066" y="-7.747" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="116" x="14.7066" y="-7.239" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="117" x="14.7066" y="-6.7564" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="118" x="14.7066" y="-6.2484" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="119" x="14.7066" y="-5.7404" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="120" x="14.7066" y="-5.2578" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="121" x="14.7066" y="-4.7498" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="122" x="14.7066" y="-4.2418" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="123" x="14.7066" y="-3.7592" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="124" x="14.7066" y="-3.2512" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="125" x="14.7066" y="-2.7432" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="126" x="14.7066" y="-2.2606" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="127" x="14.7066" y="-1.7526" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="128" x="14.7066" y="-1.2446" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="129" x="14.7066" y="-0.762" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="130" x="14.7066" y="-0.254" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="131" x="14.7066" y="0.254" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="132" x="14.7066" y="0.762" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="133" x="14.7066" y="1.2446" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="134" x="14.7066" y="1.7526" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="135" x="14.7066" y="2.2606" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="136" x="14.7066" y="2.7432" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="137" x="14.7066" y="3.2512" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="138" x="14.7066" y="3.7592" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="139" x="14.7066" y="4.2418" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="140" x="14.7066" y="4.7498" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="141" x="14.7066" y="5.2578" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="142" x="14.7066" y="5.7404" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="143" x="14.7066" y="6.2484" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="144" x="14.7066" y="6.7564" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="145" x="14.7066" y="7.239" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="146" x="14.7066" y="7.747" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="147" x="14.7066" y="8.255" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="148" x="14.7066" y="8.7376" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="149" x="14.7066" y="9.2456" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="150" x="14.7066" y="9.7536" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="151" x="14.7066" y="10.2616" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="152" x="14.7066" y="10.7442" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="153" x="14.7066" y="11.2522" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="154" x="14.7066" y="11.7602" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="155" x="14.7066" y="12.2428" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="156" x="14.7066" y="12.7508" dx="0.2794" dy="1.4732" layer="1" rot="R270"/>
<smd name="157" x="12.7508" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="158" x="12.2428" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="159" x="11.7602" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="160" x="11.2522" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="161" x="10.7442" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="162" x="10.2616" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="163" x="9.7536" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="164" x="9.2456" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="165" x="8.7376" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="166" x="8.255" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="167" x="7.747" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="168" x="7.239" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="169" x="6.7564" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="170" x="6.2484" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="171" x="5.7404" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="172" x="5.2578" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="173" x="4.7498" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="174" x="4.2418" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="175" x="3.7592" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="176" x="3.2512" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="177" x="2.7432" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="178" x="2.2606" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="179" x="1.7526" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="180" x="1.2446" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="181" x="0.762" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="182" x="0.254" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="183" x="-0.254" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="184" x="-0.762" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="185" x="-1.2446" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="186" x="-1.7526" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="187" x="-2.2606" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="188" x="-2.7432" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="189" x="-3.2512" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="190" x="-3.7592" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="191" x="-4.2418" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="192" x="-4.7498" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="193" x="-5.2578" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="194" x="-5.7404" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="195" x="-6.2484" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="196" x="-6.7564" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="197" x="-7.239" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="198" x="-7.747" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="199" x="-8.255" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="200" x="-8.7376" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="201" x="-9.2456" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="202" x="-9.7536" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="203" x="-10.2616" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="204" x="-10.7442" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="205" x="-11.2522" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="206" x="-11.7602" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="207" x="-12.2428" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<smd name="208" x="-12.7508" y="14.7066" dx="0.2794" dy="1.4732" layer="1" rot="R180"/>
<wire x1="15.6972" y1="-15.6972" x2="-15.6972" y2="-15.6972" width="0.1524" layer="39"/>
<wire x1="-15.6972" y1="-15.6972" x2="-15.6972" y2="15.6972" width="0.1524" layer="39"/>
<wire x1="-15.6972" y1="15.6972" x2="15.6972" y2="15.6972" width="0.1524" layer="39"/>
<wire x1="15.6972" y1="15.6972" x2="15.6972" y2="-15.6972" width="0.1524" layer="39"/>
<wire x1="-13.208" y1="14.0462" x2="-14.0462" y2="14.0462" width="0.2032" layer="21"/>
<wire x1="14.0462" y1="13.208" x2="14.0462" y2="14.0462" width="0.2032" layer="21"/>
<wire x1="13.208" y1="-14.0462" x2="14.0462" y2="-14.0462" width="0.2032" layer="21"/>
<wire x1="-14.0462" y1="-14.0462" x2="-13.208" y2="-14.0462" width="0.2032" layer="21"/>
<wire x1="14.0462" y1="-14.0462" x2="14.0462" y2="-13.208" width="0.2032" layer="21"/>
<wire x1="14.0462" y1="14.0462" x2="13.208" y2="14.0462" width="0.2032" layer="21"/>
<wire x1="-14.0462" y1="14.0462" x2="-14.0462" y2="13.208" width="0.2032" layer="21"/>
<wire x1="-14.0462" y1="-13.208" x2="-14.0462" y2="-14.0462" width="0.2032" layer="21"/>
<wire x1="12.6238" y1="14.0462" x2="12.8778" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="12.8778" y1="14.0462" x2="12.8778" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="12.8778" y1="15.0876" x2="12.6238" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="12.6238" y1="15.0876" x2="12.6238" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="12.1158" y1="14.0462" x2="12.3952" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="12.3952" y1="14.0462" x2="12.3952" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="12.3952" y1="15.0876" x2="12.1158" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="12.1158" y1="15.0876" x2="12.1158" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="11.6078" y1="14.0462" x2="11.8872" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="11.8872" y1="14.0462" x2="11.8872" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="11.8872" y1="15.0876" x2="11.6078" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="11.6078" y1="15.0876" x2="11.6078" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="11.1252" y1="14.0462" x2="11.3792" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="11.3792" y1="14.0462" x2="11.3792" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="11.3792" y1="15.0876" x2="11.1252" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="11.1252" y1="15.0876" x2="11.1252" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="10.6172" y1="14.0462" x2="10.8966" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="10.8966" y1="14.0462" x2="10.8966" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="10.8966" y1="15.0876" x2="10.6172" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="10.6172" y1="15.0876" x2="10.6172" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="10.1092" y1="14.0462" x2="10.3886" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="10.3886" y1="14.0462" x2="10.3886" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="10.3886" y1="15.0876" x2="10.1092" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="10.1092" y1="15.0876" x2="10.1092" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="9.6266" y1="14.0462" x2="9.8806" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="9.8806" y1="14.0462" x2="9.8806" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="9.8806" y1="15.0876" x2="9.6266" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="9.6266" y1="15.0876" x2="9.6266" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="9.1186" y1="14.0462" x2="9.3726" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="9.3726" y1="14.0462" x2="9.3726" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="9.3726" y1="15.0876" x2="9.1186" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="9.1186" y1="15.0876" x2="9.1186" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="8.6106" y1="14.0462" x2="8.89" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="8.89" y1="14.0462" x2="8.89" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="8.89" y1="15.0876" x2="8.6106" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="8.6106" y1="15.0876" x2="8.6106" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="8.1026" y1="14.0462" x2="8.382" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="8.382" y1="14.0462" x2="8.382" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="8.382" y1="15.0876" x2="8.1026" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="8.1026" y1="15.0876" x2="8.1026" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="7.62" y1="14.0462" x2="7.874" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="7.874" y1="14.0462" x2="7.874" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="7.874" y1="15.0876" x2="7.62" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="7.62" y1="15.0876" x2="7.62" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="7.112" y1="14.0462" x2="7.3914" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="7.3914" y1="14.0462" x2="7.3914" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="7.3914" y1="15.0876" x2="7.112" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="7.112" y1="15.0876" x2="7.112" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="6.604" y1="14.0462" x2="6.8834" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="6.8834" y1="14.0462" x2="6.8834" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="6.8834" y1="15.0876" x2="6.604" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="6.604" y1="15.0876" x2="6.604" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="6.1214" y1="14.0462" x2="6.3754" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="6.3754" y1="14.0462" x2="6.3754" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="6.3754" y1="15.0876" x2="6.1214" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="6.1214" y1="15.0876" x2="6.1214" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="5.6134" y1="14.0462" x2="5.8928" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="5.8928" y1="14.0462" x2="5.8928" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="5.8928" y1="15.0876" x2="5.6134" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="5.6134" y1="15.0876" x2="5.6134" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="5.1054" y1="14.0462" x2="5.3848" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="5.3848" y1="14.0462" x2="5.3848" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="5.3848" y1="15.0876" x2="5.1054" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="5.1054" y1="15.0876" x2="5.1054" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="4.6228" y1="14.0462" x2="4.8768" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="4.8768" y1="14.0462" x2="4.8768" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="4.8768" y1="15.0876" x2="4.6228" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="4.6228" y1="15.0876" x2="4.6228" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="4.1148" y1="14.0462" x2="4.3942" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="4.3942" y1="14.0462" x2="4.3942" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="4.3942" y1="15.0876" x2="4.1148" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="4.1148" y1="15.0876" x2="4.1148" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="3.6068" y1="14.0462" x2="3.8862" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="3.8862" y1="14.0462" x2="3.8862" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="3.8862" y1="15.0876" x2="3.6068" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="3.6068" y1="15.0876" x2="3.6068" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="3.1242" y1="14.0462" x2="3.3782" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="3.3782" y1="14.0462" x2="3.3782" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="3.3782" y1="15.0876" x2="3.1242" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="3.1242" y1="15.0876" x2="3.1242" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="2.6162" y1="14.0462" x2="2.8956" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="2.8956" y1="14.0462" x2="2.8956" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="2.8956" y1="15.0876" x2="2.6162" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="2.6162" y1="15.0876" x2="2.6162" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="2.1082" y1="14.0462" x2="2.3876" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="2.3876" y1="14.0462" x2="2.3876" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="2.3876" y1="15.0876" x2="2.1082" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="2.1082" y1="15.0876" x2="2.1082" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="1.6256" y1="14.0462" x2="1.8796" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="1.8796" y1="14.0462" x2="1.8796" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="1.8796" y1="15.0876" x2="1.6256" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="1.6256" y1="15.0876" x2="1.6256" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="1.1176" y1="14.0462" x2="1.397" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="1.397" y1="14.0462" x2="1.397" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="1.397" y1="15.0876" x2="1.1176" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="1.1176" y1="15.0876" x2="1.1176" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="0.6096" y1="14.0462" x2="0.889" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="0.889" y1="14.0462" x2="0.889" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="0.889" y1="15.0876" x2="0.6096" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="0.6096" y1="15.0876" x2="0.6096" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="0.127" y1="14.0462" x2="0.381" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="0.381" y1="14.0462" x2="0.381" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="0.381" y1="15.0876" x2="0.127" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="0.127" y1="15.0876" x2="0.127" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-0.381" y1="14.0462" x2="-0.127" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-0.127" y1="14.0462" x2="-0.127" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-0.127" y1="15.0876" x2="-0.381" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-0.381" y1="15.0876" x2="-0.381" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-0.889" y1="14.0462" x2="-0.6096" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-0.6096" y1="14.0462" x2="-0.6096" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-0.6096" y1="15.0876" x2="-0.889" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-0.889" y1="15.0876" x2="-0.889" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-1.397" y1="14.0462" x2="-1.1176" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-1.1176" y1="14.0462" x2="-1.1176" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-1.1176" y1="15.0876" x2="-1.397" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-1.397" y1="15.0876" x2="-1.397" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-1.8796" y1="14.0462" x2="-1.6256" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-1.6256" y1="14.0462" x2="-1.6256" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-1.6256" y1="15.0876" x2="-1.8796" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-1.8796" y1="15.0876" x2="-1.8796" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-2.3876" y1="14.0462" x2="-2.1082" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-2.1082" y1="14.0462" x2="-2.1082" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-2.1082" y1="15.0876" x2="-2.3876" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-2.3876" y1="15.0876" x2="-2.3876" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-2.8956" y1="14.0462" x2="-2.6162" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-2.6162" y1="14.0462" x2="-2.6162" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-2.6162" y1="15.0876" x2="-2.8956" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-2.8956" y1="15.0876" x2="-2.8956" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-3.3782" y1="14.0462" x2="-3.1242" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-3.1242" y1="14.0462" x2="-3.1242" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-3.1242" y1="15.0876" x2="-3.3782" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-3.3782" y1="15.0876" x2="-3.3782" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-3.8862" y1="14.0462" x2="-3.6068" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-3.6068" y1="14.0462" x2="-3.6068" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-3.6068" y1="15.0876" x2="-3.8862" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-3.8862" y1="15.0876" x2="-3.8862" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-4.3942" y1="14.0462" x2="-4.1148" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-4.1148" y1="14.0462" x2="-4.1148" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-4.1148" y1="15.0876" x2="-4.3942" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-4.3942" y1="15.0876" x2="-4.3942" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-4.8768" y1="14.0462" x2="-4.6228" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-4.6228" y1="14.0462" x2="-4.6228" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-4.6228" y1="15.0876" x2="-4.8768" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-4.8768" y1="15.0876" x2="-4.8768" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-5.3848" y1="14.0462" x2="-5.1054" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-5.1054" y1="14.0462" x2="-5.1054" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-5.1054" y1="15.0876" x2="-5.3848" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-5.3848" y1="15.0876" x2="-5.3848" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-5.8928" y1="14.0462" x2="-5.6134" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-5.6134" y1="14.0462" x2="-5.6134" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-5.6134" y1="15.0876" x2="-5.8928" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-5.8928" y1="15.0876" x2="-5.8928" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-6.3754" y1="14.0462" x2="-6.1214" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-6.1214" y1="14.0462" x2="-6.1214" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-6.1214" y1="15.0876" x2="-6.3754" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-6.3754" y1="15.0876" x2="-6.3754" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-6.8834" y1="14.0462" x2="-6.604" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-6.604" y1="14.0462" x2="-6.604" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-6.604" y1="15.0876" x2="-6.8834" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-6.8834" y1="15.0876" x2="-6.8834" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-7.3914" y1="14.0462" x2="-7.112" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-7.112" y1="14.0462" x2="-7.112" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-7.112" y1="15.0876" x2="-7.3914" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-7.3914" y1="15.0876" x2="-7.3914" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-7.874" y1="14.0462" x2="-7.62" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-7.62" y1="14.0462" x2="-7.62" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-7.62" y1="15.0876" x2="-7.874" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-7.874" y1="15.0876" x2="-7.874" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-8.382" y1="14.0462" x2="-8.1026" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-8.1026" y1="14.0462" x2="-8.1026" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-8.1026" y1="15.0876" x2="-8.382" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-8.382" y1="15.0876" x2="-8.382" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-8.89" y1="14.0462" x2="-8.6106" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-8.6106" y1="14.0462" x2="-8.6106" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-8.6106" y1="15.0876" x2="-8.89" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-8.89" y1="15.0876" x2="-8.89" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-9.3726" y1="14.0462" x2="-9.1186" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-9.1186" y1="14.0462" x2="-9.1186" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-9.1186" y1="15.0876" x2="-9.3726" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-9.3726" y1="15.0876" x2="-9.3726" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-9.8806" y1="14.0462" x2="-9.6266" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-9.6266" y1="14.0462" x2="-9.6266" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-9.6266" y1="15.0876" x2="-9.8806" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-9.8806" y1="15.0876" x2="-9.8806" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-10.3886" y1="14.0462" x2="-10.1092" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-10.1092" y1="14.0462" x2="-10.1092" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-10.1092" y1="15.0876" x2="-10.3886" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-10.3886" y1="15.0876" x2="-10.3886" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-10.8966" y1="14.0462" x2="-10.6172" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-10.6172" y1="14.0462" x2="-10.6172" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-10.6172" y1="15.0876" x2="-10.8966" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-10.8966" y1="15.0876" x2="-10.8966" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-11.3792" y1="14.0462" x2="-11.1252" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-11.1252" y1="14.0462" x2="-11.1252" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-11.1252" y1="15.0876" x2="-11.3792" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-11.3792" y1="15.0876" x2="-11.3792" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-11.8872" y1="14.0462" x2="-11.6078" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-11.6078" y1="14.0462" x2="-11.6078" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-11.6078" y1="15.0876" x2="-11.8872" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-11.8872" y1="15.0876" x2="-11.8872" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-12.3952" y1="14.0462" x2="-12.1158" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-12.1158" y1="14.0462" x2="-12.1158" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-12.1158" y1="15.0876" x2="-12.3952" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-12.3952" y1="15.0876" x2="-12.3952" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-12.8778" y1="14.0462" x2="-12.6238" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-12.6238" y1="14.0462" x2="-12.6238" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-12.6238" y1="15.0876" x2="-12.8778" y2="15.0876" width="0.1524" layer="51"/>
<wire x1="-12.8778" y1="15.0876" x2="-12.8778" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="12.6238" x2="-14.0462" y2="12.8778" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="12.8778" x2="-15.0876" y2="12.8778" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="12.8778" x2="-15.0876" y2="12.6238" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="12.6238" x2="-14.0462" y2="12.6238" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="12.1158" x2="-14.0462" y2="12.3952" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="12.3952" x2="-15.0876" y2="12.3952" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="12.3952" x2="-15.0876" y2="12.1158" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="12.1158" x2="-14.0462" y2="12.1158" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="11.6078" x2="-14.0462" y2="11.8872" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="11.8872" x2="-15.0876" y2="11.8872" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="11.8872" x2="-15.0876" y2="11.6078" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="11.6078" x2="-14.0462" y2="11.6078" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="11.1252" x2="-14.0462" y2="11.3792" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="11.3792" x2="-15.0876" y2="11.3792" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="11.3792" x2="-15.0876" y2="11.1252" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="11.1252" x2="-14.0462" y2="11.1252" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="10.6172" x2="-14.0462" y2="10.8966" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="10.8966" x2="-15.0876" y2="10.8966" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="10.8966" x2="-15.0876" y2="10.6172" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="10.6172" x2="-14.0462" y2="10.6172" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="10.1092" x2="-14.0462" y2="10.3886" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="10.3886" x2="-15.0876" y2="10.3886" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="10.3886" x2="-15.0876" y2="10.1092" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="10.1092" x2="-14.0462" y2="10.1092" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="9.6266" x2="-14.0462" y2="9.8806" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="9.8806" x2="-15.0876" y2="9.8806" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="9.8806" x2="-15.0876" y2="9.6266" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="9.6266" x2="-14.0462" y2="9.6266" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="9.1186" x2="-14.0462" y2="9.3726" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="9.3726" x2="-15.0876" y2="9.3726" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="9.3726" x2="-15.0876" y2="9.1186" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="9.1186" x2="-14.0462" y2="9.1186" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="8.6106" x2="-14.0462" y2="8.89" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="8.89" x2="-15.0876" y2="8.89" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="8.89" x2="-15.0876" y2="8.6106" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="8.6106" x2="-14.0462" y2="8.6106" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="8.1026" x2="-14.0462" y2="8.382" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="8.382" x2="-15.0876" y2="8.382" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="8.382" x2="-15.0876" y2="8.1026" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="8.1026" x2="-14.0462" y2="8.1026" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="7.62" x2="-14.0462" y2="7.874" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="7.874" x2="-15.0876" y2="7.874" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="7.874" x2="-15.0876" y2="7.62" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="7.62" x2="-14.0462" y2="7.62" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="7.112" x2="-14.0462" y2="7.3914" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="7.3914" x2="-15.0876" y2="7.3914" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="7.3914" x2="-15.0876" y2="7.112" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="7.112" x2="-14.0462" y2="7.112" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="6.604" x2="-14.0462" y2="6.8834" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="6.8834" x2="-15.0876" y2="6.8834" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="6.8834" x2="-15.0876" y2="6.604" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="6.604" x2="-14.0462" y2="6.604" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="6.1214" x2="-14.0462" y2="6.3754" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="6.3754" x2="-15.0876" y2="6.3754" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="6.3754" x2="-15.0876" y2="6.1214" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="6.1214" x2="-14.0462" y2="6.1214" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="5.6134" x2="-14.0462" y2="5.8928" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="5.8928" x2="-15.0876" y2="5.8928" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="5.8928" x2="-15.0876" y2="5.6134" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="5.6134" x2="-14.0462" y2="5.6134" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="5.1054" x2="-14.0462" y2="5.3848" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="5.3848" x2="-15.0876" y2="5.3848" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="5.3848" x2="-15.0876" y2="5.1054" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="5.1054" x2="-14.0462" y2="5.1054" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="4.6228" x2="-14.0462" y2="4.8768" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="4.8768" x2="-15.0876" y2="4.8768" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="4.8768" x2="-15.0876" y2="4.6228" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="4.6228" x2="-14.0462" y2="4.6228" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="4.1148" x2="-14.0462" y2="4.3942" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="4.3942" x2="-15.0876" y2="4.3942" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="4.3942" x2="-15.0876" y2="4.1148" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="4.1148" x2="-14.0462" y2="4.1148" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="3.6068" x2="-14.0462" y2="3.8862" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="3.8862" x2="-15.0876" y2="3.8862" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="3.8862" x2="-15.0876" y2="3.6068" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="3.6068" x2="-14.0462" y2="3.6068" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="3.1242" x2="-14.0462" y2="3.3782" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="3.3782" x2="-15.0876" y2="3.3782" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="3.3782" x2="-15.0876" y2="3.1242" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="3.1242" x2="-14.0462" y2="3.1242" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="2.6162" x2="-14.0462" y2="2.8956" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="2.8956" x2="-15.0876" y2="2.8956" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="2.8956" x2="-15.0876" y2="2.6162" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="2.6162" x2="-14.0462" y2="2.6162" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="2.1082" x2="-14.0462" y2="2.3876" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="2.3876" x2="-15.0876" y2="2.3876" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="2.3876" x2="-15.0876" y2="2.1082" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="2.1082" x2="-14.0462" y2="2.1082" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="1.6256" x2="-14.0462" y2="1.8796" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="1.8796" x2="-15.0876" y2="1.8796" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="1.8796" x2="-15.0876" y2="1.6256" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="1.6256" x2="-14.0462" y2="1.6256" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="1.1176" x2="-14.0462" y2="1.397" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="1.397" x2="-15.0876" y2="1.397" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="1.397" x2="-15.0876" y2="1.1176" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="1.1176" x2="-14.0462" y2="1.1176" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="0.6096" x2="-14.0462" y2="0.889" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="0.889" x2="-15.0876" y2="0.889" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="0.889" x2="-15.0876" y2="0.6096" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="0.6096" x2="-14.0462" y2="0.6096" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="0.127" x2="-14.0462" y2="0.381" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="0.381" x2="-15.0876" y2="0.381" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="0.381" x2="-15.0876" y2="0.127" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="0.127" x2="-14.0462" y2="0.127" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-0.381" x2="-14.0462" y2="-0.127" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-0.127" x2="-15.0876" y2="-0.127" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-0.127" x2="-15.0876" y2="-0.381" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-0.381" x2="-14.0462" y2="-0.381" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-0.889" x2="-14.0462" y2="-0.6096" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-0.6096" x2="-15.0876" y2="-0.6096" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-0.6096" x2="-15.0876" y2="-0.889" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-0.889" x2="-14.0462" y2="-0.889" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-1.397" x2="-14.0462" y2="-1.1176" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-1.1176" x2="-15.0876" y2="-1.1176" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-1.1176" x2="-15.0876" y2="-1.397" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-1.397" x2="-14.0462" y2="-1.397" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-1.8796" x2="-14.0462" y2="-1.6256" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-1.6256" x2="-15.0876" y2="-1.6256" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-1.6256" x2="-15.0876" y2="-1.8796" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-1.8796" x2="-14.0462" y2="-1.8796" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-2.3876" x2="-14.0462" y2="-2.1082" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-2.1082" x2="-15.0876" y2="-2.1082" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-2.1082" x2="-15.0876" y2="-2.3876" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-2.3876" x2="-14.0462" y2="-2.3876" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-2.8956" x2="-14.0462" y2="-2.6162" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-2.6162" x2="-15.0876" y2="-2.6162" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-2.6162" x2="-15.0876" y2="-2.8956" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-2.8956" x2="-14.0462" y2="-2.8956" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-3.3782" x2="-14.0462" y2="-3.1242" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-3.1242" x2="-15.0876" y2="-3.1242" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-3.1242" x2="-15.0876" y2="-3.3782" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-3.3782" x2="-14.0462" y2="-3.3782" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-3.8862" x2="-14.0462" y2="-3.6068" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-3.6068" x2="-15.0876" y2="-3.6068" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-3.6068" x2="-15.0876" y2="-3.8862" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-3.8862" x2="-14.0462" y2="-3.8862" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-4.3942" x2="-14.0462" y2="-4.1148" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-4.1148" x2="-15.0876" y2="-4.1148" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-4.1148" x2="-15.0876" y2="-4.3942" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-4.3942" x2="-14.0462" y2="-4.3942" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-4.8768" x2="-14.0462" y2="-4.6228" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-4.6228" x2="-15.0876" y2="-4.6228" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-4.6228" x2="-15.0876" y2="-4.8768" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-4.8768" x2="-14.0462" y2="-4.8768" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-5.3848" x2="-14.0462" y2="-5.1054" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-5.1054" x2="-15.0876" y2="-5.1054" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-5.1054" x2="-15.0876" y2="-5.3848" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-5.3848" x2="-14.0462" y2="-5.3848" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-5.8928" x2="-14.0462" y2="-5.6134" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-5.6134" x2="-15.0876" y2="-5.6134" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-5.6134" x2="-15.0876" y2="-5.8928" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-5.8928" x2="-14.0462" y2="-5.8928" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-6.3754" x2="-14.0462" y2="-6.1214" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-6.1214" x2="-15.0876" y2="-6.1214" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-6.1214" x2="-15.0876" y2="-6.3754" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-6.3754" x2="-14.0462" y2="-6.3754" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-6.8834" x2="-14.0462" y2="-6.604" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-6.604" x2="-15.0876" y2="-6.604" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-6.604" x2="-15.0876" y2="-6.8834" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-6.8834" x2="-14.0462" y2="-6.8834" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-7.3914" x2="-14.0462" y2="-7.112" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-7.112" x2="-15.0876" y2="-7.112" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-7.112" x2="-15.0876" y2="-7.3914" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-7.3914" x2="-14.0462" y2="-7.3914" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-7.874" x2="-14.0462" y2="-7.62" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-7.62" x2="-15.0876" y2="-7.62" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-7.62" x2="-15.0876" y2="-7.874" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-7.874" x2="-14.0462" y2="-7.874" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-8.382" x2="-14.0462" y2="-8.1026" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-8.1026" x2="-15.0876" y2="-8.1026" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-8.1026" x2="-15.0876" y2="-8.382" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-8.382" x2="-14.0462" y2="-8.382" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-8.89" x2="-14.0462" y2="-8.6106" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-8.6106" x2="-15.0876" y2="-8.6106" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-8.6106" x2="-15.0876" y2="-8.89" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-8.89" x2="-14.0462" y2="-8.89" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-9.3726" x2="-14.0462" y2="-9.1186" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-9.1186" x2="-15.0876" y2="-9.1186" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-9.1186" x2="-15.0876" y2="-9.3726" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-9.3726" x2="-14.0462" y2="-9.3726" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-9.8806" x2="-14.0462" y2="-9.6266" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-9.6266" x2="-15.0876" y2="-9.6266" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-9.6266" x2="-15.0876" y2="-9.8806" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-9.8806" x2="-14.0462" y2="-9.8806" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-10.3886" x2="-14.0462" y2="-10.1092" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-10.1092" x2="-15.0876" y2="-10.1092" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-10.1092" x2="-15.0876" y2="-10.3886" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-10.3886" x2="-14.0462" y2="-10.3886" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-10.8966" x2="-14.0462" y2="-10.6172" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-10.6172" x2="-15.0876" y2="-10.6172" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-10.6172" x2="-15.0876" y2="-10.8966" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-10.8966" x2="-14.0462" y2="-10.8966" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-11.3792" x2="-14.0462" y2="-11.1252" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-11.1252" x2="-15.0876" y2="-11.1252" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-11.1252" x2="-15.0876" y2="-11.3792" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-11.3792" x2="-14.0462" y2="-11.3792" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-11.8872" x2="-14.0462" y2="-11.6078" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-11.6078" x2="-15.0876" y2="-11.6078" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-11.6078" x2="-15.0876" y2="-11.8872" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-11.8872" x2="-14.0462" y2="-11.8872" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-12.3952" x2="-14.0462" y2="-12.1158" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-12.1158" x2="-15.0876" y2="-12.1158" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-12.1158" x2="-15.0876" y2="-12.3952" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-12.3952" x2="-14.0462" y2="-12.3952" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-12.8778" x2="-14.0462" y2="-12.6238" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-12.6238" x2="-15.0876" y2="-12.6238" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-12.6238" x2="-15.0876" y2="-12.8778" width="0.1524" layer="51"/>
<wire x1="-15.0876" y1="-12.8778" x2="-14.0462" y2="-12.8778" width="0.1524" layer="51"/>
<wire x1="-12.6238" y1="-14.0462" x2="-12.8778" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-12.8778" y1="-14.0462" x2="-12.8778" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-12.8778" y1="-15.0876" x2="-12.6238" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-12.6238" y1="-15.0876" x2="-12.6238" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-12.1158" y1="-14.0462" x2="-12.3952" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-12.3952" y1="-14.0462" x2="-12.3952" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-12.3952" y1="-15.0876" x2="-12.1158" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-12.1158" y1="-15.0876" x2="-12.1158" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-11.6078" y1="-14.0462" x2="-11.8872" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-11.8872" y1="-14.0462" x2="-11.8872" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-11.8872" y1="-15.0876" x2="-11.6078" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-11.6078" y1="-15.0876" x2="-11.6078" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-11.1252" y1="-14.0462" x2="-11.3792" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-11.3792" y1="-14.0462" x2="-11.3792" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-11.3792" y1="-15.0876" x2="-11.1252" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-11.1252" y1="-15.0876" x2="-11.1252" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-10.6172" y1="-14.0462" x2="-10.8966" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-10.8966" y1="-14.0462" x2="-10.8966" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-10.8966" y1="-15.0876" x2="-10.6172" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-10.6172" y1="-15.0876" x2="-10.6172" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-10.1092" y1="-14.0462" x2="-10.3886" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-10.3886" y1="-14.0462" x2="-10.3886" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-10.3886" y1="-15.0876" x2="-10.1092" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-10.1092" y1="-15.0876" x2="-10.1092" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-9.6266" y1="-14.0462" x2="-9.8806" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-9.8806" y1="-14.0462" x2="-9.8806" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-9.8806" y1="-15.0876" x2="-9.6266" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-9.6266" y1="-15.0876" x2="-9.6266" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-9.1186" y1="-14.0462" x2="-9.3726" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-9.3726" y1="-14.0462" x2="-9.3726" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-9.3726" y1="-15.0876" x2="-9.1186" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-9.1186" y1="-15.0876" x2="-9.1186" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-8.6106" y1="-14.0462" x2="-8.89" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-8.89" y1="-14.0462" x2="-8.89" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-8.89" y1="-15.0876" x2="-8.6106" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-8.6106" y1="-15.0876" x2="-8.6106" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-8.1026" y1="-14.0462" x2="-8.382" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-8.382" y1="-14.0462" x2="-8.382" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-8.382" y1="-15.0876" x2="-8.1026" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-8.1026" y1="-15.0876" x2="-8.1026" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-7.62" y1="-14.0462" x2="-7.874" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-7.874" y1="-14.0462" x2="-7.874" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-7.874" y1="-15.0876" x2="-7.62" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-7.62" y1="-15.0876" x2="-7.62" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-7.112" y1="-14.0462" x2="-7.3914" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-7.3914" y1="-14.0462" x2="-7.3914" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-7.3914" y1="-15.0876" x2="-7.112" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-7.112" y1="-15.0876" x2="-7.112" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-6.604" y1="-14.0462" x2="-6.8834" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-6.8834" y1="-14.0462" x2="-6.8834" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-6.8834" y1="-15.0876" x2="-6.604" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-6.604" y1="-15.0876" x2="-6.604" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-6.1214" y1="-14.0462" x2="-6.3754" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-6.3754" y1="-14.0462" x2="-6.3754" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-6.3754" y1="-15.0876" x2="-6.1214" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-6.1214" y1="-15.0876" x2="-6.1214" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-5.6134" y1="-14.0462" x2="-5.8928" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-5.8928" y1="-14.0462" x2="-5.8928" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-5.8928" y1="-15.0876" x2="-5.6134" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-5.6134" y1="-15.0876" x2="-5.6134" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-5.1054" y1="-14.0462" x2="-5.3848" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-5.3848" y1="-14.0462" x2="-5.3848" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-5.3848" y1="-15.0876" x2="-5.1054" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-5.1054" y1="-15.0876" x2="-5.1054" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-4.6228" y1="-14.0462" x2="-4.8768" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-4.8768" y1="-14.0462" x2="-4.8768" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-4.8768" y1="-15.0876" x2="-4.6228" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-4.6228" y1="-15.0876" x2="-4.6228" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-4.1148" y1="-14.0462" x2="-4.3942" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-4.3942" y1="-14.0462" x2="-4.3942" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-4.3942" y1="-15.0876" x2="-4.1148" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-4.1148" y1="-15.0876" x2="-4.1148" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-3.6068" y1="-14.0462" x2="-3.8862" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-3.8862" y1="-14.0462" x2="-3.8862" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-3.8862" y1="-15.0876" x2="-3.6068" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-3.6068" y1="-15.0876" x2="-3.6068" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-3.1242" y1="-14.0462" x2="-3.3782" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-3.3782" y1="-14.0462" x2="-3.3782" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-3.3782" y1="-15.0876" x2="-3.1242" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-3.1242" y1="-15.0876" x2="-3.1242" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-2.6162" y1="-14.0462" x2="-2.8956" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-2.8956" y1="-14.0462" x2="-2.8956" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-2.8956" y1="-15.0876" x2="-2.6162" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-2.6162" y1="-15.0876" x2="-2.6162" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-2.1082" y1="-14.0462" x2="-2.3876" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-2.3876" y1="-14.0462" x2="-2.3876" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-2.3876" y1="-15.0876" x2="-2.1082" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-2.1082" y1="-15.0876" x2="-2.1082" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-1.6256" y1="-14.0462" x2="-1.8796" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-1.8796" y1="-14.0462" x2="-1.8796" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-1.8796" y1="-15.0876" x2="-1.6256" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-1.6256" y1="-15.0876" x2="-1.6256" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-1.1176" y1="-14.0462" x2="-1.397" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-1.397" y1="-14.0462" x2="-1.397" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-1.397" y1="-15.0876" x2="-1.1176" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-1.1176" y1="-15.0876" x2="-1.1176" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-0.6096" y1="-14.0462" x2="-0.889" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-0.889" y1="-14.0462" x2="-0.889" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-0.889" y1="-15.0876" x2="-0.6096" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-0.6096" y1="-15.0876" x2="-0.6096" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-0.127" y1="-14.0462" x2="-0.381" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="-0.381" y1="-14.0462" x2="-0.381" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-0.381" y1="-15.0876" x2="-0.127" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="-0.127" y1="-15.0876" x2="-0.127" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="0.381" y1="-14.0462" x2="0.127" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="0.127" y1="-14.0462" x2="0.127" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="0.127" y1="-15.0876" x2="0.381" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="0.381" y1="-15.0876" x2="0.381" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="0.889" y1="-14.0462" x2="0.6096" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="0.6096" y1="-14.0462" x2="0.6096" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="0.6096" y1="-15.0876" x2="0.889" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="0.889" y1="-15.0876" x2="0.889" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="1.397" y1="-14.0462" x2="1.1176" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="1.1176" y1="-14.0462" x2="1.1176" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="1.1176" y1="-15.0876" x2="1.397" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="1.397" y1="-15.0876" x2="1.397" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="1.8796" y1="-14.0462" x2="1.6256" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="1.6256" y1="-14.0462" x2="1.6256" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="1.6256" y1="-15.0876" x2="1.8796" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="1.8796" y1="-15.0876" x2="1.8796" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="2.3876" y1="-14.0462" x2="2.1082" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="2.1082" y1="-14.0462" x2="2.1082" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="2.1082" y1="-15.0876" x2="2.3876" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="2.3876" y1="-15.0876" x2="2.3876" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="2.8956" y1="-14.0462" x2="2.6162" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="2.6162" y1="-14.0462" x2="2.6162" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="2.6162" y1="-15.0876" x2="2.8956" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="2.8956" y1="-15.0876" x2="2.8956" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="3.3782" y1="-14.0462" x2="3.1242" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="3.1242" y1="-14.0462" x2="3.1242" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="3.1242" y1="-15.0876" x2="3.3782" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="3.3782" y1="-15.0876" x2="3.3782" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="3.8862" y1="-14.0462" x2="3.6068" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="3.6068" y1="-14.0462" x2="3.6068" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="3.6068" y1="-15.0876" x2="3.8862" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="3.8862" y1="-15.0876" x2="3.8862" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="4.3942" y1="-14.0462" x2="4.1148" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="4.1148" y1="-14.0462" x2="4.1148" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="4.1148" y1="-15.0876" x2="4.3942" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="4.3942" y1="-15.0876" x2="4.3942" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="4.8768" y1="-14.0462" x2="4.6228" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="4.6228" y1="-14.0462" x2="4.6228" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="4.6228" y1="-15.0876" x2="4.8768" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="4.8768" y1="-15.0876" x2="4.8768" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="5.3848" y1="-14.0462" x2="5.1054" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="5.1054" y1="-14.0462" x2="5.1054" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="5.1054" y1="-15.0876" x2="5.3848" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="5.3848" y1="-15.0876" x2="5.3848" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="5.8928" y1="-14.0462" x2="5.6134" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="5.6134" y1="-14.0462" x2="5.6134" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="5.6134" y1="-15.0876" x2="5.8928" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="5.8928" y1="-15.0876" x2="5.8928" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="6.3754" y1="-14.0462" x2="6.1214" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="6.1214" y1="-14.0462" x2="6.1214" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="6.1214" y1="-15.0876" x2="6.3754" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="6.3754" y1="-15.0876" x2="6.3754" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="6.8834" y1="-14.0462" x2="6.604" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="6.604" y1="-14.0462" x2="6.604" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="6.604" y1="-15.0876" x2="6.8834" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="6.8834" y1="-15.0876" x2="6.8834" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="7.3914" y1="-14.0462" x2="7.112" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="7.112" y1="-14.0462" x2="7.112" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="7.112" y1="-15.0876" x2="7.3914" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="7.3914" y1="-15.0876" x2="7.3914" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="7.874" y1="-14.0462" x2="7.62" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="7.62" y1="-14.0462" x2="7.62" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="7.62" y1="-15.0876" x2="7.874" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="7.874" y1="-15.0876" x2="7.874" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="8.382" y1="-14.0462" x2="8.1026" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="8.1026" y1="-14.0462" x2="8.1026" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="8.1026" y1="-15.0876" x2="8.382" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="8.382" y1="-15.0876" x2="8.382" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="8.89" y1="-14.0462" x2="8.6106" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="8.6106" y1="-14.0462" x2="8.6106" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="8.6106" y1="-15.0876" x2="8.89" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="8.89" y1="-15.0876" x2="8.89" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="9.3726" y1="-14.0462" x2="9.1186" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="9.1186" y1="-14.0462" x2="9.1186" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="9.1186" y1="-15.0876" x2="9.3726" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="9.3726" y1="-15.0876" x2="9.3726" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="9.8806" y1="-14.0462" x2="9.6266" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="9.6266" y1="-14.0462" x2="9.6266" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="9.6266" y1="-15.0876" x2="9.8806" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="9.8806" y1="-15.0876" x2="9.8806" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="10.3886" y1="-14.0462" x2="10.1092" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="10.1092" y1="-14.0462" x2="10.1092" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="10.1092" y1="-15.0876" x2="10.3886" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="10.3886" y1="-15.0876" x2="10.3886" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="10.8966" y1="-14.0462" x2="10.6172" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="10.6172" y1="-14.0462" x2="10.6172" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="10.6172" y1="-15.0876" x2="10.8966" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="10.8966" y1="-15.0876" x2="10.8966" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="11.3792" y1="-14.0462" x2="11.1252" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="11.1252" y1="-14.0462" x2="11.1252" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="11.1252" y1="-15.0876" x2="11.3792" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="11.3792" y1="-15.0876" x2="11.3792" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="11.8872" y1="-14.0462" x2="11.6078" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="11.6078" y1="-14.0462" x2="11.6078" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="11.6078" y1="-15.0876" x2="11.8872" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="11.8872" y1="-15.0876" x2="11.8872" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="12.3952" y1="-14.0462" x2="12.1158" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="12.1158" y1="-14.0462" x2="12.1158" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="12.1158" y1="-15.0876" x2="12.3952" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="12.3952" y1="-15.0876" x2="12.3952" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="12.8778" y1="-14.0462" x2="12.6238" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="12.6238" y1="-14.0462" x2="12.6238" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="12.6238" y1="-15.0876" x2="12.8778" y2="-15.0876" width="0.1524" layer="51"/>
<wire x1="12.8778" y1="-15.0876" x2="12.8778" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-12.6238" x2="14.0462" y2="-12.8778" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-12.8778" x2="15.0876" y2="-12.8778" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-12.8778" x2="15.0876" y2="-12.6238" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-12.6238" x2="14.0462" y2="-12.6238" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-12.1158" x2="14.0462" y2="-12.3952" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-12.3952" x2="15.0876" y2="-12.3952" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-12.3952" x2="15.0876" y2="-12.1158" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-12.1158" x2="14.0462" y2="-12.1158" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-11.6078" x2="14.0462" y2="-11.8872" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-11.8872" x2="15.0876" y2="-11.8872" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-11.8872" x2="15.0876" y2="-11.6078" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-11.6078" x2="14.0462" y2="-11.6078" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-11.1252" x2="14.0462" y2="-11.3792" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-11.3792" x2="15.0876" y2="-11.3792" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-11.3792" x2="15.0876" y2="-11.1252" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-11.1252" x2="14.0462" y2="-11.1252" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-10.6172" x2="14.0462" y2="-10.8966" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-10.8966" x2="15.0876" y2="-10.8966" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-10.8966" x2="15.0876" y2="-10.6172" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-10.6172" x2="14.0462" y2="-10.6172" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-10.1092" x2="14.0462" y2="-10.3886" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-10.3886" x2="15.0876" y2="-10.3886" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-10.3886" x2="15.0876" y2="-10.1092" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-10.1092" x2="14.0462" y2="-10.1092" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-9.6266" x2="14.0462" y2="-9.8806" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-9.8806" x2="15.0876" y2="-9.8806" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-9.8806" x2="15.0876" y2="-9.6266" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-9.6266" x2="14.0462" y2="-9.6266" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-9.1186" x2="14.0462" y2="-9.3726" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-9.3726" x2="15.0876" y2="-9.3726" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-9.3726" x2="15.0876" y2="-9.1186" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-9.1186" x2="14.0462" y2="-9.1186" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-8.6106" x2="14.0462" y2="-8.89" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-8.89" x2="15.0876" y2="-8.89" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-8.89" x2="15.0876" y2="-8.6106" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-8.6106" x2="14.0462" y2="-8.6106" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-8.1026" x2="14.0462" y2="-8.382" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-8.382" x2="15.0876" y2="-8.382" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-8.382" x2="15.0876" y2="-8.1026" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-8.1026" x2="14.0462" y2="-8.1026" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-7.62" x2="14.0462" y2="-7.874" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-7.874" x2="15.0876" y2="-7.874" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-7.874" x2="15.0876" y2="-7.62" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-7.62" x2="14.0462" y2="-7.62" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-7.112" x2="14.0462" y2="-7.3914" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-7.3914" x2="15.0876" y2="-7.3914" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-7.3914" x2="15.0876" y2="-7.112" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-7.112" x2="14.0462" y2="-7.112" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-6.604" x2="14.0462" y2="-6.8834" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-6.8834" x2="15.0876" y2="-6.8834" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-6.8834" x2="15.0876" y2="-6.604" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-6.604" x2="14.0462" y2="-6.604" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-6.1214" x2="14.0462" y2="-6.3754" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-6.3754" x2="15.0876" y2="-6.3754" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-6.3754" x2="15.0876" y2="-6.1214" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-6.1214" x2="14.0462" y2="-6.1214" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-5.6134" x2="14.0462" y2="-5.8928" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-5.8928" x2="15.0876" y2="-5.8928" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-5.8928" x2="15.0876" y2="-5.6134" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-5.6134" x2="14.0462" y2="-5.6134" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-5.1054" x2="14.0462" y2="-5.3848" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-5.3848" x2="15.0876" y2="-5.3848" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-5.3848" x2="15.0876" y2="-5.1054" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-5.1054" x2="14.0462" y2="-5.1054" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-4.6228" x2="14.0462" y2="-4.8768" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-4.8768" x2="15.0876" y2="-4.8768" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-4.8768" x2="15.0876" y2="-4.6228" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-4.6228" x2="14.0462" y2="-4.6228" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-4.1148" x2="14.0462" y2="-4.3942" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-4.3942" x2="15.0876" y2="-4.3942" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-4.3942" x2="15.0876" y2="-4.1148" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-4.1148" x2="14.0462" y2="-4.1148" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-3.6068" x2="14.0462" y2="-3.8862" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-3.8862" x2="15.0876" y2="-3.8862" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-3.8862" x2="15.0876" y2="-3.6068" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-3.6068" x2="14.0462" y2="-3.6068" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-3.1242" x2="14.0462" y2="-3.3782" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-3.3782" x2="15.0876" y2="-3.3782" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-3.3782" x2="15.0876" y2="-3.1242" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-3.1242" x2="14.0462" y2="-3.1242" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-2.6162" x2="14.0462" y2="-2.8956" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-2.8956" x2="15.0876" y2="-2.8956" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-2.8956" x2="15.0876" y2="-2.6162" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-2.6162" x2="14.0462" y2="-2.6162" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-2.1082" x2="14.0462" y2="-2.3876" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-2.3876" x2="15.0876" y2="-2.3876" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-2.3876" x2="15.0876" y2="-2.1082" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-2.1082" x2="14.0462" y2="-2.1082" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-1.6256" x2="14.0462" y2="-1.8796" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-1.8796" x2="15.0876" y2="-1.8796" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-1.8796" x2="15.0876" y2="-1.6256" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-1.6256" x2="14.0462" y2="-1.6256" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-1.1176" x2="14.0462" y2="-1.397" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-1.397" x2="15.0876" y2="-1.397" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-1.397" x2="15.0876" y2="-1.1176" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-1.1176" x2="14.0462" y2="-1.1176" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-0.6096" x2="14.0462" y2="-0.889" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-0.889" x2="15.0876" y2="-0.889" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-0.889" x2="15.0876" y2="-0.6096" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-0.6096" x2="14.0462" y2="-0.6096" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-0.127" x2="14.0462" y2="-0.381" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-0.381" x2="15.0876" y2="-0.381" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-0.381" x2="15.0876" y2="-0.127" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="-0.127" x2="14.0462" y2="-0.127" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="0.381" x2="14.0462" y2="0.127" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="0.127" x2="15.0876" y2="0.127" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="0.127" x2="15.0876" y2="0.381" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="0.381" x2="14.0462" y2="0.381" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="0.889" x2="14.0462" y2="0.6096" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="0.6096" x2="15.0876" y2="0.6096" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="0.6096" x2="15.0876" y2="0.889" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="0.889" x2="14.0462" y2="0.889" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="1.397" x2="14.0462" y2="1.1176" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="1.1176" x2="15.0876" y2="1.1176" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="1.1176" x2="15.0876" y2="1.397" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="1.397" x2="14.0462" y2="1.397" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="1.8796" x2="14.0462" y2="1.6256" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="1.6256" x2="15.0876" y2="1.6256" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="1.6256" x2="15.0876" y2="1.8796" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="1.8796" x2="14.0462" y2="1.8796" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="2.3876" x2="14.0462" y2="2.1082" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="2.1082" x2="15.0876" y2="2.1082" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="2.1082" x2="15.0876" y2="2.3876" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="2.3876" x2="14.0462" y2="2.3876" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="2.8956" x2="14.0462" y2="2.6162" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="2.6162" x2="15.0876" y2="2.6162" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="2.6162" x2="15.0876" y2="2.8956" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="2.8956" x2="14.0462" y2="2.8956" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="3.3782" x2="14.0462" y2="3.1242" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="3.1242" x2="15.0876" y2="3.1242" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="3.1242" x2="15.0876" y2="3.3782" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="3.3782" x2="14.0462" y2="3.3782" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="3.8862" x2="14.0462" y2="3.6068" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="3.6068" x2="15.0876" y2="3.6068" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="3.6068" x2="15.0876" y2="3.8862" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="3.8862" x2="14.0462" y2="3.8862" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="4.3942" x2="14.0462" y2="4.1148" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="4.1148" x2="15.0876" y2="4.1148" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="4.1148" x2="15.0876" y2="4.3942" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="4.3942" x2="14.0462" y2="4.3942" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="4.8768" x2="14.0462" y2="4.6228" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="4.6228" x2="15.0876" y2="4.6228" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="4.6228" x2="15.0876" y2="4.8768" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="4.8768" x2="14.0462" y2="4.8768" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="5.3848" x2="14.0462" y2="5.1054" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="5.1054" x2="15.0876" y2="5.1054" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="5.1054" x2="15.0876" y2="5.3848" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="5.3848" x2="14.0462" y2="5.3848" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="5.8928" x2="14.0462" y2="5.6134" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="5.6134" x2="15.0876" y2="5.6134" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="5.6134" x2="15.0876" y2="5.8928" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="5.8928" x2="14.0462" y2="5.8928" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="6.3754" x2="14.0462" y2="6.1214" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="6.1214" x2="15.0876" y2="6.1214" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="6.1214" x2="15.0876" y2="6.3754" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="6.3754" x2="14.0462" y2="6.3754" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="6.8834" x2="14.0462" y2="6.604" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="6.604" x2="15.0876" y2="6.604" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="6.604" x2="15.0876" y2="6.8834" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="6.8834" x2="14.0462" y2="6.8834" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="7.3914" x2="14.0462" y2="7.112" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="7.112" x2="15.0876" y2="7.112" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="7.112" x2="15.0876" y2="7.3914" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="7.3914" x2="14.0462" y2="7.3914" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="7.874" x2="14.0462" y2="7.62" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="7.62" x2="15.0876" y2="7.62" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="7.62" x2="15.0876" y2="7.874" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="7.874" x2="14.0462" y2="7.874" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="8.382" x2="14.0462" y2="8.1026" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="8.1026" x2="15.0876" y2="8.1026" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="8.1026" x2="15.0876" y2="8.382" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="8.382" x2="14.0462" y2="8.382" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="8.89" x2="14.0462" y2="8.6106" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="8.6106" x2="15.0876" y2="8.6106" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="8.6106" x2="15.0876" y2="8.89" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="8.89" x2="14.0462" y2="8.89" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="9.3726" x2="14.0462" y2="9.1186" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="9.1186" x2="15.0876" y2="9.1186" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="9.1186" x2="15.0876" y2="9.3726" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="9.3726" x2="14.0462" y2="9.3726" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="9.8806" x2="14.0462" y2="9.6266" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="9.6266" x2="15.0876" y2="9.6266" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="9.6266" x2="15.0876" y2="9.8806" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="9.8806" x2="14.0462" y2="9.8806" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="10.3886" x2="14.0462" y2="10.1092" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="10.1092" x2="15.0876" y2="10.1092" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="10.1092" x2="15.0876" y2="10.3886" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="10.3886" x2="14.0462" y2="10.3886" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="10.8966" x2="14.0462" y2="10.6172" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="10.6172" x2="15.0876" y2="10.6172" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="10.6172" x2="15.0876" y2="10.8966" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="10.8966" x2="14.0462" y2="10.8966" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="11.3792" x2="14.0462" y2="11.1252" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="11.1252" x2="15.0876" y2="11.1252" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="11.1252" x2="15.0876" y2="11.3792" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="11.3792" x2="14.0462" y2="11.3792" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="11.8872" x2="14.0462" y2="11.6078" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="11.6078" x2="15.0876" y2="11.6078" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="11.6078" x2="15.0876" y2="11.8872" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="11.8872" x2="14.0462" y2="11.8872" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="12.3952" x2="14.0462" y2="12.1158" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="12.1158" x2="15.0876" y2="12.1158" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="12.1158" x2="15.0876" y2="12.3952" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="12.3952" x2="14.0462" y2="12.3952" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="12.8778" x2="14.0462" y2="12.6238" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="12.6238" x2="15.0876" y2="12.6238" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="12.6238" x2="15.0876" y2="12.8778" width="0.1524" layer="51"/>
<wire x1="15.0876" y1="12.8778" x2="14.0462" y2="12.8778" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="-14.0462" x2="14.0462" y2="-14.0462" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="-14.0462" x2="14.0462" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="14.0462" y1="14.0462" x2="-14.0462" y2="14.0462" width="0.1524" layer="51"/>
<wire x1="-14.0462" y1="14.0462" x2="-14.0462" y2="-14.0462" width="0.1524" layer="51"/>
<text x="-4.8006" y="0.254" size="2.0828" layer="21" font="vector" ratio="10" rot="SR0">&gt;NAME</text>
<text x="-5.08" y="-3.2766" size="2.0828" layer="21" font="vector" ratio="10" rot="SR0">&gt;VALUE</text>
<circle x="-11.684" y="11.684" radius="0.359209375" width="0.2032" layer="21"/>
<wire x1="-13.716" y1="13.716" x2="13.716" y2="13.716" width="0.2032" layer="21"/>
<wire x1="13.716" y1="13.716" x2="13.716" y2="-13.716" width="0.2032" layer="21"/>
<wire x1="13.716" y1="-13.716" x2="-13.716" y2="-13.716" width="0.2032" layer="21"/>
<wire x1="-13.716" y1="-13.716" x2="-13.716" y2="13.716" width="0.2032" layer="21"/>
</package>
<package name="XTAL_SMD_3.2X2.5">
<description>http://www.farnell.com/datasheets/1796637.pdf

TXC  7M-14.31818MAAJ-T  XTAL, 14.31818MHZ, 18PF,SMD, 3.2X2.5


    Crystal Case: SMD, 3.2mm x 2.5mm
    Frequency Nom: 14.31818MHz
    Frequency Stability + / -: 30ppm
    Frequency Tolerance + / -: 30ppm
    Load Capacitance: 18pF
    Operating Temperature Max: 85°C
    Operating Temperature Min: -40°C
    Product Range: 7M Series
    SVHC: No SVHC (15-Jun-2015</description>
<smd name="P$1" x="-0.7" y="0.6" dx="1.4" dy="1.2" layer="1"/>
<smd name="P$2" x="1.5" y="0.6" dx="1.4" dy="1.2" layer="1"/>
<smd name="P$3" x="1.5" y="-1.1" dx="1.4" dy="1.2" layer="1"/>
<smd name="P$4" x="-0.7" y="-1.1" dx="1.4" dy="1.2" layer="1"/>
<wire x1="0.2" y1="1" x2="0.6" y2="1" width="0.2032" layer="21"/>
<wire x1="0.2" y1="-1.5" x2="0.6" y2="-1.5" width="0.2032" layer="21"/>
<wire x1="-1.2" y1="-0.3" x2="-1.2" y2="-0.2" width="0.2032" layer="21"/>
<wire x1="2" y1="-0.3" x2="2" y2="-0.2" width="0.2032" layer="21"/>
<text x="2.54" y="0" size="0.8128" layer="21" font="vector">&gt;NAME</text>
<text x="2.54" y="-1.27" size="0.8128" layer="21" font="vector">&gt;VALUE</text>
</package>
<package name="XTAL_SMD_5X3.2">
<smd name="P$1" x="-2.54" y="0" dx="1.384" dy="1.7" layer="1" rot="R90"/>
<smd name="P$2" x="2.54" y="0" dx="1.384" dy="1.7" layer="1" rot="R90"/>
<wire x1="-2.6" y1="1.5" x2="-2.4" y2="1.7" width="0.127" layer="21"/>
<wire x1="-2.4" y1="1.7" x2="2.4" y2="1.7" width="0.127" layer="21"/>
<wire x1="2.4" y1="1.7" x2="2.6" y2="1.5" width="0.127" layer="21"/>
<wire x1="2.7" y1="-1.5" x2="2.5" y2="-1.7" width="0.127" layer="21"/>
<wire x1="2.5" y1="-1.7" x2="-2.4" y2="-1.7" width="0.127" layer="21"/>
<wire x1="-2.4" y1="-1.7" x2="-2.6" y2="-1.5" width="0.127" layer="21"/>
<text x="-3.175" y="1.905" size="1.27" layer="21" font="vector">&gt;VALUE</text>
<text x="-3.175" y="-3.175" size="1.27" layer="21" font="vector">&gt;NAME</text>
</package>
<package name="BATTERY_HOLDER_COIN_20MM_SMD">
<description>http://www.farnell.com/datasheets/1505862.pdf</description>
<smd name="-" x="0" y="0" dx="3.6" dy="2.6" layer="1"/>
<smd name="+" x="21.5" y="0" dx="3.6" dy="2.6" layer="1" rot="R90"/>
<wire x1="0.5" y1="8" x2="0" y2="7.5" width="0.2032" layer="21"/>
<wire x1="0" y1="7.5" x2="-2.5" y2="0" width="0.2032" layer="21" curve="46.397181"/>
<wire x1="-2.5" y1="0" x2="0" y2="-7.5" width="0.2032" layer="21" curve="44.464429"/>
<wire x1="0" y1="-7.5" x2="0.5" y2="-8" width="0.2032" layer="21" curve="1.932742"/>
<wire x1="22.5" y1="6.5" x2="22.5" y2="2.5" width="0.2032" layer="21"/>
<wire x1="22.5" y1="-2.5" x2="22.5" y2="-6.5" width="0.2032" layer="21"/>
<wire x1="22.5" y1="6.5" x2="18" y2="6.5" width="0.2032" layer="21"/>
<wire x1="22.5" y1="-6.5" x2="18" y2="-6.5" width="0.2032" layer="21"/>
<wire x1="0.5" y1="-8" x2="16.5" y2="-8" width="0.2032" layer="21"/>
<wire x1="16.5" y1="-8" x2="18" y2="-6.5" width="0.2032" layer="21"/>
<wire x1="0.5" y1="8" x2="16.5" y2="8" width="0.2032" layer="21"/>
<wire x1="16.5" y1="8" x2="18" y2="6.5" width="0.2032" layer="21"/>
<wire x1="0.5" y1="8" x2="1" y2="8.5" width="0.2032" layer="21"/>
<wire x1="1" y1="8.5" x2="16" y2="8.5" width="0.2032" layer="21" style="shortdash" curve="-90"/>
<wire x1="16" y1="8.5" x2="16.5" y2="8" width="0.2032" layer="21" style="shortdash"/>
<wire x1="16.5" y1="-8" x2="16" y2="-8.5" width="0.2032" layer="21" style="shortdash"/>
<wire x1="16" y1="-8.5" x2="1" y2="-8.5" width="0.2032" layer="21" style="shortdash" curve="-90"/>
<wire x1="1" y1="-8.5" x2="0.5" y2="-8" width="0.2032" layer="21" style="shortdash"/>
<text x="7.5" y="1" size="1.27" layer="21" font="vector">&gt;NAME</text>
<text x="7.5" y="-1" size="1.27" layer="21" font="vector">&gt;VALUE</text>
</package>
<package name="XTAL_ABS25">
<smd name="1" x="0" y="0" dx="1.27" dy="1.905" layer="1"/>
<smd name="4" x="0" y="3.175" dx="1.27" dy="1.905" layer="1"/>
<smd name="2" x="6.858" y="0" dx="1.27" dy="1.905" layer="1"/>
<smd name="3" x="6.858" y="3.175" dx="1.27" dy="1.905" layer="1"/>
<wire x1="-1.143" y1="3.175" x2="-1.905" y2="3.175" width="0.2032" layer="21"/>
<wire x1="-1.905" y1="3.175" x2="-1.905" y2="0" width="0.2032" layer="21"/>
<wire x1="-1.905" y1="0" x2="-1.143" y2="0" width="0.2032" layer="21"/>
<wire x1="1.016" y1="0" x2="5.842" y2="0" width="0.2032" layer="21"/>
<wire x1="1.016" y1="3.175" x2="5.842" y2="3.175" width="0.2032" layer="21"/>
<wire x1="7.874" y1="3.175" x2="8.636" y2="3.175" width="0.2032" layer="21"/>
<wire x1="8.636" y1="3.175" x2="8.636" y2="0" width="0.2032" layer="21"/>
<wire x1="8.636" y1="0" x2="7.874" y2="0" width="0.2032" layer="21"/>
<text x="1.27" y="1.905" size="0.8128" layer="21" font="vector">&gt;NAME</text>
<text x="1.27" y="0.635" size="0.8128" layer="21" font="vector">&gt;VALUE</text>
</package>
<package name="DO219AB">
<smd name="P$1" x="0" y="0" dx="1.3" dy="1.4" layer="1"/>
<smd name="P$2" x="3.535" y="0" dx="1.3" dy="1.4" layer="1"/>
<wire x1="1.3175" y1="0.6" x2="1.3175" y2="-0.6" width="0.2032" layer="21"/>
<wire x1="1.3175" y1="-0.6" x2="2.2175" y2="0" width="0.2032" layer="21"/>
<wire x1="2.2175" y1="0" x2="1.3175" y2="0.6" width="0.2032" layer="21"/>
<wire x1="2.2175" y1="0.6" x2="2.2175" y2="-0.6" width="0.2032" layer="21"/>
<text x="0.5" y="1" size="0.8128" layer="21" font="vector">&gt;NAME</text>
</package>
<package name="DO-214AC">
<smd name="A" x="0.35" y="0" dx="1.8" dy="1.4" layer="1" rot="R180"/>
<smd name="K" x="5.3" y="0" dx="1.8" dy="1.4" layer="1"/>
<wire x1="0.45" y1="1.4" x2="5.2" y2="1.4" width="0.2032" layer="21"/>
<wire x1="5.2" y1="-1.4" x2="0.45" y2="-1.4" width="0.2032" layer="21"/>
<wire x1="2.3" y1="1" x2="3.3" y2="0" width="0.2032" layer="21"/>
<wire x1="3.3" y1="0" x2="2.3" y2="-1" width="0.2032" layer="21"/>
<wire x1="2.3" y1="-1" x2="2.3" y2="1" width="0.2032" layer="21"/>
<wire x1="3.4" y1="1" x2="3.4" y2="-1" width="0.2032" layer="21"/>
<wire x1="0.45" y1="-1.4" x2="0.45" y2="-1.1" width="0.2032" layer="21"/>
<wire x1="0.45" y1="1.4" x2="0.45" y2="1.1" width="0.2032" layer="21"/>
<wire x1="5.25" y1="-1.4" x2="5.25" y2="-1.1" width="0.2032" layer="21"/>
<wire x1="5.2" y1="1.4" x2="5.2" y2="1.1" width="0.2032" layer="21"/>
</package>
<package name="SOIC8">
<smd name="P$1" x="-2.286" y="2.54" dx="0.635" dy="1.524" layer="1" rot="R270"/>
<smd name="P$2" x="-2.286" y="1.27" dx="0.635" dy="1.524" layer="1" roundness="100" rot="R270"/>
<smd name="P$3" x="-2.286" y="0" dx="0.635" dy="1.524" layer="1" roundness="100" rot="R270"/>
<smd name="P$4" x="-2.286" y="-1.27" dx="0.635" dy="1.524" layer="1" roundness="100" rot="R270"/>
<smd name="P$5" x="3.556" y="-1.27" dx="0.635" dy="1.524" layer="1" roundness="100" rot="R270"/>
<smd name="P$6" x="3.556" y="0" dx="0.635" dy="1.524" layer="1" roundness="100" rot="R270"/>
<smd name="P$7" x="3.556" y="1.27" dx="0.635" dy="1.524" layer="1" roundness="100" rot="R270"/>
<smd name="P$8" x="3.556" y="2.54" dx="0.635" dy="1.524" layer="1" roundness="100" rot="R270"/>
<wire x1="2.286" y1="3.556" x2="2.286" y2="-2.286" width="0.2032" layer="21"/>
<wire x1="2.286" y1="-2.286" x2="-1.016" y2="-2.286" width="0.2032" layer="21"/>
<wire x1="-1.016" y1="-2.286" x2="-1.016" y2="3.556" width="0.2032" layer="21"/>
<wire x1="-1.016" y1="3.556" x2="2.286" y2="3.556" width="0.2032" layer="21"/>
<circle x="0" y="2.54" radius="0.359209375" width="0.2032" layer="21"/>
<text x="-0.635" y="0.635" size="0.8128" layer="21" font="vector">&gt;NAME</text>
<text x="-0.635" y="-0.635" size="0.8128" layer="21" font="vector">&gt;VALUE</text>
</package>
<package name="CAP_POL_SMD_10X10X10MM">
<smd name="+" x="0" y="-0.635" dx="1.5" dy="2.54" layer="1"/>
<smd name="-" x="0" y="10.935" dx="1.5" dy="2.54" layer="1"/>
<wire x1="-1.5" y1="0" x2="-3.5" y2="0" width="0.2032" layer="21"/>
<wire x1="-3.5" y1="0" x2="-5.5" y2="2" width="0.2032" layer="21"/>
<wire x1="-5.5" y1="2" x2="-5.5" y2="10.5" width="0.2032" layer="21"/>
<wire x1="-5.5" y1="10.5" x2="-1.5" y2="10.5" width="0.2032" layer="21"/>
<wire x1="1.5" y1="10.5" x2="5.5" y2="10.5" width="0.2032" layer="21"/>
<wire x1="5.5" y1="10.5" x2="5.5" y2="2" width="0.2032" layer="21"/>
<wire x1="5.5" y1="2" x2="3.5" y2="0" width="0.2032" layer="21"/>
<wire x1="3.5" y1="0" x2="1.5" y2="0" width="0.2032" layer="21"/>
<text x="-1" y="3.5" size="1.27" layer="21" font="vector">&gt;VALUE</text>
<text x="-1" y="5.365" size="1.27" layer="21" font="vector">&gt;NAME</text>
</package>
<package name="1210">
<description>metric 3225 SMD package</description>
<smd name="P$1" x="-0.3" y="0" dx="2.5" dy="2" layer="1" rot="R270"/>
<smd name="P$2" x="3.4" y="0" dx="2.5" dy="2" layer="1" rot="R270"/>
<wire x1="1.1" y1="1.1" x2="1.1" y2="-1.1" width="0.2032" layer="21"/>
</package>
<package name="INDUCTOR_BOURNS_10X13X5MM">
<smd name="P$1" x="-1.754" y="0" dx="2.8" dy="3.556" layer="1" rot="R90"/>
<smd name="P$2" x="9.054" y="0" dx="2.8" dy="3.556" layer="1" rot="R270"/>
<wire x1="-2.4" y1="1.8" x2="1.6" y2="4.6" width="0.2032" layer="21"/>
<wire x1="1.6" y1="4.6" x2="6" y2="4.6" width="0.2032" layer="21" curve="-72.359206"/>
<wire x1="6" y1="4.6" x2="10" y2="1.8" width="0.2032" layer="21"/>
<wire x1="10" y1="-1.8" x2="6" y2="-4.6" width="0.2032" layer="21"/>
<wire x1="6" y1="-4.6" x2="1.6" y2="-4.6" width="0.2032" layer="21" curve="-72.359206"/>
<wire x1="1.6" y1="-4.6" x2="-2.4" y2="-1.8" width="0.2032" layer="21"/>
<text x="1.8" y="1.8" size="1.27" layer="21" font="vector">&gt;NAME</text>
<text x="1.8" y="-1.2" size="1.27" layer="21" font="vector">&gt;VALUE</text>
</package>
<package name="PIEZO_SOUNDER_MURATA">
<pad name="P$1" x="-2.4" y="0" drill="1.016" shape="square"/>
<pad name="P$2" x="2.6" y="0" drill="1.016"/>
<pad name="P$3" x="0" y="-3.25" drill="1.016"/>
<pad name="P$4" x="0" y="3.25" drill="1.016"/>
<circle x="0" y="0" radius="6.25" width="0.2032" layer="21"/>
<text x="2" y="2" size="0.8128" layer="21" font="vector">&gt;NAME</text>
<text x="2" y="-3" size="0.8128" layer="21" font="vector">&gt;VALUE</text>
</package>
<package name="USB_A_RECEPTACLE_VERTICAL_MULTICOMP">
<pad name="P$1" x="-3.048" y="0" drill="1.016" shape="square"/>
<pad name="P$2" x="-1.016" y="0" drill="1.016"/>
<pad name="P$3" x="1.016" y="0" drill="1.016"/>
<pad name="P$4" x="3.048" y="0" drill="1.016"/>
<pad name="P$5" x="-6.731" y="-2.794" drill="2.286"/>
<pad name="P$6" x="6.731" y="-2.794" drill="2.286"/>
<wire x1="-8.89" y1="1.27" x2="8.89" y2="1.27" width="0.2032" layer="21"/>
<wire x1="8.89" y1="1.27" x2="8.89" y2="-5.08" width="0.2032" layer="21"/>
<wire x1="8.89" y1="-5.08" x2="-8.89" y2="-5.08" width="0.2032" layer="21"/>
<wire x1="-8.89" y1="-5.08" x2="-8.89" y2="1.27" width="0.2032" layer="21"/>
<text x="-2.54" y="-3.81" size="1.016" layer="21" font="vector">&gt;VALUE</text>
</package>
<package name="HEADER_KENTEC_TFT_LCD_4.3_INCH">
<smd name="P$1" x="-9.5" y="0.3" dx="0.2" dy="1" layer="1"/>
<smd name="P$2" x="-9" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$3" x="-8.5" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$4" x="-8" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$5" x="-7.5" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$6" x="-7" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$7" x="-6.5" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$8" x="-6" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$9" x="-5.5" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$10" x="-5" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$11" x="-4.5" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$12" x="-4" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$13" x="-3.5" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$14" x="-3" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$15" x="-2.5" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$16" x="-2" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$17" x="-1.5" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$18" x="-1" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$19" x="-0.5" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$20" x="0" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$21" x="0.5" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$22" x="1" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$23" x="1.5" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$24" x="2" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$25" x="2.5" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$26" x="3" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$27" x="3.5" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$28" x="4" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$29" x="4.5" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$30" x="5" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$31" x="5.5" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$32" x="6" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$33" x="6.5" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$34" x="7" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$35" x="7.5" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$36" x="8" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$37" x="8.5" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$38" x="9" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$39" x="9.5" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<smd name="P$40" x="10" y="0.3" dx="0.2" dy="1" layer="1" roundness="100"/>
<wire x1="-12.7" y1="-5.5" x2="12.6" y2="-5.5" width="0.2032" layer="21"/>
<wire x1="12" y1="-0.5" x2="-12" y2="-0.5" width="0.2032" layer="21"/>
<smd name="P$41" x="12" y="-2.8" dx="2" dy="1.2" layer="1"/>
<smd name="P$42" x="-12" y="-2.8" dx="2" dy="1.2" layer="1"/>
<wire x1="-12" y1="-0.5" x2="-12" y2="-1.7" width="0.2032" layer="21"/>
<wire x1="12" y1="-0.5" x2="12" y2="-1.7" width="0.2032" layer="21"/>
<wire x1="-12.7" y1="-5.5" x2="-12.7" y2="-3.9" width="0.2032" layer="21"/>
<wire x1="-12.7" y1="-3.9" x2="-12" y2="-3.9" width="0.2032" layer="21"/>
<wire x1="12.6" y1="-5.5" x2="12.6" y2="-3.9" width="0.2032" layer="21"/>
<wire x1="12.6" y1="-3.9" x2="12" y2="-3.9" width="0.2032" layer="21"/>
<text x="-3" y="-3.5" size="1.27" layer="21" font="vector">&gt;NAME</text>
</package>
<package name="SOT323">
<smd name="L" x="0" y="0" dx="0.5" dy="0.7" layer="1"/>
<smd name="R" x="1.27" y="0" dx="0.5" dy="0.7" layer="1"/>
<smd name="M" x="0.63" y="2" dx="0.5" dy="0.7" layer="1"/>
<wire x1="-0.51" y1="0.5" x2="1.72" y2="0.5" width="0.127" layer="21"/>
<wire x1="1.72" y1="0.5" x2="1.72" y2="1.51" width="0.127" layer="21"/>
<wire x1="1.72" y1="1.51" x2="-0.51" y2="1.51" width="0.127" layer="21"/>
<wire x1="-0.51" y1="1.51" x2="-0.51" y2="0.5" width="0.127" layer="21"/>
<text x="2" y="2" size="0.8128" layer="21" font="vector">&gt;NAME</text>
<text x="2" y="0.73" size="0.8128" layer="21" font="vector">&gt;VALUE</text>
</package>
<package name="MULTICOMP_MC36211">
<description>MULTICOMP  MC36211  FUSE, PTC RESET, SMD, 16V, 350MA 
The FSMD series from Multicomp are surface mountable PTC (positive Temperature coefficient) resettable fuses. These fuses have operation current ranges from 0.10mA to 3A.

    Faster time to trip
    Lower resistance
    Temperature range from -40°C to 85°C
    Rated voltage range from 6V to 60V
    UL, CSA and TUV approved</description>
<smd name="P$1" x="-1.5" y="0" dx="1.9" dy="1" layer="1" rot="R90"/>
<smd name="P$2" x="1.5" y="0" dx="1.9" dy="1" layer="1" rot="R90"/>
<wire x1="-0.7" y1="0.9" x2="0.7" y2="0.9" width="0.2032" layer="21"/>
<wire x1="-0.7" y1="-0.9" x2="0.7" y2="-0.9" width="0.2032" layer="21"/>
<text x="-0.8" y="-0.4" size="0.8128" layer="21" font="vector">&gt;NAME</text>
</package>
<package name="HEADER_USART_2_TH">
<pad name="P$1" x="1.27" y="8.89" drill="1.016" shape="square"/>
<pad name="P$2" x="3.81" y="8.89" drill="1.016"/>
<pad name="P$3" x="1.27" y="6.35" drill="1.016"/>
<pad name="P$4" x="3.81" y="6.35" drill="1.016"/>
<pad name="P$5" x="1.27" y="3.81" drill="1.016"/>
<pad name="P$6" x="3.81" y="3.81" drill="1.016"/>
<pad name="P$7" x="1.27" y="1.27" drill="1.016"/>
<pad name="P$8" x="3.81" y="1.27" drill="1.016"/>
<wire x1="0" y1="10.16" x2="5.08" y2="10.16" width="0.2032" layer="21"/>
<wire x1="5.08" y1="10.16" x2="5.08" y2="0" width="0.2032" layer="21"/>
<wire x1="5.08" y1="0" x2="0" y2="0" width="0.2032" layer="21"/>
<wire x1="0" y1="0" x2="0" y2="10.16" width="0.2032" layer="21"/>
<text x="0.635" y="10.795" size="0.8128" layer="21" font="vector">&gt;NAME</text>
<text x="5.715" y="8.255" size="1.27" layer="21" font="vector">GND</text>
<text x="5.715" y="5.715" size="1.27" layer="21" font="vector">+5</text>
<text x="5.715" y="3.175" size="1.27" layer="21" font="vector">TX</text>
<text x="5.715" y="0.635" size="1.27" layer="21" font="vector">RX</text>
<text x="-2.54" y="8.255" size="1.27" layer="21" font="vector">RX</text>
<text x="-2.54" y="5.715" size="1.27" layer="21" font="vector">TX</text>
<text x="-2.54" y="3.175" size="1.27" layer="21" font="vector">+5</text>
<text x="-3.81" y="0.635" size="1.27" layer="21" font="vector">GND</text>
</package>
<package name="HEADER_4_2_SMD">
<smd name="P$1" x="-0.4572" y="0" dx="1.27" dy="2.54" layer="1" rot="R90"/>
<smd name="P$2" x="5.08" y="0" dx="1.27" dy="2.54" layer="1" rot="R90"/>
<smd name="P$3" x="-0.4572" y="-2.54" dx="1.27" dy="2.54" layer="1" rot="R90"/>
<smd name="P$4" x="5.08" y="-2.54" dx="1.27" dy="2.54" layer="1" rot="R90"/>
<smd name="P$5" x="-0.4572" y="-5.08" dx="1.27" dy="2.54" layer="1" rot="R90"/>
<smd name="P$6" x="5.08" y="-5.08" dx="1.27" dy="2.54" layer="1" rot="R90"/>
<smd name="P$7" x="-0.4572" y="-7.62" dx="1.27" dy="2.54" layer="1" rot="R90"/>
<smd name="P$8" x="5.08" y="-7.62" dx="1.27" dy="2.54" layer="1" rot="R90"/>
<wire x1="1.0668" y1="1.27" x2="3.6068" y2="1.27" width="0.254" layer="21"/>
<wire x1="1.016" y1="-8.89" x2="3.556" y2="-8.89" width="0.254" layer="21"/>
<text x="0" y="1.905" size="1.27" layer="21" font="vector">&gt;NAME</text>
<text x="-0.635" y="-10.795" size="1.27" layer="21" font="vector">&gt;VALUE</text>
</package>
<package name="TSOP_II_54_PIN">
<smd name="P$1" x="-6.2992" y="10.2362" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$2" x="-6.2992" y="9.4488" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$3" x="-6.2992" y="8.6614" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$4" x="-6.2992" y="7.874" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$5" x="-6.2992" y="7.0866" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$6" x="-6.2992" y="6.2992" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$7" x="-6.2992" y="5.5118" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$8" x="-6.2992" y="4.7244" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$9" x="-6.2992" y="3.937" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$10" x="-6.2992" y="3.1496" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$11" x="-6.2992" y="2.3622" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$12" x="-6.2992" y="1.5748" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$13" x="-6.2992" y="0.7874" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$14" x="-6.2992" y="0" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$15" x="-6.2992" y="-0.7874" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$16" x="-6.2992" y="-1.5748" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$17" x="-6.2992" y="-2.3622" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$18" x="-6.2992" y="-3.1496" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$19" x="-6.2992" y="-3.937" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$20" x="-6.2992" y="-4.7244" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$21" x="-6.2992" y="-5.5118" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$22" x="-6.2992" y="-6.2992" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$23" x="-6.2992" y="-7.0866" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$24" x="-6.2992" y="-7.874" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$25" x="-6.2992" y="-8.6614" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$26" x="-6.2992" y="-9.4488" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$27" x="-6.2992" y="-10.2362" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$28" x="5.5118" y="-10.2362" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$29" x="5.5118" y="-9.4488" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$30" x="5.5118" y="-8.6614" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$31" x="5.5118" y="-7.874" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$32" x="5.5118" y="-7.0866" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$33" x="5.5118" y="-6.2992" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$34" x="5.5118" y="-5.5118" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$35" x="5.5118" y="-4.7244" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$36" x="5.5118" y="-3.937" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$37" x="5.5118" y="-3.1496" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$38" x="5.5118" y="-2.3622" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$39" x="5.5118" y="-1.5748" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$40" x="5.5118" y="-0.7874" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$41" x="5.5118" y="0" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$42" x="5.5118" y="0.7874" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$43" x="5.5118" y="1.5748" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$44" x="5.5118" y="2.3622" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$45" x="5.5118" y="3.1496" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$46" x="5.5118" y="3.937" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$47" x="5.5118" y="4.7244" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$48" x="5.5118" y="5.5118" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$49" x="5.5118" y="6.2992" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$50" x="5.5118" y="7.0866" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$51" x="5.5118" y="7.874" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$52" x="5.5118" y="8.6614" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$53" x="5.5118" y="9.4488" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<smd name="P$54" x="5.5118" y="10.2362" dx="0.3556" dy="1.016" layer="1" rot="R270"/>
<wire x1="-5.5118" y1="-11.0236" x2="-5.5118" y2="11.0236" width="0.2032" layer="21"/>
<wire x1="-5.5118" y1="11.0236" x2="4.7244" y2="11.0236" width="0.2032" layer="21"/>
<wire x1="4.7244" y1="11.0236" x2="4.7244" y2="-11.0236" width="0.2032" layer="21"/>
<wire x1="4.7244" y1="-11.0236" x2="-5.5118" y2="-11.0236" width="0.2032" layer="21"/>
<circle x="-3.937" y="9.4488" radius="0.7874" width="0.2032" layer="21"/>
<text x="-3.1496" y="6.2992" size="1.27" layer="21" font="vector">&gt;NAME</text>
<text x="-3.1496" y="4.7244" size="0.8128" layer="21" font="vector">&gt;VALUE</text>
</package>
<package name="MOLEX_MX120G">
<pad name="P$1" x="-15.75" y="0" drill="4" diameter="5"/>
<pad name="P$2" x="15.75" y="0" drill="4" diameter="5"/>
<pad name="12" x="-8.75" y="-2.2" drill="1.45" diameter="2"/>
<pad name="6" x="-8.75" y="-5.7" drill="1.45" diameter="2"/>
<pad name="5" x="-5.25" y="-5.7" drill="1.45" diameter="2"/>
<pad name="11" x="-5.25" y="-2.2" drill="1.45" diameter="2"/>
<pad name="10" x="-1.75" y="-2.2" drill="1.45" diameter="2"/>
<pad name="4" x="-1.75" y="-5.7" drill="1.45" diameter="2"/>
<pad name="3" x="1.75" y="-5.7" drill="1.45" diameter="2"/>
<pad name="9" x="1.75" y="-2.2" drill="1.45" diameter="2"/>
<pad name="8" x="5.25" y="-2.2" drill="1.45" diameter="2"/>
<pad name="2" x="5.25" y="-5.7" drill="1.45" diameter="2"/>
<pad name="1" x="8.75" y="-5.7" drill="1.45" diameter="2"/>
<pad name="7" x="8.75" y="-2.2" drill="1.45" diameter="2"/>
<wire x1="-19.6" y1="6" x2="-16" y2="6" width="0.2" layer="21"/>
<wire x1="16" y1="6" x2="19.4" y2="6" width="0.2" layer="21"/>
<wire x1="-19.6" y1="8" x2="-16" y2="8" width="0.2" layer="21"/>
<wire x1="16" y1="8" x2="19.4" y2="8" width="0.2" layer="21"/>
<wire x1="-19.6" y1="9.5" x2="19.4" y2="9.5" width="0.2" layer="21"/>
<wire x1="-16" y1="8" x2="-16" y2="6" width="0.2" layer="21"/>
<wire x1="16" y1="8" x2="16" y2="6" width="0.2" layer="21"/>
<wire x1="19.4" y1="8" x2="19.4" y2="9.5" width="0.2" layer="21"/>
<wire x1="-19.6" y1="8" x2="-19.6" y2="9.5" width="0.2" layer="21"/>
<wire x1="-19.6" y1="6" x2="-19.6" y2="-3.6" width="0.2" layer="21"/>
<wire x1="-19.6" y1="-3.6" x2="-13.1" y2="-3.6" width="0.2" layer="21"/>
<wire x1="-13.1" y1="-3.6" x2="-7.5" y2="2" width="0.2" layer="21"/>
<wire x1="-7.5" y1="2" x2="7.5" y2="2" width="0.2" layer="21"/>
<wire x1="7.5" y1="2" x2="13.1" y2="-3.6" width="0.2" layer="21"/>
<wire x1="13.1" y1="-3.6" x2="19.4" y2="-3.6" width="0.2" layer="21"/>
<wire x1="19.4" y1="-3.6" x2="19.4" y2="6" width="0.2" layer="21"/>
<text x="-2.54" y="2.54" size="1.27" layer="21" font="vector">&gt;VALUE</text>
<text x="-2.54" y="5.08" size="1.27" layer="21" font="vector">&gt;NAME</text>
</package>
<package name="0603">
<smd name="0" x="-1.0414" y="0" dx="0.508" dy="0.889" layer="1"/>
<smd name="1" x="0.8001" y="0" dx="0.508" dy="0.889" layer="1"/>
<text x="-1.1049" y="0.635" size="0.8128" layer="21" font="vector">&gt;NAME</text>
<wire x1="0.32385" y1="0.34925" x2="0.32385" y2="-0.37465" width="0.2032" layer="21"/>
</package>
<package name="CAP_SMD_6.3X7.7_MM">
<wire x1="-3.3" y1="0" x2="3.3" y2="0" width="0.127" layer="21"/>
<wire x1="3.3" y1="0" x2="3.3" y2="5.9" width="0.127" layer="21"/>
<wire x1="3.3" y1="5.9" x2="2.2" y2="7" width="0.127" layer="21"/>
<wire x1="2.2" y1="7" x2="-2.2" y2="7" width="0.127" layer="21"/>
<wire x1="-2.2" y1="7" x2="-3.3" y2="5.9" width="0.127" layer="21"/>
<wire x1="-3.3" y1="5.9" x2="-3.3" y2="0" width="0.127" layer="21"/>
<smd name="P$1" x="0" y="7" dx="0.8" dy="3" layer="1"/>
<smd name="P$2" x="0" y="0" dx="0.8" dy="3" layer="1"/>
<text x="-1" y="3.5" size="0.8128" layer="21" font="vector">&gt;NAME</text>
</package>
<package name="CAP_POLY_5.3MM">
<pad name="P$1" x="0" y="0" drill="1.016" shape="square"/>
<pad name="P$2" x="2.5" y="0" drill="1.016"/>
<circle x="1.25" y="0" radius="3.010396875" width="0.127" layer="21"/>
<wire x1="2.25" y1="1.5" x2="2.75" y2="1.5" width="0.127" layer="21"/>
<wire x1="2.5" y1="1.75" x2="2.5" y2="1.25" width="0.127" layer="21"/>
<text x="-0.75" y="-2" size="0.8128" layer="21" font="vector">&gt;VALUE</text>
</package>
<package name="LED_TH">
<pad name="K" x="-1.27" y="0" drill="1.016" diameter="1.778" shape="square"/>
<pad name="A" x="1.27" y="0" drill="1.016" diameter="1.778"/>
<circle x="0" y="0" radius="2.83980625" width="0.2032" layer="21"/>
<text x="-1.27" y="3.175" size="1.27" layer="21" font="vector">&gt;NAME</text>
<wire x1="-2.6416" y1="1.016" x2="-2.6416" y2="-0.9652" width="0.2032" layer="21"/>
<wire x1="-2.4384" y1="1.3716" x2="-2.4384" y2="-1.4224" width="0.2032" layer="21"/>
</package>
<package name="DIODE">
<smd name="P$1" x="0" y="0" dx="2.54" dy="1.27" layer="1" rot="R90"/>
<smd name="P$2" x="5.08" y="0" dx="2.54" dy="1.27" layer="1" rot="R90"/>
<wire x1="3.81" y1="1.27" x2="3.81" y2="0" width="0.2032" layer="21"/>
<wire x1="3.81" y1="0" x2="3.81" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="3.81" y1="0" x2="1.27" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="1.27" y1="-1.27" x2="1.27" y2="1.27" width="0.2032" layer="21"/>
<wire x1="1.27" y1="1.27" x2="3.81" y2="0" width="0.2032" layer="21"/>
<text x="1.27" y="1.27" size="1.27" layer="21" font="vector">&gt;NAME</text>
</package>
<package name="DO-41">
<pad name="P" x="0" y="0" drill="1.016" shape="square"/>
<pad name="N" x="0" y="-7.62" drill="1.016"/>
<wire x1="-1.27" y1="-1.27" x2="-1.27" y2="-6.35" width="0.2032" layer="21"/>
<wire x1="-1.27" y1="-1.27" x2="1.27" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="1.27" y1="-1.27" x2="1.27" y2="-6.35" width="0.2032" layer="21"/>
<wire x1="1.27" y1="-6.35" x2="-1.27" y2="-6.35" width="0.2032" layer="21"/>
<wire x1="-0.889" y1="-2.921" x2="0.889" y2="-2.921" width="0.2032" layer="21"/>
<wire x1="0.889" y1="-2.921" x2="0" y2="-4.699" width="0.2032" layer="21"/>
<wire x1="0" y1="-4.699" x2="-0.889" y2="-2.921" width="0.2032" layer="21"/>
<wire x1="-0.889" y1="-4.699" x2="0" y2="-4.699" width="0.2032" layer="21"/>
<wire x1="0" y1="-4.699" x2="0.889" y2="-4.699" width="0.2032" layer="21"/>
</package>
<package name="USB_MINI_B">
<smd name="SHLD@1" x="0" y="0" dx="2.5" dy="2" layer="1" rot="R90"/>
<smd name="SHLD@2" x="0" y="-5.5" dx="2.5" dy="2" layer="1" rot="R90"/>
<smd name="SHLD" x="8.9" y="0" dx="2.5" dy="2" layer="1" rot="R90"/>
<smd name="SHLD@3" x="8.9" y="-5.5" dx="2.5" dy="2" layer="1" rot="R90"/>
<smd name="VCC" x="2.8984" y="0.6" dx="2.25" dy="0.47" layer="1" rot="R90"/>
<smd name="D-" x="3.6492" y="0.6" dx="2.25" dy="0.47" layer="1" rot="R90"/>
<smd name="D+" x="4.4" y="0.6" dx="2.25" dy="0.47" layer="1" rot="R90"/>
<smd name="ID" x="5.1508" y="0.6" dx="2.25" dy="0.47" layer="1" rot="R90"/>
<smd name="GND" x="5.9016" y="0.6" dx="2.25" dy="0.47" layer="1" rot="R90"/>
<wire x1="0.5" y1="-1.7" x2="0.5" y2="-3.8" width="0.2032" layer="21"/>
<wire x1="0.5" y1="-7.735" x2="0.5" y2="-9" width="0.2032" layer="21"/>
<wire x1="0.5" y1="-9" x2="8.5" y2="-9" width="0.2032" layer="21"/>
<wire x1="8.5" y1="-9" x2="8.5" y2="-7.735" width="0.2032" layer="21"/>
<wire x1="8.5" y1="-3.8" x2="8.5" y2="-1.7" width="0.2032" layer="21"/>
<wire x1="7.5" y1="1" x2="6.5" y2="1" width="0.2032" layer="21"/>
<wire x1="2.3" y1="1" x2="1.4" y2="1" width="0.2032" layer="21"/>
<text x="3.1" y="-3.4" size="1.27" layer="21" font="vector">&gt;NAME</text>
</package>
<package name="TO-220">
<pad name="LEFT" x="0" y="0" drill="1" diameter="1.778" shape="square"/>
<pad name="MIDDLE" x="2.54" y="0" drill="1" diameter="1.778"/>
<pad name="RIGHT" x="5.08" y="0" drill="1" diameter="1.778"/>
<wire x1="-0.635" y1="1.27" x2="-0.635" y2="3.81" width="0.127" layer="21"/>
<wire x1="-0.635" y1="3.81" x2="-1.905" y2="3.81" width="0.127" layer="21"/>
<wire x1="-1.905" y1="3.81" x2="-1.905" y2="10.795" width="0.127" layer="21"/>
<wire x1="-1.905" y1="10.795" x2="-1.905" y2="17.145" width="0.127" layer="21"/>
<wire x1="-1.905" y1="17.145" x2="6.985" y2="17.145" width="0.127" layer="21"/>
<wire x1="6.985" y1="17.145" x2="6.985" y2="10.795" width="0.127" layer="21"/>
<wire x1="6.985" y1="10.795" x2="6.985" y2="3.81" width="0.127" layer="21"/>
<wire x1="6.985" y1="3.81" x2="5.715" y2="3.81" width="0.127" layer="21"/>
<wire x1="5.715" y1="3.81" x2="5.715" y2="1.27" width="0.127" layer="21"/>
<wire x1="0.635" y1="1.27" x2="0.635" y2="3.81" width="0.127" layer="21"/>
<wire x1="0.635" y1="3.81" x2="1.905" y2="3.81" width="0.127" layer="21"/>
<wire x1="1.905" y1="3.81" x2="1.905" y2="1.27" width="0.127" layer="21"/>
<wire x1="3.175" y1="1.27" x2="3.175" y2="3.81" width="0.127" layer="21"/>
<wire x1="3.175" y1="3.81" x2="4.445" y2="3.81" width="0.127" layer="21"/>
<wire x1="4.445" y1="3.81" x2="4.445" y2="1.27" width="0.127" layer="21"/>
<wire x1="-1.905" y1="10.795" x2="6.985" y2="10.795" width="0.127" layer="21"/>
<circle x="2.54" y="13.97" radius="1.79605" width="0.127" layer="21"/>
<text x="0" y="17.78" size="1.27" layer="21" font="vector">&gt;NAME</text>
</package>
<package name="FUSE_MAXI">
<smd name="P$1" x="0" y="0" dx="5.715" dy="5.715" layer="1"/>
<smd name="P$2" x="9.525" y="0" dx="5.715" dy="5.715" layer="1"/>
<wire x1="-2.794" y1="-3.556" x2="-5.08" y2="-3.556" width="0.2032" layer="21"/>
<wire x1="-5.08" y1="-3.556" x2="-5.08" y2="-15.24" width="0.2032" layer="21"/>
<wire x1="-5.08" y1="-15.24" x2="14.478" y2="-15.24" width="0.2032" layer="21"/>
<wire x1="14.478" y1="-15.24" x2="14.478" y2="-3.556" width="0.2032" layer="21"/>
<wire x1="14.478" y1="-3.556" x2="12.192" y2="-3.556" width="0.2032" layer="21"/>
<text x="1.27" y="-6.35" size="1.27" layer="21" font="vector">&gt;NAME</text>
</package>
<package name="FUSE_RESETABLE">
<smd name="P$1" x="-3" y="0" dx="2" dy="5.3" layer="1"/>
<smd name="P$2" x="2.6" y="0" dx="2" dy="5.3" layer="1"/>
<wire x1="-1.6" y1="2.5" x2="1.2" y2="2.5" width="0.2032" layer="21"/>
<wire x1="-1.6" y1="-2.6" x2="1.2" y2="-2.6" width="0.2032" layer="21"/>
<text x="-1" y="3" size="1.27" layer="21" font="vector">&gt;NAME</text>
</package>
<package name="1812">
<smd name="P$1" x="-1.816" y="0" dx="1.5" dy="3.2" layer="1"/>
<smd name="P$2" x="1.684" y="0" dx="1.5" dy="3.2" layer="1"/>
<wire x1="0.684" y1="1.5" x2="-0.816" y2="1.5" width="0.2032" layer="21"/>
<wire x1="-0.816" y1="-1.5" x2="0.684" y2="-1.5" width="0.2032" layer="21"/>
<text x="-2.016" y="2" size="1.016" layer="21" font="vector">&gt;NAME</text>
</package>
<package name="FUSE_100MA">
<smd name="P$1" x="0" y="0" dx="3.41" dy="1.5" layer="1" rot="R90"/>
<smd name="P$2" x="4.572" y="0" dx="3.41" dy="1.5" layer="1" rot="R90"/>
<wire x1="1.27" y1="1.524" x2="3.302" y2="1.524" width="0.3048" layer="21"/>
<wire x1="1.27" y1="-1.524" x2="3.302" y2="-1.524" width="0.3048" layer="21"/>
<text x="-0.762" y="2.032" size="1.016" layer="21" font="vector">&gt;NAME</text>
<text x="-0.762" y="-3.048" size="1.016" layer="21" font="vector">&gt;VALUE</text>
</package>
<package name="QFP32">
<smd name="P$1" x="-3" y="1.5" dx="0.2" dy="1.2" layer="1" rot="R270"/>
<smd name="P$2" x="-3" y="1" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R270"/>
<smd name="P$3" x="-3" y="0.5" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R270"/>
<smd name="P$4" x="-3" y="0" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R270"/>
<smd name="P$5" x="-3" y="-0.5" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R270"/>
<smd name="P$6" x="-3" y="-1" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R270"/>
<smd name="P$7" x="-3" y="-1.5" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R270"/>
<smd name="P$8" x="-3" y="-2" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R270"/>
<smd name="P$9" x="-1.75" y="-3.25" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R180"/>
<smd name="P$10" x="-1.25" y="-3.25" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R180"/>
<smd name="P$11" x="-0.75" y="-3.25" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R180"/>
<smd name="P$12" x="-0.25" y="-3.25" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R180"/>
<smd name="P$13" x="0.25" y="-3.25" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R180"/>
<smd name="P$14" x="0.75" y="-3.25" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R180"/>
<smd name="P$15" x="1.25" y="-3.25" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R180"/>
<smd name="P$16" x="1.75" y="-3.25" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R180"/>
<smd name="P$17" x="3" y="-2" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R90"/>
<smd name="P$18" x="3" y="-1.5" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R90"/>
<smd name="P$19" x="3" y="-1" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R90"/>
<smd name="P$20" x="3" y="-0.5" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R90"/>
<smd name="P$21" x="3" y="0" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R90"/>
<smd name="P$22" x="3" y="0.5" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R90"/>
<smd name="P$23" x="3" y="1" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R90"/>
<smd name="P$24" x="3" y="1.5" dx="0.2" dy="1.2" layer="1" roundness="100" rot="R90"/>
<smd name="P$25" x="1.75" y="2.75" dx="0.2" dy="1.2" layer="1" roundness="100"/>
<smd name="P$26" x="1.25" y="2.75" dx="0.2" dy="1.2" layer="1" roundness="100"/>
<smd name="P$27" x="0.75" y="2.75" dx="0.2" dy="1.2" layer="1" roundness="100"/>
<smd name="P$28" x="0.25" y="2.75" dx="0.2" dy="1.2" layer="1" roundness="100"/>
<smd name="P$29" x="-0.25" y="2.75" dx="0.2" dy="1.2" layer="1" roundness="100"/>
<smd name="P$30" x="-0.75" y="2.75" dx="0.2" dy="1.2" layer="1" roundness="100"/>
<smd name="P$31" x="-1.25" y="2.75" dx="0.2" dy="1.2" layer="1" roundness="100"/>
<smd name="P$32" x="-1.75" y="2.75" dx="0.2" dy="1.2" layer="1" roundness="100"/>
<wire x1="-1.65" y1="1.75" x2="-2" y2="1.4" width="0.2032" layer="21"/>
<wire x1="-2" y1="1.4" x2="-2" y2="-2" width="0.2032" layer="21"/>
<wire x1="-2" y1="-2" x2="-1.7" y2="-2.3" width="0.2032" layer="21"/>
<wire x1="-1.7" y1="-2.3" x2="1.8" y2="-2.3" width="0.2032" layer="21"/>
<wire x1="1.8" y1="-2.3" x2="2.1" y2="-2" width="0.2032" layer="21"/>
<wire x1="2.1" y1="-2" x2="2.1" y2="1.4" width="0.2032" layer="21"/>
<wire x1="2.1" y1="1.4" x2="1.75" y2="1.75" width="0.2032" layer="21"/>
<wire x1="1.75" y1="1.75" x2="-1.65" y2="1.75" width="0.2032" layer="21"/>
<circle x="-1.25" y="0.95" radius="0.360553125" width="0.2032" layer="21"/>
<text x="-1.5" y="-1.5" size="0.8128" layer="21" font="vector">&gt;NAME</text>
<text x="-1.5" y="-0.23" size="0.8128" layer="21" font="vector">&gt;VALUE</text>
</package>
<package name="SOT-23">
<smd name="P$1" x="0" y="0" dx="1" dy="0.4" layer="1" rot="R90"/>
<smd name="P$2" x="0.95" y="0" dx="1" dy="0.4" layer="1" rot="R90"/>
<smd name="P$3" x="1.9" y="0" dx="1" dy="0.4" layer="1" rot="R90"/>
<smd name="P$4" x="1.9" y="2.7" dx="1" dy="0.4" layer="1" rot="R90"/>
<smd name="P$5" x="0" y="2.7" dx="1" dy="0.4" layer="1" rot="R90"/>
<wire x1="-0.6" y1="0.4" x2="-0.6" y2="2.3" width="0.2032" layer="21"/>
<wire x1="2.5" y1="2.3" x2="2.5" y2="0.4" width="0.2032" layer="21"/>
<wire x1="-0.6" y1="2.3" x2="-0.5" y2="2.3" width="0.2032" layer="21"/>
<wire x1="-0.6" y1="0.4" x2="-0.5" y2="0.4" width="0.2032" layer="21"/>
<wire x1="2.5" y1="0.4" x2="2.4" y2="0.4" width="0.2032" layer="21"/>
<wire x1="2.5" y1="2.3" x2="2.4" y2="2.3" width="0.2032" layer="21"/>
<wire x1="0.5" y1="2.3" x2="1.4" y2="2.3" width="0.2032" layer="21"/>
<text x="-0.7" y="3.5" size="0.8128" layer="21" font="vector">&gt;VALUE</text>
<text x="-0.7" y="4.77" size="0.8128" layer="21" font="vector">&gt;NAME</text>
</package>
</packages>
<symbols>
<symbol name="RES">
<pin name="P$1" x="-2.54" y="0" visible="off" length="point" swaplevel="1"/>
<pin name="P$2" x="5.08" y="0" visible="off" length="point" swaplevel="1" rot="R180"/>
<wire x1="-0.762" y1="0.9525" x2="-0.762" y2="0" width="0.254" layer="94"/>
<wire x1="-0.762" y1="0" x2="-0.762" y2="-0.9525" width="0.254" layer="94"/>
<wire x1="-0.762" y1="-0.9525" x2="3.302" y2="-0.9525" width="0.254" layer="94"/>
<wire x1="3.302" y1="-0.9525" x2="3.302" y2="0" width="0.254" layer="94"/>
<wire x1="3.302" y1="0" x2="3.302" y2="0.9525" width="0.254" layer="94"/>
<wire x1="3.302" y1="0.9525" x2="-0.762" y2="0.9525" width="0.254" layer="94"/>
<text x="3.683" y="-1.27" size="1.016" layer="96">&gt;VALUE</text>
<text x="3.556" y="0.254" size="1.27" layer="95">&gt;NAME</text>
<wire x1="-0.762" y1="0" x2="-2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="3.302" y1="0" x2="5.08" y2="0" width="0.1524" layer="94"/>
</symbol>
<symbol name="CAP">
<pin name="P$1" x="-5.08" y="0" visible="off" length="short" swaplevel="1"/>
<pin name="P$2" x="2.54" y="0" visible="off" length="short" swaplevel="1" rot="R180"/>
<wire x1="-1.905" y1="1.397" x2="-1.905" y2="0" width="0.254" layer="94"/>
<text x="-0.254" y="0.254" size="1.016" layer="96">&gt;VALUE</text>
<wire x1="-1.905" y1="0" x2="-1.905" y2="-1.397" width="0.254" layer="94"/>
<wire x1="-0.635" y1="-1.397" x2="-0.635" y2="0" width="0.254" layer="94"/>
<wire x1="-0.635" y1="0" x2="-0.635" y2="1.397" width="0.254" layer="94"/>
<wire x1="-2.54" y1="0" x2="-1.905" y2="0" width="0.1524" layer="94"/>
<wire x1="0" y1="0" x2="-0.635" y2="0" width="0.1778" layer="94"/>
<text x="-0.254" y="-1.524" size="1.27" layer="95">&gt;NAME</text>
</symbol>
<symbol name="LED">
<description>**** BLUE 0603 ***
2251459 	

VISHAY

VLMB1300-GS08

 LED Colour:Blue; Bulb Size:-; Wavelength Typ:475nm; Forward Voltage:3.8V; Forward Current If:20mA; Luminous Intensity:180mcd; LED Mounting:SMD; Lens Shape:Rectangular; Viewing Angle:130°; Pack

http://fi.farnell.com/webapp/wcs/stores/servlet/ProductDisplay?catalogId=15001&amp;langId=358&amp;urlRequestType=Base&amp;partNumber=2251459&amp;storeId=10159</description>
<wire x1="-0.508" y1="1.016" x2="-0.508" y2="0" width="0.254" layer="94"/>
<wire x1="-0.508" y1="0" x2="-0.508" y2="-1.016" width="0.254" layer="94"/>
<wire x1="-0.508" y1="-1.016" x2="-2.54" y2="0" width="0.254" layer="94"/>
<wire x1="-2.54" y1="0" x2="-0.508" y2="1.016" width="0.254" layer="94"/>
<wire x1="-2.54" y1="1.016" x2="-2.54" y2="0" width="0.254" layer="94"/>
<wire x1="-2.54" y1="0" x2="-2.54" y2="-1.016" width="0.254" layer="94"/>
<wire x1="-2.286" y1="1.016" x2="-0.762" y2="2.54" width="0.254" layer="94"/>
<wire x1="-0.762" y1="2.54" x2="-0.762" y2="1.778" width="0.254" layer="94"/>
<wire x1="-0.762" y1="2.54" x2="-1.524" y2="2.54" width="0.254" layer="94"/>
<wire x1="-1.016" y1="1.016" x2="0.508" y2="2.54" width="0.254" layer="94"/>
<wire x1="0.508" y1="2.54" x2="-0.254" y2="2.54" width="0.254" layer="94"/>
<wire x1="0.508" y1="2.54" x2="0.508" y2="1.778" width="0.254" layer="94"/>
<pin name="1" x="-5.08" y="0" visible="off" length="short" swaplevel="1"/>
<pin name="0" x="2.54" y="0" visible="off" length="short" rot="R180"/>
<text x="0.254" y="-1.524" size="1.27" layer="96">&gt;VALUE</text>
<text x="0.254" y="0.254" size="1.27" layer="95">&gt;NAME</text>
<wire x1="0" y1="0" x2="-0.508" y2="0" width="0.1651" layer="94"/>
</symbol>
<symbol name="LPC1785FBD208,551_A">
<pin name="VDDA" x="-27.94" y="40.64" length="short" direction="pwr"/>
<pin name="VDD(3V3)_2" x="-27.94" y="38.1" length="short" direction="pwr"/>
<pin name="VDD(3V3)" x="-27.94" y="35.56" length="short" direction="pwr"/>
<pin name="VDD(REG)(3V3)" x="-27.94" y="33.02" length="short" direction="pwr"/>
<pin name="VREFP" x="-27.94" y="27.94" length="short"/>
<pin name="JTAG_TDI" x="-27.94" y="22.86" length="short" direction="in"/>
<pin name="JTAG_TMS/(SWDIO)" x="-27.94" y="20.32" length="short" direction="in"/>
<pin name="P3[12]/EMC_D[12]" x="-27.94" y="-10.16" length="short"/>
<pin name="P3[3]/EMC_D[3]" x="-27.94" y="-12.7" length="short"/>
<pin name="P3[5]/EMC_D[5]" x="-27.94" y="-15.24" length="short"/>
<pin name="P3[28]/EMC_D[28]/PWM1[5]/T1_CAP1" x="-27.94" y="-17.78" length="short"/>
<pin name="P3[30]/EMC_D[30]/U1_RTS/T1_MAT1" x="-27.94" y="-20.32" length="short"/>
<pin name="P3[13]/EMC_D[13]" x="-27.94" y="-22.86" length="short"/>
<pin name="P3[14]/EMC_D[14]" x="-27.94" y="-25.4" length="short"/>
<pin name="P3[7]/EMC_D[7]" x="-27.94" y="-27.94" length="short"/>
<pin name="P3[4]/EMC_D[4]" x="-27.94" y="-30.48" length="short"/>
<pin name="P3[6]/EMC_D[6]" x="-27.94" y="-33.02" length="short"/>
<pin name="P3[29]/EMC_D[29]/PWM1[6]/T1_MAT0" x="-27.94" y="-35.56" length="short"/>
<pin name="P3[15]/EMC_D[15]" x="-27.94" y="-38.1" length="short"/>
<pin name="P3[26]/EMC_D[26]/PWM1[3]/T0_MAT1/STCLK" x="-27.94" y="-40.64" length="short"/>
<pin name="P3[31]/EMC_D[31]/R/T1_MAT2" x="-27.94" y="-43.18" length="short"/>
<pin name="P3[25]/EMC_D[25]/PWM1[2]/T0_MAT0" x="-27.94" y="-45.72" length="short"/>
<pin name="P3[24]/EMC_D[24]/PWM1[1]/T0_CAP1" x="-27.94" y="-48.26" length="short"/>
<pin name="P5[0]/EMC_A[24]/SSP2_MOSI/T2_MAT2" x="50.8" y="-25.4" length="short" rot="R180"/>
<pin name="P5[1]/EMC_A[25]/SSP2_MISO/T2_MAT3" x="50.8" y="-27.94" length="short" rot="R180"/>
<pin name="USB_D-2" x="-27.94" y="7.62" length="short"/>
<pin name="VSSREG" x="-27.94" y="2.54" length="short" direction="pas"/>
<pin name="VSSA" x="-27.94" y="0" length="short" direction="pas"/>
<pin name="VSS" x="-27.94" y="-2.54" length="short" direction="pas"/>
<pin name="JTAG_TDO/(SWO)" x="50.8" y="40.64" length="short" direction="out" rot="R180"/>
<pin name="P2[31]/EMC_DQM3/I2C2_SCL/T3_MAT3" x="50.8" y="35.56" length="short" rot="R180"/>
<pin name="P2[27]/EMC_CKE3/SSP0_MOSI/T3_MAT1" x="50.8" y="33.02" length="short" rot="R180"/>
<pin name="P2[28]/EMC_DQM0" x="50.8" y="30.48" length="short" rot="R180"/>
<pin name="P2[24]/EMC_CKE0" x="50.8" y="27.94" length="short" rot="R180"/>
<pin name="P2[30]/EMC_DQM2/I2C2_SDA/T3_MAT2" x="50.8" y="25.4" length="short" rot="R180"/>
<pin name="P2[25]/EMC_CKE1" x="50.8" y="22.86" length="short" rot="R180"/>
<pin name="P2[29]/EMC_DQM1" x="50.8" y="20.32" length="short" rot="R180"/>
<pin name="P2[18]/EMC_CLK[0]" x="50.8" y="17.78" length="short" rot="R180"/>
<pin name="P2[26]/EMC_CKE2/SSP0_MISO/T3_MAT0" x="50.8" y="15.24" length="short" rot="R180"/>
<pin name="P1[31]/USB_OVRCR2_N/SSP1_SCK/ADC0_IN[5]/I2C0_SCL" x="50.8" y="10.16" length="short" rot="R180"/>
<pin name="P1[30]/USB_PWRD2/USB_VBUS/ADC0_IN[4]/I2C0_SDA" x="50.8" y="7.62" length="short" rot="R180"/>
<pin name="P0[25]/ADC0_IN[2]/I2S_RX_SDA/U3_TXD" x="50.8" y="2.54" length="short" rot="R180"/>
<pin name="P0[28]/I2C0_SCL/USB_SCL1" x="50.8" y="0" length="short" rot="R180"/>
<pin name="P0[26]/ADC0_IN[3]/DAC_OUT/U3_RXD" x="50.8" y="-2.54" length="short" rot="R180"/>
<pin name="P0[12]/USB_PPWR2_N/SSP1_MISO/ADC0_IN[6]" x="50.8" y="-5.08" length="short" rot="R180"/>
<pin name="P0[24]/ADC0_IN[1]/I2S_RX_WS/T3_CAP1" x="50.8" y="-7.62" length="short" rot="R180"/>
<pin name="P0[13]/USB_UP_LED2/SSP1_MOSI/ADC0_IN[7]" x="50.8" y="-10.16" length="short" rot="R180"/>
<pin name="P0[23]/ADC0_IN[0]/I2S_RX_SCK/T3_CAP0" x="50.8" y="-12.7" length="short" rot="R180"/>
<pin name="P0[27]/I2C0_SDA/USB_SDA1" x="50.8" y="-15.24" length="short" rot="R180"/>
<pin name="P0[31]/USB_D+2" x="50.8" y="-17.78" length="short" rot="R180"/>
<wire x1="-25.4" y1="45.72" x2="-25.4" y2="-50.8" width="0.4064" layer="94"/>
<wire x1="-25.4" y1="-50.8" x2="48.26" y2="-50.8" width="0.4064" layer="94"/>
<wire x1="48.26" y1="-50.8" x2="48.26" y2="45.72" width="0.4064" layer="94"/>
<wire x1="48.26" y1="45.72" x2="-25.4" y2="45.72" width="0.4064" layer="94"/>
<text x="4.3434" y="47.8028" size="2.0828" layer="95" ratio="10" rot="SR0">&gt;NAME</text>
<text x="3.0226" y="-54.8894" size="2.0828" layer="96" ratio="10" rot="SR0">&gt;VALUE</text>
</symbol>
<symbol name="LPC1785FBD208,551_B">
<pin name="VDD(3V3)_2" x="-27.94" y="38.1" length="short" direction="pwr"/>
<pin name="VDD(3V3)_3" x="-27.94" y="35.56" length="short" direction="pwr"/>
<pin name="VDD(3V3)" x="-27.94" y="33.02" length="short" direction="pwr"/>
<pin name="VBAT" x="-27.94" y="30.48" length="short" direction="pwr"/>
<pin name="JTAG_!TRST!" x="-27.94" y="12.7" length="short" direction="in"/>
<pin name="JTAG_TCK/(SWDCLK)" x="-27.94" y="10.16" length="short" direction="in"/>
<pin name="P0[0]/CAN_RD1/U3_TXD/I2C1_SDA/U0_TXD" x="-27.94" y="2.54" length="short"/>
<pin name="P0[29]/USB_D+1/!EINT0" x="-27.94" y="0" length="short"/>
<pin name="P0[1]/CAN_TD1/U3_RXD/I2C1_SCL/U0_RXD" x="-27.94" y="-2.54" length="short"/>
<pin name="P0[14]/!USB_HSTEN2!/SSP1_SSEL/USB_CONNECT2" x="-27.94" y="-5.08" length="short"/>
<pin name="P0[10]/U2_TXD/I2C2_SDA/T3_MAT0" x="-27.94" y="-7.62" length="short"/>
<pin name="P0[30]/USB_D-1/!EINT1" x="-27.94" y="-10.16" length="short"/>
<pin name="P0[11]/U2_RXD/I2C2_SCL/T3_MAT1" x="-27.94" y="-12.7" length="short"/>
<pin name="P1[26]/!USB_SSPND1!/PWM1[6]/T0_CAP0/MC_1B/SSP1_SSEL/LCD_VD[12]/LCD_VD[20]" x="-27.94" y="-17.78" length="short"/>
<pin name="P1[25]/!USB_LS1!/!USB_HSTEN1!/T1_MAT1/MC_1A/CLKOUT/LCD_VD[11]/LCD_VD[15]" x="-27.94" y="-20.32" length="short"/>
<pin name="P1[21]/USB_TX_DM1/PWM1[3]/SSP0_SSEL/!MC_ABORT!/R/LCD_VD[7]/LCD_VD[11]" x="-27.94" y="-22.86" length="short"/>
<pin name="P1[22]/USB_RCV1/USB_PWRD1/T1_MAT0/MC_0B/SSP1_MOSI/LCD_VD[8]/LCD_VD[12]" x="-27.94" y="-25.4" length="short"/>
<pin name="P1[23]/USB_RX_DP1/PWM1[4]/QEI_PHB/MC_FB1/SSP0_MISO/LCD_VD[9]/LCD_VD[13]" x="-27.94" y="-27.94" length="short"/>
<pin name="P1[19]/!USB_TX_E1!/!USB_PPWR1!/T1_CAP1_MC_0A/SSP1_SCK/U2_OE" x="-27.94" y="-30.48" length="short"/>
<pin name="P1[27]/!USB_INT1!/!USB_OVRCR1!/T0_CAP1/CLKOUT/R/LCD_VD[13]/LCD_VD[21]" x="-27.94" y="-33.02" length="short"/>
<pin name="P1[18]/USB_UP_LED1/PWM1[1]/T1_CAP0/R/SSP1_MISO" x="-27.94" y="-35.56" length="short"/>
<pin name="P1[24]/USB_RX_DM1/PWM1[5]/QEI_IDX/MC_FB2/SSP0_MOSI/LCD_VD[10]/LCD_VD[14]" x="-27.94" y="-38.1" length="short"/>
<pin name="P1[20]/USB_TX_DP1/PWM1[2]/QEI_PHA/MC_FB0/SSP0_SCK/LCD_VD[6]/LCD_VD[10]" x="-27.94" y="-40.64" length="short"/>
<pin name="P1[28]/USB_SCL1/PWM1_CAP0/T0_MAT0/MC_2A/SSP0_SSEL/LCD_VD[14]/LCD_VD[22]" x="-27.94" y="-43.18" length="short"/>
<pin name="P1[29]/USB_SDA1/PWM1_CAP1/T0_MAT1/MC_2B/U4_TXD/LCD_VD[15]/LCD_VD[23]" x="-27.94" y="-45.72" length="short"/>
<pin name="VSS_2" x="-27.94" y="25.4" length="short" direction="pas"/>
<pin name="VSS_3" x="-27.94" y="22.86" length="short" direction="pas"/>
<pin name="VSS" x="-27.94" y="20.32" length="short" direction="pas"/>
<pin name="VSSREG" x="-27.94" y="17.78" length="short" direction="pas"/>
<pin name="!RSTOUT" x="86.36" y="38.1" length="short" direction="out" rot="R180"/>
<pin name="P2[23]/!EMC_DYCS3!/SSP0_SSEL/T3_CAP1" x="86.36" y="33.02" length="short" rot="R180"/>
<pin name="P2[20]/!EMC_DYCS0" x="86.36" y="30.48" length="short" rot="R180"/>
<pin name="P2[21]/!EMC_DYCS1" x="86.36" y="27.94" length="short" rot="R180"/>
<pin name="P2[12]/!EINT2!/SD_DAT[2]/I2S_TX_WS/LCD_VD[4]/LCD_VD[3]/LCD_VD[8]/LCD_VD[18]" x="86.36" y="25.4" length="short" rot="R180"/>
<pin name="P2[19]/EMC_CLK[1]" x="86.36" y="22.86" length="short" rot="R180"/>
<pin name="P2[22]/!EMC_DYCS2!/SSP0_SCK/T3_CAP0" x="86.36" y="20.32" length="short" rot="R180"/>
<pin name="P2[16]/!EMC_CAS!" x="86.36" y="17.78" length="short" rot="R180"/>
<pin name="P2[14]/!EMC_CS2!/I2C1_SDA/T2_CAP0" x="86.36" y="15.24" length="short" rot="R180"/>
<pin name="P2[17]/!EMC_RAS" x="86.36" y="12.7" length="short" rot="R180"/>
<pin name="P2[15]/!EMC_CS3!/I2C1_SCL/T2_CAP1" x="86.36" y="10.16" length="short" rot="R180"/>
<pin name="P2[13]/!EINT3!/SD_DAT[3]/I2S_TX_SDA/R/LCD_VD[5]/LCD_VD[9]/LCD_VD[19]" x="86.36" y="7.62" length="short" rot="R180"/>
<pin name="P3[23]/EMC_D[23]/PWM1_CAP0/T0_CAP0" x="86.36" y="-7.62" length="short" rot="R180"/>
<pin name="P4[4]/EMC_A[4]" x="86.36" y="-25.4" length="short" rot="R180"/>
<pin name="P4[16]/EMC_A[16]" x="86.36" y="-27.94" length="short" rot="R180"/>
<pin name="P4[17]/EMC_A[17]" x="86.36" y="-30.48" length="short" rot="R180"/>
<pin name="P4[3]/EMC_A[3]" x="86.36" y="-33.02" length="short" rot="R180"/>
<pin name="P4[5]/EMC_A[5]" x="86.36" y="-35.56" length="short" rot="R180"/>
<pin name="P4[18]/EMC_A[18]" x="86.36" y="-38.1" length="short" rot="R180"/>
<pin name="P4[0]/EMC_A[0]" x="86.36" y="-40.64" length="short" rot="R180"/>
<pin name="P4[2]/EMC_A[2]" x="86.36" y="-43.18" length="short" rot="R180"/>
<pin name="P4[1]/EMC_A[1]" x="86.36" y="-45.72" length="short" rot="R180"/>
<wire x1="-25.4" y1="40.64" x2="-25.4" y2="-48.26" width="0.4064" layer="94"/>
<wire x1="-25.4" y1="-48.26" x2="83.82" y2="-48.26" width="0.4064" layer="94"/>
<wire x1="83.82" y1="-48.26" x2="83.82" y2="40.64" width="0.4064" layer="94"/>
<wire x1="83.82" y1="40.64" x2="-25.4" y2="40.64" width="0.4064" layer="94"/>
<text x="20.5232" y="42.8498" size="2.0828" layer="95" ratio="10" rot="SR0">&gt;NAME</text>
<text x="19.6596" y="-51.2318" size="2.0828" layer="96" ratio="10" rot="SR0">&gt;VALUE</text>
</symbol>
<symbol name="LPC1785FBD208,551_C">
<pin name="VDD(REG)(3V3)" x="-22.86" y="35.56" length="short" direction="pwr"/>
<pin name="VDD(3V3)_2" x="-22.86" y="33.02" length="short" direction="pwr"/>
<pin name="VDD(3V3)_3" x="-22.86" y="30.48" length="short" direction="pwr"/>
<pin name="VDD(3V3)" x="-22.86" y="27.94" length="short" direction="pwr"/>
<pin name="RTCX1" x="-22.86" y="0" length="short" direction="in"/>
<pin name="!RESET" x="-22.86" y="-2.54" length="short" direction="in"/>
<pin name="P0[22]/U1_RTS/SD_DAT[0]/U4_TXD/CAN_TD1/SPIFI_CLK" x="-22.86" y="-7.62" length="short"/>
<pin name="P0[20]/U1_DTR/SD_CMD/I2C1_SCL" x="-22.86" y="-10.16" length="short"/>
<pin name="P0[18]/U1_DCD/SSP0_MOSI/SPIFI_IO0" x="-22.86" y="-12.7" length="short"/>
<pin name="P0[15]/U1_TXD/SSP0_SCK/SPIFI_IO2" x="-22.86" y="-15.24" length="short"/>
<pin name="P0[17]/U1_CTS/SSP0_MISO/SPIFI_IO1" x="-22.86" y="-17.78" length="short"/>
<pin name="P0[19]/U1_DSR/SD_CLK/I1C1_SDA" x="-22.86" y="-20.32" length="short"/>
<pin name="P0[16]/U1_RXD/SSP0_SSEL/SPIFI_IO3" x="-22.86" y="-22.86" length="short"/>
<pin name="P0[21]/U1_RI/SD_PWR/U4_OE/CAN_RD1/U4_SCLK" x="-22.86" y="-25.4" length="short"/>
<pin name="P3[16]/EMC_D[16]/PWM0[1]/U1_TXD" x="-22.86" y="-30.48" length="short"/>
<pin name="P3[17]/EMC_D[17]/PWM0[2]/U1_RXD" x="-22.86" y="-33.02" length="short"/>
<pin name="P3[18]/EMC_D[18]/PWM0[3]/U1_CTS" x="-22.86" y="-35.56" length="short"/>
<pin name="P1[13]/ENET_RX_DV" x="-22.86" y="-40.64" length="short"/>
<pin name="P1[7]/ENET_COL/SD_DAT[1]/PWM0[5]" x="-22.86" y="-43.18" length="short"/>
<pin name="VSS_2" x="-22.86" y="20.32" length="short" direction="pas"/>
<pin name="VSS_3" x="-22.86" y="17.78" length="short" direction="pas"/>
<pin name="VSS_4" x="-22.86" y="15.24" length="short" direction="pas"/>
<pin name="VSS" x="-22.86" y="12.7" length="short" direction="pas"/>
<pin name="RTCX2" x="-22.86" y="2.54" length="short" direction="out"/>
<pin name="P2[9]/USB_CONNECT1/U2_RXD/U4_RXD/ENET_MDIO/R/LCD_VD[3]/LCD_VD[7]" x="78.74" y="35.56" length="short" rot="R180"/>
<pin name="P2[2]/PWM1[3]/U1_CTS/T2_MAT3/R/TRACEDATA[3]/R/LCD_DCLK" x="78.74" y="33.02" length="short" rot="R180"/>
<pin name="P2[8]/CAN_TD2/U2_TXD/U1_CTS/ENET_MDC/R/LCD_VD[2]/LCD_VD[6]" x="78.74" y="30.48" length="short" rot="R180"/>
<pin name="P2[11]/!EINT1!/SD_DAT[1]/I2S_TX-SCK/R/LCD_CLKIN" x="78.74" y="27.94" length="short" rot="R180"/>
<pin name="P2[3]/PWM1[4]/U1_DCD/T2_MAT2/R/TRACEDATA[2]/R/LCD_FP" x="78.74" y="25.4" length="short" rot="R180"/>
<pin name="P2[10]/!EINT0!/NMI" x="78.74" y="22.86" length="short" rot="R180"/>
<pin name="P2[5]/PWM1[6]/U1_DTR/T2_MAT0/R/TRACEDATA[0]/R/LCD_LP" x="78.74" y="20.32" length="short" rot="R180"/>
<pin name="P2[4]/PWM1[5]/U1_DSR/T2_MAT1/R/TRACEDATA[1]/R/LCD_ENAB_M" x="78.74" y="17.78" length="short" rot="R180"/>
<pin name="P2[7]/CAN_RD2/U1_RTS/R/LCD_VD[1]/LCD_VD[5]" x="78.74" y="15.24" length="short" rot="R180"/>
<pin name="P2[6]/PWM1_CAP0/U1_RI/T2_CAP0/U2_OE/TRACECLK/LCD_VD[0]/LCD_VD[4]" x="78.74" y="12.7" length="short" rot="R180"/>
<pin name="P2[1]/PWM1[2]/U1_RXD/R/LCD_LE" x="78.74" y="10.16" length="short" rot="R180"/>
<pin name="P4[20]/EMC_A[20]/I2C2_SDA/SSP1_SCK" x="78.74" y="0" length="short" rot="R180"/>
<pin name="P4[26]/!EMC_BLS0" x="78.74" y="-2.54" length="short" rot="R180"/>
<pin name="P4[19]/EMC_A[19]" x="78.74" y="-5.08" length="short" rot="R180"/>
<pin name="P4[7]/EMC_A[7]" x="78.74" y="-7.62" length="short" rot="R180"/>
<pin name="P4[6]/EMC_A[6]" x="78.74" y="-10.16" length="short" rot="R180"/>
<pin name="P4[23]/EMC_A[23]/U2_RXD/SSP1_MOSI" x="78.74" y="-12.7" length="short" rot="R180"/>
<pin name="P4[21]/EMC_A[21]/I2C2_SCL/SSP1_SSEL" x="78.74" y="-15.24" length="short" rot="R180"/>
<pin name="P4[22]/EMC_A[22]/U2_TXD/SSP1_MISO" x="78.74" y="-17.78" length="short" rot="R180"/>
<pin name="P4[27]/!EMC_BLS1" x="78.74" y="-20.32" length="short" rot="R180"/>
<pin name="P4[12]/EMC_A[12]" x="78.74" y="-22.86" length="short" rot="R180"/>
<pin name="P4[9]/EMC_A[9]" x="78.74" y="-25.4" length="short" rot="R180"/>
<pin name="P4[11]/EMC_A[11]" x="78.74" y="-27.94" length="short" rot="R180"/>
<pin name="P4[10]/EMC_A[10]" x="78.74" y="-30.48" length="short" rot="R180"/>
<pin name="P4[8]/EMC_A[8]" x="78.74" y="-33.02" length="short" rot="R180"/>
<pin name="P5[2]/R/T3_MAT2/R/I2C0_SDA" x="78.74" y="-38.1" length="short" rot="R180"/>
<pin name="P5[3]/R/U4_RXD/I2C0_SCL" x="78.74" y="-40.64" length="short" rot="R180"/>
<wire x1="-20.32" y1="38.1" x2="-20.32" y2="-45.72" width="0.4064" layer="94"/>
<wire x1="-20.32" y1="-45.72" x2="76.2" y2="-45.72" width="0.4064" layer="94"/>
<wire x1="76.2" y1="-45.72" x2="76.2" y2="38.1" width="0.4064" layer="94"/>
<wire x1="76.2" y1="38.1" x2="-20.32" y2="38.1" width="0.4064" layer="94"/>
<text x="17.6784" y="40.1574" size="2.0828" layer="95" ratio="10" rot="SR0">&gt;NAME</text>
<text x="17.8816" y="-49.0474" size="2.0828" layer="96" ratio="10" rot="SR0">&gt;VALUE</text>
</symbol>
<symbol name="LPC1785FBD208,551_D">
<pin name="VDD(3V3)_2" x="-25.4" y="43.18" length="short" direction="pwr"/>
<pin name="VDD(3V3)" x="-25.4" y="40.64" length="short" direction="pwr"/>
<pin name="VDD(REG)(3V3)" x="-25.4" y="38.1" length="short" direction="pwr"/>
<pin name="XTAL1" x="-25.4" y="33.02" length="short" direction="in"/>
<pin name="P0[9]/I2S_TX_SDA/SSP1_MOSI/T2_MAT3/RTC_EV2/R/LCD_VD[17]" x="76.2" y="12.7" length="short" rot="R180"/>
<pin name="P0[6]/I2S_RX_SDA/SSP1_SSEL/T2_MAT0/U1_RTS/R/LCD_VD[8]" x="76.2" y="10.16" length="short" rot="R180"/>
<pin name="P0[8]/I2S_TX_WS/SSP1_MISO/T2_MAT2/RTC_EV1/R/LCD_VD[16]" x="76.2" y="7.62" length="short" rot="R180"/>
<pin name="P0[2]/U0_TXD/U3_TXD" x="76.2" y="5.08" length="short" rot="R180"/>
<pin name="P0[7]/I2S_TX_SCK/SSP1_SCK/T2_MAT1/RTC_EV0/R/LCD_VD[9]" x="76.2" y="2.54" length="short" rot="R180"/>
<pin name="P0[3]/U0_RXD/U3_RXD" x="76.2" y="0" length="short" rot="R180"/>
<pin name="P0[4]/I2S_RX_SCK/CAN_RD2/T2_CAP0/R/LCD_VD[0]" x="76.2" y="-2.54" length="short" rot="R180"/>
<pin name="P0[5]/I2S_RX_WS/CAN_TD2/T2_CAP1/R/LCD_VD[1]" x="76.2" y="-5.08" length="short" rot="R180"/>
<pin name="P1[5]/ENET_TX_ER/SD_PWR/PWM0[3]" x="-25.4" y="0" length="short"/>
<pin name="P1[3]/ENET_TXD3/SD_CMD/PWM0[2]" x="-25.4" y="-2.54" length="short"/>
<pin name="P1[17]/ENET_MDIO/I2S_RX_MCLK" x="-25.4" y="-5.08" length="short"/>
<pin name="P1[4]/ENET_TX_EN/R/T3_MAT2/SSP2_MISO" x="-25.4" y="-7.62" length="short"/>
<pin name="P1[12]/ENET_RXD3/SD_DAT[3]/PWM0_CAP0" x="-25.4" y="-10.16" length="short"/>
<pin name="P1[16]/ENET_MDC/I2S_TX_MCLK" x="-25.4" y="-12.7" length="short"/>
<pin name="P1[15]/ENET_RX_CLK/R/I2C2_SDA" x="-25.4" y="-15.24" length="short"/>
<pin name="P1[0]/ENET_TXD0/R/T3_CAP1/SSP2_SCK" x="-25.4" y="-17.78" length="short"/>
<pin name="P1[11]/ENET_RXD2/SD_DAT[2]/PWM0[6]" x="-25.4" y="-20.32" length="short"/>
<pin name="P1[14]/ENET_RX_ER/R/T2_CAP0" x="-25.4" y="-22.86" length="short"/>
<pin name="P1[9]/ENET_RXD0/R/T3_MAT0" x="-25.4" y="-25.4" length="short"/>
<pin name="P1[6]/ENET_TX_CLK/SD_DAT[0]/PWM0[4]" x="-25.4" y="-27.94" length="short"/>
<pin name="P1[8]/ENET_CRS/R/T3_MAT1/SSP2_SSEL" x="-25.4" y="-30.48" length="short"/>
<pin name="P1[10]/ENET_RXD1/R/T3_CAP0" x="-25.4" y="-33.02" length="short"/>
<pin name="P1[2]/ENET_TXD2/SD_CLK/PWM0[1]" x="-25.4" y="-35.56" length="short"/>
<pin name="P1[1]/ENET_TXD1/R/T3_MAT3/SSP2_MOSI" x="-25.4" y="-38.1" length="short"/>
<pin name="P2[0]/PWM1[1]/U1_TXD/R/LCD_PWR" x="-25.4" y="5.08" length="short"/>
<pin name="VSS_2" x="-25.4" y="25.4" length="short" direction="pas"/>
<pin name="VSS" x="-25.4" y="22.86" length="short" direction="pas"/>
<pin name="VSSREG" x="-25.4" y="20.32" length="short" direction="pas"/>
<pin name="!RTC_ALARM" x="-25.4" y="12.7" length="short" direction="out"/>
<pin name="XTAL2" x="-25.4" y="30.48" length="short" direction="out"/>
<pin name="P3[8]/EMC_D[8]" x="76.2" y="-10.16" length="short" rot="R180"/>
<pin name="P3[22]/EMC_D[22]/PWM0_CAP0/U1_RI" x="76.2" y="-12.7" length="short" rot="R180"/>
<pin name="P3[27]/EMC_D[27]/PWM1[3]/T0_MAT1/STCLK" x="76.2" y="-15.24" length="short" rot="R180"/>
<pin name="P3[2]/EMC_D[2]" x="76.2" y="-17.78" length="short" rot="R180"/>
<pin name="P3[10]/EMC_D[10]" x="76.2" y="-20.32" length="short" rot="R180"/>
<pin name="P3[11]/EMC_D[11]" x="76.2" y="-22.86" length="short" rot="R180"/>
<pin name="P3[19]/EMC_D[19]/PWM0[4]/U1_DCD" x="76.2" y="-25.4" length="short" rot="R180"/>
<pin name="P3[20]/EMC_D[20]/PWM0[5]/U1_DSR" x="76.2" y="-27.94" length="short" rot="R180"/>
<pin name="P3[0]/EMC_D[0]" x="76.2" y="-30.48" length="short" rot="R180"/>
<pin name="P3[21]/EMC_D[21]/PWM0[6]/U1_DTR" x="76.2" y="-33.02" length="short" rot="R180"/>
<pin name="P3[9]/EMC_D[9]" x="76.2" y="-35.56" length="short" rot="R180"/>
<pin name="P3[1]/EMC_D[1]" x="76.2" y="-38.1" length="short" rot="R180"/>
<pin name="P4[14]/EMC_A[14]" x="76.2" y="43.18" length="short" rot="R180"/>
<pin name="P4[29]/!EMC_BLS3!/U3_RXD/T2_MAT1/I2C2_SCL/LCD_VD[7]/LCD_VD[11]/LCD_VD[3]" x="76.2" y="40.64" length="short" rot="R180"/>
<pin name="P4[25]/!EMC_WE" x="76.2" y="38.1" length="short" rot="R180"/>
<pin name="P4[24]/!EMC_OE" x="76.2" y="35.56" length="short" rot="R180"/>
<pin name="P4[30]/!EMC_CS0" x="76.2" y="33.02" length="short" rot="R180"/>
<pin name="P4[31]/!EMC_CS1" x="76.2" y="30.48" length="short" rot="R180"/>
<pin name="P4[28]/!EMC_BLS2!/U3_TXD/T2_MAT0/R/LCD_VD[6]/LCD_VD[10]/LCD_VD[2]" x="76.2" y="27.94" length="short" rot="R180"/>
<pin name="P4[13]/EMC_A[13]" x="76.2" y="25.4" length="short" rot="R180"/>
<pin name="P4[15]/EMC_A[15]" x="76.2" y="22.86" length="short" rot="R180"/>
<pin name="P5[4]/U0_OE/R/T3_MAT3/U4_TXD" x="76.2" y="17.78" length="short" rot="R180"/>
<wire x1="-22.86" y1="45.72" x2="-22.86" y2="-40.64" width="0.4064" layer="94"/>
<wire x1="-22.86" y1="-40.64" x2="73.66" y2="-40.64" width="0.4064" layer="94"/>
<wire x1="73.66" y1="-40.64" x2="73.66" y2="45.72" width="0.4064" layer="94"/>
<wire x1="73.66" y1="45.72" x2="-22.86" y2="45.72" width="0.4064" layer="94"/>
<text x="23.0378" y="47.2694" size="2.0828" layer="95" ratio="10" rot="SR0">&gt;NAME</text>
<text x="24.8158" y="-44.323" size="2.0828" layer="96" ratio="10" rot="SR0">&gt;VALUE</text>
</symbol>
<symbol name="XTAL">
<pin name="P$1" x="-5.08" y="0" visible="off" length="short"/>
<pin name="P$2" x="2.54" y="0" visible="off" length="short" rot="R180"/>
<wire x1="-2.54" y1="1.778" x2="-2.54" y2="-1.778" width="0.254" layer="94"/>
<wire x1="0" y1="1.778" x2="0" y2="-1.778" width="0.254" layer="94"/>
<wire x1="-1.778" y1="1.778" x2="-1.778" y2="-1.778" width="0.254" layer="94"/>
<wire x1="-1.778" y1="-1.778" x2="-0.762" y2="-1.778" width="0.254" layer="94"/>
<wire x1="-0.762" y1="-1.778" x2="-0.762" y2="1.778" width="0.254" layer="94"/>
<wire x1="-0.762" y1="1.778" x2="-1.778" y2="1.778" width="0.254" layer="94"/>
<text x="0.508" y="0.508" size="1.27" layer="95">&gt;NAME</text>
<text x="0.508" y="-1.778" size="1.27" layer="95">&gt;VALUE</text>
</symbol>
<symbol name="BATTERY_HOLDER_COIN_20MM">
<pin name="+" x="0" y="10.16" visible="pad" length="short" rot="R270"/>
<pin name="-" x="0" y="0" visible="pad" length="short" rot="R90"/>
<wire x1="-2.54" y1="7.62" x2="2.54" y2="7.62" width="0.254" layer="94"/>
<wire x1="-1.016" y1="6.35" x2="1.016" y2="6.35" width="0.254" layer="94"/>
<wire x1="-2.54" y1="5.08" x2="2.54" y2="5.08" width="0.254" layer="94"/>
<wire x1="-1.016" y1="3.81" x2="1.016" y2="3.81" width="0.254" layer="94"/>
<wire x1="2.032" y1="9.906" x2="2.032" y2="8.382" width="0.254" layer="94"/>
<wire x1="1.27" y1="9.144" x2="2.794" y2="9.144" width="0.254" layer="94"/>
<wire x1="1.27" y1="2.794" x2="2.794" y2="2.794" width="0.254" layer="94"/>
<text x="1.27" y="10.16" size="1.778" layer="95">&gt;NAME</text>
</symbol>
<symbol name="DIODE">
<description>1864882 	

VISHAY SEMICONDUCTOR

RS07J-GS18

http://fi.farnell.com/webapp/wcs/stores/servlet/ProductDisplay?catalogId=15001&amp;langId=358&amp;urlRequestType=Base&amp;partNumber=1864882&amp;storeId=10159

Diode Configuration:Single; Repetitive Reverse Voltage Vrrm Max:600V; Forward Current If(AV):1.4A; Forward Voltage VF Max:1.15V; Reverse Recovery Time trr Max:250ns; Forward Surge Curr</description>
<pin name="P" x="-5.08" y="0" visible="off" length="short"/>
<pin name="N" x="2.54" y="0" visible="off" length="short" rot="R180"/>
<wire x1="0" y1="1.778" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="0" y2="-1.778" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-2.54" y2="1.778" width="0.254" layer="94"/>
<wire x1="-2.54" y1="1.778" x2="-2.54" y2="-1.778" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-1.778" x2="0" y2="0" width="0.254" layer="94"/>
<text x="0.508" y="0.508" size="1.27" layer="95">&gt;NAME</text>
<text x="0.508" y="-1.524" size="1.27" layer="96">&gt;VALUE</text>
</symbol>
<symbol name="LM2671">
<description>TEXAS INSTRUMENTS  LM2671MX-5.0/NOPB  IC, STEP-DOWN REGULATOR, SOIC-8 
http://fi.farnell.com/texas-instruments/lm2671mx-5-0-nopb/ic-step-down-regulator-soic-8/dp/2395920</description>
<pin name="CB" x="17.78" y="5.08" length="short" rot="R180"/>
<pin name="SS" x="-7.62" y="5.08" length="short"/>
<pin name="SYNC" x="-7.62" y="2.54" length="short"/>
<pin name="FB" x="17.78" y="10.16" length="short" rot="R180"/>
<pin name="ON/OFF" x="-7.62" y="7.62" length="short"/>
<pin name="GND" x="17.78" y="2.54" length="short" rot="R180"/>
<pin name="VIN" x="-7.62" y="10.16" length="short"/>
<pin name="VSW" x="17.78" y="7.62" length="short" rot="R180"/>
<wire x1="15.24" y1="0" x2="-5.08" y2="0" width="0.254" layer="94"/>
<wire x1="-5.08" y1="0" x2="-5.08" y2="12.7" width="0.254" layer="94"/>
<wire x1="-5.08" y1="12.7" x2="15.24" y2="12.7" width="0.254" layer="94"/>
<wire x1="15.24" y1="12.7" x2="15.24" y2="0" width="0.254" layer="94"/>
<text x="-5.08" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<text x="-5.08" y="13.208" size="1.778" layer="95">&gt;NAME</text>
</symbol>
<symbol name="CAP_POLY">
<description>2326162 	

PANASONIC ELECTRONIC COMPONENTS

EEE1JA101P
 Product Range:S Series; Capacitance:100µF; Voltage Rating:63V; AE Capacitor Case:Radial Can - SMD; Diameter:10mm; ESR:-; Height:10.2mm; Ripple Current AC:60mA; Packaging:Cut Tape; Lifetime

http://fi.farnell.com/webapp/wcs/stores/servlet/ProductDisplay?catalogId=15001&amp;langId=358&amp;urlRequestType=Base&amp;partNumber=2326162&amp;storeId=10159</description>
<pin name="+" x="-5.08" y="0" visible="off" length="short"/>
<pin name="-" x="2.54" y="0" visible="off" length="short" swaplevel="1" rot="R180"/>
<wire x1="-2.413" y1="1.905" x2="-2.413" y2="-1.905" width="0.254" layer="94"/>
<wire x1="-0.635" y1="1.905" x2="-0.635" y2="-1.905" width="0.254" layer="94" curve="90"/>
<wire x1="-3.302" y1="1.5875" x2="-3.302" y2="0.9525" width="0.254" layer="94"/>
<wire x1="-3.6195" y1="1.27" x2="-2.9845" y2="1.27" width="0.254" layer="94"/>
<text x="0.127" y="0.889" size="1.27" layer="96">&gt;VALUE</text>
<wire x1="0" y1="0" x2="-1.27" y2="0" width="0.1651" layer="94"/>
<text x="0" y="-1.524" size="1.27" layer="95">&gt;NAME</text>
</symbol>
<symbol name="INDUCTOR">
<description>1828057 	

BOURNS

SDR1005-101KL
Product Range:SDR1005 Series; Inductance:100µH; Inductance Tolerance:± 10%; Inductor Construction:Unshielded; DC Resistance Max:0.33ohm; RMS Current (Irms):1A; Saturation Current (Isat):1.2A;
http://fi.farnell.com/webapp/wcs/stores/servlet/ProductDisplay?catalogId=15001&amp;langId=358&amp;urlRequestType=Base&amp;partNumber=1828057&amp;storeId=10159</description>
<pin name="P$1" x="-5.08" y="0" visible="off" length="point" swaplevel="1"/>
<pin name="P$2" x="5.08" y="0" visible="off" length="short" swaplevel="1" rot="R180"/>
<wire x1="-3.175" y1="0" x2="-1.27" y2="0" width="0.254" layer="94" curve="-180"/>
<wire x1="-1.27" y1="0" x2="0.635" y2="0" width="0.254" layer="94" curve="-180"/>
<wire x1="0.635" y1="0" x2="2.54" y2="0" width="0.254" layer="94" curve="-180"/>
<wire x1="-3.175" y1="0" x2="-5.08" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="1.27" size="1.27" layer="96">&gt;VALUE</text>
<text x="-2.54" y="-1.524" size="1.27" layer="95">&gt;NAME</text>
</symbol>
<symbol name="USB">
<pin name="VCC" x="5.08" y="5.08" visible="pin" length="middle" rot="R180"/>
<pin name="D-" x="5.08" y="2.54" visible="pin" length="middle" rot="R180"/>
<pin name="D+" x="5.08" y="0" visible="pin" length="middle" rot="R180"/>
<pin name="GND" x="5.08" y="-2.54" visible="pin" length="middle" rot="R180"/>
<pin name="SHLD" x="5.08" y="-5.08" visible="pin" length="middle" rot="R180"/>
<wire x1="0" y1="7.62" x2="0" y2="-10.16" width="0.254" layer="94"/>
<wire x1="0" y1="-10.16" x2="-12.7" y2="-10.16" width="0.254" layer="94"/>
<wire x1="-12.7" y1="-10.16" x2="-12.7" y2="7.62" width="0.254" layer="94"/>
<wire x1="-12.7" y1="7.62" x2="0" y2="7.62" width="0.254" layer="94"/>
<text x="-7.62" y="8.382" size="1.778" layer="95">&gt;NAME</text>
<pin name="SHLD@2" x="5.08" y="-7.62" visible="pin" length="middle" rot="R180"/>
<text x="-10.16" y="-12.7" size="1.778" layer="96">&gt;VALUE</text>
</symbol>
<symbol name="HEADER_KENTEK_LCD_4.3_INCH">
<pin name="VLED-" x="-2.54" y="50.8" length="short"/>
<pin name="VLED+" x="-2.54" y="48.26" length="short"/>
<pin name="GND" x="-2.54" y="45.72" length="short"/>
<pin name="VDD" x="-2.54" y="43.18" length="short"/>
<pin name="R0" x="-2.54" y="40.64" length="short"/>
<pin name="R1" x="-2.54" y="38.1" length="short"/>
<pin name="R2" x="-2.54" y="35.56" length="short"/>
<pin name="R3" x="-2.54" y="33.02" length="short"/>
<pin name="R4" x="-2.54" y="30.48" length="short"/>
<pin name="R5" x="-2.54" y="27.94" length="short"/>
<pin name="R6" x="-2.54" y="25.4" length="short"/>
<pin name="R7" x="-2.54" y="22.86" length="short"/>
<pin name="G0" x="-2.54" y="20.32" length="short"/>
<pin name="G1" x="-2.54" y="17.78" length="short"/>
<pin name="G2" x="-2.54" y="15.24" length="short"/>
<pin name="G3" x="-2.54" y="12.7" length="short"/>
<pin name="G4" x="-2.54" y="10.16" length="short"/>
<pin name="G5" x="-2.54" y="7.62" length="short"/>
<pin name="G6" x="-2.54" y="5.08" length="short"/>
<pin name="G7" x="-2.54" y="2.54" length="short"/>
<pin name="B0" x="-2.54" y="0" length="short"/>
<pin name="B1" x="-2.54" y="-2.54" length="short"/>
<pin name="B2" x="-2.54" y="-5.08" length="short"/>
<pin name="B3" x="-2.54" y="-7.62" length="short"/>
<pin name="B4" x="-2.54" y="-10.16" length="short"/>
<pin name="B5" x="-2.54" y="-12.7" length="short"/>
<pin name="B6" x="-2.54" y="-15.24" length="short"/>
<pin name="B7" x="-2.54" y="-17.78" length="short"/>
<pin name="GND@2" x="-2.54" y="-20.32" length="short"/>
<pin name="DCLK" x="-2.54" y="-22.86" length="short"/>
<pin name="DISP" x="-2.54" y="-25.4" length="short"/>
<pin name="HSYNC" x="-2.54" y="-27.94" length="short"/>
<pin name="VSYNC" x="-2.54" y="-30.48" length="short"/>
<pin name="DE" x="-2.54" y="-33.02" length="short"/>
<pin name="NC" x="-2.54" y="-35.56" length="short"/>
<pin name="GND@3" x="-2.54" y="-38.1" length="short"/>
<pin name="X_R" x="-2.54" y="-40.64" length="short"/>
<pin name="Y_B" x="-2.54" y="-43.18" length="short"/>
<pin name="X_L" x="-2.54" y="-45.72" length="short"/>
<pin name="Y_T" x="-2.54" y="-48.26" length="short"/>
<wire x1="0" y1="-55.88" x2="12.7" y2="-55.88" width="0.254" layer="94"/>
<wire x1="12.7" y1="-55.88" x2="12.7" y2="53.34" width="0.254" layer="94"/>
<wire x1="12.7" y1="53.34" x2="0" y2="53.34" width="0.254" layer="94"/>
<wire x1="0" y1="53.34" x2="0" y2="-55.88" width="0.254" layer="94"/>
<text x="0" y="53.848" size="1.778" layer="95">&gt;NAME</text>
<text x="0" y="-58.42" size="1.778" layer="95">&gt;VALUE</text>
<text x="0" y="56.388" size="1.778" layer="97">K430WQA KENTEC 
TFT LCD 4.3 INCH</text>
<pin name="SHD" x="-2.54" y="-50.8" length="short"/>
<pin name="SHD@2" x="-2.54" y="-53.34" length="short"/>
</symbol>
<symbol name="NPN_TRANSISTOR">
<pin name="E" x="-5.08" y="-2.54" visible="off" length="short"/>
<pin name="C" x="5.08" y="-2.54" visible="off" length="short" rot="R180"/>
<pin name="B" x="0" y="2.54" visible="off" length="short" rot="R270"/>
<wire x1="-2.54" y1="-0.762" x2="-0.762" y2="-0.762" width="0.254" layer="94"/>
<wire x1="-0.762" y1="-0.762" x2="0" y2="-0.762" width="0.254" layer="94"/>
<wire x1="0" y1="-0.762" x2="0.762" y2="-0.762" width="0.254" layer="94"/>
<wire x1="0.762" y1="-0.762" x2="2.54" y2="-0.762" width="0.254" layer="94"/>
<wire x1="2.54" y1="-2.54" x2="0.762" y2="-0.762" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-2.54" x2="-0.762" y2="-0.762" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="0" y2="-0.762" width="0.1524" layer="94"/>
<text x="0.254" y="-0.254" size="1.27" layer="94">B</text>
<text x="-4.064" y="-2.286" size="1.27" layer="94">E</text>
<text x="2.794" y="-2.286" size="1.27" layer="94">C</text>
<text x="-4.064" y="1.016" size="1.27" layer="95">&gt;NAME</text>
<text x="-6.604" y="-0.508" size="1.27" layer="96">&gt;VALUE</text>
<wire x1="-2.54" y1="-2.54" x2="-2.54" y2="-1.778" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-2.54" x2="-1.778" y2="-2.54" width="0.254" layer="94"/>
</symbol>
<symbol name="FUSE">
<pin name="P$1" x="-5.08" y="0" visible="off" length="short"/>
<pin name="P$2" x="5.08" y="0" visible="off" length="short" rot="R180"/>
<wire x1="-2.54" y1="1.27" x2="-2.54" y2="0" width="0.254" layer="94"/>
<wire x1="-2.54" y1="0" x2="-2.54" y2="-1.27" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-1.27" x2="2.54" y2="-1.27" width="0.254" layer="94"/>
<wire x1="2.54" y1="-1.27" x2="2.54" y2="0" width="0.254" layer="94"/>
<wire x1="2.54" y1="0" x2="2.54" y2="1.27" width="0.254" layer="94"/>
<wire x1="2.54" y1="1.27" x2="-2.54" y2="1.27" width="0.254" layer="94"/>
<wire x1="-2.54" y1="0" x2="2.54" y2="0" width="0.254" layer="94"/>
<text x="3.048" y="0.508" size="1.27" layer="95">&gt;NAME</text>
<text x="3.048" y="-1.524" size="1.27" layer="96">&gt;VALUE</text>
</symbol>
<symbol name="HEADER_USART_2">
<pin name="TX" x="-5.08" y="5.08" length="middle"/>
<pin name="RX" x="-5.08" y="0" length="middle"/>
<pin name="+5V" x="-5.08" y="-5.08" length="middle"/>
<pin name="GND" x="-5.08" y="-10.16" length="middle"/>
<wire x1="0" y1="7.62" x2="0" y2="-15.24" width="0.254" layer="94"/>
<wire x1="0" y1="-15.24" x2="10.16" y2="-15.24" width="0.254" layer="94"/>
<wire x1="10.16" y1="-15.24" x2="10.16" y2="7.62" width="0.254" layer="94"/>
<wire x1="10.16" y1="7.62" x2="0" y2="7.62" width="0.254" layer="94"/>
<text x="0" y="8.636" size="1.778" layer="95">&gt;NAME</text>
<text x="0" y="-17.78" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND@1" x="-5.08" y="-12.7" length="middle"/>
<pin name="+5V@1" x="-5.08" y="-7.62" length="middle"/>
<pin name="RX@1" x="-5.08" y="-2.54" length="middle"/>
<pin name="TX@1" x="-5.08" y="2.54" length="middle"/>
</symbol>
<symbol name="ALLIANCE_AS4C4M16SA">
<description>http://www.alliancememory.com/pdf/dram/64M-AS4C4M16SA-AUTOMOTIVE.pdf
AS4C4M16SA-Automotive</description>
<pin name="VDD" x="-20.32" y="27.94" length="short"/>
<pin name="DQ0" x="-20.32" y="25.4" length="short"/>
<pin name="VDDQ" x="-20.32" y="22.86" length="short"/>
<pin name="DQ1" x="-20.32" y="20.32" length="short"/>
<pin name="DQ2" x="-20.32" y="17.78" length="short"/>
<pin name="VSSQ" x="-20.32" y="15.24" length="short"/>
<pin name="DQ3" x="-20.32" y="12.7" length="short"/>
<pin name="DQ4" x="-20.32" y="10.16" length="short"/>
<pin name="VDDQ@2" x="-20.32" y="7.62" length="short"/>
<pin name="DQ5" x="-20.32" y="5.08" length="short"/>
<pin name="DQ6" x="-20.32" y="2.54" length="short"/>
<pin name="VSSQ@3" x="-20.32" y="0" length="short"/>
<pin name="DQ7" x="-20.32" y="-2.54" length="short"/>
<pin name="VDD@2" x="-20.32" y="-5.08" length="short"/>
<pin name="LDQM" x="-20.32" y="-7.62" length="short"/>
<pin name="!WE" x="-20.32" y="-10.16" length="short"/>
<pin name="!CAS" x="-20.32" y="-12.7" length="short"/>
<pin name="!RAS" x="-20.32" y="-15.24" length="short"/>
<pin name="!CS" x="-20.32" y="-17.78" length="short"/>
<pin name="BA0" x="-20.32" y="-20.32" length="short"/>
<pin name="BA1" x="-20.32" y="-22.86" length="short"/>
<pin name="A10/AP" x="-20.32" y="-25.4" length="short"/>
<pin name="VDD@3" x="-20.32" y="-38.1" length="short"/>
<pin name="A0" x="-20.32" y="-27.94" length="short"/>
<pin name="A1" x="-20.32" y="-30.48" length="short"/>
<pin name="A2" x="-20.32" y="-33.02" length="short"/>
<pin name="A3" x="-20.32" y="-35.56" length="short"/>
<pin name="VSS" x="15.24" y="-38.1" length="short" rot="R180"/>
<pin name="A4" x="15.24" y="-35.56" length="short" rot="R180"/>
<pin name="A5" x="15.24" y="-33.02" length="short" rot="R180"/>
<pin name="A6" x="15.24" y="-30.48" length="short" rot="R180"/>
<pin name="A7" x="15.24" y="-27.94" length="short" rot="R180"/>
<pin name="A8" x="15.24" y="-25.4" length="short" rot="R180"/>
<pin name="A9" x="15.24" y="-22.86" length="short" rot="R180"/>
<pin name="A11" x="15.24" y="-20.32" length="short" rot="R180"/>
<pin name="NC" x="15.24" y="-17.78" length="short" rot="R180"/>
<pin name="CKE" x="15.24" y="-15.24" length="short" rot="R180"/>
<pin name="CLK" x="15.24" y="-12.7" length="short" rot="R180"/>
<pin name="UDQM" x="15.24" y="-10.16" length="short" rot="R180"/>
<pin name="NC/RFU" x="15.24" y="-7.62" length="short" rot="R180"/>
<pin name="VSS@2" x="15.24" y="-5.08" length="short" rot="R180"/>
<pin name="DQ8" x="15.24" y="-2.54" length="short" rot="R180"/>
<pin name="VDDQ@3" x="15.24" y="0" length="short" rot="R180"/>
<pin name="DQ9" x="15.24" y="2.54" length="short" rot="R180"/>
<pin name="DQ10" x="15.24" y="5.08" length="short" rot="R180"/>
<pin name="VSSQ@2" x="15.24" y="7.62" length="short" rot="R180"/>
<pin name="DQ11" x="15.24" y="10.16" length="short" rot="R180"/>
<pin name="DQ12" x="15.24" y="12.7" length="short" rot="R180"/>
<pin name="VDDQ@4" x="15.24" y="15.24" length="short" rot="R180"/>
<pin name="DQ13" x="15.24" y="17.78" length="short" rot="R180"/>
<pin name="DQ14" x="15.24" y="20.32" length="short" rot="R180"/>
<pin name="VSSQ@4" x="15.24" y="22.86" length="short" rot="R180"/>
<pin name="DQ15" x="15.24" y="25.4" length="short" rot="R180"/>
<pin name="VSS@3" x="15.24" y="27.94" length="short" rot="R180"/>
<wire x1="-17.78" y1="30.48" x2="12.7" y2="30.48" width="0.254" layer="94"/>
<wire x1="12.7" y1="30.48" x2="12.7" y2="-40.64" width="0.254" layer="94"/>
<wire x1="12.7" y1="-40.64" x2="-17.78" y2="-40.64" width="0.254" layer="94"/>
<wire x1="-17.78" y1="-40.64" x2="-17.78" y2="30.48" width="0.254" layer="94"/>
<text x="-17.526" y="31.242" size="1.778" layer="95">&gt;NAME</text>
<text x="2.794" y="31.242" size="1.778" layer="96">&gt;VALUE</text>
</symbol>
<symbol name="MCP2551">
<description>Microchip High-Speed CAN
 Transceiver
Supports 1 Mb/s operation
•  Implements ISO-11898 standard physical layer 
requirements
•  Suitable for 12V and 24V systems
•  Externally-controlled slope for reduced RFI        
emissions
•  Detection of ground fault (permanent dominant) 
on TXD input
•  Power-on reset and voltage brown-out protection
•  An unpowered node or brown-out event will not   
disturb the CAN bus
•  Low current standby operation
•  Protection against damage due to short-circuit    
conditions (positive or negative battery voltage)
•  Protection against high-voltage transients
•  Automatic thermal shutdown protection
•  Up to 112 nodes can be connected
•  High noise immunity due to differential bus        
implementation
•  Temperature ranges:
-  Industrial (I): -40°C to +85°C
-  Extended (E): -40°C to +125°C


http://www.digikey.com/product-detail/en/MCP2551T-E%2FSN/MCP2551T-E%2FSNCT-ND/4307904
http://ww1.microchip.com/downloads/en/DeviceDoc/21667f.pdf
http://www.farnell.com/datasheets/657417.pdf
http://fi.farnell.com/microchip/mcp2551-i-sn/ic-can-transceiver-hi-speed-smd/dp/9758569</description>
<pin name="TXD" x="-2.54" y="2.54" length="short"/>
<pin name="VSS" x="-2.54" y="0" length="short"/>
<pin name="VDD" x="-2.54" y="-2.54" length="short"/>
<pin name="RXD" x="-2.54" y="-5.08" length="short"/>
<pin name="RS" x="20.32" y="2.54" length="short" rot="R180"/>
<pin name="CANH" x="20.32" y="0" length="short" rot="R180"/>
<pin name="CANL" x="20.32" y="-2.54" length="short" rot="R180"/>
<pin name="VREF" x="20.32" y="-5.08" length="short" rot="R180"/>
<wire x1="17.78" y1="-7.62" x2="0" y2="-7.62" width="0.254" layer="94"/>
<wire x1="0" y1="-7.62" x2="0" y2="5.08" width="0.254" layer="94"/>
<wire x1="0" y1="5.08" x2="17.78" y2="5.08" width="0.254" layer="94"/>
<wire x1="17.78" y1="5.08" x2="17.78" y2="-7.62" width="0.254" layer="94"/>
<text x="0" y="-9.652" size="1.778" layer="96">&gt;VALUE</text>
<text x="0" y="5.588" size="1.778" layer="95">&gt;NAME</text>
</symbol>
<symbol name="HEADER12">
<pin name="P$1" x="0" y="12.7" length="short"/>
<pin name="P$2" x="0" y="10.16" length="short"/>
<pin name="P$3" x="0" y="7.62" length="short"/>
<pin name="P$4" x="0" y="5.08" length="short"/>
<pin name="P$5" x="0" y="2.54" length="short"/>
<pin name="P$6" x="0" y="0" length="short"/>
<pin name="P$7" x="0" y="-2.54" length="short"/>
<pin name="P$8" x="0" y="-5.08" length="short"/>
<pin name="P$9" x="0" y="-7.62" length="short"/>
<pin name="P$10" x="0" y="-10.16" length="short"/>
<pin name="P$11" x="0" y="-12.7" length="short"/>
<pin name="P$12" x="0" y="-15.24" length="short"/>
<wire x1="2.54" y1="15.24" x2="10.16" y2="15.24" width="0.254" layer="94"/>
<wire x1="10.16" y1="15.24" x2="10.16" y2="-17.78" width="0.254" layer="94"/>
<wire x1="10.16" y1="-17.78" x2="2.54" y2="-17.78" width="0.254" layer="94"/>
<wire x1="2.54" y1="-17.78" x2="2.54" y2="15.24" width="0.254" layer="94"/>
<text x="2.794" y="15.748" size="1.778" layer="95">&gt;NAME</text>
<text x="2.54" y="-19.812" size="1.778" layer="95">&gt;VALUE</text>
</symbol>
<symbol name="WINDBOND_W25Q32FV">
<description>W25Q32FVSSIG
Format - Memory	FLASH
Memory Type	FLASH - NOR
Memory Size	32M (4M x 8)
Speed	104MHz
Interface	SPI Serial
Voltage - Supply	2.7 V ~ 3.6 V
Operating Temperature	-40°C ~ 85°C
Package / Case	8-SOIC (0.209", 5.30mm Width)
Supplier Device Package	8-SOIC
http://www.winbond.com/resource-files/w25q32fv%20revh%20091613.pdf</description>
<pin name="!CS" x="-12.7" y="2.54" length="short"/>
<pin name="DO/IO1" x="-12.7" y="0" length="short"/>
<pin name="!WP!/IO2" x="-12.7" y="-2.54" length="short"/>
<pin name="GND" x="-12.7" y="-5.08" length="short"/>
<pin name="VCC" x="17.78" y="2.54" length="short" rot="R180"/>
<pin name="!RESET!/IO3" x="17.78" y="0" length="short" rot="R180"/>
<pin name="CLK" x="17.78" y="-2.54" length="short" rot="R180"/>
<pin name="DI/IO0" x="17.78" y="-5.08" length="short" rot="R180"/>
<wire x1="-10.16" y1="5.08" x2="15.24" y2="5.08" width="0.254" layer="94"/>
<wire x1="15.24" y1="5.08" x2="15.24" y2="-7.62" width="0.254" layer="94"/>
<wire x1="15.24" y1="-7.62" x2="-10.16" y2="-7.62" width="0.254" layer="94"/>
<wire x1="-10.16" y1="-7.62" x2="-10.16" y2="5.08" width="0.254" layer="94"/>
<text x="-10.16" y="5.588" size="1.778" layer="95">&gt;NAME</text>
<text x="2.794" y="5.588" size="1.778" layer="96">&gt;VALUE</text>
</symbol>
<symbol name="TI_TVP5150AM1">
<description>TVP5150AM1
http://www.ti.com/lit/ds/symlink/tvp5150am1.pdf
Standard
Programmable
Video
Output
Formats
M,
N,
Nc),
and
SECAM
(B,
D,
G,
K,
K1,
L)
Video
–
ITU-R
BT.656,
8-Bit
4:2:2
With
Embedded
•
Supports
ITU-R
BT.601
Standard
Sampling
Syncs
•
High-Speed
9-Bit
Analog-to-Digital
Converter
–
8-Bit
4:2:2
With
Discrete
Syncs
(ADC)
•
Macrovision
™
Copy
Protection
Detection
•
Two
Composite
Inputs
or
One
S-Video
Input
•
Advanced
Programmable
Video
Output
•
Fully
Differential
CMOS
Analog
Preprocessing
Formats
Channels
With
Clamping
and
Automatic
Gain
–
2
×
Oversampled
Raw
Vertical
Blanking
Control
(AGC)
for
Best
Signal-to-Noise
(S/N)
Interval
(VBI)
Data
During
Active
Video
Performance
–
Sliced
VBI
Data
During
Horizontal
Blanking
•
Ultralow
Power
Consumption
or
Active
Video
•
48-Terminal
PBGA
Package
(ZQC)
or
•
VBI
Modes
Supported
32-Terminal
TQFP
Package
(PBS)
–
Teletext
(NABTS,
WST)
•
Power-Down
Mode:
&lt;
1
mW
–
Closed-Caption
Decode
With
FIFO
and
•
Brightness,
Contrast,
Saturation,
Hue,
and
Extended
Data
Services
(XDS)
Sharpness
Control
Through
I
2
C
–
Wide
Screen
Signaling,
Video
Program
•
Complementary
4-Line
(3-H
Delay)
Adaptive
System,
CGMS-A,
Vertical
Interval
Time
Comb
Filters
for
Both
Cross-Luminance
and
Code
Cross-Chrominance
Noise
Reduction
–
Gemstar
1x/2x
Electronic
Program
Guide
•
Patented
Architecture
for
Locking
to
Weak,
Compatible
Mode
Noisy,
or
Unstable
Signals
–
Custom
Configuration
Mode
That
Allows
•
Single
14.31818-MHz
Crystal
for
All
Standards
User
to
Program
Slice
Engine
for
Unique
VBI
•
Internal
Phase-Locked
Loop
(PLL)
for
Data
Signals
Line-Locked
Clock
and
Sampling
•
Power-On
Reset
•
Subcarrier
Genlock
Output
for
Synchronizing
•
Industrial
Temperature
Range
Color
Subcarrier
of
External
Encoder
(TVP5150AM1I):
–
40
°
C
to
85
°
C
•
3.3-V
Digital
I/O
Supply
Voltage
Range
•
Qualified
for
Automotive
Applications
(AEC-Q100
Rev
G
–
TVP5150AM1IPBSQ1,
TVP5150AM1IPBSRQ)</description>
<pin name="AIP1A" x="-12.7" y="12.7" length="short"/>
<pin name="AIP1B" x="-12.7" y="10.16" length="short"/>
<pin name="PLL_AGND" x="27.94" y="-30.48" length="short" rot="R180"/>
<pin name="PLL_AVDD" x="27.94" y="7.62" length="short" rot="R180"/>
<pin name="XTAL1/OSC" x="-12.7" y="2.54" length="short"/>
<pin name="XTAL2" x="-12.7" y="0" length="short"/>
<pin name="AGND" x="27.94" y="-33.02" length="short" rot="R180"/>
<pin name="RESETB" x="-12.7" y="-7.62" length="short"/>
<pin name="SCLK" x="-12.7" y="-10.16" length="short"/>
<pin name="IO_DVDD" x="27.94" y="5.08" length="short" rot="R180"/>
<pin name="YOUT7/I2CSEL" x="-12.7" y="-17.78" length="short"/>
<pin name="YOUT6" x="-12.7" y="-20.32" length="short"/>
<pin name="YOUT5" x="-12.7" y="-22.86" length="short"/>
<pin name="YOUT4" x="-12.7" y="-25.4" length="short"/>
<pin name="YOUT3" x="-12.7" y="-27.94" length="short"/>
<pin name="YOUT2" x="-12.7" y="-30.48" length="short"/>
<pin name="YOUT1" x="-12.7" y="-33.02" length="short"/>
<pin name="YOUT0" x="-12.7" y="-35.56" length="short"/>
<pin name="DGND" x="27.94" y="-35.56" length="short" rot="R180"/>
<pin name="DVDD" x="27.94" y="10.16" length="short" rot="R180"/>
<pin name="SCL" x="27.94" y="-22.86" length="short" rot="R180"/>
<pin name="SDA" x="27.94" y="-20.32" length="short" rot="R180"/>
<pin name="FID/GLCO" x="27.94" y="-17.78" length="short" rot="R180"/>
<pin name="VSYNC/PALI" x="27.94" y="-15.24" length="short" rot="R180"/>
<pin name="HSYNC" x="27.94" y="-12.7" length="short" rot="R180"/>
<pin name="AVID" x="27.94" y="-10.16" length="short" rot="R180"/>
<pin name="INTREQ/GPCL/VBLK" x="27.94" y="-7.62" length="short" rot="R180"/>
<pin name="PDN" x="27.94" y="-5.08" length="short" rot="R180"/>
<pin name="REFP" x="27.94" y="-2.54" length="short" rot="R180"/>
<pin name="REFM" x="27.94" y="0" length="short" rot="R180"/>
<pin name="CH_AGND" x="27.94" y="-27.94" length="short" rot="R180"/>
<pin name="CH_AVDD" x="27.94" y="12.7" length="short" rot="R180"/>
<wire x1="-10.16" y1="15.24" x2="25.4" y2="15.24" width="0.254" layer="94"/>
<wire x1="25.4" y1="15.24" x2="25.4" y2="-38.1" width="0.254" layer="94"/>
<wire x1="25.4" y1="-38.1" x2="-10.16" y2="-38.1" width="0.254" layer="94"/>
<wire x1="-10.16" y1="-38.1" x2="-10.16" y2="15.24" width="0.254" layer="94"/>
<text x="-9.906" y="16.002" size="1.778" layer="95">&gt;NAME</text>
<text x="5.08" y="16.002" size="1.778" layer="96">&gt;VALUE</text>
</symbol>
<symbol name="MICREL_MIC5247-1.8YM5">
<description>MICREL SEMICONDUCTOR  MIC5247-1.8YM5 TR  V REG, 2.7-6V, 0.15A, 1.8V, 2%, 5SOT23 

http://www.farnell.com/datasheets/1670792.pdf

 Input Voltage Max: 6V
Input Voltage Min: 2.7V
Linear Regulator Case Style: SOT-23
MSL: MSL 3 - 168 hours
No. of Pins: 5
Operating Temperature Max: 125°C
Operating Temperature Min: -40°C
Output Current: 150mA
Output Voltage Nom.: 1.8V</description>
<pin name="IN" x="-7.62" y="2.54" length="short"/>
<pin name="GND" x="-7.62" y="-2.54" length="short"/>
<pin name="EN" x="-7.62" y="0" length="short"/>
<pin name="BYP" x="10.16" y="0" length="short" rot="R180"/>
<pin name="OUT" x="10.16" y="2.54" length="short" rot="R180"/>
<wire x1="7.62" y1="5.08" x2="-5.08" y2="5.08" width="0.254" layer="94"/>
<wire x1="-5.08" y1="5.08" x2="-5.08" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-5.08" x2="7.62" y2="-5.08" width="0.254" layer="94"/>
<wire x1="7.62" y1="-5.08" x2="7.62" y2="5.08" width="0.254" layer="94"/>
<text x="-5.08" y="5.588" size="1.778" layer="95">&gt;NAME</text>
<text x="-5.08" y="7.62" size="1.778" layer="96">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="RES" prefix="R" uservalue="yes">
<gates>
<gate name="G$1" symbol="RES" x="0" y="0"/>
</gates>
<devices>
<device name="TROUGH_HOLE" package="RES_1/4W_TH">
<connects>
<connect gate="G$1" pin="P$1" pad="0"/>
<connect gate="G$1" pin="P$2" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_0603" package="0603_SILKSCREEN">
<connects>
<connect gate="G$1" pin="P$1" pad="0"/>
<connect gate="G$1" pin="P$2" pad="1"/>
</connects>
<technologies>
<technology name="">
<attribute name="SMD_SIZE" value="0603 (1608 metric)" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="CAP" prefix="C" uservalue="yes">
<gates>
<gate name="G$1" symbol="CAP" x="0" y="0"/>
</gates>
<devices>
<device name="_0603" package="0603_SILKSCREEN">
<connects>
<connect gate="G$1" pin="P$1" pad="0"/>
<connect gate="G$1" pin="P$2" pad="1"/>
</connects>
<technologies>
<technology name="">
<attribute name="SMD_SIZE" value="0603 (1608 metric)" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="LED" prefix="D" uservalue="yes">
<gates>
<gate name="G$1" symbol="LED" x="2.54" y="0"/>
</gates>
<devices>
<device name="TROUGHT-HOLE" package="LED_TH">
<connects>
<connect gate="G$1" pin="0" pad="A"/>
<connect gate="G$1" pin="1" pad="K"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_0603" package="0603_SILKSCREEN">
<connects>
<connect gate="G$1" pin="0" pad="0"/>
<connect gate="G$1" pin="1" pad="1"/>
</connects>
<technologies>
<technology name="">
<attribute name="SMD_SIZE" value="0603 (1608 metric)" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="LPC1785FBD208,551" prefix="U" uservalue="yes">
<description>32-bit ARM Cortex-M3 microcontroller,LQFP-208

Datasheets	LPC178X,177X
Product Photos	208-LQFP SOT459-1
PCN Design/Specification	LPC177x/178x Datasheet Update 05/Jun/2014
Standard Package ? 	36
Category	Integrated Circuits (ICs)
Family	Embedded - Microcontrollers
Series	LPC17xx
Packaging ? 	Tray ? 
Core Processor	ARM® Cortex®-M3
Core Size	32-Bit
Speed	120MHz
Connectivity	CAN, EBI/EMI, I²C, Microwire, Memory Card, SPI, SSI, SSP, UART/USART, USB OTG
Peripherals	Brown-out Detect/Reset, DMA, I²S, LCD, Motor Control PWM, POR, PWM, WDT
Number of I/O	165
Program Memory Size	256KB (256K x 8)
Program Memory Type	FLASH
EEPROM Size	4K x 8
RAM Size	80K x 8
Voltage - Supply (Vcc/Vdd)	2.4 V ~ 3.6 V
Data Converters	A/D 8x12b, D/A 1x10b
Oscillator Type	Internal
Operating Temperature	-40°C ~ 85°C
Package / Case	208-LQFP
Supplier Device Package	208-LQFP (28x28)
For Use With	
568-10930-ND - BOARD EVAL LPC-LINK 2
EA-XPR-200-ND - LPC-LINK 2
Other Names	568-7573
935291613551
LPC1785FBD208,551-ND
LPC1785FBD208551</description>
<gates>
<gate name="A" symbol="LPC1785FBD208,551_A" x="0" y="0"/>
<gate name="B" symbol="LPC1785FBD208,551_B" x="0" y="0"/>
<gate name="C" symbol="LPC1785FBD208,551_C" x="0" y="0"/>
<gate name="D" symbol="LPC1785FBD208,551_D" x="0" y="0"/>
</gates>
<devices>
<device name="QFP50" package="QFP50P3000X3000X160-208N">
<connects>
<connect gate="A" pin="JTAG_TDI" pad="4"/>
<connect gate="A" pin="JTAG_TDO/(SWO)" pad="2"/>
<connect gate="A" pin="JTAG_TMS/(SWDIO)" pad="6"/>
<connect gate="A" pin="P0[12]/USB_PPWR2_N/SSP1_MISO/ADC0_IN[6]" pad="41"/>
<connect gate="A" pin="P0[13]/USB_UP_LED2/SSP1_MOSI/ADC0_IN[7]" pad="45"/>
<connect gate="A" pin="P0[23]/ADC0_IN[0]/I2S_RX_SCK/T3_CAP0" pad="18"/>
<connect gate="A" pin="P0[24]/ADC0_IN[1]/I2S_RX_WS/T3_CAP1" pad="16"/>
<connect gate="A" pin="P0[25]/ADC0_IN[2]/I2S_RX_SDA/U3_TXD" pad="14"/>
<connect gate="A" pin="P0[26]/ADC0_IN[3]/DAC_OUT/U3_RXD" pad="12"/>
<connect gate="A" pin="P0[27]/I2C0_SDA/USB_SDA1" pad="50"/>
<connect gate="A" pin="P0[28]/I2C0_SCL/USB_SCL1" pad="48"/>
<connect gate="A" pin="P0[31]/USB_D+2" pad="51"/>
<connect gate="A" pin="P1[30]/USB_PWRD2/USB_VBUS/ADC0_IN[4]/I2C0_SDA" pad="42"/>
<connect gate="A" pin="P1[31]/USB_OVRCR2_N/SSP1_SCK/ADC0_IN[5]/I2C0_SCL" pad="40"/>
<connect gate="A" pin="P2[18]/EMC_CLK[0]" pad="59"/>
<connect gate="A" pin="P2[24]/EMC_CKE0" pad="53"/>
<connect gate="A" pin="P2[25]/EMC_CKE1" pad="54"/>
<connect gate="A" pin="P2[26]/EMC_CKE2/SSP0_MISO/T3_MAT0" pad="57"/>
<connect gate="A" pin="P2[27]/EMC_CKE3/SSP0_MOSI/T3_MAT1" pad="47"/>
<connect gate="A" pin="P2[28]/EMC_DQM0" pad="49"/>
<connect gate="A" pin="P2[29]/EMC_DQM1" pad="43"/>
<connect gate="A" pin="P2[30]/EMC_DQM2/I2C2_SDA/T3_MAT2" pad="31"/>
<connect gate="A" pin="P2[31]/EMC_DQM3/I2C2_SCL/T3_MAT3" pad="39"/>
<connect gate="A" pin="P3[12]/EMC_D[12]" pad="1"/>
<connect gate="A" pin="P3[13]/EMC_D[13]" pad="7"/>
<connect gate="A" pin="P3[14]/EMC_D[14]" pad="21"/>
<connect gate="A" pin="P3[15]/EMC_D[15]" pad="28"/>
<connect gate="A" pin="P3[24]/EMC_D[24]/PWM1[1]/T0_CAP1" pad="58"/>
<connect gate="A" pin="P3[25]/EMC_D[25]/PWM1[2]/T0_MAT0" pad="56"/>
<connect gate="A" pin="P3[26]/EMC_D[26]/PWM1[3]/T0_MAT1/STCLK" pad="55"/>
<connect gate="A" pin="P3[28]/EMC_D[28]/PWM1[5]/T1_CAP1" pad="5"/>
<connect gate="A" pin="P3[29]/EMC_D[29]/PWM1[6]/T1_MAT0" pad="11"/>
<connect gate="A" pin="P3[30]/EMC_D[30]/U1_RTS/T1_MAT1" pad="19"/>
<connect gate="A" pin="P3[31]/EMC_D[31]/R/T1_MAT2" pad="25"/>
<connect gate="A" pin="P3[3]/EMC_D[3]" pad="3"/>
<connect gate="A" pin="P3[4]/EMC_D[4]" pad="13"/>
<connect gate="A" pin="P3[5]/EMC_D[5]" pad="17"/>
<connect gate="A" pin="P3[6]/EMC_D[6]" pad="23"/>
<connect gate="A" pin="P3[7]/EMC_D[7]" pad="27"/>
<connect gate="A" pin="P5[0]/EMC_A[24]/SSP2_MOSI/T2_MAT2" pad="9"/>
<connect gate="A" pin="P5[1]/EMC_A[25]/SSP2_MISO/T2_MAT3" pad="30"/>
<connect gate="A" pin="USB_D-2" pad="52"/>
<connect gate="A" pin="VDD(3V3)" pad="198"/>
<connect gate="A" pin="VDD(3V3)_2" pad="15"/>
<connect gate="A" pin="VDD(REG)(3V3)" pad="26"/>
<connect gate="A" pin="VDDA" pad="20"/>
<connect gate="A" pin="VREFP" pad="24"/>
<connect gate="A" pin="VSS" pad="33"/>
<connect gate="A" pin="VSSA" pad="22"/>
<connect gate="A" pin="VSSREG" pad="32"/>
<connect gate="B" pin="!RSTOUT" pad="29"/>
<connect gate="B" pin="JTAG_!TRST!" pad="8"/>
<connect gate="B" pin="JTAG_TCK/(SWDCLK)" pad="10"/>
<connect gate="B" pin="P0[0]/CAN_RD1/U3_TXD/I2C1_SDA/U0_TXD" pad="94"/>
<connect gate="B" pin="P0[10]/U2_TXD/I2C2_SDA/T3_MAT0" pad="98"/>
<connect gate="B" pin="P0[11]/U2_RXD/I2C2_SCL/T3_MAT1" pad="100"/>
<connect gate="B" pin="P0[14]/!USB_HSTEN2!/SSP1_SSEL/USB_CONNECT2" pad="69"/>
<connect gate="B" pin="P0[1]/CAN_TD1/U3_RXD/I2C1_SCL/U0_RXD" pad="96"/>
<connect gate="B" pin="P0[29]/USB_D+1/!EINT0" pad="61"/>
<connect gate="B" pin="P0[30]/USB_D-1/!EINT1" pad="62"/>
<connect gate="B" pin="P1[18]/USB_UP_LED1/PWM1[1]/T1_CAP0/R/SSP1_MISO" pad="66"/>
<connect gate="B" pin="P1[19]/!USB_TX_E1!/!USB_PPWR1!/T1_CAP1_MC_0A/SSP1_SCK/U2_OE" pad="68"/>
<connect gate="B" pin="P1[20]/USB_TX_DP1/PWM1[2]/QEI_PHA/MC_FB0/SSP0_SCK/LCD_VD[6]/LCD_VD[10]" pad="70"/>
<connect gate="B" pin="P1[21]/USB_TX_DM1/PWM1[3]/SSP0_SSEL/!MC_ABORT!/R/LCD_VD[7]/LCD_VD[11]" pad="72"/>
<connect gate="B" pin="P1[22]/USB_RCV1/USB_PWRD1/T1_MAT0/MC_0B/SSP1_MOSI/LCD_VD[8]/LCD_VD[12]" pad="74"/>
<connect gate="B" pin="P1[23]/USB_RX_DP1/PWM1[4]/QEI_PHB/MC_FB1/SSP0_MISO/LCD_VD[9]/LCD_VD[13]" pad="76"/>
<connect gate="B" pin="P1[24]/USB_RX_DM1/PWM1[5]/QEI_IDX/MC_FB2/SSP0_MOSI/LCD_VD[10]/LCD_VD[14]" pad="78"/>
<connect gate="B" pin="P1[25]/!USB_LS1!/!USB_HSTEN1!/T1_MAT1/MC_1A/CLKOUT/LCD_VD[11]/LCD_VD[15]" pad="80"/>
<connect gate="B" pin="P1[26]/!USB_SSPND1!/PWM1[6]/T0_CAP0/MC_1B/SSP1_SSEL/LCD_VD[12]/LCD_VD[20]" pad="82"/>
<connect gate="B" pin="P1[27]/!USB_INT1!/!USB_OVRCR1!/T0_CAP1/CLKOUT/R/LCD_VD[13]/LCD_VD[21]" pad="88"/>
<connect gate="B" pin="P1[28]/USB_SCL1/PWM1_CAP0/T0_MAT0/MC_2A/SSP0_SSEL/LCD_VD[14]/LCD_VD[22]" pad="90"/>
<connect gate="B" pin="P1[29]/USB_SDA1/PWM1_CAP1/T0_MAT1/MC_2B/U4_TXD/LCD_VD[15]/LCD_VD[23]" pad="92"/>
<connect gate="B" pin="P2[12]/!EINT2!/SD_DAT[2]/I2S_TX_WS/LCD_VD[4]/LCD_VD[3]/LCD_VD[8]/LCD_VD[18]" pad="106"/>
<connect gate="B" pin="P2[13]/!EINT3!/SD_DAT[3]/I2S_TX_SDA/R/LCD_VD[5]/LCD_VD[9]/LCD_VD[19]" pad="102"/>
<connect gate="B" pin="P2[14]/!EMC_CS2!/I2C1_SDA/T2_CAP0" pad="91"/>
<connect gate="B" pin="P2[15]/!EMC_CS3!/I2C1_SCL/T2_CAP1" pad="99"/>
<connect gate="B" pin="P2[16]/!EMC_CAS!" pad="87"/>
<connect gate="B" pin="P2[17]/!EMC_RAS" pad="95"/>
<connect gate="B" pin="P2[19]/EMC_CLK[1]" pad="67"/>
<connect gate="B" pin="P2[20]/!EMC_DYCS0" pad="73"/>
<connect gate="B" pin="P2[21]/!EMC_DYCS1" pad="81"/>
<connect gate="B" pin="P2[22]/!EMC_DYCS2!/SSP0_SCK/T3_CAP0" pad="85"/>
<connect gate="B" pin="P2[23]/!EMC_DYCS3!/SSP0_SSEL/T3_CAP1" pad="64"/>
<connect gate="B" pin="P3[23]/EMC_D[23]/PWM1_CAP0/T0_CAP0" pad="65"/>
<connect gate="B" pin="P4[0]/EMC_A[0]" pad="75"/>
<connect gate="B" pin="P4[16]/EMC_A[16]" pad="101"/>
<connect gate="B" pin="P4[17]/EMC_A[17]" pad="104"/>
<connect gate="B" pin="P4[18]/EMC_A[18]" pad="105"/>
<connect gate="B" pin="P4[1]/EMC_A[1]" pad="79"/>
<connect gate="B" pin="P4[2]/EMC_A[2]" pad="83"/>
<connect gate="B" pin="P4[3]/EMC_A[3]" pad="97"/>
<connect gate="B" pin="P4[4]/EMC_A[4]" pad="103"/>
<connect gate="B" pin="P4[5]/EMC_A[5]" pad="107"/>
<connect gate="B" pin="VBAT" pad="38"/>
<connect gate="B" pin="VDD(3V3)" pad="181"/>
<connect gate="B" pin="VDD(3V3)_2" pad="71"/>
<connect gate="B" pin="VDD(3V3)_3" pad="60"/>
<connect gate="B" pin="VSS" pad="93"/>
<connect gate="B" pin="VSSREG" pad="84"/>
<connect gate="B" pin="VSS_2" pad="63"/>
<connect gate="B" pin="VSS_3" pad="77"/>
<connect gate="C" pin="!RESET" pad="35"/>
<connect gate="C" pin="P0[15]/U1_TXD/SSP0_SCK/SPIFI_IO2" pad="128"/>
<connect gate="C" pin="P0[16]/U1_RXD/SSP0_SSEL/SPIFI_IO3" pad="130"/>
<connect gate="C" pin="P0[17]/U1_CTS/SSP0_MISO/SPIFI_IO1" pad="126"/>
<connect gate="C" pin="P0[18]/U1_DCD/SSP0_MOSI/SPIFI_IO0" pad="124"/>
<connect gate="C" pin="P0[19]/U1_DSR/SD_CLK/I1C1_SDA" pad="122"/>
<connect gate="C" pin="P0[20]/U1_DTR/SD_CMD/I2C1_SCL" pad="120"/>
<connect gate="C" pin="P0[21]/U1_RI/SD_PWR/U4_OE/CAN_RD1/U4_SCLK" pad="118"/>
<connect gate="C" pin="P0[22]/U1_RTS/SD_DAT[0]/U4_TXD/CAN_TD1/SPIFI_CLK" pad="116"/>
<connect gate="C" pin="P1[13]/ENET_RX_DV" pad="147"/>
<connect gate="C" pin="P1[7]/ENET_COL/SD_DAT[1]/PWM0[5]" pad="153"/>
<connect gate="C" pin="P2[10]/!EINT0!/NMI" pad="110"/>
<connect gate="C" pin="P2[11]/!EINT1!/SD_DAT[1]/I2S_TX-SCK/R/LCD_CLKIN" pad="108"/>
<connect gate="C" pin="P2[1]/PWM1[2]/U1_RXD/R/LCD_LE" pad="152"/>
<connect gate="C" pin="P2[2]/PWM1[3]/U1_CTS/T2_MAT3/R/TRACEDATA[3]/R/LCD_DCLK" pad="150"/>
<connect gate="C" pin="P2[3]/PWM1[4]/U1_DCD/T2_MAT2/R/TRACEDATA[2]/R/LCD_FP" pad="144"/>
<connect gate="C" pin="P2[4]/PWM1[5]/U1_DSR/T2_MAT1/R/TRACEDATA[1]/R/LCD_ENAB_M" pad="142"/>
<connect gate="C" pin="P2[5]/PWM1[6]/U1_DTR/T2_MAT0/R/TRACEDATA[0]/R/LCD_LP" pad="140"/>
<connect gate="C" pin="P2[6]/PWM1_CAP0/U1_RI/T2_CAP0/U2_OE/TRACECLK/LCD_VD[0]/LCD_VD[4]" pad="138"/>
<connect gate="C" pin="P2[7]/CAN_RD2/U1_RTS/R/LCD_VD[1]/LCD_VD[5]" pad="136"/>
<connect gate="C" pin="P2[8]/CAN_TD2/U2_TXD/U1_CTS/ENET_MDC/R/LCD_VD[2]/LCD_VD[6]" pad="134"/>
<connect gate="C" pin="P2[9]/USB_CONNECT1/U2_RXD/U4_RXD/ENET_MDIO/R/LCD_VD[3]/LCD_VD[7]" pad="132"/>
<connect gate="C" pin="P3[16]/EMC_D[16]/PWM0[1]/U1_TXD" pad="137"/>
<connect gate="C" pin="P3[17]/EMC_D[17]/PWM0[2]/U1_RXD" pad="143"/>
<connect gate="C" pin="P3[18]/EMC_D[18]/PWM0[3]/U1_CTS" pad="151"/>
<connect gate="C" pin="P4[10]/EMC_A[10]" pad="135"/>
<connect gate="C" pin="P4[11]/EMC_A[11]" pad="145"/>
<connect gate="C" pin="P4[12]/EMC_A[12]" pad="149"/>
<connect gate="C" pin="P4[19]/EMC_A[19]" pad="111"/>
<connect gate="C" pin="P4[20]/EMC_A[20]/I2C2_SDA/SSP1_SCK" pad="109"/>
<connect gate="C" pin="P4[21]/EMC_A[21]/I2C2_SCL/SSP1_SSEL" pad="115"/>
<connect gate="C" pin="P4[22]/EMC_A[22]/U2_TXD/SSP1_MISO" pad="123"/>
<connect gate="C" pin="P4[23]/EMC_A[23]/U2_RXD/SSP1_MOSI" pad="129"/>
<connect gate="C" pin="P4[26]/!EMC_BLS0" pad="119"/>
<connect gate="C" pin="P4[27]/!EMC_BLS1" pad="139"/>
<connect gate="C" pin="P4[6]/EMC_A[6]" pad="113"/>
<connect gate="C" pin="P4[7]/EMC_A[7]" pad="121"/>
<connect gate="C" pin="P4[8]/EMC_A[8]" pad="127"/>
<connect gate="C" pin="P4[9]/EMC_A[9]" pad="131"/>
<connect gate="C" pin="P5[2]/R/T3_MAT2/R/I2C0_SDA" pad="117"/>
<connect gate="C" pin="P5[3]/R/U4_RXD/I2C0_SCL" pad="141"/>
<connect gate="C" pin="RTCX1" pad="34"/>
<connect gate="C" pin="RTCX2" pad="36"/>
<connect gate="C" pin="VDD(3V3)" pad="125"/>
<connect gate="C" pin="VDD(3V3)_2" pad="89"/>
<connect gate="C" pin="VDD(3V3)_3" pad="112"/>
<connect gate="C" pin="VDD(REG)(3V3)" pad="86"/>
<connect gate="C" pin="VSS" pad="148"/>
<connect gate="C" pin="VSS_2" pad="169"/>
<connect gate="C" pin="VSS_3" pad="114"/>
<connect gate="C" pin="VSS_4" pad="133"/>
<connect gate="D" pin="!RTC_ALARM" pad="37"/>
<connect gate="D" pin="P0[2]/U0_TXD/U3_TXD" pad="202"/>
<connect gate="D" pin="P0[3]/U0_RXD/U3_RXD" pad="204"/>
<connect gate="D" pin="P0[4]/I2S_RX_SCK/CAN_RD2/T2_CAP0/R/LCD_VD[0]" pad="168"/>
<connect gate="D" pin="P0[5]/I2S_RX_WS/CAN_TD2/T2_CAP1/R/LCD_VD[1]" pad="166"/>
<connect gate="D" pin="P0[6]/I2S_RX_SDA/SSP1_SSEL/T2_MAT0/U1_RTS/R/LCD_VD[8]" pad="164"/>
<connect gate="D" pin="P0[7]/I2S_TX_SCK/SSP1_SCK/T2_MAT1/RTC_EV0/R/LCD_VD[9]" pad="162"/>
<connect gate="D" pin="P0[8]/I2S_TX_WS/SSP1_MISO/T2_MAT2/RTC_EV1/R/LCD_VD[16]" pad="160"/>
<connect gate="D" pin="P0[9]/I2S_TX_SDA/SSP1_MOSI/T2_MAT3/RTC_EV2/R/LCD_VD[17]" pad="158"/>
<connect gate="D" pin="P1[0]/ENET_TXD0/R/T3_CAP1/SSP2_SCK" pad="196"/>
<connect gate="D" pin="P1[10]/ENET_RXD1/R/T3_CAP0" pad="186"/>
<connect gate="D" pin="P1[11]/ENET_RXD2/SD_DAT[2]/PWM0[6]" pad="163"/>
<connect gate="D" pin="P1[12]/ENET_RXD3/SD_DAT[3]/PWM0_CAP0" pad="157"/>
<connect gate="D" pin="P1[14]/ENET_RX_ER/R/T2_CAP0" pad="184"/>
<connect gate="D" pin="P1[15]/ENET_RX_CLK/R/I2C2_SDA" pad="182"/>
<connect gate="D" pin="P1[16]/ENET_MDC/I2S_TX_MCLK" pad="180"/>
<connect gate="D" pin="P1[17]/ENET_MDIO/I2S_RX_MCLK" pad="178"/>
<connect gate="D" pin="P1[1]/ENET_TXD1/R/T3_MAT3/SSP2_MOSI" pad="194"/>
<connect gate="D" pin="P1[2]/ENET_TXD2/SD_CLK/PWM0[1]" pad="185"/>
<connect gate="D" pin="P1[3]/ENET_TXD3/SD_CMD/PWM0[2]" pad="177"/>
<connect gate="D" pin="P1[4]/ENET_TX_EN/R/T3_MAT2/SSP2_MISO" pad="192"/>
<connect gate="D" pin="P1[5]/ENET_TX_ER/SD_PWR/PWM0[3]" pad="156"/>
<connect gate="D" pin="P1[6]/ENET_TX_CLK/SD_DAT[0]/PWM0[4]" pad="171"/>
<connect gate="D" pin="P1[8]/ENET_CRS/R/T3_MAT1/SSP2_SSEL" pad="190"/>
<connect gate="D" pin="P1[9]/ENET_RXD0/R/T3_MAT0" pad="188"/>
<connect gate="D" pin="P2[0]/PWM1[1]/U1_TXD/R/LCD_PWR" pad="154"/>
<connect gate="D" pin="P3[0]/EMC_D[0]" pad="197"/>
<connect gate="D" pin="P3[10]/EMC_D[10]" pad="205"/>
<connect gate="D" pin="P3[11]/EMC_D[11]" pad="208"/>
<connect gate="D" pin="P3[19]/EMC_D[19]/PWM0[4]/U1_DCD" pad="161"/>
<connect gate="D" pin="P3[1]/EMC_D[1]" pad="201"/>
<connect gate="D" pin="P3[20]/EMC_D[20]/PWM0[5]/U1_DSR" pad="167"/>
<connect gate="D" pin="P3[21]/EMC_D[21]/PWM0[6]/U1_DTR" pad="175"/>
<connect gate="D" pin="P3[22]/EMC_D[22]/PWM0_CAP0/U1_RI" pad="195"/>
<connect gate="D" pin="P3[27]/EMC_D[27]/PWM1[3]/T0_MAT1/STCLK" pad="203"/>
<connect gate="D" pin="P3[2]/EMC_D[2]" pad="207"/>
<connect gate="D" pin="P3[8]/EMC_D[8]" pad="191"/>
<connect gate="D" pin="P3[9]/EMC_D[9]" pad="199"/>
<connect gate="D" pin="P4[13]/EMC_A[13]" pad="155"/>
<connect gate="D" pin="P4[14]/EMC_A[14]" pad="159"/>
<connect gate="D" pin="P4[15]/EMC_A[15]" pad="173"/>
<connect gate="D" pin="P4[24]/!EMC_OE" pad="183"/>
<connect gate="D" pin="P4[25]/!EMC_WE" pad="179"/>
<connect gate="D" pin="P4[28]/!EMC_BLS2!/U3_TXD/T2_MAT0/R/LCD_VD[6]/LCD_VD[10]/LCD_VD[2]" pad="170"/>
<connect gate="D" pin="P4[29]/!EMC_BLS3!/U3_RXD/T2_MAT1/I2C2_SCL/LCD_VD[7]/LCD_VD[11]/LCD_VD[3]" pad="176"/>
<connect gate="D" pin="P4[30]/!EMC_CS0" pad="187"/>
<connect gate="D" pin="P4[31]/!EMC_CS1" pad="193"/>
<connect gate="D" pin="P5[4]/U0_OE/R/T3_MAT3/U4_TXD" pad="206"/>
<connect gate="D" pin="VDD(3V3)" pad="165"/>
<connect gate="D" pin="VDD(3V3)_2" pad="146"/>
<connect gate="D" pin="VDD(REG)(3V3)" pad="174"/>
<connect gate="D" pin="VSS" pad="200"/>
<connect gate="D" pin="VSSREG" pad="172"/>
<connect gate="D" pin="VSS_2" pad="189"/>
<connect gate="D" pin="XTAL1" pad="44"/>
<connect gate="D" pin="XTAL2" pad="46"/>
</connects>
<technologies>
<technology name="">
<attribute name="MPN" value="LPC1785FBD208,551" constant="no"/>
<attribute name="OC_FARNELL" value="2094301" constant="no"/>
<attribute name="OC_NEWARK" value="41T4095" constant="no"/>
<attribute name="PACKAGE" value="LQFP-208" constant="no"/>
<attribute name="SUPPLIER" value="NXP" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="XTAL_ABS25-32.768KHZ-T" prefix="X" uservalue="yes">
<description>Frequency	32.768kHz
Frequency Stability	-
Frequency Tolerance	±20ppm
Load Capacitance	12.5pF
ESR (Equivalent Series Resistance)	50 kOhm
Operating Mode	Fundamental
Operating Temperature	-40°C ~ 85°C
Ratings	-
Mounting Type	Surface Mount
Package / Case	4-SOJ, 5.50mm pitch
Size / Dimension	0.315" L x 0.150" W (8.00mm x 3.80mm)
Height	0.098" (2.50mm)</description>
<gates>
<gate name="G$1" symbol="XTAL" x="0" y="0"/>
</gates>
<devices>
<device name="" package="XTAL_ABS25">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$2" pad="4"/>
</connects>
<technologies>
<technology name="">
<attribute name="DIGIKEY_ID" value="535-9166-1-ND" constant="no"/>
<attribute name="MANUFACTURER_ID" value="ABS25-32.768KHZ-T" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="XTAL_7A-20.000MAAJ-T" prefix="X" uservalue="yes">
<description>http://www.farnell.com/datasheets/1041607.pdf

The 7A-20.000MAAJ-T is a 5 x 3.2mm 30ppm surface-mount Quartz Crystal with 2 pads glass sealed. The 7A series features high reliable environmental performance, tight tolerance and stability. Designed for automatic mounting and reflow soldering and portable PC, PDA, DSC and USB interface cards.

    Fundamental operation mode
    50R Maximum equivalent series resistance
    5pF Maximum shunt capacitance
    200µW Maximum drive level

 Crystal Case: SMD, 5mm x 3.2mm
Frequency Nom: 20MHz
Frequency Stability + / -: 30ppm
Frequency Tolerance + / -: 30ppm
Load Capacitance: 18pF
Operating Temperature Max: 85°C
Operating Temperature Min: -40°C
Product Range: 7A Series</description>
<gates>
<gate name="G$1" symbol="XTAL" x="0" y="0"/>
</gates>
<devices>
<device name="" package="XTAL_SMD_5X3.2">
<connects>
<connect gate="G$1" pin="P$1" pad="P$1"/>
<connect gate="G$1" pin="P$2" pad="P$2"/>
</connects>
<technologies>
<technology name="">
<attribute name="FARNELL_ID" value="1841950" constant="no"/>
<attribute name="MANUFACTURER_ID" value="7A-20.000MAAJ-T" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="XTAL_7M-14.31818MAAJ-T" prefix="X" uservalue="yes">
<description>http://www.farnell.com/datasheets/1796637.pdf TXC 7M-14.31818MAAJ-T XTAL, 14.31818MHZ, 18PF,SMD, 3.2X2.5 Crystal Case: SMD, 3.2mm x 2.5mm Frequency Nom: 14.31818MHz Frequency 
Stability + / -: 30ppm Frequency Tolerance + / -: 30ppm Load Capacitance: 18pF Operating Temperature Max: 85°C Operating Temperature Min: -40°C Product Range: 7M Series SVHC: No SVHC (15-Jun-2015</description>
<gates>
<gate name="G$1" symbol="XTAL" x="0" y="0"/>
</gates>
<devices>
<device name="_SMD" package="XTAL_SMD_3.2X2.5">
<connects>
<connect gate="G$1" pin="P$1" pad="P$4"/>
<connect gate="G$1" pin="P$2" pad="P$2"/>
</connects>
<technologies>
<technology name="">
<attribute name="FARNELL_ID" value="1796637" constant="no"/>
<attribute name="MANUFACTURER_ID" value="7M-14.31818MAAJ-T" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="BATTERY_HOLDER_CH7410-2032LF" prefix="BT" uservalue="yes">
<description>http://www.farnell.com/datasheets/1505862.pdf

Surface mount battery holder for 20mm coin cell batteries

    Current Rating: 3A AC/DC
    Voltage Rating: 250V AC/DC
    Contact Resistance: 30mR
    Insulation Resistance: 1000MR
    Temperature Range : -55°C to +85°C


    Battery Holder Mount: SMD
    Battery Sizes Accepted: Coin Cell - 20mm
    Battery Terminals: SMD
    No. of Batteries: 1
    SVHC: No SVHC (15-Jun-2015)
    Terminal Type: SMD</description>
<gates>
<gate name="G$1" symbol="BATTERY_HOLDER_COIN_20MM" x="0" y="-5.08"/>
</gates>
<devices>
<device name="SMD" package="BATTERY_HOLDER_COIN_20MM_SMD">
<connects>
<connect gate="G$1" pin="+" pad="+"/>
<connect gate="G$1" pin="-" pad="-"/>
</connects>
<technologies>
<technology name="">
<attribute name="FARNELL_ID" value="2064724" constant="no"/>
<attribute name="MANUFACTURER_ID" value="CH7410-2032LF" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="DIODE" prefix="D" uservalue="yes">
<gates>
<gate name="G$1" symbol="DIODE" x="0" y="0"/>
</gates>
<devices>
<device name="CYLINDRIC_SMD" package="DIODE">
<connects>
<connect gate="G$1" pin="N" pad="P$2"/>
<connect gate="G$1" pin="P" pad="P$1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="DO219AB" package="DO219AB">
<connects>
<connect gate="G$1" pin="N" pad="P$2"/>
<connect gate="G$1" pin="P" pad="P$1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="DO-214AC" package="DO-214AC">
<connects>
<connect gate="G$1" pin="N" pad="K"/>
<connect gate="G$1" pin="P" pad="A"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="DO41" package="DO-41">
<connects>
<connect gate="G$1" pin="N" pad="N"/>
<connect gate="G$1" pin="P" pad="P"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="LM2671" prefix="VR" uservalue="yes">
<description>TEXAS INSTRUMENTS  LM2671MX-5.0/NOPB  IC, STEP-DOWN REGULATOR, SOIC-8 
http://www.farnell.com/datasheets/1874686.pdf</description>
<gates>
<gate name="G$1" symbol="LM2671" x="-5.08" y="-5.08"/>
</gates>
<devices>
<device name="SOIC8" package="SOIC8">
<connects>
<connect gate="G$1" pin="CB" pad="P$1"/>
<connect gate="G$1" pin="FB" pad="P$4"/>
<connect gate="G$1" pin="GND" pad="P$6"/>
<connect gate="G$1" pin="ON/OFF" pad="P$5"/>
<connect gate="G$1" pin="SS" pad="P$2"/>
<connect gate="G$1" pin="SYNC" pad="P$3"/>
<connect gate="G$1" pin="VIN" pad="P$7"/>
<connect gate="G$1" pin="VSW" pad="P$8"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="CAP_POL" prefix="C" uservalue="yes">
<gates>
<gate name="G$1" symbol="CAP_POLY" x="0" y="0"/>
</gates>
<devices>
<device name="0603" package="0603">
<connects>
<connect gate="G$1" pin="+" pad="0"/>
<connect gate="G$1" pin="-" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="SMD_6.3X7.7_MM" package="CAP_SMD_6.3X7.7_MM">
<connects>
<connect gate="G$1" pin="+" pad="P$1"/>
<connect gate="G$1" pin="-" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="TH_5.3MM" package="CAP_POLY_5.3MM">
<connects>
<connect gate="G$1" pin="+" pad="P$2"/>
<connect gate="G$1" pin="-" pad="P$1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="SMD_10X10X10MM" package="CAP_POL_SMD_10X10X10MM">
<connects>
<connect gate="G$1" pin="+" pad="+"/>
<connect gate="G$1" pin="-" pad="-"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="INDUCTOR" prefix="L" uservalue="yes">
<gates>
<gate name="G$1" symbol="INDUCTOR" x="0" y="0"/>
</gates>
<devices>
<device name="_1210" package="1210">
<connects>
<connect gate="G$1" pin="P$1" pad="P$1"/>
<connect gate="G$1" pin="P$2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="BOURNS_10X13X5MM" package="INDUCTOR_BOURNS_10X13X5MM">
<connects>
<connect gate="G$1" pin="P$1" pad="P$1"/>
<connect gate="G$1" pin="P$2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_0603" package="0603_SILKSCREEN">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="PIEZO_SOUNDER" prefix="Y" uservalue="yes">
<description>MURATA  PKM13EPYH4002-B0  PIEZO SOUNDER
Transducer Function:Sounder; Tones:Continuous; Supply Voltage Min:-; Supply Voltage Max:30V; Operating Current Max:-; Sound Level SPL:70dB; Sound Level Distance:10cm; Resonant Frequency:-; SVHC:Lead titani
http://www.farnell.com/datasheets/579045.pdf</description>
<gates>
<gate name="G$1" symbol="XTAL" x="0" y="0"/>
</gates>
<devices>
<device name="_MURATA" package="PIEZO_SOUNDER_MURATA">
<connects>
<connect gate="G$1" pin="P$1" pad="P$1"/>
<connect gate="G$1" pin="P$2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="USB" prefix="J" uservalue="yes">
<gates>
<gate name="G$1" symbol="USB" x="5.08" y="0"/>
</gates>
<devices>
<device name="_B_RECEPTACLE_SMD" package="USB_MINI_B">
<connects>
<connect gate="G$1" pin="D+" pad="D+"/>
<connect gate="G$1" pin="D-" pad="D-"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="SHLD" pad="SHLD"/>
<connect gate="G$1" pin="SHLD@2" pad="SHLD@1"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_A_RECEPTACLE_TH_VERT" package="USB_A_RECEPTACLE_VERTICAL_MULTICOMP">
<connects>
<connect gate="G$1" pin="D+" pad="P$3"/>
<connect gate="G$1" pin="D-" pad="P$2"/>
<connect gate="G$1" pin="GND" pad="P$4"/>
<connect gate="G$1" pin="SHLD" pad="P$5"/>
<connect gate="G$1" pin="SHLD@2" pad="P$6"/>
<connect gate="G$1" pin="VCC" pad="P$1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="KENTEC_TFT_LCD_4.3_INCH" prefix="DS" uservalue="yes">
<gates>
<gate name="G$1" symbol="HEADER_KENTEK_LCD_4.3_INCH" x="-2.54" y="-5.08"/>
</gates>
<devices>
<device name="SMD" package="HEADER_KENTEC_TFT_LCD_4.3_INCH">
<connects>
<connect gate="G$1" pin="B0" pad="P$21"/>
<connect gate="G$1" pin="B1" pad="P$22"/>
<connect gate="G$1" pin="B2" pad="P$23"/>
<connect gate="G$1" pin="B3" pad="P$24"/>
<connect gate="G$1" pin="B4" pad="P$25"/>
<connect gate="G$1" pin="B5" pad="P$26"/>
<connect gate="G$1" pin="B6" pad="P$27"/>
<connect gate="G$1" pin="B7" pad="P$28"/>
<connect gate="G$1" pin="DCLK" pad="P$30"/>
<connect gate="G$1" pin="DE" pad="P$34"/>
<connect gate="G$1" pin="DISP" pad="P$31"/>
<connect gate="G$1" pin="G0" pad="P$13"/>
<connect gate="G$1" pin="G1" pad="P$14"/>
<connect gate="G$1" pin="G2" pad="P$15"/>
<connect gate="G$1" pin="G3" pad="P$16"/>
<connect gate="G$1" pin="G4" pad="P$17"/>
<connect gate="G$1" pin="G5" pad="P$18"/>
<connect gate="G$1" pin="G6" pad="P$19"/>
<connect gate="G$1" pin="G7" pad="P$20"/>
<connect gate="G$1" pin="GND" pad="P$3"/>
<connect gate="G$1" pin="GND@2" pad="P$29"/>
<connect gate="G$1" pin="GND@3" pad="P$36"/>
<connect gate="G$1" pin="HSYNC" pad="P$32"/>
<connect gate="G$1" pin="NC" pad="P$35"/>
<connect gate="G$1" pin="R0" pad="P$5"/>
<connect gate="G$1" pin="R1" pad="P$6"/>
<connect gate="G$1" pin="R2" pad="P$7"/>
<connect gate="G$1" pin="R3" pad="P$8"/>
<connect gate="G$1" pin="R4" pad="P$9"/>
<connect gate="G$1" pin="R5" pad="P$10"/>
<connect gate="G$1" pin="R6" pad="P$11"/>
<connect gate="G$1" pin="R7" pad="P$12"/>
<connect gate="G$1" pin="SHD" pad="P$41"/>
<connect gate="G$1" pin="SHD@2" pad="P$42"/>
<connect gate="G$1" pin="VDD" pad="P$4"/>
<connect gate="G$1" pin="VLED+" pad="P$2"/>
<connect gate="G$1" pin="VLED-" pad="P$1"/>
<connect gate="G$1" pin="VSYNC" pad="P$33"/>
<connect gate="G$1" pin="X_L" pad="P$39"/>
<connect gate="G$1" pin="X_R" pad="P$37"/>
<connect gate="G$1" pin="Y_B" pad="P$38"/>
<connect gate="G$1" pin="Y_T" pad="P$40"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="NPN_TRANSISTOR" prefix="Q" uservalue="yes">
<description>http://www.farnell.com/datasheets/1697409.pdf
9294511</description>
<gates>
<gate name="G$1" symbol="NPN_TRANSISTOR" x="0" y="2.54"/>
</gates>
<devices>
<device name="TO-220" package="TO-220">
<connects>
<connect gate="G$1" pin="B" pad="LEFT"/>
<connect gate="G$1" pin="C" pad="MIDDLE"/>
<connect gate="G$1" pin="E" pad="RIGHT"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="SOT323" package="SOT323">
<connects>
<connect gate="G$1" pin="B" pad="L"/>
<connect gate="G$1" pin="C" pad="M"/>
<connect gate="G$1" pin="E" pad="R"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="FUSE" prefix="F" uservalue="yes">
<gates>
<gate name="G$1" symbol="FUSE" x="0" y="0"/>
</gates>
<devices>
<device name="_MAXI" package="FUSE_MAXI">
<connects>
<connect gate="G$1" pin="P$1" pad="P$1"/>
<connect gate="G$1" pin="P$2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_RESETABLE" package="FUSE_RESETABLE">
<connects>
<connect gate="G$1" pin="P$1" pad="P$1"/>
<connect gate="G$1" pin="P$2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_1812" package="1812">
<connects>
<connect gate="G$1" pin="P$1" pad="P$1"/>
<connect gate="G$1" pin="P$2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_100MA" package="FUSE_100MA">
<connects>
<connect gate="G$1" pin="P$1" pad="P$1"/>
<connect gate="G$1" pin="P$2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_300MA" package="MULTICOMP_MC36211">
<connects>
<connect gate="G$1" pin="P$1" pad="P$1"/>
<connect gate="G$1" pin="P$2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="HEADER_USART_2" prefix="J" uservalue="yes">
<gates>
<gate name="G$1" symbol="HEADER_USART_2" x="-2.54" y="2.54"/>
</gates>
<devices>
<device name="_TH" package="HEADER_USART_2_TH">
<connects>
<connect gate="G$1" pin="+5V" pad="P$5"/>
<connect gate="G$1" pin="+5V@1" pad="P$4"/>
<connect gate="G$1" pin="GND" pad="P$7"/>
<connect gate="G$1" pin="GND@1" pad="P$2"/>
<connect gate="G$1" pin="RX" pad="P$1"/>
<connect gate="G$1" pin="RX@1" pad="P$8"/>
<connect gate="G$1" pin="TX" pad="P$3"/>
<connect gate="G$1" pin="TX@1" pad="P$6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_SMD" package="HEADER_4_2_SMD">
<connects>
<connect gate="G$1" pin="+5V" pad="P$5"/>
<connect gate="G$1" pin="+5V@1" pad="P$4"/>
<connect gate="G$1" pin="GND" pad="P$7"/>
<connect gate="G$1" pin="GND@1" pad="P$2"/>
<connect gate="G$1" pin="RX" pad="P$1"/>
<connect gate="G$1" pin="RX@1" pad="P$8"/>
<connect gate="G$1" pin="TX" pad="P$3"/>
<connect gate="G$1" pin="TX@1" pad="P$6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="ALLIANCE_AS4C4M16SA" prefix="U" uservalue="yes">
<description>http://www.alliancememory.com/pdf/dram/64M-AS4C4M16SA-AUTOMOTIVE.pdf

Category	Integrated Circuits (ICs)
Family	Memory
Series	-
Packaging ? 	Tray ? 
Format - Memory	RAM
Memory Type	SDRAM
Memory Size	64M (4M x 16)
Speed	166MHz
Interface	Parallel
Voltage - Supply	3 V ~ 3.6 V
Operating Temperature	-40°C ~ 105°C
Package / Case	54-TSOP (0.400", 10.16mm Width)
Supplier Device Package	54-TSOP II
Other Names	1450-1154
AS4C4M16S-6TAN-ND</description>
<gates>
<gate name="G$1" symbol="ALLIANCE_AS4C4M16SA" x="2.54" y="5.08"/>
</gates>
<devices>
<device name="_TSOP_II" package="TSOP_II_54_PIN">
<connects>
<connect gate="G$1" pin="!CAS" pad="P$17"/>
<connect gate="G$1" pin="!CS" pad="P$19"/>
<connect gate="G$1" pin="!RAS" pad="P$18"/>
<connect gate="G$1" pin="!WE" pad="P$16"/>
<connect gate="G$1" pin="A0" pad="P$23"/>
<connect gate="G$1" pin="A1" pad="P$24"/>
<connect gate="G$1" pin="A10/AP" pad="P$22"/>
<connect gate="G$1" pin="A11" pad="P$35"/>
<connect gate="G$1" pin="A2" pad="P$25"/>
<connect gate="G$1" pin="A3" pad="P$26"/>
<connect gate="G$1" pin="A4" pad="P$29"/>
<connect gate="G$1" pin="A5" pad="P$30"/>
<connect gate="G$1" pin="A6" pad="P$31"/>
<connect gate="G$1" pin="A7" pad="P$32"/>
<connect gate="G$1" pin="A8" pad="P$33"/>
<connect gate="G$1" pin="A9" pad="P$34"/>
<connect gate="G$1" pin="BA0" pad="P$20"/>
<connect gate="G$1" pin="BA1" pad="P$21"/>
<connect gate="G$1" pin="CKE" pad="P$37"/>
<connect gate="G$1" pin="CLK" pad="P$38"/>
<connect gate="G$1" pin="DQ0" pad="P$2"/>
<connect gate="G$1" pin="DQ1" pad="P$4"/>
<connect gate="G$1" pin="DQ10" pad="P$45"/>
<connect gate="G$1" pin="DQ11" pad="P$47"/>
<connect gate="G$1" pin="DQ12" pad="P$48"/>
<connect gate="G$1" pin="DQ13" pad="P$50"/>
<connect gate="G$1" pin="DQ14" pad="P$51"/>
<connect gate="G$1" pin="DQ15" pad="P$53"/>
<connect gate="G$1" pin="DQ2" pad="P$5"/>
<connect gate="G$1" pin="DQ3" pad="P$7"/>
<connect gate="G$1" pin="DQ4" pad="P$8"/>
<connect gate="G$1" pin="DQ5" pad="P$10"/>
<connect gate="G$1" pin="DQ6" pad="P$11"/>
<connect gate="G$1" pin="DQ7" pad="P$13"/>
<connect gate="G$1" pin="DQ8" pad="P$42"/>
<connect gate="G$1" pin="DQ9" pad="P$44"/>
<connect gate="G$1" pin="LDQM" pad="P$15"/>
<connect gate="G$1" pin="NC" pad="P$36"/>
<connect gate="G$1" pin="NC/RFU" pad="P$40"/>
<connect gate="G$1" pin="UDQM" pad="P$39"/>
<connect gate="G$1" pin="VDD" pad="P$1"/>
<connect gate="G$1" pin="VDD@2" pad="P$14"/>
<connect gate="G$1" pin="VDD@3" pad="P$27"/>
<connect gate="G$1" pin="VDDQ" pad="P$3"/>
<connect gate="G$1" pin="VDDQ@2" pad="P$9"/>
<connect gate="G$1" pin="VDDQ@3" pad="P$43"/>
<connect gate="G$1" pin="VDDQ@4" pad="P$49"/>
<connect gate="G$1" pin="VSS" pad="P$28"/>
<connect gate="G$1" pin="VSS@2" pad="P$41"/>
<connect gate="G$1" pin="VSS@3" pad="P$54"/>
<connect gate="G$1" pin="VSSQ" pad="P$6"/>
<connect gate="G$1" pin="VSSQ@2" pad="P$12"/>
<connect gate="G$1" pin="VSSQ@3" pad="P$46"/>
<connect gate="G$1" pin="VSSQ@4" pad="P$52"/>
</connects>
<technologies>
<technology name="">
<attribute name="DIGIKEY_ID" value="1450-1154-ND" constant="no"/>
<attribute name="MANUFACTURER_ID" value="AS4C4M16S-6TAN" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="MCP2551" prefix="U" uservalue="yes">
<description>Microchip High-Speed CAN
 Transceiver
Supports 1 Mb/s operation
•  Implements ISO-11898 standard physical layer 
requirements
•  Suitable for 12V and 24V systems
•  Externally-controlled slope for reduced RFI        
emissions
•  Detection of ground fault (permanent dominant) 
on TXD input
•  Power-on reset and voltage brown-out protection
•  An unpowered node or brown-out event will not   
disturb the CAN bus
•  Low current standby operation
•  Protection against damage due to short-circuit    
conditions (positive or negative battery voltage)
•  Protection against high-voltage transients
•  Automatic thermal shutdown protection
•  Up to 112 nodes can be connected
•  High noise immunity due to differential bus        
implementation
•  Temperature ranges:
-  Industrial (I): -40°C to +85°C
-  Extended (E): -40°C to +125°C


http://www.digikey.com/product-detail/en/MCP2551T-E%2FSN/MCP2551T-E%2FSNCT-ND/4307904
http://ww1.microchip.com/downloads/en/DeviceDoc/21667f.pdf
http://www.farnell.com/datasheets/657417.pdf
http://fi.farnell.com/microchip/mcp2551-i-sn/ic-can-transceiver-hi-speed-smd/dp/9758569</description>
<gates>
<gate name="G$1" symbol="MCP2551" x="-10.16" y="0"/>
</gates>
<devices>
<device name="_SOIC8" package="SOIC8">
<connects>
<connect gate="G$1" pin="CANH" pad="P$7"/>
<connect gate="G$1" pin="CANL" pad="P$6"/>
<connect gate="G$1" pin="RS" pad="P$8"/>
<connect gate="G$1" pin="RXD" pad="P$4"/>
<connect gate="G$1" pin="TXD" pad="P$1"/>
<connect gate="G$1" pin="VDD" pad="P$3"/>
<connect gate="G$1" pin="VREF" pad="P$5"/>
<connect gate="G$1" pin="VSS" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="HEADER12" uservalue="yes">
<gates>
<gate name="G$1" symbol="HEADER12" x="-2.54" y="0"/>
</gates>
<devices>
<device name="_MX120G" package="MOLEX_MX120G">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$10" pad="10"/>
<connect gate="G$1" pin="P$11" pad="11"/>
<connect gate="G$1" pin="P$12" pad="12"/>
<connect gate="G$1" pin="P$2" pad="2"/>
<connect gate="G$1" pin="P$3" pad="3"/>
<connect gate="G$1" pin="P$4" pad="4"/>
<connect gate="G$1" pin="P$5" pad="5"/>
<connect gate="G$1" pin="P$6" pad="6"/>
<connect gate="G$1" pin="P$7" pad="7"/>
<connect gate="G$1" pin="P$8" pad="8"/>
<connect gate="G$1" pin="P$9" pad="9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="WINDBOND_W25Q32FV" prefix="U" uservalue="yes">
<description>http://www.winbond.com/resource-files/w25q32fv%20revh%20091613.pdf

Photos	8-SOIC
EDA / CAD Models ? 	Download from Accelerated Designs
Standard Package ? 	90
Category	Integrated Circuits (ICs)
Family	Memory
Series	SpiFlash®
Packaging ? 	Tube ? 
Format - Memory	FLASH
Memory Type	FLASH - NOR
Memory Size	32M (4M x 8)
Speed	104MHz
Interface	SPI Serial
Voltage - Supply	2.7 V ~ 3.6 V
Operating Temperature	-40°C ~ 85°C</description>
<gates>
<gate name="G$1" symbol="WINDBOND_W25Q32FV" x="15.24" y="-7.62"/>
</gates>
<devices>
<device name="_SOIC8" package="SOIC8">
<connects>
<connect gate="G$1" pin="!CS" pad="P$1"/>
<connect gate="G$1" pin="!RESET!/IO3" pad="P$7"/>
<connect gate="G$1" pin="!WP!/IO2" pad="P$3"/>
<connect gate="G$1" pin="CLK" pad="P$6"/>
<connect gate="G$1" pin="DI/IO0" pad="P$5"/>
<connect gate="G$1" pin="DO/IO1" pad="P$2"/>
<connect gate="G$1" pin="GND" pad="P$4"/>
<connect gate="G$1" pin="VCC" pad="P$8"/>
</connects>
<technologies>
<technology name="">
<attribute name="DIGIKEY_ID" value="W25Q32FVSSIG-ND" constant="no"/>
<attribute name="MANUFACTURER_ID" value="W25Q32FVSSIG" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="TI_TVP5150AM1" prefix="U" uservalue="yes">
<description>TVP5150AM1
http://www.ti.com/lit/ds/symlink/tvp5150am1.pdf
Standard
Programmable
Video
Output
Formats
M,
N,
Nc),
and
SECAM
(B,
D,
G,
K,
K1,
L)
Video
–
ITU-R
BT.656,
8-Bit
4:2:2
With
Embedded
•
Supports
ITU-R
BT.601
Standard
Sampling
Syncs
•
High-Speed
9-Bit
Analog-to-Digital
Converter
–
8-Bit
4:2:2
With
Discrete
Syncs
(ADC)
•
Macrovision
™
Copy
Protection
Detection
•
Two
Composite
Inputs
or
One
S-Video
Input
•
Advanced
Programmable
Video
Output
•
Fully
Differential
CMOS
Analog
Preprocessing
Formats
Channels
With
Clamping
and
Automatic
Gain
–
2
×
Oversampled
Raw
Vertical
Blanking
Control
(AGC)
for
Best
Signal-to-Noise
(S/N)
Interval
(VBI)
Data
During
Active
Video
Performance
–
Sliced
VBI
Data
During
Horizontal
Blanking
•
Ultralow
Power
Consumption
or
Active
Video
•
48-Terminal
PBGA
Package
(ZQC)
or
•
VBI
Modes
Supported
32-Terminal
TQFP
Package
(PBS)
–
Teletext
(NABTS,
WST)
•
Power-Down
Mode:
&lt;
1
mW
–
Closed-Caption
Decode
With
FIFO
and
•
Brightness,
Contrast,
Saturation,
Hue,
and
Extended
Data
Services
(XDS)
Sharpness
Control
Through
I
2
C
–
Wide
Screen
Signaling,
Video
Program
•
Complementary
4-Line
(3-H
Delay)
Adaptive
System,
CGMS-A,
Vertical
Interval
Time
Comb
Filters
for
Both
Cross-Luminance
and
Code
Cross-Chrominance
Noise
Reduction
–
Gemstar
1x/2x
Electronic
Program
Guide
•
Patented
Architecture
for
Locking
to
Weak,
Compatible
Mode
Noisy,
or
Unstable
Signals
–
Custom
Configuration
Mode
That
Allows
•
Single
14.31818-MHz
Crystal
for
All
Standards
User
to
Program
Slice
Engine
for
Unique
VBI
•
Internal
Phase-Locked
Loop
(PLL)
for
Data
Signals
Line-Locked
Clock
and
Sampling
•
Power-On
Reset
•
Subcarrier
Genlock
Output
for
Synchronizing
•
Industrial
Temperature
Range
Color
Subcarrier
of
External
Encoder
(TVP5150AM1I):
–
40
°
C
to
85
°
C
•
3.3-V
Digital
I/O
Supply
Voltage
Range
•
Qualified
for
Automotive
Applications
(AEC-Q100
Rev
G
–
TVP5150AM1IPBSQ1,
TVP5150AM1IPBSRQ)</description>
<gates>
<gate name="G$1" symbol="TI_TVP5150AM1" x="-2.54" y="5.08"/>
</gates>
<devices>
<device name="_QFP32" package="QFP32">
<connects>
<connect gate="G$1" pin="AGND" pad="P$7"/>
<connect gate="G$1" pin="AIP1A" pad="P$1"/>
<connect gate="G$1" pin="AIP1B" pad="P$2"/>
<connect gate="G$1" pin="AVID" pad="P$26"/>
<connect gate="G$1" pin="CH_AGND" pad="P$31"/>
<connect gate="G$1" pin="CH_AVDD" pad="P$32"/>
<connect gate="G$1" pin="DGND" pad="P$19"/>
<connect gate="G$1" pin="DVDD" pad="P$20"/>
<connect gate="G$1" pin="FID/GLCO" pad="P$23"/>
<connect gate="G$1" pin="HSYNC" pad="P$25"/>
<connect gate="G$1" pin="INTREQ/GPCL/VBLK" pad="P$27"/>
<connect gate="G$1" pin="IO_DVDD" pad="P$10"/>
<connect gate="G$1" pin="PDN" pad="P$28"/>
<connect gate="G$1" pin="PLL_AGND" pad="P$3"/>
<connect gate="G$1" pin="PLL_AVDD" pad="P$4"/>
<connect gate="G$1" pin="REFM" pad="P$30"/>
<connect gate="G$1" pin="REFP" pad="P$29"/>
<connect gate="G$1" pin="RESETB" pad="P$8"/>
<connect gate="G$1" pin="SCL" pad="P$21"/>
<connect gate="G$1" pin="SCLK" pad="P$9"/>
<connect gate="G$1" pin="SDA" pad="P$22"/>
<connect gate="G$1" pin="VSYNC/PALI" pad="P$24"/>
<connect gate="G$1" pin="XTAL1/OSC" pad="P$5"/>
<connect gate="G$1" pin="XTAL2" pad="P$6"/>
<connect gate="G$1" pin="YOUT0" pad="P$18"/>
<connect gate="G$1" pin="YOUT1" pad="P$17"/>
<connect gate="G$1" pin="YOUT2" pad="P$16"/>
<connect gate="G$1" pin="YOUT3" pad="P$15"/>
<connect gate="G$1" pin="YOUT4" pad="P$14"/>
<connect gate="G$1" pin="YOUT5" pad="P$13"/>
<connect gate="G$1" pin="YOUT6" pad="P$12"/>
<connect gate="G$1" pin="YOUT7/I2CSEL" pad="P$11"/>
</connects>
<technologies>
<technology name="">
<attribute name="DIGIKEY_ID" value="296-17016-1-ND" constant="no"/>
<attribute name="FARNELL_ID" value="8462038" constant="no"/>
<attribute name="MANUFACTURER_ID" value="TVP5150AM1PBS" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="MICREL_MIC5247-1.8YM5" uservalue="yes">
<description>MICREL SEMICONDUCTOR  MIC5247-1.8YM5 TR  V REG, 2.7-6V, 0.15A, 1.8V, 2%, 5SOT23 

http://www.farnell.com/datasheets/1670792.pdf

 Input Voltage Max: 6V
Input Voltage Min: 2.7V
Linear Regulator Case Style: SOT-23
MSL: MSL 3 - 168 hours
No. of Pins: 5
Operating Temperature Max: 125°C
Operating Temperature Min: -40°C
Output Current: 150mA
Output Voltage Nom.: 1.8V</description>
<gates>
<gate name="G$1" symbol="MICREL_MIC5247-1.8YM5" x="0" y="0"/>
</gates>
<devices>
<device name="_SOT23-5" package="SOT-23">
<connects>
<connect gate="G$1" pin="BYP" pad="P$4"/>
<connect gate="G$1" pin="EN" pad="P$3"/>
<connect gate="G$1" pin="GND" pad="P$2"/>
<connect gate="G$1" pin="IN" pad="P$1"/>
<connect gate="G$1" pin="OUT" pad="P$5"/>
</connects>
<technologies>
<technology name="">
<attribute name="FARNELL_ID" value="2219070" constant="no"/>
<attribute name="MANUFACTURER_ID" value="MIC5247-1.8YM5 TR" constant="no"/>
</technology>
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
<part name="FRAME1" library="frames" deviceset="A5L-LOC" device=""/>
<part name="GND1" library="supply1" deviceset="GND" device=""/>
<part name="GND2" library="supply1" deviceset="GND" device=""/>
<part name="P+3" library="supply1" deviceset="+5V" device=""/>
<part name="+3V1" library="supply1" deviceset="+3V3" device=""/>
<part name="F1" library="usevolt" deviceset="FUSE" device="_300MA" value="500mA"/>
<part name="D1" library="arm" deviceset="DIODE_TVS" device="DO-214AA"/>
<part name="C7" library="usevolt" deviceset="CAP" device="_0603" value="1u"/>
<part name="VR2" library="arm" deviceset="LP2985" device="SOP5" value="LIN_REG_3V3"/>
<part name="R22" library="usevolt" deviceset="RES" device="_0603" value="430"/>
<part name="D2" library="usevolt" deviceset="LED" device="_0603" value="LED"/>
<part name="GND3" library="supply1" deviceset="GND" device=""/>
<part name="FRAME2" library="frames" deviceset="A4L-LOC" device=""/>
<part name="U1" library="usevolt" deviceset="LPC1785FBD208,551" device="QFP50" value="LPC1785"/>
<part name="FRAME3" library="frames" deviceset="A4L-LOC" device=""/>
<part name="FRAME4" library="frames" deviceset="A4L-LOC" device=""/>
<part name="FRAME5" library="frames" deviceset="A4L-LOC" device=""/>
<part name="+3V2" library="supply1" deviceset="+3V3" device=""/>
<part name="C3" library="usevolt" deviceset="CAP" device="_0603" value="100nF"/>
<part name="C4" library="usevolt" deviceset="CAP" device="_0603" value="100nF"/>
<part name="GND4" library="supply1" deviceset="GND" device=""/>
<part name="X1" library="usevolt" deviceset="XTAL_7A-20.000MAAJ-T" device="" value="20MHz"/>
<part name="C5" library="usevolt" deviceset="CAP" device="_0603" value="15pF"/>
<part name="C6" library="usevolt" deviceset="CAP" device="_0603" value="15pF"/>
<part name="+3V4" library="supply1" deviceset="+3V3" device=""/>
<part name="GND5" library="supply1" deviceset="GND" device=""/>
<part name="C8" library="usevolt" deviceset="CAP" device="_0603" value="100nF"/>
<part name="C9" library="usevolt" deviceset="CAP" device="_0603" value="100nF"/>
<part name="C10" library="usevolt" deviceset="CAP" device="_0603" value="100nF"/>
<part name="C11" library="usevolt" deviceset="CAP" device="_0603" value="100nF"/>
<part name="+3V5" library="supply1" deviceset="+3V3" device=""/>
<part name="GND6" library="supply1" deviceset="GND" device=""/>
<part name="C12" library="usevolt" deviceset="CAP" device="_0603" value="100nF"/>
<part name="C13" library="usevolt" deviceset="CAP" device="_0603" value="100nF"/>
<part name="C14" library="usevolt" deviceset="CAP" device="_0603" value="100nF"/>
<part name="C15" library="usevolt" deviceset="CAP" device="_0603" value="100nF"/>
<part name="C16" library="usevolt" deviceset="CAP" device="_0603" value="100nF"/>
<part name="C17" library="usevolt" deviceset="CAP" device="_0603" value="100nF"/>
<part name="C18" library="usevolt" deviceset="CAP" device="_0603" value="100nF"/>
<part name="GND7" library="supply1" deviceset="GND" device=""/>
<part name="+3V6" library="supply1" deviceset="+3V3" device=""/>
<part name="GND8" library="supply1" deviceset="GND" device=""/>
<part name="BT1" library="usevolt" deviceset="BATTERY_HOLDER_CH7410-2032LF" device="SMD" value="BAT"/>
<part name="+3V7" library="supply1" deviceset="+3V3" device=""/>
<part name="GND9" library="supply1" deviceset="GND" device=""/>
<part name="J2" library="arm" deviceset="ARM_JTAG/SWD_HEADER_10_PIN" device="SMD" value="SWD"/>
<part name="R2" library="usevolt" deviceset="RES" device="_0603" value="10k"/>
<part name="R3" library="usevolt" deviceset="RES" device="_0603" value="10k"/>
<part name="R4" library="usevolt" deviceset="RES" device="_0603" value="10k"/>
<part name="X2" library="usevolt" deviceset="XTAL_ABS25-32.768KHZ-T" device="" value="34.768kHz"/>
<part name="C19" library="usevolt" deviceset="CAP" device="_0603" value="12pF"/>
<part name="C20" library="usevolt" deviceset="CAP" device="_0603" value="12pF"/>
<part name="GND10" library="supply1" deviceset="GND" device=""/>
<part name="C1" library="usevolt" deviceset="CAP" device="_0603" value="100n"/>
<part name="VR1" library="usevolt" deviceset="LM2671" device="SOIC8" value="SWITCH_REG_5V"/>
<part name="C2" library="usevolt" deviceset="CAP_POL" device="SMD_10X10X10MM" value="100 uF"/>
<part name="D23" library="usevolt" deviceset="DIODE" device="DO219AB"/>
<part name="L1" library="usevolt" deviceset="INDUCTOR" device="BOURNS_10X13X5MM" value="100 uH"/>
<part name="C21" library="usevolt" deviceset="CAP" device="_0603" value="10nF"/>
<part name="C22" library="usevolt" deviceset="CAP_POL" device="SMD_10X10X10MM" value="100 uF"/>
<part name="GND11" library="supply1" deviceset="GND" device=""/>
<part name="P+1" library="supply1" deviceset="+5V" device=""/>
<part name="P+2" library="supply1" deviceset="+5V" device=""/>
<part name="GND12" library="supply1" deviceset="GND" device=""/>
<part name="Y1" library="usevolt" deviceset="PIEZO_SOUNDER" device="_MURATA" value="BUZZER"/>
<part name="GND13" library="supply1" deviceset="GND" device=""/>
<part name="J4" library="usevolt" deviceset="USB" device="_A_RECEPTACLE_TH_VERT" value="USB"/>
<part name="D3" library="usevolt" deviceset="DIODE" device="DO219AB"/>
<part name="P+4" library="supply1" deviceset="+5V" device=""/>
<part name="GND14" library="supply1" deviceset="GND" device=""/>
<part name="C24" library="usevolt" deviceset="CAP" device="_0603" value="100n"/>
<part name="R10" library="usevolt" deviceset="RES" device="_0603" value="1M"/>
<part name="R11" library="usevolt" deviceset="RES" device="_0603" value="470"/>
<part name="D4" library="usevolt" deviceset="LED" device="_0603" value="LED"/>
<part name="GND15" library="supply1" deviceset="GND" device=""/>
<part name="DS1" library="usevolt" deviceset="KENTEC_TFT_LCD_4.3_INCH" device="SMD"/>
<part name="Q1" library="usevolt" deviceset="NPN_TRANSISTOR" device="SOT323"/>
<part name="P+5" library="supply1" deviceset="VCC" device=""/>
<part name="P+6" library="supply1" deviceset="VCC" device=""/>
<part name="R12" library="usevolt" deviceset="RES" device="_0603" value="1k"/>
<part name="GND16" library="supply1" deviceset="GND" device=""/>
<part name="+3V3" library="supply1" deviceset="+3V3" device=""/>
<part name="GND17" library="supply1" deviceset="GND" device=""/>
<part name="J5" library="usevolt" deviceset="HEADER_USART_2" device="_SMD" value="UART"/>
<part name="U3" library="usevolt" deviceset="ALLIANCE_AS4C4M16SA" device="_TSOP_II" value="AS4C4M16SA"/>
<part name="+3V8" library="supply1" deviceset="+3V3" device=""/>
<part name="+3V9" library="supply1" deviceset="+3V3" device=""/>
<part name="GND18" library="supply1" deviceset="GND" device=""/>
<part name="GND19" library="supply1" deviceset="GND" device=""/>
<part name="U2" library="usevolt" deviceset="MCP2551" device="_SOIC8" value="MCP2551"/>
<part name="U$2" library="usevolt" deviceset="HEADER12" device="_MX120G" value="MX120G"/>
<part name="U4" library="usevolt" deviceset="WINDBOND_W25Q32FV" device="_SOIC8" value="W25Q32FV"/>
<part name="+3V10" library="supply1" deviceset="+3V3" device=""/>
<part name="GND20" library="supply1" deviceset="GND" device=""/>
<part name="C23" library="usevolt" deviceset="CAP" device="_0603" value="100nF"/>
<part name="R1" library="usevolt" deviceset="RES" device="_0603" value="1k"/>
<part name="U6" library="usevolt" deviceset="TI_TVP5150AM1" device="_QFP32" value="TVP5150AM1"/>
<part name="GND21" library="supply1" deviceset="GND" device=""/>
<part name="+3V11" library="supply1" deviceset="+3V3" device=""/>
<part name="FRAME6" library="frames" deviceset="A4L-LOC" device=""/>
<part name="U5" library="usevolt" deviceset="MICREL_MIC5247-1.8YM5" device="_SOT23-5" value="MIC5247-1.8YM5"/>
<part name="P+7" library="supply1" deviceset="+5V" device=""/>
<part name="P+8" library="supply1" deviceset="V+" device=""/>
<part name="GND22" library="supply1" deviceset="GND" device=""/>
<part name="P+9" library="supply1" deviceset="V+" device=""/>
<part name="C25" library="usevolt" deviceset="CAP" device="_0603" value="100n"/>
<part name="C26" library="usevolt" deviceset="CAP" device="_0603" value="100n"/>
<part name="C27" library="usevolt" deviceset="CAP" device="_0603" value="100n"/>
<part name="GND23" library="supply1" deviceset="GND" device=""/>
<part name="GND24" library="supply1" deviceset="GND" device=""/>
<part name="GND25" library="supply1" deviceset="GND" device=""/>
<part name="X3" library="usevolt" deviceset="XTAL_7M-14.31818MAAJ-T" device="_SMD" value="14.31MHz"/>
<part name="C29" library="usevolt" deviceset="CAP" device="_0603" value="15pF"/>
<part name="C30" library="usevolt" deviceset="CAP" device="_0603" value="15pF"/>
<part name="C31" library="usevolt" deviceset="CAP" device="_0603" value="100n"/>
<part name="C32" library="usevolt" deviceset="CAP" device="_0603" value="100n"/>
<part name="C33" library="usevolt" deviceset="CAP" device="_0603" value="100n"/>
<part name="R9" library="usevolt" deviceset="RES" device="_0603" value="37.4"/>
<part name="R13" library="usevolt" deviceset="RES" device="_0603" value="37.4"/>
<part name="D5" library="usevolt" deviceset="DIODE" device="DO219AB"/>
<part name="D6" library="usevolt" deviceset="DIODE" device="DO219AB"/>
<part name="P+10" library="supply1" deviceset="V+" device=""/>
<part name="C28" library="usevolt" deviceset="CAP" device="_0603" value="1u"/>
<part name="C34" library="usevolt" deviceset="CAP" device="_0603" value="1u"/>
<part name="C35" library="usevolt" deviceset="CAP" device="_0603" value="1u"/>
<part name="P+11" library="supply1" deviceset="V+" device=""/>
<part name="R14" library="usevolt" deviceset="RES" device="_0603" value="10k"/>
<part name="U7" library="usevolt" deviceset="TI_TVP5150AM1" device="_QFP32" value="TVP5150AM1"/>
<part name="GND26" library="supply1" deviceset="GND" device=""/>
<part name="+3V12" library="supply1" deviceset="+3V3" device=""/>
<part name="P+12" library="supply1" deviceset="V+" device=""/>
<part name="C36" library="usevolt" deviceset="CAP" device="_0603" value="100n"/>
<part name="C37" library="usevolt" deviceset="CAP" device="_0603" value="100n"/>
<part name="GND27" library="supply1" deviceset="GND" device=""/>
<part name="GND28" library="supply1" deviceset="GND" device=""/>
<part name="GND29" library="supply1" deviceset="GND" device=""/>
<part name="X4" library="usevolt" deviceset="XTAL_7M-14.31818MAAJ-T" device="_SMD" value="14.31 MHz"/>
<part name="C38" library="usevolt" deviceset="CAP" device="_0603" value="15pF"/>
<part name="C39" library="usevolt" deviceset="CAP" device="_0603" value="15pF"/>
<part name="C40" library="usevolt" deviceset="CAP" device="_0603" value="100n"/>
<part name="C41" library="usevolt" deviceset="CAP" device="_0603" value="100n"/>
<part name="C42" library="usevolt" deviceset="CAP" device="_0603" value="100n"/>
<part name="R15" library="usevolt" deviceset="RES" device="_0603" value="37.4"/>
<part name="R16" library="usevolt" deviceset="RES" device="_0603" value="37.4"/>
<part name="D7" library="usevolt" deviceset="DIODE" device="DO219AB"/>
<part name="D8" library="usevolt" deviceset="DIODE" device="DO219AB"/>
<part name="P+13" library="supply1" deviceset="V+" device=""/>
<part name="C43" library="usevolt" deviceset="CAP" device="_0603" value="1u"/>
<part name="C44" library="usevolt" deviceset="CAP" device="_0603" value="1u"/>
<part name="C45" library="usevolt" deviceset="CAP" device="_0603" value="1u"/>
<part name="P+14" library="supply1" deviceset="V+" device=""/>
<part name="R17" library="usevolt" deviceset="RES" device="_0603" value="10k"/>
<part name="GND30" library="supply1" deviceset="GND" device=""/>
<part name="R18" library="usevolt" deviceset="RES" device="_0603" value="10k"/>
<part name="R19" library="usevolt" deviceset="RES" device="_0603" value="10k"/>
<part name="+3V13" library="supply1" deviceset="+3V3" device=""/>
<part name="C46" library="usevolt" deviceset="CAP" device="_0603" value="100nF"/>
<part name="C47" library="usevolt" deviceset="CAP" device="_0603" value="100nF"/>
<part name="C48" library="usevolt" deviceset="CAP" device="_0603" value="4.7uF"/>
<part name="Q2" library="usevolt" deviceset="NPN_TRANSISTOR" device="SOT323"/>
<part name="R5" library="usevolt" deviceset="RES" device="_0603" value="1k"/>
<part name="R6" library="usevolt" deviceset="RES" device="_0603"/>
<part name="P+15" library="supply1" deviceset="+5V" device=""/>
<part name="R7" library="usevolt" deviceset="RES" device="_0603" value="10k"/>
<part name="+3V14" library="supply1" deviceset="+3V3" device=""/>
<part name="C49" library="usevolt" deviceset="CAP" device="_0603" value="100nF"/>
<part name="C50" library="usevolt" deviceset="CAP" device="_0603" value="100nF"/>
<part name="C51" library="usevolt" deviceset="CAP" device="_0603" value="100nF"/>
<part name="C52" library="usevolt" deviceset="CAP" device="_0603" value="100nF"/>
<part name="C53" library="usevolt" deviceset="CAP" device="_0603" value="100nF"/>
<part name="C54" library="usevolt" deviceset="CAP" device="_0603" value="100nF"/>
<part name="GND31" library="supply1" deviceset="GND" device=""/>
</parts>
<sheets>
<sheet>
<plain>
<wire x1="35.56" y1="121.92" x2="175.26" y2="121.92" width="0.508" layer="97" style="shortdash"/>
<wire x1="175.26" y1="121.92" x2="175.26" y2="91.44" width="0.508" layer="97" style="shortdash"/>
<wire x1="175.26" y1="91.44" x2="35.56" y2="91.44" width="0.508" layer="97" style="shortdash"/>
<wire x1="35.56" y1="91.44" x2="35.56" y2="121.92" width="0.508" layer="97" style="shortdash"/>
<text x="60.96" y="116.84" size="2.54" layer="97">POWER SUPPLY</text>
<text x="86.36" y="15.24" size="1.778" layer="94" font="vector">Usewood Display
(c) Usewood Forest Tec Oy
Developer: Olli Usenius</text>
</plain>
<instances>
<instance part="FRAME1" gate="G$1" x="0" y="0"/>
<instance part="GND1" gate="1" x="127" y="96.52"/>
<instance part="GND2" gate="1" x="40.64" y="96.52"/>
<instance part="P+3" gate="1" x="127" y="119.38"/>
<instance part="+3V1" gate="G$1" x="162.56" y="119.38"/>
<instance part="F1" gate="G$1" x="40.64" y="109.22"/>
<instance part="D1" gate="G$1" x="50.8" y="101.6" rot="R90"/>
<instance part="C7" gate="G$1" x="162.56" y="104.14" rot="R90"/>
<instance part="VR2" gate="G$1" x="137.16" y="106.68"/>
<instance part="R22" gate="G$1" x="170.18" y="109.22" rot="R90"/>
<instance part="D2" gate="G$1" x="170.18" y="104.14" rot="R90"/>
<instance part="GND3" gate="1" x="50.8" y="45.72"/>
<instance part="C1" gate="G$1" x="58.42" y="104.14" rot="R90"/>
<instance part="VR1" gate="G$1" x="81.28" y="101.6"/>
<instance part="C2" gate="G$1" x="66.04" y="101.6" rot="R270"/>
<instance part="D23" gate="G$1" x="111.76" y="104.14" rot="R90"/>
<instance part="L1" gate="G$1" x="116.84" y="109.22"/>
<instance part="C21" gate="G$1" x="106.68" y="106.68"/>
<instance part="C22" gate="G$1" x="121.92" y="101.6" rot="R270"/>
<instance part="GND11" gate="1" x="96.52" y="50.8"/>
<instance part="P+1" gate="1" x="93.98" y="76.2"/>
<instance part="P+5" gate="VCC" x="50.8" y="116.84"/>
<instance part="U2" gate="G$1" x="88.9" y="63.5" rot="R180"/>
<instance part="U$2" gate="G$1" x="17.78" y="66.04" rot="MR0"/>
<instance part="C47" gate="G$1" x="96.52" y="68.58" rot="R90"/>
<instance part="C48" gate="G$1" x="101.6" y="68.58" rot="R90"/>
</instances>
<busses>
</busses>
<nets>
<net name="GND" class="0">
<segment>
<pinref part="GND1" gate="1" pin="GND"/>
<wire x1="132.08" y1="104.14" x2="132.08" y2="99.06" width="0.1524" layer="91"/>
<wire x1="132.08" y1="99.06" x2="127" y2="99.06" width="0.1524" layer="91"/>
<wire x1="170.18" y1="99.06" x2="162.56" y2="99.06" width="0.1524" layer="91"/>
<junction x="132.08" y="99.06"/>
<wire x1="162.56" y1="99.06" x2="132.08" y2="99.06" width="0.1524" layer="91"/>
<pinref part="C7" gate="G$1" pin="P$1"/>
<junction x="162.56" y="99.06"/>
<pinref part="VR2" gate="G$1" pin="GND"/>
<pinref part="D2" gate="G$1" pin="1"/>
<pinref part="C1" gate="G$1" pin="P$1"/>
<wire x1="58.42" y1="99.06" x2="66.04" y2="99.06" width="0.1524" layer="91"/>
<wire x1="66.04" y1="99.06" x2="99.06" y2="99.06" width="0.1524" layer="91"/>
<wire x1="99.06" y1="99.06" x2="111.76" y2="99.06" width="0.1524" layer="91"/>
<wire x1="111.76" y1="99.06" x2="121.92" y2="99.06" width="0.1524" layer="91"/>
<pinref part="C2" gate="G$1" pin="-"/>
<junction x="66.04" y="99.06"/>
<pinref part="VR1" gate="G$1" pin="GND"/>
<wire x1="99.06" y1="104.14" x2="99.06" y2="99.06" width="0.1524" layer="91"/>
<junction x="99.06" y="99.06"/>
<pinref part="D23" gate="G$1" pin="P"/>
<junction x="111.76" y="99.06"/>
<pinref part="C22" gate="G$1" pin="-"/>
<wire x1="127" y1="99.06" x2="121.92" y2="99.06" width="0.1524" layer="91"/>
<junction x="127" y="99.06"/>
<junction x="121.92" y="99.06"/>
<pinref part="GND2" gate="1" pin="GND"/>
<wire x1="50.8" y1="99.06" x2="58.42" y2="99.06" width="0.1524" layer="91"/>
<pinref part="D1" gate="G$1" pin="P"/>
<junction x="50.8" y="99.06"/>
<wire x1="50.8" y1="99.06" x2="40.64" y2="99.06" width="0.1524" layer="91"/>
<junction x="58.42" y="99.06"/>
</segment>
<segment>
<pinref part="GND3" gate="1" pin="GND"/>
<pinref part="U$2" gate="G$1" pin="P$5"/>
<wire x1="50.8" y1="48.26" x2="50.8" y2="50.8" width="0.1524" layer="91"/>
<wire x1="50.8" y1="50.8" x2="50.8" y2="58.42" width="0.1524" layer="91"/>
<wire x1="50.8" y1="58.42" x2="50.8" y2="66.04" width="0.1524" layer="91"/>
<wire x1="50.8" y1="66.04" x2="50.8" y2="68.58" width="0.1524" layer="91"/>
<wire x1="50.8" y1="68.58" x2="17.78" y2="68.58" width="0.1524" layer="91"/>
<pinref part="U$2" gate="G$1" pin="P$6"/>
<wire x1="17.78" y1="66.04" x2="50.8" y2="66.04" width="0.1524" layer="91"/>
<junction x="50.8" y="66.04"/>
<pinref part="U$2" gate="G$1" pin="P$9"/>
<wire x1="17.78" y1="58.42" x2="50.8" y2="58.42" width="0.1524" layer="91"/>
<junction x="50.8" y="58.42"/>
<pinref part="U$2" gate="G$1" pin="P$12"/>
<wire x1="17.78" y1="50.8" x2="50.8" y2="50.8" width="0.1524" layer="91"/>
<junction x="50.8" y="50.8"/>
</segment>
<segment>
<pinref part="GND11" gate="1" pin="GND"/>
<wire x1="96.52" y1="53.34" x2="96.52" y2="55.88" width="0.1524" layer="91"/>
<wire x1="96.52" y1="55.88" x2="96.52" y2="63.5" width="0.1524" layer="91"/>
<wire x1="96.52" y1="63.5" x2="91.44" y2="63.5" width="0.1524" layer="91"/>
<pinref part="U2" gate="G$1" pin="VSS"/>
<pinref part="U2" gate="G$1" pin="RS"/>
<wire x1="96.52" y1="55.88" x2="68.58" y2="55.88" width="0.1524" layer="91"/>
<wire x1="68.58" y1="55.88" x2="68.58" y2="60.96" width="0.1524" layer="91"/>
<junction x="96.52" y="55.88"/>
<pinref part="C47" gate="G$1" pin="P$1"/>
<junction x="96.52" y="63.5"/>
<pinref part="C48" gate="G$1" pin="P$1"/>
<wire x1="101.6" y1="63.5" x2="96.52" y2="63.5" width="0.1524" layer="91"/>
</segment>
</net>
<net name="+3V3" class="0">
<segment>
<pinref part="+3V1" gate="G$1" pin="+3V3"/>
<wire x1="162.56" y1="106.68" x2="162.56" y2="109.22" width="0.1524" layer="91"/>
<wire x1="162.56" y1="109.22" x2="162.56" y2="114.3" width="0.1524" layer="91"/>
<wire x1="162.56" y1="114.3" x2="162.56" y2="116.84" width="0.1524" layer="91"/>
<wire x1="154.94" y1="109.22" x2="162.56" y2="109.22" width="0.1524" layer="91"/>
<junction x="162.56" y="109.22"/>
<pinref part="C7" gate="G$1" pin="P$2"/>
<pinref part="VR2" gate="G$1" pin="VOUT"/>
<pinref part="R22" gate="G$1" pin="P$2"/>
<wire x1="162.56" y1="114.3" x2="170.18" y2="114.3" width="0.1524" layer="91"/>
<junction x="162.56" y="114.3"/>
</segment>
</net>
<net name="PWR" class="0">
<segment>
<pinref part="F1" gate="G$1" pin="P$1"/>
<wire x1="17.78" y1="73.66" x2="22.86" y2="73.66" width="0.1524" layer="91"/>
<label x="22.86" y="109.22" size="1.778" layer="95"/>
<pinref part="U$2" gate="G$1" pin="P$3"/>
<pinref part="U$2" gate="G$1" pin="P$4"/>
<wire x1="22.86" y1="73.66" x2="22.86" y2="109.22" width="0.1524" layer="91"/>
<wire x1="22.86" y1="109.22" x2="35.56" y2="109.22" width="0.1524" layer="91"/>
<wire x1="17.78" y1="71.12" x2="22.86" y2="71.12" width="0.1524" layer="91"/>
<wire x1="22.86" y1="71.12" x2="22.86" y2="73.66" width="0.1524" layer="91"/>
<junction x="22.86" y="73.66"/>
<pinref part="U$2" gate="G$1" pin="P$7"/>
<wire x1="17.78" y1="63.5" x2="22.86" y2="63.5" width="0.1524" layer="91"/>
<wire x1="22.86" y1="63.5" x2="22.86" y2="71.12" width="0.1524" layer="91"/>
<junction x="22.86" y="71.12"/>
<pinref part="U$2" gate="G$1" pin="P$10"/>
<wire x1="17.78" y1="55.88" x2="22.86" y2="55.88" width="0.1524" layer="91"/>
<wire x1="22.86" y1="55.88" x2="22.86" y2="63.5" width="0.1524" layer="91"/>
<junction x="22.86" y="63.5"/>
</segment>
</net>
<net name="+5V" class="0">
<segment>
<wire x1="127" y1="109.22" x2="127" y2="114.3" width="0.1524" layer="91"/>
<junction x="127" y="109.22"/>
<wire x1="127" y1="114.3" x2="127" y2="116.84" width="0.1524" layer="91"/>
<pinref part="P+3" gate="1" pin="+5V"/>
<wire x1="132.08" y1="109.22" x2="127" y2="109.22" width="0.1524" layer="91"/>
<wire x1="154.94" y1="104.14" x2="157.48" y2="104.14" width="0.1524" layer="91"/>
<wire x1="157.48" y1="104.14" x2="157.48" y2="114.3" width="0.1524" layer="91"/>
<wire x1="157.48" y1="114.3" x2="127" y2="114.3" width="0.1524" layer="91"/>
<junction x="127" y="114.3"/>
<pinref part="VR2" gate="G$1" pin="VIN"/>
<pinref part="VR2" gate="G$1" pin="RESET"/>
<pinref part="VR1" gate="G$1" pin="FB"/>
<wire x1="99.06" y1="111.76" x2="121.92" y2="111.76" width="0.1524" layer="91"/>
<pinref part="L1" gate="G$1" pin="P$2"/>
<wire x1="121.92" y1="111.76" x2="121.92" y2="109.22" width="0.1524" layer="91"/>
<pinref part="C22" gate="G$1" pin="+"/>
<wire x1="121.92" y1="109.22" x2="121.92" y2="106.68" width="0.1524" layer="91"/>
<junction x="121.92" y="109.22"/>
<wire x1="127" y1="109.22" x2="121.92" y2="109.22" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="P+1" gate="1" pin="+5V"/>
<wire x1="93.98" y1="73.66" x2="93.98" y2="71.12" width="0.1524" layer="91"/>
<wire x1="93.98" y1="71.12" x2="93.98" y2="66.04" width="0.1524" layer="91"/>
<wire x1="93.98" y1="66.04" x2="91.44" y2="66.04" width="0.1524" layer="91"/>
<pinref part="U2" gate="G$1" pin="VDD"/>
<pinref part="C47" gate="G$1" pin="P$2"/>
<wire x1="96.52" y1="71.12" x2="93.98" y2="71.12" width="0.1524" layer="91"/>
<junction x="93.98" y="71.12"/>
<pinref part="C48" gate="G$1" pin="P$2"/>
<wire x1="101.6" y1="71.12" x2="96.52" y2="71.12" width="0.1524" layer="91"/>
<junction x="96.52" y="71.12"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="R22" gate="G$1" pin="P$1"/>
<pinref part="D2" gate="G$1" pin="0"/>
</segment>
</net>
<net name="CANH_P" class="0">
<segment>
<wire x1="17.78" y1="78.74" x2="58.42" y2="78.74" width="0.1524" layer="91"/>
<label x="25.4" y="78.74" size="1.778" layer="95"/>
<wire x1="58.42" y1="63.5" x2="58.42" y2="78.74" width="0.1524" layer="91"/>
<pinref part="U2" gate="G$1" pin="CANH"/>
<wire x1="68.58" y1="63.5" x2="58.42" y2="63.5" width="0.1524" layer="91"/>
<pinref part="U$2" gate="G$1" pin="P$1"/>
</segment>
</net>
<net name="CANL_N" class="0">
<segment>
<wire x1="17.78" y1="76.2" x2="55.88" y2="76.2" width="0.1524" layer="91"/>
<label x="25.4" y="76.2" size="1.778" layer="95"/>
<wire x1="55.88" y1="76.2" x2="55.88" y2="66.04" width="0.1524" layer="91"/>
<pinref part="U2" gate="G$1" pin="CANL"/>
<wire x1="68.58" y1="66.04" x2="55.88" y2="66.04" width="0.1524" layer="91"/>
<pinref part="U$2" gate="G$1" pin="P$2"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<pinref part="L1" gate="G$1" pin="P$1"/>
<pinref part="VR1" gate="G$1" pin="VSW"/>
<wire x1="111.76" y1="109.22" x2="109.22" y2="109.22" width="0.1524" layer="91"/>
<pinref part="D23" gate="G$1" pin="N"/>
<wire x1="109.22" y1="109.22" x2="99.06" y2="109.22" width="0.1524" layer="91"/>
<wire x1="111.76" y1="106.68" x2="111.76" y2="109.22" width="0.1524" layer="91"/>
<junction x="111.76" y="109.22"/>
<pinref part="C21" gate="G$1" pin="P$2"/>
<wire x1="109.22" y1="106.68" x2="109.22" y2="109.22" width="0.1524" layer="91"/>
<junction x="109.22" y="109.22"/>
</segment>
</net>
<net name="N$32" class="0">
<segment>
<pinref part="C21" gate="G$1" pin="P$1"/>
<pinref part="VR1" gate="G$1" pin="CB"/>
<wire x1="101.6" y1="106.68" x2="99.06" y2="106.68" width="0.1524" layer="91"/>
</segment>
</net>
<net name="CAN_RXD" class="0">
<segment>
<label x="109.22" y="68.58" size="1.778" layer="95"/>
<pinref part="U2" gate="G$1" pin="RXD"/>
<wire x1="91.44" y1="68.58" x2="119.38" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="CAN_TXD" class="0">
<segment>
<label x="109.22" y="60.96" size="1.778" layer="95"/>
<pinref part="U2" gate="G$1" pin="TXD"/>
<wire x1="119.38" y1="60.96" x2="91.44" y2="60.96" width="0.1524" layer="91"/>
</segment>
</net>
<net name="VCC" class="0">
<segment>
<wire x1="58.42" y1="106.68" x2="58.42" y2="109.22" width="0.1524" layer="91"/>
<pinref part="C1" gate="G$1" pin="P$2"/>
<pinref part="C2" gate="G$1" pin="+"/>
<wire x1="66.04" y1="106.68" x2="66.04" y2="109.22" width="0.1524" layer="91"/>
<wire x1="66.04" y1="109.22" x2="66.04" y2="111.76" width="0.1524" layer="91"/>
<wire x1="66.04" y1="111.76" x2="73.66" y2="111.76" width="0.1524" layer="91"/>
<pinref part="VR1" gate="G$1" pin="VIN"/>
<wire x1="58.42" y1="109.22" x2="66.04" y2="109.22" width="0.1524" layer="91"/>
<junction x="66.04" y="109.22"/>
<wire x1="50.8" y1="106.68" x2="50.8" y2="109.22" width="0.1524" layer="91"/>
<wire x1="50.8" y1="109.22" x2="45.72" y2="109.22" width="0.1524" layer="91"/>
<junction x="50.8" y="109.22"/>
<wire x1="50.8" y1="109.22" x2="58.42" y2="109.22" width="0.1524" layer="91"/>
<pinref part="F1" gate="G$1" pin="P$2"/>
<pinref part="D1" gate="G$1" pin="N"/>
<junction x="58.42" y="109.22"/>
<pinref part="P+5" gate="VCC" pin="VCC"/>
<wire x1="50.8" y1="114.3" x2="50.8" y2="109.22" width="0.1524" layer="91"/>
</segment>
</net>
<net name="CAM0" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="P$8"/>
<wire x1="17.78" y1="60.96" x2="33.02" y2="60.96" width="0.1524" layer="91"/>
<label x="33.02" y="60.96" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="CAM1" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="P$11"/>
<wire x1="17.78" y1="53.34" x2="33.02" y2="53.34" width="0.1524" layer="91"/>
<label x="33.02" y="53.34" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
</nets>
</sheet>
<sheet>
<plain>
<text x="162.56" y="15.24" size="1.778" layer="94" font="vector">Usewood Display
(c) Usewood Forest Tec Oy
Developer: Olli Usenius</text>
</plain>
<instances>
<instance part="FRAME2" gate="G$1" x="0" y="0"/>
<instance part="U1" gate="A" x="175.26" y="114.3"/>
<instance part="C15" gate="G$1" x="137.16" y="144.78" rot="R90"/>
<instance part="C16" gate="G$1" x="132.08" y="144.78" rot="R90"/>
<instance part="C17" gate="G$1" x="127" y="144.78" rot="R90"/>
<instance part="C18" gate="G$1" x="121.92" y="144.78" rot="R90"/>
<instance part="GND7" gate="1" x="121.92" y="134.62"/>
<instance part="+3V6" gate="G$1" x="121.92" y="157.48"/>
<instance part="GND8" gate="1" x="139.7" y="109.22"/>
<instance part="+3V7" gate="G$1" x="88.9" y="137.16"/>
<instance part="GND9" gate="1" x="88.9" y="99.06"/>
<instance part="J2" gate="G$1" x="81.28" y="116.84" rot="MR0"/>
<instance part="R2" gate="G$1" x="93.98" y="127" rot="R90"/>
<instance part="R3" gate="G$1" x="99.06" y="127" rot="R90"/>
<instance part="R4" gate="G$1" x="104.14" y="127" rot="R90"/>
<instance part="R11" gate="G$1" x="246.38" y="139.7" rot="R90"/>
<instance part="D4" gate="G$1" x="246.38" y="132.08" rot="R90"/>
<instance part="GND15" gate="1" x="246.38" y="121.92"/>
<instance part="U3" gate="G$1" x="73.66" y="53.34"/>
<instance part="+3V8" gate="G$1" x="33.02" y="91.44"/>
<instance part="+3V9" gate="G$1" x="111.76" y="91.44"/>
<instance part="GND18" gate="1" x="30.48" y="10.16"/>
<instance part="GND19" gate="1" x="109.22" y="10.16"/>
<instance part="C49" gate="G$1" x="27.94" y="81.28" rot="R180"/>
<instance part="C50" gate="G$1" x="27.94" y="76.2" rot="R180"/>
<instance part="C51" gate="G$1" x="30.48" y="60.96"/>
<instance part="C52" gate="G$1" x="30.48" y="15.24"/>
<instance part="C53" gate="G$1" x="116.84" y="53.34"/>
<instance part="C54" gate="G$1" x="116.84" y="68.58"/>
<instance part="GND31" gate="1" x="119.38" y="43.18"/>
</instances>
<busses>
</busses>
<nets>
<net name="GND" class="0">
<segment>
<pinref part="C18" gate="G$1" pin="P$1"/>
<pinref part="GND7" gate="1" pin="GND"/>
<wire x1="121.92" y1="137.16" x2="121.92" y2="139.7" width="0.1524" layer="91"/>
<pinref part="C15" gate="G$1" pin="P$1"/>
<pinref part="C16" gate="G$1" pin="P$1"/>
<wire x1="137.16" y1="139.7" x2="132.08" y2="139.7" width="0.1524" layer="91"/>
<pinref part="C17" gate="G$1" pin="P$1"/>
<wire x1="132.08" y1="139.7" x2="127" y2="139.7" width="0.1524" layer="91"/>
<junction x="132.08" y="139.7"/>
<wire x1="121.92" y1="139.7" x2="127" y2="139.7" width="0.1524" layer="91"/>
<junction x="121.92" y="139.7"/>
<junction x="127" y="139.7"/>
</segment>
<segment>
<pinref part="U1" gate="A" pin="VSSREG"/>
<wire x1="147.32" y1="116.84" x2="144.78" y2="116.84" width="0.1524" layer="91"/>
<wire x1="144.78" y1="116.84" x2="144.78" y2="114.3" width="0.1524" layer="91"/>
<pinref part="U1" gate="A" pin="VSSA"/>
<wire x1="147.32" y1="114.3" x2="144.78" y2="114.3" width="0.1524" layer="91"/>
<wire x1="144.78" y1="114.3" x2="144.78" y2="111.76" width="0.1524" layer="91"/>
<junction x="144.78" y="114.3"/>
<pinref part="U1" gate="A" pin="VSS"/>
<wire x1="147.32" y1="111.76" x2="144.78" y2="111.76" width="0.1524" layer="91"/>
<wire x1="144.78" y1="111.76" x2="139.7" y2="111.76" width="0.1524" layer="91"/>
<junction x="144.78" y="111.76"/>
<pinref part="GND8" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="GND9" gate="1" pin="GND"/>
<wire x1="88.9" y1="101.6" x2="88.9" y2="114.3" width="0.1524" layer="91"/>
<wire x1="88.9" y1="114.3" x2="83.82" y2="114.3" width="0.1524" layer="91"/>
<wire x1="88.9" y1="114.3" x2="88.9" y2="119.38" width="0.1524" layer="91"/>
<junction x="88.9" y="114.3"/>
<wire x1="88.9" y1="119.38" x2="83.82" y2="119.38" width="0.1524" layer="91"/>
<pinref part="J2" gate="G$1" pin="GND"/>
<pinref part="J2" gate="G$1" pin="GND@2"/>
</segment>
<segment>
<pinref part="GND15" gate="1" pin="GND"/>
<pinref part="D4" gate="G$1" pin="1"/>
<wire x1="246.38" y1="124.46" x2="246.38" y2="127" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND19" gate="1" pin="GND"/>
<pinref part="U3" gate="G$1" pin="VSS"/>
<wire x1="109.22" y1="12.7" x2="109.22" y2="15.24" width="0.1524" layer="91"/>
<wire x1="109.22" y1="15.24" x2="88.9" y2="15.24" width="0.1524" layer="91"/>
<pinref part="U3" gate="G$1" pin="VSS@2"/>
<wire x1="109.22" y1="15.24" x2="109.22" y2="48.26" width="0.1524" layer="91"/>
<wire x1="109.22" y1="48.26" x2="88.9" y2="48.26" width="0.1524" layer="91"/>
<junction x="109.22" y="15.24"/>
<pinref part="U3" gate="G$1" pin="VSSQ@2"/>
<wire x1="109.22" y1="48.26" x2="109.22" y2="60.96" width="0.1524" layer="91"/>
<wire x1="109.22" y1="60.96" x2="88.9" y2="60.96" width="0.1524" layer="91"/>
<junction x="109.22" y="48.26"/>
<pinref part="U3" gate="G$1" pin="VSSQ@4"/>
<wire x1="109.22" y1="60.96" x2="109.22" y2="76.2" width="0.1524" layer="91"/>
<wire x1="109.22" y1="76.2" x2="88.9" y2="76.2" width="0.1524" layer="91"/>
<junction x="109.22" y="60.96"/>
<pinref part="U3" gate="G$1" pin="VSS@3"/>
<wire x1="109.22" y1="76.2" x2="109.22" y2="81.28" width="0.1524" layer="91"/>
<wire x1="109.22" y1="81.28" x2="88.9" y2="81.28" width="0.1524" layer="91"/>
<junction x="109.22" y="76.2"/>
</segment>
<segment>
<pinref part="GND18" gate="1" pin="GND"/>
<pinref part="U3" gate="G$1" pin="VSSQ@3"/>
<wire x1="30.48" y1="12.7" x2="30.48" y2="53.34" width="0.1524" layer="91"/>
<wire x1="30.48" y1="53.34" x2="53.34" y2="53.34" width="0.1524" layer="91"/>
<pinref part="U3" gate="G$1" pin="VSSQ"/>
<wire x1="30.48" y1="53.34" x2="30.48" y2="68.58" width="0.1524" layer="91"/>
<wire x1="30.48" y1="68.58" x2="53.34" y2="68.58" width="0.1524" layer="91"/>
<junction x="30.48" y="53.34"/>
<wire x1="30.48" y1="12.7" x2="25.4" y2="12.7" width="0.1524" layer="91"/>
<junction x="30.48" y="12.7"/>
<pinref part="C52" gate="G$1" pin="P$1"/>
<wire x1="25.4" y1="12.7" x2="25.4" y2="15.24" width="0.1524" layer="91"/>
<pinref part="C51" gate="G$1" pin="P$1"/>
<wire x1="25.4" y1="15.24" x2="25.4" y2="60.96" width="0.1524" layer="91"/>
<junction x="25.4" y="15.24"/>
<pinref part="C50" gate="G$1" pin="P$2"/>
<wire x1="25.4" y1="60.96" x2="25.4" y2="76.2" width="0.1524" layer="91"/>
<junction x="25.4" y="60.96"/>
<pinref part="C49" gate="G$1" pin="P$2"/>
<wire x1="25.4" y1="76.2" x2="25.4" y2="81.28" width="0.1524" layer="91"/>
<junction x="25.4" y="76.2"/>
</segment>
<segment>
<pinref part="C54" gate="G$1" pin="P$2"/>
<pinref part="C53" gate="G$1" pin="P$2"/>
<wire x1="119.38" y1="68.58" x2="119.38" y2="53.34" width="0.1524" layer="91"/>
<wire x1="119.38" y1="53.34" x2="119.38" y2="45.72" width="0.1524" layer="91"/>
<junction x="119.38" y="53.34"/>
<pinref part="GND31" gate="1" pin="GND"/>
</segment>
</net>
<net name="+3V3" class="0">
<segment>
<pinref part="C18" gate="G$1" pin="P$2"/>
<pinref part="C17" gate="G$1" pin="P$2"/>
<wire x1="121.92" y1="147.32" x2="127" y2="147.32" width="0.1524" layer="91"/>
<pinref part="C16" gate="G$1" pin="P$2"/>
<wire x1="127" y1="147.32" x2="132.08" y2="147.32" width="0.1524" layer="91"/>
<junction x="127" y="147.32"/>
<pinref part="C15" gate="G$1" pin="P$2"/>
<wire x1="132.08" y1="147.32" x2="137.16" y2="147.32" width="0.1524" layer="91"/>
<junction x="132.08" y="147.32"/>
<pinref part="U1" gate="A" pin="VDD(REG)(3V3)"/>
<wire x1="137.16" y1="147.32" x2="144.78" y2="147.32" width="0.1524" layer="91"/>
<junction x="137.16" y="147.32"/>
<pinref part="U1" gate="A" pin="VDD(3V3)"/>
<wire x1="144.78" y1="147.32" x2="147.32" y2="147.32" width="0.1524" layer="91"/>
<wire x1="147.32" y1="149.86" x2="144.78" y2="149.86" width="0.1524" layer="91"/>
<wire x1="144.78" y1="149.86" x2="144.78" y2="147.32" width="0.1524" layer="91"/>
<junction x="144.78" y="147.32"/>
<pinref part="U1" gate="A" pin="VDD(3V3)_2"/>
<wire x1="147.32" y1="152.4" x2="144.78" y2="152.4" width="0.1524" layer="91"/>
<wire x1="144.78" y1="152.4" x2="144.78" y2="149.86" width="0.1524" layer="91"/>
<junction x="144.78" y="149.86"/>
<pinref part="U1" gate="A" pin="VDDA"/>
<wire x1="147.32" y1="154.94" x2="144.78" y2="154.94" width="0.1524" layer="91"/>
<wire x1="144.78" y1="154.94" x2="144.78" y2="152.4" width="0.1524" layer="91"/>
<junction x="144.78" y="152.4"/>
<pinref part="+3V6" gate="G$1" pin="+3V3"/>
<wire x1="121.92" y1="154.94" x2="121.92" y2="147.32" width="0.1524" layer="91"/>
<junction x="121.92" y="147.32"/>
<pinref part="U1" gate="A" pin="VREFP"/>
<wire x1="147.32" y1="142.24" x2="144.78" y2="142.24" width="0.1524" layer="91"/>
<wire x1="144.78" y1="142.24" x2="144.78" y2="147.32" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="+3V7" gate="G$1" pin="+3V3"/>
<wire x1="88.9" y1="134.62" x2="88.9" y2="132.08" width="0.1524" layer="91"/>
<wire x1="88.9" y1="132.08" x2="88.9" y2="124.46" width="0.1524" layer="91"/>
<wire x1="88.9" y1="124.46" x2="83.82" y2="124.46" width="0.1524" layer="91"/>
<wire x1="104.14" y1="132.08" x2="99.06" y2="132.08" width="0.1524" layer="91"/>
<junction x="88.9" y="132.08"/>
<pinref part="J2" gate="G$1" pin="VREF"/>
<pinref part="R2" gate="G$1" pin="P$2"/>
<wire x1="99.06" y1="132.08" x2="93.98" y2="132.08" width="0.1524" layer="91"/>
<wire x1="93.98" y1="132.08" x2="88.9" y2="132.08" width="0.1524" layer="91"/>
<junction x="93.98" y="132.08"/>
<pinref part="R3" gate="G$1" pin="P$2"/>
<junction x="99.06" y="132.08"/>
<pinref part="R4" gate="G$1" pin="P$2"/>
</segment>
<segment>
<pinref part="+3V8" gate="G$1" pin="+3V3"/>
<pinref part="U3" gate="G$1" pin="VDD"/>
<wire x1="33.02" y1="88.9" x2="33.02" y2="81.28" width="0.1524" layer="91"/>
<wire x1="33.02" y1="81.28" x2="53.34" y2="81.28" width="0.1524" layer="91"/>
<pinref part="U3" gate="G$1" pin="VDDQ"/>
<wire x1="33.02" y1="81.28" x2="33.02" y2="76.2" width="0.1524" layer="91"/>
<wire x1="33.02" y1="76.2" x2="53.34" y2="76.2" width="0.1524" layer="91"/>
<junction x="33.02" y="81.28"/>
<pinref part="U3" gate="G$1" pin="VDDQ@2"/>
<wire x1="33.02" y1="76.2" x2="33.02" y2="60.96" width="0.1524" layer="91"/>
<wire x1="33.02" y1="60.96" x2="53.34" y2="60.96" width="0.1524" layer="91"/>
<junction x="33.02" y="76.2"/>
<pinref part="U3" gate="G$1" pin="VDD@2"/>
<wire x1="33.02" y1="60.96" x2="33.02" y2="48.26" width="0.1524" layer="91"/>
<wire x1="33.02" y1="48.26" x2="53.34" y2="48.26" width="0.1524" layer="91"/>
<junction x="33.02" y="60.96"/>
<pinref part="U3" gate="G$1" pin="VDD@3"/>
<wire x1="33.02" y1="48.26" x2="33.02" y2="15.24" width="0.1524" layer="91"/>
<wire x1="33.02" y1="15.24" x2="53.34" y2="15.24" width="0.1524" layer="91"/>
<junction x="33.02" y="48.26"/>
<pinref part="C49" gate="G$1" pin="P$1"/>
<pinref part="C50" gate="G$1" pin="P$1"/>
<pinref part="C51" gate="G$1" pin="P$2"/>
<pinref part="C52" gate="G$1" pin="P$2"/>
<junction x="33.02" y="15.24"/>
</segment>
<segment>
<pinref part="+3V9" gate="G$1" pin="+3V3"/>
<pinref part="U3" gate="G$1" pin="VDDQ@4"/>
<wire x1="111.76" y1="88.9" x2="111.76" y2="68.58" width="0.1524" layer="91"/>
<wire x1="111.76" y1="68.58" x2="88.9" y2="68.58" width="0.1524" layer="91"/>
<pinref part="U3" gate="G$1" pin="VDDQ@3"/>
<wire x1="111.76" y1="68.58" x2="111.76" y2="53.34" width="0.1524" layer="91"/>
<wire x1="111.76" y1="53.34" x2="88.9" y2="53.34" width="0.1524" layer="91"/>
<junction x="111.76" y="68.58"/>
<pinref part="C53" gate="G$1" pin="P$1"/>
<junction x="111.76" y="53.34"/>
<pinref part="C54" gate="G$1" pin="P$1"/>
</segment>
</net>
<net name="SWDCLK" class="0">
<segment>
<wire x1="91.44" y1="119.38" x2="91.44" y2="116.84" width="0.1524" layer="91"/>
<wire x1="91.44" y1="116.84" x2="83.82" y2="116.84" width="0.1524" layer="91"/>
<wire x1="91.44" y1="119.38" x2="99.06" y2="119.38" width="0.1524" layer="91"/>
<wire x1="99.06" y1="119.38" x2="114.3" y2="119.38" width="0.1524" layer="91"/>
<wire x1="99.06" y1="119.38" x2="99.06" y2="124.46" width="0.1524" layer="91"/>
<junction x="99.06" y="119.38"/>
<pinref part="J2" gate="G$1" pin="TCK/SWDCLK"/>
<pinref part="R3" gate="G$1" pin="P$1"/>
<label x="114.3" y="119.38" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="SWDIO" class="0">
<segment>
<wire x1="93.98" y1="121.92" x2="93.98" y2="124.46" width="0.1524" layer="91"/>
<wire x1="83.82" y1="121.92" x2="93.98" y2="121.92" width="0.1524" layer="91"/>
<junction x="93.98" y="121.92"/>
<pinref part="J2" gate="G$1" pin="TMS/SWDIO"/>
<pinref part="R2" gate="G$1" pin="P$1"/>
<wire x1="93.98" y1="121.92" x2="139.7" y2="121.92" width="0.1524" layer="91"/>
<wire x1="139.7" y1="121.92" x2="139.7" y2="134.62" width="0.1524" layer="91"/>
<pinref part="U1" gate="A" pin="JTAG_TMS/(SWDIO)"/>
<wire x1="139.7" y1="134.62" x2="147.32" y2="134.62" width="0.1524" layer="91"/>
<label x="139.7" y="134.62" size="1.27" layer="95" rot="R180" xref="yes"/>
<junction x="139.7" y="134.62"/>
</segment>
</net>
<net name="RESET" class="0">
<segment>
<wire x1="83.82" y1="104.14" x2="91.44" y2="104.14" width="0.1524" layer="91"/>
<wire x1="91.44" y1="104.14" x2="91.44" y2="114.3" width="0.1524" layer="91"/>
<wire x1="91.44" y1="114.3" x2="104.14" y2="114.3" width="0.1524" layer="91"/>
<wire x1="104.14" y1="114.3" x2="104.14" y2="124.46" width="0.1524" layer="91"/>
<wire x1="104.14" y1="124.46" x2="114.3" y2="124.46" width="0.1524" layer="91"/>
<pinref part="J2" gate="G$1" pin="RESET"/>
<pinref part="R4" gate="G$1" pin="P$1"/>
<junction x="104.14" y="124.46"/>
<label x="114.3" y="124.46" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="N$21" class="0">
<segment>
<pinref part="D4" gate="G$1" pin="0"/>
<pinref part="R11" gate="G$1" pin="P$1"/>
<wire x1="246.38" y1="134.62" x2="246.38" y2="137.16" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$22" class="0">
<segment>
<pinref part="R11" gate="G$1" pin="P$2"/>
<wire x1="246.38" y1="144.78" x2="246.38" y2="149.86" width="0.1524" layer="91"/>
<pinref part="U1" gate="A" pin="P2[31]/EMC_DQM3/I2C2_SCL/T3_MAT3"/>
<wire x1="246.38" y1="149.86" x2="226.06" y2="149.86" width="0.1524" layer="91"/>
</segment>
</net>
<net name="LCD_X_R" class="0">
<segment>
<pinref part="U1" gate="A" pin="P0[31]/USB_D+2"/>
<wire x1="226.06" y1="96.52" x2="228.6" y2="96.52" width="0.1524" layer="91"/>
<label x="228.6" y="96.52" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="LCD_Y_B" class="0">
<segment>
<pinref part="U1" gate="A" pin="P0[27]/I2C0_SDA/USB_SDA1"/>
<wire x1="226.06" y1="99.06" x2="228.6" y2="99.06" width="0.1524" layer="91"/>
<label x="228.6" y="99.06" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="LCD_Y_T" class="0">
<segment>
<pinref part="U1" gate="A" pin="P0[13]/USB_UP_LED2/SSP1_MOSI/ADC0_IN[7]"/>
<wire x1="226.06" y1="104.14" x2="228.6" y2="104.14" width="0.1524" layer="91"/>
<label x="228.6" y="104.14" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_D0" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="DQ0"/>
<wire x1="53.34" y1="78.74" x2="48.26" y2="78.74" width="0.1524" layer="91"/>
<label x="48.26" y="78.74" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_D1" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="DQ1"/>
<wire x1="53.34" y1="73.66" x2="48.26" y2="73.66" width="0.1524" layer="91"/>
<label x="48.26" y="73.66" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_D2" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="DQ2"/>
<wire x1="48.26" y1="71.12" x2="53.34" y2="71.12" width="0.1524" layer="91"/>
<label x="48.26" y="71.12" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_D3" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="DQ3"/>
<wire x1="53.34" y1="66.04" x2="48.26" y2="66.04" width="0.1524" layer="91"/>
<label x="48.26" y="66.04" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="A" pin="P3[3]/EMC_D[3]"/>
<wire x1="142.24" y1="101.6" x2="147.32" y2="101.6" width="0.1524" layer="91"/>
<label x="142.24" y="101.6" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_D4" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="DQ4"/>
<wire x1="48.26" y1="63.5" x2="53.34" y2="63.5" width="0.1524" layer="91"/>
<label x="48.26" y="63.5" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="A" pin="P3[4]/EMC_D[4]"/>
<wire x1="142.24" y1="83.82" x2="147.32" y2="83.82" width="0.1524" layer="91"/>
<label x="142.24" y="83.82" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_D5" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="DQ5"/>
<wire x1="53.34" y1="58.42" x2="48.26" y2="58.42" width="0.1524" layer="91"/>
<label x="48.26" y="58.42" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="A" pin="P3[5]/EMC_D[5]"/>
<wire x1="147.32" y1="99.06" x2="142.24" y2="99.06" width="0.1524" layer="91"/>
<label x="142.24" y="99.06" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_D6" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="DQ6"/>
<wire x1="48.26" y1="55.88" x2="53.34" y2="55.88" width="0.1524" layer="91"/>
<label x="48.26" y="55.88" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="A" pin="P3[6]/EMC_D[6]"/>
<wire x1="147.32" y1="81.28" x2="142.24" y2="81.28" width="0.1524" layer="91"/>
<label x="142.24" y="81.28" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_D7" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="DQ7"/>
<wire x1="53.34" y1="50.8" x2="48.26" y2="50.8" width="0.1524" layer="91"/>
<label x="48.26" y="50.8" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="A" pin="P3[7]/EMC_D[7]"/>
<wire x1="147.32" y1="86.36" x2="142.24" y2="86.36" width="0.1524" layer="91"/>
<label x="142.24" y="86.36" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_WE" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="!WE"/>
<wire x1="53.34" y1="43.18" x2="48.26" y2="43.18" width="0.1524" layer="91"/>
<label x="48.26" y="43.18" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_CAS" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="!CAS"/>
<wire x1="48.26" y1="40.64" x2="53.34" y2="40.64" width="0.1524" layer="91"/>
<label x="48.26" y="40.64" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_RAS" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="!RAS"/>
<wire x1="53.34" y1="38.1" x2="48.26" y2="38.1" width="0.1524" layer="91"/>
<label x="48.26" y="38.1" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_CS" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="!CS"/>
<wire x1="48.26" y1="35.56" x2="53.34" y2="35.56" width="0.1524" layer="91"/>
<label x="48.26" y="35.56" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_BA0" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="BA0"/>
<wire x1="53.34" y1="33.02" x2="48.26" y2="33.02" width="0.1524" layer="91"/>
<label x="48.26" y="33.02" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_BA1" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="BA1"/>
<wire x1="48.26" y1="30.48" x2="53.34" y2="30.48" width="0.1524" layer="91"/>
<label x="48.26" y="30.48" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_A10" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="A10/AP"/>
<wire x1="53.34" y1="27.94" x2="48.26" y2="27.94" width="0.1524" layer="91"/>
<label x="48.26" y="27.94" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_A0" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="A0"/>
<wire x1="48.26" y1="25.4" x2="53.34" y2="25.4" width="0.1524" layer="91"/>
<label x="48.26" y="25.4" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_A1" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="A1"/>
<wire x1="53.34" y1="22.86" x2="48.26" y2="22.86" width="0.1524" layer="91"/>
<label x="48.26" y="22.86" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_A2" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="A2"/>
<wire x1="48.26" y1="20.32" x2="53.34" y2="20.32" width="0.1524" layer="91"/>
<label x="48.26" y="20.32" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_A3" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="A3"/>
<wire x1="48.26" y1="17.78" x2="53.34" y2="17.78" width="0.1524" layer="91"/>
<label x="48.26" y="17.78" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_A4" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="A4"/>
<wire x1="88.9" y1="17.78" x2="93.98" y2="17.78" width="0.1524" layer="91"/>
<label x="93.98" y="17.78" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_A5" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="A5"/>
<wire x1="93.98" y1="20.32" x2="88.9" y2="20.32" width="0.1524" layer="91"/>
<label x="93.98" y="20.32" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_A6" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="A6"/>
<wire x1="88.9" y1="22.86" x2="93.98" y2="22.86" width="0.1524" layer="91"/>
<label x="93.98" y="22.86" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_A7" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="A7"/>
<wire x1="93.98" y1="25.4" x2="88.9" y2="25.4" width="0.1524" layer="91"/>
<label x="93.98" y="25.4" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_A8" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="A8"/>
<wire x1="88.9" y1="27.94" x2="93.98" y2="27.94" width="0.1524" layer="91"/>
<label x="93.98" y="27.94" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_A9" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="A9"/>
<wire x1="93.98" y1="30.48" x2="88.9" y2="30.48" width="0.1524" layer="91"/>
<label x="93.98" y="30.48" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_A11" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="A11"/>
<wire x1="88.9" y1="33.02" x2="93.98" y2="33.02" width="0.1524" layer="91"/>
<label x="93.98" y="33.02" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_CKE" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="CKE"/>
<wire x1="88.9" y1="38.1" x2="93.98" y2="38.1" width="0.1524" layer="91"/>
<label x="93.98" y="38.1" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="A" pin="P2[24]/EMC_CKE0"/>
<wire x1="226.06" y1="142.24" x2="228.6" y2="142.24" width="0.1524" layer="91"/>
<label x="228.6" y="142.24" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_CLK" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="CLK"/>
<wire x1="93.98" y1="40.64" x2="88.9" y2="40.64" width="0.1524" layer="91"/>
<label x="93.98" y="40.64" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="A" pin="P2[18]/EMC_CLK[0]"/>
<wire x1="226.06" y1="132.08" x2="228.6" y2="132.08" width="0.1524" layer="91"/>
<label x="228.6" y="132.08" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_D8" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="DQ8"/>
<wire x1="88.9" y1="50.8" x2="93.98" y2="50.8" width="0.1524" layer="91"/>
<label x="93.98" y="50.8" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_D9" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="DQ9"/>
<wire x1="93.98" y1="55.88" x2="88.9" y2="55.88" width="0.1524" layer="91"/>
<label x="93.98" y="55.88" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_D10" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="DQ10"/>
<wire x1="88.9" y1="58.42" x2="93.98" y2="58.42" width="0.1524" layer="91"/>
<label x="93.98" y="58.42" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_D11" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="DQ11"/>
<wire x1="93.98" y1="63.5" x2="88.9" y2="63.5" width="0.1524" layer="91"/>
<label x="93.98" y="63.5" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_D12" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="DQ12"/>
<wire x1="88.9" y1="66.04" x2="93.98" y2="66.04" width="0.1524" layer="91"/>
<label x="93.98" y="66.04" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="A" pin="P3[12]/EMC_D[12]"/>
<wire x1="147.32" y1="104.14" x2="142.24" y2="104.14" width="0.1524" layer="91"/>
<label x="142.24" y="104.14" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_D13" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="DQ13"/>
<wire x1="93.98" y1="71.12" x2="88.9" y2="71.12" width="0.1524" layer="91"/>
<label x="93.98" y="71.12" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="A" pin="P3[13]/EMC_D[13]"/>
<wire x1="142.24" y1="91.44" x2="147.32" y2="91.44" width="0.1524" layer="91"/>
<label x="142.24" y="91.44" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_D14" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="DQ14"/>
<wire x1="88.9" y1="73.66" x2="93.98" y2="73.66" width="0.1524" layer="91"/>
<label x="93.98" y="73.66" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="A" pin="P3[14]/EMC_D[14]"/>
<wire x1="147.32" y1="88.9" x2="142.24" y2="88.9" width="0.1524" layer="91"/>
<label x="142.24" y="88.9" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_D15" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="DQ15"/>
<wire x1="93.98" y1="78.74" x2="88.9" y2="78.74" width="0.1524" layer="91"/>
<label x="93.98" y="78.74" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="A" pin="P3[15]/EMC_D[15]"/>
<wire x1="147.32" y1="76.2" x2="142.24" y2="76.2" width="0.1524" layer="91"/>
<label x="142.24" y="76.2" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_X_L" class="0">
<segment>
<pinref part="U1" gate="A" pin="P0[28]/I2C0_SCL/USB_SCL1"/>
<wire x1="226.06" y1="114.3" x2="228.6" y2="114.3" width="0.1524" layer="91"/>
<label x="228.6" y="114.3" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_DQM0" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="LDQM"/>
<wire x1="48.26" y1="45.72" x2="53.34" y2="45.72" width="0.1524" layer="91"/>
<label x="48.26" y="45.72" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="A" pin="P2[28]/EMC_DQM0"/>
<wire x1="226.06" y1="144.78" x2="228.6" y2="144.78" width="0.1524" layer="91"/>
<label x="228.6" y="144.78" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_DQM1" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="UDQM"/>
<wire x1="88.9" y1="43.18" x2="93.98" y2="43.18" width="0.1524" layer="91"/>
<label x="93.98" y="43.18" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="A" pin="P2[29]/EMC_DQM1"/>
<wire x1="226.06" y1="134.62" x2="228.6" y2="134.62" width="0.1524" layer="91"/>
<label x="228.6" y="134.62" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
</nets>
</sheet>
<sheet>
<plain>
<text x="162.56" y="15.24" size="1.778" layer="94" font="vector">Usewood Display
(c) Usewood Forest Tec Oy
Developer: Olli Usenius</text>
</plain>
<instances>
<instance part="FRAME3" gate="G$1" x="0" y="0"/>
<instance part="U1" gate="B" x="119.38" y="101.6"/>
<instance part="+3V5" gate="G$1" x="81.28" y="147.32"/>
<instance part="GND6" gate="1" x="81.28" y="116.84"/>
<instance part="C12" gate="G$1" x="83.82" y="132.08" rot="R90"/>
<instance part="C13" gate="G$1" x="78.74" y="132.08" rot="R90"/>
<instance part="C14" gate="G$1" x="73.66" y="132.08" rot="R90"/>
<instance part="BT1" gate="G$1" x="63.5" y="119.38"/>
<instance part="J4" gate="G$1" x="33.02" y="88.9"/>
<instance part="D3" gate="G$1" x="40.64" y="93.98" rot="MR0"/>
<instance part="P+4" gate="1" x="48.26" y="101.6"/>
<instance part="GND14" gate="1" x="58.42" y="76.2"/>
<instance part="C24" gate="G$1" x="48.26" y="83.82" rot="R90"/>
<instance part="R10" gate="G$1" x="43.18" y="81.28" rot="R90"/>
</instances>
<busses>
</busses>
<nets>
<net name="GND" class="0">
<segment>
<pinref part="C12" gate="G$1" pin="P$1"/>
<pinref part="C13" gate="G$1" pin="P$1"/>
<wire x1="83.82" y1="127" x2="81.28" y2="127" width="0.1524" layer="91"/>
<pinref part="C14" gate="G$1" pin="P$1"/>
<wire x1="81.28" y1="127" x2="78.74" y2="127" width="0.1524" layer="91"/>
<wire x1="78.74" y1="127" x2="73.66" y2="127" width="0.1524" layer="91"/>
<junction x="78.74" y="127"/>
<pinref part="U1" gate="B" pin="VSS_2"/>
<wire x1="91.44" y1="127" x2="88.9" y2="127" width="0.1524" layer="91"/>
<junction x="83.82" y="127"/>
<pinref part="U1" gate="B" pin="VSS_3"/>
<wire x1="88.9" y1="127" x2="83.82" y2="127" width="0.1524" layer="91"/>
<wire x1="91.44" y1="124.46" x2="88.9" y2="124.46" width="0.1524" layer="91"/>
<wire x1="88.9" y1="124.46" x2="88.9" y2="127" width="0.1524" layer="91"/>
<junction x="88.9" y="127"/>
<pinref part="U1" gate="B" pin="VSS"/>
<wire x1="91.44" y1="121.92" x2="88.9" y2="121.92" width="0.1524" layer="91"/>
<wire x1="88.9" y1="121.92" x2="88.9" y2="124.46" width="0.1524" layer="91"/>
<junction x="88.9" y="124.46"/>
<pinref part="U1" gate="B" pin="VSSREG"/>
<wire x1="91.44" y1="119.38" x2="88.9" y2="119.38" width="0.1524" layer="91"/>
<wire x1="88.9" y1="119.38" x2="88.9" y2="121.92" width="0.1524" layer="91"/>
<junction x="88.9" y="121.92"/>
<pinref part="GND6" gate="1" pin="GND"/>
<wire x1="81.28" y1="119.38" x2="81.28" y2="127" width="0.1524" layer="91"/>
<junction x="81.28" y="127"/>
<pinref part="BT1" gate="G$1" pin="-"/>
<wire x1="63.5" y1="119.38" x2="81.28" y2="119.38" width="0.1524" layer="91"/>
<junction x="81.28" y="119.38"/>
</segment>
<segment>
<pinref part="GND14" gate="1" pin="GND"/>
<wire x1="58.42" y1="78.74" x2="58.42" y2="86.36" width="0.1524" layer="91"/>
<pinref part="J4" gate="G$1" pin="GND"/>
<wire x1="58.42" y1="86.36" x2="48.26" y2="86.36" width="0.1524" layer="91"/>
<pinref part="C24" gate="G$1" pin="P$2"/>
<wire x1="48.26" y1="86.36" x2="43.18" y2="86.36" width="0.1524" layer="91"/>
<junction x="48.26" y="86.36"/>
<pinref part="R10" gate="G$1" pin="P$2"/>
<wire x1="43.18" y1="86.36" x2="38.1" y2="86.36" width="0.1524" layer="91"/>
<junction x="43.18" y="86.36"/>
</segment>
</net>
<net name="+3V3" class="0">
<segment>
<pinref part="C14" gate="G$1" pin="P$2"/>
<pinref part="C13" gate="G$1" pin="P$2"/>
<wire x1="73.66" y1="134.62" x2="78.74" y2="134.62" width="0.1524" layer="91"/>
<pinref part="C12" gate="G$1" pin="P$2"/>
<wire x1="78.74" y1="134.62" x2="81.28" y2="134.62" width="0.1524" layer="91"/>
<junction x="78.74" y="134.62"/>
<pinref part="U1" gate="B" pin="VDD(3V3)"/>
<wire x1="81.28" y1="134.62" x2="83.82" y2="134.62" width="0.1524" layer="91"/>
<wire x1="91.44" y1="134.62" x2="88.9" y2="134.62" width="0.1524" layer="91"/>
<junction x="83.82" y="134.62"/>
<pinref part="U1" gate="B" pin="VDD(3V3)_3"/>
<wire x1="88.9" y1="134.62" x2="83.82" y2="134.62" width="0.1524" layer="91"/>
<wire x1="91.44" y1="137.16" x2="88.9" y2="137.16" width="0.1524" layer="91"/>
<wire x1="88.9" y1="137.16" x2="88.9" y2="134.62" width="0.1524" layer="91"/>
<junction x="88.9" y="134.62"/>
<pinref part="U1" gate="B" pin="VDD(3V3)_2"/>
<wire x1="91.44" y1="139.7" x2="88.9" y2="139.7" width="0.1524" layer="91"/>
<wire x1="88.9" y1="139.7" x2="88.9" y2="137.16" width="0.1524" layer="91"/>
<junction x="88.9" y="137.16"/>
<pinref part="+3V5" gate="G$1" pin="+3V3"/>
<wire x1="81.28" y1="144.78" x2="81.28" y2="134.62" width="0.1524" layer="91"/>
<junction x="81.28" y="134.62"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="U1" gate="B" pin="VBAT"/>
<wire x1="91.44" y1="132.08" x2="63.5" y2="132.08" width="0.1524" layer="91"/>
<wire x1="63.5" y1="132.08" x2="63.5" y2="129.54" width="0.1524" layer="91"/>
<pinref part="BT1" gate="G$1" pin="+"/>
</segment>
</net>
<net name="SWDCLK" class="0">
<segment>
<pinref part="U1" gate="B" pin="JTAG_TCK/(SWDCLK)"/>
<wire x1="91.44" y1="111.76" x2="86.36" y2="111.76" width="0.1524" layer="91"/>
<label x="86.36" y="111.76" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAN_TXD" class="0">
<segment>
<pinref part="U1" gate="B" pin="P0[1]/CAN_TD1/U3_RXD/I2C1_SCL/U0_RXD"/>
<wire x1="91.44" y1="99.06" x2="86.36" y2="99.06" width="0.1524" layer="91"/>
<label x="86.36" y="99.06" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAN_RXD" class="0">
<segment>
<pinref part="U1" gate="B" pin="P0[0]/CAN_RD1/U3_TXD/I2C1_SDA/U0_TXD"/>
<wire x1="91.44" y1="104.14" x2="86.36" y2="104.14" width="0.1524" layer="91"/>
<label x="86.36" y="104.14" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="USB_D_P" class="0">
<segment>
<pinref part="U1" gate="B" pin="P0[29]/USB_D+1/!EINT0"/>
<wire x1="91.44" y1="101.6" x2="50.8" y2="101.6" width="0.1524" layer="91"/>
<wire x1="50.8" y1="101.6" x2="50.8" y2="88.9" width="0.1524" layer="91"/>
<pinref part="J4" gate="G$1" pin="D+"/>
<wire x1="50.8" y1="88.9" x2="38.1" y2="88.9" width="0.1524" layer="91"/>
<label x="50.8" y="101.6" size="1.27" layer="95"/>
</segment>
</net>
<net name="USB_D_N" class="0">
<segment>
<pinref part="U1" gate="B" pin="P0[30]/USB_D-1/!EINT1"/>
<wire x1="91.44" y1="91.44" x2="38.1" y2="91.44" width="0.1524" layer="91"/>
<pinref part="J4" gate="G$1" pin="D-"/>
<label x="53.34" y="91.44" size="1.27" layer="95"/>
</segment>
</net>
<net name="N$19" class="0">
<segment>
<pinref part="J4" gate="G$1" pin="VCC"/>
<pinref part="D3" gate="G$1" pin="N"/>
</segment>
</net>
<net name="+5V" class="0">
<segment>
<pinref part="P+4" gate="1" pin="+5V"/>
<wire x1="48.26" y1="99.06" x2="48.26" y2="93.98" width="0.1524" layer="91"/>
<pinref part="D3" gate="G$1" pin="P"/>
<wire x1="48.26" y1="93.98" x2="45.72" y2="93.98" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$20" class="0">
<segment>
<pinref part="J4" gate="G$1" pin="SHLD"/>
<wire x1="38.1" y1="83.82" x2="40.64" y2="83.82" width="0.1524" layer="91"/>
<wire x1="40.64" y1="83.82" x2="40.64" y2="81.28" width="0.1524" layer="91"/>
<pinref part="R10" gate="G$1" pin="P$1"/>
<wire x1="40.64" y1="81.28" x2="40.64" y2="78.74" width="0.1524" layer="91"/>
<wire x1="40.64" y1="78.74" x2="43.18" y2="78.74" width="0.1524" layer="91"/>
<pinref part="C24" gate="G$1" pin="P$1"/>
<wire x1="43.18" y1="78.74" x2="48.26" y2="78.74" width="0.1524" layer="91"/>
<junction x="43.18" y="78.74"/>
<pinref part="J4" gate="G$1" pin="SHLD@2"/>
<wire x1="38.1" y1="81.28" x2="40.64" y2="81.28" width="0.1524" layer="91"/>
<junction x="40.64" y="81.28"/>
</segment>
</net>
<net name="LCD_VD18" class="0">
<segment>
<pinref part="U1" gate="B" pin="P2[12]/!EINT2!/SD_DAT[2]/I2S_TX_WS/LCD_VD[4]/LCD_VD[3]/LCD_VD[8]/LCD_VD[18]"/>
<wire x1="205.74" y1="127" x2="210.82" y2="127" width="0.1524" layer="91"/>
<label x="210.82" y="127" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="LCD_VD15" class="0">
<segment>
<pinref part="U1" gate="B" pin="P1[25]/!USB_LS1!/!USB_HSTEN1!/T1_MAT1/MC_1A/CLKOUT/LCD_VD[11]/LCD_VD[15]"/>
<wire x1="91.44" y1="81.28" x2="86.36" y2="81.28" width="0.1524" layer="91"/>
<label x="86.36" y="81.28" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD11" class="0">
<segment>
<pinref part="U1" gate="B" pin="P1[21]/USB_TX_DM1/PWM1[3]/SSP0_SSEL/!MC_ABORT!/R/LCD_VD[7]/LCD_VD[11]"/>
<wire x1="91.44" y1="78.74" x2="86.36" y2="78.74" width="0.1524" layer="91"/>
<label x="86.36" y="78.74" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD12" class="0">
<segment>
<pinref part="U1" gate="B" pin="P1[22]/USB_RCV1/USB_PWRD1/T1_MAT0/MC_0B/SSP1_MOSI/LCD_VD[8]/LCD_VD[12]"/>
<wire x1="86.36" y1="76.2" x2="91.44" y2="76.2" width="0.1524" layer="91"/>
<label x="86.36" y="76.2" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD13" class="0">
<segment>
<pinref part="U1" gate="B" pin="P1[23]/USB_RX_DP1/PWM1[4]/QEI_PHB/MC_FB1/SSP0_MISO/LCD_VD[9]/LCD_VD[13]"/>
<wire x1="91.44" y1="73.66" x2="86.36" y2="73.66" width="0.1524" layer="91"/>
<label x="86.36" y="73.66" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD14" class="0">
<segment>
<pinref part="U1" gate="B" pin="P1[24]/USB_RX_DM1/PWM1[5]/QEI_IDX/MC_FB2/SSP0_MOSI/LCD_VD[10]/LCD_VD[14]"/>
<wire x1="91.44" y1="63.5" x2="86.36" y2="63.5" width="0.1524" layer="91"/>
<label x="86.36" y="63.5" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD10" class="0">
<segment>
<pinref part="U1" gate="B" pin="P1[20]/USB_TX_DP1/PWM1[2]/QEI_PHA/MC_FB0/SSP0_SCK/LCD_VD[6]/LCD_VD[10]"/>
<wire x1="86.36" y1="60.96" x2="91.44" y2="60.96" width="0.1524" layer="91"/>
<label x="86.36" y="60.96" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD19" class="0">
<segment>
<pinref part="U1" gate="B" pin="P2[13]/!EINT3!/SD_DAT[3]/I2S_TX_SDA/R/LCD_VD[5]/LCD_VD[9]/LCD_VD[19]"/>
<wire x1="205.74" y1="109.22" x2="210.82" y2="109.22" width="0.1524" layer="91"/>
<label x="210.82" y="109.22" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="LCD_VD20" class="0">
<segment>
<pinref part="U1" gate="B" pin="P1[26]/!USB_SSPND1!/PWM1[6]/T0_CAP0/MC_1B/SSP1_SSEL/LCD_VD[12]/LCD_VD[20]"/>
<wire x1="91.44" y1="83.82" x2="86.36" y2="83.82" width="0.1524" layer="91"/>
<label x="86.36" y="83.82" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD21" class="0">
<segment>
<pinref part="U1" gate="B" pin="P1[27]/!USB_INT1!/!USB_OVRCR1!/T0_CAP1/CLKOUT/R/LCD_VD[13]/LCD_VD[21]"/>
<wire x1="91.44" y1="68.58" x2="86.36" y2="68.58" width="0.1524" layer="91"/>
<label x="86.36" y="68.58" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD22" class="0">
<segment>
<pinref part="U1" gate="B" pin="P1[28]/USB_SCL1/PWM1_CAP0/T0_MAT0/MC_2A/SSP0_SSEL/LCD_VD[14]/LCD_VD[22]"/>
<wire x1="91.44" y1="58.42" x2="86.36" y2="58.42" width="0.1524" layer="91"/>
<label x="86.36" y="58.42" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD23" class="0">
<segment>
<pinref part="U1" gate="B" pin="P1[29]/USB_SDA1/PWM1_CAP1/T0_MAT1/MC_2B/U4_TXD/LCD_VD[15]/LCD_VD[23]"/>
<wire x1="86.36" y1="55.88" x2="91.44" y2="55.88" width="0.1524" layer="91"/>
<label x="86.36" y="55.88" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_CS" class="0">
<segment>
<pinref part="U1" gate="B" pin="P2[20]/!EMC_DYCS0"/>
<wire x1="205.74" y1="132.08" x2="210.82" y2="132.08" width="0.1524" layer="91"/>
<label x="210.82" y="132.08" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_CAS" class="0">
<segment>
<pinref part="U1" gate="B" pin="P2[16]/!EMC_CAS!"/>
<wire x1="205.74" y1="119.38" x2="210.82" y2="119.38" width="0.1524" layer="91"/>
<label x="210.82" y="119.38" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_RAS" class="0">
<segment>
<pinref part="U1" gate="B" pin="P2[17]/!EMC_RAS"/>
<wire x1="205.74" y1="114.3" x2="210.82" y2="114.3" width="0.1524" layer="91"/>
<label x="210.82" y="114.3" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_A1" class="0">
<segment>
<pinref part="U1" gate="B" pin="P4[1]/EMC_A[1]"/>
<wire x1="205.74" y1="55.88" x2="210.82" y2="55.88" width="0.1524" layer="91"/>
<label x="210.82" y="55.88" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_A2" class="0">
<segment>
<pinref part="U1" gate="B" pin="P4[2]/EMC_A[2]"/>
<wire x1="210.82" y1="58.42" x2="205.74" y2="58.42" width="0.1524" layer="91"/>
<label x="210.82" y="58.42" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_A5" class="0">
<segment>
<pinref part="U1" gate="B" pin="P4[5]/EMC_A[5]"/>
<wire x1="210.82" y1="66.04" x2="205.74" y2="66.04" width="0.1524" layer="91"/>
<label x="210.82" y="66.04" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_A3" class="0">
<segment>
<pinref part="U1" gate="B" pin="P4[3]/EMC_A[3]"/>
<wire x1="205.74" y1="68.58" x2="210.82" y2="68.58" width="0.1524" layer="91"/>
<label x="210.82" y="68.58" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_A4" class="0">
<segment>
<pinref part="U1" gate="B" pin="P4[4]/EMC_A[4]"/>
<wire x1="210.82" y1="76.2" x2="205.74" y2="76.2" width="0.1524" layer="91"/>
<label x="210.82" y="76.2" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_A0" class="0">
<segment>
<pinref part="U1" gate="B" pin="P4[0]/EMC_A[0]"/>
<wire x1="205.74" y1="60.96" x2="210.82" y2="60.96" width="0.1524" layer="91"/>
<label x="210.82" y="60.96" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="CAM1_OUT2" class="0">
<segment>
<pinref part="U1" gate="B" pin="P4[18]/EMC_A[18]"/>
<wire x1="210.82" y1="63.5" x2="205.74" y2="63.5" width="0.1524" layer="91"/>
<label x="210.82" y="63.5" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="MMOV" class="0">
<segment>
<pinref part="U1" gate="B" pin="P4[17]/EMC_A[17]"/>
<wire x1="205.74" y1="71.12" x2="210.82" y2="71.12" width="0.1524" layer="91"/>
<label x="210.82" y="71.12" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="CAM1_OUT0" class="0">
<segment>
<pinref part="U1" gate="B" pin="P4[16]/EMC_A[16]"/>
<wire x1="210.82" y1="73.66" x2="205.74" y2="73.66" width="0.1524" layer="91"/>
<label x="210.82" y="73.66" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="CAM1_PDN" class="0">
<segment>
<pinref part="U1" gate="B" pin="P0[11]/U2_RXD/I2C2_SCL/T3_MAT1"/>
<wire x1="91.44" y1="88.9" x2="86.36" y2="88.9" width="0.1524" layer="91"/>
<label x="86.36" y="88.9" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM1_AVID" class="0">
<segment>
<pinref part="U1" gate="B" pin="P0[10]/U2_TXD/I2C2_SDA/T3_MAT0"/>
<wire x1="91.44" y1="93.98" x2="86.36" y2="93.98" width="0.1524" layer="91"/>
<label x="86.36" y="93.98" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM1_HSYNC" class="0">
<segment>
<pinref part="U1" gate="B" pin="P2[15]/!EMC_CS3!/I2C1_SCL/T2_CAP1"/>
<wire x1="205.74" y1="111.76" x2="210.82" y2="111.76" width="0.1524" layer="91"/>
<label x="210.82" y="111.76" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
</nets>
</sheet>
<sheet>
<plain>
<text x="162.56" y="15.24" size="1.778" layer="94" font="vector">Usewood Display
(c) Usewood Forest Tec Oy
Developer: Olli Usenius</text>
</plain>
<instances>
<instance part="FRAME4" gate="G$1" x="0" y="0"/>
<instance part="U1" gate="C" x="86.36" y="99.06"/>
<instance part="+3V4" gate="G$1" x="53.34" y="139.7"/>
<instance part="GND5" gate="1" x="53.34" y="111.76"/>
<instance part="C8" gate="G$1" x="58.42" y="124.46" rot="R90"/>
<instance part="C9" gate="G$1" x="53.34" y="124.46" rot="R90"/>
<instance part="C10" gate="G$1" x="48.26" y="124.46" rot="R90"/>
<instance part="C11" gate="G$1" x="43.18" y="124.46" rot="R90"/>
<instance part="X2" gate="G$1" x="43.18" y="104.14" rot="R90"/>
<instance part="C19" gate="G$1" x="38.1" y="106.68"/>
<instance part="C20" gate="G$1" x="38.1" y="99.06"/>
<instance part="GND10" gate="1" x="30.48" y="93.98"/>
<instance part="DS1" gate="G$1" x="231.14" y="93.98"/>
<instance part="Q1" gate="G$1" x="198.12" y="147.32"/>
<instance part="P+6" gate="VCC" x="208.28" y="157.48"/>
<instance part="R12" gate="G$1" x="198.12" y="154.94" rot="R90"/>
<instance part="GND16" gate="1" x="190.5" y="134.62"/>
<instance part="+3V3" gate="G$1" x="205.74" y="152.4"/>
<instance part="GND17" gate="1" x="195.58" y="33.02"/>
<instance part="U4" gate="G$1" x="53.34" y="30.48"/>
<instance part="+3V10" gate="G$1" x="17.78" y="45.72"/>
<instance part="GND20" gate="1" x="17.78" y="17.78"/>
<instance part="C23" gate="G$1" x="17.78" y="30.48" rot="R90"/>
<instance part="R1" gate="G$1" x="22.86" y="35.56" rot="R90"/>
<instance part="R18" gate="G$1" x="172.72" y="45.72" rot="R90"/>
<instance part="R19" gate="G$1" x="175.26" y="48.26" rot="R90"/>
<instance part="+3V13" gate="G$1" x="175.26" y="60.96"/>
<instance part="R7" gate="G$1" x="198.12" y="127" rot="R270"/>
<instance part="+3V14" gate="G$1" x="198.12" y="134.62"/>
</instances>
<busses>
</busses>
<nets>
<net name="RESET" class="0">
<segment>
<pinref part="U1" gate="C" pin="!RESET"/>
<wire x1="58.42" y1="96.52" x2="63.5" y2="96.52" width="0.1524" layer="91"/>
<label x="58.42" y="96.52" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="+3V3" class="0">
<segment>
<pinref part="C11" gate="G$1" pin="P$2"/>
<pinref part="C10" gate="G$1" pin="P$2"/>
<wire x1="43.18" y1="127" x2="48.26" y2="127" width="0.1524" layer="91"/>
<pinref part="C9" gate="G$1" pin="P$2"/>
<wire x1="48.26" y1="127" x2="53.34" y2="127" width="0.1524" layer="91"/>
<junction x="48.26" y="127"/>
<pinref part="C8" gate="G$1" pin="P$2"/>
<wire x1="53.34" y1="127" x2="58.42" y2="127" width="0.1524" layer="91"/>
<junction x="53.34" y="127"/>
<pinref part="U1" gate="C" pin="VDD(3V3)"/>
<wire x1="58.42" y1="127" x2="60.96" y2="127" width="0.1524" layer="91"/>
<junction x="58.42" y="127"/>
<pinref part="U1" gate="C" pin="VDD(3V3)_3"/>
<wire x1="60.96" y1="127" x2="63.5" y2="127" width="0.1524" layer="91"/>
<wire x1="63.5" y1="129.54" x2="60.96" y2="129.54" width="0.1524" layer="91"/>
<wire x1="60.96" y1="129.54" x2="60.96" y2="127" width="0.1524" layer="91"/>
<junction x="60.96" y="127"/>
<pinref part="U1" gate="C" pin="VDD(3V3)_2"/>
<wire x1="63.5" y1="132.08" x2="60.96" y2="132.08" width="0.1524" layer="91"/>
<wire x1="60.96" y1="132.08" x2="60.96" y2="129.54" width="0.1524" layer="91"/>
<junction x="60.96" y="129.54"/>
<pinref part="U1" gate="C" pin="VDD(REG)(3V3)"/>
<wire x1="63.5" y1="134.62" x2="60.96" y2="134.62" width="0.1524" layer="91"/>
<wire x1="60.96" y1="134.62" x2="60.96" y2="132.08" width="0.1524" layer="91"/>
<junction x="60.96" y="132.08"/>
<pinref part="+3V4" gate="G$1" pin="+3V3"/>
<wire x1="53.34" y1="137.16" x2="53.34" y2="127" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="DS1" gate="G$1" pin="VDD"/>
<pinref part="+3V3" gate="G$1" pin="+3V3"/>
<wire x1="205.74" y1="149.86" x2="205.74" y2="137.16" width="0.1524" layer="91"/>
<wire x1="205.74" y1="137.16" x2="228.6" y2="137.16" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="+3V10" gate="G$1" pin="+3V3"/>
<pinref part="C23" gate="G$1" pin="P$2"/>
<wire x1="17.78" y1="33.02" x2="17.78" y2="40.64" width="0.1524" layer="91"/>
<pinref part="U4" gate="G$1" pin="VCC"/>
<wire x1="17.78" y1="40.64" x2="17.78" y2="43.18" width="0.1524" layer="91"/>
<wire x1="73.66" y1="40.64" x2="73.66" y2="33.02" width="0.1524" layer="91"/>
<wire x1="73.66" y1="33.02" x2="71.12" y2="33.02" width="0.1524" layer="91"/>
<wire x1="17.78" y1="40.64" x2="22.86" y2="40.64" width="0.1524" layer="91"/>
<junction x="17.78" y="40.64"/>
<pinref part="R1" gate="G$1" pin="P$2"/>
<wire x1="22.86" y1="40.64" x2="73.66" y2="40.64" width="0.1524" layer="91"/>
<junction x="22.86" y="40.64"/>
</segment>
<segment>
<pinref part="+3V13" gate="G$1" pin="+3V3"/>
<pinref part="R19" gate="G$1" pin="P$2"/>
<wire x1="175.26" y1="58.42" x2="175.26" y2="55.88" width="0.1524" layer="91"/>
<wire x1="175.26" y1="55.88" x2="175.26" y2="53.34" width="0.1524" layer="91"/>
<wire x1="175.26" y1="55.88" x2="172.72" y2="55.88" width="0.1524" layer="91"/>
<junction x="175.26" y="55.88"/>
<pinref part="R18" gate="G$1" pin="P$2"/>
<wire x1="172.72" y1="55.88" x2="172.72" y2="50.8" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="R7" gate="G$1" pin="P$1"/>
<pinref part="+3V14" gate="G$1" pin="+3V3"/>
<wire x1="198.12" y1="129.54" x2="198.12" y2="132.08" width="0.1524" layer="91"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="U1" gate="C" pin="VSS"/>
<wire x1="63.5" y1="111.76" x2="60.96" y2="111.76" width="0.1524" layer="91"/>
<wire x1="60.96" y1="111.76" x2="60.96" y2="114.3" width="0.1524" layer="91"/>
<pinref part="U1" gate="C" pin="VSS_4"/>
<wire x1="60.96" y1="114.3" x2="63.5" y2="114.3" width="0.1524" layer="91"/>
<pinref part="U1" gate="C" pin="VSS_3"/>
<wire x1="63.5" y1="116.84" x2="60.96" y2="116.84" width="0.1524" layer="91"/>
<wire x1="60.96" y1="116.84" x2="60.96" y2="114.3" width="0.1524" layer="91"/>
<junction x="60.96" y="114.3"/>
<pinref part="U1" gate="C" pin="VSS_2"/>
<wire x1="63.5" y1="119.38" x2="60.96" y2="119.38" width="0.1524" layer="91"/>
<wire x1="60.96" y1="119.38" x2="60.96" y2="116.84" width="0.1524" layer="91"/>
<junction x="60.96" y="116.84"/>
<pinref part="C8" gate="G$1" pin="P$1"/>
<wire x1="60.96" y1="119.38" x2="58.42" y2="119.38" width="0.1524" layer="91"/>
<junction x="60.96" y="119.38"/>
<pinref part="C9" gate="G$1" pin="P$1"/>
<wire x1="58.42" y1="119.38" x2="53.34" y2="119.38" width="0.1524" layer="91"/>
<junction x="58.42" y="119.38"/>
<pinref part="C10" gate="G$1" pin="P$1"/>
<wire x1="53.34" y1="119.38" x2="48.26" y2="119.38" width="0.1524" layer="91"/>
<junction x="53.34" y="119.38"/>
<pinref part="C11" gate="G$1" pin="P$1"/>
<wire x1="48.26" y1="119.38" x2="43.18" y2="119.38" width="0.1524" layer="91"/>
<junction x="48.26" y="119.38"/>
<pinref part="GND5" gate="1" pin="GND"/>
<wire x1="53.34" y1="114.3" x2="53.34" y2="119.38" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND10" gate="1" pin="GND"/>
<wire x1="30.48" y1="96.52" x2="30.48" y2="99.06" width="0.1524" layer="91"/>
<pinref part="C20" gate="G$1" pin="P$1"/>
<wire x1="30.48" y1="99.06" x2="33.02" y2="99.06" width="0.1524" layer="91"/>
<wire x1="30.48" y1="99.06" x2="30.48" y2="106.68" width="0.1524" layer="91"/>
<junction x="30.48" y="99.06"/>
<pinref part="C19" gate="G$1" pin="P$1"/>
<wire x1="30.48" y1="106.68" x2="33.02" y2="106.68" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND16" gate="1" pin="GND"/>
<pinref part="Q1" gate="G$1" pin="E"/>
<wire x1="190.5" y1="137.16" x2="190.5" y2="139.7" width="0.1524" layer="91"/>
<wire x1="190.5" y1="139.7" x2="190.5" y2="144.78" width="0.1524" layer="91"/>
<wire x1="190.5" y1="144.78" x2="193.04" y2="144.78" width="0.1524" layer="91"/>
<pinref part="DS1" gate="G$1" pin="GND"/>
<wire x1="228.6" y1="139.7" x2="190.5" y2="139.7" width="0.1524" layer="91"/>
<junction x="190.5" y="139.7"/>
</segment>
<segment>
<pinref part="DS1" gate="G$1" pin="GND@3"/>
<pinref part="GND17" gate="1" pin="GND"/>
<wire x1="195.58" y1="35.56" x2="195.58" y2="43.18" width="0.1524" layer="91"/>
<wire x1="195.58" y1="43.18" x2="195.58" y2="55.88" width="0.1524" layer="91"/>
<wire x1="195.58" y1="55.88" x2="228.6" y2="55.88" width="0.1524" layer="91"/>
<pinref part="DS1" gate="G$1" pin="GND@2"/>
<wire x1="228.6" y1="73.66" x2="195.58" y2="73.66" width="0.1524" layer="91"/>
<wire x1="195.58" y1="73.66" x2="195.58" y2="55.88" width="0.1524" layer="91"/>
<junction x="195.58" y="55.88"/>
<pinref part="DS1" gate="G$1" pin="SHD"/>
<wire x1="228.6" y1="43.18" x2="223.52" y2="43.18" width="0.1524" layer="91"/>
<junction x="195.58" y="43.18"/>
<pinref part="DS1" gate="G$1" pin="SHD@2"/>
<wire x1="223.52" y1="43.18" x2="195.58" y2="43.18" width="0.1524" layer="91"/>
<wire x1="228.6" y1="40.64" x2="223.52" y2="40.64" width="0.1524" layer="91"/>
<wire x1="223.52" y1="40.64" x2="223.52" y2="43.18" width="0.1524" layer="91"/>
<junction x="223.52" y="43.18"/>
</segment>
<segment>
<pinref part="C23" gate="G$1" pin="P$1"/>
<pinref part="GND20" gate="1" pin="GND"/>
<wire x1="17.78" y1="20.32" x2="17.78" y2="25.4" width="0.1524" layer="91"/>
<pinref part="U4" gate="G$1" pin="GND"/>
<wire x1="40.64" y1="25.4" x2="17.78" y2="25.4" width="0.1524" layer="91"/>
<junction x="17.78" y="25.4"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="X2" gate="G$1" pin="P$1"/>
<pinref part="U1" gate="C" pin="RTCX1"/>
<wire x1="43.18" y1="99.06" x2="63.5" y2="99.06" width="0.1524" layer="91"/>
<pinref part="C20" gate="G$1" pin="P$2"/>
<wire x1="40.64" y1="99.06" x2="43.18" y2="99.06" width="0.1524" layer="91"/>
<junction x="43.18" y="99.06"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="U1" gate="C" pin="RTCX2"/>
<wire x1="63.5" y1="101.6" x2="50.8" y2="101.6" width="0.1524" layer="91"/>
<wire x1="50.8" y1="101.6" x2="50.8" y2="106.68" width="0.1524" layer="91"/>
<pinref part="X2" gate="G$1" pin="P$2"/>
<wire x1="50.8" y1="106.68" x2="43.18" y2="106.68" width="0.1524" layer="91"/>
<pinref part="C19" gate="G$1" pin="P$2"/>
<wire x1="40.64" y1="106.68" x2="43.18" y2="106.68" width="0.1524" layer="91"/>
<junction x="43.18" y="106.68"/>
</segment>
</net>
<net name="LCD_VLED-" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="VLED-"/>
<pinref part="Q1" gate="G$1" pin="C"/>
<wire x1="203.2" y1="144.78" x2="228.6" y2="144.78" width="0.1524" layer="91"/>
</segment>
</net>
<net name="LCD_VD2" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="R2"/>
<wire x1="218.44" y1="129.54" x2="228.6" y2="129.54" width="0.1524" layer="91"/>
<label x="218.44" y="129.54" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD3" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="R3"/>
<wire x1="228.6" y1="127" x2="218.44" y2="127" width="0.1524" layer="91"/>
<label x="218.44" y="127" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD4" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="R4"/>
<wire x1="218.44" y1="124.46" x2="228.6" y2="124.46" width="0.1524" layer="91"/>
<label x="218.44" y="124.46" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="C" pin="P2[6]/PWM1_CAP0/U1_RI/T2_CAP0/U2_OE/TRACECLK/LCD_VD[0]/LCD_VD[4]"/>
<wire x1="165.1" y1="111.76" x2="170.18" y2="111.76" width="0.1524" layer="91"/>
<label x="170.18" y="111.76" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="LCD_VD5" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="R5"/>
<wire x1="228.6" y1="121.92" x2="218.44" y2="121.92" width="0.1524" layer="91"/>
<label x="218.44" y="121.92" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="C" pin="P2[7]/CAN_RD2/U1_RTS/R/LCD_VD[1]/LCD_VD[5]"/>
<wire x1="165.1" y1="114.3" x2="170.18" y2="114.3" width="0.1524" layer="91"/>
<label x="170.18" y="114.3" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="LCD_VD6" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="R6"/>
<wire x1="218.44" y1="119.38" x2="228.6" y2="119.38" width="0.1524" layer="91"/>
<label x="218.44" y="119.38" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="C" pin="P2[8]/CAN_TD2/U2_TXD/U1_CTS/ENET_MDC/R/LCD_VD[2]/LCD_VD[6]"/>
<wire x1="165.1" y1="129.54" x2="170.18" y2="129.54" width="0.1524" layer="91"/>
<label x="170.18" y="129.54" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="LCD_VD7" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="R7"/>
<wire x1="228.6" y1="116.84" x2="218.44" y2="116.84" width="0.1524" layer="91"/>
<label x="218.44" y="116.84" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="C" pin="P2[9]/USB_CONNECT1/U2_RXD/U4_RXD/ENET_MDIO/R/LCD_VD[3]/LCD_VD[7]"/>
<wire x1="165.1" y1="134.62" x2="170.18" y2="134.62" width="0.1524" layer="91"/>
<label x="170.18" y="134.62" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="LCD_VD10" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="G2"/>
<wire x1="218.44" y1="109.22" x2="228.6" y2="109.22" width="0.1524" layer="91"/>
<label x="218.44" y="109.22" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD11" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="G3"/>
<wire x1="228.6" y1="106.68" x2="218.44" y2="106.68" width="0.1524" layer="91"/>
<label x="218.44" y="106.68" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD12" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="G4"/>
<wire x1="218.44" y1="104.14" x2="228.6" y2="104.14" width="0.1524" layer="91"/>
<label x="218.44" y="104.14" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD13" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="G5"/>
<wire x1="228.6" y1="101.6" x2="218.44" y2="101.6" width="0.1524" layer="91"/>
<label x="218.44" y="101.6" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD14" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="G6"/>
<wire x1="218.44" y1="99.06" x2="228.6" y2="99.06" width="0.1524" layer="91"/>
<label x="218.44" y="99.06" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD15" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="G7"/>
<wire x1="228.6" y1="96.52" x2="218.44" y2="96.52" width="0.1524" layer="91"/>
<label x="218.44" y="96.52" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD18" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="B2"/>
<wire x1="218.44" y1="88.9" x2="228.6" y2="88.9" width="0.1524" layer="91"/>
<label x="218.44" y="88.9" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD19" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="B3"/>
<wire x1="228.6" y1="86.36" x2="218.44" y2="86.36" width="0.1524" layer="91"/>
<label x="218.44" y="86.36" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD20" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="B4"/>
<wire x1="218.44" y1="83.82" x2="228.6" y2="83.82" width="0.1524" layer="91"/>
<label x="218.44" y="83.82" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD21" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="B5"/>
<wire x1="228.6" y1="81.28" x2="218.44" y2="81.28" width="0.1524" layer="91"/>
<label x="218.44" y="81.28" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD22" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="B6"/>
<wire x1="218.44" y1="78.74" x2="228.6" y2="78.74" width="0.1524" layer="91"/>
<label x="218.44" y="78.74" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD23" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="B7"/>
<wire x1="228.6" y1="76.2" x2="218.44" y2="76.2" width="0.1524" layer="91"/>
<label x="218.44" y="76.2" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_DCLK" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="DCLK"/>
<wire x1="228.6" y1="71.12" x2="218.44" y2="71.12" width="0.1524" layer="91"/>
<label x="218.44" y="71.12" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="C" pin="P2[2]/PWM1[3]/U1_CTS/T2_MAT3/R/TRACEDATA[3]/R/LCD_DCLK"/>
<wire x1="165.1" y1="132.08" x2="170.18" y2="132.08" width="0.1524" layer="91"/>
<label x="170.18" y="132.08" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="LCD_DISP" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="DISP"/>
<wire x1="218.44" y1="68.58" x2="228.6" y2="68.58" width="0.1524" layer="91"/>
<label x="218.44" y="68.58" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_HSYNC" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="HSYNC"/>
<wire x1="228.6" y1="66.04" x2="218.44" y2="66.04" width="0.1524" layer="91"/>
<label x="218.44" y="66.04" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="C" pin="P2[5]/PWM1[6]/U1_DTR/T2_MAT0/R/TRACEDATA[0]/R/LCD_LP"/>
<wire x1="165.1" y1="119.38" x2="170.18" y2="119.38" width="0.1524" layer="91"/>
<label x="170.18" y="119.38" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="LCD_VSYNC" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="VSYNC"/>
<wire x1="218.44" y1="63.5" x2="228.6" y2="63.5" width="0.1524" layer="91"/>
<label x="218.44" y="63.5" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="C" pin="P2[3]/PWM1[4]/U1_DCD/T2_MAT2/R/TRACEDATA[2]/R/LCD_FP"/>
<wire x1="165.1" y1="124.46" x2="170.18" y2="124.46" width="0.1524" layer="91"/>
<label x="170.18" y="124.46" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="LCD_DE" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="DE"/>
<wire x1="228.6" y1="60.96" x2="218.44" y2="60.96" width="0.1524" layer="91"/>
<label x="218.44" y="60.96" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="C" pin="P2[4]/PWM1[5]/U1_DSR/T2_MAT1/R/TRACEDATA[1]/R/LCD_ENAB_M"/>
<wire x1="165.1" y1="116.84" x2="170.18" y2="116.84" width="0.1524" layer="91"/>
<label x="170.18" y="116.84" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="LCD_X_R" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="X_R"/>
<wire x1="228.6" y1="53.34" x2="218.44" y2="53.34" width="0.1524" layer="91"/>
<label x="218.44" y="53.34" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_Y_B" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="Y_B"/>
<wire x1="218.44" y1="50.8" x2="228.6" y2="50.8" width="0.1524" layer="91"/>
<label x="218.44" y="50.8" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_X_L" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="X_L"/>
<wire x1="228.6" y1="48.26" x2="218.44" y2="48.26" width="0.1524" layer="91"/>
<label x="218.44" y="48.26" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_Y_T" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="Y_T"/>
<wire x1="218.44" y1="45.72" x2="228.6" y2="45.72" width="0.1524" layer="91"/>
<label x="218.44" y="45.72" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="VCC" class="0">
<segment>
<pinref part="P+6" gate="VCC" pin="VCC"/>
<wire x1="208.28" y1="154.94" x2="208.28" y2="142.24" width="0.1524" layer="91"/>
<pinref part="DS1" gate="G$1" pin="VLED+"/>
<wire x1="208.28" y1="142.24" x2="228.6" y2="142.24" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="R12" gate="G$1" pin="P$1"/>
<pinref part="Q1" gate="G$1" pin="B"/>
<wire x1="198.12" y1="152.4" x2="198.12" y2="149.86" width="0.1524" layer="91"/>
</segment>
</net>
<net name="LCD_BACKLIGHT" class="0">
<segment>
<pinref part="R12" gate="G$1" pin="P$2"/>
<wire x1="198.12" y1="160.02" x2="198.12" y2="162.56" width="0.1524" layer="91"/>
<label x="198.12" y="162.56" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="LCD_VD0" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="R0"/>
<wire x1="218.44" y1="134.62" x2="228.6" y2="134.62" width="0.1524" layer="91"/>
<label x="218.44" y="134.62" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD1" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="R1"/>
<wire x1="228.6" y1="132.08" x2="218.44" y2="132.08" width="0.1524" layer="91"/>
<label x="218.44" y="132.08" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD8" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="G0"/>
<wire x1="218.44" y1="114.3" x2="228.6" y2="114.3" width="0.1524" layer="91"/>
<label x="218.44" y="114.3" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD9" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="G1"/>
<wire x1="228.6" y1="111.76" x2="218.44" y2="111.76" width="0.1524" layer="91"/>
<label x="218.44" y="111.76" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD16" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="B0"/>
<wire x1="218.44" y1="93.98" x2="228.6" y2="93.98" width="0.1524" layer="91"/>
<label x="218.44" y="93.98" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD17" class="0">
<segment>
<pinref part="DS1" gate="G$1" pin="B1"/>
<wire x1="228.6" y1="91.44" x2="218.44" y2="91.44" width="0.1524" layer="91"/>
<label x="218.44" y="91.44" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="EMC_A8" class="0">
<segment>
<pinref part="U1" gate="C" pin="P4[8]/EMC_A[8]"/>
<wire x1="165.1" y1="66.04" x2="170.18" y2="66.04" width="0.1524" layer="91"/>
<label x="170.18" y="66.04" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_A10" class="0">
<segment>
<pinref part="U1" gate="C" pin="P4[10]/EMC_A[10]"/>
<wire x1="170.18" y1="68.58" x2="165.1" y2="68.58" width="0.1524" layer="91"/>
<label x="170.18" y="68.58" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_A11" class="0">
<segment>
<pinref part="U1" gate="C" pin="P4[11]/EMC_A[11]"/>
<wire x1="165.1" y1="71.12" x2="170.18" y2="71.12" width="0.1524" layer="91"/>
<label x="170.18" y="71.12" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_A9" class="0">
<segment>
<pinref part="U1" gate="C" pin="P4[9]/EMC_A[9]"/>
<wire x1="170.18" y1="73.66" x2="165.1" y2="73.66" width="0.1524" layer="91"/>
<label x="170.18" y="73.66" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_A6" class="0">
<segment>
<pinref part="U1" gate="C" pin="P4[6]/EMC_A[6]"/>
<wire x1="165.1" y1="88.9" x2="170.18" y2="88.9" width="0.1524" layer="91"/>
<label x="170.18" y="88.9" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_A7" class="0">
<segment>
<pinref part="U1" gate="C" pin="P4[7]/EMC_A[7]"/>
<wire x1="170.18" y1="91.44" x2="165.1" y2="91.44" width="0.1524" layer="91"/>
<label x="170.18" y="91.44" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="SPIFI_CS" class="0">
<segment>
<pinref part="R1" gate="G$1" pin="P$1"/>
<pinref part="U4" gate="G$1" pin="!CS"/>
<wire x1="22.86" y1="33.02" x2="38.1" y2="33.02" width="0.1524" layer="91"/>
<wire x1="38.1" y1="33.02" x2="40.64" y2="33.02" width="0.1524" layer="91"/>
<wire x1="38.1" y1="33.02" x2="38.1" y2="35.56" width="0.1524" layer="91"/>
<junction x="38.1" y="33.02"/>
<wire x1="38.1" y1="35.56" x2="35.56" y2="35.56" width="0.1524" layer="91"/>
<label x="35.56" y="35.56" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="C" pin="P0[19]/U1_DSR/SD_CLK/I1C1_SDA"/>
<wire x1="63.5" y1="78.74" x2="58.42" y2="78.74" width="0.1524" layer="91"/>
<label x="58.42" y="78.74" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="SPIFI_IO1" class="0">
<segment>
<pinref part="U4" gate="G$1" pin="DO/IO1"/>
<wire x1="40.64" y1="30.48" x2="35.56" y2="30.48" width="0.1524" layer="91"/>
<label x="35.56" y="30.48" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="C" pin="P0[17]/U1_CTS/SSP0_MISO/SPIFI_IO1"/>
<wire x1="63.5" y1="81.28" x2="58.42" y2="81.28" width="0.1524" layer="91"/>
<label x="58.42" y="81.28" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="SPIFI_IO2" class="0">
<segment>
<pinref part="U4" gate="G$1" pin="!WP!/IO2"/>
<wire x1="40.64" y1="27.94" x2="35.56" y2="27.94" width="0.1524" layer="91"/>
<label x="35.56" y="27.94" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="C" pin="P0[15]/U1_TXD/SSP0_SCK/SPIFI_IO2"/>
<wire x1="58.42" y1="83.82" x2="63.5" y2="83.82" width="0.1524" layer="91"/>
<label x="58.42" y="83.82" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="SPIFI_IO3" class="0">
<segment>
<pinref part="U4" gate="G$1" pin="!RESET!/IO3"/>
<wire x1="71.12" y1="30.48" x2="76.2" y2="30.48" width="0.1524" layer="91"/>
<label x="76.2" y="30.48" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="C" pin="P0[16]/U1_RXD/SSP0_SSEL/SPIFI_IO3"/>
<wire x1="63.5" y1="76.2" x2="58.42" y2="76.2" width="0.1524" layer="91"/>
<label x="58.42" y="76.2" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="SPIFI_CLK" class="0">
<segment>
<pinref part="U4" gate="G$1" pin="CLK"/>
<wire x1="76.2" y1="27.94" x2="71.12" y2="27.94" width="0.1524" layer="91"/>
<label x="76.2" y="27.94" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="C" pin="P0[22]/U1_RTS/SD_DAT[0]/U4_TXD/CAN_TD1/SPIFI_CLK"/>
<wire x1="63.5" y1="91.44" x2="58.42" y2="91.44" width="0.1524" layer="91"/>
<label x="58.42" y="91.44" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="SPIFI_IO0" class="0">
<segment>
<pinref part="U4" gate="G$1" pin="DI/IO0"/>
<wire x1="71.12" y1="25.4" x2="76.2" y2="25.4" width="0.1524" layer="91"/>
<label x="76.2" y="25.4" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="C" pin="P0[18]/U1_DCD/SSP0_MOSI/SPIFI_IO0"/>
<wire x1="63.5" y1="86.36" x2="58.42" y2="86.36" width="0.1524" layer="91"/>
<label x="58.42" y="86.36" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM1_OUT7" class="0">
<segment>
<pinref part="U1" gate="C" pin="P4[23]/EMC_A[23]/U2_RXD/SSP1_MOSI"/>
<wire x1="165.1" y1="86.36" x2="170.18" y2="86.36" width="0.1524" layer="91"/>
<label x="170.18" y="86.36" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="CAM1_OUT5" class="0">
<segment>
<pinref part="U1" gate="C" pin="P4[21]/EMC_A[21]/I2C2_SCL/SSP1_SSEL"/>
<wire x1="170.18" y1="83.82" x2="165.1" y2="83.82" width="0.1524" layer="91"/>
<label x="170.18" y="83.82" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="CAM1_OUT6" class="0">
<segment>
<pinref part="U1" gate="C" pin="P4[22]/EMC_A[22]/U2_TXD/SSP1_MISO"/>
<wire x1="165.1" y1="81.28" x2="170.18" y2="81.28" width="0.1524" layer="91"/>
<label x="170.18" y="81.28" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="CAM1_OUT4" class="0">
<segment>
<pinref part="U1" gate="C" pin="P4[20]/EMC_A[20]/I2C2_SDA/SSP1_SCK"/>
<wire x1="165.1" y1="99.06" x2="170.18" y2="99.06" width="0.1524" layer="91"/>
<label x="170.18" y="99.06" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="CAM1_OUT3" class="0">
<segment>
<pinref part="U1" gate="C" pin="P4[19]/EMC_A[19]"/>
<wire x1="165.1" y1="93.98" x2="170.18" y2="93.98" width="0.1524" layer="91"/>
<label x="170.18" y="93.98" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="I2C_SCL" class="0">
<segment>
<pinref part="U1" gate="C" pin="P5[3]/R/U4_RXD/I2C0_SCL"/>
<wire x1="165.1" y1="58.42" x2="167.64" y2="58.42" width="0.1524" layer="91"/>
<wire x1="167.64" y1="58.42" x2="167.64" y2="43.18" width="0.1524" layer="91"/>
<wire x1="167.64" y1="43.18" x2="172.72" y2="43.18" width="0.1524" layer="91"/>
<label x="180.34" y="43.18" size="1.27" layer="95" xref="yes"/>
<pinref part="R18" gate="G$1" pin="P$1"/>
<wire x1="172.72" y1="43.18" x2="180.34" y2="43.18" width="0.1524" layer="91"/>
<junction x="172.72" y="43.18"/>
</segment>
</net>
<net name="I2C_SDA" class="0">
<segment>
<pinref part="U1" gate="C" pin="P5[2]/R/T3_MAT2/R/I2C0_SDA"/>
<wire x1="180.34" y1="45.72" x2="175.26" y2="45.72" width="0.1524" layer="91"/>
<wire x1="175.26" y1="45.72" x2="170.18" y2="45.72" width="0.1524" layer="91"/>
<wire x1="170.18" y1="45.72" x2="170.18" y2="60.96" width="0.1524" layer="91"/>
<wire x1="170.18" y1="60.96" x2="165.1" y2="60.96" width="0.1524" layer="91"/>
<label x="180.34" y="45.72" size="1.27" layer="95" xref="yes"/>
<pinref part="R19" gate="G$1" pin="P$1"/>
<junction x="175.26" y="45.72"/>
</segment>
</net>
<net name="CAM1_VSYNC" class="0">
<segment>
<pinref part="U1" gate="C" pin="P2[11]/!EINT1!/SD_DAT[1]/I2S_TX-SCK/R/LCD_CLKIN"/>
<wire x1="165.1" y1="127" x2="170.18" y2="127" width="0.1524" layer="91"/>
<label x="170.18" y="127" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="CAM0_OUT3" class="0">
<segment>
<pinref part="U1" gate="C" pin="P1[13]/ENET_RX_DV"/>
<wire x1="63.5" y1="58.42" x2="58.42" y2="58.42" width="0.1524" layer="91"/>
<label x="58.42" y="58.42" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM0_VSYNC" class="0">
<segment>
<pinref part="U1" gate="C" pin="P1[7]/ENET_COL/SD_DAT[1]/PWM0[5]"/>
<wire x1="63.5" y1="55.88" x2="58.42" y2="55.88" width="0.1524" layer="91"/>
<label x="58.42" y="55.88" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="ISP" class="0">
<segment>
<pinref part="U1" gate="C" pin="P2[10]/!EINT0!/NMI"/>
<pinref part="R7" gate="G$1" pin="P$2"/>
<wire x1="198.12" y1="121.92" x2="165.1" y2="121.92" width="0.1524" layer="91"/>
<label x="190.5" y="121.92" size="1.27" layer="95"/>
</segment>
</net>
</nets>
</sheet>
<sheet>
<plain>
<text x="162.56" y="15.24" size="1.778" layer="94" font="vector">Usewood Display
(c) Usewood Forest Tec Oy
Developer: Olli Usenius</text>
</plain>
<instances>
<instance part="FRAME5" gate="G$1" x="0" y="0"/>
<instance part="U1" gate="D" x="101.6" y="91.44"/>
<instance part="+3V2" gate="G$1" x="63.5" y="147.32"/>
<instance part="C3" gate="G$1" x="68.58" y="124.46" rot="R90"/>
<instance part="C4" gate="G$1" x="63.5" y="124.46" rot="R90"/>
<instance part="GND4" gate="1" x="63.5" y="114.3"/>
<instance part="X1" gate="G$1" x="50.8" y="124.46" rot="R90"/>
<instance part="C5" gate="G$1" x="45.72" y="127"/>
<instance part="C6" gate="G$1" x="45.72" y="119.38"/>
<instance part="P+2" gate="1" x="231.14" y="109.22"/>
<instance part="GND12" gate="1" x="231.14" y="73.66"/>
<instance part="Y1" gate="G$1" x="58.42" y="40.64"/>
<instance part="GND13" gate="1" x="38.1" y="35.56"/>
<instance part="J5" gate="G$1" x="241.3" y="96.52"/>
<instance part="C46" gate="G$1" x="58.42" y="124.46" rot="R90"/>
<instance part="Q2" gate="G$1" x="45.72" y="43.18"/>
<instance part="R5" gate="G$1" x="45.72" y="50.8" rot="R90"/>
<instance part="R6" gate="G$1" x="68.58" y="40.64"/>
<instance part="P+15" gate="1" x="76.2" y="48.26"/>
</instances>
<busses>
</busses>
<nets>
<net name="+3V3" class="0">
<segment>
<pinref part="C4" gate="G$1" pin="P$2"/>
<pinref part="+3V2" gate="G$1" pin="+3V3"/>
<wire x1="63.5" y1="127" x2="63.5" y2="144.78" width="0.1524" layer="91"/>
<pinref part="C3" gate="G$1" pin="P$2"/>
<wire x1="63.5" y1="127" x2="68.58" y2="127" width="0.1524" layer="91"/>
<junction x="63.5" y="127"/>
<wire x1="68.58" y1="127" x2="73.66" y2="127" width="0.1524" layer="91"/>
<junction x="68.58" y="127"/>
<pinref part="U1" gate="D" pin="VDD(3V3)_2"/>
<wire x1="73.66" y1="134.62" x2="76.2" y2="134.62" width="0.1524" layer="91"/>
<pinref part="U1" gate="D" pin="VDD(3V3)"/>
<wire x1="76.2" y1="132.08" x2="73.66" y2="132.08" width="0.1524" layer="91"/>
<wire x1="73.66" y1="132.08" x2="73.66" y2="134.62" width="0.1524" layer="91"/>
<junction x="73.66" y="132.08"/>
<pinref part="U1" gate="D" pin="VDD(REG)(3V3)"/>
<wire x1="76.2" y1="129.54" x2="73.66" y2="129.54" width="0.1524" layer="91"/>
<wire x1="73.66" y1="129.54" x2="73.66" y2="132.08" width="0.1524" layer="91"/>
<wire x1="73.66" y1="127" x2="73.66" y2="129.54" width="0.1524" layer="91"/>
<junction x="73.66" y="129.54"/>
<pinref part="C46" gate="G$1" pin="P$2"/>
<wire x1="58.42" y1="127" x2="63.5" y2="127" width="0.1524" layer="91"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="U1" gate="D" pin="VSSREG"/>
<wire x1="76.2" y1="111.76" x2="73.66" y2="111.76" width="0.1524" layer="91"/>
<wire x1="73.66" y1="111.76" x2="73.66" y2="114.3" width="0.1524" layer="91"/>
<pinref part="U1" gate="D" pin="VSS"/>
<wire x1="73.66" y1="114.3" x2="76.2" y2="114.3" width="0.1524" layer="91"/>
<wire x1="73.66" y1="114.3" x2="73.66" y2="116.84" width="0.1524" layer="91"/>
<junction x="73.66" y="114.3"/>
<pinref part="U1" gate="D" pin="VSS_2"/>
<wire x1="73.66" y1="116.84" x2="76.2" y2="116.84" width="0.1524" layer="91"/>
<pinref part="C3" gate="G$1" pin="P$1"/>
<wire x1="73.66" y1="116.84" x2="68.58" y2="116.84" width="0.1524" layer="91"/>
<wire x1="68.58" y1="116.84" x2="68.58" y2="119.38" width="0.1524" layer="91"/>
<junction x="73.66" y="116.84"/>
<pinref part="C4" gate="G$1" pin="P$1"/>
<wire x1="68.58" y1="116.84" x2="63.5" y2="116.84" width="0.1524" layer="91"/>
<wire x1="63.5" y1="116.84" x2="63.5" y2="119.38" width="0.1524" layer="91"/>
<junction x="68.58" y="116.84"/>
<pinref part="GND4" gate="1" pin="GND"/>
<junction x="63.5" y="116.84"/>
<pinref part="C5" gate="G$1" pin="P$1"/>
<pinref part="C6" gate="G$1" pin="P$1"/>
<wire x1="40.64" y1="127" x2="40.64" y2="119.38" width="0.1524" layer="91"/>
<wire x1="40.64" y1="119.38" x2="40.64" y2="116.84" width="0.1524" layer="91"/>
<junction x="40.64" y="119.38"/>
<wire x1="40.64" y1="116.84" x2="58.42" y2="116.84" width="0.1524" layer="91"/>
<pinref part="C46" gate="G$1" pin="P$1"/>
<wire x1="58.42" y1="116.84" x2="63.5" y2="116.84" width="0.1524" layer="91"/>
<wire x1="58.42" y1="119.38" x2="58.42" y2="116.84" width="0.1524" layer="91"/>
<junction x="58.42" y="116.84"/>
</segment>
<segment>
<pinref part="GND12" gate="1" pin="GND"/>
<wire x1="231.14" y1="76.2" x2="231.14" y2="83.82" width="0.1524" layer="91"/>
<pinref part="J5" gate="G$1" pin="GND@1"/>
<wire x1="231.14" y1="83.82" x2="236.22" y2="83.82" width="0.1524" layer="91"/>
<pinref part="J5" gate="G$1" pin="GND"/>
<wire x1="236.22" y1="86.36" x2="231.14" y2="86.36" width="0.1524" layer="91"/>
<wire x1="231.14" y1="86.36" x2="231.14" y2="83.82" width="0.1524" layer="91"/>
<junction x="231.14" y="83.82"/>
</segment>
<segment>
<pinref part="Q2" gate="G$1" pin="E"/>
<pinref part="GND13" gate="1" pin="GND"/>
<wire x1="40.64" y1="40.64" x2="38.1" y2="40.64" width="0.1524" layer="91"/>
<wire x1="38.1" y1="40.64" x2="38.1" y2="38.1" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="X1" gate="G$1" pin="P$2"/>
<pinref part="C5" gate="G$1" pin="P$2"/>
<wire x1="50.8" y1="127" x2="48.26" y2="127" width="0.1524" layer="91"/>
<wire x1="50.8" y1="127" x2="53.34" y2="127" width="0.1524" layer="91"/>
<junction x="50.8" y="127"/>
<pinref part="U1" gate="D" pin="XTAL1"/>
<wire x1="53.34" y1="127" x2="53.34" y2="124.46" width="0.1524" layer="91"/>
<wire x1="53.34" y1="124.46" x2="76.2" y2="124.46" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="X1" gate="G$1" pin="P$1"/>
<pinref part="C6" gate="G$1" pin="P$2"/>
<wire x1="50.8" y1="119.38" x2="48.26" y2="119.38" width="0.1524" layer="91"/>
<pinref part="U1" gate="D" pin="XTAL2"/>
<wire x1="76.2" y1="121.92" x2="53.34" y2="121.92" width="0.1524" layer="91"/>
<wire x1="53.34" y1="121.92" x2="53.34" y2="119.38" width="0.1524" layer="91"/>
<wire x1="53.34" y1="119.38" x2="50.8" y2="119.38" width="0.1524" layer="91"/>
<junction x="50.8" y="119.38"/>
</segment>
</net>
<net name="N$13" class="0">
<segment>
<pinref part="U1" gate="D" pin="P0[3]/U0_RXD/U3_RXD"/>
<wire x1="177.8" y1="91.44" x2="218.44" y2="91.44" width="0.1524" layer="91"/>
<wire x1="218.44" y1="99.06" x2="218.44" y2="91.44" width="0.1524" layer="91"/>
<wire x1="236.22" y1="99.06" x2="233.68" y2="99.06" width="0.1524" layer="91"/>
<pinref part="J5" gate="G$1" pin="TX@1"/>
<pinref part="J5" gate="G$1" pin="TX"/>
<wire x1="236.22" y1="101.6" x2="233.68" y2="101.6" width="0.1524" layer="91"/>
<wire x1="233.68" y1="101.6" x2="233.68" y2="99.06" width="0.1524" layer="91"/>
<junction x="233.68" y="99.06"/>
<wire x1="218.44" y1="99.06" x2="233.68" y2="99.06" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="J5" gate="G$1" pin="RX"/>
<pinref part="J5" gate="G$1" pin="RX@1"/>
<wire x1="233.68" y1="96.52" x2="236.22" y2="96.52" width="0.1524" layer="91"/>
<wire x1="236.22" y1="93.98" x2="233.68" y2="93.98" width="0.1524" layer="91"/>
<wire x1="233.68" y1="93.98" x2="233.68" y2="96.52" width="0.1524" layer="91"/>
<junction x="233.68" y="96.52"/>
<pinref part="U1" gate="D" pin="P0[2]/U0_TXD/U3_TXD"/>
<wire x1="233.68" y1="96.52" x2="177.8" y2="96.52" width="0.1524" layer="91"/>
</segment>
</net>
<net name="+5V" class="0">
<segment>
<pinref part="P+2" gate="1" pin="+5V"/>
<wire x1="231.14" y1="91.44" x2="231.14" y2="106.68" width="0.1524" layer="91"/>
<pinref part="J5" gate="G$1" pin="+5V"/>
<wire x1="231.14" y1="91.44" x2="236.22" y2="91.44" width="0.1524" layer="91"/>
<pinref part="J5" gate="G$1" pin="+5V@1"/>
<wire x1="236.22" y1="88.9" x2="231.14" y2="88.9" width="0.1524" layer="91"/>
<wire x1="231.14" y1="88.9" x2="231.14" y2="91.44" width="0.1524" layer="91"/>
<junction x="231.14" y="91.44"/>
</segment>
<segment>
<pinref part="P+15" gate="1" pin="+5V"/>
<wire x1="76.2" y1="45.72" x2="76.2" y2="43.18" width="0.1524" layer="91"/>
<wire x1="76.2" y1="43.18" x2="76.2" y2="40.64" width="0.1524" layer="91"/>
<wire x1="76.2" y1="40.64" x2="73.66" y2="40.64" width="0.1524" layer="91"/>
<pinref part="R6" gate="G$1" pin="P$2"/>
</segment>
</net>
<net name="LCD_BACKLIGHT" class="0">
<segment>
<pinref part="U1" gate="D" pin="P1[3]/ENET_TXD3/SD_CMD/PWM0[2]"/>
<wire x1="76.2" y1="88.9" x2="73.66" y2="88.9" width="0.1524" layer="91"/>
<label x="73.66" y="88.9" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_DISP" class="0">
<segment>
<pinref part="U1" gate="D" pin="P2[0]/PWM1[1]/U1_TXD/R/LCD_PWR"/>
<wire x1="76.2" y1="96.52" x2="73.66" y2="96.52" width="0.1524" layer="91"/>
<label x="73.66" y="96.52" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="LCD_VD8" class="0">
<segment>
<pinref part="U1" gate="D" pin="P0[6]/I2S_RX_SDA/SSP1_SSEL/T2_MAT0/U1_RTS/R/LCD_VD[8]"/>
<wire x1="177.8" y1="101.6" x2="182.88" y2="101.6" width="0.1524" layer="91"/>
<label x="182.88" y="101.6" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="LCD_VD16" class="0">
<segment>
<pinref part="U1" gate="D" pin="P0[8]/I2S_TX_WS/SSP1_MISO/T2_MAT2/RTC_EV1/R/LCD_VD[16]"/>
<wire x1="177.8" y1="99.06" x2="182.88" y2="99.06" width="0.1524" layer="91"/>
<label x="182.88" y="99.06" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="LCD_VD9" class="0">
<segment>
<pinref part="U1" gate="D" pin="P0[7]/I2S_TX_SCK/SSP1_SCK/T2_MAT1/RTC_EV0/R/LCD_VD[9]"/>
<wire x1="177.8" y1="93.98" x2="182.88" y2="93.98" width="0.1524" layer="91"/>
<label x="182.88" y="93.98" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="LCD_VD0" class="0">
<segment>
<pinref part="U1" gate="D" pin="P0[4]/I2S_RX_SCK/CAN_RD2/T2_CAP0/R/LCD_VD[0]"/>
<wire x1="177.8" y1="88.9" x2="182.88" y2="88.9" width="0.1524" layer="91"/>
<label x="182.88" y="88.9" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="LCD_VD1" class="0">
<segment>
<pinref part="U1" gate="D" pin="P0[5]/I2S_RX_WS/CAN_TD2/T2_CAP1/R/LCD_VD[1]"/>
<wire x1="177.8" y1="86.36" x2="182.88" y2="86.36" width="0.1524" layer="91"/>
<label x="182.88" y="86.36" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="LCD_VD17" class="0">
<segment>
<pinref part="U1" gate="D" pin="P0[9]/I2S_TX_SDA/SSP1_MOSI/T2_MAT3/RTC_EV2/R/LCD_VD[17]"/>
<wire x1="177.8" y1="104.14" x2="182.88" y2="104.14" width="0.1524" layer="91"/>
<label x="182.88" y="104.14" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="LCD_VD2" class="0">
<segment>
<pinref part="U1" gate="D" pin="P4[28]/!EMC_BLS2!/U3_TXD/T2_MAT0/R/LCD_VD[6]/LCD_VD[10]/LCD_VD[2]"/>
<wire x1="177.8" y1="119.38" x2="182.88" y2="119.38" width="0.1524" layer="91"/>
<label x="182.88" y="119.38" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="LCD_VD3" class="0">
<segment>
<pinref part="U1" gate="D" pin="P4[29]/!EMC_BLS3!/U3_RXD/T2_MAT1/I2C2_SCL/LCD_VD[7]/LCD_VD[11]/LCD_VD[3]"/>
<wire x1="177.8" y1="132.08" x2="182.88" y2="132.08" width="0.1524" layer="91"/>
<label x="182.88" y="132.08" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_WE" class="0">
<segment>
<pinref part="U1" gate="D" pin="P4[25]/!EMC_WE"/>
<wire x1="177.8" y1="129.54" x2="182.88" y2="129.54" width="0.1524" layer="91"/>
<label x="182.88" y="129.54" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_BA1" class="0">
<segment>
<pinref part="U1" gate="D" pin="P4[14]/EMC_A[14]"/>
<wire x1="177.8" y1="134.62" x2="182.88" y2="134.62" width="0.1524" layer="91"/>
<label x="182.88" y="134.62" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_BA0" class="0">
<segment>
<pinref part="U1" gate="D" pin="P4[13]/EMC_A[13]"/>
<wire x1="177.8" y1="116.84" x2="182.88" y2="116.84" width="0.1524" layer="91"/>
<label x="182.88" y="116.84" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_D1" class="0">
<segment>
<pinref part="U1" gate="D" pin="P3[1]/EMC_D[1]"/>
<wire x1="177.8" y1="53.34" x2="182.88" y2="53.34" width="0.1524" layer="91"/>
<label x="182.88" y="53.34" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_D9" class="0">
<segment>
<pinref part="U1" gate="D" pin="P3[9]/EMC_D[9]"/>
<wire x1="182.88" y1="55.88" x2="177.8" y2="55.88" width="0.1524" layer="91"/>
<label x="182.88" y="55.88" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_D0" class="0">
<segment>
<pinref part="U1" gate="D" pin="P3[0]/EMC_D[0]"/>
<wire x1="177.8" y1="60.96" x2="182.88" y2="60.96" width="0.1524" layer="91"/>
<label x="182.88" y="60.96" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_D11" class="0">
<segment>
<pinref part="U1" gate="D" pin="P3[11]/EMC_D[11]"/>
<wire x1="182.88" y1="68.58" x2="177.8" y2="68.58" width="0.1524" layer="91"/>
<label x="182.88" y="68.58" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_D10" class="0">
<segment>
<pinref part="U1" gate="D" pin="P3[10]/EMC_D[10]"/>
<wire x1="177.8" y1="71.12" x2="182.88" y2="71.12" width="0.1524" layer="91"/>
<label x="182.88" y="71.12" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_D2" class="0">
<segment>
<pinref part="U1" gate="D" pin="P3[2]/EMC_D[2]"/>
<wire x1="182.88" y1="73.66" x2="177.8" y2="73.66" width="0.1524" layer="91"/>
<label x="182.88" y="73.66" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="EMC_D8" class="0">
<segment>
<pinref part="U1" gate="D" pin="P3[8]/EMC_D[8]"/>
<wire x1="177.8" y1="81.28" x2="182.88" y2="81.28" width="0.1524" layer="91"/>
<label x="182.88" y="81.28" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="CAM0_OUT0" class="0">
<segment>
<pinref part="U1" gate="D" pin="P1[10]/ENET_RXD1/R/T3_CAP0"/>
<wire x1="71.12" y1="58.42" x2="76.2" y2="58.42" width="0.1524" layer="91"/>
<label x="71.12" y="58.42" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM0_PDN" class="0">
<segment>
<pinref part="U1" gate="D" pin="P1[5]/ENET_TX_ER/SD_PWR/PWM0[3]"/>
<wire x1="76.2" y1="91.44" x2="73.66" y2="91.44" width="0.1524" layer="91"/>
<label x="73.66" y="91.44" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM0_AVID" class="0">
<segment>
<pinref part="U1" gate="D" pin="P4[15]/EMC_A[15]"/>
<wire x1="177.8" y1="114.3" x2="182.88" y2="114.3" width="0.1524" layer="91"/>
<label x="182.88" y="114.3" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="CAM0_OUT1" class="0">
<segment>
<pinref part="U1" gate="D" pin="P1[11]/ENET_RXD2/SD_DAT[2]/PWM0[6]"/>
<wire x1="76.2" y1="71.12" x2="71.12" y2="71.12" width="0.1524" layer="91"/>
<label x="71.12" y="71.12" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM0_OUT7" class="0">
<segment>
<pinref part="U1" gate="D" pin="P1[17]/ENET_MDIO/I2S_RX_MCLK"/>
<wire x1="76.2" y1="86.36" x2="71.12" y2="86.36" width="0.1524" layer="91"/>
<label x="71.12" y="86.36" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM0_OUT6" class="0">
<segment>
<pinref part="U1" gate="D" pin="P1[16]/ENET_MDC/I2S_TX_MCLK"/>
<wire x1="76.2" y1="78.74" x2="71.12" y2="78.74" width="0.1524" layer="91"/>
<label x="71.12" y="78.74" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM0_OUT5" class="0">
<segment>
<pinref part="U1" gate="D" pin="P1[15]/ENET_RX_CLK/R/I2C2_SDA"/>
<wire x1="71.12" y1="76.2" x2="76.2" y2="76.2" width="0.1524" layer="91"/>
<label x="71.12" y="76.2" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM0_OUT4" class="0">
<segment>
<pinref part="U1" gate="D" pin="P1[14]/ENET_RX_ER/R/T2_CAP0"/>
<wire x1="71.12" y1="68.58" x2="76.2" y2="68.58" width="0.1524" layer="91"/>
<label x="71.12" y="68.58" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM0_OUT2" class="0">
<segment>
<pinref part="U1" gate="D" pin="P1[12]/ENET_RXD3/SD_DAT[3]/PWM0_CAP0"/>
<wire x1="76.2" y1="81.28" x2="71.12" y2="81.28" width="0.1524" layer="91"/>
<label x="71.12" y="81.28" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<pinref part="R5" gate="G$1" pin="P$1"/>
<pinref part="Q2" gate="G$1" pin="B"/>
<wire x1="45.72" y1="48.26" x2="45.72" y2="45.72" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$14" class="0">
<segment>
<pinref part="R5" gate="G$1" pin="P$2"/>
<pinref part="U1" gate="D" pin="P1[2]/ENET_TXD2/SD_CLK/PWM0[1]"/>
<wire x1="45.72" y1="55.88" x2="76.2" y2="55.88" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="Y1" gate="G$1" pin="P$1"/>
<pinref part="Q2" gate="G$1" pin="C"/>
<wire x1="53.34" y1="40.64" x2="50.8" y2="40.64" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$15" class="0">
<segment>
<pinref part="Y1" gate="G$1" pin="P$2"/>
<pinref part="R6" gate="G$1" pin="P$1"/>
<wire x1="60.96" y1="40.64" x2="66.04" y2="40.64" width="0.1524" layer="91"/>
</segment>
</net>
<net name="CAM0_HSYNC" class="0">
<segment>
<pinref part="U1" gate="D" pin="P1[6]/ENET_TX_CLK/SD_DAT[0]/PWM0[4]"/>
<wire x1="71.12" y1="63.5" x2="76.2" y2="63.5" width="0.1524" layer="91"/>
<label x="71.12" y="63.5" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
</nets>
</sheet>
<sheet>
<plain>
<text x="162.56" y="15.24" size="1.778" layer="94" font="vector">Usewood Display
(c) Usewood Forest Tec Oy
Developer: Olli Usenius</text>
<wire x1="5.08" y1="134.62" x2="55.88" y2="134.62" width="0.254" layer="97" style="longdash"/>
<wire x1="55.88" y1="134.62" x2="55.88" y2="175.26" width="0.254" layer="97" style="longdash"/>
<text x="17.78" y="170.18" size="2.54" layer="97">POWER SUPPLY</text>
</plain>
<instances>
<instance part="U6" gate="G$1" x="76.2" y="50.8"/>
<instance part="GND21" gate="1" x="111.76" y="10.16"/>
<instance part="+3V11" gate="G$1" x="149.86" y="71.12"/>
<instance part="FRAME6" gate="G$1" x="0" y="0"/>
<instance part="U5" gate="G$1" x="33.02" y="154.94"/>
<instance part="P+7" gate="1" x="15.24" y="167.64"/>
<instance part="P+8" gate="1" x="48.26" y="167.64"/>
<instance part="GND22" gate="1" x="15.24" y="139.7"/>
<instance part="P+9" gate="1" x="111.76" y="71.12"/>
<instance part="C25" gate="G$1" x="48.26" y="152.4" rot="R270"/>
<instance part="C26" gate="G$1" x="116.84" y="63.5" rot="R90"/>
<instance part="C27" gate="G$1" x="154.94" y="63.5" rot="R90"/>
<instance part="GND23" gate="1" x="154.94" y="43.18"/>
<instance part="GND24" gate="1" x="25.4" y="48.26"/>
<instance part="GND25" gate="1" x="53.34" y="58.42"/>
<instance part="X3" gate="G$1" x="53.34" y="48.26" rot="R270"/>
<instance part="C29" gate="G$1" x="43.18" y="53.34" rot="R180"/>
<instance part="C30" gate="G$1" x="45.72" y="45.72"/>
<instance part="C31" gate="G$1" x="121.92" y="63.5" rot="R90"/>
<instance part="C32" gate="G$1" x="127" y="63.5" rot="R90"/>
<instance part="C33" gate="G$1" x="53.34" y="63.5"/>
<instance part="R9" gate="G$1" x="33.02" y="63.5"/>
<instance part="R13" gate="G$1" x="40.64" y="58.42" rot="R90"/>
<instance part="D5" gate="G$1" x="30.48" y="60.96" rot="R90"/>
<instance part="D6" gate="G$1" x="30.48" y="68.58" rot="R90"/>
<instance part="P+10" gate="1" x="30.48" y="76.2"/>
<instance part="C28" gate="G$1" x="147.32" y="53.34"/>
<instance part="C34" gate="G$1" x="139.7" y="50.8" rot="R90"/>
<instance part="C35" gate="G$1" x="147.32" y="45.72"/>
<instance part="P+11" gate="1" x="35.56" y="48.26"/>
<instance part="R14" gate="G$1" x="35.56" y="38.1" rot="R270"/>
<instance part="U7" gate="G$1" x="165.1" y="134.62"/>
<instance part="GND26" gate="1" x="200.66" y="93.98"/>
<instance part="+3V12" gate="G$1" x="238.76" y="154.94"/>
<instance part="P+12" gate="1" x="200.66" y="154.94"/>
<instance part="C36" gate="G$1" x="205.74" y="147.32" rot="R90"/>
<instance part="C37" gate="G$1" x="243.84" y="147.32" rot="R90"/>
<instance part="GND27" gate="1" x="243.84" y="127"/>
<instance part="GND28" gate="1" x="114.3" y="132.08"/>
<instance part="GND29" gate="1" x="142.24" y="142.24"/>
<instance part="X4" gate="G$1" x="142.24" y="132.08" rot="R270"/>
<instance part="C38" gate="G$1" x="134.62" y="137.16"/>
<instance part="C39" gate="G$1" x="132.08" y="129.54" rot="R180"/>
<instance part="C40" gate="G$1" x="210.82" y="147.32" rot="R90"/>
<instance part="C41" gate="G$1" x="215.9" y="147.32" rot="R90"/>
<instance part="C42" gate="G$1" x="142.24" y="147.32"/>
<instance part="R15" gate="G$1" x="124.46" y="147.32" rot="R180"/>
<instance part="R16" gate="G$1" x="129.54" y="144.78" rot="R270"/>
<instance part="D7" gate="G$1" x="116.84" y="144.78" rot="R90"/>
<instance part="D8" gate="G$1" x="116.84" y="152.4" rot="R90"/>
<instance part="P+13" gate="1" x="116.84" y="160.02"/>
<instance part="C43" gate="G$1" x="236.22" y="137.16"/>
<instance part="C44" gate="G$1" x="228.6" y="134.62" rot="R90"/>
<instance part="C45" gate="G$1" x="236.22" y="129.54"/>
<instance part="P+14" gate="1" x="124.46" y="132.08"/>
<instance part="R17" gate="G$1" x="134.62" y="91.44" rot="R90"/>
<instance part="GND30" gate="1" x="134.62" y="86.36"/>
</instances>
<busses>
</busses>
<nets>
<net name="+5V" class="0">
<segment>
<pinref part="P+7" gate="1" pin="+5V"/>
<pinref part="U5" gate="G$1" pin="IN"/>
<wire x1="15.24" y1="165.1" x2="15.24" y2="157.48" width="0.1524" layer="91"/>
<wire x1="15.24" y1="157.48" x2="25.4" y2="157.48" width="0.1524" layer="91"/>
<pinref part="U5" gate="G$1" pin="EN"/>
<wire x1="15.24" y1="157.48" x2="15.24" y2="154.94" width="0.1524" layer="91"/>
<wire x1="15.24" y1="154.94" x2="25.4" y2="154.94" width="0.1524" layer="91"/>
<junction x="15.24" y="157.48"/>
</segment>
</net>
<net name="V+" class="0">
<segment>
<pinref part="P+8" gate="1" pin="V+"/>
<pinref part="U5" gate="G$1" pin="OUT"/>
<wire x1="48.26" y1="165.1" x2="48.26" y2="157.48" width="0.1524" layer="91"/>
<wire x1="48.26" y1="157.48" x2="43.18" y2="157.48" width="0.1524" layer="91"/>
<pinref part="C25" gate="G$1" pin="P$1"/>
<junction x="48.26" y="157.48"/>
</segment>
<segment>
<pinref part="U6" gate="G$1" pin="PLL_AVDD"/>
<wire x1="104.14" y1="58.42" x2="111.76" y2="58.42" width="0.1524" layer="91"/>
<pinref part="P+9" gate="1" pin="V+"/>
<wire x1="111.76" y1="58.42" x2="111.76" y2="60.96" width="0.1524" layer="91"/>
<pinref part="U6" gate="G$1" pin="DVDD"/>
<wire x1="111.76" y1="60.96" x2="111.76" y2="63.5" width="0.1524" layer="91"/>
<wire x1="111.76" y1="63.5" x2="111.76" y2="66.04" width="0.1524" layer="91"/>
<wire x1="111.76" y1="66.04" x2="111.76" y2="68.58" width="0.1524" layer="91"/>
<wire x1="111.76" y1="60.96" x2="104.14" y2="60.96" width="0.1524" layer="91"/>
<junction x="111.76" y="60.96"/>
<pinref part="U6" gate="G$1" pin="CH_AVDD"/>
<wire x1="104.14" y1="63.5" x2="111.76" y2="63.5" width="0.1524" layer="91"/>
<junction x="111.76" y="63.5"/>
<pinref part="C26" gate="G$1" pin="P$2"/>
<wire x1="116.84" y1="66.04" x2="111.76" y2="66.04" width="0.1524" layer="91"/>
<junction x="111.76" y="66.04"/>
<pinref part="C32" gate="G$1" pin="P$2"/>
<pinref part="C31" gate="G$1" pin="P$2"/>
<wire x1="127" y1="66.04" x2="121.92" y2="66.04" width="0.1524" layer="91" style="longdash"/>
<wire x1="121.92" y1="66.04" x2="116.84" y2="66.04" width="0.1524" layer="91" style="longdash"/>
<junction x="121.92" y="66.04"/>
<junction x="116.84" y="66.04"/>
</segment>
<segment>
<pinref part="D6" gate="G$1" pin="N"/>
<pinref part="P+10" gate="1" pin="V+"/>
<wire x1="30.48" y1="71.12" x2="30.48" y2="73.66" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U6" gate="G$1" pin="RESETB"/>
<wire x1="63.5" y1="43.18" x2="35.56" y2="43.18" width="0.1524" layer="91"/>
<pinref part="P+11" gate="1" pin="V+"/>
<wire x1="35.56" y1="45.72" x2="35.56" y2="43.18" width="0.1524" layer="91"/>
<pinref part="R14" gate="G$1" pin="P$1"/>
<wire x1="35.56" y1="40.64" x2="35.56" y2="43.18" width="0.1524" layer="91"/>
<junction x="35.56" y="43.18"/>
</segment>
<segment>
<pinref part="U7" gate="G$1" pin="PLL_AVDD"/>
<wire x1="193.04" y1="142.24" x2="200.66" y2="142.24" width="0.1524" layer="91"/>
<pinref part="P+12" gate="1" pin="V+"/>
<wire x1="200.66" y1="142.24" x2="200.66" y2="144.78" width="0.1524" layer="91"/>
<pinref part="U7" gate="G$1" pin="DVDD"/>
<wire x1="200.66" y1="144.78" x2="200.66" y2="147.32" width="0.1524" layer="91"/>
<wire x1="200.66" y1="147.32" x2="200.66" y2="149.86" width="0.1524" layer="91"/>
<wire x1="200.66" y1="149.86" x2="200.66" y2="152.4" width="0.1524" layer="91"/>
<wire x1="200.66" y1="144.78" x2="193.04" y2="144.78" width="0.1524" layer="91"/>
<junction x="200.66" y="144.78"/>
<pinref part="U7" gate="G$1" pin="CH_AVDD"/>
<wire x1="193.04" y1="147.32" x2="200.66" y2="147.32" width="0.1524" layer="91"/>
<junction x="200.66" y="147.32"/>
<pinref part="C36" gate="G$1" pin="P$2"/>
<wire x1="205.74" y1="149.86" x2="200.66" y2="149.86" width="0.1524" layer="91"/>
<junction x="200.66" y="149.86"/>
<pinref part="C41" gate="G$1" pin="P$2"/>
<pinref part="C40" gate="G$1" pin="P$2"/>
<wire x1="215.9" y1="149.86" x2="210.82" y2="149.86" width="0.1524" layer="91" style="longdash"/>
<wire x1="210.82" y1="149.86" x2="205.74" y2="149.86" width="0.1524" layer="91" style="longdash"/>
<junction x="210.82" y="149.86"/>
<junction x="205.74" y="149.86"/>
</segment>
<segment>
<pinref part="D8" gate="G$1" pin="N"/>
<pinref part="P+13" gate="1" pin="V+"/>
<wire x1="116.84" y1="154.94" x2="116.84" y2="157.48" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U7" gate="G$1" pin="RESETB"/>
<wire x1="152.4" y1="127" x2="124.46" y2="127" width="0.1524" layer="91"/>
<pinref part="P+14" gate="1" pin="V+"/>
<wire x1="124.46" y1="129.54" x2="124.46" y2="127" width="0.1524" layer="91"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="GND22" gate="1" pin="GND"/>
<wire x1="15.24" y1="142.24" x2="15.24" y2="144.78" width="0.1524" layer="91"/>
<pinref part="U5" gate="G$1" pin="GND"/>
<wire x1="15.24" y1="144.78" x2="15.24" y2="152.4" width="0.1524" layer="91"/>
<wire x1="15.24" y1="152.4" x2="25.4" y2="152.4" width="0.1524" layer="91"/>
<pinref part="C25" gate="G$1" pin="P$2"/>
<wire x1="48.26" y1="149.86" x2="48.26" y2="144.78" width="0.1524" layer="91"/>
<wire x1="48.26" y1="144.78" x2="15.24" y2="144.78" width="0.1524" layer="91"/>
<junction x="15.24" y="144.78"/>
</segment>
<segment>
<pinref part="GND21" gate="1" pin="GND"/>
<pinref part="U6" gate="G$1" pin="AGND"/>
<wire x1="111.76" y1="12.7" x2="111.76" y2="15.24" width="0.1524" layer="91"/>
<wire x1="111.76" y1="15.24" x2="111.76" y2="17.78" width="0.1524" layer="91"/>
<wire x1="111.76" y1="17.78" x2="104.14" y2="17.78" width="0.1524" layer="91"/>
<pinref part="U6" gate="G$1" pin="DGND"/>
<wire x1="104.14" y1="15.24" x2="111.76" y2="15.24" width="0.1524" layer="91"/>
<junction x="111.76" y="15.24"/>
<wire x1="111.76" y1="17.78" x2="111.76" y2="20.32" width="0.1524" layer="91"/>
<junction x="111.76" y="17.78"/>
<pinref part="U6" gate="G$1" pin="PLL_AGND"/>
<wire x1="111.76" y1="20.32" x2="104.14" y2="20.32" width="0.1524" layer="91"/>
<wire x1="111.76" y1="20.32" x2="111.76" y2="22.86" width="0.1524" layer="91"/>
<junction x="111.76" y="20.32"/>
<pinref part="U6" gate="G$1" pin="CH_AGND"/>
<wire x1="111.76" y1="22.86" x2="104.14" y2="22.86" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND23" gate="1" pin="GND"/>
<pinref part="C27" gate="G$1" pin="P$1"/>
<wire x1="154.94" y1="45.72" x2="154.94" y2="53.34" width="0.1524" layer="91"/>
<pinref part="C26" gate="G$1" pin="P$1"/>
<wire x1="154.94" y1="53.34" x2="154.94" y2="58.42" width="0.1524" layer="91"/>
<wire x1="116.84" y1="58.42" x2="121.92" y2="58.42" width="0.1524" layer="91"/>
<junction x="154.94" y="58.42"/>
<pinref part="C31" gate="G$1" pin="P$1"/>
<wire x1="121.92" y1="58.42" x2="127" y2="58.42" width="0.1524" layer="91"/>
<junction x="121.92" y="58.42"/>
<pinref part="C32" gate="G$1" pin="P$1"/>
<wire x1="127" y1="58.42" x2="154.94" y2="58.42" width="0.1524" layer="91"/>
<junction x="127" y="58.42"/>
<pinref part="C35" gate="G$1" pin="P$2"/>
<wire x1="154.94" y1="45.72" x2="149.86" y2="45.72" width="0.1524" layer="91"/>
<junction x="154.94" y="45.72"/>
<pinref part="C28" gate="G$1" pin="P$2"/>
<wire x1="149.86" y1="53.34" x2="154.94" y2="53.34" width="0.1524" layer="91"/>
<junction x="154.94" y="53.34"/>
</segment>
<segment>
<pinref part="GND25" gate="1" pin="GND"/>
<pinref part="U6" gate="G$1" pin="AIP1B"/>
<wire x1="53.34" y1="60.96" x2="63.5" y2="60.96" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND24" gate="1" pin="GND"/>
<wire x1="40.64" y1="53.34" x2="30.48" y2="53.34" width="0.1524" layer="91"/>
<wire x1="30.48" y1="53.34" x2="25.4" y2="53.34" width="0.1524" layer="91"/>
<wire x1="25.4" y1="53.34" x2="25.4" y2="50.8" width="0.1524" layer="91"/>
<pinref part="C30" gate="G$1" pin="P$1"/>
<pinref part="C29" gate="G$1" pin="P$2"/>
<wire x1="40.64" y1="45.72" x2="40.64" y2="53.34" width="0.1524" layer="91" style="longdash"/>
<junction x="40.64" y="53.34"/>
<pinref part="R13" gate="G$1" pin="P$1"/>
<wire x1="40.64" y1="55.88" x2="40.64" y2="53.34" width="0.1524" layer="91"/>
<pinref part="D5" gate="G$1" pin="P"/>
<wire x1="30.48" y1="55.88" x2="30.48" y2="53.34" width="0.1524" layer="91"/>
<junction x="30.48" y="53.34"/>
</segment>
<segment>
<pinref part="GND26" gate="1" pin="GND"/>
<pinref part="U7" gate="G$1" pin="AGND"/>
<wire x1="200.66" y1="96.52" x2="200.66" y2="99.06" width="0.1524" layer="91"/>
<wire x1="200.66" y1="99.06" x2="200.66" y2="101.6" width="0.1524" layer="91"/>
<wire x1="200.66" y1="101.6" x2="193.04" y2="101.6" width="0.1524" layer="91"/>
<pinref part="U7" gate="G$1" pin="DGND"/>
<wire x1="193.04" y1="99.06" x2="200.66" y2="99.06" width="0.1524" layer="91"/>
<junction x="200.66" y="99.06"/>
<wire x1="200.66" y1="101.6" x2="200.66" y2="104.14" width="0.1524" layer="91"/>
<junction x="200.66" y="101.6"/>
<pinref part="U7" gate="G$1" pin="PLL_AGND"/>
<wire x1="200.66" y1="104.14" x2="193.04" y2="104.14" width="0.1524" layer="91"/>
<wire x1="200.66" y1="104.14" x2="200.66" y2="106.68" width="0.1524" layer="91"/>
<junction x="200.66" y="104.14"/>
<pinref part="U7" gate="G$1" pin="CH_AGND"/>
<wire x1="200.66" y1="106.68" x2="193.04" y2="106.68" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND27" gate="1" pin="GND"/>
<pinref part="C37" gate="G$1" pin="P$1"/>
<wire x1="243.84" y1="129.54" x2="243.84" y2="137.16" width="0.1524" layer="91"/>
<pinref part="C36" gate="G$1" pin="P$1"/>
<wire x1="243.84" y1="137.16" x2="243.84" y2="142.24" width="0.1524" layer="91"/>
<wire x1="205.74" y1="142.24" x2="210.82" y2="142.24" width="0.1524" layer="91"/>
<junction x="243.84" y="142.24"/>
<pinref part="C40" gate="G$1" pin="P$1"/>
<wire x1="210.82" y1="142.24" x2="215.9" y2="142.24" width="0.1524" layer="91"/>
<junction x="210.82" y="142.24"/>
<pinref part="C41" gate="G$1" pin="P$1"/>
<wire x1="215.9" y1="142.24" x2="243.84" y2="142.24" width="0.1524" layer="91"/>
<junction x="215.9" y="142.24"/>
<pinref part="C45" gate="G$1" pin="P$2"/>
<wire x1="243.84" y1="129.54" x2="238.76" y2="129.54" width="0.1524" layer="91"/>
<junction x="243.84" y="129.54"/>
<pinref part="C43" gate="G$1" pin="P$2"/>
<wire x1="238.76" y1="137.16" x2="243.84" y2="137.16" width="0.1524" layer="91"/>
<junction x="243.84" y="137.16"/>
</segment>
<segment>
<pinref part="GND29" gate="1" pin="GND"/>
<pinref part="U7" gate="G$1" pin="AIP1B"/>
<wire x1="142.24" y1="144.78" x2="152.4" y2="144.78" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND28" gate="1" pin="GND"/>
<wire x1="129.54" y1="137.16" x2="116.84" y2="137.16" width="0.1524" layer="91"/>
<wire x1="116.84" y1="137.16" x2="114.3" y2="137.16" width="0.1524" layer="91"/>
<wire x1="114.3" y1="137.16" x2="114.3" y2="134.62" width="0.1524" layer="91"/>
<pinref part="C39" gate="G$1" pin="P$2"/>
<pinref part="C38" gate="G$1" pin="P$1"/>
<wire x1="129.54" y1="129.54" x2="129.54" y2="137.16" width="0.1524" layer="91" style="longdash"/>
<junction x="129.54" y="137.16"/>
<pinref part="R16" gate="G$1" pin="P$2"/>
<wire x1="129.54" y1="139.7" x2="129.54" y2="137.16" width="0.1524" layer="91"/>
<pinref part="D7" gate="G$1" pin="P"/>
<wire x1="116.84" y1="139.7" x2="116.84" y2="137.16" width="0.1524" layer="91"/>
<junction x="116.84" y="137.16"/>
</segment>
<segment>
<pinref part="R17" gate="G$1" pin="P$1"/>
<pinref part="GND30" gate="1" pin="GND"/>
</segment>
</net>
<net name="+3V3" class="0">
<segment>
<pinref part="+3V11" gate="G$1" pin="+3V3"/>
<pinref part="U6" gate="G$1" pin="IO_DVDD"/>
<wire x1="149.86" y1="68.58" x2="149.86" y2="66.04" width="0.1524" layer="91"/>
<wire x1="149.86" y1="66.04" x2="149.86" y2="55.88" width="0.1524" layer="91"/>
<wire x1="149.86" y1="55.88" x2="104.14" y2="55.88" width="0.1524" layer="91"/>
<pinref part="C27" gate="G$1" pin="P$2"/>
<wire x1="154.94" y1="66.04" x2="149.86" y2="66.04" width="0.1524" layer="91"/>
<junction x="149.86" y="66.04"/>
</segment>
<segment>
<pinref part="+3V12" gate="G$1" pin="+3V3"/>
<pinref part="U7" gate="G$1" pin="IO_DVDD"/>
<wire x1="238.76" y1="152.4" x2="238.76" y2="149.86" width="0.1524" layer="91"/>
<wire x1="238.76" y1="149.86" x2="238.76" y2="139.7" width="0.1524" layer="91"/>
<wire x1="238.76" y1="139.7" x2="193.04" y2="139.7" width="0.1524" layer="91"/>
<pinref part="C37" gate="G$1" pin="P$2"/>
<wire x1="243.84" y1="149.86" x2="238.76" y2="149.86" width="0.1524" layer="91"/>
<junction x="238.76" y="149.86"/>
</segment>
</net>
<net name="CAM0" class="0">
<segment>
<label x="25.4" y="63.5" size="1.27" layer="95" rot="R180" xref="yes"/>
<pinref part="R9" gate="G$1" pin="P$1"/>
<wire x1="30.48" y1="63.5" x2="25.4" y2="63.5" width="0.1524" layer="91"/>
<pinref part="D5" gate="G$1" pin="N"/>
<junction x="30.48" y="63.5"/>
<pinref part="D6" gate="G$1" pin="P"/>
</segment>
</net>
<net name="CAM0_OUT0" class="0">
<segment>
<pinref part="U6" gate="G$1" pin="YOUT0"/>
<wire x1="63.5" y1="15.24" x2="33.02" y2="15.24" width="0.1524" layer="91"/>
<label x="33.02" y="15.24" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM0_OUT1" class="0">
<segment>
<pinref part="U6" gate="G$1" pin="YOUT1"/>
<wire x1="63.5" y1="17.78" x2="33.02" y2="17.78" width="0.1524" layer="91"/>
<label x="33.02" y="17.78" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM0_OUT2" class="0">
<segment>
<pinref part="U6" gate="G$1" pin="YOUT2"/>
<wire x1="63.5" y1="20.32" x2="33.02" y2="20.32" width="0.1524" layer="91"/>
<label x="33.02" y="20.32" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM0_OUT3" class="0">
<segment>
<pinref part="U6" gate="G$1" pin="YOUT3"/>
<wire x1="33.02" y1="22.86" x2="63.5" y2="22.86" width="0.1524" layer="91"/>
<label x="33.02" y="22.86" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM0_OUT4" class="0">
<segment>
<pinref part="U6" gate="G$1" pin="YOUT4"/>
<wire x1="63.5" y1="25.4" x2="33.02" y2="25.4" width="0.1524" layer="91"/>
<label x="33.02" y="25.4" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM0_OUT5" class="0">
<segment>
<pinref part="U6" gate="G$1" pin="YOUT5"/>
<wire x1="33.02" y1="27.94" x2="63.5" y2="27.94" width="0.1524" layer="91"/>
<label x="33.02" y="27.94" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM0_OUT6" class="0">
<segment>
<pinref part="U6" gate="G$1" pin="YOUT6"/>
<wire x1="63.5" y1="30.48" x2="33.02" y2="30.48" width="0.1524" layer="91"/>
<label x="33.02" y="30.48" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM0_OUT7" class="0">
<segment>
<pinref part="U6" gate="G$1" pin="YOUT7/I2CSEL"/>
<wire x1="33.02" y1="33.02" x2="35.56" y2="33.02" width="0.1524" layer="91"/>
<label x="33.02" y="33.02" size="1.27" layer="95" rot="R180" xref="yes"/>
<pinref part="R14" gate="G$1" pin="P$2"/>
<junction x="35.56" y="33.02"/>
<wire x1="35.56" y1="33.02" x2="63.5" y2="33.02" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="X3" gate="G$1" pin="P$1"/>
<pinref part="U6" gate="G$1" pin="XTAL1/OSC"/>
<wire x1="53.34" y1="53.34" x2="63.5" y2="53.34" width="0.1524" layer="91" style="longdash"/>
<pinref part="C29" gate="G$1" pin="P$1"/>
<wire x1="48.26" y1="53.34" x2="53.34" y2="53.34" width="0.1524" layer="91" style="longdash"/>
<junction x="53.34" y="53.34"/>
</segment>
</net>
<net name="N$23" class="0">
<segment>
<pinref part="U6" gate="G$1" pin="XTAL2"/>
<wire x1="63.5" y1="50.8" x2="58.42" y2="50.8" width="0.1524" layer="91" style="longdash"/>
<wire x1="58.42" y1="50.8" x2="58.42" y2="45.72" width="0.1524" layer="91" style="longdash"/>
<pinref part="X3" gate="G$1" pin="P$2"/>
<wire x1="58.42" y1="45.72" x2="53.34" y2="45.72" width="0.1524" layer="91" style="longdash"/>
<pinref part="C30" gate="G$1" pin="P$2"/>
<wire x1="53.34" y1="45.72" x2="48.26" y2="45.72" width="0.1524" layer="91" style="longdash"/>
<junction x="53.34" y="45.72"/>
</segment>
</net>
<net name="N$24" class="0">
<segment>
<pinref part="C33" gate="G$1" pin="P$2"/>
<pinref part="U6" gate="G$1" pin="AIP1A"/>
<wire x1="55.88" y1="63.5" x2="63.5" y2="63.5" width="0.1524" layer="91" style="longdash"/>
</segment>
</net>
<net name="N$17" class="0">
<segment>
<pinref part="C33" gate="G$1" pin="P$1"/>
<wire x1="48.26" y1="63.5" x2="40.64" y2="63.5" width="0.1524" layer="91"/>
<pinref part="R9" gate="G$1" pin="P$2"/>
<pinref part="R13" gate="G$1" pin="P$2"/>
<junction x="40.64" y="63.5"/>
<wire x1="40.64" y1="63.5" x2="38.1" y2="63.5" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$25" class="0">
<segment>
<pinref part="C28" gate="G$1" pin="P$1"/>
<pinref part="C34" gate="G$1" pin="P$2"/>
<wire x1="139.7" y1="53.34" x2="142.24" y2="53.34" width="0.1524" layer="91"/>
<pinref part="U6" gate="G$1" pin="REFM"/>
<wire x1="104.14" y1="50.8" x2="137.16" y2="50.8" width="0.1524" layer="91"/>
<wire x1="137.16" y1="50.8" x2="137.16" y2="53.34" width="0.1524" layer="91"/>
<wire x1="137.16" y1="53.34" x2="139.7" y2="53.34" width="0.1524" layer="91"/>
<junction x="139.7" y="53.34"/>
</segment>
</net>
<net name="N$26" class="0">
<segment>
<pinref part="C34" gate="G$1" pin="P$1"/>
<pinref part="C35" gate="G$1" pin="P$1"/>
<wire x1="139.7" y1="45.72" x2="142.24" y2="45.72" width="0.1524" layer="91"/>
<wire x1="139.7" y1="45.72" x2="137.16" y2="45.72" width="0.1524" layer="91"/>
<junction x="139.7" y="45.72"/>
<wire x1="137.16" y1="45.72" x2="137.16" y2="48.26" width="0.1524" layer="91"/>
<pinref part="U6" gate="G$1" pin="REFP"/>
<wire x1="137.16" y1="48.26" x2="104.14" y2="48.26" width="0.1524" layer="91"/>
</segment>
</net>
<net name="CAM0_AVID" class="0">
<segment>
<pinref part="U6" gate="G$1" pin="AVID"/>
<wire x1="104.14" y1="40.64" x2="111.76" y2="40.64" width="0.1524" layer="91"/>
<label x="111.76" y="40.64" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="CAM0_HSYNC" class="0">
<segment>
<pinref part="U6" gate="G$1" pin="HSYNC"/>
<wire x1="104.14" y1="38.1" x2="111.76" y2="38.1" width="0.1524" layer="91"/>
<label x="111.76" y="38.1" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="CAM0_VSYNC" class="0">
<segment>
<pinref part="U6" gate="G$1" pin="VSYNC/PALI"/>
<wire x1="111.76" y1="35.56" x2="104.14" y2="35.56" width="0.1524" layer="91"/>
<label x="111.76" y="35.56" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="CAM0_SCLK" class="0">
<segment>
<pinref part="U6" gate="G$1" pin="SCLK"/>
<wire x1="63.5" y1="40.64" x2="60.96" y2="40.64" width="0.1524" layer="91"/>
<wire x1="60.96" y1="40.64" x2="60.96" y2="38.1" width="0.1524" layer="91"/>
<wire x1="60.96" y1="38.1" x2="58.42" y2="38.1" width="0.1524" layer="91"/>
<label x="58.42" y="38.1" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM0_PDN" class="0">
<segment>
<pinref part="U6" gate="G$1" pin="PDN"/>
<wire x1="104.14" y1="45.72" x2="111.76" y2="45.72" width="0.1524" layer="91"/>
<label x="111.76" y="45.72" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="N$27" class="0">
<segment>
<pinref part="X4" gate="G$1" pin="P$1"/>
<pinref part="U7" gate="G$1" pin="XTAL1/OSC"/>
<wire x1="142.24" y1="137.16" x2="152.4" y2="137.16" width="0.1524" layer="91" style="longdash"/>
<pinref part="C38" gate="G$1" pin="P$2"/>
<wire x1="137.16" y1="137.16" x2="142.24" y2="137.16" width="0.1524" layer="91" style="longdash"/>
<junction x="142.24" y="137.16"/>
</segment>
</net>
<net name="N$28" class="0">
<segment>
<pinref part="U7" gate="G$1" pin="XTAL2"/>
<wire x1="152.4" y1="134.62" x2="147.32" y2="134.62" width="0.1524" layer="91" style="longdash"/>
<wire x1="147.32" y1="134.62" x2="147.32" y2="129.54" width="0.1524" layer="91" style="longdash"/>
<pinref part="X4" gate="G$1" pin="P$2"/>
<wire x1="147.32" y1="129.54" x2="142.24" y2="129.54" width="0.1524" layer="91" style="longdash"/>
<pinref part="C39" gate="G$1" pin="P$1"/>
<wire x1="142.24" y1="129.54" x2="137.16" y2="129.54" width="0.1524" layer="91" style="longdash"/>
<junction x="142.24" y="129.54"/>
</segment>
</net>
<net name="N$29" class="0">
<segment>
<pinref part="C42" gate="G$1" pin="P$2"/>
<pinref part="U7" gate="G$1" pin="AIP1A"/>
<wire x1="144.78" y1="147.32" x2="152.4" y2="147.32" width="0.1524" layer="91" style="longdash"/>
</segment>
</net>
<net name="N$30" class="0">
<segment>
<pinref part="C42" gate="G$1" pin="P$1"/>
<wire x1="137.16" y1="147.32" x2="129.54" y2="147.32" width="0.1524" layer="91"/>
<pinref part="R15" gate="G$1" pin="P$1"/>
<pinref part="R16" gate="G$1" pin="P$1"/>
<junction x="129.54" y="147.32"/>
<wire x1="129.54" y1="147.32" x2="127" y2="147.32" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$31" class="0">
<segment>
<pinref part="C43" gate="G$1" pin="P$1"/>
<pinref part="C44" gate="G$1" pin="P$2"/>
<wire x1="228.6" y1="137.16" x2="231.14" y2="137.16" width="0.1524" layer="91"/>
<pinref part="U7" gate="G$1" pin="REFM"/>
<wire x1="193.04" y1="134.62" x2="226.06" y2="134.62" width="0.1524" layer="91"/>
<wire x1="226.06" y1="134.62" x2="226.06" y2="137.16" width="0.1524" layer="91"/>
<wire x1="226.06" y1="137.16" x2="228.6" y2="137.16" width="0.1524" layer="91"/>
<junction x="228.6" y="137.16"/>
</segment>
</net>
<net name="N$33" class="0">
<segment>
<pinref part="C44" gate="G$1" pin="P$1"/>
<pinref part="C45" gate="G$1" pin="P$1"/>
<wire x1="228.6" y1="129.54" x2="231.14" y2="129.54" width="0.1524" layer="91"/>
<wire x1="228.6" y1="129.54" x2="226.06" y2="129.54" width="0.1524" layer="91"/>
<junction x="228.6" y="129.54"/>
<wire x1="226.06" y1="129.54" x2="226.06" y2="132.08" width="0.1524" layer="91"/>
<pinref part="U7" gate="G$1" pin="REFP"/>
<wire x1="226.06" y1="132.08" x2="193.04" y2="132.08" width="0.1524" layer="91"/>
</segment>
</net>
<net name="CAM1_PDN" class="0">
<segment>
<pinref part="U7" gate="G$1" pin="PDN"/>
<wire x1="193.04" y1="129.54" x2="200.66" y2="129.54" width="0.1524" layer="91"/>
<label x="200.66" y="129.54" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="CAM1_AVID" class="0">
<segment>
<pinref part="U7" gate="G$1" pin="AVID"/>
<wire x1="193.04" y1="124.46" x2="200.66" y2="124.46" width="0.1524" layer="91"/>
<label x="200.66" y="124.46" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="CAM1_HSYNC" class="0">
<segment>
<pinref part="U7" gate="G$1" pin="HSYNC"/>
<wire x1="193.04" y1="121.92" x2="200.66" y2="121.92" width="0.1524" layer="91"/>
<label x="200.66" y="121.92" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="CAM1_VSYNC" class="0">
<segment>
<pinref part="U7" gate="G$1" pin="VSYNC/PALI"/>
<wire x1="200.66" y1="119.38" x2="193.04" y2="119.38" width="0.1524" layer="91"/>
<label x="200.66" y="119.38" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="CAM1_OUT7" class="0">
<segment>
<pinref part="U7" gate="G$1" pin="YOUT7/I2CSEL"/>
<label x="129.54" y="116.84" size="1.27" layer="95" rot="R180" xref="yes"/>
<wire x1="129.54" y1="116.84" x2="134.62" y2="116.84" width="0.1524" layer="91"/>
<pinref part="R17" gate="G$1" pin="P$2"/>
<wire x1="134.62" y1="116.84" x2="152.4" y2="116.84" width="0.1524" layer="91"/>
<wire x1="134.62" y1="96.52" x2="134.62" y2="116.84" width="0.1524" layer="91"/>
<junction x="134.62" y="116.84"/>
</segment>
</net>
<net name="CAM1_OUT6" class="0">
<segment>
<pinref part="U7" gate="G$1" pin="YOUT6"/>
<wire x1="152.4" y1="114.3" x2="129.54" y2="114.3" width="0.1524" layer="91"/>
<label x="129.54" y="114.3" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM1_OUT5" class="0">
<segment>
<pinref part="U7" gate="G$1" pin="YOUT5"/>
<wire x1="129.54" y1="111.76" x2="152.4" y2="111.76" width="0.1524" layer="91"/>
<label x="129.54" y="111.76" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM1_OUT4" class="0">
<segment>
<pinref part="U7" gate="G$1" pin="YOUT4"/>
<wire x1="152.4" y1="109.22" x2="129.54" y2="109.22" width="0.1524" layer="91"/>
<label x="129.54" y="109.22" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM1_OUT3" class="0">
<segment>
<pinref part="U7" gate="G$1" pin="YOUT3"/>
<wire x1="129.54" y1="106.68" x2="152.4" y2="106.68" width="0.1524" layer="91"/>
<label x="129.54" y="106.68" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM1_OUT2" class="0">
<segment>
<pinref part="U7" gate="G$1" pin="YOUT2"/>
<wire x1="152.4" y1="104.14" x2="129.54" y2="104.14" width="0.1524" layer="91"/>
<label x="129.54" y="104.14" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="MMOV" class="0">
<segment>
<pinref part="U7" gate="G$1" pin="YOUT1"/>
<wire x1="152.4" y1="101.6" x2="129.54" y2="101.6" width="0.1524" layer="91"/>
<label x="129.54" y="101.6" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM1_OUT0" class="0">
<segment>
<pinref part="U7" gate="G$1" pin="YOUT0"/>
<wire x1="152.4" y1="99.06" x2="129.54" y2="99.06" width="0.1524" layer="91"/>
<label x="129.54" y="99.06" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM1_SCLK" class="0">
<segment>
<pinref part="U7" gate="G$1" pin="SCLK"/>
<wire x1="152.4" y1="124.46" x2="149.86" y2="124.46" width="0.1524" layer="91"/>
<wire x1="149.86" y1="124.46" x2="149.86" y2="121.92" width="0.1524" layer="91"/>
<wire x1="149.86" y1="121.92" x2="147.32" y2="121.92" width="0.1524" layer="91"/>
<label x="147.32" y="121.92" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="CAM1" class="0">
<segment>
<pinref part="D8" gate="G$1" pin="P"/>
<pinref part="D7" gate="G$1" pin="N"/>
<pinref part="R15" gate="G$1" pin="P$2"/>
<wire x1="119.38" y1="147.32" x2="116.84" y2="147.32" width="0.1524" layer="91"/>
<junction x="116.84" y="147.32"/>
<wire x1="116.84" y1="147.32" x2="109.22" y2="147.32" width="0.1524" layer="91"/>
<label x="109.22" y="147.32" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="I2C_SDA" class="0">
<segment>
<pinref part="U6" gate="G$1" pin="SDA"/>
<wire x1="111.76" y1="30.48" x2="104.14" y2="30.48" width="0.1524" layer="91"/>
<label x="111.76" y="30.48" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U7" gate="G$1" pin="SDA"/>
<wire x1="200.66" y1="114.3" x2="193.04" y2="114.3" width="0.1524" layer="91"/>
<label x="200.66" y="114.3" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="I2C_SCL" class="0">
<segment>
<pinref part="U6" gate="G$1" pin="SCL"/>
<wire x1="104.14" y1="27.94" x2="111.76" y2="27.94" width="0.1524" layer="91"/>
<label x="111.76" y="27.94" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U7" gate="G$1" pin="SCL"/>
<wire x1="193.04" y1="111.76" x2="200.66" y2="111.76" width="0.1524" layer="91"/>
<label x="200.66" y="111.76" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="6.3" minversion="6.2.2" severity="warning">
Since Version 6.2.2 text objects can contain more than one line,
which will not be processed correctly with this version.
</note>
</compatibility>
</eagle>
