// 1002eed0 FUN_1002eed0 [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * __fastcall FUN_1002eed0(undefined4 param_1,undefined4 param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  char cVar4;
  undefined4 extraout_ECX;
  undefined4 uVar5;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined8 uVar6;
  uint *local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (param_3[0x11] == 3) {
    local_14 = param_3;
    uVar6 = FUN_1002d750(&local_8,param_2,&local_8,param_4,(float *)(param_3 + 0x13));
    uVar5 = (undefined4)((ulonglong)uVar6 >> 0x20);
    local_10 = (float)param_3[0x16] + local_8;
    local_c = (float)param_3[0x17] + local_4;
    cVar4 = '\x01';
    if (_DAT_1005223c <= local_c) {
      cVar4 = (0 < (int)local_10) + '\x02';
    }
    if (cVar4 == '\x02') {
      if (_DAT_1005223c <= local_c + local_10) {
        local_10 = -local_10;
        if (local_10 < (float)param_3[0x17] - (float)param_3[0x16]) {
          cVar4 = '\x03';
          param_3[0x16] = (uint)((float)param_3[0x16] + local_10);
        }
      }
      else if (local_c < (float)param_3[0x17] - (float)param_3[0x16]) {
        cVar4 = '\x01';
        param_3[0x17] = (uint)((float)param_3[0x17] - local_c);
      }
    }
    if (cVar4 == '\x01') {
      FUN_1002d8b0(1,uVar5,local_14,local_14,param_4);
      puVar3 = FUN_1002eed0(param_3[0x19],extraout_EDX,(uint *)param_3[0x19],param_4);
      if (puVar3 == (uint *)0x0) {
        local_14 = (uint *)0x0;
      }
      else {
        param_3[0x19] = (uint)puVar3;
      }
    }
    else if (cVar4 == '\x02') {
      if ((*local_14 & 4) == 0) {
        uVar1 = *(uint *)local_14[6];
        if ((uVar1 & 2) == 0) {
          *(uint *)local_14[6] = uVar1 | 1;
        }
        else {
          iVar2 = FUN_1002da80((uint *)&local_14,param_4);
          if (iVar2 == -1) {
            local_14 = (uint *)0x0;
          }
          else if (iVar2 == 0) {
            FUN_1002d8b0(extraout_ECX,extraout_EDX_00,local_14,local_14,param_4);
            *param_4 = *param_4 | 0x10;
            *local_14 = *local_14 | 0x10;
            puVar3 = (uint *)local_14[6];
            *puVar3 = *puVar3 | 4;
            puVar3 = FUN_1002eed0(puVar3,local_14,(uint *)param_3[0x18],param_4);
            if (puVar3 == (uint *)0x0) {
              local_14 = (uint *)0x0;
            }
            else {
              param_3[0x18] = (uint)puVar3;
            }
          }
        }
      }
      else if ((uint *)local_14[4] == (uint *)0x0) {
        param_4[5] = (uint)local_14;
        local_14[4] = (uint)param_4;
      }
      else {
        puVar3 = FUN_1002eed0(local_14 + 4,uVar5,(uint *)local_14[4],param_4);
        if (puVar3 == (uint *)0x0) {
          local_14 = (uint *)0x0;
        }
        else {
          local_14[4] = (uint)puVar3;
        }
      }
    }
    else if (cVar4 == '\x03') {
      FUN_1002d8b0(3,uVar5,local_14,local_14,param_4);
      puVar3 = FUN_1002eed0(param_3[0x18],extraout_EDX_01,(uint *)param_3[0x18],param_4);
      if (puVar3 == (uint *)0x0) {
        local_14 = (uint *)0x0;
      }
      else {
        param_3[0x18] = (uint)puVar3;
      }
    }
  }
  else {
    local_14 = FUN_1002e520(param_3,param_4);
  }
  *param_4 = *param_4 | 1;
  return local_14;
}


