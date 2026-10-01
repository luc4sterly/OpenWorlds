// 00438800 FUN_00438800 [Global]
// program: gamma.dll

void __cdecl FUN_00438800(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined1 local_30 [4];
  undefined4 *local_2c;
  undefined1 local_25;
  undefined1 local_24 [4];
  undefined4 *local_20;
  undefined1 local_1c;
  undefined4 *local_18;
  undefined1 local_11;
  
  while( true ) {
    iVar3 = ((int)param_2 - (int)param_1) + ((int)param_2 - (int)param_1 >> 0x1f & 7U);
    iVar4 = iVar3 >> 3;
    if (iVar4 < 2) {
      return;
    }
    if (iVar4 < 0x15) break;
    if (DAT_0049de04 == '\0') {
      DAT_0049de04 = '\x01';
      DAT_0049de00 = -4;
    }
    iVar6 = DAT_0049de00 % 5;
    DAT_0049de00 = DAT_0049de00 + 1;
    if (4 < DAT_0049de00) {
      DAT_0049de00 = -4;
    }
    iVar7 = DAT_0049de00 % 5;
    DAT_0049de00 = DAT_0049de00 + 1;
    if (4 < DAT_0049de00) {
      DAT_0049de00 = -4;
    }
    puVar8 = param_2 + -2;
    FUN_00438cb0(param_1 + (iVar6 + ((int)(iVar4 + (iVar3 >> 0x1f & 3U)) >> 2)) * 2,
                 param_1 + (iVar7 + ((int)(iVar4 * 3 + (iVar4 * 3 >> 0x1f & 3U)) >> 2)) * 2,puVar8);
    local_30[0] = local_25;
    local_2c = puVar8;
    puVar5 = FUN_00438dd0(param_1,puVar8,(int)local_30);
    if (puVar5 == param_1) {
      uVar1 = *puVar5;
      uVar2 = puVar5[1];
      *puVar5 = *puVar8;
      puVar5[1] = param_2[-1];
      *puVar8 = uVar1;
      param_2[-1] = uVar2;
      local_1c = local_11;
      local_18 = param_1;
      local_24[0] = local_11;
      local_20 = param_1;
      param_1 = FUN_00438fb0(puVar5 + 2,param_2,(int)local_24);
    }
    else if ((int)(((int)puVar5 - (int)param_1) + ((int)puVar5 - (int)param_1 >> 0x1f & 7U)) >> 3 <
             (int)(((int)param_2 - (int)puVar5) + ((int)param_2 - (int)puVar5 >> 0x1f & 7U)) >> 3) {
      FUN_00438800(param_1,puVar5);
      param_1 = puVar5;
    }
    else {
      FUN_00438800(puVar5,param_2);
      param_2 = puVar5;
    }
  }
  FUN_00439210(param_1,param_2);
  return;
}


