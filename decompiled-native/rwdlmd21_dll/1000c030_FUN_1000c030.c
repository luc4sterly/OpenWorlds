// 1000c030 FUN_1000c030 [Global]
// program: rwdlmd21.dll

uint FUN_1000c030(byte *param_1)

{
  byte bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  undefined3 extraout_var_00;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  undefined4 *puVar11;
  byte *pbVar12;
  byte local_38;
  undefined1 local_37;
  undefined1 local_36;
  uint local_34;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint auStack_18 [6];
  
  if ((DAT_10087368 == (int *)0x0) || (param_1 == (byte *)0x0)) {
    return 0xffffffff;
  }
  piVar10 = (int *)&DAT_10087368;
  local_30 = DAT_100860d0;
  local_2c = DAT_100860d4;
  local_28 = DAT_100860d8;
  local_24 = DAT_100860dc;
  local_20 = DAT_100860e0;
  local_34 = 8;
  local_1c = DAT_100860e4;
  piVar8 = DAT_10087368;
  do {
    if (*piVar8 != 0) break;
    local_34 = local_34 + -1;
    local_38 = (byte)((int)(local_2c + local_30) >> 1);
    local_37 = (undefined1)(local_28 + local_24 >> 1);
    local_36 = (undefined1)(local_1c + local_20 >> 1);
    bVar1 = FUN_1000c6d0(param_1,&local_38,&local_30);
    piVar10 = piVar8 + CONCAT31(extraout_var,bVar1) + 1;
    piVar8 = (int *)*piVar10;
  } while (0 < (int)local_34);
  iVar9 = *piVar8;
  do {
    if (((int)local_34 < 1) || (iVar9 < 9)) goto LAB_1000c257;
    local_34 = local_34 + -1;
    puVar2 = (undefined4 *)(**(code **)(DAT_10089de0 + 0x34c))(0x24);
    if (puVar2 == (undefined4 *)0x0) goto LAB_1000c257;
    *puVar2 = 0;
    local_38 = (byte)((int)(local_2c + local_30) >> 1);
    local_37 = (undefined1)(local_28 + local_24 >> 1);
    uVar7 = 0;
    local_36 = (undefined1)(local_1c + local_20 >> 1);
    do {
      piVar3 = FUN_1000c650(piVar8);
      piVar4 = (int *)FUN_1000c750(auStack_18,uVar7,&local_38,&local_30);
      piVar3 = FUN_1000c3c0(piVar4,piVar3);
      puVar2[uVar7 + 1] = piVar3;
      if (piVar3 == (int *)0x0) break;
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 < 8);
    if ((int)uVar7 < 8) {
      if ((int)(uVar7 + 1) < 8) {
        puVar11 = puVar2 + uVar7 + 2;
        for (iVar9 = 8 - (uVar7 + 1); iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar11 = 0;
          puVar11 = puVar11 + 1;
        }
      }
      if (puVar2 != (undefined4 *)0x0) {
        iVar9 = 8;
        puVar11 = puVar2;
        do {
          puVar11 = puVar11 + 1;
          uVar5 = FUN_1000bf20((int *)*puVar11);
          iVar9 = iVar9 + -1;
          *puVar11 = uVar5;
        } while (iVar9 != 0);
        (**(code **)(DAT_10089de0 + 0x358))(puVar2);
      }
LAB_1000c257:
      pbVar12 = (byte *)piVar8[1];
      iVar9 = *piVar8 + -1;
      local_34 = (uint)*pbVar12;
      if (0 < iVar9) {
        do {
          pbVar12 = pbVar12 + 1;
          bVar1 = *pbVar12;
          iVar6 = FUN_1000c2b0(local_34,(uint)bVar1,param_1);
          if (iVar6 < 0) {
            local_34 = (uint)bVar1;
          }
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      return local_34;
    }
    if (piVar8 != (int *)0x0) {
      if (piVar8[1] != 0) {
        (**(code **)(DAT_10089de0 + 0x358))(piVar8[1]);
      }
      piVar8[1] = 0;
      *piVar8 = 0;
      (**(code **)(DAT_10089de0 + 0x358))(piVar8);
    }
    *piVar10 = (int)puVar2;
    bVar1 = FUN_1000c6d0(param_1,&local_38,&local_30);
    piVar8 = (int *)puVar2[CONCAT31(extraout_var_00,bVar1) + 1];
    piVar10 = puVar2 + CONCAT31(extraout_var_00,bVar1) + 1;
    iVar9 = *piVar8;
  } while( true );
}


