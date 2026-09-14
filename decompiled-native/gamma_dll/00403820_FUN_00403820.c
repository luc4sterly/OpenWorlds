// 00403820 FUN_00403820 [Global]
// programa: gamma.dll

undefined4 * __cdecl
FUN_00403820(undefined4 *param_1,int *param_2,int param_3,byte param_4,byte *param_5,int param_6,
            byte *param_7,int param_8)

{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  uint uVar4;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_18;
  ushort local_14;
  
  local_18 = 0;
  if (param_6 + param_8 < *(int *)(param_3 + 0x2c)) {
    local_18 = *(int *)(param_3 + 0x2c) - (param_6 + param_8);
  }
  local_14 = *(ushort *)(param_3 + 0x30) & 0xb0;
  if (((local_14 != 0x20) && (local_14 != 0x10)) && (local_38 = 0, 0 < local_18)) {
    do {
      bVar3 = false;
      if (param_2 != (int *)0x0) {
        if ((uint)param_2[5] < (uint)param_2[6]) {
          pbVar2 = (byte *)param_2[5];
          param_2[5] = param_2[5] + 1;
          *pbVar2 = param_4;
          uVar4 = (uint)*pbVar2;
        }
        else {
          uVar4 = (**(code **)(*param_2 + 0x30))(param_4);
        }
        if (uVar4 == 0xffffffff) {
          bVar3 = true;
        }
      }
      if (bVar3) {
        param_2 = (int *)0x0;
      }
      local_38 = local_38 + 1;
    } while (local_38 < local_18);
  }
  local_2c = 0;
  if (0 < param_6) {
    do {
      bVar3 = false;
      bVar1 = *param_5;
      param_5 = param_5 + 1;
      if (param_2 != (int *)0x0) {
        if ((uint)param_2[5] < (uint)param_2[6]) {
          pbVar2 = (byte *)param_2[5];
          param_2[5] = param_2[5] + 1;
          *pbVar2 = bVar1;
          uVar4 = (uint)*pbVar2;
        }
        else {
          uVar4 = (**(code **)(*param_2 + 0x30))(bVar1);
        }
        if (uVar4 == 0xffffffff) {
          bVar3 = true;
        }
      }
      if (bVar3) {
        param_2 = (int *)0x0;
      }
      local_2c = local_2c + 1;
    } while (local_2c < param_6);
  }
  if ((local_14 == 0x10) && (local_34 = 0, 0 < local_18)) {
    do {
      bVar3 = false;
      if (param_2 != (int *)0x0) {
        if ((uint)param_2[5] < (uint)param_2[6]) {
          pbVar2 = (byte *)param_2[5];
          param_2[5] = param_2[5] + 1;
          *pbVar2 = param_4;
          uVar4 = (uint)*pbVar2;
        }
        else {
          uVar4 = (**(code **)(*param_2 + 0x30))(param_4);
        }
        if (uVar4 == 0xffffffff) {
          bVar3 = true;
        }
      }
      if (bVar3) {
        param_2 = (int *)0x0;
      }
      local_34 = local_34 + 1;
    } while (local_34 < local_18);
  }
  local_28 = 0;
  if (0 < param_8) {
    do {
      bVar3 = false;
      bVar1 = *param_7;
      param_7 = param_7 + 1;
      if (param_2 != (int *)0x0) {
        if ((uint)param_2[5] < (uint)param_2[6]) {
          pbVar2 = (byte *)param_2[5];
          param_2[5] = param_2[5] + 1;
          *pbVar2 = bVar1;
          uVar4 = (uint)*pbVar2;
        }
        else {
          uVar4 = (**(code **)(*param_2 + 0x30))(bVar1);
        }
        if (uVar4 == 0xffffffff) {
          bVar3 = true;
        }
      }
      if (bVar3) {
        param_2 = (int *)0x0;
      }
      local_28 = local_28 + 1;
    } while (local_28 < param_8);
  }
  if ((local_14 == 0x20) && (local_30 = 0, 0 < local_18)) {
    do {
      bVar3 = false;
      if (param_2 != (int *)0x0) {
        if ((uint)param_2[5] < (uint)param_2[6]) {
          pbVar2 = (byte *)param_2[5];
          param_2[5] = param_2[5] + 1;
          *pbVar2 = param_4;
          uVar4 = (uint)*pbVar2;
        }
        else {
          uVar4 = (**(code **)(*param_2 + 0x30))(param_4);
        }
        if (uVar4 == 0xffffffff) {
          bVar3 = true;
        }
      }
      if (bVar3) {
        param_2 = (int *)0x0;
      }
      local_30 = local_30 + 1;
    } while (local_30 < local_18);
  }
  *(undefined4 *)(param_3 + 0x2c) = 0;
  *param_1 = param_2;
  return param_1;
}


