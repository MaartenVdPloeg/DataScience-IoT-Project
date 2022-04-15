# DataScience-IoT-Project, Measuring Temperature, Humidity and CO2 ppm with an ESP-8266, DHT22 and a MHZ19.

![ESP8226_DHT22_MHZ19](https://user-images.githubusercontent.com/103762292/163602142-9362232b-c31f-4ccc-9905-40ef79275244.jpg)

This project uses two sensors and uploads the values to the io.adafruit cloud using the MQTT protocol. The data that is generated will be uploaded to the io.adafruit cloud service to analyze the data in realtime and in further detail.
There will be 3 values uploaded and you can use the io.adafruit analytical tools to display these to your own personal preference. 

Follow the link [here](https://io.adafruit.com/Shaolu/dashboards/temperature-and-humidity) to view my example page on io.adafruit.

## MHZ-19 CO2 Sensor

A brief explanation of the MHZ19 CO2 sensor:

> *"A nondispersive infrared sensor (or NDIR sensor) is a relatively simple spectroscopic sensor often used as a gas detector. It is nondispersive in the sense of optical dispersion since the infrared energy is allowed to pass through the atmospheric sampling chamber without deformation.
Principle of operation:
The main components of an NDIR sensor are an infrared source (lamp), a sample chamber or light tube, a light filter and an infrared detector. The IR light is directed through the sample chamber towards the detector. In parallel there is another chamber with an enclosed reference gas, typically nitrogen. The gas in the sample chamber causes absorption of specific wavelengths according to the Beer–Lambert law, and the attenuation of these wavelengths is measured by the detector to determine the gas concentration. The detector has an optical filter in front of it that eliminates all light except the wavelength that the selected gas molecules can absorb."* 

Retrieved from: https://www.circuits.dk/testing-mh-z19-ndir-co2-sensor-module/

You can find the data sheet for the MHZ-19 CO2 sensor [here.](https://www.winsen-sensor.com/d/files/infrared-gas-sensor/mh-z19b-co2-ver1_0.pdf)

## DHT-22 Temperature & Humidity Sensor

A brief explanation of the DHT-22 sensor:

> *"The DHT22 is a basic, low-cost digital temperature and humidity sensor. It uses a capacitive humidity sensor and a thermistor to measure the surrounding air and spits out a digital signal on the data pin (no analog input pins needed). It's fairly simple to use but requires careful timing to grab data. The only real downside of this sensor is you can only get new data from it once every 2 seconds, so when using our library, sensor readings can be up to 2 seconds old."*

Retrieved from: https://www.adafruit.com/product/385

You can find the data sheet for the DHT-22 sensor [here.](https://www.sparkfun.com/datasheets/Sensors/Temperature/DHT22.pdf)

## Why MQTT is suitable for IoT applications

Using the MQTT protocol has certain benefits as described briefly below:

> *Residing on top of the TCP/IP network stack, MQTT is a lightweight publish/subscribe messaging protocol designed for low-bandwidth, high latency, unreliable networks. MQTT's features make it an excellent option for sending high volumes of sensor messages to analytics platforms and cloud solutions.*

Retrieved from: https://behrtech.com/blog/mqtt-in-the-iot-architecture/

## How to build this project?

### Hardware required

![project_parts](https://user-images.githubusercontent.com/103762292/163607917-80506998-b1e0-41a8-b5e2-9f509635acbf.jpg)

  - ESP-8266
  - DHT-22 Sensor
  - MHZ-19 Sensor
  - Breadboard(s)
  - Jumper wires
  - Micro-USB cable capable of sync (not just charging capability)

### Software

  - Adafruit IO
  - Arduino IDE

## Connect the components to the ESP8266

#### MHZ-19 pin connections: 

- PWM pin -> D5 pin
- Vin pin -> 3.3V pin
- GND pin -> GND pin

#### DHT-22 pin connections:

- Data pin -> D6
- Vin pin -> 3.3V pin
- GND pin -> GND pin

## Connect the components to the ESP8266
