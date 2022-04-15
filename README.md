# DataScience-IoT-Project, Measuring Temperature, Humidity and CO2 ppm with an ESP-8266, DHT22 and a MHZ19.

![ESP8226_DHT22_MHZ19](https://user-images.githubusercontent.com/103762292/163602142-9362232b-c31f-4ccc-9905-40ef79275244.jpg)

This project uses two sensors and uploads the values to the io.adafruit cloud using the MQTT protocol. The data that is generated will be uploaded to the io.adafruit cloud service to analyze the data in realtime and in further detail.
There will be 3 values uploaded and you can use the io.adafruit analytical tools to display these to your own personal preference. 

Follow the link [here](https://io.adafruit.com/Shaolu/dashboards/temperature-and-humidity) to view my example page on io.adafruit.

### MHZ-19 CO2 Sensor

A brief explanation of the MHZ19 CO2 sensor:

> A nondispersive infrared sensor (or NDIR sensor) is a relatively simple spectroscopic sensor often used as a gas detector. It is nondispersive in the sense of optical dispersion since the infrared energy is allowed to pass through the atmospheric sampling chamber without deformation.
Principle of operation:
The main components of an NDIR sensor are an infrared source (lamp), a sample chamber or light tube, a light filter and an infrared detector. The IR light is directed through the sample chamber towards the detector. In parallel there is another chamber with an enclosed reference gas, typically nitrogen. The gas in the sample chamber causes absorption of specific wavelengths according to the Beer–Lambert law, and the attenuation of these wavelengths is measured by the detector to determine the gas concentration. The detector has an optical filter in front of it that eliminates all light except the wavelength that the selected gas molecules can absorb. 

Retrieved from: https://www.circuits.dk/testing-mh-z19-ndir-co2-sensor-module/
