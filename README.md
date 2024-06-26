# 2023-24-Dash
2023-24 Dash


# Current Notes:
<details>
  This revision has not been compiled, nor flashed to the ESP. 
  Comments starting with LOOK INTO -> are lines or chunks of code with components that need deeper understanding or can be improved. Riley/Henry here would be a good place to start.
</details>

# Hardware
## Can Transceiver (MCP2561/2FD)
[Data Sheet](https://ww1.microchip.com/downloads/en/DeviceDoc/20005284A.pdf)  
Libraries may be redundant, Copied from [2022-23-Dash](https://github.com/mstfsae/2023-Dash)  
<details>
  <summary>Libraries</summary>
    
  ### CAN.h
  [Download](https://www.arduino.cc/reference/en/libraries/can/)  
  [GitHub/Docs/Examples](https://github.com/sandeepmistry/arduino-CAN?tab=readme-ov-file) 
  This appears to not be used unless another library is dependent on it.
  
  ### CAN_config.h
  unfinished
  
  ### ESP32CAN.h
  [GitHub](https://github.com/miwagner/ESP32-Arduino-CAN/tree/master)
  
  ### can_regdef.h
  unfinished  

</details>

## Analog to Digital Converter (ADS869x)
[Data Sheet](https://www.ti.com/lit/ds/symlink/ads8698.pdf?ts=1708044397958)  
we're gonna have to get \*creative\* with this one

## Microcontroller Unit (ESP32-S3-MINI-x)
[Data Sheet](https://www.espressif.com/sites/default/files/documentation/esp32-s3-mini-1_mini-1u_datasheet_en.pdf)  
lost


## Display (NHD-4.3-480272FT-CSXP-T)
[Store Page](https://newhavendisplay.com/4-3-inch-ips-480x272px-eve2-resistive-tft/)  
<details>

  <summary>Resources</summary>

  [FT81x advanced embedded video engine datasheet](https://support.newhavendisplay.com/hc/en-us/article_attachments/6963168242711)  
  [FT800 Example with Arduino](https://www.ftdichip.com/Support/Documents/AppNotes/AN_275_FT800_Example_with_Arduino.pdf)  
  [FT800 Arduino Library Docs](https://www.ftdichip.com/Support/Documents/AppNotes/AN_318_Arduino_Library_For_FT800_Series.pdf)  
  [Emulator Library Docs](https://www.ftdichip.com/Support/Documents/AppNotes/AN_281_FT800_Emulator_Library_User_Guide.pdf)  
  [Programmers Guide](https://www.ftdichip.com/Support/Documents/ProgramGuides/FT800%20Programmers%20Guide.pdf)  
  [Another Guide](https://newhavendisplay.com/blog/using-gameduino-2-library-with-eve2-tft-modules/)  
  [Gameduino2 Library](https://github.com/jamesbowman/gd2-lib)  
  
</details>

## SPI interface
unfinished
