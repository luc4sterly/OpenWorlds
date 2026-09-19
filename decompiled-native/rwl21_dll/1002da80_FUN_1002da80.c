// 1002da80 FUN_1002da80 [Global]
// programa: RWL21.DLL

/* WARNING: Removing unreachable block (ram,0x1002dac6) */

undefined4 FUN_1002da80(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  uint *puVar5;
  undefined3 extraout_var;
  uint *puVar6;
  int iVar7;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  float *pfVar8;
  float *pfVar9;
  uint *local_1c;
  undefined4 *local_18;
  float local_14 [5];
  
  puVar1 = (uint *)*param_1;
  local_1c = (uint *)FUN_1002dde0(local_14,(int)puVar1,(int)param_2);
  if (local_1c != (uint *)0x2) {
    uVar2 = puVar1[5];
    uVar3 = puVar1[6];
    local_18 = (undefined4 *)0x0;
    local_18 = FUN_10037030(DAT_1005adac);
    if (local_18 == (undefined4 *)0x0) {
      FUN_1000cba0(3);
    }
    else {
      local_18[0x11] = 3;
      local_18[6] = uVar3;
      local_18[5] = uVar2;
      *local_18 = 0;
      local_18[4] = 0;
    }
    if (local_18 != (undefined4 *)0x0) {
      pfVar8 = local_14;
      pfVar9 = (float *)(local_18 + 0x13);
      for (iVar7 = 5; iVar7 != 0; iVar7 = iVar7 + -1) {
        *pfVar9 = *pfVar8;
        pfVar8 = pfVar8 + 1;
        pfVar9 = pfVar9 + 1;
      }
      if (local_1c == (uint *)0x3) {
        local_18[0x18] = puVar1;
        local_18[0x19] = param_2;
      }
      else {
        local_18[0x18] = param_2;
        local_18[0x19] = puVar1;
      }
      FUN_1002d8b0(local_18,local_1c,local_18,puVar1,param_2);
      puVar1[5] = (uint)local_18;
      param_2[5] = (uint)local_18;
      *param_1 = (uint)local_18;
      return 1;
    }
    return 0xffffffff;
  }
  if (((*(uint *)puVar1[0x18] & 4) != 0) &&
     (iVar7 = FUN_1002dde0(local_14,(int)puVar1[0x18],(int)param_2), iVar7 == 2)) {
    puVar5 = *(uint **)(puVar1[0x18] + 0x10);
    if (puVar5 == (uint *)0x0) {
      param_2[5] = puVar1[0x18];
      *(uint **)(puVar1[0x18] + 0x10) = param_2;
      return 1;
    }
    if (puVar5[0x11] == 3) {
      puVar5 = FUN_1002ea90(3,extraout_EDX,puVar5,param_2);
    }
    else {
      puVar5 = FUN_1002e520(puVar5,param_2);
    }
    *param_2 = *param_2 | 1;
    if (puVar5 != (uint *)0x0) {
      *(uint **)(puVar1[0x18] + 0x10) = puVar5;
      return 1;
    }
    return 0xffffffff;
  }
  if (((*(uint *)puVar1[0x19] & 4) == 0) ||
     (iVar7 = FUN_1002dde0(local_14,(int)puVar1[0x19],(int)param_2), iVar7 != 2)) {
    return 0;
  }
  puVar5 = *(uint **)(puVar1[0x19] + 0x10);
  if (puVar5 == (uint *)0x0) {
    param_2[5] = puVar1[0x19];
    *(uint **)(puVar1[0x19] + 0x10) = param_2;
    return 1;
  }
  if (puVar5[0x11] == 3) {
    local_1c = puVar5;
    cVar4 = FUN_1002d680(extraout_ECX,extraout_EDX_00,(float *)(puVar5 + 0x13),param_2);
    iVar7 = CONCAT31(extraout_var,cVar4);
    if (iVar7 == 1) {
      FUN_1002d8b0(extraout_ECX_00,extraout_EDX_01,local_1c,local_1c,param_2);
      puVar6 = FUN_1002eed0(puVar5[0x19],extraout_EDX_02,(uint *)puVar5[0x19],param_2);
      if (puVar6 == (uint *)0x0) {
        local_1c = (uint *)0x0;
      }
      else {
        puVar5[0x19] = (uint)puVar6;
      }
    }
    else if (iVar7 == 2) {
      if ((*local_1c & 4) == 0) {
        uVar2 = *(uint *)local_1c[6];
        if ((uVar2 & 2) == 0) {
          *(uint *)local_1c[6] = uVar2 | 1;
        }
        else {
          iVar7 = FUN_1002da80((uint *)&local_1c,param_2);
          if (iVar7 == -1) {
            local_1c = (uint *)0x0;
          }
          else if (iVar7 == 0) {
            FUN_1002d8b0(extraout_ECX_01,extraout_EDX_03,local_1c,local_1c,param_2);
            *param_2 = *param_2 | 0x10;
            *local_1c = *local_1c | 0x10;
            puVar6 = (uint *)local_1c[6];
            *puVar6 = *puVar6 | 4;
            puVar6 = FUN_1002eed0(puVar6,local_1c,(uint *)puVar5[0x18],param_2);
            if (puVar6 == (uint *)0x0) {
              local_1c = (uint *)0x0;
            }
            else {
              puVar5[0x18] = (uint)puVar6;
            }
          }
        }
      }
      else if ((uint *)local_1c[4] == (uint *)0x0) {
        param_2[5] = (uint)local_1c;
        local_1c[4] = (uint)param_2;
      }
      else {
        puVar5 = FUN_1002eed0(local_1c + 4,extraout_EDX_01,(uint *)local_1c[4],param_2);
        if (puVar5 == (uint *)0x0) {
          local_1c = (uint *)0x0;
        }
        else {
          local_1c[4] = (uint)puVar5;
        }
      }
    }
    else if (iVar7 == 3) {
      FUN_1002d8b0(extraout_ECX_00,extraout_EDX_01,local_1c,local_1c,param_2);
      puVar6 = FUN_1002eed0(puVar5[0x18],extraout_EDX_04,(uint *)puVar5[0x18],param_2);
      if (puVar6 == (uint *)0x0) {
        local_1c = (uint *)0x0;
      }
      else {
        puVar5[0x18] = (uint)puVar6;
      }
    }
  }
  else {
    local_1c = FUN_1002e520(puVar5,param_2);
  }
  *param_2 = *param_2 | 1;
  if (local_1c != (uint *)0x0) {
    *(uint **)(puVar1[0x19] + 0x10) = local_1c;
    return 1;
  }
  return 0xffffffff;
}


