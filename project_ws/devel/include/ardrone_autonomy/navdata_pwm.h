/* Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of Willow Garage, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Auto-generated by genmsg_cpp from file /home/eduardorz/project_ws/src/ardrone_autonomy/msg/navdata_pwm.msg
 *
 */


#ifndef ARDRONE_AUTONOMY_MESSAGE_NAVDATA_PWM_H
#define ARDRONE_AUTONOMY_MESSAGE_NAVDATA_PWM_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace ardrone_autonomy
{
template <class ContainerAllocator>
struct navdata_pwm_
{
  typedef navdata_pwm_<ContainerAllocator> Type;

  navdata_pwm_()
    : header()
    , drone_time(0.0)
    , tag(0)
    , size(0)
    , motor1(0)
    , motor2(0)
    , motor3(0)
    , motor4(0)
    , sat_motor1(0)
    , sat_motor2(0)
    , sat_motor3(0)
    , sat_motor4(0)
    , gaz_feed_forward(0.0)
    , gaz_altitude(0.0)
    , altitude_integral(0.0)
    , vz_ref(0.0)
    , u_pitch(0)
    , u_roll(0)
    , u_yaw(0)
    , yaw_u_I(0.0)
    , u_pitch_planif(0)
    , u_roll_planif(0)
    , u_yaw_planif(0)
    , u_gaz_planif(0.0)
    , current_motor1(0)
    , current_motor2(0)
    , current_motor3(0)
    , current_motor4(0)
    , altitude_der(0.0)  {
    }
  navdata_pwm_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , drone_time(0.0)
    , tag(0)
    , size(0)
    , motor1(0)
    , motor2(0)
    , motor3(0)
    , motor4(0)
    , sat_motor1(0)
    , sat_motor2(0)
    , sat_motor3(0)
    , sat_motor4(0)
    , gaz_feed_forward(0.0)
    , gaz_altitude(0.0)
    , altitude_integral(0.0)
    , vz_ref(0.0)
    , u_pitch(0)
    , u_roll(0)
    , u_yaw(0)
    , yaw_u_I(0.0)
    , u_pitch_planif(0)
    , u_roll_planif(0)
    , u_yaw_planif(0)
    , u_gaz_planif(0.0)
    , current_motor1(0)
    , current_motor2(0)
    , current_motor3(0)
    , current_motor4(0)
    , altitude_der(0.0)  {
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef double _drone_time_type;
  _drone_time_type drone_time;

   typedef uint16_t _tag_type;
  _tag_type tag;

   typedef uint16_t _size_type;
  _size_type size;

   typedef uint8_t _motor1_type;
  _motor1_type motor1;

   typedef uint8_t _motor2_type;
  _motor2_type motor2;

   typedef uint8_t _motor3_type;
  _motor3_type motor3;

   typedef uint8_t _motor4_type;
  _motor4_type motor4;

   typedef uint8_t _sat_motor1_type;
  _sat_motor1_type sat_motor1;

   typedef uint8_t _sat_motor2_type;
  _sat_motor2_type sat_motor2;

   typedef uint8_t _sat_motor3_type;
  _sat_motor3_type sat_motor3;

   typedef uint8_t _sat_motor4_type;
  _sat_motor4_type sat_motor4;

   typedef float _gaz_feed_forward_type;
  _gaz_feed_forward_type gaz_feed_forward;

   typedef float _gaz_altitude_type;
  _gaz_altitude_type gaz_altitude;

   typedef float _altitude_integral_type;
  _altitude_integral_type altitude_integral;

   typedef float _vz_ref_type;
  _vz_ref_type vz_ref;

   typedef int32_t _u_pitch_type;
  _u_pitch_type u_pitch;

   typedef int32_t _u_roll_type;
  _u_roll_type u_roll;

   typedef int32_t _u_yaw_type;
  _u_yaw_type u_yaw;

   typedef float _yaw_u_I_type;
  _yaw_u_I_type yaw_u_I;

   typedef int32_t _u_pitch_planif_type;
  _u_pitch_planif_type u_pitch_planif;

   typedef int32_t _u_roll_planif_type;
  _u_roll_planif_type u_roll_planif;

   typedef int32_t _u_yaw_planif_type;
  _u_yaw_planif_type u_yaw_planif;

   typedef float _u_gaz_planif_type;
  _u_gaz_planif_type u_gaz_planif;

   typedef uint16_t _current_motor1_type;
  _current_motor1_type current_motor1;

   typedef uint16_t _current_motor2_type;
  _current_motor2_type current_motor2;

   typedef uint16_t _current_motor3_type;
  _current_motor3_type current_motor3;

   typedef uint16_t _current_motor4_type;
  _current_motor4_type current_motor4;

   typedef float _altitude_der_type;
  _altitude_der_type altitude_der;




  typedef boost::shared_ptr< ::ardrone_autonomy::navdata_pwm_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ardrone_autonomy::navdata_pwm_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;

}; // struct navdata_pwm_

typedef ::ardrone_autonomy::navdata_pwm_<std::allocator<void> > navdata_pwm;

typedef boost::shared_ptr< ::ardrone_autonomy::navdata_pwm > navdata_pwmPtr;
typedef boost::shared_ptr< ::ardrone_autonomy::navdata_pwm const> navdata_pwmConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ardrone_autonomy::navdata_pwm_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ardrone_autonomy::navdata_pwm_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ardrone_autonomy

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/hydro/share/std_msgs/cmake/../msg'], 'ardrone_autonomy': ['/home/eduardorz/project_ws/src/ardrone_autonomy/msg'], 'geometry_msgs': ['/opt/ros/hydro/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ardrone_autonomy::navdata_pwm_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ardrone_autonomy::navdata_pwm_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ardrone_autonomy::navdata_pwm_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ardrone_autonomy::navdata_pwm_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ardrone_autonomy::navdata_pwm_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ardrone_autonomy::navdata_pwm_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ardrone_autonomy::navdata_pwm_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6369e637a869960c68d7de5c2e10d6b1";
  }

  static const char* value(const ::ardrone_autonomy::navdata_pwm_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6369e637a869960cULL;
  static const uint64_t static_value2 = 0x68d7de5c2e10d6b1ULL;
};

template<class ContainerAllocator>
struct DataType< ::ardrone_autonomy::navdata_pwm_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ardrone_autonomy/navdata_pwm";
  }

  static const char* value(const ::ardrone_autonomy::navdata_pwm_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ardrone_autonomy::navdata_pwm_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
float64 drone_time\n\
uint16 tag\n\
uint16 size\n\
uint8 motor1\n\
uint8 motor2\n\
uint8 motor3\n\
uint8 motor4\n\
uint8 sat_motor1\n\
uint8 sat_motor2\n\
uint8 sat_motor3\n\
uint8 sat_motor4\n\
float32 gaz_feed_forward\n\
float32 gaz_altitude\n\
float32 altitude_integral\n\
float32 vz_ref\n\
int32 u_pitch\n\
int32 u_roll\n\
int32 u_yaw\n\
float32 yaw_u_I\n\
int32 u_pitch_planif\n\
int32 u_roll_planif\n\
int32 u_yaw_planif\n\
float32 u_gaz_planif\n\
uint16 current_motor1\n\
uint16 current_motor2\n\
uint16 current_motor3\n\
uint16 current_motor4\n\
float32 altitude_der\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::ardrone_autonomy::navdata_pwm_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ardrone_autonomy::navdata_pwm_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.drone_time);
      stream.next(m.tag);
      stream.next(m.size);
      stream.next(m.motor1);
      stream.next(m.motor2);
      stream.next(m.motor3);
      stream.next(m.motor4);
      stream.next(m.sat_motor1);
      stream.next(m.sat_motor2);
      stream.next(m.sat_motor3);
      stream.next(m.sat_motor4);
      stream.next(m.gaz_feed_forward);
      stream.next(m.gaz_altitude);
      stream.next(m.altitude_integral);
      stream.next(m.vz_ref);
      stream.next(m.u_pitch);
      stream.next(m.u_roll);
      stream.next(m.u_yaw);
      stream.next(m.yaw_u_I);
      stream.next(m.u_pitch_planif);
      stream.next(m.u_roll_planif);
      stream.next(m.u_yaw_planif);
      stream.next(m.u_gaz_planif);
      stream.next(m.current_motor1);
      stream.next(m.current_motor2);
      stream.next(m.current_motor3);
      stream.next(m.current_motor4);
      stream.next(m.altitude_der);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct navdata_pwm_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ardrone_autonomy::navdata_pwm_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ardrone_autonomy::navdata_pwm_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "drone_time: ";
    Printer<double>::stream(s, indent + "  ", v.drone_time);
    s << indent << "tag: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.tag);
    s << indent << "size: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.size);
    s << indent << "motor1: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.motor1);
    s << indent << "motor2: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.motor2);
    s << indent << "motor3: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.motor3);
    s << indent << "motor4: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.motor4);
    s << indent << "sat_motor1: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.sat_motor1);
    s << indent << "sat_motor2: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.sat_motor2);
    s << indent << "sat_motor3: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.sat_motor3);
    s << indent << "sat_motor4: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.sat_motor4);
    s << indent << "gaz_feed_forward: ";
    Printer<float>::stream(s, indent + "  ", v.gaz_feed_forward);
    s << indent << "gaz_altitude: ";
    Printer<float>::stream(s, indent + "  ", v.gaz_altitude);
    s << indent << "altitude_integral: ";
    Printer<float>::stream(s, indent + "  ", v.altitude_integral);
    s << indent << "vz_ref: ";
    Printer<float>::stream(s, indent + "  ", v.vz_ref);
    s << indent << "u_pitch: ";
    Printer<int32_t>::stream(s, indent + "  ", v.u_pitch);
    s << indent << "u_roll: ";
    Printer<int32_t>::stream(s, indent + "  ", v.u_roll);
    s << indent << "u_yaw: ";
    Printer<int32_t>::stream(s, indent + "  ", v.u_yaw);
    s << indent << "yaw_u_I: ";
    Printer<float>::stream(s, indent + "  ", v.yaw_u_I);
    s << indent << "u_pitch_planif: ";
    Printer<int32_t>::stream(s, indent + "  ", v.u_pitch_planif);
    s << indent << "u_roll_planif: ";
    Printer<int32_t>::stream(s, indent + "  ", v.u_roll_planif);
    s << indent << "u_yaw_planif: ";
    Printer<int32_t>::stream(s, indent + "  ", v.u_yaw_planif);
    s << indent << "u_gaz_planif: ";
    Printer<float>::stream(s, indent + "  ", v.u_gaz_planif);
    s << indent << "current_motor1: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.current_motor1);
    s << indent << "current_motor2: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.current_motor2);
    s << indent << "current_motor3: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.current_motor3);
    s << indent << "current_motor4: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.current_motor4);
    s << indent << "altitude_der: ";
    Printer<float>::stream(s, indent + "  ", v.altitude_der);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ARDRONE_AUTONOMY_MESSAGE_NAVDATA_PWM_H
