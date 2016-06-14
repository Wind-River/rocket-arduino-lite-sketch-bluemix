cxxflags-y += ${PROJECTINCLUDE}
cxxflags-y += -I$(srctree)/drivers
cxxflags-y += -I${PROJECT_ROOT}/arduino-lite -include ${PROJECT_ROOT}/arduino-lite/Arduino-lite.h
cxxflags-y += -I${PROJECT_ROOT}/arduino-lite/wiring-lite
cxxflags-y += -I${PROJECT_ROOT}/arduino-lite/wiring-lite/rocket/common
cxxflags-y += -I${PROJECT_ROOT}/arduino-lite/wiring-lite/rocket/intel-galieo-gen2
cxxflags-y += -I${PROJECT_ROOT}/arduino-lite/wiring-lite/rocket/nxp-frdm-k64f
cxxflags-y += -I${PROJECT_ROOT}/arduino-lite/libraries/MqttClient
cxxflags-y += -I${PROJECT_ROOT}/arduino-lite/libraries/MqttClient/rocket
cxxflags-y += -I${PROJECT_ROOT}/arduino-lite/paho/MQTTClient-C/src
cxxflags-y += -I${PROJECT_ROOT}/arduino-lite/paho/MQTTPacket/src
cxxflags-y += -I${PROJECT_ROOT}/arduino-lite/libraries/Ethernet/
cxxflags-y += -I${PROJECT_ROOT}/arduino-lite/libraries/Ethernet/rocket
cxxflags-y += -I${PROJECT_ROOT}/arduino-lite/libraries/Ethernet/rocket/lwip-nosys
cxxflags-y += -I${PROJECT_ROOT}/arduino-lite/libraries/Ethernet/rocket/intel-galileo-gen2
cxxflags-y += -I${PROJECT_ROOT}/arduino-lite/libraries/Ethernet/rocket/nxp-frdm-k64f
cxxflags-y += -I${PROJECT_ROOT}/arduino-lite/lwip/src/include
cxxflags-y += -I${PROJECT_ROOT}/arduino-lite/
cxxflags-y += -I${PROJECT_ROOT}/arduino-lite/libraries/BluemixClient
cxxflags-y += -I${PROJECT_ROOT}/arduino-lite/libraries/BluemixClient/rocket
cxxflags-y += -I${PROJECT_ROOT}/lwip/src/include




#
# This will pull in all source files present in the src directory
#
main_SOURCES = $(notdir $(wildcard $(PROJECT_ROOT)/application/src/*.cpp))
main_OBJS = $(patsubst %.cpp, %.o, $(main_SOURCES))

obj-y += $(main_OBJS)
