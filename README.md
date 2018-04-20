# Touchberry_Thumper_Project
![Demonstration](https://github.com/Treagle350/Touchberry/blob/master/Demonstration.gif)

With this code you can cycle chronologically from 5 red values to 5 green values to 5 blue values, pressing the A button cycles through these colors. Pressing the arrow keys applies a color filter on top of these color values to shift them into a different color spectrum. X and B control the brightness of the LEDs.
## Additional information about the code
```
This code was made using the following course, extra information about the project can be found here : 
https://bioboost.gitbooks.io/embedded-systems-course/content/assignments/week_7.html
```
-----------------------------------------------------------------------------------------------------------------
## Hardware
```
You'll need :
a)A computer running a linux distro, the commands specified below are to be entered in a terminal inside that computer
b)A RaspberryPi running a debian distro
c)A TouchberryPi shield, more information can be found at :
https://circuitmaker.com/Projects/Details/Sille-Van-Landschoot-2/TouchBerry-Pi
```
------------------------------------------------------------------------------------------------------------------
## Dependencies : 

`sudo apt-get update && sudo apt-get install git build-essential autoconf automake libtool libcurl4-gnutls-dev`
```
You'll also need to enable I2C on the raspberryPi using :
sudo raspi-config
This will present you with a graphical user interface
Select Interfacing Options
Select I2C
Select Yes, when prompted if you want to enable I2C

Also don't forget to install the i2c-tools with :
sudo apt-get install i2c-tools
```
----------------------------------------------------------------------------------------------------------------
## Downloading the repository :
```
git clone https://github.com/Treagle350/Touchberry.git
```
-------------------------------------------------------------------------------------------------------------------
## Downloading the RESTclient-library :

```
sudo su
cd /usr/local/src
git clone https://github.com/mrtazz/restclient-cpp.git
cd restclient-cpp
./autogen.sh
./configure
make install
ldconfig
exit
```
------------------------------------------------------------------------------------------------------------------------------

## Compiling the program :
The makefile was designed as to have the code natively compiled on the Raspberry Pi itself
```
cd Touchberry
make clean
make
```
------------------------------------------------------------------------------------------------------------------------------
## Executing the application : 

`./bin/touchshield`
