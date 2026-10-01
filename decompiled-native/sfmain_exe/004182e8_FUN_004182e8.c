// 004182e8 FUN_004182e8 [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_004182e8(undefined4 param_1,undefined4 param_2)

{
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_24;
  int local_20;
  
  local_20 = 0;
  if (DAT_0043d584 == 0) {
    if (DAT_0043d574 == 0) {
      if (DAT_0043d570 == 0) {
        if (DAT_0043d568 == 0 && DAT_0043d57c == 0) {
          local_24 = 0xb4;
        }
        else {
          local_24 = 0xa0;
        }
      }
      else {
        local_24 = 0xa0;
      }
    }
    else {
      local_24 = 0xb4;
    }
    local_20 = local_24 * DAT_0043d700;
    if (DAT_0043d560 != 0) {
      local_20 = local_20 * 2;
    }
    if (DAT_0043d564 != 0) {
      local_20 = local_20 * 3;
    }
    if (DAT_0043d56c != 0) {
      local_20 = local_20 * 2 + -4;
    }
    if ((DAT_0043d5d4 == 0) && (DAT_0043d69c == 0x2b11)) {
      local_20 = (local_20 * 0x2b11) / 8000;
    }
  }
  else if (DAT_0043d584 < 2) {
    if ((DAT_0043d568 == 0 && DAT_0043d570 == 0) && DAT_0043d56c == 0) {
      local_38 = 0x140;
    }
    else {
      local_38 = 0x280;
    }
    local_20 = local_38;
  }
  else if (DAT_0043d584 == 2) {
    if (DAT_0043d5b4 == 0) {
      if ((DAT_0043d568 == 0 && DAT_0043d570 == 0) && DAT_0043d56c == 0) {
        local_34 = 0x1e0;
      }
      else {
        local_34 = 0x280;
      }
      local_20 = local_34;
    }
    else {
      if (DAT_0043d570 == 0) {
        if (DAT_0043d568 == 0) {
          local_2c = 0x1e0;
        }
        else {
          local_2c = 0x640;
        }
        local_30 = local_2c;
      }
      else {
        local_30 = 0x640;
      }
      local_20 = local_30;
    }
  }
  return CONCAT44(param_2,local_20);
}


