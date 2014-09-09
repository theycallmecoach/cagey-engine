set(CageyMath_HEADERS
  BaseAngle.hh
  Constants.hh
  Degree.hh
  MathFwd.hh
  Radian.hh
  Util.hh
  Vector.hh
  Matrix.hh)

add_custom_target(CageyMath SOURCES ${CageyMath_HEADERS})
