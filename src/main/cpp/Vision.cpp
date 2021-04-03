#include "Vision.h"

Vision::Vision()
{
}
void Vision::AutoTarget()
{
  nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("ledMode", 3);
  double targetX = ITable->GetNumber("tx", 0.0);

  double aim_error = targetX;
  float Kp = 0.1;
  float correction = targetX * Kp;

  if (aim_error > 0.01f)
  {
    spin.Set(correction);
  }else if (aim_error < -0.01f)
  {
    spin.Set(correction);
  }else
  {
    spin.Set(0);
  }
}

void Vision::visionStop()
{
    nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("ledMode", 1);
  spin.Set(0);

}

void Vision::leftManual()
{
  spin.Set(5);
}

void Vision::rightManual()
{
  spin.Set(-5);
}
