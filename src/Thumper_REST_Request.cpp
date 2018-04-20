#include "Thumper_REST_Request.h"

namespace thumper_rest_request{
  Thumper_REST_Request::Thumper_REST_Request(){
  }
  void Thumper_REST_Request::set_rgb_color_leds(int R,int G,int B){
    std::string current_url = base_url + rgb_leds_url_offset;
    std::string json = "{ \"red\":" + std::to_string(R) + ", \"green\":" + std::to_string(G) + ", \"blue\":" + std::to_string(B) + "}";
    send_data(current_url, json);
  }
  void Thumper_REST_Request::set_motor_drive(int left_motor,int right_motor){
    std::string current_url = base_url + motor_url_offset;
    std::string json = "{ \"left_speed\":" + std::to_string(right_motor) + ", \"right_speed\":" + std::to_string(left_motor) + "}";
    send_data(current_url, json);
  }
  /*void Thumper_REST_Request::print_battery_voltage(){
    std::string current_url = base_url + battery_voltage_url_offset;
    std::cout<<receive_data(current_url)<<std::endl;
  }*/
  void Thumper_REST_Request::send_data(std::string url, std::string json){
    RestClient::Response r = RestClient::post(url, application, json);
  }
  /*RestClient::Response Thumper_REST_Request::receive_data(std::string url){
    RestClient::Response r = RestClient::get(url);
    return r;
  }*/
}
