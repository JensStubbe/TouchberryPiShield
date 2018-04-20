#pragma once
#include "restclient-cpp/restclient.h"
#include <iostream>

namespace thumper_rest_request{
  class Thumper_REST_Request{
    public:
      Thumper_REST_Request();
      //void print_battery_voltage();
      void set_motor_drive(int left_motor,int right_motor);
      void set_rgb_color_leds(int R,int G,int B);

    private:
      void send_data(std::string url, std::string json);
      //RestClient::Response receive_data(std::string url);
      std::string base_url = "http://192.168.0.100:3000";
      std::string rgb_leds_url_offset = "/neopixels/strings/0";
      std::string motor_url_offset = "/speed";
      std::string battery_voltage_url_offset = "/batteryvoltage";
      std::string application = "application/json";
  };
}

