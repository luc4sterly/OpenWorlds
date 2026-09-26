// 10008770 FUN_10008770 [Global]
// programa: RWDLDD21.DLL

void FUN_10008770(undefined4 *param_1)

{
  short sVar1;
  short sVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  short *psVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 local_8c [4];
  undefined4 uStack_7c;
  undefined4 auStack_78 [26];
  undefined4 uStack_10;
  
  psVar7 = (short *)(param_1[6] + param_1[7] * param_1[8] * 2);
  sVar1 = *psVar7;
  sVar2 = psVar7[1];
  puVar4 = local_8c;
  for (iVar6 = 8; psVar7 = psVar7 + 2, iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar4 = *(undefined4 *)psVar7;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (undefined4 *)(**(code **)(DAT_100394fc + 0x34c))();
  if (puVar4 != (undefined4 *)0x0) {
    puVar4[9] = 0;
    puVar4[0xb] = 0;
    puVar4[0xd] = 0;
    puVar5 = FUN_10003490(param_1[6],param_1[10],param_1[7],param_1[8],local_8c);
    *puVar4 = puVar5;
    if (puVar5 == (undefined1 *)0x0) {
      (**(code **)(DAT_100394fc + 0x358))();
    }
    else {
      param_1[1] = local_8c[3];
      *param_1 = 2;
      param_1[2] = uStack_7c;
      param_1[3] = auStack_78[0];
      param_1[4] = auStack_78[1];
      param_1[5] = auStack_78[2];
      puVar8 = local_8c;
      puVar9 = puVar4;
      for (iVar6 = 8; puVar9 = puVar9 + 1, iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
      }
      param_1[0xb] = puVar4;
      (**(code **)(DAT_100394fc + 0x358))();
      param_1[6] = 0;
      param_1[9] = 0x10;
      piVar3 = (int *)*puVar4;
      if (((sVar1 != 0) || (sVar2 != -1)) &&
         (iVar6 = (**(code **)(*piVar3 + 0x74))(), iVar6 == -0x7789fe3e)) {
        puVar4 = auStack_78;
        for (iVar6 = 0x1b; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
        auStack_78[0] = 0x6c;
        auStack_78[1] = 1;
        uStack_10 = 0x4000;
        (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,auStack_78,0);
        if (DAT_10036038 != (int *)0x0) {
          (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
        }
        if (DAT_1003603c != DAT_10036038) {
          (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
        }
        (**(code **)(*piVar3 + 0x74))(piVar3,8,&stack0xffffff4c);
      }
    }
  }
  return;
}


