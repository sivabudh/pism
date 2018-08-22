#pragma once

using PumpID = int;

namespace PITHUNDER {
  struct Messages
  {
    PumpID pumpId;

    PumpID m_unit_id()   // To mimic the real Messages members
    {
      return pumpId;
    }
  };
}

struct PumpServiceRequest
{
  PumpID pumpId;
};


