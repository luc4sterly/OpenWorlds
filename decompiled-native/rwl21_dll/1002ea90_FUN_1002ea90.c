// 1002ea90 FUN_1002ea90 [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * __fastcall FUN_1002ea90(undefined4 param_1,undefined4 param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  char cVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 extraout_EDX;
  uint *extraout_EDX_00;
  uint *extraout_EDX_01;
  uint *extraout_EDX_02;
  uint *extraout_EDX_03;
  uint *extraout_EDX_04;
  uint *extraout_EDX_05;
  uint *extraout_EDX_06;
  uint *extraout_EDX_07;
  undefined4 extraout_EDX_08;
  float *pfVar10;
  float *pfVar11;
  undefined8 uVar12;
  float local_14 [5];
  
  puVar2 = param_3;
  uVar12 = FUN_1002d750(local_14,param_2,local_14,param_4,(float *)(param_3 + 0x13));
  uVar9 = (undefined4)((ulonglong)uVar12 >> 0x20);
  local_14[0] = (float)param_3[0x16] + local_14[0];
  local_14[1] = (float)param_3[0x17] + local_14[1];
  cVar7 = '\x01';
  if (_DAT_1005223c <= local_14[1]) {
    cVar7 = (0 < (int)local_14[0]) + '\x02';
  }
  if (cVar7 == '\x02') {
    if (_DAT_1005223c <= local_14[1] + local_14[0]) {
      if (-local_14[0] < (float)param_3[0x17] - (float)param_3[0x16]) {
        cVar7 = '\x03';
        param_3[0x16] = (uint)((float)param_3[0x16] + -local_14[0]);
      }
    }
    else if (local_14[1] < (float)param_3[0x17] - (float)param_3[0x16]) {
      cVar7 = '\x01';
      param_3[0x17] = (uint)((float)param_3[0x17] - local_14[1]);
    }
  }
  if (cVar7 == '\x01') {
    FUN_1002d8b0(param_3,uVar9,param_3,param_3,param_4);
    puVar2 = (uint *)param_3[0x19];
    if (puVar2[0x11] == 3) {
      puVar2 = FUN_1002ea90(3,extraout_EDX,puVar2,param_4);
    }
    else {
      puVar2 = FUN_1002e520(puVar2,param_4);
    }
    *param_4 = *param_4 | 1;
    if (puVar2 != (uint *)0x0) {
      param_3[0x19] = (uint)puVar2;
      return param_3;
    }
    return (uint *)0x0;
  }
  if (cVar7 == '\x02') {
    if ((*param_3 & 4) != 0) {
      puVar2 = (uint *)param_3[4];
      if (puVar2 == (uint *)0x0) {
        param_4[5] = (uint)param_3;
        param_3[4] = (uint)param_4;
        return param_3;
      }
      if (puVar2[0x11] == 3) {
        puVar2 = FUN_1002ea90(3,uVar9,puVar2,param_4);
      }
      else {
        puVar2 = FUN_1002e520(puVar2,param_4);
      }
      *param_4 = *param_4 | 1;
      if (puVar2 != (uint *)0x0) {
        param_3[4] = (uint)puVar2;
        return param_3;
      }
      return (uint *)0x0;
    }
    uVar1 = *(uint *)param_3[6];
    if ((uVar1 & 2) == 0) {
      *(uint *)param_3[6] = uVar1 | 1;
      return param_3;
    }
    iVar3 = FUN_1002dde0(local_14,(int)param_3,(int)param_4);
    if (iVar3 == 2) {
      puVar6 = extraout_EDX_00;
      if (((*(uint *)param_3[0x18] & 4) == 0) ||
         (iVar3 = FUN_1002dde0(local_14,(int)param_3[0x18],(int)param_4), puVar6 = extraout_EDX_02,
         iVar3 != 2)) {
        puVar4 = param_3 + 0x19;
        if (((*(uint *)param_3[0x19] & 4) == 0) ||
           (iVar3 = FUN_1002dde0(local_14,(int)param_3[0x19],(int)param_4), puVar6 = extraout_EDX_05
           , iVar3 != 2)) {
          iVar3 = 0;
        }
        else {
          puVar5 = *(uint **)(*puVar4 + 0x10);
          if (puVar5 == (uint *)0x0) {
            param_4[5] = *puVar4;
            *(uint **)(*puVar4 + 0x10) = param_4;
            iVar3 = 1;
          }
          else {
            if (puVar5[0x11] == 3) {
              puVar5 = FUN_1002ea90(puVar5,extraout_EDX_05,puVar5,param_4);
              puVar6 = extraout_EDX_06;
            }
            else {
              puVar5 = FUN_1002e520(puVar5,param_4);
              puVar6 = extraout_EDX_07;
            }
            *param_4 = *param_4 | 1;
            if (puVar5 == (uint *)0x0) {
              iVar3 = -1;
            }
            else {
              *(uint **)(*puVar4 + 0x10) = puVar5;
              iVar3 = 1;
            }
          }
        }
      }
      else {
        puVar4 = *(uint **)(param_3[0x18] + 0x10);
        if (puVar4 == (uint *)0x0) {
          param_4[5] = param_3[0x18];
          *(uint **)(param_3[0x18] + 0x10) = param_4;
          iVar3 = 1;
        }
        else {
          if (puVar4[0x11] == 3) {
            puVar4 = FUN_1002ea90(3,extraout_EDX_02,puVar4,param_4);
            puVar6 = extraout_EDX_03;
          }
          else {
            puVar4 = FUN_1002e520(puVar4,param_4);
            puVar6 = extraout_EDX_04;
          }
          *param_4 = *param_4 | 1;
          if (puVar4 == (uint *)0x0) {
            iVar3 = -1;
          }
          else {
            *(uint **)(param_3[0x18] + 0x10) = puVar4;
            iVar3 = 1;
          }
        }
      }
    }
    else {
      puVar6 = FUN_1002ee60(3,param_3[6],param_3[5]);
      if (puVar6 == (uint *)0x0) {
        iVar3 = -1;
        puVar6 = extraout_EDX_01;
      }
      else {
        pfVar10 = local_14;
        pfVar11 = (float *)(puVar6 + 0x13);
        for (iVar8 = 5; iVar8 != 0; iVar8 = iVar8 + -1) {
          *pfVar11 = *pfVar10;
          pfVar10 = pfVar10 + 1;
          pfVar11 = pfVar11 + 1;
        }
        if (iVar3 == 3) {
          puVar6[0x18] = (uint)param_3;
          puVar6[0x19] = (uint)param_4;
        }
        else {
          puVar6[0x18] = (uint)param_4;
          puVar6[0x19] = (uint)param_3;
        }
        FUN_1002d8b0(param_3,extraout_EDX_01,puVar6,param_3,param_4);
        iVar3 = 1;
        param_3[5] = (uint)puVar6;
        param_4[5] = (uint)puVar6;
        param_3 = puVar6;
      }
    }
    if (iVar3 == -1) {
      return (uint *)0x0;
    }
    if (iVar3 != 0) {
      return param_3;
    }
    FUN_1002d8b0(param_3,puVar6,param_3,param_3,param_4);
    *param_4 = *param_4 | 0x10;
    *param_3 = *param_3 | 0x10;
    puVar6 = (uint *)param_3[6];
    *puVar6 = *puVar6 | 4;
    puVar4 = (uint *)puVar2[0x18];
    if (puVar4[0x11] == 3) {
      puVar6 = FUN_1002ea90(puVar6,param_3,puVar4,param_4);
    }
    else {
      puVar6 = FUN_1002e520(puVar4,param_4);
    }
    *param_4 = *param_4 | 1;
  }
  else {
    if (cVar7 != '\x03') {
      return param_3;
    }
    FUN_1002d8b0(param_3,uVar9,param_3,param_3,param_4);
    puVar6 = (uint *)param_3[0x18];
    if (puVar6[0x11] == 3) {
      puVar6 = FUN_1002ea90(3,extraout_EDX_08,puVar6,param_4);
    }
    else {
      puVar6 = FUN_1002e520(puVar6,param_4);
    }
    *param_4 = *param_4 | 1;
  }
  if (puVar6 != (uint *)0x0) {
    puVar2[0x18] = (uint)puVar6;
    return param_3;
  }
  return (uint *)0x0;
}


