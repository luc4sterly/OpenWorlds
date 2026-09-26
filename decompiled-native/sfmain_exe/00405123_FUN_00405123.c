// 00405123 FUN_00405123 [Global]
// programa: sfmain.exe

void __fastcall FUN_00405123(short *param_1,short param_2,short *param_3,undefined2 *param_4)

{
  undefined2 in_AX;
  int unaff_EBX;
  int iVar1;
  int local_30;
  undefined2 local_2c;
  int local_24;
  int local_20;
  undefined2 local_1c;
  undefined2 local_18;
  undefined2 local_14;
  int local_10;
  
  switch(in_AX) {
  case 0:
    local_10 = 0;
    do {
      *param_3 = (short)(*(short *)(unaff_EBX + (local_10 - param_2) * 2) * 0xccd + 0x4000 >> 0xf);
      iVar1 = (int)*param_1 - (int)*param_3;
      if (iVar1 < 0x7fff) {
        if (iVar1 < -0x7fff) {
          iVar1 = -0x8000;
        }
        local_18 = (undefined2)iVar1;
      }
      else {
        local_18 = 0x7fff;
      }
      param_1 = param_1 + 1;
      param_3 = param_3 + 1;
      local_10 = local_10 + 1;
      *param_4 = local_18;
      param_4 = param_4 + 1;
    } while (local_10 < 0x28);
    break;
  case 1:
    local_24 = 0;
    do {
      *param_3 = (short)(*(short *)(unaff_EBX + (local_24 - param_2) * 2) * 0x2ccd + 0x4000 >> 0xf);
      iVar1 = (int)*param_1 - (int)*param_3;
      if (iVar1 < 0x7fff) {
        if (iVar1 < -0x7fff) {
          iVar1 = -0x8000;
        }
        local_14 = (undefined2)iVar1;
      }
      else {
        local_14 = 0x7fff;
      }
      param_1 = param_1 + 1;
      *param_4 = local_14;
      param_3 = param_3 + 1;
      local_24 = local_24 + 1;
      param_4 = param_4 + 1;
    } while (local_24 < 0x28);
    break;
  case 2:
    local_20 = 0;
    do {
      *param_3 = (short)(*(short *)(unaff_EBX + (local_20 - param_2) * 2) * 0x5333 + 0x4000 >> 0xf);
      iVar1 = (int)*param_1 - (int)*param_3;
      if (iVar1 < 0x7fff) {
        if (iVar1 < -0x7fff) {
          iVar1 = -0x8000;
        }
        local_2c = (undefined2)iVar1;
      }
      else {
        local_2c = 0x7fff;
      }
      param_1 = param_1 + 1;
      param_3 = param_3 + 1;
      local_20 = local_20 + 1;
      *param_4 = local_2c;
      param_4 = param_4 + 1;
    } while (local_20 < 0x28);
    break;
  case 3:
    local_30 = 0;
    do {
      *param_3 = (short)(*(short *)(unaff_EBX + (local_30 - param_2) * 2) * 0x7fff + 0x4000 >> 0xf);
      iVar1 = (int)*param_1 - (int)*param_3;
      if (iVar1 < 0x7fff) {
        if (iVar1 < -0x7fff) {
          iVar1 = -0x8000;
        }
        local_1c = (undefined2)iVar1;
      }
      else {
        local_1c = 0x7fff;
      }
      param_1 = param_1 + 1;
      *param_4 = local_1c;
      param_3 = param_3 + 1;
      local_30 = local_30 + 1;
      param_4 = param_4 + 1;
    } while (local_30 < 0x28);
  }
  return;
}


