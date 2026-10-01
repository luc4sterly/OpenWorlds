// 10027fe0 FUN_10027fe0 [Global]
// program: RWDLDD21.DLL

uint FUN_10027fe0(byte *param_1)

{
  byte bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  undefined3 extraout_var_00;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  byte *pbVar9;
  int *piVar10;
  undefined4 *puVar11;
  int iVar12;
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
  
  if ((DAT_10036410 == (int *)0x0) || (param_1 == (byte *)0x0)) {
    return 0xffffffff;
  }
  piVar10 = (int *)&DAT_10036410;
  local_30 = DAT_100346e0;
  local_2c = DAT_100346e4;
  local_28 = DAT_100346e8;
  local_24 = DAT_100346ec;
  local_20 = DAT_100346f0;
  local_34 = 8;
  local_1c = DAT_100346f4;
  piVar7 = DAT_10036410;
  do {
    if (*piVar7 != 0) break;
    local_34 = local_34 + -1;
    local_38 = (byte)((int)(local_2c + local_30) >> 1);
    local_37 = (undefined1)(local_28 + local_24 >> 1);
    local_36 = (undefined1)(local_1c + local_20 >> 1);
    bVar1 = FUN_10028670(param_1,&local_38,&local_30);
    piVar10 = piVar7 + CONCAT31(extraout_var,bVar1) + 1;
    piVar7 = (int *)*piVar10;
  } while (0 < (int)local_34);
  iVar12 = *piVar7;
  do {
    if (((int)local_34 < 1) || (iVar12 < 9)) goto LAB_10028208;
    local_34 = local_34 + -1;
    puVar2 = (undefined4 *)(**(code **)(DAT_100394fc + 0x34c))(0x24);
    if (puVar2 == (undefined4 *)0x0) goto LAB_10028208;
    *puVar2 = 0;
    local_38 = (byte)((int)(local_2c + local_30) >> 1);
    local_37 = (undefined1)(local_28 + local_24 >> 1);
    uVar8 = 0;
    local_36 = (undefined1)(local_1c + local_20 >> 1);
    do {
      piVar3 = FUN_100285f0(piVar7);
      piVar4 = (int *)FUN_100286f0(auStack_18,uVar8,&local_38,&local_30);
      piVar3 = FUN_10028370(piVar4,piVar3);
      puVar2[uVar8 + 1] = piVar3;
      if (piVar3 == (int *)0x0) break;
      uVar8 = uVar8 + 1;
    } while ((int)uVar8 < 8);
    if ((int)uVar8 < 8) {
      if ((int)(uVar8 + 1) < 8) {
        puVar11 = puVar2 + uVar8 + 2;
        for (iVar12 = 8 - (uVar8 + 1); iVar12 != 0; iVar12 = iVar12 + -1) {
          *puVar11 = 0;
          puVar11 = puVar11 + 1;
        }
      }
      if (puVar2 != (undefined4 *)0x0) {
        iVar12 = 8;
        puVar11 = puVar2;
        do {
          puVar11 = puVar11 + 1;
          uVar5 = FUN_10027ed0((int *)*puVar11);
          iVar12 = iVar12 + -1;
          *puVar11 = uVar5;
        } while (iVar12 != 0);
        (**(code **)(DAT_100394fc + 0x358))(puVar2);
      }
LAB_10028208:
      pbVar9 = (byte *)piVar7[1];
      iVar12 = *piVar7 + -1;
      local_34 = (uint)*pbVar9;
      if (0 < iVar12) {
        do {
          pbVar9 = pbVar9 + 1;
          bVar1 = *pbVar9;
          iVar6 = FUN_10028260(local_34,(uint)bVar1,param_1);
          if (iVar6 < 0) {
            local_34 = (uint)bVar1;
          }
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
      }
      return local_34;
    }
    if (piVar7 != (int *)0x0) {
      if (piVar7[1] != 0) {
        (**(code **)(DAT_100394fc + 0x358))(piVar7[1]);
      }
      piVar7[1] = 0;
      *piVar7 = 0;
      (**(code **)(DAT_100394fc + 0x358))(piVar7);
    }
    *piVar10 = (int)puVar2;
    bVar1 = FUN_10028670(param_1,&local_38,&local_30);
    piVar7 = (int *)puVar2[CONCAT31(extraout_var_00,bVar1) + 1];
    piVar10 = puVar2 + CONCAT31(extraout_var_00,bVar1) + 1;
    iVar12 = *piVar7;
  } while( true );
}


