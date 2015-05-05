"""autogenerated by genpy from ardrone_autonomy/navdata_demo.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import std_msgs.msg

class navdata_demo(genpy.Message):
  _md5sum = "5f569653293c884e2ea43f113057d0ea"
  _type = "ardrone_autonomy/navdata_demo"
  _has_header = True #flag to mark the presence of a Header object
  _full_text = """Header header
float64 drone_time
uint16 tag
uint16 size
uint32 ctrl_state
uint32 vbat_flying_percentage
float32 theta
float32 phi
float32 psi
int32 altitude
float32 vx
float32 vy
float32 vz
uint32 num_frames
uint32 detection_camera_type

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.secs: seconds (stamp_secs) since epoch
# * stamp.nsecs: nanoseconds since stamp_secs
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

"""
  __slots__ = ['header','drone_time','tag','size','ctrl_state','vbat_flying_percentage','theta','phi','psi','altitude','vx','vy','vz','num_frames','detection_camera_type']
  _slot_types = ['std_msgs/Header','float64','uint16','uint16','uint32','uint32','float32','float32','float32','int32','float32','float32','float32','uint32','uint32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       header,drone_time,tag,size,ctrl_state,vbat_flying_percentage,theta,phi,psi,altitude,vx,vy,vz,num_frames,detection_camera_type

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(navdata_demo, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.drone_time is None:
        self.drone_time = 0.
      if self.tag is None:
        self.tag = 0
      if self.size is None:
        self.size = 0
      if self.ctrl_state is None:
        self.ctrl_state = 0
      if self.vbat_flying_percentage is None:
        self.vbat_flying_percentage = 0
      if self.theta is None:
        self.theta = 0.
      if self.phi is None:
        self.phi = 0.
      if self.psi is None:
        self.psi = 0.
      if self.altitude is None:
        self.altitude = 0
      if self.vx is None:
        self.vx = 0.
      if self.vy is None:
        self.vy = 0.
      if self.vz is None:
        self.vz = 0.
      if self.num_frames is None:
        self.num_frames = 0
      if self.detection_camera_type is None:
        self.detection_camera_type = 0
    else:
      self.header = std_msgs.msg.Header()
      self.drone_time = 0.
      self.tag = 0
      self.size = 0
      self.ctrl_state = 0
      self.vbat_flying_percentage = 0
      self.theta = 0.
      self.phi = 0.
      self.psi = 0.
      self.altitude = 0
      self.vx = 0.
      self.vy = 0.
      self.vz = 0.
      self.num_frames = 0
      self.detection_camera_type = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_3I.pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_d2H2I3fi3f2I.pack(_x.drone_time, _x.tag, _x.size, _x.ctrl_state, _x.vbat_flying_percentage, _x.theta, _x.phi, _x.psi, _x.altitude, _x.vx, _x.vy, _x.vz, _x.num_frames, _x.detection_camera_type))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _struct_3I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 56
      (_x.drone_time, _x.tag, _x.size, _x.ctrl_state, _x.vbat_flying_percentage, _x.theta, _x.phi, _x.psi, _x.altitude, _x.vx, _x.vy, _x.vz, _x.num_frames, _x.detection_camera_type,) = _struct_d2H2I3fi3f2I.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_3I.pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_d2H2I3fi3f2I.pack(_x.drone_time, _x.tag, _x.size, _x.ctrl_state, _x.vbat_flying_percentage, _x.theta, _x.phi, _x.psi, _x.altitude, _x.vx, _x.vy, _x.vz, _x.num_frames, _x.detection_camera_type))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _struct_3I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 56
      (_x.drone_time, _x.tag, _x.size, _x.ctrl_state, _x.vbat_flying_percentage, _x.theta, _x.phi, _x.psi, _x.altitude, _x.vx, _x.vy, _x.vz, _x.num_frames, _x.detection_camera_type,) = _struct_d2H2I3fi3f2I.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_3I = struct.Struct("<3I")
_struct_d2H2I3fi3f2I = struct.Struct("<d2H2I3fi3f2I")
